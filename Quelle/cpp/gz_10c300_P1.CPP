/* === Beschreibung (Katalog) ===
 * Einheit gz_10c300 (10c300 - 10d6b0)
 *
 * Überblick
 *
 * Die Einheit gz_10c300 enthält die große statische Initialisierungsfunktion (f_10c300) für die
 * Zauberspruch-Sprungtabelle (d_1c042c bis d_1c0830), welche die 85 Zauber-Handler-Funktionen (f_10d6b0 bis
 * f_10dbf0) in das globale Zauber-Methodenarray einträgt.
 === Ende Beschreibung === */
// P1 0/1 gleich
// gz_10c300.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x10C300-0x10CAE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
typedef int W;
void f_10dbf0(void);
void f_10dbe0(void);
void f_10dbd0(void);
void f_10dbc0(void);
void f_10dbb0(void);
void f_10dba0(void);
void f_10db90(void);
void f_10db80(void);
void f_10db70(void);
void f_10db50(void);
void f_10db60(void);
void f_10db40(void);
void f_10db30(void);
void f_10db20(void);
void f_10db10(void);
void f_10db00(void);
void f_10dae0(void);
void f_10daf0(void);
void f_10dad0(void);
void f_10dac0(void);
void f_10dab0(void);
void f_10daa0(void);
void f_10da90(void);
void f_10da60(void);
void f_10da80(void);
void f_10da70(void);
void f_10da50(void);
void f_10d9f0(void);
void f_10da10(void);
void f_10da40(void);
void f_10da30(void);
void f_10da20(void);
void f_10da00(void);
void f_10d9a0(void);
void f_10d9e0(void);
void f_10d9c0(void);
void f_10d9b0(void);
void f_10d990(void);
void f_10d9d0(void);
void f_10d980(void);
void f_10d970(void);
void f_10d960(void);
void f_10d950(void);
void f_10d940(void);
void f_10d930(void);
void f_10d920(void);
void f_10d910(void);
void f_10d900(void);
void f_10d8f0(void);
void f_10d8e0(void);
void f_10d8d0(void);
void f_10d8c0(void);
void f_10d8b0(void);
void f_10d8a0(void);
void f_10d890(void);
void f_10d870(void);
void f_10d860(void);
void f_10d850(void);
void f_10d880(void);
void f_10d840(void);
void f_10d820(void);
void f_10d810(void);
void f_10d800(void);
void f_10d830(void);
void f_10d7f0(void);
void f_10d7e0(void);
void f_10d7d0(void);
void f_10d7c0(void);
void f_10d7b0(void);
void f_10d7a0(void);
void f_10d790(void);
void f_10d780(void);
void f_10d770(void);
void f_10d760(void);
void f_10d730(void);
void f_10d720(void);
void f_10d710(void);
void f_10d750(void);
void f_10d740(void);
void f_10d700(void);
void f_10d6e0(void);
void f_10d6d0(void);
void f_10d6c0(void);
void f_10d6f0(void);
void f_10d6b0(void);
extern W d_1c042c;                    // 0x1C042C
extern W d_1c0430;                    // 0x1C0430
extern W d_1c0434;                    // 0x1C0434
extern W d_1c0438;                    // 0x1C0438
extern W d_1c043c;                    // 0x1C043C
extern W d_1c0440;                    // 0x1C0440
extern W d_1c0444;                    // 0x1C0444
extern W d_1c0448;                    // 0x1C0448
extern W d_1c044c;                    // 0x1C044C
extern W d_1c0450;                    // 0x1C0450
extern W d_1c0454;                    // 0x1C0454
extern W d_1c0458;                    // 0x1C0458
extern W d_1c045c;                    // 0x1C045C
extern W d_1c0460;                    // 0x1C0460
extern W d_1c0464;                    // 0x1C0464
extern W d_1c0468;                    // 0x1C0468
extern W d_1c046c;                    // 0x1C046C
extern W d_1c0470;                    // 0x1C0470
extern W d_1c0474;                    // 0x1C0474
extern W d_1c0478;                    // 0x1C0478
extern W d_1c047c;                    // 0x1C047C
extern W d_1c0480;                    // 0x1C0480
extern W d_1c0484;                    // 0x1C0484
extern W d_1c0488;                    // 0x1C0488
extern W d_1c048c;                    // 0x1C048C
extern W d_1c0490;                    // 0x1C0490
extern W d_1c0494;                    // 0x1C0494
extern W d_1c0498;                    // 0x1C0498
extern W d_1c049c;                    // 0x1C049C
extern W d_1c04a0;                    // 0x1C04A0
extern W d_1c04a4;                    // 0x1C04A4
extern W d_1c04a8;                    // 0x1C04A8
extern W d_1c04ac;                    // 0x1C04AC
extern W d_1c04b0;                    // 0x1C04B0
extern W d_1c04b4;                    // 0x1C04B4
extern W d_1c04b8;                    // 0x1C04B8
extern W d_1c04bc;                    // 0x1C04BC
extern W d_1c04c0;                    // 0x1C04C0
extern W d_1c04c4;                    // 0x1C04C4
extern W d_1c04c8;                    // 0x1C04C8
extern W d_1c04cc;                    // 0x1C04CC
extern W d_1c04d0;                    // 0x1C04D0
extern W d_1c04d4;                    // 0x1C04D4
extern W d_1c04d8;                    // 0x1C04D8
extern W d_1c04dc;                    // 0x1C04DC
extern W d_1c04e0;                    // 0x1C04E0
extern W d_1c04e4;                    // 0x1C04E4
extern W d_1c04e8;                    // 0x1C04E8
extern W d_1c04ec;                    // 0x1C04EC
extern W d_1c04f0;                    // 0x1C04F0
extern W d_1c04f4;                    // 0x1C04F4
extern W d_1c04f8;                    // 0x1C04F8
extern W d_1c04fc;                    // 0x1C04FC
extern W d_1c0500;                    // 0x1C0500
extern W d_1c0504;                    // 0x1C0504
extern W d_1c0508;                    // 0x1C0508
extern W d_1c050c;                    // 0x1C050C
extern W d_1c0510;                    // 0x1C0510
extern W d_1c0514;                    // 0x1C0514
extern W d_1c0518;                    // 0x1C0518
extern W d_1c051c;                    // 0x1C051C
extern W d_1c0520;                    // 0x1C0520
extern W d_1c0524;                    // 0x1C0524
extern W d_1c0528;                    // 0x1C0528
extern W d_1c052c;                    // 0x1C052C
extern W d_1c0530;                    // 0x1C0530
extern W d_1c0534;                    // 0x1C0534
extern W d_1c0538;                    // 0x1C0538
extern W d_1c053c;                    // 0x1C053C
extern W d_1c0540;                    // 0x1C0540
extern W d_1c0544;                    // 0x1C0544
extern W d_1c0548;                    // 0x1C0548
extern W d_1c054c;                    // 0x1C054C
extern W d_1c0550;                    // 0x1C0550
extern W d_1c0554;                    // 0x1C0554
extern W d_1c0558;                    // 0x1C0558
extern W d_1c055c;                    // 0x1C055C
extern W d_1c0560;                    // 0x1C0560
extern W d_1c0564;                    // 0x1C0564
extern W d_1c0568;                    // 0x1C0568
extern W d_1c056c;                    // 0x1C056C
extern W d_1c0570;                    // 0x1C0570
extern W d_1c0574;                    // 0x1C0574
extern W d_1c0578;                    // 0x1C0578
extern W d_1c057c;                    // 0x1C057C
extern W d_1c0580;                    // 0x1C0580
extern W d_1c0584;                    // 0x1C0584
extern W d_1c0588;                    // 0x1C0588
extern W d_1c058c;                    // 0x1C058C
extern W d_1c0590;                    // 0x1C0590
extern W d_1c0594;                    // 0x1C0594
extern W d_1c0598;                    // 0x1C0598
extern W d_1c059c;                    // 0x1C059C
extern W d_1c05a0;                    // 0x1C05A0
extern W d_1c05a4;                    // 0x1C05A4
extern W d_1c05a8;                    // 0x1C05A8
extern W d_1c05ac;                    // 0x1C05AC
extern W d_1c05b0;                    // 0x1C05B0
extern W d_1c05b4;                    // 0x1C05B4
extern W d_1c05b8;                    // 0x1C05B8
extern W d_1c05bc;                    // 0x1C05BC
extern W d_1c05c0;                    // 0x1C05C0
extern W d_1c05c4;                    // 0x1C05C4
extern W d_1c05c8;                    // 0x1C05C8
extern W d_1c05cc;                    // 0x1C05CC
extern W d_1c05d0;                    // 0x1C05D0
extern W d_1c05d4;                    // 0x1C05D4
extern W d_1c05d8;                    // 0x1C05D8
extern W d_1c05dc;                    // 0x1C05DC
extern W d_1c05e0;                    // 0x1C05E0
extern W d_1c05e4;                    // 0x1C05E4
extern W d_1c05e8;                    // 0x1C05E8
extern W d_1c05ec;                    // 0x1C05EC
extern W d_1c05f0;                    // 0x1C05F0
extern W d_1c05f4;                    // 0x1C05F4
extern W d_1c05f8;                    // 0x1C05F8
extern W d_1c05fc;                    // 0x1C05FC
extern W d_1c0600;                    // 0x1C0600
extern W d_1c0604;                    // 0x1C0604
extern W d_1c0608;                    // 0x1C0608
extern W d_1c060c;                    // 0x1C060C
extern W d_1c0610;                    // 0x1C0610
extern W d_1c0614;                    // 0x1C0614
extern W d_1c0618;                    // 0x1C0618
extern W d_1c061c;                    // 0x1C061C
extern W d_1c0620;                    // 0x1C0620
extern W d_1c0624;                    // 0x1C0624
extern W d_1c0628;                    // 0x1C0628
extern W d_1c062c;                    // 0x1C062C
extern W d_1c0630;                    // 0x1C0630
extern W d_1c0634;                    // 0x1C0634
extern W d_1c0638;                    // 0x1C0638
extern W d_1c063c;                    // 0x1C063C
extern W d_1c0640;                    // 0x1C0640
extern W d_1c0644;                    // 0x1C0644
extern W d_1c0648;                    // 0x1C0648
extern W d_1c064c;                    // 0x1C064C
extern W d_1c0650;                    // 0x1C0650
extern W d_1c0654;                    // 0x1C0654
extern W d_1c0658;                    // 0x1C0658
extern W d_1c065c;                    // 0x1C065C
extern W d_1c0660;                    // 0x1C0660
extern W d_1c0664;                    // 0x1C0664
extern W d_1c0668;                    // 0x1C0668
extern W d_1c066c;                    // 0x1C066C
extern W d_1c0670;                    // 0x1C0670
extern W d_1c0674;                    // 0x1C0674
extern W d_1c0678;                    // 0x1C0678
extern W d_1c067c;                    // 0x1C067C
extern W d_1c0680;                    // 0x1C0680
extern W d_1c0684;                    // 0x1C0684
extern W d_1c0688;                    // 0x1C0688
extern W d_1c068c;                    // 0x1C068C
extern W d_1c0690;                    // 0x1C0690
extern W d_1c0694;                    // 0x1C0694
extern W d_1c0698;                    // 0x1C0698
extern W d_1c069c;                    // 0x1C069C
extern W d_1c06a0;                    // 0x1C06A0
extern W d_1c06a4;                    // 0x1C06A4
extern W d_1c06a8;                    // 0x1C06A8
extern W d_1c06ac;                    // 0x1C06AC
extern W d_1c06b0;                    // 0x1C06B0
extern W d_1c06b4;                    // 0x1C06B4
extern W d_1c06b8;                    // 0x1C06B8
extern W d_1c06bc;                    // 0x1C06BC
extern W d_1c06c0;                    // 0x1C06C0
extern W d_1c06c4;                    // 0x1C06C4
extern W d_1c06c8;                    // 0x1C06C8
extern W d_1c06cc;                    // 0x1C06CC
extern W d_1c06d0;                    // 0x1C06D0
extern W d_1c06d4;                    // 0x1C06D4
extern W d_1c06d8;                    // 0x1C06D8
extern W d_1c06dc;                    // 0x1C06DC
extern W d_1c06e0;                    // 0x1C06E0
extern W d_1c06e4;                    // 0x1C06E4
extern W d_1c06e8;                    // 0x1C06E8
extern W d_1c06ec;                    // 0x1C06EC
extern W d_1c06f0;                    // 0x1C06F0
extern W d_1c06f4;                    // 0x1C06F4
extern W d_1c06f8;                    // 0x1C06F8
extern W d_1c06fc;                    // 0x1C06FC
extern W d_1c0700;                    // 0x1C0700
extern W d_1c0704;                    // 0x1C0704
extern W d_1c0708;                    // 0x1C0708
extern W d_1c070c;                    // 0x1C070C
extern W d_1c0710;                    // 0x1C0710
extern W d_1c0714;                    // 0x1C0714
extern W d_1c0718;                    // 0x1C0718
extern W d_1c071c;                    // 0x1C071C
extern W d_1c0720;                    // 0x1C0720
extern W d_1c0724;                    // 0x1C0724
extern W d_1c0728;                    // 0x1C0728
extern W d_1c072c;                    // 0x1C072C
extern W d_1c0730;                    // 0x1C0730
extern W d_1c0734;                    // 0x1C0734
extern W d_1c0738;                    // 0x1C0738
extern W d_1c073c;                    // 0x1C073C
extern W d_1c0740;                    // 0x1C0740
extern W d_1c0744;                    // 0x1C0744
extern W d_1c0748;                    // 0x1C0748
extern W d_1c074c;                    // 0x1C074C
extern W d_1c0750;                    // 0x1C0750
extern W d_1c0754;                    // 0x1C0754
extern W d_1c0758;                    // 0x1C0758
extern W d_1c075c;                    // 0x1C075C
extern W d_1c0760;                    // 0x1C0760
extern W d_1c0764;                    // 0x1C0764
extern W d_1c0768;                    // 0x1C0768
extern W d_1c076c;                    // 0x1C076C
extern W d_1c0770;                    // 0x1C0770
extern W d_1c0774;                    // 0x1C0774
extern W d_1c0778;                    // 0x1C0778
extern W d_1c077c;                    // 0x1C077C
extern W d_1c0780;                    // 0x1C0780
extern W d_1c0784;                    // 0x1C0784
extern W d_1c0788;                    // 0x1C0788
extern W d_1c078c;                    // 0x1C078C
extern W d_1c0790;                    // 0x1C0790
extern W d_1c0794;                    // 0x1C0794
extern W d_1c0798;                    // 0x1C0798
extern W d_1c079c;                    // 0x1C079C
extern W d_1c07a0;                    // 0x1C07A0
extern W d_1c07a4;                    // 0x1C07A4
extern W d_1c07a8;                    // 0x1C07A8
extern W d_1c07ac;                    // 0x1C07AC
extern W d_1c07b0;                    // 0x1C07B0
extern W d_1c07b4;                    // 0x1C07B4
extern W d_1c07b8;                    // 0x1C07B8
extern W d_1c07bc;                    // 0x1C07BC
extern W d_1c07c0;                    // 0x1C07C0
extern W d_1c07c4;                    // 0x1C07C4
extern W d_1c07c8;                    // 0x1C07C8
extern W d_1c07cc;                    // 0x1C07CC
extern W d_1c07d0;                    // 0x1C07D0
extern W d_1c07d4;                    // 0x1C07D4
extern W d_1c07d8;                    // 0x1C07D8
extern W d_1c07dc;                    // 0x1C07DC
extern W d_1c07e0;                    // 0x1C07E0
extern W d_1c07e4;                    // 0x1C07E4
extern W d_1c07e8;                    // 0x1C07E8
extern W d_1c07ec;                    // 0x1C07EC
extern W d_1c07f0;                    // 0x1C07F0
extern W d_1c07f4;                    // 0x1C07F4
extern W d_1c07f8;                    // 0x1C07F8
extern W d_1c07fc;                    // 0x1C07FC
extern W d_1c0800;                    // 0x1C0800
extern W d_1c0804;                    // 0x1C0804
extern W d_1c0808;                    // 0x1C0808
extern W d_1c080c;                    // 0x1C080C
extern W d_1c0810;                    // 0x1C0810
extern W d_1c0814;                    // 0x1C0814
extern W d_1c0818;                    // 0x1C0818
extern W d_1c081c;                    // 0x1C081C
extern W d_1c0820;                    // 0x1C0820
extern W d_1c0824;                    // 0x1C0824
extern W d_1c0828;                    // 0x1C0828
extern W d_1c082c;                    // 0x1C082C
extern W d_1c0830;                    // 0x1C0830
//@ f_10c300
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsroutine belegt beim Programmstart das globale Array von 85 jeweils 12 Byte
 *   großen Methodenzeiger-Einträgen (d_1c042c bis d_1c0830) mit den Funktionszeigern der einzelnen
 *   Zauberspruch-Handler (f_10dbf0 abwärts bis f_10d6b0, definiert in gz_10d6b0_t1), über die das Magiesystem in
 *   spell3 die Wirkung jedes einzelnen DSA-Zaubers aufruft.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10c300(void)
{
    int p0 = (int)f_10dbf0;
    int p1 = (int)f_10dbe0;
    int p2 = (int)f_10dbd0;
    int p3 = (int)f_10dbc0;
    int p4 = (int)f_10dbb0;
    int p5 = (int)f_10dba0;
    int p6 = (int)f_10db90;
    int p7 = (int)f_10db80;
    int p8 = (int)f_10db70;
    int p9 = (int)f_10db60;
    int p10 = (int)f_10db50;
    int p11 = (int)f_10db40;
    int p12 = (int)f_10db30;
    int p13 = (int)f_10db20;
    int p14 = (int)f_10db10;
    int p15 = (int)f_10db00;
    d_1c042c = 0;
    d_1c0430 = 0;
    d_1c0434 = 0;
    d_1c0438 = p0;
    d_1c043c = 0;
    d_1c0440 = 0;
    d_1c0444 = p1;
    d_1c0448 = 0;
    d_1c044c = 0;
    d_1c0450 = p2;
    d_1c0454 = 0;
    d_1c0458 = 0;
    d_1c045c = p3;
    d_1c0460 = 0;
    d_1c0464 = 0;
    d_1c0468 = p4;
    d_1c046c = 0;
    d_1c0470 = 0;
    d_1c0474 = p5;
    d_1c0478 = 0;
    d_1c047c = 0;
    d_1c0480 = p6;
    d_1c0484 = 0;
    d_1c0488 = 0;
    d_1c048c = p7;
    d_1c0490 = 0;
    d_1c0494 = 0;
    d_1c0498 = p8;
    d_1c049c = 0;
    d_1c04a0 = 0;
    d_1c04a4 = p9;
    d_1c04a8 = 0;
    d_1c04ac = 0;
    d_1c04b0 = p10;
    d_1c04b4 = 0;
    d_1c04b8 = 0;
    d_1c04bc = p11;
    d_1c04c0 = 0;
    d_1c04c4 = 0;
    d_1c04c8 = p12;
    d_1c04cc = 0;
    d_1c04d0 = 0;
    d_1c04d4 = p13;
    d_1c04d8 = 0;
    d_1c04dc = 0;
    d_1c04e0 = p14;
    d_1c04e4 = 0;
    d_1c04e8 = 0;
    d_1c04ec = p15;
    d_1c04f0 = 0;
    d_1c04f4 = 0;
    d_1c04f8 = (int)f_10daf0;
    d_1c04fc = 0;
    d_1c0500 = 0;
    d_1c0504 = (int)f_10dae0;
    d_1c0508 = 0;
    d_1c050c = 0;
    d_1c0510 = (int)f_10dad0;
    d_1c0514 = 0;
    d_1c0518 = 0;
    int q0 = (int)f_10dac0;
    int q1 = (int)f_10dab0;
    int q2 = (int)f_10daa0;
    int q3 = (int)f_10da90;
    int q4 = (int)f_10da80;
    int q5 = (int)f_10da70;
    int q6 = (int)f_10da60;
    int q7 = (int)f_10da50;
    int q8 = (int)f_10da40;
    int q9 = (int)f_10da30;
    int q10 = (int)f_10da20;
    int q11 = (int)f_10da10;
    int q12 = (int)f_10da00;
    int q13 = (int)f_10d9f0;
    int q14 = (int)f_10d9e0;
    int q15 = (int)f_10d9d0;
    d_1c051c = q0;
    d_1c0520 = 0;
    d_1c0524 = 0;
    d_1c0528 = q1;
    d_1c052c = 0;
    d_1c0530 = 0;
    d_1c0534 = q2;
    d_1c0538 = 0;
    d_1c053c = 0;
    d_1c0540 = q3;
    d_1c0544 = 0;
    d_1c0548 = 0;
    d_1c054c = q4;
    d_1c0550 = 0;
    d_1c0554 = 0;
    d_1c0558 = q5;
    d_1c055c = 0;
    d_1c0560 = 0;
    d_1c0564 = q6;
    d_1c0568 = 0;
    d_1c056c = 0;
    d_1c0570 = q7;
    d_1c0574 = 0;
    d_1c0578 = 0;
    d_1c057c = q8;
    d_1c0580 = 0;
    d_1c0584 = 0;
    d_1c0588 = q9;
    d_1c058c = 0;
    d_1c0590 = 0;
    d_1c0594 = q10;
    d_1c0598 = 0;
    d_1c059c = 0;
    d_1c05a0 = q11;
    d_1c05a4 = 0;
    d_1c05a8 = 0;
    d_1c05ac = q12;
    d_1c05b0 = 0;
    d_1c05b4 = 0;
    d_1c05b8 = q13;
    d_1c05bc = 0;
    d_1c05c0 = 0;
    d_1c05c4 = q14;
    d_1c05c8 = 0;
    d_1c05cc = 0;
    d_1c05d0 = q15;
    d_1c05d4 = 0;
    d_1c05d8 = 0;
    d_1c05dc = (int)f_10d9c0;
    d_1c05e0 = 0;
    d_1c05e4 = 0;
    d_1c05e8 = (int)f_10d9b0;
    d_1c05ec = 0;
    d_1c05f0 = 0;
    d_1c05f4 = (int)f_10d9a0;
    d_1c05f8 = 0;
    d_1c05fc = 0;
    d_1c0600 = (int)f_10d990;
    d_1c0604 = 0;
    d_1c0608 = 0;
    int r0 = (int)f_10d980;
    int r1 = (int)f_10d970;
    int r2 = (int)f_10d960;
    int r3 = (int)f_10d950;
    int r4 = (int)f_10d940;
    int r5 = (int)f_10d930;
    int r6 = (int)f_10d920;
    int r7 = (int)f_10d910;
    int r8 = (int)f_10d900;
    int r9 = (int)f_10d8f0;
    int r10 = (int)f_10d8e0;
    int r11 = (int)f_10d8d0;
    int r12 = (int)f_10d8c0;
    int r13 = (int)f_10d8b0;
    int r14 = (int)f_10d8a0;
    int r15 = (int)f_10d890;
    d_1c060c = r0;
    d_1c0610 = 0;
    d_1c0614 = 0;
    d_1c0618 = r1;
    d_1c061c = 0;
    d_1c0620 = 0;
    d_1c0624 = r2;
    d_1c0628 = 0;
    d_1c062c = 0;
    d_1c0630 = r3;
    d_1c0634 = 0;
    d_1c0638 = 0;
    d_1c063c = r4;
    d_1c0640 = 0;
    d_1c0644 = 0;
    d_1c0648 = r5;
    d_1c064c = 0;
    d_1c0650 = 0;
    d_1c0654 = r6;
    d_1c0658 = 0;
    d_1c065c = 0;
    d_1c0660 = r7;
    d_1c0664 = 0;
    d_1c0668 = 0;
    d_1c066c = r8;
    d_1c0670 = 0;
    d_1c0674 = 0;
    d_1c0678 = r9;
    d_1c067c = 0;
    d_1c0680 = 0;
    d_1c0684 = r10;
    d_1c0688 = 0;
    d_1c068c = 0;
    d_1c0690 = r11;
    d_1c0694 = 0;
    d_1c0698 = 0;
    d_1c069c = r12;
    d_1c06a0 = 0;
    d_1c06a4 = 0;
    d_1c06a8 = r13;
    d_1c06ac = 0;
    d_1c06b0 = 0;
    d_1c06b4 = r14;
    d_1c06b8 = 0;
    d_1c06bc = 0;
    d_1c06c0 = r15;
    d_1c06c4 = 0;
    d_1c06c8 = 0;
    d_1c06cc = (int)f_10d880;
    d_1c06d0 = 0;
    d_1c06d4 = 0;
    d_1c06d8 = (int)f_10d870;
    d_1c06dc = 0;
    d_1c06e0 = 0;
    d_1c06e4 = (int)f_10d860;
    d_1c06e8 = 0;
    d_1c06ec = 0;
    d_1c06f0 = (int)f_10d850;
    d_1c06f4 = 0;
    d_1c06f8 = 0;
    int tail492_0_0=(int)f_10d840;
    int tail492_0_1=(int)f_10d830;
    int tail492_0_2=(int)f_10d820;
    int tail492_0_3=(int)f_10d810;
    int tail492_0_4=(int)f_10d800;
    int tail492_0_5=(int)f_10d7f0;
    int tail492_0_6=(int)f_10d7e0;
    int tail492_0_7=(int)f_10d7d0;
    int tail492_0_8=(int)f_10d7c0;
    int tail492_0_9=(int)f_10d7b0;
    int tail492_0_10=(int)f_10d7a0;
    int tail492_0_11=(int)f_10d790;
    int tail492_0_12=(int)f_10d780;
    int tail492_0_13=(int)f_10d770;
    int tail492_0_14=(int)f_10d760;
    int tail492_0_15=(int)f_10d750;
    d_1c06fc = tail492_0_0;
    d_1c0700 = 0;
    d_1c0704 = 0;
    d_1c0708 = tail492_0_1;
    d_1c070c = 0;
    d_1c0710 = 0;
    d_1c0714 = tail492_0_2;
    d_1c0718 = 0;
    d_1c071c = 0;
    d_1c0720 = tail492_0_3;
    d_1c0724 = 0;
    d_1c0728 = 0;
    d_1c072c = tail492_0_4;
    d_1c0730 = 0;
    d_1c0734 = 0;
    d_1c0738 = tail492_0_5;
    d_1c073c = 0;
    d_1c0740 = 0;
    d_1c0744 = tail492_0_6;
    d_1c0748 = 0;
    d_1c074c = 0;
    d_1c0750 = tail492_0_7;
    d_1c0754 = 0;
    d_1c0758 = 0;
    d_1c075c = tail492_0_8;
    d_1c0760 = 0;
    d_1c0764 = 0;
    d_1c0768 = tail492_0_9;
    d_1c076c = 0;
    d_1c0770 = 0;
    d_1c0774 = tail492_0_10;
    d_1c0778 = 0;
    d_1c077c = 0;
    d_1c0780 = tail492_0_11;
    d_1c0784 = 0;
    d_1c0788 = 0;
    d_1c078c = tail492_0_12;
    d_1c0790 = 0;
    d_1c0794 = 0;
    d_1c0798 = tail492_0_13;
    d_1c079c = 0;
    d_1c07a0 = 0;
    d_1c07a4 = tail492_0_14;
    d_1c07a8 = 0;
    d_1c07ac = 0;
    d_1c07b0 = tail492_0_15;
    d_1c07b4 = 0;
    d_1c07b8 = 0;
    d_1c07bc = (int)f_10d740;
    d_1c07c0 = 0;
    d_1c07c4 = 0;
    d_1c07c8 = (int)f_10d730;
    d_1c07cc = 0;
    d_1c07d0 = 0;
    d_1c07d4 = (int)f_10d720;
    d_1c07d8 = 0;
    d_1c07dc = 0;
    d_1c07e0 = (int)f_10d710;
    d_1c07e4 = 0;
    d_1c07e8 = 0;
    d_1c07ec = (int)f_10d700;
    d_1c07f0 = 0;
    d_1c07f4 = 0;
    d_1c07f8 = (int)f_10d6f0;
    d_1c07fc = 0;
    d_1c0800 = 0;
    d_1c0804 = (int)f_10d6e0;
    d_1c0808 = 0;
    d_1c080c = 0;
    d_1c0810 = (int)f_10d6d0;
    d_1c0814 = 0;
    d_1c0818 = 0;
    d_1c081c = (int)f_10d6c0;
    d_1c0820 = 0;
    d_1c0824 = 0;
    d_1c0828 = (int)f_10d6b0;
    d_1c082c = 0;
    d_1c0830 = 0;
}
