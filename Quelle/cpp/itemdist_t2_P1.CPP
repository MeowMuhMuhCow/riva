/* === Beschreibung (Katalog) ===
 * Einheit itemdist_t2 (0x0A9080 - 0x0AA250)
 *
 * Diese Einheit bildet den zweiten Teil des Gegenstandsverteilungs-Fensters (p:\riva\source\cpp\itemdist.cpp)
 * und umfasst die Tastatur- und Maus-Aktionsverarbeitung, den Fokuswechsel zwischen Heldeninventar und
 * Beutepool, die Schließen-Prüfung sowie die Cursornavigation im Gegenstandsgitter.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/12 gleich (suche.py 30.10.2026, Basis itemdist_t2_P1.CPP)
// itemdist.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A7D50-0x0AB880
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e0c0();                                         // reg - stapel 0
int f_01f3c0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);// reg eax edx ebx ecx stapel 16
int f_01f410(int p1, int p2);                           // reg eax stapel 0
int f_01f450(int p1, int p2);                           // reg eax edx stapel 0
int f_01f460(int p1);                                   // reg eax stapel 0
int f_01f470(int p1, int p2);                           // reg eax edx stapel 0
int f_01f560(int p1, int p2);                           // reg eax edx stapel 0
int f_01f6f0(int p1);                                   // reg eax stapel 0
int f_01f7d0(int p1);                                   // reg eax stapel 0
int f_01f8b0(int p1);                                   // reg eax stapel 0
int f_01f990(int p1);                                   // reg eax stapel 0
int f_01fa70(int p1);                                   // reg eax stapel 0
int f_01fa80(int p1);                                   // reg eax stapel 0
int f_01fb40(int p1, int p2);                           // reg eax edx stapel 0
int f_01fef0(int p1, int p2);                           // reg eax edx stapel 0
int f_020150(int p1);                                   // reg eax stapel 0
int f_020640(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_025c50(int p1, int p2);                           // reg eax edx stapel 0
int f_025d90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0264d0(int p1, int p2);                           // reg eax edx stapel 0
int f_026570(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0266e0(int p1, int p2);                           // reg eax edx stapel 0
int f_026a20(int p1, int p2);                           // reg eax edx stapel 0
int f_026a80(int p1, int p2);                           // reg eax edx stapel 0
int f_026ff0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_027050(int p1, int p2);                           // reg eax stapel 0
int f_027070(int p1);                                   // reg eax stapel 0
int f_027080(int p1);                                   // reg eax stapel 0
int f_027090(int p1);                                   // reg eax stapel 0
int f_0270a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0270b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0270c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0270d0(int p1);                                   // reg eax stapel 0
int f_027240(int p1);                                   // reg eax stapel 0
int f_027280(int p1, int p2);                           // reg eax edx stapel 0
int f_0272d0(int p1);                                   // reg eax stapel 0
int f_027690(int p1);                                   // reg eax stapel 0
int f_027750(int p1);                                   // reg eax stapel 0
int f_027830(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_050860();                       // nicht in clobber.tsv
int f_0508f0(int p1, int p2);                           // reg eax stapel 0
int f_050920(int p1);                                   // reg eax stapel 0
int f_050930(int p1);                                   // reg eax stapel 0
int f_050940(int p1);                                   // reg eax stapel 0
int f_050970(int p1, int p2);                           // reg eax edx stapel 0
int f_050980(int p1, int p2);                           // reg eax edx stapel 0
int f_050b40(int p1, int p2);                           // reg eax edx stapel 0
int f_050c70(int p1);                                   // reg eax stapel 0
int f_050e30(int p1, int p2);                           // reg eax edx stapel 0
int f_050ea0(int p1, int p2);                           // reg eax edx stapel 0
int f_051060(int p1);                                   // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_0a22e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0a2400(int p1, int p2);                           // reg eax stapel 0
int f_0a2430(int p1);                                   // reg eax stapel 0
int f_0a2440(int p1);                                   // reg eax stapel 0
int f_0a2460(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0a2480(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0bf680(int p1);                                   // reg eax stapel 0
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce650();                                         // reg - stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d37e0();                                         // reg - stapel 0
int f_0d3800();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
int f_11c160(int p1);                                   // reg eax stapel 0
int f_11c330(int p1, int p2);                           // reg eax edx stapel 0
int f_11c350(int p1, int p2);                           // reg eax edx stapel 0
int f_11c580(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13fc70(int p1);                                   // reg eax stapel 0
int f_13fcd0(int p1, int p2);                           // reg eax edx stapel 0
int f_140220();                       // nicht in clobber.tsv
int f_140300(int p1, int p2);                           // reg eax stapel 0
int f_140360(int p1);                                   // reg eax stapel 0
int f_140370(int p1);                                   // reg eax stapel 0
int f_140380(int p1);                                   // reg eax stapel 0
int f_140390(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1404e0(int p1);                                   // reg eax stapel 0
int f_1405c0(int p1);                                   // reg eax stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_149cf0();                       // nicht in clobber.tsv
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a48f4;                    // 0x1A48F4
extern int d_1a48f6;                    // 0x1A48F6
extern int d_1a48f8;                    // 0x1A48F8
extern int d_1a48fa;                    // 0x1A48FA
extern int d_1a48fc;                    // 0x1A48FC
extern int d_1a48fe;                    // 0x1A48FE
extern int d_1a4900;                    // 0x1A4900
extern int d_1a4902;                    // 0x1A4902
extern int d_1a4904;                    // 0x1A4904
extern int d_1a4906;                    // 0x1A4906
extern int d_1a4908;                    // 0x1A4908
extern int d_1a490a;                    // 0x1A490A
extern int d_1a490c;                    // 0x1A490C
extern int d_1a490e;                    // 0x1A490E
extern int d_1a4910;                    // 0x1A4910
extern int d_1a4912;                    // 0x1A4912
extern int d_1a4914;                    // 0x1A4914
extern int d_1a4916;                    // 0x1A4916
extern int d_1a4918;                    // 0x1A4918
extern int d_1a491a;                    // 0x1A491A
extern int d_1a491c;                    // 0x1A491C
extern int d_1a491e;                    // 0x1A491E
extern int d_1a4920;                    // 0x1A4920
extern int d_1a4922;                    // 0x1A4922
extern int d_1a4924;                    // 0x1A4924
extern int d_1a4926;                    // 0x1A4926
extern int d_1a4928;                    // 0x1A4928
extern int d_1a492a;                    // 0x1A492A
extern int d_1a492c;                    // 0x1A492C
extern int d_1a492e;                    // 0x1A492E
extern int d_1a4930;                    // 0x1A4930
extern int d_1a4932;                    // 0x1A4932
extern int d_1a4934;                    // 0x1A4934
extern int d_1a4936;                    // 0x1A4936
extern int d_1a4938;                    // 0x1A4938
extern int d_1a493a;                    // 0x1A493A
extern int d_1a493c;                    // 0x1A493C
extern int d_1a493e;                    // 0x1A493E
extern int d_1a4940;                    // 0x1A4940
extern int d_1a4942;                    // 0x1A4942
extern int d_1a4944;                    // 0x1A4944
extern int d_1a4946;                    // 0x1A4946
extern int d_1a4948;                    // 0x1A4948
extern int d_1a494a;                    // 0x1A494A
extern int d_1a494c;                    // 0x1A494C
extern int d_1a494e;                    // 0x1A494E
extern int d_1a4950;                    // 0x1A4950
extern int d_1a4952;                    // 0x1A4952
extern int d_1a4954;                    // 0x1A4954
extern int d_1a4956;                    // 0x1A4956
extern int d_1a4958;                    // 0x1A4958
extern int d_1a495a;                    // 0x1A495A
extern int d_1a495c;                    // 0x1A495C
extern int d_1a495e;                    // 0x1A495E
extern int d_1a4960;                    // 0x1A4960
extern int d_1a4962;                    // 0x1A4962
extern int d_1a4964;                    // 0x1A4964
extern int d_1a4966;                    // 0x1A4966
extern int d_1a4968;                    // 0x1A4968
extern int d_1a496a;                    // 0x1A496A
extern int d_1a496c;                    // 0x1A496C
extern int d_1a496e;                    // 0x1A496E
extern int d_1a4970;                    // 0x1A4970
extern int d_1a4972;                    // 0x1A4972
extern int d_1a4974;                    // 0x1A4974
extern int d_1a4976;                    // 0x1A4976
extern int d_1a4978;                    // 0x1A4978
extern int d_1a497a;                    // 0x1A497A
extern int d_1a497c;                    // 0x1A497C
extern int d_1a497e;                    // 0x1A497E
extern int d_1a4980;                    // 0x1A4980
extern int d_1a4982;                    // 0x1A4982
extern int d_1a4984;                    // 0x1A4984
extern int d_1a4986;                    // 0x1A4986
extern int d_1a4988;                    // 0x1A4988
extern int d_1a498a;                    // 0x1A498A
extern int d_1a498c;                    // 0x1A498C
extern int d_1a498e;                    // 0x1A498E
extern int d_1a4990;                    // 0x1A4990
extern int d_1a4992;                    // 0x1A4992
extern int d_1a4994;                    // 0x1A4994
extern int d_1a4996;                    // 0x1A4996
extern int d_1a4998;                    // 0x1A4998
extern int d_1a499a;                    // 0x1A499A
extern int d_1a499c;                    // 0x1A499C
extern int d_1a499e;                    // 0x1A499E
extern int d_1a49a0;                    // 0x1A49A0
extern int d_1a49a2;                    // 0x1A49A2
extern int d_1a49a4;                    // 0x1A49A4
extern int d_1a49a6;                    // 0x1A49A6
extern int d_1a49b0;                    // 0x1A49B0
extern int d_1a49b2;                    // 0x1A49B2
extern int d_1a49b4;                    // 0x1A49B4
extern int d_1a49b6;                    // 0x1A49B6
extern int d_1a49b8;                    // 0x1A49B8
extern int d_1a49ba;                    // 0x1A49BA
extern int d_1a49bc;                    // 0x1A49BC
extern int d_1a49be;                    // 0x1A49BE
extern int d_1a49c0;                    // 0x1A49C0
extern int d_1a49c2;                    // 0x1A49C2
extern int d_1a49c4;                    // 0x1A49C4
extern int d_1a49c6;                    // 0x1A49C6
extern int d_1a49c8;                    // 0x1A49C8
extern int d_1a49ca;                    // 0x1A49CA
extern int d_1a49ce;                    // 0x1A49CE
extern int d_1a49d0;                    // 0x1A49D0
extern int d_1a49d2;                    // 0x1A49D2
extern int d_1a49d4;                    // 0x1A49D4
extern int d_1a49d8;                    // 0x1A49D8
extern int d_1a49da;                    // 0x1A49DA
extern int d_1a49dc;                    // 0x1A49DC
extern int d_1a49de;                    // 0x1A49DE
extern int d_1a49e2;                    // 0x1A49E2
extern int d_1a49e4;                    // 0x1A49E4
extern int d_1a49e6;                    // 0x1A49E6
extern int d_1a49e8;                    // 0x1A49E8
extern int d_1a49ec;                    // 0x1A49EC
extern int d_1a49ee;                    // 0x1A49EE
extern int d_1a49f0;                    // 0x1A49F0
extern int d_1a49f2;                    // 0x1A49F2
extern int d_1a49f6;                    // 0x1A49F6
extern int d_1a49f8;                    // 0x1A49F8
extern int d_1a49fa;                    // 0x1A49FA
extern int d_1a49fc;                    // 0x1A49FC
extern int d_1a4a00;                    // 0x1A4A00
extern int d_1a4a02;                    // 0x1A4A02
extern int d_1a4a04;                    // 0x1A4A04
extern int d_1a4a06;                    // 0x1A4A06
extern int d_1a4a0a;                    // 0x1A4A0A
extern int d_1a4a0c;                    // 0x1A4A0C
extern int d_1a4a0e;                    // 0x1A4A0E
extern int d_1a4a10;                    // 0x1A4A10
extern int d_1a4a14;                    // 0x1A4A14
extern int d_1a4a16;                    // 0x1A4A16
extern int d_1a4a18;                    // 0x1A4A18
extern int d_1a4a1a;                    // 0x1A4A1A
extern int d_1a4a1e;                    // 0x1A4A1E
extern int d_1a4a20;                    // 0x1A4A20
extern int d_1a4a22;                    // 0x1A4A22
extern int d_1a4a24;                    // 0x1A4A24
extern int d_1a4a28;                    // 0x1A4A28
extern int d_1a4a2a;                    // 0x1A4A2A
extern int d_1a4a2c;                    // 0x1A4A2C
extern int d_1a4a2e;                    // 0x1A4A2E
extern int d_1a4a32;                    // 0x1A4A32
extern int d_1a4a34;                    // 0x1A4A34
extern int d_1a4a36;                    // 0x1A4A36
extern int d_1a4a38;                    // 0x1A4A38
extern int d_1a4a3c;                    // 0x1A4A3C
extern int d_1a4a3e;                    // 0x1A4A3E
extern int d_1a4a40;                    // 0x1A4A40
extern int d_1a4a42;                    // 0x1A4A42
extern int d_1a4a46;                    // 0x1A4A46
extern int d_1a4a48;                    // 0x1A4A48
extern int d_1a4a4a;                    // 0x1A4A4A
extern int d_1a4a4c;                    // 0x1A4A4C
extern int d_1a4a50;                    // 0x1A4A50
extern int d_1a4a52;                    // 0x1A4A52
extern int d_1a4a54;                    // 0x1A4A54
extern int d_1a4a56;                    // 0x1A4A56
extern int d_1a4a5a;                    // 0x1A4A5A
extern int d_1a4a5c;                    // 0x1A4A5C
extern int d_1a4a5e;                    // 0x1A4A5E
extern int d_1a4a60;                    // 0x1A4A60
extern int d_1a4a64;                    // 0x1A4A64
extern int d_1a4a66;                    // 0x1A4A66
extern int d_1a4a68;                    // 0x1A4A68
extern int d_1a4a6a;                    // 0x1A4A6A
extern int d_1a4a6e;                    // 0x1A4A6E
extern int d_1a4a70;                    // 0x1A4A70
extern int d_1a4a72;                    // 0x1A4A72
extern int d_1a4a74;                    // 0x1A4A74
extern int d_1a4a78;                    // 0x1A4A78
extern int d_1a4a7a;                    // 0x1A4A7A
extern int d_1a4a7c;                    // 0x1A4A7C
extern int d_1a4a7e;                    // 0x1A4A7E
extern int d_1a4a82;                    // 0x1A4A82
extern int d_1a4a84;                    // 0x1A4A84
extern int d_1a4a86;                    // 0x1A4A86
extern int d_1a4a88;                    // 0x1A4A88
extern int d_1a4a8c;                    // 0x1A4A8C
extern int d_1a4a8e;                    // 0x1A4A8E
extern int d_1a4a90;                    // 0x1A4A90
extern int d_1a4a92;                    // 0x1A4A92
extern int d_1a4a96;                    // 0x1A4A96
extern int d_1a4a98;                    // 0x1A4A98
extern int d_1a4a9a;                    // 0x1A4A9A
extern int d_1a4a9c;                    // 0x1A4A9C
extern int d_1a4aa0;                    // 0x1A4AA0
extern int d_1a4aa2;                    // 0x1A4AA2
extern int d_1a4aa4;                    // 0x1A4AA4
extern int d_1a4aa6;                    // 0x1A4AA6
extern int d_1a4aaa;                    // 0x1A4AAA
extern int d_1a4aac;                    // 0x1A4AAC
extern int d_1a4aae;                    // 0x1A4AAE
extern int d_1a4ab0;                    // 0x1A4AB0
extern int d_1a4ab4;                    // 0x1A4AB4
extern int d_1a4ab6;                    // 0x1A4AB6
extern int d_1a4ab8;                    // 0x1A4AB8
extern int d_1a4aba;                    // 0x1A4ABA
extern int d_1a4abe;                    // 0x1A4ABE
extern int d_1a4ac0;                    // 0x1A4AC0
extern int d_1a4ac2;                    // 0x1A4AC2
extern int d_1a4ac4;                    // 0x1A4AC4
extern int d_1a4ac8;                    // 0x1A4AC8
extern int d_1a4aca;                    // 0x1A4ACA
extern int d_1a4acc;                    // 0x1A4ACC
extern int d_1a4ace;                    // 0x1A4ACE
extern int d_1a4ad2;                    // 0x1A4AD2
extern int d_1a4ad4;                    // 0x1A4AD4
extern int d_1a4ad6;                    // 0x1A4AD6
extern int d_1a4ad8;                    // 0x1A4AD8
extern int d_1a4adc;                    // 0x1A4ADC
extern int d_1a4ade;                    // 0x1A4ADE
extern int d_1a4ae0;                    // 0x1A4AE0
extern int d_1a4ae2;                    // 0x1A4AE2
extern int d_1a4ae6;                    // 0x1A4AE6
extern int d_1a4ae8;                    // 0x1A4AE8
extern int d_1a4aea;                    // 0x1A4AEA
extern int d_1a4aec;                    // 0x1A4AEC
extern int d_1a4af0;                    // 0x1A4AF0
extern int d_1a4af2;                    // 0x1A4AF2
extern int d_1a4af4;                    // 0x1A4AF4
extern int d_1a4af6;                    // 0x1A4AF6
extern int d_1a4afa;                    // 0x1A4AFA
extern int d_1a4afc;                    // 0x1A4AFC
extern int d_1a4afe;                    // 0x1A4AFE
extern int d_1a4b00;                    // 0x1A4B00
extern int d_1a4b04;                    // 0x1A4B04
extern int d_1a4b06;                    // 0x1A4B06
extern int d_1a4b08;                    // 0x1A4B08
extern int d_1a4b0a;                    // 0x1A4B0A
extern int d_1a4b0e;                    // 0x1A4B0E
extern int d_1a4b10;                    // 0x1A4B10
extern int d_1a4b12;                    // 0x1A4B12
extern int d_1a4b14;                    // 0x1A4B14
extern int d_1a4b18;                    // 0x1A4B18
extern int d_1a4b1a;                    // 0x1A4B1A
extern int d_1a4b1c;                    // 0x1A4B1C
extern int d_1a4b1e;                    // 0x1A4B1E
extern int d_1a4b22;                    // 0x1A4B22
extern int d_1a4b24;                    // 0x1A4B24
extern int d_1a4b26;                    // 0x1A4B26
extern int d_1a4b28;                    // 0x1A4B28
extern int d_1a4b2c;                    // 0x1A4B2C
extern int d_1a4b2e;                    // 0x1A4B2E
extern int d_1a4b30;                    // 0x1A4B30
extern int d_1a4b32;                    // 0x1A4B32
extern int d_1a4b36;                    // 0x1A4B36
extern int d_1a4b38;                    // 0x1A4B38
extern int d_1a4b3a;                    // 0x1A4B3A
extern int d_1a4b3c;                    // 0x1A4B3C
extern int d_1a4c08;                    // 0x1A4C08
extern int d_1a4c0a;                    // 0x1A4C0A
extern int d_1a4c0c;                    // 0x1A4C0C
extern int d_1a4c0e;                    // 0x1A4C0E
extern int d_1a4c12;                    // 0x1A4C12
extern int d_1a4c14;                    // 0x1A4C14
extern int d_1a4c16;                    // 0x1A4C16
extern int d_1a4c18;                    // 0x1A4C18
extern int d_1a4c1c;                    // 0x1A4C1C
extern int d_1a4c1e;                    // 0x1A4C1E
extern int d_1a4c20;                    // 0x1A4C20
extern int d_1a4c22;                    // 0x1A4C22
extern int d_1a4c26;                    // 0x1A4C26
extern int d_1a4c28;                    // 0x1A4C28
extern int d_1a4c2a;                    // 0x1A4C2A
extern int d_1a4c2c;                    // 0x1A4C2C
extern int d_1a4c30;                    // 0x1A4C30
extern int d_1a4c32;                    // 0x1A4C32
extern int d_1a4c34;                    // 0x1A4C34
extern int d_1a4c36;                    // 0x1A4C36
extern int d_1a4c3a;                    // 0x1A4C3A
extern int d_1a4c3c;                    // 0x1A4C3C
extern int d_1a4c3e;                    // 0x1A4C3E
extern int d_1a4c40;                    // 0x1A4C40
extern int d_1a4c58;                    // 0x1A4C58
extern int d_1a4c5a;                    // 0x1A4C5A
extern int d_1a4c5c;                    // 0x1A4C5C
extern int d_1a4c5e;                    // 0x1A4C5E
extern int d_1a4c62;                    // 0x1A4C62
extern int d_1a4c64;                    // 0x1A4C64
extern int d_1a4c66;                    // 0x1A4C66
extern int d_1a4c68;                    // 0x1A4C68
extern int d_1a4c6c;                    // 0x1A4C6C
extern int d_1a4c6e;                    // 0x1A4C6E
extern int d_1a4c70;                    // 0x1A4C70
extern int d_1a4c72;                    // 0x1A4C72
extern short d_1a4c8a;                  // 0x1A4C8A
extern short d_1a4c8c;                  // 0x1A4C8C
extern short d_1a4c8e;                  // 0x1A4C8E
extern short d_1a4c90;                  // 0x1A4C90
extern int d_1a4d84;                    // 0x1A4D84
extern int d_1bc760;                    // 0x1BC760
extern int d_1be270;                    // 0x1BE270
extern int d_1be274;                    // 0x1BE274
extern int d_1be278;                    // 0x1BE278
extern int d_1be27c;                    // 0x1BE27C
extern int d_1be280;                    // 0x1BE280
extern int d_1be282;                    // 0x1BE282
extern int d_1bf4f0;                    // 0x1BF4F0
extern int d_1bf4f2;                    // 0x1BF4F2
extern int d_1bf510;                    // 0x1BF510
extern int d_1bf514;                    // 0x1BF514
extern int d_1bf51c;                    // 0x1BF51C
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c14c4;                    // 0x1C14C4
extern int d_1c2198;                    // 0x1C2198
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2a80;                    // 0x1C2A80
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a48d4[];           // Text 0x1A48D4

extern volatile short d_1be26c;
extern volatile short d_1be26e;
extern unsigned short d_1bd762;
extern short d_1bd766;
short f_050960(int);
short f_0208d0(int);
short f_01f620(int);
short f_01f490(int);
short f_01f480(int);
short f_11c320(int);
short f_11c620(int, int);
short f_11c5f0(int, int);
short f_020760(int, int);
short f_026a70(int, int);
int f_0bf820(int, ...);
int f_1254a0(int, int);
void f_0aa5b0(int, short);
void f_0aa690(int, short);
void f_0aa990(int, int);
void f_0aa430(int);
void f_0ab080(int, short);
void f_0ab6f0(int);
short f_0ab550(int, int);
void f_0ab320(int, short, short);
void f_0aa250(int, short);
short f_0a9630(int);
void f_0a9840(int, short *);
int f_0a9890(int);
void f_0a9960(int, short);
void f_0a9990(int);
int f_0a9a40(int);
void f_0a9b50(int);
void f_0a9be0(int);
void f_0a9c90(int);
void f_0a9d90(int, short, int);
void f_0a9e50(int, short);
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
#define SETD(p,a,b) d_1be26e = (U16(p,0x4c) == 0) ? (a) : (b); d_1be26c = d_1be26e;
#define REFRESH(p) { short rb = f_01f620(I32(p,0x24)); short rd = f_01f490(I32(p,0x24)); f_140390(I32(p,0x28), rd, rb); f_1404e0(I32(p,0x28)); }
#define B50(p) { if (d_1be26e != d_1be26c && d_1be26e >= 0x8e && d_1be26e <= 0xc0) { if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1); f_0a9d90(p, d_1be26e, 0); f_0a9c90(p); d_1be26c = d_1be26e; } }
#define BE0(p) { d_1be26e = d_1be26c; d_1be26c = 0; B50(p) }
#define A840(p,v) { if ((v) == 0) (v) = d_1bd766; else f_0d3810(); if (f_0d37b0() != 0) (v) = 0xc5; }

struct S_4 { char b[4]; };
//@ f_0a9080
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wertet einen Eingabeschritt (Tastatur- oder Maus-Hotspot-Code) im
 *   Gegenstandsverteilungs-Fenster aus und verzweigt in die jeweilige Aktion: Heldenauswahl (0x87-0x8d), Klick
 *   auf Heldeninventar-Slot (0x8e-0xac), Klick auf Pool-Gegenstand (0xad-0xc0), Ablegen eines aufgenommenen
 *   Gegenstands in den Pool (0xc1), Filter- und Aktionsschaltflächen (0x80-0x85), Scrollbalken (0xc2-0xc4),
 *   Enter-Bestätigung (0xc6), Tab-Fokuswechsel (0xc7), Beenden (0x86), Heldentausch (0xc8) oder
 *   Pfeiltasten-Navigation (0xc9-0xce).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt 0 zurück, solange das Verteilungsfenster offen bleibt, oder 1, wenn der
 *   Spieler das Fenster über die Schließen-Aktion (0x86) erfolgreich beendet.
 === Ende Beschreibung === */
int f_0a9080(int p)
{
    struct Action904 {
      static inline void input(short &v,int initial) {
        if(initial==0)v=d_1bd766;else f_0d3810();
        if(f_0d37b0()!=0)v=0xc5;
      }
      static inline void refresh(int p) {
        int rb=f_01f620(I32(p,0x24)); int rd=f_01f490(I32(p,0x24));
        f_140390(I32(p,0x28),rd,rb); f_1404e0(I32(p,0x28));
      }
      static inline void row(int p,short selected) {
        selected=(selected&0)?0:selected; // haelt die Registerzuteilung wie im Original
        for(short i=0;i<7;++i){
          int q=p; q+=i*4;
          f_027830(I32(q,8),(short)selected);f_027690(I32(q,8));
        }
      }
      static inline void page(int p,short value) {
        f_01fb40(I32(p,0x24),value);
        if(S16(p,0x4c)==(short)1)f_020640(I32(p,0x24),S16(p,0x50),0xfd);
      }
      static inline void pageRefresh(int p) {
        page(p,0); refresh(p);
      }
      static inline void pages(int p,unsigned short key) {
        int q=p;
        switch ((unsigned short)key) {
        case 0xc2: {
            f_01f6f0(I32(p,0x24));
            Action904::page(p,0); Action904::refresh(q);
            break;
        }
        case 0xc3:
            f_0ab6f0(p);
            break;
        case 0xc4: {
            f_01f7d0(I32(p,0x24));
            Action904::page(p,0); Action904::refresh(q);
            break;
        }
        default:
            break;
        }
      }
      static inline short count(int p) {
        short result=0;
        for(short i=0;i<7;++i)if(f_027070(I32(p+i*4,8)))++result;
        return result;
      }
    };
    short key = f_0a9630(p);
    int initial=key;
    volatile int result = 0; // haelt den Rueckgabewert im Stapel wie im Original
    Action904::input(key,initial);
    if (key == 0xc5) key = f_0a9890(p);

    if (key >= 0x87 && key <= 0x8d) {
        f_0ab080(p, (short)(key - 0x87));
    } else if (key >= 0x8e && key <= 0xac) {
        f_0aa5b0(p, (short)(key - 0x8e));
        return result;
    } else if (key >= 0xad && key <= 0xc0) {
        f_0aa690(p, (short)(key - 0xad));
        return result;
    } else if (key == 0xc1) {
        int base = p;
        if ((int)(short)f_050960(I32(base,0x2c))) {
            f_050b40(I32(base,0x2c), -1);
            f_051060(I32(base,0x2c));
            Action904::row(base,f_050960(I32(base,0x2c)));
            short page = (short)(f_0208d0(I32(base,0x24)) - 1);
            if (page >= 0 && page < 20) f_01fef0(I32(base,0x24), page);
            Action904::refresh(base);
        }
        f_0a9be0(base);
    } else if (key >= 0x80 && key <= 0x85) {
        f_0aa990(p, key);
        return result;
    } else if (key >= 0xc2 && key <= 0xc4) {
        Action904::pages(p,key);
        return result;
    } else if (key == 0xc6) {
        if (S16(p,0x4c) == (short)0) f_0aa5b0(p, S16(p,0x50));
        else f_0aa690(p, S16(p,0x50));
        return result;
    } else if (key == 0xc7) {
        f_0a9990(p);
        return result;
    } else if (key == 0x86) {
        f_0aa990(p, key);
        if ((int)(short)f_050960(I32(p,0x2c))) f_0aa430(p);
        else result = f_0a9a40(p);
        return result;
    } else if (key == 0xc8) {
        int base = p;
        short count=Action904::count(base);
        short second = -1;
        short first;
        if (count > 1) {
            if (count == 2) {
                second = 1;
                first = 0;
            } else {
                first = f_0ab550(base, 0x20000038);
                if (first != -1) second = f_0ab550(base, 0x20000039);
            }
            if (first != -1 && second != -1) f_0ab320(base, first, second);
        }
        f_0a9be0(base);
    } else if (key >= 0xc9 && key <= 0xce) {
        f_0a9960(p,key);
    }
    return result;
}

//@ f_0a9630
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Übersetzt den zuletzt gedrückten Tastatur-Scancode (d_1bd762) in den internen Aktionscode
 *   des Gegenstandsverteilungs-Fensters (z. B. Zifferntasten 1-7 auf 0x87-0x8d samt Setzen des Tauschflags bei
 *   Offset +0x56, Pfeiltasten/Pos1/Ende auf 0xc9-0xce, Einfg auf 0xc1, Bild-auf/ab auf 0xc5, Enter auf 0xc6, Tab
 *   auf 0xc7, Strg+O auf 0xc8, Esc auf 0x86).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt den internen Aktionscode (short) oder 0 zurück, falls keine relevante Taste
 *   gedrückt wurde.
 === Ende Beschreibung === */
short f_0a9630(int p)
{
    short key = d_1bd762;
    int r = 0;
    switch ((short)key) {
    case 0: break;
    case 0x4900: r = 0xc5; break;
    case 0x1c0d: r = 0xc6; break;
    case 0xf09: r = 0xc7; break;
    case 0x11b: r = 0x86; break;
    case 0x231: r = 0x87; I32(p,0x56) = 1; break;
    case 0x332: r = 0x88; I32(p,0x56) = 1; break;
    case 0x433: r = 0x89; I32(p,0x56) = 1; break;
    case 0x534: r = 0x8a; I32(p,0x56) = 1; break;
    case 0x635: r = 0x8b; I32(p,0x56) = 1; break;
    case 0x736: r = 0x8c; I32(p,0x56) = 1; break;
    case 0x837: r = 0x8d; I32(p,0x56) = 1; break;
    case 0x4800: r = 0xca; break;
    case 0x5000: r = 0xcb; break;
    case 0x4b00: r = 0xcc; break;
    case 0x4d00: r = 0xcd; break;
    case 0x5200: r = 0xc1; break;
    case 0x4700: r = 0xc9; break;
    case 0x4f00: r = 0xce; break;
    case 0x180f: r = 0xc8; break;
    }
    return r;
}

//@ f_0a9840
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Ergänzt einen noch leeren Eingabecode um den aktuellen Maus-Hotspot-Code (d_1bd766) bzw.
 *   quittiert einen Mausklick (f_0d3810) und setzt bei einem Rechtsklick (f_0d37b0) den Code 0xc5 zum Öffnen des
 *   Kontextmenüs.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie ein Zeiger auf den zu
 *   aktualisierenden Aktionscode (short *).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9840(int p1, short *p2)
{
    if (*p2 == 0) *p2 = d_1bd766; else f_0d3810();
    if (f_0d37b0() != 0) *p2 = 0xc5;
}

//@ f_0a9890
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Öffnet bei einem Rechtsklick ein Auswahlmenü (f_0bf820 mit den Texten 0x21040005 bis
 *   0x2104000c) für die sieben Filter- und Verteilungsaktionen und wandelt die getroffene Wahl (1-7) in den
 *   entsprechenden Schaltflächencode (0x80-0x86) um.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt den gewählten Schaltflächencode (0x80-0x86) oder 0 bei Abbruch zurück.
 === Ende Beschreibung === */
int f_0a9890(int p)
{
    int obj[15];
    int r = 0;
    f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
    f_0d2f90(0, 1);
    {
        int sv = f_0bf820((int)&d_1c2c64, 0x21040005, 7, 0x21040006, 0x21040007, 0x21040008, 0x21040009, 0x2104000b, 0x2104000a, 0x2104000c);
        switch ((unsigned short)(sv - 1)) {
    case 0: r = 0x80; break;
    case 1: r = 0x81; break;
    case 2: r = 0x82; break;
    case 3: r = 0x83; break;
    case 4: r = 0x84; break;
    case 5: r = 0x85; break;
    case 6: r = 0x86;
    }
    }
    f_051060(I32(p,0x2c));
    f_1254a0((int)obj, 0);
    return r;
}

//@ f_0a9960
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verarbeitet die Pfeiltasten-Navigation (0xc9-0xce) je nach aktivem Fokusbereich (Offset
 *   +0x4c): Sie steuert bei aktivem Beutepool (1) das Gegenstandsgitter über f_0a9e50 und bei aktivem
 *   Heldeninventar (0) die Ausrüstungs- und Rucksack-Slots über f_0aa250, gefolgt von einer Aktualisierung der
 *   Gegenstandsbeschriftung (f_0a9c90).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Richtungscode
 *   (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9960(int p, short v)
{
    if (S16(p,0x4c) == (short)1) f_0a9e50(p, v); else f_0aa250(p, v);
    f_0a9c90(p);
}

//@ f_0a9990
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Schaltet den Eingabefokus (Offset +0x4c) zwischen dem Inventar des ausgewählten Helden (0)
 *   und dem Beutepool-Gitter (1) um, tauscht dabei den aktuellen Slot-Index (+0x50) mit dem gemerkten Index des
 *   jeweils anderen Bereichs (+0x4e), hebt die alte Markierung auf, zeichnet den neuen Auswahlrahmen und
 *   aktualisiert Hotspot-Kennung sowie Detailanzeige.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9990(int p)
{
    short t = S16(p,0x50);
    S16(p,0x50) = S16(p,0x4e);
    S16(p,0x4e) = t;
    if (S16(p,0x4c) == (short)0) {
        f_0266e0(f_027080(I32(p,8)), S16(p,0x4e));
        U16(p,0x4c) = 1;
        f_020640(I32(p,0x24), S16(p,0x50), 0xfd);
    } else {
        f_01fef0(I32(p,0x24), S16(p,0x4e));
        U16(p,0x4c) = 0;
        f_026570(f_027080(I32(p,8)), S16(p,0x50), 3);
    }
    if (S16(p,0x4c) == (short)0)
        d_1be26e = U16(p,0x50) + 0x8e;
    else
        d_1be26e = U16(p,0x50) + 0xad;
    d_1be26c = d_1be26e;
    f_0a9c90(p);
}

//@ f_0a9a40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft beim Schließen des Gegenstandsverteilungs-Fensters zunächst, ob sich im Pool noch ein
 *   handlungsrelevanter Pflichtgegenstand befindet (f_0a78f0), der nicht zurückgelassen werden darf (Meldung
 *   0x2104000f), und fragt andernfalls - sofern das Fenster im Beutemodus (Offset +0x04 == 0) noch restliche
 *   Gegenstände enthält - per Bestätigungsdialog (0x2104000d), ob die übrigen Gegenstände wirklich
 *   zurückgelassen werden sollen.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn das Verteilungsfenster geschlossen werden darf, oder 0, wenn
 *   das Schließen verweigert oder abgebrochen wurde.
 === Ende Beschreibung === */
int f_0a9a40(int p)
{
    int obj[15];
    int off;
    int r = 1;
    short i = 0;
    short n;
    do {
        n = f_11c320(I32(p,0));
        if ((short)(i & 0xffff) >= n) break;
        off = f_11c620(I32(p,0), i) * 4;
        if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a78f0() == 1) {
            f_125400((int)obj, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
            r = 0;
            *(int *)(obj[1] + 4) = f_039660(d_1c0004, 5);
            *(int *)(obj[3] + 4) = *(int *)(((int)d_1c2c40) + off);
            *(short *)(obj[8] + 2) = f_11c5f0(I32(p,0), i);
            f_0bf730((int)&d_1c2c64, 0x2104000f);
            f_1254a0((int)obj, 0);
        }
        i++;
    } while (r == 1);
    if (r == 1 && I32(p,4) == 0) {
        n = f_11c320(I32(p,0));
        if (n > 0) {
            if (f_0bf6f0((int)&d_1c2c64, 0x2104000d) != 1) r = 0;
        }
    }
    return r;
}

//@ f_0a9b50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert bei einer Änderung des ausgewählten Slots (d_1be26e gegenüber d_1be26c im
 *   Bereich 0x8e bis 0xc0) die Hervorhebung des alten und neuen Slots (f_0a9d90) sowie die
 *   Gegenstands-Detailanzeige (f_0a9c90).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9b50(int p)
{
    B50(p)
}

//@ f_0a9be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzwingt eine vollständige Neuzeichnung der aktuellen Slot-Markierung und der
 *   Gegenstands-Detailanzeige, indem die alte Hotspot-Kennung (d_1be26c) zurückgesetzt und anschließend die
 *   Markierungslogik (f_0a9d90, f_0a9c90) ausgeführt wird.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9be0(int p)
{
    d_1be26e = d_1be26c;
    d_1be26c = 0;
    int q = p;
    B50(q)
}

//@ f_0a9c90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert die Gegenstands-Detailanzeige (Offset +0x2c) und die Tragfähigkeits- sowie
 *   Klasseneignungs-Markierungen aller sieben Heldenleisten (f_027830, f_027690) anhand des Gegenstands im
 *   aktuell fokussierten Inventar- oder Pool-Slot (d_1be26e), sofern derzeit kein Gegenstand am Cursor hängt
 *   (f_050960 == 0).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9c90(int p)
{
    int p2 = 0;
    short sVar2 = 0;
    short k;
    int qbase;
    if (f_050960(I32(p, 0x2c)) == 0) {
        if (d_1be26e >= 0x8e && d_1be26e <= 0xac) {
            short t = d_1be26e - 0x8e;
            sVar2 = f_026a70(f_027080(I32(p, 8)), t);
        } else if (d_1be26e >= 0xad && d_1be26e <= 0xc0) {
            short t = d_1be26e - 0xad;
            if (t < f_0208d0(I32(p, 0x24)))
                sVar2 = f_11c620(I32(p, 0), f_020760(I32(p, 0x24), t));
        }
        if (sVar2 > 0) {
            p2 = ((int)d_1c2c40);
            p2 = ((int *)p2)[(int)sVar2];
        }
        f_050ea0(I32(p, 0x2c), p2);
        qbase = p;
        for (k = 0; k < 7; k++) {
            int q = qbase + k * 4;
            f_027830(I32(q, 8), (short)sVar2);
            f_027690(I32(q, 8));
        }
    }
}

//@ f_0a9d90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt oder löscht die optische Auswahlmarkierung für einen einzelnen Slot im Heldeninventar
 *   (0x8e-0xac, über f_026570/f_0266e0) oder im Beutepool-Gitter (0xad-0xc0, über f_020640/f_01fef0) und
 *   speichert bei einem Bereichswechsel den bisherigen Slot-Index im Merkerfeld (Offset +0x4e).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this), die Hotspot-Kennung des
 *   Slots (short) sowie ein Modusflag (0 = markieren, 1 = Markierung aufheben).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9d90(int p, short a, int c)
{
    unsigned short t;
    if (a >= 0x8e && a <= 0xac) {
        a -= 0x8e;
        t = 0;
    } else {
        t = 1;
        a -= 0xad;
    }
    do {
    if (t != U16(p,0x4c)) {
        U16(p,0x4c) = t;
        S16(p,0x4e) = S16(p,0x50);
    }
    } while (0);
    S16(p,0x50) = a;
    if (t == (unsigned short)0) {
        if (c == 0) f_026570(f_027080(I32(p,8)), a, 3);
        else f_0266e0(f_027080(I32(p,8)), a);
    } else {
        if (c == 0) f_020640(I32(p,0x24), a, 0xfd);
        else f_01fef0(I32(p,0x24), a);
    }
}

//@ f_0a9e50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bewegt die Auswahlmarkierung innerhalb des 5x4-Gegenstandsgitters des Beutepools anhand
 *   einer Navigationstaste (0xc9-0xce: Pos1, Auf, Ab, Links, Rechts, Ende), scrollt das Gitter (f_01f6f0,
 *   f_01f7d0, f_01fa70, f_01fa80) sowie den Scrollbalken bei Überschreiten des sichtbaren Bereichs nach und
 *   zeichnet den Auswahlrahmen neu.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Tastencode (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9e50(int p, short key)
{
    struct Object1106 {
        char pad0[0x24]; int child; int view;
        char pad2c[0x20]; short flag; short pad4e; short index;
        inline void page() {
            f_01fb40(child, 0);
            if (flag == (short)1) f_020640(child, index, 0xfd);
        }
    };
    struct Ui {
        static inline void set(int q, short index) {
            *(short *)(q + 0x50) = index;
            if (!*(short *)(q + 0x4c))
                d_1be26e = *(short *)(q + 0x50) + 0x8e;
            else
                d_1be26e = *(short *)(q + 0x50) + 0xad;
            d_1be26c = d_1be26e;
        }
        static inline void set0(int q, short index) {
            short flag = 0;
            flag = *(short *)(q + 0x4c);
            *(short *)(q + 0x50) = index;
            if (!flag)
                d_1be26e = *(short *)(q + 0x50) + 0x8e;
            else
                d_1be26e = *(short *)(q + 0x50) + 0xad;
            d_1be26c = d_1be26e;
        }
        static inline void set1(int q, short index) {
            int base = q;
            *(short *)(base + 0x50) = index;
            if (!*(short *)(base + 0x4c))
                d_1be26e = *(short *)(base + 0x50) + 0x8e;
            else
                d_1be26e = *(short *)(base + 0x50) + 0xad;
            d_1be26c = d_1be26e;
        }
        static inline void refresh(int q) {
            int rb = f_01f620(*(int *)(q + 0x24));
            int rd = f_01f490(*(int *)(q + 0x24));
            f_140390(*(int *)(q + 0x28), rd, rb);
            f_1404e0(*(int *)(q + 0x28));
        }
    };
    short k = key;
    short next, old = f_01f480(*(int *)(p + 0x24));
    short saved = old;
    k = (short)(k - 0xc9);
    f_01fef0(*(int *)(p + 0x24), *(short *)(p + 0x50));
    switch ((unsigned short)k) {
    case 0:
        Ui::set0(p, (short)0);
        f_01fa70(*(int *)(p + 0x24));
        if (f_01f480(*(int *)(p + 0x24)) != saved) {
            f_01fb40(*(int *)(p + 0x24), 0);
            if (*(short *)(p + 0x4c) == (short)1)
                f_020640(*(int *)(p + 0x24), *(short *)(p + 0x50), 0xfd);
            Ui::refresh(p);
        }
        break;
    case 1:
        next = *(short *)(p + 0x50) - 5;
        if ((int)next >= 0) {
            Ui::set1(p, next);
        }
        else {
            f_01f6f0(*(int *)(p + 0x24));
            if (f_01f480(*(int *)(p + 0x24)) != old) {
                ((Object1106 *)p)->page();
                Ui::refresh(p);
            }
        }
        break;
    case 2:
        next = *(short *)(p + 0x50) + 5;
        if (next <= (short)0x13)
            Ui::set(p, next);
        else {
            f_01f7d0(*(int *)(p + 0x24));
            if (f_01f480(*(int *)(p + 0x24)) != old) {
                f_01fb40(*(int *)(p + 0x24), 0);
                if (*(short *)(p + 0x4c) == (short)1)
                    f_020640(*(int *)(p + 0x24), *(short *)(p + 0x50), 0xfd);
                Ui::refresh(p);
            }
        }
        break;
    case 3:
        if (*(short *)(p + 0x50) % 5 > 0)
            Ui::set(p, (short)(*(short *)(p + 0x50) - 1));
        else
            Ui::set(p, (short)(*(short *)(p + 0x50) + 4));
        break;
    case 4:
        if (*(short *)(p + 0x50) % 5 < 4)
            Ui::set(p, (short)(*(short *)(p + 0x50) + 1));
        else
            Ui::set(p, (short)(*(short *)(p + 0x50) - 4));
        break;
    case 5:
        Ui::set(p, (short)0x13);
        f_01fa80(*(int *)(p + 0x24));
        if (f_01f480(*(int *)(p + 0x24)) != saved) {
            f_01fb40(*(int *)(p + 0x24), 0);
            if (*(short *)(p + 0x4c) == (short)1)
                f_020640(*(int *)(p + 0x24), *(short *)(p + 0x50), 0xfd);
            Ui::refresh(p);
        }
        break;
    }
    f_020640(*(int *)(p + 0x24), *(short *)(p + 0x50), 0xfd);
}
