/* === Beschreibung (Katalog) ===
 * Einheit gz_0640f0_t1 (0x0640f0 - 0x065e40)
 *
 * Überblick
 * Die Einheit gz_0640f0_t1 enthält den ersten Teil einer großen Orts-/Dungeoneinheit (0x0640f0-0x065e40,
 * verknüpft mit environ2_t1 und environ2_t2). Sie verwaltet die Registrierung der lokalen Raum-/Questflags
 * (d_1bd6f0..d_1bd74c), eine mehrstufige Musik-/Tonfolge-Rätselprüfung (f_0646b0), den zentralen
 * Ereignis-Dispatcher f_0648c0 für die Raumaktionen dieses Gebiets sowie mehrere kleine Raum-Handler
 * (f_065c50-f_065e00).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/13 gleich (suche.py 28.10.2026, Basis gz_0640f0_t1_P1.CPP)
// P1 1/13 gleich
// gz_0640f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0640F0-0x065E40
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_038be0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_039040(int p1);                                   // reg eax stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039420(int p1, int p2);                           // reg eax edx stapel 0
int f_040980(int p1, int p2);                           // reg eax edx stapel 0
int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0603b0(int p1);                                   // reg eax stapel 0
int f_065e40();                                         // reg - stapel 0
int f_065f80();                                         // reg - stapel 0
int f_066220();                                         // reg - stapel 0
int f_0663f0();                                         // reg - stapel 0
int f_066780();                                         // reg - stapel 0
int f_0668c0();                                         // reg - stapel 0
int f_066d30();                                         // reg - stapel 0
int f_067030();                                         // reg - stapel 0
int f_067b00();                                         // reg - stapel 0
int f_091f70(int p1);                                   // reg eax stapel 0
int f_0db9d0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de810(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern unsigned char d_1a9820;                    // 0x1A9820
extern unsigned char d_1bc940;                    // 0x1BC940
extern int d_1bd91c;                    // 0x1BD91C
extern int d_1c0004;                    // 0x1C0004
// --- eigene Typen/Prototypen (Pass 1) ---
struct Obj { int a; int *p; char pad[0x34]; };
struct Q { int f0; int f4; void (**vt)(Q *, int, int); short slots[10]; };
extern void (*d_1bae58[])(Q *, int, int);
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern int d_1bae00, d_1c2c64, d_1c2c44, d_1c2edc;
extern signed char d_1c0e84;
extern char d_1bcaa0, d_1bfa9c, d_1c01f8;
extern short d_1c212a;
extern void **d_1c212c;
extern signed char d_1bd6ec;
extern short d_1bd6f0;
extern short d_1bd6f1;
extern short d_1bd6f4;
extern short d_1bd6f5;
extern char d_1bd6f8;
extern short d_1bd6f9;
extern signed char d_1bd6fc;
extern unsigned char d_1bd6fd;
extern signed char d_1bd700;
extern short d_1bd701;
extern char d_1bd704;
extern short d_1bd705;
extern char d_1bd708;
extern short d_1bd709;
extern char d_1bd70c;
extern short d_1bd70d;
extern char d_1bd710;
extern short d_1bd711;
extern char d_1bd714;
extern short d_1bd715;
extern char d_1bd718;
extern short d_1bd719;
extern char d_1bd71c;
extern short d_1bd71d;
extern char d_1bd720;
extern short d_1bd721;
extern char d_1bd724;
extern short d_1bd725;
extern char d_1bd728;
extern short d_1bd729;
extern char d_1bd72c;
extern short d_1bd72d;
extern char d_1bd730;
extern short d_1bd731;
extern char d_1bd734;
extern short d_1bd735;
extern char d_1bd738;
extern short d_1bd739;
extern char d_1bd73c;
extern short d_1bd73d;
extern char d_1bd740;
extern short d_1bd741;
extern signed char d_1bd744;
extern short d_1bd745;
extern char d_1bd748;
extern short d_1bd749;
extern char d_1bd74c;
extern short d_1bd74d;
void f_125400(void *o, const char *a, const char *b, const char *c);
void f_1254a0(void *o, int f);
int f_147323(void *, int, int, int, int, int, int);
int f_147323e(void *, int, int, int, int, int, int);
#pragma aux f_147323e modify [esp];
int f_0bf730(void *, int);
int f_0bf6f0(void *, int);
int f_126410(void *);
short f_1457e0(int);
short f_044c90(int, int, int);



signed char f_0dd440(int);
short f_0de820(int);
short f_060760(int);
int f_0d64a0(int, int);
Q *f_05ff60(void *, int);
void *f_060030(void *, int);

void *f_014710(void *);
int __cdecl f_0bfa20(void *, void *, int, int, int);
void *f_0606a0(int, int);
int f_0600f0(Q *, int);
int f_066b20(Q *);
int f_066e50(Q *);
int f_0677b0(Q *);
int f_069770(void *, int);
int f_060740(int, int);
int f_0607e0(int, int);
void *f_145234(void *, void *);
void f_145254(void *);
void f_145254();
#define OBJ_INIT(o) f_125400(&o, d_1c349c, d_1c3870, d_1c3498)

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0640f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft mit einer Prozentchance p3, ob ein zufälliger Helden-Zwischenfall eintritt: Wählt einen
 *   zufälligen Helden h (f_038be0), spielt das Geräusch 0x360007 ab und würfelt eine Talentprobe auf
 *   Körperbeherrschung (0x32) mit Zuschlag p2. Gelingt die Probe, erscheint Text 0x3600001d, andernfalls Text
 *   0x3600001e samt 2 Lebenspunkten Schaden (f_044300) und einer Wund-/Krankheitsfolge (f_040980(h, 1)).
 * - Eingaben und Rückgabe: Eingaben sind der Kontext p1 (eax, unbenutzt), der Probenmodifikator p2 (edx, short)
 *   und die Auslösewahrscheinlichkeit p3 (ebx, short); die Funktion gibt nichts zurück (void).
 * - Wichtige Variablen: Die lokale Variable h hält den zufällig getroffenen Helden, o den Textkontextrahmen.
 === Ende Beschreibung === */
void f_0640f0(int p1, short p2, short p3)
{
    volatile short s = p2;
    Obj o;
    int h;
    short t = f_1457e0(100);
    if (t <= p3) {
        OBJ_INIT(o);
        h = f_038be0(d_1c0004); o.p[1] = h;
        int v5 = *(int *)&d_1a9820;
        f_147323e(&d_1c2edc, 0x360007, 0x7fff, 0x8000, v5, 0, 1);
        if (f_044c90(h, 0x32, (signed char)s) > 0) {
            f_0bf730(&d_1c2c64, 0x3600001d);
        } else {
            f_0bf730(&d_1c2c64, 0x3600001e);
            f_044300(h, 2);
            f_040980(h, 1);
        }
        f_1254a0(&o, 0);
    }
}

//@ f_0641c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schadet einem lebenden Helden p1 schwer (z. B. durch Säure, Feuer oder Einsturz): Zerstört
 *   falls vorhanden getragene Gegenstände in den Ausrüstungsslots 10 und 9 (f_036300), zieht 30 Lebenspunkte
 *   (f_044300(p1, 0x1e)) ab und senkt, falls der Held den Treffer überlebt, zusätzlich einen Eigenschaftswert
 *   permanent um 1 Punkt (f_0453e0(p1, 2, -1)).
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Heldenstatusabfragen f_042470 (tot) und f_042a60 (Gegenstand im Slot).
 === Ende Beschreibung === */
void f_0641c0(int p1)
{
    if (!((char)(f_042470((struct hero *)(p1))))) {
        if (f_042a60((struct hero *)(p1), 10) > 0) f_036300(p1, 10, 1);
        if (f_042a60((struct hero *)(p1), 9) > 0) f_036300(p1, 9, 1);
        f_044300(p1, 0x1e);
        if (!((char)(f_042470((struct hero *)(p1))))) f_0453e0(p1, 2, -1);
    }
}

//@ f_064240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Compiler-generierter abgeleiteter Destruktor für das Gebiets-Steuerobjekt Q: Ruft bei
 *   gesetztem Bit 4 in p2 den Ausnahme-Abwickler (f_145234/f_145254 mit Tabelle d_1bae00) auf, andernfalls den
 *   Basisklassendestruktor f_060030(p1, 1) und gibt bei gesetztem Bit 2 den Speicher über f_014710 frei.
 * - Eingaben und Rückgabe: Eingaben sind der Objektzeiger p1 (eax) und die Destruktor-Flags p2 (edx);
 *   zurückgegeben wird der Objektzeiger (void * in eax).
 * - Wichtige Variablen: Die globale Tabelle d_1bae00 enthält die Ausnahmeschutz-Deskriptoren der Klasse.
 === Ende Beschreibung === */
void *f_064240(void *p1, unsigned p2)
{
    if (p2 & 4) {
        f_145254(f_145234(p1, &d_1bae00));
        return p1;
    }
    void *r = f_060030(p1, 1);
    if (p2 & 2) f_014710(r);
    return r;
}

#define REG(F, I, ID) F = 0; I = ID; d_1c212c[d_1c212a++] = &F;
//@ f_064280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert 24 persistente Raum-/Ereignis-Flags (d_1bd6f0 bis d_1bd74c) mit ihren jeweiligen
 *   Kennungen (0x20a..0x221 sowie 0x242) und dem Startwert 0 in der globalen Spielstandsliste d_1c212a/d_1c212c.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Struktur d_1c212a (count) und d_1c212c (list) verwaltet die beim
 *   Speichern/Laden gesicherten Zustandsvariablen.
 === Ende Beschreibung === */
struct Obj64280;
struct Reg64280 { short count; Obj64280 **list; void append(Obj64280 *o) { list[count]=o;count++; } };
struct Obj64280 { signed char flag;short number;char pad;Obj64280 *init(Reg64280 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;} };
extern Reg64280 reg64280;
#pragma aux reg64280 "d_1c212a"
extern Obj64280 ob64280_6f0;
#pragma aux ob64280_6f0 "d_1bd6f0"
extern Obj64280 ob64280_6f4;
#pragma aux ob64280_6f4 "d_1bd6f4"
extern Obj64280 ob64280_6f8;
#pragma aux ob64280_6f8 "d_1bd6f8"
extern Obj64280 ob64280_6fc;
#pragma aux ob64280_6fc "d_1bd6fc"
extern Obj64280 ob64280_700;
#pragma aux ob64280_700 "d_1bd700"
extern Obj64280 ob64280_704;
#pragma aux ob64280_704 "d_1bd704"
extern Obj64280 ob64280_708;
#pragma aux ob64280_708 "d_1bd708"
extern Obj64280 ob64280_70c;
#pragma aux ob64280_70c "d_1bd70c"
extern Obj64280 ob64280_710;
#pragma aux ob64280_710 "d_1bd710"
extern Obj64280 ob64280_714;
#pragma aux ob64280_714 "d_1bd714"
extern Obj64280 ob64280_718;
#pragma aux ob64280_718 "d_1bd718"
extern Obj64280 ob64280_71c;
#pragma aux ob64280_71c "d_1bd71c"
extern Obj64280 ob64280_720;
#pragma aux ob64280_720 "d_1bd720"
extern Obj64280 ob64280_724;
#pragma aux ob64280_724 "d_1bd724"
extern Obj64280 ob64280_728;
#pragma aux ob64280_728 "d_1bd728"
extern Obj64280 ob64280_72c;
#pragma aux ob64280_72c "d_1bd72c"
extern Obj64280 ob64280_730;
#pragma aux ob64280_730 "d_1bd730"
extern Obj64280 ob64280_734;
#pragma aux ob64280_734 "d_1bd734"
extern Obj64280 ob64280_738;
#pragma aux ob64280_738 "d_1bd738"
extern Obj64280 ob64280_73c;
#pragma aux ob64280_73c "d_1bd73c"
extern Obj64280 ob64280_740;
#pragma aux ob64280_740 "d_1bd740"
extern Obj64280 ob64280_744;
#pragma aux ob64280_744 "d_1bd744"
extern Obj64280 ob64280_748;
#pragma aux ob64280_748 "d_1bd748"
extern Obj64280 ob64280_74c;
#pragma aux ob64280_74c "d_1bd74c"
void f_064280(void) {
ob64280_6f0.init(reg64280,0x20c,0);
ob64280_6f4.init(reg64280,0x21f,0);
ob64280_6f8.init(reg64280,0x20a,0);
ob64280_6fc.init(reg64280,0x20d,0);
ob64280_700.init(reg64280,0x20e,0);
ob64280_704.init(reg64280,0x20f,0);
ob64280_708.init(reg64280,0x210,0);
ob64280_70c.init(reg64280,0x211,0);
ob64280_710.init(reg64280,0x212,0);
ob64280_714.init(reg64280,0x213,0);
ob64280_718.init(reg64280,0x214,0);
ob64280_71c.init(reg64280,0x215,0);
ob64280_720.init(reg64280,0x216,0);
ob64280_724.init(reg64280,0x217,0);
ob64280_728.init(reg64280,0x218,0);
ob64280_72c.init(reg64280,0x219,0);
ob64280_730.init(reg64280,0x21a,0);
ob64280_734.init(reg64280,0x21b,0);
ob64280_738.init(reg64280,0x21c,0);
ob64280_73c.init(reg64280,0x21d,0);
ob64280_740.init(reg64280,0x21e,0);
ob64280_744.init(reg64280,0x220,0);
ob64280_748.init(reg64280,0x221,0);
ob64280_74c.init(reg64280,0x242,0);
}
//@ f_0646b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet ein vierstufiges Musik- oder Signal-Rätsel (d_1c0e84), wenn die Gruppe in Richtung
 *   5 blickt (f_0de820 == 5) und ein bestimmter NSC/Begleiter in der Gruppe aktiv ist (f_039040, Typ 2): Prüft,
 *   ob der aktuelle Schwierigkeits-/Stufenwert f_0dd440(d_1c0004) zur nächsten Rätselstufe d_1c0e84 + 1 passt.
 *   Bei Fehlversuchen zählt d_1bd6f4 hoch (Warnungen 0x360000ae, 0x360000af und beim dritten Mal Alarm
 *   0x360000b0 samt Gegner-/NSC-Aktivierung f_0d64a0 und d_1bc940 = 1); bei richtiger Eingabe ertönt Sound
 *   0x360004, d_1c0e84 rückt vor und schaltet über f_091f70 (0x22..0x25) die nächste Stufe frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: d_1c0e84 (stage670) hält den Fortschritt (0..4), d_1bd6f4 (count670) zählt Fehlversuche
 *   und d_1bd6f0 (gate670) kennzeichnet den Endzustand.
 === Ende Beschreibung === */
struct S670state {signed char v; int less(int n)const{return v<n;} int equal(int n)const{return v==n;} signed char next(){return ++v;}};
struct U670counter {unsigned char v;unsigned char next(){return ++v;}};
extern S670state stage670;
#pragma aux stage670 "d_1c0e84"
extern S670state gate670;
#pragma aux gate670 "d_1bd6f0"
extern U670counter count670;
#pragma aux count670 "d_1bd6f4"
short difficulty670(int);
#pragma aux difficulty670 "f_0dd440" modify exact [eax]
void f_0646b0(){
void npc670(void);
#pragma aux npc670 "f_0d64a0" modify exact [eax]

 struct Tone670 {static void play(volatile int &flags,int zero){f_147323(&d_1c2edc,0x360004,0x7fff,0x8000,flags,zero,1);}};
 if(f_0de820(d_1c0004)!=5)return;
 if(f_039040(d_1c0004)==0)return;
 if(f_042400((struct hero *)(f_039040(d_1c0004)))!=2)return;
 int low=stage670.less(4);
 if(low){
  short difficulty=difficulty670(d_1c0004);signed char state=stage670.v;
  if((int)difficulty!=(int)state+1){
   switch(count670.next()){
    case 1:f_0bf730(&d_1c2c64,0x360000ae);break;
    case 2:f_0bf730(&d_1c2c64,0x360000af);break;
    case 3:f_0bf730(&d_1c2c64,0x360000b0);npc670();*(int *)&d_1bc940=1;break;
   }
   return;
  }
   count670.v=0;
   Tone670::play(*(volatile int *)&d_1a9820,0);
   stage670.next();
   if(stage670.less(4)){
    f_0bf730(&d_1c2c64,0x360000b1);
    state=stage670.v;short number=state;number+=0x21;f_091f70(number);
   }else{
    f_0bf730(&d_1c2c64,0x360000b2);
    f_091f70(0x25);
   }

 }else{
  Tone670::play(*(volatile int *)&d_1a9820,low);
  if(gate670.equal(0))f_0bf730(&d_1c2c64,0x360000b2);
  else f_0bf730(&d_1c2c64,0x360000b3);
 }
}
//@ f_064880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor des Gebiets-Steuerobjekts Q: Initialisiert die Basisklasse über f_05ff60(p1, 5),
 *   setzt die virtuelle Methodentabelle auf d_1bae58 und belegt alle zehn Entdeckungsslots p1->slots[0..9] mit
 *   -1.
 * - Eingaben und Rückgabe: Eingabe ist der Objektzeiger p1 (eax); zurückgegeben wird der initialisierte
 *   Objektzeiger Q * (eax).
 * - Wichtige Variablen: Das Array p1->slots[0..9] speichert bis zu zehn bereits aufgedeckte Geheimtüren oder
 *   versteckte Objekte (0x7a..0x7f).
 === Ende Beschreibung === */
Q *f_064880(Q *p1)
{
    p1 = f_05ff60(p1, 5);
    p1->vt = d_1bae58;
    short i;
    for (i = 0; i < 10u; i++) p1->slots[i] = -1;
    return p1;
}

//@ f_0648c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentraler Raum- und Ereignis-Dispatcher des Gebiets: Verzweigt anhand des Ereigniscodes p2
 *   (0x65..0x44d) auf über 35 verschiedene Rauminteraktionen, darunter einmalige Hinweise (0x65, 0xc9, 0x1f9,
 *   0x2bd), Schaden/Krankheit (0x66), Zeitfortschritt (0x67), Talentproben auf Sinnenschärfe (0x12e, 0x12f,
 *   0x130) und Körperbeherrschung (0x25a, 0x25b), zeitabhängige Geheimtür-Entdeckungen (0x3e9..0x3ee für
 *   Objekt-IDs 0x7a..0x7f), Karten-/Ebenenwechsel (0xcb, 0x1fb, 0x2bf, 0x321, 0x44c, 0x44d) sowie Aufrufe der
 *   komplexeren Handler in environ2_t1/environ2_t2.
 * - Eingaben und Rückgabe: Eingaben sind das Gebietsobjekt p1 (eax) und der Ereigniscode p2 (edx, unsigned
 *   short); zurückgegeben wird 1 bei bekanntem Ereigniscode, sonst 0.
 * - Wichtige Variablen: Nutzt die Gebietsflags d_1bd6ec..d_1bd744, das Entdeckungs-Array p1->slots[0..9] und das
 *   Flag d_1bd91c bei neu aufgedeckten Kartenobjekten.
 === Ende Beschreibung === */
inline int eqField648(const char &a, signed char b) {
    int av=(signed char)a; av |= av & 0; // Steuert die Feldprioritaet fuer die Registerfolge
    return av == b;
}
inline int eqByte648(const char &a, signed char b) {
    b |= b & 0; // Steuert die Byteprioritaet fuer die Registerfolge
    return (int)(signed char)a == b;
}
inline int flagField648(const char &a, signed char b) { return eqField648(a,b); }
inline int flagByte648(const char &a, signed char b) { return eqByte648(a,b); }

inline int is648(const char &a, signed char b) { return (int)(signed char)a == b; }
inline void check25e(Q *q)
{
    int owner648=(int)q; owner648 |= owner648 & 0; owner648 |= owner648 & 0; // Haelt q vor dem Vergleich im Register
    if (flagField648((const char &)d_1bd728, 0) && ((int (*)(Q *))f_067b00)((Q *)owner648) == 1) { d_1bd728 = 1; f_0603b0(6); }
}
inline void check260(Q *q)
{
    int owner648=(int)q; owner648 |= owner648 & 0; owner648 |= owner648 & 0; // Haelt q vor dem Vergleich im Register
    if (eqByte648((const char &)d_1bd72c, 0) && ((int (*)(Q *))f_067b00)((Q *)owner648) == 1) { d_1bd72c = 1; f_0603b0(7); }
}
// Echte, lokal begrenzte Callee-Vertraege: Analyse/Phase4/clobber.tsv.
void *show648_new(int, int);
#pragma aux show648_new "f_0606a0" parm [eax] [edx] value [eax] modify exact [eax edx];
short show648_msg(void *, void *, int, int, int);
#pragma aux show648_msg "f_0bfa20" parm caller [] value [ax] modify exact [eax];
void *show648_dtor(void *, int);
#pragma aux show648_dtor "f_0fad20" parm [eax] [edx] value [eax] modify exact [eax edx];
void *show648_del(void *);
#pragma aux show648_del "f_014710" parm [eax] value [eax] modify exact [eax];
inline void show648(Q *q)
{
    if (flagField648((const char &)d_1bfa9c, 0)) {
        void *n = show648_new(0x360001, 0);
        show648_msg(&d_1c2c64, n, 0, 0x36000069, 0);
        if (n) show648_del(show648_dtor(n, 0));
        f_0600f0(q, 0x15000c);
        d_1bfa9c = 1;
    }
}
inline int addslotz648(short id, Q *q, int &found)
{
    found = 0;
    for (short i = 0; i < sizeof(q->slots) / sizeof(q->slots[0]); i++) {
        if (q->slots[i] == -1) { q->slots[i] = id; found = 1; break; }
        if (id == q->slots[i]) { found = 0; break; }
    }
    return found;
}
inline void reveal7fparam648(Q *q, short id, int &found)
{
    short lim = 10;
    if (f_126410(&d_1c2c44) <= 0x93a8 || f_126410(&d_1c2c44) > 0x190c8) lim += 5;
    if (f_1457e0(100) > lim) return;
    if (f_069770((char *)q + 2, (short)id) != 1) return;
    int ok = addslotz648(id, q, found);
    if (ok != 1) return;
    d_1bd91c = 1;
    (*q->vt[0])(q, (short)id, 0);
}
int f_0648c0(Q *p1, unsigned short p2)
{
    // Sieben Rahmenwoerter und sechs Inline-Parameter ergeben die Original-Stapellage
    struct { Obj o[11]; int f7c, f7b, f7d, f7a, f7e, ret, f7f; } st;
    int h;
    st.ret = 1;
    switch (p2) {
    case 0x65:
        if (eqByte648((const char &)d_1bd6fc, 0)) { f_0bf730(&d_1c2c64, 0x36000038); d_1bd6fc = 1; }
        break;
    case 0x66:
        if (eqField648((const char &)d_1bd700, 0)) {
            OBJ_INIT(st.o[6]);
            st.o[6].p[1] = h = f_038c40(d_1c0004);
            f_0bf730(&d_1c2c64, 0x36000039);
            f_044300(h, 2);
            f_040a00(h, 2, 0x14);
            d_1bd700 = 1;
            f_1254a0(&st.o[6], 0);
        }
        break;
    case 0x67: f_0bf730(&d_1c2c64, 0x3600003a); f_0db9d0(d_1c0004, 2, 10); break;
    case 0xc9: if (d_1bd6ec == 0) { d_1bd6ec = 1; f_0bf730(&d_1c2c64, 0x3600003b); } break;
    case 0xca:
        if (eqByte648((const char &)d_1bd744, 0) && f_1457e0(100) <= 50) {
            OBJ_INIT(st.o[7]);
            st.o[7].p[1] = f_039420(d_1c0004, 15);
            f_0bf730(&d_1c2c64, 0x3600003c);
            f_0603b0(1);
            d_1bd744 = 1;
            f_1254a0(&st.o[7], 0);
        }
        break;
    case 0xcb:
        { int slot648_mapMsg05_0, slot648_mapMsg05_1; f_0bf730((void *)(slot648_mapMsg05_1 = (slot648_mapMsg05_0 = (int)&d_1c2c64)), 0x3600003d); } // Berechnete Namensfolge fuer ID-Stapelplaetze
        if (f_0bf6f0(&d_1c2c64, 0x3600003e) == 1) f_0de810(d_1c0004, 0x68);
        break;
    case 0xcc: ((int (*)(Q *))f_065e40)(p1); break;
    case 0x12d: ((int (*)(Q *))f_065f80)(p1); break;
    case 0x12e:
        OBJ_INIT(st.o[1]);
        h = f_039320(d_1c0004, 0x1d);
        st.o[1].p[1] = h;
        if (f_044c90(h, 0x1d, 7) > 0) f_0bf730(&d_1c2c64, 0x36000045);
        else f_0bf730(&d_1c2c64, 0x36000046);
        f_1254a0(&st.o[1], 0);
        break;
    case 0x12f:
        OBJ_INIT(st.o[3]);
        h = f_039320(d_1c0004, 0x1d);
        st.o[3].p[1] = h;
        if (f_044c90(h, 0x1d, 7) > 0) f_0bf730(&d_1c2c64, 0x36000046);
        else f_0bf730(&d_1c2c64, 0x36000045);
        f_1254a0(&st.o[3], 0);
        break;
    case 0x130:
        OBJ_INIT(st.o[0]);
        st.o[0].p[1] = f_039320(d_1c0004, 0x1d);
        f_0bf730(&d_1c2c64, 0x36000047);
        f_1254a0(&st.o[0], 0);
        break;
    case 0x191: f_0bf730(&d_1c2c64, 0x36000048); break;
    case 0x192: f_0bf730(&d_1c2c64, 0x36000049); break;
    case 0x1f5: ((int (*)(Q *))f_066220)(p1); break;
    case 0x1f6: f_0bf730(&d_1c2c64, 0x36000059);
 break;
    case 0x1f7: ((int (*)(Q *))f_0663f0)(p1); break;
    case 0x1f8:
        if (flagByte648((const char &)d_1bcaa0, 1) && is648((const char &)d_1bd710, 0) && f_060760(0x1f41) == 1) {
            OBJ_INIT(st.o[8]);
            h = f_039320(d_1c0004, 0x33);
            st.o[8].p[1] = h;
            f_0bf730(&d_1c2c64, 0x3600005b);
            d_1bd710 = 1;
            f_060740(0x1f41, 1);
            f_0607e0(0x1f41, 1);
            f_0607e0(0x1f42, 1);
            f_1254a0(&st.o[8], 0);
        }
        break;
    case 0x1f9:
        if (eqByte648((const char &)d_1bd714, 0)) {
            OBJ_INIT(st.o[4]);
            int context648 = d_1c0004;
            h = f_038c40(context648);
            st.o[4].p[1] = h;
            f_0bf730(&d_1c2c64, 0x3600005c);
            d_1bd714 = 1;
            f_1254a0(&st.o[4], 0);
        }
        break;
    case 0x1fa: break;
    case 0x1fb:
        if (f_0bf6f0(&d_1c2c64, 0x3600005d) == 1) f_0dd7f0(d_1c0004, 0xf, 0x13a3);
        break;
    case 0x259: break;
    case 0x25a:
        if (eqByte648((const char &)d_1bd718, 0)) {
            h = f_038c40(d_1c0004);
            if (f_044c90(h, 0x33, 4) > 0 && f_044c90(h, 0x1d, 4) > 0) {
                d_1bd718 = 1;
                OBJ_INIT(st.o[9]);
                st.o[9].p[1] = h;
                f_0bf730(&d_1c2c64, 0x3600005e);
                f_0603b0(2);
                f_1254a0(&st.o[9], 0);
            }
        }
        break;
    case 0x25b:
        if (eqField648((const char &)d_1bd720, 0)) {
            h = f_039320(d_1c0004, 0x1d);
            if (f_044c90(h, 0x33, 4) > 0 && f_044c90(h, 0x1d, 8) > 0) {
                d_1bd720 = 1;
                OBJ_INIT(st.o[10]);
                st.o[10].p[1] = h;
                f_0bf730(&d_1c2c64, 0x3600005f);
                f_0603b0(3);
                f_1254a0(&st.o[10], 0);
            }
        }
        break;
    case 0x25c: ((int (*)(Q *))f_066780)(p1); break;
    case 0x25d: ((int (*)(Q *))f_0668c0)(p1); break;
    case 0x25e:
        check25e(p1);
        break;
    case 0x25f: break;
    case 0x260:
        check260(p1);
        break;
    case 0x2bd:
        if (eqByte648((const char &)d_1bd730, 0)) {
            d_1bd730 = 1;
            OBJ_INIT(st.o[5]);
            h = f_039320(d_1c0004, 0x1f);
            st.o[5].p[1] = h;
            f_0bf730(&d_1c2c64, 0x36000068);
            f_1254a0(&st.o[5], 0);
        }
        break;
    case 0x2be: show648(p1); break;
    case 0x2bf: f_0de810(d_1c0004, 0x65); break;
    case 0x2c0: f_066b20(p1); break;
    case 0x321:
        if (flagField648((const char &)d_1c01f8, 1)) {
            OBJ_INIT(st.o[2]);
            h = f_038c40(d_1c0004);
            st.o[2].p[1] = h;
            if (f_0bf6f0(&d_1c2c64, 0x36000082) == 1) f_0dd7f0(d_1c0004, 2, 0x1715);
            f_1254a0(&st.o[2], 0);
        }
        break;
    case 0x322: { int slot648_mapMsg19_0, slot648_mapMsg19_1, slot648_mapMsg19_2, slot648_mapMsg19_3; f_0bf730((void *)(slot648_mapMsg19_3 = (slot648_mapMsg19_2 = (slot648_mapMsg19_1 = (slot648_mapMsg19_0 = (int)&d_1c2c64)))), 0x36000083); } // Berechnete Namensfolge fuer ID-Stapelplaetze
 break;
    case 0x385: ((int (*)(Q *))f_066d30)(p1); break;
    case 0x386: f_066e50(p1); break;
    case 0x387: ((int (*)(Q *))f_067030)(p1); break;
    case 0x3e9: reveal7fparam648(p1, 0x7a, st.f7a); break;
    case 0x3ea: reveal7fparam648(p1, 0x7b, st.f7b); break;
    case 0x3eb: reveal7fparam648(p1, 0x7c, st.f7c); break;
    case 0x3ec: reveal7fparam648(p1, 0x7d, st.f7d); break;
    case 0x3ed: reveal7fparam648(p1, 0x7e, st.f7e); break;
    case 0x3ee: reveal7fparam648(p1, 0x7f, st.f7f); break;
    case 0x3ef: f_0677b0(p1); break;
    case 0x44c: f_0de810(d_1c0004, 99); break;
    case 0x44d: f_0de810(d_1c0004, 0x62); break;
    default: st.ret = 0; break;
    }
    return st.ret;
}

//@ f_065c50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten (d_1bd6fc == 0) den Raumtext 0x36000038 aus und setzt das
 *   Einmal-Flag d_1bd6fc = 1 (identisch mit Zweig 0x65 in f_0648c0).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Flag d_1bd6fc verhindert eine wiederholte Textausgabe.
 === Ende Beschreibung === */
void f_065c50()
{
    if (EQ(d_1bd6fc, 0)) {
        f_0bf730(&d_1c2c64, 0x36000038);
        d_1bd6fc = 1;
    }
}

//@ f_065c80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst beim ersten Betreten (d_1bd700 == 0) für den Gruppenanführer (f_038c40) den Ereignistext
 *   0x36000039 aus, zieht ihm 2 Lebenspunkte (f_044300) ab, fügt ihm über f_040a00(h, 2, 0x14) eine
 *   Vergiftung/Krankheit zu und setzt d_1bd700 = 1.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Byte d_1bd700 markiert, dass die Falle bereits ausgelöst hat.
 === Ende Beschreibung === */
void f_065c80()
{
    if (EQ(d_1bd700, 0)) {
        Obj o;
        OBJ_INIT(o);
        int h = f_038c40(d_1c0004);
        o.p[1] = h;
        f_0bf730(&d_1c2c64, 0x36000039);
        f_044300(h, 2);
        f_040a00(h, 2, 0x14);
        d_1bd700 = 1;
        f_1254a0(&o, 0);
    }
}

//@ f_065d10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Meldung 0x3600003a aus und ruft f_0db9d0(d_1c0004, 2, 10) auf (vermutlich
 *   Gruppen-/Umgebungseffekt für Zweig 0x67).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Nutzt d_1c2c64 und d_1c0004.
 === Ende Beschreibung === */
void f_065d10()
{
    f_0bf730(&d_1c2c64, 0x3600003a);
    f_0db9d0(d_1c0004, 2, 10);
}

//@ f_065d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Aufruf (d_1bd6ec == 0) die Meldung 0x3600003b an und setzt d_1bd6ec = 1
 *   (Zweig 0xc9).
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Flag d_1bd6ec speichert den Auslösestatus.
 === Ende Beschreibung === */
void f_065d40()
{
    if (d_1bd6ec == 0) {
        d_1bd6ec = 1;
        f_0bf730(&d_1c2c64, 0x3600003b);
    }
}

//@ f_065d70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei noch nicht gesetztem Flag d_1bd744 mit 50 % Chance (f_1457e0(100) <= 50), ob ein
 *   Held mit Talent 0x0f (f_039420) etwas bemerkt, gibt dann den Text 0x3600003c aus, schaltet über f_0603b0(1)
 *   ein Ereignis frei und setzt d_1bd744 = 1.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Das globale Byte d_1bd744 speichert, ob die Entdeckung bereits erfolgt ist.
 === Ende Beschreibung === */
void f_065d70()
{
    if (EQ(d_1bd744, 0)) {
        if (f_1457e0(100) <= 0x32) {
            Obj o;
            OBJ_INIT(o);
            int h = f_039420(d_1c0004, 0xf);
            o.p[1] = h;
            f_0bf730(&d_1c2c64, 0x3600003c);
            f_0603b0(1);
            d_1bd744 = 1;
            f_1254a0(&o, 0);
        }
    }
}

//@ f_065e00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Beschreibung 0x3600003d aus, stellt anschließend die Entscheidungsfrage 0x3600003e
 *   und wechselt bei Zustimmung über f_0de810(d_1c0004, 0x68) den Ortspunkt.
 * - Eingaben und Rückgabe: Keine Parameter, kein Rückgabewert (void).
 * - Wichtige Variablen: Greift auf d_1c2c64 und d_1c0004 zu.
 === Ende Beschreibung === */
void f_065e00()
{
    f_0bf730(&d_1c2c64, 0x3600003d);
    if (f_0bf6f0(&d_1c2c64, 0x3600003e) == 1) f_0de810(d_1c0004, 0x68);
}
