/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t6 (0x153AC8 - 0x154BA0)
 *
 * Überblick
 * Diese Einheit enthält die zentrale Bildberechnungsschleife (f_153ac8) sowie die Bildausgabefunktion (f_154af8)
 * der 3D-Dungeon- und Innenraum-Engine. Hier laufen Kamera- und Bewegungsaktualisierung, Lichtquellenberechnung,
 * Sichtbarkeitsprüfung, Tiefensortierung, Polygon-Rasterisierung samt Mausklick-Objekterkennung (Picking) sowie
 * die abschließende Übertragung des Bildpuffers auf den Bildschirm zusammen.
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s -fp5
// P3 1/5 gleich (suche.py 29.10.2026, Basis fz_14dc28_t6_P1.CPP)
// CC wcc386
// fz_14dc28_t6 (Schatten ueber Riva) - Pass 1, Code 0x153AC8-0x154BA0 (08.11. Claude I15: Modulgrenze, Linker-Nullen 0x154B99-0x154B9F)
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
#pragma aux f_16ecba modify exact [eax];
#pragma aux f_155f70 modify exact [eax];
#pragma aux f_1560ac modify exact [eax];
#pragma aux f_1564cc modify exact [eax];
#pragma aux f_152e64 modify exact [eax];
#pragma aux f_1535e8 modify exact [eax ebx ecx edi];
#pragma aux f_1528cc modify exact [eax];
#pragma aux f_1528f8 modify exact [eax];
#pragma aux f_151b50 modify exact [eax];
#pragma aux f_16fc19 modify exact [eax ecx edx];
#pragma aux f_1750b6 modify exact [eax];
#pragma aux f_1750bc modify exact [eax ebx ecx edx edi];
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
struct S9C { char pad[0x9c]; };
//@ f_153ac8  groesse 4144 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet ein einzelnes 3D-Szenenbild vollständig im Hintergrundpuffer, prüft dabei über
 *   den Farbwert unter dem Mauszeiger beziehungsweie Fadenkreuz ((d_1a99a0, d_1a99a4)), welches Polygon oder
 *   3D-Objekt angeklickt wurde, löst bei gesetztem Klick-Flag (d_1a99a8) die zugehörige Objekt- oder Wandaktion
 *   aus und zeichnet abschließend das optionale 2D-Radar (f_151b50), das Fadenkreuz sowie Debug-Statuszeilen in
 *   das fertige Bild.
 * - Eingaben: Keine direkten Parameter (steuert sich über die globalen 3D-Engine-Variablen wie den
 *   Bildpufferzeiger d_1a991c, die Kamera d_1a9928 und die Klickkoordinaten d_1a99a0/d_1a99a4).
 * - Rückgabewert: int - gibt bei ungültigen Mauskoordinaten oder fehlgeschlagenen Vorbereitungen -1 zurück,
 *   sonst den Rückgabewert der Nachbearbeitungsfunktion f_149470 (beziehungsweise 0 im Normalfall).
 * - Wichtige Variablen:
 *   - d_1a99a0, d_1a99a4: Aktuelle Bildschirmkoordinaten des Prüf- oder Klickpunkts innerhalb des
 *     3D-Sichtfensters (0 <= x < d_1a9a60, 0 <= y < d_1a9a5c).
 *   - d_1a993e, d_1a993f: Statusflags, die beim ersten Durchlauf nach dem Laden einer Szene die Initialisierung
 *     der Renderpuffer (f_161328) und Geometrievorberechnung (f_1564cc) anstoßen.
 *   - p: Zeiger auf das genaue Pixel im Zielbildpuffer (d_1a991c + d_1a99a4 * d_1a9a60 + d_1a99a0), das vor
 *     jedem Polygon-Zeichenaufruf (f_17464c) mit 0xFF markiert wird, um festzustellen, welches Polygon (hit_idx)
 *     dieses Pixel zuletzt überschrieben hat.
 *   - fr: Struktur vom Typ FrameResult_153ac8, in der das getroffene Polygon (hit_id), die zugehörige Objekt-ID
 *     (obj_id) und der berechnete Abstand zum Spieler (dist) für die Interaktionsprüfung gespeichert werden.
 === Ende Beschreibung === */
int f_153ac8(void)
{
    int i;
    int k;
    struct { int found_flag; int hit_id; int j; int old_b84; char *ptr; } fr;
    int r;
    unsigned char flag;
    unsigned char *p;
    int hit_idx;
    unsigned char saved_pixel;

    if (d_1a993d == 0) {
        d_1a996c = 0xf002;
        return 0xf002;
    }
    if (d_1a99a0 < 0)
        d_1a99a0 = 0;
    else if (d_1a99a0 > d_1a998c)
        d_1a99a0 = d_1a998c;
    if (d_1a99a4 < 0)
        d_1a99a4 = 0;
    else if (d_1a99a4 > d_1a9990)
        d_1a99a4 = d_1a9990;
    if (d_1a993e || d_1a993f) {
        if (d_1a993f) {
            int cb;
            r = f_161328();
            if (r)
                return r;
            if (d_1a9928)
                f_160320(d_1a9928);
        }
        if (d_1a9918 == 0) {
            if (f_1564cc()) {
                d_1a996c = 0xf001;
                return 0xf001;
            }
        }
        d_1a993e = 0;
        d_1a994b = 0;
    }
    if (d_1a996a != (short)-1) {
        d_1a994b = 0;
        f_149a88();
    }
    if (d_1a9a1c != d_1a9b80) {
        d_1a9b80 = d_1a9a1c;
        d_1a994b = 0;
    }
    flag = (d_1a9a1c & 0x4000) ? 1 : 0;
    d_1a9930 = (d_1a9a1c & 0x100) ? 1 : 0;
    if (d_1a993c)
        d_1a9933 = 1;
    if (d_1a9942) {
        f_155f70(&d_1c90c0);
        d_1a9942 = 0;
        d_1a9944 = 0;
        d_1a9933 = 1;
    }
    if (d_1a9933 || d_1a9949 || flag != d_1a9b7c || d_1a994f) {
        d_1a9942 = 0;
        d_1a9943 = 0;
        d_1a994b = 0;
        f_1560ac();
        d_1a9b7c = flag;
    }

    p = (unsigned char *)d_1a991c + d_1a99a4 * d_1a9a60;
    p += d_1a99a0;

    d_1a9a64 -= f_16fc19();
    f_1629a8();
    f_172278();
    d_1a9a64 += f_16fc19();
    d_1a9b4c = 0;
    d_1a9b50 = 0;
    f_152e64();
    if (d_1a994b) {
        for (i = 0; i < d_1a9a4c; i++) {
            d_1cd200[i * 0x24 + 0x15] = 0;
        }
    } else {
        int t0, t1;
        d_1a99e4 = 0;
        d_1a99e8 = 0;
        d_1a99ec = 0;
        d_1a99fc = 0;
        d_1a9a04 = 0;
        d_1a9a00 = 0;
        d_1cd1b0 = d_1cd228;
        d_1cdc2a = 0;
        d_1cd31c = d_1cd318;
        d_1a9a68 -= f_16fc19();
        t0 = d_1a9a6c;
        f_1535e8();
        f_1528cc();
        if (!(d_1a9a1c & 0x80))
            f_1528f8();
        t1 = d_1a9a6c - t0;
        d_1a9a68 += f_16fc19() - t1;
    }
    saved_pixel = *p;
    *p = d_1cdb74;
    fr.found_flag = 0;
    fr.old_b84 = d_1a9b84;
    hit_idx = -1;
    d_1a9b84 = 0;
    if (d_1a9a1c & 0x80) {
        if (!d_1a994b)
            f_172028(0, d_1a9a00 - 1);
        for (i = 0; i < d_1a9a00; i++) {
            struct S9C *s = ((struct S9C **)d_1cd220)[i];
            if (s && U1(s, 1) != 3 && (U1(I4(s, 0x44), 0x10) & 1)) {
                f_17464c((int)s);
                d_1a9b50++;
            }
            if (*p != d_1cdb74) {
                int obj;
                struct S9C *s2;
                saved_pixel = *p;
                *p = d_1cdb74;
 // haelt die Registerzuteilung wie im Original
                { struct S9C **q = (struct S9C **)d_1cd220 + i; { struct S9C **u = q; q = u; } s2 = *q; }
                obj = I4(s2, 0x44);
                hit_idx = s2 - (struct S9C *)d_1cd21c;
                d_1a9b84 = obj;
                fr.hit_id = U2(obj, 4);
            }
        }
    } else {
        { char *base = (char *)d_1cd204; int off = d_1a99e4 - 1;  /* haelt die Registerzuteilung wie im Original */ fr.ptr = base + off * 8; }
        for (i = 0; i < d_1a99e4; i++, fr.ptr -= 8) {
            struct S9C **pp;
            int obj = I4(fr.ptr, 4);
            if (d_1a9a1c & 0x400000) {
                if (d_1a9b54 > 0) {
                    for (fr.j = 0; fr.j < d_1a9b54; fr.j++) {
                        if (d_1c8ff8[fr.j] == U2(obj, 4)) {
                            { int o = U2(obj, 0xa) * 4; o += d_1cd220; pp = (struct S9C **)o; }
                            for (k = 0; k < U2(obj, 0xc); k++, pp++) {
                                U1(*pp, 1) = 1;
                            }
                            break;
                        }
                    }
                    if (fr.j >= d_1a9b54)
                        continue;
                }
            } else {
                d_1a9b54 = 0;
            }
            if (U1(obj, 0x10) & 1) {
                if (obj == fr.old_b84)
                    fr.found_flag = 1;
                d_1a9b4c++;
                if ((d_1a9a1c & 0xa0) == 0x20 && !d_1a994b && U2(obj, 0xc) > 1 && !(I4(obj, 0x10) & 0x400)) {
                    f_172028(U2(obj, 0xa), U2(obj, 0xa) + U2(obj, 0xc) - 1);
                }
                pp = &((struct S9C **)d_1cd220)[U2(obj, 0xa)];
                pp = ((unsigned)pp & 0) ? 0 : pp; // haelt die Registerzuteilung wie im Original
                for (k = 0; k < U2(obj, 0xc); k++) {
                    struct S9C *s = *pp++;
                    unsigned char st = U1(s, 1);
                    if (st != 3) {
                        f_17464c((int)s);
                        d_1a9b50++;
                    }
                    if (*p != d_1cdb74) {
                        saved_pixel = *p;
                        *p = d_1cdb74;
                        hit_idx = s - (struct S9C *)d_1cd21c;
                        d_1a9b84 = obj;
                        fr.hit_id = U2(obj, 4);
                    }
                }
                if (fr.found_flag)
                    fr.found_flag = 0;
                if (d_1a9a1c & 0x400)
                    f_163484(obj, d_1cdb70);
                if (d_1a9930) {
                    unsigned t = f_1750b6();
                    while ((unsigned)(f_1750b6() - t) < 0xf)
                        ;
                    f_1750bc();
                }
            }
        }
    }
    d_1a994b = (d_1a9a1c & 0x200000) == 0x200000; // haelt die Registerzuteilung wie im Original
    *p = saved_pixel;
    { extern volatile unsigned char d_1a9a1e;
      if (d_1a9a1e & 8) f_151b50();
    }
    if (d_1a990c) {
        d_1a990c(
            d_1a991c,
            d_1cdb44 + d_1cdb4c,
            d_1cdb48 + d_1cdb50,
            d_1cdb44 + d_1cdb6c,
            d_1cdb48 + d_1cdb68,
            d_1a9a60
        );
        if (!d_1a9950) goto ende;
    } else {
        if (!d_1a9950) goto ende;
    }
    {
        if ((d_1a99a8 & 1) && d_1a9b84) {
            f_149524(U2(I4(d_1a9b84, 0x7c), 2));
            f_149b9c(I4(I4(I4(d_1a9b84, 0x7c), 0x28), 0), 1);
            if (U2(I4(d_1a9b84, 0x7c), 4) != 0)
                f_149470(U2(I4(d_1a9b84, 0x7c), 2));
        }
        P(d_1cd320, 2, 0, d_1a9b00 = d_1cdb5c, d_1ad4d4, d_1b8fc0, (double)d_1a9ae8 * d_1b945c, d_1b8fb4);
        if (d_1a9a1c & 0x10000) {
            P(d_1cd320, 2, 8, d_1a9b00, d_1ad4d4, d_1b8fd8, d_1cdb10, d_1cdb0c, d_1cdb08, d_1cdb14);
        }
        if ((d_1a9a1c & 0x400000) && d_1a9b54 > 0) {
            P(d_1cd320, 2, 0x16, d_1cdb54, d_1ad4d4, d_1b9014);
            for (i = 1; i < d_1a9b54; i++) {
                int off1 = d_1c8ff8[i] * 0x30;
                int base = d_1cd210;
                char *e1, *e2;
                int off2;
                off1 = (off1 & 0) ? 0 : off1; // haelt die Registerzuteilung wie im Original
                e1 = (char *)(base + off1);
                off2 = d_1c8ff6[i] * 0x30;
                e2 = (char *)(base + off2);
                P(
                    d_1cd320,
                    2,
                    (short)(i * 8 + 0x19),
                    d_1cdb54,
                    d_1ad4d4,
                    d_1b902c,
                    I4(I4(e1, 0x28), 0),
                    I4(I4(e2, 0x28), 0),
                    d_1c7168[i],
                    d_1c7230[i]
                );
            }
        }
        if (d_1cd22c) {
            P(
                d_1cd320,
                2,
                0x10,
                d_1a9b00,
                d_1ad4d4,
                d_1b9064,
                I4(I4(d_1cd22c, 0x28), 0),
                (d_1a9962 != (short)-1) ? d_1b9058 : d_1b905c
            );
        }
        if ((d_1a9a1c & 0x40000) && !d_1cdb3c) {
            f_16e93c(d_1cd320, 2, 0x18, d_1a9b00, d_1ad4d4, (int)d_1b9088);
        }
        if (d_1a9a1c & 0x1000) {
            f_162db8(0, 0x5a, 3, (int)&d_1cd294);
            f_162db8(0, 0x62, 3, (int)&d_1cd230);
            if (d_1a9947) {
                P(d_1cd320, 0, 0x68, d_1cdb54, d_1ad4d4, d_1b90a4, d_1cdb40, d_1cdb1c);
            }
            if (d_1a9948) {
                P(d_1cd320, 0, 0x68, d_1cdb54, d_1ad4d4, d_1b90d0, d_1cdb18, d_1cdb20);
            }
            P(
                d_1cd320,
                0,
                0x70,
                d_1a9b00,
                d_1ad4d4,
                d_1b90fc,
                d_1cdb30,
                d_1cdb34 - d_1cdb30,
                (double)d_1a9ab0 * d_1b945c,
                U2(d_1cd1e0, 0xa),
                U2(d_1cd1e0, 0x62),
                U2(d_1cd1e0, 0xba),
                U2(d_1cd1e0, 0x112)
            );
            P(d_1cd320, 0, 0x78, d_1a9b00, d_1ad4d4, d_1b9134, d_1a99ac, d_1a99bc, d_1a99c8);
            P(d_1cd320, 0, 0x80, d_1a9b00, d_1ad4d4, d_1b9168, d_1a99e4, d_1a99fc, d_1a9a00, d_1a9a04);
            P(d_1cd320, 0, 0x88, d_1a9b00, d_1ad4d4, d_1b91a8, d_1a9b4c, d_1a99fc, d_1a9b50, d_1a9a04);
            P(
                d_1cd320,
                0,
                0x90,
                d_1a9b00,
                d_1ad4d4,
                d_1b91ec,
                d_1a9a10,
                d_1a99e0,
                d_1cd214 ? (const char *)I4(I4(d_1cd214, 0x28), 0) : d_1b91e8,
                d_1a9964
            );
            P(d_1cd320, 0, 0x98, d_1a9b00, d_1ad4d4, d_1b9220, d_1a99ec, d_1a99e8, d_1a99b8);
            P(
                d_1cd320,
                0,
                0xa0,
                d_1a9b00,
                d_1ad4d4,
                d_1b925c,
                (double)d_1a9ac4 * d_1b945c,
                d_1a9944 ? d_1b924c : d_1b9254,
                d_1cd218 ? (const char *)I4(I4(d_1cd218, 0x28), 0) : d_1b91e8,
                d_1a9966
            );
            P(d_1cd320, 0, 0xc0, d_1a9b00, d_1ad4d4, d_1b9284, d_1a9a0c, d_1a9a08);
            if (d_1a9b84) {
                int obj = d_1a9b84;
                int mesh = I4(obj, 0x80);
                struct S9C *poly = &((struct S9C *)d_1cd21c)[hit_idx];
                char *sub = (char *)I4(mesh, 0x44) + U2(poly, 8) * 0x30;
                P(
                    d_1cd320,
                    0,
                    0xb0,
                    d_1a9b00,
                    d_1ad4d4,
                    d_1b92ac,
                    I4(mesh, 0),
                    U2(I4(obj, 0x7c), 6),
                    I4(obj, 0x10) & 0x400,
                    U2(mesh, 8),
                    U2(mesh, 0xa),
                    fr.hit_id,
                    (double)I4(obj, 0x14) * d_1b945c,
                    (double)I4(obj, 0x18) * d_1b945c
                );
                P(
                    d_1cd320,
                    0,
                    0xb8,
                    d_1a9b00,
                    d_1ad4d4,
                    d_1b9338,
                    U2(poly, 8),
                    I4(sub, 0x2a) >> 16,
                    I4(sub, 0x2c) >> 16,
                    I4(I4(poly, 0x48), 0),
                    (U1(I4(poly, 0x48), 0xd) & 0x10) ? d_1b92f4 : d_1b92fc,
                    (double)I4(poly, 0x3c) * d_1b945c,
                    (double)I4(poly, 0x40) * d_1b945c,
                    (U1(poly, 2) & 4) ? d_1b9304 : d_1b930c,
                    (U1(poly, 2) & 8) ? d_1b9314 : d_1b9320,
                    (U1(poly, 2) & 2) ? d_1b9328 : d_1b9330
                );
                if (U1(poly, 3)) {
                    P(d_1cd320, 0xc8, 0xc0, d_1a9b00, d_1ad4d4, d_1b9378, U2(poly, 0x86));
                }
            }
        }
        if (d_1a9a1c & 0x8000) {
            P(d_1cd320, 0xf4, 0, d_1a9b00, d_1ad4d4, d_1b9388);
            P(d_1cd320, 0xf4, 8, d_1a9b00, d_1ad4d4, d_1b939c, (d_1a9a1c & 0x40) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x10, d_1a9b00, d_1ad4d4, d_1b93b0, ((d_1a9a1c & 0x20) && !(d_1a9a1c & 0x80)) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x18, d_1a9b00, d_1ad4d4, d_1b93c4, (d_1a9a1c & 0x80) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x20, d_1a9b00, d_1ad4d4, d_1b93d8, (d_1a9a1c & 0x4000) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x28, d_1a9b00, d_1ad4d4, d_1b93ec, (d_1a9a1c & 8) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x30, d_1a9b00, d_1ad4d4, d_1b9400, (d_1a9a1c & 0x1000000) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x38, d_1a9b00, d_1ad4d4, d_1b9414, (d_1a9a1c & 0x40000) ? d_1b9394 : d_1b9398);
            P(d_1cd320, 0xf4, 0x40, d_1a9b00, d_1ad4d4, d_1b9428, d_1cdb3c);
            P(d_1cd320, 0xf4, 0x48, d_1a9b00, d_1ad4d4, d_1b9450, (d_1a9a1c & 4) ? d_1b943c : d_1b9448);
        }
        if (d_1a9a1c & 0x1000) {
            int cx = d_1a99a0 - d_1cdb44;
            int c;
            int x1, y1, x2, y2;
            r = d_1a99a4 - d_1cdb48;
            y1 = r - 5;
            c = f_16ecba(d_1cdb74);
            x1 = cx - 5;
            y2 = r + 5;
            x2 = cx + 5;
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = y2; y2 = u; }
            { int u = x1; x1 = u; }
            { int u = x1; x1 = u; }
            { int u = x1; x1 = u; }
            { int u = x1; x1 = u; }
            { int u = x1; x1 = u; }
            { int u = x1; x1 = u; }
            { int u = x2; x2 = u; }
            { int u = x2; x2 = u; }
            { int u = x2; x2 = u; }
            { int u = x2; x2 = u; }
            { int u = x2; x2 = u; }
            { int u = y1; y1 = u; }
            { int u = y1; y1 = u; }
            { int u = y1; y1 = u; }
            { int u = y1; y1 = u; }
            f_16fb53(c, x1, y1);
            f_16fb72(c, x2, y2);
            f_16fb53(c, x2, y1);
            f_16fb72(c, x1, y2);
        }
        }
ende:
    f_1630ac();
    if (d_1a9944) {
        d_1a996c = 0xf018;
        return 0xf018;
    }
    d_1a996c = 0;
    return 0;
}





//@ f_154af8  groesse 168 B
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stellt das fertig berechnete 3D-Einzelbild dar, indem zunächst ein optionaler
 *   Nachbearbeitungs-Callback (d_1a9910, etwa für 2D-Überlagerungen des Hauptspiels) aufgerufen, beim
 *   allerersten Aufruf (d_1a9941 == 0) die 256-Farben-Palette (d_1c72f8) über f_17684a aktiviert und schließlich
 *   der Hintergrundpuffer über f_1750bc auf den Bildschirm kopiert wird.
 * - Eingaben: Keine direkten Parameter.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen:
 *   - d_1a9910: Funktionszeiger für eine optionale Zeichenfunktion, die vor der Bildausgabe auf dem fertigen
 *     3D-Puffer ausgeführt wird.
 *   - d_1a9941: Flag, das sicherstellt, dass die Farbpalette beim ersten Bildaufbau automatisch gesetzt wird.
 === Ende Beschreibung === */
int f_154af8(void)
{
    int r;
    if (d_1a993d == 0) {
        {
            union Error { int i; float f; } error;
            // haelt die Registerzuteilung wie im Original
            error.i = 0xf002;
            *(float *)&d_1a996c = error.f;
            return error.i;
        }
    }
    d_1a9a64 = d_1a9a64 - f_16fc19();
    if (d_1a9910 != 0) d_1a9910(d_1a9920, d_1a9984, d_1a9988, d_1a9a60);
    if (d_1a9941 == 0) {
        f_17684a(d_1c72f8, 0x100);
        d_1a9941 = 1;
    }
    f_1750bc();
    d_1a9a64 = d_1a9a64 + f_16fc19();
    d_1a996c = 0;
    return 0;
}
