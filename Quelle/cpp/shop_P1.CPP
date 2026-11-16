/* === Beschreibung (Katalog) ===
 * Einheit shop (109430 - 1099f0)
 *
 * Überblick
 *
 * Die Einheit shop implementiert das Gebäude-Modul für Krämer- und Handelsläden in Riva. Sie steuert den
 * Eintritt in den Laden, die Auswahl zwischen Einkaufen, Verkaufen und Gespräch mit dem Händler sowie das
 * Feilschen über das Handelsfenster (f_1094e0, f_109800).
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVAMOUS.H"
// P3 2/4 gleich (suche.py 25.10.2026, Basis shop_P1.CPP)
// shop.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x109430-0x1099F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"
#include "R_FIX.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e0c0();                                         // reg - stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0dea00(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0dea70(int p1);                                   // reg eax stapel 0
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a68ec;                    // 0x1A68EC
extern int d_1bdbe4;                    // 0x1BDBE4
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile int d_1c0c94;           // haelt Lade-/Schreibfolge in f_1094e0/f_109800 wie im Original
extern int d_1c2c44;                    // 0x1C2C44
extern const char d_1a68c4[];           // Text 0x1A68C4
extern const char d_1a68e0[];           // Text 0x1A68E0
// --- eigene Funktionen (4), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
signed char f_126450(int p1);
short f_149360(int p1, int p2);
extern int d_1bfdb8[], d_1a34e0, d_1c2a80, d_1c27a8, d_1c21b4, d_1c0004;
extern volatile short d_1c2198;         // haelt Schreibfolge in f_1094e0 wie im Original
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
extern int d_1c2c64;
int f_0db8b0(int p1, int p2);
int f_0db820(int p1, int p2);
int f_040370(int p1, int p2);
int f_133fe0(int p1, int p2);
int f_09a140(int p1, int p2);
int f_0dffd0();
int f_0a8830(int p1, int p2, int p3);
int f_0a8be0(int p1);
int f_0a8b40(int p1, int p2);
int f_09a0d0(int p1);
int f_09a400();
int f_11c320(int p1);
int f_0dfdd0(int p1, int p2);
int f_11c120(int p1, int p2);
int f_09ade0(int p1, int p2, int p3);
int f_09a4c0(int p1, int p2);
int f_01dfd0(int p1);
int f_09aed0(int p1);
int f_0dfca0();
int f_0dfcf0();
int f_109a50(int p1);
int f_0dfef0();
int f_0bf730(int p1, int p2);
struct S30 { int a[12]; };
struct S5a { char c[0x5a]; };

#define SETP0 { char *pp = ob.slots[0]; int vv = *(int *)(p1 + 0x66); *(int *)(pp + 4) = vv; }
#define MBOX ((int)&d_1c2c64)

//@ f_109430
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Laden-Gebäudeobjekt, setzt die virtuelle Methodentabelle
 *   d_19e578, speichert die Händlerkennung und bereitet die Laden-Oberfläche vor.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Orts-/Händlerkennung p2 sowie das Konstruktor-Flag p3.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_109430(short *p1)
{
    void *o = operator new(1, mark(d_1a68c4, 0x99));
    f_11ea00((int)o, 0x22000d, (int)*p1, (int)(p1 + 0x37), 4);
    f_11ea00((int)o, 0x22005e, (int)*p1, (int)(p1 + 0x32), 4);
    if (f_126450((int)&d_1c2c44) == 8) {
        if (f_149360((int)*p1, (int)&d_1a68ec) != -1) {
            p1[0x37] = p1[0x37] - 4;
            p1[0x38] = p1[0x38] - 0x14;
        }
    }
    operator delete(o);
}

//@ f_1094d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Zugriffsmethode liefert konstant den Gebäudetyp 0 (regulärer Laden) zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_1094d0(void) { }

//@ f_1094e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hauptschleife steuert den Aufenthalt der Heldengruppe im Laden: Sie lädt das Händlerbild und
 *   den Begrüßungstext, präsentiert das Auswahlmenü (Kaufen, Verkaufen, Reden, Laden verlassen), öffnet das
 *   Kauf-/Verkaufsfenster (f_1099f0 ff.) und prüft, ob der Händler wegen unverschämten Feilschens verärgert den
 *   Handel abbricht.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Laden-Objekts.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode des Ladenbesuchs zurück.
 === Ende Beschreibung === */
void f_1094e0(int p1)
{
    short sa = d_1c0c94; // sichert globalen Zustand waehrend des Haendlerdialogs
    int sb = *d_1bfdb8;  // sichert globalen Zustand waehrend des Haendlerdialogs
    d_1c0c94 = 0;
    int &count=d_1c0c4c; ++count; // haelt die Registerzuteilung fuer d_1c0c4c wie im Original
    f_01e0c0();
    { RivaMouseGuard mg; f_09ac80(d_1a34e0, (int)d_1a68e0, d_1bdbe4); }
    S30 *o = new (mark(d_1a68c4, 0xd9)) S30;
    o = o ? (S30 *)f_0dea00((int)o, 0, (int)*(short *)(p1 + 100), (int)*(short *)(p1 + 0x6e), (int)*(short *)(p1 + 0x70), 0) : o;
    *(int *)(p1 + 0x6a) = (int)o;
    int r = f_0dea70((int)o);
    operator delete((void *)*(int *)(p1 + 0x6a));
    if (r == 1) {
        *(short *)(p1 + 0x5e) = f_0dfca0();
        *(int *)(p1 + 0x60) = f_0dfcf0();
        *(int *)(p1 + 0x60) -= f_109a50(p1);
#if FIX_R028   /* R028: Kaufpreis nach Feilschen-Abzug gegen negative Werte sichern */
        if (*(int *)(p1 + 0x60) < 0) *(int *)(p1 + 0x60) = 0;
#endif
        {
            RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
            f_0db8b0(d_1c0004, *(int *)(p1 + 0x60));
            f_040370((int)&d_1c27a8, *(int *)(p1 + 0x60));
            SETP0
            *(int *)(ob.slots[3] + 4) = f_133fe0((int)d_1c3498, (int)&d_1c27a8);
            f_0bf730(MBOX, 0x19000006);
        }
        f_09a140(0, 0x19);
        int h = f_0dffd0();
        S5a *q = new (mark(d_1a68c4, 0xf8)) S5a;
        q = q ? (S5a *)f_0a8830((int)q, h, 1) : q;
        int e = f_0a8be0((int)q);
        if (q) operator delete((void *)f_0a8b40((int)q, 0));
        f_09a0d0(d_1a34e0);
        f_09a400();
        if ((short)f_11c320(e) > 0) {
#if FIX_R037   /* R037: Bei nicht verteilten Kaufwaren vollen statt halbierten Kaufpreis erstatten */
            int t = f_0dfdd0(e, (int)*(short *)(p1 + 0x70)) * 2;
            if (t > *(int *)(p1 + 0x60)) t = *(int *)(p1 + 0x60);
#else
            int t = f_0dfdd0(e, (int)*(short *)(p1 + 0x70));
#endif
            RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
            f_0db820(d_1c0004, t);
            f_040370((int)&d_1c21b4, t);
            *(int *)(ob.slots[3] + 4) = *(int *)(p1 + 2);
            *(int *)(ob.slots[3] + 8) = f_133fe0((int)d_1c3498, (int)&d_1c21b4);
            f_0bf730(MBOX, 0x19000003);
        }
        if (e) operator delete((void *)f_11c120(e, 0));
        d_1c2a80 = 0;
        d_1c2198 = 1;
    } else {
        void *buf = operator new[](0xfa00, mark(d_1a68c4, 0x122));
        f_09ade0((int)buf, (int)d_1a68e0, d_1bdbe4);
        { RivaMouseGuard mg; f_09a4c0((int)buf, 1); }
        operator delete(buf);
        f_01dfd0(*(int *)(p1 + 0x22));
    }
    f_09aed0(0);
    d_1c0c4c--;
    d_1c0c94=sa;
    *d_1bfdb8 = sb;
}

//@ f_109800
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wickelt die Gesprächsoptionen mit dem Ladenbesitzer ab, zeigt gerüchte- oder
 *   questbezogene Dialogtexte an und schaltet bei Bedarf neue Themen oder Hinweise frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_109800(int p1)
{
    int r;
    short sa = d_1c0c94; // sichert globalen Zustand waehrend des Haendlerdialogs
    int sb = d_1bfdb8[0]; // sichert globalen Zustand waehrend des Haendlerdialogs
    d_1c0c94 = 0;
    int &count=d_1c0c4c; ++count; // haelt die Registerzuteilung fuer d_1c0c4c wie im Original
    f_01e0c0();
    { RivaMouseGuard mg; f_09ac80(d_1a34e0, (int)d_1a68e0, d_1bdbe4); }
    {
        int n = (int)new (mark(d_1a68c4, 0x152)) S30;
        n = n ? f_0dea00(n, 1, (int)*(short *)(p1 + 100), 0, (int)*(short *)(p1 + 0x70), 0) : n;
        *(int *)(p1 + 0x6a) = n;
        r = f_0dea70(n);
        operator delete((void *)*(int *)(p1 + 0x6a));
    }
    if (r == 1) {
        *(short *)(p1 + 0x5e) = f_0dfca0();
        *(int *)(p1 + 0x60) = f_0dfcf0();
        *(int *)(p1 + 0x60) += f_109a50(p1);
#if FIX_R028   /* R028: Verkaufserloes gegen 16-Bit-Ueberlauf ins Negative sichern */
        if (*(int *)(p1 + 0x60) < 0) *(int *)(p1 + 0x60) = 0;
#endif
        {
            RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
            f_0db820(d_1c0004, *(int *)(p1 + 0x60));
            f_040370((int)&d_1c27a8, *(int *)(p1 + 0x60));
            SETP0
            *(int *)(ob.slots[3] + 4) = f_133fe0((int)d_1c3498, (int)&d_1c27a8);
            f_0bf730(MBOX, 0x19000007);
        }
        f_0dfef0();
    }
    d_1c0c4c--;
    d_1c0c94=sa;
    d_1bfdb8[0] = sb;
    void *buf = operator new[](0xfa00, mark(d_1a68c4, 0x175));
    f_09ade0((int)buf, (int)d_1a68e0, d_1bdbe4);
    f_09aed0(0);
    { RivaMouseGuard mg; f_09a4c0((int)buf, 1); }
    operator delete(buf);
    f_01dfd0(*(int *)(p1 + 0x22));
}
