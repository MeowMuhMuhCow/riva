/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t4 (0x1511EC - 0x1524D0)
 *
 * Überblick
 * Diese Einheit enthält den vierten Teil der 3D-Geometrie-, Kollisions- und Sichtbarkeits-Engine: Punktabfragen
 * nach der Sektor-/Trigger-ID (f_1511ec), schnelle Sichtlinien- und Kollisionstests zwischen zwei 3D-Punkten
 * (f_1512d8), die Schwerpunktermittlung von 3D-Objekten (f_1513cc), das automatische Freirücken eines in einer
 * Wand steckenden Spielers (f_15156c, f_15164c), eine 2D-Minimap-/Draufsicht-Darstellung der Kollisionspolygone
 * (f_151958, f_151b50) sowie die 3D-Bounding-Box- und Bildschirm-Clipping-Berechnung (f_152020, f_152310).
 === Ende Beschreibung === */
// P3 3/9 gleich (suche.py 29.10.2026, Basis fz_14dc28_t4_P1.CPP)
// OPT -5r -oneatx -zp1 -s -fp5
// CC wcc386
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
int f_16d3d0();                       // nicht in clobber.tsv
int f_16d4d8(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d7e7(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d8ad(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16e93c(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_16ebd8();                                         // reg - stapel 0
int f_16ecb4(int p1);                                   // reg eax stapel 0
int f_16ecba(int p1);                                   // reg eax stapel 0
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
extern int d_1a993e;                    // 0x1A993E
extern int d_1a993f;                    // 0x1A993F
extern char d_1a9942;                   // 0x1A9942
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
extern int d_1a995c;                    // 0x1A995C
extern int d_1a995e;                    // 0x1A995E
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
extern short d_1a99ac;                    // 0x1A99AC
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
extern int d_1c3970;                    // 0x1C3970
extern int d_1c3974;                    // 0x1C3974
extern int d_1c3978;                    // 0x1C3978
extern int d_1c3c38;                    // 0x1C3C38
extern int d_1c3c3c;                    // 0x1C3C3C
extern int d_1c5d10;                    // 0x1C5D10
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
extern int d_1c7168;                    // 0x1C7168
extern int d_1c7230;                    // 0x1C7230
extern int d_1c76f8;                    // 0x1C76F8
extern int d_1c76f9;                    // 0x1C76F9
extern int d_1c7734;                    // 0x1C7734
extern int d_1c8ff8;                    // 0x1C8FF8
extern int d_1c90c0;                    // 0x1C90C0
extern int d_1c90c4;                    // 0x1C90C4
extern int d_1c90c8;                             // 0x1C90C8
extern int d_1c90d0;                    // 0x1C90D0
extern int d_1c90d2;                    // 0x1C90D2
extern int d_1c90d4;                    // 0x1C90D4
extern int d_1cc788;                    // 0x1CC788
extern int d_1cd1b0;                    // 0x1CD1B0
extern int d_1cd1e0;                    // 0x1CD1E0
extern int d_1cd1e8;                    // 0x1CD1E8
extern int d_1cd1f8;                    // 0x1CD1F8
extern char d_1cd200;                   // 0x1CD200
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
extern short d_1cdb60;                    // 0x1CDB60
extern int d_1cdb68;                    // 0x1CDB68
extern int d_1cdb6c;                    // 0x1CDB6C
extern int d_1cdb70;                    // 0x1CDB70
extern int d_1cdb74;                    // 0x1CDB74
extern short d_1cdc14;                    // 0x1CDC14
extern int d_1cdc1a;                    // 0x1CDC1A
extern int d_1cdc1c;                    // 0x1CDC1C
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
// --- eigene Funktionen (63), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

struct ST { char z0[2]; unsigned short w2; unsigned short w4; unsigned short w6; char z1[4]; unsigned int fl; char z2[0x18]; int *p28; int *p2c; int *p30; unsigned short *p34; };
extern struct ST d_1c3c40[];
extern struct ST *d_1c6b48;
extern unsigned char d_1a993d;
extern unsigned char d_1a9940;
extern unsigned short d_1a9960;
extern int d_1cd1ec;
extern unsigned short d_1cdc1e;
extern int d_1a9afc;
extern int d_1a9a74;
extern short d_1a9aa0;
extern int d_1a9aa4;
extern short d_1ccf60[8];
int f_14e1f0(char *p);
int f_14ea94(struct ST *p, int a, int b, int c);
void f_14fa64(void);
void f_14fd64(void);
void f_150050(void);
int f_16f693(int a, int b, int c, int d, int e);
int f_16fb53(int p, int i, int x, int y);
int f_16fb72(int p, int i, int x, int y);
#pragma aux f_16f693 parm caller [eax edx ebx ecx] modify exact [eax edx ebx ecx];
#pragma aux f_16fb53 parm caller [eax] [ebx] modify exact [eax];
#pragma aux f_16fb72 parm caller [ebx] [edx] modify exact [eax];
#pragma aux f_16cf6a parm [eax edx ebx] modify exact [eax edx];
#pragma aux f_16cff5 parm [eax edx ebx] modify exact [eax edx];
int fmul(int a, int b);
#pragma aux fmul = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int muldiv(int a, int b, int c);
#pragma aux muldiv = "imul edx" "idiv ebx" parm [eax] [edx] [ebx] modify exact [eax edx] value [eax];
#define FLB(p) (*(unsigned char *)&(p)->fl)
#define W(p,o) (*(short *)((char *)(p) + (o)))
#define UW(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define I(p,o) (*(int *)((char *)(p) + (o)))
#define YV(s) ((s)[1])
#define XV0 (a[0])
//@ f_1511ec
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ermittelt für eine gegebene horizontale Position (x, y) in der 3D-Welt die Kennnummer
 *   (1..9998) des dort liegenden Boden-/Sektorpolygons, indem im Umkreis von 2 * d_1a9afc alle
 *   Kollisionspolygone gesammelt (f_14fa64) und per Punkt-in-Polygon-Test (f_14ea94 mit Modus 2) geprüft werden.
 * - Eingaben: x, y (horizontale 3D-Weltkoordinaten im 16.16-Festkommaformat).
 * - Rückgabewert: Gefundene Sektor-/Objekt-ID (short) oder 0, falls kein passendes Polygon unter dem Punkt
 *   liegt.
 * - Wichtige Variablen: p (Laufzeiger über das Kollisionsarray d_1c3c40).
 === Ende Beschreibung === */
#pragma aux f_1511ec "*";
short f_1511ec(int x, int y)
{
 int r; int i; struct ST *p; int k; int t;
 d_1c6b78 = x;
 t = d_1cd30c;
 d_1c6b7c = y;
 d_1c6b74 = t;
 d_1c6b88 = t;
 k = d_1a9afc * 2;
 d_1c6b84 = x;
 d_1c6b68 = x - k;
 d_1c6b80 = y;
 d_1c6b90 = x;
 d_1c6bac = x;
 d_1c6b64 = x + k;
 d_1c6b8c = y;
 d_1c6bb0 = y;
 d_1c6b6c = y - k;
 d_1c6b60 = y + k;
 f_14fa64();
 r = 0;
 p = d_1c3c40;
 for (i = 0; i < d_1a9a10; i++, p++) {
  if (p->p34[1] > 0 && p->p34[1] < 9999) {
   if (f_14ea94(p, 2, x, y)) { r = p->p34[1]; break; }
  }
 }
 return r;
}
//@ f_1512d8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die Verbindungsstrecke zwischen zwei 3D-Punkten (p1, p2, p3) und (p4, p5, p6)
 *   frei passierbar ist oder durch eine Wand bzw. einen Abgrund blockiert wird (z. B. für Sichtlinien- und
 *   Bewegungsprüfungen von Monstern/NSCs), indem f_14fa64, f_14fd64 und f_150050 für diese Strecke aufgerufen
 *   werden.
 * - Eingaben: p1, p2, p3 (Startpunkt X, Y, Z) und p4, p5, p6 (Endpunkt X, Y, Z).
 * - Rückgabewert: Freigabeflag aus dem obersten Byte von d_1a9937 (0 wenn blockiert, 1 wenn frei).
 * - Wichtige Variablen: d_1c6b78..d_1c6b88 (Start- und Endkoordinaten für den Kollisionstest).
 === Ende Beschreibung === */
#pragma aux f_1512d8 "*";
int f_1512d8(int p1, int p2, int p3, int p4, int p5, int p6)
{
 int t;
 if (d_1a993d == 0 || d_1a9940 == 0) return 0;
  d_1c6b74 = p2;
  d_1c6b88 = p5;
  d_1c6b80 = p6;
  p2 = p4 - p1;
  d_1c6ba8 = p2;
  d_1c6b7c = p3;
  d_1c6b84 = p4;
  d_1c6ba4 = p6 - p3;
  d_1c6b78 = p1;
  if (p4 < p1) { d_1c6bac = p4; d_1c6b90 = p1; }
  else { d_1c6bac = p1; d_1c6b90 = p4; }
  if (d_1c6b80 < d_1c6b7c) { d_1c6bb0 = d_1c6b80; d_1c6b8c = d_1c6b7c; }
  else { d_1c6bb0 = d_1c6b7c; d_1c6b8c = d_1c6b80; }
  t = d_1a9afc * 2;
  d_1c6b68 = d_1c6bac - t;
  d_1c6b64 = d_1c6b90 + t;
  d_1c6b6c = d_1c6bb0 - t;
  d_1c6b60 = t + d_1c6b8c;
  f_14fa64();
  f_14fd64();
  f_150050();
  return d_1a9937 >> 24;
 }
//@ f_1513cc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in der aktuellen 3D-Szene (d_1cd210) das Objekt mit der Kennung id, bestimmt dessen
 *   erstes markiertes Anker-/Zielpolygon (f_14e1f0(q) & 0x18) und berechnet den arithmetischen 3D-Mittelpunkt
 *   (*px, *py, *pz) aller Eckpunkte dieses Polygons.
 * - Eingaben:
 *   - id: Gesuchte 16-Bit-Objektkennung.
 *   - px, py, pz: Ausgabezeiger für die berechneten 3D-Koordinaten des Schwerpunkts.
 * - Rückgabewert: 0 bei Erfolg, sonst ein Fehlercode (0xf002, 0xf00c, 0xf005 oder 0xf012 in d_1a996c).
 * - Wichtige Variablen: sx, sy, sz (aufsummierte Schwerpunktkoordinaten).
 === Ende Beschreibung === */
#pragma aux f_1513cc "*";
int f_1513cc(unsigned short id, int *px, int *py, int *pz)
{
 int sy, sx, sz, r, idx, k, b, i, j, n, err;
 char *e, *s, *q, *w;
 if (d_1a993d == 0) { err = 0xf002; d_1a996c = err; return err; }
 if (d_1a9940 == 0) { err = 0xf00c; d_1a996c = err; return err; }
 if (id == 0xffff || px == 0 || py == 0 || pz == 0) { d_1a996c = 0xf005; return 0xf005; }
 e = (char *)d_1cd210; // haelt die Registerzuteilung wie im Original
 px = (int *)(((int)px & 0) ? 0 : (int)px); // haelt die Registerzuteilung wie im Original
 py = (int *)(((int)py & 0) ? 0 : (int)py); // haelt die Registerzuteilung wie im Original
 for (i = 0; i < *(int *)&d_1a99ac; i++, e += 0x30) {
  if (*(unsigned short *)(e + 2) == id && *(unsigned char *)e != 0 && (s = *(char **)(e + 0x28)) != 0) {
   q = *(char **)(s + 0x44);
   j = *(unsigned short *)(s + 0xa) + 1;
   goto test1;
  body1:
   r = f_14e1f0(q);
   d_1c6b98 = r;
   if (r & 0x18) {
    n = *(unsigned char *)(q + 1);
    sx = sy = sz = 0;
    w = q + 2;
    i = n + 1;
    goto test2;
   body2:
    idx = *(unsigned short *)w;
    k = *(unsigned short *)(*(char **)(s + 0x40) + 12 * idx);
    b = *(int *)(s + 0x38);
    k = 12 * k + b;
    sx += *(int *)(k) / n;
    sy += *(int *)(k + 4) / n;
    sz += *(int *)(k + 8) / n;
    w += 4;
   test2:
    if (--i) goto body2;
    *px = sx; *py = sy; d_1a996c = 0; *pz = sz;
    return 0;
   }
   q += 0x30;
  test1:
   if (--j) goto body1;
  }
 }
 err = 0xf012; d_1a996c = err; return err;
}

//@ f_15156c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hilfsfunktion für f_15164c: Prüft, ob der horizontale Punkt (x, y) ein gültiger,
 *   kollisionsfreier Standpunkt auf begehbarem Boden ist (darf in keinem Wand-Umriss p->fl & 2 liegen und muss
 *   entweder im sicheren Innenbereich c > 0 eines Bodenpolygons oder im Übergangsbereich zweier angrenzender
 *   Bodenpolygone a > 0 && b > 0 liegen).
 * - Eingaben: x, y (horizontale Weltkoordinaten).
 * - Rückgabewert: 1, wenn der Standpunkt gültig und frei ist, sonst 0.
 * - Wichtige Variablen: a, b, c (Zähler für getroffene Boden-Teilbereiche).
 === Ende Beschreibung === */
#pragma aux f_15156c "*";
int f_15156c(int x, int y)
{
 int a; int c; int b; struct ST *p;
 c = 0; a = 0; b = 0;
 for (p = d_1c3c40; p < d_1c6b48; p++) {
  if (p->fl & 2) { if (f_14ea94(p, 1, x, y)) return 0; }
  if ((p->fl & 3) == 1) {
   if (f_14ea94(p, 1, x, y)) {
    if (f_14ea94(p, 3, x, y)) c++;
    else if (f_14ea94(p, 2, x, y)) a++;
    else b++;
   }
  }
 }
 if (c > 0) return 1;
 if (a > 0 && b > 0) return 1;
 return 0;
}
//@ f_15164c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die aktuelle Position (d_1c90c0, d_1c90c4, d_1c90c8) in einem Wandhindernis oder
 *   außerhalb des begehbaren Bodens steckt, und tastet bei Bedarf in zwei konzentrischen Quadratringen rund um
 *   den Punkt nach einer gültigen Nachbarposition (f_15156c) ab, auf die die Koordinate (d_1c90c0, d_1c90c8)
 *   korrigiert wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 1, wenn die Position bereits gültig war oder erfolgreich auf einen freien Nachbarpunkt
 *   (d_1a9942 = 1) verschoben wurde, sonst 0.
 * - Wichtige Variablen: fr.n, fr.d, fr.r (Ringindex, Schrittweite und Radius der quadratischen
 *   Nachbarschaftssuche).
 === Ende Beschreibung === */
#pragma aux f_15164c "*";
int f_15164c(void)
{
 int m, k, y, x, i, ylo, yhi, xlo, xhi;

 /* Belegte Spillrollen: sechs DWORD-Slots, dann vier BYTE-Flags im 4-Byte-Abstand. */
 struct {
  int n, e2, e, w, r, d;
  unsigned char hit; char pad_hit[3];
  unsigned char a;   char pad_a[3];
  unsigned char b;   char pad_b[3];
  unsigned char c;   char pad_c[3];
 } fr;
 struct ST *p;

 if (d_1a993d == 0 || d_1a9940 == 0) return 0;
 d_1c6b84 = d_1c90c0;
 d_1c6b78 = d_1c90c0;
 d_1c6b88 = d_1c90c4;
 d_1c6b74 = d_1c90c4;
 d_1c6b80 = d_1c90c8;
 d_1c6b7c = d_1c90c8;
 m = (int)d_1a9960 << 16;
 k = d_1a9afc + m;
 d_1c6b68 = d_1c6b84 - k;
 d_1c6b64 = d_1c6b84 + k;
 d_1c6b6c = d_1c6b80 - k;
 d_1c6b60 = d_1c6b80 + k;
 fr.a = 0;
 fr.c = 0;
 fr.b = 0;
 f_14fa64();
 for (p = d_1c3c40; p < d_1c6b48; p++) {
  if (f_14ea94(p, 1, d_1c6b84, d_1c6b80) != 0) {
   if (p->fl & 2) {
    if (d_1a9960 == 0) goto ret0;
    fr.c = 1;
    fr.a = 0;
   }
   if ((p->fl & 3) == 1) {
    if (fr.b != 0) fr.a = 1;
    if (fr.a != 0||fr.c != 0) continue;
    if (f_14ea94(p, 3, d_1c6b84, d_1c6b80) != 0) fr.a = 1;
    else if (f_14ea94(p, 2, d_1c6b84, d_1c6b80) == 0) fr.b = 1;
   }
  }
 }
 if (fr.a && !fr.c) return 1;
 fr.d = m / 4;
 fr.hit = 0;
 fr.e2 = fr.d << 1;
 fr.n = 1;
 { int q = fr.d; fr.d = q; } /* haelt die Registerzuteilung wie im Original */
 fr.w = fr.d << 1;
 fr.e = fr.d;
 fr.r = fr.d;
 for (; fr.n <= 2; fr.n++) {
  x = d_1c6b78 - fr.r;
  yhi = d_1c6b7c - fr.r;
  ylo = yhi;
  yhi += fr.w;
  /* haelt die Registerzuteilung wie im Original */
  i = -fr.n;
  i = -fr.n;
  i = -fr.n;
  if (i <= fr.n) do {
   y = ylo;
   if (f_15156c(x, y)) { fr.hit = 1; goto done; }
   y = yhi;
   if (f_15156c(x, y)) { fr.hit = 1; goto done; }
   i++;
   x += fr.d;
  } while (i <= fr.n);
  y = d_1c6b7c - fr.r;
  x = d_1c6b78 - fr.r;
  y += fr.d;
  xhi = fr.w + x;
  xlo = x;
  for (i = 1 - fr.n; i < fr.n; i++, y += fr.d) {
   x = xhi;
   if (f_15156c(x, y) ) { fr.hit = 1; goto done; }
   x = xlo;
   if (f_15156c(x, y) != 0) { fr.hit = 1; goto done; }
  }
  fr.w += fr.e2;
  fr.r += fr.e;
 }
done:
 if (fr.hit) {
  unsigned char one = 1;
  d_1c90c0 = x;
  d_1c90c8 = y;
  { char *flag = (x & 0) ? (char *)0 : (char *)&d_1a9942; /* haelt die Registerzuteilung wie im Original */
    *flag = one; }
  return one;
 }
 ret0: return 0;
}



//@ f_151958
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet in der 2D-Debug-/Übersichtskarte (f_151b50) den Umriss eines einzelnen
 *   Kollisionspolygons p1 (je nach p2 den Außen-, Original- oder Innenumriss) maßstabsgerecht um die
 *   Spielerposition zentriert und markiert die Eckpunkte mit kleinen 3x3-Quadraten.
 * - Eingaben: p1 (Kollisionsdatensatz struct ST *), p2 (Umrisstyp 1, 2 oder 3), p3 (Farbflag: 1 = Farbe nach
 *   Polygontyp wählen, 0 = Standardfarbe d_1cdb74).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: points (projizierte 2D-Bildschirmkoordinaten der bis zu 100 Polygonecken).
 === Ende Beschreibung === */
#pragma aux f_151958 "*";
void f_151958(struct ST *p1, unsigned p2, unsigned p3)
{
 void line53(int, int);
 void line72(int, int);
#pragma aux line53 "f_16fb53" parm caller [] modify exact [eax ebx];
#pragma aux line72 "f_16fb72" parm caller [] modify exact [eax ebx];
 short points[202];
 int *v;
 short *s;
 int n, i, c;
 unsigned flag;
 if (p1 == 0) return;
 if (p2 < 2) goto low_case;
 if (p2 <= 2) goto base_case;
 if (p2 == 3) goto high_case;
 goto base_case;
low_case:
 if (p2 != 1) goto base_case;
 v = p1->p2c; n = p1->w4; goto selected;
high_case:
 v = p1->p30; n = p1->w6; goto selected;
base_case:
 n = p1->w2; v = p1->p28;
selected:
 if (n > 100) n = 100;
 s = points;
 i = d_1cd23c ^ d_1cd23c;
 if (n > 0) do {
  int offset = d_1cd23c;
  int delta = v[0] - offset;
  int scale = d_1c6b24;
  s[0] = (short)(fmul(delta, scale) >> 16);
  ++i;
  offset = d_1cd244;
  delta = v[1] - offset;
  scale = d_1c6b20;
  s[1] = (short)(fmul(delta, scale) >> 16);
  s += 2;
  v += 4;
 } while (i < n);
 s[0] = points[0];
 s[1] = points[1];
 flag = p3;
 if (!flag) goto no_color;
 {
  c = d_1cdb74;
  if (FLB(p1) & 1) c = d_1cdb58;
  if (FLB(p1) & 4) {
   c = *(unsigned char *)(d_1cd1ec + d_1cdb58 + 0x3f00);
  }
  if (FLB(p1) & 2) c = d_1cdb54;
  if (FLB(p1) & 8) c = d_1cdb70;
 }
 goto color_done;
no_color:
 c = d_1cdb74;
color_done:
 f_16ecba(c);
 {
 short *q = points + 2;
 i = 0;
 line53(*(int *)(points - 1) >> 16, *(int *)points >> 16);
 if (n > 0) do {
  line72(q[0], *(int *)q >> 16);
  ++i;
  q += 2;
 } while (i < n);
 q = points + 2;
 i = 0;
 if (n > 0) do {
  line53(q[0] - 1, (*(int *)q >> 16) - 1);
  line72(q[0] + 1, (*(int *)q >> 16) - 1);
  line72(q[0] + 1, (*(int *)q >> 16) + 1);
  line72(q[0] - 1, (*(int *)q >> 16) + 1);
  line72(q[0] - 1, (*(int *)q >> 16) - 1);
  ++i;
  q += 2;
 } while (i < n);
 }
}
//@ f_151b50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Rendert ein kleines 2D-Übersichts-/Radarfenster (-80..80 x -70..70 um Bildschirmposition
 *   235, 74), das alle umliegenden Boden-, Wand- und Triggerpolygone (f_151958), den Blickrichtungsvektor des
 *   Spielers sowie das aktuelle Kollisions-Suchrechteck anzeigt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s44..s6c (gesicherte Viewport-Einstellungen), pos (rotierter Blickrichtungsvektor).
 === Ende Beschreibung === */
#pragma aux f_151b50 "*";
// BLIND: f_151b50 hier komplett neu aus dem Original-Assembler schreiben (orig.sh fz_14dc28_t4 f_151b50).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
void f_151b50(void)
{
 void line72s(int, int);
#pragma aux line72s "f_16fb72" parm caller [] modify exact [eax] nomemory;
 int fmulnm(int a, int b);
#pragma aux fmulnm = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] nomemory value [eax];
 int m[12];
 int pos[3];
 int v[3];
 int s6c;
 int s68;
 int s50;
 int s48;
 int s44;
 int s4c;
 int r, k, i, c, sc, sc2, a, b, x1, y1;
 struct ST *p;
 s44 = d_1cdb44;
 s48 = d_1cdb48;
 s4c = d_1cdb4c;
 s50 = d_1cdb50;
 s6c = d_1cdb6c;
 s68 = d_1cdb68;
 d_1cdb4c = -80;
 d_1cdb6c = 80;
 d_1cdb50 = -70;
 d_1cdb68 = 70;
 d_1ccf60[0] = d_1cdb4c;
 d_1ccf60[1] = d_1cdb50;
 d_1ccf60[2] = d_1cdb6c;
 d_1ccf60[3] = d_1cdb50;
 d_1ccf60[4] = d_1cdb6c;
 d_1ccf60[5] = d_1cdb68;
 d_1ccf60[6] = d_1cdb4c;
 d_1ccf60[7] = d_1cdb68;
 r = f_16ecb4(0);
 d_1cdb44 = 235;
 d_1cdb48 = 74;
 f_16f693(r, -80, 80, -70, 4);
 d_1c6b20 = d_1c6b24 = d_1a9a74 * 15 / d_1a997c;
 v[0] = 0;
 // haelt die Registerzuteilung wie im Original
 { int kr = d_1cdb44; d_1cdb44 = kr; } // haelt die Registerzuteilung wie im Original
 v[1] = 0;
 v[2] = 0xfff80000;
 f_16b930((int)m);
 f_16cc44((int)m, d_1cdc1e);
 f_16cff5((int)pos, (int)v, (int)m);
 d_1c6b78 = d_1cd23c;
 d_1c6b74 = d_1cd240;
 d_1c6b7c = d_1cd244;
 d_1c6b84 = d_1cd23c + pos[0];
 d_1c6b88 = d_1cd240 + pos[1];
 d_1c6b80 = d_1cd244 + pos[2];
 if (d_1c6b84 < d_1c6b78) { d_1c6bac = d_1c6b84; d_1c6b90 = d_1c6b78; }
 else { d_1c6bac = d_1c6b78; d_1c6b90 = d_1c6b84; }
 if (d_1c6b80 < d_1c6b7c) { d_1c6bb0 = d_1c6b80; d_1c6b8c = d_1c6b7c; }
 else { d_1c6bb0 = d_1c6b7c; d_1c6b8c = d_1c6b80; }
 k = d_1a9afc * 8;
 d_1c6b68 = d_1c6bac - k;
 d_1c6b64 = d_1c6b90 + k;
 d_1c6b6c = d_1c6bb0 - k;
 d_1c6b60 = k + d_1c6b8c;
 f_14fa64();
 for (i = 0, p = d_1c3c40; i < d_1a9a10; i++, p++)
  if ((p->fl & 0xa) == 0) f_151958(p, 2, 1);
 for (i = 0, p = d_1c3c40; i < d_1a9a10; i++, p++)
  if ((p->fl & 0xa) == 2) f_151958(p, 2, 1);
 for (i = 0, p = d_1c3c40; i < d_1a9a10; i++, p++)
  if (p->fl & 8) f_151958(p, 2, 1);
 if (d_1a9a1c & 0x40000000) {
  for (i = 0, p = d_1c3c40; i < d_1a9a10; i++, p++)
   if (p->fl & 0xa) f_151958(p, 1, 0);
 }
 c = *(int *)&d_1cdb60;
 sc = d_1c6b24;
 f_16ecba(c);
 sc2 = d_1c6b20;
 a = fmul(pos[0], sc);
 b = fmul(pos[2], sc2);
 f_16fb53(b, sc2, 0, 0);
 line72s(a >> 16, b >> 16);
 {
 int x0, y0;
 x0 = fmul(sc, d_1c6b68 - d_1c6b78) >> 16;
 y0 = fmulnm(sc2, d_1c6b6c - d_1c6b7c) >> 16;
 x1 = fmul(sc, d_1c6b64 - d_1c6b78) >> 16;
 y1 = fmul(sc2, d_1c6b60 - d_1c6b7c) >> 16;
 d_1ccf60[0] = x0;
 d_1ccf60[1] = y0;
 d_1ccf60[2] = x1;
 d_1ccf60[3] = y0;
 d_1ccf60[4] = x1;
 d_1ccf60[5] = y1;
 d_1ccf60[6] = x0;
 d_1ccf60[7] = y1;
 f_163428(4, c);
 }
 d_1ccf60[0] = d_1cdb4c;
 d_1ccf60[1] = d_1cdb50;
 d_1ccf60[2] = d_1cdb6c;
 d_1ccf60[3] = d_1cdb50;
 d_1ccf60[4] = d_1cdb6c;
 d_1ccf60[5] = d_1cdb68;
 d_1ccf60[6] = d_1cdb4c;
 d_1ccf60[7] = d_1cdb68;
 f_163428(4, d_1cdb74);
 d_1cdb44 = s44;
 d_1cdb48 = s48;
 d_1cdb4c = s4c;
 d_1cdb50 = s50;
 d_1cdb6c = s6c;
 d_1cdb68 = s68;
}

//@ f_152020
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Transformiert die 8 Eckpunkte der 3D-Bounding-Box eines Szenenobjekts (p1 + 0x80) mit
 *   dessen Kamera-Transformationsmatrix (p1 + 0x84) in den Kameraraum (f_16cf6a), bestimmt für jede Ecke die
 *   Frustum-Clipping-Flags (f_16d2c9), berechnet das 2D-Bildschirm-Umschließungsrechteck (p1 + 0x40) sowie die
 *   minimale und maximale Z-Tiefe (p1 + 0x14, p1 + 0x18) und gibt zurück, ob die gesamte Box außerhalb einer
 *   Schnittebene des Sichtkegels liegt (l28 != 0).
 * - Eingaben: p1 (Zeiger auf den Render-Arbeitsdatensatz des 3D-Objekts).
 * - Rückgabewert: Bitweises UND aller 8 Clipping-Codes (0, wenn das Objekt zumindest teilweise im Sichtkegel
 *   liegt; != 0, wenn es komplett außerhalb liegt und verworfen werden kann).
 * - Wichtige Variablen: vin, vout (8 Eckpunkte der Bounding-Box vor und nach der Kameratransformation), bounds
 *   (2D-Bildschirm-Rechteck x0, x1, y0, y1).
 === Ende Beschreibung === */
#pragma aux f_152020 "*";
int md152020(int a, int b, int c);
#pragma aux md152020 = "imul ebx" "idiv ecx" parm [eax] [ebx] [ecx] modify [eax ebx ecx edx] value [eax];
struct B152020 { short x0,x1,y0,y1; };
#define in vin
#define out vout
#define box bounds
unsigned f_152020(char *p1)
{
 int vout[24]; int vin[24]; struct B152020 bounds; int l3c; int l38; char *l30; int l2c; unsigned l28; int l24; unsigned l20; int l1c;
 int *bb; int *pi; int *po; unsigned fl; short s;
 bb = *(int **)(p1 + 0x80);
 in[0] = bb[8]; in[1] = bb[9]; in[2] = bb[10];
 in[3] = bb[11]; in[4] = bb[9]; in[5] = bb[10];
 in[6] = bb[11]; in[7] = bb[9]; in[8] = bb[13];
 in[9] = bb[8]; in[10] = bb[9]; in[11] = bb[13];
 in[12] = bb[8]; in[13] = bb[12]; in[14] = bb[10];
 in[15] = bb[11]; in[16] = bb[12]; in[17] = bb[10];
 in[18] = bb[11]; in[19] = bb[12];
 in[20] = bb[13]; in[21] = bb[8]; in[22] = bb[12]; in[23] = bb[13];
 l24 = 0x7fffffff; box.y0 = 32767; l2c = 0x80000000; box.x0 = 32767; box.y1 = -32767; box.x1 = -32767;
 l20 = 0; l1c = 0; l28 = 0xffffffff; l30 = p1 + 0x84;
 po = out; pi = in;
 for (l1c = 0; l1c < 8; l1c++, po += 3, pi += 3) {
  f_16cf6a((int)po, (int)pi, (int)l30);
  fl = f_16d2c9((int)po);
  l20 = l20 | fl;
  l28 = l28 & fl;
  if (po[2] < l24) l24 = po[2];
  if (po[2] > l2c) l2c = po[2];
  if ((fl & 0x10) == 0) {
   if ((fl & 3) == 0) {
    s = (short)((md152020(*(int *)&d_1a9aa0, po[0], po[2]) + 0x8000) >> 16);
    if (s < box.x0) box.x0 = s;
    if (box.x1 < s) box.x1 = s;
   } else if (fl & 1) box.x0 = (short)d_1cdb4c;
   else if (fl & 2) box.x1 = (short)d_1cdb6c;
   if ((fl & 0xc) == 0) {
    s = (short)((md152020(d_1a9aa4, po[1], po[2]) + 0x8000) >> 16);
    if (s < box.y0) box.y0 = s;
    if (box.y1 < s) box.y1 = s;
   } else if (fl & 4) box.y0 = (short)d_1cdb50;
   else if (fl & 8) box.y1 = (short)d_1cdb68;
  }
 }
 *(struct B152020 *)(p1+0x40) = box;
 I(p1, 0x14) = l2c;
 I(p1, 0x14) = -l2c;
 I(p1, 0x18) = l24;
 I(p1, 0x18) = -l24;
 *p1 = (char)l20;
 return l28;
}
#undef in
#undef out
#undef box
//@ f_152310
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Verfeinert für ein nahe an der vorderen Clipping-Ebene liegendes 3D-Objekt p1 die
 *   2D-Bildschirmgrenzen (p1 + 0x40..0x46) und den Z-Tiefenbereich (p1 + 0x14, p1 + 0x18) anhand der tatsächlich
 *   transformierten und geclippten Mesh-Eckpunkte (p1 + 0x1c, p1 + 0x24) sowie der sichtbaren Teilflächen
 *   (d_1cd220).
 * - Eingaben: p1 (Zeiger auf den Render-Arbeitsdatensatz des 3D-Objekts).
 * - Rückgabewert: 1, wenn das Objekt sichtbare Flächen im Sichtfeld besitzt, sonst 0.
 * - Wichtige Variablen: min_x, max_x (Z-Tiefenspanne), min_y, max_y, min_z, max_z (2D-Bildschirmgrenzen).
 === Ende Beschreibung === */
#pragma aux f_152310 "*";
int f_152310(char *p1)
{
 char *item;
 int count;
 int *points;
 int *records;
 char *record;
 int max_x;
 int min_x;
 int max_y;
 int min_y;
 int any;
 int max_z;
 int min_z;
 signed char *flags;
 int n2;
 int value;
 int base;

 item = (char *)I(p1, 0x1c);
 points = (int *)I(p1, 0x24);
 base = *(int *)&d_1cdc14; flags = (signed char *)(base + UW(p1, 6));
 min_x = max_x = I(item, 8);
 min_y = min_z = points[0];
 max_y = max_z = points[1];
 any = 0;
 count = UW(I(p1, 0x80), 4) + 1;
 goto loop1_test;
loop1_body:
 {
  if (I(item, 8) < min_x) min_x = I(item, 8);
  else if (I(item, 8) > max_x) max_x = I(item, 8);
  value = *flags;
  any |= value;
  ++flags;
  if (0 == value) {
   if (points[0] < min_y) min_y = points[0];
   else if (points[0] > max_y) max_y = points[0];
   if (points[1] < min_z) min_z = points[1];
   else if (points[1] > max_z) max_z = points[1];
  }
  item += 0xc;
  points += 2;
 }
loop1_test:
 if (--count != 0) goto loop1_body;
 W(p1, 0x40) = (short)((min_y + 0x8000) >> 16);
 W(p1, 0x42) = (short)((max_y + 0x8000) >> 16);
 W(p1, 0x44) = (short)((min_z + 0x8000) >> 16);
 W(p1, 0x46) = (short)((max_z + 0x8000) >> 16);
 *p1 = (char)any;
 I(p1, 0x14) = max_x;
 I(p1, 0x14) = -max_x;
 I(p1, 0x18) = min_x;
 I(p1, 0x18) = -min_x;
 if (any != 0) {
  if (W(p1, 0xc) == 0) {
   p1[0x10] &= 0xfe;
   return 0;
  }
  records = (int *)d_1cd220;
  records += UW(p1, 0xa);
  n2 = UW(p1, 0xc) + 1;
  goto loop2_test;
loop2_body:
  {
  record = (char *)*records;
  ++records;
   if (*record != 0) {
    if (W(record, 0x4c) < W(p1, 0x40)) W(p1, 0x40) = W(record, 0x4c);
    if (W(record, 0x4e) > W(p1, 0x42)) W(p1, 0x42) = W(record, 0x4e);
    if (W(record, 0x50) < W(p1, 0x44)) W(p1, 0x44) = W(record, 0x50);
    if (W(record, 0x52) > W(p1, 0x46)) W(p1, 0x46) = W(record, 0x52);
   }
  }
loop2_test:
  if (--n2 != 0) goto loop2_body;
 }
 return 1;
}

