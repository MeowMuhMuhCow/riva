/* === Beschreibung (Katalog) ===
 * Einheit gz_1099f0_t1 (1099f0 - 10a240)
 *
 * Überblick
 *
 * Die Einheit gz_1099f0_t1 bildet den ersten Teil des grafischen Handels- und Feilschen-Dialogs für Läden und
 * Marktstände. Sie enthält den Aufbau des Warensortiments, die Darstellung der Angebots- und Inventarlisten
 * sowie die Preisberechnung beim Einkaufen und Verkaufen (f_1099f0 bis f_10a200).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// OPT -4r -oneatx -zp1 -s
// P3 26/36 gleich (suche.py 26.10.2026, Basis gz_1099f0_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 12 gleich (vorher 12), Rest 622 (vorher 626)
// gz_1099f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1099F0-0x10AAD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"
#include "R_FIX.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01c840(int p1);                                   // reg eax stapel 0
void f_01f350(int p1, short p2);
int f_02de80(int p1, int p2);                           // reg edx stapel 0
int f_02de90(int p1, int p2);                           // reg eax edx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_03aa20(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_03c860(int p1);                                   // reg eax stapel 0
int f_040cb0(int p1, short p2, int p3, short p4, short p5);
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bd350(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
short f_0bf820(int, ...);
short f_0dbfe0(int p1);
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040(int, int, int, int, int, int);                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de5a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de5d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_1094e0(int p1);                                   // reg eax stapel 0
int f_10ad70(int p1, int p2);                           // reg eax edx stapel 0
int f_11e760(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_11e8f0();                                         // reg - stapel 0
int f_11e900();                                         // reg - stapel 0
int f_11e910(int p1, int p2, int p3, int p4);           // reg - stapel 0
int __stdcall f_11e960(int p1);                         // reg - stapel 4 R59 __stdcall?
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_149d20();                                         // reg - stapel 0
int f_14a1d0(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_14b3d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14bb40(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg - stapel 12
#include <bios.h>
extern int d_1bb87c[];
extern int d_1bb890[];
extern int d_1c2c64, d_1c2c44, d_1c27a8, d_1c21b4, d_1bf230;
extern int d_1c0004;
extern short d_1bc760;
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c3498[];
extern signed char d_1c03ac, d_1c03b0;
extern volatile signed char d_1c03b4; // verhindert Zusammenfassung der Schreibzugriffe auf d_1c03b4 in f_109f30
extern short d_1c03b8;
extern volatile short d_1c219a; // haelt unmittelbare Wort-Schreibfolge in f_1099f0 wie im Original
extern volatile short d_1c2198; // haelt unmittelbare Wort-Schreibfolge in f_1099f0 wie im Original
extern int d_1c21b0;
extern const char d_1a0710[];
extern const char d_1b8354[];

signed char f_126420(int p1);
signed char f_1265a0(int p1);

int __stdcall f_11e730(int p1);
int __stdcall f_14bb10(int p1);
int f_14d040(const char *fmt, ...);
int f_14d0e4(const char *fmt, ...);
int f_145234(int p1, int p2);
int f_145254();
int f_03aa20(int p1, int p2, int p3, int);
int f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_1094e0();
int f_10ad70(int p1, int p2);
int f_14b3d0(int p1);
int f_14b3d0_stack(int p1);
#pragma aux f_14b3d0_stack "f_14b3d0" parm [] modify [eax ebx ecx edx];
int f_14a1d0_call(int p1, int p2);
#pragma aux f_14a1d0_call "f_14a1d0" parm [] modify [eax ebx ecx edx];
int f_11e910_all8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
#pragma aux f_11e910_all8 "f_11e910" parm caller [] modify [eax ebx ecx edx];
unsigned char __stdcall f_11e760(short p1, short p2);
void f_10a170(int p1);
#define OBJ RivaTextContext o(d_1c349c, d_1c3870, d_1c3498)
#define C64 ((int)&d_1c2c64)
#define C44 ((int)&d_1c2c44)
#define POLL key = 0; rd = 0; if (d_1c219a != 0) { f_0bbf00((int)&d_1bf230); rd = _bios_keybrd(1); } if (rd) key = _bios_keybrd(0);
#define KEYCOND (f_0d3780() != 0 || f_0d37b0() != 0 || key == 0x11b || key == 0x3920 || key == 0x4900 || key == 0x5100)

static inline int EQBF(const signed char &x,int v){return x==v;}
static inline int EQN(int a, int b) { return a == b; }
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_02dee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese extern definierte Hilfsfunktion ist im Kopfbereich vorwärtsdeklariert und dient der Text- oder
 *   Listenformatierung.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_02dee0(short *p1)
;
//@ f_1099f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Handelsfenster-Objekt, richtet die Warenlisten und Schaltflächen
 *   für den Kauf- und Verkaufsmodus ein und verknüpft das Fenster mit dem aktuellen Händlerdatensatz.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie die Händler- und Modusparameter (p2, p3).
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_1099f0(void)
{
    int p;
    short s;
    p = f_038d70(d_1c0004, 0x200001bf);
    if (p != 0) {
        s = f_03aa20(p, 0, 1, -1);
        if (s != -3) {
            d_1c2198 = 0;
            d_1c219a = 1;
            f_125ed0(C44, 0x1e);
        }
    }
}
//@ f_109a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt die vom Handelsfenster angelegten Warenlisten, Icons und Textpuffer wieder
 *   frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 (sowie optionale Destruktor-Flags p2).
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_109a50(int p1)
{
    short r = 0;
    OBJ;
    f_01f350(d_1c0004, 0x15);
    *(int *)(p1 + 0x66) = f_038d70(d_1c0004, 0x19000002);
    if (*(int *)(p1 + 0x66) != 0) {
        short t = (short)f_040cb0(*(int *)(p1 + 0x66), *(short *)(p1 + 0x5e), *(int *)(p1 + 0x60), 0, 0);
        *(int *)(o.slots[0] + 4) = *(int *)(p1 + 0x66);
        *(int *)(o.slots[3] + 4) = *(int *)(p1 + 2);
#if FIX_R027   /* R027: Gekappten Rabattprozentsatz (max. 30 %) anzeigen und 16-Bit-Ueberlauf beim Rabattbetrag vermeiden */
        r = (short)f_0bd350(t, 0, 0x1e);
        *(short *)(o.slots[4] + 2) = r;
        unsigned char b = (r != 0);
        f_0bf730(C64, 0x19000004 + b);
        return (r * *(int *)(p1 + 0x60)) / 100;
#else
        *(short *)(o.slots[4] + 2) = t;
        r = (short)f_0bd350(t, 0, 0x1e);
        unsigned char b = (r != 0);
        f_0bf730(C64, 0x19000004 + b);
        r = (short)((r * *(int *)(p1 + 0x60)) / 100);
#endif
    }
    return r;
}
//@ f_109b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode stellt das Warensortiment des Händlers für die Anzeige zusammen und filtert Gegenstände
 *   nach Verfügbarkeit und Ladentyp.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verfügbaren Waren zurück.
 === Ende Beschreibung === */
void f_109b20(int p1)
{
    OBJ;
    f_0db8b0(d_1c0004, *(int *)(p1 + 0x60));
    f_040370((int)&d_1c27a8, *(int *)(p1 + 0x60));
    *(int *)(o.slots[0] + 4) = *(int *)(p1 + 0x66);
    *(int *)(o.slots[3] + 4) = f_133fe0((int)d_1c3498, (int)&d_1c27a8);
    f_0bf730(C64, 0x19000006);
}
//@ f_109ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode sammelt alle verkäuflichen Gegenstände aus den Inventaren der Heldengruppe für den
 *   Verkaufsmodus des Ladens.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verkäuflichen Gegenstände zurück.
 === Ende Beschreibung === */
void f_109ba0(int p1)
{
    OBJ;
    int t;
    f_0db820(d_1c0004, *(int *)(p1 + 0x60));
    f_040370((int)&d_1c27a8, *(int *)(p1 + 0x60));
    *(int *)(o.slots[0] + 4) = *(int *)(p1 + 0x66);
    t = f_133fe0((int)d_1c3498, (int)&d_1c27a8);
    *(int *)(o.slots[3] + 4) = t;
    f_0bf730(C64, 0x19000007);
}
//@ f_109c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert die Hauptinteraktion im Handelsfenster: Sie verarbeitet die Auswahl und
 *   Stückzahl der Waren, berechnet die Gesamtsumme in Dukaten, Silbertalern, Hellern und Kreuzern und ruft bei
 *   Abschluss die Feilschen-Probe (f_109f30) sowie die Waren- und Geldübergabe auf.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Abschlussstatus des Handels zurück.
 === Ende Beschreibung === */
int f_109c20(int p1)
{
    int r, c, h;
    r = 0;
    if (EQB(d_1c03ac, 1)) {
        if (f_0de7e0(d_1c0004) >= 0x2328) {
            if (f_0bf6f0(C64, 0x2200006a) == 1) {
                f_0db8b0(d_1c0004, 0x2328);
                d_1c03ac = 0;
                f_0bf730(C64, 0x2200006b);
            }
        }
    } else if (EQB(d_1c03b0, 0)) {
        c = 0;
        switch (f_0bf820(C64, 0x2200006c, 3, 0x2200006d, 0x2200006e, 0x2200006f)) {
        case 1:
            if (f_0bf820(C64, 0x22000070, 2, 0x2200006e, 0x2200006f) != 1) {
                c = 1;
            }
            break;
        case 2:
            break;
        default:
            c = 1;
        }
        if (c == 0) {
            OBJ;
            *(int *)(o.slots[0] + 4) = f_038c40(d_1c0004);
            f_0bf730(C64, 0x22000071);
            if (f_0de7e0(d_1c0004) < 0x2274) {
                f_0bf730(C64, 0x22000072);
                d_1c03ac = 1;
            } else {
                h = f_0dd3a0(d_1c0004, 6, 0);
                f_0bf730(C64, 0x22000073);
                if (h != 0) {
                    *(int *)(o.slots[0] + 8) = h;
                    f_0bf730(C64, 0x22000074);
                    f_0db8b0(d_1c0004, 0x2260);
                } else {
                    f_0db8b0(d_1c0004, 0x2274);
                }
            }
            if (f_0dbfe0(d_1c0004) > 1) {
                h = f_039660(d_1c0004, 1);
                while (h == f_038c40(d_1c0004)) {
                    h = f_038ba0(d_1c0004);
                }
                *(int *)(o.slots[0] + 0xc) = h;
                f_0bf730(C64, 0x22000075);
                f_0bf730(C64, 0x22000076);
                f_125f70(C44, 6);
                f_0bf730(C64, 0x22000077);
                h = f_038c40(d_1c0004);
                do {
                    f_0d5040(h, (short)f_0d4c80(h), 0x1fa40, 6, -3, 0);
                    h = f_0391b0(d_1c0004, h);
                } while (h != f_038c40(d_1c0004));
            } else {
                h = f_038c40(d_1c0004);
                f_0bf730(C64, 0x22000078);
                f_125f70(C44, 8);
                f_0bf730(C64, 0x22000079);
                f_0d5040(h, (short)f_0d4c80(h), 0x1fa40, 6, -5, 0);
            }
            f_0db820(d_1c0004, 0x23f0);
            d_1c03b0 = 1;
            return 1;
        }
    } else {
        f_1094e0(p1);
    }
    return r;
}

struct Time773 {
 static inline signed char get() { return (signed char)d_1c03b8; }
 static inline void init(short &a, short &b) { a=0;b=0; }
 static inline void split(short v, short &a, short &b) { a=v/24;b=v%24; }
};
//@ f_109f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt beim Kaufen oder Verkaufen die Feilschen-Talentprobe des ausgewählten Helden
 *   gegen den Aufschlag bzw. Rabatt des Händlers durch, prüft die Geduld des Händlers und passt den Endpreis um
 *   den ausgehandelten Prozentsatz an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den gewünschten Rabattprozentsatz p2.
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Preisverhandlung zurück (Erfolg, Ablehnung oder Rauswurf
 *   aus dem Laden).
 === Ende Beschreibung === */
void f_109f30(int p1)
{
    OBJ;
    if (EQ(d_1c03b4, 1)) {
        short a,b;
        Time773::init(a,b);
        short v;
        
        
        v = Time773::get() - 1;
        if (v < 0) v = 0;
        Time773::split(v,a,b);
        if (a > 1) {
            f_0bf730(C64, 0x2200007a);
        } else if (a == 1) {
            f_0bf730(C64, 0x2200007b);
            return;
        } else if (a == 0 && b > 0) {
            if (b > 1) {
                *(short *)(o.slots[4] + 2) = b;
                f_0bf730(C64, 0x2200007c);
                return;
            } else if (b == 1) {
                f_0bf730(C64, 0x2200007d);
                return;
            }
        } else {
            f_0bf730(C64, 0x2200007e);
            f_0dcf00(d_1c0004, 0x168, 1);
            f_0dcf00(d_1c0004, 0x169, 1);
            d_1c03b4 = 0;
            return;
        }
    } else {
        int q = f_038d70(d_1c0004, 0x2200007f);
        if (q) {
            int n = f_0428b0((struct hero *)(q)) * 10;
            if (f_0de7e0(d_1c0004) >= n) {
                *(short *)(o.slots[4] + 2) = n / 10;
                f_0bf730(C64, 0x22000081);
                f_0db8b0(d_1c0004, n);
                d_1c03b4 = 1;
                f_10a170(p1);
            } else {
                f_040370((int)&d_1c21b4, n);
                int r = f_133fe0((int)d_1c3498, (int)&d_1c21b4);
                *(int *)(o.slots[3] + 4) = r;
                f_0bf730(C64, 0x22000080);
                return;
            }
        }
    }
}
//@ f_10a170
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode überträgt nach einem erfolgreichen Einkauf die ausgewählten Waren in die Inventare der
 *   Helden und zieht den Kaufpreis vom Gruppengold ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Status der Transaktion zurück.
 === Ende Beschreibung === */
void f_10a170(int p1)
{
    short n;
    short k;
    short cnt, e;
    short u;

    n = f_145760(0, 4) + 10;
    u = f_126410(C44) / 0x1518;
    cnt = 0;
    k = f_126420(C44);
    while (0 < n) {
        if ((short)u < *(short *)(p1 + 0x40 + k * 2)) {
            u = u + 1;
            cnt = cnt + 1;
            n = n - 1;
        }
        if ((short)u == *(short *)(p1 + 0x40 + k * 2)) {
            e = 0x18 - u;
            cnt = cnt + e;
            k = f_1265a0(C44);
            u = *(short *)(p1 + 0x32 + k * 2);
            cnt = cnt + u;
        }
    }
    signed char out = (signed char)cnt;
    ++out;
    *(signed char *)&d_1c03b8 = out;
}
//@ f_10a200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode entfernt nach einem erfolgreichen Verkauf die verkauften Gegenstände aus dem
 *   Heldeninventar und schreibt den Erlös dem Gruppengold gut.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a200(int p1, short *p2, short *p3)
{
    signed char c;
    short v;
    short i;
    c = (signed char)d_1c03b8;
    v = c - 1;
    if (v < 0) v = 0;
    i = v;
    *p2 = i / 0x18;
    *p3 = i % 0x18;
}
//@ f_10a240
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese achtundzwanzig Funktionen sind im gemeinsamen Kopfbereich deklariert und werden in den
 *   nachfolgenden Teileinheiten gz_1099f0_t2 und gz_1099f0_t3 definiert.
 * - Eingaben: Siehe gz_1099f0_t2.md und gz_1099f0_t3.md.
 * - Rückgabewert: Siehe gz_1099f0_t2.md und gz_1099f0_t3.md.
 === Ende Beschreibung === */
int f_10a240(void)
;
//@ f_10a250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze virtuelle Platzhaltermethode des Laden-/Gebäudeobjekts gibt konstant 0 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
int f_10a250(void)
;
//@ f_10a260
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Laden- oder Stadtgebäudeobjekt über den Basiskonstruktor
 *   f_02de80 und setzt dessen virtuelle Methodentabelle bei Offset +0x58 auf d_1bb890.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Gebäudekennung p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a260(int p1, int p2)
;
//@ f_10a270
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Gebäudeobjekt der Klasse d_1bb890 (d_1bb87c) über f_02de90 ab
 *   und gibt bei gesetztem Bit p2 & 2 den Objektspeicher frei.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger zurück.
 === Ende Beschreibung === */
int f_10a270(int p1, unsigned p2)
;
//@ f_10a2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere Funktion dient als Platzhaltermethode ohne eigene Wirkung.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a2b0(void)
;
//@ f_10a2c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser kurze Wrapper leitet den übergebenen Zeiger p1 direkt an die Hilfsfunktion f_02dee0 weiter.
 * - Eingaben: Die Funktion erhält den Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_02dee0(int);
void f_10a2c0(int p1) ;
//@ f_10a2d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze virtuelle Statusmethode gibt konstant 1 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_10a2d0(void)
;
//@ f_10a2e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler über ein Eingabefenster (0x220101b7), wie viele Stunden (bis zu p3)
 *   die Gruppe warten möchte, und lässt die Spieluhr stundenweise (f_125f70) bei laufender Hintergrundanimation
 *   (f_01c840) und Abbruchmöglichkeit (0x220101b8) voranschreiten.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1, den Mindestwert p2, die Maximalstundenzahl p3, das
 *   Gruppenstatus-Flag p4 sowie den Statuswert p5.
 * - Rückgabewert: Die Funktion gibt die Anzahl der tatsächlich abgewarteten Stunden zurück (short).
 === Ende Beschreibung === */
short f_10a2e0(int p1, int p2, int p3, short p4, int p5)
;
//@ f_10a450
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion rechnet eine Zeitspanne p2 aus Spielzeit-Ticks in volle Stunden (0x1518 Ticks) um und
 *   spult die Spieluhr stundenweise (f_125f70) mit Animationsaktualisierung und optionaler Unterbrechung
 *   (0x220101b8) vor.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1, die Tick-Anzahl p2, das Gruppenstatus-Flag p3 sowie den
 *   Statuswert p4.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verstrichenen Stunden zurück (short).
 === Ende Beschreibung === */
short f_10a450(int p1, unsigned p2, int p3, short p4)
;
//@ f_10a5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt die Spielzeit um p2 Tage und p3 Stunden (p2 * 24 + p3 Stunden) voranschreiten,
 *   aktualisiert in jeder Stunde die Raum-Animation (f_01c840) und erlaubt dem Spieler das vorzeitige Abbrechen
 *   über die Rückfrage 0x220101b8.
 * - Eingaben: Die Funktion erhält einen ungenutzten Parameter p1, die Tagesanzahl p2, die Stundenanzahl p3, das
 *   Status-Flag p4 sowie den Statuswert p5.
 * - Rückgabewert: Die Funktion gibt die Anzahl der abgelaufenen Stunden zurück (int).
 === Ende Beschreibung === */
int f_10a5a0(short p1, short p2, short p3, int p4, int p5)
;
//@ f_10a6d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler einen Helden auswählen (0x200001be), prüft über f_042520, ob dieser
 *   verfügbar ist (sonst Meldung 0x200001c0), führt für ihn die Aktion f_03c860 aus und addiert bei Erfolg 30
 *   Minuten Spielzeit (f_125ed0).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a6d0(void)
;
//@ f_10a730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft während einer Warteschleife auf Tastatur- oder Mausklicks und fragt den
 *   Spieler über das Dialogfenster 0x220101b8, ob das Warten abgebrochen werden soll.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Spieler den Abbruch bestätigt, sonst 0.
 === Ende Beschreibung === */
int f_10a730(void)
;
//@ f_10a7d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt bei aktiviertem Debug-/Textflag *(int *)(p1 + 0x10) die aktuelle Frame-Nummer
 *   *(short *)(p1 + 0x16) des Smacker-Video-Players über f_14d0e4 aus.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a7d0(int p1)
;
//@ f_10a7f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine Smacker-Videodatei über f_14bb40, speichert das Handle in *p1 und trägt
 *   Breite (+4), Höhe (+8) sowie Frame-Anzahl (+0xc) in die Ausgabeparameter *p3, *p4 und *p5 ein.
 * - Eingaben: Die Funktion erhält den Objekt-/Handle-Zeiger p1, die Dateikennung p2 sowie die Ausgabezeiger p3,
 *   p4 und p5.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a7f0(int *p1, int p2, short *p3, short *p4, short *p5)
;
//@ f_10a830
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest aus dem Smacker-Handle *p1 die Videobreite (+4), die Videohöhe (+8) und
 *   die Gesamtframezahl (+0xc) in die Zeiger p2, p3 und p4 aus.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die drei 16-Bit-Ausgabezeiger p2, p3 und p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a830(int *p1, short *p2, short *p3, short *p4)
;
//@ f_10a850
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert bei noch nicht aktivierter Videoausgabe (*(int *)(p1 + 0xc) == 0) das
 *   Anzeigesystem über f_11e730(1) und setzt den Frame-Index (+0x16) sowie das Aktiv-Flag (+0xc) auf 1.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_11e730x(int);
#pragma aux f_11e730x "f_11e730" parm [] modify [eax ebx ecx edx];
void f_10a850(int p1)
;
//@ f_10a880
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stellt wie f_10a850 die Initialisierung des Video-Subsystems (f_11e730(1)) sicher und
 *   richtet anschließend über f_11e960(p1 + 0x26) den Anzeigekontext ein.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a880(int p1)
;
//@ f_10a8b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den aktuellen Frame-Index *(short *)(p1 + 0x16) auf 1 zurück und spult das
 *   Smacker-Video über f_10ad70 auf den ersten Frame zurück.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a8b0(int p1)
;
//@ f_10a8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert den aktuellen 16-Bit-Frame-Index *(short *)(p1 + 0x16) des
 *   Video-Players zurück.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion gibt die aktuelle Frame-Nummer (short) zurück.
 === Ende Beschreibung === */
short f_10a8d0(int p1)
;
//@ f_10a8e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode setzt das Anzeige- bzw. Debug-Flag bei Offset +0x10 des Video-Players p1 auf
 *   den Wert p2.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den neuen Flag-Wert p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a8e0(int p1, int p2)
;
//@ f_10a8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode ruft, sofern bei Offset +0x1c des Video-Players p1 ein gültiger Callback-Zeiger (!= 0
 *   und != -1) hinterlegt ist, diese Funktion mit dem Parameter (short)p2 auf.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den Callback-Parameter p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a8f0(int p1, int p2)
;
//@ f_10a910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion übernimmt die im Smacker-Handle *p1 ab Offset +0x6c gespeicherte Farbpalette über
 *   f_14d040 in die aktive Bildschirm-Palette.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_14d040a(const char *p);
#pragma aux f_14d040a "f_14d040" parm caller [] modify [eax ecx edx];
void f_10a910(int *p1)
;
//@ f_10a930
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reicht den 16-Bit-Steuerparameter p2 an die Smacker-Hilfsfunktion f_14bb10 weiter.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den Parameter p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_14bb10x(int);
#pragma aux f_14bb10x "f_14bb10" parm [] modify [eax ebx ecx edx];
void f_10a930(int p1, short p2)
;
//@ f_10a940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion setzt alle Status-, Positions- und Callback-Felder des
 *   Smacker-Player-Objekts p1 auf ihre Ausgangswerte (Frame = 1, übrige Felder 0).
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a940(int p1)
;
//@ f_10a980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktiviert bei Bedarf die Videoausgabe (f_11e730(1)), schaltet über f_11e760(p3, p2)
 *   und f_11e8f0 in den gewünschten Anzeigemodus und vermerkt den Moduswert p2 bei Offset +0x14.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die Modusparameter p2 und p3.
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Moduswechsel zurück, sonst 0.
 === Ende Beschreibung === */
unsigned char f_11e760_q(short, short);
#pragma aux f_11e760_q "f_11e760" parm [] modify [eax ebx ecx edx];
int f_10a980(int p1, short p2, short p3)
;
//@ f_10a9e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entspricht in Aufbau und Wirkung f_10a980: Sie initialisiert bei Bedarf das
 *   Video-Subsystem (f_11e730(1)), prüft und aktiviert über f_11e760(p3, p2) sowie f_11e8f0 den Bildschirmmodus
 *   und speichert p2 bei Offset +0x14.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die Modusparameter p2 und p3.
 * - Rückgabewert: Die Funktion gibt 1 bei Erfolg zurück, sonst 0.
 === Ende Beschreibung === */
unsigned char f_11e760_r(short, short);
#pragma aux f_11e760_r "f_11e760" parm [] modify [eax ebx ecx edx];
int f_10a9e0(int p1, short p2, short p3)
;
//@ f_10aa40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion setzt den Bildschirmmodus über f_11e900 zurück, sofern im Player-Objekt p1 bei
 *   Offset +0x14 ein aktiver Videomodus vermerkt ist.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10aa40(int p1);
#pragma aux f_10aa40 modify [eax];
int f_11e900_all();
#pragma aux f_11e900_all "f_11e900" parm [] modify [eax ebx ecx edx];
void f_10aa40(int p1)
;
//@ f_10aa60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_1099f0_t3) dekodiert das
 *   aktuelle Einzelbild des Smacker-Handles *p1 über f_14b3d0 und überträgt bei p2 == 1 in einer Schleife
 *   sämtliche geänderten Bildrechtecke (f_14a1d0) über f_11e910 unter Berücksichtigung der Zielposition (+0x1a,
 *   +0x18) in den Ausgabepuffer p1[1].
 * - Eingaben: Die Funktion erhält den Zeiger p1 (int *) auf das Smacker-Player-Objekt sowie das Kopier-Flag p2
 *   (int, 1 = geänderte Rechtecke kopieren).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *p1 (Smacker-Handle mit Rechteckfeldern +0x374..+0x380 und Breite +4), p1[1]
 *   (Zielpuffer).
 === Ende Beschreibung === */
void f_10aa60(int *p1, int p2)
;
