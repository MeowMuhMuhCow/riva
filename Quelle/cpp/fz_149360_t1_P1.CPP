/* === Beschreibung (Katalog) ===
 * Einheit fz_149360_t1 (0x149360 - 0x149470)
 *
 * Überblick
 * Diese Einheit enthält drei generische Suchhilfsfunktionen für mit -1 terminierte Wertelisten unterschiedlicher
 * Elementbreite (short, signed char, unsigned char). Solche Listen werden im Spiel unter anderem für Item-IDs,
 * Monster-IDs, Karten-Trigger und erlaubte Klassen-/Zustandsnummern verwendet.
 === Ende Beschreibung === */
// P3 7/13 gleich (suche.py 26.10.2026, Basis fz_149360_P1.CPP)
// Codex Agent 9: Tabellenfamilie, 1/13 GLEICH, +80 B; 24.10.2026.
// F4 Stand (Basis p1 FZ_149360_P1.CPP); C++-Modus; C-Modus (VMCC=wcc386) mit #pragma aux "*" vorbereitet
// fz_149360.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x149360-0x149CAA
#include <string.h>
#ifdef __cplusplus
#include "RIVAMEM.H"



#endif
int f_1664d0(const char *p1, const char *p2, int p3);
int f_144bf0(int p1, int p2);
struct H { int a0, a4, a8, v0c, v10, v14, v18; short *p1c; };
struct E { char act; char pad1; short id; short n; short s6; short s8; unsigned char fl; unsigned char fl2; short sc; short se; int v10; int v14; struct H *p18; int v1c; int v20; int v24; int *p28; int v2c; };
extern int d_1a993d;
extern signed char d_1a9940;
extern char d_1a994b;
extern short d_1a996a;
extern int d_1a996c;
extern int d_1a99ac;
extern int d_1a9aec;
extern int d_1a9af0;
extern short d_1a9af4;
extern int d_1a9ab0;
extern int d_1a9b18;
extern int d_1c8ff4;
extern struct E *d_1cd208;
extern struct E *d_1cd210;
extern const char d_1a988c[];
extern const char d_1b8d8c[];
extern const char d_1b8d98[];
extern const char d_1b8da4[];
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define S(p,o) (*(short *)((char *)(p)+(o)))
#define RET(K) { d_1a996c = K; return K; }
int fixmul(int a, int b);
#pragma aux fixmul = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] value [eax] modify [edx];
int muldiv(int a, int b, int c);
#pragma aux muldiv = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] value [eax] modify [edx];
#ifndef __cplusplus
#pragma aux f_149360 "*";
#pragma aux f_1493c0 "*";
#pragma aux f_149410 "*";
#pragma aux f_149470 "*";
#pragma aux f_149524 "*";
#pragma aux f_149640 "*";
#pragma aux f_1496d4 "*";
#pragma aux f_149728 "*";
#pragma aux f_1497d8 "*";
#pragma aux f_149a14 "*";
#pragma aux f_149a88 "*";
#pragma aux f_149b44 "*";
#pragma aux f_149b9c "*";
#endif
#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_149360
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht ein mit -1 abgeschlossenes Array von 16-Bit-Werten (short *) linear nach dem
 *   Wert b und liefert dessen 0-basierten Index zurück.
 * - Eingaben:
 *   - a: Zeiger auf das mit -1 terminierte short-Array.
 *   - b: Gesuchter 16-Bit-Wert (short).
 * - Rückgabewert: 0-basierter Index des ersten Treffers im Array oder -1, falls a == 0 ist oder der Wert nicht
 *   vorkommt.
 * - Wichtige Variablen: c (laufender Elementindex).
 === Ende Beschreibung === */
short f_149360(int c, short *p)
{
    int i = 0;
    short r = -1;
    if (p == 0) f_1664d0(d_1b8d8c, d_1a988c, 0x26);
    while (*p != -1) {
        if (*p++ == (short)c) { r = i; break; }
        i++;
    }
    return r;
}
//@ f_1493c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht ein mit -1 (0xff) abgeschlossenes Array von vorzeichenbehafteten Bytes (signed
 *   char *) linear nach dem Wert b und liefert dessen Index zurück.
 * - Eingaben:
 *   - a: Zeiger auf das mit -1 terminierte signed char-Array.
 *   - b: Gesuchter Bytewert (signed char).
 * - Rückgabewert: 0-basierter Index des Treffers oder -1, wenn der Wert nicht enthalten ist.
 * - Wichtige Variablen: c (laufender Elementindex).
 === Ende Beschreibung === */
int f_1493c0(char c, signed char *p)
{
    int i = 0;
    int r = -1;
    if (p == 0) f_1664d0(d_1b8d98, d_1a988c, 0x49);
    while (*p != -1) {
        if (*p++ == (signed char)c) { r = i; break; }
        i++;
    }
    return r;
}
//@ f_149410
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht ein mit 0xff (-1) abgeschlossenes Array von vorzeichenlosen Bytes (unsigned
 *   char *) linear nach dem Wert b und liefert dessen Index zurück.
 * - Eingaben:
 *   - a: Zeiger auf das mit 0xff terminierte unsigned char-Array.
 *   - b: Gesuchter Bytewert (unsigned char).
 * - Rückgabewert: 0-basierter Index des Treffers oder -1 bei Nichtfinden.
 * - Wichtige Variablen: c (laufender Elementindex).
 === Ende Beschreibung === */
int f_149410(char c, unsigned char *p)
{
    int i = 0;
    int r = -1;
    if (p == 0) f_1664d0(d_1b8da4, d_1a988c, 0x6e);
    while (*p != 0xff) {
        if (*p++ == (unsigned char)c) { r = i; break; }
        i++;
    }
    return r;
}