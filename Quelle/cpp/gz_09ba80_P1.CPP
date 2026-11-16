/* === Beschreibung (Katalog) ===
 * Einheit gz_09ba80 (09ba80-09c9e0)
 *
 * Überblick
 * Diese Einheit implementiert im ersten Teil das Heilerhaus (HEALER.CPP), in dem die Gruppe gegen Bezahlung
 * Lebenspunkte (f_09bc00), Krankheiten (f_09be20), Vergiftungen (f_09c090) und tote Helden (f_09c330) behandeln
 * lassen oder dem Heiler für einen Dukaten (100 Heller) Auskünfte entlocken kann (f_09c510). Im zweiten Teil
 * (f_09c750 bis f_09c990) befinden sich Verwaltungsfunktionen für die Aktions- und Animationswarteschlange im
 * Kampf.
 === Ende Beschreibung === */
// P3 16/19 gleich (suche.py 30.10.2026, Basis gz_09ba80_P1.CPP)
// gz_09ba80.cpp (Schatten ueber Riva, Attic 1996) - Pass 1
#include <string.h>
struct SO { int a[14]; short s; };
extern short d_1a0db8[], d_1a0ddc[];
extern signed char d_1a0da8[];
extern signed char d_1a0dc8[];
extern signed char d_1bed64, d_1bdd10;
extern int d_1bd914, d_1c0004;
extern signed char d_1bfb00;
extern signed char d_1bfafc;
extern short d_1c219a;
extern char d_1c2c44[], d_1c2c64[], d_1c2edc[];
extern const char d_1c3498[], d_1c349c[], d_1c3870[];
int f_038e90(int p1, int p2);
int f_040da0(int p1);
int f_040e00(int p1);
int f_040e40(int p1);
signed char f_0424e0(int p1);
int f_0424f0(int p1, int p2);
short f_042960(int p1);
short f_042970(int p1);
short f_042980(int p1);
int f_0429f0(int p1);
int f_0437e0(int p1, int p2, int p3);
int f_043a40(int p1, int p2, int p3);
int f_044890(int p1, int p2);
int f_0757f0(int p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0b9060(int p1);
int f_0bf6f0(char *p1, int p2);
int f_0bf730(char *p1, int p2);
short f_0d4ad0(int p1);
short f_0d4b00(int p1);
int f_0db820(int p1, int p2);
int f_0db8b0(int p1, int p2);
int f_0de7e0(int p1);
int f_1094e0(int p1);
int f_109800(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(char *p1, int p2);
int f_125f70(char *p1, int p2);
short f_1457e0(int p1);
int f_146dfa(char *p1, int p2);
int f_0773b0(int p1);
void f_145300(void *p1, int p2, unsigned p3);
void f_09bc00(int p1);
void f_09be20(int p1);
void f_09c090(int p1);
void f_09c330(int p1);
#define SOI(o) f_125400(&o, d_1c349c, d_1c3870, d_1c3498)
#define OP(o, n, v) ((int *)(o).a[n])[1] = (v)
#define PAY(x) (f_0de7e0(d_1c0004) >= (x) * 10)
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_09ba80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verzweigt als zentrale Ereignismethode des Heilerhauses je nach gewählter Menüoption (p2) in
 *   das Heilen von Wunden (0x92), das Heilen von Krankheiten (0x93), das Heilen von Giften (0x94), die
 *   Wiederbelebung (0x95), das Ausfragen gegen Geld (0x96) oder die allgemeinen Laden-/Gebäudeaktionen (0x81,
 *   0x87, 0x88).
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den Ereigniscode p2 (unsigned short)
 *   und gibt bei 0x80 den Wert 1, sonst 0 zurück (int).
 * - Wichtige Variablen: Das globale Byte d_1bdd10 (0..7) merkt sich beim Ereignis 0x96, welche der acht
 *   fortlaufenden Antworten (0x2200004f + c) der Heiler als Nächstes gibt.
 === Ende Beschreibung === */
void f_09c740(void)
{
}
int f_09ba80(int p1, unsigned short p2)
{
    int r = 0;
    switch (p2) {
    case 0x81:
        f_0b9060(p1);
        break;
    case 0x7f:
        break;
    case 0x87:
        f_1094e0(p1);
        break;
    case 0x88:
        f_109800(p1);
        break;
    case 0x92:
        f_09bc00(p1);
        break;
    case 0x94:
        f_09c090(p1);
        break;
    case 0x95:
        f_09c330(p1);
        break;
    case 0x96:
        f_0bf730(d_1c2c64, 0x2200004d);
        if (f_0de7e0(d_1c0004) < 100) {
            f_0bf730(d_1c2c64, 0x20000010);
            break;
        }
        f_0db8b0(d_1c0004, 100);
        f_0bf730(d_1c2c64, 0x2200004e);
        {
            signed char c = d_1bdd10;
            f_0bf730(d_1c2c64, c + 0x2200004f);
        }
        if (((d_1bdd10 > 0) ? 1 : 0)) {
            if (f_1457e0(100) <= 0x32) f_0bf730(d_1c2c64, 0x22000057);
            else f_0bf730(d_1c2c64, 0x22000058);
        }
        d_1bdd10++;
        if (EQB(d_1bdd10, 8)) d_1bdd10 = 0;
        break;
    case 0x80:
        r = 1;
        break;
    case 0x93:
        f_09be20(p1);
        break;
    }
    return r;
}
//@ f_09bc00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt den Spieler einen lebenden, verletzten Helden auswählen, berechnet den Preis für die
 *   vollständige Heilung seiner fehlenden und permanent verlorenen Lebenspunkte anhand des Preisaufschlags
 *   *(short *)(p1 + 0x70) und stellt nach Bezahlung die vollen Lebenspunkte (f_040e40, f_044890) unter
 *   Zeitverbrauch wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Jeder normale fehlende Lebenspunkt kostet im Grundpreis 5 Silberstücke und jeder
 *   permanent verlorene Lebenspunkt (f_042980) 50 Silberstücke zusätzlich; d_1bed64 verdoppelt bei gesetztem
 *   Straf-Flag die Heilungskosten.
 === Ende Beschreibung === */
void f_09bc00(int p1)
{
    struct Pricing { static short adjust(int rate, int sum) {
        unsigned short part = rate * sum / 100;
        short cost = sum; cost += part;
        if (EQ(d_1bed64, 1)) cost *= 2;
        return cost;
    } };
    struct { SO o2; short pad0; SO o; short pad1; } frame;
#define o frame.o
#define o2 frame.o2
    int h, ok, iw;
    short sa, sb, sc, sd;
    { int t_ = (int)(d_1c0004); h = f_038e90(t_, 0xf000002); }
    ok = 0;
    SOI(o);
    if (h != 0) {
        OP(o, 1, h);
        if (f_0424e0(h) == 1) f_0bf730(d_1c2c64, 0xf000004);
        else if (f_0429f0(h) == 0) f_0bf730(d_1c2c64, 0xf000003);
        else ok = 1;
    }
    f_1254a0(&o, 0);
    if (ok == 1) {
        SOI(o2);
        OP(o2, 1, h);
        sa = f_042960(h);
        sb = f_042970(h);
        if (sa >= sb && f_042980(h) == 0)
            f_0bf730(d_1c2c64, 0xf000005);
        else {
            int base, extra;
            sa = f_042980(h);
            extra = sa; extra *= 50; extra = (extra & 0) ? 0 : extra; h = (h & 0) ? 0 : h; // haelt die Registerzuteilung fuer extra und h wie im Original

            base = f_042970(h);
            base += f_042980(h);
            base -= f_042960(h);
            // haelt die Registerzuteilung fuer base und iv wie im Original
            int iv = base * 4; iv = (iv & 0) ? 0 : iv; iv += base; extra += iv;
            // haelt den Parameter p1 im Stapelrahmen wie im Original
            short cost = Pricing::adjust(*(short *)(*(int *)&p1 + 0x70), extra);
            short price = cost;
            OP(o2, 6, price);
            if (f_0bf6f0(d_1c2c64, 0xf000008) == 1) {
                int paid = 0;
                if (f_0de7e0(d_1c0004) < price * 10)
                    f_0bf730(d_1c2c64, 0x20000010);
                else {
                    paid = 1;
                    f_0db8b0(d_1c0004, price * 10);
                }
                if (paid == 1) {
                    int f_042970(void *), f_042960(void *);
                    base = f_042970((void *)h);
                    base -= f_042960((void *)h);
                    f_040e40(h);
                    sa = f_042970((void *)h);
                    f_044890(h, (short)(sa & 0xffff)); // haelt die 16-Bit-Erweiterung von sa wie im Original
                    *(volatile short *)&d_1c219a = 1; // haelt das Schreiben auf d_1c219a wie im Original
                    f_0bf730(d_1c2c64, 0xf000011);
                    f_125ed0(d_1c2c44, (short)base);
                }
            }
        }
        f_1254a0(&o2, 0);
    }
#undef o
#undef o2
}
//@ f_09be20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt einen Helden aus, ermittelt über f_0d4ad0 dessen Krankheit, berechnet das Honorar anhand
 *   der Krankheitstabelle d_1a0da8 und würfelt nach Bezahlung mit 1W100 gegen die Heilungschance (120 - Qualität
 *   * 10 + Krankheitsmodifikator d_1a0db8[u]). Bei Erfolg heilt f_040da0 die Krankheit; bei Misserfolg erstattet
 *   f_09c6f0 die Hälfte des Preises zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(short *)(p1 + 0x6e) beschreibt die Qualitätsstufe des Heilers, d_1a0da8
 *   enthält die Grundpreise und d_1a0db8 die Schwierigkeitsmodifikatoren der einzelnen Krankheiten.
 === Ende Beschreibung === */
int f_09c5e0(int, int);
int f_09c630(int, int);
int f_09c670(int, int);
void f_09c6f0(int, int);
void f_09be20(int p1)
{
    int h;
    short u;
    int fee;
    h = f_038e90(d_1c0004, 0xf000002);
    if (f_09c670(p1, h) == 1) {
        SO o2;
        u = f_0d4ad0(h);
        SOI(o2);
        OP(o2, 1, h);
        if (u == 0) {
            f_0bf730(d_1c2c64, 0xf000006);
        } else {
            fee = ((short *)d_1a0da8)[u] * 10;
            fee = f_09c630(p1, fee);
            OP(o2, 4, (unsigned)u + 0x2000003a);
            OP(o2, 6, fee);
            f_043a40(h, u, 1);
            if (f_0bf6f0(d_1c2c64, 0xf000009) == 1 &&
                f_09c5e0(p1, fee) == 1) {
                short chance = 0x78 - *(short *)(p1 + 0x6e) * 10 + d_1a0db8[u];
                if (f_1457e0(100) <= chance) {
                    f_040da0(h);
                    (*(volatile short *)&d_1c219a) = 1; // haelt das Schreiben auf d_1c219a wie im Original
                    f_0bf730(d_1c2c64, 0xf00000b);
                    f_125f70(d_1c2c44, 1);
                } else {
                    f_09c6f0(p1, fee);
                }
            }
        }
        f_1254a0(&o2, 0);
    }
}
//@ f_09c090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wählt einen Helden aus, ermittelt über f_0d4b00 dessen Vergiftung, berechnet den Preis aus
 *   d_1a0dc8 und würfelt nach Bezahlung mit 1W100 gegen die Entgiftungschance (120 - Qualität * 5 +
 *   Giftmodifikator d_1a0ddc[u]). Gelingt die Probe, heilt f_040e00 das Gift; misslingt sie, erhält die Gruppe
 *   die Hälfte des gezahlten Betrags über f_0db820 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabellen d_1a0dc8 und d_1a0ddc speichern die Grundkosten und Heilungsschwierigkeiten
 *   der verschiedenen Gifte.
 === Ende Beschreibung === */
void f_09c090(int p1)
{
    int f_0d4b00(void *);
    struct { SO o; short pad0; SO o1; short pad1; SO o2; } frame;
#define o frame.o
#define o1 frame.o1
#define o2 frame.o2
    int h, ok, iw;
    short u, s, s1, s3;
    h = f_038e90(d_1c0004, 0xf000002);
    SOI(o1);
    ok = 0;
    SOI(o);
    if (h != 0) {
        OP(o, 1, h);
        if (f_0424e0(h) == 1) f_0bf730(d_1c2c64, 0xf000004);
        else if (f_0429f0(h) == 0) f_0bf730(d_1c2c64, 0xf000003);
        else ok = 1;
    }
    iw = ok;
    f_1254a0(&o, 0);
    if (iw == 1) {
        int check; u = check = f_0d4b00((void *)h);
        SOI(o2);
        OP(o2, 1, h);
        if ((int)(short)check == 0) f_0bf730(d_1c2c64, 0xf000007);
        else {
            int base = ((short *)d_1a0dc8)[(short)check] * 20;
            int part = *(short *)(p1 + 0x70) * base / 100; short cost = base; cost += part;
            if (EQB(d_1bed64, 1)) cost *= 2;
            s = cost;
            OP(o2, 6, (int)s);
            f_0437e0(h, (short)u, 1);
            iw = s;
            if (f_0bf6f0(d_1c2c64, 0xf00000a) == 1) {
                int paid = 0;
                if (f_0de7e0(d_1c0004) < s * 10)
                    f_0bf730(d_1c2c64, 0x20000010);
                else {
                    paid = 1;
                    f_0db8b0(d_1c0004, iw * 10);
                }
                if (paid == 1) {
                    short chance = 0x78 - *(short *)(p1 + 0x6e) * 5 + d_1a0ddc[(short)u];
                    if (f_1457e0(100) <= chance) {
                        f_040e00(h);
                        (*(volatile short *)&d_1c219a) = 1; // haelt das Schreiben auf d_1c219a wie im Original
                        f_0bf730(d_1c2c64, 0xf00000f);
                        f_125f70(d_1c2c44, 1);
                    } else {
                        int refund = (iw * 10) / 2;
                        f_0bf730(d_1c2c64, 0xf00000c);
                        f_125f70(d_1c2c44, 1);
                        f_0db820(d_1c0004, refund);
                    }
                }
            }
        }
        f_1254a0(&o2, 0);
    }
    f_1254a0(&o1, 0);
#undef o
#undef o1
#undef o2
}
//@ f_09c330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bietet die Wiederbelebung eines toten (aber nicht versteinerten/endgültig verlorenen) Helden
 *   zum Grundpreis von 500 Silberstücken (angepasst über f_09c630) an und prüft nach Bezahlung mit 1W20 >
 *   *(short *)(p1 + 0x6e), ob das Wunder gelingt (f_0424f0(h, 0)). Bei einem Fehlschlag wird die Hälfte des
 *   Preises über f_09c6f0 erstattet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Abfrage f_0424e0(h) prüft, ob der ausgewählte Held tot ist, und f_042470(h) schließt
 *   untote oder nicht wiederbelebbare Zustände aus.
 === Ende Beschreibung === */
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0429a0(int p1);                                   // reg eax stapel 0
int f_042a10(int p1);                                   // reg eax stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
signed char f_042470(int);
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
extern short d_1bd90c;                    // 0x1BD90C
#define PD(x) ((int)&(x))
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
extern char d_f000002[];
int f_0d4aa0(int,int); int f_0bf730(int,int); int f_036300(int,int,int); int f_036a10(int,int,int,int,int); int f_0bf820(void);
int f_038e90(int,int); signed char f_042470(int); int f_0bf730(int,int); int f_145760(int,int); int f_042a10(int); int f_0429a0(int); int f_044230(int,int);
int f_0bf820(int,...);
    struct O { char b[12]; int *p; char c[16]; short *q; char d[24]; };
int f_125400(int,int,int,int);
int f_1254a0(int,int);
int f_09c630(int, int);
int f_09c5e0(int, int);
void f_09c6f0(int, int);
void f_09c330(int p1)
{
    int h;
    int fee;
    struct O { char a[4]; int *p; char b[16]; int *q; char c[32]; } o;
    h = f_038e90(d_1c0004, 0x0f000002);
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    if (h != 0) {
        o.p[1] = h;
        if (f_042470(h) == 1) {
            f_0bf730(d_1c2c64, 0x0f000003);
        } else if (f_0424e0(h) == 0) {
            f_0bf730(d_1c2c64, 0x0f00000e);
        } else {
            fee = 500;
            fee = f_09c630(p1, fee);
            o.q[1] = fee;
            if (f_0bf6f0(d_1c2c64, 0x0f00000d) == 1 &&
                f_09c5e0(p1, fee) == 1) {
                    if (f_1457e0(20) > S16(p1, 0x6e)) {
                        f_0424f0(h, 0);
                        f_0bf730(d_1c2c64, 0x0f000010);
                        f_125f70(d_1c2c44, 1);
                    } else {
                        f_09c6f0(p1, fee);
                    }
            }
        }
    }
    f_1254a0(&o, 0);
}

//@ f_09c510
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zieht der Gruppe im Gespräch mit dem Heiler 100 Heller (einen Dukaten) ab, gibt den nächsten
 *   Hinweis aus der achstufigen Gesprächsreihe (0x2200004f + d_1bdd10) sowie ab dem zweiten Hinweis zu 50 %
 *   einen Zusatzkommentar (0x22000057 oder 0x22000058) aus und schaltet d_1bdd10 zyklisch (0..7) weiter.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Byte d_1bdd10 speichert den aktuellen Gesprächszähler beim Heiler.
 === Ende Beschreibung === */
void f_09c510(void)
{
    f_0bf730(d_1c2c64, 0x2200004d);
    if (f_0de7e0(d_1c0004) < 100) { f_0bf730(d_1c2c64, 0x20000010); return; }
    f_0db8b0(d_1c0004, 100);
    f_0bf730(d_1c2c64, 0x2200004e);
    {
        signed char c = d_1bdd10;
        f_0bf730(d_1c2c64, c + 0x2200004f);
    }
    if (((d_1bdd10 > 0) ? 1 : 0)) {
        if (f_1457e0(100) <= 0x32) f_0bf730(d_1c2c64, 0x22000057);
        else f_0bf730(d_1c2c64, 0x22000058);
    }
    d_1bdd10++;
    if (EQ(d_1bdd10, 8)) d_1bdd10 = 0;
}
//@ f_09c5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Gruppenvermögen (f_0de7e0) für den in Silberstücken übergebenen Rechnungsbetrag
 *   p2 (p2 * 10 Heller) ausreicht, zieht den Betrag über f_0db8b0 ab oder gibt bei Geldmangel die Meldung
 *   0x20000010 aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den Preis in Silberstücken p2 und gibt
 *   1 bei erfolgreicher Zahlung oder 0 bei Geldmangel zurück (int).
 * - Wichtige Variablen: Die Umrechnung von Silberstücken in Heller erfolgt durch p2 *= 10.
 === Ende Beschreibung === */
int f_09c5e0(int p1, int p2)
{
    int r = 0;
    p2 *= 10;
    if (f_0de7e0(d_1c0004) < p2) {
        f_0bf730(d_1c2c64, 0x20000010);
    } else {
        f_0db8b0(d_1c0004, p2);
        r = 1;
    }
    return r;
}
//@ f_09c630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet aus einem Grundpreis p2 und dem prozentualen Aufschlag *(short *)(p1 + 0x70) des
 *   jeweiligen Heilers den Endpreis und verdoppelt ihn, falls das globale Straf-Flag d_1bed64 == 1 gesetzt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den Grundpreis p2 und gibt den
 *   angepassten Preis zurück (int).
 * - Wichtige Variablen: Das Feld *(short *)(p1 + 0x70) enthält den prozentualen Preismodifikator des Heilers.
 === Ende Beschreibung === */
int f_09c630(int p1, int p2)
{
    short s = p2;
    s += (short)((*(short *)(p1 + 0x70) * p2) / 100);
    if (EQB(d_1bed64, 1)) s = s * 2;
    return s;
}
//@ f_09c670
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für den ausgewählten Helden p2, ob er weder tot (f_0424e0(p2) == 1) noch
 *   handlungsunfähig/abwesend (f_0429f0(p2) == 0) ist, und gibt im Fehlerfall die passende Ablehnungsmeldung
 *   (0xf000004 bzw. 0xf000003) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den Heldenzeiger p2 und gibt 1 zurück,
 *   wenn der Held behandelt werden kann, sonst 0 (int).
 * - Wichtige Variablen: Das Textkontext-Objekt o (struct SO) bindet den Heldennamen für die Fehlermeldungen ein.
 === Ende Beschreibung === */
int f_09c670(int p1, int p2)
{
    struct SO o;
    int r;
    r = 0;
    SOI(o);
    if (p2 != 0) {
        OP(o, 1, p2);
        if (f_0424e0(p2) == 1) f_0bf730(d_1c2c64, 0xf000004);
        else if (f_0429f0(p2) == 0) f_0bf730(d_1c2c64, 0xf000003);
        else r = 1;
    }
    f_1254a0(&o, 0);
    return r;
}
//@ f_09c6f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt bei einem fehlgeschlagenen Heilungs- oder Wiederbelebungsversuch die Misserfolgsmeldung
 *   0xf00000c aus, lässt eine Stunde (f_125f70(..., 1)) vergehen und erstattet der Gruppe die Hälfte des
 *   gezahlten Preises (p2 * 10 / 2 Heller) über f_0db820 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Gebäudezeiger p1 sowie den zuvor gezahlten Silberpreis p2 und
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Rückerstattungsbetrag wird in Hellern an f_0db820(d_1c0004, p2) übergeben.
 === Ende Beschreibung === */
void f_09c6f0(int p1, int p2)
{
    p2 *= 10;
    p2 /= 2;
    f_0bf730(d_1c2c64, 0xf00000c);
    f_125f70(d_1c2c44, 1);
    f_0db820(d_1c0004, p2);
}
//@ f_09c740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere virtuelle Platzhalterfunktion am Ende der Heiler-Methodentabelle.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion greift auf keine Variablen zu.
 === Ende Beschreibung === */

//@ f_09c750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktiviert das Ausführungsflag an Offset 0xda einer Kampf-Animationswarteschlange p1 (*(int
 *   *)(p1 + 0xda) = 1).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Warteschlangenstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(p1 + 0xda) zeigt an, ob die gespeicherten Animationsschritte aktiv
 *   abgespielt werden.
 === Ende Beschreibung === */
void f_09c750(int p1)
{
    *(int *)(p1 + 0xda) = 1;
}
//@ f_09c760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Ausführungsflag an Offset 0xda der Kampf-Animationswarteschlange p1 auf 0 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Warteschlangenstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(p1 + 0xda) steuert den Abspielzustand der Warteschlange.
 === Ende Beschreibung === */
void f_09c760(int p1)
{
    *(int *)(p1 + 0xda) = 0;
}
//@ f_09c770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt einen Rückruf- oder Zielobjektzeiger p2 an Offset 0xe2 der Kampf-Animationswarteschlange
 *   p1 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 sowie den Wert p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Feld *(int *)(p1 + 0xe2) speichert den zugeordneten Kontextzeiger.
 === Ende Beschreibung === */
void f_09c770(int p1, int p2)
{
    *(int *)(p1 + 0xe2) = p2;
}
//@ f_09c780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht den Einträgepuffer der Kampf-Animationswarteschlange p1 (0xd2 Bytes ab Offset 8), setzt
 *   die Eintragsanzahl *(short *)p1 auf 0 und berechnet die Schrittgeschwindigkeit *(short *)(p1 + 4) abhängig
 *   davon, ob ein Unterwasserkampf (f_0773b0) vorliegt, aus d_1bfb00 oder d_1bfafc.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Felder *(short *)(p1 + 4) und *(short *)(p1 + 6) speichern die Animationsverzögerung
 *   pro Schritt.
 === Ende Beschreibung === */
void f_09c780(int p1)
{
    f_145300((char *)p1 + 8, 0, 0xd2);
    *(short *)p1 = 0;
    if (f_0773b0(d_1c0004)) {
        signed char c = d_1bfb00;
        if (!c)
            *(short *)(p1 + 4) = 5;
        else
            *(short *)(p1 + 4) = (short)(c * 4 + 1);
    } else {
        signed char c = d_1bfafc;
        *(short *)(p1 + 4) = (short)(c * 4 + 2);
    }
    *(int *)(p1 + 0xde) = 0;
    *(short *)(p1 + 6) = *(short *)(p1 + 4);
    *(int *)(p1 + 0xda) = 0;
}
//@ f_09c800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt der Kampf-Animationswarteschlange p1 (sofern weniger als 14 Einträge vorhanden sind)
 *   einen vollständigen 14-Byte-Eintrag mit zwei Koordinaten/Werten (p2, p3) und zwei Paaren aus Aktionsart und
 *   Zielwert (p4/p5 sowie p6/p7) hinzu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 (short *) sowie die sechs
 *   Eintragsparameter p2 bis p7 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zähler *p1 begrenzt die Warteschlange auf maximal 14 Einträge (0xe) zu je 14 Bytes.
 === Ende Beschreibung === */
void f_09c800(short *p1, int p2, short p3, signed char p4, int p5, int p6, int p7)
{
    p1[*p1 * 7 + 4] = (short)p2;
    p1[*p1 * 7 + 5] = (short)p3;
    *(char *)(p1 + *p1 * 7 + 6) = (char)p4;
    *(int *)((char *)p1 + *p1 * 0xe + 0xd) = p5;
    *(char *)((char *)p1 + *p1 * 0xe + 0x11) = (char)p6;
    *(int *)(p1 + *p1 * 7 + 9) = p7;
    if (*p1 < 0xe) *p1 = *p1 + 1;
}
//@ f_09c890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt der Kampf-Animationswarteschlange p1 einen 14-Byte-Eintrag hinzu, bei dem beide
 *   Aktionspaare denselben Typ p4 und denselben Parameter p5 erhalten.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 (short *) sowie die Parameter p2, p3,
 *   p4 und p5 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Wie in f_09c800 wird *p1 bis maximal 14 (0xe) erhöht.
 === Ende Beschreibung === */
void f_09c890(short *p1, int p2, int p3, int p4, int p5)
{
    int t383_8;
    p1[*p1 * 7 + 4] = (short)p2;
    p1[*p1 * 7 + 5] = (short)p3;
    *(char *)(p1 + *p1 * 7 + 6) = (char)p4;
    *(int *)((char *)p1 + *p1 * 0xe + 0xd) = p5;
    *(char *)((char *)p1 + *p1 * 0xe + 0x11) = (char)p4;
    *(int *)(p1 + *p1 * 7 + 9) = p5;
    if ((t383_8 = *p1) < 0xe) *p1 = *p1 + 1;
}
//@ f_09c910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt der Kampf-Animationswarteschlange p1 einen einfachen Bewegungseintrag mit den Werten p2
 *   und p3 ohne Zusatzaktionen (0) hinzu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 (short *) sowie die beiden Werte p2
 *   und p3 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Zusatzfelder an Offset +6, +0xd, +0x11 und +9 des Eintrags werden auf 0 gesetzt.
 === Ende Beschreibung === */
void f_09c910(short *p1, int p2, int p3)
{
    p1[*p1 * 7 + 4] = (short)p2;
    p1[*p1 * 7 + 5] = (short)p3;
    *(char *)(p1 + *p1 * 7u + 6) = 0;
    *(int *)((char *)p1 + *p1 * 0xe + 0xd) = 0;
    *(char *)((char *)p1 + *p1 * 0xe + 0x11) = 0;
    *(int *)(p1 + *p1 * 7 + 9) = 0;
    if (*p1 < 0xe) *p1 = *p1 + 1;
}
//@ f_09c990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet die Ausführung der Kampf-Animationswarteschlange p1 (*(int *)(p1 + 0xda) = 1),
 *   arbeitet alle Animationsschritte in einer Schleife über f_0757f0(d_1bd914) ab und aktualisiert abschließend
 *   den linken Kampfbildschirmbereich (0, 140 bis 90, 199) über f_0762e0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Warteschlangenzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Kampfanzeige-Objekt d_1bd914 führt die einzelnen Bildschirmschritte aus.
 === Ende Beschreibung === */
void f_09c990(int p1)
{
    *(int *)(p1 + 0xda) = 1;
    do {
        f_146dfa(d_1c2edc, 1);
    } while (f_0757f0(d_1bd914) == 1);
    f_0762e0(0, 0x8c, 0x5a, 199);
    f_0757f0(d_1bd914);
}
