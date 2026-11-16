/* === Beschreibung (Katalog) ===
 * Einheit options_t1 (0d7430 - 0d87e0)
 *
 * Überblick
 * Die Einheit options_t1 bildet den ersten Teil des ursprünglichen Moduls options.cpp. Sie verwaltet die 21
 * globalen Spieleinstellungen (d_1bfadc..d_1bfb2c in der Registrierung d_1bfad4), das Laden und Speichern der
 * Konfigurationsdatei RIVA.CFG, das Zurücksetzen auf Standardwerte sowie den Aufbau, Abbau und die Hauptschleife
 * des Optionsmenüs.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 10/13 gleich (suche.py 29.10.2026, Basis options_t1_P1.CPP)
// options.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0D7430-0x0D9CB0
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_012700(int p1, int p2);                           // reg eax edx stapel 0
int f_012870(int p1, int p2);                           // reg eax edx stapel 0
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_02de20(int p1, int p2);                           // reg eax edx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_09a0d0(int p1);                                   // reg eax stapel 0
int f_09a120(int p1, int p2);                           // reg eax edx stapel 0
int f_09a140(int p1, int p2);                           // reg eax edx stapel 0
int f_09ac80(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09ade0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_09aed0(int p1);                                   // reg eax stapel 0
int f_0bd350(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0bf8e0(int p, int a, int b, int c, short d, ...);                                         // reg - stapel 0
int f_0c0020(int p1, int p2);                           // reg eax edx stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d3f25(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4070(int p1);                                   // reg eax stapel 0
int f_0d40b6(int p1);                                   // reg eax stapel 0
int f_0d4248(int p1, int p2);                           // reg eax edx stapel 0
int f_0d451f(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0d4800(int p1);                                   // reg eax stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0f0130(int p1);                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
int f_10a8b0(int p1);                                   // reg eax stapel 0
int f_10a940(int p1);                                   // reg eax stapel 0
int f_10a980(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_10aad0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_10ac80(int p1);                                   // reg eax stapel 0
int f_10ae20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                   // reg eax ebx stapel 0
                                   // reg eax stapel 0
int f_145a20(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_146ae4(int p1, int p2);                           // reg eax edx stapel 0
int f_146dfa(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_147688(int p1, int p2);                           // reg eax edx stapel 0
int f_147746(int p1, int p2);                           // reg eax edx stapel 0
int f_147aad(int p1);                                   // reg eax stapel 0
int f_147b97(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_147c02(int p1, int p2);                           // reg eax edx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
#pragma inline_depth(0)
int f_0d4880(int p1);
short f_0d3530(int p1);
short f_149360(int p1, int p2);
int f_050580(int p1, int p2, int p3, int p4, int p5);
int __cdecl f_149eb4(int p1, int p2, int p3);
int f_1459d0(int p1, int p2);
int f_1459b0(int p1);
short f_0de800(int p1);
int f_14d17f(int p1);
void f_0d8c00(int p1, void *p2, int p3);
void f_0d8950(int p1, void *p2, int p3);
void f_0d8d20(int p1, void *p2, int p3);
void f_0d9670(int p1, int p2);
void f_0d9b20(int p1);
void f_0d99d0(int p1, void *p2, int p3, int p4);
void f_0d98c0(int p1, void *p2, int p3, int p4);
void f_0d97b0(int p1);
#define A(x) ((int)&(x))
#define I4(p,o) (*(int *)((p) + (o)))
#define I2(p,o) (*(short *)((p) + (o)))
struct Ent { signed char v; short id; char pad; };
struct E5 { char *p; char v; };
struct Rc { short x0, y0, x1, y1, id; };
struct Opt { short x, y; signed char c4, c5; char pad6[8]; int v0e; char padf[0x14]; signed char nav[5]; };
struct Spr9 { char b[9]; };
extern struct Ent d_1bfadc[];
#define EN(n) ((char *)&d_1bfadc[n])
extern struct E5 d_1a5afc[];
extern struct Opt d_1a5b88[];
extern struct Rc d_1bfb64[];
extern short d_1bfb38[], d_1bfb4e[], d_1a5b72[], d_1a5b78[];
extern short d_1bfb54, d_1bfb4c;
extern short d_1bfb3e;
extern short d_1bfb40;
extern int d_1a5ac0, d_1a5af0, d_1a621c, d_1a6218, d_1a34e0;
extern unsigned short d_1a5ac8;
extern unsigned char d_1a9820;
extern short d_1bfad6, d_1bfaca, d_1bfacc, d_1bd766, d_1bd90c, d_1bd910, d_1bf500, d_1c2198, d_1bf4bc, d_1bf4be;
extern short d_1bfad4;
extern short d_1a5afa;
extern int d_1bfdb4;
extern volatile short d_1bf51c;
extern void **d_1bfad8;
extern int d_1bfad0, d_1bfb34, d_1c0c4c, d_1c0004, d_1c2a80, d_1bf510, d_1bf520, d_1bf524;
extern volatile int d_1bf514;
extern int d_1bf4ef;
extern int d_1a5aec, d_1a965c;
extern int d_1c2e68, d_1c2e78, d_1c2edc, d_1c38b0, d_1c2c64, d_1c2be0;
extern const char d_1a5acc[];

static int EQBF(const signed char &,int);
#pragma aux EQBF "optionCompare650"
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0d7430
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Initialisiert beim Programmstart die globale Optionen-Registrierung (d_1bfad4) mit einer Kapazität
 *   von 25 Einträgen und trägt die 21 Konfigurationsvariablen (d_1bfadc bis d_1bfb2c, IDs 1 bis 21, darunter
 *   Musik, Soundeffekte, Lautstärke, Textgeschwindigkeit, Detailstufe, Automapping und Druckereinstellungen) mit
 *   ihren jeweiligen Standardwerten ein.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
#pragma inline_depth(20)
int allocateOptions650(int,int,int);
#pragma aux allocateOptions650 "f_014540" modify exact [eax ebx edx];
int cleanupOptions650(int);
#pragma aux cleanupOptions650 "f_14d17f" modify [eax ebx ecx edx esi];
struct OptionNight650;
struct RegistryNight650 {
 short capacity,count;OptionNight650 **items;
 void initialize(short n){count=0;capacity=n;items=(OptionNight650 **)allocateOptions650(n*4,(int)d_1a5acc,0xd3);}
 void append(OptionNight650 *p){items[count]=p;count++;}
};
struct OptionNight650 {signed char value;short id;char pad;
 OptionNight650 *init(RegistryNight650 &r,short n,signed char v){value=v;id=n;r.append(this);return this;}
};
extern RegistryNight650 optionRegistry650;
#pragma aux optionRegistry650 "d_1bfad4"
extern OptionNight650 option650_0;
#pragma aux option650_0 "d_1bfadc"
extern OptionNight650 option650_1;
#pragma aux option650_1 "d_1bfae0"
extern OptionNight650 option650_2;
#pragma aux option650_2 "d_1bfae4"
extern OptionNight650 option650_3;
#pragma aux option650_3 "d_1bfae8"
extern OptionNight650 option650_4;
#pragma aux option650_4 "d_1bfaec"
extern OptionNight650 option650_5;
#pragma aux option650_5 "d_1bfaf0"
extern OptionNight650 option650_6;
#pragma aux option650_6 "d_1bfaf4"
extern OptionNight650 option650_7;
#pragma aux option650_7 "d_1bfaf8"
extern OptionNight650 option650_8;
#pragma aux option650_8 "d_1bfafc"
extern OptionNight650 option650_9;
#pragma aux option650_9 "d_1bfb00"
extern OptionNight650 option650_10;
#pragma aux option650_10 "d_1bfb04"
extern OptionNight650 option650_11;
#pragma aux option650_11 "d_1bfb08"
extern OptionNight650 option650_12;
#pragma aux option650_12 "d_1bfb0c"
extern OptionNight650 option650_13;
#pragma aux option650_13 "d_1bfb10"
extern OptionNight650 option650_14;
#pragma aux option650_14 "d_1bfb14"
extern OptionNight650 option650_15;
#pragma aux option650_15 "d_1bfb18"
extern OptionNight650 option650_16;
#pragma aux option650_16 "d_1bfb1c"
extern OptionNight650 option650_17;
#pragma aux option650_17 "d_1bfb20"
extern OptionNight650 option650_18;
#pragma aux option650_18 "d_1bfb24"
extern OptionNight650 option650_19;
#pragma aux option650_19 "d_1bfb28"
extern OptionNight650 option650_20;
#pragma aux option650_20 "d_1bfb2c"

extern int optionReady650;
#pragma aux optionReady650 "d_1a5ac8"
void f_0d7430(void)
{
 cleanupOptions650(A(d_1a5ac0));
 optionRegistry650.initialize(25);
 optionReady650=1;
 option650_0.init(optionRegistry650,1,1);
 option650_1.init(optionRegistry650,2,1);
 option650_2.init(optionRegistry650,3,100);
 option650_3.init(optionRegistry650,4,0);
 option650_4.init(optionRegistry650,5,0);
 option650_5.init(optionRegistry650,6,1);
 option650_6.init(optionRegistry650,7,80);
 option650_7.init(optionRegistry650,8,64);
 option650_8.init(optionRegistry650,9,1);
 option650_9.init(optionRegistry650,10,1);
 option650_10.init(optionRegistry650,11,2);
 option650_11.init(optionRegistry650,12,1);
 option650_12.init(optionRegistry650,13,0);
 option650_13.init(optionRegistry650,14,0);
 option650_14.init(optionRegistry650,15,0);
 option650_15.init(optionRegistry650,16,1);
 option650_16.init(optionRegistry650,17,0);
 option650_17.init(optionRegistry650,18,0);
 option650_18.init(optionRegistry650,19,15);
 option650_19.init(optionRegistry650,20,0);
 option650_20.init(optionRegistry650,21,0);
}


#pragma inline_depth(0)
//@ f_0d7830
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Wertet als Maus-Zonen-Rückruffunktion im Optionsmenü den aktuellen Hot-Spot-Index (0x80..0xf0) aus,
 *   schaltet den Mauszeiger über den Schiebereglern um (d_1bfaca = 0xc bzw. 0) und aktualisiert bei gedrückter
 *   Maustaste den Index des aktuell ausgewählten Optionsfelds (d_1bfacc).
 * - Eingaben: Übergeben wird die Kennung der unter dem Mauszeiger liegenden Bildschirmzone (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d7830(short p1)
{
    if (p1 && f_0d3810()) {
        if (f_149360((short)(p1 - 0x80), A(d_1a621c)) != -1) d_1bfaca = 0xc; else d_1bfaca = 0;
        if (p1 != 0xf0) {
            p1 -= 0x80; if (p1 >= 0x26) p1 -= 0x26; d_1bfacc = p1;
        }
    }
}
//@ f_0d78a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Konstruiert das Basisfenster- bzw. Bildlader-Objekt des Optionsmenüs durch Weiterleitung an den
 *   Basiskonstruktor f_1459b0.
 * - Eingaben: Übergeben wird der Zeiger auf das zu initialisierende Optionsmenü-Objekt (p1).
 * - Rückgabewert: Gibt den Zeiger auf das initialisierte Objekt zurück.
 === Ende Beschreibung === */
int f_0d78a0(int p1)
{
    return f_1459b0(p1);
}
//@ f_0d78b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Baut das Basisfenster-Objekt des Optionsmenüs beim Zerstören über den Basisdestruktor f_1459d0
 *   wieder ab.
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1) sowie das Freigabe-Flag (p2).
 * - Rückgabewert: Gibt den Rückgabewert des Basisdestruktors zurück.
 === Ende Beschreibung === */
int f_0d78b0(int p1, int p2)
{
    return f_1459d0(p1, 0);
}
//@ f_0d78c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Übernimmt geänderte Audio- und Steuerungseinstellungen unmittelbar in die laufenden Spielsysteme:
 *   aktualisiert bei Änderung der Maus-Option (EN(10)) die Mausempfindlichkeit (f_0d4880), schaltet Musik
 *   (EN(0), d_1c2e78) bzw. digitale Soundeffekte (EN(1), d_1c2edc) ein oder aus und passt bei geänderter
 *   Effektlautstärke (EN(2)) den Lautstärkepegel an (inklusive Abspielen des Testklangs 0x180002 bei geöffnetem
 *   Optionsmenü).
 * - Eingaben: Übergeben werden der Zeiger auf das Optionsmenü-Objekt (p1) sowie der Zeiger auf die geänderte
 *   Optionsvariable (p2, oder 0 zum Aktualisieren aller Audio-Optionen).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d78c0(int p1, char *p2)
{
struct ToneFamily670_1 {static void play(int id,volatile int&flags,int volume,int pan,int zero,int one){f_147323(A(d_1c2edc),id,volume,pan,flags,zero,one);}};
struct ToneFamily670_0 {static void play(int id,volatile int&flags,int volume,int pan,int zero,int one){f_147323(A(d_1c2edc),id,volume,pan,flags,zero,one);}};

    if (p2 == EN(10)) f_0d4880(A(d_1c2e68));
    if (p2 == EN(0) || p2 == 0) {
        { signed char c = d_1bfadc[0].v; f_0d4248(A(d_1c2e78), c); }
        { signed char c = d_1bfadc[0].v;
          if (c == 0) f_0d4070(A(d_1c2e78));
          else if (d_1bfb34 == 1) f_0d3f25(A(d_1c2e78), 4); }
    }
    if (p2 == EN(1) || p2 == 0) {
        if (d_1bfad0 == 0) f_146ae4(A(d_1c2edc), 0);
        else {
            { signed char c = d_1bfadc[1].v; f_146ae4(A(d_1c2edc), c); }
            { signed char c = d_1bfadc[1].v;
              if (c == 0) f_147aad(A(d_1c2edc));
              else if (d_1bfb34 == 1) {
                  f_147688(A(d_1c2edc), 0x180002);
                  ToneFamily670_0::play(0x180002,*(volatile int*)&d_1a9820,0x7fff,0x8000,0,1);
              } }
        }
    }
    if (p2 == EN(2) && d_1bfad0 == 1) {
        { signed char c = d_1bfadc[2].v;
          f_147746(A(d_1c2edc), (unsigned short)((short)c * 0x147)); }
        f_147688(A(d_1c2edc), 0x180002);
        ToneFamily670_1::play(0x180002,*(volatile int*)&d_1a9820,0x7fff,0x8000,0,1);
    }
}
static inline void refresh491(int p){int i=d_1bfad0;if(i==0)d_1bfadc[1].v=0;for(i=0;(short)i<0x26;i++){int k=(short)i;Opt*it=&d_1a5b88[k];int kind=it->c5;if(kind==1)f_0d99d0(p,it,k,1);else if(kind==3)f_0d98c0(p,it,k,1);}f_0d97b0(p);}
//@ f_0d7a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Lädt die gespeicherten Spieleinstellungen aus der Konfigurationsdatei RIVA.CFG (d_1a5aec) in die
 *   Optionen-Registrierung (d_1bfad4), setzt bei fehlender Datei alle 25 Optionswerte auf die Standardtabelle
 *   d_1a5afc zurück, aktualisiert bei geöffnetem Optionsmenü sämtliche Schalter- und Regleranzeigen und wendet
 *   die Audioeinstellungen über f_0d78c0 an.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Gibt 1 zurück, wenn RIVA.CFG erfolgreich geladen wurde, oder 0, wenn auf die Standardwerte
 *   zurückgegriffen werden musste.
 === Ende Beschreibung === */
int f_0d7a20(int p1)
{
struct R { static void refresh(int p) {
    if (d_1bfad0 == 0) d_1bfadc[1].v = 0;
    for (int i = 0; (short)i < 0x26; i++) {
        int k = (short)i;
        Opt *it = &d_1a5b88[k];
        int kind = it->c5;
        if (kind == 1) f_0d99d0(p, it, k, 1);
        else if (kind == 3) f_0d98c0(p, it, k, 1);
    }
    f_0d97b0(p);
}
static void restore(int p) {
    short i = 0;
    do {
        *d_1a5afc[i].p = d_1a5afc[i].v;
        i++;
    } while (i < (short)0x19);
    if (d_1bfb34 == 1) {
        refresh(p);
        f_0d78c0(p, 0);
        return;
    }
    if (d_1bfad0 == 0) d_1bfadc[1].v = 0;
}
};
    int result = 1;
    d_1a965c = d_1a5aec;
    if (((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1448b0( 0, 0x200) == 1) {
        f_012700(A(d_1bfad4), A((*(int*)&d_1c2098)));
        ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1449a0();
        if (d_1bfb34 == 1) {
            R::refresh(p1);
            f_0d78c0(p1, 0);
        } else {
            if (d_1bfad0 == 0) d_1bfadc[1].v = 0;
            f_0d78c0(p1, 0);
        }
    } else {
        R::restore(p1);
        result = 0;
    }
    return result;
}
//@ f_0d7be0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Speichert die aktuellen Spieleinstellungen aus der Optionen-Registrierung (d_1bfad4) in die
 *   Konfigurationsdatei RIVA.CFG (d_1a5aec).
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d7be0()
{
    d_1a965c = d_1a5aec;
    ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_144890( 0);
    f_012870(A(d_1bfad4), A((*(int*)&d_1c2098)));
    ((RivaFileManager*)(A((*(int*)&d_1c2098))))->f_1449a0();
}
//@ f_0d7c20
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Setzt alle 25 Konfigurationswerte anhand der Tabelle d_1a5afc auf ihre Werkseinstellungen zurück
 *   und zeichnet bei geöffnetem Optionsmenü (d_1bfb34 == 1) sämtliche Schalter, Schieberegler und das
 *   Vorschau-Symbol neu.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d7c20(int p1)
{
    short i = 0;
    do {
        *d_1a5afc[i].p = d_1a5afc[i].v;
        i++;
    } while (i < (short)0x19);
    if (d_1bfb34 == 1) {
        int p = p1;
        if (d_1bfad0 == 0) d_1bfadc[1].v = 0;
        for (i = 0; i < 0x26; i++) {
            struct Opt *it = &d_1a5b88[i];
            int kind = it->c5;
            if (kind == 1) f_0d99d0(p, it, i, 1);
            else if (kind == 3) f_0d98c0(p, it, i, 1);
        }
        f_0d97b0(p);
        f_0d78c0(p1, 0);
        return;
    }
    if (d_1bfad0 == 0) d_1bfadc[1].v = 0;
}
#pragma inline_depth(20)
static inline void setm(int m){d_1bf51c=(short)m;} // haelt die Stapelplatz-Reihenfolge wie im Original
//@ f_0d7ce0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Baut aus der Tabelle der 38 Optionsfelder (d_1a5b88) die Liste der anklickbaren Maus-Rechtecke
 *   (d_1bfb64, einschließlich getrennter Plus-/Minus-Zonen 128 + i und 166 + i für Regler vom Typ 3), sichert
 *   die bisherigen Mauszonen und den Mauszeiger im Optionsmenü-Objekt und aktiviert den Rückruf f_0d7830.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d7ce0(int p1)
{
    short n = 0;
    short i;
    if (!*(volatile unsigned char *)&d_1bf4ef) {
        for (i = 0; i < 38; ++i) {
            if (d_1a5b88[i].c4 < 3) {
                d_1bfb64[n].x0 = d_1a5b88[i].x;
                d_1bfb64[n].y0 = d_1a5b88[i].y;
                d_1bfb64[n].x1 = d_1a5b88[i].x + d_1bfb38[d_1a5b88[i].c4];
                d_1bfb64[n].y1 = d_1a5b88[i].y + d_1bfb4e[d_1a5b88[i].c4];
                d_1bfb64[n].id = 128 + i;
                n++;
            } else if (d_1a5b88[i].c4 == 3) {
                d_1bfb64[n].x0 = d_1a5b88[i].x;
                d_1bfb64[n].y0 = d_1a5b88[i].y;
                d_1bfb64[n].x1 = d_1a5b88[i].x + d_1bfb3e;
                d_1bfb64[n].y1 = d_1a5b88[i].y + d_1bfb54;
                d_1bfb64[n].id = 128 + i;
                n++;
                d_1bfb64[n].x0 = d_1bfb64[n - 1].x1 + d_1bfb4c + 2;
                d_1bfb64[n].y0 = d_1bfb64[n - 1].y0;
                d_1bfb64[n].x1 = d_1bfb64[n].x0 + d_1bfb40;
                d_1bfb64[n].y1 = d_1bfb64[n - 1].y1;
                d_1bfb64[n].id = 166 + i;
                n++;
            } else {
                d_1bfb64[n].x0 = d_1a5b88[i].x;
                d_1bfb64[n].y0 = d_1a5b88[i].y;
                d_1bfb64[n].x1 = d_1a5b88[i].x + d_1a5b72[d_1a5b88[i].c4];
                d_1bfb64[n].y1 = d_1a5b88[i].y + d_1a5b78[d_1a5b88[i].c4];
                d_1bfb64[n].id = 128 + i;
                n++;
            }
        }
        d_1bfb64[n].x0 = 0;
        d_1bfb64[n].y0 = 0;
        d_1bfb64[n].x1 = 319;
        d_1bfb64[n].y1 = 199;
        d_1bfb64[n].id = 240;
        *(int *)(p1 + 0xd9) = *(int *)&d_1bf514;
        I4(p1, 0xd5) = *(volatile int *)&d_1bf510; // haelt die Ladereihenfolge wie im Original
        d_1bf510 = (int)&d_1bfb64[0];
        d_1bf514 = 0;
        I2(p1, 0xfd) = d_1bf4bc;
        I2(p1, 0xff) = d_1bf4be;
        f_0d2f90(0, 1);
        I4(p1, 0xe7) = d_1bf520;
        I4(p1, 0xe3) = d_1bf524;
        I2(p1, 0xe1) = *(short *)&d_1bf51c;
        *(volatile short *)&d_1bfaca = 0;
        *(volatile int *)&d_1bf520 = d_1a6218;
        d_1bf524 = (int)f_0d7830;
        setm(1);
        d_1bfacc = 2;
        short result = f_0d3530(d_1bf520);
        if (result != 0xf0) {
            result -= 0x80;
            if (result >= 0x26) result -= 0x26;
            d_1bfacc = result;
        }
    } else {
        d_1bfacc = 2;
    }
}
//@ f_0d8010
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Stellt beim Verlassen des Optionsmenüs die zuvor in f_0d7ce0 gesicherten Maus-Klickzonen, die
 *   Rückruffunktion und die Mauszeigerform wieder her.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d8010(int p1)
{
    f_0d3870();
    if (!*(unsigned char *)&d_1bf4ef) {
        d_1bf51c = 0;
        d_1bf520 = I4(p1, 0xe7);
        d_1bf524 = I4(p1, 0xe3);
        d_1bf51c = I2(p1, 0xe1);
        d_1bf510 = I4(p1, 0xd5);
        (d_1bf514) = I4(p1, 0xd9);
        f_0d2f90(I2(p1, 0xfd), 1);
        d_1bf4be = I2(p1, 0xff);
    }
}
//@ f_0d8090
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Bereitet das Öffnen des Optionsmenüs vor: lagert den aktuellen Bildschirminhalt bei Bedarf in die
 *   temporäre Auslagerungsdatei optsav.$$$ (d_1a5af0) aus, sichert Textfenster- und Palettenzustand, lädt die 11
 *   Schalter- und Regler-Sprites aus dem Archiv 0x180001, startet die Optionsmenü-Musik (4) und registriert die
 *   Mauszonen über f_0d7ce0.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d8090(int p1)
{
    volatile int c;
    int loc;
    short i;
    d_1bfb34 = 1;
    d_1c0c4c = d_1c0c4c + 1;
    I4(p1, 0xcf) = d_1c2a80;
    if (d_1bd90c == 1 || f_0de800(d_1c0004) != -1) {
        if (d_1bf500 < 0) {
            I4(p1, 0x119) = 1;
            f_0d26e0();
        }
        if (f_0d3860() == 1) { f_0d2710(); c = 1; } else c = 0;
        f_09ac80(d_1a34e0, d_1a5af0, 0);
        if (c == 1) f_0d26e0();
    }
    I2(p1, 0x115) = d_1bd90c;
    d_1bd90c = 0;
    I2(p1, 0x117) = d_1bd910;
    d_1bd910 = 0;
    f_05e2a0(A(d_1c38b0), p1 + 0xef, p1 + 0xf1, p1 + 0xf3, p1 + 0xf5);
    f_05e2d0(A(d_1c38b0), 0, 0x140, 0, 0);
    f_05e360(A(d_1c38b0), p1 + 0xeb, p1 + 0xed);
    f_05e320(A(d_1c38b0), 0xfd, -1);
    I2(p1, 0xfb) = f_0c0020(A(d_1c2c64), 6);
    I4(p1, 0xdd) = f_014540(0x300, (int)d_1a5acc, 0x2ae);
    f_149eb4(I4(p1, 0xdd), 0, 0x100);
    I4(p1, 0x111) = 0;
    for (i = 0; i < (short)0xb; i++) {
        f_050580(A(d_1c2be0), 0x180001, i, A(d_1bfb38[i]), A(d_1bfb4e[i]));
        Spr9 *q = new (mark(d_1a5acc, 0x2b6)) Spr9;
        I4(p1, 0xa3 + (i + i) * 2) = (int)(q ? (Spr9 *)((int)(((RivaRasterImage*)((int)q))->f_0fac80( d_1bfb38[i], d_1bfb4e[i]))) : q);
        f_04feb0(A(d_1c2be0), 0x180001, ((int)(((RivaRasterImage*)(I4(p1, 0xa3 + i * 4)))->f_0fb0b0())), 0, i, 0, (int)&loc, (int)&loc, 0x140);
    }
    I2(p1, 0x11d) = f_0d40b6(A(d_1c2e78));
    f_0d3f25(A(d_1c2e78), 4);
    f_0d7ce0(p1);
    f_0d3770();
}
//@ f_0d82f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Räumt das Optionsmenü beim Schließen wieder ab: gibt die 11 Schalter-Sprites und den Auswahlrahmen
 *   frei, stellt Textfenster-, Mauszonen- und Musikzustand wieder her, blendet die Anzeige aus und lädt den
 *   zuvor in optsav.$$$ gesicherten Hintergrundbildschirm samt Palette zurück.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d82f0(int p1)
{
    short i;
    volatile int c;
    int t, u;
    for (i = 0; i < (short)0xb; i++) {
        t = *(int *)(p1 + 0xa3 + i * 4);
        if (t != 0) {
            operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
        }
    }
    if (I4(p1, 0x111) != 0) {
        t = I4(p1, 0x111);
        if (t != 0) operator delete((void *)((int)(((RivaRasterImage*)(t))->f_0fad20( 0))));
    }
    d_1c2a80 = I4(p1, 0xcf);
    d_1bd90c = I2(p1, 0x115);
    d_1bfb34 = 0;
    d_1bd910 = I2(p1, 0x117);
    f_05e320(A(d_1c38b0), I2(p1, 0xeb), I2(p1, 0xed));
    f_05e2d0(A(d_1c38b0), I2(p1, 0xef), I2(p1, 0xf1), I2(p1, 0xf3), I2(p1, 0xf5));
    f_0c0020(A(d_1c2c64), I2(p1, 0xfb));
    f_0d3870();
    if ((char)d_1bf4ef == (char)0) {
        d_1bf51c = 0;
        d_1bf520 = I4(p1, 0xe7);
        d_1bf524 = I4(p1, 0xe3);
        d_1bf51c = I2(p1, 0xe1);
        d_1bf510 = I4(p1, 0xd5);
        (d_1bf514) = I4(p1, 0xd9);
        f_0d2f90(I2(p1, 0xfd), 1);
        d_1bf4be = I2(p1, 0xff);
    }
    f_09a140(0, 0x19);
    int t_449 = f_0d3860();
    if (t_449 == 1) { f_0d2710(); c = 1; } else c = 0;
    f_09a0d0(d_1a34e0);
    if (d_1bd90c == 1 || f_0de800(d_1c0004) != -1) {
        f_09ade0(d_1a34e0, d_1a5af0, 0);
        f_09aed0(d_1a5af0);
        u = f_09a120(I4(p1, 0xdd), 0x19);
    }
    else {
        (*(volatile short *)&d_1c2198) = 1;
        d_1c2a80 = 0;
        u = -1;
    }
    if (c == 1) f_0d26e0();
    if (I4(p1, 0x119) == 1) f_0d2710();
    delete (void *)I4(p1, 0xdd);
    f_147aad(A(d_1c2edc));
    f_0d3f25(A(d_1c2e78), I2(p1, 0x11d));
    d_1c0c4c--;
}
//@ f_0d8520
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Führt die interaktive Hauptschleife des Optionsmenüs aus: öffnet und zeichnet die Optionsmaske
 *   (f_0d8090, f_0d9670), verarbeitet Pfeiltasten-, Tab-, Eingabe-, Plus-/Minus- und Mausklick-Ereignisse auf
 *   den 38 Optionsfeldern (Hilfetext bei Typ 0, Umschalter f_0d8950 bei Typ 1, Aktionsknopf f_0d8d20 bei Typ 2,
 *   Zahlenregler f_0d8c00 bei Typ 3) und schließt das Menü bei Escape oder Rechtsklick über f_0d82f0.
 * - Eingaben: Übergeben wird der Zeiger auf das Optionsmenü-Objekt (p1).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0d8520(int p1)
{
    struct Ui905 {
        static int integer(short x) { return x; }
        static int selection() { return d_1bfacc; }
        static int previous() { return d_1a5afa; }
        static Opt *at(int x) { return &d_1a5b88[x]; }
        static int kind(Opt *p) { return p->c5; }
        static int mouseX() { return *(volatile short *)&d_1bfaca; } // haelt die Ladereihenfolge wie im Original
    };
    Opt *q;
    int index;
    
    f_0d8090(p1);
    f_0d9670(p1,1);
    *(volatile short *)&d_1c2198 = 0;
    d_1a5afa = -1;
    do {
        if(d_1c2198 != (short)0) { f_0d9670(p1,0); d_1c2198=0; }
        f_068f40();
        f_0f0130(A(d_1c2e68));
        if(d_1bfaca != d_1bf4bc) {
            d_1bf51c=0;
            f_0d2f90(Ui905::mouseX(),1);
            d_1bf51c=1;
        }
        if(d_1bd766==0x4800 || d_1bd766==0x5000 || d_1bd766==(unsigned short)0x4b00 || d_1bd766==0x4d00 || d_1bd766==0xf09) {
            d_1bf51c=0;
            if(Ui905::selection()==-1) (d_1bfacc)=2;
            else {
                int direction=d_1bd766==0x4800?0:d_1bd766==0x5000?1:d_1bd766==(unsigned short)0x4b00?2:d_1bd766==0x4d00?3:4;
                direction=(direction & 0) ? 0 : direction;
                { short value=Ui905::at(d_1bd766)->x;Ui905::at(d_1bd766)->x=value; }
                q=Ui905::at((d_1bfacc));
                { short val905=q->x;q->x=val905;}
                (d_1bfacc)=q->nav[(short)direction];
            }
            d_1bf51c=1;
        }
        if(Ui905::selection() != Ui905::previous()) f_0d9b20(p1);
        if(d_1bd766==0x1c0d || d_1bd766==0x352d || d_1bd766==0x1b2b) {
            d_1bf51c=0;
            q=Ui905::at((d_1bfacc));
            if(Ui905::kind(q)==3 && (d_1bd766==0x1b2b || d_1bd766==0x1c0d)) d_1bd766=(d_1bfacc)+0xa6;
            else d_1bd766=(*(volatile short *)&d_1bfacc)+0x80;
            d_1bf51c=1;
        }
        if(d_1bd766>=128 && d_1bd766<240) {
            d_1bd766-=128;
            index=d_1bd766;
            if(index>=38)index-=38;
            q=Ui905::at(index);
            int kind=Ui905::kind(q);
            if(kind==0) {f_0bf8e0(A(d_1c2c64),0,0,q->v0e,0);d_1bd766=0;}
            else if(kind==3) {f_0d8c00(p1,q,d_1bd766);d_1bd766=0;}
            else if(kind==1) {f_0d8950(p1,q,d_1bd766);d_1bd766=0;}
            else if(kind==2) {f_0d8d20(p1,q,d_1bd766);d_1bd766=0;}
        }
        if(d_1bd766==0x11b)break;
    }while(!f_0d37b0());
    f_0d5b50(0);
    f_0d82f0(p1);
}
#pragma inline_depth(20)
