/* === Beschreibung (Katalog) ===
 * Einheit: gz_010010
 *
 * Adressbereich: 0x010010-0x0104b0
 * Spielsystem: Systemstart (CPU-Erkennung), Tastatur-Interrupt-Hilfen (Ziffernblock-Richtungstasten),
 * Bildschirm-Wellenverzerrung (Grafikeffekt) sowie Datenkopf-Zugriffe für ACE-Einzelbilder.
 === Ende Beschreibung === */
// P3 10/14 gleich (suche.py 29.10.2026, Basis gz_010010_P1.CPP)
// P1 6/12 GLEICH, Rest: f_010010 ASM, f_01008c REG, f_0100c0 ASM (16-bit), f_0101db FOLGE, f_0101e0 STAPEL, f_010430 FOLGE
// gz_010010.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x010010-0x0104B0
#include <string.h>
#include <conio.h>
#include <i86.h>
#pragma intrinsic(inp)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_123330(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern unsigned char d_000417;                    // 0x000417
extern unsigned char d_1a0100;                    // 0x1A0100
extern signed char d_1a0102;                    // 0x1A0102
extern volatile int d_1a0104;                    // 0x1A0104
extern int d_1a0108;                    // 0x1A0108
extern int d_1a010c;                    // 0x1A010C
extern int d_1a0110;                    // 0x1A0110
extern int d_1a0114;                    // 0x1A0114
extern char *d_1a0118;                    // 0x1A0118
extern int d_1a011c;                    // 0x1A011C
extern int d_1a0120;                    // 0x1A0120
extern int d_1a0124;                    // 0x1A0124
extern int d_1a0128;                    // 0x1A0128
extern int d_1a012c;                    // 0x1A012C
extern int d_1a0130;                    // 0x1A0130
extern int *d_1c0c14;                    // 0x1C0C14
extern int *d_1c0c18;                    // 0x1C0C18
extern int d_1c0c1c;                    // 0x1C0C1C
extern int d_1c0c20;                    // 0x1C0C20
extern char *d_1c0c24;                    // 0x1C0C24
extern int *d_1c0c28;                    // 0x1C0C28
extern int *d_1c0c2c;                    // 0x1C0C2C
// --- eigene Funktionen (12), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_010010  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt beim Programmstart die Prozessorklasse (386, 486 oder Pentium) über das
 *   Umschalten der EFLAGS-Bits AC (Bit 18) und ID (Bit 21) sowie den CPUID-Befehl (handgeschriebener
 *   Watcom-Startcode; der C-Rumpf in p3 ist ein reiner Formnachbau für den Compiler).
 * - Eingaben / Rückgabe: Im Original keine Eingabeparameter (die drei Parameter im C-Nachbau dienen nur der
 *   Registerbelegung); gibt 3 für 80386, 4 für 80486 und 5 für Pentium (CPUID-Familie >= 5) zurück.
 * - Wichtige Variablen & Daten: Nutzt im Original direkt das EFLAGS-Register und die CPUID-Rückgaberegister.
 === Ende Beschreibung === */
//@ f_01008c  groesse 52 B, 15 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft bei gesperrten Interrupts (cli/sti), ob seit dem letzten Tastaturereignis mehr als
 *   0x25 Zeiteinheiten (ca. 2 Sekunden) vergangen sind, und löscht in diesem Fall die gehaltenen
 *   Richtungstasten-Bits 0-5 sowie die BIOS-Umschaltflags (Shift, Strg, Alt) an Adresse 0x417, um "hängende"
 *   Bewegungstasten zu verhindern.
 * - Eingaben / Rückgabe: Keine fachlichen Parameter und keine Rückgabe (EAX bleibt unverändert erhalten).
 * - Wichtige Variablen & Daten:
 *   - d_1a0104: Zeitstempel des letzten Tastenereignisses.
 *   - d_1a0102: 16-Bit-Bitmaske der gehaltenen Ziffernblock-Richtungstasten (Bits 0-5 werden mit & 0xffc0
 *     gelöscht).
 *   - BIOS-Byte 0x000417: Tastatur-Umschaltstatus (untere 4 Bits für Shift/Strg/Alt werden mit & 0xf0 gelöscht).
 * - Besonderheiten / Originalfehler: Das Original lädt die Adresse 0x46c als unmittelbare Konstante (mov edx,
 *   0x46c), statt den BIOS-Tickzähler aus dem Speicher [0x46c] zu lesen (ebenso in f_0100c0). Sobald d_1a0104
 *   einmal auf 0x46c gesetzt wurde, ist die Differenz 0x46c - d_1a0104 immer 0, sodass das automatische
 *   Zurücksetzen hängender Tasten nie wieder auslöst.
 === Ende Beschreibung === */
//@ f_0100c0  groesse 288 B, 88 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest im Original (handgeschriebener 16-Bit-naher Interrupt-Teil, aufgerufen aus der
 *   Tastatur-IRQ1-Routine f_0a6bf0) den Scancode von Port 0x60, aktualisiert den Zeitstempel d_1a0104 und pflegt
 *   die Bitmaske der gehaltenen Ziffernblock-Bewegungstasten (d_1a0102) sowie den Zustand der
 *   Ziffernblock-5-Taste (d_1a0100). *(Hinweis: In p3 steht unter dieser Marke als Platzhalter aus Pass 1 eine
 *   nicht hierher gehörende Würfelformel n*Wm+x wie dice_template aus Schicksalsklinge; im Gesamtbau wird der
 *   Bereich als HANDASM aus dem Original übernommen.)*
 * - Eingaben / Rückgabe: Keine Eingaben (liest Hardware-Port 0x60); gibt den gelesenen Tastatur-Scancode
 *   (0..255) zurück.
 * - Wichtige Variablen & Daten:
 *   - d_1a0102: Bitmaske der gehaltenen Richtungstasten (0x48 Hoch = 1, 0x50 Runter = 2, 0x4B Links = 4, 0x4D
 *     Rechts = 8, 0x47 Pos1 = 0x10, 0x4F Ende = 0x20, 0x49 Bild↑ = 0x40, 0x51 Bild↓ = 0x80; Make-Code setzt das
 *     Bit, Break-Code mit Bit 7 löscht es).
 *   - d_1a0100: Merker für gehaltene Taste Ziffernblock 5 (Scancode 0x4C).
 *   - d_1a0104: Zeitstempel des letzten Tastendrucks (wird auch hier fehlerhaft auf die Konstante 0x46c
 *     gesetzt).
 === Ende Beschreibung === */
//@ f_0101db  ?
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Besteht nur aus einem einzelnen ret-Befehl und dient als Endmarke des per DPMI (f_0a6a30,
 *   Funktion 0x0600) im Speicher gesperrten Tastatur-Interrupt-Codebereichs (f_0100c0 bis f_0101db).
 * - Eingaben / Rückgabe: Keine.
 * - Wichtige Variablen & Daten: Keine.
 === Ende Beschreibung === */
//@ f_0101e0  groesse 592 B, 176 Bef, reg eax edx ebx ecx, stapel 8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verzerrt einen rechteckigen Bildausschnitt (im Spiel bei d_1c0b94 == 1 den gesamten
 *   320x200-Bildschirm, vermutlich für Unterwasser- oder Schwindel-/Rausch-Effekte) mit einer animierten
 *   zweidimensionalen Sinuswelle. Im ersten Durchgang werden die Spalten senkrecht versetzt und gestaucht in
 *   einen Zwischenpuffer kopiert, im zweiten Durchgang zeilenweise waagrecht versetzt und gestaucht in das
 *   Zielbild zurückgeschrieben; anschließend rücken beide Wellenphasen um 1 weiter.
 * - Eingaben / Rückgabe: Eingaben sind der Zeiger auf den Bildpuffer, die linke obere Ecke (x1, y1), die rechte
 *   untere Ecke (x2, y2, jeweils inklusive) und die Zeilenbreite in Bytes (Pitch, z. B. 320); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - d_1a010c, d_1a0110: Berechnete Breite und Höhe des Bildausschnitts.
 *   - d_1a0118: Startadresse des Ausschnitts im Zielbild.
 *   - d_1a0108, d_1a0128: Senkrechte Wellenamplitude in Pixeln und gestauchte Spaltenhöhe (Höhe - 2 *
 *     Amplitude).
 *   - d_1a012c, d_1a0130: Laufende Phasenwinkel der senkrechten und waagrechten Sinuswelle (pro Aufruf +1).
 *   - d_1c0c14, d_1c0c18, d_1c0c1c, d_1c0c20: Sinustabellen (senkrecht/waagrecht) und deren Wellenlängen
 *     (angelegt über f_123330 in tdmwater).
 *   - d_1c0c24, d_1c0c28, d_1c0c2c: Zwischenpuffer sowie Spalten- und Zeilen-Stauchtabellen.
 === Ende Beschreibung === */
//@ f_010430  groesse 16 B, 1 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Funktion (nur ret, in p3 aus Layoutgründen vor f_010010 platziert).
 * - Eingaben / Rückgabe: Keine.
 * - Wichtige Variablen & Daten: Keine.
 === Ende Beschreibung === */
//@ f_010440  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den X-Versatz (+0) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt den X-Versatz (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +0 des Bildkopfes.
 === Ende Beschreibung === */
//@ f_010450  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den Y-Versatz (+2) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt den Y-Versatz (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +2 des Bildkopfes.
 === Ende Beschreibung === */
//@ f_010460  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Bildbreite (+4) eines 14-Byte-ACE-Einzelbildkopfes (wird u. a. in face2 an die
 *   Entpackfunktion f_0a2520 übergeben).
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Breite in Pixeln (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +4 des Bildkopfes.
 === Ende Beschreibung === */
//@ f_010470  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Bildhöhe (+6) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Höhe in Pixeln (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +6 des Bildkopfes.
 === Ende Beschreibung === */
//@ f_010480  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Länge der komprimierten Bilddaten (+8) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die gepackte Größe in Bytes (int) zurück.
 * - Wichtige Variablen & Daten: Offset +8 des Bildkopfes.
 === Ende Beschreibung === */
//@ f_010490  groesse 16 B, 2 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Packart (Kompressionsverfahren, +12) eines 14-Byte-ACE-Einzelbildkopfes für den
 *   Aufruf des Entpackers f_0a2520.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Packart (unsigned char) zurück.
 * - Wichtige Variablen & Daten: Offset +12 des Bildkopfes.
 === Ende Beschreibung === */

//@ f_010010
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt beim Programmstart die Prozessorklasse (386, 486 oder Pentium) über das
 *   Umschalten der EFLAGS-Bits AC (Bit 18) und ID (Bit 21) sowie den CPUID-Befehl (handgeschriebener
 *   Watcom-Startcode; der C-Rumpf in p3 ist ein reiner Formnachbau für den Compiler).
 * - Eingaben / Rückgabe: Im Original keine Eingabeparameter (die drei Parameter im C-Nachbau dienen nur der
 *   Registerbelegung); gibt 3 für 80386, 4 für 80486 und 5 für Pentium (CPUID-Familie >= 5) zurück.
 * - Wichtige Variablen & Daten: Nutzt im Original direkt das EFLAGS-Register und die CPUID-Rückgaberegister.
 === Ende Beschreibung === */
void f_010430(void)
{
}
// Handgeschriebener Watcom-Startcode (EFLAGS/CPUID); die Parameter belegen edx/ebx fuer die Registerfolge.
int f_010010(unsigned a, unsigned b, short c);

// Im Original handgeschrieben ohne ECX-Sicherung.
#pragma aux f_010010 modify [ecx];

int f_010010(unsigned a, unsigned b, short c)
{
    union U { unsigned full; unsigned short w[2]; unsigned char b[4]; };
    unsigned f = a;
    a ^= 0x40000;
    a ^= f;
    a = (a >> 0x12) & 1;
    if (!c)
        return 3;
    f = a;
    a |= 0x200000;
    a ^= f;
    if (!a)
        return 4;
    U uc;
    uc.full = c;
    a = ((b + uc.full) & 0xf00) >> 8;
    if ((signed char)a >= (signed char)5)
        return 5;
    uc.b[0] = 0x10;
    U ub;
    ub.full = b;
    ub.w[0] = (unsigned short)a;
    ub.full <<= uc.full;
    ub.w[0] = (unsigned short)a;
    return ub.full;
}

//@ f_01008c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft bei gesperrten Interrupts (cli/sti), ob seit dem letzten Tastaturereignis mehr als
 *   0x25 Zeiteinheiten (ca. 2 Sekunden) vergangen sind, und löscht in diesem Fall die gehaltenen
 *   Richtungstasten-Bits 0-5 sowie die BIOS-Umschaltflags (Shift, Strg, Alt) an Adresse 0x417, um "hängende"
 *   Bewegungstasten zu verhindern.
 * - Eingaben / Rückgabe: Keine fachlichen Parameter und keine Rückgabe (EAX bleibt unverändert erhalten).
 * - Wichtige Variablen & Daten:
 *   - d_1a0104: Zeitstempel des letzten Tastenereignisses.
 *   - d_1a0102: 16-Bit-Bitmaske der gehaltenen Ziffernblock-Richtungstasten (Bits 0-5 werden mit & 0xffc0
 *     gelöscht).
 *   - BIOS-Byte 0x000417: Tastatur-Umschaltstatus (untere 4 Bits für Shift/Strg/Alt werden mit & 0xf0 gelöscht).
 * - Besonderheiten / Originalfehler: Das Original lädt die Adresse 0x46c als unmittelbare Konstante (mov edx,
 *   0x46c), statt den BIOS-Tickzähler aus dem Speicher [0x46c] zu lesen (ebenso in f_0100c0). Sobald d_1a0104
 *   einmal auf 0x46c gesetzt wurde, ist die Differenz 0x46c - d_1a0104 immer 0, sodass das automatische
 *   Zurücksetzen hängender Tasten nie wieder auslöst.
 === Ende Beschreibung === */
// Parameter haelt EAX ueber die Funktion hinweg wie im Original erhalten.
int f_01008c(int eax_in)
{
    extern volatile unsigned short flags976;
#pragma aux flags976 "d_1a0102";
    extern int tick976;
#pragma aux tick976 "d_1a0104";
    extern int holdglobal0;
#pragma aux holdglobal0 "d_1a0104";
    extern int holdglobal1;
#pragma aux holdglobal1 "d_1a0104";
    extern int holdglobal2;
#pragma aux holdglobal2 "d_1a0104";
    _disable();
    int stamp = d_1a0104;
    int transient = tick976;
    tick976 = transient; // Haelt die Registerfolge fuer den Zeitstempel-Vergleich
    int delta = 0x46c - stamp;
    if (delta > 0x25) {
        int hold0=holdglobal0;
        int hold1=holdglobal1;
        int hold2=holdglobal2;
        unsigned short *flags_ptr = (unsigned short *)&flags976;
        *flags_ptr &= 0xffc0;
        holdglobal0=hold0;
        holdglobal1=hold1;
        holdglobal2=hold2;
        *(unsigned char *)0x417 &= 0xf0;
        // Erzwingt Register-Store von 0x46c ueber edx wie im Original.
        union S { unsigned full; unsigned short words[2]; unsigned char bytes[4]; }; S value; value.full=0x46c; unsigned short low=value.words[0]; value.words[0]=low; d_1a0104=(int)value.full;
    }
    _enable();
    return eax_in;
}

//@ f_0100c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest im Original (handgeschriebener 16-Bit-naher Interrupt-Teil, aufgerufen aus der
 *   Tastatur-IRQ1-Routine f_0a6bf0) den Scancode von Port 0x60, aktualisiert den Zeitstempel d_1a0104 und pflegt
 *   die Bitmaske der gehaltenen Ziffernblock-Bewegungstasten (d_1a0102) sowie den Zustand der
 *   Ziffernblock-5-Taste (d_1a0100). *(Hinweis: In p3 steht unter dieser Marke als Platzhalter aus Pass 1 eine
 *   nicht hierher gehörende Würfelformel n*Wm+x wie dice_template aus Schicksalsklinge; im Gesamtbau wird der
 *   Bereich als HANDASM aus dem Original übernommen.)*
 * - Eingaben / Rückgabe: Keine Eingaben (liest Hardware-Port 0x60); gibt den gelesenen Tastatur-Scancode
 *   (0..255) zurück.
 * - Wichtige Variablen & Daten:
 *   - d_1a0102: Bitmaske der gehaltenen Richtungstasten (0x48 Hoch = 1, 0x50 Runter = 2, 0x4B Links = 4, 0x4D
 *     Rechts = 8, 0x47 Pos1 = 0x10, 0x4F Ende = 0x20, 0x49 Bild↑ = 0x40, 0x51 Bild↓ = 0x80; Make-Code setzt das
 *     Bit, Break-Code mit Bit 7 löscht es).
 *   - d_1a0100: Merker für gehaltene Taste Ziffernblock 5 (Scancode 0x4C).
 *   - d_1a0104: Zeitstempel des letzten Tastendrucks (wird auch hier fehlerhaft auf die Konstante 0x46c
 *     gesetzt).
 === Ende Beschreibung === */
int f_1457e0(int p1);
short f_0100c0(short p1)
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

//@ f_0101db
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Besteht nur aus einem einzelnen ret-Befehl und dient als Endmarke des per DPMI (f_0a6a30,
 *   Funktion 0x0600) im Speicher gesperrten Tastatur-Interrupt-Codebereichs (f_0100c0 bis f_0101db).
 * - Eingaben / Rückgabe: Keine.
 * - Wichtige Variablen & Daten: Keine.
 === Ende Beschreibung === */
// OPT -5r -oneatxu -zp1 -s
void f_0101db(void)
{
}

//@ f_0101e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verzerrt einen rechteckigen Bildausschnitt (im Spiel bei d_1c0b94 == 1 den gesamten
 *   320x200-Bildschirm, vermutlich für Unterwasser- oder Schwindel-/Rausch-Effekte) mit einer animierten
 *   zweidimensionalen Sinuswelle. Im ersten Durchgang werden die Spalten senkrecht versetzt und gestaucht in
 *   einen Zwischenpuffer kopiert, im zweiten Durchgang zeilenweise waagrecht versetzt und gestaucht in das
 *   Zielbild zurückgeschrieben; anschließend rücken beide Wellenphasen um 1 weiter.
 * - Eingaben / Rückgabe: Eingaben sind der Zeiger auf den Bildpuffer, die linke obere Ecke (x1, y1), die rechte
 *   untere Ecke (x2, y2, jeweils inklusive) und die Zeilenbreite in Bytes (Pitch, z. B. 320); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - d_1a010c, d_1a0110: Berechnete Breite und Höhe des Bildausschnitts.
 *   - d_1a0118: Startadresse des Ausschnitts im Zielbild.
 *   - d_1a0108, d_1a0128: Senkrechte Wellenamplitude in Pixeln und gestauchte Spaltenhöhe (Höhe - 2 *
 *     Amplitude).
 *   - d_1a012c, d_1a0130: Laufende Phasenwinkel der senkrechten und waagrechten Sinuswelle (pro Aufruf +1).
 *   - d_1c0c14, d_1c0c18, d_1c0c1c, d_1c0c20: Sinustabellen (senkrecht/waagrecht) und deren Wellenlängen
 *     (angelegt über f_123330 in tdmwater).
 *   - d_1c0c24, d_1c0c28, d_1c0c2c: Zwischenpuffer sowie Spalten- und Zeilen-Stauchtabellen.
 === Ende Beschreibung === */
static inline char *getbase2348(int offset){return d_1a0118+offset;}
void f_0101e0(char *p1, int p2, int p3, int p4, int p5, int p6)
{
    char *src, *dst, *base;
    int cnt, step;
    int *ptr;

    d_1a010c = p4 - p2 + 1;
    d_1a0110 = p5 - p3 + 1;
    d_1a0118 = p1 + (p2 + p3 * p6);
    f_123330(d_1a010c, d_1a0110, p6);

    int hold1101 = d_1a0108; // Haelt d_1a0108 ueber die Modulo-Rechnung im Register
    src = ((unsigned)src & 0) ? 0 : src; // Belegt das Zielregister fuer den spaeteren Zeigerpfad vor
    int * hold2101 = d_1c0c14; // Haelt den Tabellenzeiger vor der Schleife bereit
    d_1a0128 = d_1a0110 - d_1a0108 - d_1a0108;
    d_1c0c14 = hold2101;
    d_1a011c = (d_1a012c + (d_1a010c - 1)) % d_1c0c1c;
    d_1a0108 = hold1101;
    for (d_1a0120 = d_1a010c - 1; d_1a0120 >= 0; d_1a0120--) {
        int t = d_1c0c14[d_1a011c--];
        { int g_ = d_1c0c1c; d_1c0c1c = g_; } // Haelt d_1c0c1c fuer den Vorzeichentest im Register
        if (d_1a011c < 0)
            d_1a011c += d_1c0c1c;
        {
            char *a = d_1c0c24 + d_1a0120;
            t += *(int *)((char *)d_1c0c28 + d_1a0120 * 4);
            t += (int)d_1a0118;
            int c = d_1a0128;
            char *d = a; char *s = (char *)t; int n = c; int st = p6;
            while (--n >= 0) {
                *(volatile char *)d = *s;
                s += st;
                d += st;
                d = ((unsigned)d & 0) ? (char *)0 : d; // Verhindert Zusammenlegung der Zeigerfortschaltung
            }
        }
    }

    d_1a0114 = (d_1a0110 - 1) * p6;
    d_1a011c = (d_1a0130 + (d_1a0110 - 1)) % d_1c0c20;
    for (d_1a0124 = d_1a0110 - 1; d_1a0124 >= 0; ) {
        int *table2348=d_1c0c18; int off2348=(int)(d_1a011c--)*4; d_1c0c18=table2348; int *entry2348=(int*)((char*)table2348+off2348); if(off2348&0)src=0;else src=(char*)*entry2348; // Haelt skalierten Index im Register
        if (d_1a011c < 0)
            d_1a011c += d_1c0c20;
        base=getbase2348(d_1a0114); // Haelt die Registerfolge beim Laden von d_1a0118 + d_1a0114
        unsigned address2348=(unsigned)src; address2348+=(unsigned)d_1c0c2c[d_1a0124]; unsigned image2348=(unsigned)d_1c0c24; image2348=(image2348&0)?0:image2348; address2348+=(unsigned)image2348; src=(char*)address2348; // Haelt Bildbasis in der Additionsreihenfolge des Originals
        cnt = d_1a010c;
        dst = (char *)(cnt - 1) + (int)base;
        ptr = (int *)((char *)d_1c0c28 + ((cnt << 2) - 4));
        while (ptr >= d_1c0c28) {
            int offset = *ptr--;
            *dst-- = src[offset];
        }
        d_1a0124--;
        d_1a0114 -= p6;
    }

    d_1a012c++;
    d_1a0130++;
}

//@ f_010400
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert einen 14 Byte großen Einzelbild-Kopf einer ACE-Animation im Speicher
 *   (Gegenstück zu struct ace_frame in Sternenschweif OVL050.CPP, jedoch mit geänderter Feldreihenfolge).
 * - Eingaben / Rückgabe: Eingaben sind der Zielzeiger auf den 14-Byte-Bildkopf sowie X-Versatz (+0), Y-Versatz
 *   (+2), Breite (+4), Höhe (+6), gepackte Datenlänge in Bytes (+8), Ereignismarke/Cue (+13) und Packart (+12);
 *   gibt den Zeiger auf den Bildkopf zurück.
 * - Wichtige Variablen & Daten: 14-Byte-Struktur mit short x (+0), short y (+2), short w (+4), short h (+6), int
 *   size (+8), unsigned char pack (+12), unsigned char cue (+13).
 === Ende Beschreibung === */
char *f_010400(char *p, unsigned short a, unsigned short b, unsigned short c,
               unsigned short d, int e, unsigned char f, unsigned char g)
{
    *(unsigned short *)(p + 0) = a;
    *(unsigned short *)(p + 2) = b;
    *(unsigned short *)(p + 4) = c;
    *(unsigned short *)(p + 6) = d;
    *(int *)(p + 8) = e;
    *(unsigned char *)(p + 13) = f;
    *(unsigned char *)(p + 12) = g;
    return p;
}

//@ f_010430
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Funktion (nur ret, in p3 aus Layoutgründen vor f_010010 platziert).
 * - Eingaben / Rückgabe: Keine.
 * - Wichtige Variablen & Daten: Keine.
 === Ende Beschreibung === */


//@ f_010440
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den X-Versatz (+0) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt den X-Versatz (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +0 des Bildkopfes.
 === Ende Beschreibung === */
unsigned short f_010440(unsigned short *p)
{
    return *p;
}

//@ f_010450
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den Y-Versatz (+2) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt den Y-Versatz (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +2 des Bildkopfes.
 === Ende Beschreibung === */
unsigned short f_010450(char *p)
{
    return *(unsigned short *)(p + 2);
}

//@ f_010460
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Bildbreite (+4) eines 14-Byte-ACE-Einzelbildkopfes (wird u. a. in face2 an die
 *   Entpackfunktion f_0a2520 übergeben).
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Breite in Pixeln (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +4 des Bildkopfes.
 === Ende Beschreibung === */
unsigned short f_010460(char *p)
{
    return *(unsigned short *)(p + 4);
}

//@ f_010470
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Bildhöhe (+6) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Höhe in Pixeln (unsigned short) zurück.
 * - Wichtige Variablen & Daten: Offset +6 des Bildkopfes.
 === Ende Beschreibung === */
unsigned short f_010470(char *p)
{
    return *(unsigned short *)(p + 6);
}

//@ f_010480
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Länge der komprimierten Bilddaten (+8) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die gepackte Größe in Bytes (int) zurück.
 * - Wichtige Variablen & Daten: Offset +8 des Bildkopfes.
 === Ende Beschreibung === */
int f_010480(char *p)
{
    return *(int *)(p + 8);
}

//@ f_010490
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest die Packart (Kompressionsverfahren, +12) eines 14-Byte-ACE-Einzelbildkopfes für den
 *   Aufruf des Entpackers f_0a2520.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Packart (unsigned char) zurück.
 * - Wichtige Variablen & Daten: Offset +12 des Bildkopfes.
 === Ende Beschreibung === */
unsigned char f_010490(char *p)
{
    return *(unsigned char *)(p + 12);
}

//@ f_0104a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest das Marken-Byte (+13, vermutlich Ereignis-/Synchronisationsmarke event/cue analog zu
 *   Sternenschweif ace_frame.event) eines 14-Byte-ACE-Einzelbildkopfes.
 * - Eingaben / Rückgabe: Zeiger auf den Bildkopf; gibt die Marke (unsigned char) zurück.
 * - Wichtige Variablen & Daten: Offset +13 des Bildkopfes.
 === Ende Beschreibung === */
unsigned char f_0104a0(char *p)
{
    return *(unsigned char *)(p + 13);
}
