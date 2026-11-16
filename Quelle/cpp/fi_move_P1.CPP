/* === Beschreibung (Katalog) ===
 * Einheit fi_move (07d080 - 07daf0)
 *
 * Überblick
 * Die Einheit fi_move (Fight Movement) setzt einen zuvor in d_1bd950 berechneten Bewegungspfad in eine
 * Laufanimation und eine Aktualisierung des Kampfrasters um - getrennt für Monster einschließlich zweifeldriger
 * Großgegner (f_07d080) und für Helden (f_07d6a0).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/2 gleich (suche.py 30.10.2026, Basis fi_move_P1.CPP)
// fi_move.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07D080-0x07DAF0
#include <string.h>
#include "RIVAMEM.H"

unsigned char f_043470(int p1);
int f_069460();
int f_07ea60(int p1, int p2);
int f_07eb00(int p1, int p2);
unsigned char f_0cfc50(int p1);
signed char f_0cfc70(int p1);
int f_0cfbf0(int p1, int p2);
int f_0cfbe0(int p1, int p2);
unsigned char f_0cffb0(int p1);
int f_0728f0(int p1);
unsigned char f_0729c0(int p1);
int f_071f20(int p1, int p2);
int f_071e50(int p1, int p2, int p3, int p4);
int f_06f400(int p1, int p2, unsigned char *p3, int p4, short *p5, int p6, int p7);
void f_069a00(int p1, int p2);
#pragma aux f_069a00 modify [eax edx]
int f_069be0(int p1);
int f_07ea20(int p1, int p2);
int f_07eba0(int p1, int p2, int p3);
int f_06f5c0(int p1, int p2);
int f_0757f0(int p1);
int f_07e930(int p1);
int f_07b5e0(int p1, int p2);
void f_145300(int p1, int p2, int p3);
struct RIVA_DIRS { short d[8]; };
extern RIVA_DIRS d_1a1f8c;
extern int d_1a1f90;
extern int d_1a1f94;
extern int d_1a1f9c;
extern int d_1a1fa0;
extern int d_1a1fa4;
extern char d_1bd928;
extern signed char d_1bd950[];
extern char d_1a275c[], d_1a2760[], d_1a2734[];
extern unsigned char *d_1bd984;
extern signed char d_1bda54;
//@ f_07d080  groesse 1568 B, 448 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt ein ein- oder zweifeldriges Monster (p2) entlang der im globalen Pfadpuffer d_1bd950
 *   abgelegten Schrittfolge über das Kampffeld, baut daraus die Dreh- und Laufanimationssequenz (p1 + 0x45) auf,
 *   zieht für Einzelschritte 1 AP bzw. für Doppelschritte 2 AP ab, spielt die Bewegung grafisch ab und
 *   aktualisiert abschließend das Kampfraster d_1bd984 (oder entfernt das Monster bei Erreichen eines
 *   Fluchtrandfeldes f_071f20).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Hauptkampfstruktur sowie den Monsterzeiger
 *   p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1bd950 enthält die Schrittfolge als Richtungsindizes (0..3, Ende -1), objekt
 *   und objekt2 verweisen auf die Darstellungs-Knoten des Vorder- und Hinterteils in OList, und d_1a275c bzw.
 *   d_1a2760 liefern die Animationsphasen-Codes für Einzel- und Doppelschritte.
 === Ende Beschreibung === */
#pragma aux f_069460 modify exact [eax];
#pragma aux f_069be0 modify exact [eax];
#pragma aux f_06f400 modify exact [eax ebx ecx edx];
#pragma aux f_071e50 modify exact [eax ebx edx];
#pragma aux f_071f20 modify exact [eax edx];
#pragma aux f_0728f0 modify exact [eax];
#pragma aux f_0729c0 modify exact [eax];
#pragma aux f_0757f0 modify exact [eax];
#pragma aux f_07b5e0 modify exact [eax edx];
#pragma aux f_07e930 modify exact [eax];
#pragma aux f_07ea20 modify exact [eax edx];
#pragma aux f_07ea60 modify exact [eax edx];
#pragma aux f_07eb00 modify exact [eax edx];
#pragma aux f_07eba0 modify exact [eax ebx edx];
#pragma aux f_0cfbe0 modify exact [eax edx];
#pragma aux f_0cfbf0 modify exact [eax edx];
#pragma aux f_0cfc50 modify exact [eax];
#pragma aux f_0cfc70 modify exact [eax];
#pragma aux f_0cffb0 modify exact [eax];
#pragma aux f_145300 modify exact [eax ebx edx];

struct DIRS_M { short d[4][2]; };
typedef int (*F_06F5C0_T)(int, int, int);
#pragma aux F_06F5C0_T modify exact [eax ebx edx];

void f_07d080(char *p1, int p2)
{
    DIRS_M richtungen = *(DIRS_M *)&d_1a1f8c;
    short i;
    short xx;
    int blockiert;
    char * objekt;
    short x;
    short yy;
    short x2;
    short y;
    short xx2;
    int tx;
    char * objekt2;
    short yy2;
    char kachel2;
    signed char dir;
    short y2;
    int ty;
    char kachel;
    char kennung2;
    short anzahl = 0;
    int flag = 0;
    char kennung;

    if (d_1bd928) f_069460();
    if (d_1bd950[0] < 0) return;

    objekt = (char *)f_07ea60((int)(p1 + 0x39), f_0cfc50(p2));
    x = (signed char)objekt[0];
    xx = x;
    y = (signed char)objekt[1];
    yy = y;
    kennung = objekt[0xe];
    if ((signed char)objekt[0xd] != (signed char)-1) {
        objekt2 = (char *)f_07eb00((int)(p1 + 0x39), (unsigned char)(objekt[0xd] + 0x14));
        kennung2 = objekt2[0xe];
        xx2 = (signed char)objekt2[0];
        yy2 = (signed char)objekt2[1];
    } else {
        objekt2 = 0;
    }
    f_145300((int)(p1 + 0x45), 0, 0xa4);
    *(int *)(p1 + 0x45) = f_0728f0(p2);
    i = 0;
    dir = f_0cfc70(p2);

    while (d_1bd950[i] >= 0 && anzahl < (short)0x26) {
        if (d_1bd928) f_069460();
        if (dir != d_1bd950[i])
            f_06f400((int)p1, p2, (unsigned char *)&dir, d_1bd950[i], &anzahl, (int)(p1 + 0x45), 1);
        if (d_1bd950[i] == d_1bd950[i + 1]) {
            p1[anzahl * 4 + 0x51] = d_1a2760[d_1bd950[i]];
            p1[anzahl++ * 4 + 0x52] = 0;
            i += 2;
            f_0cfbf0(p2, -2);
            x += 2 * richtungen.d[dir][0];
            y += 2 * richtungen.d[dir][1];
        } else {
            p1[anzahl * 4 + 0x51] = d_1a275c[d_1bd950[i]];
            p1[anzahl++ * 4 + 0x52] = 0;
            i++;
            f_0cfbf0(p2, -1);
            x += richtungen.d[dir][0];
            y += richtungen.d[dir][1];
        }
    }
    p1[anzahl * 4 + 0x51] = -1;
    if (!d_1bd928) {
        if ((signed char)p1[0x293] != (signed char)-1) {
            f_07eba0((int)(p1 + 0x39), (unsigned char)p1[0x293], 0);
            p1[0x293] = -1;
        }
        f_069a00(*(int *)(objekt + 0xf), (int)(p1 + 0x45));
        blockiert = 0;
        do {
            f_069460();
            if (f_0cffb0(p2))
                blockiert = !f_07ea20((int)(p1 + 0x39), f_0cfc50(p2));
            if (!blockiert) objekt = (char *)f_07ea60((int)(p1 + 0x39), f_0cfc50(p2));
        } while (!blockiert && *(int *)(objekt + 0xf) && !f_069be0(*(int *)(objekt + 0xf)));
        if (!blockiert) {
            f_07b5e0((int)p1, f_0cfc50(p2));
            // Haelt die Register- und Clobbersicht beim Aufruf wie im Original.
            ((F_06F5C0_T)f_06f5c0)((int)p1, p2, (int)(p1 + 0x45));
            f_0757f0((int)p1);
        }
    } else f_069460();

    kachel = ((unsigned char (*)[25])d_1bd984)[y][x];
    if (objekt2) {
        x2 = x + ((DIRS_M *)d_1a2734)->d[f_0cfc70(p2)][0];
        y2 = y + ((DIRS_M *)d_1a2734)->d[f_0cfc70(p2)][1];
        kachel2 = ((unsigned char (*)[25])d_1bd984)[y2][x2];
    }
    ty = y;
    tx = x;
    if (f_071f20(tx, ty)) {
        f_0cfbe0(p2, 0);
        f_071e50((int)p1, xx, yy, (unsigned char)kennung);
        if (d_1bd928) {
            objekt = (char *)f_07ea60((int)(p1 + 0x39), f_0cfc50(p2));
            objekt[0x1f] = 1;
            if (objekt2) {
                objekt2 = (char *)f_07eb00((int)(p1 + 0x39), (unsigned char)(objekt[0xd] + 0x14));
                objekt2[0x1f] = 1;
            }
        }
        if (objekt2)
            f_071e50((int)p1, xx2, yy2, (unsigned char)kennung2);
        flag = 1;
    } else {
        objekt = (char *)f_07ea60((int)(p1 + 0x39), f_0cfc50(p2));
        f_071e50((int)p1, xx, yy, (unsigned char)kennung);
        f_071e50((int)p1, tx, ty, (unsigned char)(f_0729c0(p2) + 0xa));
        if (objekt2) {
            if ((unsigned char)kachel != f_0729c0(p2) + 0x1e && (unsigned char)kachel != f_0729c0(p2) + 0xa)
                objekt[0xe] = kachel;
        } else {
            if ((unsigned char)kachel != f_0729c0(p2) + 0xa)
                objekt[0xe] = kachel;
        }
        objekt[0] = (char)x;
        objekt[1] = (char)y;
        objekt[0x20] = 1;
        if (objekt2) {
            objekt2 = (char *)f_07eb00((int)(p1 + 0x39), (unsigned char)(objekt[0xd] + 0x14));
            f_071e50((int)p1, xx2, yy2, (unsigned char)kennung2);
            f_071e50((int)p1, x2, y2, (unsigned char)(f_0729c0(p2) + 0x1e));
            if ((unsigned char)kachel2 != f_0729c0(p2) + 0xa && (unsigned char)kachel2 != f_0729c0(p2) + 0x1e)
                objekt2[0xe] = kachel2;
            objekt2[0] = (char)x2;
            objekt2[1] = (char)y2;
            objekt2[0x20] = 1;
        }
    }
    if (!d_1bd928) {
        f_07e930((int)(p1 + 0x39));
        if (flag) {
            // Haelt den 32-Bit-Store auf d_1bda54 wie im Original.
            *(int *)&d_1bda54 = 1;
            f_0757f0((int)p1);
        }
    } else f_069460();
}

//@ f_07d6a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bewegt einen Helden (p2) entlang der in d_1bd950 gespeicherten Schrittfolge über das
 *   Kampfraster, erzeugt die zugehörigen Dreh- und Geh-Animationskommandos (f_06e9e0), zieht die verbrauchten
 *   Aktionspunkte ab (f_043430), wartet das Abspielen der Laufanimation ab und trägt die neue Heldenposition in
 *   d_1bd984 und in der Darstellungsliste ein (bzw. nimmt den Helden auf einem Fluchtfeld vom Schlachtfeld).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p1 auf die Hauptkampfstruktur sowie den Heldenzeiger p2
 *   entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Puffer p1 + 0x45 nimmt die Animationssequenz für die Sprite-Engine auf, und
 *   objekt[0xe] sichert den ursprünglichen Bodenkachelwert des betretenen Kampffeldes.
 === Ende Beschreibung === */

int f_043420(int p1, int p2);
int f_043430(int p1, int p2);
signed char f_043490(int p1);
int f_06e9e0(int p1, int p2, int p3, int p4, short *p5, int p6, int p7);
int f_06ed10(int p1, int p2, int p3);
int f_0727e0(int p1);
unsigned char f_0d54c0(int p1);

#pragma aux f_042640 modify exact [eax];
#pragma aux f_043420 modify exact [eax edx];
#pragma aux f_043430 modify exact [eax edx];
#pragma aux f_043470 modify exact [eax];
#pragma aux f_043490 modify exact [eax];
#pragma aux f_069460 modify exact [eax];
#pragma aux f_069be0 modify exact [eax];
#pragma aux f_06e9e0 modify exact [eax ebx ecx edx];
#pragma aux f_06ed10 modify exact [eax ebx edx];
#pragma aux f_071e50 modify exact [eax ebx edx];
#pragma aux f_071f20 modify exact [eax edx];
#pragma aux f_0727e0 modify exact [eax];
#pragma aux f_0757f0 modify exact [eax];
#pragma aux f_07b5e0 modify exact [eax edx];
#pragma aux f_07e930 modify exact [eax];
#pragma aux f_07ea20 modify exact [eax edx];
#pragma aux f_07ea60 modify exact [eax edx];
#pragma aux f_07eb00 modify exact [eax edx];
#pragma aux f_07eba0 modify exact [eax ebx edx];
#pragma aux f_0d54c0 modify exact [eax];

struct DIRS2 { short d[4][2]; };
void f_07d6a0(char *p1, int p2)
{
    DIRS2 richtungen = *(DIRS2 *)&d_1a1f9c;
    short yy, xx, anzahl = 0;
    char kennung, kachel;
    short i, y, x;
    char *objekt;
    int blockiert;

    if (d_1bd928) f_069460();
    if (d_1bd950[0] < 0) return;

    objekt = (char *)f_07ea60((int)(p1 + 0x39), f_043470(p2));
    x = (signed char)objekt[0];
    xx = x;
    y = (signed char)objekt[1];
    yy = y;
    kennung = objekt[0xe];
    f_145300((int)(p1 + 0x45), 0, 0xa4);
    *(int *)(p1 + 0x45) = f_0727e0(p2);
    i = 0;

    while (d_1bd950[i] >= 0) {
        if (d_1bd928) f_069460();
        if (f_043490(p2) != d_1bd950[i])
            f_06e9e0((int)p1, p2, f_043490(p2), d_1bd950[i], &anzahl, (int)(p1 + 0x45), 1);
        if (d_1bd950[i] == d_1bd950[i + 1]) {
            p1[anzahl * 4 + 0x51] = d_1a2760[d_1bd950[i]];
            p1[anzahl++ * 4 + 0x52] = 0;
            i += 2;
            f_043430(p2, -2);
            x += 2 * richtungen.d[f_043490(p2)][0];
            y += 2 * richtungen.d[f_043490(p2)][1];
        } else {
            p1[anzahl * 4 + 0x51] = d_1a275c[d_1bd950[i]];
            p1[anzahl++ * 4 + 0x52] = 0;
            i++;
            f_043430(p2, -1);
            x += richtungen.d[f_043490(p2)][0];
            y += richtungen.d[f_043490(p2)][1];
        }
    }
    p1[anzahl * 4 + 0x51] = -1;
    if (!d_1bd928) {
        if ((signed char)p1[0x293] != (signed char)-1) {
            f_07eba0((int)(p1 + 0x39), (unsigned char)p1[0x293], 0);
            p1[0x293] = -1;
        }
        f_069a00(*(int *)(objekt + 0xf), (int)(p1 + 0x45));
        blockiert = 0;
        do {
            f_069460();
            if (f_042640((struct hero *)(p2)))
                blockiert = !f_07ea20((int)(p1 + 0x39), f_043470(p2));
            if (!blockiert) objekt = (char *)f_07ea60((int)(p1 + 0x39), f_043470(p2));
        } while (!blockiert && *(int *)(objekt + 0xf) && !f_069be0(*(int *)(objekt + 0xf)));
        if (!blockiert) {
            f_07b5e0((int)p1, f_043470(p2));
            f_06ed10((int)p1, p2, (int)(p1 + 0x45));
            f_0757f0((int)p1);
        }
    } else f_069460();

    kachel = ((unsigned char (*)[25])d_1bd984)[y][x];
    if (f_071f20(x, y)) {
        f_071e50((int)p1, xx, yy, (unsigned char)kennung);
        f_043420(p2, 0);
        if (d_1bd928) {
            objekt = (char *)f_07ea60((int)(p1 + 0x39), f_043470(p2));
            objekt[0x1f] = 1;
        }
    } else {
        objekt = (char *)f_07ea60((int)(p1 + 0x39), f_043470(p2));
        f_071e50((int)p1, xx, yy, (unsigned char)kennung);
        f_071e50((int)p1, x, y, (unsigned char)(f_0d54c0(p2) + 1));
        if ((unsigned char)kachel != f_0d54c0(p2) + 1) objekt[0xe] = kachel;
        objekt[0] = (char)x;
        objekt[1] = (char)y;
        objekt[0x20] = 1;
    }
    if (!d_1bd928) {
        f_07e930((int)(p1 + 0x39));
    } else f_069460();
}
