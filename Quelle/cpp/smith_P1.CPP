/* === Beschreibung (Katalog) ===
 * Einheit smith (10afd0 - 10b6a0)
 *
 * Überblick
 *
 * Die Einheit smith implementiert das Gebäude-Modul für die Schmieden in Riva. Dort kann die Heldengruppe
 * beschädigte oder verrostete Waffen und Rüstungen gegen Bezahlung reparieren lassen, den Reparaturpreis
 * aushandeln und nach Ablauf der Arbeitszeit wieder abholen (f_10afd0 bis f_10b520).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVACTX.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 4/5 gleich (suche.py 24.10.2026, Basis smith_P1.CPP)
// smith.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10AFD0-0x10B680
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0a8830(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0a8b40(int p1, int p2);                           // reg eax stapel 0
int f_0a8be0(int p1);                                   // reg eax stapel 0
int f_0b9060(int p1);                                   // reg eax stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0dea00(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0dea70(int p1);                                   // reg eax stapel 0
int f_0e0400(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e0530(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_109430(int p1);                                   // reg eax stapel 0
int f_1094e0(int p1);                                   // reg eax stapel 0
int f_109800(int p1);                                   // reg eax stapel 0
int f_11c120(int p1, int p2);                           // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1bc760;                    // 0x1BC760
extern int d_1bdbe4;                    // 0x1BDBE4
extern int d_1c0c4c;                    // 0x1C0C4C
extern volatile int d_1c0c94;           // 0x1C0C94: haelt die Speicherzugriffe in f_10b2f0/f_10b520 wie im Original
                    // 0x1C2098
extern int d_1c2a80;                    // 0x1C2A80
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1a6bf0[];           // Text 0x1A6BF0
// --- eigene Funktionen (5), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
extern volatile short d_1c2198;         // haelt die Schreibreihenfolge in f_10b520 wie im Original
extern int d_1c2c44;
extern int d_1bfdb8;
int f_0dfca0();
int f_0dfcf0();
int f_109a50(int p1);
int f_109b20(int p1);
signed char f_126420(int p1);
int f_126410(int p1);
int f_0e0250(int p1, int p2, int p3);
int f_0dfef0();
int f_09ade0(int p1, int p2, int p3);
int f_09a4c0(int p1, int p2);
int f_09aed0(int p1);
int f_01c120(int p1, int p_h);
int f_0e0400(int p1, int p2, int p3);
void f_10b2f0(int p1);
void f_10b520(int p1);

struct S30 { char b[0x30]; };
struct S5A { char b[0x5a]; };
#define CH ((int)&d_1c2c64)
#define DS ((int)&d_1c2098)
//@ f_10afd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Schmiede-Gebäudeobjekt, setzt die virtuelle Methodentabelle
 *   d_19e660 und speichert die Schmiedekennung.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1, die Schmiedekennung p2 sowie das Konstruktor-Flag p3.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
void f_10afd0(int p1)
{
    int y;
    int x;
    f_109430(p1);
    if (((RivaFileManager*)(DS))->f_1448b0( 0x401a0001, 0x200) == 1) {
        do {
            x = -1;
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&x), 2)));
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&y), 2)));
            if ((short)x != -1) {
                if ((short)x == *(unsigned short *)p1) {
                    *(short *)(p1 + 0x72) = (short)y;
                    if ((short)y > 0) {
                        void *t = mark(d_1a6bf0, 0x54);
                        int n = (int)operator new[]((short)*(short *)(p1 + 0x72) * 0xf, t);
                        *(int *)(p1 + 0x74) = n;
                        ((int)(((RivaFileManager*)(DS))->f_144920((void *)( n), (short)*(short *)(p1 + 0x72) * 0xf)));
                    } else {
                        *(int *)(p1 + 0x74) = 0;
                    }
                } else {
                    ((RivaFileManager*)(DS))->f_144ab0( (short)y * 0xf, 1);
                }
            }
        } while ((short)x != *(unsigned short *)p1 && (short)x != -1);
        ((RivaFileManager*)(DS))->f_1449a0();
    }
}
//@ f_10b0c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert den Besuch in der Schmiede: Sie begrüßt die Gruppe, prüft, ob ein zuvor in
 *   Auftrag gegebener Gegenstand fertig repariert ist, und bietet das Auswahlmenü (Waffe/Rüstung reparieren
 *   lassen, Feilschen, Reden, Schmiede verlassen) an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 des Schmiede-Objekts.
 * - Rückgabewert: Die Funktion gibt den Ergebniscode des Schmiedebesuchs zurück.
 === Ende Beschreibung === */
void f_10b0c0(int p1)
{
    int x = 0;
    int y = 0;
    int buf = 0;
#if FIX_R010   /* R010: Kennung und Anzahl des anderen Schmieds separat sichern statt mit EOF (-1) zu ueberschreiben */
    short ox = -1;
    short oy = 0;
    if (((RivaFileManager*)(DS))->f_1448b0( 0x401a0001, 0x220) == 1) {
        do {
            x = -1;
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&x), 2)));
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&y), 2)));
            if ((short)x != -1) {
                if ((short)x != *(unsigned short *)p1) {
                    ox = (short)x;
                    oy = (short)y;
                    if (buf) { operator delete((void *)buf); buf = 0; }
                    if ((short)y > 0) {
                        void *t = mark(d_1a6bf0, 0x87);
                        buf = (int)operator new[]((short)y * 0xf, t);
                        ((int)(((RivaFileManager*)(DS))->f_144920((void *)( buf), (short)y * 0xf)));
                    }
                } else {
                    ((RivaFileManager*)(DS))->f_144ab0( (short)y * 0xf, 1);
                }
            }
        } while ((short)x != -1);
        ((RivaFileManager*)(DS))->f_1449a0();
    }
    if (((RivaFileManager*)(DS))->f_1448b0( 0x401a0001, 0x221) == 1) {
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( p1), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( p1 + 0x72), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( *(int *)(p1 + 0x74)), (short)*(short *)(p1 + 0x72) * 0xf)));
        if (ox != -1) {
            ((int)(((RivaFileManager*)(DS))->f_144960((void *)( (int)&ox), 2)));
            ((int)(((RivaFileManager*)(DS))->f_144960((void *)( (int)&oy), 2)));
            if (oy > 0 && buf) ((int)(((RivaFileManager*)(DS))->f_144960((void *)( buf), oy * 0xf)));
        }
        ((RivaFileManager*)(DS))->f_1449a0();
    }
#else
    if (((RivaFileManager*)(DS))->f_1448b0( 0x401a0001, 0x220) == 1) {
        do {
            x = -1;
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&x), 2)));
            ((int)(((RivaFileManager*)(DS))->f_144920((void *)( (int)&y), 2)));
            if ((short)x != -1) {
                if ((short)x != *(unsigned short *)p1) {
                    if ((short)y > 0) {
                        void *t = mark(d_1a6bf0, 0x87);
                        buf = (int)operator new[]((short)y * 0xf, t);
                        ((int)(((RivaFileManager*)(DS))->f_144920((void *)( buf), (short)y * 0xf)));
                    } else {
                        buf = 0;
                    }
                } else {
                    ((RivaFileManager*)(DS))->f_144ab0( (short)y * 0xf, 1);
                }
            }
        } while ((short)x != -1);
        ((RivaFileManager*)(DS))->f_1449a0();
    }
    if (((RivaFileManager*)(DS))->f_1448b0( 0x401a0001, 0x221) == 1) {
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( p1), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( p1 + 0x72), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( *(int *)(p1 + 0x74)), (short)*(short *)(p1 + 0x72) * 0xf)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( (int)&x), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( (int)&y), 2)));
        ((int)(((RivaFileManager*)(DS))->f_144960((void *)( buf), (short)y * 0xf)));
        ((RivaFileManager*)(DS))->f_1449a0();
    }
#endif
    if (buf) operator delete((void *)buf);
    if (*(int *)(p1 + 0x74) != 0) {
        operator delete((void *)*(int *)(p1 + 0x74));
        *(int *)(p1 + 0x74) = 0;
    }
}
//@ f_10b270
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Filter-Prädikat prüft für einen Inventargegenstand p1, ob es sich um eine beschädigte Waffe
 *   oder Rüstung handelt, die vom Schmied repariert werden kann.
 * - Eingaben: Die Funktion erhält den Gegenstandszeiger p1.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Gegenstand reparierbar ist, andernfalls 0.
 === Ende Beschreibung === */
int f_10b270(int p1, unsigned short p2)
{
    int r = 0;
    switch (p2) {
    case 0: break;
    case 0x81: f_0b9060(p1); break;
    case 0x87: f_1094e0(p1); break;
    case 0x88: f_109800(p1); break;
    case 0x8a: f_10b2f0(p1); break;
    case 0x8b: f_10b520(p1); break;
    case 0x80: r = 1; break;
    }
    return r;
}
//@ f_10b2f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode wickelt die Auswahl eines beschädigten Ausrüstungsstücks, die Berechnung der
 *   Reparaturkosten, das optionale Feilschen mit dem Schmied und die Beauftragung bzw. sofortige Instandsetzung
 *   des Gegenstands ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10b2f0(int p1)
{
    int r;
    short sv = (short)d_1c0c94;
    int sv2 = d_1bfdb8; // sichert und restauriert d_1bfdb8 ueber den Schmiededialog wie im Original
    d_1c0c94 = 0;
    d_1c0c4c = d_1c0c4c + 1;
    f_01cef0(d_1bc760);
    {
        RivaMouseGuard g1;
        f_09ac80(d_1a34e0, 0, d_1bdbe4);
    }
    {
        int n = (int)new (mark(d_1a6bf0, 0x10a)) S30;
        n = n ? f_0dea00(n, 4, 4, -1, (short)*(short *)(p1 + 0x70), 0) : n;
        *(int *)(p1 + 0x6a) = n;
        r = f_0dea70(n);
        operator delete((void *)*(int *)(p1 + 0x6a));
    }
    if (r == 1) {
        RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
        *(short *)(p1 + 0x5e) = f_0dfca0();
        *(int *)(p1 + 0x60) = f_0dfcf0();
        *(int *)(p1 + 0x60) = *(int *)(p1 + 0x60) - f_109a50(p1);
        f_109b20(p1);
        *(int *)(ob.slots[3] + 4) = *(int *)(p1 + 2);
        {
            int sk = *(short *)(p1 + (int)f_126420((int)&d_1c2c44) * 2 + 0x40);
            if (f_126410((int)&d_1c2c44) / 0x1518 > sk - 6) {
                f_0bf730(CH, 0x1a000003);
            } else {
                f_0bf730(CH, 0x1a000004);
            }
        }
        *(int *)(p1 + 0x74) = f_0e0250(*(short *)(p1 + 0x5c), p1 + 0x72, *(int *)(p1 + 0x74));
        f_0dfef0();
    }
    if (r != -1) {
        int q = (int)operator new[](0xfa00, mark(d_1a6bf0, 0x13f));
        {
            RivaMouseGuard g2;
            f_09ade0(q, 0, d_1bdbe4);
            f_09a4c0(q, 1);
        }
        operator delete((void *)q);
    }
    f_09aed0(0);
    f_01c120(d_1bc760, 5);
    d_1c0c4c = d_1c0c4c - 1;
    d_1c0c94 = sv;
    d_1bfdb8 = sv2;
}
//@ f_10b520
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt die Feilschen-Probe des Helden beim Verhandeln über den Reparaturpreis in der
 *   Schmiede durch und passt den Preis bzw. die Laune des Schmieds entsprechend an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den geforderten Nachlass p2.
 * - Rückgabewert: Die Funktion gibt den Status der Preisverhandlung zurück.
 === Ende Beschreibung === */
void f_10b520(int p1)
{
    if (*(short *)(p1 + 0x72) == 0) {
        f_0bf730(CH, 0x1a000001);
    } else {
        int r = f_0e0400(*(short *)(p1 + 0x5c), p1 + 0x72, *(int *)(p1 + 0x74));
        if (r == 0) {
            RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
            *(int *)(ob.slots[3] + 4) = *(int *)(p1 + 2);
            f_0bf730(CH, 0x1a000002);
            return;
        }
        short sv = (short)d_1c0c94;
        f_09a140(0, 0x19);
        d_1c0c94 = 0;
        d_1c0c4c = d_1c0c4c + 1;
        f_01cef0(d_1bc760);
        int n = (int)new (mark(d_1a6bf0, 0x173)) S5A;
        n = n ? f_0a8830(n, r, 1) : n;
        int u = f_0a8be0(n);
        if (n) operator delete((void *)f_0a8b40(n, 0));
        f_0e0530(u, *(int *)(p1 + 0x74), p1 + 0x72);
        if (u) operator delete((void *)f_11c120(u, 0));
        f_09a140(0, 0x19);
        f_09a0d0(d_1a34e0);
        d_1c2a80 = 0;
        d_1c2198 = 1;
        d_1c0c4c = d_1c0c4c - 1;
        d_1c0c94 = sv;
    }
}
