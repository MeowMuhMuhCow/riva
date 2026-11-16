/* === Beschreibung (Katalog) ===
 * Einheit gz_0bde40 (Adresse 0x0bde40 - 0x0be0f0)
 *
 * Diese Einheit bildet den Auftakt des Menü- und Dialogfenster-Systems direkt vor menu.cpp. Sie enthält
 * Zugriffsfunktionen auf die Menüstruktur sowie die Berechnungs- und Zeichenroutinen für den mehrteiligen
 * Pergament- bzw. Steinrahmen und die Auswahlpunkte eines Dialog- oder Auswahlmenüs.
 === Ende Beschreibung === */
// P3 2/4 gleich (suche.py 29.10.2026, Basis gz_0bde40_P1.CPP)
// gz_0bde40.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BDE40-0x0BE0F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05e2a0(void *p1, void *p2, void *p3, void *p4, void *p5);
int f_05e2d0(void *p1, int p2, int p3, int p4, int p5);
int f_05e7e0(void *p1, int p2, int p3);
int f_05e800(void *p1, void *p2, void *p3);
int f_0be0f0(int p1, int p2, int p3);
int f_0e33c0(int p1);
int f_0e36d0(int p1, int p2, int p3, int p4);
int f_0e9610(void *p1, int p2);
void f_149d20(void);
extern int d_1c38b0;
//@ f_0bde40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion löscht das Abschluss- bzw. Schließflag bei Offset +0x8a einer Menüstruktur p (p[0x8a]
 *   = 0).
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bde40(char *p)
{
    p[0x8a] = 0;
}
//@ f_0bde50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest den 16-Bit-Status- oder Auswahlwert bei Offset +0x4c einer Menüstruktur
 *   p aus.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die Menüstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt den vorzeichenbehafteten 16-Bit-Wert bei Offset +0x4c zurück.
 === Ende Beschreibung === */
int f_0bde50(char *p)
{
    return *(short *)(p + 0x4c);
}
//@ f_0bde60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet die gesamte Textzeilenhöhe für p2 Menü-Antwortoptionen im Zeiger-Array *p3,
 *   indem sie die rechte Textbegrenzung vorübergehend um 10 Pixel verringert und für jede Option die benötigte
 *   Zeilenanzahl über f_0e9610 aufsummiert.
 * - Eingaben: Die Funktion nimmt den Menü-Zeiger p1, die Anzahl der Menüpunkte p2 sowie einen Zeiger p3 auf das
 *   aktuelle Textzeiger-Array entgegen.
 * - Rückgabewert: Die Funktion gibt die Gesamtzahl der benötigten Textzeilen (sum) über alle Menüoptionen
 *   zurück.
 === Ende Beschreibung === */
short f_0bde60(int p1, int p2, int **p3)
{
    short f_0e9610_s(void *p1, int p2);
    #pragma aux f_0e9610_s "f_0e9610"
    struct Frame { short d[2], w[2], x[2]; } f;
    short sum;
    short i;
    int *q;
    f_05e2a0(&d_1c38b0, f.d, f.w, f.d, f.d);
    short y[2];
    f_05e800(&d_1c38b0, y, f.x);
    f_05e2d0(&d_1c38b0, -1, (short)(f.w[0] - 10), -1, -1);
    sum = 0;
    f_05e7e0(&d_1c38b0, 0, 0);
    for (i = 0; i < *(short *)&p2; i++) {
        q = ++*p3;
        sum += f_0e9610_s(&d_1c38b0, q[-1]);
    }
    f_05e2d0(&d_1c38b0, -1, f.w[0], -1, -1);
    f_05e7e0(&d_1c38b0, y[0], f.x[0]);
    return sum;
}
//@ f_0bdf20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeichnet den oberen, mittleren (in 4-Zeilen-Streifen gestückelten) und unteren
 *   Hintergrundstreifen eines dynamisch hohen Auswahlmenüs (f_0e33c0, f_0e36d0) und setzt anschließend vor jeden
 *   der p2 Menüpunkte das kleine runde Auswahl-Aufzählungszeichen (0x0d über f_0be0f0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die Menüstruktur, die Anzahl der auswählbaren Menüpunkte p2
 *   sowie einen Zeiger p3 auf das Array der Options-Textzeiger entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bdf20(int p1, short p2, int **p3)
{
    short f_0e9610_s(void *p1, int p2);
    short sum;
    unsigned short rem;
    short a34[2], a30[2], a2c[2], a28[2];
    short x;
    int *q;
    short b, i;
    #undef V
    #define V(x) ((x)[0])
    f_0e33c0(p1);
    f_0e36d0(p1, 0, 0, 0x20);
    sum = 0;
    x = 0;
    rem = *(short *)(p1 + 0x5c) % 4;
    b = *(unsigned short *)(p1 + 0x5c) - rem;
    if (b > 0) {
        for (x = 0; x < b; x += 4) {
            f_0e36d0(p1, (short)(x + 2), 1, 0x20);
        }
    }
    if ((short)rem) {
        f_0e36d0(p1, (short)(x + 2), 1, (short)(rem << 3));
    }
    f_0e36d0(p1, (short)(*(short *)(p1 + 0x5c) + 2), 2, 0x20);
    if (p2) {
        f_05e2a0(&d_1c38b0, &a30, &a34, &a30, &a30);
        f_05e800(&d_1c38b0, &a2c, &a28);
        f_05e2d0(&d_1c38b0, -1, (short)(V(a34) - 10), -1, -1);
        f_05e7e0(&d_1c38b0, 0, 0);
        for (i = 0; i < p2; i++) {
            f_0be0f0(p1, (short)((*(short *)(p1 + 0x28) + sum + 2) * 8 + *(short *)(p1 + 0x16)), 0xd);
            q = ++*p3;
            sum += f_0e9610_s(&d_1c38b0, q[-1]);
        }
        f_05e2d0(&d_1c38b0, -1, (short)V(a34), -1, -1);
        f_05e7e0(&d_1c38b0, (short)V(a2c), (short)V(a28));
    }
    d_1c38b0 = (d_1c38b0 & 0) ? 0 : d_1c38b0; // haelt die Registerzuteilung wie im Original
    f_149d20();
}
