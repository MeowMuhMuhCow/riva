/* === Beschreibung (Katalog) ===
 * Einheit itemdist_t3 (0x0AA250 - 0x0AB550)
 *
 * Diese Einheit bildet den dritten Teil des Gegenstandsverteilungs-Fensters (p:\riva\source\cpp\itemdist.cpp)
 * und behandelt die Navigation im Heldeninventar, das Aufnehmen und Ablegen von Gegenständen, das automatische
 * Verteilen und Entleeren sowie das Tauschen von Heldenpositionen.
 === Ende Beschreibung === */
// P3 17/19 gleich (suche.py 25.10.2026, Basis itemdist_t3_P1.CPP)
// itemdist.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A7D50-0x0AB880
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
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
int f_0422b0(int p1);                                   // reg eax stapel 0
int f_050860();                       // nicht in clobber.tsv
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
unsigned short f_0a2440(int p1);                                   // reg eax stapel 0
int f_0a2460(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0a2480(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0a78f0(int p1);                                   // reg eax stapel 0
int f_0a7910(int p1);                                   // reg eax stapel 0
int f_0a7990(int p1);                                   // reg eax stapel 0
int f_0a79b0(int p1);                                   // reg eax stapel 0
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
int f_0fac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0fad20(int p1, int p2);                           // reg eax stapel 0
int f_0fade0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
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
int f_140220();                       // nicht in clobber.tsv
int f_140300(int p1, int p2);                           // reg eax stapel 0
int f_140360(int p1);                                   // reg eax stapel 0
int f_140370(int p1);                                   // reg eax stapel 0
int f_140380(int p1);                                   // reg eax stapel 0
int f_140390(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1404e0(int p1, int p2, int p3);
int f_1405c0(int p1);                                   // reg eax stapel 0
int f_1459b0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_149cf0(int p1);
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
extern short d_1a4994[];
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
extern int d_1a4d84;                    // 0x1A4D84
extern int d_1bc760;                    // 0x1BC760
extern int d_1bd762;                    // 0x1BD762
extern int d_1bd766;                    // 0x1BD766
extern volatile short d_1be26c; extern volatile short d_1be26e;
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
extern int *d_1c2c40;
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a48d4[];           // Text 0x1A48D4
// --- eigene Funktionen (43), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
extern struct T4 { short a, b, c, d; } d_1a4c8a[];
void f_0a9990(int p);
void f_0a9c90(int p);
void f_0a9d90(int p, int s, int f);
void f_0aa250(short p, int p2);
void f_0aa410(int p);
void f_0aa430(int p);
void f_0aa5b0(int p, short p2);
void f_0aa690(int p, short p2);
void f_0aa7b0(int p);
void f_0aa900(int p, int pq);
void f_0aa930(int p, int p2);
void f_0aa990(int p, int p2);
void f_0aab50(int p, int p2, int p3);
void f_0aac50(int p, short p2);
void f_0aadb0(int p);
int f_0aaf10(int p1, short p2, int p3);
int f_0aafe0(int p, short *p2);
void f_0ab080(int p, short p2);
void f_0ab2e0(int p, int p2);
void f_0ab320(int p, short p2, int p3);
void f_0ab400(int p);
int f_0ab550(int p, int v);
int f_0ab520(int p);
struct O { int h; int pad; int sl[7]; int o24; int o28; int o2c; int sl2[7]; short f4c, f4e, f50, f52a, f52b; int f56; };
#define S16(p,o) (*(short *)((p)+(o)))
#define FLD(p,f) (((struct O *)(p))->f)
#define I32(p,o) (*(int *)((p)+(o)))
#define UPD(p) \
    d_1be26e = d_1be26c; \
    d_1be26c = 0; \
    if (d_1be26e != d_1be26c) { \
        if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) { \
            if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1); \
            f_0a9d90(p, d_1be26e, 0); \
            f_0a9c90(p); \
            d_1be26c = d_1be26e; \
        } \
    }
#define SETD(c,a,b) if (c) d_1be26e = (a); else d_1be26e = (b); d_1be26c = d_1be26e;
#define TB0(i) d_1c2c40[i]
#define TB1(i) (*(int *)((int)d_1c2c40 + (i) * 4))
struct MG {
    int fl;
    MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else { fl = 0; } }
    ~MG() { if (fl == 1) f_0d26e0(); }
};
#define DELP(x) operator delete((void *)(x));
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0aa250
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bewegt die Auswahlmarkierung innerhalb der Ausrüstungs- und Rucksack-Slots des ausgewählten
 *   Helden anhand einer Richtungstaste (0xc9-0xce: Pos1 springt auf Slot 15, Ende auf Slot 14, die vier
 *   Pfeiltasten folgen der Nachbarschaftstabelle d_1a4c8a) und zeichnet den neuen Auswahlrahmen (f_026570).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Tastencode
 *   (0xc9-0xce).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa250(int p, int p2)
{
    short s;
    f_0266e0(f_027080(I32(p, 8)), FLD(p, f50));
    switch ((unsigned short)(p2 - 0xc9)) {
    case 0:
        FLD(p, f50) = 0xf;
        SETD(FLD(p, f4c) == (short)0, FLD(p, f50) + 0x8e, FLD(p, f50) + 0xad);
        break;
    case 1:
        FLD(p, f50) = d_1a4c8a[FLD(p, f50)].a;
        SETD(FLD(p, f4c) == (short)0, FLD(p, f50) + 0x8e, FLD(p, f50) + 0xad);
        break;
    case 2:
        s = d_1a4c8a[FLD(p, f50)].b;
        FLD(p, f50) = s;
        SETD(FLD(p, f4c) == (short)0, s + 0x8e, s + 0xad);
        break;
    case 3:
        s = d_1a4c8a[FLD(p, f50)].c;
        FLD(p, f50) = s;
        SETD(FLD(p, f4c) == (short)0, s + 0x8e, s + 0xad);
        break;
    case 4:
        s = d_1a4c8a[FLD(p, f50)].d;
        FLD(p, f50) = s;
        SETD(FLD(p, f4c) == (short)0, s + 0x8e, s + 0xad);
        break;
    case 5:
        FLD(p, f50) = 0xe;
        SETD(FLD(p, f4c) == (short)0, FLD(p, f50) + 0x8e, FLD(p, f50) + 0xad);
    }
    f_026570(f_027080(I32(p, 8)), FLD(p, f50), 3);
}
//@ f_0aa410
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Standard-Auswahlaktion (z. B. bei Druck auf Enter) für den aktuell fokussierten
 *   Slot aus: Sie verzweigt je nach Fokusbereich (Offset +0x4c) entweder in die Heldeninventar-Slot-Aktion
 *   (f_0aa5b0) oder in die Beutepool-Slot-Aktion (f_0aa690).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa410(int p)
{
    if (!FLD(p, f4c)) {
        f_0aa5b0(p, FLD(p, f50));
        return;
    }
    f_0aa690(p, FLD(p, f50));
}
//@ f_0aa430
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Macht eine laufende Gegenstandsaufnahme rückgängig (z. B. beim Abbrechen mit Esc, während
 *   ein Gegenstand am Cursor hängt): Sie legt den Gegenstand im Detail- und Cursor-Controller (f_050c70) an
 *   seinen Ursprungsort im Beutepool oder Heldeninventar zurück und aktualisiert Gitter, Scrollbalken,
 *   Heldenanzeige sowie Slot-Markierung.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa430(int p)
{
    int a;
    short s1;
    int s2;
    short s3;
    int q, t1, t2;
    a = f_050920(I32(p, 0x2c));
    s1 = f_050930(I32(p, 0x2c));
    s2 = f_050940(I32(p, 0x2c));
    q = f_027080(I32(p, 8));
    f_050c70(I32(p, 0x2c));
    f_051060(I32(p, 0x2c));
    s3 = f_050930(I32(p, 0x2c));
    if (s3 == (short)1) {
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1)
            f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
        t1 = (short)f_01f620(I32(p, 0x24));
        t2 = (short)f_01f490(I32(p, 0x24));
        f_140390(I32(p, 0x28), t2, t1);
        { extern int f_1404e0(int); f_1404e0(I32(p, 0x28)); }
        goto L1;
    } else if (s1 == (short)0) {
        if (a == q) f_025d90(q, (short)s2, d_1a34e0);
        goto L1;
    } else {
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
    }
    t1 = (short)f_01f620(I32(p, 0x24));
    t2 = (short)f_01f490(I32(p, 0x24));
    f_140390(I32(p, 0x28), t2, t1);
    { extern int f_1404e0(int); f_1404e0(I32(p, 0x28)); }
L1:
    d_1be26e = d_1be26c;
    d_1be26c = 0;
    int c = p;
    if (d_1be26e != d_1be26c) {
        if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) {
            if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1);
            f_0a9d90(c, d_1be26e, 0);
            f_0a9c90(c);
            d_1be26c = d_1be26e;
        }
    }
}
//@ f_0aa5b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verarbeitet das Anklicken oder Aktivieren eines Slots im Inventar des ausgewählten Helden:
 *   Sie übergibt den Slot-Index an die Gegenstands-Übergabelogik (f_050980), wechselt bei Bedarf den Fokus auf
 *   das Heldeninventar, aktualisiert die Eignungsanzeigen aller sieben Heldenleisten (f_027830, f_027690) und
 *   zeichnet den betroffenen Inventar-Slot (f_027280) sowie die Detailanzeige neu.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Slot-Index im
 *   Heldeninventar (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa5b0(int p, short p2)
{
    short k;
    short sv;
    f_050980(I32(p, 0x2c), p2);
    f_051060(I32(p, 0x2c));
    if (FLD(p, f4c) != (short)0) {
        FLD(p, f4e) = p2;
        f_0a9990(p);
    } else {
        f_0266e0(f_027080(I32(p, 8)), FLD(p, f50));
        FLD(p, f50) = p2;
        SETD(FLD(p, f4c) == (short)0, (unsigned short)FLD(p, f50) + 0x8e, (unsigned short)FLD(p, f50) + 0xad);
        f_026570(f_027080(I32(p, 8)), FLD(p, f50), 3);
    }
    sv = f_050960(I32(p, 0x2c));
    int base = p;
    for (k = 0; k < 7; k++) {
        int q = base + k * 4;
        f_027830(I32(q, 8), sv);
        f_027690(I32(q, 8));
    }
    f_027280(I32(p, 8), p2);
    f_0a9c90(p);
}
//@ f_0aa690
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verarbeitet das Anklicken oder Aktivieren eines Slots im Beutepool-Gitter: Sie ermittelt den
 *   Pool-Index des angeklickten Gitterplatzes (f_020760), nimmt den Gegenstand über die Übergabelogik auf bzw.
 *   legt ihn dort ab (f_050b40), setzt den Fokus auf das Pool-Gitter und aktualisiert Heldenleisten,
 *   Gegenstandsgitter, Scrollbalken und Detailanzeige.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der sichtbare
 *   Gitter-Slot-Index (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa690(int p, short p2)
{
    short s1, s2, k;
    int q;
    s1 = f_020760(I32(p, 0x24), (short)p2);
    f_050b40(I32(p, 0x2c), s1);
    f_051060(I32(p, 0x2c));
    if (FLD(p, f4c) != (short)1) {
        FLD(p, f4e) = p2;
        f_0a9990(p);
    } else {
        FLD(p, f50) = p2;
        SETD(FLD(p, f4c) == (short)0, (unsigned short)FLD(p, f50) + 0x8e, (unsigned short)FLD(p, f50) + 0xad);
    }
    s1 = f_050960(I32(p, 0x2c));
    int base = p;
    for (k = 0; k < 7; k++) {
        q = base + k * 4;
        f_027830(I32(q, 8), s1);
        f_027690(I32(q, 8));
    }
    if (f_020150(I32(p, 0x24)) == 1) {
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
    } else {
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
    }
    int x = (short)f_01f620(I32(p, 0x24));
    int y = (short)f_01f490(I32(p, 0x24));
    f_140390(I32(p, 0x28), y, x);
    f_1404e0(I32(p, 0x28));
    f_0a9c90(p);
}
//@ f_0aa7b0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Legt einen derzeit am Cursor aufgenommenen Gegenstand direkt ans Ende des Beutepools ab
 *   (f_050b40 mit Index -1), aktualisiert die sieben Heldenleisten, das Gegenstandsgitter sowie den Scrollbalken
 *   und stellt die Slot-Markierung wieder her.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa7b0(int p)
{
    if ((short)f_050960(I32(p, 0x2c)) != 0) {
        f_050b40(I32(p, 0x2c), -1);
        int base = p;
        f_051060(I32(p, 0x2c));
        short k;
        short n = f_050960(I32(p, 0x2c));
        for (k = 0; k < 7; k++) {
            int q = base + k * 4;
            f_027830(I32(q, 8), n);
            f_027690(I32(q, 8));
        }
        short t = f_0208d0(I32(p, 0x24)) - 1;
        if (t >= 0 && t < 0x14) f_01fef0(I32(p, 0x24), t);
        int x = (short)f_01f620(I32(p, 0x24));
        int y = (short)f_01f490(I32(p, 0x24));
        f_140390(I32(p, 0x28), y, x);
        { extern int f_1404e0(int); f_1404e0(I32(p, 0x28)); }
    }
    d_1be26e = d_1be26c;
    d_1be26c = 0;
    int c = p;
    if (d_1be26e != d_1be26c) {
        if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) {
            if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1);
            f_0a9d90(c, d_1be26e, 0);
            f_0a9c90(c);
            d_1be26c = d_1be26e;
        }
    }
}
//@ f_0aa900
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet das Gegenstandsgitter des Beutepools neu (f_01fb40) und setzt - falls der
 *   Eingabefokus derzeit auf dem Beutepool liegt (Offset +0x4c == 1) - den Auswahlrahmen auf den aktuellen
 *   Gitter-Slot (f_020640).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie ein zweiter Parameter
 *   (pq), der im Funktionskörper jedoch ignoriert wird (siehe Fehlerliste).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa900(int p, int pq)
{
    f_01fb40(I32(p, 0x24), 0);
    if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
}
//@ f_0aa930
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Aktualisiert für alle sieben Helden-Widgets der Gruppe die Anzeige zur Tragbarkeit bzw.
 *   Gegenstandseignung für die übergebene Gegenstands-ID (f_027830) und zeichnet die Heldenleisten neu
 *   (f_027690).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und die Gegenstands-ID
 *   (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa930(int p, int p2)
{
    short k;
    for (k = 0; k < 7; k++) {
        int q = p + k * 4;
        f_027830(I32(q, 8), (short)p2);
        f_027690(I32(q, 8));
    }
}
//@ f_0aa990
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt die Funktion einer der sieben oberen Aktionsschaltflächen (0x80-0x86) aus: Sie
 *   schaltet bei 0x80-0x83 zwischen den vier Gegenstands-Filterkategorien um (f_01f450), verteilt bei 0x84 die
 *   sichtbaren Pool-Gegenstände automatisch auf die Helden (f_0aac50), räumt bei 0x85 das Inventar des aktuellen
 *   Helden in den Pool zurück (f_0aadb0) und betätigt bei 0x86 optisch den Schließen-Knopf.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Schaltflächencode
 *   (0x80-0x86).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aa990(int p, int p2)
{
    int fl = 0;
    short b, a;
    switch ((short)p2) {
    case 0x80: case 0x81: case 0x82: case 0x83:
        b = (short)p2 - 0x80;
        a = f_01f460(I32(p, 0x24));
        if (a != b) {
            f_0aab50(p, a, 0);
            f_0aab50(p, b, 1);
            f_01f450(I32(p, 0x24), b);
            fl = 1;
        }
        break;
    case 0x84:
        f_0aab50(p, 4, 1);
        a = f_01f460(I32(p, 0x24));
        f_0aac50(p, a);
        f_0aab50(p, 4, 0);
        a = f_0208d0(I32(p, 0x24));
        fl = 1;
        if (a == 0) {
            a = f_01f460(I32(p, 0x24));
            f_0aab50(p, a, 0);
            f_01f450(I32(p, 0x24), 3);
            f_0aab50(p, 3, 1);
        }
        break;
    case 0x85:
        f_0aab50(p, 5, 1);
        f_0aadb0(p);
        fl = 1;
        f_0aab50(p, 5, 0);
        break;
    case 0x86:
        f_0aab50(p, 6, 1);
        f_149cf0(0x50);
        while (f_0d3790() == 0) ;
        f_0aab50(p, 6, 0);
    }
    if (fl == 1) {
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
        f_140390(I32(p, 0x28), (short)f_01f490(I32(p, 0x24)), (short)f_01f620(I32(p, 0x24)));
        { extern int f_1404e0(int); f_1404e0(I32(p, 0x28)); }
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
        f_0a9c90(p);
    }
}
//@ f_0aab50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zeichnet eine der sieben oberen Aktionsschaltflächen im gedrückten (p3 == 1, über f_0a2460)
 *   oder ungedrückten Zustand (p3 == 0, über f_0a2480) in ein temporäres Rasterbild und kopiert dieses an die
 *   zugehörige Bildschirmposition (d_1a4994) im Bildschirmpuffer (d_1a34e0).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this), der Schaltflächenindex
 *   (0-6) sowie der Darstellungszustand (0 = normal, 1 = gedrückt).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aab50(int p, int p2, int p3)
{
    MG mg;
    int t = (int)operator new(9, mark(d_1a48d4, 0x72c));
    int o = t ? f_0fac80(t, (short)f_0a2430(I32(p + (short)p2 * 4, 0x30)), (short)f_0a2440(I32(p + (short)p2 * 4, 0x30))) : t;
    if ((short)p3 == (short)1) f_0a2460(I32(p, 0x30 + (short)p2 * 4), o, 0, 0);
    else f_0a2480(I32(p, 0x30 + (short)p2 * 4), o, 0, 0);
    f_0fade0(o, d_1a34e0, d_1a4994[(short)p2 * 2], d_1a4994[(short)p2 * 2 + 1]);
    if (o != 0) DELP(f_0fad20(o, 0))
}
//@ f_0aac50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verteilt alle Gegenstände des Beutepools, die zur übergebenen Filterkategorie passen (p2 ==
 *   3 für alle oder Prüfung über f_0aaf10), automatisch der Reihe nach auf die Gruppenmitglieder (f_0aafe0),
 *   entfernt erfolgreich übergebene Gegenstände aus dem Pool (f_11c580) und gibt eine Meldung (0x21040010) aus,
 *   falls kein einziger Gegenstand verteilt werden konnte.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und die aktive
 *   Filterkategorie (0-3).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aac50(int p, short p2)
{
    int fnd;
    short k = 0, j;
    fnd = 0;
    if ((short)f_11c320(I32(p, 0)) > 0) {
        while (k < (short)f_11c320(I32(p, 0))) {
            if ((short)p2 != (short)3) {
                if (f_0aaf10(p, (short)f_11c620(I32(p, 0), k), (short)p2) != 1) goto L2;
            }
            if (f_0aafe0(p, (short *)f_11c330(I32(p, 0), k)) == 1) {
                f_11c580(I32(p, 0), k);
                fnd = 1;
                continue;
            }
L2:
            k++;
        }
        f_01f470(I32(p, 0x24), 0);
        for (j = 0; j < 7; j++) f_027240(I32(p + (short)j * 4, 8));
        {
            int q;
            d_1be26e = d_1be26c;
            d_1be26c = 0;
            q = p;
            if (d_1be26e != d_1be26c) {
                if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) {
                    if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1);
                    f_0a9d90(q, d_1be26e, 0);
                    f_0a9c90(q);
                    d_1be26c = d_1be26e;
                }
            }
        }
        if (fnd == 0 && (short)f_0208d0(I32(p, 0x24)) > 0) f_0bf730((int)&d_1c2c64, 0x21040010);
    }
}
//@ f_0aadb0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Überträgt sämtliche ablegbaren Gegenstände aus den 31 Inventar-Slots des aktuell
 *   ausgewählten Helden in den Beutepool (f_11c350), sofern der Pool nicht gesperrt oder voll ist (f_11c160,
 *   sonst Meldung 0x21040011), und zeichnet Heldenleiste sowie Gegenstandsgitter neu.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aadb0(int p)
{
    short i, s1, s2;
    int q = f_027080(I32(p, 8));
    int z;
    int c;
    if (f_11c160(I32(p, 0)) == 1) {
        f_0bf730((int)&d_1c2c64, 0x21040011);
    } else {
        for (i = 0; i < 0x1f; i++) {
            if ((short)f_026a70(q, i) != 0) {
                s1 = f_026a20(q, i);
                z = f_026a80(q, i);
                s2 = f_0264d0(q, i);
                if (s2 == s1) {
                    DELP(z)
                } else {
                    f_11c350(I32(p, 0), z);
                }
            }
        }
        f_027240(I32(p, 8));
        f_01fb40(I32(p, 0x24), 0);
        if (FLD(p, f4c) == (short)1) f_020640(I32(p, 0x24), FLD(p, f50), 0xfd);
        d_1be26e = d_1be26c;
        d_1be26c = 0;
        c = p;
        if (d_1be26e != d_1be26c) {
            if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) {
                if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1);
                f_0a9d90(c, d_1be26e, 0);
                f_0a9c90(c);
                d_1be26c = d_1be26e;
            }
        }
    }
}
//@ f_0aaf10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob ein Gegenstand anhand seiner Definition in der globalen Gegenstandstabelle
 *   (d_1c2c40) zu einer bestimmten Filterkategorie des Verteilungsfensters gehört: Kategorie 0 prüft Waffen und
 *   Rüstungen (f_0a7910), Kategorie 1 Kräuter, Tränke und Magisches (f_0a7990 oder f_0a79b0) und Kategorie 2
 *   sonstige Gegenstände (keines der drei Attribute).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this), die Gegenstands-ID (short)
 *   und die Filterkategorie (0-2).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Gegenstand in die Kategorie fällt, und sonst 0.
 === Ende Beschreibung === */
int f_0aaf10(int p1, short p2, int p3)
{
    int r = 0;
    switch ((short)p3) {
    case 0:
        { int *base = d_1c2c40;
          base += (short)p2;
          if (f_0a7910(*base)) r = 1; }
        break;
    case 1:
        if (f_0a7990(TB1((short)p2)) != 0 || f_0a79b0(TB1((short)p2)) != 0) r = 1;
        break;
    case 2:
        if (0 == f_0a7910(TB1((short)p2)) && f_0a7990(TB1((short)p2)) == 0 && f_0a79b0(TB1((short)p2)) == 0) r = 1;
        break;
    }
    return r;
}
//@ f_0aafe0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Versucht, einen Gegenstandsstapel (oder Teilmengen davon) nacheinander im Inventar der bis
 *   zu sieben Helden der Gruppe unterzubringen (f_025c50), beginnend beim ersten Heldenplatz, bis die Stückzahl
 *   auf 0 reduziert ist oder kein Held mehr Platz hat.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie ein Zeiger auf den
 *   Gegenstandseintrag des Pools (short *).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Gegenstand vollständig aufgenommen wurde, und sonst 0.
 === Ende Beschreibung === */
int f_0aafe0(int p, short *p2)
{
    int r = 0;
    int fl = 0;
    short s1 = 0;
    short k = 0;
    int lc = I32(p, 8);
    int q = 0;
    while (r == 0 && fl == 0) {
        q = f_027080(lc);
        if (q != 0) {
            do {
                s1 = *p2;
                *p2 = f_025c50(q, (int)p2);
            } while (*p2 > 0 && *p2 != s1);
            if (*p2 == 0) {
                r = 1;
            } else {
                if (k >= 6) fl = 1;
                else { k++; lc = I32(p, k * 4 + 8); }
            }
        } else {
            fl = 1;
        }
    }
    return r;
}
//@ f_0ab080
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verarbeitet die Auswahl einer der sieben Heldenleisten (per Mausklick oder Zifferntaste
 *   1-7): Sie tauscht bei gesetztem Tastatur-Tauschflag (Offset +0x56) den ersten Helden mit dem gewählten Platz
 *   (f_0ab320), übergibt andernfalls einen am Cursor hängenden Gegenstand an diesen Helden (f_050e30) oder
 *   behandelt Klicks und Tauschaktionen auf der Heldenleiste (f_027750, f_0272d0).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Gruppenindex des
 *   Helden (0-6).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ab080(int p, short p2)
{
    short k = p2, s;
    int u, q;
#define U080 \
    d_1be26e = d_1be26c; \
    d_1be26c = 0; \
    { int z = p; \
      if (d_1be26e != d_1be26c && d_1be26e >= 0x8e && d_1be26e <= 0xc0) { \
        if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1); \
        f_0a9d90(z, d_1be26e, 0); f_0a9c90(z); d_1be26c = d_1be26e; \
      } }
    if (I32(p, 0x56) != 0) {
        I32(p, 0x56) = 0;
        f_0ab320(p, 0, k);
        U080
    } else {
        if ((short)f_050960(I32(p, 0x2c)) != 0) {
            q = p + k * 4;
            if (f_027070(I32(q, 8)) != 0) {
                u = f_027080(I32(q, 8));
                f_050e30(I32(p, 0x2c), u);
                f_051060(I32(p, 0x2c));
                f_027240(I32(q, 8));
                U080
            }
        } else {
            u = I32(p, 8 + k * 4);
            if (f_027070(u) != 0) {
                s = f_027750(u);
                if (k == s) f_0272d0(u);
                else f_0ab320(p, k, s);
            }
            U080
        }
    }
#undef U080
}
//@ f_0ab2e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wertet eine Interaktion auf der Heldenleiste mit Index p2 aus (f_027750) und schaltet
 *   entweder den Anzeigestatus desselben Helden um (f_0272d0) oder tauscht dessen Position mit dem Zielhelden
 *   (f_0ab320).
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) und der Gruppenindex des
 *   Helden (0-6).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ab2e0(int p, int p2)
{
    int u = I32(p, 8 + (short)p2 * 4);
    short s;
    if (f_027070(u) != 0) {
        s = f_027750(u);
        if ((short)p2 == s) {
            f_0272d0(u);
            return;
        }
        f_0ab320(p, (short)p2, s);
    }
}
//@ f_0ab320
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Tauscht im Gegenstandsverteilungs-Fenster die Positionen zweier Heldenleisten (p2 und p3),
 *   indem ihre zugeordneten Heldenzeiger, Inventar-Controller und Anzeigedaten über die
 *   Widget-Zugriffsfunktionen (f_027070 bis f_0270c0) kreuzweise ausgetauscht und beide Leisten sowie die
 *   Detailanzeige neu gezeichnet werden.
 * - Eingaben: Übergeben werden ein Zeiger auf die Verteilungsfenster-Struktur (this) sowie die beiden
 *   Gruppenindizes (p2, p3).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ab320(int p, short p2, int p3)
{
    int a, b, v1, v2, v3, v4;
    if ((short)p2 != (short)p3) {
        a = I32(p, 8 + (short)p2 * 4);
        b = I32(p, 8 + (short)p3 * 4);
        if (f_027070(a) != 0) {
            if (f_027070(b) != 0) {
                v1 = f_027070(a);
                v2 = f_027080(a);
                v3 = f_027090(a);
                v4 = f_027070(b);
                f_0270a0(a, v4);
                f_0270a0(b, v1);
                v1 = f_027080(b);
                f_0270b0(a, v1);
                f_0270b0(b, v2);
                v1 = f_027090(b);
                f_0270c0(a, v1);
                f_0270c0(b, v3);
                f_0270d0(b);
                f_0270d0(a);
                v1 = f_027080(I32(p, 8));
                f_050970(I32(p, 0x2c), v1);
                return;
            }
        }
        f_0272d0(a);
    }
}
//@ f_0ab400
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Führt den Dialog zum Tauschen zweier Heldenplätze aus: Sind genau zwei Helden in der Gruppe,
 *   werden die Plätze 0 und 1 direkt getauscht; bei mehr als zwei Helden wählt der Spieler über zwei
 *   Auswahl-Popups (f_0ab550 mit den Texten 0x20000038 und 0x20000039) den ersten und zweiten Helden für
 *   f_0ab320 aus.
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ab400(int p)
{
    short s1 = 0, s2;
    int c = p;
    for (s2 = 0; s2 < 7; s2++) {
        if (f_027070(I32(c, 8 + s2 * 4))) s1++;
    }
    s2 = -1;
    if (1 < s1) {
        if (s1 == 2) {
            s2 = 1;
            s1 = 0;
        } else {
            s1 = f_0ab550(p, 0x20000038);
            if (s1 != -1) s2 = f_0ab550(p, 0x20000039);
        }
        if (s1 != -1 && s2 != -1) f_0ab320(p, s1, s2);
    }
    d_1be26e = d_1be26c;
    d_1be26c = 0;
    c = p;
    if (d_1be26e != d_1be26c) {
        if (d_1be26e >= 0x8e && d_1be26e <= 0xc0) {
            if (d_1be26c >= 0x8e && d_1be26c <= 0xc0) f_0a9d90(p, d_1be26c, 1);
            f_0a9d90(c, d_1be26e, 0);
            f_0a9c90(c);
            d_1be26c = d_1be26e;
        }
    }
}
//@ f_0ab520
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Zählt, wie viele der sieben Heldenplätze im Gegenstandsverteilungs-Fenster derzeit
 *   tatsächlich mit einem Gruppenmitglied belegt sind (f_027070 != 0).
 * - Eingaben: Übergeben wird ein Zeiger auf die Verteilungsfenster-Struktur (this).
 * - Rückgabewert: Die Funktion gibt die Anzahl der belegten Heldenplätze (0-7) zurück.
 === Ende Beschreibung === */
int f_0ab520(int p)
{
    int n = 0;
    short k;
    for (k = 0; k < 7; k++) {
        if (f_027070(I32(p, 8 + k * 4)) != 0) n = n + 1;
    }
    return n;
}
