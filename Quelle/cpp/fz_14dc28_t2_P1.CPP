/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t2 (0x14EEAC - 0x150050)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil der 3D-Kollisions- und Bewegungs-Engine. Sie berechnet sämtliche
 * Schnittpunkte eines 2D-Bewegungsvektors mit den aufgeweiteten Kanten und Eckkreisen der umliegenden Wand- und
 * Bodenpolygone (f_14eeac), sammelt alle relevanten Kollisionsflächen im Umkreis des Spielers (f_14fa64) und
 * sortiert alle Ein- und Austrittspunkte entlang des Bewegungsstrahls nach ihrer Distanz (f_14fc78, f_14fd64).
 === Ende Beschreibung === */
// P3 0/5 gleich (suche.py 26.10.2026, Basis fz_14dc28_t2_P1.CPP)
// CC wcc386
// OPT -5r -oneatx -zp1 -s -fp5
// fz_14dc28.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x14DC28-0x1567AF
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_149470();                       // nicht in clobber.tsv
int f_149524(int p1);                                   // reg eax stapel 0
int f_149a88();                                         // reg - stapel 0
int f_149b9c(int p1, int p2);                           // reg eax edx stapel 0
int f_160320(int p1);                                   // reg eax stapel 0
int f_161328();                                         // reg - stapel 0
int f_161e84(int p1);                                   // reg eax stapel 0
int f_1629a8();                                         // reg - stapel 0
int f_162db8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_163050(int p1);                                   // reg eax stapel 0
int f_1630ac();                                         // reg - stapel 0
int f_163428(int p1, int p2);                           // reg eax edx stapel 0
int f_163484(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_163bf8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16b60c(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16b930(int p1);                                   // reg eax stapel 0
int f_16cbdc(int p1, int p2);                           // reg eax edx stapel 0
int f_16cc44(int p1, int p2);                           // reg eax edx stapel 0
int f_16ccac(int p1, int p2);                           // reg eax edx stapel 0
int f_16cd74(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_16cf6a(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16cff5(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16d295(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16d2c9(int p1);                                   // reg eax stapel 0
int f_16d33f(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3b7(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3d0(int p1);
int f_16d4d8(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d7e7(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d8ad(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16e93c(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_16ebd8();                                         // reg - stapel 0
int f_16ecb4(int p1);                                   // reg eax stapel 0
int f_16ecba(int p1);                                   // reg eax stapel 0
int f_16f693(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16fb53(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_16fb72(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_16fc19(int p1, int p2, int p3, int p4);           // reg edx ecx stapel 0
int f_1702b8(int p1);                                   // reg eax stapel 0
int f_171000(int p1, int p2);                           // reg eax edx stapel 0
int f_171994(int p1, int p2);                           // reg eax edx stapel 0
int f_172028(int p1, int p2);                           // reg eax edx stapel 0
int f_172148(int p1, int p2);                           // reg eax edx stapel 0
int f_172278();                                         // reg - stapel 0
int f_172628(int p1);                                   // reg eax stapel 0
int f_17464c(int p1);                                   // reg eax stapel 0
int f_1750b6();                       // nicht in clobber.tsv
int f_1750bc(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_176f10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1782e8(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a98dd;                    // 0x1A98DD
extern int d_1a98e1;                    // 0x1A98E1
extern int d_1a98e3;                    // 0x1A98E3
extern int d_1a98e4;                    // 0x1A98E4
extern int d_1a98e5;                    // 0x1A98E5
extern int d_1a98e6;                    // 0x1A98E6
extern int d_1a98e8;                    // 0x1A98E8
extern int d_1a98ec;                    // 0x1A98EC
extern int d_1a98f0;                    // 0x1A98F0
extern int d_1a98f4;                    // 0x1A98F4 Breiten int,unsigned char
extern int d_1a98f8;                    // 0x1A98F8
extern int d_1a98fc;                    // 0x1A98FC Breiten int,int,unsigned char
extern int d_1a9900;                    // 0x1A9900
extern int d_1a9904;                    // 0x1A9904
extern int d_1a990c;                    // 0x1A990C
extern int d_1a9914;                    // 0x1A9914
extern int d_1a9918;                    // 0x1A9918
extern int d_1a991c;                    // 0x1A991C
extern int d_1a9928;                    // 0x1A9928
extern int d_1a9930;                    // 0x1A9930
extern int d_1a9933;                    // 0x1A9933
extern int d_1a9935;                    // 0x1A9935
extern int d_1a9936;                    // 0x1A9936
extern int d_1a9937;                    // 0x1A9937
extern int d_1a993b;                    // 0x1A993B
extern int d_1a993c;                    // 0x1A993C
extern int d_1a993d;                    // 0x1A993D
extern int d_1a993e;                    // 0x1A993E
extern int d_1a993f;                    // 0x1A993F
extern int d_1a9940;                    // 0x1A9940
extern int d_1a9942;                    // 0x1A9942
extern int d_1a9943;                    // 0x1A9943
extern int d_1a9944;                    // 0x1A9944
extern int d_1a9945;                    // 0x1A9945
extern int d_1a9947;                    // 0x1A9947
extern int d_1a9948;                    // 0x1A9948
extern int d_1a9949;                    // 0x1A9949
extern int d_1a994b;                    // 0x1A994B
extern int d_1a994d;                    // 0x1A994D
extern int d_1a994f;                    // 0x1A994F
extern int d_1a9950;                    // 0x1A9950
extern int d_1a9960;                    // 0x1A9960
extern int d_1a9962;                    // 0x1A9962
extern int d_1a9964;                    // 0x1A9964
extern int d_1a9966;                    // 0x1A9966
extern int d_1a996a;                    // 0x1A996A
extern int d_1a996c;                    // 0x1A996C
extern int d_1a9978;                    // 0x1A9978
extern int d_1a997c;                    // 0x1A997C
extern int d_1a998c;                    // 0x1A998C
extern int d_1a9990;                    // 0x1A9990
extern int d_1a99a0;                    // 0x1A99A0
extern int d_1a99a4;                    // 0x1A99A4
extern int d_1a99a8;                    // 0x1A99A8
extern int d_1a99ac;                    // 0x1A99AC
extern int d_1a99b0;                    // 0x1A99B0
extern int d_1a99e0;                    // 0x1A99E0
extern int d_1a99e4;                    // 0x1A99E4
extern int d_1a99e8;                    // 0x1A99E8
extern int d_1a99ec;                    // 0x1A99EC
extern int d_1a99f0;                    // 0x1A99F0
extern int d_1a99f4;                    // 0x1A99F4
extern int d_1a99fc;                    // 0x1A99FC
extern int d_1a9a00;                    // 0x1A9A00
extern int d_1a9a04;                    // 0x1A9A04
extern int d_1a9a0c;                    // 0x1A9A0C
extern int d_1a9a10;                    // 0x1A9A10
extern int d_1a9a14;                    // 0x1A9A14
extern int d_1a9a18;                    // 0x1A9A18
extern int d_1a9a1c;                    // 0x1A9A1C
extern int d_1a9a2c;                    // 0x1A9A2C
extern int d_1a9a38;                    // 0x1A9A38
extern int d_1a9a3c;                    // 0x1A9A3C
extern int d_1a9a40;                    // 0x1A9A40
extern int d_1a9a44;                    // 0x1A9A44
extern int d_1a9a48;                    // 0x1A9A48
extern int d_1a9a4c;                    // 0x1A9A4C
extern int d_1a9a60;                    // 0x1A9A60
extern int d_1a9a64;                    // 0x1A9A64
extern int d_1a9a68;                    // 0x1A9A68
extern int d_1a9a6c;                    // 0x1A9A6C
extern int d_1a9ab4;                    // 0x1A9AB4
extern int d_1a9ab8;                    // 0x1A9AB8
extern int d_1a9abc;                    // 0x1A9ABC
extern int d_1a9ac0;                    // 0x1A9AC0
extern int d_1a9ac4;                    // 0x1A9AC4
extern int d_1a9ae0;                    // 0x1A9AE0
extern int d_1a9ae4;                    // 0x1A9AE4
extern int d_1a9b00;                    // 0x1A9B00
extern int d_1a9b04;                    // 0x1A9B04
extern int d_1a9b06;                    // 0x1A9B06
extern int d_1a9b08;                    // 0x1A9B08
extern int d_1a9b1c;                    // 0x1A9B1C
extern int d_1a9b20;                    // 0x1A9B20
extern int d_1a9b24;                    // 0x1A9B24
extern int d_1a9b2c;                    // 0x1A9B2C
extern int d_1a9b30;                    // 0x1A9B30
extern int d_1a9b34;                    // 0x1A9B34
extern int d_1a9b38;                    // 0x1A9B38
extern int d_1a9b3c;                    // 0x1A9B3C
extern int d_1a9b40;                    // 0x1A9B40
extern int d_1a9b44;                    // 0x1A9B44
extern int d_1a9b48;                    // 0x1A9B48
extern int d_1a9b4c;                    // 0x1A9B4C
extern int d_1a9b50;                    // 0x1A9B50
extern int d_1a9b54;                    // 0x1A9B54
extern short d_1a9b5c;                  // 0x1A9B5C
extern int d_1a9b7c;                    // 0x1A9B7C
extern int d_1a9b80;                    // 0x1A9B80
extern int d_1a9b84;                    // 0x1A9B84
extern int d_1a9b8c;                    // 0x1A9B8C
extern int d_1a9c64;                    // 0x1A9C64
extern int d_1a9c68;                    // 0x1A9C68
extern int d_1a9c6c;                    // 0x1A9C6C
extern int d_1ad4d4;                    // 0x1AD4D4
extern int d_1b8db0;                    // 0x1B8DB0
extern int d_1c6b20;                    // 0x1C6B20
extern int d_1c6b24;                    // 0x1C6B24
extern int d_1c6b44;                    // 0x1C6B44
extern int d_1c6b4c;                    // 0x1C6B4C
extern int d_1c6b50;                    // 0x1C6B50
extern int d_1c6b54;                    // 0x1C6B54
extern int d_1c6b58;                    // 0x1C6B58
extern int d_1c6b5c;                    // 0x1C6B5C
extern int d_1c6b60;                    // 0x1C6B60
extern int d_1c6b64;                    // 0x1C6B64
extern int d_1c6b68;                    // 0x1C6B68
extern int d_1c6b6c;                    // 0x1C6B6C
extern int d_1c6b70;                    // 0x1C6B70
extern int d_1c6b74;                    // 0x1C6B74
extern int d_1c6b78;                    // 0x1C6B78
extern int d_1c6b7c;                    // 0x1C6B7C
extern int d_1c6b80;                    // 0x1C6B80
extern int d_1c6b84;                    // 0x1C6B84
extern int d_1c6b88;                    // 0x1C6B88
extern int d_1c6b8c;                    // 0x1C6B8C
extern int d_1c6b90;                    // 0x1C6B90
extern int d_1c6b94;                    // 0x1C6B94
extern int d_1c6b9c;                    // 0x1C6B9C
extern short d_1c6ba0;                    // 0x1C6BA0
extern int d_1c6ba4;                    // 0x1C6BA4
extern int d_1c6ba8;                    // 0x1C6BA8
extern int d_1c6bac;                    // 0x1C6BAC
extern int d_1c6bb0;                    // 0x1C6BB0
extern int d_1c6bc0;                    // 0x1C6BC0
extern int d_1c6bc4;                    // 0x1C6BC4
extern int d_1c6bca;                    // 0x1C6BCA
extern int d_1c6bcc;                    // 0x1C6BCC
extern int d_1c6bd0;                    // 0x1C6BD0
extern int d_1c6bd4;                    // 0x1C6BD4
extern int d_1c6be8;                    // 0x1C6BE8
extern int d_1c6bec;                    // 0x1C6BEC
extern int d_1c6bf0;                    // 0x1C6BF0
extern int d_1c6bf4;                    // 0x1C6BF4
extern int d_1c6bf8;                    // 0x1C6BF8
extern int d_1c6bfc;                    // 0x1C6BFC
extern int d_1c6c00;                    // 0x1C6C00
extern int d_1c6c02;                    // 0x1C6C02
extern int d_1c6c04;                    // 0x1C6C04
extern int d_1c6c06;                    // 0x1C6C06
extern int d_1c6c08;                    // 0x1C6C08
extern int d_1c6c0a;                    // 0x1C6C0A
extern int d_1c6c0e;                    // 0x1C6C0E
extern int d_1c6c12;                    // 0x1C6C12
extern int d_1c6c14;                    // 0x1C6C14
extern int d_1c6c16;                    // 0x1C6C16
extern int d_1c6c18;                    // 0x1C6C18
extern int d_1c6c1a;                    // 0x1C6C1A
extern int d_1c6c1c;                    // 0x1C6C1C
extern int d_1c6c1e;                    // 0x1C6C1E
extern int d_1c6c20;                    // 0x1C6C20
extern int d_1c6c3c;                    // 0x1C6C3C
extern int d_1c6c40;                    // 0x1C6C40
extern int d_1c6c44;                    // 0x1C6C44
extern int d_1c6c78;                    // 0x1C6C78
extern int d_1c6d50;                    // 0x1C6D50
extern int d_1c7168;                    // 0x1C7168
extern int d_1c7230;                    // 0x1C7230
extern int d_1c76f8;                    // 0x1C76F8
extern int d_1c76f9;                    // 0x1C76F9
extern int d_1c7734;                    // 0x1C7734
extern int d_1c8ff8;                    // 0x1C8FF8
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c4;                    // 0x1C90C4
extern int d_1c90c8;                    // 0x1C90C8
extern int d_1c90d0;                    // 0x1C90D0
extern int d_1c90d2;                    // 0x1C90D2
extern int d_1c90d4;                    // 0x1C90D4
extern int d_1cc788;                    // 0x1CC788
extern int d_1ccf5e;                    // 0x1CCF5E
extern int d_1ccf62;                    // 0x1CCF62
extern int d_1ccf64;                    // 0x1CCF64
extern int d_1ccf66;                    // 0x1CCF66
extern int d_1ccf68;                    // 0x1CCF68
extern int d_1ccf6c;                    // 0x1CCF6C
extern int d_1ccf6e;                    // 0x1CCF6E
extern int d_1cd1b0;                    // 0x1CD1B0
extern int d_1cd1e0;                    // 0x1CD1E0
extern int d_1cd1e8;                    // 0x1CD1E8
extern unsigned char d_1cd1ec;          // 0x1CD1EC
extern int d_1cd1f8;                    // 0x1CD1F8
extern char d_1cd200;                   // 0x1CD200
extern int d_1cd204;                    // 0x1CD204
extern int d_1cd20c;                    // 0x1CD20C
extern int d_1cd214;                    // 0x1CD214
extern int d_1cd218;                    // 0x1CD218
extern int d_1cd21c;                    // 0x1CD21C
extern int d_1cd220;                    // 0x1CD220
extern int d_1cd224;                    // 0x1CD224
extern int d_1cd228;                    // 0x1CD228
extern int d_1cd22c;                    // 0x1CD22C
extern int d_1cd230;                    // 0x1CD230
extern int d_1cd234;                    // 0x1CD234
extern int d_1cd238;                    // 0x1CD238
extern int d_1cd23c;                    // 0x1CD23C
extern int d_1cd240;                    // 0x1CD240
extern int d_1cd244;                    // 0x1CD244
extern int d_1cd248;                    // 0x1CD248
extern int d_1cd270;                    // 0x1CD270
extern int d_1cd294;                    // 0x1CD294
extern int d_1cd298;                    // 0x1CD298
extern int d_1cd29c;                    // 0x1CD29C
extern int d_1cd2a4;                    // 0x1CD2A4
extern int d_1cd300;                    // 0x1CD300
extern int d_1cd308;                    // 0x1CD308
extern int d_1cd30c;                    // 0x1CD30C
extern int d_1cd310;                    // 0x1CD310
extern int d_1cd314;                    // 0x1CD314
extern int d_1cd318;                    // 0x1CD318
extern int d_1cd31c;                    // 0x1CD31C
extern int d_1cd320;                    // 0x1CD320
extern int d_1cd324;                    // 0x1CD324
extern int d_1cd328;                    // 0x1CD328
extern int d_1cd32c;                    // 0x1CD32C
extern int d_1cd330;                    // 0x1CD330
extern int d_1cdb1c;                    // 0x1CDB1C
extern int d_1cdb3c;                    // 0x1CDB3C
extern int d_1cdb40;                    // 0x1CDB40
extern int d_1cdb44;                    // 0x1CDB44
extern int d_1cdb48;                    // 0x1CDB48
extern int d_1cdb4c;                    // 0x1CDB4C
extern int d_1cdb50;                    // 0x1CDB50
extern int d_1cdb54;                    // 0x1CDB54
extern int d_1cdb58;                    // 0x1CDB58
extern int d_1cdb5c;                    // 0x1CDB5C
extern int d_1cdb60;                    // 0x1CDB60
extern int d_1cdb68;                    // 0x1CDB68
extern int d_1cdb6c;                    // 0x1CDB6C
extern int d_1cdb70;                    // 0x1CDB70
extern int d_1cdb74;                    // 0x1CDB74
extern int d_1cdc14;                    // 0x1CDC14
extern int d_1cdc1a;                    // 0x1CDC1A
extern int d_1cdc1c;                    // 0x1CDC1C
extern int d_1cdc1e;                    // 0x1CDC1E
extern int d_1cdc20;                    // 0x1CDC20
extern int d_1cdc26;                    // 0x1CDC26
extern int d_1cdc28;                    // 0x1CDC28
extern int d_1cdc2a;                    // 0x1CDC2A
extern short d_1cdc44;                  // 0x1CDC44 Breiten short,unsigned short
extern int d_1cdc48;                    // 0x1CDC48
extern int d_1cdc4c;                    // 0x1CDC4C
extern int d_1cdca0;                    // 0x1CDCA0
extern int d_1cdca4;                    // 0x1CDCA4
extern int d_1cdca8;                    // 0x1CDCA8
extern int d_1cdcac;                    // 0x1CDCAC
extern int d_1cdda0;                    // 0x1CDDA0
extern unsigned d_1ce424;               // 0x1CE424
extern int d_1ce65c;                    // 0x1CE65C
extern const char d_1b9088[];           // Text 0x1B9088
extern const char d_1b94b8[];           // Text 0x1B94B8

#include <stdlib.h>
extern int d_1a9afc;
extern int d_1a9a74;
extern short d_1a995c;
extern short d_1a995e;
extern char d_1a98e2;
extern unsigned d_1c6b98;
extern char *d_1cd210;
extern unsigned char *d_1c6b48;
extern unsigned char d_1c3c40[];
extern int d_1c3c38;
struct ENT { char kind; char pad[3]; int p4; int key; int x; int y; int a; int b; int c; int d; void *src; };
struct KE { int key; struct ENT *e; };
struct V3 { int x; int y; int z; };
extern struct ENT *d_1c3c3c;
extern struct KE d_1c3970[];
extern struct ENT d_1c5d10[];
#define I(p,o) (*(int *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define U8(p,o) (*(unsigned char *)((char *)(p) + (o)))
int FMUL(int a, int b);
#pragma aux FMUL = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify [edx] value [eax];
int FDIV(int a, int b);
#pragma aux FDIV = "mov edx,eax" "sar edx,16" "shl eax,16" "idiv ebx" parm [eax] [ebx] modify [edx] value [eax];
#define ABSX(x) abs(x)
unsigned f_14e1f0(void *p1);
int f_14e288(void *p1, void *p2);
int f_14e4a4(void);
int f_14e5c8(int p1);
int f_14ea94(void *p1, int p2, int p3, int p4);
int f_14dd20(int p1, int p2, void *p3, void *p4, int *p5);
int f_14ec24(int p1, int p2, int p3, int *p4, int p5, int p6, void *p7);
#pragma aux f_14eeac "*";
#pragma aux f_14f61c "*";
#pragma aux f_14fa64 "*";
#pragma aux f_14fc78 "*";
#pragma aux f_14fd64 "*";

//@ f_14eeac  groesse 1904 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schneidet einen gerichteten 2D-Bewegungsabschnitt von (p3, p4) mit dem Verschiebungsvektor
 *   (p5, p6) gegen das Kollisionspolygon p1 (Umrissmodus p2) und trägt bis zu p8 gefundene Schnittpunkte samt
 *   Schnittparameter key, Normalenvektor und Trefferkoordinaten in das Ergebnisarray p7 ein. Bei p2 == 1
 *   (aufgeweiteter Kollisionsumriss) werden neben den geraden Kantenabschnitten zusätzlich die Kreisbögen um die
 *   Polygonecken per quadratischer Gleichung (f_16d3d0) und Ecksektor-Prüfung (f_14ec24) auf Schnittpunkte
 *   getestet.
 * - Eingaben:
 *   - p1: Zeiger auf den 56-Byte-Kollisionsdatensatz.
 *   - p2: Umriss-Modus (1 = aufgeweiteter Außenumriss mit Eckkreisen, 2 = Originalkanten, 3 = Innenumriss).
 *   - p3, p4: Startpunkt (X, Z) des Bewegungsstrahls.
 *   - p5, p6: Richtungs-/Längenvektor (dX, dZ) der Bewegung.
 *   - p7: Zielarray (struct ENT *) für die gefundenen Schnittpunkte.
 *   - p8: Maximale Anzahl einzutragender Schnittpunkte.
 * - Rückgabewert: Anzahl der gefundenen Schnittpunkte (nres).
 * - Wichtige Variablen:
 *   - xl, xh, yl, yh: Achsenparallele Bounding-Box des Bewegungsabschnitts zur schnellen Vorabfilterung.
 *   - q, t1, c2: Normierte Schnittparameter entlang des Strahls (0 bis 0x10000).
 === Ende Beschreibung === */
int mul14eeac(int,int);
#pragma aux mul14eeac = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int div14eeac(int,int);
// haelt die Registerzuteilung wie im Original
#pragma aux div14eeac = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm [edx] [ebx] modify exact [eax ebx edx] value [eax];
int f_14eeac(char *p1, unsigned p2, int p3, int p4, int p5, int p6, struct ENT *p7, int p8)
{
  int nres;
  int xl;
  int xh;
  int yh;
  int yl;
  int *pe;
  int i;
  int n;
  int hi;
  int x0;
  int dx;
  int y0;
  int lo;
  int t2;
  int d;
  int u;
  int dy;
  int t;
  int q;
  int w;
  int u2;
  int cnt;
  int m54;
  int m38;
  int m1c;
  int m5c;
  int r;
  int f1;
  char flag;
  int a;
  int b;
  int uv;
  int m40;
  int neg;
  int c;
  int s;
  int c2;
  int t1;
  int v;
  int dd;
  int e1;
  int ea;
  int f2;
  int e2;
  int eb;
  int ylo;
  int yhi;
  if (p1 == 0 || p7 == 0)
    return 0;
  nres = 0;
  xl = xh = p3;
  yl = yh = p4;
  if (p5 < 0)
    xl = p3 + p5;
  else
    xh = p3 + p5;
  if (p6 < 0)
    yl += p6;
  else
    yh += p6;
  switch (p2) {
  case 1:
    n = U16(p1, 4);
    pe = (int *)I(p1, 0x2c);
    break;
  case 3:
    n = U16(p1, 6);
    pe = (int *)I(p1, 0x30);
    break;
  case 2:
  default:
    n = U16(p1, 2);
    pe = (int *)I(p1, 0x28);
    break;
  }
  for (i = n + 1; --i; ) {
    if (p2 != 1 || (i & 1) == 0) {
      if (pe[0] < pe[4]) {
        lo = pe[0];
        hi = pe[4];
      } else {
        hi = pe[0];
        lo = pe[4];
      }
      if (hi >= xl && lo <= xh) {
        if (pe[1] < pe[5]) {
          ylo = pe[1];
          yhi = pe[5];
        } else {
          yhi = pe[1];
          ylo = pe[5];
        }
        if (yhi >= yl && ylo <= yh) {
          x0 = pe[0];
          y0 = pe[1];
          dx = pe[4] - x0;
          dy = pe[5] - y0;
          t = t2 = f_16d3b7(x0 - p3, dy, y0 - p4, dx);
          d = f_16d3b7(p5, dy, dx, p6);
          if (d != 0 && ((t >= 0 && t <= d) || (t2 <= 0 && t2 >= d))) {
            u = f_16d3b7(x0 - p3, p6, y0 - p4, p5);
            if ((u >= 0 && u < d) || (u <= 0 && u > d)) {
              if (nres >= p8)
                return nres;
              q = div14eeac(t2, d);
              p7->key = mul14eeac(0xfd70, q);
              p7->a = pe[2];
              p7->b = pe[3];
              p7->c = dx;
              p7->d = dy;
              p7->x = p3 + mul14eeac(q, p5);
              p7->y = p4 + mul14eeac(q, p6);
              nres++;
              p7++;
            }
          }
        }
      }
    }
    pe += 4;
  }
  if (p2 == 1) {
    n = U16(p1, 2);
    m5c = I(p1, 0x2c);
    u2 = U16(p1, 4);
    pe = (int *)I(p1, 0x28);
    m1c = m5c + ((u2 << 4) - 0x10);
    flag = 2 * n > u2;
    r = f_16d33f(I(p1, 0x18), I(p1, 0x18), 0, 0);
    cnt = n + 1;
    m54 = m5c + 0x10;
    for (; --cnt; ) {
      if (!flag || pe[0] != pe[4] || pe[1] != pe[5]) {
        m40 = m1c;
        m38 = m5c;
        w = m54;
        m1c = w;
        m54 = w + 0x20;
        m5c += 0x20;
        lo = pe[0] - I(p1, 0x18);
        hi = pe[0] + I(p1, 0x18);
        if (hi < xl || lo > xh)
          goto next;
        lo = pe[1] - I(p1, 0x18);
        hi = pe[1] + I(p1, 0x18);
        if (hi >= yl && lo <= yh) {
          a = p3 - pe[0];
          b = p4 - pe[1];
          uv = f_16d33f(p5, p5, p6, p6);
          neg = -f_16d33f(a, p5, b, p6);
          dd = f_16d33f(a, a, b, b) - r;
          if (ABSX(uv) > ABSX(neg >> 15)) {
            c = div14eeac(neg, uv);
            if (ABSX(uv) > ABSX(dd >> 15)) {
              q = div14eeac(dd, uv);
              s = mul14eeac(c, c) - q;
              if (s >= 0) {
                s = f_16d3d0(s);
                t1 = c - s;
                if (t1 >= 0 && t1 <= 0x10000) {
                  e1 = p3 + mul14eeac(t1, p5);
                  f1 = p4 + mul14eeac(t1, p6);
                  if (f_14ec24(e1, f1, r, pe, m40, m38, p1) != 0) {
                    if (nres >= p8)
                      return nres;
                    ea = e1 - pe[0];
                    eb = f1 - pe[1];
                    v = mul14eeac(0xfae1, t1);
                    p7->key = v;
                    p7->a = ea;
                    p7->b = eb;
                    p7->c = eb;
                    p7->c = -p7->c;
                    p7->d = ea;
                    p7->x = p3 + mul14eeac(v, p5);
                    p7->y = p4 + mul14eeac(v, p6);
                    nres++;
                    p7++;
                  }
                }
                c2 = c + s;
                if (c2 >= 0 && c2 <= 0x10000) {
                  e2 = p3 + mul14eeac(c2, p5);
                  f2 = p4 + mul14eeac(c2, p6);
                  if (f_14ec24(e2, f2, r, pe, m40, m38, p1) != 0) {
                    if (nres >= p8)
                      return nres;
                    ea = e2 - pe[0];
                    eb = f2 - pe[1];
                    v = mul14eeac(0xfae1, c2);
                    p7->key = v;
                    p7->a = ea;
                    p7->b = eb;
                    p7->c = eb;
                    p7->c = -p7->c;
                    p7->d = ea;
                    p7->x = p3 + mul14eeac(v, p5);
                    p7->y = p4 + mul14eeac(v, p6);
                    nres++;
                    p7++;
                  }
                }
              }
            }
          }
        }
      }
next:
      pe += 4;
    }
  }
  return nres;
}


//@ f_14f61c  groesse 1096 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet für ein spezielles Stufen-/Übergangspolygon p1 innerhalb der Sektorgeometrie p2
 *   einmalig die minimale und maximale Höhendifferenz (min_dy, max_dy in p1 + 0x2c und p1 + 0x2e) zu den
 *   darunterliegenden begehbaren Bodenpolygonen der Szene und markiert das Polygon durch Setzen von Bit 0x40
 *   (*(char *)p1 |= 0x40) als vorberechnet.
 * - Eingaben: p1 (Zeiger auf die Polygonstruktur), p2 (Zeiger auf das übergeordnete Mesh/Sektorobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: pts (Eckpunkte des Polygons p1), min_dy, max_dy (minimale und maximale Stufenhöhe
 *   relativ zum Boden).
 === Ende Beschreibung === */
void f_14f61c(unsigned short *p1, char *p2)
{
  struct V3 pts[8];
  char hit[8];
  int min_dy;
  int val;
  int s68;
  int s64;
  int s60;
  int s6c;
  int arrB;
  int i;
  int m;
  char *sec;
  int j;
  int n;
  char *obj;
  int min_hit;
  int max_dy;
  int arrA;
  unsigned short *q;
  struct V3 *p;
  char *part;
  int k;

  *(short *)((char *)p1 + 0x2c) = *(short *)((char *)p1 + 0x2e) = 0;
  min_hit = 0x7fffffff;
  min_dy = 0x7fffffff;
  max_dy = (int)0x80000000;
  arrB = I(p2, 0x40);
  n = U8(p1, 1);
  arrA = I(p2, 0x38);
  q = p1 + 1;
  s68 = d_1c6b68;
  s64 = d_1c6b64;
  s6c = d_1c6b6c;
  s60 = d_1c6b60;
  d_1c6b6c = 0x7fffffff;
  d_1c6b64 = (int)0x80000000;
  d_1c6b68 = 0x7fffffff;
  d_1c6b60 = (int)0x80000000;
  *((((unsigned)p1) & 0) ? (int *)0 : &d_1c6b60) = (int)0x80000000; // haelt die Registerzuteilung wie im Original
  p = pts;
  for (i = 0; i < n; i++, p++) {
    hit[i] = 0;
    *p = *(struct V3 *)(arrA + U16(arrB + *q * 12, 0) * 12);
    if (p->x < d_1c6b68) d_1c6b68 = p->x;
    if (p->x > d_1c6b64) d_1c6b64 = p->x;
    if (p->z < d_1c6b6c) d_1c6b6c = p->z;
    if (p->z > d_1c6b60) d_1c6b60 = p->z;
    q++;
  }
  d_1c6b68 -= d_1a9afc * 2;
  d_1c6b64 += d_1a9afc * 2;
  d_1c6b6c -= d_1a9afc * 2;
  d_1c6b60 += d_1a9afc * 2;
  obj = d_1cd210;
  for (i = 0; i < d_1a99ac; i++, obj += 0x30) {
    if (obj[0xa] & 0x80) continue;
    sec = (char *)I(obj, 0x28);
    if (sec == 0) continue;
    if (I(sec, 0x2c) < d_1c6b68) continue;
    if (I(sec, 0x20) > d_1c6b64) continue;
    if (I(sec, 0x34) < d_1c6b6c) continue;
    if (I(sec, 0x28) > d_1c6b60) continue;
    part = (char *)I(sec, 0x44);
    m = U16(sec, 0xa);
    for (j = 0; j < m; j++, part += 0x30) {
      if (!(f_14e1f0(part) & 1)) continue;
      p = (struct V3 *)I(sec, 0x3c);
      if (p[U16(part, 0x24)].y < 0x4ccc) continue;
      if (!f_14e288(part, obj)) continue;
      if (!f_14e5c8(1)) continue;
      p = pts;
      for (k = 0; k < n; k++, p++) {
        if (f_14ea94(d_1c6b48, 1, p->x, p->z) &&
            f_14dd20(p->x, p->z, obj, part, &val)) {
          hit[k] = 1;
          if (val < min_hit) min_hit = val;
          val = p->y - val;
          if (val < min_dy) min_dy = val;
          if (val > max_dy) max_dy = val;
        }
      }
    }
  }
  d_1c6b68 = s68;
  d_1c6b64 = s64;
  d_1c6b6c = s6c;
  d_1c6b60 = s60;
  for (i = 0; i < n; i++) {
    if (hit[i] == 0 && min_hit < 0x7fffffff) {
      val = pts[i].y - min_hit;
      if (val < min_dy) min_dy = val;
      if (val > max_dy) max_dy = val;
    }
  }
  *(short *)((char *)p1 + 0x2c) = (short)(min_dy >> 16);
  *(char *)p1 |= 0x40;
  *(short *)((char *)p1 + 0x2e) = (short)(max_dy >> 16);
}


//@ f_14fa64
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht alle aktiven 3D-Objekte der Szene (d_1cd210, Anzahl d_1a99ac) nach Polygonen,
 *   deren Bounding-Box das aktuelle Bewegungssuchfenster (d_1c6b68..d_1c6b64, d_1c6b6c..d_1c6b60) überlappt,
 *   klassifiziert jedes Polygon über f_14e1f0, übernimmt relevante Boden-, Treppen- und Wandpolygone über
 *   f_14e288 in die Kollisionsliste d_1c3c40 und berechnet für jedes aufgenommene Polygon über f_14e5c8(1) und
 *   f_14e5c8(3) die verschobenen Kollisionsumrisse.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c3c40: Array der gesammelten 56-Byte-Kollisionsdatensätze.
 *   - d_1a9a10: Anzahl der in d_1c3c40 eingetragenen Kollisionspolygone.
 === Ende Beschreibung === */
#define FW14 (*(unsigned short *)&d_1c6b98)
#define FB14 (*(unsigned char *)&d_1c6b98)
// Opus W63 05.11.: neu gefasst, krueckenfrei. d_1a9a10 = 0 zuerst (erster Null-Store wandert ans Blockende,
// Rover-Anfrage gibt der Adresskonstante ECX), Basis b = sec->3c als eigene Lokale (EBP), Vergleiche mit dem Feld links.
void f_14fa64(void)
{
  char *obj;
  char *sec;
  char *part;
  char *rec;
  unsigned r;
  int i, j, flag, n;
  int v;
  int k, b;

  d_1a9a10 = 0;
  d_1c6b70 = 0;
  d_1c6b48 = d_1c3c40;
  d_1c6b44 = d_1cd20c;
  i = 0;
  obj = d_1cd210;
  for (; i < d_1a99ac; i++, obj += 0x30) {
    if (obj[0] == 0) continue;
    if (obj[0xa] & 0x80) continue;
    sec = (char *)I(obj, 0x28);
    if (sec == 0) continue;
    if (I(sec,0x2c) < d_1c6b68) continue;
    if (I(sec,0x20) > d_1c6b64) continue;
    if (I(sec,0x34) < d_1c6b6c) continue;
    if (I(sec,0x28) > d_1c6b60) continue;
    flag = U16(obj, 0xa) & 0x200u;
    n = U16(sec, 0xa);
    part = (char *)I(sec, 0x44);
    for (j = 0; j < n; j++, part += 0x30) {
      r = f_14e1f0(part);
      d_1c6b98 = r;
      if (r & 0x80) continue;
      k = U16(part,0x24);
      b = I(sec,0x3c);
      k = 12*k + b;
      if ((r & 1) && ((int *)k)[1] < 0x3333) continue;
      if (d_1c6b98 & 0x40) {
        if (flag != 0) continue;
        v = ((int *)k)[1];
        if (v < -0xccc) continue;
        if (v >= 0xc000) continue;
        if ((part[0] & 0x40) == 0)
          f_14f61c((unsigned short *)part, sec);
        if (*(short *)(part + 0x2c) > d_1a995c) continue;
        if (*(short *)(part + 0x2e) < d_1a995e) continue;
        FW14 = FW14 & 0xfffffebc;
        FW14 = FW14 | 0x102;
      }
      if (flag != 0) {
        FW14 = FW14 & 0xfefc;
        FB14 = FB14 | 1;
      }
      if (f_14e288(part, obj) != 0) {
        if (obj[0xb] & 8) {
          ((unsigned char *)&d_1c6b98)[1] = ((unsigned char *)&d_1c6b98)[1] | 2;
          d_1a98e2 = 1;
        }
        f_14e5c8(1);
        f_14e5c8(3);
        rec = (char *)d_1c6b48;
        *(short *)(rec + 8) = (short)j;
        I(rec, 0x34) = (int)obj;
        I(rec, 0xc) = (int)d_1c6b98;
        if (f_14e4a4() == 0) break;
      }
    }
  }
}

#undef FW14
#undef FB14

//@ f_14fc78  groesse 236 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt ein einzelnes Kollisionsereignis p2 mit dem Distanzschlüssel p1 per binärer Suche
 *   aufsteigend sortiert in die Ereignisliste d_1c3970 (Maximalgröße 90 Einträge in d_1c5d10, aktueller Zähler
 *   in d_1c6ba0) ein.
 * - Eingaben: p1 (Distanz-/Zeit-Schlüssel entlang des Bewegungsvektors), p2 (Zeiger auf den
 *   40-Byte-Ereignisdatensatz struct ENT).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c3970 (sortiertes Schlüssel-Zeiger-Array), d_1c6ba0 (Anzahl der Einträge).
 === Ende Beschreibung === */
void f_14fc78(int p1, struct ENT *p2)
{
  register int count;
  int lo, hi, mid, next, offset;
  unsigned flag;
  int k;
  struct ENT *entry;
  struct KE *slot;
  count = I(&d_1c6ba0, 0);
  if (count < 90) {
    offset = count * 5;
    next = count + 1;
    d_1c3970[count].key = 0x7fffffff;
    entry = (struct ENT *)((char *)d_1c5d10 + offset * 8);
    I(&d_1c6ba0, 0) = next;
  } else {
    if (p1 >= d_1c3c38) return;
    entry = d_1c3c3c;
  }
  flag = I(p2, 4) & 4;
  hi = I(&d_1c6ba0, 0) - 1;
  lo = 0;
search14:
  if (hi - lo >= 2) goto middle14;
  k = d_1c3970[lo].key;
  if (p1 >= k) {
    if (flag) {
      if (p1 != k) lo = hi;
    } else {
      lo = hi;
    }
  }
  goto found14;
middle14:
  mid = (lo + hi) >> 1;
  k = d_1c3970[mid].key;
  if (p1 < k || (flag && p1 == k))
    hi = mid;
  else
    lo = mid;
  goto search14;
found14:
  count = I(&d_1c6ba0, 0);
  slot = &d_1c3970[lo];
  lo = count - lo;
  lo--;
  memmove(slot + 1, slot, lo * 8);
  slot->key = p1;
  slot->e = entry;
  *entry = *p2;
}


//@ f_14fd64  groesse 748 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt für den geplanten Bewegungsschritt von (d_1c6b78, d_1c6b7c) nach (d_1c6b84,
 *   d_1c6b80) über alle in d_1c3c40 gesammelten Kollisionspolygone die sortierte Gesamtliste aller Ein- und
 *   Austrittsereignisse (d_1c3970). Dazu prüft sie für jedes Polygon, ob der Startpunkt oder Endpunkt bereits im
 *   Polygon liegt (f_14ea94), bestimmt alle Kantenschnitte über f_14eeac, sortiert diese nach Entfernung und
 *   trägt sie abwechselnd als Eintritt (kind = 1) und Austritt (kind = 2) über f_14fc78 ein.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: list (lokales Array für bis zu 20 Schnittpunkte pro Polygon), d_1c6ba0 (wird zu Beginn
 *   auf 0 gesetzt).
 === Ende Beschreibung === */
void f_14fd64(void)
{
  struct ENT list[20];
  struct ENT tmp;
  struct ENT *p;
  int i, j, m;
  int n, flag, k;
  int y0, x0, width, height;
  char *rec;

  x0 = d_1c6b78;
  y0 = d_1c6b7c;
  width = d_1c6b84 - x0;
  height = d_1c6b80 - y0;
  *(int *)&d_1c6ba0 = 0;   // haelt die Registerzuteilung wie im Original
  rec = (char *)d_1c3c40;
  i = 0;
  while (i < d_1a9a10) {
    flag = 0;
    *rec = 0;
    if (f_14ea94(rec, 1, d_1c6b78, d_1c6b7c)) {
      tmp.key = 0;
      tmp.x = d_1c6b78;
      tmp.y = d_1c6b7c;
      tmp.a = 0;
      tmp.b = 0;
      tmp.kind = 1;
      tmp.c = 0;
      tmp.d = 0;
      tmp.p4 = I(rec, 0xc);
      tmp.src = rec;
      flag = 1;
      f_14fc78(0, &tmp);
    }
    if (f_14ea94(rec, 1, d_1c6b84, d_1c6b80)) {
      tmp.key = d_1a9a74;
      tmp.a = 0;
      tmp.b = 0;
      tmp.x = d_1c6b84;
      tmp.c = 0;
      tmp.y = d_1c6b80;
      tmp.d = 0;
      tmp.kind = 1;
      tmp.p4 = I(rec, 0xc);
      tmp.src = rec;
      f_14fc78(d_1a9a74, &tmp);
    }
    n = f_14eeac(rec, 1, x0, y0, width, height, list, 20);
    if (n > 0) {
      for (m = n; m > 0; m--) {
        p = list + 1;
        for (j = 1; j < m; j++, p++) {
          if (p[-1].key > p->key) {
            tmp = *p;
            *p = p[-1];
            p[-1] = tmp;
          }
        }
      }
      p = list;
      k = (flag != 0) + 1;
      for (j = n + 1; --j; ) {   // haelt die Registerzuteilung wie im Original
        p->kind = k;
        p->p4 = I(rec, 0xc);
        p->src = rec;
        k = k == 1 ? 2 : 1;
        f_14fc78(p->key, p);
        p++;
      }
    }
    i++;
    rec += 0x38;
  }
}


