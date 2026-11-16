/* === Beschreibung (Katalog) ===
 * Einheit fz_14dc28_t3 (0x150050 - 0x1511EC)
 *
 * Überblick
 * Diese Einheit enthält den dritten Teil der 3D-Kollisions- und Bewegungssteuerung: die Auswertung der
 * sortierten Schnittpunktliste entlang des Bewegungsweges (f_150050), das Abstoppen und Entlanggleiten an Wänden
 * (f_150334, f_1508fc), die weiche Anpassung des Kamera-/Körperneigungswinkels an Steigungen (f_150734) sowie
 * eine Debug-Textausgabe der Kollisionstreffer (f_151060).
 === Ende Beschreibung === */
// GEGENSTAND: Wiederhergestellter Quelltext (Pass 2, Einzeldatei)
// EINHEIT: fz_14dc28_t3 (5 Funktionen)  Quelltyp: .c
// CC wcc386
// OPT -5r -oneatx -zp1 -s -fp5
// Ursprung: Achse_1_Architektur/Granularitaet/Ergebnisse/Einheiten/fz_14dc28/fz_14dc28.c
// Statistik Pass 1: 42/63 (66%)
// Hand: 2026-04-14 Auto-Kette Stage 1-4  (p3_lang A3-Welle 2026-04-17: +1 (f_14def4)) (Auto-Pass2) (K5-Konst) (L2-Aehnlich) (G-Welle1) (K-Einzeln) (L-Lauf) (S5-Sturm) (F3-Fable) (S6-Sturm2) (N-Nachschub) (W-Welle)

// --- externe Funktionen (75) ---
extern int f_018a08();                  // 0x018A08 R:[eax]
extern int f_018aa0();                  // 0x018AA0 R:[eax]
extern int f_0263a0(int,int);           // 0x0263A0 [eax,edx] R:[eax]
extern int f_027690(int,int);           // 0x027690 [eax,edx] R:[eax]
extern int f_027b60(int,int,int);       // 0x027B60 [eax,edx,ebx] R:[eax]
extern int f_035b30(int,int);           // 0x035B30 [eax,edx] R:[eax]
extern int f_035fc0(int);               // 0x035FC0 [eax] R:[eax]
extern int f_03b7e0(int);               // 0x03B7E0 [eax] R:[eax]
extern int f_056600(int);               // 0x056600 [eax]
extern int f_059ca0(int);               // 0x059CA0 [eax] R:[eax]
extern int f_0985c0(int);               // 0x0985C0 [eax] R:[eax]
extern int f_09be30(int,int,int);       // 0x09BE30 [eax,edx,ebx] R:[eax]
extern int f_09ded0(int,int,int);       // 0x09DED0 [eax,edx,ebx] R:[eax]
extern int f_0b7a10(int,int,int);       // 0x0B7A10 [eax,edx,ebx]
extern int f_0b7c70(int);               // 0x0B7C70 [eax] R:[eax]
extern int f_0b7db0(int,int);           // 0x0B7DB0 [eax,edx]
extern int f_0b7ef0();                  // 0x0B7EF0
extern int f_0b8780(int,int);           // 0x0B8780 [eax,edx] R:[eax]
extern int f_0b8920(int);               // 0x0B8920 [eax] R:[eax]
extern int f_0dd170(int,int);           // 0x0DD170 [eax,edx] R:[eax]
extern int f_113690(int,int);           // 0x113690 [eax,edx]
extern int f_11bc20(int);               // 0x11BC20 [eax] R:[eax]
extern int f_1224a0(int,int);           // 0x1224A0 [eax,edx]
extern int f_122a40();                  // 0x122A40
extern int f_13de20(int);               // 0x13DE20 [eax] R:[eax]
extern int f_14a21c();                  // 0x14A21C R:[eax]
extern int f_14a3bc();                  // 0x14A3BC
extern int f_14a600();                  // 0x14A600
extern int f_14a6d0(int);               // 0x14A6D0 [eax]
extern int f_14b9e0(int);               // 0x14B9E0 [eax]
extern int f_14bd10(int,int);           // 0x14BD10 [eax,edx]
extern int f_14bec8(int);               // 0x14BEC8 [eax] R:[eax]
extern int f_14bfac(int);               // 0x14BFAC [eax] R:[eax]
extern int f_14c008(int);               // 0x14C008 [eax] R:[eax]
extern int f_14d218(int);               // 0x14D218 [eax] R:[eax]
extern int f_14d9f8();                  // 0x14D9F8 R:[eax]
extern int f_155ee4(int);               // 0x155EE4 [eax]
extern int f_155ef8(int,int,int);       // 0x155EF8 [eax,edx,ebx] R:[eax]
extern int f_15685c(int,int);           // 0x15685C [eax,edx] R:[eax]
extern int f_159280(int);               // 0x159280 [eax] R:[eax]
extern int f_159c80(int,int,int);       // 0x159C80 [eax,edx,ebx] R:[eax]
extern int f_159d60(int);               // 0x159D60 [eax]
extern int f_159ec4(int);               // 0x159EC4 [eax] R:[eax]
extern int f_15a004(int);               // 0x15A004 [eax] R:[eax]
extern int f_15a078(int,int);           // 0x15A078 [eax,edx] R:[eax]
extern int f_1632c8(int);               // 0x1632C8 [eax] R:[eax]
extern int f_163374(int);               // 0x163374 [eax]
extern int f_164bd0(int,int);           // 0x164BD0 [eax,edx] R:[eax]
extern int f_165624(int,int,int);       // 0x165624 [eax,edx,ebx] R:[eax]
extern int f_166080();                  // 0x166080 R:[eax]
extern int f_1663ec(int,int,int,int);   // 0x1663EC [eax,edx,ebx,ecx]
extern int f_16b930(int);               // 0x16B930 [eax]
extern int f_16cc44(int,int);           // 0x16CC44 [eax,edx] R:[eax]
extern int f_16cc88(int,int);           // 0x16CC88 [eax,edx] R:[eax]
extern int f_16ccc8(int,int);           // 0x16CCC8 [eax,edx]
extern int f_16cff5(int,int,int);       // 0x16CFF5 [eax,edx,ebx]
extern int f_16d33f(int,int,int,int);   // 0x16D33F [eax,edx,ebx,ecx] R:[eax]
extern int f_16d369(int,int,int,int);   // 0x16D369 [eax,edx,ebx,ecx] R:[eax]
extern int f_16d47e(int,int);           // 0x16D47E [edx,ebx] R:[eax]
extern int f_16d49c(int);               // 0x16D49C [eax]
extern int f_16d4d8(int,int);           // 0x16D4D8 [stack] R:[eax]
#pragma aux f_16d4d8 parm caller [];
extern int f_16d556(int,int);           // 0x16D556 [stack] R:[eax]
#pragma aux f_16d556 parm caller [];
extern int f_16d881(int,int);           // 0x16D881 [stack] R:[eax]
#pragma aux f_16d881 parm caller [];
extern int f_16ec8c();                  // 0x16EC8C R:[eax]
extern int f_17121b(int);               // 0x17121B [eax] R:[eax]
extern int f_1719dc(int,int);           // 0x1719DC [eax,edx] R:[eax]
extern int f_1739a5(int,int,int);       // 0x1739A5 [eax,edx,ebx] R:[eax]
extern int f_17a9de(int);               // 0x17A9DE [eax] R:[eax]
extern int f_17ff6e(int);               // 0x17FF6E [eax]
extern int f_18082a(int,int,int);       // 0x18082A [eax,edx,ebx]
extern int f_181c33(int,int);           // 0x181C33 [eax,edx] R:[eax]
extern int f_181c6a(int,int,int);       // 0x181C6A [eax,edx,ebx] R:[eax]
extern int f_185811(int,int,int,int);   // 0x185811 [eax,edx,ebx,ecx] R:[eax]
extern int f_185ba9(int);               // 0x185BA9 [eax] R:[eax]

// --- externe Daten (215) ---
extern int d_19999a;                    // 0x19999A
extern int d_19b7d0;                    // 0x19B7D0
extern int d_19b7d4;                    // 0x19B7D4
extern int d_1a5be8;                    // 0x1A5BE8
extern int d_1a5bec;                    // 0x1A5BEC
extern int d_1a6666;                    // 0x1A6666
extern int d_1a94d8;                    // 0x1A94D8
extern int d_1a96ac;                    // 0x1A96AC
extern int d_1a96d4;                    // 0x1A96D4
extern int d_1a98c8;                    // 0x1A98C8
extern int d_1a98cc;                    // 0x1A98CC
extern int d_1a98d0;                    // 0x1A98D0
extern int d_1a98d4;                    // 0x1A98D4
extern int d_1a98dd;                    // 0x1A98DD Breiten byte,dword
extern int d_1a98ec;                    // 0x1A98EC
extern int d_1a98f0;                    // 0x1A98F0
extern int d_1a9900;                    // 0x1A9900
extern int d_1a9904;                    // 0x1A9904
extern int d_1a9908;                    // 0x1A9908
extern int d_1a990c;                    // 0x1A990C
extern int d_1a9910;                    // 0x1A9910
extern int d_1a9914;                    // 0x1A9914
extern int d_1a9918;                    // 0x1A9918
extern int d_1a991c;                    // 0x1A991C
extern int d_1a9920;                    // 0x1A9920
extern int d_1a9924;                    // 0x1A9924
extern int d_1a9928;                    // 0x1A9928
extern int d_1a992c;                    // 0x1A992C
extern int d_1a9930;                    // 0x1A9930
extern int d_1a9934;                    // 0x1A9934
extern int d_1a9954;                    // 0x1A9954
extern int d_1a9958;                    // 0x1A9958
extern int d_1a9968;                    // 0x1A9968
extern int d_1a9980;                    // 0x1A9980
extern int d_1a99b0;                    // 0x1A99B0
extern int d_1a99c8;                    // 0x1A99C8
extern int d_1a99d8;                    // 0x1A99D8
extern int d_1a99e0;                    // 0x1A99E0
extern int d_1a9a10;                    // 0x1A9A10
extern int d_1a9a14;                    // 0x1A9A14
extern int d_1a9a28;                    // 0x1A9A28
extern int d_1a9a2c;                    // 0x1A9A2C
extern int d_1a9a30;                    // 0x1A9A30
extern int d_1a9a34;                    // 0x1A9A34
extern int d_1a9a38;                    // 0x1A9A38
extern int d_1a9a3c;                    // 0x1A9A3C
extern int d_1a9a40;                    // 0x1A9A40
extern int d_1a9a48;                    // 0x1A9A48
extern int d_1a9a4c;                    // 0x1A9A4C
extern int d_1a9a50;                    // 0x1A9A50
extern int d_1a9a5c;                    // 0x1A9A5C
extern int d_1a9a60;                    // 0x1A9A60
extern int d_1a9a64;                    // 0x1A9A64
extern int d_1a9a68;                    // 0x1A9A68
extern int d_1a9a6c;                    // 0x1A9A6C
extern int d_1a9a70;                    // 0x1A9A70
extern int d_1a9a78;                    // 0x1A9A78
extern int d_1a9a7c;                    // 0x1A9A7C
extern int d_1a9a80;                    // 0x1A9A80
extern int d_1a9a84;                    // 0x1A9A84
extern int d_1a9a8c;                    // 0x1A9A8C
extern int d_1a9a90;                    // 0x1A9A90
extern int d_1a9a98;                    // 0x1A9A98
extern int d_1a9a9c;                    // 0x1A9A9C
extern int d_1a9aa0;                    // 0x1A9AA0
extern int d_1a9aa8;                    // 0x1A9AA8
extern int d_1a9ab4;                    // 0x1A9AB4
extern int d_1a9ab8;                    // 0x1A9AB8
extern int d_1a9abc;                    // 0x1A9ABC
extern int d_1a9ac0;                    // 0x1A9AC0
extern int d_1a9ac4;                    // 0x1A9AC4
extern int d_1a9ac8;                    // 0x1A9AC8
extern int d_1a9ad0;                    // 0x1A9AD0
extern int d_1a9ad4;                    // 0x1A9AD4
extern int d_1a9adc;                    // 0x1A9ADC
extern int d_1a9ae0;                    // 0x1A9AE0
extern int d_1a9ae4;                    // 0x1A9AE4
extern int d_1a9ae8;                    // 0x1A9AE8
extern int d_1a9af4;                    // 0x1A9AF4
extern int d_1a9af8;                    // 0x1A9AF8
extern int d_1a9b00;                    // 0x1A9B00
extern int d_1a9b04;                    // 0x1A9B04
extern int d_1a9b0c;                    // 0x1A9B0C
extern int d_1a9b10;                    // 0x1A9B10
extern int d_1a9b14;                    // 0x1A9B14
extern int d_1a9b18;                    // 0x1A9B18
extern int d_1a9b1c;                    // 0x1A9B1C
extern int d_1ad4d4;                    // 0x1AD4D4
extern int d_1b8dc3;                    // 0x1B8DC3
extern int d_1b8e2f;                    // 0x1B8E2F
extern int d_1b8eb0;                    // 0x1B8EB0
extern int d_1b9010;                    // 0x1B9010
extern int d_1b90ec;                    // 0x1B90EC
extern int d_1b94e0;                    // 0x1B94E0
extern int d_1b9528;                    // 0x1B9528
extern int d_1b9544;                    // 0x1B9544
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2fe0;                    // 0x1C2FE0
extern int d_1c3960;                    // 0x1C3960
extern int d_1c396c;                    // 0x1C396C
extern int d_1c3c4c;                    // 0x1C3C4C Breiten byte,dword
extern int d_1c62c0;                    // 0x1C62C0
extern int d_1c69c8;                    // 0x1C69C8
extern int d_1c6ad8;                    // 0x1C6AD8
extern int d_1c6b40;                    // 0x1C6B40
extern int d_1c6b44;                    // 0x1C6B44
extern int d_1c6b48;                    // 0x1C6B48
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
extern int d_1cd1cc;                    // 0x1CD1CC
extern int d_1cd1d0;                    // 0x1CD1D0
extern int d_1cd1d4;                    // 0x1CD1D4
extern int d_1cd1dc;                    // 0x1CD1DC
extern int d_1cd1fc;                    // 0x1CD1FC
extern int d_1cd208;                    // 0x1CD208
extern int d_1cd20c;                    // 0x1CD20C
extern int d_1cd210;                    // 0x1CD210
extern int d_1cd214;                    // 0x1CD214
extern int d_1cd218;                    // 0x1CD218
extern int d_1cd21c;                    // 0x1CD21C
extern int d_1cd220;                    // 0x1CD220
extern int d_1cd224;                    // 0x1CD224
extern int d_1cd228;                    // 0x1CD228
extern int d_1cd22c;                    // 0x1CD22C
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

extern unsigned char d_1a98e1, d_1a98e2, d_1a98e3, d_1a98e4, d_1a98e5, d_1a98e6, d_1a9944, d_1a9949, d_1a994d, d_1a994f, d_1a993b, d_1a993c, d_1a9a1c;
extern unsigned short d_1a98e8, d_1a9962, d_1a9964, d_1a9966, d_1cdc1a, d_1cdc1e;
extern char *d_1a98f4, *d_1a98f8, *d_1a98fc;
extern int d_1cd230[3];
extern unsigned char d_1a9a1d;
// --- t3 Handanteil ---
#define I32(p,o) (*(int *)((char *)(p) + (o)))
#define U32(p,o) (*(unsigned *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define B8(p,o) (*(unsigned char *)((char *)(p) + (o)))
int FM(int a, int b);
#pragma aux FM = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify exact [eax edx] value [eax];
int FDIV(int a, int b);
#pragma aux FDIV = "mov edx,eax" "sar edx,16" "shl eax,16" "idiv ebx" parm [eax] [ebx] modify exact [eax edx] value [eax];
#include <stdlib.h>
#pragma intrinsic(abs)
#define ABS(x) abs(x)
struct E { int a; char *o; };
extern struct E d_1c3970[];
extern char d_1c3c40[];
extern unsigned char d_1a98e0, d_1a9938, d_1a9939, d_1a993a;
extern int d_1a9a74, d_1a9ab0, d_1a9afc;
extern double d_1b8e4c;
extern const char d_1b8db4[], d_1b8dbc[], d_1b8dc4[], d_1b8dcc[], d_1b8dd4[], d_1b8df8[], d_1b8e00[], d_1b8e08[], d_1b8e0c[], d_1b8e18[], d_1b8e20[], d_1b8e28[];
int f_14dc6c(int p1);
int f_14def4(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_14ea94(int p1, int p2, int p3, int p4);
void f_14fa64(void);
void f_14fd64(void);
int f_16d3d0(int p1);
short f_16d8ad(short y, short x);
#pragma aux f_16d8ad parm caller [];
int f_16ebd8(int p1, int p2, int p3, int p4, int p5, const char *p6, ...);
#pragma aux f_16ebd8 modify exact [eax];
#pragma aux f_150050 "*";
#pragma aux f_150334 "*";
int mul150334(int a, int b);
#pragma aux mul150334 = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int div150334(int a, int b);
#pragma aux div150334 = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm [edx] [ebx] modify exact [eax edx ebx ecx esi] value [eax];
#pragma aux f_150734 "*";
#pragma aux f_1508fc "*";
#pragma aux f_151060 "*";

//@ f_150050
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchläuft die nach Distanz sortierte Liste der Polygon-Ein- und Austrittsereignisse
 *   (d_1c3970, Anzahl d_1c6ba0) entlang des aktuellen Bewegungsschritts und führt Buch über die Zahl der
 *   gleichzeitig aktiven Bodenpolygone (c1), Wandhindernisse (c2), Durchgangsöffnungen/Türen (c4) und
 *   Triggerzonen (c8). Sobald der Spieler auf eine nicht durch eine Öffnung (c4) freigegebene Wand trifft (flags
 *   & 2) oder den begehbaren Boden verlässt (c1 <= 0), speichert die Funktion das blockierende Hindernis in
 *   d_1a98fc (samt Objekt-Handle d_1cd218 und ID d_1a9966) und bricht den weiteren Weg an dieser Stelle ab.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - c1, c2, c4, c8: Laufende Zähler für überlappende Böden (1), Wände (2), Öffnungen (4) und
 *     Trigger/Aktionsflächen (8).
 *   - d_1a98fc: Zeiger auf das erste blockierende Kollisionsereignis.
 *   - d_1a98f4, d_1a98f8: Zeiger auf getroffene Trigger-/Ereignispolygone.
 === Ende Beschreibung === */
// haelt die Registerzuteilung wie im Original
#define PICK150(P) { char *hit = (char *)I32(P,0x24); int handle = I32(hit,0x34); unsigned short id = U16(hit,8); d_1cd218 = handle; d_1a9966 = id; *(volatile int *)&d_1c6ba0 = count; return; }
void f_150050(void)
{
    char *o, *prev8, *prev2, *active2, *so;
    struct E *entry, *scan;
    int count, c2, c4, c8, c1, index, delta, si, pass, limit;
    unsigned flags; short j, k; int t2;
    count = d_1c6ba0;
    c2 = 0;
    t2 = k - k; /* haelt die Registerzuteilung wie im Original */
    c4 = 0; c8 = 0;  /* haelt die Registerzuteilung wie im Original */
    entry = d_1c3970;
    d_1a98ec = j - j; /* haelt die Registerzuteilung wie im Original */
    prev8 = 0;
    d_1a98f4 = 0;
    prev2 = 0;
    active2 = 0;
    *(int *)&d_1a98fc = t2;
    d_1a98f8 = 0;
    c1 = 0;
    if (count <= 0) {
        d_1a9944 = 1; ((unsigned char *)&d_1a98e0)[1] = 1; ((unsigned char *)&d_1a9938)[2] = 1;
        d_1cd218 = 0; d_1a9966 = 0;
    } else {
        index = 0;
        ((unsigned char *)&d_1a98e0)[1] = 0; ((unsigned char *)&d_1a9938)[2] = 0;
        for (; index < count; index++, entry++) {
            if (entry->a > d_1a9a74) break;
            o = entry->o;
            if (*o == 1) delta = 1; else delta = -1;
            flags = U32(o,4);
            if (flags && !(flags & 0x80)) {
                d_1a98ec = entry->a;
                if (*o == 1) d_1a98fc = o;
                if (flags & 1) c1 += delta;
                if (flags & 8) {
                    c8 += delta;
                    if (*o == 1) {
                        prev8 = d_1a98f4; d_1a98f4 = o;
                        if ((flags & 0x10) && d_1a98ec > 0 &&
                            d_1a98ec < d_1a9a74 && !d_1a98f8) d_1a98f8 = o;
                    } else {
                        if (c8 > 0) d_1a98f4 = prev8; else d_1a98f4 = 0;
                    }
                }
                if (flags & 2) {
                    c2 += delta;
                    if (*o == 1) {
                        prev2 = active2; active2 = o;
                        if (c4 <= 0 || (flags & 0x100)) {
                            d_1a98fc = active2; ((unsigned char *)&d_1a9938)[2] = 1;
                            PICK150(active2)
                        }
                    } else if (c2 > 0) active2 = prev2;
                }
                if (flags & 4) {
                    if ((c4 += delta) <= 0 && c2 > 0) {
                        d_1a98fc = o; ((unsigned char *)&d_1a9938)[2] = 1;
                        PICK150(o)
                    }
                }
                if (c1 <= 0) {
                    pass = 1; scan = entry + 1; si = index + pass;
                    for (; si < count; si++, scan++) {
                        if (d_1a98ec + 0x28f <= scan->a) break;
                        so = scan->o;
                        if (*so == 1 && (B8(so,4) & 1)) { pass = 0; break; }
                    }
                    if (pass) {
                        if (!d_1a98ec) d_1a9944 = 1;
                        ((unsigned char *)&d_1a98e0)[1] = 1; ((unsigned char *)&d_1a9938)[2] = 1; d_1a98fc = o;
                        PICK150(o)
                    }
                }
            }
        }
    }
    d_1c6ba0 = count;
}
#undef PICK150

//@ f_150334
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Korrigiert nach einer in f_150050 erkannten Kollision (d_1a993a != 0) die Zielposition
 *   (d_1c6b84, d_1c6b80) des Spielers so, dass er kurz vor dem getroffenen Hindernis d_1a98fc zum Stehen kommt,
 *   ohne in die Wand einzudringen, und übernimmt gegebenenfalls die Ereignis-ID (d_1a9962, <= 9000) einer
 *   berührten Triggerfläche (d_1a98f8 / d_1a98f4).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a98ec: Zulässige freie Bewegungsdistanz bis kurz vor den Kollisionspunkt.
 *   - d_1a9962: Ausgelöste Trigger-/Aktions-ID (0xffff wenn keine).
 *   - d_1a993b: Flag, ob ein Abgleiten entlang der Wandnormale versucht werden soll.
 === Ende Beschreibung === */
void f_150334(void)
{
    unsigned short id;
    char *hit;
    char *item;
    int x;
    int y;
    int numerator;
    int denominator;
    int allowed;
    int found;
    int clear;
    int index;
    int valid;
    int position;
    int scaleX;
    int horizontal;
    int baseX;
    int baseY;
    int selectedPtr;

    d_1a98e8 = 0xffff;
    d_1a993b = 0;
    if (d_1a98f8) {
        id = U16(I32(I32(d_1a98f8, 0x24), 0x34), 2);
        if (id != 0xffff && id <= 0x2328) {
            d_1a9962 = id;
            d_1a9949 = 0;
        }
    }
    if (d_1a993a) {
        d_1a98e0 = 1;
        if (!d_1a98fc) {
            d_1a98ec = 0;
            d_1c6b84 = d_1c6b78;
            d_1a98e8 = 0xffff;
            d_1c6b80 = d_1c6b7c;
            return;
        }

        if (B8(d_1a98fc, 4) & 0x10) {
            id = U16(I32(I32(d_1a98fc, 0x24), 0x34), 2);
            if (id != 0xffff && id <= 0x2328) d_1a9962 = id;
        } else {
            d_1a993b = 1;
        }
        if (d_1a98f4) {
            hit = (char *)I32(d_1a98f4, 0x24);
            d_1cd22c = I32(hit, 0x34);
            if (d_1a9949 && !(B8(d_1a98f4, 4) & 0x10) && f_14dc6c((int)hit)) {
                id = U16(I32(hit, 0x34), 2);
                if (id != 0xffff && id <= 0x2328) valid = 1;
                else valid = 0;
                if (valid) d_1a9962 = id;
            }
        }

        x = I32(d_1a98fc, 0x14);
        { int rt = x; x = rt; } /* haelt die Registerzuteilung wie im Original */
        d_1a98e8 = U16(I32(I32(d_1a98fc, 0x24), 0x34), 2);
        d_1a98ec = I32(d_1a98fc, 8);
        y = I32(d_1a98fc, 0x18);
        { int rt = y; y = rt; } /* haelt die Registerzuteilung wie im Original */ { int rt = y; y = rt; }
        numerator = f_16d33f(x, x, y, y) / 4;
        denominator = f_16d33f(d_1c6ba8, x, d_1c6ba4, y);
        if (ABS(denominator) > ABS(numerator >> 15)) {
            int r = d_1a98ec;
            d_1a98f0 = div150334(numerator, denominator);
            d_1a98ec = r - ABS(d_1a98f0);
            if (d_1a98ec < 0) d_1a98ec = 0;
        }

        do {
            int radius = d_1a98ec;
            d_1c6b84 = d_1c6b78 + mul150334(radius, d_1c6ba8);
            d_1c6b80 = mul150334(radius, d_1c6ba4) + d_1c6b7c;
            allowed = 1;
            if (d_1a98e1) {
                if (!f_14ea94(I32(d_1a98fc, 0x24), 1, d_1c6b84, d_1c6b80)) allowed = 0;
            } else {
                if (f_14ea94(I32(d_1a98fc, 0x24), 1, d_1c6b84, d_1c6b80)) allowed = 0;
            }
            if (!allowed) {
                d_1a98ec -= 0x1999;
                if (d_1a98ec < 0) {
                    d_1a98ec = numerator ^ numerator; /* haelt die Registerzuteilung wie im Original */
                    break;
                }
            }
        } while (!allowed);

        horizontal = d_1c6ba8;
        position = d_1a98ec;
        baseX = d_1c6b78;
        selectedPtr = (int)d_1a98fc;
        { int rt = selectedPtr; selectedPtr = rt; } /* haelt die Registerzuteilung wie im Original */ { int rt = selectedPtr; selectedPtr = rt; } /* haelt die Registerzuteilung wie im Original */
        baseY = d_1c6b7c;
        d_1c6b84 = mul150334(position, horizontal) + baseX;
        I32(selectedPtr, 0xc) = d_1c6b84;
        index = 0;
        d_1c6b80 = mul150334(position, d_1c6ba4) + baseY;
        I32(selectedPtr, 8) = position;
        item = d_1c3c40;
        I32(selectedPtr, 0x10) = d_1c6b80;
        found = 0;
        clear = 1;
        if (d_1a9a10 > 0) do {
            if ((U32(item, 0xc) & 3) == 1 && !found &&
                f_14ea94((int)item, 1, d_1c6b84, d_1c6b80)) found = 1;
            if ((B8(item, 0xc) & 2) &&
                f_14ea94((int)item, 1, d_1c6b84, d_1c6b80)) {
                clear = 0;
                break;
            }
            ++index;
            item += 0x38;
        } while (index < d_1a9a10);
        if (clear && found) return;
        { int resetX; char *sel;
        d_1a9944 = 1;
        resetX = d_1c6b78;
        sel = d_1a98fc;
         /* haelt die Registerzuteilung wie im Original */
        d_1c6b84 = resetX;
        I32(sel, 0xc) = resetX;
        d_1a98ec = 0;
        d_1c6b80 = d_1c6b7c;
        I32(sel, 0x10) = d_1c6b80; }
        return;
    }

    if (d_1a98f4) {
        hit = (char *)I32(d_1a98f4, 0x24);
        d_1cd22c = I32(hit, 0x34);
        if (d_1a9949 && !(B8(d_1a98f4, 4) & 0x10) &&
            (f_14ea94((int)hit, 2, d_1c6b78, d_1c6b7c) || f_14dc6c((int)hit))) {
            id = U16(I32(hit, 0x34), 2);
            if (id != 0xffff && id <= 0x2328) valid = 1;
            else valid = 0;
            if (valid) d_1a9962 = id;
        }
    }
}

//@ f_150734
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Glättet den aktuellen Boden-Normalenvektor d_1cd230[0..2] per exponentiellem Mittelwert
 *   ((7 * alt + ziel ± 4) / 8) in Richtung der neuen Standflächennormale (d_1c6b54, d_1c6b58, d_1c6b5c) und
 *   berechnet daraus über f_16d8ad (atan2) den Nickwinkel (d_1cdc1a) der Kamera beim Gehen auf Treppen oder
 *   Schrägen.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1cd230[0..2]: Geglätteter 3D-Normalenvektor des Untergrunds.
 *   - d_1cdc1a: Berechneter vertikaler Neigungswinkel der Sicht auf Schrägen.
 *   - d_1a994f: Flag, das 1 bleibt, solange die Normalenglättung noch nachläuft.
 === Ende Beschreibung === */
void f_150734(void)
{
    int m[12];
    int v[3];
    int t;
    int a;
    int a7;
    int sum;
    int x;
    short y;

    d_1a994f = 1;
    if (d_1c6b54 < 0) {
        t = -4;
    } else {
        t = 4;
    }
    a = d_1cd230[0];
    a7 = a * 8;
    a7 -= a;
    sum = d_1c6b54;
    sum += a7;
    sum += t;
    d_1cd230[0] = sum / 8;
    a = d_1cd230[1];
    a7 = a * 8;
    a7 -= a;
    a7 += d_1c6b58;
    if (d_1c6b58 < 0) {
        sum = -4;
    } else {
        sum = 4;
    }
    sum += a7;
    d_1cd230[1] = sum / 8;
    a = d_1cd230[2];
    a7 = a * 8;
    a7 -= a;
    a7 += d_1c6b5c;
    if (d_1c6b5c < 0) {
        sum = -4;
    } else {
        sum = 4;
    }
    sum += a7;
    d_1cd230[2] = sum / 8;
    if (d_1cd230[1] < 0xffff) {
        f_16b930((int)m);
        f_16cc44((int)m, (unsigned short)-d_1cdc1e);
        f_16cff5((int)v, (int)d_1cd230, (int)m);
        x = v[1] / 2 / 2;
        y = v[2] / 2 / 2;
        d_1cdc1a = f_16d8ad(y, x);
        if (d_1cdc1a < 0x7ff8 && 0x37a0 < d_1cdc1a) {
            d_1cdc1a = 0x37a0;
        } else if (0x7ff8 < d_1cdc1a && d_1cdc1a < 0xc850) {
            d_1cdc1a = 0xc850;
        }
    } else {
        d_1cdc1a = 0;
    }
    if (d_1cd230[0] == d_1c6b54 && d_1cd230[1] == d_1c6b58 && d_1cd230[2] == d_1c6b5c) {
        d_1a994f = 0;
    }
}

//@ f_1508fc
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hauptfunktion für einen vollständigen 3D-Bewegungs- und Physikschritt des Spielers von
 *   (d_1cd23c, d_1cd240, d_1cd244) zur Wunschposition (d_1cd308, d_1cd30c, d_1cd310). Sie sammelt die
 *   umliegenden Kollisionspolygone (f_14fa64), führt in bis zu 4 Iterationen die 2D-Wandkollision mit
 *   Wandgleiten entlang der getroffenen Wandtangente (f_14fd64, f_150050, f_150334) durch, tastet anschließend
 *   die zurückgelegte Strecke in Teilschritten (local_38) mit f_14def4 nach der Bodenhöhe,
 *   Schwerkraft/Fallgeschwindigkeit (d_1a9ab4) und Raumnummer (d_1cdb3c) ab und aktualisiert zuletzt über
 *   f_150734 die Kameraneigung.
 * - Eingaben: Keine Parameter (liest Start- und Zielkoordinaten aus den globalen 3D-Bewegungsvariablen).
 * - Rückgabewert: Statusbyte aus d_1a98dd >> 24.
 * - Wichtige Variablen:
 *   - iter: Schleifenzähler für bis zu 4 Wandgleit-Versuche.
 *   - step, local_38: Laufindex und Anzahl der Unterteilungsschritte für die Bodenhöhenabtastung.
 *   - cz: Laufende vertikale Höhe des Spielers (inklusive Schwerkraft/Fallen bei d_1a994d).
 === Ende Beschreibung === */
int mul1508fc(int,int);
#pragma aux mul1508fc = "imul ebx" "shrd eax,edx,16" parm [eax] [ebx] modify exact [eax edx] value [eax];
int div1508fc(int,int);
#pragma aux div1508fc = "mov eax,edx" "shl eax,16" "sar edx,16" "idiv ebx" parm [edx] [ebx] modify exact [eax edx ebx] value [eax];
#define local_38 n

// BLIND: f_1508fc hier komplett neu aus dem Original-Assembler schreiben (orig.sh fz_14dc28_t3 f_1508fc).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
struct V3_1508fc { int a, b, c; };
struct ST_1508fc { int n; int sv; int last; };
int f_1508fc(void)
{
    
    int dy;
    int cx;
    int cy;
    int n;
    int sv;
    int iter;
    int step;
    int cz;
    int dx;
    int nx;
    int ny;
    int len;
    int dot;
    char *p;
    char *q;
    char *r;
    int i;
    int id;
    int ty;
    int tx;
    int min_z;
    int oy;
    int ox;
    int d;


    d_1a9962 = 0xffff;
    d_1a9964 = 0;
    d_1a9944 = 0;
    len = d_1a9a74;
    d_1cdb3c = 0;
    *(short *)&d_1a9966 = 0;
    d_1cd22c = 0;
    *(volatile int *)&d_1cd214 = 0;
    d_1cd218 = 0;
    d_1a994f = 0;
    d_1c6b54 = 0;
    d_1c6b58 = len;
    d_1c6b5c = 0;
    d_1a98e6 = 0;
    d_1a98e2 = 0;
    d_1a98ec = 0;
    d_1a98f0 = 0;
    d_1a98e3 = 0;
    d_1a98e0 = 0;
    ox = d_1cd23c;
    { int u = ox; ox = u; }
    oy = d_1cd244;
    d_1c6b78 = ox;
    dy = d_1cd240;
    dx = d_1cd30c;
    d_1c6b74 = dy;
    d_1c6b7c = oy;
    d_1c6b88 = dx;
    ny = d_1cd310;
    ny = (ny & 0) ? 0 : ny; // haelt die Registerzuteilung wie im Original
    nx = d_1cd308;
 // haelt die Registerzuteilung wie im Original
    d_1c6b84 = nx;
    d_1c6b80 = ny;
    d_1c6ba8 = nx - ox;
    d_1c6ba4 = ny - oy;
    if (nx < ox) {
        d_1c6b90 = ox;
        d_1c6bac = nx;
    } else {
        d_1c6b90 = nx;
        d_1c6bac = ox;
    }
    if (d_1c6b80 < d_1c6b7c) {
        d_1c6bb0 = d_1c6b80;
        d_1c6b8c = d_1c6b7c;
    } else {
        d_1c6bb0 = d_1c6b7c;
        d_1c6b8c = d_1c6b80;
    }
    d_1c6b68 = d_1c6bac - d_1a9afc * 8;
    d_1c6b64 = d_1c6b90 + d_1a9afc * 8;
    d_1c6b6c = d_1c6bb0 - d_1a9afc * 8;
    d_1c6b60 = d_1c6b8c + d_1a9afc * 8;
    iter = 0;
    f_14fa64();
    for (;;) {
        f_14fd64();
        f_150050();
        if (!(d_1a9a1c & 0x40)) break;
        f_150334();
        if (!d_1a993b || iter > 3) break;
        p = d_1a98fc;
        dx = d_1cd308 - ((int *)p)[3];
        dy = ((int *)p)[4];
        nx = ((int *)p)[7];
        ny = ((int *)p)[8];
        { int u = ny; ny = u; }
        dy = d_1cd310 - dy;
        len = f_16d4d8(nx, ny);
        len = (len & 0) ? 0 : len; // haelt die Registerzuteilung wie im Original
        len = (len & 0) ? 0 : len; // haelt die Registerzuteilung wie im Original
        len = (len & 0) ? 0 : len; // haelt die Registerzuteilung wie im Original
        if (len > 0) {
            nx = div1508fc(nx, len);
            ny = div1508fc(ny, len);
        }
        dot = f_16d33f(nx, dx, ny, dy);
        { unsigned rt1508 = (unsigned)d_1c6b54; int magnitude1508;
        rt1508 += (unsigned)d_1c6b78;
        rt1508 += (unsigned)d_1c6b74;
        magnitude1508 = ABS(dot);
        d_1c6b58 = (int)((unsigned)d_1c6b58 + (rt1508 ^ rt1508)); // haelt die Registerzuteilung wie im Original
        if (magnitude1508 < 0x28f) {
            if (dot < 0 && dot > -0x28f) dot = -0x28f;
            if (dot >= 0 && dot < 0x28f) dot = 0x28f;
        }
        }
        nx = mul1508fc(dot, nx);
        d_1c6ba8 = nx;
        ny = mul1508fc(dot, ny);
        p = d_1a98fc;
        d_1c6ba4 = ny;
        tx = ((int *)p)[3];
        ty = ((int *)p)[4];
        d_1c6b80 = ny + ty;
        d_1c6b78 = tx;
        d_1c6b84 = tx + nx;
        d_1c6b7c = ty;
        { unsigned rt1508 = (unsigned)d_1c6b54; unsigned zero1508 = rt1508 ^ rt1508;
          d_1c6b58 = (int)((unsigned)d_1c6b58 + zero1508);
          d_1c6b5c = (int)((unsigned)d_1c6b5c + zero1508);
          d_1c6b74 = (int)((unsigned)d_1c6b74 + zero1508);
          d_1c6b88 = (int)((unsigned)d_1c6b88 + zero1508);
          d_1c6b90 = (int)((unsigned)d_1c6b90 + zero1508);
        } // haelt die Registerzuteilung wie im Original
        iter++;
    }
    if (d_1a9949) {
        p = d_1c3c40;
        for (i = 0; i < d_1a9a10; i++, p += 0x38) {
            if (I32(p, 0x34) != 0 && (I32(p, 0xc) & 0xa) == 0xa && (B8(p, 0xc) & 0x10) == 0) {
                tx = d_1c6b84;
                ty = d_1c6b80;
                tx -= I32(p, 0x10);
                ty -= I32(p, 0x14);
                dy = I32(p, 0x10) + mul1508fc(0xb333, tx);
                ty = I32(p, 0x14) + mul1508fc(0xb333, ty);
                if (f_14ea94((int)p, 1, dy, ty) && f_14dc6c((int)p)) {
                    q = (char *)I32(p, 0x34);
                    id = *(unsigned short *)(q + 2);
                    if (id != 0xffff && id <= 0x2328) {
                        d_1a9962 = id;
                        d_1cd22c = (int)q;
                    }
                    break;
                }
            }
        }
    }
    if (d_1a98e2) {
        p = d_1c3c40;
        for (i = 0; i < d_1a9a10; i++, p += 0x38) {
            if ((I32(p, 0xc) & 0x200) &&
                f_14ea94((int)p, 1, d_1c6b84, d_1c6b80) &&
                I32(I32(I32(d_1a98fc, 0x24), 0x34), 0x28) != 0) {
                d_1a98e6 = 1;
                *(struct V3_1508fc *)&d_1c6b54 = *(struct V3_1508fc *)(p + 0x1c);
                break;
            }
        }
    }
    q = d_1a98fc;
    if (q) {
        q = (char *)I32(q, 0x24);
        if (I32(q, 0x34)) {
            r = (char *)I32(q, 0x34);
            if ((B8(q, 0xc) & 1) && !d_1a98e6 && I32(r, 0x28)) {
                *(struct V3_1508fc *)&d_1c6b54 = *(struct V3_1508fc *)(q + 0x1c);
            }
        }
    }
    dx = d_1c6b84 - d_1c6b78;
    dy = d_1c6b80 - d_1c6b7c;
    d_1c6ba8 = dx;
    d_1c6ba4 = dy;
    local_38 = div1508fc(f_16d3d0(f_16d33f(dx, dx, dy, dy)), 0x8000) >> 16;
    if (local_38 < 1) {
        local_38 = 1;
    } else if (local_38 > 100) {
        local_38 = 100;
    }
    { unsigned char byte_copy = ((unsigned char *)&n)[0]; ((unsigned char *)&n)[0] = byte_copy; } // haelt die Registerzuteilung wie im Original
    { unsigned char byte_copy = ((unsigned char *)&n)[1]; ((unsigned char *)&n)[1] = byte_copy; } // haelt die Registerzuteilung wie im Original
    { unsigned char byte_copy = ((unsigned char *)&n)[2]; ((unsigned char *)&n)[2] = byte_copy; } // haelt die Registerzuteilung wie im Original
    cx = d_1c6b78;
 // haelt die Registerzuteilung wie im Original
    cy = d_1c6b7c;
    d_1c6ba8 /= local_38;
    d_1c6ba4 /= local_38;
    cz = d_1c6b74;
    if (d_1a994d) {
        sv = mul1508fc(d_1a9b1c, d_1a9ab0) / local_38;
    { unsigned char byte_copy = ((unsigned char *)&sv)[0]; ((unsigned char *)&sv)[0] = byte_copy; } // haelt die Registerzuteilung wie im Original
    { unsigned char byte_copy = ((unsigned char *)&sv)[1]; ((unsigned char *)&sv)[1] = byte_copy; } // haelt die Registerzuteilung wie im Original
    }
    { unsigned char byte_copy = ((unsigned char *)&cx)[0]; ((unsigned char *)&cx)[0] = byte_copy; } // haelt die Registerzuteilung wie im Original
    { unsigned char byte_copy = ((unsigned char *)&cy)[0]; ((unsigned char *)&cy)[0] = byte_copy; } // haelt die Registerzuteilung wie im Original
    d_1a98e5 = 0;
    d_1a98e4 = 0;
    step = 0;
    while (step < local_38) {
        d_1a99e0 = 0;
        d_1cdb3c = 0;
        d_1c6b9c = -0x7fffffff;
        d_1c6b94 = -0x7fffffff;
        d_1a98e3 = 0;
        d_1a9938 = 0;
        d_1a9abc = -0x7fffffff;
        d_1a9ac0 = 0x7fffffff;
        d_1a9939 = 0;
        if (step >= local_38 - 1) {
            cx = d_1c6b84;
            cy = d_1c6b80;
        } else {
            cx += d_1c6ba8;
            cy += d_1c6ba4;
        }
        p = d_1c3c40;
        for (i = 0; i < d_1a9a10; i++, p += 0x38) {
            if ((B8(p, 0xc) & 0xa) == 0) {
                if (I32(p, 0x34)) {
                    int res;
                    q = (char *)I32(p, 0x34);
                    r = (char *)I32(q, 0x28);
                    tx = U16(p, 8) * 0x30;
                    res = f_14def4(
                        cx,
                        cz,
                        cy,
                        I32(r, 0x44) + tx,
                        (int)p,
                        (int)q,
                        B8(q, 1)
                    );
                    { int u = res; res = u; }
                    if (step >= local_38) {
                        *p = res;
                    }
                }
            }
        }
        if (d_1a99e0 > 0 && (d_1a9a1d & 0x40)) {
            if (d_1a9938) {
                id = d_1a9abc + d_1a9ae0;
                min_z = id;
                if (cz > id) {
                    if (d_1a994d && cz > id + 0x30000) {
                        d_1a993c = 1;
                        cz -= d_1a9ab4 / local_38;
                        d_1a9ab4 += sv;
                    } else {
                        cz = min_z;
                    }
                }
                if (cz < min_z) {
                    d_1a993c = 0;
                    cz = min_z;
                    d_1a9ab4 = 0;
                }
                if (!d_1a98e6 && d_1c6b4c) {
                    *(struct V3_1508fc *)&d_1c6b54 = *(struct V3_1508fc *)d_1c6b4c;
                }
            } else {
                cz = d_1a9ac0 + d_1a9ae0;
                d_1a993c = 0;
                d_1a9ab4 = 0;
                if (!d_1a98e6 && d_1c6b50) {
                    *(struct V3_1508fc *)&d_1c6b54 = *(struct V3_1508fc *)d_1c6b50;
                }
            }
            d_1a98e0 = 1;
        } else {
            d_1a993c = 0;
            d_1a9ab4 = 0;
        }
        step++;
    }
    d_1c6b88 = cz;
    if (d_1c6b58 < 0) {
        d_1c6b54 = -d_1c6b54;
        d_1c6b58 = -d_1c6b58;
        d_1c6b5c = -d_1c6b5c;
    }
    f_150734();
    d_1cd308 = d_1c6b84;
    d_1cd30c = d_1c6b88;
    d_1cd310 = d_1c6b80;
    { int roundtrip = d_1c6b54; d_1c6b54 = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1c6b58; d_1c6b58 = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1c6b5c; d_1c6b5c = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1c6b78; d_1c6b78 = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1c6b74; d_1c6b74 = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1c6b7c; d_1c6b7c = roundtrip; } // haelt die Registerzuteilung wie im Original
    { int roundtrip = d_1a9a74; d_1a9a74 = roundtrip; } // haelt die Registerzuteilung wie im Original
    return d_1a98dd >> 24;
}


//@ f_151060
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt im Debug-Modus über f_16ebd8 die aktuellen Kollisionsparameter (d_1a98ec, d_1a98f0,
 *   Flags d_1a993a, d_1a993b) sowie eine tabellarische Liste aller in d_1c3970 verzeichneten
 *   Polygon-Schnitteinträge auf dem Bildschirm aus.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c3970 (Liste der Kollisionsschnitte), d_1c6ba0 (Anzahl der Einträge).
 === Ende Beschreibung === */
void f_151060(void)
{
    
    int index;
    struct E *entry;
    register char * hit;
    register unsigned flags;
    register char * object;
    register char * str;
    unsigned zf; char *zh, *zs; struct E *ze;


    f_16ebd8(d_1cd320, 0, 0x16, d_1a9b00, d_1ad4d4, d_1b8dd4,
        (double)d_1a98ec * d_1b8e4c,
        (double)d_1a98f0 * d_1b8e4c,
        d_1a993a ? d_1b8db4 : d_1b8dbc,
        d_1a993b ? d_1b8dc4 : d_1b8dcc);

    for (index = 0, entry = d_1c3970; index < d_1c6ba0; ++index, ++entry) {
        str = entry->o;
        hit = (char *)I32(str, 0x24);
        object = (char *)I32(hit, 0x34);
        object = (char *)I32(object, 0x28);
        flags = (unsigned)I32(str, 4);
        // haelt die Registerzuteilung wie im Original
        ze = entry; entry = ze; ze = entry; entry = ze; zs = str; str = zs; zh = hit; hit = zh; zf = flags; flags = zf; zf = flags; flags = zf;

        f_16ebd8(d_1cd320, 0, (short)(index * 8 + 0x1e), d_1a9b00, d_1ad4d4, d_1b8e28,
            (double)entry->a * d_1b8e4c,
            str[0] ? d_1b8df8 : d_1b8e00,
            I32(object, 0),
            U16(hit, 8),
            I32(I32(*(char **)(object + 0x44) + U16(hit, 8) * 0x30, 0x28), 0),
            (flags & 2) ? d_1b8db4 : d_1b8e08,
            (flags & 1) ? d_1b8e0c : d_1b8e08,
            (flags & 8) ? d_1b8e18 : d_1b8e08,
            B8(hit, 0) ? d_1b8e20 : d_1b8e08);
    }
}

