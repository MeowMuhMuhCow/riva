/* === Beschreibung (Katalog) ===
 * Einheit fi_build (070c50 - 0710e0)
 *
 * Überblick
 * Die Einheit fi_build (*Fight Build*) berechnet bei zufällig aufgebauten Kämpfen gültige Startkoordinaten und
 * Blickrichtungen für Helden (f_070c50) und Gegner (f_070e50) auf dem isometrischen 24 x 24-Kampffeld sowie die
 * Manhattan-Distanz zum nächstgelegenen Helden (f_070d70).
 === Ende Beschreibung === */
// P3 1/3 gleich (suche.py 30.10.2026, Basis fi_build_P1.CPP)
// fi_build.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x070C50-0x0710E0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_072610(void *p, short x, short y);
short f_145760(int lo, int hi);
short f_1457e0(int hi);
#pragma aux f_145760 modify exact [eax ebx ecx edx]
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
struct FI_POS { signed char x, y; };
extern FI_POS d_1a1c2c[];
extern signed char d_1a1c36;
extern signed char (*d_1bd984)[25];
// --- eigene Funktionen (0), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#include <string.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))
extern char d_1a1c24[];
extern char d_1a2734[];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C070d70_5(int,int,int,int,int);
#pragma aux C070d70_5 "f_070d70" modify exact [eax ebx ecx edx];
int f_071e20(int,int,int,int);
int C071e20_4(int,int,int,int);
#pragma aux C071e20_4 "f_071e20" modify exact [eax ebx edx];
int C072610_3(int,int,int);
#pragma aux C072610_3 "f_072610" modify exact [eax ebx edx];
int C1457e0_1(int);
#pragma aux C1457e0_1 "f_1457e0" modify exact [eax];
//@ f_070c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Würfelt für einen Helden zufällige Koordinaten (0..23, 0..23) auf dem Kampffeld aus, bis ein
 *   freies Feld (d_1bd984[y][x] == 0) gefunden wird, das vom Fluchtankerpunkt d_1a1c2c[d_1a1c36] aus über
 *   f_072610 erreichbar ist. Das gefundene Feld wird im Raster d_1bd984 vorläufig mit 0xc9 (Helden-Startplatz)
 *   markiert und die anfängliche Blickrichtung anhand der Aufstellungsrichtung d_1a1c36 gesetzt.
 * - Eingaben und Rückgabe: Empfängt den Kampfstrukturzeiger p sowie die drei Ausgabezeiger outx, outy und outdir
 *   für Spalte, Zeile und Blickrichtung (0..3) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1a1c36 gibt die Aufstellungsseite (0..4) an, d_1a1c2c speichert
 *   die zugehörigen Ankerkoordinaten am Kartenrand und 0xc9 kennzeichnet im Kampfraster d_1bd984 einen bereits
 *   vergebenen Heldenplatz.
 === Ende Beschreibung === */
void f_070c50(char *p, signed char *outx, signed char *outy, signed char *outdir)
{
    signed char old = 0;
    old = d_1bd984[d_1a1c2c[d_1a1c36].y][d_1a1c2c[d_1a1c36].x];
    d_1bd984[d_1a1c2c[d_1a1c36].y][d_1a1c2c[d_1a1c36].x] = (signed char)0xcb;
    for (;;) {
        *outx = (signed char)f_145760(0, 23);
        *outy = (signed char)f_145760(0, 23);
        if (d_1bd984[*outy][*outx] == (signed char)0) {
            if (f_072610(p, *outx, *outy))
                break;
        }
    }
    int row, dir;
    dir = d_1a1c36;
    row = d_1a1c2c[dir].y;
    d_1bd984[row][d_1a1c2c[dir].x] = old;
    d_1bd984[*outy][*outx] = (signed char)0xc9;
    *outdir = 0;
    if (dir == 4)
        *outdir = (signed char)(f_1457e0(dir) - 1);
    else
        *outdir = (signed char)((dir + 1) % 4);
}
//@ f_070d70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht auf dem gesamten Kampfraster d_1bd984 nach dem nächstgelegenen mit 0xc9 markierten
 *   Helden-Startplatz relativ zur übergebenen Position (x, y) und gibt dessen Koordinaten sowie die
 *   Manhattan-Distanz zurück. Bei gleichem Abstand werden Felder bevorzugt, die in derselben Spalte oder Zeile
 *   liegen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger self, die Ausgangskoordinaten x und y sowie die
 *   Ausgabezeiger ox und oy für den gefundenen Heldenplatz und gibt die kleinste Manhattan-Distanz (short,
 *   Startwert 99) zurück.
 * - Wichtige Variablen: Die Hilfsfunktion f_071e20 berechnet die Manhattan-Distanz |x1 - x2| + |y1 - y2| auf dem
 *   Kampfraster.
 === Ende Beschreibung === */
short f_070d70(int self,signed char x,signed char y,signed char *ox,signed char *oy)
{
short distance1049_twin(int,int,int,int);
#pragma aux distance1049_twin "f_071e20" parm [eax] [edx] [ebx] [ecx] modify exact [eax ebx edx]

    signed char rx=*(signed char *)&x;*(signed char *)&x=rx;
    signed char ry=*(signed char *)&y;*(signed char *)&y=ry;
    short best=99;short col,row,d;
    for(row=0;row<(short)24;row++) for(col=0;col<(short)25;col++){
      if(((signed char (*)[25])ND32(d_1bd984))[row][col]!=(signed char)0xc9)continue;
      int yy=y;self=x;d=(short)distance1049_twin(self,yy,col,row);
      if(d>best)continue;
      if(d<best || col==self || row==yy){signed char rt0=*(signed char *)&d_1bd984;*(signed char *)&d_1bd984=rt0;short rt1=*(short *)&d_1bd984;*(short *)&d_1bd984=rt1;int rt2=*(int *)&d_1bd984;*(int *)&d_1bd984=rt2;*(*&ox)=(signed char)col;*oy=(signed char)row;best=d;}
    }
    return best;
}

//@ f_070e50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Würfelt für einen Gegner einen erreichbaren freien Startplatz (ox, oy) auf dem Kampfraster
 *   aus, der (in den ersten 50 Versuchen) innerhalb der durch kind in d_1a1c24 vorgegebenen Mindest- und
 *   Höchstdistanz zum nächsten Helden liegt. Danach wird die Blickrichtung dir (0..3) zum nächsten Helden
 *   bestimmt, bei zweifeldrigen Großgegnern (check != 0) auch das Nachbarfeld für das hintere Körpersegment
 *   geprüft und mit 0xca reserviert sowie das Hauptfeld ebenfalls mit 0xca markiert. *(Hinweis: Enthält bei der
 *   Nachbarfeldprüfung für zweifeldrige Gegner sowohl eine Prüfung vor der Array-Grenzkontrolle als auch um 1 zu
 *   große Obergrenzen > 24 bzw. > 25; siehe Fehlerliste.)*
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger self, den Distanztyp kind, die Ausgabezeiger ox, oy und dir
 *   sowie das Flag check (1 bei zweifeldrigen Gegnern, sonst 0) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle d_1a1c24 enthält je Distanztyp die minimale und maximale Startentfernung zu
 *   den Helden, d_1a2734 liefert die Richtungsvektoren (dx, dy) für das zweite Feld großer Gegner und 0xca
 *   markiert im Raster d_1bd984 reservierte Gegner-Startfelder.
 === Ende Beschreibung === */
void f_070e50(int self, short kind, signed char *ox, signed char *oy, signed char *dir, int check)
{
    int r;
    short flag;
    short count;
    short d;
    signed char old;
    signed char tx;
    signed char ty;

    flag = 0;
    count = 0;
    old = d_1bd984[d_1a1c2c[d_1a1c36].y][d_1a1c2c[d_1a1c36].x];
    d_1bd984[d_1a1c2c[d_1a1c36].y][d_1a1c2c[d_1a1c36].x] = (signed char)0xcb;
    do {
        do {
            *ox = (signed char)(f_1457e0(24) - 1);
            *oy = (signed char)(f_1457e0(24) - 1);
        } while (d_1bd984[*oy][*ox] != (signed char)0);
        r = f_072610((void *)self, *ox, *oy);
        count++;
        d = f_070d70(self, *ox, *oy, &tx, &ty);
        if (!r) continue;
        if (count <= 50) {
            if (d < ((signed char *)d_1a1c24)[kind * 2]
                || d > ((signed char *)d_1a1c24)[kind * 2 + 1]) continue;
        }
        flag = 1;
        if (tx == *ox) {
            if (ty < *oy) *dir = 1; else *dir = 3;
        } else if (ty == *oy) {
            if (tx < *ox) *dir = 2; else *dir = 0;
        } else if (tx < *ox) {
            if (ty < *oy) {
                if (*oy - ty > *ox - tx) *dir = 1; else *dir = 2;
            } else {
                if (ty - *oy > *ox - tx) *dir = 3; else *dir = 2;
            }
        } else {
            if (ty < *oy) {
                if (*oy - ty > tx - *ox) *dir = 1; else *dir = 0;
            } else {
                if (ty - *oy > tx - *ox) *dir = 3; else *dir = 0;
            }
        }
        if (check) {
            if (((unsigned char (*)[25])d_1bd984)[*oy + *(short *)(d_1a2734 + *dir * 4 + 2)][*ox + *(short *)(d_1a2734 + *dir * 4)] != 0
                || *oy + *(short *)(d_1a2734 + *dir * 4 + 2) < 0
                || *oy + *(short *)(d_1a2734 + *dir * 4 + 2) > 24
                || *ox + *(short *)(d_1a2734 + *dir * 4) < 0
                || *ox + *(short *)(d_1a2734 + *dir * 4) > 25)
                flag = 0;
            else
                ((unsigned char (*)[25])d_1bd984)[*oy + *(short *)(d_1a2734 + *dir * 4 + 2)][*ox + *(short *)(d_1a2734 + *dir * 4)] = 0xca;
        }
    } while (!flag);
    d_1bd984[d_1a1c2c[d_1a1c36].y][d_1a1c2c[d_1a1c36].x] = old;
    d_1bd984[*oy][*ox] = (signed char)0xca;
}
