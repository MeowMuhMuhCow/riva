/* === Beschreibung (Katalog) ===
 * Einheit gz_0222d0_mod2 (0x00022960 - 0x00022980)
 *
 * Überblick
 *
 * Die winzige Einheit gz_0222d0_mod2 enthält lediglich die statische Initialisierungs-Brückenfunktion (__STI),
 * die beim Programmstart die Variablen-Registrierung der Nachbareinheit gz_0222d0_mod1 anstößt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/11 gleich (suche.py 28.10.2026, Basis gz_0222d0_P1.CPP)
// gz_0222d0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0222D0-0x022980
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_0600f0(int p1, int p2);                           // reg edx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
short f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a9820;                    // 0x1A9820
extern int d_1bab3c;
extern int d_1bab94;                    // 0x1BAB3C
extern signed char d_1bc76c;                    // 0x1BC76C
extern signed char d_1bc77c;                    // 0x1BC77C
extern signed char d_1bc780;                    // 0x1BC780
extern signed char d_1bc788;                    // 0x1BC788
extern signed char d_1bc78c;                    // 0x1BC78C
extern unsigned char d_1bc7f4;                    // 0x1BC7F4
extern signed char d_1bc800;                    // 0x1BC800
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2c44;                    // 0x1C2C44
extern short d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern char d_1c3498[];
extern char d_1c349c[];                    // 0x1C349C
extern char d_1c3870[];                    // 0x1C3870
void f_021180();
void f_021190();
int f_145234(int p, int d);
int f_145254();

static inline int EQ(int x, int v) { return x == v; }
#define KV(ok) 0
struct Cell { long a; long b; long c; };
typedef RivaTextContextData Msg;
struct Msg3 { int h; int *n; int pad[4]; int *q; int rest[8]; };
#define CX(m) Msg m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CX3(m) Msg3 m; f_125400((int)&m, A(d_1c349c), A(d_1c3870), A(d_1c3498))
#define CXEND(m) f_1254a0((int)&m, 0)
#define F1(m) (m).tables.p[1]
#define F2(m) (m).tables.p[2]
#define F6(m) (m).q[1]
#define A(x) ((int)&(x))

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_022960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft beim Start des Spiels automatisch die Registrierungsfunktion f_022910 auf, damit die
 *   Ereignismerker des zugehörigen Schauplatzes in die Spielstand-Verwaltung aufgenommen werden.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Es werden keine eigenen Variablen verwaltet; die Funktion delegiert direkt an f_022910.
 === Ende Beschreibung === */
void f_022960(int p1) { int r = f_05ff60(p1, 0xe); *(int **)(r + 8) = &d_1bab94; }
