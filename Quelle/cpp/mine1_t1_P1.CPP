/* === Beschreibung (Katalog) ===
 * Einheit mine1_t1 (Adresse 0x0c0e30 - 0x0c2f40)
 *
 * Diese Einheit bildet den ersten Teil des 3D-Dungeon-Moduls für die erste Ebene der Zwergenmine
 * (p:\riva\source\cpp\mine1.cpp). Sie enthält den großen zentralen Ereignis-Dispatcher f_0c0e30, der sämtliche
 * Interaktionspunkte, Rätsel, Truhen, Spinde und Übergänge dieser Minenebene verzweigt, sowie die ersten
 * Einzel-Ereignishandler (f_0c2a60 bis f_0c2f00).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 9/12 gleich (suche.py 25.10.2026, Basis mine1_t1_P1.CPP)
// OPT -4r -onetx -zp1 -s
// P1 6/12 gleich
// mine1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C0E30-0x0C5D80
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_0366e0(int p1, int p2, int p3, int p4);
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
short f_0398c0(int p1, int p2, int p3);
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039c50(int p1, int p2);                           // reg edx stapel 0
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0

                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_043ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044090(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044890(int p1, int p2);                           // reg eax edx stapel 0
short f_044900(int p1, int p2, int p3);
#pragma aux f_044900 modify exact [eax ebx ecx edx];
short f_044c90(int p1, int p2, int p3);
int f_045170(int p1, int p2);                           // reg eax edx stapel 0
int f_046d10(int p1, int p2);                           // reg eax edx stapel 0
void *f_046d90(int p1, int p2);
int f_046de0(int p1);                                   // reg eax stapel 0
int f_047120(int p1);                                   // reg eax stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(void *p1, int p2, int p3);
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060a70();                                         // reg - stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
short f_0bf820();
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
short f_0dcf00(int p1, int p2, int p3);
int f_0dd100(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
void *f_112e70(int p1, int p2);
int f_112ec0(int p1);                                   // reg eax stapel 0
unsigned f_1131b0(int p1);                                   // reg eax stapel 0
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(void *p1, int p2);
int f_125f70(void *p1, int p2);
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_134840(void *p1, int p2, int p3, int p4, int p5, int p6);
int f_1348d0();                                         // reg - stapel 0
int f_135040(void *p1);
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
short f_1457e0(int p1);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a5600;                    // 0x1A5600
extern int d_1a5604;                    // 0x1A5604
extern int d_1a5606;                    // 0x1A5606
extern int d_1a5680;                    // 0x1A5680
extern const int d_1a9820;                    // 0x1A9820
extern int d_1bd6c8;                    // 0x1BD6C8
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1bd922;                    // 0x1BD922
extern int d_1bf230;                    // 0x1BF230
extern signed char d_1bf24c;
extern signed char d_1bf250;
extern int d_1bf254;                    // 0x1BF254
extern signed char d_1bf258;
extern int d_1bf25c;                    // 0x1BF25C
extern int d_1bf260;                    // 0x1BF260
extern int d_1bf264;                    // 0x1BF264
extern int d_1bf268;                    // 0x1BF268
extern signed char d_1bf26c;
extern signed char d_1bf270;
extern signed char d_1bf274;
extern signed char d_1bf278;
extern int d_1bf27c;                    // 0x1BF27C
extern int d_1bf280;                    // 0x1BF280
extern signed char d_1bf284;
extern signed char d_1bf288;
extern int d_1bf28c;                    // 0x1BF28C
extern signed char d_1bf294;
extern int d_1bf298;                    // 0x1BF298
extern signed char d_1bf29c;
extern int d_1bf2a0;                    // 0x1BF2A0
extern int d_1bf2a4;                    // 0x1BF2A4
extern signed char d_1bf2a8;
extern int d_1bf2ac;                    // 0x1BF2AC
extern signed char d_1bf34c;
extern int d_1c0004;                    // 0x1C0004
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c00;                    // 0x1C2C00
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a5660[];           // Text 0x1A5660

int f_0c5ac0(int p1);
void f_0c42c0(); void f_0c4560(); void f_0c4ae0(int p1); void f_0c3b20(); void f_0c3470(); void f_0c3750(); void f_0c3db0(); void f_0c4080(); void f_0c5490(); void f_0c55d0(int p1); void f_0c5b70(int p1, int p2); void f_0c2f40(int p1);
void f_0c2a60(); void f_0c2ad0(); void f_0c2b00(); void f_0c2b30(); void f_0c2b60(int p1); void f_0c2bd0(); void f_0c2c00(); void f_0c2cc0(); void f_0c2e30(); void f_0c2e60(); int f_0c2f00(int p1);
typedef int (*PF)(int, int);
typedef short (*PF3)(int, int, int);
inline int EQ(int a, int b) { return a == b; }
inline int EQC(char a, char b) { return a == b; }
#define EQI(x,v) (((x)==(v))?1:0)
#pragma aux f_147323 modify [esp];
#define CTOR(b) f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498)
#define SETF(b, v) *(int *)(b[1] + 4) = (v)
#define MSG(n) f_0bf730(&d_1c2c64, n)
#define BODY_0c2a60 { if (f_0bf6f0(&d_1c2c64, 0x35000001) == 1) { if (EQC(d_1bf34c, 0) && EQI(d_1bf2a8, 0)) { f_057220(&d_1c2c00, 0x8030041, 0); d_1bf2a8 = 1; } f_0dd7f0(d_1c0004, 5, 0x1459); } }
#define BODY_0c2ad0 { MSG(0x35000002); f_125ed0(&d_1c2c44, 5); }
#define BODY_0c2b30 { MSG(0x35000003); f_125ed0(&d_1c2c44, 5); }
#define BODY_0c2b60 { if (EQ(d_1bf26c, 0)) { MSG(0x35000004); d_1bf26c = 1; } if (EQ(d_1bf26c, 1)) { if ((**(PF3 **)(p1 + 8))(p1, 0x36, 0) == 0) d_1bf26c = 2; } }
#define BODY_0c2bd0 { MSG(0x35000005); f_125ed0(&d_1c2c44, 5); }
#define BODY_0c2c00 { int bb[15]; int s; if (EQI(d_1bf24c, 0)) { s = f_039320(d_1c0004, 0x33); CTOR(bb); SETF(bb, s); MSG(0x35000006); if (f_0366e0(s, 0x1a4, 1, 1) <= 0) f_0dcf00(d_1c0004, 0x1a4, 1); d_1bf24c = 1; f_1254a0(bb, 0); } else { MSG(0x35000005); } f_125ed0(&d_1c2c44, 5); }
#define BODY_0c2e30 { MSG(0x3500000e); f_125ed0(&d_1c2c44, 10); }
#define BODY_0c2e60 { int q, q2; MSG(0x3500000e); q = (int)operator new(0x14, mark(d_1a5660, 0x274)); if (q) q = f_112df0(q, 0x15, 0, 0); q2 = q; if (f_1131b0(q) == 1) { MSG(0x3500000f); f_112ec0(q); f_125ed0(&d_1c2c44, 10); } if (q2) operator delete(f_112e70(q2, 0)); }
#define DOSW(MASK, LOC) { int uu = (MASK); short ss = f_0bf820(); switch (ss + 1) { case 2: f_0c5b70(p1, uu); return r; case 3: MSG(0x3500006e); f_125f70(&d_1c2c44, 5); if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)(LOC)) > 0) { MSG(0x3500006f); return r; } } }

//@ f_0c0e30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese zentrale Dispatch-Methode verarbeitet alle 3D-Ereigniskennungen m (0x65 bis 0x70b sowie 0x1f41)
 *   auf der ersten Ebene der Zwergenmine: Sie steuert den Ausgang ins Umland (0x65), Lore- und
 *   Schacht-Interaktionen (0x12d, 0x191-0x193), das Durchsuchen von elf verschiedenen Zwergenspinden und
 *   Quartieren (0x4b1 bis 0x642 über Z832_tuer), spezielle Begegnungen und Kämpfe (0xc9, 0x579) sowie den
 *   Übergang in die tiefere Minenebene (0x709-0x70b).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt sowie die 16-Bit-Ereigniskennung m
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Ereigniskennung verarbeitet wurde, oder 0 im
 *   Standardfall.
 === Ende Beschreibung === */
inline int mineEqB221(int a, signed char b) { int y=b; return a==y; }
short doorMenu493(int,int,short,int,int,int);
#pragma aux doorMenu493 "f_0bf820" parm caller [] value [ax] modify exact [eax]
#define DOOR493(MASK,LOC) { int uu=(MASK); short ss=doorMenu493((int)&d_1c2c64,0x35000065,3,0x35000066,0x35000067,0x35000068); switch((unsigned short)(ss+1)) { case 0:return r;case 1:return r;case 4:return r; case 2: f_0c5b70(p1,uu); return r; case 3: MSG(0x3500006e); f_125f70(&d_1c2c44,5); if(f_0398c0(d_1c0004,(int)f_0c5ac0,(int)(LOC))>0){MSG(0x3500006f);return r;} break;default:return r; } }
void mineActor493_0c3470(int);
#pragma aux mineActor493_0c3470 "f_0c3470" parm [eax] modify exact [eax]
void mineActor493_0c3750(int);
#pragma aux mineActor493_0c3750 "f_0c3750" parm [eax] modify exact [eax]
void mineActor493_0c3b20(int);
#pragma aux mineActor493_0c3b20 "f_0c3b20" parm [eax] modify exact [eax]
void mineActor493_0c3db0(int);
#pragma aux mineActor493_0c3db0 "f_0c3db0" parm [eax] modify exact [eax]
void mineActor493_0c4080(int);
#pragma aux mineActor493_0c4080 "f_0c4080" parm [eax] modify exact [eax]
void mineActor493_0c42c0(int);
#pragma aux mineActor493_0c42c0 "f_0c42c0" parm [eax] modify exact [eax]
void mineActor493_0c4560(int);
#pragma aux mineActor493_0c4560 "f_0c4560" parm [eax] modify exact [eax]
void mineActor493_0c5490(int);
#pragma aux mineActor493_0c5490 "f_0c5490" parm [eax] modify exact [eax]
void mine147323_222(void*,int,short,short,int,short,unsigned short);
#pragma aux mine147323_222 "f_147323" modify [esp];
void mineDtor493(void*,int);
#pragma aux mineDtor493 "f_1348d0" parm [eax] [edx] modify exact []
// BLIND: f_0c0e30 hier komplett neu aus dem Original-Assembler schreiben (orig.sh mine1_t1 f_0c0e30).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
void z832_c2cc0(int);
#pragma aux z832_c2cc0 "f_0c2cc0" parm [eax] modify exact [eax]

inline int z832_eqc(int a, signed char b) { return a == b; }
inline int z832_eqEarly(int a, signed char b) {
    a |= a & 0; /* haelt die Registerzuteilung wie im Original */
    return a == b;
}
inline int eq1094(const signed char &a, signed char b) { return a == b; }
inline int z832_eqi(int a, int b) { return a == b; }
inline void z832_msg(int n) { f_0bf730(&d_1c2c64, n); }
inline int z832_ask(int n) { return f_0bf6f0(&d_1c2c64, n); }
inline void z832_ctor(int *b) { f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498); }
inline short z832_virt(int p, int a) { return (**(PF3 **)(p + 8))(p, a, 0); }

inline void z832_c065()
{
  if (z832_ask(0x35000001) == 1) {
    if (z832_eqc(d_1bf34c, 0) && z832_eqi(d_1bf2a8, 0)) {
      f_057220(&d_1c2c00, 0x8030041, 0);
      d_1bf2a8 = 1;
    }
    f_0dd7f0(d_1c0004, 5, 0x1459);
  }
}
inline void z832_c066() { z832_msg(0x35000002); f_125ed0(&d_1c2c44, 5); }
inline void z832_c067() { z832_msg(0x35000002); f_125ed0(&d_1c2c44, 5); }
inline void z832_c068() { z832_msg(0x35000003); f_125ed0(&d_1c2c44, 5); }
inline void z832_c0c9(int p)
{
  if (z832_eqEarly(d_1bf26c, 0)) {
    z832_msg(0x35000004);
    d_1bf26c = 1;
  }
  if (z832_eqi(d_1bf26c, 1)) {
    if (z832_virt(p, 0x36) == 0) d_1bf26c = 2;
  }
}
inline void z832_c0ca() { z832_msg(0x35000005); f_125ed0(&d_1c2c44, 5); }
#define Z832_c0cb(b) {\
  if (eq1094(d_1bf24c, 0)) {\
    int s = f_039320(d_1c0004, 0x33);\
    z832_ctor(b);\
    *(int *)(b[1] + 4) = s;\
    z832_msg(0x35000006);\
    if (f_0366e0(s, 0x1a4, 1, 1) <= 0) f_0dcf00(d_1c0004, 0x1a4, 1);\
    d_1bf24c = 1;\
    f_1254a0(b, 0);\
  } else {\
    z832_msg(0x35000005);\
  }\
  f_125ed0(&d_1c2c44, 5);\
}
inline void z832_c12e() { z832_msg(0x3500000e); f_125ed0(&d_1c2c44, 10); }
struct Item904 { struct f_112df0 { char body[20]; f_112df0(int,int=0,int=0); }; };
inline void z832_c12f()
{
  int q, q2;
  z832_msg(0x3500000e);
  q = (int)new(mark(d_1a5660, 0x274)) Item904::f_112df0(0x15);
  q2 = q;
  if (f_1131b0(q) == 1) {
    z832_msg(0x3500000f);
    f_112ec0(q);
    f_125ed0(&d_1c2c44, 10);
  }
  if (q2) operator delete(f_112e70(q2, 0));
}
#if FIX_R052
#define Z832_c192(A_p, b) {  int p = A_p; \
  if (z832_eqEarly(d_1bf274, 1) && z832_eqi(d_1bf250, 0)) {\
    int t = f_039ac0(d_1c0004, (int)f_0c2f00);\
    if (!t) t = f_038c40(d_1c0004);\
    if (t) {\
      z832_ctor(b);\
      *(int *)(b[1] + 4) = t;\
      z832_msg(0x35000015);\
      z832_msg(0x35000014);\
      z832_virt(p, 0x37);\
      f_0697c0(p + 2, 0x37, 0);\
      f_060740(0x191, 0);\
      d_1bf250 = 1;\
      d_1bf274 = 0;\
      f_1254a0(b, 0);\
    }\
  }\
}
#else
#define Z832_c192(A_p, b) {  int p = A_p; \
  if (z832_eqEarly(d_1bf274, 1) && z832_eqi(d_1bf250, 0)) {\
    int t = f_039ac0(d_1c0004, (int)f_0c2f00);\
    if (t) {\
      z832_ctor(b);\
      *(int *)(b[1] + 4) = t;\
      z832_msg(0x35000015);\
      z832_msg(0x35000014);\
      z832_virt(p, 0x37);\
      f_0697c0(p + 2, 0x37, 0);\
      f_060740(0x191, 0);\
      d_1bf250 = 1;\
      d_1bf274 = 0;\
      f_1254a0(b, 0);\
    }\
  }\
}
#endif
#define Z832_c193(A_p, b) {  int p = A_p; \
  if (z832_eqEarly(d_1bf250, 0) && z832_eqi(d_1bf274, 1)) {\
    z832_ctor(b);\
    *(int *)(b[1] + 4) = f_038c40(d_1c0004);\
    z832_msg(0x35000015);\
    z832_msg(0x35000014);\
    z832_virt(p, 0x37);\
    f_0697c0(p + 2, 0x37, 0);\
    f_060740(0x191, 0);\
    d_1bf250 = 1;\
    d_1bf274 = 0;\
    f_1254a0(b, 0);\
  }\
}
#define Z832_c1f5(b) {\
  if (z832_ask(0x35000016) == 1) {\
    int t = f_038d70(d_1c0004, 0x35000017);\
    if (t) {\
      int rtPlan0=d_1c0004; d_1c0004=rtPlan0; /* haelt die Stapelplatz-Reihenfolge wie im Original */ f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498);\
      *(int *)(b[1] + 4) = t;\
      z832_msg(0x35000018);\
      f_125ed0(&d_1c2c44, 5);\
      f_044090(t, 0x3f480, 2);\
      f_1254a0(b, 0);\
    }\
  }\
}
inline void z832_c1f7() { z832_msg(0x35000021); }
#define Z832_c1f8(b) {\
  f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498);\
  *(int *)(b[1] + 4) = f_039660(d_1c0004, 0xd);\
  z832_msg(0x35000022);\
  int rtPlan1=d_1c0004; d_1c0004=rtPlan1; /* haelt die Stapelplatz-Reihenfolge wie im Original */ z832_msg(0x35000023);\
  f_125f70(&d_1c2c44, 1);\
  f_1254a0(b, 0);\
}
inline void z832_c1f9() { z832_msg(0x35000022); }
inline void z832_c259() { z832_msg(0x35000025); z832_msg(0x35000026); f_125ed0(&d_1c2c44, 10); }
inline void z832_c25a()
{
  int q, q2;
  q = (int)new(mark(d_1a5660, 0x484)) Item904::f_112df0(0x17);
  q2 = q;
  if (f_1131b0(q) == 1) {
    z832_msg(0x35000027);
    f_112ec0(q);
  } else {
    z832_msg(0x35000025);
  }
  if (q2) operator delete(f_112e70(q2, 0));
  f_125ed0(&d_1c2c44, 5);
}
#define Z832_c2bd(b) {\
  f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498);\
  *(int *)(b[1] + 4) = f_039660(d_1c0004, 6);\
  if (z832_eqc(d_1bf278, 1)) {\
    *(int *)(b[4] + 4) = 0x20000194;\
  } else {\
    *(int *)(b[4] + 4) = 0x35000029;\
    /* haelt die Registerzuteilung wie im Original */ \
    int rate904 = (d_1a9820 & 0) ? 0 : d_1a9820; \
    f_147323(&d_1c2edc, 0x350031, 0x7fff, 0x8000, rate904, 0, 1);\
    f_0db820(d_1c0004, 0x22);\
    d_1bf278 = 1;\
  }\
  z832_msg(0x35000028);\
  f_125ed0(&d_1c2c44, 10);\
  f_1254a0(b, 0);\
}
inline void z832_c2be() { z832_msg(0x3500002a); }
int audioDefault904(void*,int,unsigned short=0x7fff,unsigned short=0x8000,int=d_1a9820,short=0,unsigned short=1);
#pragma aux audioDefault904 "f_147323" modify [esp];
inline void z832_c2bf()
{
  if (z832_ask(0x3500002b) == 1) {
    audioDefault904(&d_1c2edc, 0x350032);
    z832_msg(0x3500002c);
    f_0dbeb0(d_1c0004);
    f_0db9d0(d_1c0004, 2, 5);
  }
}
inline void z832_c321() { z832_msg(0x3500002d); f_125ed0(&d_1c2c44, 5); }
#define Z832_c322(b) {\
  int rtPlan2=d_1c0004; d_1c0004=rtPlan2; /* haelt die Stapelplatz-Reihenfolge wie im Original */ f_125400(b, &d_1c349c, &d_1c3870, &d_1c3498);\
  *(int *)(b[1] + 4) = f_0396f0(d_1c0004, 0xd);\
  z832_msg(0x3500002e);\
  f_1254a0(b, 0);\
}
struct Chest908 { Chest908 *f_046d10(int=0xb); int f_047120(); int f_046de0(); void *f_046d90(int); };
struct Chest904 { Chest904 *f_046d10(short=0xb); };
struct ChestMember1094 { struct f_046d10 {
  char body[12]; f_046d10(int=11);
  int f_047120(); int f_046de0(); void *f_046d90(int);
  void use() { if(f_047120()) f_046de0(); }
}; };
inline void z832_c323()
{
  ChestMember1094::f_046d10 *q=new(mark(d_1a5660,0x524)) ChestMember1094::f_046d10();
  q->use();
  if(q)operator delete(q->f_046d90(0));
}
#define Z832_c385(b) {\
  z832_msg(0x35000044);\
  if (z832_eqc(d_1bf258, 0)) {\
    d_1bf258 = 1;\
    z832_ctor(b);\
    *(int *)(b[1] + 4) = f_039320(d_1c0004, 0x16);\
    z832_msg(0x35000045);\
    f_0db820(d_1c0004, 0x1b1c);\
    f_125ed0(&d_1c2c44, 10);\
    f_1254a0(b, 0);\
  }\
}
#define Z832_c386(b, o) {\
int rtPlan3=d_1c0004; rtPlan3 |= rtPlan3 & 0; d_1c0004=rtPlan3; /* haelt die Registerzuteilung wie im Original */ \
  if (eq1094(d_1bf294, 0)) {\
    int s = f_039320(d_1c0004, 0x26);\
    z832_ctor(b);\
    *(int *)(b[1] + 4) = s;\
    z832_msg(0x35000046);\
    if (f_0dcf00(d_1c0004, 0x1d2, 1) > 0) {\
      f_134840(o, 0, 0, 0, 0x1d2, 0);\
      f_135040(o);\
      mineDtor493(o, 0);\
      d_1bf294 = 1;\
    }\
    f_1254a0(b, 0);\
  }\
}
#define Z832_c3ea(b) {\
  if (eq1094(d_1bf284, 0)) {\
    z832_ctor(b);\
    *(int *)(b[1] + 4) = f_039320(d_1c0004, 0x33);\
    z832_msg(0x35000056);\
    d_1bf284 = 1;\
    f_1254a0(b, 0);\
  } else {\
    z832_msg(0x35000057);\
  }\
}
inline void z832_c3eb() { z832_msg(0x35000058); }
inline void z832_c44d() { z832_msg(0x35000059); f_125ed0(&d_1c2c44, 10); }
inline void z832_c44e() { z832_msg(0x3500005a); }
#define Z832_tuer(A_p, A_maske, loc) {  int tuerActor904 = A_p;   int maske = A_maske; \
  short s = doorMenu493((int)&d_1c2c64, 0x35000065, 3, 0x35000066, 0x35000067, 0x35000068);\
  switch (s) {\
  case -1:\
  case 0:\
  case 3:\
    break;\
  case 1:\
    f_0c5b70(tuerActor904, maske);\
    break;\
  case 2:\
    z832_msg(0x3500006e);\
    f_125f70(&d_1c2c44, 5);\
    if (f_0398c0(d_1c0004, (int)f_0c5ac0, (int)loc) > 0) z832_msg(0x3500006f);\
    break;\
  }\
}
inline void z832_c4b3() { z832_msg(0x35000070); }
inline void z832_c517() { z832_msg(0x35000070); }
#define Z832_c57c(A_p, loc) {  int p = A_p; \
  if (z832_eqc(d_1bf288, 2)) z832_msg(0x3500007a);\
  else Z832_tuer(p, 0x20, loc);\
}
inline void z832_c57e() { z832_msg(0x3500007b); }
inline void z832_c57f()
{
  if (eq1094(d_1bf29c, 0)) {
    if (z832_ask(0x3500007c) == 1) {
      if (f_0dcf00(d_1c0004, 0x4d, 1) == 1) d_1bf29c = 1;
    }
  }
}
inline void z832_c5df() { z832_msg(0x3500007d); }
inline void z832_c643() { z832_msg(0x3500007e); }
inline void z832_c6a5() { z832_msg(0x3500007f); }
#define Z832_c6a6(b) {\
  z832_ctor(b);\
  *(int *)(b[1] + 4) = f_038c40(d_1c0004);\
  z832_msg(0x35000080);\
  f_1254a0(b, 0);\
}
#define Z832_c6a7(b) {\
  int s = f_038c40(d_1c0004);\
  z832_ctor(b);\
  *(int *)(b[1] + 4) = s;\
  z832_msg(0x35000081);\
  f_044090(s, 0x3f480, 5);\
  f_125ed0(&d_1c2c44, 10);\
  f_1254a0(b, 0);\
}
inline void z832_c6a8() { z832_msg(0x35000082); }
inline void z832_c70a() { if (z832_ask(0x35000092) == 1) f_060800(0x350004, 0, 0); }
inline void z832_c70b() { if (z832_ask(0x35000093) == 1) f_0dd7f0(d_1c0004, 0x10, 0x13a3); }

int f_0c0e30(int p1, unsigned short m)
{
#if FIX_R052
  int r = 1;
#else
  int r;
#endif
  struct Rahmen904 {
    int b3ea[15];
    int b193[15];
    int b385[15];
    int b1f5[15];
    int b1f8[15];
    int b2bd[15];
    int b192[15];
    int b322[15];
    int b6a6[15];
    int b6a7[15];
    int b0cb[15];
    int b386[15];
    int o386[8];
    char t2[28];
    char t1[28];
    char t8[28];
    char t100[28];
    char t4[28];
    char t200[28];
    char t20[28];
    char t80[28];
    char t0[28];
    char t40[28];
    char t10[28];
    char t400[28];
  } rahmen;
  switch (m) {
  case 0x65: z832_c065(); break;
  case 0x66: z832_c066(); break;
  case 0x67: z832_c067(); break;
  case 0x68: z832_c068(); break;
  case 0xc9: z832_c0c9(p1); break;
  case 0xcb: Z832_c0cb(rahmen.b0cb); break;
  case 0xca: z832_c0ca(); break;
  case 0x12d: z832_c2cc0(p1); break;
  case 0x12e: z832_c12e(); break;
  case 0x12f: z832_c12f(); break;
  case 0x130: break;
  case 0x191: f_0c2f40(p1); break;
  case 0x192: Z832_c192(p1, rahmen.b192); break;
  case 0x193: Z832_c193(p1, rahmen.b193); break;
  case 0x1f5: Z832_c1f5(rahmen.b1f5); break;
  case 0x1f6: mineActor493_0c3470(p1); break;
  case 0x1f7: z832_c1f7(); break;
  case 0x1f8: Z832_c1f8(rahmen.b1f8); break;
  case 0x1f9: z832_c1f9(); break;
  case 0x1fa: mineActor493_0c3750(p1); break;
  case 0x259: z832_c259(); break;
  case 0x25a: z832_c25a(); break;
  case 0x2bd: Z832_c2bd(rahmen.b2bd); break;
  case 0x2be: z832_c2be(); break;
  case 0x2bf: z832_c2bf(); break;
  case 0x321: z832_c321(); break;
  case 0x322: Z832_c322(rahmen.b322); break;
  case 0x323: z832_c323(); break;
  case 0x1f41: mineActor493_0c3b20(p1); break;
  case 0x325: mineActor493_0c3db0(p1); break;
  case 0x385: Z832_c385(rahmen.b385); break;
  case 0x386: Z832_c386(rahmen.b386, rahmen.o386); break;
  case 0x387: mineActor493_0c4080(p1); break;
  case 0x3e9: mineActor493_0c42c0(p1); break;
  case 0x3ea: Z832_c3ea(rahmen.b3ea); break;
  case 0x3eb: z832_c3eb(); break;
  case 0x44d: z832_c44d(); break;
  case 0x44e: z832_c44e(); break;
  case 0x44f: mineActor493_0c4560(p1); break;
  case 0x4b1: Z832_tuer(p1, 0, rahmen.t0); break;
  case 0x4b2: Z832_tuer(p1, 1, rahmen.t1); break;
  case 0x4b3: z832_c4b3(); break;
  case 0x515: Z832_tuer(p1, 2, rahmen.t2); break;
  case 0x516: Z832_tuer(p1, 4, rahmen.t4); break;
  case 0x517: z832_c517(); break;
  case 0x579: f_0c4ae0(p1); break;
  case 0x57a: Z832_tuer(p1, 8, rahmen.t8); break;
  case 0x57b: Z832_tuer(p1, 0x10, rahmen.t10); break;
  case 0x57c: Z832_c57c(p1, rahmen.t20); break;
  case 0x57d: Z832_tuer(p1, 0x40, rahmen.t40); break;
  case 0x57e: z832_c57e(); break;
  case 0x57f: z832_c57f(); break;
  case 0x5dd: Z832_tuer(p1, 0x80, rahmen.t80); break;
  case 0x5de: Z832_tuer(p1, 0x100, rahmen.t100); break;
  case 0x5df: z832_c5df(); break;
  case 0x641: Z832_tuer(p1, 0x200, rahmen.t200); break;
  case 0x642: Z832_tuer(p1, 0x400, rahmen.t400); break;
  case 0x643: z832_c643(); break;
  case 0x6a5: z832_c6a5(); break;
  case 0x6a6: Z832_c6a6(rahmen.b6a6); break;
  case 0x6a7: Z832_c6a7(rahmen.b6a7); break;
  case 0x6a8: z832_c6a8(); break;
  case 0x6a9: mineActor493_0c5490(p1); break;
  case 0x709: f_0c55d0(p1); break;
  case 0x70a: z832_c70a(); break;
  case 0x70b: z832_c70b(); break;
  default: r = 0; break;
  }
  return r;
}


#undef p1
#undef DOOR493
//@ f_0c2a60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt am Ausgang der Zwergenmine (0x35000001), ob die Gruppe die Mine verlassen
 *   möchte, trägt beim erstmaligen Verlassen (d_1bf34c == 0 und d_1bf2a8 == 0) den Tagebucheintrag 0x8030041 ein
 *   und wechselt zurück auf die Umland-/Stadtkarte (0x1459).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2a60()
{
  if (f_0bf6f0(&d_1c2c64, 0x35000001) == 1) {
    if (EQ(d_1bf34c, 0)) {
      if (EQ(d_1bf2a8, 0)) {
        f_057220(&d_1c2c00, 0x8030041, 0);
        d_1bf2a8 = 1;
      }
    }
    f_0dd7f0(d_1c0004, 5, 0x1459);
  }
}
//@ f_0c2ad0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000002 aus und lässt 5 Minuten Spielzeit
 *   (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2ad0() BODY_0c2ad0
//@ f_0c2b00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt ebenfalls den Beschreibungstext 0x35000002 aus und lässt 5 Minuten
 *   Spielzeit (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2b00() BODY_0c2ad0
//@ f_0c2b30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000003 aus und lässt 5 Minuten Spielzeit
 *   (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2b30() BODY_0c2b30
//@ f_0c2b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt beim erstmaligen Betreten eines Bereiches (d_1bf26c == 0) die Warn- oder
 *   Entdeckungsmeldung 0x35000004 aus und löst über die virtuelle Dungeon-Methode (Code 0x36) die zugehörige
 *   Begegnung aus, nach deren Abschluss d_1bf26c = 2 gesetzt wird.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das mine1-Dungeon-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2b60(int p1) BODY_0c2b60
//@ f_0c2bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt den Beschreibungstext 0x35000005 aus und lässt 5 Minuten Spielzeit
 *   (f_125ed0) verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2bd0() BODY_0c2bd0
//@ f_0c2c00
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt die Gruppe bei der ersten Untersuchung (d_1bf24c == 0) durch den Helden mit der
 *   höchsten Sinnenschärfe (0x33) den Gegenstand 0x1a4 (420) entdecken (0x35000006) und ins Inventar aufnehmen
 *   (f_0dcf00); bei späteren Untersuchungen erscheint nur noch der Leermeldungstext 0x35000005.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2c00() BODY_0c2c00

//@ f_0c2cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler an einer engen oder verschütteten Stelle in der Mine (0x35000007)
 *   einen Helden auswählen (0x35000008), der eine Körperkraft-/Geschicklichkeitsprobe (f_044900(p, 3, 8))
 *   ablegt: Ist der gewählte Held ein Zwerg (f_042350 == 6), birgt er beim ersten Mal (d_1bf270 == 0) den
 *   Gegenstand 0x1a5 (421, Texte 0x35000009/0x3500000a), während ein größerer Nicht-Zwerg sich verletzt
 *   (f_044850) und erschöpft wird (f_040a00).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2cc0()
{
  int p;
  if (f_0bf6f0(&d_1c2c64, 0x35000007) == 1) {
    p = f_038d70(d_1c0004, 0x35000008);
    if (p != 0) {
      int b[15];
      int ok = f_044900(p, 3, 8) > 0;
      CTOR(b);
      *(int *)(b[1] + 4) = p;
      if (ok == 1 && EQ(d_1bf270, 0)) {
        if (f_042350((struct hero *)(p)) == 6) {
          MSG(0x35000009);
          MSG(0x3500000a);
          short t_405 = f_0dcf00(d_1c0004, 0x1a5, 1);
          if (t_405 != (short)0) d_1bf270 = 1;
        } else {
          MSG(0x3500000b);
          MSG(0x3500000c);
          f_044850(p, f_1457e0(3), 5);
          f_040a00(p, 1, 0x14);
        }
      } else {
        MSG(0x3500000d);
      }
      f_044090(p, 0x3f480, 2);
      f_125ed0(&d_1c2c44, 5);
      f_1254a0(b, 0);
    }
  }
}

//@ f_0c2e30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Ereignisfunktion gibt die Meldung 0x3500000e aus und lässt 10 Minuten Spielzeit (f_125ed0)
 *   verstreichen.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2e30() BODY_0c2e30
//@ f_0c2e60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt die Meldung 0x3500000e aus und öffnet anschließend den Beutebehälter bzw. Fundort
 *   mit der Kennung 0x15 (21, f_112df0/f_112ec0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2e60()
{
  int q, q2;
  MSG(0x3500000e);
    q = (int)operator new(0x14, mark(d_1a5660, 0x274));
  q = q ? f_112df0(q, 0x15, 0, 0) : q;
  q2 = q;
  if (f_1131b0(q) == 1) {
    MSG(0x3500000f);
    f_112ec0(q);
    f_125ed0(&d_1c2c44, 10);
  }
  if (q2) delete (char *)f_112e70(q2, 0);
}

//@ f_0c2ef0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere Funktion dient als Platzhalter für den Ereigniszweig 0x130 ohne eigene Operation.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0c2ef0(void)
{
}

//@ f_0c2f00
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Helden-Prädikat prüft, ob ein handlungsfähiger Held (f_0d4a60) eine stark erleichterte Probe
 *   auf die Eigenschaft bzw. das Talent 0x0d (-8, z. B. Höhenangst/Raumangst oder Gefahreninstinkt) nicht
 *   besteht (<= 0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held handlungsfähig ist und die Probe misslingt,
 *   andernfalls 0.
 === Ende Beschreibung === */
int f_0c2f00(int p1)
{
  int r = 0;
  if (f_0d4a60(p1)) {
    if (f_044c90(p1, 0xd, -8) <= 0) r = 1;
  }
  return r;
}
