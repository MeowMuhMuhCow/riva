/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t8 (0x156370 - 0x1567AF)
 *
 * Überblick
 * Diese Einheit bildet den achten und letzten Teil des 3D-Engine-Moduls fz_14dc28. Sie kapselt die über
 * Funktionszeiger konfigurierbaren Speicherverwaltungs-Callbacks (f_156370, f_156384, f_1563a8) sowie die
 * Reservierung, Partitionierung und Freigabe der beiden großen Arbeits- und Geometrie-Speicherblöcke (d_1a9914
 * und d_1a9918) des 3D-Renderers.
 === Ende Beschreibung === */
// P3 5/9 gleich (suche.py 26.10.2026, Basis fz_14dc28_t8_P1.CPP)
// CC wcc386
// P1 2/9 gleich
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
extern int d_1a993f;                    // 0x1A993F
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
extern int d_1a995c;                    // 0x1A995C
extern int d_1a995e;                    // 0x1A995E
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
extern const char d_1b947c[];
extern const char d_1b94a8[];
extern char d_1a993d;
extern unsigned char d_1a993e;
extern char d_1a9940;
extern int d_1cd1ec;
int f_1771c2(void);
#pragma inline_depth(0)
extern int d_1a99cc, d_1a99d0, d_1a99d4, d_1a99d8, d_1a9a28, d_1cdb7c, d_1cdb80, d_1cdb84, d_1cdb8c;
extern const char d_1b946c[];
extern const char d_1b9484[];
int f_145300(int, int, int);
extern int (*d_1a9904)(int, const char *, const char *, int);

//@ f_156370
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reserviert einen Speicherblock der Größe a über den vom Hauptprogramm registrierten
 *   Allokations-Callback d_1a9904 (mit Modulname b, Beschreibung c und Kennung d). Ist kein Callback
 *   eingetragen, gibt sie 0 zurück.
 * - Eingaben: a (Größe in Bytes), b (Quelldateiname), c (Puffername), d (Blockkennung).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock oder 0.
 * - Wichtige Variablen: d_1a9904 (Funktionszeiger auf den benutzerdefinierten Speicherallokator).
 === Ende Beschreibung === */
#pragma aux f_156370 "*";
int f_156370(int a, const char *b, const char *c, int d)
{
    if (d_1a9904) return d_1a9904(a, b, c, d);
    return 0;
}

//@ f_156384
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft den optional registrierten Callback d_1a9908 mit fünf Parametern auf oder weicht
 *   andernfalls auf die Standardroutine f_1771c2 aus.
 * - Eingaben: a, b, c, d, e (Steuer-/Kontextparameter).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9908 (optionaler Callback-Zeiger).
 === Ende Beschreibung === */
extern void (*d_1a9908)(int, int, int, int, int);
#pragma aux f_156384 "*";
void f_156384(int a, int b, int c, int d, int e)
{
    if (d_1a9908) d_1a9908(a, b, c, d, e);
    else f_1771c2();
}

//@ f_1563a8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt einen zuvor über f_156370 reservierten Speicherblock p wieder frei, indem entweder
 *   der registrierte Freigabe-Callback d_1a9900 oder standardmäßig f_15ebd6 (free) aufgerufen wird.
 * - Eingaben: p (Zeiger auf den freizugebenden Speicherblock).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9900 (optionaler Freigabe-Callback).
 === Ende Beschreibung === */
#pragma aux f_1563a8 "*";
void f_15ebd6(int p1);
extern void (*d_1a9900)(int);
void f_1563a8(int p)
{
    if (d_1a9900) d_1a9900(p);
    else f_15ebd6(p);
}

//@ f_1563bc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet den Speicherbedarf für die permanenten 3D-Szenentabellen
 *   (Schattierungs-/Farbtabellen d_1cd1ec, Textur-/Materialpools d_1cdb8c, d_1cdb84, d_1cdb80, d_1cdb7c sowie
 *   das Array der 48-Byte-Szenenobjekte d_1cd210), reserviert den zusammenhängenden Hauptblock d_1a9914 über
 *   f_156370, richtet die Teilzeiger an einer 256-Byte-Grenze aus und initialisiert die Objektliste mit Nullen
 *   (f_145300).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 0 bei Erfolg, 0xf001 bei Speichermangel.
 * - Wichtige Variablen:
 *   - d_1a9914: Basisadresse des reservierten Szenen-Speicherblocks.
 *   - d_1cd1ec: 256-Byte-ausgerichtete Schattierungstabelle (0x4000 Bytes).
 *   - d_1cd210: Zeiger auf das Array der Szenenobjekte (d_1a9a38 * 48 Bytes).
 === Ende Beschreibung === */
#pragma aux f_1563bc "*";
int f_1563bc_alloc(int, const char *, const char *, int);
#pragma aux f_1563bc_alloc "f_156370";
int f_1563bc(void)
{
    int p, b, a, d, c, error;
    b = 1 + ((d_1a99d8 - 1) >> 4);
    a = ((d_1a99d4 - 1) >> 2) + 1;
    c = d_1a99cc;
    d = d_1a99d0;
    d_1a9a28 = ((a + b + d + c) << 16) + 0x4100;
    d_1a9a28 = d_1a9a28 + d_1a9a38 * 48;
    p = f_1563bc_alloc(d_1a9a28, d_1b947c, d_1b946c, 10);
    d_1a9914 = p;
    if (p == 0) {
        error = 0xf001;
        f_163050((int)d_1b9484);
        d_1a996c = error;
        return error;
    }
    if (p & 0xff) p = (p & ~0xff) + 0x100;
    d_1cd1ec = p;
    p += 0x4000;
    d_1cdb8c = p;
    p += b << 16;
    d_1cdb84 = p;
    p += a << 16;
    d_1cdb80 = p;
    {
    int count = d_1a9a38;
    p += d << 16;
    d_1cdb7c = p;
    p += c << 16;
    d_1cd210 = p;
    f_145300(p, 0, count * 48);
    }
    d_1a996c = 0;
    return 0;
}

//@ f_1564cc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reserviert den zweiten großen, temporären Geometrie- und Render-Arbeitsspeicherblock
 *   d_1a9918 (Gesamtgröße d_1a9a2c) über f_156370 und teilt ihn in die einzelnen Arbeitspuffer für
 *   transformierte Eckpunkte (d_1cd314), projizierte 2D-Punkte (d_1cd224), Vertex-Clippingflags (d_1cdc14),
 *   Polygone (d_1cd21c, d_1cd220), transformierte Normalen (d_1cd324), sichtbare Objekte (d_1cd228, d_1cd204)
 *   und Kollisions-Eckpunkte (d_1cd20c) auf.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 0 bei Erfolg, 0xf001 bei Speichermangel.
 * - Wichtige Variablen: d_1a9918 (Basisadresse des Render-Arbeitsblocks), d_1a9a2c (berechnete Blockgröße).
 === Ende Beschreibung === */
#pragma aux f_1564cc "*";
int f_1564cc_alloc(int, const char *, const char *, int);
#pragma aux f_1564cc_alloc "f_156370";
// OPT -5r -oneatx -zp1 -s -fp5
int f_1564cc(void)
{
    int align, p, error;
    align = (d_1a9a3c & ~3) + 4;
    d_1a9a2c = d_1a9a3c * 12 + (d_1a9a3c << 3) + align
              + (d_1a9a40 << 3) + d_1a9a44 * 156 + d_1a9a44 * 4
              + d_1a9a48 * 12 + d_1a9a38 * 184 + (d_1a9a38 << 3) + 32000;
    p = f_1564cc_alloc(d_1a9a2c, d_1b947c, d_1b94a8, 20);
    d_1a9918 = p;
    if (p == 0) {
        error = 0xf001;
        f_163050((int)d_1b94b8);
        d_1a996c = error;
        return error;
    }
    d_1cd314 = p;
    d_1cd224 = (p += d_1a9a3c * 12);
    d_1cdc14 = (p += (d_1a9a3c << 3));
    d_1cd318 = (p += align);
    d_1cd21c = (p += (d_1a9a40 << 3));
    d_1cd220 = (p += d_1a9a44 * 156);
    d_1cd324 = (p += d_1a9a44 * 4);
    d_1cd228 = (p += d_1a9a48 * 12);
    d_1cd204 = (p += d_1a9a38 * 184);
    d_1cd20c = (p += (d_1a9a38 << 3));
    d_1a996c = 0;
    return 0;
}

//@ f_15666c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den in f_1563bc reservierten permanenten Szenen-Speicherblock d_1a9914 über f_1563a8
 *   frei und setzt d_1a9914, d_1cd210 und d_1cd1ec auf 0.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9914, d_1cd210, d_1cd1ec.
 === Ende Beschreibung === */
#pragma aux f_15666c "*";
void f_15666c_free(int p);
#pragma aux f_15666c_free "f_1563a8";
void f_15666c(void)
{
    if (d_1a9914 != 0) {
        d_1cd210 = 0;
        f_15666c_free(d_1a9914);
        d_1a9914 = 0;
        d_1cd1ec = 0;
    }
}

//@ f_156698
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den in f_1564cc reservierten temporären Render-Arbeitsspeicherblock d_1a9918 über
 *   f_1563a8 wieder frei.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9918.
 === Ende Beschreibung === */
#pragma aux f_156698 "*";
void f_156698_free(int p);
#pragma aux f_156698_free "f_1563a8";
void f_156698(void)
{
    if (d_1a9918 != 0) {
        f_156698_free(d_1a9918);
        d_1a9918 = 0;
    }
}

//@ f_1566b8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den Render-Arbeitsspeicherblock d_1a9918 frei und räumt bei weiterem Speicherbedarf
 *   (p1 > d_1a9a2c) zusätzlich über f_161e84(1) Textur-/Cache-Speicher frei, damit dem aufrufenden Spielmodul
 *   mindestens p1 Bytes Speicher zur Verfügung stehen.
 * - Eingaben: p1 (angeforderte Speichergröße in Bytes).
 * - Rückgabewert: 0 wenn die Freigabe von d_1a9918 ausreichte, 0xf012 wenn zusätzlich Caches geleert wurden,
 *   oder ein Fehlercode (0xf002, 0xf005).
 * - Wichtige Variablen: d_1a9918, d_1a9a2c, d_1a993e (Flag "Renderpuffer muss vor dem nächsten Frame neu
 *   angelegt werden").
 === Ende Beschreibung === */
#pragma aux f_1566b8 "*";
void f_1566b8_free(int p);
#pragma aux f_1566b8_free "f_1563a8";
int f_1566b8(int p1)
{
    if (d_1a993d == 0) {
        p1 = 0xf002;
        return d_1a996c = p1;
    } else {
        if (p1 < 0) {
            p1 = 0xf005;
            d_1a996c = p1;
            return p1;
        }
        d_1a993e = 1;
        p1 -= d_1a9a2c;
        if (d_1a9918 != 0) {
            f_1566b8_free(d_1a9918);
            d_1a9918 = 0;
        }
        if (p1 > 0) f_161e84(1);
        if (p1 > 0) {
            p1 = 0xf012;
            return d_1a996c = p1;
        }
        d_1a996c = 0;
    }
    return 0;
}

//@ f_15674c
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die 3D-Szene bzw. den Textur-/Geometriecache zurück (d_1a993e = 1), indem bei
 *   geladener Szene (d_1a9940 != 0) f_161e84(1) aufgerufen oder andernfalls ein noch vorhandener Puffer d_1cd300
 *   über f_1782e8 freigegeben wird.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: 0 bei Erfolg, 0xf002 wenn nicht initialisiert.
 * - Wichtige Variablen: d_1a993e, d_1a9940, d_1cd300.
 === Ende Beschreibung === */
#pragma aux f_15674c "*";
int f_15674c(void)
{
    unsigned char r;
    int t;
    if (d_1a993d == 0) {
        d_1a996c = 0xf002; return 0xf002;
    }
    d_1a993e = 1;
    if (d_1a9940 != 0) {
        f_161e84(1);
    } else {
        if (d_1cd300 != 0) {
            f_1782e8(d_1cd300);
            d_1cd300 = 0;
        }
    }
    d_1a996c = 0;
    return 0;
}
