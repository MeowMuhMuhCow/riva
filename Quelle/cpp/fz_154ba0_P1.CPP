/* === Beschreibung (Katalog) ===
 * Einheit fz_154ba0 (0x154BA0 - 0x154E78)
 *
 * Überblick
 * Diese aus fz_14dc28_t6 abgetrennte Einheit enthält die Aufzeichnungsfunktionen (Kamera-/Bewegungs-Rekorder)
 * der 3D-Engine. Damit lassen sich Kamerafahrten und Bewegungspfade durch ein 3D-Dungeon inklusive Zeitstempel,
 * Raumnummer, 3D-Position und Blickwinkeln in einem Speicherpuffer mitschneiden (f_154ba0, f_154d68, f_154e18),
 * die später über die Wiedergabefunktionen in fz_14dc28_t7a (f_154e78, f_154f08) abgespielt werden können.
 === Ende Beschreibung === */
// CC wcc386
// fz_154ba0 (Schatten ueber Riva) - abgetrennt aus fz_14dc28_t6 (08.11. Claude I15): Code 0x154BA0-0x154E78
#include <string.h>
#include <stdlib.h>
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
int f_16d3d0();                       // nicht in clobber.tsv
int f_16d4d8(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d7e7(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d8ad(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16e93c(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_16ecb4(int p1);                                   // reg eax stapel 0
int f_16ecba(int p1);                                   // reg eax stapel 0
int f_16f693(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_1702b8(int p1);                                   // reg eax stapel 0
int f_171000(int p1, int p2);                           // reg eax edx stapel 0
int f_171994(int p1, int p2);                           // reg eax edx stapel 0
int f_172028(int p1, int p2);                           // reg eax edx stapel 0
int f_172148(int p1, int p2);                           // reg eax edx stapel 0
int f_172278();                                         // reg - stapel 0
int f_172628(int p1);                                   // reg eax stapel 0
int f_17464c(int p1);                                   // reg eax stapel 0
int f_1750b6();                       // nicht in clobber.tsv
int f_176f10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1782e8(int p1);                                   // reg eax stapel 0
extern int d_1a98dd;                    // 0x1A98DD
extern int d_1a98e1;                    // 0x1A98E1
extern int d_1a98e2;                    // 0x1A98E2
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
extern int d_1a9914;                    // 0x1A9914
extern int d_1a9918;                    // 0x1A9918
extern int d_1a991c;                    // 0x1A991C
extern int d_1a9928;                    // 0x1A9928
extern int d_1a9935;                    // 0x1A9935
extern int d_1a9936;                    // 0x1A9936
extern int d_1a9937;                    // 0x1A9937
extern int d_1a993b;                    // 0x1A993B
extern int d_1a9940;                    // 0x1A9940
extern int d_1a9945;                    // 0x1A9945
extern int d_1a994d;                    // 0x1A994D
extern int d_1a995c;                    // 0x1A995C
extern int d_1a995e;                    // 0x1A995E
extern int d_1a9960;                    // 0x1A9960
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
extern int d_1a9b80;                    // 0x1A9B80
extern int d_1a9b84;                    // 0x1A9B84
extern int d_1a9b8c;                    // 0x1A9B8C
extern int d_1a9c64;                    // 0x1A9C64
extern int d_1a9c68;                    // 0x1A9C68
extern int d_1a9c6c;                    // 0x1A9C6C
extern int d_1ad4d4;                    // 0x1AD4D4
extern int d_1b8db0;                    // 0x1B8DB0
extern int d_1c3970;                    // 0x1C3970
extern int d_1c3974;                    // 0x1C3974
extern int d_1c3978;                    // 0x1C3978
extern int d_1c3c38;                    // 0x1C3C38
extern int d_1c3c3c;                    // 0x1C3C3C
extern int d_1c3c40;                    // 0x1C3C40
extern int d_1c5d10;                    // 0x1C5D10
extern int d_1c6b20;                    // 0x1C6B20
extern int d_1c6b24;                    // 0x1C6B24
extern int d_1c6b44;                    // 0x1C6B44
extern short d_1c6b48;                  // 0x1C6B48 Breiten short,short,unsigned,unsigned short
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
extern int d_1c6b98;                    // 0x1C6B98
extern int d_1c6b9c;                    // 0x1C6B9C
extern int d_1c6ba0;                    // 0x1C6BA0
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
extern int d_1c76f8;                    // 0x1C76F8
extern int d_1c76f9;                    // 0x1C76F9
extern int d_1c7734;                    // 0x1C7734
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
extern int d_1cd204;                    // 0x1CD204
extern int d_1cd20c;                    // 0x1CD20C
extern int d_1cd210;                    // 0x1CD210
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
extern int d_1cdb3c;                    // 0x1CDB3C
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


#define I4(p,o) (*(int *)((char *)(p) + (o)))
#define U2(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define S2(p,o) (*(short *)((char *)(p) + (o)))
#define U1(p,o) (*(unsigned char *)((char *)(p) + (o)))
#define P f_16ebd8
struct TR { short id; short pad; int v0, v1, v2, v3; unsigned short s0, s1, s2, s3; int t; };
struct GV { int v0, v1, v2, v3; unsigned short s0, s1, s2, s3; };
struct V6 { int a[6]; };
extern struct GV d_1c90c0;
extern struct TR *d_1cdc44;
extern int *d_1cdc40;
extern unsigned d_1cdb40, d_1cdb1c;
extern unsigned char d_1a993d, d_1a993e, d_1a993f, d_1a994b, d_1a9930, d_1a993c, d_1a9933, d_1a9942, d_1a9943, d_1a9944, d_1a9949, d_1a994f, d_1a9b7c, d_1a9950, d_1a9947, d_1a9948, d_1a9941, d_1cdc2a;
extern short d_1a996a, d_1a9962;
extern unsigned short d_1a9964, d_1a9966;
extern unsigned short d_1c8ff8[], d_1c8ff6[], d_1c7230[], d_1c7168[];
extern char *d_1cd200;
extern void (*d_1a990c)(int, int, int, int, int, int);
extern void (*d_1a9910)(int, int, int, int);
extern const double d_1b945c;
extern char d_1c72f8[];
int f_149470(int p1);
unsigned f_16fc19(void);
int f_1750bc(void);
int f_163484(int p1, int p2);
int f_16fb53(int c, int x, int y);
int f_16fb72(int c, int x, int y);
int f_16ebd8(int, ...);
int f_155f70(void *p);
int f_1560ac(void);
int f_1564cc(void);
int f_152e64(void);
int f_1535e8(void);
int f_1528cc(void);
int f_1528f8(void);
int f_151b50(void);
int f_17684a(char *p, int n);
#pragma aux f_16fb53 parm caller [eax] modify exact [];
#pragma aux f_16fb72 parm caller [eax] modify exact [];
#pragma aux f_155f70 modify exact [eax];
#pragma aux f_1560ac modify exact [eax];
#pragma aux f_1564cc modify exact [eax];
#pragma aux f_152e64 modify exact [eax];
#pragma aux f_1535e8 modify exact [eax];
#pragma aux f_1528cc modify exact [eax];
#pragma aux f_1528f8 modify exact [eax];
#pragma aux f_151b50 modify exact [eax];
#pragma aux f_16fc19 modify exact [eax ecx edx];
#pragma aux f_1750bc modify exact [eax ebx ecx edx esi edi];
#pragma aux f_17684a parm [eax] [edx] modify exact [eax ecx edx esi];

extern int d_1a9920;
extern int d_1a9984;
extern int d_1a9988;
extern int d_1a99b8;
extern int d_1a99bc;
extern int d_1a99c8;
extern int d_1a9a08;
extern int d_1a9ab0;
extern int d_1a9ae8;
extern const char d_1b8fb4[];
extern const char d_1b8fc0[];
extern const char d_1b8fd8[];
extern const char d_1b9014[];
extern const char d_1b902c[];
extern const char d_1b9058[];
extern const char d_1b905c[];
extern const char d_1b9064[];
extern const char d_1b90a4[];
extern const char d_1b90d0[];
extern const char d_1b90fc[];
extern const char d_1b9134[];
extern const char d_1b9168[];
extern const char d_1b91a8[];
extern const char d_1b91e8[];
extern const char d_1b91ec[];
extern const char d_1b9220[];
extern const char d_1b924c[];
extern const char d_1b9254[];
extern const char d_1b925c[];
extern const char d_1b9284[];
extern const char d_1b92ac[];
extern const char d_1b92f4[];
extern const char d_1b92fc[];
extern const char d_1b9304[];
extern const char d_1b930c[];
extern const char d_1b9314[];
extern const char d_1b9320[];
extern const char d_1b9328[];
extern const char d_1b9330[];
extern const char d_1b9338[];
extern const char d_1b9378[];
extern const char d_1b9388[];
extern const char d_1b9394[];
extern const char d_1b9398[];
extern const char d_1b939c[];
extern const char d_1b93b0[];
extern const char d_1b93c4[];
extern const char d_1b93d8[];
extern const char d_1b93ec[];
extern const char d_1b9400[];
extern const char d_1b9414[];
extern const char d_1b9428[];
extern const char d_1b943c[];
extern const char d_1b9448[];
extern const char d_1b9450[];
extern int d_1cdb08;
extern int d_1cdb0c;
extern int d_1cdb10;
extern int d_1cdb14;
extern int d_1cdb18;
extern int d_1cdb20;
extern int d_1cdb30;
extern int d_1cdb34;
#pragma aux f_153ac8 "*";
#pragma aux f_154af8 "*";
#pragma aux f_154ba0 "*";
#pragma aux f_154d68 "*";
#pragma aux f_154e18 "*";
#define EQ(x,v) (((x)==(v))?1:0)
void sperre(void);
// haelt die Registerzuteilung wie im Original
// EAX-Sperre: "mov esi,eax" bleibt echte Kopie hinter der Zaehlerlast und vor dem Vergleich.
// Vermutete Originalform: Zaehler direkt global + Inline-Betrag "parm nomemory [eax] modify nomemory [edx]" (BEFUND FL03_1345).
#pragma aux sperre = "" parm [] modify exact [eax ebx];
//@ f_154ba0  groesse 456 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft während einer aktiven Kamera-/Bewegungsaufzeichnung (d_1a9947 != 0), ob sich die
 *   aktuelle Kameraposition oder Blickrichtung (d_1c90c0) gegenüber dem letzten aufgezeichneten Keyframe
 *   (d_1cdc44[-1]) merklich verändert hat (mindestens 0x10000 in X/Y/Z, 0x222 in einem Drehwinkel oder 10
 *   Zeitticks Abstand) oder ob p1 != 0 einen Eintrag erzwingt. Trifft dies zu, speichert sie einen neuen
 *   32-Byte-Keyframe (struct TR) mit Sektor-ID (d_1cdb3c), Pose (d_1c90c0) und Zeitstempel t im
 *   Aufzeichnungspuffer d_1cdc44 (bei Pausen über 200 Ticks wird zuvor ein Halte-Keyframe eingefügt).
 * - Eingaben: p1 (Erzwingungsflag: 1 = Keyframe unabhängig von der Bewegungsdifferenz aufzeichnen, 0 = nur bei
 *   Änderung).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cdb40: Anzahl der bisher aufgezeichneten Keyframes (n).
 *   - d_1cdb1c: Maximale Kapazität des Aufzeichnungspuffers in Keyframes.
 *   - d_1cdc44: Schreibzeiger auf den nächsten freien Keyframe-Slot.
 === Ende Beschreibung === */
void f_154ba0(int p1)
{
    unsigned t;
    unsigned n;
    int force;
    char *prev;
    struct TR *cursor;
    struct TR *dst;

    n = d_1cdb40;
    force = p1;
    sperre(); // haelt die Registerzuteilung wie im Original
    if (n >= d_1cdb1c) {
        d_1a9947 = 0;
    } else {
        p1 = f_16fc19(); // haelt die Registerzuteilung wie im Original
        t = (unsigned)p1 / 0x2e97 - d_1cdc48;
        cursor = d_1cdc44;
        prev = (char *)cursor - 0x1c;
        d_1cdc4c = cursor[-1].t;
        n = d_1cdb40;
        if (n <= 0 || force != 0
            || abs(d_1c90c0.v0 - *(int *)(prev + 0x00)) >= 0x10000
            || abs(d_1c90c0.v1 - *(int *)(prev + 0x04)) >= 0x10000
            || abs(d_1c90c0.v2 - *(int *)(prev + 0x08)) >= 0x10000
            || abs((int)*(unsigned short *)((char *)&d_1c90c0 + 0x10) - (int)*(unsigned short *)(prev + 0x10)) >= 0x222
            || abs((int)*(unsigned short *)((char *)&d_1c90c0 + 0x12) - (int)*(unsigned short *)(prev + 0x12)) >= 0x222
            || abs((int)*(unsigned short *)((char *)&d_1c90c0 + 0x14) - (int)*(unsigned short *)(prev + 0x14)) >= 0x222
            || (unsigned)(t - d_1cdc4c) >= 10) {
            if (n > 0 && (unsigned)(t - d_1cdc4c) > 200) {
                dst = d_1cdc44 + 1;
                dst[-1].id = (short)d_1cdb3c;
                ++n;
                d_1cdc44 = dst;
                *(struct V6 *)&dst[-1].v0 = *(struct V6 *)&dst[-2].v0;
                dst[-1].t = t - 1;
                if (n >= d_1cdb1c) {
                    d_1a9947 = 0;
                    goto ende;
                }
            }
            dst = d_1cdc44;
            dst->id = (short)d_1cdb3c;
            *(struct V6 *)&dst->v0 = *(struct V6 *)&d_1c90c0;
            {
                unsigned stamp = n == 0 ? 0 : t;
                dst = d_1cdc44 + 1;
                ++n;
                dst[-1].t = stamp;
                d_1cdc44 = dst;
            }
        }
    }
    { int v = d_1cdc48; d_1cdc48 = v; } // haelt die Registerzuteilung wie im Original
ende:
    d_1cdb40 = n;
}
//@ f_154d68  groesse 176 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Startet eine neue Kamera-/Bewegungsaufzeichnung in den übergebenen Speicherpuffer p der
 *   Bytegröße size (mindestens 0x68 Bytes). Sie initialisiert den 2-Wort-Header (p[0] = 0, p[1] = 0), berechnet
 *   die maximale Keyframe-Anzahl d_1cdb1c, setzt den Schreibzeiger d_1cdc44 auf p + 10, merkt sich die Startzeit
 *   d_1cdc48 und schaltet das Aufzeichnungsflag d_1a9947 = 1 scharf.
 * - Eingaben:
 *   - p: Zielpuffer für die aufgezeichnete Kamerafahrt.
 *   - size: Größe des Puffers in Bytes (unsigned).
 * - Rückgabewert: 0 bei Erfolg, sonst ein Fehlercode (0xf002 = Engine nicht bereit, 0xf005 = Nullzeiger, 0xf00b
 *   = Puffer zu klein).
 * - Wichtige Variablen: d_1cdc40 (Basiszeiger des Aufzeichnungspuffers), d_1a9947 (Flag "Aufzeichnung aktiv").
 === Ende Beschreibung === */
int f_154d68(int *p, unsigned size)
{
    int r;
    unsigned n;
    struct TR *t;

    if (d_1a993d == 0) {
        return d_1a996c = 0xf002;
    }
    if (p == 0) {
        {
            union Error { int i; float f; } error;
            // haelt die Registerzuteilung wie im Original
            error.i = 0xf005;
            *(float *)&d_1a996c = error.f;
            return error.i;
        }
    }
    if (size < 0x68) {
        {
            union Error { int i; float f; } error;
            // haelt die Registerzuteilung wie im Original
            error.i = 0xf00b;
            *(float *)&d_1a996c = error.f;
            return error.i;
        }
    }
    d_1cdc40 = p;
    *p = 0;
    p[1] = 0;
    n = size - 8;
    t = (struct TR *)(p + 10);
    d_1cdb40 = 0;
    d_1cdb1c = n >> 5;
    d_1cdc44 = t;
    d_1cdb1c -= 2;
    d_1cdc48 = (unsigned)f_16fc19() / 0x2e97;
    d_1a996c = 0;
    d_1a9947 = 1;
    return 0;
}

//@ f_154e18  groesse 96 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Beendet eine laufende Kamera-/Bewegungsaufzeichnung, indem ein abschließender Keyframe
 *   erzwungen (f_154ba0(1)), das Aufzeichnungsflag d_1a9947 auf 0 gesetzt und im Pufferkopf die Gesamtzahl der
 *   Keyframes (d_1cdc40[0] = d_1cdb40) sowie die Gesamtdauer (d_1cdc40[1]) eingetragen werden.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gesamtgröße der aufgezeichneten Daten in Bytes (d_1cdb40 * 32 + 8) oder 0, falls die Engine
 *   nicht initialisiert ist.
 * - Wichtige Variablen: d_1cdc40 (Header des Aufzeichnungspuffers), d_1cdb40 (Keyframe-Anzahl).
 === Ende Beschreibung === */
int f_154e18(void)
{
    int t;
    if (d_1a993d == 0) return 0;
    f_154ba0(1);
    d_1a9947 = 0;
    d_1cdc40[0] = d_1cdb40;
    d_1cdc40[1] = (unsigned)f_16fc19() / 0x2e97 - d_1cdc48;
    return d_1cdb40 * 32 + 8;
}
