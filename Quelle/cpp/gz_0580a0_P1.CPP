/* === Beschreibung (Katalog) ===
 * Einheit gz_0580a0 (0x0580a0 - 0x058210)
 *
 * Überblick
 * Diese kleine Grenzeinheit zwischen diary.cpp und diary2.cpp enthält das Auswahlmenü zum Ausdrucken von
 * Tagebuchseiten auf einen angeschlossenen Drucker oder in die Textdatei ..\DIARY.TXT.
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 25.10.2026, Basis gz_0580a0_P1.CPP)
// gz_0580a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0580A0-0x058210
#include <string.h>
#include "RIVAMEM.H"



int f_059a40(short *p1, int p2, int p3);                 // reg eax edx ebx
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
unsigned short __cdecl f_0bf820(int *p1, int p2, int p3, int p4, int p5, int p6);
int f_0e8c20(const char *p1);
char *f_148518(int v, char *buf, int radix);
int f_145259(int h);
extern unsigned short d_1bfaf0;            // 0x1BFAF0
extern int d_1c0098;                    // 0x1C0098
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1b6e40[];           // Text 0x1B6E40
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0580a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet das Auswahlmenü "Tagebuch drucken" (0x803006e), nachdem der Drucker bzw. die
 *   Ausgabedatei ..\DIARY.TXT über f_0e8c20 vorbereitet wurde. Je nach Auswahl druckt die Funktion über f_059a40
 *   entweder nur die aktuell aufgeschlagene Seite (Punkt 1), einen über zwei Zahleneingabedialoge (0x8030072
 *   "von", 0x8030073 "bis") abgefragten Seitenbereich (Punkt 2, wobei vertauschte Grenzen automatisch geordnet
 *   werden) oder sämtliche Tagebuchseiten (Punkt 3) und schließt im Dateimodus (d_1bfaf0 == 0) anschließend die
 *   Ausgabedatei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Tagebuch-Objekt (d_1c2c00, mit der
 *   Gesamtseitenzahl in p1[0] und der aktuellen Seite in p1[1]) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bfaf0 speichert den Druckermodus (0 für Dateiausgabe nach
 *   ..\DIARY.TXT unter dem Dateihandle d_1c0098, > 0 für eine Druckerschnittstelle).
 === Ende Beschreibung === */
void f_0580a0(short *p1)
{
    char buf[12]; short r;
    unsigned short u;
    short s;
    char *p;
    if (!f_0e8c20(d_1b6e40)) {
        u = f_0bf820(&d_1c2c64, 0x803006e, 3, 0x803006f, 0x8030070, 0x8030071);
        switch (u) {
        case 1:
            f_059a40(p1, p1[1], p1[1]);
            break;
        case 2:
            r = f_0bf7b0((int)&d_1c2c64, (short)strlen(f_148518((unsigned short)*p1, buf, 10)), 0x8030072, 1, *p1, 1);
            if (r != -1) {
                s = f_0bf7b0((int)&d_1c2c64, (short)strlen(f_148518((unsigned short)*p1, buf, 10)), 0x8030073, 1, *p1, *p1);
                if (s != -1) {
                    if (s < (short)r) {
                        f_059a40(p1, (short)(s - 1), (short)((short)r - 1));
                    } else {
                        f_059a40(p1, (short)((short)r - 1), (short)(s - 1));
                    }
                }
            }
            break;
        case 3:
            f_059a40(p1, 0, (short)(*p1 - 1));
            break;
        }
        { signed char flag = (signed char)d_1bfaf0; if (flag == 0) {
            f_145259(d_1c0098);
        } }
    }
}
