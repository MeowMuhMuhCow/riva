/* === Beschreibung (Katalog) ===
 * Einheit gz_0bd2e0_rand910a (Adresse 0x0bd2e0 - 0x0bd540)
 *
 * Diese Einheit bildet die erste Rand-Aufteilung des Hilfsmoduls gz_0bd2e0 zwischen dem Masken-Modul (mask.cpp)
 * und der Speicherverwaltung (memory.cpp). In dieser Datei sind die Rahmen-Hilfsfunktion f_0bd2e0, die
 * Begrenzungsfunktion f_0bd350 sowie der allgemeine Würfelgenerator f_0bd360 ausimplementiert, während die
 * nachfolgenden sechs Funktionen (f_0bd3e0 bis f_0bd540) als Vorwärtsdeklarationen markiert sind und in
 * gz_0bd2e0_rand910b bzw. gz_0bd2e0_rand910c stehen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 9/9 gleich (suche.py 25.10.2026, Basis gz_0bd2e0_P1.CPP)
// gz_0bd2e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BD2E0-0x0BD5A0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60();                       // nicht in clobber.tsv
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_057220(int p1, int p2, int p3);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_060a80(int p1);
int f_091f70(int p1);
int f_0dcbb0(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
short f_0de800(int p1);
short f_0de820(int p1);

int f_1457e0(int p1);
int f_145234(int p1, int p2);
void f_145254(void);
extern int d_1bb2c4;
extern char d_1bdb74;
extern int d_1c0004;
extern int d_1c2be0;
extern int d_1c2c00;
//@ f_0bd2e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion lädt das passende Teilbild des Sichtfenster-Innenrahmens aus der Grafikressource
 *   0x40005 (Teilbild 1 bei aktivem Dungeon/Gebäude oder speziellem Stadtbereich, sonst Teilbild 0) in den
 *   übergebenen Bitmap-Puffer p2.
 * - Eingaben: Die Funktion nimmt den ungenutzten this-Zeiger p1 sowie den Ziel-Bitmap-Puffer p2 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd2e0(int p1, int p2)
{
    short s;
    int b;
    s = f_0de800(d_1c0004);
    b = 0;
    if (s == -1) {
        s = f_0de820(d_1c0004);
        if (f_060a80((int)s) != 0) b = 1;
    } else {
        b = 1;
    }
    if (b == 1) f_04fef0((int)&d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(p2))->f_0fb0b0())), 0, b, 0, 0x140); else f_04fef0((int)&d_1c2be0, 0x40005, ((int)(((RivaRasterImage*)(p2))->f_0fb0b0())), 0, 0, 0, 0x140);
}
//@ f_0bd350
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese mathematische Hilfsfunktion begrenzt (clamp) einen ganzzahligen Wert p1 auf das abgeschlossene
 *   Intervall zwischen der Untergrenze p2 und der Obergrenze p3.
 * - Eingaben: Die Funktion nimmt den zu begrenzenden Wert p1, das Minimum p2 und das Maximum p3 entgegen.
 * - Rückgabewert: Die Funktion gibt den auf den Bereich [p2, p3] begrenzten Wert zurück.
 === Ende Beschreibung === */
int f_0bd350(int p1, int p2, int p3)
{
    if (p1 < p2) p1 = p2;
    if (p1 > p3) p1 = p3;
    return p1;
}
//@ f_0bd360
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Würfelfunktion wertet ein gepacktes 16-Bit-Würfelformat p1 (wie es für Waffenschaden
 *   und Beutetabellen verwendet wird) aus: Die oberen 4 Bits ((p1 & 0xf000) >> 12) geben die Anzahl der Würfel
 *   an, die nächsten 4 Bits ((p1 & 0x0f00) >> 8) bestimmen den Würfeltyp (1 = W6, 2 = W20, 3 = W3, 4 = W4, sonst
 *   W100), und das untere Vorzeichenbyte (signed char)p1 bildet den festen Zahlenbonus.
 * - Eingaben: Die Funktion nimmt das gepackte 16-Bit-Würfelwort p1 entgegen.
 * - Rückgabewert: Die Funktion gibt die gewürfelte Gesamtsumme einschließlich des vorzeichenbehafteten Bonus
 *   zurück.
 *
 *
 * Vorwärtsdeklarationen (Implementierung in gz_0bd2e0_rand910b und gz_0bd2e0_rand910c)
 *
 * Die folgenden Funktionen sind in dieser Teileinheit nur als Prototypen deklariert und in den Nachbareinheiten
 * beschrieben:
 * - f_0bd3e0 (0x0bd3e0, in gz_0bd2e0_rand910b)
 * - f_0bd400 (0x0bd400, in gz_0bd2e0_rand910b)
 * - f_0bd490 (0x0bd490, in gz_0bd2e0_rand910b)
 * - f_0bd4d0 (0x0bd4d0, in gz_0bd2e0_rand910c)
 * - f_0bd510 (0x0bd510, in gz_0bd2e0_rand910c)
 * - f_0bd540 (0x0bd540, in gz_0bd2e0_rand910c)
 === Ende Beschreibung === */
short f_0bd360(short p1)
{
    int sum = 0;
    short dice, s, cnt;
    signed char bonus;
    cnt = (short)(((short)p1 & 0xf000) >> 12);
    s = (short)(((short)p1 & 0xf00) >> 8);
    dice = s == 1 ? 6 : s == 2 ? 20 : s == 3 ? 3 : s == 4 ? 4 : 100;
    bonus = (signed char)p1;
    for (s = 0; s < cnt; s++) {
        sum += f_1457e0((int)dice);
    }
    return bonus + sum;
}
//@ f_0bd3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Schauplatz-Objekt mit der Kennung 0x1b (27) über den
 *   Basiskonstruktor f_05ff60 und trägt die virtuelle Methodentabelle d_1bb2d8 bei Offset +0x08 ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das zu initialisierende Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
extern int d_1bb2d8;
void f_0bd3e0(int p1)
;
//@ f_0bd400
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignis-Methode verarbeitet die Aktionscodes 0x65 (101) und 0x66 (102) des Schauplatzes 0x1b:
 *   Bei 0x65 wechselt die Gruppe über f_0dd7f0 (Typ 0x0b, Ziel 5000) den Schauplatz; bei 0x66 wird das
 *   Handlungsflag d_1bdb74 = 1 gesetzt, der Kampf 0x1e (30, f_091f70) gestartet, die Gruppe mit 20
 *   Abenteuerpunkten (f_0dcbb0) und dem Tagebucheintrag 0x8030048 (f_057220) belohnt und schließlich zum Ziel
 *   0x13f5 (5109) übergeleitet.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie den 16-Bit-Aktionscode p2 entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Code 0x65 oder 0x66 verarbeitet wurde, oder 0 im
 *   Standardfall.
 === Ende Beschreibung === */
short f_0bd400(int p1, unsigned short p2)
;
//@ f_0bd490
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Schauplatz-Objekt der Klasse d_1bb2d8 (d_1bb2c4) oder ein Array
 *   solcher Objekte (p2 & 4) ab, ruft den Basisdestruktor f_060030 auf und gibt bei gesetztem Bit p2 & 2 den
 *   Objektspeicher frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie die Watcom-Destruktor-Flags p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0bd490(int p1, unsigned p2)
;
//@ f_0bd4d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor setzt sämtliche neun 32-Bit-Felder (36 Bytes) eines Speicherknotens (Node) auf 0.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf die zu initialisierende Node-Struktur entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd4d0(int *p)
;
//@ f_0bd510
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion richtet einen Speicherknoten (Node) als freien, belegten Listeneintrag
 *   (used = 1, fre = 1) ein und trägt den übergeordneten Pool-Zeiger p2, die Blockadresse p3 sowie die
 *   Blockgröße p4 ein.
 * - Eingaben: Die Funktion nimmt den Knotenzeiger p1, den Pool-Zeiger p2, die Speicheradresse p3 und die
 *   Blockgröße p4 entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd510(int *p1, int p2, int p3, int p4)
;
//@ f_0bd540
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion hängt einen Speicherknoten t aus der doppelt verketteten Liste (prev/next) des
 *   Speicher-Pools aus und setzt alle Felder des Knotens wieder auf 0 zurück, sodass der Knoteneintrag im
 *   Pool-Array wiederverwendet werden kann.
 * - Eingaben: Die Funktion nimmt den Zeiger t auf den freizugebenden Node-Eintrag entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bd540(int *p1)
;
