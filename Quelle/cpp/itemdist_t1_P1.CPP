/* === Beschreibung (Katalog) ===
 * Einheit itemdist_t1 (0x0A7D50 - 0x0A9080)
 *
 * Diese Einheit bildet den ersten Teil des Fensters zur Gegenstandsverteilung (p:\riva\source\cpp\itemdist.cpp),
 * mit dem Beute- oder Pool-Gegenstände nach Kämpfen oder aus Lagern auf die bis zu sieben Gruppenmitglieder
 * verteilt werden.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 8/9 gleich (suche.py 29.10.2026, Basis itemdist_t1_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 4 gleich (vorher 3), Rest 147 (vorher 161)
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
int f_01f480(int p1);                                   // reg eax stapel 0
int f_01f490(int p1);                                   // reg eax stapel 0
int f_01f560(int p1, int p2);                           // reg eax edx stapel 0
int f_01f620(int p1);                                   // reg eax stapel 0
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
int f_020760(int p1, int p2);                           // reg eax edx stapel 0
int f_0208d0(int p1);                                   // reg eax stapel 0
int f_025c50(int p1, int p2);                           // reg eax edx stapel 0
int f_025d90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0264d0(int p1, int p2);                           // reg eax edx stapel 0
int f_026570(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0266e0(int p1, int p2);                           // reg eax edx stapel 0
int f_026a20(int p1, int p2);                           // reg eax edx stapel 0
int f_026a70(int p1, int p2);                           // reg eax edx stapel 0
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
int f_050860(int p1, int p2, int p3, int p4);
int f_0508f0(int p1, int p2);                           // reg eax stapel 0
int f_050920(int p1);                                   // reg eax stapel 0
int f_050930(int p1);                                   // reg eax stapel 0
int f_050940(int p1);                                   // reg eax stapel 0
int f_050960(int p1);                                   // reg eax stapel 0
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
int f_0bf820();                                         // reg - stapel 0
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
int f_11c320(int p1);                                   // reg eax stapel 0
int f_11c330(int p1, int p2);                           // reg eax edx stapel 0
int f_11c350(int p1, int p2);                           // reg eax edx stapel 0
int f_11c580(int p1, int p2);                           // reg eax edx stapel 0
int f_11c5f0(int p1, int p2);                           // reg eax edx stapel 0
int f_11c620(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_13fc70(int p1);                                   // reg eax stapel 0
int f_13fcd0(int p1, int p2);                           // reg eax edx stapel 0
int f_140220(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
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
extern short d_1a48f4;                    // 0x1A48F4
extern short d_1a48f6;                    // 0x1A48F6
extern short d_1a48f8;                    // 0x1A48F8
extern short d_1a48fa;                    // 0x1A48FA
extern short d_1a48fc;                    // 0x1A48FC
extern short d_1a48fe;                    // 0x1A48FE
extern short d_1a4900;                    // 0x1A4900
extern short d_1a4902;                    // 0x1A4902
extern short d_1a4904;                    // 0x1A4904
extern short d_1a4906;                    // 0x1A4906
extern short d_1a4908;                    // 0x1A4908
extern short d_1a490a;                    // 0x1A490A
extern short d_1a490c;                    // 0x1A490C
extern short d_1a490e;                    // 0x1A490E
extern short d_1a4910;                    // 0x1A4910
extern short d_1a4912;                    // 0x1A4912
extern short d_1a4914;                    // 0x1A4914
extern short d_1a4916;                    // 0x1A4916
extern short d_1a4918;                    // 0x1A4918
extern short d_1a491a;                    // 0x1A491A
extern short d_1a491c;                    // 0x1A491C
extern short d_1a491e;                    // 0x1A491E
extern short d_1a4920;                    // 0x1A4920
extern short d_1a4922;                    // 0x1A4922
extern short d_1a4924;                    // 0x1A4924
extern short d_1a4926;                    // 0x1A4926
extern short d_1a4928;                    // 0x1A4928
extern short d_1a492a;                    // 0x1A492A
extern short d_1a492c;                    // 0x1A492C
extern short d_1a492e;                    // 0x1A492E
extern short d_1a4930;                    // 0x1A4930
extern short d_1a4932;                    // 0x1A4932
extern short d_1a4934;                    // 0x1A4934
extern short d_1a4936;                    // 0x1A4936
extern short d_1a4938;                    // 0x1A4938
extern short d_1a493a;                    // 0x1A493A
extern short d_1a493c;                    // 0x1A493C
extern short d_1a493e;                    // 0x1A493E
extern short d_1a4940;                    // 0x1A4940
extern short d_1a4942;                    // 0x1A4942
extern short d_1a4944;                    // 0x1A4944
extern short d_1a4946;                    // 0x1A4946
extern short d_1a4948;                    // 0x1A4948
extern short d_1a494a;                    // 0x1A494A
extern short d_1a494c;                    // 0x1A494C
extern short d_1a494e;                    // 0x1A494E
extern short d_1a4950;                    // 0x1A4950
extern short d_1a4952;                    // 0x1A4952
extern short d_1a4954;                    // 0x1A4954
extern short d_1a4956;                    // 0x1A4956
extern short d_1a4958;                    // 0x1A4958
extern short d_1a495a;                    // 0x1A495A
extern short d_1a495c;                    // 0x1A495C
extern short d_1a495e;                    // 0x1A495E
extern short d_1a4960;                    // 0x1A4960
extern short d_1a4962;                    // 0x1A4962
extern short d_1a4964;                    // 0x1A4964
extern short d_1a4966;                    // 0x1A4966
extern short d_1a4968;                    // 0x1A4968
extern short d_1a496a;                    // 0x1A496A
extern short d_1a496c;                    // 0x1A496C
extern short d_1a496e;                    // 0x1A496E
extern short d_1a4970;                    // 0x1A4970
extern short d_1a4972;                    // 0x1A4972
extern short d_1a4974;                    // 0x1A4974
extern short d_1a4976;                    // 0x1A4976
extern short d_1a4978;                    // 0x1A4978
extern short d_1a497a;                    // 0x1A497A
extern short d_1a497c;                    // 0x1A497C
extern short d_1a497e;                    // 0x1A497E
extern short d_1a4980;                    // 0x1A4980
extern short d_1a4982;                    // 0x1A4982
extern short d_1a4984;                    // 0x1A4984
extern short d_1a4986;                    // 0x1A4986
extern short d_1a4988;                    // 0x1A4988
extern short d_1a498a;                    // 0x1A498A
extern short d_1a498c;                    // 0x1A498C
extern short d_1a498e;                    // 0x1A498E
extern short d_1a4990;                    // 0x1A4990
extern short d_1a4992;                    // 0x1A4992
extern short d_1a4994;                    // 0x1A4994
extern short d_1a4996;                    // 0x1A4996
extern short d_1a4998;                    // 0x1A4998
extern short d_1a499a;                    // 0x1A499A
extern short d_1a499c;                    // 0x1A499C
extern short d_1a499e;                    // 0x1A499E
extern short d_1a49a0;                    // 0x1A49A0
extern short d_1a49a2;                    // 0x1A49A2
extern short d_1a49a4;                    // 0x1A49A4
extern short d_1a49a6;                    // 0x1A49A6
extern short d_1a49b0;                    // 0x1A49B0
extern short d_1a49b2;                    // 0x1A49B2
extern short d_1a49b4;                    // 0x1A49B4
extern short d_1a49b6;                    // 0x1A49B6
extern short d_1a49b8;                    // 0x1A49B8
extern short d_1a49ba;                    // 0x1A49BA
extern short d_1a49bc;                    // 0x1A49BC
extern short d_1a49be;                    // 0x1A49BE
extern int d_1a49c0;                    // 0x1A49C0
extern short d_1a49c2;                    // 0x1A49C2
extern short d_1a49c4;                    // 0x1A49C4
extern short d_1a49c6;                    // 0x1A49C6
extern short d_1a49c8;                    // 0x1A49C8
extern short d_1a49ca;                    // 0x1A49CA
extern short d_1a49ce;                    // 0x1A49CE
extern short d_1a49d0;                    // 0x1A49D0
extern short d_1a49d2;                    // 0x1A49D2
extern short d_1a49d4;                    // 0x1A49D4
extern short d_1a49d8;                    // 0x1A49D8
extern short d_1a49da;                    // 0x1A49DA
extern short d_1a49dc;                    // 0x1A49DC
extern short d_1a49de;                    // 0x1A49DE
extern short d_1a49e2;                    // 0x1A49E2
extern short d_1a49e4;                    // 0x1A49E4
extern short d_1a49e6;                    // 0x1A49E6
extern short d_1a49e8;                    // 0x1A49E8
extern short d_1a49ec;                    // 0x1A49EC
extern short d_1a49ee;                    // 0x1A49EE
extern short d_1a49f0;                    // 0x1A49F0
extern short d_1a49f2;                    // 0x1A49F2
extern short d_1a49f6;                    // 0x1A49F6
extern short d_1a49f8;                    // 0x1A49F8
extern short d_1a49fa;                    // 0x1A49FA
extern short d_1a49fc;                    // 0x1A49FC
extern short d_1a4a00;                    // 0x1A4A00
extern short d_1a4a02;                    // 0x1A4A02
extern short d_1a4a04;                    // 0x1A4A04
extern short d_1a4a06;                    // 0x1A4A06
extern short d_1a4a0a;                    // 0x1A4A0A
extern short d_1a4a0c;                    // 0x1A4A0C
extern short d_1a4a0e;                    // 0x1A4A0E
extern short d_1a4a10;                    // 0x1A4A10
extern short d_1a4a14;                    // 0x1A4A14
extern short d_1a4a16;                    // 0x1A4A16
extern short d_1a4a18;                    // 0x1A4A18
extern short d_1a4a1a;                    // 0x1A4A1A
extern short d_1a4a1e;                    // 0x1A4A1E
extern short d_1a4a20;                    // 0x1A4A20
extern short d_1a4a22;                    // 0x1A4A22
extern short d_1a4a24;                    // 0x1A4A24
extern short d_1a4a28;                    // 0x1A4A28
extern short d_1a4a2a;                    // 0x1A4A2A
extern short d_1a4a2c;                    // 0x1A4A2C
extern short d_1a4a2e;                    // 0x1A4A2E
extern short d_1a4a32;                    // 0x1A4A32
extern short d_1a4a34;                    // 0x1A4A34
extern short d_1a4a36;                    // 0x1A4A36
extern short d_1a4a38;                    // 0x1A4A38
extern short d_1a4a3c;                    // 0x1A4A3C
extern short d_1a4a3e;                    // 0x1A4A3E
extern short d_1a4a40;                    // 0x1A4A40
extern short d_1a4a42;                    // 0x1A4A42
extern short d_1a4a46;                    // 0x1A4A46
extern short d_1a4a48;                    // 0x1A4A48
extern short d_1a4a4a;                    // 0x1A4A4A
extern short d_1a4a4c;                    // 0x1A4A4C
extern short d_1a4a50;                    // 0x1A4A50
extern short d_1a4a52;                    // 0x1A4A52
extern short d_1a4a54;                    // 0x1A4A54
extern short d_1a4a56;                    // 0x1A4A56
extern short d_1a4a5a;                    // 0x1A4A5A
extern short d_1a4a5c;                    // 0x1A4A5C
extern short d_1a4a5e;                    // 0x1A4A5E
extern short d_1a4a60;                    // 0x1A4A60
extern short d_1a4a64;                    // 0x1A4A64
extern short d_1a4a66;                    // 0x1A4A66
extern short d_1a4a68;                    // 0x1A4A68
extern short d_1a4a6a;                    // 0x1A4A6A
extern short d_1a4a6e;                    // 0x1A4A6E
extern short d_1a4a70;                    // 0x1A4A70
extern short d_1a4a72;                    // 0x1A4A72
extern short d_1a4a74;                    // 0x1A4A74
extern short d_1a4a78;                    // 0x1A4A78
extern short d_1a4a7a;                    // 0x1A4A7A
extern short d_1a4a7c;                    // 0x1A4A7C
extern short d_1a4a7e;                    // 0x1A4A7E
extern short d_1a4a82;                    // 0x1A4A82
extern short d_1a4a84;                    // 0x1A4A84
extern short d_1a4a86;                    // 0x1A4A86
extern short d_1a4a88;                    // 0x1A4A88
extern short d_1a4a8c;                    // 0x1A4A8C
extern short d_1a4a8e;                    // 0x1A4A8E
extern short d_1a4a90;                    // 0x1A4A90
extern short d_1a4a92;                    // 0x1A4A92
extern short d_1a4a96;                    // 0x1A4A96
extern short d_1a4a98;                    // 0x1A4A98
extern short d_1a4a9a;                    // 0x1A4A9A
extern short d_1a4a9c;                    // 0x1A4A9C
extern short d_1a4aa0;                    // 0x1A4AA0
extern short d_1a4aa2;                    // 0x1A4AA2
extern short d_1a4aa4;                    // 0x1A4AA4
extern short d_1a4aa6;                    // 0x1A4AA6
extern short d_1a4aaa;                    // 0x1A4AAA
extern short d_1a4aac;                    // 0x1A4AAC
extern short d_1a4aae;                    // 0x1A4AAE
extern short d_1a4ab0;                    // 0x1A4AB0
extern short d_1a4ab4;                    // 0x1A4AB4
extern short d_1a4ab6;                    // 0x1A4AB6
extern short d_1a4ab8;                    // 0x1A4AB8
extern short d_1a4aba;                    // 0x1A4ABA
extern short d_1a4abe;                    // 0x1A4ABE
extern short d_1a4ac0;                    // 0x1A4AC0
extern short d_1a4ac2;                    // 0x1A4AC2
extern short d_1a4ac4;                    // 0x1A4AC4
extern short d_1a4ac8;                    // 0x1A4AC8
extern short d_1a4aca;                    // 0x1A4ACA
extern short d_1a4acc;                    // 0x1A4ACC
extern short d_1a4ace;                    // 0x1A4ACE
extern short d_1a4ad2;                    // 0x1A4AD2
extern short d_1a4ad4;                    // 0x1A4AD4
extern short d_1a4ad6;                    // 0x1A4AD6
extern short d_1a4ad8;                    // 0x1A4AD8
extern short d_1a4adc;                    // 0x1A4ADC
extern short d_1a4ade;                    // 0x1A4ADE
extern short d_1a4ae0;                    // 0x1A4AE0
extern short d_1a4ae2;                    // 0x1A4AE2
extern short d_1a4ae6;                    // 0x1A4AE6
extern short d_1a4ae8;                    // 0x1A4AE8
extern short d_1a4aea;                    // 0x1A4AEA
extern short d_1a4aec;                    // 0x1A4AEC
extern short d_1a4af0;                    // 0x1A4AF0
extern short d_1a4af2;                    // 0x1A4AF2
extern short d_1a4af4;                    // 0x1A4AF4
extern short d_1a4af6;                    // 0x1A4AF6
extern short d_1a4afa;                    // 0x1A4AFA
extern short d_1a4afc;                    // 0x1A4AFC
extern short d_1a4afe;                    // 0x1A4AFE
extern short d_1a4b00;                    // 0x1A4B00
extern short d_1a4b04;                    // 0x1A4B04
extern short d_1a4b06;                    // 0x1A4B06
extern short d_1a4b08;                    // 0x1A4B08
extern short d_1a4b0a;                    // 0x1A4B0A
extern short d_1a4b0e;                    // 0x1A4B0E
extern short d_1a4b10;                    // 0x1A4B10
extern short d_1a4b12;                    // 0x1A4B12
extern short d_1a4b14;                    // 0x1A4B14
extern short d_1a4b18;                    // 0x1A4B18
extern short d_1a4b1a;                    // 0x1A4B1A
extern short d_1a4b1c;                    // 0x1A4B1C
extern short d_1a4b1e;                    // 0x1A4B1E
extern short d_1a4b22;                    // 0x1A4B22
extern short d_1a4b24;                    // 0x1A4B24
extern short d_1a4b26;                    // 0x1A4B26
extern short d_1a4b28;                    // 0x1A4B28
extern short d_1a4b2c;                    // 0x1A4B2C
extern short d_1a4b2e;                    // 0x1A4B2E
extern short d_1a4b30;                    // 0x1A4B30
extern short d_1a4b32;                    // 0x1A4B32
extern short d_1a4b36;                    // 0x1A4B36
extern short d_1a4b38;                    // 0x1A4B38
extern short d_1a4b3a;                    // 0x1A4B3A
extern short d_1a4b3c;                    // 0x1A4B3C
extern short d_1a4c08;                    // 0x1A4C08
extern short d_1a4c0a;                    // 0x1A4C0A
extern short d_1a4c0c;                    // 0x1A4C0C
extern short d_1a4c0e;                    // 0x1A4C0E
extern short d_1a4c12;                    // 0x1A4C12
extern short d_1a4c14;                    // 0x1A4C14
extern short d_1a4c16;                    // 0x1A4C16
extern short d_1a4c18;                    // 0x1A4C18
extern short d_1a4c1c;                    // 0x1A4C1C
extern short d_1a4c1e;                    // 0x1A4C1E
extern short d_1a4c20;                    // 0x1A4C20
extern short d_1a4c22;                    // 0x1A4C22
extern short d_1a4c26;                    // 0x1A4C26
extern short d_1a4c28;                    // 0x1A4C28
extern short d_1a4c2a;                    // 0x1A4C2A
extern short d_1a4c2c;                    // 0x1A4C2C
extern short d_1a4c30;                    // 0x1A4C30
extern short d_1a4c32;                    // 0x1A4C32
extern short d_1a4c34;                    // 0x1A4C34
extern short d_1a4c36;                    // 0x1A4C36
extern short d_1a4c3a;                    // 0x1A4C3A
extern short d_1a4c3c;                    // 0x1A4C3C
extern short d_1a4c3e;                    // 0x1A4C3E
extern short d_1a4c40;                    // 0x1A4C40
extern short d_1a4c58;                    // 0x1A4C58
extern short d_1a4c5a;                    // 0x1A4C5A
extern short d_1a4c5c;                    // 0x1A4C5C
extern short d_1a4c5e;                    // 0x1A4C5E
extern short d_1a4c62;                    // 0x1A4C62
extern short d_1a4c64;                    // 0x1A4C64
extern short d_1a4c66;                    // 0x1A4C66
extern short d_1a4c68;                    // 0x1A4C68
extern short d_1a4c6c;                    // 0x1A4C6C
extern short d_1a4c6e;                    // 0x1A4C6E
extern short d_1a4c70;                    // 0x1A4C70
extern short d_1a4c72;                    // 0x1A4C72
extern short d_1a4c8a;                  // 0x1A4C8A
extern short d_1a4c8c;                  // 0x1A4C8C
extern short d_1a4c8e;                  // 0x1A4C8E
extern short d_1a4c90;                  // 0x1A4C90
extern int d_1a4d84;                    // 0x1A4D84
extern int d_1bc760;                    // 0x1BC760
extern int d_1bd762;                    // 0x1BD762
extern short d_1bd766;                    // 0x1BD766
extern volatile short d_1be26c;                    // 0x1BE26C
extern volatile short d_1be26e;                    // 0x1BE26E
extern short d_1be270;                    // 0x1BE270
extern volatile int d_1be274;                    // 0x1BE274
extern int d_1be278;                    // 0x1BE278
extern int d_1be27c;                    // 0x1BE27C
extern short d_1be280;                    // 0x1BE280
extern short d_1be282;                    // 0x1BE282
extern short d_1bf4f0;                    // 0x1BF4F0
extern short d_1bf4f2;                    // 0x1BF4F2
extern int d_1bf510;                    // 0x1BF510
extern volatile int d_1bf514;                    // 0x1BF514
extern volatile short d_1bf51c;                    // 0x1BF51C
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0c4c;                    // 0x1C0C4C
extern int d_1c14c4;                    // 0x1C14C4
extern short d_1c2198;                    // 0x1C2198
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c2a80;                    // 0x1C2A80
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a48d4[];           // Text 0x1A48D4

struct S16 { char c[0x16]; };
struct S1e { char c[0x1e]; };
struct S22 { char c[0x22]; };
struct S1c { char c[0x1c]; };
struct S20 { char c[0x20]; };
struct SA3 { char c[0xa3]; };
struct QQ { char c[0x4c]; short a4c; };
int f_0a9080(int p1);
int f_0a9d90(int p1, int p2, int p3);
int f_0a9c90(int p1);
int f_0a9990(int p1);
int f_0aab50(int p1);
void f_0a8e40(int *p1);
int f_145b40(int p1);
int f_1459d0(int p1, int p2);
void f_09a120(int p1, int p2);
#define DELP(x) operator delete((void *)(x));

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0a7d50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Berechnet und initialisiert beim Aufbau des Gegenstandsverteilungs-Bildschirms sämtliche
 *   Klick- und Anzeigerechtecke (linke/obere sowie rechte/untere Koordinaten in d_1a49c4 bis d_1a4c72) für die
 *   sieben Helden-Porträts (32x32 Pixel), die Gegenstands-Slots (16x16 Pixel), die Aktionsschaltflächen (26x26
 *   Pixel) und die Bildlaufleiste aus den Basispositionen (d_1a48f4 bis d_1a49c2).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen und beschreibt direkt die globale Hotspot-Tabelle des
 *   Verteilungsfensters.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a7d50(void)
{
    d_1a49c4 = d_1a48f4;
    d_1a49c6 = d_1a48f6;
    d_1a49c8 = d_1a48f4 + 0x1f;
    d_1a49ca = d_1a48f6 + 0x1f;
    d_1a49ce = d_1a48f8;
    d_1a49d0 = d_1a48fa;
    d_1a49d2 = d_1a48f8 + 0x1f;
    d_1a49d4 = d_1a48fa + 0x1f;
    d_1a49d8 = d_1a48fc;
    d_1a49da = d_1a48fe;
    d_1a49dc = d_1a48fc + 0x1f;
    d_1a49de = d_1a48fe + 0x1f;
    d_1a49e2 = d_1a4900;
    d_1a49e4 = d_1a4902;
    d_1a49e6 = d_1a4900 + 0x1f;
    d_1a49e8 = d_1a4902 + 0x1f;
    d_1a49ec = d_1a4904;
    d_1a49ee = d_1a4906;
    d_1a49f0 = d_1a4904 + 0x1f;
    d_1a49f2 = d_1a4906 + 0x1f;
    d_1a49f6 = d_1a4908;
    d_1a49f8 = d_1a490a;
    d_1a49fa = d_1a4908 + 0x1f;
    d_1a49fc = d_1a490a + 0x1f;
    d_1a4a00 = d_1a490c;
    d_1a4a02 = d_1a490e;
    d_1a4a04 = d_1a490c + 0x1f;
    d_1a4a06 = d_1a490e + 0x1f;
    d_1a4a0a = d_1a4910;
    d_1a4a0c = d_1a4912;
    d_1a4a0e = d_1a4910 + 0xf;
    d_1a4a10 = d_1a4912 + 0xf;
    d_1a4a14 = d_1a4914;
    d_1a4a16 = d_1a4916;
    d_1a4a18 = d_1a4914 + 0xf;
    d_1a4a1a = d_1a4916 + 0xf;
    d_1a4a1e = d_1a4918;
    d_1a4a20 = d_1a491a;
    d_1a4a22 = d_1a4918 + 0xf;
    d_1a4a24 = d_1a491a + 0xf;
    d_1a4a28 = d_1a491c;
    d_1a4a2a = d_1a491e;
    d_1a4a2c = d_1a491c + 0xf;
    d_1a4a2e = d_1a491e + 0xf;
    d_1a4a32 = d_1a4920;
    d_1a4a34 = d_1a4922;
    d_1a4a36 = d_1a4920 + 0xf;
    d_1a4a38 = d_1a4922 + 0xf;
    d_1a4a3c = d_1a4924;
    d_1a4a3e = d_1a4926;
    d_1a4a40 = d_1a4924 + 0xf;
    d_1a4a42 = d_1a4926 + 0xf;
    d_1a4a46 = d_1a4928;
    d_1a4a48 = d_1a492a;
    d_1a4a4a = d_1a4928 + 0xf;
    d_1a4a4c = d_1a492a + 0xf;
    d_1a4a50 = d_1a492c;
    d_1a4a52 = d_1a492e;
    d_1a4a54 = d_1a492c + 0xf;
    d_1a4a56 = d_1a492e + 0xf;
    d_1a4a5a = d_1a4930;
    d_1a4a5c = d_1a4932;
    d_1a4a5e = d_1a4930 + 0xf;
    d_1a4a60 = d_1a4932 + 0xf;
    d_1a4a64 = d_1a4934;
    d_1a4a66 = d_1a4936;
    d_1a4a68 = d_1a4934 + 0xf;
    d_1a4a6a = d_1a4936 + 0xf;
    d_1a4a6e = d_1a4938;
    d_1a4a70 = d_1a493a;
    d_1a4a72 = d_1a4938 + 0xf;
    d_1a4a74 = d_1a493a + 0xf;
    d_1a4a78 = d_1a493c;
    d_1a4a7a = d_1a493e;
    d_1a4a7c = d_1a493c + 0xf;
    d_1a4a7e = d_1a493e + 0xf;
    d_1a4a82 = d_1a4940;
    d_1a4a84 = d_1a4942;
    d_1a4a86 = d_1a4940 + 0xf;
    d_1a4a88 = d_1a4942 + 0xf;
    d_1a4a8c = d_1a4944;
    d_1a4a8e = d_1a4946;
    d_1a4a90 = d_1a4944 + 0xf;
    d_1a4a92 = d_1a4946 + 0xf;
    d_1a4a96 = d_1a4948;
    d_1a4a98 = d_1a494a;
    d_1a4a9a = d_1a4948 + 0xf;
    d_1a4a9c = d_1a494a + 0xf;
    d_1a4aa0 = d_1a494c;
    d_1a4aa2 = d_1a494e;
    d_1a4aa4 = d_1a494c + 0xf;
    d_1a4aa6 = d_1a494e + 0xf;
    d_1a4aaa = d_1a4950;
    d_1a4aac = d_1a4952;
    d_1a4aae = d_1a4950 + 0xf;
    d_1a4ab0 = d_1a4952 + 0xf;
    d_1a4ab4 = d_1a4954;
    d_1a4ab6 = d_1a4956;
    d_1a4ab8 = d_1a4954 + 0xf;
    d_1a4aba = d_1a4956 + 0xf;
    d_1a4abe = d_1a4958;
    d_1a4ac0 = d_1a495a;
    d_1a4ac2 = d_1a4958 + 0xf;
    d_1a4ac4 = d_1a495a + 0xf;
    d_1a4ac8 = d_1a495c;
    d_1a4aca = d_1a495e;
    d_1a4acc = d_1a495c + 0xf;
    d_1a4ace = d_1a495e + 0xf;
    d_1a4ad2 = d_1a4960;
    d_1a4ad4 = d_1a4962;
    d_1a4ad6 = d_1a4960 + 0xf;
    d_1a4ad8 = d_1a4962 + 0xf;
    d_1a4adc = d_1a4964;
    d_1a4ade = d_1a4966;
    d_1a4ae0 = d_1a4964 + 0xf;
    d_1a4ae2 = d_1a4966 + 0xf;
    d_1a4ae6 = d_1a4968;
    d_1a4ae8 = d_1a496a;
    d_1a4aea = d_1a4968 + 0xf;
    d_1a4aec = d_1a496a + 0xf;
    d_1a4af0 = d_1a496c;
    d_1a4af2 = d_1a496e;
    d_1a4af4 = d_1a496c + 0xf;
    d_1a4af6 = d_1a496e + 0xf;
    d_1a4afa = d_1a4970;
    d_1a4afc = d_1a4972;
    d_1a4afe = d_1a4970 + 0xf;
    d_1a4b00 = d_1a4972 + 0xf;
    d_1a4b04 = d_1a4974;
    d_1a4b06 = d_1a4976;
    d_1a4b08 = d_1a4974 + 0xf;
    d_1a4b0a = d_1a4976 + 0xf;
    d_1a4b0e = d_1a4978;
    d_1a4b10 = d_1a497a;
    d_1a4b12 = d_1a4978 + 0xf;
    d_1a4b14 = d_1a497a + 0xf;
    d_1a4b18 = d_1a497c;
    d_1a4b1a = d_1a497e;
    d_1a4b1c = d_1a497c + 0xf;
    d_1a4b1e = d_1a497e + 0xf;
    d_1a4b22 = d_1a4980;
    d_1a4b24 = d_1a4982;
    d_1a4b26 = d_1a4980 + 0xf;
    d_1a4b28 = d_1a4982 + 0xf;
    d_1a4b2c = d_1a4984;
    d_1a4b2e = d_1a4986;
    d_1a4b30 = d_1a4984 + 0xf;
    d_1a4b32 = d_1a4986 + 0xf;
    d_1a4b36 = d_1a4988;
    d_1a4b38 = d_1a498a;
    d_1a4b3a = d_1a4988 + 0xf;
    d_1a4b3c = d_1a498a + 0xf;
    d_1a4c08 = d_1a498c;
    d_1a4c0a = d_1a498e;
    d_1a4c0c = d_1a4990;
    d_1a4c0e = d_1a4992;
    d_1a4c12 = d_1a4994;
    d_1a4c14 = d_1a4996;
    d_1a4c16 = d_1a4994 + 0x19;
    d_1a4c18 = d_1a4996 + 0x19;
    d_1a4c1c = d_1a4998;
    d_1a4c1e = d_1a499a;
    d_1a4c20 = d_1a4998 + 0x19;
    d_1a4c22 = d_1a499a + 0x19;
    d_1a4c26 = d_1a499c;
    d_1a4c28 = d_1a499e;
    d_1a4c2a = d_1a499c + 0x19;
    d_1a4c2c = d_1a499e + 0x19;
    d_1a4c30 = d_1a49a0;
    d_1a4c32 = d_1a49a2;
    d_1a4c34 = d_1a49a0 + 0x19;
    d_1a4c36 = d_1a49a2 + 0x19;
    d_1a4c3a = d_1a49a4;
    d_1a4c3c = d_1a49a6;
    d_1a4c3e = d_1a49a4 + 0x19;
    d_1a4c40 = d_1a49a6 + 0x19;
    d_1a4c58 = d_1a49b0;
    d_1a4c5a = d_1a49b2;
    d_1a4c5c = d_1a49b4;
    d_1a4c5e = d_1a49b6;
    d_1a4c62 = d_1a49b8;
    d_1a4c64 = d_1a49ba;
    d_1a4c66 = d_1a49bc;
    d_1a4c68 = d_1a49be;
    d_1a4c6c = d_1a49c0;
    d_1a4c6e = d_1a49c2;
    d_1a4c70 = d_1a49c0 + 10;
    d_1a4c72 = d_1a49c2 + 0x45;
}

//@ f_0a87e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Dient als Maus-Callback-Funktion des Gegenstandsverteilungs-Fensters: Sie prüft, ob die
 *   übergebene Hotspot-Kennung ungleich dem aktuell ausgewählten Feld (d_1be26c) ist und eine Maustaste betätigt
 *   wurde (f_0d3810, f_0d3780 oder f_0d3800), und merkt in diesem Fall die neue Hotspot-Kennung (d_1be270) samt
 *   Änderungsflag (d_1be274 = 1) vor.
 * - Eingaben: Übergeben wird die Kennung des unter dem Mauszeiger liegenden Interaktionsfelds (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a87e0(short p1)
{
    if (p1 && p1 != d_1be26c) {
        if (f_0d3810() || f_0d3780() || f_0d3800()) {
            d_1be274 = 1;
            d_1be270 = p1;
        }
    }
}

//@ f_0a8830
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Agiert als Konstruktor der Gegenstandsverteilungs-Ansicht: Die Methode speichert den
 *   übergebenen Gegenstandspool und den Modus im Fensterobjekt, erzeugt für die sieben Gruppenplätze die
 *   Helden-Anzeige-Widgets (f_026ff0), das Gegenstandsgitter-Widget (f_01f3c0), den vertikalen Scrollbalken
 *   (f_140220, skaliert nach der Anzahl der Gegenstände im Pool), die Detailanzeige (f_050860) sowie sieben
 *   Icons/Schaltflächen (0x80 bis 0x86 aus Archiv 0x210005) und setzt die Auswahl- und Filterfelder auf ihre
 *   Startwerte.
 * - Eingaben: Übergeben werden ein Zeiger auf die zu initialisierende Verteilungsfenster-Struktur (this), ein
 *   Zeiger auf den zu verteilenden Gegenstandspool sowie ein Steuer- und Modus-Parameter.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die initialisierte Verteilungsfenster-Struktur zurück.
 === Ende Beschreibung === */
int *f_0a8830(int *p1, int p2, int p3)
{
    short bound;
    short loc;
    short i;
    int s1;
    {
        int t;
        int a;
        int b;
        int fp = (int)&d_1c14c4;
        d_1be282 = f_13fc70(fp);
        bound = 20;
        loc = 100;
        s1 = f_11c320(p2);
        p1[0] = p2;
        p1[1] = p3;
        for (i = 0; i < 7; i++) {
            t = (int)new (mark(d_1a48d4, 0x28e)) S16;
            if (t != 0) t = f_026ff0(t, f_0de7d0(d_1c0004, i), i, 0x210002, 0x50002);
            p1[i + 2] = t;
        }
        t = (int)new (mark(d_1a48d4, 0x292)) S1e;
        if (t) {
            t = f_01f3c0(t, 0x8b, 0x31, 4, 5, (a = p1[0]), 0x210001, 0x50002);
        } else {
            t = 0;
        }
        p1[9] = t;
        if ((short)s1 > (short)bound) loc = ((short)bound * 100) / (short)s1;
        t = (int)new (mark(d_1a48d4, 0x29a)) S22;
        t = t ? f_140220(t, (short)d_1a49c0, d_1a49c2, 0x45, (short)loc, 0, 0x210003) : 0;
        p1[10] = t;
        t = (int)new (mark(d_1a48d4, 0x29d)) S1c;
        if (t != 0) {
            a = p1[0];
            b = f_027080(p1[2]);
            t = f_050860(t, b, a, 0x210002);
        }
        p1[0xb] = t;
        t = (int)new (mark(d_1a48d4, 0x2a0)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x80) : 0;
        p1[0xc] = t;
        t = (int)new (mark(d_1a48d4, 0x2a1)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x81) : 0;
        p1[0xd] = t;
        t = (int)new (mark(d_1a48d4, 0x2a2)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x82) : 0;
        p1[0xe] = t;
        t = (int)new (mark(d_1a48d4, 0x2a3)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x83) : 0;
        p1[0xf] = t;
        t = (int)new (mark(d_1a48d4, 0x2a4)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x84) : 0;
        p1[0x10] = t;
        t = (int)new (mark(d_1a48d4, 0x2a5)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x85) : 0;
        p1[0x11] = t;
        t = (int)new (mark(d_1a48d4, 0x2a6)) S20;
        t = t ? f_0a22e0(t, 0x210005, 0x86) : 0;
        *(short *)(p1 + 0x13) = 1;
        *(short *)((char *)p1 + 0x4e) = 0xf;
        *(short *)(p1 + 0x14) = 0;
        *(short *)((char *)p1 + 0x52) = 0;
        *(short *)(p1 + 0x15) = 0;
        *(int *)((char *)p1 + 0x56) = 0;
        p1[0x12] = t;
    }
    return p1;
}

//@ f_0a8b40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Agiert als Destruktor der Gegenstandsverteilungs-Ansicht: Die Methode zerstört die sieben
 *   Helden-Widgets, die sieben Aktions-Icons, das Gegenstandsgitter, den Scrollbalken sowie die Detailanzeige,
 *   gibt deren Speicher frei und stellt den vorherigen Grafik- und Schriftstatus (d_1c14c4, d_1be282) wieder
 *   her.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie ein Steuerflag für
 *   die Speicherfreigabe.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die bereinigte Verteilungsfenster-Struktur zurück.
 === Ende Beschreibung === */
int f_0a8b40(int p1, int kp2)
{
    short i;
    int t;
    for (i = 0; i < 7; i++) {
        t = *(int *)(p1 + 8 + i * 4);
        if (t != 0) DELP(f_027050(t, 0));
    }
    for (i = 0; i < 7; i++) {
        t = *(int *)(p1 + 0x30 + i * 4);
        if (t != 0) DELP(f_0a2400(t, 0));
    }
    t = *(int *)(p1 + 0x24);
    if (t != 0) DELP(f_01f410(t, 0));
    t = *(int *)(p1 + 0x28);
    if (t != 0) DELP(f_140300(t, 0));
    t = *(int *)(p1 + 0x2c);
    if (t != 0) DELP(f_0508f0(t, 0));
    f_13fcd0((int)&d_1c14c4, d_1be282);
    return p1;
}

//@ f_0a8be0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Haupt-Ereignisschleife des Gegenstandsverteilungs-Dialogs aus: Sie sichert den
 *   aktuellen UI- und Maus-Kontext, zeichnet den Bildschirm über f_0a8e40, registriert die Hotspot-Tabelle
 *   (d_1a49c4) sowie den Callback f_0a87e0 und verarbeitet in einer Schleife Auswahlwechsel (Hotspots 142 bis
 *   192 für Gegenstands- und Inventarplätze) sowie Benutzeraktionen (f_0a9080), bis das Fenster geschlossen
 *   wird.
 * - Eingaben: Übergeben wird ein Zeiger auf die aktive Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt den im ersten Feld der Struktur gespeicherten Zeiger auf den Gegenstandspool
 *   zurück.
 === Ende Beschreibung === */
struct OC {
    int h;
    OC() { f_0ce7c0((int)this); }
    ~OC() { f_0ce7e0((int)this, 0); }
};
int f_0a8be0(int p1)
{
    struct Frame720 {
        int flag;
        int guard;
        void init(){ if (f_0d3860()==1) { f_0d2710(); flag=1; } else flag=0; }
        ~Frame720(){ if (flag==1) f_0d26e0(); f_0ce7e0((int)&guard,0); }
    } frame;
    f_0ce7c0((int)&frame.guard);
    int saved_second, saved_first;
    saved_first = d_1bf510;
    saved_second = d_1bf514;

    f_0bf6c0((int)&d_1c2c64, 5);
    if (d_1bc760 != 0) f_01e0c0();
    f_0ce650();
    d_1c0c4c = d_1c0c4c + 1;
    f_09a140(0, 25);
    f_0d2f90(0, 1);
    f_0a8e40((int *)p1);

    d_1bd766 = 0;
    d_1bf510 = (int)&d_1a49c4;
    d_1bf514 = 0;
    d_1be278 = d_1bf520;
    d_1be27c = d_1bf524;
    d_1be280 = d_1bf51c;
    d_1be26c = 157;
    d_1be26e = 157;
    *(volatile int *)&d_1bf520 = d_1a4d84;
    d_1bf524 = (int)f_0a87e0;
    d_1bf51c = 1;

    do {
        if (d_1be274 == 1) {
            d_1be274 = 0;
            d_1be26e = d_1be270;
        }
        int current = p1;
        if (d_1be26e != d_1be26c && d_1be26e >= 142 && d_1be26e <= 192) {
            if (d_1be26c >= 142 && d_1be26c <= 192)
                f_0a9d90(p1, d_1be26c, 1);
            f_0a9d90(current, d_1be26e, 0);
            f_0a9c90(current);
            d_1be26c = d_1be26e;
        }
        *(short *)(p1 + 0x52) = d_1bf4f0;
        *(short *)(p1 + 0x54) = d_1bf4f2;
        f_068f40();
    } while (f_0a9080(p1) == 0);

    frame.init();
    f_0d3870();
    d_1bf51c = 0;
    d_1bf520 = d_1be278;
    d_1bf524 = d_1be27c;
    d_1bf51c = d_1be280;
    d_1bf510 = saved_first;
    d_1bf514 = saved_second;
    *(volatile short *)&d_1c2198 = 1;
    --d_1c0c4c;
    f_0bf680((int)&d_1c2c64);
    f_09a140(0, 25);
    f_09a0d0(d_1a34e0);
    d_1c2a80 = 0;
    int result = *(int *)p1;

    return result;
}
//@ f_0a8e40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Lädt das Hintergrundbild des Gegenstandsverteilungs-Bildschirms (0x210000) in einen 64.000
 *   Byte großen Zwischenpuffer, kopiert es in den Bildschirmpuffer (d_1a34e0), zeichnet die Schaltflächen, die
 *   sieben Heldenleisten, das Gegenstandsgitter, den Scrollbalken sowie die Beschriftungen (f_0a9c90, f_0a9990)
 *   und übernimmt die zugehörige Farbpalette (f_09a120).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
int f_0aab50(int p1, int p2, int p3);
void f_0a8e40(int *p1)
{
    char *buf;
    int obj;
    int fl;
    short i;
    buf = new (mark(d_1a48d4, 0x324)) char[64000];
    {
        int t = (int)new (mark(d_1a48d4, 0x325)) SA3;
        obj = t ? f_1459b0(t) : t;
    }
    if (f_0d3860() == 1) {
        f_0d2710();
        fl = 1;
    } else {
        fl = 0;
    }
    d_1c2a80 = 0x210000;
    f_145a10(obj, 0x210000, (int)buf);
    memcpy((void *)d_1a34e0, buf, 64000);
    DELP(buf);
    f_0aab50((int)p1, 3, 1);
    for (i = 0; i < 7; i++) f_0270d0(p1[i + 2]);
    f_01fb40(p1[9], 0);
    f_1404e0(p1[10]);
    f_0a9c90((int)p1);
    f_0a9990((int)p1);
    f_09a120(f_145b40(obj), 0x19);
    if (obj != 0) DELP(f_1459d0(obj, 0));
    if (fl == 1) f_0d26e0();
}
//@ f_0a8f80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktiviert die Hotspot-Überwachung für das Gegenstandsverteilungs-Fenster, indem die
 *   vorherigen Zeiger und Callbacks der Maussteuerung (d_1bf520, d_1bf524, d_1bf51c) gesichert und durch die
 *   Hotspot-Tabelle des Verteilungsfensters (d_1a49c4, d_1a4d84) sowie den Callback f_0a87e0 (mit Startauswahl
 *   157) ersetzt werden.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a8f80(void)
{
    d_1bd766 = 0;
    (*(volatile int *)&d_1bf510) = (int)&d_1a49c4;
    d_1bf514 = 0;
    d_1be278 = d_1bf520;
    d_1be27c = d_1bf524;
    d_1be280 = d_1bf51c;
    d_1be26c = 0x9d;
    d_1be26e = 0x9d;
    (*(volatile int *)&d_1bf520) = d_1a4d84;
    d_1bf524 = (int)f_0a87e0;
    d_1bf51c = 1;
}

//@ f_0a9000
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Deaktiviert die Hotspot-Überwachung des Gegenstandsverteilungs-Fensters wieder und stellt
 *   die zuvor in d_1be278, d_1be27c und d_1be280 gesicherten Maus-Hotspot-Zeiger und Callbacks wieder her.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0a9000(void)
{
    f_0d3870();
    d_1bf51c = 0;
    d_1bf520 = d_1be278;
    d_1bf524 = d_1be27c;
    d_1bf51c = d_1be280;
}

//@ f_0a9040
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Setzt den aktuell ausgewählten Slot-Index im Verteilungsfenster (Offset +0x50) und
 *   aktualisiert die globale Hotspot-Kennung (d_1be26c, d_1be26e) abhängig davon, ob derzeit die obere
 *   Pool-Ansicht (+0x8e, Basis 142) oder das Heldeninventar (+0xad, Basis 173) aktiv ist (Offset +0x4c).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der neue Slot-Index
 *   (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
#define C4C (!*(short *)(p1 + 0x4c))
void f_0a9040(int p1, short p2)
{
    *(short *)(p1 + 0x50) = p2;
    if (C4C) d_1be26e = *(short *)(p1 + 0x50) + 0x8e;
    else d_1be26e = *(short *)(p1 + 0x50) + 0xad;
    d_1be26c = d_1be26e;
}
