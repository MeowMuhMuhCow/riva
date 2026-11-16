/* === Beschreibung (Katalog) ===
 * Einheit gz_0e4640_t2
 *
 * Diese Einheit bildet den zweiten Teil von gz_0e4640 und definiert die Hilfsfunktion f_0e4c60, während die
 * übrigen Funktionen des Bereichs als Vorwärtsdeklarationen aufgeführt sind.
 === Ende Beschreibung === */
#include "RIVAMOUS.H"
// OPT -4r -oneatx -zp1 -s -ou
// P3 6/8 gleich (suche.py 26.10.2026, Basis gz_0e4640_P1.CPP)
// gz_0e4640.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0E4640-0x0E4CB0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01eb40(int p1);                                   // reg eax stapel 0
int f_01eb60(int p1);                                   // reg eax stapel 0
int f_01eb70(int p1, int p2);                           // reg eax edx stapel 0
int f_045db0(int p1, int p2);                           // reg eax edx stapel 0
int f_05e1d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e1f0(int p1);                                   // reg eax stapel 0
int f_05e200(int p1);                                   // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e7e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0a6200(int p1, int p2);                           // reg eax edx stapel 0
int f_0a6280(int p1, int p2);                           // reg eax stapel 0
int f_0a6740(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d4880(int p1);                                         // reg - stapel 0
int f_0d6710(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0d6ab0(int p1, int p2);                           // reg eax stapel 0
int f_0d6e10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3580(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3970(int p1, int p2);                           // reg eax edx stapel 0
int f_0e39e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e4380(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9590(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9610(int p1, int p2);                           // reg eax edx stapel 0
int f_14d5c9(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1bd90c;                    // 0x1BD90C
extern int d_1bf4e8;                    // 0x1BF4E8
extern short d_1bf51c;                    // 0x1BF51C
extern int d_1c0c94;                    // 0x1C0C94
extern int d_1c299c;                    // 0x1C299C
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c3078;                    // 0x1C3078
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (8), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern int d_1c2e68;
#define P(x) ((int)&(x))

//@ f_0e4640  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4640 aus gz_0e4640_t1 zum Setzen des Warte-Flags (+0x38) eines
 * Popup-Fensters.
 * - Eingaben: Die Funktion erwartet den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4640(int p1)
;
//@ f_0e4650  groesse 192 B, 55 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4650 aus gz_0e4640_t1 zum Schließen eines Popup-Fensters und
 * Wiederherstellen des Hintergrunds.
 * - Eingaben: Die Funktion erhält den Zeiger auf das Popup-Fensterobjekt p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4650(int p1)
;
//@ f_0e4710  groesse 288 B, 70 Bef, reg eax edx ebx ecx, stapel 0
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4710 aus gz_0e4640_t1 zum Vorbereiten des Layouts eines Popup-Fensters.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die Textkennung p2 sowie die Abstandsparameter p3 und
 *   p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4710(int p1, int p2, int p3, int p4)
;
//@ f_0e4830  groesse 576 B, 164 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4830 aus gz_0e4640_t1 zum Anzeigen eines Meldungs- oder Eingabe-Popups.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die Eingabefeldlänge p2 sowie die Textkennung p3.
 * - Rückgabewert: Sie gibt den eingegebenen Zahlenwert oder 0 bzw. -1 zurück.
 === Ende Beschreibung === */
short f_0e4830(int p1, int p2, int p3)
;
//@ f_0e4a70  groesse 576 B, 141 Bef, reg eax edx ebx ecx, stapel 8
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4a70 aus gz_0e4640_t1 zum Anzeigen eines Zahlenregler-Popups.
 * - Eingaben: Übergeben werden das Popup-Fensterobjekt p1, die Stellenanzahl p2, die Textkennung p3, der
 *   Minimalwert p4, der Maximalwert p5 und der Startwert p6.
 * - Rückgabewert: Sie gibt den gewählten Zahlenwert oder -1 zurück.
 === Ende Beschreibung === */
int f_0e4a70(int p1, short p2, int p3, short p4, short p5, short p6)
;
//@ f_0e4c60  ?
/* === Beschreibung (Katalog) ===
 * Liefert die konstante Zeilenbreite des VGA-Bildschirmpuffers (320 Pixel bzw. 0x140 Bytes) zurück.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den konstanten Wert 320 (0x140) zurück.
 === Ende Beschreibung === */
int f_0e4c60(void)
{ return 0x140; }
//@ f_0e4c70  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der Funktion f_0e4c70 aus gz_0e4640_t3.
 * - Eingaben: Die Funktion erwartet keine Parameter.
 * - Rückgabewert: Sie gibt den konstanten Wert 320 (0x140) zurück.
 === Ende Beschreibung === */
int f_0e4c70(void)
;
//@ f_0e4c80  ?
/* === Beschreibung (Katalog) ===
 * Vorwärtsdeklaration der String-Indizierungsfunktion f_0e4c80 aus gz_0e4640_t3.
 * - Eingaben: Übergeben werden das Zeigerarray p, der Textpuffer s sowie die Anzahl der Einträge n.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert.
 === Ende Beschreibung === */
void f_0e4c80(char **p, char *s, unsigned short n)
;
