/* === Beschreibung (Katalog) ===
 * Einheit zmain (0x143520 - 0x144090)
 *
 * Überblick
 *
 * Die Einheit zmain (zmain.cpp) enthält die globale Systeminitialisierung und das Hauptprogramm von *DSA 3 -
 * Schatten über Riva*. Hier werden beim Programmstart sämtliche statischen Subsysteme und Manager-Objekte der
 * Engine in festgelegter Reihenfolge konstruiert (f_143520), der DOS-InDOS-Zeiger über Interrupt 0x21 (AH =
 * 0x34) abgefragt (f_143990), die Grafik-, Sound-, Speicher-, Archiv- und CD-ROM-Prüfungen durchgeführt
 * (f_143ef0) und schließlich im Haupteinstiegspunkt (f_1439e0) das Intro-Video (RIVA.SMK), die
 * Kommandozeilen-Schnellladefunktion für Spielstände sowie das Hauptspiel gestartet.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 3/5 gleich (suche.py 29.10.2026, Basis zmain_P1.CPP)
// zmain.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x143520-0x144090
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
void f_019460(int p1);                                   // reg eax stapel 0
int f_01e5e0(int p1);                                   // reg eax stapel 0
int f_045a90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_046520(int p1, int p2);                           // reg eax edx stapel 0
int f_04fe30(int p1, int p2);
int f_056d00(int p1);                                   // reg eax stapel 0
int f_099750(int p1, int p2);                           // reg eax edx stapel 0
int f_09c740(int p1);
int f_0bd910(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx stapel 8
int f_0bdcb0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf580(int p1);                                   // reg eax stapel 0
int f_0d3a30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0da460(int p1, int p2, int p3, int p4);           // reg eax ecx stapel 0
int f_0e92e0(int p1, int p2, int p3);                   // reg ebx stapel 0
int f_0ed890(int p1, int p2);                           // reg - stapel 0
void f_0f00e0(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
int f_11bde0(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_126520(int p1);                                   // reg eax stapel 0
int f_133fd0(int p1);                                   // reg eax stapel 0
int f_13fa90(int p1, int p2);                           // reg eax edx stapel 0
   // reg eax edx ebx ecx stapel 4
int f_146920(int p1, int p2);                           // reg eax edx stapel 0
int f_148570(int p1, int p2);                           // reg eax edx stapel 0
int f_165460(int p1, int p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern char d_1bacd0;
extern int d_0a0000;                    // 0x0A0000
extern int d_1a9618;                    // 0x1A9618
extern int d_1a9620;                    // 0x1A9620
extern int d_1a965c;                    // 0x1A965C
extern int d_1c1190;                    // 0x1C1190
extern int d_1c11a0;                    // 0x1C11A0
extern int d_1c11b8;                    // 0x1C11B8
extern int d_1c11cc;                    // 0x1C11CC
extern int d_1c1348;                    // 0x1C1348
extern int d_1c1418;                    // 0x1C1418
extern int d_1c14c4;                    // 0x1C14C4
extern int d_1c1fe0;                    // 0x1C1FE0
                    // 0x1C2098
extern short d_1c2128;
extern short d_1c212a;
extern int d_1c212c;                    // 0x1C212C
extern short d_1c2130;
extern short d_1c2132;
extern short d_1c2134;                    // 0x1C2134
extern short d_1c2138;
extern short d_1c213a;
extern int d_1c213c;                    // 0x1C213C
extern int d_1c2a58;                    // 0x1C2A58
extern int d_1c2a64;                    // 0x1C2A64
extern char d_1c2a70;
extern char d_1c2a71;
extern char d_1c2a72;
extern char d_1c2a74;
extern char d_1c2a75;
extern char d_1c2a76;
extern int d_1c2a84;                    // 0x1C2A84
extern int d_1c2bcc;                    // 0x1C2BCC
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c60;                    // 0x1C2C60
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2e68;                    // 0x1C2E68
extern int d_1c2e78;                    // 0x1C2E78
extern int d_1c2edc;                    // 0x1C2EDC
extern short d_1c3068;
extern short d_1c306a;
extern volatile short d_1c306c; // haelt Schreibreihenfolge in f_143520 wie im Original
extern int d_1c306e;                    // 0x1C306E
extern int d_1c3072;                    // 0x1C3072
extern int d_1c3078;                    // 0x1C3078
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c3874;                    // 0x1C3874
extern int d_1c38b0;                    // 0x1C38B0
extern char d_1c38fc;
extern short d_1c38fd;
extern char d_1c3900;
extern short d_1c3901;
extern char d_1c390c;
extern short d_1c390d;
extern const char d_1a9624[];           // Text 0x1A9624
extern const char d_1b8714[];           // Text 0x1B8714
extern const char d_1b8723[];           // Text 0x1B8723
extern const char d_1b872c[];           // Text 0x1B872C
extern const char d_1b8735[];           // Text 0x1B8735
// --- eigene Funktionen (4), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
#define AD(x) ((int)&(x))
int f_14d17f(int p1);
extern int d_1c2d1c;
extern char d_1c2a78[];
extern char d_1c21b4[];
extern char d_1c20b4[];
extern char d_1c27a8[];
extern char d_1c20b0;
extern signed char d_1a9692;
extern char d_1a9693;
extern char d_1a9694;
extern signed char d_1c2a50;
extern short d_1c21ac;
extern int d_1c21a8;
extern int d_1a34e0;
extern short d_1bc760;
extern unsigned d_1a96a0;
extern unsigned d_1c3904;
extern int d_1c3908;
extern short d_1c2198;
extern unsigned short d_1a982c;
extern const char d_1b873e[];
extern const char d_1b874b[];
extern const char d_1b8758[];
extern const char d_1b875e[];
extern const char d_1b8763[];
extern const char d_1b8775[];
extern const char d_1b8788[];
extern const char d_1b878d[];
extern const char d_1b8792[];
int f_149caa(int p1, int p2, int p3);
#pragma aux f_149caa parm [eax] [edx] [ebx] value [edx];
int f_165d73(int p1, int p2);
int f_0a6ea0();
int f_0b0530(int p1);
int f_14572e(int, int, int, int, int, int);
#pragma aux f_14572e parm caller [ebx];
int f_148143(int p1, int p2);
int f_14d0e4(int, ...);
int f_165e06(int p1);
int f_149dbe(int, ...);
int f_149dfe(int, ...);
#pragma aux f_149dfe value [edx];
int f_143ef0();
int __stdcall f_11e730(int p1);
int __stdcall f_11e960(int p1);
char __stdcall f_11e760(int p1, int p2);
int f_145547(int p1, int p2, int p3);
int f_0ed950(int, ...);
int f_11e6d0(int p1);
int f_0d2a90();
int f_144110();
int f_09a400();
int f_1442c0();


int f_03f170();
int f_09a0d0(int p1);
int f_0f2720(int p1);
int f_0ce0f0(int p1);
int f_1254a0(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0d4070(int p1);
int f_147aad(int p1);
int f_11fbe0();
int f_01e0c0();
int f_01bf80();
int f_148534(int p1);
int f_1454d0(int p1);
int f_14d50b(int p1, int pattern);
int f_05da10(int p1, int p2, int p3);
int f_05b080(int p1, int p2);
int f_133fe0(int p1, int p2);
int f_059e40(int p1, int p2);
int f_05a910(int p1, int p2);
int f_147b97(int p1, int p2, int p3);
int f_147c02(int p1, int p2);
int f_091c00();
int f_0d26e0();
int f_0d2710();
struct SO { int a0; int *a4; int c[2]; int *q; int d14; int *p18; char pad[32];
    SO() { f_125400((int)this, AD(d_1c349c), AD(d_1c3870), AD(d_1c3498)); }
    ~SO() { f_1254a0((int)this, 0); } };
struct TT { char b[0x652]; TT(); ~TT(); };
struct VO { char c; int *vp; };
struct R2 { int lo; int hi; };


#include <string.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))
extern unsigned char d_1baac0;
extern unsigned char d_1bc608;
extern unsigned char d_1bc8f0;
extern unsigned char d_1bc8f8;
extern unsigned char d_1bc97c;
extern unsigned char d_1bdbe4;
extern unsigned char d_1bdbe8;
extern unsigned char d_1be17c;
extern unsigned char d_1bfad0;
extern unsigned char d_1c2144;
extern unsigned char d_1c2a54;
int C0144e0_0();
#pragma aux C0144e0_0 "f_0144e0";
int C014540_3(int,int,int);
#pragma aux C014540_3 "f_014540" modify exact [eax ebx edx];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C05fd00_0();
#pragma aux C05fd00_0 "f_05fd00" modify exact [eax];
int C0a1e10_2(int,int);
#pragma aux C0a1e10_2 "f_0a1e10" modify exact [eax edx];
int C0a7b60_0();
#pragma aux C0a7b60_0 "f_0a7b60" modify exact [eax];
int __cdecl C0ed8f0_2(int,int);
#pragma aux C0ed8f0_2 "f_0ed8f0" modify exact [eax ecx];
int C126b60_1(int);
#pragma aux C126b60_1 "f_126b60" modify exact [eax];
int C146d0f_1(int);
#pragma aux C146d0f_1 "f_146d0f" modify exact [eax];
int C146d36_1(int);
#pragma aux C146d36_1 "f_146d36" modify exact [eax];
int C146d5c_1(int);
#pragma aux C146d5c_1 "f_146d5c" modify exact [eax];
int C147954_1(int);
#pragma aux C147954_1 "f_147954" modify exact [eax];
int C147c84_3(int,int,int);
#pragma aux C147c84_3 "f_147c84" modify exact [eax ebx edx];
int __pascal C165e20_2(int,int);
#pragma aux C165e20_2 "f_165e20" modify exact [eax ebx ecx edx];
//@ f_143980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Rückruffunktion (No-Op-Callback), die in f_1439e0 bei der Registrierung des
 *   Sound-/Timer-Hooks (f_147b97) übergeben wird.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_143980()
{
}

//@ f_143520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Statische Gesamtinitialisierung der Spiel-Engine: Registriert zunächst den
 *   Destruktor-Aufräumknoten d_1a9618 über f_14d17f und konstruiert anschließend schrittweise (mit
 *   Fortschrittsmarkierung d_1a9620 = 1 bis 0x1B zur Fehlerdiagnose bei einem Absturz während des Starts) alle
 *   globalen Subsysteme: Fehler-/Logausgabe (d_1c1190), Haupt- und EMS/DPMI-Speicherverwaltung (d_1c11a0,
 *   d_1c11b8), Timer (d_1c11cc), Dateipfadverwaltung (d_1c1348), Archivtreiber realdisk (d_1c1418 mit den
 *   Archiven aus d_1b8723..d_1b8735), virtuelle RAM-Disk virtdisk (d_1c14c4), Stream-Puffer (d_1c1fe0),
 *   zentralen Ressourcenmanager (d_1c2098), die drei Spielstand-Variablenregister (byteReg690 für 1000
 *   Byte-Flags, wordReg690 für 500 16-Bit-Werte, dwordReg690 für 100 32-Bit-Werte), Mauszeiger-Puffer (d_1c2a58,
 *   d_1c2a64), Gruppen-/Heldenverwaltung (d_1c2a84), Text- und GUI-Systeme (d_1c2bcc..d_1c2e68), Maustreiber
 *   (d_1c2e78), Sound-/Musiksystem (d_1c2edc) sowie den Bildschirm- und Textrenderer (d_1c3078, d_1c3498,
 *   d_1c3874, d_1c38b0).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9620: Globale Initialisierungsstufe (1 bis 27), an der ein Fehlerhandler erkennen kann, welches
 *     Subsystem beim Programmstart zuletzt initialisiert wurde.
 *   - byteReg690, wordReg690, dwordReg690: Globale Registrierungslisten (d_1c2128, d_1c2130, d_1c2138) für alle
 *     persistenten Spielstandsvariablen.
 === Ende Beschreibung === */

struct InitRegistry690 {
    short capacity,count;
    void **list;
    void init(short n,const char *file) {
        count=0;capacity=n;
        list=(void **)f_014540((int)n*4,(int)file,0xd3);
    }
    void append(void *object) {list[count]=object;count++;}
};
struct InitObject690 {
    signed char value;short id;char pad;
    InitObject690 *init(InitRegistry690 &reg,short number,signed char v) {
        value=v;id=number;reg.append(this);return this;
    }
};
typedef char InitLayout690[(sizeof(InitRegistry690)==8 && sizeof(InitObject690)==4)?1:-1];
extern InitRegistry690 byteReg690,wordReg690,dwordReg690;
#pragma aux byteReg690 "d_1c2128";
#pragma aux wordReg690 "d_1c2130";
#pragma aux dwordReg690 "d_1c2138";
extern InitObject690 initObject690_0,initObject690_1,initObject690_2;
#pragma aux initObject690_0 "d_1c38fc";
#pragma aux initObject690_1 "d_1c3900";
#pragma aux initObject690_2 "d_1c390c";

void f_143520()
{
    int tab908(int);
    #pragma aux tab908 "f_046520" parm[eax] value[eax] modify exact [];
    int alloc908(int,int,int);
    #pragma aux alloc908 "f_014540" parm[eax][edx][ebx] value[eax] modify exact[eax edx ebx ecx]; // konservative Clobber-Menge fuer Registerwahl wie im Original
    int stream908(int,int);
    #pragma aux stream908 "f_165460" parm [eax][edx] value[eax] modify exact[eax edx];
    int A14d17f(int);
    #pragma aux A14d17f "f_14d17f" parm [eax] modify exact [eax edx ecx ebx esi edi ebp];
    extern volatile int stage9620; // verhindert Verschieben des Schreibzugriffs d_1a9620 = 9 in f_143520
    #pragma aux stage9620 "d_1a9620";
    A14d17f(AD(d_1a9618));
    f_0ed890(AD(d_1c1190), (int)d_1b8714);
    d_1a9620 = 1;
    f_0bd910(AD(d_1c11a0), 0x33e800, 0x1800000, 0x80000, 0x9c4, 1);
    d_1a9620 = 2;
    f_0bdcb0(AD(d_1c11b8), 0x8000, 0x14);
    d_1a9620 = 3;
    f_11bde0(AD(d_1c11cc));
    d_1a9620 = 4;
    f_148570(AD(d_1c1348), AD(d_1a965c));
    d_1a9620 = 5;
    f_0da460(AD(d_1c1418), (int)d_1b8735, (int)d_1b872c, (int)d_1b8723);
    d_1a9620 = 6;
    void *init908(void*,int);
    #pragma aux init908 "f_13fa90" parm[eax][edx] value[eax] modify exact[eax edx];
    void *framePtr908=&d_1c14c4;
    void *streamPtr908=&d_1c1418;
    init908(framePtr908,0);
    int frame14c4=(int)framePtr908;
    d_1a9620 = 7;
    // Komma-Kette verzoegert BlkTooBig, Reihenfolge bleibt erhalten.
    (stream908(AD(d_1c1fe0), AD(d_1a965c)),
    d_1a9620 = 8,
    ((int)(((RivaFileManager*)(AD((*(int*)&d_1c2098))))->f_144610((RivaFileDevice *)( AD(d_1c1348)),(RivaFileDevice *)( (int)streamPtr908),(RivaFileDevice *)( frame14c4),(RivaFileDevice *)( AD(d_1c1fe0))))));
    d_1c212a = 0;
    d_1c2128 = 1000;
    d_1c212c = alloc908(4000, (int)d_1a9624, 0xd3);
    stage9620=9;
    wordReg690.count=0;
    wordReg690.capacity=500;
    *(int *)&d_1c2134=alloc908(2000,(int)d_1a9624,0xd3);
    d_1c213a = 0;
    d_1c2138 = 100;
    d_1a9620 = 10;
    d_1c213c = alloc908(400, (int)d_1a9624, 0xd3);
    d_1a9620 = 0xb;
    ((int)(((RivaRasterImage*)(AD(d_1c2a58)))->f_0fac80( 0x20, 0x20)));
    d_1a9620 = 0xc;
    ((int)(((RivaRasterImage*)(AD(d_1c2a64)))->f_0fac80( 0x20, 0x20)));
    d_1a9620 = 0xd;
    d_1c2a70 = 0;
    d_1c2a71 = 0;
    d_1c2a72 = 0;
    d_1c2a74 = 0x3f;
    d_1c2a75 = 0x3f;
    d_1c2a76 = 0x3f;
    f_019460(AD(d_1c2a84));
    d_1a9620 = 0xe;
    f_01e5e0(AD(d_1c2bcc));
    d_1a9620 = 0xf;
    f_04fe30(AD(d_1c2be0), 1);
    d_1a9620 = 0x10;
    f_056d00(AD(d_1c2c00));
    d_1a9620 = 0x11;
    f_126520(AD(d_1c2c44));
    d_1a9620 = 0x12;
    tab908(AD(d_1c2c60));
    d_1a9620 = 0x13;
    f_0bf580(AD(d_1c2c64));
    d_1a9620 = 0x14;
    f_09c740(AD(d_1c2d1c));
    d_1a9620 = 0x15;
    f_0f00e0(AD(d_1c2e68));
    d_1a9620 = 0x16;
    f_0d3a30(AD(d_1c2e78), -1, 1);
    d_1a9620 = 0x17;
    f_146920(AD(d_1c2edc), AD((*(int*)&d_1c2098)));
    d_1a9620 = 0x18;
    d_1c306e = 0xa0000;
    d_1c3072 = AD(d_1bacd0);
    d_1c3068 = 1;
    d_1c306a = 0x140;
    d_1c306c = 200;
    // Komma-Kette bis zum ersten Listenstore haelt die ID-Ladung
    // vor f_125400. count++ beginnt den Folgeblock fuer die weiteren Inits.
    (f_045a90(AD(d_1c3078), AD(d_1c3068), AD((*(int*)&d_1c2098))),
    d_1a9620 = 0x19,
    f_133fd0(AD(d_1c3498)),
    f_099750(AD(d_1c349c), AD((*(int*)&d_1c2098))),
    d_1a9620 = 0x1a,
    f_125400(AD(d_1c3874), AD(d_1c349c), AD(d_1c3870), AD(d_1c3498)),
    d_1a9620 = 0x1b,
    f_0e92e0(AD(d_1c38b0), AD(d_1c3078), AD(d_1c3498)),
    initObject690_0.value=0,
    initObject690_0.id=0xd,
    byteReg690.list[byteReg690.count]=&initObject690_0);
    byteReg690.count++;
    initObject690_1.init(byteReg690,0x240,0);
    initObject690_2.init(byteReg690,1,0);
}

//@ f_143990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über den DOS-Interrupt 0x21 mit AX = 0x3400 (*Get InDOS Flag Address*) die
 *   Real-Mode-/Protected-Mode-Adresse des DOS-internen InDOS-Zählers ab und gibt sie als 48-Bit-Far-Pointer
 *   (ES:EBX) zurück, damit Interrupt-Routinen prüfen können, ob gerade ein DOS-Systemaufruf aktiv ist.
 * - Eingaben: Keine.
 * - Rückgabewert: Far-Pointer (void __far *) auf das InDOS-Byte in ES:EBX.
 * - Wichtige Variablen:
 *   - r, s: Register- und Segmentregisterstruktur für den DOS-Interrupt-Aufruf f_165d73.
 === Ende Beschreibung === */
void __far *f_143990()
{
    struct WORDREGS { unsigned short ax, _1, bx, _2, cx, _3, dx, _4, si, _5, di, _6; unsigned int cflag; };
    struct DWORDREGS { unsigned int eax, ebx, ecx, edx, esi, edi, cflag; };
    union REGS { struct DWORDREGS x; struct WORDREGS w; };
    struct SREGS { unsigned short es, cs, ss, ds, fs, gs; };
    void seg_149caa(struct SREGS *s);
    #pragma aux seg_149caa "f_149caa" parm [eax] modify exact [eax];
    int dos_165d73(union REGS *in, union REGS *out, struct SREGS *s);
    #pragma aux dos_165d73 "f_165d73" parm [eax] [edx] [ebx] modify exact [eax edx ebx];
    void mem_145300(void *p, int c, unsigned n);
    #pragma aux mem_145300 "f_145300" parm [eax] [edx] [ebx] modify exact [eax edx ebx];
    union REGS r;
    struct SREGS s;

    mem_145300(&r, 0, 0x1c);
    mem_145300(&s, 0, 0xc);
    seg_149caa(&s);
    r.w.ax = 0x3400;
    dos_165d73(&r, &r, &s);
    return ((unsigned short)s.es :> (void __near *)r.x.ebx);
}

//@ f_1439e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hauptfunktion (main) von *Schatten über Riva*: Sichert den InDOS-Zeiger (d_1c21ac:d_1c21a8),
 *   ermittelt das Startlaufwerk, wechselt in das Spielverzeichnis, ruft die Hardware- und
 *   Speicherinitialisierung f_143ef0 auf, prüft die VESA-Auflösung 640x480 (f_11e760(0x1E0, 0x280)) für
 *   hochauflösende Videos, schaltet in den VGA-Modus 19 (0x13, 320x200x256), führt den
 *   CD-/Archiv-Kopierschutzcheck durch (und spielt, falls keine Kommandozeilenoption übergeben wurde, über
 *   f_03f170 das Intro-Video ab), prüft den freien Festplattenspeicher für Auslagerungsdateien (0x2000000F bei
 *   Platzmangel), lädt bei Übergabe eines Spielstandsnamens auf der Kommandozeile direkt diesen Spielstand
 *   (f_059e40) oder öffnet andernfalls das Hauptmenü (f_05a910) und startet anschließend die Hauptspielschleife
 *   f_091c00().
 * - Eingaben: Parameteranzahl argc (short) und Argumentvektor argv (char ) der Kommandozeile.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - view: Zeiger auf das Bildschirm-/Grafikansichtsobjekt (d_1c3870).
 *   - file: Geöffneter Dateihandle beim Prüfen der Signatur (d_1b875e) für die hochauflösende
 *     VESA-Unterstützung.
 *   - lower, upper: Verfügbarer (d_1c3904) und mindestens benötigter (d_1a96a0) freier Festplattenspeicher auf
 *     dem aktuellen Laufwerk.
 *   - text: Temporäres 0x652 Byte großes Lade-/Menüobjekt (TT) zum Laden eines Spielstands oder Starten des
 *     Hauptmenüs.
 === Ende Beschreibung === */
void f_1439e0(short argc, char **argv)
{
    int call_149caa(int, int, int);
    #pragma aux call_149caa "f_149caa" parm [ebx] [edx] [eax] value [edx];
    int call_05da10(int, int, int);
    #pragma aux call_05da10 "f_05da10" parm [ebx] [eax] [edx];

    struct SO2 { int a0; int *a4; int c[2]; int *q; int d14; int *p18; char pad[32];
        SO2(int p2, int p3, int p4) { f_125400((int)this, p2, p3, p4); }
        ~SO2() { void *p = this; f_1254a0((int)p, 0); } };
    int io[20];
    int a[7];
    char name[16];
    int b[3];
    int result, file;
    char *arg;
    const char *flag_next;
    VO *view;
    TT *text;
    unsigned lower, upper;

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    *(short *)a = (short)call_149caa((int)b, 0x3400, (int)b);
    f_165d73((int)a, (int)a);
    d_1c21ac = (short)b[0];
    d_1c21a8 = a[1];
    f_0a6ea0();
    d_1a9693 = 3;
    d_1c2a50 = 0;
    d_1a9694 = 3;
    d_1a9692 = d_1c20b0;
    view = (VO *)f_0b0530(d_1a9692);
    d_1c3870 = (int)view;
    result = ((int (*)(VO *))view->vp[7])(view);
    f_14572e(0x3f, (int)d_1c21b4, (int)d_1b874b, (int)d_1c20b4, (int)d_1b873e, result);
    f_148143((int)d_1c20b4, (int)d_1c21b4);
    f_14d0e4((int)d_1b8758, (int)d_1c20b4);
    f_165e06(0);
    f_149dbe(AD(d_1c2a78));

    if (f_143ef0()) {
        f_11e730(1);
        d_1c3908=0; { int *dup=(argc&0)?(int*)0:&d_1c3908; *dup=0; } // erzeugt doppelte Null-Zuweisung auf d_1c3908 wie im Original
        file = f_11e960((int)io);
        if (file != 0 && f_145547(file, (int)d_1b875e, 4) == 0) {
            result = (unsigned char)f_11e760(0x1e0, 0x280);
            if (result == 1) {
                d_1c3908 = result;
                f_0ed950(AD(d_1c1190), 0x29a0013, file);
            } else {
                f_0ed950(AD(d_1c1190), 0x29a0014);
            }
        } else {
            f_0ed950(AD(d_1c1190), 0x29a0015);
        }
        f_11e6d0(19);
        f_0d2a90();
        f_144110();
        f_09a400();
        f_0d26e0();
        f_1442c0();

        if (argc > 1) {
            if (*argv[1] == '-' || *argv[1] == '/') goto flag_true;
        }
        if (argc > 1) {
        flag_false:
            result = 0;
            goto flag_done;
        }
        d_1a965c = (int)d_1b8763;
        if (((RivaFileManager*)(AD((*(int*)&d_1c2098))))->f_144870( 0) != 1) goto flag_true;
        flag_next=d_1b8775;
        result=((int)(((RivaFileManager*)(AD((*(int*)&d_1c2098))))->f_144a30(0)));
        d_1a965c = (int)flag_next;
        if (((RivaFileManager*)(AD((*(int*)&d_1c2098))))->f_144870( 0) != 1) goto flag_true;
        if (result != ((int)(((RivaFileManager*)(AD((*(int*)&d_1c2098))))->f_144a30( 0)))) goto flag_false;
    flag_true:
        result = 1;
    flag_done:
        if (result == 1) {
            f_03f170();
            f_09a0d0(d_1a34e0);
            f_0f2720(15);
            f_09a400();
        }
        {
            SO2 state((d_1c3904 = f_0ce0f0(0), AD(d_1c349c)),
                      (f_09a0d0(d_1a34e0), AD(d_1c3870)),
                      AD(d_1c3498));
            lower = d_1c3904;
            upper = d_1a96a0;
            if (lower < upper) {
                ((unsigned *)state.p18)[1] = (upper -= lower);
                f_0bf730(AD(d_1c2c64), 0x2000000f);
                f_0d2710();
                f_0d4070(AD(d_1c2e78));
                f_147aad(AD(d_1c2edc));
                f_11fbe0();
                if (*(int *)&d_1bc760) f_01e0c0();
                f_01bf80();
                f_149dfe(AD(d_1c2a78));
                f_148534(0);
            }
            if (argc > 1) {
                arg = argv[1];
                if (*arg != '-' && *arg != '/') {
                    strcpy(d_1c27a8, arg);
                    f_1454d0(AD(d_1c27a8));
                    arg = (char *)f_14d50b(AD(d_1c27a8), (int)d_1b8788);
                    if (arg != 0) *arg = 0;
                    call_05da10(14, AD(d_1c21b4), AD(d_1c27a8));
                    f_148143((int)name, AD(d_1c21b4));
                    strcat(d_1c21b4, d_1b878d);
                    text = new (mark(d_1a9624, 0x1fe)) TT;
                    if (f_05b080((int)text, AD(d_1c21b4)) == -1) {
                        state.q[1] = f_133fe0(AD(d_1c3498), (int)name);
                        f_0bf730(AD(d_1c2c64), 0x200001af);
                    } else {
                        f_059e40((int)text, AD(d_1c21b4));
                    }
                    delete text;
                    d_1c2198 = 1;
                }
            } else {
                text = new (mark(d_1a9624, 0x210)) TT;
                f_05a910((int)text, (int)d_1b8792);
                delete text;
                d_1c2198 = 1;
            }
            f_147c02(AD(d_1c2edc), f_147b97(AD(d_1c2edc), d_1a982c, (int)f_143980));
            f_091c00();
            f_0d2710();
            f_0d4070(AD(d_1c2e78));
            f_147aad(AD(d_1c2edc));
            f_11fbe0();
            if (*(int *)&d_1bc760) f_01e0c0();
            f_01bf80();
            f_149dfe(AD(d_1c2a78));
        }
    }
    f_149dfe(AD(d_1c2a78));
}
//@ f_143ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft und reserviert beim Spielstart die grundlegenden Speicher-, Sound-, Paletten- und
 *   Kampfsystem-Puffer: Ermittelt den freien Arbeitsspeicher (f_0144e0 nach d_1c2a54 / d_1bc608), initialisiert
 *   das 3D-/Polygon-Subsystem (f_05fd00), gibt bei Soundkarten-Konfigurationsfehlern eine Warnmeldung
 *   (0x29A0009) aus, startet den Sound-Timer (f_165e20), setzt die VGA-Basisadresse d_1a34e0 = 0xA0000,
 *   reserviert die globalen Arbeits- und Palettenpuffer (d_1bc8f0, d_1bc8f8, d_1bdbe4, d_1bdbe8, d_1c2144), lädt
 *   die Gegenstands- und Kampftabellen (f_126b60, f_0a7b60) und legt das globale Zufalls-/Würfelobjekt d_1be17c
 *   an.
 * - Eingaben: Keine.
 * - Rückgabewert: Immer 1 (success).
 * - Wichtige Variablen:
 *   - available: Beim Start ermittelter freier Speicher in Bytes.
 *   - d_1bdbe4, d_1bdbe8, d_1c2144: Drei jeweils 0x300 (768) Byte große Farbpaletten-Arrays mit je 256
 *     Einträgen.
 === Ende Beschreibung === */
int f_143ef0()
{
    int available=C0144e0_0();
    ND32(d_1c2a54)=available;ND32(d_1bc608)=available;
    ND32(d_1bc97c)=C05fd00_0();
    int success=1;
    if(C147954_1(NA(d_1c2edc))==0 && (C146d0f_1(NA(d_1c2edc))&65535)==4)
        C0ed8f0_2(NA(d_1c1190),0x29a0009);
    ND32(d_1bfad0)=C146d36_1(NA(d_1c2edc));
    C165e20_2((short)C146d5c_1(NA(d_1c2edc)),ND32(d_1a982c));
    ND32(d_1a34e0)=0xa0000;
    ND32(d_1bc8f0)=C014540_3(0x2989,NA(d_1a9624),0x280);
    ND32(d_1bc8f8)=C014540_3(0x400,NA(d_1a9624),0x281);
    { char *allocated=(char *)C147c84_3(NNEW(0x300,d_1a9624,0x282),0x100,NA(d_1baac0)); ND32(d_1bdbe4)=(int)(allocated?allocated:0); }
    { char *allocated=(char *)C147c84_3(NNEW(0x300,d_1a9624,0x283),0x100,NA(d_1baac0)); ND32(d_1bdbe8)=(int)(allocated?allocated:0); }
    { char *allocated=(char *)C147c84_3(NNEW(0x300,d_1a9624,0x285),0x100,NA(d_1baac0)); ND32(d_1c2144)=(int)(allocated?allocated:0); }
    C126b60_1(NA(d_1c2c44));
    C0a7b60_0();
    int raw=NOBJ(10,d_1a9624,0x297);
    ND32(d_1be17c)=raw?C0a1e10_2(raw,32):raw;
    return success;
}

