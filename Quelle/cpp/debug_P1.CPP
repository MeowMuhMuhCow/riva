/* === Beschreibung (Katalog) ===
 * Einheit debug (0x051870 - 0x051AD0)
 *
 * Überblick
 * Die Einheit debug implementiert die Absturz- und Notfallbehandlung des Spiels ("GURU Meditation", f_051870)
 * inklusive Ausgabe einer Fehlermeldung, Erzeugung von Speicherauszugsdateien (ALLOC.CAT bzw. RIVA.CAT) und
 * geordnetem Programmabbruch sowie die Initialisierung der zugehörigen Ausnahmebehandlungsstrukturen (f_051a30).
 === Ende Beschreibung === */
struct CrLf909 { char b[3]; };
extern const CrLf909 d_1a1460;
extern const char d_1b6658[];
extern const char d_1b6679[];
extern const char d_1b6683[];
extern const char d_1b66ab[];
extern const char d_1b66be[];
// I9: aus debug_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// debug.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x51870-0x51A30. "GURU Meditation": Absturzmeldung, Speicherabzug (ALLOC.CAT / RIVA.CAT), Aufraeumen, exit.
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
extern "C" int exit(int code);
int f_0d3860();                                          // 0x0D3860
void f_0d2710();                                         // 0x0D2710
void f_0d26e0();                                         // 0x0D26E0
void f_01e0c0();                                         // 0x01E0C0
void f_144570();                                         // 0x144570
void f_149d50();                                         // 0x149D50
void __cdecl f_149dfe(void *p);                          // 0x149DFE
void f_11e6d0(short mode);                               // 0x11E6D0
int f_14d0d7(const char *name, int mode);                // 0x14D0D7 (creat)
void f_053b30(int);                                      // 0x053B30
extern int d_1a01b4;
extern int d_1c0c4c;
extern int d_1bc948;
extern int d_1bc760;
extern int d_1c2a80;
extern char d_1c2a78[];
extern char d_1c27a8[];
extern short d_1bd75c, d_1bd762, d_1bd766;
struct Rec { char *start; char *end; char pad[12]; };
extern Rec *d_1bc614;


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
extern unsigned char d_1a1464;
extern unsigned char d_1a146c;
extern unsigned char d_1b66c8;
extern unsigned char d_1b66cc;
extern unsigned char d_1bc988;
extern unsigned char d_1bc98a;
extern unsigned char d_1bc98c;
extern unsigned char d_1bca0a;
extern unsigned char d_1bca0c;
extern unsigned char d_1bca10;
extern unsigned char d_1bca14;
extern unsigned char d_1bca1e;
extern unsigned char d_1bca28;
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C053b30_0();
#pragma aux C053b30_0 "f_053b30";
int C145300_3(int,int,int);
#pragma aux C145300_3 "f_145300";
int __cdecl f_14572e_k909(int,int,int);
#pragma aux f_14572e_k909 "f_14572e" modify exact [eax ebp];
int C14d17f_1(int);
#pragma aux C14d17f_1 "f_14d17f";
//@ f_051870
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt einen kontrollierten Not-Ausstieg ("Guru Meditation") bei schwerwiegenden Laufzeit-
 *   oder Speicherfehlern durch: Schaltet bei Bedarf den Mauszeiger ab, beendet laufende Animationen (f_01e0c0)
 *   und Sound-Timer (f_149dfe), gibt den Fehlertext msg auf der Konsole aus, schreibt bei code == 1 die
 *   vollständige 2500-Einträge-Belegungstabelle d_1bc614 in die Datei ALLOC.CAT (d_1b6679) bzw. bei einem
 *   Speicherzeiger code != 0 einen 64.000-Byte-Speicherabzug ab code - 500 in die Datei RIVA.CAT (d_1b66be),
 *   räumt Grafikmodus (0x13), Soundsystem und Dateiverwaltung auf und beendet das Programm über f_148534(0).
 * - Eingaben:
 *   - msg (Zeiger auf die auszugebende Fehlermeldung oder 0).
 *   - code (Steuercode für den Speicherauszug: 0 = kein Dump, 1 = Heap-Katalog ALLOC.CAT aus d_1bc614 schreiben,
 *     sonst Speicheradresse für 64-KB-Dump in RIVA.CAT).
 * - Rückgabewert: Keiner (void, kehrt durch den Aufruf von f_148534(0) nicht ins normale Spiel zurück).
 * - Wichtige Variablen:
 *   - m (Fehlermeldungs-Zeichenkette msg).
 *   - saved (Gesicherter Zustand des Speicher-Debug-Flags d_1a01b4).
 *   - h (Dateihandle für ALLOC.CAT bzw. RIVA.CAT).
 *   - d_1bc614 (Globaler Arrayzeiger auf die 2500 Heap-Belegungseinträge mit Start- und Endadresse).
 === Ende Beschreibung === */
void f_051870(const char *msg, int code)
{
    const char *m = (const char *)d_1a01b4; // haelt die Registerzuteilung wie im Original
    int saved = (int)m;
    char *s = d_1c27a8;
    volatile int fl;
    m = msg;
    if (f_0d3860() == 1) {
        f_0d2710();
        fl = 1;
    } else
        fl = 0;
    d_1a01b4 = 0;
    d_1c0c4c = d_1c0c4c + 1;
    d_1bc948 = 0;
    if (d_1bc760) f_01e0c0();
    f_149dfe(d_1c2a78);
    d_1c2a80 = 0;
    cputs(d_1b6658);
    if (m) cputs(m);
    short h;
    if (code == 1) {
        CrLf909 crlf = d_1a1460;
        h = f_14d0d7(d_1b6679, 0);
        for (short i = 0; i < (short)2500; i++) {
            sprintf(s, d_1b6683, i, d_1bc614[i].start, d_1bc614[i].end, d_1bc614[i].end - d_1bc614[i].start, crlf.b);
            write(h, s, strlen(s));
        }
        close(h);
    } else if (code != 0) {
        sprintf(s, d_1b66ab, code);
        printf(s);
        h = f_14d0d7(d_1b66be, 0);
        code = code - 500;
        write(h, (char *)code, 32000);
        write(h, (char *)code + 32000, 32000);
        close(h);
    }
    d_1bd75c = 0;
    d_1bd762 = 0;
    d_1bd766 = 0;
    f_149d50();
    f_11e6d0(0x13);
    d_1a01b4 = saved;
    f_144570();
    void f_148534(int);
    f_148534(0);
    if (fl == 1) f_0d26e0();
}
//@ f_051a30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert beim Programmstart die globalen Strukturen und Rückrufzeiger (f_053b30 in
 *   d_1bca10) für die Fehler-, Signal- und Ausnahmebehandlung und setzt das Bereitschaftsflag d_1a146c = 1.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bc98c, d_1bca10, d_1bca14, d_1bca1e, d_1bca28 (Globale Konfigurations- und Handler-Felder der
 *     Debug-/Ausnahmeverwaltung).
 *   - d_1a146c (Initialisierungsflag, wird auf 1 gesetzt).
 === Ende Beschreibung === */
void f_051a30()
{
    int C14d17f_local(int);
#pragma aux C14d17f_local "f_14d17f" modify exact [eax ebx ecx edx esi edi];
    C14d17f_local(NA(d_1a1464));ND16(d_1bc98a)=0;ND16(d_1bc988)=0;
    C145300_3(NA(d_1bc98c),0,0x7e);ND16(d_1bca0a)=1;ND16(d_1bca0c)=25;ND32(d_1bca10)=(int)C053b30_0;
    C145300_3(NA(d_1bca28),0,0x15);strcpy((char *)NA(d_1bca14),(char *)NA(d_1b66c8));
    f_14572e_k909(NA(d_1bca1e),NA(d_1b66cc),0x15);ND32(d_1a146c)=1;
}


