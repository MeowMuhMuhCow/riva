/* === Beschreibung (Katalog) ===
 * Einheit gz_0b5dc0_t1b (Adresse 0x0b6b40 - 0x0b7310)
 *
 * Diese Einheit bildet den zweiten Teil des Stadtgebäudemoduls in Riva (Codebereich 0x0b6b40 bis 0x0b7310). Sie
 * enthält die Begegnungslogik mit alarmierten Hausbewohnern, kurze Dialog- und Ereignishandler für spezielle
 * Stadthäuser sowie das Untergrund-Treffen der Widerstandskämpfer um Tarik.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// P3 40/46 gleich (suche.py 26.10.2026, Basis gz_0b5dc0_t1_P1.CPP)
// gz_0b5dc0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B5DC0-0x0B8530
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_0391f0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0


int f_043c90(int p1);                                   // reg eax stapel 0
int f_043ca0(int p1);                                   // reg eax stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_044c90(int p1, int p2, int p3);
int f_060a70();                                         // reg - stapel 0
short f_08c920(int p1, int p2);
short f_0b3640(int p1);
int f_0b38e0();                                         // reg - stapel 0
int f_0b3950(int p1, int p2);                           // reg eax edx stapel 0
int f_0b3990();                                         // reg - stapel 0
int f_0b8d40(int p1);                                   // reg eax stapel 0
int f_0b8ef0(int p1);                                   // reg eax stapel 0
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
int f_0bf820(void *p1, ...);
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);
int f_0d64a0();                       // nicht in clobber.tsv
int f_0d6690(int p1);                                   // reg eax stapel 0
short f_0dbfe0(int p1);
int f_0dbda0(int p1);                                   // reg eax stapel 0
short f_0dbff0(int p1);
short f_0dc050(int p1, int p2, int p3);
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
short f_0de820(int p1);
int f_0eb820();                                         // reg - stapel 0
int f_0ebde0();                                         // reg - stapel 0
int f_0ec070();                                         // reg - stapel 0
int f_0ec5a0();                                         // reg - stapel 0
int f_0ec760();                                         // reg - stapel 0
int f_0ed760();                                         // reg - stapel 0
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_125dc0(void *p1, int p2);
int f_125ed0(void *p1, int p2);
int f_125f70(void *p1, int p2);
int f_126410(void *p1);
char f_126420(void *p1);
short f_1457e0(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bb210[];
extern int d_1bc924;                    // 0x1BC924
extern signed char d_1bca84;                    // 0x1BCA84
extern signed char d_1bca88;                    // 0x1BCA88
extern signed char d_1bdd04;                    // 0x1BDD04
extern signed char d_1bed6c;                    // 0x1BED6C
extern signed char d_1bed7c;                    // 0x1BED7C
extern signed char d_1bed80;                    // 0x1BED80
extern signed char d_1beda8;                    // 0x1BEDA8
extern signed char d_1bedac;                    // 0x1BEDAC
extern signed char d_1bedb4;                    // 0x1BEDB4
extern signed char d_1bedb8;                    // 0x1BEDB8
extern signed char d_1bedc8;                    // 0x1BEDC8
extern signed char d_1bedcc;                    // 0x1BEDCC
extern signed char d_1bedd4;                    // 0x1BEDD4
extern signed char d_1bedd8;                    // 0x1BEDD8
extern signed char d_1beddc;                    // 0x1BEDDC
extern signed char d_1bede0;                    // 0x1BEDE0
extern signed char d_1bede4;                    // 0x1BEDE4
extern signed char d_1bede8;                    // 0x1BEDE8
extern signed char d_1bedec;                    // 0x1BEDEC
extern signed char d_1bedf4;                    // 0x1BEDF4
extern signed char d_1bedf8;                    // 0x1BEDF8
extern signed char d_1bedfc;                    // 0x1BEDFC
extern signed char d_1bee00;                    // 0x1BEE00
extern signed char d_1bee04;                    // 0x1BEE04
extern short d_1bee08;                    // 0x1BEE08
extern signed char d_1bee0c;                    // 0x1BEE0C
extern signed char d_1bee10;                    // 0x1BEE10
extern signed char d_1bee14;                    // 0x1BEE14
extern signed char d_1bee18;                    // 0x1BEE18
extern signed char d_1bee1c;                    // 0x1BEE1C
extern signed char d_1bee20;                    // 0x1BEE20
extern signed char d_1bee24;                    // 0x1BEE24
extern signed char d_1bee28;                    // 0x1BEE28
extern int d_1bee34;                    // 0x1BEE34
extern int d_1bee38;                    // 0x1BEE38
extern int d_1bee3c;                    // 0x1BEE3C
extern int d_1bee40;                    // 0x1BEE40
extern int d_1bee44;                    // 0x1BEE44
extern int d_1bee48;                    // 0x1BEE48
extern int d_1bee4c;                    // 0x1BEE4C
extern int d_1bee50;                    // 0x1BEE50
extern int d_1bee54;                    // 0x1BEE54
extern int d_1bee58;                    // 0x1BEE58
extern int d_1bee5c;                    // 0x1BEE5C
extern int d_1bee60;                    // 0x1BEE60
extern int d_1bee64;                    // 0x1BEE64
extern int d_1bee68;                    // 0x1BEE68
extern int d_1bee6c;                    // 0x1BEE6C
extern int d_1bee70;                    // 0x1BEE70
extern int d_1bee74;                    // 0x1BEE74
extern int d_1bee78;                    // 0x1BEE78
extern int d_1bee7c;                    // 0x1BEE7C
extern int d_1bee80;                    // 0x1BEE80
extern int d_1bee84;                    // 0x1BEE84
extern int d_1bee88;                    // 0x1BEE88
extern int d_1bee8c;                    // 0x1BEE8C
extern int d_1bee90;                    // 0x1BEE90
extern int d_1bee94;                    // 0x1BEE94
extern int d_1bee98;                    // 0x1BEE98
extern int d_1bee9c;                    // 0x1BEE9C
extern int d_1beea0;                    // 0x1BEEA0
extern int d_1beea4;                    // 0x1BEEA4
extern int d_1beea8;                    // 0x1BEEA8
extern int d_1beeac;                    // 0x1BEEAC
extern int d_1beeb0;                    // 0x1BEEB0
extern int d_1beeb4;                    // 0x1BEEB4
extern int d_1beeb8;                    // 0x1BEEB8
extern int d_1beebc;                    // 0x1BEEBC
extern int d_1beec0;                    // 0x1BEEC0
extern int d_1beec4;                    // 0x1BEEC4
extern int d_1beec8;                    // 0x1BEEC8
extern int d_1beecc;                    // 0x1BEECC
extern int d_1beed0;                    // 0x1BEED0
extern int d_1beed4;                    // 0x1BEED4
extern int d_1beed8;                    // 0x1BEED8
extern int d_1beedc;                    // 0x1BEEDC
extern int d_1beee0;                    // 0x1BEEE0
extern int d_1beee4;                    // 0x1BEEE4
extern int d_1beee8;                    // 0x1BEEE8
extern int d_1beeec;                    // 0x1BEEEC
extern int d_1beef0;                    // 0x1BEEF0
extern int d_1beef4;                    // 0x1BEEF4
extern int d_1beef8;                    // 0x1BEEF8
extern int d_1beefc;                    // 0x1BEEFC
extern int d_1bef00;                    // 0x1BEF00
extern int d_1bef04;                    // 0x1BEF04
extern int d_1bef08;                    // 0x1BEF08
extern int d_1bef0c;                    // 0x1BEF0C
extern int d_1bef10;                    // 0x1BEF10
extern int d_1bef14;                    // 0x1BEF14
extern int d_1bef18;                    // 0x1BEF18
extern int d_1bef1c;                    // 0x1BEF1C
extern int d_1bef20;                    // 0x1BEF20
extern int d_1bef24;                    // 0x1BEF24
extern int d_1bef28;                    // 0x1BEF28
extern int d_1bef2c;                    // 0x1BEF2C
extern int d_1bef30;                    // 0x1BEF30
extern int d_1bef34;                    // 0x1BEF34
extern int d_1bef38;                    // 0x1BEF38
extern int d_1bef3c;                    // 0x1BEF3C
extern int d_1bef40;                    // 0x1BEF40
extern int d_1bef44;                    // 0x1BEF44
extern int d_1bef48;                    // 0x1BEF48
extern int d_1bef4c;                    // 0x1BEF4C
extern int d_1bef50;                    // 0x1BEF50
extern int d_1bef54;                    // 0x1BEF54
extern int d_1bef58;                    // 0x1BEF58
extern int d_1bef5c;                    // 0x1BEF5C
extern int d_1bef60;                    // 0x1BEF60
extern int d_1bef64;                    // 0x1BEF64
extern int d_1bef68;                    // 0x1BEF68
extern int d_1bef6c;                    // 0x1BEF6C
extern int d_1bef70;                    // 0x1BEF70
extern int d_1bef74;                    // 0x1BEF74
extern int d_1bef78;                    // 0x1BEF78
extern int d_1bef7c;                    // 0x1BEF7C
extern int d_1bef80;                    // 0x1BEF80
extern int d_1bef84;                    // 0x1BEF84
extern int d_1bef88;                    // 0x1BEF88
extern int d_1bef8c;                    // 0x1BEF8C
extern int d_1bef90;                    // 0x1BEF90
extern int d_1bef94;                    // 0x1BEF94
extern int d_1bef98;                    // 0x1BEF98
extern int d_1bef9c;                    // 0x1BEF9C
extern int d_1befa0;                    // 0x1BEFA0
extern int d_1befa4;                    // 0x1BEFA4
extern int d_1befa8;                    // 0x1BEFA8
extern int d_1befac;                    // 0x1BEFAC
extern int d_1befb0;                    // 0x1BEFB0
extern int d_1befb4;                    // 0x1BEFB4
extern int d_1befb8;                    // 0x1BEFB8
extern int d_1befbc;                    // 0x1BEFBC
extern int d_1befc0;                    // 0x1BEFC0
extern int d_1befc4;                    // 0x1BEFC4
extern int d_1befc8;                    // 0x1BEFC8
extern int d_1befcc;                    // 0x1BEFCC
extern int d_1befd0;                    // 0x1BEFD0
extern int d_1befd4;                    // 0x1BEFD4
extern int d_1befd8;                    // 0x1BEFD8
extern int d_1befdc;                    // 0x1BEFDC
extern int d_1befe0;                    // 0x1BEFE0
extern int d_1befe4;                    // 0x1BEFE4
extern int d_1befe8;                    // 0x1BEFE8
extern int d_1befec;                    // 0x1BEFEC
extern int d_1beff0;                    // 0x1BEFF0
extern int d_1beff4;                    // 0x1BEFF4
extern int d_1beff8;                    // 0x1BEFF8
extern int d_1beffc;                    // 0x1BEFFC
extern int d_1bf000;                    // 0x1BF000
extern int d_1bf004;                    // 0x1BF004
extern int d_1bf008;                    // 0x1BF008
extern int d_1bf00c;                    // 0x1BF00C
extern int d_1bf010;                    // 0x1BF010
extern int d_1bf014;                    // 0x1BF014
extern int d_1bf018;                    // 0x1BF018
extern int d_1bf01c;                    // 0x1BF01C
extern int d_1bf020;                    // 0x1BF020
extern int d_1bf024;                    // 0x1BF024
extern int d_1bf028;                    // 0x1BF028
extern int d_1bf02c;                    // 0x1BF02C
extern int d_1bf030;                    // 0x1BF030
extern int d_1bf034;                    // 0x1BF034
extern int d_1bf038;                    // 0x1BF038
extern int d_1bf03c;                    // 0x1BF03C
extern int d_1bf040;                    // 0x1BF040
extern int d_1bf044;                    // 0x1BF044
extern int d_1bf048;                    // 0x1BF048
extern int d_1bf04c;                    // 0x1BF04C
extern int d_1bf050;                    // 0x1BF050
extern int d_1bf054;                    // 0x1BF054
extern int d_1bf058;                    // 0x1BF058
extern int d_1bf05c;                    // 0x1BF05C
extern int d_1bf060;                    // 0x1BF060
extern int d_1bf064;                    // 0x1BF064
extern int d_1bf068;                    // 0x1BF068
extern int d_1bf06c;                    // 0x1BF06C
extern int d_1bf070;                    // 0x1BF070
extern int d_1bf074;                    // 0x1BF074
extern int d_1bf078;                    // 0x1BF078
extern int d_1bf07c;                    // 0x1BF07C
extern int d_1bf080;                    // 0x1BF080
extern int d_1bf084;                    // 0x1BF084
extern int d_1bf088;                    // 0x1BF088
extern int d_1bf08c;                    // 0x1BF08C
extern int d_1bf090;                    // 0x1BF090
extern int d_1bf094;                    // 0x1BF094
extern int d_1bf098;                    // 0x1BF098
extern int d_1bf09c;                    // 0x1BF09C
extern int d_1bf0a0;                    // 0x1BF0A0
extern int d_1bf0a4;                    // 0x1BF0A4
extern int d_1bf0a8;                    // 0x1BF0A8
extern int d_1bf0ac;                    // 0x1BF0AC
extern int d_1bf0b0;                    // 0x1BF0B0
extern int d_1bf0b4;                    // 0x1BF0B4
extern int d_1bf0b8;                    // 0x1BF0B8
extern int d_1bf0bc;                    // 0x1BF0BC
extern int d_1bf0c0;                    // 0x1BF0C0
extern int d_1bf0c4;                    // 0x1BF0C4
extern int d_1bf0c8;                    // 0x1BF0C8
extern int d_1bf0cc;                    // 0x1BF0CC
extern int d_1bf0d0;                    // 0x1BF0D0
extern int d_1bf0d4;                    // 0x1BF0D4
extern int d_1bf0d8;                    // 0x1BF0D8
extern int d_1bf0dc;                    // 0x1BF0DC
extern int d_1bf0e0;                    // 0x1BF0E0
extern int d_1bf0e4;                    // 0x1BF0E4
extern int d_1bf0e8;                    // 0x1BF0E8
extern int d_1bf0ec;                    // 0x1BF0EC
extern int d_1bf0f0;                    // 0x1BF0F0
extern int d_1bf0f4;                    // 0x1BF0F4
extern int d_1bf0f8;                    // 0x1BF0F8
extern int d_1bf0fc;                    // 0x1BF0FC
extern int d_1bf100;                    // 0x1BF100
extern int d_1bf104;                    // 0x1BF104
extern int d_1bf108;                    // 0x1BF108
extern int d_1bf10c;                    // 0x1BF10C
extern int d_1bf110;                    // 0x1BF110
extern int d_1bf114;                    // 0x1BF114
extern int d_1bf118;                    // 0x1BF118
extern int d_1bf11c;                    // 0x1BF11C
extern int d_1bf120;                    // 0x1BF120
extern int d_1bf124;                    // 0x1BF124
extern int d_1bf128;                    // 0x1BF128
extern int d_1bf12c;                    // 0x1BF12C
extern int d_1bf130;                    // 0x1BF130
extern int d_1bf134;                    // 0x1BF134
extern int d_1bf138;                    // 0x1BF138
extern int d_1bf13c;                    // 0x1BF13C
extern int d_1bf140;                    // 0x1BF140
extern int d_1bf144;                    // 0x1BF144
extern int d_1bf148;                    // 0x1BF148
extern int d_1bf14c;                    // 0x1BF14C
extern int d_1bf150;                    // 0x1BF150
extern int d_1bf154;                    // 0x1BF154
extern int d_1bf158;                    // 0x1BF158
extern int d_1bf15c;                    // 0x1BF15C
extern int d_1bf160;                    // 0x1BF160
extern int d_1bf164;                    // 0x1BF164
extern int d_1bf168;                    // 0x1BF168
extern int d_1bf16c;                    // 0x1BF16C
extern int d_1bf170;                    // 0x1BF170
extern int d_1bf174;                    // 0x1BF174
extern int d_1bf178;                    // 0x1BF178
extern int d_1bf17c;                    // 0x1BF17C
extern int d_1bf180;                    // 0x1BF180
extern int d_1bf184;                    // 0x1BF184
extern int d_1bf188;                    // 0x1BF188
extern int d_1bf18c;                    // 0x1BF18C
extern int d_1bf190;                    // 0x1BF190
extern int d_1bf194;                    // 0x1BF194
extern int d_1bf198;                    // 0x1BF198
extern int d_1bf19c;                    // 0x1BF19C
extern int d_1bf1a0;                    // 0x1BF1A0
extern int d_1bf1a4;                    // 0x1BF1A4
extern int d_1bf1a8;                    // 0x1BF1A8
extern signed char d_1bfabc;                    // 0x1BFABC
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c00a4;                    // 0x1C00A4
extern signed char d_1c00ac;                    // 0x1C00AC
extern signed char d_1c00b4;                    // 0x1C00B4
extern signed char d_1c00bc;                    // 0x1C00BC
extern signed char d_1c00c0;                    // 0x1C00C0
extern signed char d_1c00c4;                    // 0x1C00C4
extern short d_1c00cc;                    // 0x1C00CC
extern signed char d_1c0178;                    // 0x1C0178
extern signed char d_1c0190;                    // 0x1C0190
extern signed char d_1c01b8;                    // 0x1C01B8
extern signed char d_1c01f4;                    // 0x1C01F4
extern int d_1c21b0;                    // 0x1C21B0
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c3498;
extern int d_1bb224[];
int lib_dtorarst(int p1, void *p2, int p3);
int f_0b8490(int p1, int p2);
int f_0b8520(int p1, int p2);                           // reg eax edx stapel 0
int f_0b9960(void);
int f_0b9970(void);
int f_0b9980(void);
int f_0b9990(void);
int f_0b99a0(void);
int f_0b99b0(void);
int f_0b99c0(void);
int f_0b99d0(void);
int f_0b99e0(void);
int f_0b99f0(void);
int f_0b9a00(void);
int f_0b9a10(void);
int f_0b9a20(void);
int f_0b9a30(void);
int f_0b9a40(void);
int f_0b9a50(void);
int f_0b9a60(void);
int f_0b9a70(void);
int f_0b9a80(void);
int f_0b9a90(void);
int f_0b9aa0(void);
int f_0b9ab0(void);
int f_0b9ac0(void);
int f_0b9ad0(void);
int f_0b9ae0(void);
int f_0b9af0(void);
int f_0b9b00(void);
int f_0b9b10(void);
int f_0b9b20(void);
int f_0b9b30(void);
int f_0b9b40(void);
int f_0b9b50(void);
int f_0b9b60(void);
int f_0b9b70(void);
int f_0b9b80(void);
int f_0b9b90(void);
int f_0b9ba0(void);
int f_0b9bb0(void);
int f_0b9bc0(void);
int f_0b9bd0(void);
int f_0b9be0(void);
int f_0b9bf0(void);
int f_0b9c00(void);
int f_0b9c10(void);
int f_0b9c20(void);
int f_0b9c30(void);
int f_0b9c40(void);
int f_0b9c50(void);
int f_0b9c60(void);
int f_0b9c70(void);
int f_0b9c80(void);
int f_0b9c90(void);
int f_0b9ca0(void);
int f_0b9cb0(void);
int f_0b9cc0(void);
int f_0b9cd0(void);
int f_0b9ce0(void);
int f_0b9cf0(void);
int f_0b9d00(void);
int f_0b9d10(void);
int f_0b9d20(void);
int f_0b9d30(void);
int f_0b9d40(void);
int f_0b9d50(void);
int f_0b9d60(void);
int f_0b9d70(void);
int f_0b9d80(void);
int f_0b9d90(void);
int f_0b9da0(void);
int f_0b9db0(void);
int f_0b9dc0(void);
#define EQ(x,v) (((x)==(v))?1:0)
#define NE(x,v) (!EQ(x,v))
#define NEV(x,v) (!EQ(x,v))
#define LT1F(x) ((x) < 0x1f)
#define W16(p,o) (*(short *)((p)+(o)))
#define OBN(b,n) (((int **)(b))[n])
#define OB1(b) OBN(b,1)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0b5dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt den Versuch eines ausgewählten Helden ab, eine verschlossene Haustür mit roher
 *   Körperkraft einzutreten oder aufzubrechen. Bei einer misslungenen Kraftprobe erleidet der Held leichten
 *   Schaden, und mit einer Zufallschance wird ein Bewohner oder eine Stadtwache durch den Lärm alarmiert
 *   (f_0b6b40).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Tür erfolgreich aufgebrochen wurde, oder 0, wenn der
 *   Versuch scheiterte oder abgebrochen wurde.
 === Ende Beschreibung === */
int f_0b5dc0(void)
;
//@ f_0b5ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion setzt den globalen Zähler für fehlgeschlagene Türöffnungsversuche (d_1bedfc) auf
 *   0 zurück.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den zurückgesetzten Zählerwert 0 zurück.
 === Ende Beschreibung === */
int f_0b5ed0(void)
{ return 1; }
//@ f_0b5ee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den Versuch durch, ein Türschloss an einem Bürgerhaus mit Dietrichen oder
 *   Haarnadeln und einer Schlösser-Talentprobe (0x30) zu knacken. Bei wiederholten Fehlschlägen (d_1bedfc > 2)
 *   oder kritischem Patzer bricht das Werkzeug ab (f_0dc7a0), und der Lärm kann mit einer Zufallschance einen
 *   Wachposten herbeirufen (f_0b6b40).
 * - Eingaben: Die Funktion nimmt den Zeiger self auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Schloss geknackt wurde, oder 0 bei einem Fehlschlag.
 === Ende Beschreibung === */
int f_0b5ee0(int p1)
;
//@ f_0b6080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion bietet dem Spieler an einer verschlossenen Haustür ein Auswahlmenü an, ob die Gruppe
 *   das Schloss knacken (f_0b5ee0), die Tür eintreten (f_0b5dc0) oder unverrichteter Dinge weiterziehen möchte.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Tür geöffnet wurde, oder 0, wenn die Gruppe vor der
 *   verschlossenen Tür umkehrt.
 === Ende Beschreibung === */
int f_0b6080(int p1)
;
//@ f_0b6140
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft beim Verlassen oder Durchsuchen eines aufgebrochenen Hauses, ob die Gruppe
 *   überraschend auf einen Bewohner oder eine Stadtwache trifft (f_0b6b40) oder ob sich noch ein unentdecktes
 *   Beutestück im Haus befindet (f_0b3790). Findet die Gruppe einen Gegenstand, wird dieser in das
 *   Gruppeninventar übertragen (f_0dd7f0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 als Abschlussstatus zurück.
 === Ende Beschreibung === */
int f_0b6140(int p1)
;
//@ f_0b6240
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert die nächtliche Erkundung eines aufgebrochenen Wohnhauses, einschließlich der
 *   Entscheidung, ob die Gruppe eine Lichtquelle entzündet (f_0d54f0), im Dunkeln weitersucht (mit
 *   Verletzungsgefahr für einen zufälligen Helden) oder auf einen Wachhund im Haus stößt. Einen Wachhund kann
 *   die Gruppe mit Fleischrationen (0x2d) besänftigen, im Kampf stellen (0x81) oder durch eilige Flucht meiden.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe das Haus wieder verlässt, oder 0, wenn das Innere
 *   des Hauses weiter durchsucht werden kann (f_0b6140).
 === Ende Beschreibung === */
int f_0b6240(int p1)
;
//@ f_0b6530
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt den kompletten Ablauf eines nächtlichen Hauseinbruchs ab, indem sie zunächst
 *   das Öffnen der Tür (f_0b6080) und anschließend die Durchsuchung des dunklen Innenraums (f_0b6240, f_0b6140)
 *   nacheinander aufruft.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück, wodurch das Gebäude nach dem Einbruchsversuch wieder
 *   verlassen wird.
 === Ende Beschreibung === */
int f_0b6530(int p1)
;
//@ f_0b6560
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das Anklopfen an einem verschlossenen Bürgerhaus zur Nachtzeit, wobei ein
 *   verärgerter Bewohner öffnet und der Gruppe droht, die Stadtwache zu rufen. Reagiert die Gruppe abweisend
 *   oder aggressiv, kann es unmittelbar zu einem Gefecht mit der herbeigerufenen Stadtwache kommen (f_0b38e0).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6560(void)
;
//@ f_0b66c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Betreten einer verschlossenen Haustür bei Nacht und fragt den Spieler, ob
 *   er klopfen (f_0b6560), heimlich einbrechen (f_0b6530) oder weitergehen möchte. Falls das Haus in derselben
 *   Nacht bereits leergeräumt wurde (d_1bedf8), erscheint lediglich ein Hinweis.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b66c0(int p1)
;
//@ f_0b6810
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt den Besuch eines normalen Bürgerhauses bei Tageslicht, bei dem die Bewohner
 *   die Helden entweder abweisen, nach ihrem Begehren fragen oder ihnen je nach Handlungsfortschritt kurze
 *   Auskünfte geben. Versucht die Gruppe tagsüber mit Gewalt einzudringen (f_0b6530), wird sofort der Stadtalarm
 *   (d_1c00bc = 1) ausgelöst.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6810(int p1)
;
//@ f_0b6980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion bildet den Haupteinstiegspunkt für generische Wohnhäuser in Riva: Sie prüft zunächst
 *   das Haus-Einbruchsbit in der Bitmaske d_1bedb0, lädt das passende Hintergrundbild (Tag- oder Nachtansicht
 *   einer Haustür) und verzweigt je nach Tageszeit in die Tag-Interaktion (f_0b6810) oder die Nacht-Interaktion
 *   (f_0b66c0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt den Rückgabewert der aufgerufenen Tag- oder Nachtroutine (in der Regel 1)
 *   zurück.
 === Ende Beschreibung === */
short f_0b6980(int p1)
;
//@ f_0b6b40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wird ausgelöst, wenn die Heldengruppe bei einem Einbruch Lärm verursacht oder im Haus
 *   entdeckt wird: Ein Bewohner stellt die Einbrecher zur Rede, woraufhin die Gruppe fliehen, den Bewohner
 *   bestechen (50 Dukaten, 5000 Heller) oder ihn bedrohen und angreifen (f_0b38e0) kann. Gelingt weder
 *   Bestechung noch Einschüchterung, wird der allgemeine Stadtalarm (d_1c00bc = 1) aktiviert.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Gruppe das Haus fluchtartig verlässt oder einen Kampf
 *   auslöst, oder 0, wenn der Bewohner erfolgreich bestochen bzw. eingeschüchtert wurde und die Gruppe weiter
 *   durchsuchen darf.
 === Ende Beschreibung === */
int f_0b6b40(void)
;
//@ f_0b6d10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze Ereignisfunktion gibt den Beschreibungstext 0x2201003c für ein spezielles Stadthaus aus
 *   und beendet den Besuch sofort.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6d10(void)
;
//@ f_0b6d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze Ereignisfunktion gibt den Beschreibungstext 0x2201003d für ein spezielles Stadthaus aus
 *   und beendet den Besuch sofort.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6d40(void)
;
//@ f_0b6d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze Ereignisfunktion gibt den Beschreibungstext 0x2201003e für ein spezielles Stadthaus aus
 *   und beendet den Besuch sofort.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6d70(void)
;
//@ f_0b6da0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet beim Betreten eines bestimmten Hauses direkt den zugehörigen NPC-Dialog mit
 *   der Kennung 0x28 (40).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6da0(void)
;
//@ f_0b6dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet beim Betreten eines bestimmten Hauses direkt den zugehörigen NPC-Dialog mit
 *   der Kennung 0x1b (27).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6dc0(void)
;
//@ f_0b6de0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft vor dem Start des NPC-Dialogs 0x16 (22), ob bereits Abend oder Nacht herrscht
 *   (f_126420(d_1c2c44) >= 2). Tagsüber wird stattdessen der Hinweis 0x2201003f angezeigt, dass die gesuchte
 *   Person erst am Abend anzutreffen ist.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b6de0(void)
;
//@ f_0b6e50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob die Gruppe eine Einladung zum geheimen Treffen der Widerstandsgruppe besitzt
 *   (d_1bedce == 1) und ob es Abend ist (f_126420(d_1c2c44) == 2). Sind beide Bedingungen erfüllt und fand das
 *   Treffen noch nicht statt (d_1bedcf == 0), startet sie den Dialog 0x2b (43) und setzt das Abschlussflag
 *   d_1bedcf = 1; andernfalls wird das Haus wie ein gewöhnliches Bürgerhaus behandelt (f_0b6980).
 * - Eingaben: Die Funktion erhält keine Parameter (void), reicht aber implizit das aktuelle Gebäudeobjekt an
 *   f_0b6980 weiter.
 * - Rückgabewert: Die Funktion gibt 1 nach dem Treffen oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
short f_0b6e50(void)
;
//@ f_0b6ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft an einem Stadthaus, ob ein bestimmtes Handlungsereignis aktiv ist (d_1bedbe == 1
 *   und d_1bedba == 0), und startet in diesem Fall den Dialog 0x1a (26), andernfalls die Standard-Wohnhauslogik
 *   (f_0b6980).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 nach dem Dialog oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b6ed0(void)
;
//@ f_0b6f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft an einem Stadthaus das Handlungsflag d_1beda6: Ist es gesetzt, wird der Hinweis
 *   0x22010040 ausgegeben, andernfalls wird das Gebäude als normales Wohnhaus behandelt (f_0b6980).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b6f30(int p1)
;
//@ f_0b6f80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft an einem Stadthaus das Handlungsflag d_1beda2: Ist es gesetzt, startet sie den
 *   NPC-Dialog 0x1d (29), andernfalls ruft sie die Standard-Wohnhauslogik (f_0b6980) auf.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b6f80(int p1)
;
//@ f_0b6fd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet das Haus eines Informanten (Dialog 0x1e), das nur betreten werden kann,
 *   solange dieser noch lebt (d_1beda3 != 1 und d_1beddf == 0). Wurde der Informant ermordet (d_1beddf != 0),
 *   entdeckt die Gruppe beim ersten Besuch (d_1bede0 == 0) seine Leiche (Texte 0x22010041 bis 0x22010044, 50
 *   Abenteuerpunkte) und bei späteren Besuchen nur noch das verlassene Haus (0x22010045).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b6fd0(int p1)
;
//@ f_0b7100
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet in einem Stadthaus den NPC-Dialog 0x20 (32), sofern das zugehörige
 *   Handlungsflag d_1bedd8 noch 0 ist, und behandelt das Gebäude danach als normales Wohnhaus (f_0b6980).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b7100(int p1)
;
//@ f_0b7150
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert ein Gebäude, in dem je nach den Handlungsflags d_1bedaa und d_1bedaf entweder
 *   der NPC-Dialog 0x22 (34) stattfindet, nach dessen Abschluss ein Tagebucheintrag (0x8030042) angelegt wird,
 *   oder die normale Wohnhauslogik (f_0b6980) greift.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b7150(int p1)
;
//@ f_0b71d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet in einem Stadthaus den NPC-Dialog 0x23 (35), sofern das Handlungsflag d_1bedaa
 *   den Wert 1 hat, und ruft andernfalls die Standard-Wohnhauslogik (f_0b6980) auf.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b71d0(int p1)
;
//@ f_0b7230
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet das Haus eines weiteren Quest-NPCs (Dialog 0x24 / 36): Nach einem bestimmten
 *   Handlungsfortschritt (d_1bed9c == 1) findet die Gruppe beim ersten Besuch eine Nachricht oder Entdeckung
 *   (0x22010046, 10 Abenteuerpunkte, d_1bedea = 1), während das Haus bei noch späterem Fortschritt (d_1bed9c ==
 *   2) oder vorab als normales Wohnhaus (f_0b6980) behandelt wird.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b7230(int p1)
;
//@ f_0b7310
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert den Besuch in einem überwachten Stadthaus: Ist das Flag d_1bed9c == 2 gesetzt,
 *   wird die Gruppe beim Betreten von Wachen überrascht und muss sich entweder ergeben (f_0b3990,
 *   Verhaftung/Kampf 0x87) oder gegen die Wachen kämpfen (f_0b38e0); bei d_1bed9c == 1 und gesetztem d_1bedc9
 *   startet der Dialog 0x25 (37).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
short f_0b7310(int p1)
;
#pragma inline_depth(0)
int enterScene491(void);
#pragma aux enterScene491 "f_0b38e0";
//@ f_0b7440
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion verwaltet ein Quest-Gebäude, in dem bei aktivem Flag d_1bedeb == 1 der Dialog 0x2c
 *   (44) gestartet wird. Ist stattdessen d_1bedd0 == 1 und es ist Nacht (f_126420(d_1c2c44) == 3), kann die
 *   Gruppe über eine Klettern-Probe (0x1b) heimlich in das Haus einsteigen, einen Kampf (0x90, f_091f70)
 *   bestreiten und 50 Abenteuerpunkte sowie einen Tagebucheintrag (0x8030037) erhalten.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b7440(int p1)
;
//@ f_0b75e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion startet beim ersten Besuch eines bestimmten Hauses (d_1bedde == 0), sofern das
 *   Handlungsflag d_1bedaa noch 0 ist, den NPC-Dialog 0x1f (31) und vergibt anschließend 10 Abenteuerpunkte
 *   (f_0dcbb0).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b75e0(int p1)
;
//@ f_0b7660
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft, ob die Gruppe nachts (f_126420(d_1c2c44) == 3) und nach Freischaltung des
 *   Hinweises (d_1bed9e == 1, d_1bede8 == 0) ein geheimes Versteck (oder das Kanalisations-/Kellerzugangshaus
 *   0x16) betritt. Bei Bestätigung durch den Spieler wechselt das Spiel direkt in die zugehörige 3D-Umgebung
 *   (f_0dd7f0(d_1c0004, 0, 0x1614)).
 * - Eingaben: Die Funktion nimmt einen Zeiger p1 auf das Gebäudeobjekt (beginnend mit der 16-Bit-Gebäudekennung)
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt 1 beim Wechsel oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
short f_0b7660(unsigned short *p1)
;
//@ f_0b7710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert das Durchsuchen eines verlassenen Hauses (nach d_1beda8 == 1), in dem die
 *   Gruppe beim ersten Mal (d_1bedeb == 0) mehrere Hinweise entdeckt (0x22010063 bis 0x22010069) und 15
 *   Abenteuerpunkte erhält.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 oder den Rückgabewert von f_0b6980 zurück.
 === Ende Beschreibung === */
int f_0b7710(int p1)
;
//@ f_0b77d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermöglicht es der Gruppe, bei Nacht (f_126420(d_1c2c44) == 3) die Auslagen eines
 *   unbewachten Marktstandes oder Lagerplatzes zu durchsuchen (0x22010075), wobei ein zufälliges Beutestück aus
 *   f_0b3790 gefunden werden kann. Wird die Gruppe dabei entdeckt (f_0b6b40), droht ein Zusammenstoß mit den
 *   Wachen.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b77d0(int p1)
;
//@ f_0b78f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion behandelt das Betreten eines speziellen Hauses (nach d_1beda8 == 1 und d_1bedec == 0),
 *   das zunächst mit f_0b6080 aufgebrochen werden muss. Im Inneren findet der Gruppenanführer eine wichtige
 *   Quest-Spur (0x2201006b bis 0x22010072) sowie den Gegenstand 0x16c (364), während eine Stunde Spielzeit
 *   vergeht (f_125f70).
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das aktuelle Gebäudeobjekt entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Einbruch stattfand oder abgebrochen wurde, oder 0, falls
 *   keine Aktion ausgelöst wurde.
 === Ende Beschreibung === */
int f_0b78f0(int p1)
;
//@ f_0b7a10
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert den Übergang an einem Stadttor oder Bootshaus (f_0b3640), über das die Gruppe
 *   je nach aktuellem Gebietsmodus (f_0de820) und Gruppengröße (f_0dbff0) entweder auf die Stadtkarte von Riva
 *   oder in das Umland wechselt (f_0dd7f0). Falls ein magisches Gruppenmitglied oder Begleiter (f_039040) den
 *   Status 2 hat, wird zuvor f_0d64a0 aufgerufen.
 * - Eingaben: Die Funktion nimmt einen Zeiger p1 auf die 16-Bit-Gebäudekennung entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b7a10(short *p1)
;
//@ f_0b7af0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert einen zweiten Übergangspunkt (Tor oder Durchgang, f_0b3640), der die Gruppe
 *   abhängig vom aktuellen Gebietsmodus (f_0de820) und der Prüfung f_0ed760 zwischen zwei Kartenbereichen
 *   (0x139a/0x1964 bzw. 0x15f8/0x19d4) teleportiert (f_0dd7f0).
 * - Eingaben: Die Funktion nimmt einen Zeiger p1 auf die 16-Bit-Gebäudekennung entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b7af0(short *p1)
;
//@ f_0b7b70
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion präsentiert ein interaktives Stadtereignis mit drei Handlungsoptionen (0x22010085 bis
 *   0x22010087): Entscheidet sich der Spieler für den Angriff bzw. Widerstand (Option 1 mit Bestätigung), kommt
 *   es zur Konfrontation mit der Stadtwache (f_0b3990); bei Option 2 wartet die Gruppe zweimal 5 Minuten ab
 *   (f_125ed0) und beobachtet die Szene.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b7b70(void)
;
//@ f_0b7c60
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Prädikat prüft für einen einzelnen Helden p1, ob er sowohl die Eigenschaft f_043ca0 (z. B.
 *   weibliches Geschlecht oder bestimmter Zaubertyp) als auch den Status f_0d4a60 (bei Bewusstsein und
 *   handlungsfähig) erfüllt.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn beide Bedingungen zutreffen, andernfalls 0.
 === Ende Beschreibung === */
int f_0b7c60(int p1)
;
//@ f_0b7c90
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieses Prädikat prüft für einen einzelnen Helden p1, ob er sowohl die Eigenschaft f_043c90 als auch
 *   den Handlungsfähigkeitsstatus f_0d4a60 erfüllt.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf die Heldenstruktur entgegen.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn beide Bedingungen zutreffen, andernfalls 0.
 === Ende Beschreibung === */
int f_0b7c90(int p1)
;
//@ f_0b7cc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht die Heldengruppe mittels f_039ac0 nach einem Helden, der die Bedingung
 *   f_0b7c60 oder f_0b7c90 erfüllt, und gibt mit dessen Namen die entsprechende Meldung (0x220101c0 bzw.
 *   0x220101c1) aus.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn ein passender Held gefunden und eine Meldung ausgegeben
 *   wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0b7cc0(void)
;
//@ f_0b7d50
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese triviale Platzhalterfunktion gibt konstant 0 zurück und dient als Standard-Handler in der
 *   Gebäudetabelle.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 0 zurück.
 === Ende Beschreibung === */
int f_0b7d50(void)
;
//@ f_0b7d60
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein abgeleitetes Stadtgebäudeobjekt über den Basiskonstruktor
 *   f_0b8490 und trägt die virtuelle Methodentabelle d_1bb224 bei Offset +0x58 ein.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 sowie die 16-Bit-Gebäudekennung p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0b7d60(int p1, int p2)
;
//@ f_0b7d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein abgeleitetes Stadtgebäudeobjekt oder ein Array solcher Objekte
 *   (p2 & 4) ab, ruft den Basisdestruktor f_0b8520 auf und gibt bei gesetztem Bit p2 & 2 den Objektspeicher
 *   frei.
 * - Eingaben: Die Funktion nimmt den Objektzeiger p1 und die Watcom-Destruktor-Flags p2 entgegen.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_145234(int p1, int p2);
int f_145254();
int f_0b7d70(int p1, unsigned p2)
;

//@ f_0b7db0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere Funktion dient als Platzhalter-Methode ohne eigene Operation.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b7db0(void)
;
//@ f_0b7dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese virtuelle Standardmethode der Gebäudeklasse d_1bb224 gibt konstant 1 zurück.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0b7dc0(void)
;
//@ f_0b7dd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese statische Initialisierungsfunktion (__STI) belegt beim Programmstart die globale Tabelle der
 *   C++-Memberfunktionszeiger (d_1bee34 bis d_1bf1a8, insgesamt über 70 12-Byte-Einträge im
 *   Watcom-Memberpointer-Format) mit den Adressen der zugehörigen Trampolinfunktionen f_0b9dc0 abwärts bis
 *   f_0b9960 aus der Einheit gz_0b9940. Dadurch wird jedem Gebäudetyp in Riva sein spezifischer
 *   Interaktions-Handler zugeordnet.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b7dd0(void)
;
