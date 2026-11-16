/* === Beschreibung (Katalog) ===
 * Einheit ch_level_t2 (0x0384e0 - 0x038ba0)
 *
 * Überblick
 * Dieser zweite Teil des Stufenaufstiegs-Moduls (ch_level) enthält die beiden übergeordneten Steuerfunktionen
 * des Stufenaufstiegs: die Verteilung und interaktive Einlösung der Talent- und Zauber-Steigerungspunkte
 * (f_0384e0, einschließlich des Tauschs zwischen Talent- und Zauberpunkten für Magiekundige) sowie den
 * Haupteinstiegspunkt f_038880, der den gesamten Stufenaufstieg eines Helden von der Gratulationsmeldung bis zur
 * Freigabe der Hilfstabellen abwickelt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/2 gleich (suche.py 30.10.2026, Basis ch_level_t2_P1.CPP)
// ch_level.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x036EE0-0x038BA0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a0994;                    // 0x1A0994
extern int d_1a0995;                    // 0x1A0995
extern int d_1a09a6;                    // 0x1A09A6
extern int d_1a09ac;                    // 0x1A09AC
extern int d_1a0a8c;                    // 0x1A0A8C
extern int d_1a0ab0;                    // 0x1A0AB0
extern int d_1a0abe;                    // 0x1A0ABE
extern int d_1a0acc;                    // 0x1A0ACC
extern int d_1a0ae4;                    // 0x1A0AE4
extern int d_1a0aeb;                    // 0x1A0AEB
extern int d_1a0b90;                    // 0x1A0B90
extern int d_1a0b94;                    // 0x1A0B94
extern int d_1a0b9c;                    // 0x1A0B9C
extern int d_1a0ba4;                    // 0x1A0BA4
extern int d_1a1388;                    // 0x1A1388
extern int d_1a6ad3;                    // 0x1A6AD3
extern int d_1a7270;                    // 0x1A7270
extern int d_1bc8f4;                    // 0x1BC8F4
                    // 0x1C2098
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a0974[];           // Text 0x1A0974
// --- eigene Funktionen (16), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct T12 { signed char v[12]; };
struct T6 { signed char v[6]; };
extern T12 d_1a0b8c;
extern T6 d_1a0b98;
extern T6 d_1a0ba0;
extern char d_1a0514;
extern short d_1a0515;
extern signed char d_1bfaec;
extern char *d_1bc89c;
extern char *d_1bc8a0;
extern int d_1bc8a4;
extern int d_1c0c4c;
extern int d_1bc898;
extern char d_1bc930;
extern short d_1bd766;
extern short d_1c2198;

#define IDX(b) (char *)(s * 2 + (int)(b))
struct P { char m0; char x1[4]; short m5; char x2[4]; int mb; char x3[17]; short m20; short m22; char x4[254]; int m122; };
struct E { int f0; int *f4; int f8; int fc; int f10; char *f14; char rest[36]; };






int f_043360(int, int);

int f_043e20(int, int);
char f_043e30(int);
int f_0449d0(int, int);
void f_04e470(P *);
int f_0bf6f0(void *, int);
int f_0bf730(void *, int);
short f_0bf7b0(void *, int, int, int, int, int);
short f_0bf820(void *, ...);
int f_0c0000(void *, int);
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0d4730(int);
int f_0d5550(void *);
int f_01eb40(void *);
int f_01eb50(void *);
int f_014540(int, const char *, int);
int f_014710(void *, int);
int f_125400(void *, void *, void *, void *);
int f_1254a0(void *, int);





short f_03b5e0(int, int);
short f_03cd00(int, int);
void f_037e60(P *);
void f_037fd0(P *);
void f_037140(P *, int);
void f_037030(P *, int);
void f_037730(P *);
void f_0378e0(P *);
void f_037bb0(P *);

//@ f_0384e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion schreibt dem Helden beim Stufenaufstieg die klassenspezifische Anzahl neuer
 *   Talent-Steigerungspunkte (d_1a0b8c) und Zauber-Steigerungspunkte (d_1a0ba0) gut, fragt magiebegabte Helden
 *   nach einer eventuellen Umwandlung zwischen Talent- und Zauberpunkten und führt anschließend entweder die
 *   automatische Steigerung (f_037e60/f_037fd0) oder die interaktive Steigerungsschleife über die Talent- und
 *   Zaubermenüs (f_03b5e0/f_03cd00) durch.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Charakterbogen-/Stufenaufstiegs-Objekt (P
 *   *) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Tabelle d_1a0b8c (12 Bytes) enthält in den ersten 6 Einträgen die Talentpunkte je
 *   Klasse und in den Einträgen ab Index 6 die maximal zwischen Talenten und Zaubern umwandelbaren Punkte für
 *   die Magier-/Elfenklassen; d_1a0ba0 enthält die hinzukommenden Zauberpunkte. In der interaktiven Schleife
 *   dürfen ungenutzte Punkte nur dann für den nächsten Stufenaufstieg aufgespart werden, wenn der Punktestand
 *   unter 200 liegt.
 === Ende Beschreibung === */
void f_0384e0(P *p1)
{
    E e;
    T12 A = d_1a0b8c;
    T6 C; T6 B;
    B = d_1a0b98;
    C = d_1a0ba0;
    (void)&B; 
    signed char c;
    short k;
    short s;
    int fl;
    f_125400(&e, &d_1c349c, &d_1c3870, &d_1c3498);
    c = ((char)(f_042350((struct hero *)(p1->mb))));
    f_043360(p1->mb, A.v[c - 1]);
    if (f_042a10((struct hero *)(p1->mb)) != 0) {
        c = ((char)(f_042350((struct hero *)(p1->mb))));
        f_043310((struct hero *)(p1->mb), C.v[c + 1]);
    }
    if ((d_1bfaec == 0) != 0 || p1->m122 != 0) {
        f_037e60(p1);
        f_037fd0(p1);
        goto done;
    }
    p1->m0 = 3;
    f_04e470(p1);
    if (f_042a10((struct hero *)(p1->mb)) != 0) {
        c = ((char)(f_042350((struct hero *)(p1->mb))));
        s = A.v[c + 5];
        if (A.v[c + 5] != 0 && f_0bf6f0(&d_1c2c64, 0x304004a) == 1) {
            *(short *)(e.f14 + 2) = s;
            k = f_0bf7b0(&d_1c2c64, 1, 0x304004b, 0, s, 0);
            if (k > 0) {
                f_043310((struct hero *)(p1->mb), (signed char)k);
                f_043360(p1->mb, (signed char)-k);
            } else {
                *(short *)(e.f14 + 2) = s;
                k = f_0bf7b0(&d_1c2c64, 1, 0x304004c, 0, s, 0);
                if (k <= 0) goto L670;
                f_043310((struct hero *)(p1->mb), (signed char)-k);
                f_043360(p1->mb, (signed char)k);
            }
        }
    }
L670:
    fl = 0;
    for (;;) {
        c = ((char)(f_043340((struct hero *)(p1->mb))));
        if (c == (signed char)0 || fl) break;
        s = f_03b5e0(p1->mb, 1);
        p1->m5 = s;
        if (s >= 0) {
            f_037140(p1, s);
            f_04e470(p1);
        } else {
            if (s == -2) {
                do {
                    s = f_0bf820(&d_1c2c64, 0x304004f, 3, 0x304004d, 0x3040050, 0x3040051) - 1;
                    p1->m5 = s;
                    if (s == 0) {
                        if (((char)(f_043340((struct hero *)(p1->mb)))) < 200) {
                            fl = 1;
                            break;
                        }
                        f_0bf730(&d_1c2c64, 0x3040049);
                    } else {
                        if (s == 1) {
                            f_037e60(p1);
                            f_04e470(p1);
                            f_0d4730(0xfa);
                            break;
                        }
                        if (s == 2) break;
                    }
                } while (p1->m5 == -2);
            }
        }
    }
    if (f_042a10((struct hero *)(p1->mb)) != 0) {
        p1->m0 = 4;
        f_04e470(p1);
    }
    fl = 0;
    for (;;) {
        c = ((char)(f_0432f0((struct hero *)(p1->mb))));
        if (c == (signed char)0 || fl) break;
        s = f_03cd00(p1->mb, 1);
        p1->m5 = s;
        if (s > 0) {
            p1->m0 = (s >= 0x31) + 4;
            f_037030(p1, p1->m5);
            f_04e470(p1);
        } else {
            if (s == -2) {
                do {
                    s = f_0bf820(&d_1c2c64, 0x304004f, 3, 0x304004d, 0x3040050, 0x3040051) - 1;
                    p1->m5 = s;
                    if (s == 0) {
                        if (((char)(f_0432f0((struct hero *)(p1->mb)))) < 200) {
                            fl = 1;
                            break;
                        }
                        f_0bf730(&d_1c2c64, 0x3040049);
                    } else {
                        if (s == 1) {
                            f_037fd0(p1);
                            p1->m0 = 4;
                            f_04e470(p1);
                            f_0d4730(0xfa);
                            p1->m0 = 5;
                            f_04e470(p1);
                            f_0d4730(0xfa);
                            break;
                        }
                        if (s == 2) break;
                    }
                } while (p1->m5 == -2);
            }
        }
    }
done:
    f_1254a0(&e, 0);
}

//@ f_038880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hauptfunktion steuert den kompletten Ablauf eines Stufenaufstiegs für den Helden p2. Sie
 *   lädt die klassenspezifischen Steigerungstabellen (0x30002, 0x30003) aus dem Archiv, löscht die Fehlversuchs-
 *   und Stufenzähler (d_1bc89c, d_1bc8a0), erhöht die Erfahrungsstufe des Helden (f_0428e0), fragt den Spieler,
 *   ob er selbst steigern oder den Computer steigern lassen möchte, und ruft nacheinander die Steigerung der
 *   positiven und schlechten Eigenschaften (f_037730, f_0378e0), die Neuberechnung der Magieresistenz
 *   (f_0449d0), den LE/AE-Zuwachs (f_037bb0) sowie die Talent- und Zaubersteigerung (f_0384e0) auf.
 * - Eingaben und Rückgabe: Die Funktion erhält das Dialogobjekt p1 (P *), den Heldenzeiger p2 und den
 *   Aufrufmodus p3 (0 = normaler Stufenaufstieg mit Meldung, 1 = ohne Eingangsmeldung, 2 = erzwungene stille
 *   Computer-Steigerung) und gibt keinen Wert zurück.
 * - Wichtige Variablen: d_1bc898 und d_1bc8a4 sind die dynamisch für die Dauer des Stufenaufstiegs allokierten
 *   Puffer für die Talent-Zielwerte und Magier-Hauszauber.
 === Ende Beschreibung === */
struct LevelDraw903 {
    struct Guard { int active;
        Guard() { if (f_0d3860()==1) { int one=1; f_0d2710(); active=one; } else active=0; }
        ~Guard() { if (active==1) f_0d26e0(); }
    };
    static void draw(P *self) {
        Guard guard;
        f_04e470(self);
        *(char *)&d_1a0515=(char)0xff;
        d_1a0514=(char)0xff;
        f_0d5550(&d_1c2bcc);
    }
};
void f_038880(P *p1, int p2, short p3)
{
    (void)&p3; // Haelt p3 im Stapelplatz wie im Original
    E e;
    int n = 0;
    short s = 0;

    f_125400(&e, &d_1c349c, &d_1c3870, &d_1c3498);
    d_1c0c4c = d_1c0c4c + 1;
    d_1a1388 = 0;
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x30002, 0x200);
    d_1bc898 = f_014540((n = ((int)(((RivaFileManager*)(&d_1c2098))->f_144a00()))), d_1a0974, 0x4c0);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( d_1bc898), n)));
    d_1bc8a4 = f_014540((((RivaFileManager*)(&d_1c2098))->f_1449a0(), 0x129), d_1a0974, 0x4c4);
    ((RivaFileManager*)(&d_1c2098))->f_1448d0( 0x30003,(void *)( d_1bc8a4));

    for (s = 0; s < 0x56; s++) {
        char *base = (s & 0) ? (char *)0 : d_1bc8a0; char *q = base + s*2; // Trennt Basiszeiger fuer die Schleifen-Registerwahl
        q[1] = 0;
        *q = q[1];
    }
    for (s = 0; s < 0x34; s++) {
        char *base = (s & 0) ? (char *)0 : d_1bc89c; char *q = base + s*2; // Trennt Basiszeiger fuer die Schleifen-Registerwahl
        q[1] = 0;
        *q = q[1];
    }

    p1->m0 = 1;
    *(volatile char *)&d_1bc930 = 0;
    p1->m22 = -1;
    p1->mb = p2;
    p1->m20 = p1->m22;
    d_1bc8f4 = p2;
    d_1bd766 = 0;
    f_0428e0((struct hero *)(p1->mb));
    e.f4[1] = p1->mb;

    if (!p3) f_0bf730(&d_1c2c64, 0x304004e);
    if (p3 != (short)2) {
        LevelDraw903::draw(p1);
        s = f_0bf820(&d_1c2c64, 0x3040058, 2, 0x3040059, 0x304005a);
        p1->m122 = s - 1;
    } else {
        p1->m122 = 1;
        f_043e20(p1->mb, 1);
    }

    if (p1->m122 == -2) p1->m122 = 0;
    if (p1->m122 == 1) f_01eb40(&d_1c2bcc);
    f_0c0000(&d_1c2c64, -100);
    f_037730(p1);
    f_0378e0(p1);
    f_0449d0(p1->mb, 0);

    if (d_1c2198 != (short)0 && !f_043e30(p1->mb)) {
        LevelDraw903::draw(p1);
    }

    f_037bb0(p1);
    f_0c0000(&d_1c2c64, 0);
    f_0384e0(p1);
    if (p1->m122 == 1) {
        f_01eb50(&d_1c2bcc);
        f_043e20(p1->mb, 0);
    }
    *(volatile short *)&d_1c2198 = 1;
    d_1a1388 = 1;
    d_1c0c4c -= d_1a1388;
    operator delete((void *)d_1bc898);
    operator delete((void *)d_1bc8a4);
    f_1254a0(&e, 0);
}
