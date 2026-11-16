/* === Beschreibung (Katalog) ===
 * Einheit gz_12e960 (0x12E960-0x12EDF0)
 *
 * Diese Einheit bildet das Bindeglied zwischen der zweiten (tower2.cpp) und der dritten Ebene (tower3.cpp) des
 * Magierturms. Sie enthält Abschluss- und Ebenenwechsel-Routinen für Turmebene 2 sowie die
 * Spielstands-Registrierung und den Konstruktor des Dungeon-Steuerobjekts für die dritte Ebene des Magierturms
 * (0x15 = 21).
 === Ende Beschreibung === */
// P3 5/7 gleich (suche.py 25.10.2026, Basis gz_12e960_P1.CPP)
// OPT -4r -oneatxu -zp1 -s
// P1 3/7 gleich (von Hand: f_12e960 f_12ea30 f_12edd0)
// gz_12e960.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x12E960-0x12EDF0
#include <string.h>
#pragma inline_depth(0)
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_05ff60(int p1, int p2);                       // nicht in clobber.tsv
int f_060030(int p1, int p2);                           // reg eax stapel 0
int f_060100(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060740(int p1, int p2);           // reg eax stapel 0
short f_060760(int p1);                                   // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_11f920(int p1);                                   // reg eax stapel 0
extern int d_1bd91c;
extern signed char d_1c0cf8;
extern char d_1bbb80[];
extern char d_1bbbd8[];
int f_145234(int p1, int p2);
void f_145254(void);
extern short d_1c212a;
extern int *d_1c212c;
extern unsigned char d_1c0d4c;
extern short d_1c0d4d;
extern unsigned char d_1c0d50;
extern short d_1c0d51;
extern unsigned char d_1c0d54;
extern short d_1c0d55;
extern unsigned char d_1c0d58;
extern short d_1c0d59;
extern unsigned char d_1c0d5c;
extern short d_1c0d5d;
extern unsigned char d_1c0d60;
extern short d_1c0d61;
extern unsigned char d_1c0d64;
extern short d_1c0d65;
extern unsigned char d_1c0d68;
extern short d_1c0d69;
extern unsigned char d_1c0d6c;
extern short d_1c0d6d;
extern unsigned char d_1c0d70;
extern short d_1c0d71;
extern unsigned char d_1c0d74;
extern short d_1c0d75;
extern unsigned char d_1c0d78;
extern short d_1c0d79;
extern unsigned char d_1c0d7c;
extern short d_1c0d7d;
extern unsigned char d_1c0d80;
extern short d_1c0d81;
extern unsigned char d_1c0d84;
extern short d_1c0d85;
extern unsigned char d_1c0d88;
extern short d_1c0d89;
extern unsigned char d_1c0d8c;
extern short d_1c0d8d;
extern unsigned char d_1c0d90;
extern short d_1c0d91;
extern unsigned char d_1c0d94;
extern short d_1c0d95;

//@ f_12ea70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Registriert 19 ein-Byte-Zustandsflags (0xe9 bis 0x23c, Adressen d_1c0d4c bis d_1c0d94) der
 *   dritten Ebene des Magierturms im globalen Byte-Spielstandsregister (d_1c212a) und initialisiert ihre Werte
 *   mit 0.
 * - Eingaben: Keine Parameter.
 * - Rückgabe: Keine (void).
 * - Wichtige Variablen: Globale Ereignis- und Rätselflags d_1c0d4c..d_1c0d94 der dritten Turmebene.
 === Ende Beschreibung === */
#define RIVA_REG_FIRST(OBJ, IDFIELD, ID) \
    do { (OBJ) = 0; (IDFIELD) = (ID); \
         ((int *&)d_1c212c)[(short &)d_1c212a] = (int)&(OBJ); } while (0)
#define RIVA_REG_NEXT(OBJ, IDFIELD, ID) \
    do { (OBJ) = 0; (IDFIELD) = (ID); \
         ((int *&)d_1c212c)[++d_1c212a] = (int)&(OBJ); } while (0)
#pragma inline_depth(3)
struct RR700V3_12ea708;
struct OR700V3_12ea708 { signed char flag; short number; char pad; OR700V3_12ea708 *init(RR700V3_12ea708 &r,short id,signed char f); };
struct RR700V3_12ea708 { short count; OR700V3_12ea708 **list; void append(OR700V3_12ea708 *o) {list[count]=o;count++;} };
inline OR700V3_12ea708 *OR700V3_12ea708::init(RR700V3_12ea708 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_12ea708 regR700V3_12ea708;
#pragma aux regR700V3_12ea708 "d_1c212a"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d4c;
#pragma aux obR700V3_12ea70_1c0d4c "d_1c0d4c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d50;
#pragma aux obR700V3_12ea70_1c0d50 "d_1c0d50"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d54;
#pragma aux obR700V3_12ea70_1c0d54 "d_1c0d54"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d58;
#pragma aux obR700V3_12ea70_1c0d58 "d_1c0d58"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d5c;
#pragma aux obR700V3_12ea70_1c0d5c "d_1c0d5c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d60;
#pragma aux obR700V3_12ea70_1c0d60 "d_1c0d60"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d64;
#pragma aux obR700V3_12ea70_1c0d64 "d_1c0d64"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d68;
#pragma aux obR700V3_12ea70_1c0d68 "d_1c0d68"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d6c;
#pragma aux obR700V3_12ea70_1c0d6c "d_1c0d6c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d70;
#pragma aux obR700V3_12ea70_1c0d70 "d_1c0d70"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d74;
#pragma aux obR700V3_12ea70_1c0d74 "d_1c0d74"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d78;
#pragma aux obR700V3_12ea70_1c0d78 "d_1c0d78"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d7c;
#pragma aux obR700V3_12ea70_1c0d7c "d_1c0d7c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d80;
#pragma aux obR700V3_12ea70_1c0d80 "d_1c0d80"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d84;
#pragma aux obR700V3_12ea70_1c0d84 "d_1c0d84"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d88;
#pragma aux obR700V3_12ea70_1c0d88 "d_1c0d88"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d8c;
#pragma aux obR700V3_12ea70_1c0d8c "d_1c0d8c"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d90;
#pragma aux obR700V3_12ea70_1c0d90 "d_1c0d90"
extern OR700V3_12ea708 obR700V3_12ea70_1c0d94;
#pragma aux obR700V3_12ea70_1c0d94 "d_1c0d94"
void f_12ea70(void) {
obR700V3_12ea70_1c0d4c.init(regR700V3_12ea708,0xe9,0);
obR700V3_12ea70_1c0d50.init(regR700V3_12ea708,0xea,0);
obR700V3_12ea70_1c0d54.init(regR700V3_12ea708,0xeb,0);
obR700V3_12ea70_1c0d58.init(regR700V3_12ea708,0xec,0);
obR700V3_12ea70_1c0d5c.init(regR700V3_12ea708,0xed,0);
obR700V3_12ea70_1c0d60.init(regR700V3_12ea708,0x15a,0);
obR700V3_12ea70_1c0d64.init(regR700V3_12ea708,0xef,0);
obR700V3_12ea70_1c0d68.init(regR700V3_12ea708,0xf0,0);
obR700V3_12ea70_1c0d6c.init(regR700V3_12ea708,0x14f,0);
obR700V3_12ea70_1c0d70.init(regR700V3_12ea708,0x159,0);
obR700V3_12ea70_1c0d74.init(regR700V3_12ea708,0x222,0);
obR700V3_12ea70_1c0d78.init(regR700V3_12ea708,0x22b,0);
obR700V3_12ea70_1c0d7c.init(regR700V3_12ea708,0x14c,0);
obR700V3_12ea70_1c0d80.init(regR700V3_12ea708,0x14d,0);
obR700V3_12ea70_1c0d84.init(regR700V3_12ea708,0x14e,0);
obR700V3_12ea70_1c0d88.init(regR700V3_12ea708,0x22e,0);
obR700V3_12ea70_1c0d8c.init(regR700V3_12ea708,0x230,0);
obR700V3_12ea70_1c0d90.init(regR700V3_12ea708,0x231,0);
obR700V3_12ea70_1c0d94.init(regR700V3_12ea708,0x23c,0);
}

#pragma inline_depth(0)

#undef RIVA_REG_FIRST
#undef RIVA_REG_NEXT

//@ f_12edd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor des Dungeon-Steuerobjekts für die dritte Ebene des Magierturms (tower3); ruft
 *   den Basiskonstruktor f_05ff60 mit der Ebenen-Kennung 0x15 (21) auf und trägt die virtuelle Methodentabelle
 *   d_1bbbd8 ein.
 * - Eingaben: p1 (this-Zeiger auf das anzulegende Dungeon-Steuerobjekt).
 * - Rückgabe: Keine (void bzw. initialisiertes Objekt).
 * - Wichtige Variablen: r (Zeiger auf das initialisierte Objekt, an dessen Offset +8 der vtable-Zeiger d_1bbbd8
 *   geschrieben wird).
 === Ende Beschreibung === */
void f_12edd0(int p1)
{
    int r = f_05ff60(p1, 0x15);
    *(int *)(r + 8) = (int)d_1bbbd8;
}

#pragma inline_depth(3)
