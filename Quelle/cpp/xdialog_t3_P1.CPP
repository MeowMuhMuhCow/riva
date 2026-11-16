/* === Beschreibung (Katalog) ===
 * Einheit xdialog_t3 (0x142F70 - 0x143330)
 *
 * Überblick
 *
 * Die Einheit xdialog_t3 bildet den dritten Teil des Multiple-Choice-Dialogsystems (xdialog.cpp) und enthält den
 * Konstruktor (f_142f70), den Destruktor (f_1430a0) sowie die übergeordnete Hauptsteuerfunktion (f_143170), die
 * ein komplettes Gespräch vom Öffnen bis zum Schließen durchführt.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 1/3 gleich (suche.py 24.10.2026, Basis xdialog_t3_P1.CPP)
// xdialog.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x140B40-0x143330
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e240(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_01e3a0(int p1, int p2);                           // reg eax edx stapel 0
int f_01e430(int p1, int p2);                           // reg eax edx stapel 0
int f_01e570(int p1);                                   // reg eax stapel 0
int f_04fe30();                       // nicht in clobber.tsv
int f_04fe60(int p1, int p2);                           // reg eax stapel 0
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
int f_05e1f0(int p1);                                   // reg eax stapel 0
int f_05e200(int p1);                                   // reg eax stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e420(int p1, int p2);                           // reg eax edx stapel 0
int f_05e440(int p1, int p2);                           // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
           // reg eax stapel 0
                   // reg eax edx ebx stapel 0
int f_145970(int p1, int p2);                           // reg eax edx stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b10(int p1);                                   // reg eax stapel 0
int f_149cf0();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a94b0;                    // 0x1A94B0
extern int d_1a9564;                    // 0x1A9564
extern int d_1a965c;                    // 0x1A965C
extern int d_1b8708;                    // 0x1B8708
extern int d_1b870a;                    // 0x1B870A
extern int d_1b870b;                    // 0x1B870B
extern int d_1bd762;                    // 0x1BD762
extern short d_1bd766;
extern int d_1bf510;                    // 0x1BF510
extern int d_1bf514;                    // 0x1BF514
extern short d_1bf51c;
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1c1160;                    // 0x1C1160
extern short d_1c1164;
extern short d_1c1166;
extern int d_1c1168;                    // 0x1C1168
                    // 0x1C2098
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a948c[];           // Text 0x1A948C
// --- eigene Funktionen (36), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#define AD(x) ((int)&(x))
#define W8(p,o) (*(unsigned char *)((char *)(p) + (o)))
#define W16(p,o) (*(short *)((char *)(p) + (o)))
#define W32(p,o) (*(int *)((char *)(p) + (o)))
void f_140980();
int f_142e10(int p1);
int f_142d20(int p1);
int f_142920(int p1);
int f_142e90(int p1);
struct B33 { int a[8]; char c; };
struct f_0fad20 { ~f_0fad20(); };
struct f_01e290 { ~f_01e290(); };
struct CG { int x; CG() { f_0ce7c0((int)this); } ~CG() { f_0ce7e0((int)this, 0); } };

//@ f_142f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor einer xdialog-Gesprächsinstanz (p1): Setzt das globale Dialog-Aktiv-Flag d_1c1160
 *   = 1, speichert die Dateikennung der Dialogressource (W32(p1, 0x10) = p2), kopiert den 33 Byte großen
 *   Konfigurations- und Callback-Block *p3 nach p1 + 0x14, initialisiert alle Grafik-, Daten- und Pufferzeiger
 *   mit 0, setzt das Standard-Ungeduldslimit W16(p1, 0xA7) = 3 und markiert die Antwort-Klickzonentabelle (p1 +
 *   0x6B) als leer (-1).
 * - Eingaben: Zeiger p1 auf die zu initialisierende Dialoginstanz (179 Bytes), Ressourcenkennung p2 (int) der
 *   Dialogdatei und Zeiger p3 (int) auf die 33-Byte-Konfigurationsstruktur (B33).
 * - Rückgabewert: Keiner (void, bzw. this in EAX).
 * - Wichtige Variablen:
 *   - d_1c1160: Globales Flag, das anzeigt, dass gerade ein xdialog-Gespräch aktiv ist.
 *   - W16(p1, 0xA7): Maximale Anzahl unbeantwortbarer Fragen (Standardwert 3), bevor der Gesprächspartner die
 *     Geduld verliert.
 === Ende Beschreibung === */
void f_142f70(int p1, int p2, int p3)
{
    W32(p1, 0) = 0;
    W32(p1, 4) = 0;
    W32(p1, 8) = 0;
    W32(p1, 0xc) = 0;
    d_1c1160 = 1;
    W32(p1, 0x10) = p2;
    *(struct B33 *)((char *)p1 + 0x14) = *(struct B33 *)p3;
    W32(p1, 0x35) = 0;
    W32(p1, 0x39) = 0;
    W32(p1, 0x3d) = 0;
    W32(p1, 0x41) = 0;
    W32(p1, 0x45) = 0;
    W32(p1, 0x49) = 0;
    W32(p1, 0x4d) = 0;
    W32(p1, 0x51) = 0;
    W32(p1, 0x55) = 0;
    W32(p1, 0x5d) = 0;
    W32(p1, 0x59) = 0;
    W32(p1, 0x61) = 0;
    W8(p1, 0x65) = 0;
    W8(p1, 0x66) = 0;
    W32(p1, 0x67) = 0;
    W32(p1, 0x9b) = 0;
    W16(p1, 0x6b) = -1;
    W16(p1, 0x6d) = -1;
    W16(p1, 0x6f) = -1;
    W16(p1, 0x71) = -1;
    W16(p1, 0x73) = -1;
    W8(p1, 0x93) = 0;
    W8(p1, 0x94) = 0;
    W32(p1, 0x95) = 0;
    W16(p1, 0x99) = 0;
    W32(p1, 0x9f) = 0;
    W32(p1, 0xa3) = 0;
    W16(p1, 0xa7) = 3;
    W16(p1, 0xa9) = 0;
    W32(p1, 0xab) = 0;
    W32(p1, 0xaf) = 0;
}

//@ f_1430a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor einer xdialog-Gesprächsinstanz (p1): Gibt alle während des Gesprächs dynamisch
 *   angelegten Grafikpuffer (p1 + 0x00 bis p1 + 0x0C), den Dialogdatenpuffer (p1 + 0x35), den
 *   Themen-Textspeicher (p1 + 0x59), das Sichtbarkeitsarray (p1 + 0x61), das Themenphasen-Array (p1 + 0xAB)
 *   sowie den Formatierungspuffer (p1 + 0xAF) wieder frei und setzt d_1c1160 = 0 zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Destruktor-Steuerflag p2 (int).
 * - Rückgabewert: Der Objektzeiger p1 (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_1430a0(int p1, int p2)
{
    if (W32(p1, 0)) delete (f_0fad20 *)W32(p1, 0);
    if (W32(p1, 4)) delete (f_0fad20 *)W32(p1, 4);
    if (W32(p1, 8)) delete (f_0fad20 *)W32(p1, 8);
    if (W32(p1, 0xc)) delete (f_0fad20 *)W32(p1, 0xc);
    if (W32(p1, 0x35)) delete (char *)W32(p1, 0x35);
    if (W32(p1, 0x59)) delete (f_01e290 *)W32(p1, 0x59);
    if (W32(p1, 0x61)) delete (char *)W32(p1, 0x61);
    if (W32(p1, 0xab)) delete (char *)W32(p1, 0xab);
    if (W32(p1, 0xaf)) delete (char *)W32(p1, 0xaf);
    d_1c1160 = 0;
    return p1;
}

//@ f_143170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ein komplettes NSC-Gespräch durch: Reserviert bei Bedarf den
 *   1024-Byte-Textformatierungspuffer W32(p1, 0xAF), sichert die aktuellen Einstellungen des Textrenderers
 *   d_1c38b0 sowie die globalen Mauszonen- und Callback-Variablen (d_1bf510..d_1bf524), aktiviert die
 *   Themen-Klickzonentabelle d_1a94b0 und die Hover-Tabelle d_1a9564 mit dem Callback f_140980, ruft die
 *   Gesprächseröffnung f_142e10(p1) auf, betreibt die Haupt-Ereignisschleife (f_068f40, f_142d20, f_142920), bis
 *   das Gespräch beendet wird, führt anschließend die Verabschiedung und Statussicherung f_142e90(p1) aus und
 *   stellt den vorherigen Grafik- und Mauszustand wieder her.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - g: Lokales Wächterobjekt (CG), das beim Betreten und Verlassen des Gesprächs den
 *     Bildschirm-/Palettenzustand über f_0ce7c0 / f_0ce7e0 sichert.
 *   - s1 bis s5: Gesicherte globale Maus-Klickzonen- und Callback-Zeiger.
 *   - l1 bis l6: Gesicherte Textfenster-Koordinaten und Farben von d_1c38b0.
 === Ende Beschreibung === */
void f_143170(int p1)
{
    int p2;
    int s5;
    short s3;
    int r;
    volatile int s4; // haelt gesicherten Callback-Zeiger auf dem Stapel
    volatile int s1 = d_1bf510; // sichert d_1bf510 vor der Dialogschleife im Stapelslot
    int s2 = d_1bf514; // sichert d_1bf514 vor der Dialogschleife
    short l1[2], l2[2], l3[2], l4[2], l5[2], l6[2];
    CG g;
    if (W32(p1, 0xaf) == 0) {
        W32(p1, 0xaf) = (int)new (mark(d_1a948c, 0xa7e)) char[0x400];
    }
    f_05e2a0(AD(d_1c38b0), (int)l1, (int)l2, (int)l3, (int)l4);
    f_05e2d0(AD(d_1c38b0), 0, 0x140, 0, 0);
    f_05e360(AD(d_1c38b0), (int)l5, (int)l6);
    f_05e320(AD(d_1c38b0), 0xff, -1);
    p2 = f_05e420(AD(d_1c38b0), 8);
    d_1bd766 = 0;
    *(volatile int *)&d_1bf510 = AD(d_1a94b0); // verhindert Umsortierung beim Setzen der Interrupt-Zeiger
    *(volatile int *)&d_1bf514 = 0; // haelt die Schreibfolge von d_1bf514 vor dem Sichern von d_1bf520
    s5 = d_1bf520; s4 = d_1bf524; s3 = d_1bf51c;
    d_1c1164 = 0;
    d_1c1166 = 0;
    d_1bf51c = 0;
    *(volatile int *)&d_1bf520 = AD(d_1a9564); // verhindert Umsortierung der Hook-Registrierung
    *(volatile int *)&d_1bf524 = (int)f_140980; // haelt die Schreibfolge des Callback-Zeigers vor dem Freigeben
    *(volatile short *)&d_1bf51c = 1; // verhindert Dead-Store-Eliminierung von d_1bf51c = 0 davor
    f_142e10(p1);
    do {
        f_068f40();
        f_142d20(p1);
        r = f_142920(p1);
    } while (r == 0);
    f_142e90(p1);
    d_1bf51c = 0;
    f_0d3870();
    d_1bf510 = s1;
    d_1bf514 = s2;
    d_1bf520 = s5;
    d_1bf524 = s4;
    d_1bf51c = s3;
    f_05e420(AD(d_1c38b0), (short)p2);
    f_05e320(AD(d_1c38b0), l5[0], l6[0]);
    f_05e2d0(AD(d_1c38b0), l1[0], l2[0], l3[0], l4[0]);
}
