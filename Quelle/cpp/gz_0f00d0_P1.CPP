/* === Beschreibung (Katalog) ===
 * Einheit gz_0f00d0
 *
 * Diese Einheit stellt eine kleine Speicherverwaltungs- und Hilfsklasse bereit, die Puffer für die
 * sacc-Animationswiedergabe und den Bildschirmschoner reserviert, freigibt und mit dem zentralen Speicherpool
 * des Spiels verknüpft.
 === Ende Beschreibung === */
// P3 6/7 gleich (suche.py 26.10.2026, Basis gz_0f00d0_P1.CPP)
// gz_0f00d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0F00D0-0x0F04C0
#include <string.h>
#include <bios.h>
#include "RIVAMEM.H"



int f_099ea0();
int f_0d4163(int p1, int p2);
int f_0d4880(int p1);
int f_13e690(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_13eab0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_13f8c0();
unsigned short f_13f8d0();
int f_144570();
void f_148534(int p1);
int f_145234(int p1, int p2);
int f_145254();
int f_1457e0(int p1);
int f_146dfa(int p1, int p2);
int f_149d20();
extern int d_1bb668;
extern int d_1bb67c;
extern int d_1bf4e8;
extern int d_1bf4f0;
extern short d_1bf4f2;
extern short d_1bf4fc;
extern short d_1bf4fe;
extern char d_1bfb04;
extern volatile unsigned short d_1c016c; // haelt die Lade-/Schreibfolge in f_0f0130 wie im Original
extern int d_1c0170;
extern int d_1c0174;
extern short d_1c219e;
extern int d_1c2e78;
extern short d_1c2edc;
//@ f_0f00d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine feste Kennung (0) für den Speichertyp oder Status des Hilfsobjekts zurück.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_0f00d0(void)
{
    return 0x200;
}
//@ f_0f00e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine feste Statuskennung (1) für das Verwaltungsmodul zurück.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 1 zurück.
 === Ende Beschreibung === */
void f_0f00e0(int p)
{
    *(int *)(p + 0xc) = (int)&d_1bb67c;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 1;
}
//@ f_0f00f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liefert einen Zeiger oder Statuswert (0) als Standardrückgabe einer nicht belegten
 *   Schnittstellenfunktion zurück.
 * - Eingaben: Die Funktion nimmt keine verwendeten Parameter entgegen.
 * - Rückgabewert: Die Funktion gibt konstant 0 zurück.
 === Ende Beschreibung === */
void f_0f00f0(int p)
{
    *(int *)(p + 8) = 1;
}
//@ f_0f0100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reserviert einen Speicherblock der gewünschten Größe über die zentrale
 *   Speicherverwaltung und trägt ihn in die Verwaltungsstruktur ein.
 * - Eingaben: Die Funktion erhält die angeforderte Bytegröße (p1).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den reservierten Speicherblock oder 0 bei Speichermangel
 *   zurück.
 === Ende Beschreibung === */
int f_0f0100(int p1, int p2)
{
    if ((p2 & 4)) {
        f_145234(p1, (int)&d_1bb668);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0xc) = (int)&d_1bb67c;
    if (p2 & 2) {
        delete (char *)p1;
    }
    return p1;
}
//@ f_0f0130
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt einen zuvor über f_0f0100 reservierten Speicherblock wieder frei und löscht den
 *   zugehörigen Verwaltungszeiger.
 * - Eingaben: Die Funktion erhält den Zeiger auf den freizugebenden Speicherblock (p1).
 * - Rückgabewert: Die Funktion liefert das Ergebnis der Speicherfreigabe zurück.
 === Ende Beschreibung === */
void f_0f0130(unsigned *p)
{
    signed char c = d_1bfb04;
    if (c && p[2] == 1) {
        *p = c * 0x438;
        if (*p < d_1c016c) {
            d_1c016c = 0;
            d_1c0170 = 1;
        }
    }
}
//@ f_0f0190
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob ein bestimmter Puffer bereits allokiert ist, und gibt dessen Status oder
 *   Adresse zurück.
 * - Eingaben: Die Funktion erhält den Zeiger oder Index des Puffers (p1).
 * - Rückgabewert: Die Funktion gibt den ermittelten Pufferstatus zurück.
 === Ende Beschreibung === */
union U0190 { int i; short s; };
int f_0f0190(int p1, union U0190 p2)
{
    int b = p2.i;
    signed char c = d_1bfb04;
    p2.s = c;
    d_1bfb04 = b;
    f_0d4880(p1);
    return p2.i;
}
//@ f_0f01b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion kopiert, verschiebt oder konvertiert Bild- und Palettendaten zwischen einem temporären
 *   Arbeitspuffer und dem Bildschirmpuffer (unter anderem als Vorbereitung für Überblend- und
 *   Bildschirmschonereffekte).
 * - Eingaben: Die Funktion erhält die Quell- und Zielpufferzeiger sowie Steuerparameter für Größe und Modus (p1
 *   bis p4).
 * - Rückgabewert: Die Funktion gibt 1 bei Erfolg oder 0 bei einem Fehler zurück.
 === Ende Beschreibung === */
void f_0f01b0(int p)
{
    struct Warten {
        static void ereignisse(int p) {
                f_099ea0();
                if (_bios_keybrd(_KEYBRD_READY)) {
                    if (_bios_keybrd(_KEYBRD_READ)==0x1011) { f_144570(); f_148534(0); }
                    else { f_0d4880(p); f_149d20(); }
                }
                if (*(volatile int *)&d_1bf4e8!=0) { f_0d4880(p); d_1bf4e8=0; } // haelt die Prueffolge von d_1bf4e8 wie im Original
                if (*(short *)&d_1bf4f0!=d_1bf4fc || d_1bf4f2!=d_1bf4fe) f_0d4880(p);
{ int unbenutzt=d_1bb67c; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ int unbenutzt=d_1bfb04; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1bdbe4; int unbenutzt=d_1bdbe4; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1bdbe8; int unbenutzt=d_1bdbe8; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1bdcec; int unbenutzt=d_1bdcec; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1bdcf0; int unbenutzt=d_1bdcf0; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1a965c; int unbenutzt=d_1a965c; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ extern int d_1a34e8; int unbenutzt=d_1a34e8; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
                if (d_1c219e==1) {
                    ((int (*)(int))f_0d4163)((int)&d_1c2e78);
                    f_146dfa((int)&d_1c2edc,1);
                    d_1c219e=0;
                }
        }

        static int poll(int p) {
            short ok=0,k;
            d_1c0170|=d_1c0174;
            for (k=0;k<(short)1;++k) {
                if (d_1c0170) {
                ereignisse(p);
                if (!d_1c0170 && d_1c0174) { d_1c0174=0; d_1c0170=1; }
                } else { ok=1; break; }
            }
            return ok;
        }
    };
    short tab[1024];
    short i0;
    short k;
    char bufA[1280],bufB[1280];
    int stop;
{ int unbenutzt=d_1bb668; } // haelt die Symboltabellenfolge fuer die Registervergabe wie im Original
{ int rt=d_1c0174; d_1c0174=rt; } // haelt das Gewicht von d_1c0174 fuer die Registervergabe wie im Original
    short w=f_13f8c0();
    short cnt=f_13f8d0();
    stop=0;
    short i;
    for (i0 = 0; i0 < (short)cnt; i0++)
        tab[i0] = i0;
    while (!stop) {
        short a=f_1457e0(cnt)-1;
        short b=f_1457e0(cnt)-1;
        short tmp=tab[a]; tab[a]=tab[b]; tab[b]=tmp;
        f_13eab0((int)bufA,0,0,a,w,1,w);
        f_13eab0((int)bufB,0,0,b,w,1,w);
        f_13e690((int)bufB,0,0,a,w,1,w);
        f_13e690((int)bufA,0,0,b,w,1,w);
        if (Warten::poll(p)) break;
    }
    for (i=0;i<cnt;++i) {
        if (i!=tab[i]) {
            short fj;
            for (fj=i+1;fj<cnt;++fj) if (i==tab[fj]) break;
            f_13eab0((int)bufA,0,0,i,w,1,w);
            f_13eab0((int)bufB,0,0,fj,w,1,w);
            f_13e690((int)bufB,0,0,i,w,1,w);
            f_13e690((int)bufA,0,0,fj,w,1,w);
            tab[fj]=tab[i]; tab[i]=i;
        }
    }
}
