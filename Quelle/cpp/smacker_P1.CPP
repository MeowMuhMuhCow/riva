/* === Beschreibung (Katalog) ===
 * Einheit smacker (10aad0 - 10ac80)
 *
 * Überblick
 *
 * Die Einheit smacker enthält die Abspielroutine (f_10aad0) für Vollbild-Videosequenzen im Smacker-Format (.SMK,
 * z. B. Intro-, Outro- und Zwischensequenzen von der CD-ROM).
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 30.10.2026, Basis smacker_P1.CPP)
// smacker.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10AAD0-0x10AC80
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_11e9c0();                                         // reg - stapel 0
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int __stdcall f_14bb30(int p1);                         // reg - stapel 4 R59 __stdcall?

// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c2edc;                    // 0x1C2EDC
extern const char d_1a6bd0[];           // Text 0x1A6BD0
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---


extern unsigned d_1ce4fc;
extern unsigned d_1ce4f8;
extern void (__pascal *d_1a9c9c)(void);   // Aufrufkonvention des Funktionszeigers sichert keine Arbeitsregister edx/ebx
int __stdcall f_14bb40(int a, int b, int c);
int __stdcall f_11e760(int a, int b);
void f_11e8f0();
int __stdcall f_14a940(int a, int b, int c, int d, int e, int f, int g);
void f_10aa60(int *p1, int p2);
int f_14d040(const char *fmt, ...);
void *f_145300(void *p, int c, unsigned n);
//@ f_10aad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine Smacker-Videodatei (.SMK), richtet die Video- und Audiopuffer sowie die
 *   Farbpalette ein, spielt die Einzelbilder synchron zur Tonspur auf dem Bildschirm ab und bricht die
 *   Wiedergabe ab, sobald das Video endet oder der Spieler eine Taste bzw. Maustaste drückt.
 * - Eingaben: Die Funktion erhält den Dateinamen bzw. Ressourcenzeiger p1 sowie Wiedergabe- und
 *   Koordinatenparameter (p2, p3, p4).
 * - Rückgabewert: Die Funktion gibt den Statuscode der Videowiedergabe zurück.
 === Ende Beschreibung === */
// BLIND: f_10aad0 hier komplett neu aus dem Original-Assembler schreiben (orig.sh smacker f_10aad0).
struct SmackHdr {
    unsigned Version;           // 0x00
    unsigned Width;             // 0x04
    unsigned Height;            // 0x08
    unsigned rest[23];          // 0x0C
    unsigned NewPalette;        // 0x68
    char Pal[1];                // 0x6C
};
struct SmkPlayer {
    SmackHdr *smk;              // 0x00
    char *buf;                  // 0x04
    int open;                   // 0x08
    int r0c, r10;               // 0x0C
    short width;                // 0x14
    short frame;                // 0x16
    short x;                    // 0x18
    short y;                    // 0x1A
    int buffer;                 // 0x1C
    short pause;                // 0x20
    int sound;                  // 0x22
};
//@ f_10aad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine Smacker-Videodatei (.SMK), richtet die Video- und Audiopuffer sowie die
 *   Farbpalette ein, spielt die Einzelbilder synchron zur Tonspur auf dem Bildschirm ab und bricht die
 *   Wiedergabe ab, sobald das Video endet oder der Spieler eine Taste bzw. Maustaste drückt.
 * - Eingaben: Die Funktion erhält den Dateinamen bzw. Ressourcenzeiger p1 sowie Wiedergabe- und
 *   Koordinatenparameter (p2, p3, p4).
 * - Rückgabewert: Die Funktion gibt den Statuscode der Videowiedergabe zurück.
 === Ende Beschreibung === */
//@ f_10aad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine Smacker-Videodatei (.SMK), richtet die Video- und Audiopuffer sowie die
 *   Farbpalette ein, spielt die Einzelbilder synchron zur Tonspur auf dem Bildschirm ab und bricht die
 *   Wiedergabe ab, sobald das Video endet oder der Spieler eine Taste bzw. Maustaste drückt.
 * - Eingaben: Die Funktion erhält den Dateinamen bzw. Ressourcenzeiger p1 sowie Wiedergabe- und
 *   Koordinatenparameter (p2, p3, p4).
 * - Rückgabewert: Die Funktion gibt den Statuscode der Videowiedergabe zurück.
 === Ende Beschreibung === */
// Smacker-Film oeffnen (Opus 1354 blind, 03.11.): p = Spielerstruktur, name = Datei, y/x = Position (-1 = zentriert)
int f_10aad0(SmkPlayer *p, const char *name, short y, short x)
{
    int ok;
    ok = 0;
    d_1a9c9c();
    f_146dfa((int)&d_1c2edc, 1);
    if (p->sound) {
        f_14bb30(p->sound);
        p->smk = (SmackHdr *)f_14bb40(-1, 0x800, (int)name);
    } else {
        p->smk = (SmackHdr *)f_14bb40(0, 0, (int)name);
    }
    p->buffer = f_11e9c0();
    f_146dfa((int)&d_1c2edc, 1);
    if (!p->smk) goto ende;
    p->buf = (char *)operator new[](p->smk->Width * p->smk->Height, mark(d_1a6bd0, 0xe9));
    if (!p->buf) goto ende;
    f_145300(p->buf, 0, p->smk->Width * p->smk->Height);
    if (p->width != p->smk->Width) {
        f_11e760(p->smk->Height, p->smk->Width);
        p->width = p->smk->Width;
        if (p->width > 320 || p->smk->Width > 320) f_11e8f0();
        f_146dfa((int)&d_1c2edc, 1);
    }
    // Form !(x != -1): legt den Ternaer-Zweig wie im Original (eax-Ergebnis, else movsx)
    p->x = !((short)x != -1) ? (d_1ce4fc - p->smk->Height) >> 1 : (short)x;
    p->y = y == -1 ? (d_1ce4f8 - p->smk->Width) >> 1 : y;
    f_14a940(0, (int)p->buf, p->smk->Height, p->smk->Width, 0, 0, (int)p->smk);
    f_146dfa((int)&d_1c2edc, 1);
    f_10aa60((int *)p, 1);
    if (p->smk->NewPalette) f_14d040(p->smk->Pal);
    p->open = 1;
    p->frame = 1;
    ok = 1;
    p->pause = 0;
    f_146dfa((int)&d_1c2edc, 1);
ende:
    return ok;
}
