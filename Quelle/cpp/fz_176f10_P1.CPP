/* === Beschreibung (Katalog) ===
 * Einheit fz_176f10 (0x176F10 - 0x1771C2)
 *
 * Überblick
 * Diese Einheit gehört zur 3D-Geometrie- und Szenenbaum-Verwaltung (BRender-Hierarchie) und berechnet die
 * relative 3D-Transformationsmatrix (4x3-Matrix zu 48 Bytes) zwischen zwei beliebigen Knoten (struct N) eines
 * Szenenbaums über deren gemeinsamen Vorfahren.
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -nt=_TEXT3
// CC wcc386
// P1 0/1 gleich
// fz_176f10.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x176F10-0x1771C2
struct N { char q0[0xc]; struct N *nx; unsigned short k; char q1[0x12]; unsigned short t; };
extern const unsigned char d_1b4727[];   // Claude 860: Original adressiert 1B46F4+0x33 = L1B4727 (Label 1B46F4 fehlt in der Basis)
void f_16b930(void *a);
void f_187f7c(void *a, void *b);
void f_16bd98(void *a, void *b);
void f_16c138(void *a, void *b);
void f_188260(void *a, void *b);
void f_16b5c0(void *a, void *b);
void f_16b60c(void *a, void *b, void *c);
#pragma aux f_176f10 "*";
#pragma aux f_16b930 "*";
#pragma aux f_187f7c "*";
#pragma aux f_16bd98 "*";
#pragma aux f_16c138 "*";
#pragma aux f_188260 "*";
#pragma aux f_16b5c0 "*";
#pragma aux f_16b60c "*";
//@ f_176f10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet die relative 4x3-Transformationsmatrix (p1, 48 Bytes) zwischen dem Quellknoten
 *   p2 und dem Zielknoten p3 im 3D-Szenenbaum: Sind beide Knoten identisch, wird die Einheitsmatrix (f_16b930,
 *   Typ 6) gesetzt; ist einer der direkte Elternknoten (nx) des anderen, wird dessen lokale Transformation
 *   direkt übernommen (f_187f7c) beziehungsweise invertiert (f_16c138/f_16bd98); andernfalls wandert die
 *   Funktion anhand der Baumtiefe k von beiden Knoten aus aufwärts bis zum tiefsten gemeinsamen Vorfahren,
 *   verkettet die beiden Teilpfade in a4 und l44 (f_188260), invertiert l44 nach l74 und multipliziert beide
 *   Matrizen über f_16b60c in p1 zusammen.
 * - Eingaben: Zielmatrix-Puffer p1 (48 Bytes), erster Szenenbaum-Knoten p2 und zweiter Szenenbaum-Knoten p3.
 * - Rückgabewert: unsigned char - kombinierter Transformations-Typcode (0..6, verknüpft über die 7x7-Typmatrix
 *   d_1b4727).
 * - Wichtige Variablen:
 *   - a4, l44, l74: Lokale 48-Byte-Matrizen für den Aufstiegspfad von p2, den Aufstiegspfad von p3 und dessen
 *     Inverse.
 *   - l10, l14: Laufende Matrix-Typcodes (6 = Einheitsmatrix) für die beiden Teilpfade.
 *   - d_1b4727: Lookup-Tabelle (7x7 Bytes) zur Bestimmung des resultierenden Matrixtyps bei der Verkettung
 *     zweier Transformationen.
 === Ende Beschreibung === */
unsigned char f_176f10(void *p1, struct N *p2, struct N *p3)
{
    unsigned char l74[48];
    unsigned char a4[48];
    unsigned char l44[48];
    unsigned char l14;
    volatile unsigned char l10;
    if (p2 == p3) {
        f_16b930(p1);
        return 6;
    }
    if (p3 == p2->nx) {
        f_187f7c(p1, &p2->t);
        return (unsigned char)p2->t;
    }
    if (p2 == p3->nx) {
        f_187f7c(l44, &p3->t);
        if (p3->t != 0) {
            f_16c138(p1, l44);
        } else {
            f_16bd98(p1, l44);
        }
        return (unsigned char)p3->t;
    }
    l10 = 6;
    f_16b930(a4);
    l14 = 6;
    f_16b930(l44);
    while (p2 != 0) {
        if (p3 == 0) break;
        if (p2 == p3) break;
        if (p2->k > p3->k) {
            if ((unsigned)p2->t != 6) {
                f_188260(a4, &p2->t);
                { unsigned off = l10 * 7; l10 = d_1b4727[off + p2->t]; }
            }
            p2 = p2->nx;
        } else if (p3->k > p2->k) {
            if ((unsigned)p3->t != 6) {
                f_188260(l44, &p3->t);
                { unsigned off = l14 * 7; l14 = d_1b4727[off + p3->t]; }
            }
            { struct N *nx = p3->nx; p3 = nx; } // haelt die Registerzuteilung wie im Original
        } else {
            if ((unsigned)p2->t != 6) {
                f_188260(a4, &p2->t);
                { unsigned off = l10 * 7; l10 = d_1b4727[off + p2->t]; }
            }
            if ((unsigned)p3->t != 6) {
                f_188260(l44, &p3->t);
                { unsigned off = l14 * 7; l14 = d_1b4727[off + p3->t]; }
            }
            p3 = p3->nx;
            p2 = p2->nx;
        }
    }
    if ((unsigned)l14 == 6) {
        f_16b5c0(p1, a4);
        return l10;
    }
    if ((unsigned)l10 == 6) {
        if (l14) {
            f_16c138(p1, l44);
        } else {
            f_16bd98(p1, l44);
        }
        return l14;
    }
    if (l14) {
        f_16c138(l74, l44);
    } else {
        f_16bd98(l74, l44);
    }
    f_16b60c(p1, a4, l74);
    { unsigned off = l10 * 7; return d_1b4727[off + l14]; }
}

void f_176e24(void *, struct N *);
void f_189a74(void *, void *);
#pragma aux f_176e24 "*";
#pragma aux f_189a74 "*";
#pragma aux f_17718c "*";
void f_17718c(void *p1, struct N *p2, struct N *p3)
{
    unsigned char tmp[48];
    f_176e24(p1, p3);
    if(p2 != p3 && (unsigned)f_176f10(tmp,p2,p3) != 6)
        f_189a74(p1,tmp);
}
