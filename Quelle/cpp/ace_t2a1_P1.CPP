/* === Beschreibung (Katalog) ===
 * Einheit: ace_t2a1
 *
 * Adressbereich: 0x011680-0x011750
 * Spielsystem: Grafik / Animationen (Stopp- und Warteschleifen für ACE-Animationen) sowie Beginn des
 * Template-Codes für Spielvariablen-Register (32-Bit-Initialisierer).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAIMG.H"
#include "RIVAACE.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// P3 17/27 gleich (suche.py 26.10.2026, Basis ace_t2_P1.CPP)
// P1 2/26 GLEICH, Rest: Wait-Schleifen (sete-Muster) 0116a0 0116d0 011700; Stapel/Register in read/write-Funktionen; 011da0/0123a0 und 011dc0/0123c0 vom Compiler gefaltet; 011680 011dd0 0123d0 nur Fuellbytes
// ace.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0104B0-0x012A00
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_0a2520(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg edx ebx ecx stapel 12
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3420(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fabf0(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
   // reg eax edx ebx ecx stapel 4
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1b62ec;                    // 0x1B62EC
extern int d_1bc5f0;                    // 0x1BC5F0
extern short d_1bc5f4;                    // 0x1BC5F4
extern int d_1bc5f6;                    // 0x1BC5F6
extern int d_1bc5f8;                    // 0x1BC5F8
                    // 0x1C2098
extern const char d_1a0134[];           // Text 0x1A0134
#include <io.h>
#define VR(s,b,n) (s)->vt->read(s,b,n)
#define VW(s,b,n) (s)->vt->write(s,b,n)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_011680
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hält die laufende ACE-Animation an (d_1bc5f4 = 0) und gibt das Zeilenverzeichnis des
 *   Arbeits-Bildpuffers (+0xb4, Bitmap a) frei (entspricht Anim::stop in Sternenschweif OVL051.CPP).
 * - Eingaben / Rückgabe: Zeiger auf das ACE-Animationsobjekt (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Globales Lauf-Flag d_1bc5f4 und eingebettetes Bitmap-Objekt bei Offset +0xb4.
 === Ende Beschreibung === */
void f_011680(char *p1)
{
    d_1bc5f4 = 0;
    ((RivaRasterImage*)((int)p1 + 0xb4))->f_0fadc0();
}
//@ f_0116a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wartet in einer Ereignisschleife (f_068f40), solange die Animation läuft (d_1bc5f4 == 1),
 *   bis im aktuellen Einzelbild eine Synchronisations-/Ereignismarke (c_af bei Offset +0xaf != 0) erreicht wird
 *   oder die Animation endet (Anim::wait_cue in Sternenschweif OVL051.CPP).
 * - Eingaben / Rückgabe: Zeiger auf das ACE-Animationsobjekt (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Globales Lauf-Flag d_1bc5f4 und Objektfeld c_af (+0xaf, aktuelle Bildmarke).
 === Ende Beschreibung === */
void f_0116a0(char *p1)
{
    for (;;) {
        int c = (d_1bc5f4 == 1);
        if (!(c & 1)) break;
        f_068f40();
        if (p1[0xaf]) break;
    }
}
//@ f_0116d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wartet in einer Ereignisschleife (f_068f40), solange die Animation läuft (d_1bc5f4 == 1),
 *   bis der Einzelbildindex idx (Offset +0xac) mindestens die übergebene Bildnummer erreicht hat oder die
 *   Animation stoppt (Anim::wait_frame in Sternenschweif OVL051.CPP).
 * - Eingaben / Rückgabe: Zeiger auf das ACE-Animationsobjekt (this) und Ziel-Bildindex (p2); keine Rückgabe.
 * - Wichtige Variablen & Daten: Globales Lauf-Flag d_1bc5f4 und Objektfeld idx (short bei Offset +0xac).
 === Ende Beschreibung === */
void f_0116d0(char *p1, int p2)
{
    for (;;) {
        int c = (d_1bc5f4 == 1);
        if (c & 1) {
            f_068f40();
            if (*(short *)(p1 + 0xac) >= (short)p2) break;
        } else break;
    }
}
//@ f_011700
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wartet in einer Ereignisschleife (f_068f40), solange die Animation läuft UND die aktuelle
 *   Bildmarke c_af (+0xaf) noch gesetzt ist, und setzt die Bildmarke anschließend auf 0 zurück (Anim::clear_cue
 *   / Warten auf Markenende in Sternenschweif OVL051.CPP).
 * - Eingaben / Rückgabe: Zeiger auf das ACE-Animationsobjekt (this); keine Rückgabe.
 * - Wichtige Variablen & Daten: Globales Lauf-Flag d_1bc5f4 und Objektfeld c_af (+0xaf).
 === Ende Beschreibung === */
void f_011700(char *p1)
{
    for (;;) {
        int c = (d_1bc5f4 == 1);
        if (c & 1) {
            f_068f40();
            if (p1[0xaf]) continue;
        }
        break;
    }
    p1[0xaf] = 0;
}
//@ f_011730
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert ein 32-Bit-Spielvariablen-Objekt (Doppelwort-Wert + 16-Bit-Kennnummer) mit
 *   Startwert und Nummer und hängt seinen Zeiger hinten an das übergebene Doppelwort-Variablenregister (z. B.
 *   d_1c2138 für den Spielstand-Block 'DVAR') an.
 * - Eingaben / Rückgabe: Zeiger auf das Variablenobjekt (this), Zeiger auf das Doppelwort-Register (p2),
 *   Variablennummer (p3) und 32-Bit-Startwert (p4); keine Rückgabe.
 * - Wichtige Variablen & Daten:
 *   - Variablenobjekt (6 Bytes): 32-Bit-Wert (+0) und 16-Bit-Kennnummer (+4).
 *   - Registerobjekt (8 Bytes): Kapazität (+0), aktuelle Anzahl (+2), Zeigerfeld (+4).
 * - Besonderheiten / Originalfehler: Es findet beim Anhängen an p2->arr[p2->n] keine Prüfung gegen die
 *   Registerkapazität p2->cap statt.
 === Ende Beschreibung === */
void f_011730(RivaAceIntEntry *p1, RivaAceIntRegister *p2, short p3, int p4)
{
    p1->v = p4;
    p1->id = (short)p3;
#if FIX_R007   /* R007: Kapazitaetspruefung vor dem Eintragen in das ACE-Variablenregister */
    if (p2->n < p2->cap) {
        p2->arr[p2->n] = p1;
        p2->n++;
    }
#else
    p2->arr[p2->n] = p1;
    p2->n++;
#endif
}