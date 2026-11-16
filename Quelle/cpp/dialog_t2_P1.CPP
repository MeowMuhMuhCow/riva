/* === Beschreibung (Katalog) ===
 * Einheit dialog_t2 (056930 - 056cc0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil des Dialog-Systems (dialog.cpp). Sie stellt den Haupteinstiegspunkt
 * f_056a50 zum Starten eines NPC-Gesprächs bereit und bietet Hilfsfunktionen zum Lesen, Setzen und Löschen
 * einzelner globaler Dialog-Flags in d_1bca74.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 5/6 gleich (suche.py 29.10.2026, Basis dialog_t2_P1.CPP)
// dialog.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x055120-0x056CC0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
void __cdecl f_099ef0(void *p1, int p2, int p3);
//int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8a00(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1, int p2);
//int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a10(int p1);                                   // reg eax stapel 0
int f_0d5ff0();                       // nicht in clobber.tsv
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dd410(int p1, int p2);                           // reg edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_11f550(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126f40(int p1);                                   // reg eax stapel 0
int f_1270c0(int p1);                                   // reg eax stapel 0
int f_142f70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
char *f_1430a0(void *p1, int p2);
//int f_1430a0(int p1, int p2);                           // reg eax stapel 0
int f_143170(void *p1);
//int f_143170(int p1);                                   // reg eax stapel 0
int f_143350(int p1, int p2);                           // reg eax edx stapel 0
int f_143390(int p1);                                   // reg eax stapel 0
int f_1433c0(int p1);                                   // reg eax stapel 0
int f_1433d0(int p1, int p2, int p3);                   // reg eax edx stapel 0
int f_1434f0(int p1);                                   // reg eax stapel 0
           // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0

//int f_144960(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
void __cdecl f_149eb4(void *p1, int p2, int p3);
//int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern const char *d_1a965c;
extern const char *d_1a1688;
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1bc760;                    // 0x1BC760
extern int d_1bc76c;                    // 0x1BC76C
extern int d_1bc788;                    // 0x1BC788
extern int d_1bc790;                    // 0x1BC790
extern int d_1bc7f0;                    // 0x1BC7F0
extern int d_1bca68;                    // 0x1BCA68
extern int d_1bca69;                    // 0x1BCA69
extern int d_1bca6c;                    // 0x1BCA6C
extern int d_1bca70;                    // 0x1BCA70
extern char *d_1bca74;
extern char *d_1bca78;
extern int d_1bca7c;                    // 0x1BCA7C
extern int d_1bca80;                    // 0x1BCA80
extern int d_1bca84;                    // 0x1BCA84
extern int d_1bca88;                    // 0x1BCA88
extern int d_1bca8c;                    // 0x1BCA8C
extern int d_1bca90;                    // 0x1BCA90
extern int d_1bca94;                    // 0x1BCA94
extern int d_1bca98;                    // 0x1BCA98
extern int d_1bca9c;                    // 0x1BCA9C
extern int d_1bcaa0;                    // 0x1BCAA0
extern int d_1bcaa4;                    // 0x1BCAA4
extern int d_1bcaa8;                    // 0x1BCAA8
extern int d_1bcaac;                    // 0x1BCAAC
extern int d_1bcab0;                    // 0x1BCAB0
extern int d_1bcab4;                    // 0x1BCAB4
extern int d_1bdcf4;                    // 0x1BDCF4
extern int d_1bdcf8;                    // 0x1BDCF8
extern int d_1bed74;                    // 0x1BED74
extern int d_1bf1ac;                    // 0x1BF1AC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c00a0;                    // 0x1C00A0
extern int d_1c00a4;                    // 0x1C00A4
extern int d_1c00a8;                    // 0x1C00A8
extern int d_1c00ac;                    // 0x1C00AC
extern int d_1c00bc;                    // 0x1C00BC
extern int d_1c00c0;                    // 0x1C00C0
extern int d_1c00c4;                    // 0x1C00C4
extern int d_1c01b8;                    // 0x1C01B8
extern int d_1c01e0;                    // 0x1C01E0
extern int d_1c01f4;                    // 0x1C01F4
extern volatile int d_1c0c94;                    // 0x1C0C94
                    // 0x1C2098
extern short d_1c2198;
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c21b8;                    // 0x1C21B8
extern int d_1c27a8;                    // 0x1C27A8
extern signed char d_1c2a80;                    // 0x1C2A80
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a1668[];           // Text 0x1A1668
// --- eigene Funktionen (14), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

void *f_142f70(void *p1, int p2, void *p3);
void *f_147c84(void *p1, int p2, void *p3);
void f_055120();
void f_0552a0();
void f_055650();
void f_056030();
void f_056450();
void f_056860();
struct DP { char *buf; char a; char b; char c; const char *t; short w; char *buf2; void (*h1)(); void (*h2)(); void (*h3)(); void (*h4)(); };
struct W { char pad[0xb3]; };
#define OBJ ((int)&d_1c2098)
#define TBL ((int)&d_1c21b4)

//@ f_056930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt sicher, dass die Dialog-Zustandsdaten (d_1bca74 und d_1bca78) im Speicher geladen sind,
 *   und lädt sie bei Bedarf aus der Spielstanddatei nach.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt als int den Wert 1 zurück, wenn die Daten
 *   neu geladen werden mussten, oder 0, wenn sie bereits im Speicher lagen.
 * - Wichtige Variablen: Geprüft wird der globale Pufferzeiger d_1bca74; ist er 0, werden f_055120 und f_0552a0
 *   aufgerufen.
 === Ende Beschreibung === */
int f_056930()
{
    int r = 0;
    if (d_1bca74 == 0) {
        f_055120();
        f_0552a0();
        r = 1;
    }
    return r;
}

//@ f_056950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert die aktuellen Dialog-Flags (d_1bca74) und Gesprächszähler (d_1bca78) in die Datei
 *   0x40000000 zurück und gibt beide Speicherblöcke frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Sie schreibt ab Dateioffset 0xe82 die 12 Bytes aus d_1bca74 sowie die 0xce Bytes aus
 *   d_1bca78 über den Dateimanager d_1c2098 weg.
 === Ende Beschreibung === */
void f_056950()
{
    const char *sv = d_1a965c;
    d_1a965c = d_1a1688;
    if (((RivaFileManager*)(OBJ))->f_1448b0( 0x40000000, 0x202) == 1) {
        ((RivaFileManager*)(OBJ))->f_144ab0( 0xe82, 0);
        ((int)(((RivaFileManager*)(OBJ))->f_144920((void *)( TBL), 6)));
        ((int)(((RivaFileManager*)(OBJ))->f_144960((void *)( d_1bca74), 0xc)));
        delete d_1bca74;
        d_1bca74 = 0;
        ((int)(((RivaFileManager*)(OBJ))->f_144920((void *)( TBL), 6)));
        ((int)(((RivaFileManager*)(OBJ))->f_144960((void *)( d_1bca78), 0xce)));
        delete d_1bca78;
        d_1bca78 = 0;
        ((RivaFileManager*)(OBJ))->f_1449a0();
    }
    d_1a965c = sv;
}

//@ f_056a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Zustand eines einzelnen globalen Dialog-Flags aus dem Array d_1bca74 aus (z. B. nach
 *   Abschluss eines Gesprächs zur Abfrage, ob ein bestimmtes Ereignis ausgelöst wurde).
 * - Eingaben und Rückgabe: Die Funktion erhält den Flag-Index p1 (short) und gibt den Wert d_1bca74[p1] als int
 *   zurück.
 * - Wichtige Variablen: Das Array d_1bca74 umfasst 12 globale Statusbytes für wichtige Gesprächsergebnisse.
 === Ende Beschreibung === */
int f_056a20(short p1)
{
    return *(signed char *)(d_1bca74 + p1);
}

//@ f_056a30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt ein einzelnes globales Dialog-Flag im Array d_1bca74 auf 1.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Flag-Index p1 (short) entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Byte d_1bca74[p1] wird auf 1 gesetzt.
 === Ende Beschreibung === */
void f_056a30(short p1)
{
    *(d_1bca74 + p1) = 1;
}

//@ f_056a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht ein einzelnes globales Dialog-Flag im Array d_1bca74 auf 0.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Flag-Index p1 (short) entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Byte d_1bca74[p1] wird auf 0 zurückgesetzt.
 === Ende Beschreibung === */
void f_056a40(short p1)
{
    *(d_1bca74 + p1) = 0;
}

//@ f_056a50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet und führt ein komplettes Gespräch mit einem Nichtspielercharakter (NPC): Die Funktion
 *   sichert die aktuelle Farbpalette, lädt die Dialog-Zustandsdatei, öffnet das Dialogfenster mit den vier
 *   Callback-Funktionen (f_055650, f_056030, f_056450, f_056860), führt den Dialog bis zum Gesprächsende aus und
 *   speichert danach die geänderten Dialog-Flags wieder ab.
 * - Eingaben und Rückgabe: Die Funktion erhält die Ressourcen-Kennung des Dialogs mode (z. B. 0x150008 +
 *   dialog_nr) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Struktur dialog (DP) bündelt die Puffer d_1bca74 und d_1bca78 sowie die vier
 *   Callback-Zeiger für die allgemeine Dialogfenster-Klasse (f_142f70 / f_143170), während d_1c2a80 für die
 *   Dauer des Gesprächs auf 0x150004 gesetzt wird.
 === Ende Beschreibung === */
void *paletteDialogCtor492(void *);
#pragma aux paletteDialogCtor492 "f_01e100" parm [eax] value [eax] modify exact []
struct PaletteDialog492 { unsigned char red, green, blue; PaletteDialog492(); };
void f_056a50(int mode)
{
    DP dialog;
    int guard;
    f_0ce7c0(&guard);

    PaletteDialog492 *palette = new (mark(d_1a1668, 0x601)) PaletteDialog492[256];
    int saved_callback = d_1c0c94;
    f_0d2f90(0, 1);
    f_055120();
    f_0552a0();

    dialog.buf = d_1bca74;
    dialog.a = 12;
    dialog.b = 28;
    dialog.c = 32;
    dialog.t = d_1a1688;
    dialog.w = (short)(mode - 0x150008);
    dialog.buf2 = d_1bca78;
    dialog.h1 = f_055650;
    dialog.h2 = f_056030;
    dialog.h3 = f_056450;
    dialog.h4 = f_056860;
    d_1c0c94 = 0;
    f_149eb4(palette, 0, 256);

    f_09a140(0, 25);
    if (d_1bc760) f_01cef0(d_1bc760);
    f_09a0d0(d_1a34e0);

    W *allocation = new (mark(d_1a1668, 0x629)) W;
    W *window;
    if (allocation) window = (W *)f_142f70(allocation, mode, &dialog);
    else window = allocation;
    *(int *)&d_1c2a80 = 0x150004;
    f_143170(window);
    if (window) operator delete(f_1430a0(window, 0));

    const char *old_text = d_1a965c;
    d_1a965c = d_1a1688;
    int result = ((RivaFileManager*)(OBJ))->f_1448b0( 0x40000000, 0x202);
    if (result == 1) {
        ((RivaFileManager*)(OBJ))->f_144ab0( 0xe82, 0);
        ((int)(((RivaFileManager*)(OBJ))->f_144920((void *)( TBL), 6)));
        ((int)(((RivaFileManager*)(OBJ))->f_144960((void *)( d_1bca74), 12)));
        operator delete(d_1bca74);
        d_1bca74 = 0;
        ((int)(((RivaFileManager*)(OBJ))->f_144920((void *)( TBL), 6)));
        ((int)(((RivaFileManager*)(OBJ))->f_144960((void *)( d_1bca78), 0xce)));
        operator delete(d_1bca78);
        d_1bca78 = 0;
        ((RivaFileManager*)(OBJ))->f_1449a0();
    }
    d_1a965c = old_text;

    f_09a140(0, 25);
    f_09a0d0(d_1a34e0);
    f_099ef0(palette, 0, 256);
    *(volatile short *)&d_1c2198 = 1;
    *(int *)&d_1c2a80 = 0;
    d_1c0c94 = saved_callback;
    operator delete(palette);
    f_0ce7e0(&guard, 0);
}
