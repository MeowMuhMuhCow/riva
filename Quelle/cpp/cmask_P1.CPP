/* === Beschreibung (Katalog) ===
 * Einheit cmask (0x049da0 - 0x04b5f0)
 *
 * Überblick
 * Die Einheit cmask implementiert den ersten Teil des Charakterblatts und Inventarbildschirms (CMask): Sie
 * initialisiert die Klick-Rechtecke aller 31 Ausrüstungs- und Rucksackslots, lädt beim Öffnen des
 * Charakterblatts die benötigten Hintergrund-, Rahmen-, Körper- und Symbolgrafiken aus dem Archiv 0x3000b,
 * verwandelt den Mauszeiger beim Aufnehmen eines Gegenstands in dessen 16x16-Icon, markiert kompatible
 * Ausrüstungsplätze am Körper grün und zeichnet die Slot-Rahmen samt Gegenstandsbezeichnung in der Fußzeile.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAITEX.H"
// P3 9/10 gleich (suche.py 29.10.2026, Basis cmask_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 4 gleich (vorher 4), Rest 287 (vorher 303)
// cmask.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x049DA0-0x04B5F0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_033250(int p1, int p2);                           // reg edx stapel 0
int f_033260(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_033450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
                         // reg eax edx stapel 0
int f_045960(int p1, int p2);                           // reg eax edx stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3080(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int f_0d3530(int p1);                                   // reg eax stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0e9300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a0f28[];           // Text 0x1A0F28
int f_014540(int, const char *, int);
int f_1459b0(int);
int f_1459d0(int, int);

struct Reg { char b[32]; void f_04feb0(int id, int r, int z, int idx, int z2, void *a, void *b2, int n); };
extern Reg d_1c2be0;
struct Vp { char b[1]; void f_1481a0(void *d, int x, int y, int w, int h, int c); };
extern Vp d_1bdbd4;
short f_149360(int, char *);
void f_04b0d0(char *self, void *p2, short p3, short p4);
extern const char d_1a0f28[];
extern char d_1a0f46[];
extern short d_1a0f50[], d_1a0f52[];
extern char d_1a0fd4[], d_1a10ec[];
extern void *d_1a34e0;
extern char d_1bc92c;
extern signed char d_1bc930;
extern short d_1bc92d;
extern short d_1bc931;
extern char *d_1bc89c, *d_1bc8a0, *d_1bc928;
extern volatile int d_1bc940;
extern signed char d_1bf4ef;
extern short d_1c212a;
extern volatile short d_1c2198;
extern int *d_1c212c;
extern int d_1c2a80;

extern char d_1c21b4[], d_1c2e78[], d_1c38b0[];
extern short d_1a126e, d_1a0fd2;
extern short d_1a0f54;
extern short d_1a0f56;
extern short d_1a0f58;
extern short d_1a0f5a;
extern short d_1a0f5c;
extern short d_1a0f5e;
extern short d_1a0f60;
extern short d_1a0f62;
extern short d_1a0f64;
extern short d_1a0f66;
extern short d_1a0f68;
extern short d_1a0f6a;
extern short d_1a0f6c;
extern short d_1a0f6e;
extern short d_1a0f70;
extern short d_1a0f72;
extern short d_1a0f74;
extern short d_1a0f76;
extern short d_1a0f78;
extern short d_1a0f7a;
extern short d_1a0f7c;
extern short d_1a0f7e;
extern short d_1a0f80;
extern short d_1a0f82;
extern short d_1a0f84;
extern short d_1a0f86;
extern short d_1a0f88;
extern short d_1a0f8a;
extern short d_1a0f8c;
extern short d_1a0f8e;
extern short d_1a0f90;
extern short d_1a0f92;
extern short d_1a0f94;
extern short d_1a0f96;
extern short d_1a0f98;
extern short d_1a0f9a;
extern short d_1a0f9c;
extern short d_1a0f9e;
extern short d_1a0fa0;
extern short d_1a0fa2;
extern short d_1a0fa4;
extern short d_1a0fa6;
extern short d_1a0fa8;
extern short d_1a0faa;
extern short d_1a0fac;
extern short d_1a0fae;
extern short d_1a0fb0;
extern short d_1a0fb2;
extern short d_1a0fb4;
extern short d_1a0fb6;
extern short d_1a0fb8;
extern short d_1a0fba;
extern short d_1a0fbc;
extern short d_1a0fbe;
extern short d_1a0fc0;
extern short d_1a0fc2;
extern short d_1a0fc4;
extern short d_1a0fc6;
extern short d_1a0fc8;
extern short d_1a0fca;
extern short d_1a0fcc;
extern short d_1a0fce;
extern short d_1a0fd0;
extern short d_1a0fd2;
extern short d_1a1038;
extern short d_1a103a;
extern short d_1a103c;
extern short d_1a103e;
extern short d_1a1042;
extern short d_1a1044;
extern short d_1a1046;
extern short d_1a1048;
extern short d_1a104c;
extern short d_1a104e;
extern short d_1a1050;
extern short d_1a1052;
extern short d_1a1056;
extern short d_1a1058;
extern short d_1a105a;
extern short d_1a105c;
extern short d_1a1060;
extern short d_1a1062;
extern short d_1a1064;
extern short d_1a1066;
extern short d_1a106a;
extern short d_1a106c;
extern short d_1a106e;
extern short d_1a1070;
extern short d_1a1074;
extern short d_1a1076;
extern short d_1a1078;
extern short d_1a107a;
extern short d_1a107e;
extern short d_1a1080;
extern short d_1a1082;
extern short d_1a1084;
extern short d_1a1088;
extern short d_1a108a;
extern short d_1a108c;
extern short d_1a108e;
extern short d_1a1092;
extern short d_1a1094;
extern short d_1a1096;
extern short d_1a1098;
extern short d_1a109c;
extern short d_1a109e;
extern short d_1a10a0;
extern short d_1a10a2;
extern short d_1a10a6;
extern short d_1a10a8;
extern short d_1a10aa;
extern short d_1a10ac;
extern short d_1a10b0;
extern short d_1a10b2;
extern short d_1a10b4;
extern short d_1a10b6;
extern short d_1a10ba;
extern short d_1a10bc;
extern short d_1a10be;
extern short d_1a10c0;
extern short d_1a10c4;
extern short d_1a10c6;
extern short d_1a10c8;
extern short d_1a10ca;
extern short d_1a10ce;
extern short d_1a10d0;
extern short d_1a10d2;
extern short d_1a10d4;
extern short d_1a1128;
extern short d_1a112a;
extern short d_1a112c;
extern short d_1a112e;
extern short d_1a1132;
extern short d_1a1134;
extern short d_1a1136;
extern short d_1a1138;
extern short d_1a113c;
extern short d_1a113e;
extern short d_1a1140;
extern short d_1a1142;
extern short d_1a1146;
extern short d_1a1148;
extern short d_1a114a;
extern short d_1a114c;
extern short d_1a1150;
extern short d_1a1152;
extern short d_1a1154;
extern short d_1a1156;
extern short d_1a115a;
extern short d_1a115c;
extern short d_1a115e;
extern short d_1a1160;
extern short d_1a1164;
extern short d_1a1166;
extern short d_1a1168;
extern short d_1a116a;
extern short d_1a116e;
extern short d_1a1170;
extern short d_1a1172;
extern short d_1a1174;
extern short d_1a1178;
extern short d_1a117a;
extern short d_1a117c;
extern short d_1a117e;
extern short d_1a1182;
extern short d_1a1184;
extern short d_1a1186;
extern short d_1a1188;
extern short d_1a118c;
extern short d_1a118e;
extern short d_1a1190;
extern short d_1a1192;
extern short d_1a1196;
extern short d_1a1198;
extern short d_1a119a;
extern short d_1a119c;
extern short d_1a11a0;
extern short d_1a11a2;
extern short d_1a11a4;
extern short d_1a11a6;
extern short d_1a11aa;
extern short d_1a11ac;
extern short d_1a11ae;
extern short d_1a11b0;
extern short d_1a11b4;
extern short d_1a11b6;
extern short d_1a11b8;
extern short d_1a11ba;
extern short d_1a11be;
extern short d_1a11c0;
extern short d_1a11c2;
extern short d_1a11c4;
extern short d_1a11c8;
extern short d_1a11ca;
extern short d_1a11cc;
extern short d_1a11ce;
extern short d_1a11d2;
extern short d_1a11d4;
extern short d_1a11d6;
extern short d_1a11d8;
extern short d_1a11dc;
extern short d_1a11de;
extern short d_1a11e0;
extern short d_1a11e2;
extern short d_1a11e6;
extern short d_1a11e8;
extern short d_1a11ea;
extern short d_1a11ec;
extern short d_1a11f0;
extern short d_1a11f2;
extern short d_1a11f4;
extern short d_1a11f6;
extern short d_1a11fa;
extern short d_1a11fc;
extern short d_1a11fe;
extern short d_1a1200;
extern short d_1a1204;
extern short d_1a1206;
extern short d_1a1208;
extern short d_1a120a;
extern short d_1a120e;
extern short d_1a1210;
extern short d_1a1212;
extern short d_1a1214;
extern short d_1a1218;
extern short d_1a121a;
extern short d_1a121c;
extern short d_1a121e;
extern short d_1a1222;
extern short d_1a1224;
extern short d_1a1226;
extern short d_1a1228;
extern short d_1a122c;
extern short d_1a122e;
extern short d_1a1230;
extern short d_1a1232;
extern short d_1a1236;
extern short d_1a1238;
extern short d_1a123a;
extern short d_1a123c;
extern short d_1a1240;
extern short d_1a1242;
extern short d_1a1244;
extern short d_1a1246;
extern short d_1a124a;
extern short d_1a124c;
extern short d_1a124e;
extern short d_1a1250;
extern short d_1a1254;
extern short d_1a1256;
extern short d_1a1258;
extern short d_1a125a;
extern short d_1a125e;
extern short d_1a1260;
extern short d_1a1262;
extern short d_1a1264;
extern short d_1a1268;
extern short d_1a126a;
extern short d_1a126c;
#define S16(p,o) (*(short*)((p)+(o)))
#define S32(p,o) (*(int*)((p)+(o)))
#define IMG(p,o) ((RivaRasterImage*)S32(p,o))

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_049da0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet beim Programmstart aus den X/Y-Startkoordinaten der 31 Inventarslots (d_1a0f50,
 *   d_1a0f52 bis d_1a0fd2) die 18x18 Pixel großen Klick-Rechtecke (+ 0x11 in Breite und Höhe) für die
 *   Maus-Trefferabfrage auf dem Charakterblatt und registriert die beiden Konfigurationsflags d_1bc92c (Kennung
 *   0x13) und d_1bc930 (Kennung 0x14, Anzeige der Körper-Ausrüstungsslots ein/aus) in der Spielstandsliste
 *   d_1c212c.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Initialisiert die Hitbox-Tabellen d_1a1038 bis d_1a126e und registriert d_1bc92c sowie
 *   d_1bc930.
 === Ende Beschreibung === */
void f_049da0()
{
    d_1a1038 = d_1a0f8c;
    d_1a103a = d_1a0f8e;
    d_1a103c = d_1a0f8c + 0x11;
    d_1a103e = d_1a0f8e + 0x11;
    d_1a1042 = d_1a0f90;
    d_1a1044 = d_1a0f92;
    d_1a1046 = d_1a0f90 + 0x11;
    d_1a1048 = d_1a0f92 + 0x11;
    d_1a104c = d_1a0f94;
    d_1a104e = d_1a0f96;
    d_1a1050 = d_1a0f94 + 0x11;
    d_1a1052 = d_1a0f96 + 0x11;
    d_1a1056 = d_1a0f98;
    d_1a1058 = d_1a0f9a;
    d_1a105a = d_1a0f98 + 0x11;
    d_1a105c = d_1a0f9a + 0x11;
    d_1a1060 = d_1a0f9c;
    d_1a1062 = d_1a0f9e;
    d_1a1064 = d_1a0f9c + 0x11;
    d_1a1066 = d_1a0f9e + 0x11;
    d_1a106a = d_1a0fa0;
    d_1a106c = d_1a0fa2;
    d_1a106e = d_1a0fa0 + 0x11;
    d_1a1070 = d_1a0fa2 + 0x11;
    d_1a1074 = d_1a0fa4;
    d_1a1076 = d_1a0fa6;
    d_1a1078 = d_1a0fa4 + 0x11;
    d_1a107a = d_1a0fa6 + 0x11;
    d_1a107e = d_1a0fa8;
    d_1a1080 = d_1a0faa;
    d_1a1082 = d_1a0fa8 + 0x11;
    d_1a1084 = d_1a0faa + 0x11;
    d_1a1088 = d_1a0fac;
    d_1a108a = d_1a0fae;
    d_1a108c = d_1a0fac + 0x11;
    d_1a108e = d_1a0fae + 0x11;
    d_1a1092 = d_1a0fb0;
    d_1a1094 = d_1a0fb2;
    d_1a1096 = d_1a0fb0 + 0x11;
    d_1a1098 = d_1a0fb2 + 0x11;
    d_1a109c = d_1a0fb4;
    d_1a109e = d_1a0fb6;
    d_1a10a0 = d_1a0fb4 + 0x11;
    d_1a10a2 = d_1a0fb6 + 0x11;
    d_1a10a6 = d_1a0fb8;
    d_1a10a8 = d_1a0fba;
    d_1a10aa = d_1a0fb8 + 0x11;
    d_1a10ac = d_1a0fba + 0x11;
    d_1a10b0 = d_1a0fbc;
    d_1a10b2 = d_1a0fbe;
    d_1a10b4 = d_1a0fbc + 0x11;
    d_1a10b6 = d_1a0fbe + 0x11;
    d_1a10ba = d_1a0fc0;
    d_1a10bc = d_1a0fc2;
    d_1a10be = d_1a0fc0 + 0x11;
    d_1a10c0 = d_1a0fc2 + 0x11;
    d_1a10c4 = d_1a0fc4;
    d_1a10c6 = d_1a0fc6;
    d_1a10c8 = d_1a0fc4 + 0x11;
    d_1a10ca = d_1a0fc6 + 0x11;
    d_1a10ce = d_1a0fc8;
    d_1a10d0 = d_1a0fca;
    d_1a10d2 = d_1a0fc8 + 0x11;
    d_1a10d4 = d_1a0fca + 0x11;
    d_1a1128 = d_1a0f50[0];
    d_1a112a = d_1a0f52[0];
    d_1a112c = d_1a0f50[0] + 0x11;
    d_1a112e = d_1a0f52[0] + 0x11;
    d_1a1132 = d_1a0f54;
    d_1a1134 = d_1a0f56;
    d_1a1136 = d_1a0f54 + 0x11;
    d_1a1138 = d_1a0f56 + 0x11;
    d_1a113c = d_1a0f58;
    d_1a113e = d_1a0f5a;
    d_1a1140 = d_1a0f58 + 0x11;
    d_1a1142 = d_1a0f5a + 0x11;
    d_1a1146 = d_1a0f5c;
    d_1a1148 = d_1a0f5e;
    d_1a114a = d_1a0f5c + 0x11;
    d_1a114c = d_1a0f5e + 0x11;
    d_1a1150 = d_1a0f60;
    d_1a1152 = d_1a0f62;
    d_1a1154 = d_1a0f60 + 0x11;
    d_1a1156 = d_1a0f62 + 0x11;
    d_1a115a = d_1a0f64;
    d_1a115c = d_1a0f66;
    d_1a115e = d_1a0f64 + 0x11;
    d_1a1160 = d_1a0f66 + 0x11;
    d_1a1164 = d_1a0f68;
    d_1a1166 = d_1a0f6a;
    d_1a1168 = d_1a0f68 + 0x11;
    d_1a116a = d_1a0f6a + 0x11;
    d_1a116e = d_1a0f6c;
    d_1a1170 = d_1a0f6e;
    d_1a1172 = d_1a0f6c + 0x11;
    d_1a1174 = d_1a0f6e + 0x11;
    d_1a1178 = d_1a0f70;
    d_1a117a = d_1a0f72;
    d_1a117c = d_1a0f70 + 0x11;
    d_1a117e = d_1a0f72 + 0x11;
    d_1a1182 = d_1a0f74;
    d_1a1184 = d_1a0f76;
    d_1a1186 = d_1a0f74 + 0x11;
    d_1a1188 = d_1a0f76 + 0x11;
    d_1a118c = d_1a0f78;
    d_1a118e = d_1a0f7a;
    d_1a1190 = d_1a0f78 + 0x11;
    d_1a1192 = d_1a0f7a + 0x11;
    d_1a1196 = d_1a0f7c;
    d_1a1198 = d_1a0f7e;
    d_1a119a = d_1a0f7c + 0x11;
    d_1a119c = d_1a0f7e + 0x11;
    d_1a11a0 = d_1a0f80;
    d_1a11a2 = d_1a0f82;
    d_1a11a4 = d_1a0f80 + 0x11;
    d_1a11a6 = d_1a0f82 + 0x11;
    d_1a11aa = d_1a0f84;
    d_1a11ac = d_1a0f86;
    d_1a11ae = d_1a0f84 + 0x11;
    d_1a11b0 = d_1a0f86 + 0x11;
    d_1a11b4 = d_1a0f88;
    d_1a11b6 = d_1a0f8a;
    d_1a11b8 = d_1a0f88 + 0x11;
    d_1a11ba = d_1a0f8a + 0x11;
    d_1a11be = d_1a0f8c;
    d_1a11c0 = d_1a0f8e;
    d_1a11c2 = d_1a103c;
    d_1a11c4 = d_1a103e;
    d_1a11c8 = d_1a0f90;
    d_1a11ca = d_1a0f92;
    d_1a11cc = d_1a1046;
    d_1a11ce = d_1a1048;
    d_1a11d2 = d_1a0f94;
    d_1a11d4 = d_1a0f96;
    d_1a11d6 = d_1a1050;
    d_1a11d8 = d_1a1052;
    d_1a11dc = d_1a0f98;
    d_1a11de = d_1a0f9a;
    d_1a11e0 = d_1a105a;
    d_1a11e2 = d_1a105c;
    d_1a11e6 = d_1a0f9c;
    d_1a11e8 = d_1a0f9e;
    d_1a11ea = d_1a1064;
    d_1a11ec = d_1a1066;
    d_1a11f0 = d_1a0fa0;
    d_1a11f2 = d_1a0fa2;
    d_1a11f4 = d_1a106e;
    d_1a11f6 = d_1a1070;
    d_1a11fa = d_1a0fa4;
    d_1a11fc = d_1a0fa6;
    d_1a11fe = d_1a1078;
    d_1a1200 = d_1a107a;
    d_1a1204 = d_1a0fa8;
    d_1a1206 = d_1a0faa;
    d_1a1208 = d_1a1082;
    d_1a120a = d_1a1084;
    d_1a120e = d_1a0fac;
    d_1a1210 = d_1a0fae;
    d_1a1212 = d_1a108c;
    d_1a1214 = d_1a108e;
    d_1a1218 = d_1a0fb0;
    d_1a121a = d_1a0fb2;
    d_1a121c = d_1a1096;
    d_1a121e = d_1a1098;
    d_1a1222 = d_1a0fb4;
    d_1a1224 = d_1a0fb6;
    d_1a1226 = d_1a10a0;
    d_1a1228 = d_1a10a2;
    d_1a122c = d_1a0fb8;
    d_1a122e = d_1a0fba;
    d_1a1230 = d_1a10aa;
    d_1a1232 = d_1a10ac;
    d_1a1236 = d_1a0fbc;
    d_1a1238 = d_1a0fbe;
    d_1a123a = d_1a10b4;
    d_1a123c = d_1a10b6;
    d_1a1240 = d_1a0fc0;
    d_1a1242 = d_1a0fc2;
    d_1a1244 = d_1a10be;
    d_1a1246 = d_1a10c0;
    d_1a124a = d_1a0fc4;
    d_1a124c = d_1a0fc6;
    d_1a124e = d_1a10c8;
    d_1a1250 = d_1a10ca;
    d_1a1254 = d_1a0fc8;
    d_1a1256 = d_1a0fca;
    d_1a1258 = d_1a10d2;
    d_1a125a = d_1a10d4;
    d_1a125e = d_1a0fcc;
    d_1a1260 = d_1a0fce;
    d_1a1262 = d_1a0fcc + 0x12;
    d_1a1264 = d_1a0fce + 0xc;
    d_1a1268 = d_1a0fd0;
    d_1a126a = d_1a0fd2;
    d_1a126c = d_1a0fd0 + 0x12;
    d_1a126e = d_1a0fd2 + 0xc;
    {
        struct Obj { signed char flag; short id; };
        struct H {
            static inline void first(Obj *p, short *n, int * &t, short k, char v) {
                p->id = k;
                p->flag = v;
                t[*n] = (int)p;
            }
            static inline void slot(int offset, int *base, Obj *p) { *(int *)(offset + (int)base) = (int)p; }
            static inline void put(Obj *p, short *n, int * &t, short k, char v) {
                ++*n;
                p->id = k;
                int i = *n;
                p->flag = v;
                slot(i * 4, t, p);
            }
        };
        H::first((Obj *)&d_1bc92c, &d_1c212a, (int *&)d_1c212c, 0x13, 0);
        H::put((Obj *)&d_1bc930, &d_1c212a, (int *&)d_1c212c, 0x14, 0);
        ++d_1c212a;
    }
}
//@ f_04a890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert das Charakterblatt-Fensterobjekt (self), allokiert den 64000 Byte großen
 *   Hintergrundpuffer (320x200) sowie dreizehn RivaRasterImage-Hilfspuffer (für Körperansicht, Rahmen,
 *   Rollbalken, Gegenstands-Icons und Textzeile) und lädt die Grafikelemente aus dem Archiv 0x3000b.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) und gibt den initialisierten Zeiger
 *   zurück.
 * - Wichtige Variablen: Speichert die erzeugten RivaRasterImage-Zeiger in self + 0xea bis self + 0x11e,
 *   allokiert die Hilfspuffer d_1bc89c und d_1bc8a0 und setzt d_1bc928 = self.
 === Ende Beschreibung === */
char *f_04a890(char *self)
{
    self = (char*)f_1459b0((int)(self + 0x47)) - 0x47;
    S16(self,0x126) = f_0d40b6((int)d_1c2e78);
    f_0d3f25((int)d_1c2e78, 4);
    S32(self,0x11e) = f_014540(64000, d_1a0f28, 0x96);
    S32(self,0xea) = (int)new (mark(d_1a0f28, 0x98)) RivaRasterImage(0x140, 200, (unsigned char*)S32(self,0x11e));
    S32(self,0x112) = (int)new (mark(d_1a0f28, 0x99)) RivaRasterImage(0x140, 8);
    S32(self,0xee) = (int)new (mark(d_1a0f28, 0x9a)) RivaRasterImage(0x20, 0x20, 0);
    S32(self,0xf2) = (int)new (mark(d_1a0f28, 0x9b)) RivaRasterImage(0x10, 0x10);
    S32(self,0xf6) = (int)new (mark(d_1a0f28, 0x9c)) RivaRasterImage(0x62, 0xa4);
    S32(self,0xfa) = (int)new (mark(d_1a0f28, 0x9d)) RivaRasterImage(0x83, 0x15);
    S32(self,0xfe) = (int)new (mark(d_1a0f28, 0x9e)) RivaRasterImage(0x83, 0x15);
    S32(self,0x102) = (int)new (mark(d_1a0f28, 0x9f)) RivaRasterImage(0x12, 0x12);
    S32(self,0x10e) = (int)new (mark(d_1a0f28, 0xa0)) RivaRasterImage(0x12, 0x12);
    S32(self,0x106) = (int)new (mark(d_1a0f28, 0xa1)) RivaRasterImage(0x12, 0x12);
    S32(self,0x10a) = (int)new (mark(d_1a0f28, 0xa2)) RivaRasterImage(0x12, 0x12);
    S32(self,0x116) = (int)new (mark(d_1a0f28, 0xa3)) RivaRasterImage(0x15, 0x14);
    S32(self,0x11a) = (int)new (mark(d_1a0f28, 0xa4)) RivaRasterImage(0x15, 0x14);
    d_1bc89c = (char*)f_014540(0x68, d_1a0f28, 0xa6);
    d_1bc8a0 = (char*)f_014540(0xac, d_1a0f28, 0xa7);
    memset(self + 0x28, 0, 0x1f);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0xf6)))->f_0fb0b0())), 0, 0, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0x102)))->f_0fb0b0())), 0, 1, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0x10e)))->f_0fb0b0())), 0, 2, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0x106)))->f_0fb0b0())), 0, 3, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0x10a)))->f_0fb0b0())), 0, 4, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0x116)))->f_0fb0b0())), 0, 5, 0, self + 7, self + 7, 0x140);
    d_1c2be0.f_04feb0(0x3000b, ((int)(((RivaRasterImage*)(IMG(self,0xfa)))->f_0fb0b0())), 0, 0x12, 0, self + 7, self + 7, 0x140);
    *(signed char*)(self + 0x1f) = 0;
    S16(self,3) = 1;
    S16(self,0x20) = 0xf;
    short v = *(signed char*)(self + 0x1f);
    S16(self,0x1d) = v;
    S16(self,0x17) = v;
    d_1bc940 = 0;
    S16(self,1) = v;
    if (d_1bf4ef == 0) S16(self,0x20) = -1;
    S16(self,9) = -1;
    S16(self,0x26) = S16(self,9);
    S16(self,0x22) = S16(self,9);
    d_1bc928 = self;
    S16(self,0x24) = S16(self,9);
    return self;
}

//@ f_04ad40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Schließen des Charakterblatts als Destruktor sämtliche in f_04a890 angelegten
 *   RivaRasterImage-Objekte, den 64000-Byte-Puffer sowie d_1bc89c und d_1bc8a0 wieder frei, stellt den
 *   vorherigen Mausmodus (S16(self, 0x126)) wieder her und markiert den Hauptbildschirm über d_1c2198 = 1 zur
 *   Neuzeichnung.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) sowie ein Destruktor-Flag (kp2) und gibt
 *   den bereinigten Basisklassenzeiger zurück.
 * - Wichtige Variablen: Löscht d_1bc89c, d_1bc8a0, die Bildpuffer 0xea-0x11e und setzt d_1c2a80 = 0 sowie
 *   d_1c2198 = 1.
 === Ende Beschreibung === */
char *f_04ad40(char *self, int kp2)
{
    delete d_1bc89c;
    delete d_1bc8a0;
    delete IMG(self,0x11a);
    delete IMG(self,0x116);
    delete IMG(self,0x10a);
    delete IMG(self,0x106);
    delete IMG(self,0x10e);
    delete IMG(self,0x102);
    delete IMG(self,0xf6);
    delete IMG(self,0xfa);
    delete IMG(self,0xfe);
    delete IMG(self,0xf2);
    delete IMG(self,0xee);
    delete IMG(self,0x112);
    delete IMG(self,0xea);
    delete (char*)S32(self,0x11e);
    S32(self,0x11e) = 0;
    S32(self,0xf) = 0;
    S32(self,0x13) = 0;
    d_1c2a80 = 0;
    S32(self,0xb) = S32(self,0xf);
    d_1c2198 = 1;
    f_0d3f25((int)d_1c2e78, S16(self,0x126));
    return (char*)f_1459d0((int)(self + 0x47), 0) - 0x47;
}

//@ f_04aee0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Adresse des 64000 Byte großen Hintergrund-Bildpuffers (S32(self, 0x11e)) des
 *   Charakterblatts zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) sowie zwei ungenutzte Parameter (kp2,
 *   kp3) und gibt den Pufferzeiger als int zurück.
 * - Wichtige Variablen: Liest S32(self, 0x11e).
 === Ende Beschreibung === */
int f_04aee0(char *self, int kp2, int kp3)
{
    return S32(self,0x11e);
}

//@ f_04aef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das 16x16-Grafiksymbol des Gegenstands p2 aus dem Icon-Archiv 0x50002 in den Puffer
 *   IMG(self, 0xf2) und setzt dieses Bild über f_0d3080 als aktuellen Mauszeiger (mit Hotspot 8, 8), solange ein
 *   Gegenstand im Inventar gezogen wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) sowie die Grafikkennung des Gegenstands
 *   (p2) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Speichert die aktuelle Icon-Kennung in S16(self, 9) und nutzt d_1c2be0.
 === Ende Beschreibung === */
void f_04aef0(char *self, short p2)
{
    if (d_1bf4ef == 0 && p2 != -1) {
        S16(self,9) = p2;
        d_1c2be0.f_04feb0(0x50002, ((int)(((RivaRasterImage*)(IMG(self,0xf2)))->f_0fb0b0())), 0, p2, 0, self + 7, self + 7, 0x140);
        f_0d3080(((int)(((RivaRasterImage*)(IMG(self,0xf2)))->f_0fb0b0())), 0x10, 0x10, 8, 8, 1);
    }
}

//@ f_04af60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den gezogenen Gegenstands-Mauszeiger wieder auf den normalen Pfeilcursor (f_0d2f90(0,
 *   1)) zurück und trägt -1 in S16(self, 9) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Setzt S16(self, 9) = -1.
 === Ende Beschreibung === */
void f_04af60(char *self)
{
    S16(self,9) = -1;
    f_0d2f90(0, 1);
}

//@ f_04af80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für einen im Inventar ausgewählten Gegenstand (S16(self, 0x20)), an welchen der 15
 *   Körper-Ausrüstungsplätze (0 bis 14) des angezeigten Helden (S32(self, 0xb)) dieser angelegt werden darf
 *   (f_033250, f_033260, f_033450), und markiert die zulässigen Slots im Array self[0x28 + i] mit dem Farbwert
 *   0xfc (grüner Rahmen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das 15-Byte-Markierungsarray self + 0x28.
 === Ende Beschreibung === */
void f_04af80(char *self)
{
    short loc = 0;
    short i;
    if (S16(self,0x22) != -1)
        loc = f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20));
    if (loc != (short)0) {
        if (f_033250(S32(self,0xb), loc) == 0) loc = 0;
    }
    for (i = 0; i < 0xf; i++) {
        if (loc == (short)0) {
            self[0x28 + i] = 0;
        } else if (f_033260(S32(self,0xb), loc, i) == 0) {
            self[0x28 + i] = 0;
        } else if (f_033450(S32(self,0xb), loc, i, S32(self,0xb), S16(self,0x20)) != 0) {
            self[0x28 + i] = 0;
        } else {
            self[0x28 + i] = 0xfc;
        }
    }
}

//@ f_04b050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Rahmen aller 15 Körper-Ausrüstungsplätze (0 bis 14) über f_04b0d0 neu, sofern die
 *   Körperansicht eingeblendet ist (d_1bc930 == 1) und das Charakterblatt im Hauptmodus (d_1c2a80 == 0x30000)
 *   steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self) sowie die Ziel-Zeichenfläche (p2) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d_1bc930 und d_1c2a80 unter Schutz des Maus-Locks (f_0d2710/f_0d26e0).
 === Ende Beschreibung === */
void f_04b050(char *self, void *p2)
{
    short i;
    int flag, t;
    if (f_0d3860() == 1) { f_0d2710(); flag = 1; } else flag = 0;
    t = (d_1bc930 == 1);
    if (t != 0 && *(signed char*)(self + 0x1f) == 0 && d_1c2a80 == 0x30000) {
        for (i = 0; i < 0xf; i++) f_04b0d0(self, p2, i, 0);
    }
    if (flag == 1) f_0d26e0();
}

//@ f_04b0d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet den Auswahlrahmen um den Inventar- oder Körperslot p3 (Farbe/Rahmentyp p4: normal,
 *   grün hervorgehoben oder aktiv selektiert 0xfd) und gibt beim ausgewählten Slot zusätzlich am unteren
 *   Bildschirmrand (Y = 192) den Namen des dort liegenden Gegenstands aus-ergänzt um den Hinweis (nicht passend)
 *   (0x3040001), falls der Held ihn nicht tragen darf (f_045960 == 0), oder um das zugehörige Waffentalent
 *   (0x2000005c + wtype), falls es sich um eine Waffe handelt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (self), die Ziel-Zeichenfläche (p2), den
 *   Slot-Index (p3) und den Rahmenstatus (p4) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest die Slot-Koordinaten d_1a0f50/d_1a0f52, die Gegenstandsdatenbank d_1c2c40 und gibt
 *   den Namen über d_1c38b0 im Puffer d_1c21b4 aus.
 === Ende Beschreibung === */
void f_04b0d0(char *self, void *p2, short p3, short p4)
{
#pragma aux f_05e320 parm [eax] [edx] [ebx] modify exact [eax edx ebx]
    short y, x;
    int pass;
    char enabled, ok;
    struct H {
        static inline int first(short i, int *base) { return base[i]; }
        static inline int item(int offset, int *base) { return *(int *)(offset + (int)base); }
    };
    if (p3 == -1) return;
    enabled = !d_1bc930;
    ok = enabled && p3 >= 0xf && p3 < (short)0x1f;
    pass = d_1bc930 || ok;
    if (!pass) return;

    if (p2 == d_1a34e0 && f_149360(p3, d_1a0f46) != -1)
        IMG(self,0x112)->f_0fade0(p2, 0, 0xc0);

    x = d_1a0f50[p3 * 2];
    y = d_1a0f52[p3 * 2];
    if (p3 >= 0 && p3 < (short)0x1f) {
        if (p4 == 0) {
            if (self[0x28 + p3] == (char)0)
                IMG(self,0x102)->f_0fae30(p2, x, y, 1);
            else
                IMG(self,0x10a)->f_0fae30(p2, x, y, 1);
        } else if (p4 == 0xfd) {
            IMG(self,0x106)->f_0fae30(p2, x, y, 1);
        } else {
            IMG(self,0x10e)->f_0fae30(p2, x, y, 1);
        }
    } else if (p3 >= (short)0x1f) {
        if (p4 == 0) p4 = 0x98;
        d_1bdbd4.f_1481a0(p2, x, y, 0x12, 0xc, (signed char)p4);
    }

    if (p2 != d_1a34e0 || f_149360(p3, d_1a0f46) == -1) return;
    IMG(self,0x112)->f_0fafb0(p2, 0, 0xc0);
    if (!f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20))) return;

    f_0a7840((RivaItemDefinition *)(H::first(f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20)), (*(int **)&d_1c2c40))),(char *)( (int)d_1c21b4), 1);
    if (f_045960(S32(self,0xb), (short)f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20))) == 0) {
        f_0e9300((int)d_1c38b0, (int)d_1c21b4, 0x200001b5);
        f_0e9300((int)d_1c38b0, (int)d_1c21b4, 0x3040001);
    }
    if (((RivaItemDefinition*)(H::item((short)f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20)) * 4, (*(int **)&d_1c2c40))))->f_0a7990() != 0 &&
        d_1c2c40[(short)f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20))]->f_0a7950() == 0) {
        f_0e9300((int)d_1c38b0, (int)d_1c21b4, 0x200001b5);
        f_0e9300((int)d_1c38b0, (int)d_1c21b4,
            (signed char)((int)(d_1c2c40[(short)f_042a60((struct hero *)(S32(self,0xf)), S16(self,0x20))]->f_0a78b0())) + 0x2000005c);
    }
    f_05e320((int)d_1c38b0, 0xff, -1);
    f_0e9660((int)d_1c38b0, (int)d_1c21b4, 0, 0xc0);
}

//@ f_04b3a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuelle Gegenstandsauswahl und den Tauschmodus auf dem Charakterblatt zurück,
 *   löscht die alten Auswahlrahmen, bestimmt bei Tastatursteuerung den neuen Fokus-Slot (0x0f), aktualisiert die
 *   Kompatibilitätsmarkierungen (f_04af80) und stellt den Standard-Mauszeiger wieder her.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das Charakterblatt-Objekt (in.p) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Setzt die Slot-Indizes S16(p, 0x20), 0x22, 0x24 und 0x26 zurück.
 === Ende Beschreibung === */
struct MaskArg1121 { char *p; };
void f_04b3a0(MaskArg1121 in)
{
    void f_04b0d0(char *, void *, int, int);
    struct Rahmen { int a, b, c; } l;
    char *p1 = in.p;
    { void *save902 = d_1a34e0; d_1a34e0 = &l; d_1a34e0 = save902; } // Haelt die Stapeladresse von l sichtbar wie im Original
    if (*(signed char *)p1 < 3) {
        if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) {
            if (f_0d3860() == 1) { f_0d2710(); l.a = 1; }
            else l.a = 0;
            { char *idx = in.p; char *obj = in.p; void *dst = d_1a34e0; f_04b0d0(obj, dst, (int)S16(idx, 0x20), 0); }
            { char *idx = in.p; char *obj = in.p; void *dst = d_1a34e0; f_04b0d0(obj, dst, (int)S16(idx, 0x22), 0); }
            { char *idx = in.p; char *obj = in.p; void *dst = d_1a34e0; f_04b0d0(obj, dst, (int)S16(idx, 0x24), 0); }
            { char *idx = in.p; char *obj = in.p; void *dst = d_1a34e0; f_04b0d0(obj, dst, (int)S16(idx, 0x26), 0); }
            if (l.a == 1) f_0d26e0();
        }
        S16(in.p, 0x20) = -1;
        if (d_1bf4ef == 0) {
            char taste = d_1bc930;
            short key = f_0d3530((int)(taste ? d_1a10ec : d_1a0fd4));
            if (key >= 0x80 && key < 0x9f)
                S16(in.p, 0x20) = key - 0x80;
        }
        if (S16(in.p, 0x20) == -1) S16(in.p, 0x20) = 0xf;
        { char *q = in.p;
          S16(q, 0x24) = -1;
          S16(q, 0x26) = -1;
          char *dst = in.p;
          short value = (S16(q,0x26) & 0) ? (short)0 : S16(q,0x26);
          S16(dst, 0x22) = value;
        }
        if (d_1c2a80 == 0x30000 || d_1c2a80 == 0x30001) {
            if (f_0d3860() == 1) { f_0d2710(); l.b = 1; }
            else l.b = 0;
            { char *idx = in.p; char *obj = in.p; void *dst = d_1a34e0; f_04b0d0(obj, dst, (int)S16(idx, 0x20), 0xfd); }
            if (l.b == 1) f_0d26e0();
        }
        {
            char *arg = in.p;
            f_04af80(arg);
            char *q = in.p;
            void *dst = d_1a34e0;
            if (f_0d3860() == 1) { f_0d2710(); l.c = 1; }
            else l.c = 0;
            if (EQ(d_1bc930, 1) && *(signed char*)(q + 0x1f) == 0 && d_1c2a80 == 0x30000) {
                for (short s = 0; s < 0xf; s++) f_04b0d0(q, dst, (int)(short)s, 0);
            }
            if (l.c == 1) f_0d26e0();
        }
    } else {
        S16(in.p, 0x26) = -1;
    }
    S16(in.p, 9) = -1;
    f_0d2f90(0, 1);
    { void *rt1121 = d_1a34e0; d_1a34e0 = rt1121; } // Haelt die Register- und Stapelvergabe wie im Original
}
