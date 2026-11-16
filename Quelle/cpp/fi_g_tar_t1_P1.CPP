/* === Beschreibung (Katalog) ===
 * Einheit fi_g_tar_t1 (0738a0 - 074a90)
 *
 * Überblick
 * Der erste Teil von fi_g_tar (*Fight Get Target*) implementiert die interaktive Zielauswahl mit Maus und
 * Tastatur auf dem isometrischen Kampffeld (f_0738a0) sowie die Rückverfolgung des kürzesten und kurvenärmsten
 * Bewegungspfads auf dem Distanzraster (f_074680, f_074a50).
 *
 * Hinweis zu den volatile-Variablen (ghost_*), Stand Version 1.0 (16.11.2026)
 * Diese Einheit enthaelt noch 272 unbenutzte volatile-Lokale (vorher 1016). Sie erzeugen keinen Befehl und keinen
 * Stapelplatz, steuern aber, wie Watcom 10.6 Register und Stapelplaetze verteilt - nur mit ihnen wird der Code
 * bytegleich zum Original. In allen anderen Einheiten liessen sie sich mit dem Modell der Watcom-Symboltabelle
 * (zweiphasige ShellSort-Sortierung, siehe Analyse/Pass2/codex/astra_48h/GEISTER_GEM/REZEPT_GEISTER.md) grossteils
 * wegrechnen (8149 -> 950 im ganzen Projekt); hier gelang es K48 am 16.11. zu drei Vierteln (1016 -> 272). Wer weiter kuerzt, muss nach jeder Aenderung
 * nativ messen: alle Funktionen GLEICH, Gesamtbau-MD5 fb8f5fc3ba5454c7344c17aaf362de35.
 === Ende Beschreibung === */
// P1 1/3 gleich
// fi_g_tar_t1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0738A0-0x074A90
#include <string.h>
#include <stdlib.h>
#pragma intrinsic(abs)
#include "RIVAMEM.H"
#include "R_FIX.H"



typedef short VS;
#define GR(x,y) ((d_1bd984+(y)*25)[(x)])
inline int ABS(int a) { int s = a >> 31; return (a ^ s) - s; }
struct D4 { int a, b, c, d; };
struct B24 { int a[6]; };
#define UB(o) (*(unsigned char*)(t+(o)))
#define SB(o) (*(signed char*)(t+(o)))
#define I4(o) (*(int*)(t+(o)))
#define SH(o) (*(short*)(t+(o)))
char *f_014540(int size, const char *file, int line);
int f_043410(int p1);
int f_069460();
short f_071e20(int p1, int p2, int p3, int p4);
int f_071e50(int p1, int p2, int p3, int p4);
int f_071e90(int p1, short *p2, short *p3);
int f_071f20(int p1, int p2);
int f_072910();
short f_073410(int p1, int p2, int p3, int p4, int p5);
int f_0735b0(int p1, int p2, int p3, short *p4, short *p5, int p6);
int f_0757f0(int p1);
int f_0758b0(int p1);
int f_075f10(int p1);
int f_0762e0(int p1, int p2, int p3, int p4);
int f_0765a0(int p1);
int f_077400(int p1);
int f_07b220(int p1);
int f_07db20(int p1, int p2, short *p3, short *p4, short *p5, short *p6, short *p7, char *p8);
int f_07eba0(int p1, int p2, int p3);
char f_07ec10(int p1, int p2);
void f_0cdd50(int p1, int p2, int p3, int p4, int p5);
int f_0d06c0(int p1);
int f_0d26e0();
int f_0d2710();
int f_0d3780();
int f_0d37b0();
extern const char d_1a1ca8[];
extern const char d_1a1cbe[];
extern const char d_1a1cc0[];
extern const char d_1a1ce0[];
extern int d_1bc8f0;
extern short d_1bd766;
extern char d_1bd928;
extern signed char d_1bd950[];
extern unsigned char *d_1bd984;
extern int d_1bda64;
extern signed char d_1bf4ef;
extern short d_1bf4f0;
extern short d_1bf4f2;
extern int d_1c2ed4;
inline int cnt(signed char *q)
{
    int n = 0;
    short j;
    if (*q == -1) return 99;
    j = 1;
    while (1) {
        if (q[j] == -1) break;
        if (q[j - 1] != q[j]) n++;
        j++;
    }
    return n;
}
//@ f_0738a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die interaktive Fadenkreuz-/Zielauswahl des Spielers im Kampf (für Fernkampf, Zauber
 *   oder Bewegung). Der Spieler bewegt das Markierungsfeld per Maus (Umrechnung der Bildschirmkoordinaten in
 *   isometrische Rasterkoordinaten 0..23) oder Pfeiltasten; die Funktion zeichnet live die Schusslinie
 *   (P325-Markierungsobjekte) und das Zielporträt am unteren Bildschirmrand. Ist ein angewähltes Ziel vom
 *   aktuellen Standort aus nicht in Schusslinie oder Reichweite, hebt die Funktion bei Bestätigung automatisch
 *   alle erreichbaren Nachbarfelder hervor, von denen aus der Held im selben Zug noch angreifen könnte, und gibt
 *   einen entsprechenden Hinweis (0x1010059 / 0x101005a) aus.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger t, die Ein-/Ausgabezeiger p2 (Ziel-X) und p3 (Ziel-Y), die
 *   Reichweite p4, die Mindestdistanz p5, ein Diagonal-Flag p6 sowie die für den Angriff benötigten
 *   Aktionspunkte p7 und gibt die Rasterkennung c des gewählten Ziels (oder 0xff bei Abbruch/Ungültigkeit)
 *   zurück.
 * - Wichtige Variablen: Nutzt d_1a1ca8 zur Begrenzung der sichtbaren Rautenkanten, t + 0x325 für die Sprite-IDs
 *   der Schusslinienpunkte und t + 0x295 für die Sprite-IDs vorgeschlagener Ausweich-Standorte.
 === Ende Beschreibung === */
#define NOID ((unsigned char)0xff)
#define TFD ((unsigned char)0xfd)
#define F71E20 ((short (*)(short, short, short, short))f_071e20) // Haelt die Register- und Stapelfolge wie im Original: Aufruf ueber Cast (echte Parameter short)
#define F43410 ((signed char (*)(int))f_043410) // Haelt die Register- und Stapelfolge wie im Original: Aufruf ueber Cast (echte Rueckgabe char)
#define MAUSX_0738a0 (*(volatile short *)&d_1bf4f0) // Haelt die Register- und Stapelfolge wie im Original: Mauskoordinate als volatile lesen (32-Bit-Vergleich wie im Original)
#define MAUSY_0738a0 (*(volatile short *)&d_1bf4f2) // Haelt die Register- und Stapelfolge wie im Original: wie oben
struct PT_0738a0 { short x, y; };
#define P325 ((unsigned char *)(t + 0x325))
#define P295 ((unsigned char *)(t + 0x295))
#define PATH ((PT_0738a0 *)(t + 0x35b))
inline int chk_0738a0(int t, short x1, short y1, short x2, short y2, short m)
{
 short result;
 if(m==1) {
   if(x1!=x2 && y1!=y2) result=0;
   else {
     result=F71E20(x1,y1,x2,y2);
     if(result>1) result=0; else result=1;
   }
 } else {
   f_0cdd50(x1,y1,x2,y2,t+0x35b);
   result=f_073410(t,x1,y1,t+0x35b,m);
 }
 return result;
}
inline int chk_second_D11(int t, short x1, short x2, short y2, short y1, short m)
{
 short result;
 if(m==1) {
   if(x1!=x2 && y1!=y2) result=0;
   else {
     result=F71E20(x1,y1,x2,y2);
     if(result>1) result=0; else result=1;
   }
 } else {
   f_0cdd50(x1,y1,x2,y2,t+0x35b);
   result=f_073410(t,x1,y1,t+0x35b,m);
 }
 return result;
}

inline int oldx_D11(int t) { int v=SB(0x18);  { int q=v;v=q;} return v;}
inline int ecx_seed_D14(short v) { int n=v; {int q=n;n=q;q=n;n=q;q=n;n=q;q=n;n=q;q=n;n=q;} return n; }
inline int table_index_D14(short v) { int n=v; {int q=n;n=q;q=n;n=q;q=n;n=q;q=n;n=q;} return n; }
inline int cv_A20T(short a) { int v=a; {int q=v;v=q;} return v; }
inline int dx_A20T(short x,short y) { int a=x; int b=y; {int q=b;b=q;} return abs(a-b); }
inline int cy_dist_A20T(short a) { int v=a;{int q=v;v=q;}return v; }
char f_0738a0(int t, VS *p2, VS *p3, short p4, short p5, int p6, short p7)
{
    extern unsigned char * volatile path_grid_0738a0;
    #pragma aux path_grid_0738a0 "d_1bd984" // Haelt die Register- und Stapelfolge wie im Original: reiner Symbolalias, kein Codekoerper
    // Haelt die Register- und Stapelfolge wie im Original: unbenutzte volatile Sortierknoten; nativ ohne eigenen Stapelplatz oder Befehle.
    struct GhostShape3_A20T { char pad[3]; };
    struct GhostShape5_A20T { char pad[5]; };
    volatile int ghost_0_A20T;
    short ox;
    short cx;
    int done;
    unsigned char c;
    short my;
    short i;
    int special;
    int u761_; // Haelt die Register- und Stapelfolge wie im Original ungenutzt
    int ok;
    signed char tab[24];
    int first;
    short cy;
    short ny;
    short mx;
    short nx;
    short oy;
    volatile char ghost_1_A20T;
    volatile char ghost_2_A20T;
    volatile int ghost_3_A20T;
    volatile GhostShape5_A20T ghost_4_A20T;
    volatile int ghost_5_A20T;
    volatile short ghost_6_A20T;
    volatile short ghost_7_A20T;
    volatile char ghost_8_A20T;
    volatile char ghost_9_A20T;
    volatile GhostShape5_A20T ghost_10_A20T;
    volatile short ghost_11_A20T;
    volatile short ghost_12_A20T;
    volatile short ghost_13_A20T;
    volatile char ghost_14_A20T;
    volatile char ghost_15_A20T;
    volatile GhostShape5_A20T ghost_16_A20T;
    volatile GhostShape5_A20T ghost_17_A20T;
    volatile char ghost_18_A20T;
    volatile GhostShape5_A20T ghost_19_A20T;
    volatile short ghost_20_A20T;
    volatile GhostShape3_A20T ghost_21_A20T;
    volatile GhostShape3_A20T ghost_22_A20T;
    volatile GhostShape3_A20T ghost_23_A20T;
    volatile GhostShape5_A20T ghost_24_A20T;
    volatile int ghost_25_A20T;
    volatile GhostShape5_A20T ghost_26_A20T;
    volatile short ghost_27_A20T;
    volatile GhostShape3_A20T ghost_28_A20T;
    volatile int ghost_29_A20T;
    volatile char ghost_30_A20T;
    volatile char ghost_31_A20T;
    volatile short ghost_32_A20T;
    volatile char ghost_33_A20T;
    volatile char ghost_34_A20T;
    volatile char ghost_35_A20T;
    volatile short ghost_36_A20T;
    volatile short ghost_37_A20T;
    volatile short ghost_38_A20T;
    volatile int ghost_39_A20T;
    volatile GhostShape5_A20T ghost_40_A20T;
    volatile int ghost_41_A20T;
    volatile GhostShape3_A20T ghost_42_A20T;
    volatile GhostShape5_A20T ghost_43_A20T;
    volatile int ghost_44_A20T;
    volatile GhostShape3_A20T ghost_45_A20T;
    volatile GhostShape5_A20T ghost_46_A20T;
    volatile char ghost_47_A20T;
    volatile GhostShape5_A20T ghost_48_A20T;
    volatile short ghost_49_A20T;
    volatile GhostShape3_A20T ghost_50_A20T;
    volatile short ghost_51_A20T;
    volatile char ghost_52_A20T;
    volatile GhostShape5_A20T ghost_53_A20T;
    volatile char ghost_54_A20T;
    volatile GhostShape5_A20T ghost_55_A20T;
    volatile GhostShape3_A20T ghost_56_A20T;
    volatile short ghost_57_A20T;
    volatile GhostShape3_A20T ghost_58_A20T;
    volatile GhostShape3_A20T ghost_59_A20T;
    volatile GhostShape3_A20T ghost_60_A20T;
    volatile char ghost_61_A20T;
    volatile int ghost_62_A20T;
    volatile char ghost_63_A20T;
    volatile char ghost_64_A20T;
    volatile short ghost_65_A20T;
    volatile char ghost_66_A20T;
    volatile char ghost_67_A20T;
    volatile GhostShape3_A20T ghost_68_A20T;
    volatile char ghost_69_A20T;
    volatile GhostShape3_A20T ghost_70_A20T;
    volatile int ghost_71_A20T;
    volatile char ghost_72_A20T;
    volatile short ghost_73_A20T;
    volatile GhostShape5_A20T ghost_74_A20T;
    volatile short ghost_75_A20T;
    volatile char ghost_76_A20T;
    volatile char ghost_77_A20T;
    volatile char ghost_78_A20T;
    volatile char ghost_79_A20T;
    volatile int ghost_80_A20T;
    volatile short ghost_81_A20T;
    volatile char ghost_82_A20T;
    volatile int ghost_83_A20T;
    volatile GhostShape3_A20T ghost_84_A20T;
    volatile short ghost_85_A20T;
    volatile int ghost_86_A20T;
    volatile short ghost_87_A20T;
    volatile GhostShape3_A20T ghost_88_A20T;
    volatile GhostShape3_A20T ghost_89_A20T;
    volatile GhostShape5_A20T ghost_90_A20T;
    volatile short ghost_91_A20T;
    volatile short ghost_92_A20T;
    volatile short ghost_93_A20T;
    volatile GhostShape5_A20T ghost_94_A20T;
    volatile short ghost_95_A20T;
    volatile GhostShape3_A20T ghost_96_A20T;
    volatile short ghost_97_A20T;
    volatile GhostShape5_A20T ghost_98_A20T;
    volatile GhostShape5_A20T ghost_99_A20T;
    volatile char ghost_100_A20T;
    volatile GhostShape3_A20T ghost_101_A20T;
    volatile char ghost_102_A20T;
    volatile short ghost_103_A20T;
    volatile GhostShape3_A20T ghost_104_A20T;
    volatile GhostShape5_A20T ghost_105_A20T;
    volatile char ghost_106_A20T;
    volatile GhostShape5_A20T ghost_107_A20T;
    volatile short ghost_108_A20T;
    volatile short ghost_109_A20T;
    volatile GhostShape3_A20T ghost_110_A20T;
    volatile GhostShape5_A20T ghost_111_A20T;
    volatile short ghost_112_A20T;
    volatile char ghost_113_A20T;
    volatile short ghost_114_A20T;
    volatile GhostShape5_A20T ghost_115_A20T;
    volatile char ghost_116_A20T;
    volatile char ghost_117_A20T;
    volatile int ghost_118_A20T;
    volatile char ghost_119_A20T;
    volatile char ghost_120_A20T;
    volatile GhostShape5_A20T ghost_121_A20T;
    volatile char ghost_122_A20T;
    volatile char ghost_123_A20T;
    volatile int ghost_124_A20T;
    volatile short ghost_125_A20T;
    volatile short ghost_126_A20T;
    volatile int ghost_127_A20T;
    volatile int ghost_128_A20T;
    volatile char ghost_129_A20T;
    volatile char ghost_130_A20T;
    volatile short ghost_131_A20T;
    volatile char ghost_132_A20T;
    volatile short ghost_133_A20T;
    volatile GhostShape5_A20T ghost_134_A20T;
    volatile char ghost_135_A20T;
    volatile int ghost_136_A20T;
    volatile GhostShape5_A20T ghost_137_A20T;
    volatile short ghost_138_A20T;
    volatile short ghost_139_A20T;
    volatile char ghost_140_A20T;
    volatile GhostShape3_A20T ghost_141_A20T;
    volatile GhostShape5_A20T ghost_142_A20T;
    volatile short ghost_143_A20T;
    volatile short ghost_144_A20T;
    volatile int ghost_145_A20T;
    volatile int ghost_146_A20T;
    volatile char ghost_147_A20T;
    volatile int ghost_148_A20T;
    volatile char ghost_149_A20T;
    volatile short ghost_150_A20T;
    volatile GhostShape3_A20T ghost_151_A20T;
    volatile int ghost_152_A20T;
    volatile int ghost_153_A20T;
    volatile char ghost_154_A20T;
    volatile GhostShape5_A20T ghost_155_A20T;
    volatile short ghost_156_A20T;
    volatile GhostShape3_A20T ghost_157_A20T;
    volatile short ghost_158_A20T;
    volatile GhostShape5_A20T ghost_159_A20T;
    volatile char ghost_160_A20T;
    volatile int ghost_161_A20T;
    volatile GhostShape5_A20T ghost_162_A20T;
    volatile char ghost_163_A20T;
    volatile short ghost_164_A20T;
    volatile int ghost_165_A20T;
    volatile char ghost_166_A20T;
    volatile char ghost_167_A20T;
    volatile char ghost_168_A20T;
    volatile int ghost_169_A20T;
    volatile char ghost_170_A20T;
    volatile GhostShape3_A20T ghost_171_A20T;
    volatile char ghost_172_A20T;
    volatile int ghost_173_A20T;
    volatile GhostShape5_A20T ghost_174_A20T;
    volatile GhostShape5_A20T ghost_175_A20T;
    volatile char ghost_176_A20T;
    volatile GhostShape3_A20T ghost_177_A20T;
    volatile short ghost_178_A20T;
    volatile GhostShape5_A20T ghost_179_A20T;
    volatile int ghost_180_A20T;
    volatile GhostShape5_A20T ghost_181_A20T;
    volatile GhostShape3_A20T ghost_182_A20T;
    volatile GhostShape3_A20T ghost_183_A20T;
    volatile int ghost_184_A20T;
    volatile short ghost_185_A20T;
    volatile char ghost_186_A20T;
    volatile int ghost_187_A20T;
    volatile GhostShape5_A20T ghost_188_A20T;
    volatile char ghost_189_A20T;
    volatile short ghost_190_A20T;
    volatile GhostShape3_A20T ghost_191_A20T;
    volatile short ghost_192_A20T;
    volatile GhostShape3_A20T ghost_193_A20T;
    volatile GhostShape5_A20T ghost_194_A20T;
    volatile short ghost_195_A20T;
    volatile char ghost_196_A20T;
    volatile GhostShape5_A20T ghost_197_A20T;
    volatile short ghost_198_A20T;
    volatile short ghost_199_A20T;
    volatile GhostShape5_A20T ghost_200_A20T;
    volatile GhostShape3_A20T ghost_201_A20T;
    volatile int ghost_202_A20T;
    volatile char ghost_203_A20T;
    volatile int ghost_204_A20T;
    volatile GhostShape5_A20T ghost_205_A20T;
    volatile int ghost_206_A20T;
    volatile char ghost_207_A20T;
    volatile GhostShape5_A20T ghost_208_A20T;
    volatile short ghost_209_A20T;
    volatile GhostShape5_A20T ghost_210_A20T;
    volatile char ghost_211_A20T;
    volatile char ghost_212_A20T;
    volatile short ghost_213_A20T;
    volatile char ghost_214_A20T;
    volatile char ghost_215_A20T;
    volatile short ghost_216_A20T;
    volatile short ghost_217_A20T;
    volatile int ghost_218_A20T;
    volatile char ghost_219_A20T;
    volatile GhostShape3_A20T ghost_220_A20T;
    volatile short ghost_221_A20T;
    volatile GhostShape3_A20T ghost_222_A20T;
    volatile char ghost_223_A20T;
    volatile char ghost_224_A20T;
    volatile char ghost_225_A20T;
    volatile GhostShape3_A20T ghost_226_A20T;
    volatile GhostShape5_A20T ghost_227_A20T;
    volatile short ghost_228_A20T;
    volatile int ghost_229_A20T;
    volatile char ghost_230_A20T;
    volatile GhostShape3_A20T ghost_231_A20T;
    volatile GhostShape3_A20T ghost_232_A20T;
    volatile short ghost_233_A20T;
    volatile GhostShape5_A20T ghost_234_A20T;
    volatile GhostShape5_A20T ghost_235_A20T;
    volatile GhostShape3_A20T ghost_236_A20T;
    volatile short ghost_237_A20T;
    volatile GhostShape3_A20T ghost_238_A20T;
    volatile char ghost_239_A20T;
    volatile int ghost_240_A20T;
    volatile short ghost_241_A20T;
    volatile char ghost_242_A20T;
    volatile int ghost_243_A20T;
    volatile short ghost_244_A20T;
    volatile char ghost_245_A20T;
    volatile GhostShape3_A20T ghost_246_A20T;
    volatile char ghost_247_A20T;
    volatile int ghost_248_A20T;
    volatile GhostShape5_A20T ghost_249_A20T;
    volatile int ghost_250_A20T;
    volatile GhostShape5_A20T ghost_251_A20T;
    volatile short ghost_252_A20T;
    volatile GhostShape3_A20T ghost_253_A20T;
    volatile short ghost_254_A20T;
    volatile int ghost_255_A20T;
    volatile GhostShape3_A20T ghost_256_A20T;
    volatile GhostShape3_A20T ghost_257_A20T;
    volatile int ghost_258_A20T;
    volatile char ghost_259_A20T;
    volatile char ghost_260_A20T;
    volatile char ghost_261_A20T;
    volatile int ghost_262_A20T;
    volatile GhostShape5_A20T ghost_263_A20T;
    volatile GhostShape3_A20T ghost_264_A20T;
    volatile short ghost_265_A20T;
    volatile GhostShape5_A20T ghost_266_A20T;
    volatile int ghost_267_A20T;
    volatile GhostShape3_A20T ghost_268_A20T;
    volatile char ghost_269_A20T;
    volatile char ghost_270_A20T;
    volatile GhostShape3_A20T ghost_271_A20T;
    done=0;
    ok=0;
    special=0;
    first=1;
    *(B24 *)tab = *(B24 *)d_1a1ca8;
    f_0d26e0();
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{VS * weight_A20T=p3;p3=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert

{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip

{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip





    mx = MAUSX_0738a0;
{short weight_A20T=mx;mx=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert

    my = MAUSY_0738a0;
    ox = (*p2);
    oy = (*p3);
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=p4;p4=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert



{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=p4; p4=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung



    if (UB(0x294) != NOID) {
        f_07eba0(t + 0x39, UB(0x294), 0);
        UB(0x294) = 0xff;
    }
    for (i = 0; i < (short)30; i++) P325[i] = 0xff;
    SB(0x1e) = 0;
    SB(0x18) = (char)(*p2);
    SB(0x19) = (char)(*p3);
    SB(0x1f) = 0;
    SB(0x20) = 6;
    SB(0x24) = 0;
    I4(0x27) = 0;
    I4(0x2b) = I4(0x1f1);
    SB(0x22) = 2;
    SB(0x23) = 1;
    SB(0x25) = -1;
    SB(0x294) = f_07ec10(t + 0x39, -1);
    f_0757f0(t);
    do {
        f_077400(t);
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge
{short q_D14=mx;mx=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: ausgerechnete Pfadregisterfolge




{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p3; p3=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip

{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip
{VS *q_D11=p2; p2=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: codeloser Zeiger-Roundtrip






        if (d_1bd766 == 0x11b || f_0d37b0()) {
            done = 1;
            ok = 0;
        } else {
            if (f_0d3780()) d_1bd766 = 0x1c0d;
            if (!d_1bd766 && !d_1bf4ef) {
                int lx_D11=mx;{int q=lx_D11;lx_D11=q;}
                if (lx_D11 != MAUSX_0738a0 || my != MAUSY_0738a0) {
                short v;
                mx = MAUSX_0738a0;
                my = MAUSY_0738a0;
                v = my * 2 + mx - 0xd5;
                if (v < 0) v -= 0x13;
                cx = v / 0x14 - 1;
                v = mx - my * 2 + 0xfb;
                if (v < 0) v -= 0x13;
                cy = v / 0x14 - 1;
                if (cx < 0) cx = 0;
                if (cx > 0x17) cx = 0x17;
                if (cy < 0) cy = 0;
                if (cy > 0x17) cy = 0x17;
                if (cx != (*p2) || cy != (*p3)) {
                    (*p2) = cx;
                    (*p3) = cy;
                }
            }
            }
            if (d_1bd766 == 0x4d00) (*p2)++;
            else if (d_1bd766 == 0x4b00) (*p2)--;
            else if (d_1bd766 == 0x4800) (*p3)++;
            else if (d_1bd766 == 0x5000) (*p3)--;
            if ((*p2) < 0) (*p2) = 0;
            if ((*p2) > 0x17) (*p2) = 0x17;
            if ((*p3) < 0) (*p3) = 0;
            if ((*p3) > 0x17) (*p3) = 0x17;
            int table_idx_D14;
            for (i = 0; (table_idx_D14=table_index_D14(i)) < 0x17; i++) {
                {short q=i;i=q;q=i;i=q;q=i;i=q;q=i;i=q;}
                int table_pos_D14=*p2; {int q=table_pos_D14;table_pos_D14=q;q=table_pos_D14;table_pos_D14=q;q=table_pos_D14;table_pos_D14=q;q=table_pos_D14;table_pos_D14=q;}
                if (table_pos_D14 > tab[table_idx_D14] && i == (*p3)) { (*p2) = tab[table_idx_D14]; break; }
            }
            if ((*p2) != oldx_D11(t) || (*p3) != SB(0x19) || first == 1) {
                first = 0;
                special = 0;
                { int rv=(int)d_1bd984; d_1bd984=(unsigned char *)rv; c=(d_1bd984+(*p3)*25)[*p2]; }
                if (c == TFD || (c == 10 && f_0d06c0(d_1c2ed4))) {
                    c = 10;
                    special = 1;
                }
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
                d_1bda64 = 1;
                I4(0x20d) = 0;
                I4(0x209) = 0;
                if (c > 0 && c < 0x32) {
                    if (c < 10) { int product_D11=(c-1)*0x5ef; {int q=product_D11;product_D11=q;} {int q=product_D11;product_D11=q;} I4(0x209)=(int)((unsigned char*)d_1bc8f0+product_D11); } // Haelt die Register- und Stapelfolge wie im Original: Produkt-Lebensdauer vor Basisladung
                    else if (c >= 0x1e) { int product_enemy_D14=(c-0x1e)*0x73; { int q=product_enemy_D14; product_enemy_D14=q; } { int q=product_enemy_D14; product_enemy_D14=q; } I4(0x20d)=d_1c2ed4+product_enemy_D14; }
                    else I4(0x20d) = d_1c2ed4 + (c - 10) * 0x73;
                }
                ok = 0;
                nx = (*p2);
                ny = (*p3);
                if (special) {
                    if (f_0735b0(t, ox, oy, &nx, &ny, p4)) ok = 1;
                } else {
                    if (chk_0738a0(t, ox, oy, nx, ny, p4) != 0) ok = 1;
                }
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
                if (ok == 1) {
                    i = 0;
                    while (P325[i] != NOID) {
                        f_07eba0(t + 0x39, P325[i], 0);
                        P325[i] = 0xff;
                        i++;
                    }
                    f_0758b0(t);
                    if (I4(0x20d) == 0 && I4(0x209) == 0) f_0762e0(0, 0x91, 0x64, 0xc7);
                    if (p4 > 1) {
                        short n = 0;
                        if (ox != nx || oy != ny) {
                            i = 1;
                            while (PATH[i + 1].x != -1) {{short w_grid_A20T=n;n=w_grid_A20T;}
                                int pathrow_D14=PATH[i].y*25; unsigned char *pathbase_D14=d_1bd984;
                                unsigned char *pathaddr_D14=pathbase_D14+pathrow_D14;
                                if (pathaddr_D14[PATH[i].x] != TFD) {
                                    SB(0x18) = (char)PATH[i].x;
                                    SB(0x19) = (char)PATH[i].y;
                                    P325[n++] = f_07ec10(t + 0x39, -1);
                                } else break;
                                i++;
                            }
                        }
                    }
                    if (special) {
                        if (UB(0x294) != NOID) f_07eba0(t + 0x39, UB(0x294), 0);
                        SB(0x18) = (char)nx;
                        SB(0x19) = (char)ny;
                        UB(0x294) = 0xff;
                    } else {
                        if (UB(0x294) != NOID) {
                            f_07eba0(t + 0x39, UB(0x294), 1);
                            SB(0x18) = (char)nx;
                            SB(0x19) = (char)ny;
                            f_07ec10(t + 0x39, SB(0x294));
                        } else {
                            SB(0x18) = (char)nx;
                            SB(0x19) = (char)ny;
                            SB(0x294) = f_07ec10(t + 0x39, -1);
                        }
                    }
                    f_0765a0(t);
                    f_075f10(t);
                } else {
                    f_0758b0(t);
                    if (I4(0x20d) == 0 && I4(0x209) == 0) f_0762e0(0, 0x91, 0x64, 0xc7);
                    i = 0;
                    while (P325[i] != NOID) {
                        f_07eba0(t + 0x39, P325[i], 0);
                        P325[i] = 0xff;
                        i++;
                    }
                    if (special) {
                        if (UB(0x294) != NOID) f_07eba0(t + 0x39, UB(0x294), 0);
                        SB(0x18) = (char)nx;
                        SB(0x19) = (char)ny;
                        UB(0x294) = 0xff;
                    } else {
                        if (UB(0x294) != NOID) {
                            f_07eba0(t + 0x39, UB(0x294), 1);
                            SB(0x18) = (char)nx;
                            SB(0x19) = (char)ny;
                            f_07ec10(t + 0x39, SB(0x294));
                        } else {
                            SB(0x18) = (char)nx;
                            SB(0x19) = (char)ny;
                            SB(0x294) = f_07ec10(t + 0x39, -1);
                        }
                    }
                    f_0765a0(t);
                    f_075f10(t);
                }
            }
        }
    } while (d_1bd766 != 0x1c0d && !done);
    if (UB(0x294) != NOID) f_07eba0(t + 0x39, UB(0x294), 0);
    UB(0x294) = 0xff;
    i = 0;
    while (P325[i] != NOID) {
        f_07eba0(t + 0x39, P325[i], 0);
        P325[i] = 0xff;
        i++;
    }
    I4(0x209) = 0;
    I4(0x20d) = 0;
    f_0758b0(t);
    f_0762e0(0, 0x91, 0x64, 0xc7);
    f_0765a0(t);
{int q_D14=ok; ok=q_D14;} // Haelt die Register- und Stapelfolge wie im Original: SAV402, Originalplatz der Rolle t770
    f_075f10(t);
    f_0d2710();
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
{int q_D11=ok; ok=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung



    if (!ok) {
        if (!done) {
            special = 0;
            { int gridrow_D14=ny*25; {int q=gridrow_D14;gridrow_D14=q;} {int q=gridrow_D14;gridrow_D14=q;} unsigned char *gridaddr_D14=d_1bd984+gridrow_D14; {unsigned char *q=gridaddr_D14;gridaddr_D14=q;} c=gridaddr_D14[nx]; }
            if (c == TFD || (c == 10 && f_0d06c0(d_1c2ed4))) {
                c = 10;
                special = 1;
            }
{int q_D11=special; special=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete Gewichtung
            if (c > 0 && c < 0x32) {
                                short r;
                short x0;
                short cnt;
                short y1;
                short y0;
                int hero;
                short x1;

                cnt = 0;
                int hr_D14=oy; int h24_D14=hr_D14*24; hr_D14+=h24_D14;
                unsigned char *base_D14=d_1bd984; {unsigned char *q=base_D14;base_D14=q;} {unsigned char *q=base_D14;base_D14=q;}
                unsigned char *row_D14=base_D14+hr_D14; {unsigned char *q=row_D14;row_D14=q;}
                hero = d_1bc8f0 + (row_D14[ox] - 1) * 0x5ef;
{int weight_A20T=hero;hero=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert


                r = F43410(hero);
{short q_D11=r; r=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung

                x0 = ox - r;
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x0;x0=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert


                y0 = oy - r;
                x1 = ox + r;


                y1 = oy + r;
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=y1;y1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert


                if (x0 < 0) x0 = 0;
                if (y0 < 0) y0 = 0;
                if (x1 > 0x18) x1 = 0x18;
                if (y1 > (short)0x18) y1 = 0x18;
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert
{short weight_A20T=x1;x1=weight_A20T;} // Haelt die Register- und Stapelfolge wie im Original: berechneter Nutzwert

{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
{short q_D11=x1; x1=q_D11;} // Haelt die Register- und Stapelfolge wie im Original: berechnete schmale Gewichtung
                SB(0x1e) = 0;
                SB(0x1f) = 0;
                SB(0x20) = 6;
                SB(0x24) = 0;
                I4(0x27) = 0;
                I4(0x2b) = I4(0x1f9);
                SB(0x22) = 1;
                SB(0x23) = 1;
                SB(0x25) = -1;
                for (cy = y0; cy < y1; cy++) {
                    for (cx = x0; cx < x1; cx++) {
                        int scan_y_D14=cy;
                        { int q=scan_y_D14; scan_y_D14=q; q=scan_y_D14; scan_y_D14=q; q=scan_y_D14; scan_y_D14=q; q=scan_y_D14; scan_y_D14=q; q=scan_y_D14; scan_y_D14=q; } { int q=scan_y_D14; scan_y_D14=q; }
                        int scan_row_D14=scan_y_D14*25;
                        unsigned char *scan_base_D14=d_1bd984;
                        { unsigned char *q=scan_base_D14; scan_base_D14=q; q=scan_base_D14; scan_base_D14=q; }
                        unsigned char *scan_addr_D14=scan_base_D14+scan_row_D14;
                        { unsigned char *q=scan_addr_D14; scan_addr_D14=q; q=scan_addr_D14; scan_addr_D14=q; } { unsigned char *q=scan_addr_D14; scan_addr_D14=q; }
                        if (!scan_addr_D14[cx]) {
                                            int adj;
                short d1;
                short d2;
 adj = 0;
                            ok = 0;
                            if (abs(scan_y_D14 - ny) == 1 && dx_A20T(cx,nx) == 1) adj = 1;
                            d1 = f_071e20(ox, oy, cx, ecx_seed_D14(cy));
                            d2 = f_071e20(nx, ny, cx, cy_dist_A20T(cy));
                            if (p5 < d2) ok = 1;
                            else if (d2 == 2 && p5 == 2) {
                                if (!adj || p6 == 1) ok = 1;
                            } else if (d2 == 1 && p5 == 1) ok = 1;
                            if (d1 <= r - p7 && ok == 1) {
                                ok = 0;
                                if (special) {
                                    if (f_0735b0(t, cx, cy, &nx, &ny, p4)) ok = 1;
                                } else {
                                    if (chk_second_D11(t, cx, nx, ny, cy, p4) != 0) ok = 1;
                                }
                                if (ok) {
                                                    short sel;
                short mode;

                                    f_07db20(t, hero, &cx, &cy, &ox, &oy, &mode, (char *)&sel);
                                    if (mode == 0) {
                                        SB(0x18) = (char)cx;
                                        SB(0x19) = (char)cy;
                                        P295[cnt++] = f_07ec10(t + 0x39, -1);
                                    }
                                }
                            }
                        }
                    }
                }
                if (cnt > 0) f_07b220(0x1010059);
                else f_07b220(0x101005a);
            }
        }
        return 0xff;
    }
    { int gridrow_D14=ny*25; {int q=gridrow_D14;gridrow_D14=q;} {int q=gridrow_D14;gridrow_D14=q;} unsigned char *gridaddr_D14=d_1bd984+gridrow_D14; {unsigned char *q=gridaddr_D14;gridaddr_D14=q;} c=gridaddr_D14[nx]; }
    if (c == TFD) {
        f_071e90(10, &cx, &cy);
        f_071e50(t, cx, cy, 0xfd);
        f_071e50(t, nx, ny, 10);
        c = 10;
    }
    (*p2) = nx;
    (*p3) = ny;
    return c;
}

//@ f_074680
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Rekonstruiert nach einer Breitensuche (f_074b40) vom gefundenen Zielfeld (x, y) aus rückwärts
 *   entlang der absteigenden Schrittweiten s1 im Distanzraster g vier mögliche kürzeste Wege (jeweils mit einer
 *   anderen bevorzugten Startrichtung 0..3), wählt über cnt_074680 denjenigen Pfad mit den wenigsten
 *   Richtungswechseln (Knicken) aus und kopiert die Schrittfolge in das globale Richtungsarray d_1bd950. Reichen
 *   die Bewegungspunkte s2 nicht für den gesamten Pfad, wird das Ende der erreichbaren Teilstrecke mit -2
 *   markiert. *(Hinweis: Prüft bei zweifeldrigen Figuren s4 != 0 den Inhalt des zweiten Körperfelds G2(ny2, nx2)
 *   vor der Prüfung, ob ny2 und nx2 im Bereich 0..23 liegen; siehe Fehlerliste.)*
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger t, das Distanzraster g, die Zielkoordinaten x und y, die
 *   Gesamtschrittzahl s1, die verfügbaren Bewegungspunkte s2, den Suchmodus s3, das Zweifeld-Flag s4 sowie den
 *   Basisindex s5 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Legt vier temporäre 50-Byte-Puffer buf[0..3] an und schreibt das beste Ergebnis (0..3 =
 *   Richtungsschritte, -1 = Ende, -2 = BP-Limit) in d_1bd950 (50 Bytes).
 === Ende Beschreibung === */
#define G2(yy, xx) (*(*(unsigned char **)(t + 0x3d3) + (yy) * 25 + (xx)))
#define G2V(yy, xx) (*(volatile unsigned char *)(*(unsigned char **)(t + 0x3d3) + (yy) * 25 + (xx)))
void *f_145300(void *p, int c, int n);
inline short cnt_074680(signed char *q)
{
    short n = 0;
    short j;
    if (*q == -1) return 99;
    j = 1;
    while (1) {
        if (q[j] == -1) break;
        if (q[j - 1] != q[j]) n++;
        j++;
    }
    return n;
}
void f_074680(int t, unsigned char *g, short x, short y, short s1, signed char s2, short s3, short s4, short s5)
{
    short v14 = 0;
    short v28;
    short orig_x;
    short v30;
    signed char *buf[4];
    short val;
    short orig_s1;
    short orig_y;
    short ny2 = 0; // Haelt die Register- und Stapelfolge wie im Original init (mutator2b)
    short i;
    short d;
    signed char *p;
    short dir[4][2];
    short k;
    short found;
    short ny;
    short v2c;
    short nx;
    short nx2;
    short c;
    s1=(s1&0)?(short)0:s1; // Haelt die Register- und Stapelfolge wie im Original: ausgerechneter s1-Nutzwert
    *(D4 *)dir = *(D4 *)d_1a1ce0;
    v28 = -1;
    v2c = 0;

    if (d_1bd928) f_069460();
    v30 = 99;
    buf[0] = (signed char *)f_014540(0x32, d_1a1cc0, 0x43);
    buf[1] = (signed char *)f_014540(0x32, d_1a1cc0, 0x44);
    buf[2] = (signed char *)f_014540(0x32, d_1a1cc0, 0x45);
    buf[3] = (signed char *)f_014540(0x32, d_1a1cc0, 0x46);
    val = GR(x, y);
    if (f_071f20(x, y)) v14 = 1;
    orig_s1 = s1;
    orig_x = x;
    orig_y = y;
    for (i = 0; i < 4; i++) {
        s1 = orig_s1;
        x = orig_x;
        y = orig_y;
        d = i;
        p = buf[i];
        k = s1;
        f_145300(p, -1, 0x32);
        p[k--] = -1;
        s1--;
        while (s1 >= 0) {
            if (d_1bd928) f_069460();
            found = 0;
            while (!found) {
                ny = y + dir[d][1];
                nx = x + dir[d][0];
                ny2 = ny;
                ny2 += dir[d][1];
                nx2 = nx + dir[d][0];
                if (ny < (short)0x18 && ny >= 0 && nx < 0x18 && nx >= 0) {
                    val = *(g + ny * 25 + nx);
#if FIX_R039   /* R039: Feldgrenzen ny2/nx2 (0..23) vor dem Zugriff auf G2V(ny2, nx2) pruefen */
                    if (val == s1 && (!s4 || (s4 && ny2 < (short)0x18 && ny2 >= 0 && nx2 < 0x18 && nx2 >= 0 && (!G2V(ny2, nx2) || G2(ny2, nx2) == s5 + 10 || G2(ny2, nx2) == s5 + 0x1e)))) {
#else
                    if (val == s1 && (!s4 || (s4 && (!G2V(ny2, nx2) || G2(ny2, nx2) == s5 + 10 || G2(ny2, nx2) == s5 + 0x1e) && ny2 < (short)0x18 && ny2 >= 0 && nx2 < 0x18 && nx2 >= 0))) {
#endif
                        y = ny;
                        x = nx;
                        if (s2 <= s1) {
                            p[k--] = -1;
                            v2c = 1;
                            v2c = (v2c & 0) ? 0 : v2c; // Haelt die Register- und Stapelfolge wie im Original dreier_null (mutator2b)
                        } else {
                            p[k--] = (signed char)d;
                        }
                        s1--;
                        found = 1;
                    }
                }
                if (!found) {
                    d++;
                    if (d == 4) d = 0;
                }
            }
        }
        if (orig_s1 <= s2 && !v14 && s3 < 9) {
            p[orig_s1 - 1] = -1;
        }
        if (*p != -1) {
            c = cnt_074680(p);
            if (c < v30) {
                v28 = i;
                v30 = c;
                if (!c) break;
            }
        }
    }
    if (v28 < 0 || v28 > 3) v28 = 0;
    memcpy(d_1bd950, buf[v28], 0x32);
    if (v2c) {
        i = 0;
        while (d_1bd950[i++] != -1)
            ;
        d_1bd950[i - 1] = -2;
    }
    delete buf[0];
    delete buf[1];
    delete buf[2];
    delete buf[3];
    if (d_1bd928) f_069460();
}

//@ f_074a50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt die Anzahl der Richtungswechsel (Knicke) innerhalb einer mit -1 terminierten
 *   Schrittfolge p, damit Figuren auf dem Kampffeld möglichst geradlinige Wege wählen.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger a und das Richtungsarray p (signed char *) und gibt die
 *   Anzahl der Richtungswechsel (int, oder 99 bei leerem Pfad *p == -1) zurück.
 * - Wichtige Variablen: Vergleicht fortlaufend p[j - 1] mit p[j].
 === Ende Beschreibung === */
int f_074a50(int a, signed char *p)
{
    int n = 0;
    short j;
    if (*p == -1) return 99;
    j = 1;
    while (1) {
        if (p[j] == -1) break;
        if (p[j - 1] != p[j]) n++;
        j++;
    }
    return n;
}
