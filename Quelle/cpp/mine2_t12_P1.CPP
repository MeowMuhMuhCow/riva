/* === Beschreibung (Katalog) ===
 * Einheit mine2_t12
 *
 * Diese Einheit gehört zu mine2.cpp und implementiert den ersten und zweiten Teil der Ereignis-, Rätsel-,
 * Fallen- und Begegnungslogik für die zweite Ebene der Zwergenmine (0x35), darunter Lorenschalter, Gänge mit
 * Grubengas, Seilabstiege, Seuchengefahren sowie Begegnungen und Beutelager.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// Astra 992: gemeinsame Einbauvorlage mine2_t1 + mine2_t2; f_0c7660 GLEICH.
// mine2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0C6180-0x0C9940
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_032820(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038cb0(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_038e90(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0396f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_039b70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03d4b0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040780(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040a40(int p1);                                   // reg eax stapel 0
int f_041530();                                         // reg - stapel 0
int f_041920(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_043a80(int p1, int p2);                           // reg eax edx stapel 0
int f_0441b0(int p1);                                   // reg eax stapel 0
int f_0441c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0441d0(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_045190(int p1, int p2);                           // reg eax edx stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f190(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05f220(int p1, int p2);                           // reg eax stapel 0
int f_05f280(int p1, int p2);                           // reg eax edx stapel 0
int f_05f360(int p1);                                   // reg eax stapel 0
int f_05f580(int p1);                                   // reg eax stapel 0
int f_05f5a0(int p1, int p2);                           // reg eax edx stapel 0
int f_05fa00(int p1, int p2);                           // reg eax edx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_0606a0(int p1, int p2);                           // reg eax edx stapel 0
int f_060740(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0607e0(int p1, int p2);                           // reg eax edx stapel 0
int f_060800(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0697c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_09a400();                                         // reg - stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0cda50();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0dbeb0(int p1);                                   // reg eax stapel 0
int f_0dcae0(int p1);                                   // reg eax stapel 0
int f_0dcbb0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd750(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de210(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax stapel 0
int f_112df0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_112e70(int p1, int p2);                           // reg eax stapel 0
int f_112ec0(int p1);                                   // reg eax stapel 0
int f_1131b0(int p1);                                   // reg eax stapel 0
int f_113340(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_1457e0(int p1);                                   // reg eax stapel 0
int f_145850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149360();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a56da;                    // 0x1A56DA
extern int d_1a56de;                    // 0x1A56DE
extern int d_1a56e2;                    // 0x1A56E2
extern int d_1a56e6;                    // 0x1A56E6
extern int d_1a56ea;                    // 0x1A56EA
extern short d_1a9820;                    // 0x1A9820
extern int d_1bf2b4;                    // 0x1BF2B4
extern int d_1bf2c8;                    // 0x1BF2C8
extern int d_1bf2cc;                    // 0x1BF2CC
extern int d_1bf2d0;                    // 0x1BF2D0
extern int d_1bf2e0;                    // 0x1BF2E0
extern int d_1bf2e4;                    // 0x1BF2E4
extern int d_1bf2e8;                    // 0x1BF2E8
extern int d_1bf2ec;                    // 0x1BF2EC
extern int d_1c0004;                    // 0x1C0004
                    // 0x1C2C40
extern const char d_1a56bc[];           // Text 0x1A56BC
// --- eigene Funktionen (56), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

#define A(x) ((int)&(x))
#define I4(p,o) (*(int *)((p) + (o)))
inline int EQ(int a, int b) { return a == b; }
inline int NE(int a, int b) { return a != b; }
inline int GE(int a, int b) { return a >= b; }
inline int LT(int a, int b) { return a < b; }
typedef short (*VF)(int, int, int);
typedef unsigned short (*VFU)(int, int, int);
typedef short (*VF4)(int, int, int, int);
struct O12 { char b[12]; };
struct O14 { char b[0x14]; };
#pragma aux f_147323 modify [esp];
short f_0db9a0(int p1);
short f_044900(int p1, int p2, int p3);
short f_0dcf00(int p1, int p2, int p3);
short f_0d54f0(int p1, int p2);
short f_0de480(int p1, int p2);
int __cdecl f_0bf820(int p1, ...);
int __cdecl f_0bfa20(int p1, ...);
int __cdecl f_041030(int p1, int p2);
int f_0f2720(int p1, int p2, int p3);
extern short d_1c2c64;
extern int d_1c2c44;
extern int d_1c2c00;
extern int d_1c2edc;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c3498;
extern char d_1bf2c4;
extern signed char d_1bf2c0;
extern short d_1bd922;
extern int d_1bd91c;
extern signed char d_1bf2d8;
extern char d_1bf2dc;
extern char d_1bf2d4;
extern char d_1bf2f0;
extern char d_1bf2f3;
extern int d_1bf2f4;
extern int d_1bf2b8;
extern char d_1bf2bc;
extern signed char d_1bf2b0;
extern signed char d_1bf280;
extern int d_1c0412;
extern int d_1c040c;
extern int d_1c0428;
extern int d_1c21a4;
void f_0c6b50(void); void f_0c6b80(void); void f_0c6cf0(int p1); void f_0c6d60(void); char f_0c6d80(void); void f_0c6dc0(void);
void f_0c6de0(int p1); void f_0c6ee0(void); void f_0c7030(int p1); void f_0c7180(int p1); void f_0c7300(int p1); void f_0c74e0(int p1);
void f_0c7520(int p1); void f_0c7550(void); void f_0c75a0(void); void f_0c7630(void);
void f_0c9380(void); void f_0c9790(int p1, short p2); void f_0c7660(int p1); void f_0c7a70(void); void f_0c7b50(void); void f_0c7c20(int p1);
void f_0c8410(int p1); void f_0c8540(int p1); void f_0c8580(void); void f_0c8750(void); void f_0c88c0(void); void f_0c8d50(int p1, int p2, int p3);
void f_0c8e40(int p1); void f_0c8ef0(int p1); void f_0c91b0(int p1); void f_0c9290(int p1);
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0c6180
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fungiert als zentraler Aktions- und Ereignis-Dispatcher der zweiten Zwergenminen-Ebene
 *   und verzweigt abhängig vom Aktionscode p2 zu den jeweiligen Minen-Interaktionen (Ausgang zur ersten Ebene,
 *   Zwischensequenzen, Lorenschalter, Truhen, Grubengasfelder, Kletterstellen, Wasserrad, Goblinschamanen und
 *   Endkampf).
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Dungeon-Verwaltungsstruktur sowie die Aktions- oder
 *   Trigger-ID p2 des betretenen oder ausgelösten Minenfeldes.
 * - Rückgabewert: Die Funktion gibt standardmäßig 0 zurück, sofern die aufgerufene Unterfunktion keinen
 *   abweichenden Wert im Rückgaberegister hinterlässt.
 === Ende Beschreibung === */
struct Item923 { struct f_112df0 { char data[20]; f_112df0(int,int=0,int=0); }; };
int f_0c6180(int p1, short p2)
{
    int end1085(int);
    #pragma aux end1085 "f_0dcae0" modify exact [eax edx]
    void action1085(int);
    #pragma aux action1085 "f_0c6b80" modify exact [eax]
    void de210_923(int);
    #pragma aux de210_923 "f_0de210" modify exact [eax]
    int call492_0bf6f0(int,int);
    #pragma aux call492_0bf6f0 "f_0bf6f0" modify exact [eax]
    int call492_0bf730(int,int);
    #pragma aux call492_0bf730 "f_0bf730" modify exact [eax edx]
    int call492_0bf820(int,int,short,...);
    #pragma aux call492_0bf820 "f_0bf820" parm caller [] modify exact [eax]
    int call492_038c40(int);
    #pragma aux call492_038c40 "f_038c40" modify exact [eax]
    int call492_1131b0(int);
    #pragma aux call492_1131b0 "f_1131b0" modify exact [eax]
    int call492_112ec0(int);
    #pragma aux call492_112ec0 "f_112ec0" modify exact [eax]
    int call492_112e70(int,int);
    #pragma aux call492_112e70 "f_112e70" modify exact [eax edx]
    int call492_112df0(int,short,int,int);
    #pragma aux call492_112df0 "f_112df0" modify exact [eax ebx edx]
    short call492_0db9a0(int);
    #pragma aux call492_0db9a0 "f_0db9a0" modify exact [eax]
    short call492_0dcf00(int,int,int);
    #pragma aux call492_0dcf00 "f_0dcf00" modify exact [eax ebx edx]

    struct Types905 {
 static void gift(char v) { *(volatile char*)&d_1bf2c4=(char)v; }
 static int sound() { return *(int *)&d_1a9820; }
 // haelt die Registerzuteilung wie im Original
 static unsigned short one() { return 1; }
 static short zero() { return 0; }

      static void flag(char x) { *(char *)&d_1bf2f3=x; }
      static int positive(short x) { return x>0; }
      static int truth923(char a) { return a ? 1 : 0; }
      static int bit(char x) { return truth923((char)(x&*(char*)&d_1bf2b8)); }
      static void amount(short x) { *(short *)&d_1bf2f4=x; }

      static unsigned short u(int x) { return x; }
      static short s(int x) { return x; }
      static int i(int x) { return x; }
      static short ss(short x) { return x; }
    };
    struct Frame923 { char oA[60]; char oB[60]; } frame923;
    int ret905;
    int handled905=1;
    int r;
    int o;
    int t;
    short rem;
    if ((p2 >= 0x1f41 && p2 <= 0x1f43) || (p2 >= 0x1b59 && p2 <= 0x1b5b)) {
        rem=p2%1000-1;
        f_0c9790(p1, rem);
    } else {
        p2=(p2&0)?(short)0:p2; // haelt die Registerzuteilung wie im Original
        switch ((unsigned short)p2) {
        case 0x65:
            if (call492_0bf6f0(A(d_1c2c64), 0x35000099) == 1) { f_0dd7f0(d_1c0004, 0xf, 0x13f5); { ret905=handled905; goto result905; } }
            break;
        case 0x66: action1085(p1); ret905=handled905; goto result905;
        case 0x67:
            r = call492_0bf820(A(d_1c2c64), 0x350000a0, 4, 0x350000a1, 0x350000a2, 0x350000a3, 0x350000a4);
            switch ((unsigned short)(r + 1)) {
            case 0: case 1: break;
            case 2: { ret905=0; int who1085=call492_038c40(d_1c0004); int place1085=p1; f_0c8d50(place1085,who1085,ret905); } { ret905=handled905; goto result905; }
            case 3: f_0c8e40(p1); { ret905=handled905; goto result905; }
            case 4: f_0c8ef0(p1); { ret905=handled905; goto result905; }
            case 5: break;
            }
            break;
        case 0x68: f_0603b0(0x19); Types905::gift(0); { ret905=handled905; goto result905; }
        case 0x69: ((void (*)(int))f_0c9380)(p1); { ret905=handled905; goto result905; }
        case 0x1f41: f_05fa00(0x15, 0x1f41); { ret905=handled905; goto result905; }
        case 0xca: f_0c6de0(p1); { ret905=handled905; goto result905; }
        case 0x12d: ((void (*)(int))f_0c6ee0)(p1); { ret905=handled905; goto result905; }
        case 0x191: f_0c7030(p1); { ret905=handled905; goto result905; }
        case 0x1f5:
            if (call492_0bf6f0(A(d_1c2c64), 0x350000de) == 1) {
                call492_0bf730(A(d_1c2c64), 0x350000df);
                f_039a80(d_1c0004, (int)f_0c7520);
                f_125ed0(A(d_1c2c44), 0x28);
                { ret905=handled905; goto result905; }
            }
            break;
        case 0x1f6:
            t = (int)new(mark(d_1a56bc,0x33c)) Item923::f_112df0(0x1b); o=t;
            if (call492_1131b0(o) == 1) { call492_0bf730(A(d_1c2c64), 0x350000e0); call492_112ec0(o); }
            else call492_0bf730(A(d_1c2c64), 0x350000e1);
            if (o) delete (char *)call492_112e70(o, 0);
            f_125ed0(A(d_1c2c44), 10);
            { ret905=handled905; goto result905; }
        case 0x1f8: call492_0bf730(A(d_1c2c64), 0x350000e2); { ret905=handled905; goto result905; }
        case 0x1f44: f_0c7660(p1); { ret905=handled905; goto result905; }
        case 0x1f43: f_05fa00(0x52, 0x1f43); { ret905=handled905; goto result905; }
        case 0x25a: call492_0bf730(A(d_1c2c64), 0x350000ef); f_125ed0(A(d_1c2c44), 10); { ret905=handled905; goto result905; }
        case 0x25b:
            if (call492_0bf6f0(A(d_1c2c64), 0x350000f0) == 1) { f_0603b0(0x1d); f_125f70(A(d_1c2c44), 1); { ret905=handled905; goto result905; } }
            break;
        case 0x25c: ((void(*)(int))f_0c7a70)(p1); { ret905=handled905; goto result905; }
        case 0x25d:
            if (call492_0bf6f0(A(d_1c2c64), 0x350000f2) == 1) {
                
                f_147323(A(d_1c2edc), 0x350032, Types905::u(0x7fff), Types905::u(0x8000), Types905::sound(), Types905::zero(), Types905::one());
                r = f_039ac0(d_1c0004, (int)f_0c7b50);
                if (r != 0) call492_0bf730(A(d_1c2c64), 0x350000f3); else call492_0bf730(A(d_1c2c64), 0x350000f4);
                f_0dbeb0(d_1c0004);
                end1085(d_1c0004);
                { ret905=handled905; goto result905; }
            }
            break;
        case 0x1f46: f_0c7c20(p1); { ret905=handled905; goto result905; }
        case 0x2bd: call492_0bf730(A(d_1c2c64), 0x35000102); f_125ed0(A(d_1c2c44), 10); { ret905=handled905; goto result905; }
        case 0x2be: call492_0bf730(A(d_1c2c64), 0x35000103); f_125ed0(A(d_1c2c44), 10); { ret905=handled905; goto result905; }
        case 0x1f42: f_05fa00(0x16, 0x1f42); { ret905=handled905; goto result905; }
        case 0x385: break;
        case 0x3e9: { int n905=0x19;
            Types905::flag(1);
            f_039a80(d_1c0004, (int)f_0c91b0);
            if (Types905::i(call492_0db9a0(d_1c0004)) > 0 && !Types905::bit(1)) { *(short *)&d_1bf2f4 = n905; f_039ac0(d_1c0004, (int)f_0c9290); { ret905=handled905; goto result905; } }
            }
break;
        case 0x3ea: { int n905=0x12;
            Types905::flag(2);
            f_039a80(d_1c0004, (int)f_0c91b0);
            if (Types905::i(call492_0db9a0(d_1c0004)) > 0 && !Types905::bit(1)) { *(short *)&d_1bf2f4 = n905; f_039ac0(d_1c0004, (int)f_0c9290); { ret905=handled905; goto result905; } }
            }
break;
        case 0x3eb: { int n905=10;
            Types905::flag(4);
            f_039a80(d_1c0004, (int)f_0c91b0);
            if (Types905::i(call492_0db9a0(d_1c0004)) > 0 && !Types905::bit(1)) { *(short *)&d_1bf2f4 = n905; f_039ac0(d_1c0004, (int)f_0c9290); { ret905=handled905; goto result905; } }
            }
break;
        case 0x3ec: f_0c8410(p1); { ret905=handled905; goto result905; }
        case 0x3ed: f_039a80(d_1c0004, (int)f_0c8540); { ret905=handled905; goto result905; }
        case 0x1f45: ((void(*)(int))f_0c8580)(p1); { ret905=handled905; goto result905; }
        case 0x4b1:
            f_125400(A(frame923.oA), A(d_1c349c), A(d_1c3870), A(d_1c3498));
            I4(I4(frame923.oA, 4), 4) = call492_038c40(d_1c0004);
            call492_0bf730(A(d_1c2c64), 0x35000112);
            f_1254a0(A(frame923.oA), 0);
            { ret905=handled905; goto result905; }
        case 0x515: ((void (*)(int))f_0c8750)(p1); { ret905=handled905; goto result905; }
        case 0x516:
            if (EQ(*(signed char *)&d_1bf2bc, 1)) { d_1bf2bc = 2; call492_0bf730(A(d_1c2c64), 0x3500011c); { ret905=handled905; goto result905; } }
            break;
        case 0x579: ((void (*)(int))f_0c88c0)(p1); { ret905=handled905; goto result905; }
        case 0x57a:
            if (EQ(*(signed char *)&d_1bf2dc, 0)) {
                f_125400(A(frame923.oB), A(d_1c349c), A(d_1c3870), A(d_1c3498));
                I4(I4(frame923.oB, 4), 4) = f_039320(d_1c0004, 0xc);
                call492_0bf730(A(d_1c2c64), 0x35000123);
                if (call492_0dcf00(d_1c0004, 0x1a9, 1) == 1) d_1bf2dc = 1;
                f_1254a0(A(frame923.oB), 0);
            }
            d_1bf2d4 = 0;
            { ret905=handled905; goto result905; }
        case 0x5dd:
            if (EQ(*(signed char *)&d_1bf2f0, 0)) {
                r = ((int (*)(int))f_0f2720)(4);
                if (r == 0) {
                    f_0dd7f0(d_1c0004, 0x11, 5000);
                    f_057220(A(d_1c2c00), 0x803003e, 0);
                    f_091f70(2);
                    *(volatile char*)&d_1bf2f0 = 1;
                    { ret905=handled905; goto result905; }
                }
                de210_923(d_1c0004);
                *(short *)&d_1c21a4 = 7;
                { ret905=handled905; goto result905; }
            }
            ((int (*)(int))f_0f2720)(4);
            f_0dd7f0(d_1c0004, 0x11, 5000);
            { ret905=handled905; goto result905; }
        default: handled905=0; break;
        }
    }
    { ret905=handled905; goto result905; }
result905:
    return ret905;

}
//@ f_0c6b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler am Übergang zur ersten Ebene (0x35000099), ob die Gruppe diesen
 *   Bereich verlassen möchte, und wechselt bei Bestätigung zurück in die erste Zwergenminen-Ebene (0xf,
 *   Zielposition 0x13f5).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6b50(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x35000099) == 1) f_0dd7f0(d_1c0004, 0xf, 0x13f5);
}
//@ f_0c6b80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion spielt beim ersten Betreten eines Stollenabschnitts (d_1bf2d8 == 0) eine geskriptete
 *   Szene mit einem Einsturz- oder Umgebungsgeräusch (0x350038) sowie einem Dialog zweier Porträt-Sprecher
 *   (0x350001, Texte 0x3500009a bis 0x3500009d) ab und markiert das Ereignis als erlebt (d_1bf2d8 = 1).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
int talk492(int,int,int,int,int);
#pragma aux talk492 "f_0bfa20" parm caller [] modify exact [eax];
void f_0c6b80(void)
{
    char obj[60];
    int a, b;
    int snd;
    if (EQ(d_1bf2d8, 0)) {
        d_1bf2d8 = 1;
        f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
        I4(I4(obj, 4), 4) = f_039320(d_1c0004, 0x33);
        if (f_0db9a0(d_1c0004) == 1) f_0bf730(A(d_1c2c64), 0x3500009a); else f_0bf730(A(d_1c2c64), 0x3500009b);
        snd = *(int *)&d_1a9820;
        f_147323(A(d_1c2edc), 0x350038, 0x7fff, 0x8000, snd, 0, 1);
        f_0bf730(A(d_1c2c64), 0x3500009c);
        a = f_0606a0(0x350001, 1);
        b = f_0606a0(0x350001, 0);
        talk492(A(d_1c2c64), a, 0, 0x3500009d, 0);
        talk492(A(d_1c2c64), b, 0, 0x3500009e, 0);
        if (b != 0) delete (char *)((int)(((RivaRasterImage*)(b))->f_0fad20( 0)));
        if (a != 0) delete (char *)((int)(((RivaRasterImage*)(a))->f_0fad20( 0)));
        I4(I4(obj, 4), 4) = f_039320(d_1c0004, 0x28);
        f_0bf730(A(d_1c2c64), 0x3500009f);
        f_1254a0(A(obj), 0);
    }
}
//@ f_0c6cf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet an einer Untersuchungs- oder Gefahrenstelle der Mine ein Auswahlmenü mit vier
 *   Optionen (0x350000a0 bis 0x350000a4) und verzweigt je nach Wahl zu den Aktionen f_0c8d50, f_0c8e40 oder zur
 *   Gegenstandsverwendung f_0c8ef0.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6cf0(int p1)
{
    int local_0bf820(int p1, ...);
    #pragma aux local_0bf820 "f_0bf820" parm caller [] value [eax] modify exact [eax edx];
    int local_038c40(int p1);
    #pragma aux local_038c40 "f_038c40" parm [eax] value [eax] modify exact [eax edx];
    int r;
    r = local_0bf820(A(d_1c2c64), 0x350000a0, 4, 0x350000a1, 0x350000a2, 0x350000a3, 0x350000a4);
    switch ((unsigned short)(r + 1)) {
    case 0: return;
    case 2: f_0c8d50(p1, local_038c40(d_1c0004), 0); return;
    case 3: f_0c8e40(p1); return;
    case 4: f_0c8ef0(p1); return;
    case 5: return;
    default: return;
    }
}
//@ f_0c6d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktiviert das Minenobjekt 0x19 über f_0603b0(0x19) und setzt den zugehörigen
 *   Statuszähler d_1bf2c4 auf 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6d60(void)
{
    f_0603b0(0x19);
    d_1bf2c4 = 0;
}
//@ f_0c6d80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion berechnet einen Erleichterungsmodifikator für Proben an einer Gefahrenstelle, der 5
 *   beträgt, wenn die Gruppe den Gegenstand 0x167 besitzt, 3, wenn der Queststatus 0x79 gesetzt ist, und
 *   andernfalls 0.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der ermittelte Proben-Modifikator (0, 3 oder 5).
 === Ende Beschreibung === */
char f_0c6d80(void)
{
    char r;
    short s;
    s = f_0d54f0(d_1c0004, 0x167);
    r = 0;
    if (s != -1) {
        r = 5;
    } else {
        s = f_0de480(d_1c0004, 0x79);
        if (s > 0) r = 3;
    }
    return r;
}
//@ f_0c6dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet das Weichen- oder Mechanismusobjekt 0x1f41 im Dungeon über f_05fa00(0x15,
 *   0x1f41) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6dc0(void)
{
    f_05fa00(0x15, 0x1f41);
}
//@ f_0c6de0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft und aktualisiert die Weiche 0x1f41 (0x15), gibt den Beschreibungstext 0x350000c8
 *   aus und startet über die virtuelle Methode des Dungeon-Handlers die zugehörige Lorenfahrt oder
 *   Bewegungssequenz (0x2a).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6de0(int p1)
{
    int p, t;
    unsigned short u;
    t = (int)new (mark(d_1a56bc, 0x1b5)) O12; p = t ? f_05f190(t, 0x15, 0x1f41) : t;
    if (NE(d_1bf2c0, 1) && EQ(f_05f580(p), 0)) {
        f_0bf730(A(d_1c2c64), 0x350000c8);
        f_05f280(p, 0);
        signed char c = d_1bf2c0;
        d_1bd922 = c + 8;
        u = (*(VFU *)I4(p1, 8))(p1, 0x2a, 0);
        switch (u) {
        case 1: case 3: d_1bf2c0 = 2; f_05f280(p, 0); break;
        case 0: d_1bf2c0 = 1; break;
        default: f_05f280(p, 0); break;
        }
    }
    if (p != 0) delete (char *)f_05f220(p, 0);
}
//@ f_0c6ee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion inszeniert an einer Fundstelle (Beutelager 0x1a) ein kurzes Gespräch zwischen dem
 *   Gruppenanführer und einem zweiten Helden (0x350000c9 bis 0x350000cb), fragt nach dem Durchsuchen
 *   (0x350000cc) und öffnet bei Bestätigung das Beutefenster für Lager 0x1a.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c6ee0(void)
{
    char obj[60];
    int l = 0;
    int a, b, t;
    a = f_038c40(d_1c0004); b = f_039660(d_1c0004, 1);
    l = b;
    f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    if (a == b) {
        if (f_0db9a0(d_1c0004) > 1) a = f_038cb0(d_1c0004);
    }
    I4(I4(obj, 4), 4) = a;
    f_0bf730(A(d_1c2c64), 0x350000c9);
    I4(I4(obj, 4), 4) = l;
    f_0bf730(A(d_1c2c64), 0x350000ca);
    if (GE(d_1bf280, 1)) f_0bf730(A(d_1c2c64), 0x350000cb);
    t = (int)operator new(0x14, mark(d_1a56bc, 0x206)); a = t ? f_112df0(t, 0x1a, 0, 0) : t;
    if (f_1131b0(a) != 0) {
        if (f_0bf6f0(A(d_1c2c64), 0x350000cc) == 1) f_112ec0(a);
    }
    if (a) delete (char *)f_112e70(a, 0);
    f_1254a0(A(obj), 0);
}
//@ f_0c7030
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert eine Begegnung im Stollen in Abhängigkeit vom Begegnungsstatus d_1bf2b0 (0 bis
 *   2) und bietet in einem Drei-Optionen-Menü (0x350000ce/0x350000cf) den direkten Vorstoß (f_0c7180) oder den
 *   Einsatz von Magie (f_0c7300) an.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c7030(int p1)
{
    char obj[60];
    int id;
    if (GE(d_1bf2b0, 0) && LT(d_1bf2b0, 3)) {
        f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
        I4(I4(obj, 4), 4) = f_039320(d_1c0004, 0x1d);
        if (EQ(d_1bf2b0, 0) && f_0bf6f0(A(d_1c2c64), 0x350000cd) == 1) d_1bf2b0 = 1;
        if (EQ(d_1bf2b0, 1) || EQ(d_1bf2b0, 2)) {
            if (EQ(d_1bf2b0, 1)) { d_1bf2b0 = 2; id = 0x350000ce; } else id = 0x350000cf;
            I4(I4(obj, 4), 4) = f_039320(d_1c0004, 0x33);
            switch ((unsigned short)(f_0bf820(A(d_1c2c64), id, 3, 0x350000d0, 0x350000d1, 0x350000d2) + 1)) {
            case 0: break;
            case 1: break;
            case 2: f_0c7180(p1); break;
            case 3: f_0c7300(p1); break;
            case 4: break;
            }
        }
        f_1254a0(A(obj), 0);
    }
}
//@ f_0c7180
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt den direkten Angriff oder Rückzug bei der Begegnung aus f_0c7030, lässt bei
 *   einem Fluchtversuch für jeden Helden eine erschwerte Körperbeherrschungs-/Athletikprobe (0xb, Erschwernis 8)
 *   würfeln, versetzt erfolgreiche Flüchtende auf Feld 0x146b und startet für Zurückgebliebene den Kampf
 *   (f_0c74e0).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c7180(int p1)
{
    char obj[60];
    int fl;
    int v;
    f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    fl = 1;
    if (f_0db9a0(d_1c0004) > 1) {
        v = f_039660(d_1c0004, 0xb);
        if (f_044900(v, 0xb, -8) > 0) {
            I4(I4(obj, 4), 4) = v;
            if (f_0bf6f0(A(d_1c2c64), 0x350000d3) != 1) {
                I4(I4(obj, 4), 8) = f_039b70(d_1c0004, v, 2);
                fl = 0;
                f_0bf730(A(d_1c2c64), 0x350000d4);
            } else {
                f_0dd750(f_041030(1, v), 0x146b);
            }
        }
    }
    if (fl == 1) {
        I4(I4(obj, 4), 4) = f_039660(d_1c0004, 0);
        f_0bf730(A(d_1c2c64), 0x350000d5);
        if (EQ(d_1bf280, 2)) {
            I4(I4(obj, 4), 4) = f_039660(d_1c0004, 1);
            f_0bf730(A(d_1c2c64), 0x350000d6);
        }
        f_0bf730(A(d_1c2c64), 0x350000d7);
        d_1bd91c = 1;
        if ((*(VF *)I4(p1, 8))(p1, 0x2b, 0) == 0) {
            f_09a400();
            f_0bf730(A(d_1c2c64), 0x350000d8);
            d_1bf2b0 = 2;
        }
    }
    f_1254a0(A(obj), 0);
}
//@ f_0c7300
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler bei der Begegnung aus f_0c7030 einen Helden und einen Zauberspruch
 *   wählen (f_03d4b0), wobei Zauber 0x13 die Gefahr friedlich bannt (d_1bf2b0 = 3, 2000 Schritte Fortschritt, 30
 *   Abenteuerpunkte, Tagebucheintrag 1), während Kampfzauber (0x3b, 0x17) direkt das Gefecht (f_0c74e0)
 *   auslösen.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c7300(int p1)
{
    char obj[60];
    int q;
    q = f_038e10(d_1c0004, 0x350000d9);
    if (q != 0) {
        *(short *)&d_1c0428 = 4;
        f_03d4b0(q, 1, 0);
        if (d_1c0412 == 1) {
        f_125400(A(obj), A(d_1c349c), A(d_1c3870), A(d_1c3498));
        I4(I4(obj, 4), 4) = q;
        switch ((unsigned short)d_1c040c) {
        case 0x3b:
            f_0bf730(A(d_1c2c64), 0x17000002);
            d_1bd91c = 1;
            if ((*(VF *)I4(p1, 8))(p1, 0x2b, 0) == 0) {
                f_09a400();
                f_0bf730(A(d_1c2c64), 0x350000d8);
                *(volatile signed char *)&d_1bf2b0 = 2;
                f_1254a0(A(obj), 0);
                return;
            }
            break;
        case 0x13:
                f_0bf730(A(d_1c2c64), 0x17000003);
                f_054ca0(5, 2000);
                f_054ca0(0xb, 2000);
                f_040780(q, 0x1e);
                f_091f70(1);
                f_0697c0(p1 + 2, 0x2b, 0);
                d_1bf2b0 = 3;
                f_1254a0(A(obj), 0);
                return;
        case 0x17:
            f_0bf730(A(d_1c2c64), 0x17000004);
            d_1bd91c = 1;
            if ((*(VF *)I4(p1, 8))(p1, 0x2b, 0) == 0) {
                f_09a400();
                f_0bf730(A(d_1c2c64), 0x350000d8);
                d_1bf2b0 = 2;
                f_1254a0(A(obj), 0);
                return;
            }
            break;
        default:
            f_1254a0(A(obj), 0);
            return;
        }
        f_1254a0(A(obj), 0);
        }
    }
}
//@ f_0c74e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion startet den Kampf 0x2b mit gesetztem Sonderflag d_1bd91c = 1 und gibt bei einem
 *   nicht siegreichen Ausgang den Text 0x350000d8 aus, wobei der Status d_1bf2b0 auf 2 gesetzt wird.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c74e0(int p1)
{
    d_1bd91c = 1;
    if ((*(VF *)I4(p1, 8))(p1, 0x2b, 0) == 0) {
        f_09a400();
        f_0bf730(A(d_1c2c64), 0x350000d8);
        d_1bf2b0 = 2;
    }
}
//@ f_0c7520
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dient als Gruppen-Callback an einer Heil- oder Wasserstelle, der bei jedem
 *   handlungsfähigen Helden f_040a40 aufruft und über f_045190(p1, 0x14) 20 Punkte gutschreibt.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück, damit die Iteration über alle Helden fortgesetzt wird.
 === Ende Beschreibung === */
void f_0c7520(int p1)
{
    if (f_0d4a60(p1) != 0) {
        f_040a40(p1);
        f_045190(p1, 0x14);
    }
}
//@ f_0c7550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler an einer Quelle oder Raststelle (0x350000de), ob die Gruppe
 *   verweilen möchte, wendet bei Bestätigung f_0c7520 auf alle Gruppenmitglieder an und lässt 40 Zeiteinheiten
 *   (0x28) verstreichen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c7550(void)
{
    if (f_0bf6f0(A(d_1c2c64), 0x350000de) == 1) {
        f_0bf730(A(d_1c2c64), 0x350000df);
        f_039a80(d_1c0004, (int)f_0c7520);
        f_125ed0(A(d_1c2c44), 0x28);
    }
}
//@ f_0c75a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion untersucht das Beutelager 0x1b, öffnet bei noch vorhandenen Gegenständen das
 *   Beutefenster nach Ausgabe von 0x350000e0 oder meldet andernfalls einen leeren Fundort (0x350000e1) bei einem
 *   Zeitaufwand von 10 Einheiten.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c75a0(void)
{
    int q;
    q = (int)new (mark(d_1a56bc, 0x33c)) O14;
    q = q ? f_112df0(q, 0x1b, 0, 0) : q;
    if (f_1131b0(q) == 1) {
        f_0bf730(A(d_1c2c64), 0x350000e0);
        f_112ec0(q);
    } else {
        f_0bf730(A(d_1c2c64), 0x350000e1);
    }
    if (q != 0) delete (char *)f_112e70(q, 0);
    f_125ed0(A(d_1c2c44), 10);
}
//@ f_0c7630
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den allgemeinen Raumbeschreibungstext 0x350000e2 in der zweiten
 *   Zwergenminen-Ebene aus.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0c7630(void)
{
    f_0bf730(A(d_1c2c64), 0x350000e2);
}

extern short mine992_d_1a9820;
#pragma aux mine992_d_1a9820 "d_1a9820"
extern int mine992_d_1a56da;
#pragma aux mine992_d_1a56da "d_1a56da"
extern int mine992_d_1a56de;
#pragma aux mine992_d_1a56de "d_1a56de"
extern int mine992_d_1a56e2;
#pragma aux mine992_d_1a56e2 "d_1a56e2"
extern int mine992_d_1a56e6;
#pragma aux mine992_d_1a56e6 "d_1a56e6"
extern int mine992_d_1c0004;
#pragma aux mine992_d_1c0004 "d_1c0004"
extern signed char mine992_d_1bf2b4;
#pragma aux mine992_d_1bf2b4 "d_1bf2b4"
extern unsigned char mine992_d_1bf2b8;
#pragma aux mine992_d_1bf2b8 "d_1bf2b8"
extern signed char mine992_d_1bf2bc;
#pragma aux mine992_d_1bf2bc "d_1bf2bc"
extern signed char mine992_d_1bf2c8;
#pragma aux mine992_d_1bf2c8 "d_1bf2c8"
extern signed char mine992_d_1bf2cc;
#pragma aux mine992_d_1bf2cc "d_1bf2cc"
extern signed char mine992_d_1bf2d0;
#pragma aux mine992_d_1bf2d0 "d_1bf2d0"
extern char mine992_d_1bf2f3;
#pragma aux mine992_d_1bf2f3 "d_1bf2f3"
extern short mine992_d_1bf2f4;
#pragma aux mine992_d_1bf2f4 "d_1bf2f4"
extern char mine992_d_1c2c44[];
#pragma aux mine992_d_1c2c44 "d_1c2c44"
extern char mine992_d_1c2c64[];
#pragma aux mine992_d_1c2c64 "d_1c2c64"
extern char mine992_d_1c2edc[];
#pragma aux mine992_d_1c2edc "d_1c2edc"
extern const char mine992_d_1c349c[];
#pragma aux mine992_d_1c349c "d_1c349c"
extern const char mine992_d_1c3870[];
#pragma aux mine992_d_1c3870 "d_1c3870"
extern const char mine992_d_1c3498[];
#pragma aux mine992_d_1c3498 "d_1c3498"
extern const char mine992_d_1a56bc[];
#pragma aux mine992_d_1a56bc "d_1a56bc"
#pragma aux h_147323 modify [esp];
void h_147323(void *p, int a, int b, int c, int d, int e, int f);
int f_0607e0g(int p1, int p2, int p3);
#pragma aux f_0607e0g parm [eax] [edx] [ecx];
struct ContextMine992 { public:
static int f_0c8020(int);
// mine2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1 Teil t2, Code 0x0C7660-0x0C88C0
#define EQI(x,v) (((x)==(v))?1:0)
#define NEI(x,v) (((x)!=(v))?1:0)
#define MSG34(r) ((r) ? 0x350000f3 : 0x350000f4)
struct SO { int a; int *p; char c[52]; };
struct E { short v; int p; };
struct BF8 { unsigned char b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1; };
struct T { char d[20]; T *f_112df0(int a, int b, int c); void f_112ec0(); int f_1131b0(); T *f_112e70(int a); };
struct V { short (*f)(void *, int, int); };
struct X { char pad[8]; V *vt; };
static void f_147323(void *p, int a, int b, int c, int d, int e, int f);
static int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
static int f_1254a0(void *p1, int p2);
static int f_0bf730(const char *o, int b);
static int f_0bf730(const char *o, int b, int c);
static int f_0bf6f0(const char *o, int b);
static int f_0bf820(const char *fmt, ...);
static int f_0db9a0i(int p1);
static int f_038c40(int p1);
static int f_038ba0(int p1);
static int f_038d70(int p1, int p2);
static int f_039320(int p1, int p2);
static int f_039660(int p1, int p2);
static int f_0397d0(int p1, int p2);
static int f_039a80(int p1, void (*cb)(int));
static int f_039ac0(int p1, int (*cb)(int));
static int f_040a00(int p1, int p2, int p3);
static int f_042960x(int p1);






static int f_0441c0(int p1, int p2);
static int f_044c90(int p1, int p2, int p3);
static int f_05fa00(int p1, int p2);
static int f_0603b0(int p1);
static int f_060740(int p1, int p2);
static int f_0607e0(int p1, int p2);
static int f_060800(int p1, int p2, int p3);
static int f_0d4a60(int p1);
static short f_0d4aa0(int p1, int p2);
static short f_0d54f0(int p1, int p2);
static int f_0db820(int p1, int p2);
static short f_0db9a0(int p1);
static int f_0dbeb0(int p1);
static int f_0dcae0(int p1);
static unsigned short f_0dcf00(int p1, int p2, int p3);
static int f_0de7d0(int p1, int p2);
static int f_125ed0(void *p1, int p2);
static int f_125f70(void *p1, int p2);
static short f_1457e0(int p1);
static int f_0366e0(int p1, int p2, int p3);
static int f_03af20(int p1, int p2);
static void f_0c91b0(int p1);
static void f_0c9290(int p1);
#define GB0 NEI(mine992_d_1bf2b8 & 1, 0)
#define GB1 NEI(mine992_d_1bf2b8 & 2, 0)
#define GB2 NEI(mine992_d_1bf2b8 & 4, 0)
#define SB2 mine992_d_1bf2b8 |= 4
#define SW(r) ((unsigned short)((r) + 1))
#define EQ(x,v) (((x)==(v))?1:0)
static void f_0c7660(int p1);
static void f_0c7770(int p1);
static void f_0c79f0(void);
static void f_0c7a10(void);
static void f_0c7a40(void);
static void f_0c7a70(void);
static int f_0c7b50(int p1);
static void f_0c7ba0(void);
static void f_0c7c20(int p1);
static void f_0c7fb0(int p1);
static int f_0c8020(void);
static int f_0c8120(void);
static int f_0c81d0(void);
static void f_0c8260(void);
static void f_0c8290(void);
static int f_0c82c0(void);
static void f_0c82e0(void);
static void f_0c82f0(void);
static void f_0c8350(void);
static void f_0c83b0(void);
static void f_0c8410(X *p1);
static void f_0c8540(int p1);
static void f_0c8550(void);
static void f_0c8580(void);
static void f_0c86f0(void);
static void f_0c8750(void);
static void f_0c8840(void);
static int f_0c8870(void);
};
//@ f_0c7660
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet ein versperrtes Hindernis (0x1f44, Status d_1bf2d0), bietet im Auswahlmenü
 *   (0x350000e4) eine Kraftanstrengung (f_0c7770) oder das Einsetzen zweier Stangen/Gegenstände vom Typ 0x21 an
 *   und schaltet das Hindernis bei Erfolg frei (f_0604c0(0x1f44, 0)).
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7660(int p1)
{
  SO o;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  // Gemeinsamer Cleanup als reiner Sprungzielblock: Watcom teilt ihn mit f_0c7030.
  goto body992;
done:
  ::f_1254a0((int)&o, 0);
  return;
body992:
  if (NEI(mine992_d_1bf2d0, 0)) {
    o.p[1] = f_038c40(mine992_d_1c0004);
    f_0bf730(mine992_d_1c2c64, 0x350000e3);
    goto done;
  }
  goto choose;
chosen2:
  f_0c7770(p1);
  goto done;
chosen3:
  if ((short)f_0dcf00(mine992_d_1c0004, 0x21, 2) <= 0) goto done;
  f_060740(0x1f44, 1);
  f_0607e0(0x1f44, 1);
  mine992_d_1bf2d0 = 1;
  goto done;
choose:
  switch (SW(f_0bf820(mine992_d_1c2c64, 0x350000e4, 3, 0x350000e5, 0x350000e6, 0x350000e7))) {
  case 0: case 1: case 4: goto done;
  case 2: goto chosen2;
  case 3: goto chosen3;
  default: goto done;
  }
}
//@ f_0c7770
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt alle handlungsfähigen Helden eine Probe auf das Attribut/Talent 8 ablegen (für
 *   Zwerge der Klasse 6 um +3, für andere um +5 erschwert), wertet kritische Fehlschläge (permanenter Abzug -1
 *   auf Attribut 8 und Schaden), normale Fehlschläge, Erfolge sowie kritische Erfolge (+1 auf Attribut 8) aus
 *   und übergibt dem besten Helden zwei Gegenstände 0x21.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7770(int p1)
{
    extern void attribut494(int,short,signed char);
#pragma aux attribut494 "f_03af20";
    extern short gegenstand494(int,short,short,short);
#pragma aux gegenstand494 "f_0366e0";
  signed char klasse494(int);
#pragma aux klasse494 "f_042350";
  SO o;
  E arr[7];
  short n;
  short k;
  short k2;
  int p = 0;
  int m;
  int q;
  short rr;
  n = f_0db9a0i(mine992_d_1c0004);
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  {
    short first1073 = (short)(n & 0xffff);
    {
      volatile short i;
      if (first1073 > 1) {
    short best; int current;
    memset(arr, 0, 0x2a);
    best = 0;
    k = 0;
    for (i = 0; (current=(short)i) < 7; ++i) {
      { int t_ = (int)(mine992_d_1c0004); p = f_0de7d0(t_,current); }
      if (p != 0 && f_0d4a60(p) != 0) {
        m = 5;
        if (klasse494(p) == 6) m = 3;
        arr[(short)k].p = p;
        arr[(short)k].v = f_044c90(p, 8, (signed char)m);
        if (arr[(short)k].v >= arr[(short)best].v) best = k;
        k++;
      }
    }
    if (arr[(short)best].v == 0) arr[(short)best].v = 1;
    for (k2 = 0; k2 < (short)n; k2++) {
      short entryValue=arr[k2].v;
      q = arr[k2].p;
      o.p[1] = q;
      if (entryValue == -1) {
        f_0bf730(mine992_d_1c2c64, 0x350000e9);
        attribut494(q,8,-1);
      } else if (entryValue <= 0) {
        f_0bf730(mine992_d_1c2c64, 0x350000ea);
      } else if (entryValue < 7) {
        f_0bf730(mine992_d_1c2c64, 0x350000eb);
      } else {
        f_0bf730(mine992_d_1c2c64, 0x350000ec);
        attribut494(q,8,1);
      }
    }
    o.p[1] = arr[(short)best].p;
    f_0bf730(mine992_d_1c2c64, 0x350000ed);
    f_060740(0x1f44, 1);
    f_0607e0(0x1f44,1);
    mine992_d_1bf2d0 = 2;
    rr = gegenstand494(arr[(short)best].p,0x21,0,2);
    if ((short)rr < 2) f_0dcf00(mine992_d_1c0004, 0x21, (short)(2 - rr));
  } else {
    o.p[1] = f_038c40(mine992_d_1c0004);
    f_0bf730(mine992_d_1c2c64, 0x350000ee);
  }
    }
  }
  f_1254a0(&o, 0);
}
//@ f_0c79f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet das Dungeon-Objekt 0x1f43 über f_05fa00(0x52, 0x1f43) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c79f0(void)
{
  f_05fa00(0x52, 0x1f43);
}
//@ f_0c7a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion zeigt den Untersuchungstext 0x350000ef an und lässt 10 Zeiteinheiten verstreichen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7a10(void)
{
  f_0bf730(mine992_d_1c2c64, 0x350000ef);
  f_125ed0(mine992_d_1c2c44, 10);
}
//@ f_0c7a40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt den Spieler an einem Mechanismus (0x350000f0), ob er ihn betätigen möchte,
 *   aktiviert bei Bestätigung das Objekt 0x1d (f_0603b0(0x1d)) und speichert einen Zeit-Timer (0x15180) in
 *   d_1c2c44.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7a40(void)
{
  if (f_0bf6f0(mine992_d_1c2c64, 0x350000f0) == 1) {
    f_0603b0(0x1d);
    f_125f70(mine992_d_1c2c44, 1);
  }
}
//@ f_0c7a70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet das Beutelager 0x1c, wobei beim ersten Entdecken (d_1bf2b4 == 0) der Held mit
 *   der höchsten Sinnesschärfe (0x33) den Hinweis 0x350000f1 gibt; ist das Lager leer, wird 0x350000e1 gemeldet.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7a70(void)
{
  SO o;
  T *p;
  p = new (mark(mine992_d_1a56bc, 0x460)) T;
  p = p ? p->f_112df0(0x1c, 0, 0) : p;
  if (EQI(mine992_d_1bf2b4, 0)) {
    f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
    o.p[1] = f_039320(mine992_d_1c0004, 0x33);
    f_0bf730(mine992_d_1c2c64, 0x350000f1);
    p->f_112ec0();
    mine992_d_1bf2b4 = 1;
    f_1254a0(&o, 0);
  } else {
    if (p->f_1131b0() == 1) {
      p->f_112ec0();
    } else {
      f_0bf730(mine992_d_1c2c64, 0x350000ef);
    }
  }
  if (p != 0) delete p->f_112e70(0);
}
//@ f_0c7b50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft als Gruppen-Callback, ob ein lebender Held ein unbeschädigtes Seil oder
 *   Kletterwerkzeug (0x1e) im Inventar trägt, und gibt bei einem Treffer 0 (Abbruch der Suche mit Erfolg), sonst
 *   1 zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Die Funktion gibt 0 zurück, wenn der Held den Gegenstand 0x1e einsatzbereit besitzt,
 *   andernfalls 1.
 === Ende Beschreibung === */
int ContextMine992::f_0c7b50(int p1)
{
  int r = 1;
  int i;
  if (((signed char)(f_042470((struct hero *)(p1)))) == 0) {
    i = f_0d4aa0(p1, 0x1e);
    if (i != -1) {
      if (f_042d30((struct hero *)(p1), i) == 0) {
        if (f_042da0((struct hero *)(p1), i) == 0) r = 0;
      }
    }
  }
  return r;
}
//@ f_0c7ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt vor einem tiefen Schacht (0x350000f2) nach Bestätigung zum Abstieg, spielt das
 *   Geräusch 0x350032 ab und lässt die Gruppe bei fehlendem Seil (f_0c7b50) tödlich verunglücken (f_0dbeb0,
 *   f_0dcae0).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7ba0(void)
{
  int r;
  if (f_0bf6f0(mine992_d_1c2c64, 0x350000f2) == 1) {
    f_147323(mine992_d_1c2edc, 0x350032, 0x7fff, 0x8000, (r=*(int*)&mine992_d_1a9820), 0, 1);
    if (f_039ac0(mine992_d_1c0004, f_0c7b50)) f_0bf730(mine992_d_1c2c64, 0x350000f3);
    else f_0bf730(mine992_d_1c2c64, 0x350000f4);
    f_0dbeb0(mine992_d_1c0004);
    f_0dcae0(mine992_d_1c0004);
  }
}
//@ f_0c7c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein mehrstufiges Hindernis am Objekt 0x1f46 (d_1bf2c8) mit drei Lösungswegen
 *   (f_0c8020, Gegenstand 0x1c über f_0c8120 oder Opfern von Gesundheit über f_0c81d0) und händigt beim Bergen
 *   der Fundstücke die Gegenstände 0xcf, 0x19b und 0x4a aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c7c20(int p1)
{
  void m4_147323(void*,int,int,int,int,int,int);
#pragma aux m4_147323 "f_147323" modify [esp];
  int f_0c8020(int);
  struct { SO o2, oA, o3; } frame;
  int r, id; unsigned u;
  if (EQI(mine992_d_1bf2c8,1)) {
    if (f_0bf6f0(mine992_d_1c2c64,0x350000f2)==1) {
      m4_147323(mine992_d_1c2edc,0x350032,0x7fff,0x8000,(r=*(int*)&mine992_d_1a9820),0,1);
      if (f_039ac0(mine992_d_1c0004,f_0c7b50)) f_0bf730(mine992_d_1c2c64,0x350000f3);
      else f_0bf730(mine992_d_1c2c64,0x350000f4);
      f_0dbeb0(mine992_d_1c0004); f_0dcae0(mine992_d_1c0004);
    }
    return;
  }
  if(EQI(mine992_d_1bf2c8,2)) { f_0bf730(mine992_d_1c2c64,0x350000f5); return; }
  f_125400(&frame.oA,mine992_d_1c349c,mine992_d_1c3870,mine992_d_1c3498);
  frame.oA.p[1]=f_039320(mine992_d_1c0004,0x33);
  if(f_0bf6f0(mine992_d_1c2c64,0x350000f6)==1) {
    u=0;
    switch((unsigned short)f_0bf820(mine992_d_1c2c64,0x350000f8,3,0x350000f9,0x350000fa,0x350000fb)) {
    case 1: u=f_0c8020(p1); break;
    case 2: {
      r=f_0397d0(mine992_d_1c0004,0x1c); unsigned ok=0;
      f_125400(&frame.o2,mine992_d_1c349c,mine992_d_1c3870,mine992_d_1c3498);
      if(r) {
        frame.o2.p[1]=r; f_0bf730(mine992_d_1c2c64,0x350000fd);
        mine992_d_1bf2c8=1; f_125ed0(mine992_d_1c2c44,0x32); ok=1;
      } else { frame.o2.p[1]=f_039660(mine992_d_1c0004,1); f_0bf730(mine992_d_1c2c64,0x350000fe); }
      f_1254a0(&frame.o2,0); u=ok; break;
    }
    case 3: {
      unsigned ok=0;
      f_125400(&frame.o3,mine992_d_1c349c,mine992_d_1c3870,mine992_d_1c3498);
      r=f_038d70(mine992_d_1c0004,0x350000ff);
      if(r) {
        frame.o3.p[1]=r; f_0bf730(mine992_d_1c2c64,0x35000100);
        mine992_d_1bf2c8=1; f_125ed0(mine992_d_1c2c44,0x14); f_040a00(r,2,0x32); ok=1;
      }
      f_1254a0(&frame.o3,0); u=ok; break;
    }
    }
    if(u==1) {
      frame.oA.p[1]=f_039320(mine992_d_1c0004,0x30);
      f_0bf730(mine992_d_1c2c64,0x35000101);
      f_0dcf00(mine992_d_1c0004,0xcf,1); f_0dcf00(mine992_d_1c0004,0x19b,1); f_0dcf00(mine992_d_1c0004,0x4a,1);
    }
  } else if(f_0bf6f0(mine992_d_1c2c64,0x350000f7)==1) {
    m4_147323(mine992_d_1c2edc,0x350032,0x7fff,0x8000,(r=*(int*)&mine992_d_1a9820),0,1);
    if(f_039ac0(mine992_d_1c0004,f_0c7b50)) f_0bf730(mine992_d_1c2c64,0x350000f3);
    else f_0bf730(mine992_d_1c2c64,0x350000f4);
    f_0dbeb0(mine992_d_1c0004); f_0dcae0(mine992_d_1c0004);
  }
  f_1254a0(&frame.oA,0);
}
//@ f_0c7fb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion würfelt als Gruppen-Callback für jeden echten Helden (f_042510(p1) == 0) eine
 *   Infektionschance aus (10 %, bzw. auf 5 % halbiert, wenn am Ausrüstungsplatz 0xe der Schutzgegenstand 0x33
 *   oder 0x185 getragen wird) und löst bei Fehlschlag über f_040a00(p1, 2, 0x14) eine Krankheit aus.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
void ContextMine992::f_0c7fb0(int p1)
{
  short s;
  short lim;
  if (f_0d4a60(p1) == 0) return;
  if (f_042400((struct hero *)(p1)) == 0) {
    s = f_0d4aa0(p1, 0x33);
    lim = 10;
    if (s == 0xe || (s = f_0d4aa0(p1, 0x185)) == 0xe) lim = 5;
    s = f_1457e0(100);
    if (s <= lim) f_040a00(p1, 2, 0x14);
  }
}
//@ f_0c8020
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt die erste Option am Hindernis 0x1f46 aus, wählt einen Helden nach
 *   Klassenpriorität aus, spielt den Sound 0x350035 ab, prüft für die gesamte Gruppe das Krankheitsrisiko
 *   (f_0c7fb0) und schaltet das Objekt 0x1f46 frei (d_1bf2c8 = 2).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
int ContextMine992::f_0c8020(void)
{
  int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  SO o;
  int r;
  short i;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  r = 0;
  i = 0;
  short t[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  for (i = 0; i < (short)8 && r == 0; i++) {
    r = f_0397d0(mine992_d_1c0004, t[i]);
  }
  if (r == 0) r = f_038ba0(mine992_d_1c0004);
  o.p[1] = r;
  { int snd = *(int *)&mine992_d_1a9820; f_147323_frame((int)mine992_d_1c2edc, 0x350035, 0x7fff, 0x8000, snd, 0, 1); }
  f_0bf730(mine992_d_1c2c64, 0x350000fc);
  mine992_d_1bf2c8 = 2;
  f_039a80(mine992_d_1c0004, f_0c7fb0);
  f_125ed0(mine992_d_1c2c44, 0x14);
  f_060740(0x1f46, 1);
  f_0607e0(0x1f46, 1);
  f_1254a0(&o, 0);
  return 1;
}
//@ f_0c8120
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft als zweite Option am Hindernis 0x1f46, ob ein Held das Hilfsmittel 0x1c besitzt
 *   (f_0397d0), und bereitet bei Erfolg nach 50 Zeiteinheiten die Bergung vor (d_1bf2c8 = 1).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
int ContextMine992::f_0c8120(void)
{
  SO o;
  int r;
  r = f_0397d0(mine992_d_1c0004, 0x1c);
  {
  int ok;
  ok = 0;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  if (r != 0) {
    o.p[1] = r;
    f_0bf730(mine992_d_1c2c64, 0x350000fd);
    mine992_d_1bf2c8 = 1;
    f_125ed0(mine992_d_1c2c44, 0x32);
    ok = 1;
  } else {
    o.p[1] = f_039660(mine992_d_1c0004, 1);
    f_0bf730(mine992_d_1c2c64, 0x350000fe);
  }
  f_1254a0(&o, 0);
  return ok;
  }
}
//@ f_0c81d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler als dritte Option am Hindernis 0x1f46 einen Helden auswählen
 *   (0x350000ff), infiziert diesen mit einer Krankheit (f_040a00(r, 2, 0x32)) und schaltet das Hindernis in den
 *   Zustand d_1bf2c8 = 1.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
int ContextMine992::f_0c81d0(void)
{
  SO o;
  int r;
  int ok = 0;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  r = f_038d70(mine992_d_1c0004, 0x350000ff);
  if (r != 0) {
    o.p[1] = r;
    f_0bf730(mine992_d_1c2c64, 0x35000100);
    mine992_d_1bf2c8 = 1;
    f_125ed0(mine992_d_1c2c44, 0x14);
    ok = 1;
    f_040a00(r, 2, 0x32);
  }
  f_1254a0(&o, 0);
  return ok;
}
//@ f_0c8260
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den Untersuchungstext 0x35000102 aus und lässt 10 Zeiteinheiten verstreichen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8260(void)
{
  f_0bf730(mine992_d_1c2c64, 0x35000102);
  f_125ed0(mine992_d_1c2c44, 10);
}
//@ f_0c8290
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt den Untersuchungstext 0x35000103 aus und lässt 10 Zeiteinheiten verstreichen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8290(void)
{
  f_0bf730(mine992_d_1c2c64, 0x35000103);
  f_125ed0(mine992_d_1c2c44, 10);
}
//@ f_0c82c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion schaltet die Weiche oder Vorrichtung 0x1f42 über f_05fa00(0x16, 0x1f42) um.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
int ContextMine992::f_0c82c0(void)
{
  return f_05fa00(0x16, 0x1f42);
}

//@ f_0c82e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dies ist eine leere Platzhalterfunktion ohne ausführbare Operationen.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c82e0(void)
{
}

//@ f_0c82f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt ein leichtes Grubengasfeld (d_1bf2f3 = 1), wendet den Gasschaden-Callback
 *   f_0c91b0 auf alle Helden an und prüft bei noch unentdecktem Gas (d_1bf2f2 == 0) eine stark erschwerte
 *   Sinnesschärfe-Probe (f_0c9290(0x19)).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c82f0(void)
{
  register int n = 0x19;
  signed char bits;
  int bit;
  mine992_d_1bf2f3 = 1;
  f_039a80(mine992_d_1c0004, f_0c91b0);
  if (f_0db9a0(mine992_d_1c0004) > 0 && (bit = !!(bits = mine992_d_1bf2b8 & 1)) == 0) {
    int p = mine992_d_1c0004;
    mine992_d_1bf2f4 = n;
    f_039ac0(p, (int (*)(int))f_0c9290);
  }
}
//@ f_0c8350
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt ein mittleres Grubengasfeld (d_1bf2f3 = 2), wendet f_0c91b0 auf alle Helden
 *   an und prüft bei unentdecktem Gas eine um 18 erschwerte Sinnesschärfe-Probe (f_0c9290(0x12)).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8350(void)
{
  register int n = 0x12;
  unsigned char bits;
  int bit;
  mine992_d_1bf2f3 = 2;
  f_039a80(mine992_d_1c0004, f_0c91b0);
  if (f_0db9a0(mine992_d_1c0004) > 0 && (bit = !!(bits = mine992_d_1bf2b8 & 1)) == 0) {
    int p = mine992_d_1c0004;
    mine992_d_1bf2f4 = n;
    f_039ac0(p, (int (*)(int))f_0c9290);
  }
}
//@ f_0c83b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt ein dichtes Grubengasfeld (d_1bf2f3 = 4), wendet f_0c91b0 auf alle Helden an
 *   und prüft bei unentdecktem Gas eine um 10 erschwerte Sinnesschärfe-Probe (f_0c9290(0xa)).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c83b0(void)
{
  register int n = 10;
  unsigned char bits;
  int bit;
  mine992_d_1bf2f3 = 4;
  f_039a80(mine992_d_1c0004, f_0c91b0);
  if (f_0db9a0(mine992_d_1c0004) > 0 && (bit = !!(bits = mine992_d_1bf2b8 & 1)) == 0) {
    int p = mine992_d_1c0004;
    mine992_d_1bf2f4 = n;
    f_039ac0(p, (int (*)(int))f_0c9290);
  }
}
//@ f_0c8410
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das Zentrum der Gas- und Monsterzone (d_1bf2f3 = 7), wendet f_0c91b0 und
 *   f_0c9290(0xa) an und startet abhängig von den Statusbits in d_1bf2b8 einen Kampf (0x2c) samt
 *   Folgeereignissen.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8410(X *p1)
{
  SO o;
  register int z = 0;
  unsigned char bits;
  int bit;
  mine992_d_1bf2f3 = 7;
  f_039a80(mine992_d_1c0004, f_0c91b0);
  if (f_0db9a0(mine992_d_1c0004) > 0 && (bit = !!(bits = mine992_d_1bf2b8 & 1)) == 0) {
    mine992_d_1bf2f4 = z;
    f_039ac0(mine992_d_1c0004, (int (*)(int))f_0c9290);
  }
  short s_474 = f_0db9a0(mine992_d_1c0004); int t_474 = (s_474 & 0) ? 0 : s_474;
  if (t_474 > 0) {
    if ((bit = !!(bits = mine992_d_1bf2b8 & 4)) == 1) {
      f_0bf730(mine992_d_1c2c64, 0x35000106);
    } else {
      if ((bit = !!(bits = mine992_d_1bf2b8 & 2)) == 0) {
        f_0bf730(mine992_d_1c2c64, 0x35000107);
        f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
        o.p[1] = f_039320(mine992_d_1c0004, 0x25);
        f_0bf730(mine992_d_1c2c64, 0x35000108);
        f_1254a0(&o, 0);
      } else {
        f_0bf730(mine992_d_1c2c64, 0x35000109);
      }
      if (p1->vt->f(p1, 0x2c, 0) == 0) SB2;
    }
  }
}
//@ f_0c8540
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt als Gruppen-Callback den angesammelten Gas-/Erstickungszähler eines Helden über
 *   f_0441c0(p1, 0) auf 0 zurück.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Heldenstruktur übergeben.
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
void ContextMine992::f_0c8540(int p1)
{
  f_0441c0(p1, 0);
}
//@ f_0c8550
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt beim Verlassen des Gasbereichs den Gaszähler aller Gruppenmitglieder über
 *   f_0c8540 sowie die globalen Gas-Statusvariablen d_1bf2f2 und d_1bf2f3 auf 0 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8550(void)
{
  f_039a80(mine992_d_1c0004, f_0c8540);
}
//@ f_0c8580
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet eine blockierte Tür oder Vorrichtung (0x1f45, Status d_1bf2cc), bietet im
 *   Menü (0x3500010a) das Aufstemmen mit dem Werkzeug 0x1a5 an, spielt den Sound 0x350036 ab und gibt den
 *   Durchgang 0x1f45 frei.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8580(void)
{
  int f_147323_frame(int,int,int,int,int,int,int);
#pragma aux f_147323_frame "f_147323" modify [esp]
  SO o;
  int r;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  o.p[1] = f_038c40(mine992_d_1c0004);
  if (EQI(mine992_d_1bf2cc, 0)) {
    r = f_0bf820(mine992_d_1c2c64, 0x3500010a, 3, 0x3500010b, 0x3500010c, 0x3500010d);
    switch (SW(r)) {
    case 0:
    case 1:
    case 4:
    default:
      f_1254a0(&o, 0);
      return;
    case 2:
      o.p[1] = f_039660(mine992_d_1c0004, 6);
      f_0bf730(mine992_d_1c2c64, 0x3500010e);
      break;
    case 3:
      if (f_0d54f0(mine992_d_1c0004, 0x1a5) == -1) {
        o.p[1] = f_039660(mine992_d_1c0004, 1);
        f_0bf730(mine992_d_1c2c64, 0x3500010f);
        break;
      }
      o.p[1] = f_039660(mine992_d_1c0004, 6);
      { int snd = *(int *)&mine992_d_1a9820;
        f_147323_frame((int)mine992_d_1c2edc, 0x350036, 0x7fff, 0x8000, snd, 0, 1);
      }
      f_0bf730(mine992_d_1c2c64, 0x35000110);
      f_060740(0x1f45, 1);
      f_0607e0(0x1f45, 1);
      *(volatile signed char *)&mine992_d_1bf2cc = 1;
      f_1254a0(&o, 0);
      return;
    }
  } else {
    f_0bf730(mine992_d_1c2c64, 0x35000111);
  }
  f_1254a0(&o, 0);
}
//@ f_0c86f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Gruppenanführer den Kommentar 0x35000112 ausgeben und verbraucht 10
 *   Zeiteinheiten.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c86f0(void)
{
  SO o;
  f_125400(&o, mine992_d_1c349c, mine992_d_1c3870, mine992_d_1c3498);
  o.p[1] = f_038c40(mine992_d_1c0004);
  f_0bf730(mine992_d_1c2c64, 0x35000112);
  f_1254a0(&o, 0);
}
//@ f_0c8750
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet beim ersten Betreten (d_1bf2bc == 0) das Auswahlmenü 0x35000113 (Optionen 1 bis
 *   3), aktiviert bei einer Interaktion das Ereignis 0x350020, würfelt bei Option 3 eine Talentprobe auf 0x28
 *   (+5) und zieht 300 Geldeinheiten über f_0db820 ab. Originalfehler: In case 3: geben sowohl der Erfolgs- als
 *   auch der Misserfolgszweig der Talentprobe f_044c90(p, 0x28, 5) exakt denselben Text 0x35000119 aus (Text
 *   0x3500011a bleibt ungenutzt).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8750(void)
{
  int r;
  int p;
  int q;
  if (EQI(mine992_d_1bf2bc, 0)) {
    r = f_0bf820(mine992_d_1c2c64, 0x35000113, 3, 0x35000114, 0x35000115, 0x35000116);
    f_060800(0x350020, 1, 0);
    switch (SW(r)) {
    case 2:
      f_0bf730(mine992_d_1c2c64, 0x35000117);
      break;
    case 3:
      f_0bf730(mine992_d_1c2c64, 0x35000118);
      p = f_039320(mine992_d_1c0004, 0x28);
      q = (short)f_044c90(p, 0x28, 5);
      if (q)
        f_0bf730(mine992_d_1c2c64, 0x35000119);
      else
        f_0bf730(mine992_d_1c2c64, 0x35000119);
      break;
    case 0:
    case 4:
      f_0bf730(mine992_d_1c2c64, 0x3500011b);
      break;
    }
    f_0db820(mine992_d_1c0004, 300);
    mine992_d_1bf2bc = 1;
  }
}
//@ f_0c8840
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt beim Weitergehen nach der Interaktion aus f_0c8750 (d_1bf2bc == 1) die
 *   Folgemeldung 0x3500011c aus und setzt d_1bf2bc auf 2.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void ContextMine992::f_0c8840(void)
{
  if (EQI(mine992_d_1bf2bc, 1)) {
    mine992_d_1bf2bc = 2;
    f_0bf730(mine992_d_1c2c64, 0x3500011c);
  }
}
//@ f_0c8870
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle sieben Gruppenplätze und ermittelt den handlungsfähigen Helden mit der
 *   aktuell höchsten Lebensenergie (f_042960).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Zeiger auf die Heldenstruktur mit den meisten Lebenspunkten (oder 0,
 *   falls kein Held handlungsfähig ist).
 === Ende Beschreibung === */
int ContextMine992::f_0c8870(void)
{
  int best;
  short i;
  int p;
  short a, b;
  best = 0;
  for (i = 0; i < 7; ++i) {
    p = f_0de7d0(mine992_d_1c0004, i);
    if (p != 0 && f_0d4a60(p) != 0) {
      if (best != 0) {
        a = f_042960((struct hero *)(best));
        b = f_042960((struct hero *)(p));
        if (a < b) best = p;
      } else {
        best = p;
      }
    }
  }
  return best;
}
