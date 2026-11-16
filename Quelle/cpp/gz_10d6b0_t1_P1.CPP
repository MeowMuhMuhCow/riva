/* === Beschreibung (Katalog) ===
 * Einheit gz_10d6b0_t1 (0x10d6b0 - 0x10fb00)
 *
 * Überblick
 * Diese Einheit implementiert den ersten großen Block der Zauberspruch-Ausführungsroutinen außerhalb und
 * innerhalb von Kämpfen (darunter Beherrschungs-, Verwandlungs-, Illusions-, Kampf- und Hellsichtzauber wie
 * *Bannbaladin*, *Böser Blick*, *Horriphobus*, *Große Gier*, *Große Verwirrung*, *Somnigravis*, *Karnifilo*,
 * *Chamaelioni*, *Duplicatus*, *Harmlose Gestalt*, *Hexenknoten*, *Blitz dich find*, *Fulminictus*, *Ignifaxius*
 * und *Plumbumbarum*). Zudem enthält sie die zentrale Sprungverteiler-Funktion (f_10d6b0), die anhand der
 * Zauber-ID (0x00 bis 0x54) die zugehörige Zauberroutine aufruft.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 98/112 gleich (suche.py 26.10.2026, Basis gz_10d6b0_t1_P1.CPP)
// gz_10d6b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10D6B0-0x10F910
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_030e20(int p1, int p2);                           // reg eax edx stapel 0

struct SO { int a0; int *p4; int *p8; int *pc; int *p10; short *p14; short *p18; short *p1c; short *p20; char pad[0x18]; };
struct P { short s0; short s2; signed char c4; signed char c5; char pad[12]; int i12; int i16; int i1a; };
struct VOb;
struct VT { char pad[0x28]; short (*f28)(VOb *, int, VT *, const char *); void (*f2c)(VOb *, int); };
struct VOb { int a0; int a4; VT *vt; };
void f_10dc00(P *);
void f_10dce0(P *);
void f_10dee0(P *);
void f_10e000(P *);
void f_10e1a0(P *);
void f_10e380(P *);
void f_10e440(P *);
void f_10e4f0(P *);
void f_10e5e0(P *);
void f_10e6c0(P *);
void f_10e760(P *);
void f_10e830(P *);
void f_10e900(P *);
void f_10ea90(P *);
void f_10eaf0(P *);
void f_10ebc0(P *);
void f_10ec50(P *);
void f_10eef0(P *);
void f_10ef30(P *);
void f_10ef60(P *);
void f_10f300(P *);
void f_10f3d0(P *);
void f_10f4c0(P *);
void f_10f630(P *);
void f_10f7e0(P *);
void f_10f250(int);
void f_10f770(void);
int f_125400(SO *, const char *, const char *, const char *);
int f_1254a0(SO *, int);
void f_0e93f0(const char *, char *, int);
short f_145760(int, int);
short f_1457e0(int);





short f_032820(int, int, int);


int f_033530(int, int);
int f_091f70(int);


int f_068e40(void);
short f_0bf7b0(int, int, int, int, int, int);
short f_03d3d0(int, int, int);
int f_043c70(int, int);
char f_0cff20(int);
signed char f_0cfcc0(int);
int f_0cfdd0(int, int);

int f_10d5e0(int, int);
int f_10d640(int);



int f_045430(int, int, int);

int f_0d0440(int);
char f_0d00c0(int);
int f_0cfed0(int, int);

signed char f_0cfa70(int);
int f_0cff90(int, int);
int f_0cfac0(int, int);
int f_0773b0(int);
int f_0cffc0(int, int);

int f_0cfae0(int, int);
int f_0cfb10(int, int);
unsigned f_0cfa90(int);
int f_0cff60(int, int);
char f_0cfc10(int);
int f_044230(int, int);
int f_0442b0(int, int);
int f_039040(int);

int f_0cfe00(int, int);
int f_030e20(int, int);
int f_0cfff0(int, int);
char f_0cfdc0(int);

short f_10cde0(int);
int f_10ccf0(int, int);

short f_0d4c80(int);

int f_0d5040(int, int, int, int, int, int);
signed char f_0433e0(int);
signed char f_045300(int);
int f_043420(int, int);
int f_0433f0(int, int);


int f_0406d0(int, int);
extern int d_1bc88c;
extern VOb *d_1bd6c0;
extern short d_1bd90c;
extern short d_1bd924;
extern int d_1c0004;
extern char d_1c0416;
extern short d_1c041d;
extern char d_1c041f;
extern int d_1c0424;
extern short d_1c0428;
extern signed char d_1c042a;
extern int d_1c0900;
extern char d_1c0904;
extern short d_1c0905;
extern char d_1c0908;
extern short d_1c0909;
extern short d_1c212a;
extern char **d_1c212c;
extern volatile short d_1c2198; // haelt Schreibfolge in f_10dce0 wie im Original

extern char d_1c21b4;
extern const char d_1c2c64[];
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c38b0[];
#define CTOR f_125400(&o, d_1c349c, d_1c3870, d_1c3498)
#define DTOR f_1254a0(&o, 0)
#define MSG(x) f_0e93f0(d_1c38b0, &d_1c21b4, x)

//@ f_10d6b0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Verteilt die Ausführung eines gesprochenen Zauberspruchs anhand seiner Zauber-ID (0x00 bis 0x54) auf
 *   die zuständige Implementierungsfunktion im Zaubersystem (spell bis spell5).
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt (mit der Zauber-ID
 *   an Offset +2, dem Zaubernden an +3, dem Zielwesen an +7 und den Zielkoordinaten an +11/+13).
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück; Ergebnisse und eventuelle Fehlercodes werden direkt in
 *   das Zauberkontext-Objekt (s0 an Offset +0) eingetragen.
 === Ende Beschreibung === */
extern void f_112dc0(void);
void *f_10d6b0(void) { return (void *)f_112dc0; }
//@ f_10d6c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112d40
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112d40 als void * zurück.
 === Ende Beschreibung === */
extern void f_112d40(void);
void *f_10d6c0(void) { return (void *)f_112d40; }
//@ f_10d6d0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112c90
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112c90 als void * zurück.
 === Ende Beschreibung === */
extern void f_112c90(void);
void *f_10d6d0(void) { return (void *)f_112c90; }
//@ f_10d6e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112c20
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112c20 als void * zurück.
 === Ende Beschreibung === */
extern void f_112c20(void);
void *f_10d6e0(void) { return (void *)f_112c20; }
//@ f_10d6f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112bf0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112bf0 als void * zurück.
 === Ende Beschreibung === */
extern void f_112bf0(void);
void *f_10d6f0(void) { return (void *)f_112bf0; }
//@ f_10d700  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112b80
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112b80 als void * zurück.
 === Ende Beschreibung === */
extern void f_112b80(void);
void *f_10d700(void) { return (void *)f_112b80; }
//@ f_10d710  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112ac0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112ac0 als void * zurück.
 === Ende Beschreibung === */
extern void f_112ac0(void);
void *f_10d710(void) { return (void *)f_112ac0; }
//@ f_10d720  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1127e0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1127e0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1127e0(void);
void *f_10d720(void) { return (void *)f_1127e0; }
//@ f_10d730  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112790
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112790 als void * zurück.
 === Ende Beschreibung === */
extern void f_112790(void);
void *f_10d730(void) { return (void *)f_112790; }
//@ f_10d740  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1126e0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1126e0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1126e0(void);
void *f_10d740(void) { return (void *)f_1126e0; }
//@ f_10d750  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112590
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112590 als void * zurück.
 === Ende Beschreibung === */
extern void f_112590(void);
void *f_10d750(void) { return (void *)f_112590; }
//@ f_10d760  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112340
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112340 als void * zurück.
 === Ende Beschreibung === */
extern void f_112340(void);
void *f_10d760(void) { return (void *)f_112340; }
//@ f_10d770  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112270
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112270 als void * zurück.
 === Ende Beschreibung === */
extern void f_112270(void);
void *f_10d770(void) { return (void *)f_112270; }
//@ f_10d780  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1121d0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1121d0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1121d0(void);
void *f_10d780(void) { return (void *)f_1121d0; }
//@ f_10d790  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1121a0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1121a0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1121a0(void);
void *f_10d790(void) { return (void *)f_1121a0; }
//@ f_10d7a0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112190
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112190 als void * zurück.
 === Ende Beschreibung === */
extern void f_112190(void);
void *f_10d7a0(void) { return (void *)f_112190; }
//@ f_10d7b0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112180
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112180 als void * zurück.
 === Ende Beschreibung === */
extern void f_112180(void);
void *f_10d7b0(void) { return (void *)f_112180; }
//@ f_10d7c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112170
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112170 als void * zurück.
 === Ende Beschreibung === */
extern void f_112170(void);
void *f_10d7c0(void) { return (void *)f_112170; }
//@ f_10d7d0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112160
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112160 als void * zurück.
 === Ende Beschreibung === */
extern void f_112160(void);
void *f_10d7d0(void) { return (void *)f_112160; }
//@ f_10d7e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112150
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112150 als void * zurück.
 === Ende Beschreibung === */
extern void f_112150(void);
void *f_10d7e0(void) { return (void *)f_112150; }
//@ f_10d7f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112140
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112140 als void * zurück.
 === Ende Beschreibung === */
extern void f_112140(void);
void *f_10d7f0(void) { return (void *)f_112140; }
//@ f_10d800  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112090
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112090 als void * zurück.
 === Ende Beschreibung === */
extern void f_112090(void);
void *f_10d800(void) { return (void *)f_112090; }
//@ f_10d810  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_112080
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_112080 als void * zurück.
 === Ende Beschreibung === */
extern void f_112080(void);
void *f_10d810(void) { return (void *)f_112080; }
//@ f_10d820  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111e00
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111e00 als void * zurück.
 === Ende Beschreibung === */
extern void f_111e00(void);
void *f_10d820(void) { return (void *)f_111e00; }
//@ f_10d830  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111d70
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111d70 als void * zurück.
 === Ende Beschreibung === */
extern void f_111d70(void);
void *f_10d830(void) { return (void *)f_111d70; }
//@ f_10d840  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111ca0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111ca0 als void * zurück.
 === Ende Beschreibung === */
extern void f_111ca0(void);
void *f_10d840(void) { return (void *)f_111ca0; }
//@ f_10d850  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111b90
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111b90 als void * zurück.
 === Ende Beschreibung === */
extern void f_111b90(void);
void *f_10d850(void) { return (void *)f_111b90; }
//@ f_10d860  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111b60
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111b60 als void * zurück.
 === Ende Beschreibung === */
extern void f_111b60(void);
void *f_10d860(void) { return (void *)f_111b60; }
//@ f_10d870  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111a80
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111a80 als void * zurück.
 === Ende Beschreibung === */
extern void f_111a80(void);
void *f_10d870(void) { return (void *)f_111a80; }
//@ f_10d880  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111930
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111930 als void * zurück.
 === Ende Beschreibung === */
extern void f_111930(void);
void *f_10d880(void) { return (void *)f_111930; }
//@ f_10d890  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1118a0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1118a0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1118a0(void);
void *f_10d890(void) { return (void *)f_1118a0; }
//@ f_10d8a0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1117c0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1117c0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1117c0(void);
void *f_10d8a0(void) { return (void *)f_1117c0; }
//@ f_10d8b0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1114a0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1114a0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1114a0(void);
void *f_10d8b0(void) { return (void *)f_1114a0; }
//@ f_10d8c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111440
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111440 als void * zurück.
 === Ende Beschreibung === */
extern void f_111440(void);
void *f_10d8c0(void) { return (void *)f_111440; }
//@ f_10d8d0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111300
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111300 als void * zurück.
 === Ende Beschreibung === */
extern void f_111300(void);
void *f_10d8d0(void) { return (void *)f_111300; }
//@ f_10d8e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_111190
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_111190 als void * zurück.
 === Ende Beschreibung === */
extern void f_111190(void);
void *f_10d8e0(void) { return (void *)f_111190; }
//@ f_10d8f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1110f0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1110f0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1110f0(void);
void *f_10d8f0(void) { return (void *)f_1110f0; }
//@ f_10d900  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_1110c0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_1110c0 als void * zurück.
 === Ende Beschreibung === */
extern void f_1110c0(void);
void *f_10d900(void) { return (void *)f_1110c0; }
//@ f_10d910  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110ff0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110ff0 als void * zurück.
 === Ende Beschreibung === */
extern void f_110ff0(void);
void *f_10d910(void) { return (void *)f_110ff0; }
//@ f_10d920  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110f30
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110f30 als void * zurück.
 === Ende Beschreibung === */
extern void f_110f30(void);
void *f_10d920(void) { return (void *)f_110f30; }
//@ f_10d930  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110ed0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110ed0 als void * zurück.
 === Ende Beschreibung === */
extern void f_110ed0(void);
void *f_10d930(void) { return (void *)f_110ed0; }
//@ f_10d940  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110e70
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110e70 als void * zurück.
 === Ende Beschreibung === */
extern void f_110e70(void);
void *f_10d940(void) { return (void *)f_110e70; }
//@ f_10d950  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110d90
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110d90 als void * zurück.
 === Ende Beschreibung === */
extern void f_110d90(void);
void *f_10d950(void) { return (void *)f_110d90; }
//@ f_10d960  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110b70
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110b70 als void * zurück.
 === Ende Beschreibung === */
extern void f_110b70(void);
void *f_10d960(void) { return (void *)f_110b70; }
//@ f_10d970  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110ae0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110ae0 als void * zurück.
 === Ende Beschreibung === */
extern void f_110ae0(void);
void *f_10d970(void) { return (void *)f_110ae0; }
//@ f_10d980  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110980
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110980 als void * zurück.
 === Ende Beschreibung === */
extern void f_110980(void);
void *f_10d980(void) { return (void *)f_110980; }
//@ f_10d990  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110690
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110690 als void * zurück.
 === Ende Beschreibung === */
extern void f_110690(void);
void *f_10d990(void) { return (void *)f_110690; }
//@ f_10d9a0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110620
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110620 als void * zurück.
 === Ende Beschreibung === */
extern void f_110620(void);
void *f_10d9a0(void) { return (void *)f_110620; }
//@ f_10d9b0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110520
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110520 als void * zurück.
 === Ende Beschreibung === */
extern void f_110520(void);
void *f_10d9b0(void) { return (void *)f_110520; }
//@ f_10d9c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110490
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110490 als void * zurück.
 === Ende Beschreibung === */
extern void f_110490(void);
void *f_10d9c0(void) { return (void *)f_110490; }
//@ f_10d9d0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110380
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110380 als void * zurück.
 === Ende Beschreibung === */
extern void f_110380(void);
void *f_10d9d0(void) { return (void *)f_110380; }
//@ f_10d9e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_110200
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_110200 als void * zurück.
 === Ende Beschreibung === */
extern void f_110200(void);
void *f_10d9e0(void) { return (void *)f_110200; }
//@ f_10d9f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ffe0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ffe0 als void * zurück.
 === Ende Beschreibung === */
extern void f_10ffe0(void);
void *f_10d9f0(void) { return (void *)f_10ffe0; }
//@ f_10da00  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10fe10
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10fe10 als void * zurück.
 === Ende Beschreibung === */
extern void f_10fe10(void);
void *f_10da00(void) { return (void *)f_10fe10; }
//@ f_10da10  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10fc90
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10fc90 als void * zurück.
 === Ende Beschreibung === */
extern void f_10fc90(void);
void *f_10da10(void) { return (void *)f_10fc90; }
//@ f_10da20  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10fc00
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10fc00 als void * zurück.
 === Ende Beschreibung === */
extern void f_10fc00(void);
void *f_10da20(void) { return (void *)f_10fc00; }
//@ f_10da30  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10fb00
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10fb00 als void * zurück.
 === Ende Beschreibung === */
extern void f_10fb00(void);
void *f_10da30(void) { return (void *)f_10fb00; }
//@ f_10da40  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f910
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f910 als void * zurück.
 === Ende Beschreibung === */
extern void f_10f910(void);
void *f_10da40(void) { return (void *)f_10f910; }
//@ f_10da50  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f7e0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f7e0 als void * zurück.
 === Ende Beschreibung === */
void *f_10da50(void) { return (void *)f_10f7e0; }
//@ f_10da60  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f630
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f630 als void * zurück.
 === Ende Beschreibung === */
void *f_10da60(void) { return (void *)f_10f630; }
//@ f_10da70  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f4c0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f4c0 als void * zurück.
 === Ende Beschreibung === */
void *f_10da70(void) { return (void *)f_10f4c0; }
//@ f_10da80  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f3d0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f3d0 als void * zurück.
 === Ende Beschreibung === */
void *f_10da80(void) { return (void *)f_10f3d0; }
//@ f_10da90  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f300
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f300 als void * zurück.
 === Ende Beschreibung === */
void *f_10da90(void) { return (void *)f_10f300; }
//@ f_10daa0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10f250
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10f250 als void * zurück.
 === Ende Beschreibung === */
void *f_10daa0(void) { return (void *)f_10f250; }
//@ f_10dab0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ef60
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ef60 als void * zurück.
 === Ende Beschreibung === */
void *f_10dab0(void) { return (void *)f_10ef60; }
//@ f_10dac0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ef30
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ef30 als void * zurück.
 === Ende Beschreibung === */
void *f_10dac0(void) { return (void *)f_10ef30; }
//@ f_10dad0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10eef0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10eef0 als void * zurück.
 === Ende Beschreibung === */
void *f_10dad0(void) { return (void *)f_10eef0; }
//@ f_10dae0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ec50
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ec50 als void * zurück.
 === Ende Beschreibung === */
void *f_10dae0(void) { return (void *)f_10ec50; }
//@ f_10daf0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ebc0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ebc0 als void * zurück.
 === Ende Beschreibung === */
void *f_10daf0(void) { return (void *)f_10ebc0; }
//@ f_10db00  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10eaf0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10eaf0 als void * zurück.
 === Ende Beschreibung === */
void *f_10db00(void) { return (void *)f_10eaf0; }
//@ f_10db10  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e760
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e760 als void * zurück.
 === Ende Beschreibung === */
void *f_10db10(void) {
    extern void f_10e760_alt(P *);
#pragma aux f_10e760_alt "W?f_10e760$n(pn$P$$)v"
    return (void *)f_10e760_alt;
}
//@ f_10db20  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10ea90
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10ea90 als void * zurück.
 === Ende Beschreibung === */
void *f_10db20(void) { return (void *)f_10ea90; }
//@ f_10db30  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e900
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e900 als void * zurück.
 === Ende Beschreibung === */
void *f_10db30(void) { return (void *)f_10e900; }
//@ f_10db40  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e830
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e830 als void * zurück.
 === Ende Beschreibung === */
void *f_10db40(void) { return (void *)f_10e830; }
//@ f_10db50  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e760
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e760 als void * zurück.
 === Ende Beschreibung === */
void *f_10db50(void) { return (void *)f_10e760; }
//@ f_10db60  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e6c0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e6c0 als void * zurück.
 === Ende Beschreibung === */
void *f_10db60(void) { return (void *)f_10e6c0; }
//@ f_10db70  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e5e0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e5e0 als void * zurück.
 === Ende Beschreibung === */
void *f_10db70(void) { return (void *)f_10e5e0; }
//@ f_10db80  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e4f0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e4f0 als void * zurück.
 === Ende Beschreibung === */
void *f_10db80(void) { return (void *)f_10e4f0; }
//@ f_10db90  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e440
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e440 als void * zurück.
 === Ende Beschreibung === */
void *f_10db90(void) { return (void *)f_10e440; }
//@ f_10dba0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e380
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e380 als void * zurück.
 === Ende Beschreibung === */
void *f_10dba0(void) { return (void *)f_10e380; }
//@ f_10dbb0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e1a0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e1a0 als void * zurück.
 === Ende Beschreibung === */
void *f_10dbb0(void) { return (void *)f_10e1a0; }
//@ f_10dbc0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10e000
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10e000 als void * zurück.
 === Ende Beschreibung === */
void *f_10dbc0(void) { return (void *)f_10e000; }
//@ f_10dbd0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10dee0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10dee0 als void * zurück.
 === Ende Beschreibung === */
void *f_10dbd0(void) { return (void *)f_10dee0; }
//@ f_10dbe0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10dce0
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10dce0 als void * zurück.
 === Ende Beschreibung === */
void *f_10dbe0(void) { return (void *)f_10dce0; }
//@ f_10dbf0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Liefert als Hilfs-Getter für die Zauber-Sprungtabelle die Funktionsadresse der Zauberroutine f_10dc00
 *   zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Funktionszeiger auf f_10dc00 als void * zurück.
 === Ende Beschreibung === */
void *f_10dbf0(void) { return (void *)f_10dc00; }
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_10dc00  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Hebt bei einem ausgewählten Gruppenmitglied (p->i16) einen magischen Zustand (f_0425a0 / f_0425b0)
 *   auf, sofern der Zaubernde über die ausgewürfelten Astralpunkte ((2..5) * 4 + d_1c042a) verfügt.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10dc00(P *p)
{
    SO o;
    CTOR;
    o.p4[1] = p->i16;
    if (!((char)(f_0425a0((struct hero *)(p->i16))))) {
        MSG(0x170000ec);
        p->s0 = -4;
    } else {
        short s2 = f_145760(2, 5);
        p->s0 = (short)(s2 & 0xffff) << 2; // erzwingt 16-Bit-Maske vor Linksshift wie im Original
        p->s0 += d_1c042a;
        if (f_0429a0((struct hero *)(p->i12)) < p->s0) {
            short h = p->s0 / 2;
            p->s0 = -2;
            *(volatile short *)&p->s2 = h; // verhindert Epilog-Verschmelzung vor DTOR wie im Original
            DTOR;
            return;
        }
        f_0425b0((struct hero *)(p->i16), 0);
        MSG(0x17000011);
    }
    DTOR;
}
//@ f_10dce0
/* === Beschreibung (Katalog) ===
 * - Zweck: Lässt den Spieler außerhalb eines Kampfes (!d_1c0428) einen Gegenstand aus dem Inventar des
 *   Zaubernden (p->i12) auswählen (0x170000b6), führt darauf eine magische Umwandlung bzw. Reinigung (f_033530)
 *   durch und berechnet die Astralenergiekosten (5..50 + d_1c042a).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10dce0(P *p)
{
    struct Objekt : SO {
        Objekt() { f_125400(this,d_1c349c,d_1c3870,d_1c3498); }
        ~Objekt() { f_1254a0(this,0); }
    };
    Objekt o;
    short s1, u1, u2;
    int r;
    int item = 0;
    int k, kt, h, hu;
    if (!d_1c0428) {
        h = p->i12; hu = h; h = hu; // haelt die Registerfolge fuer p->i12 wie im Original
        s1 = f_032820(h,0x170000b6,1);
        r = s1;
        if (r != -1) {
            s1 = f_042a60((struct hero *)(p->i12),r);
            u1 = f_042ac0((struct hero *)(p->i12),r);
            u2 = u1;
#if FIX_R049
            p->s0 = f_145760(5,0x32) + (short)d_1c042a;
            if (f_0429a0((struct hero *)(p->i12)) < p->s0) return;
#endif
            r = f_033530(p->i12,r);
            if (r == 0) {
                p->s0 = -4;
                if ((u1 > 1 && (k = s1, kt = k, k = kt, ((RivaItemDefinition*)((*(int **)&d_1c2c40)[k]))->f_0a7950()) != 0) || ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s1]))->f_0a7ad0() != 0)
                    o.p20[1] = 2;
                else o.p20[1] = 1;
                item = (*(int **)&d_1c2c40)[s1];
                o.pc[1] = item;
                MSG(0x170000ee);
                return;
            } else {
                *(int *)(o.pc+1) = (*(int **)&d_1c2c40)[s1];
                if (s1 == 0x1bd) f_091f70(4);
                if ((u2 > 1 && ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s1]))->f_0a7950() != 0) || ((RivaItemDefinition*)((*(int **)&d_1c2c40)[s1]))->f_0a7ad0() != 0) {
                    o.p20[1] = 2;
                    o.p10[1] = 0x1700002a;
                } else {
                    o.p20[1] = 1;
                    o.p10[1] = 0x20000194;
                }
                MSG(0x170000ed);
                f_068e40();
#if !FIX_R049
                p->s0 = f_145760(5,0x32);
                p->s0 += (short)d_1c042a;
#endif
                d_1c2198 = 1;
                return;
            }
        }
    }
    *(volatile short *)&p->s0 = -4; // verhindert Epilog-Verschmelzung am Funktionsende wie im Original
}
//@ f_10dee0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt über einen Zahlendialog (0x17000012) die einzusetzenden Astralpunkte ab, legt eine Zauberprobe
 *   auf Spruch 3 (f_03d3d0) ab und überträgt bzw. regeneriert bei Erfolg die entsprechende Menge samt
 *   Stufenbonus (f_0428d0) über f_043c70.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10dee0(P *p)
{
    SO o;
    signed char c;
    short s2, s3;
    CTOR;
    int *dst = *(int * volatile *)&o.p4; // haelt die Registerzuteilung fuer o.p4 wie im Original
    dst[1] = p->i12;
    s2 = f_0bf7b0((int)d_1c2c64, 2, 0x17000012, 0, f_0429a0((struct hero *)(p->i12)), 0);
    d_1c21b4 = 0;
    if ((short)s2 > 0) {
        s3 = f_03d3d0(p->i12, 3, p->c4);
        if ((short)s3 > 0) {
            p->s0 = s2;
            p->s0 += d_1c042a;
            if (f_0429a0((struct hero *)(p->i12)) < p->s0) {
                p->s2 = p->s0 / 2;
                p->s0 = -2;
            } else {
                MSG(0x17000017);
                c = f_0428d0((struct hero *)(p->i12));
                s2 += c;
                f_043c70(p->i12, (short)(s2 & 0xffff)); // erzwingt movsx nach 16-Bit-Addition wie im Original
            }
        } else {
            short h = s2 / 2;
            p->s0 = -2;
            p->s2 = h;
        }
    } else {
        p->s0 = -4;
    }
    DTOR;
}
//@ f_10e000
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den Zauberspruch mit Index 4 wahlweise im taktischen Kampf (d_1bd90c == 1) gegen das Zielwesen
 *   p->i1a (f_0cfdd0) oder außerhalb des Kampfes auf das aktive Interaktionsobjekt d_1bd6c0 (virtuelle Methoden
 *   f28 und f2c mit Kennung 4) aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
typedef short (*F28_2)(VOb *, int);
typedef void (*F2C_2)(VOb *, int);
void f_10e000(P *p)
{
    SO o;
    CTOR;
    int v0 = d_1bc88c; d_1bc88c = v0; // haelt die Register- und Stapelplatzfolge wie im Original
    if (d_1bd90c == 1 && p->i1a != 0) {
        o.p8[1] = p->i1a;
        o.p1c[1] = 1;
        if (f_0cff20(p->i1a)) {
            p->s0 = 2 * ((short)f_0cfcc0(p->i1a) - f_0428d0((struct hero *)(p->i12)));
            p->s0 += d_1c042a;
            if (p->s0 < 5)
                p->s0 = 5;
            if (f_0429a0((struct hero *)(p->i12)) < p->s0) {
                p->s0 = -2;
                p->s2 = f_0429a0((struct hero *)(p->i12));
            } else {
                f_0cfdd0(p->i1a, 1);
            }
        } else {
            MSG(0x17000013);
            p->s0 = -2;
            *(volatile short *)&p->s2 = 2; // verhindert Epilog-Verschmelzung vor DTOR wie im Original
            DTOR;
            return;
        }
    } else {
        if (d_1bd6c0 != 0 && (short)((F28_2)d_1bd6c0->vt->f28)(d_1bd6c0, 4) != 0) {
            VOb *q;
            VT *u;
            p->s0 = 5;
            f_10d5e0(4, ((unsigned char)(f_042380((struct hero *)(p->i12)))));
            f_10d640(4);
            q = d_1bd6c0;
            u = q->vt;
            ((F2C_2)u->f2c)(q, (d_1c0424 = 1, 4));
            d_1c0424 = 1;
        } else {
            MSG(0x17000111);
            p->s0 = 0;
        }
    }
    DTOR;
}
//@ f_10e1a0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Hebt bei einem Gruppenmitglied (p->i16) eine bestehende Verwandlung (f_0424e0 / f_0424f0) oder
 *   Attributsveränderung (f_042700 / f_042710 über alle sieben Grundattribute) auf bzw. setzt im Sonderkontext
 *   d_1c0428 == 6 das Flag d_1c0900.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e1a0(P *p)
{
    struct LocalSO494:SO { void actor(int v) { p4[1]=v; } } o;
    int i;
    CTOR;
    if (d_1c0428 != (short)0) goto other;
    o.actor(p->i16);
    if (((char)(f_0424e0((struct hero *)(p->i16))))) {
        p->s0 = f_1457e0(10) * 5;
        p->s0 += d_1c042a;
        if (f_0429a0((struct hero *)(p->i12)) < p->s0) {
            p->s0 = -2;
            p->s2 = f_0429a0((struct hero *)(p->i12));
        } else {
            f_0424f0((struct hero *)(p->i16), 0);
            MSG(0x17000014);
        }
    } else if (((char)(f_042700((struct hero *)(p->i16))))) {
        f_042710((struct hero *)(p->i16),0);
        d_1bc88c = 1;
        for (i = 0; (short)i <= 6; ++i)
            f_045430(p->i16, (short)i, 1);
        d_1bc88c = 0;
        MSG(0x17000011);
    } else {
        MSG(0x17000015);
        p->s0 = -4;
    }
    goto ende;
other:
    switch (d_1c0428) {
    case 6:
        if (f_0429a0((struct hero *)(p->i12)) >= 10) {
            p->s0 = 10;
            d_1c0900 = 1;
        } else {
            p->s0 = f_0429a0((struct hero *)(p->i12)) + 10;
            d_1c0900 = 0;
        }
        break;
    default:
        MSG(0x170000a4);
        p->s0 = -4;
        break;
    }
ende:
    DTOR;
}
//@ f_10e380  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Versetzt je nach Zieltyp (p->c5) entweder ein feindliches Kampfwesen (p->i1a, f_0cfed0) oder ein
 *   Gruppenmitglied (p->i16, f_042610) in den magischen Zustand des Zaubers und gibt die zugehörige Kampfmeldung
 *   (0x17000016 bzw. 0x1010008) aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e380(P *p)
{
    SO o;
    CTOR;
    if (p->c5 == 1 || p->c5 == 4) {
        o.p8[1] = p->i1a;
        o.p1c[1] = 1;
        if (f_0d0440(p->i1a)) {
            p->s0 = -2;
            MSG(0x170000a1);
        } else {
            f_0cfed0(p->i1a, 1);
            MSG(0x17000016);
        }
    } else {
        o.p4[1] = p->i16;
        f_042610((struct hero *)(p->i16), 1);
        MSG(0x1010008);
    }
    DTOR;
}
//@ f_10e440  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für das Zielwesen p->i1a, ob es gegen den Zauber immun ist (f_0d00c0, Meldung 0x17000018) oder
 *   bereits beeinflusst wurde (f_0d0440), und aktiviert andernfalls den Kampfzustand über f_0cff60(p->i1a, 1)
 *   mit Meldung 0x17000019.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e440(P *p)
{
    SO o;
    P *unused;
    CTOR;
    o.p8[1] = p->i1a;
    o.p1c[1] = 1;
    if (f_0d00c0(p->i1a)) {
        p->s0 = -4;
        MSG(0x17000018);
    } else {
        if (f_0d0440(p->i1a)) {
            p->s0 = -2;
            MSG(0x170000a1);
        } else {
            f_0cff60(p->i1a, 1);
            MSG(0x17000019);
        }
    }
    DTOR;
}
//@ f_10e4f0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt nach einer um den Gegnerwert f_0cfa70(p->i1a) modifizierten Zauberprobe auf Spruch 8 (f_03d3d0)
 *   die Kampfbeeinflussung (f_0cff90(p->i1a, 1) und f_0cfac0(p->i1a, 2)) auf das Zielwesen p->i1a aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e4f0(P *p)
{
    SO o;
    signed char c1;
    short s2;
    int p3;
    CTOR;
    o.p8[1] = p->i1a;
    o.p1c[1] = 1;
    if (f_0d0440(p->i1a)) {
        p->s0 = -2;
        MSG(0x170000a1);
    } else {
        c1 = f_0cfa70(p->i1a);
        s2 = f_03d3d0(p->i12, 8, (signed char)(c1 + p->c4));
        if (0 < s2) {
            f_0cff90(p->i1a, 1);
            f_0cfac0(p->i1a, 2);
            if (f_0773b0(d_1c0004) != 0) {
                p3 = 0x170000d6;
            } else {
                p3 = 0x1700001a;
            }
            MSG(p3);
            DTOR;
            return;
        }
        p->s0 = -2;
    }
    DTOR;
}
//@ f_10e5e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt außerhalb von Sonderkontexten (d_1c0428 == 0) je nach Zieltyp (p->c5) entweder beim Zielgegner
 *   p->i1a den Zustand f_0cffc0(p->i1a, 1) (0x1700010a) oder beim Gruppenmitglied p->i16 den Zustand
 *   f_042650(p->i16, 1) (0x170000b7).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e5e0(P *p)
{
    SO o;
    struct Store { void put(int *dst, int value) { dst[1] = value; } };
    Store store;
    signed char c;
    CTOR;
    if (d_1c0428 == (short)0) {
        if (p->c5 == 1 || p->c5 == 4) {
            store.put(o.p8, p->i1a);
            o.p1c[1] = 1;
            if (f_0d00c0(p->i1a)) {
                p->s0 = -4;
                MSG(0x17000018);
            } else {
                MSG(0x1700010a);
                f_0cffc0(p->i1a, 1);
            }
        } else {
            o.p4[1] = p->i16;
            MSG(0x170000b7);
            f_042650((struct hero *)(p->i16), 1);
        }
    }
    DTOR;
}
//@ f_10e6c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Senkt bei einem verwundbaren Zielwesen p->i1a (!f_0d0440) zwei Kampfwerte jeweils um 2 Punkte
 *   (f_0cfae0(p->i1a, -2) und f_0cfb10(p->i1a, -2)) und gibt die Meldung 0x1700009b aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e6c0(P *p)
{
    SO o;
    int r;
    CTOR;
    if (f_0d0440(p->i1a)) {
        p->s0 = -2;
        MSG(0x1700009a);
    } else {
        o.p8[1] = p->i1a;
        o.p1c[1] = 1;
        MSG(0x1700009b);
        f_0cfae0(p->i1a, -2);
        f_0cfb10(p->i1a, -2);
    }
    DTOR;
}
//@ f_10e760  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft, ob das Zielwesen p->i1a der passenden Wesenskategorie angehört (f_0d00c0), berechnet die vom
 *   Gegnerwert f_0cfa90 abhängigen Astralenergiekosten und aktiviert bei ausreichender Astralenergie den Zustand
 *   f_0cff60(p->i1a, 1) (0x17000019).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e760(P *p)
{
    SO o;
    signed char c;
    unsigned u;
    short s3;
    CTOR;
    o.p8[1] = p->i1a;
    o.p1c[1] = 1;
    if (!f_0d00c0(p->i1a)) {
        p->s0 = -4;
        MSG(0x1700001b);
    } else {
        u = f_0cfa90(p->i1a);
        p->s0 = (unsigned char)u;
        p->s0 = p->s0 + (short)d_1c042a;
        s3 = f_0429a0((struct hero *)(p->i12));
        if (s3 < p->s0) {
            p->s0 = -2;
            p->s2 = f_0429a0((struct hero *)(p->i12));
            goto L_x;
        }
        f_0cff60(p->i1a, 1);
        MSG(0x17000019);
    }
L_x:
    DTOR;
}
//@ f_10e830  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft am Zielgegner p->i1a die Bedingungen f_0d0440 und f_0cfc10, setzt bei Erfolg die Kampfzustände
 *   f_0cffc0(p->i1a, 1) sowie f_0cff90(p->i1a, 0) und gibt je nach Kampfumgebung die Meldung 0x170000d1 oder
 *   0x1700001c aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e830(P *p)
{
    SO o;
    int p3;
    CTOR;
    if (f_0d0440(p->i1a)) {
        p->s0 = -2;
        MSG(0x170000a1);
    } else {
        if (f_0cfc10(p->i1a)) {
            p->s0 = -2;
            MSG(0x17000033);
        } else {
            f_0cffc0(p->i1a, 1);
            f_0cff90(p->i1a, 0);
            o.p8[1] = p->i1a;
            o.p1c[1] = 1;
            if (f_0773b0(d_1c0004)) {
                p3 = 0x170000d1;
            } else {
                p3 = 0x1700001c;
            }
            MSG(p3);
        }
    }
    DTOR;
}
//@ f_10e900
/* === Beschreibung (Katalog) ===
 * - Zweck: Überträgt Astralenergie von einem ausgewählten Gruppenmitglied (p->i16) auf den Zaubernden (p->i12),
 *   indem geprüft wird, ob mindestens 7 Astralpunkte übertragen werden können, die gewünschte Punktzahl per
 *   Dialog (0x170000a2) abgefragt und anschließend beim Spender abgezogen (f_044230) und beim Empfänger
 *   gutgeschrieben (f_0442b0) wird.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10e900(P *p)
{
    SO o;
    short r;
    short a, d;
    CTOR;
    r = 0;
    if ((short)f_0429a0((struct hero *)(p->i16)) < 7) {
        o.p4[1] = p->i16;
        MSG(0x17000105);
        p->s0 = -4;
    } else if (f_0429b0((struct hero *)(p->i12)) - f_0429a0((struct hero *)(p->i12)) < 7) {
        o.p4[1] = p->i12;
        MSG(0x17000107);
        p->s0 = -4;
    } else {
        a = f_0429a0((struct hero *)(p->i16));
        d = a;
        if (f_0429b0((struct hero *)(p->i12)) - f_0429a0((struct hero *)(p->i12)) < a)
            d = f_0429b0((struct hero *)(p->i12)) - f_0429a0((struct hero *)(p->i12));
        o.p4[1] = p->i12;
        o.p4[2] = p->i16;
        o.p14[1] = 7;
        o.p14[2] = d;
        r = f_0bf7b0((int)d_1c2c64, 2, 0x170000a2, 1, d, d);
        d_1c21b4 = 0;
    }
    if (r > 0) {
        f_044230(p->i16, r);
        f_0442b0(p->i12, r);
        o.p4[1] = p->i12;
        o.p4[2] = p->i16;
        o.p14[1] = r;
        MSG(0x17000106);
    } else {
        p->s0 = -4;
    }
    DTOR;
}
//@ f_10ea90  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt über f_039040 ein betroffenes Gruppenmitglied, liest dessen Zustandswert f_042400 aus und
 *   gibt die entsprechende Statusmeldung (0x170000fc + c) bzw. bei fehlendem Treffer 0x170000a3 aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10ea90(P *p)
{
    int t;
    signed char c;
    t = f_039040(d_1c0004);
    if (t != 0) {
        c = f_042400((struct hero *)(t));
        MSG(c + 0x170000fc);
        return;
    }
    if (d_1c0428 == (short)0) {
        MSG(0x170000a3);
        p->s0 = -4;
    }
}
//@ f_10eaf0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert je nach Zieltyp (p->c5) entweder beim Zielgegner p->i1a den Zustand f_0cfe00(p->i1a, 1)
 *   (0x1700001d) oder beim Gruppenmitglied p->i16 den Zustand f_030e20(p->i16, 1) (0x17000108).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10eaf0(P *p)
{
    SO o;
    CTOR;
    if (p->c5 == 1 || p->c5 == 4) {
        if (f_0d0440(p->i1a)) {
            p->s0 = -2;
            MSG(0x170000a1);
        } else {
            f_0cfe00(p->i1a, 1);
            o.p8[1] = p->i1a;
            o.p1c[1] = 1;
            MSG(0x1700001d);
        }
    } else {
        if (((char)(f_0424e0((struct hero *)(p->i16))))) {
            p->s0 = -2;
        } else {
            f_030e20(p->i16, 1);
            o.p4[1] = p->i16;
            MSG(0x17000108);
        }
    }
    DTOR;
}
//@ f_10ebc0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert beim Zielgegner p->i1a, sofern f_0d0440 nicht gesetzt ist, den Kampfzustand
 *   f_0cfff0(p->i1a, 1) und gibt die Meldung 0x1700001e aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10ebc0(P *p)
{
    SO o;
    CTOR;
    if (f_0d0440(p->i1a)) {
        p->s0 = -2;
        MSG(0x170000a1);
    } else {
        f_0cfff0(p->i1a, 1);
        o.p8[1] = p->i1a;
        o.p1c[1] = 1;
        MSG(0x1700001e);
    }
    DTOR;
}
//@ f_10ec50  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt die Beschwörungsroutine für Spruch 0x12 (13 bzw. 33 Astralpunkte) im Kampf durch, würfelt die
 *   Kontrollproben (f_03d3d0) und setzt bei Erfolg den Typ des herbeigerufenen Kampfbegleiters (d_1c041d = 4,
 *   0x11 oder 0x50) sowie dessen Gesinnungsflag (d_1c041f).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10ec50(P *p)
{
    SO o;
    short roll;
    short keep;
    signed char cv, sum;
    short s2;
    CTOR;
    keep = f_1457e0(2);
    roll = keep;
    f_042800((struct hero *)(p->i12), 0xd);
    int actor = p->i12;
    o.p4[1] = actor;
    s2 = f_0429a0((struct hero *)(actor));
    if ((int)s2 < 0xd) {
        MSG(0x17000083);
        p->s0 = -2;
        p->s2 = 0xd;
    } else {
        if (d_1bd924 == (short)0x14) {
            MSG(0x170000d8);
            p->s0 = -2;
            p->s2 = 0xd;
        } else {
            sum = p->c4;
            sum += 5;
            cv = roll;
            --cv;
            sum += cv;
            s2 = f_03d3d0(p->i12, 0x12, sum);
            if ((int)s2 > 0) {
                sum = p->c4;
                --sum;
                sum += cv;
                s2 = f_03d3d0(p->i12, 0x12, sum);
                if ((int)s2 > 0) {
                    p->s0 = 0x21;
                    s2 = f_0429a0((struct hero *)(p->i12));
                    if (s2 < p->s0) {
                        MSG(0x170000dd);
                        p->s0 = -2;
                        p->s2 = 0xd;
                    } else {
                        MSG(0x170000db);
                        d_1c041d = ((int)keep == 1) ? 4 : 0x11;
                        d_1c041f = 1;
                    }
                } else {
                    p->s0 = 0xd;
                    s2 = f_1457e0(6);
                    if ((int)s2 < 4) {
                        MSG(0x170000d9);
                        p->s0 = -2;
                        p->s2 = 0xd;
                    } else {
                        MSG(0x170000da);
                        d_1c041d = ((int)keep == 1) ? 4 : 0x11;
                        d_1c041f = 0;
                    }
                }
            } else {
                s2 = f_1457e0(6);
                if ((int)s2 < 5) {
                    MSG(0x170000d8);
                    p->s0 = -2;
                    p->s2 = 7;
                } else {
                    MSG(0x170000dc);
                    p->s0 = 0xd;
                    d_1c041d = 0x50;
                    d_1c041f = 0;
                }
            }
        }
    }
    DTOR;
}
//@ f_10eef0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft für einen situationsgebundenen Zauber, ob der Kontext d_1c0428 == 4 vorliegt, und bricht
 *   andernfalls mit der Meldung 0x170000a4 (p->s0 = -4) ab.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10eef0(P *p)
{
    switch (d_1c0428) {
    case 4:
        return;
    default:
        MSG(0x170000a4);
        p->s0 = -4;
        return;
    }
}
//@ f_10ef30  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Bricht bei normalem Standardkontext (d_1c0428 == 0) den Zauber mit der Hinweis- bzw. Fehlermeldung
 *   0x170000d7 (p->s0 = -4) ab.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10ef30(P *p)
{
    if (d_1c0428 == (short)0) {
        MSG(0x170000d7);
        p->s0 = -4;
    }
}
//@ f_10ef60  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt die Dämonenbeschwörung für Spruch 0x15 (13 bzw. 37 Astralpunkte) durch, prüft die Beschwörungs-
 *   und Beherrschungsproben, setzt bei Erfolg d_1c041d = 0x50 und zieht bei einem schweren Patzer (Würfel == 6)
 *   dem Zaubernden permanent 5 Punkte vom Talentwert 0x15 sowie 2..40 Lebenspunkte (f_0406d0) ab.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10ef60(P *p)
{
    struct ByteWork {
        static int plus6(signed char c) { c += 6; return c; }
        static signed char lowered(int actor) {
            short value = f_0430f0((struct hero *)(actor), 0x15);
            value -= 5;
            if ((int)value < -0x12) value = -0x12;
            return (signed char)value;
        }
    };
    SO o;
    short s;
    signed char sum;
    CTOR;
    f_042800((struct hero *)(p->i12), 0xd);
    int actor = p->i12;
    o.p4[1] = actor;
    s = f_0429a0((struct hero *)(actor));
    if ((int)s < 0xd) {
        MSG(0x17000083);
        p->s0 = -2;
        p->s2 = 0xd;
    } else {
        if (d_1bd924 == (short)0x14) {
            MSG(0x170000d8);
            p->s0 = -2;
            p->s2 = 0xd;
        } else {
            s = f_03d3d0(p->i12, 0x15, ByteWork::plus6(p->c4));
            if ((int)s > 0) {
                s = f_03d3d0(p->i12, 0x15, p->c4);
                if ((int)s > 0) {
                    p->s0 = 0x25;
                    s = f_0429a0((struct hero *)(p->i12));
                    if (s < p->s0) {
                        MSG(0x170000e2);
                        p->s0 = -2;
                        p->s2 = 0xd;
                    } else {
                        MSG(0x170000e0);
                        d_1c041d = 0x50;
                        d_1c041f = 1;
                    }
                } else {
                    p->s0 = 0xd;
                    s = f_1457e0(6);
                    if ((int)s < 4) {
                        MSG(0x170000de);
                        p->s0 = -2;
                        p->s2 = 0xd;
                    } else {
                        short kind = 0x50;
                        MSG(0x170000df);
                        d_1c041d = kind;
                        d_1c041f = 0;
                    }
                }
            } else {
                s = f_1457e0(6);
                if ((int)s < 4) {
                    MSG(0x170000d8);
                    p->s2 = 0xd;
                    p->s0 = -2;
                } else if ((int)s == 6) {
                    p->s2 = 0x1a;
                    p->s0 = -2;
                    f_043100((struct hero *)(p->i12), 0x15, ByteWork::lowered(p->i12));
                    short roll = f_145760(2, 0x28);
                    short limit = roll;
                    if (f_0429b0((struct hero *)(p->i12)) <= limit) {
                        roll = f_0429b0((struct hero *)(p->i12));
                        --roll;
                    }
                    f_0406d0(p->i12, (int)roll);
                    MSG(0x170000e8);
                } else {
                    MSG(0x170000e1);
                    p->s0 = 0xd;
                    d_1c041d = 0x50;
                    d_1c041f = 0;
                }
            }
        }
    }
    DTOR;
}
//@ f_10f250  groesse 11568 B, 53 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Zweck: Ermittelt für Stufe + 2 Versuche (f_0428d0 + 2) mittels 1W20-Würfen gegen den Schwellenwert
 *   f_10cde0(p1) die Anzahl der herbeigerufenen Tiere/Treffer (s4), gibt die Meldung 0x170000b8 aus und wendet
 *   den Effekt über f_10ccf0(p1, s4) an.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f250(int p1)
{
    SO o;
    int s2, s4;
    short s5, s6;
    CTOR;
    s6 = (signed char)f_0428d0((struct hero *)(*(int *)(p1 + 0x12)));
    s2 = ((int (*)(int))f_10cde0)(p1);
    s6 += 2;
    o.p14[1] = s6;
    s4 = 1;
    MSG(0x170000b8);
    s5 = 0;
    for (s5 = 0; s5 < s6; s5++) {
            if ((int)(short)f_1457e0(0x14) <= 8 && (short)f_1457e0(0x14) > (short)s2)
                s4++;
    }
    f_10ccf0(p1, (short)s4);
    DTOR;
}
//@ f_10f300  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft außerhalb des Sonderkontexts d_1c0428 == 4, ob das Zielwesen p->i1a ein Untoter/Geist ist
 *   (f_0cfdc0), und bereitet bei Erfolg dessen Bannung bzw. Übernahme (d_1c041d = 0x10, d_1c041f = 1, Meldung
 *   0x17000020) vor.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f300(P *p)
{
    SO o;
    short state;
    CTOR;
    state = d_1c0428;
    switch (state) {
    case 4:
        break;
    default:
        o.p8[1] = p->i1a;
        o.p1c[1] = 1;
        f_042800((struct hero *)(p->i12), 0xd);
        if (!f_0cfdc0(p->i1a)) {
            MSG(0x1700001f);
            p->s0 = -4;
        } else {
            MSG(0x17000020);
            d_1c041d = 0x10;
            d_1c041f = 1;
        }
    }
    DTOR;
}
//@ f_10f3d0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den Beschwörungszauber 0x18 (Mindest-AE 13, Effektkosten 18 AE) aus und setzt nach bestandener
 *   Probe (f_03d3d0 mit Erschwernis p->c4 + 2) die Beschwörungskennung d_1c041d = 0x52 und d_1c041f = 1
 *   (0x170000e4).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f3d0(P *p)
{
    SO o;
    int t;
    short s1;
    CTOR;
    f_042800((struct hero *)(p->i12), 0xd);
    o.p4[1] = p->i12;
    s1 = f_0429a0((struct hero *)(p->i12));
    if (s1 < 0xd) {
        MSG(0x17000083);
        p->s0 = -2;
        p->s2 = 0xd;
        goto L_z;
    } else {
        if (d_1bd924 != (short)0x14) {
            s1 = f_03d3d0(p->i12, 0x18, (signed char)(p->c4 + 2));
            if (0 < s1) {
                p->s0 = 0x12;
                s1 = f_0429a0((struct hero *)(p->i12));
                if (s1 < p->s0) {
                    MSG(0x170000e7);
                    p->s0 = -2;
                    p->s2 = 0xd;
                    goto L_z;
                }
                MSG(0x170000e4);
                d_1c041d = 0x52;
                d_1c041f = 1;
                goto L_z;
            }
        }
        MSG(0x170000e3);
        p->s0 = -2;
        p->s2 = 0xd;
        goto L_z;
    }
L_z:
    DTOR;
}
//@ f_10f4c0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt für Spruch 0x19 über den Zahlendialog 0x170000a5 die gewünschte Wirkungsstärke (s2, bis zu
 *   max(AE / 5, Stufe)) ab, prüft die Zauberprobe und speichert bei Erfolg die Stärke in d_1c0416 bei Kosten von
 *   s2 * 5 + d_1c042a Astralpunkten (0x170000b9).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f4c0(P *p)
{
    SO o;
    int n;
    short s2;
    CTOR;
    if (f_0429a0((struct hero *)(p->i12)) / 5 > f_0428d0((struct hero *)(p->i12))) {
        n = f_0429a0((struct hero *)(p->i12)) / 5;
    } else {
        n = f_0428d0((struct hero *)(p->i12));
    }
    o.p4[1] = p->i12;
    o.p14[1] = n;
    if ((short)n < 10) s2 = f_0bf7b0((int)d_1c2c64, 1, 0x170000a5, 0, (short)n, 0); else s2 = f_0bf7b0((int)d_1c2c64, 2, 0x170000a5, 0, (short)n, 0);
    d_1c21b4 = 0;
    if (s2 > 0) {
        if (f_03d3d0(p->i12, 0x19, p->c4) > 0) {
            short v = s2 * 5;
            p->s0 = v;
            p->s0 = p->s0 + (short)d_1c042a;
            o.p14[1] = s2 * 2;
            MSG(0x170000b9);
            d_1c0416 = (char)s2;
        } else {
            p->s0 = -2;
            p->s2 = (s2 * 5) / 2;
        }
    } else {
        p->s0 = -4;
    }
    switch (d_1c0428) {
    default:
        break;
    case 5:
        d_1c21b4 = 0;
        break;
    }
    DTOR;
}
//@ f_10f630  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Fragt für Spruch 0x1a über den Zahlendialog 0x170000a6 die gewünschte Punktzahl (r, bis zu AE / 2)
 *   für den Zielhelden p->i16 ab, legt eine Zauberprobe ab und trägt bei Erfolg die Stärke in d_1c0416 bei
 *   Kosten von r * 2 + d_1c042a Astralpunkten (0x170000ba) ein.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f630(P *p)
{
    SO o;
    short s1, s2, r;
    CTOR;
    s1 = f_0429a0((struct hero *)(p->i12));
    s1 = s1 / 2;
    o.p4[1] = p->i16;
    o.p14[1] = s1;
    if (s1 < 10) {
        r = f_0bf7b0((int)d_1c2c64, 1, 0x170000a6, 0, s1, 0);
    } else {
        r = f_0bf7b0((int)d_1c2c64, 2, 0x170000a6, 0, s1, 0);
    }
    d_1c21b4 = 0;
    if (r > 0) {
        s2 = f_03d3d0(p->i12, 0x1a, p->c4);
        if (s2 > 0) {
            p->s0 = r * 2;
            p->s0 = p->s0 + (short)d_1c042a;
            o.p14[1] = r;
            MSG(0x170000ba);
            d_1c0416 = (char)r;
        } else {
            p->s0 = -2;
            p->s2 = r;
        }
    } else {
        p->s0 = -4;
    }
    switch (d_1c0428) {
    default: break;
    case 5: *(volatile char *)&d_1c21b4 = 0; DTOR; return; // verhindert Epilog-Verschmelzung in case 5 wie im Original
    }
    DTOR;
}
//@ f_10f770  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert beim Programmstart die beiden persistenten Zauber-Zustandsvariablen d_1c0904 (Kennung
 *   0x158) und d_1c0908 (Kennung 0x22f) in der globalen Spielstands-Tabelle (d_1c212a/d_1c212c).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f770(void)
{
    struct Obj { signed char a; short b; };
    struct Reg { short count; Obj **list; };
    Obj &a = *(Obj *)&d_1c0904;
    Obj &b = *(Obj *)&d_1c0908;
    Reg &r = *(Reg *)&d_1c212a;
    signed char c = 0;
    a.a = c;
    a.b = 0x158;
    int i = r.count;
    ((Obj ** &)d_1c212c)[i] = &a;
    signed char z = 0;
    b.a = z;
    b.b = 0x22f;
    r.count++;
    ((Obj ** &)r.list)[r.count] = &b;
    r.count++;
}
//@ f_10f7e0  ?
/* === Beschreibung (Katalog) ===
 * - Zweck: Verleiht einem ausgewählten Gruppenmitglied (p->i16), sofern dieses noch nicht unter dem Effekt steht
 *   (!f_0427e0), drei temporäre Kampf-Modifikatoren für 90 Zeiteinheiten (f_0d5040 für die Werte 2, 3 und 7),
 *   verdoppelt gegebenenfalls dessen Aktionsstatus (f_0433f0(p->i16, 2)) und gibt die Meldung 0x17000021 aus.
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f7e0(P *p)
{
    SO o;
    int t;
    short c;
    short s2;
    CTOR;
    t = p->i16;
    o.p4[1] = t;
    if (!((char)(f_0427e0((struct hero *)(t))))) {
        s2 = f_0d4c80(p->i16);
        f_0d5040(p->i16, s2, 0x5a, ((signed char)(f_043120((struct hero *)(p->i16)))), 2, 2);
        s2 = f_0d4c80(p->i16);
        f_0d5040(p->i16, s2, 0x5a, ((signed char)(f_043120((struct hero *)(p->i16)))), 2, 3);
        s2 = f_0d4c80(p->i16);
        f_0d5040(p->i16, s2, 0x5a, 0, 1, 7);
        c = f_0433e0(p->i16);
        if (c == (signed char)1) {
            c = f_045300(p->i16);
            f_043420(p->i16, c);
            f_0433f0(p->i16, 2);
        }
        MSG(0x17000021);
        DTOR;
        return;
    }
    MSG(0x170000bb);
    *(volatile short *)&p->s0 = -4; // haelt die Epilogform fuer den Nachfolger f_10f910 wie im Original
    DTOR;
}

// ---- f_10f910 (bisher erste Funktion von spell3_t1): gleiches Originalmodul wie f_10f7e0.
// Ihr Ruecksprungblock wird beim Einreihen auf den identischen Epilog der Vorfunktion gelegt und beim
// Ausgeben in alle fuenf Ausgaenge kopiert (Beleg: Analyse/Pass2/codex/astra_48h/F2_2357/BEFUND.md).
int f_0bf730(int p1, int p2);
int f_112df0(int p1, int p2, int p3, int p4);
int f_112e70(int p1, int p2);
int f_112ec0(int p1);
extern const char d_1a7858[];
struct S14 {int a[5];};
//@ f_10f910
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den situationsabhängigen Zauber 0x1c für die Kontexte d_1c0428 == 1 (6 AE, Meldung
 *   0x1700000b) und d_1c0428 == 3 (60 AE, löst das Dungeon-Ereignis 99 über f_112df0/f_112ec0 mit Meldung
 *   0x17000006 aus).
 * - Eingaben: Die Funktion erhält im Parameter p einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_10f910(P *p)
{
    SO o;
    unsigned short mode; unsigned char b; short s; int q; int t;
    CTOR;
    mode = d_1c0428;
    p->s0 = 6;
    switch (mode) {
    case 1: {
#if !FIX_R041
        d_1c0424 = 1;
#endif
        b = ((unsigned char)(f_042380((struct hero *)(p->i12))));
        f_10d5e0(0x1c, b);
        f_10d640(0x1c);
        s = f_03d3d0(p->i12, 0x1c, p->c4);
#if FIX_R041
        if (0 < s && f_0429a0((struct hero *)(p->i12)) >= p->s0) { d_1c0424 = 1; o.p4[1] = p->i12; f_0bf730((int)d_1c2c64, 0x1700000b); DTOR; return; }
#else
        if (0 < s) { o.p4[1] = p->i12; f_0bf730((int)d_1c2c64, 0x1700000b); DTOR; return; }
#endif
        else {
fail:
            p->s2 = 5;
            *(volatile short *)&p->s0 = -2; // verhindert Epilog-Verschmelzung vor DTOR wie im Original
            DTOR; return;
        }
    }
    case 3:
#if !FIX_R041
        d_1c0424 = 1;
#endif
        b = ((unsigned char)(f_042380((struct hero *)(p->i12))));
        f_10d5e0(0x1c, b);
        s = f_03d3d0(p->i12, 0x1c, p->c4);
        if (s <= 0) goto fail;
        f_10d640(0x1c);
        o.p4[1] = p->i12;
        s = f_0429a0((struct hero *)(p->i12));
        if (s >= 0x3c) {
#if FIX_R041
            d_1c0424 = 1;
#endif
            f_0bf730((int)d_1c2c64, 0x17000006);
            p->s0 = 0x3c;
            t = (int)new (mark(d_1a7858, 0x94)) S14;
            q = (t != 0) ? f_112df0(t, 99, 0, 0) : t;
            f_112ec0(q);
            if (q) operator delete((void*)f_112e70(q, 0));
            *(volatile signed char*)&d_1c21b4 = 0; // verhindert Epilog-Verschmelzung vor DTOR wie im Original
            DTOR; return;
        }
        f_0bf730((int)d_1c2c64, 0x17000005);
        *(volatile short *)&p->s0 = f_0429a0((struct hero *)(p->i12)); // verhindert Epilog-Verschmelzung vor DTOR wie im Original
        DTOR; return;
    default:
        p->s0 = -4;
        MSG(0x170000f2);
        DTOR; return;
    }
}
