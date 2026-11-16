/* === Beschreibung (Katalog) ===
 * Einheit gz_0945c0 (0945c0 - 094f08)
 *
 * Überblick
 * Die Einheit gz_0945c0 gehört zur Heldenerschaffung (gen) und übernimmt vier Aufgaben: die Prüfung, ob noch
 * positive und negative Eigenschaften gegeneinander getauscht werden dürfen (f_0945c0), das schrittweise
 * Auswürfeln und Zuweisen der 7 positiven (MU..KK) und 7 negativen (AG..JZ) Grundwerte (f_094700), die
 * Berechnung der Grundwerte für Attacke/Parade auf die sieben Kampftalente (f_094ac0) sowie das automatische
 * Verteilen aller Talent- und Zaubersteigerungsversuche im Einsteigermodus (f_094c70).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 3/4 gleich (suche.py 30.10.2026, Basis gz_0945c0_P1.CPP)
// gz_0945c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0945C0-0x094F40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (4), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
signed char f_03ad80(int p1, int p2);
signed char f_043ac0(int p1, int p2);

int f_043b00(int p1, int p2, int p3);
int f_043b10(int p1, int p2, int p3);
int f_043b40(int p1, int p2, int p3);
int f_043b50(int p1, int p2, int p3);
int f_095600(int p1, int p2);
int f_095710(int p1, int p2);
int f_1457e0(int p1);
signed char f_0422b0x(int p1);






int f_043e20(int, int);
int f_0978a0(int, int);
int f_0978a0(int);
int f_043af0(int, int);


int f_094330(int);
int f_043aa0(int, int, int);
int f_0455b0(int, int, int);
signed char f_145760(int, int);
int f_0bf820(int, ...);
int f_0bf6f0(int, int);
int f_145300(int, int, int, int);
int f_145300(int, int, int);
extern signed char d_1a7734[];
extern int d_1bc88c;
extern char *d_1bc898;
extern char *d_1bc8a4;
extern signed char d_1c2198;
extern int d_1c29c4[];
extern char d_1c2c64[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
struct Obj { int f0; short *p[13]; short s38; Obj(const char *, const char *, const char *); ~Obj(); };
#define FLD(p) (*(int *)((p) + 0xdf))
#define P34(p) (*(int *)((p) + 0x34))
//@ f_0945c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft in der Heldenerschaffung, ob der aktuell bearbeitete Held (FLD(p)) noch über genügend
 *   Spielraum bei seinen positiven (0..6) und negativen (7..13) Eigenschaften verfügt, um eine positive
 *   Eigenschaft um 1 Punkt zu heben (gegen Erhöhung zweier negativer Eigenschaften) oder um 1 Punkt zu senken
 *   (gegen Senkung zweier negativer Eigenschaften).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p auf die Generierungsstruktur und gibt 1 zurück, wenn
 *   ein Eigenschaftstausch regelkonform möglich ist, sonst 0.
 * - Wichtige Variablen: Das Array *(signed char *)(p + 0x14 + i) speichert für jede Eigenschaft i (0..13), ob
 *   sie bereits nach oben (1) oder nach unten (-1) verändert wurde.
 === Ende Beschreibung === */
short f_0945c0(int p)
{
    short a, c, d, b, i;
    b = 0; a = 0; c = 0; d = 0;
    signed char t;
    for (i = 0; i <= 6; i++) {
        t = f_043ac0(FLD(p), i);
        if (*(signed char *)(i + 0x14 + p) != 1 && (short)t > 8) a += 8 - t;
        if (*(signed char *)(i + 0x14 + p) != -1 && t < 13) b += 13 - t;
    }
    for (i = 7; i <= 13; i++) {
        t = f_043ac0(FLD(p), i);
        if (*(signed char *)(i + 0x14 + p) != 1 && t > 2) d += 2 - t;
        if (*(signed char *)(i + 0x14 + p) != -1 && t < 8) c += 8 - t;
    }
    if ((!b && !a) || (!b && d < 2) || (c < 2 && !a) || (d < 2 && c < 2)) return 0; return 1;
}
//@ f_094700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt für einen neu angelegten Helden (FLD(p)) das Auswürfeln der Eigenschaften durch: Sie
 *   würfelt nacheinander sieben positive Werte (8..13, also 1W6+7) und sieben negative Werte (2..7, also 1W6+1),
 *   lässt den Spieler jeden gezogenen Wert einer noch unbelegten Eigenschaft zuordnen und setzt bei Abbruch (sel
 *   == -2) den Helden wieder auf den Ausgangszustand zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Array d_1c29c4 sammelt die Textkennungen (0x20000143 + j) der noch freien
 *   Eigenschaften für das Auswahlmenü f_0bf820.
 === Ende Beschreibung === */
void f_094700(int p)
{
    Obj obj(d_1c349c, d_1c3870, d_1c3498);
    signed char saved;
    short i = 0, j, sel;
    signed char n, count;
    int text;
    signed char tab[16];
    char buf[12];

    d_1bc88c = 1;
    if (f_042350((struct hero *)(FLD(p)))) *(short *)&d_1c2198 = 1;
    strcpy(buf, f_0422b0((struct hero *)(FLD(p))));
    saved = f_042380((struct hero *)(FLD(p)));
    f_145300(FLD(p), 0, 0x5ef);
    f_043e20(FLD(p), 1);
    f_0978a0(p);
    f_043af0(FLD(p), saved);
    f_0422f0((struct hero *)(FLD(p)),(char *)( (int)buf));
    f_0422c0((struct hero *)(FLD(p)),(char *)( (int)buf));
    f_094330(p);

    for (i = 0; i <= 6; i++) {
        n = f_145760(8, 13);
        count = 0;
        for (j = 0; j <= 6; j++) {
            if (!f_043ac0(FLD(p), j)) {
                tab[count] = (signed char)j;
                d_1c29c4[count++] = j + 0x20000143U;
            }
        }
        obj.p[4][1] = n;
        sel = -1;
        text = (int)d_1c2c64;
        while (sel == -1) {
            sel = f_0bf820(text, 0xe140011, count,
                d_1c29c4[0], d_1c29c4[1], d_1c29c4[2],
                d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]);
            if (sel == -1 && f_0bf6f0(text, 0xe140049) == 1) {
                sel = -2;
                break;
            }
        }
        if (sel == -2) break;
        sel = tab[sel - 1];
        f_043aa0(FLD(p), sel, n);
        f_0455b0(FLD(p), sel, n);
        f_094330(p);
    }

    if (sel != -2) {
        for (i = 7; i <= 13; i++) {
            n = f_145760(2, 7);
            count = 0;
            for (j = 7; j <= 13; j++) {
                if (!f_043ac0(FLD(p), j)) {
                    tab[count] = (signed char)j;
                    d_1c29c4[count++] = j + 0x20000143U;
                }
            }
            obj.p[4][1] = n;
            sel = -1;
            text = (int)d_1c2c64;
            while (sel == -1) {
                sel = f_0bf820(text, 0xe140011, count,
                    d_1c29c4[0], d_1c29c4[1], d_1c29c4[2],
                    d_1c29c4[3], d_1c29c4[4], d_1c29c4[5], d_1c29c4[6]);
                if (sel == -1 && f_0bf6f0(text, 0xe140049) == 1) {
                    sel = -2;
                    break;
                }
            }
            if (sel == -2) break;
            sel = tab[sel - 1];
            f_043aa0(FLD(p), sel, n);
            f_0455b0(FLD(p), sel, n);
            f_094330(p);
        }
    }

    if (sel == -2) {
        f_145300(FLD(p), 0, 0x5ef);
        f_043e20(FLD(p), 1);
        f_0978a0(p);
        f_043af0(FLD(p), saved);
        f_0422f0((struct hero *)(FLD(p)),(char *)( (int)buf));
        f_0422c0((struct hero *)(FLD(p)),(char *)( (int)buf));
        f_094330(p);
    }
    d_1bc88c = 0;
}

//@ f_094ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für den neu erstellten Helden (FLD(p)) den Attacke-/Parade-Basiswert aus (IN + GE +
 *   KK) / 5 (kaufmännisch gerundet ab Rest 3), setzt damit die Basiswerte aller sieben Kampftalente (0..6) und
 *   verteilt die vorhandenen Kampftalentpunkte hälftig auf Attacke (f_043b40) und Parade (f_043b50).
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bei ungeraden Kampftalentwerten (% 2 != 0) geht der zusätzliche Punkt bei positivem
 *   Talentwert auf die Attacke, bei negativem Talentwert als Abzug auf die Parade.
 === Ende Beschreibung === */
#include <stdlib.h>
void f_094ac0(int p)
{
    div_t q = div(f_043ac0(FLD(p), 5) + f_043ac0(FLD(p), 6) + f_043ac0(FLD(p), 4), 5);
    if (q.rem >= 3) q.quot++;
    f_0428a0((struct hero *)(FLD(p)), (signed char)q.quot);
    short i;
    short half;
    for (i = 0; i <= 6; i++) {
        f_043b00(FLD(p), i, (signed char)q.quot);
        f_043b10(FLD(p), i, (signed char)q.quot);
        if (f_03ad80(FLD(p), i) < 0) {
            half = abs(f_03ad80(FLD(p), i)) / 2;
            f_043b40(FLD(p), i, (signed char)-(signed char)half);
            f_043b50(FLD(p), i, (signed char)-(signed char)half);
            if (f_03ad80(FLD(p), i) % 2) f_043b50(FLD(p), i, -1);
        } else {
            half = f_03ad80(FLD(p), i) / 2;
            f_043b40(FLD(p), i, (signed char)half);
            f_043b50(FLD(p), i, (signed char)half);
            if (f_03ad80(FLD(p), i) % 2) f_043b40(FLD(p), i, 1);
        }
    }
}
//@ f_094c70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verteilt im Einsteigermodus (d_1bfaec == 0) automatisch alle freien Talentsteigerungsversuche
 *   (f_043340) und Zaubersteigerungsversuche (f_0432f0) eines neuen Helden anhand klassenspezifischer
 *   Prioritätstabellen (d_1bc898, d_1bc8a4, d_1a7734) über f_095600 und f_095710.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Für Magier (d == 9) stellt die Funktion in P34(p) + 0xb4 zuerst eine Wunschliste aus den
 *   Haussprüchen der gewählten Akademie (d_1bc8a4, dreimal eingetragen für bis zu +3 Steigerungen) und den
 *   Schulzaubern (d_1a7734) zusammen, bevor verbleibende Versuche zufällig vergeben werden.
 === Ende Beschreibung === */
void f_094c70(int p)
{
    short d;
    short a;
    short b;
    signed char v;
    short t1;
    short t2;
    d = f_042350((struct hero *)(FLD(p)));
    a = 0;
    while (f_043340((struct hero *)(FLD(p))) > 0) {
        t1 = *(short *)(d_1bc898 + d * 100 + a++ * 4);
        f_095600(p, t1);
    }
    b = 0;
    if (d == 9) {
        for (a = 0; a < *(signed char *)(d_1bc8a4 + f_043320((struct hero *)(FLD(p))) * 0x21); a++) {
            v = f_043320((struct hero *)(FLD(p)));
            *(short *)(P34(p) + 0xb4 + (b++) * 2) = *(short *)(d_1bc8a4 + v * 0x21 + a * 2 + 1);
        }
        for (a = 0; a < d_1a7734[f_043320((struct hero *)(FLD(p))) * 2 + 1]; a++) {
            v = f_043320((struct hero *)(FLD(p)));
            short letter = d_1a7734[v * 2];
            short sum770 = (letter & 0xffff) + a; // haelt die 16-Bit-Erweiterung und den Stapelrahmen wie im Original
            *(short *)(P34(p) + b * 2 + 0xb4) = sum770;
            b++;
        }
        *(short *)(P34(p) + 0xb4 + b++ * 2) = 0x52;
        { int target942 = P34(p); P34(p) = target942; *(short *)(b++ * 2 + (target942 + 0xb4)) = 0x31; } // haelt die Registerzuteilung beim Basiszeiger P34(p) wie im Original
        *(short *)(P34(p) + 0xb4 + b++ * 2) = 0x35;
        { int target942 = P34(p); P34(p) = target942; *(short *)(b++ * 2 + (target942 + 0xb4)) = 0x21; } // haelt die Registerzuteilung beim Basiszeiger P34(p) wie im Original
        { int target942 = P34(p); P34(p) = target942; *(short *)(b++ * 2 + (target942 + 0xb4)) = 0x4f; } // haelt die Registerzuteilung beim Basiszeiger P34(p) wie im Original
        for (a = 0; a < *(signed char *)(d_1bc8a4 + f_043320((struct hero *)(FLD(p))) * 0x21); a++) {
            v = f_043320((struct hero *)(FLD(p)));
            *(short *)(P34(p) + 0xb4 + (b++) * 2) = *(short *)(d_1bc8a4 + v * 0x21 + a * 2 + 1);
        }
        for (a = 0; a < *(signed char *)(f_043320((struct hero *)(FLD(p))) * 0x21 + d_1bc8a4); a++) {
            v = f_043320((struct hero *)(FLD(p)));
            *(short *)(P34(p) + 0xb4 + (b++) * 2) = *(short *)(v * 0x21 + d_1bc8a4 + a * 2 + 1);
            { char *sort942 = d_1bc898; d_1bc898 = sort942; } // haelt die Registerzuteilung in der Schleife wie im Original
        }
        int fillIndex942;
        while ((fillIndex942 = b) < 0x2d) {
            *(short *)(P34(p) + 0xb4 + fillIndex942 * 2) = f_1457e0(0x55);
            b++;
        }
    }
    a = 0;
    while (f_0432f0((struct hero *)(FLD(p))) > 0) {
        t2 = *(short *)(a++ * 2 + (P34(p) + (d - 7) * 0x5a));
        f_095710(p, t2);
    }
}
