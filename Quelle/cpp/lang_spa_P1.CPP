/* === Beschreibung (Katalog) ===
 * Einheit lang_spa (0x0AE770 - 0x0AF1E0)
 *
 * Diese Einheit implementiert das Sprachmodul für Spanisch (p:\riva\source\cpp\lang_spa.cpp) mit Artikel-,
 * Relativpronomen-, Personalpronomen- und Possessivpronomen-Logik der mehrsprachigen Text-Engine.
 === Ende Beschreibung === */
// P3 3/8 gleich (suche.py 25.10.2026, Basis lang_spa_P1.CPP)
// lang_spa.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0AE770-0x0AF1E0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
unsigned short f_0b04e0(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a4ff4;                    // 0x1A4FF4
extern int d_1a4ff8;                    // 0x1A4FF8
extern int d_1a4ffc;                    // 0x1A4FFC
extern int d_1a5000;                    // 0x1A5000
extern int d_1a5010;                    // 0x1A5010
extern int d_1a5014;                    // 0x1A5014
extern int d_1a5018;                    // 0x1A5018
extern int d_1a5034;                    // 0x1A5034
extern int d_1a5038;                    // 0x1A5038
extern int d_1a5044;                    // 0x1A5044
extern int d_1a5058;                    // 0x1A5058
extern int d_1a505c;                    // 0x1A505C
extern int d_1a5060;                    // 0x1A5060
extern int d_1a5064;                    // 0x1A5064
extern int d_1a5080;                    // 0x1A5080
extern int d_1a5084;                    // 0x1A5084
extern int d_1a5088;                    // 0x1A5088
extern int d_1a508c;                    // 0x1A508C
extern int d_1a5090;                    // 0x1A5090
extern int d_1a5094;                    // 0x1A5094
extern int d_1a5098;                    // 0x1A5098
extern int d_1a509c;                    // 0x1A509C
extern int d_1a50a8;                    // 0x1A50A8
extern int d_1a50ac;                    // 0x1A50AC
extern int d_1a50b0;                    // 0x1A50B0
extern int d_1a50bc;                    // 0x1A50BC
extern int d_1a50cc;                    // 0x1A50CC
extern int d_1be858;                    // 0x1BE858
extern int d_1be85c;                    // 0x1BE85C
extern int d_1be860;                    // 0x1BE860
extern int d_1be864;                    // 0x1BE864
extern int d_1be868;                    // 0x1BE868
extern int d_1be86c;                    // 0x1BE86C
extern int d_1be870;                    // 0x1BE870
extern int d_1be874;                    // 0x1BE874
extern int d_1be878;                    // 0x1BE878
extern int d_1be87c;                    // 0x1BE87C
extern int d_1be880;                    // 0x1BE880
extern int d_1be884;                    // 0x1BE884
extern int d_1be888;                    // 0x1BE888
extern int d_1be88c;                    // 0x1BE88C
extern int d_1be890;                    // 0x1BE890
extern int d_1be894;                    // 0x1BE894
extern int d_1be898;                    // 0x1BE898
extern int d_1be89c;                    // 0x1BE89C
extern int d_1be8a0;                    // 0x1BE8A0
extern int d_1be8a4;                    // 0x1BE8A4
extern int d_1be8a8;                    // 0x1BE8A8
extern int d_1be8ac;                    // 0x1BE8AC
extern int d_1be8b0;                    // 0x1BE8B0
extern int d_1be8b4;                    // 0x1BE8B4
extern int d_1be8b8;                    // 0x1BE8B8
extern int d_1be8bc;                    // 0x1BE8BC
extern int d_1be8c0;                    // 0x1BE8C0
extern int d_1be8c4;                    // 0x1BE8C4
extern int d_1be8c8;                    // 0x1BE8C8
extern int d_1be8cc;                    // 0x1BE8CC
extern int d_1be8d0;                    // 0x1BE8D0
extern int d_1be8d4;                    // 0x1BE8D4
extern int d_1be8d8;                    // 0x1BE8D8
extern int d_1be8dc;                    // 0x1BE8DC
extern int d_1be8e0;                    // 0x1BE8E0
extern int d_1be8e4;                    // 0x1BE8E4
extern int d_1be8e8;                    // 0x1BE8E8
extern int d_1be8ec;                    // 0x1BE8EC
extern int d_1be8f0;                    // 0x1BE8F0
extern int d_1be8f4;                    // 0x1BE8F4
extern int d_1be8f8;                    // 0x1BE8F8
extern int d_1be8fc;                    // 0x1BE8FC
extern int d_1be900;                    // 0x1BE900
extern int d_1be904;                    // 0x1BE904
extern int d_1be908;                    // 0x1BE908
extern int d_1be90c;                    // 0x1BE90C
extern int d_1be910;                    // 0x1BE910
extern int d_1be914;                    // 0x1BE914
extern int d_1be918;                    // 0x1BE918
extern int d_1be91c;                    // 0x1BE91C
extern int d_1be920;                    // 0x1BE920
extern int d_1be924;                    // 0x1BE924
extern int d_1be928;                    // 0x1BE928
extern int d_1be92c;                    // 0x1BE92C
extern int d_1be930;                    // 0x1BE930
extern int d_1be934;                    // 0x1BE934
extern int d_1be938;                    // 0x1BE938
extern int d_1be93c;                    // 0x1BE93C
extern int d_1be940;                    // 0x1BE940
extern int d_1be944;                    // 0x1BE944
extern int d_1be948;                    // 0x1BE948
extern int d_1be94c;                    // 0x1BE94C
extern int d_1be950;                    // 0x1BE950
extern int d_1be954;                    // 0x1BE954
extern int d_1be958;                    // 0x1BE958
extern int d_1be95c;                    // 0x1BE95C
extern int d_1be960;                    // 0x1BE960
extern int d_1be964;                    // 0x1BE964
extern int d_1be968;                    // 0x1BE968
extern int d_1be96c;                    // 0x1BE96C
extern int d_1be970;                    // 0x1BE970
extern int d_1be974;                    // 0x1BE974
extern int d_1be978;                    // 0x1BE978
extern int d_1be97c;                    // 0x1BE97C
extern int d_1be980;                    // 0x1BE980
extern int d_1be984;                    // 0x1BE984
extern int d_1be988;                    // 0x1BE988
extern int d_1be98c;                    // 0x1BE98C
extern int d_1be990;                    // 0x1BE990
extern int d_1be994;                    // 0x1BE994
extern int d_1be998;                    // 0x1BE998
extern int d_1be99c;                    // 0x1BE99C
extern int d_1be9a0;                    // 0x1BE9A0
extern int d_1be9a4;                    // 0x1BE9A4
extern int d_1be9a8;                    // 0x1BE9A8
extern int d_1be9ac;                    // 0x1BE9AC
extern int d_1be9b0;                    // 0x1BE9B0
extern int d_1be9b4;                    // 0x1BE9B4
extern int d_1be9b8;                    // 0x1BE9B8
extern int d_1be9bc;                    // 0x1BE9BC
extern int d_1be9c0;                    // 0x1BE9C0
extern int d_1be9c4;                    // 0x1BE9C4
extern int d_1be9c8;                    // 0x1BE9C8
extern int d_1be9cc;                    // 0x1BE9CC
extern int d_1be9d0;                    // 0x1BE9D0
extern int d_1be9d4;                    // 0x1BE9D4
extern int d_1be9d8;                    // 0x1BE9D8
extern int d_1be9dc;                    // 0x1BE9DC
extern int d_1be9e0;                    // 0x1BE9E0
extern int d_1be9e4;                    // 0x1BE9E4
extern int d_1be9e8;                    // 0x1BE9E8
extern int d_1be9ec;                    // 0x1BE9EC
extern int d_1be9f0;                    // 0x1BE9F0
extern int d_1be9f4;                    // 0x1BE9F4
extern int d_1be9f8;                    // 0x1BE9F8
extern int d_1be9fc;                    // 0x1BE9FC
extern int d_1bea00;                    // 0x1BEA00
extern int d_1bea04;                    // 0x1BEA04
extern int d_1bea08;                    // 0x1BEA08
extern int d_1bea0c;                    // 0x1BEA0C
extern int d_1bea10;                    // 0x1BEA10
extern int d_1bea14;                    // 0x1BEA14
extern int d_1bea18;                    // 0x1BEA18
extern int d_1bea1c;                    // 0x1BEA1C
extern int d_1bea20;                    // 0x1BEA20
extern int d_1bea24;                    // 0x1BEA24
extern int d_1bea28;                    // 0x1BEA28
extern int d_1bea2c;                    // 0x1BEA2C
extern int d_1bea30;                    // 0x1BEA30
extern int d_1bea34;                    // 0x1BEA34
extern int d_1bea38;                    // 0x1BEA38
extern int d_1bea3c;                    // 0x1BEA3C
extern int d_1bea40;                    // 0x1BEA40
extern int d_1bea44;                    // 0x1BEA44
extern int d_1bea48;                    // 0x1BEA48
extern int d_1bea4c;                    // 0x1BEA4C
extern int d_1bea50;                    // 0x1BEA50
extern int d_1bea54;                    // 0x1BEA54
extern int d_1bea58;                    // 0x1BEA58
extern int d_1bea5c;                    // 0x1BEA5C
extern int d_1bea60;                    // 0x1BEA60
extern int d_1bea64;                    // 0x1BEA64
extern int d_1bea68;                    // 0x1BEA68
extern int d_1bea6c;                    // 0x1BEA6C
extern int d_1bea70;                    // 0x1BEA70
extern int d_1bea74;                    // 0x1BEA74
extern int d_1bea78;                    // 0x1BEA78
extern int d_1bea7c;                    // 0x1BEA7C
extern int d_1bea80;                    // 0x1BEA80
extern int d_1bea84;                    // 0x1BEA84
extern int d_1bea88;                    // 0x1BEA88
extern int d_1bea8c;                    // 0x1BEA8C
extern int d_1bea90;                    // 0x1BEA90
extern int d_1bea94;                    // 0x1BEA94
extern int d_1bea98;                    // 0x1BEA98
extern int d_1bea9c;                    // 0x1BEA9C
extern int d_1beaa0;                    // 0x1BEAA0
extern int d_1beaa4;                    // 0x1BEAA4
extern int d_1beaa8;                    // 0x1BEAA8
extern int d_1beaac;                    // 0x1BEAAC
extern int d_1beab0;                    // 0x1BEAB0
extern int d_1beab4;                    // 0x1BEAB4
extern int d_1beab8;                    // 0x1BEAB8
extern int d_1beabc;                    // 0x1BEABC
extern int d_1beac0;                    // 0x1BEAC0
extern int d_1beac4;                    // 0x1BEAC4
extern int d_1beac8;                    // 0x1BEAC8
extern int d_1beacc;                    // 0x1BEACC
extern int d_1bead0;                    // 0x1BEAD0
extern const char d_1a4fd4[];           // Text 0x1A4FD4
// --- eigene Funktionen (8), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

extern int d_1a5004;
extern int d_1a5008;
extern int d_1a500c;
extern int d_1a501c;
extern int d_1a5020;
extern int d_1a5024;
extern int d_1a5028;
extern int d_1a502c;
extern int d_1a5030;
extern int d_1a503c;
extern int d_1a5040;
extern int d_1a5048;
extern int d_1a504c;
extern int d_1a5050;
extern int d_1a5068;
extern int d_1a506c;
extern int d_1a5070;
extern int d_1a5074;
extern int d_1a5078;
extern int d_1a507c;
extern int d_1a50a0;
extern int d_1a50a4;
extern int d_1a50b4;
extern int d_1a50b8;
extern int d_1a50c0;
extern const char d_1b7ff0[];
extern const char d_1b7fec[];
extern const char d_1b7fee[];
void f_145300(void *p, int v, int n);
struct BF16 { unsigned short a:2, k:3, c:3, h:3; };
struct BF8 { unsigned char a:2, h:2, c:4; };
#define A01(x) ((unsigned char)(x) & 3)
#define TB(base,k,h,a) *(char **)((char *)&base + (a)*4 + ((k) + (h)*4)*0xc)
#define PREP(kx,hx) unsigned char h = hx; h <<= 4; h >>= 6; kx <<= 3; kx >>= 5; unsigned char &k = kx;
#define PREP2(kx,hx) unsigned char h = hx; h <<= 4; h >>= 6; unsigned char k = kx; k <<= 3; k >>= 5;
struct OB;
typedef char *(*FA)(struct OB *, char *, short, char);
typedef char *(*FB)(struct OB *, char *, char *, unsigned char, char, int);
struct VTB { int z; FA f4; FA f8; FB fc; };
struct OB { char c; struct VTB *vt; };
#define P3F ((struct BF16 *)&p3)
#define P4F ((struct BF8 *)&p4)
//@ f_0ae770
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert die globalen Zeigertabellen (d_1be858 bis d_1bead0) für die spanischen
 *   Possessivpronomen ("su", "sus", "de su", "de sus", "a su", "con sus"), Personalpronomen ("él", "ella",
 *   "ello", "le", "les", "lo", "la", "los", "ellos", "ellas"), bestimmten Artikel ("el", "la", "del", "al",
 *   "los", "las", "de los", "de las" usw.), unbestimmten Artikel ("un", "una" usw.) und Relativpronomen ("que",
 *   "cuyo", "cuya", "a quien" usw.).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0ae770(void)
{
  int r_edx, r_ebx, r_ecx, r_esi, r_edi, r_ebp, r_eax;
  r_edx = d_1a50bc;
  r_ebx = d_1a50b0;
  r_ecx = d_1a5058;
  r_esi = d_1a505c;
  r_edi = d_1a50ac;
  r_ebp = d_1a50cc;
  r_eax = d_1a50b4;
  d_1be858 = r_edi;
  d_1be85c = r_edi;
  d_1be860 = r_edi;
  d_1be86c = r_ebp;
  d_1be870 = r_edx;
  d_1be874 = r_edx;
  d_1be878 = r_edx;
  d_1be87c = r_edx;
  d_1be880 = r_edx;
  d_1be884 = r_ebp;
  d_1be888 = r_edi;
  d_1be88c = r_edi;
  d_1be890 = r_edi;
  d_1be89c = r_ebp;
  d_1be8a0 = r_edx;
  d_1be8a4 = r_edx;
  d_1be8a8 = r_edx;
  d_1be8ac = r_edx;
  d_1be8b0 = r_edx;
  d_1be8b4 = r_ebp;
  d_1be8b8 = r_edi;
  d_1be8bc = r_edi;
  d_1be8c0 = r_edi;
  d_1be8cc = r_ebp;
  d_1be8d0 = r_edx;
  d_1be8d4 = r_edx;
  d_1be8d8 = r_edx;
  d_1be8dc = r_edi;
  d_1be8e0 = r_edi;
  d_1be8e4 = r_ebp;
  d_1be8e8 = r_ebx;
  d_1be8ec = r_ebx;
  d_1be8f0 = r_ebx;
  d_1be8fc = r_ebp;
  d_1be90c = r_edx;
  d_1be910 = r_edx;
  d_1be914 = r_ebp;
  d_1be918 = r_ebx;
  d_1be864 = r_eax;
  d_1be868 = r_eax;
  d_1be894 = r_eax;
  d_1be898 = r_eax;
  d_1be8c4 = r_eax;
  d_1be8c8 = r_eax;
  r_eax = d_1a50b8;
  d_1be91c = r_ebx;
  d_1be8f4 = r_eax;
  d_1be8f8 = r_eax;
  r_eax = d_1a50c0;
  d_1be920 = r_ebp;
  d_1be900 = r_eax;
  d_1be904 = r_eax;
  d_1be908 = r_eax;
  d_1be93c = r_eax;
  d_1be940 = r_eax;
  d_1be944 = r_eax;
  r_eax = d_1a5080;
  d_1be924 = r_ebx;
  d_1be954 = r_eax;
  r_eax = d_1a5084;
  d_1be928 = r_ebx;
  d_1be958 = r_eax;
  r_eax = d_1a5088;
  d_1be92c = r_ebx;
  d_1be95c = r_eax;
  r_eax = d_1a50a8;
  d_1be930 = r_ebx;
  d_1be960 = r_eax;
  d_1be964 = r_eax;
  d_1be968 = r_eax;
  r_eax = d_1a508c;
  (d_1be934) = r_ebx;
  d_1be96c = r_eax;
  d_1be970 = r_eax;
  d_1be974 = r_eax;
  r_eax = d_1a5094;
  (d_1be938) = r_ebx;
  d_1be978 = r_eax;
  r_eax = d_1a509c;
  (d_1be948) = r_edx;
  d_1be97c = r_eax;
  r_eax = d_1a5094;
  (d_1be94c) = r_edx;
  d_1be980 = r_eax;
  r_eax = d_1a50a0;
  (*(volatile int *)&d_1be950) = r_ebx;
  d_1be984 = r_eax;
  r_eax = d_1a50a4;
  d_1be988 = r_eax;
  r_eax = d_1a50a0;
  d_1be98c = r_eax;
  r_eax = d_1a50a8;
  d_1be990 = r_eax;
  d_1be994 = r_eax;
  d_1be998 = r_eax;
  r_eax = d_1a5090;
  d_1be99c = r_eax;
  d_1be9a0 = r_eax;
  d_1be9a4 = r_eax;
  r_eax = d_1a5098;
  d_1be9a8 = r_eax;
  d_1be9ac = r_eax;
  d_1be9b0 = r_eax;
  r_eax = d_1a4ff4;
  d_1be9b4 = r_eax;
  r_eax = d_1a4ff8;
  d_1be9b8 = r_eax;
  r_eax = d_1a4ff4;
  d_1be9bc = r_eax;
  r_eax = d_1a4ffc;
  d_1be9c0 = r_eax;
  r_eax = d_1a5008;
  d_1be9c4 = r_eax;
  r_eax = d_1a4ffc;
  d_1be9c8 = r_eax;
  r_eax = d_1a5004;
  d_1be9cc = r_eax;
  r_eax = d_1a500c;
  d_1be9d0 = r_eax;
  r_eax = d_1a5004;
  d_1be9d4 = r_eax;
  r_eax = d_1a5000;
  d_1be9d8 = r_eax;
  r_eax = d_1a5010;
  d_1be9dc = r_eax;
  r_eax = d_1a5000;
  d_1be9e0 = r_eax;
  r_eax = d_1a5014;
  d_1be9e4 = r_eax;
  r_eax = d_1a5018;
  d_1be9e8 = r_eax;
  r_eax = d_1a5014;
  d_1be9ec = r_eax;
  r_eax = d_1a501c;
  d_1be9f0 = r_eax;
  r_eax = d_1a5020;
  d_1be9f4 = r_eax;
  r_eax = d_1a501c;
  d_1be9f8 = r_eax;
  r_eax = d_1a5024;
  d_1be9fc = r_eax;
  r_eax = d_1a5028;
  d_1bea00 = r_eax;
  r_eax = d_1a5024;
  d_1bea04 = r_eax;
  r_eax = d_1a502c;
  d_1bea08 = r_eax;
  r_eax = d_1a5030;
  d_1bea44 = r_ecx;
  d_1bea0c = r_eax;
  r_eax = d_1a502c;
  d_1bea48 = r_ecx;
  d_1bea10 = r_eax;
  r_eax = d_1a5034;
  d_1bea4c = r_ecx;
  d_1bea14 = r_eax;
  r_eax = d_1a5038;
  d_1bea50 = r_ecx;
  d_1bea18 = r_eax;
  r_eax = d_1a5034;
  d_1bea54 = r_ecx;
  d_1bea1c = r_eax;
  r_eax = d_1a503c;
  d_1bea58 = r_ecx;
  d_1bea20 = r_eax;
  r_eax = d_1a5040;
  d_1bea5c = r_ecx;
  d_1bea24 = r_eax;
  r_eax = d_1a503c;
  d_1bea60 = r_ecx;
  d_1bea28 = r_eax;
  r_eax = d_1a504c;
  d_1bea64 = r_ecx;
  d_1bea2c = r_eax;
  r_eax = d_1a5050;
  d_1bea68 = r_ecx;
  d_1bea30 = r_eax;
  r_eax = d_1a504c;
  d_1bea6c = r_ecx;
  d_1bea34 = r_eax;
  r_eax = d_1a5044;
  d_1bea70 = r_ecx;
  d_1bea38 = r_eax;
  r_eax = d_1a5048;
  d_1bea74 = r_esi;
  d_1bea3c = r_eax;
  r_eax = d_1a5044;
  d_1bea78 = r_esi;
  d_1bea40 = r_eax;
  r_eax = d_1a5060;
  d_1bea7c = r_esi;
  d_1bea80 = r_eax;
  r_eax = d_1a5064;
  d_1bea98 = r_esi;
  d_1bea84 = r_eax;
  r_eax = d_1a5060;
  d_1bea9c = r_esi;
  d_1bea88 = r_eax;
  r_eax = d_1a5068;
  d_1beaa0 = r_esi;
  d_1bea8c = r_eax;
  d_1bea90 = r_eax;
  r_eax = d_1a506c;
  d_1beaa4 = r_esi;
  d_1bea94 = r_eax;
  r_eax = d_1a5070;
  d_1beaa8 = r_esi;
  d_1beab0 = r_eax;
  r_eax = d_1a5074;
  d_1beaac = r_esi;
  d_1beab4 = r_eax;
  r_eax = d_1a5070;
  d_1beac8 = r_esi;
  d_1beab8 = r_eax;
  r_eax = d_1a5078;
  d_1beacc = r_esi;
  d_1beabc = r_eax;
  d_1beac0 = r_eax;
  r_eax = d_1a507c;
  d_1bead0 = r_esi;
  d_1beac4 = r_eax;
}

//@ f_0aec40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt das passende spanische Relativpronomen ("que", "cuyo", "cuya", "a quien", "al que",
 *   "cuyos", "cuyas", "a quienes", "a los que") anhand von Kasus (p2), Numerus und Genus (p3) aus der Tabelle
 *   d_1bea74 an den Zielpuffer (p1) an.
 * - Eingaben: Übergeben werden der Zielpuffer (p1), das Kasus-Bitfeld (p2) und das Numerus- und Genus-Bitfeld
 *   (p3).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
struct BF3W { unsigned char a:2, k:3, c:3; unsigned char spare; };
void f_0aec40(char *p1, struct BF3W p2, struct BF8 p3)
{
  strcat(p1, ((char *(*)[3])&d_1bea74)[p2.k + p3.h * 4][p3.a]);
}
//@ f_0aecd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Bildet für ein spanisches Substantiv (p2) in einem neu allokierten Puffer die vollständige
 *   Nominalphrase je nach Modus (p3 oberes Byte): bestimmter Artikel + Leerzeichen + Substantiv (case 2),
 *   unbestimmter Artikel + Leerzeichen + Substantiv (case 1), nur Substantiv (case 0), nur bestimmter Artikel
 *   (case 3), nur unbestimmter Artikel (case 4) oder Relativpronomen über f_0aec40 (case 5).
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), das Substantiv (p2), das Modus-
 *   und Kasus-Bitfeld (p3), das Numerus- und Genus-Bitfeld (p4) sowie ein Zusatzparameter (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten Zeichenpuffer mit der gebildeten
 *   spanischen Nominalphrase zurück.
 === Ende Beschreibung === */
char *f_0aecd0(struct OB *p1, char *p2, struct BF16 p3, struct BF8 p4, int p5)
{
  typedef char *(*FAcall)(struct OB *,char *,struct BF16,struct BF8);
  typedef char *(*FBcall)(struct OB *,char *,char *,unsigned char,struct BF8,int);
  struct LowByte { unsigned char a:2,k:3,c:3; };
  int n = (short)(strlen((*(char **)(signed char *)&p2)) + 0x14);
  char *buf = 0; buf = new (mark(d_1a4fd4, 0x13e)) char[n];
  f_145300(buf, 0, n);
  switch ((unsigned char)(((unsigned char *)&p3)[1] & 7)) {
  case 2:
    ((FAcall)p1->vt->f4)(p1, buf, p3, p4);
    if (buf[0]) strcat(buf, d_1b7fec);
    ((FBcall)p1->vt->fc)(p1, buf, p2, ((struct LowByte *)&p3)->k, p4, p5);
    break;
  case 1:
    ((FAcall)p1->vt->f8)(p1, buf, p3, p4);
    if (buf[0]) strcat(buf, d_1b7fee);
    ((FBcall)p1->vt->fc)(p1, buf, p2, ((struct LowByte *)&p3)->k, p4, p5);
    break;
  case 3:
    ((FAcall)p1->vt->f4)(p1, buf, p3, p4);
    break;
  case 4:
    ((FAcall)p1->vt->f8)(p1, buf, p3, p4);
    break;
  case 0:
    ((FBcall)p1->vt->fc)(p1, buf, p2, ((struct LowByte *)&p3)->k, p4, p5);
    break;
  case 5: {
    f_0aec40(buf,*(struct BF3W *)&p3,p4);
    break; }
  }
  return buf;
}
//@ f_0aef10
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden spanischen bestimmten Artikel samt Präpositionsverschmelzung ("el",
 *   "la", "del", "al", "para el", "de la", "los", "las" usw.) anhand von Kasus (p3), Numerus und Genus (p4) aus
 *   der Tabelle d_1be9b4 an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), der Zielpuffer (p2), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aef10(int p1, char *p2, struct BF3W p3, struct BF8 p4)
{
  strcat(p2, ((char *(*)[3])&d_1be9b4)[p3.k + p4.h * 4][p4.a]);
}
//@ f_0aef80
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Hängt den passenden spanischen unbestimmten Artikel samt Präposition ("un", "una", "de un",
 *   "de una", "a un", "a una", "para un", "para una") anhand von Kasus (p3), Numerus und Genus (p4) aus der
 *   Tabelle d_1bea14 an den Zielpuffer (p2) an.
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), der Zielpuffer (p2), das
 *   Kasus-Bitfeld (p3) und das Numerus- und Genus-Bitfeld (p4).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aef80(int p1, char *p2, struct BF3W p3, struct BF8 p4)
{
  strcat(p2, ((char *(*)[3])&d_1bea14)[p3.k + p4.h * 4][p4.a]);
}
//@ f_0aeff0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kopiert im spanischen Sprachmodul das übergebene Substantiv (p3) unverändert per strcat an
 *   das Ende des Zielpuffers (p2).
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), der Zielpuffer (p2), das Quellwort
 *   (p3) sowie drei ungenutzte Grammatikparameter.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0aeff0(int p1, char *p2, char *p3, int p4, int p5, int p6)
{
  strcat(p2, p3);
}
//@ f_0af020
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 20-Byte-Puffer auf dem Heap und trägt darin das passende spanische
 *   Possessivpronomen ("su", "sus", "de su", "de sus", "a su", "con sus", im Akkusativ bei Bedarf mit
 *   vorangestelltem "a " aus d_1b7ff0) anhand von Artikelmodus (p2), Bezugswort-Genus (p3), Kasus (p4) und
 *   Besitzer-Flags (p5) aus den Tabellen d_1be858 bis d_1be924 ein.
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), der Artikelmodus (p2), das
 *   Bezugswort-Genus (p3), die Kasus-Flags (p4) und die Besitzer-Flags (p5).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem spanischen
 *   Possessivpronomen zurück.
 === Ende Beschreibung === */
char *f_0af020(int p1, short p2, short p3, short p4, signed char p5)
{
  short a = p2;
  char *r = new (mark(d_1a4fd4, 0x1b9)) char[0x14];
  char *(*base)[3];
  *r = 0;
  if (a == 0) {
    unsigned char hh = p5; hh <<= 4; hh >>= 6;
    if (hh == 1) base = (char *(*)[3])&d_1be8e8;
    else switch ((unsigned char)(p5 & 3)) {
    case 0: base = (char *(*)[3])&d_1be858; break;
    case 1: base = (char *(*)[3])&d_1be888; break;
    case 2: base = (char *(*)[3])&d_1be8b8; break;
    }
  } else base = (char *(*)[3])&d_1be924;
  unsigned char kt = p4; kt <<= 3; kt >>= 5;
  int k = kt;
  char *t = base[k][p3];
  if (k == 3 && (unsigned char)f_0b04e0(p1) != 2) strcat(r, d_1b7ff0);
  strcat(r, t);
  return r;
}
//@ f_0af140
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Erzeugt einen 20-Byte-Puffer auf dem Heap und kopiert das passende spanische
 *   Personalpronomen ("él", "ella", "ello", "le", "les", "lo", "la", "los", "ellos", "ellas") anhand von Kasus
 *   (p2), Numerus und Genus (p3) aus der Tabelle d_1be954 hinein.
 * - Eingaben: Übergeben werden ein Zeiger auf das spanische Sprachmodul (p1), das Kasus-Bitfeld (p2) und das
 *   Numerus- und Genus-Bitfeld (p3).
 * - Rückgabewert: Die Funktion gibt einen Zeiger auf den neu allokierten String mit dem spanischen
 *   Personalpronomen zurück.
 === Ende Beschreibung === */
struct BF4S { unsigned char b01:2, b23:2, b47:4; };
char *f_0af140(int p1, struct BF3W p2, struct BF4S p3)
{
    char *buf = new (mark(d_1a4fd4, 0x1fe)) char[20];
    *buf = 0;
    strcat(buf, ((char *(*)[3])&d_1be954)[p2.k + p3.b23 * 4][p3.b01]);
    return buf;
}
