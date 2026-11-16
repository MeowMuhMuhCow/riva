/* === Beschreibung (Katalog) ===
 * Einheit gz_110d90 (0x110d90 - 0x112340)
 *
 * Überblick
 * Diese Einheit implementiert weitere Zaubersprüche aus den Bereichen Hellsicht, Kampf, Verständigung und
 * Bewegung (darunter *Adlerauge Luchsenohr*, *Exposami Lebenskraft*, *Odem Arcanum*, *Penetrizzel*, *Sensibar*,
 * *Eisenrost und Grüner Span*, *Körperlose Reise*, *Silentium Schweigekreis*, *Flim Flam Funkel*, *Dunkelheit*,
 * *Foramen Foraminor*, *Motoricus* und *Spurlos Trittlos*).
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 24/32 gleich (suche.py 25.10.2026, Basis gz_110d90_P1.CPP)
// gz_110d90.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x110D90-0x112340
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
short f_030960(int p1);
int f_033c50(int p1, int p2, int p3);
int f_0348d0(int p1, int p2, int p3);
int f_039040(int p1);
int f_039070(int p1);
short f_03d3d0(int p1, int p2, int p3);
unsigned char f_042380(int p1);
signed char f_042400(int p1);
int f_0424f0(int p1, int p2);
int f_042570(int p1, int p2);
signed char f_0425a0(int p1);
signed char f_042750(int p1);
int f_042800(int p1, int p2);
signed char f_0428d0(int p1);
short f_0429a0(int p1);
int f_0429c0(int p1, int p2);
short f_042a60(int p1, int p2);
short f_042b50(int p1, int p2);
int f_042bb0(int p1, int p2);
short f_042d00(int p1, int p2);
signed char f_043120(int p1);
int f_043240(int p1, int p2);
int f_043260(int p1, int p2);
signed char f_043270(int p1);
int f_043c90(int p1);
int f_043ca0(int p1);
int f_043ce0(int p1);
int f_043cf0(int p1);
unsigned short f_043dc0(int p1);
int f_043dd0(int p1, int p2);
int f_043e20(int p1, int p2);
signed char f_043e30(int p1);
int f_0773b0(int p1);

int f_0bf730(int p1, int p2);
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0cf970(int p1, int p2);
signed char f_0cf990(int p1);
signed char f_0cfa70(int p1);
int f_0cfae0(int p1, int p2);
int f_0cfb10(int p1, int p2);
int f_0cfd80(int p1, int p2);
signed char f_0cfda0(int p1);
int f_0cfdb0(int p1, int p2);
int f_0cfe40(int p1, int p2);
int f_0cff00(int p1, int p2);
int f_0d0460(int p1);
short f_0d4aa0(int p1, int p2);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0d5290(int p1, int p2);
short f_0de800(int p1);
int f_0e93f0(int p1, int p2, int p3);
short f_10ccf0(int p1, int p2);
int f_10d5e0(int p1, int p2);
int f_10d640(int p1);
int f_10f250(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_1457e0(int p1);
short f_145850(int p1, int p2, int p3);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern signed char d_1a47ac[];
extern int d_1bd6c0;                    // 0x1BD6C0
extern short d_1bd928;
extern short d_1bd938;
extern int d_1c0004;                    // 0x1C0004
extern int d_1c0424;                    // 0x1C0424
extern short d_1c0428;
extern signed char d_1c042a;
extern char d_1c0834[];
extern char d_1c21b4[];
extern int d_1c2c40;                    // 0x1C2C40
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
#pragma intrinsic(strcpy)
#define S(p,o) (*(short *)((p)+(o)))
#define I(p,o) (*(int *)((p)+(o)))
#define C(p,o) (*(signed char *)((p)+(o)))
#define M38 ((int)d_1c38b0)
#define M21 ((int)d_1c21b4)
#define M64 ((int)d_1c2c64)
#define CTOR f_125400((int)&ob, (int)d_1c349c, (int)d_1c3870, (int)d_1c3498)
#define DTOR f_1254a0((int)&ob, 0)
struct Ob { int w0; int p4; int p8; int pc; int p10; int p14; int p18; int p1c; char pad[0x1c]; };

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_110d90
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert die Zauber *Adlerauge Luchsenohr* (0x28), *Sensibar* (0x2d), *Axxeleratus
 *   Blitzgeschwind* (0x39), *Flim Flam Funkel* (0x44) und *Spurlos Trittlos* (0x4d), die je nach Zauber-ID
 *   temporäre Talent-, Licht- oder Kampfboni für den Zaubernden oder die Heldengruppe aktivieren.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_110d90(int p1)
{
    struct Ob ob;
    CTOR;
    if (f_0de800(d_1c0004) != -1) {
        f_0bf730(M64, 0x17000114);
        S(p1,0) = (short)0xfffc;
        DTOR;
        return;
    }
    f_10d5e0(0x2b, f_042380(I(p1,0x12)));
    f_10d640(0x2b);
    d_1c0424 = 1;
    if (d_1c0428 == 3) {
        I(ob.p4,4) = I(p1,0x12);
        f_0bf730(M64, 0x1700000a);
    } else if ((*(short (**)(int,int))(I(d_1bd6c0,8) + 0x28))(d_1bd6c0, 0x2b) != 0) {
        (*(void (**)(int,int))(I(d_1bd6c0,8) + 0x2c))(d_1bd6c0, 0x2b);
    }
    DTOR;
}

//@ f_110e70
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft vor Ausführung eines Hellsicht-/Verständigungszaubers, ob ein Gruppenmitglied
 *   (f_039040(d_1c0004)) eine besondere Bedingung erfüllt (Ausgabe von 0x170000f4 + c), oder bricht außerhalb
 *   gültiger Zauberkontexte (d_1c0428 == 0) mit der Meldung 0x170000aa und Fehlercode -4 (0xfffc) ab.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: h (gefundener Held), S(p1, 0) (Astralkosten / Statuscode).
 === Ende Beschreibung === */
void f_110e70(int p1)
{
    int h;
    signed char c;
    h = f_039040(d_1c0004);
    if (h != 0) {
        c = f_042400(h);
        f_0e93f0(M38, M21, c + 0x170000f4);
        return;
    }
    if (d_1c0428 == (short)0) {
        f_0e93f0(M38, M21, 0x170000aa);
        S(p1,0) = (short)0xfffc;
    }
}

//@ f_110ed0
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert auf dem Zaubernden I(p1, 0x12) über f_042570(..., 1) das Statusflag für magische
 *   Hellsicht/Wahrnehmung und gibt die Erfolgsmeldung 0x17000061 aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: ob (Textkontext Ob).
 === Ende Beschreibung === */
void f_110ed0(int p1)
{
    struct Ob ob;
    CTOR;
    f_042570(I(p1,0x12), 1);
    I(ob.p4,4) = I(p1,0x12);
    f_0e93f0(M38, M21, 0x17000061);
    DTOR;
}

//@ f_110f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Stuft den magischen Schutz- oder Sichtzustand (f_043dc0) des Zielhelden I(p1, 0x16) bei gesetztem
 *   Flag d_1bd928 über f_043dd0 um eine Stufe (auf 1 bzw. 2) hoch oder bricht mit 0x170000be (-4) ab, wenn
 *   bereits Stufe 2 erreicht ist.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: u (Zielheld I(p1, 0x16)), c (aktuelle Stufe aus f_043dc0), p3 (Meldungs-ID 0x170000d4
 *   oder 0x17000062).
 === Ende Beschreibung === */
void f_110f30(int p1)
{
    struct Ob ob;
    signed char c;
    int u;
    int p3;
    CTOR;
    u = I(p1,0x16);
    I(ob.p4,4) = u;
    c = f_043dc0(u);
    if (c == (short)2) {
        f_0e93f0(M38, M21, 0x170000be);
        S(p1,0) = (short)0xfffc;
    } else {
        if (*(char *)&d_1bd928) {
            if ((signed char)f_043dc0(I(p1,0x16))) {
                f_043dd0(I(p1,0x16), 2);
            } else {
                f_043dd0(I(p1,0x16), 1);
            }
        }
        if (f_0773b0(d_1c0004)) { p3 = 0x170000d4; } else { p3 = 0x17000062; }
        f_0e93f0(M38, M21, p3);
    }
    DTOR;
}

//@ f_110ff0
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert für den Zaubernden I(p1, 0x12) einen stufenabhängigen Langzeitbonus (Dauer Stufe * 0x1c2,
 *   Typ 0x0d, Wirkung 0x11 über f_0d5290 und f_0d5040), sofern dieser noch nicht aktiv ist (f_043c90(u) == 0,
 *   sonst Abbruch mit 0x170000bf).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: u (Zaubernder), s (Timer-Slot), c (Heldenstufe aus f_0428d0).
 === Ende Beschreibung === */
void f_110ff0(int p1)
{
    struct Ob ob;
    signed char c;
    short s;
    int u;
    CTOR;
    u = I(p1,0x12);
    I(ob.p4,4) = u;
    if (f_043c90(u) != 0) {
        f_0e93f0(M38, M21, 0x170000bf);
        S(p1,0) = (short)0xfffc;
    } else {
        s = f_0d4c80(I(p1,0x12));
        f_0d5290(I(p1,0x12), 0x11);
        f_0d5040(I(p1,0x12), s, f_0428d0(I(p1,0x12)) * 0x1c2, 0, 1, 0xd);
        c = f_0428d0(I(p1,0x12));
        S(ob.p14,2) = c * 5;
        f_0e93f0(M38, M21, 0x170000ab);
    }
    DTOR;
}

//@ f_1110c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt für den Zaubernden I(p1, 0x12) bei d_1bd938 < 0x96 die Aktion f_042800(..., 0x0d) aus oder
 *   meldet andernfalls ein Misslingen (S(p1, 0) = -2).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bd938 (globaler Zähler/Schwellenwert).
 === Ende Beschreibung === */
void f_1110c0(int p1)
{
    if (d_1bd938 < (short)0x96) {
        f_042800(I(p1,0x12), 0xd);
        return;
    }
    S(p1,0) = (short)0xfffe;
}

//@ f_1110f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt je nach Zieltyp C(p1, 5) entweder auf einem Gruppenmitglied (C(p1, 5) == 2, f_043240(I(p1,
 *   0x16), 3), Meldung 0x17000064) oder auf einem Gegner (f_0cfd80(I(p1, 0x1a), 3), Meldung 0x17000063) den
 *   Kampfstatuswert 3 (z. B. *Bannbaladin* / *Horriphobus*-Effekt).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: C(p1, 5) (Zielart: 2 = Held, sonst Gegner).
 === Ende Beschreibung === */
void f_1110f0(int p1)
{
    struct Ob ob;
    CTOR;
    if (C(p1,5) == 2) {
        f_043240(I(p1,0x16), 3);
        I(ob.p4,4) = I(p1,0x16);
        f_0e93f0(M38, M21, 0x17000064);
    } else {
        f_0cfd80(I(p1,0x1a), 3);
        I(ob.p8,4) = I(p1,0x1a);
        S(ob.p1c,2) = 1;
        f_0e93f0(M38, M21, 0x17000063);
    }
    DTOR;
}

//@ f_111190
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Hellsichtzauber *Eigenschaften seid gelesen* / *Analüs Arcanstruktur* (0x29), mit
 *   dem der Spieler einen Gegenstand im Inventar des Zaubernden auswählen und auf magische Eigenschaften
 *   untersuchen kann.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_111190(int p1)
{
    struct Ob ob;
    short m;
    short t;
    short v;
    unsigned char k;
    int u;
    signed char c;
    CTOR;
    int t_245 = f_0429a0(I(p1,0x12));
    if (t_245 > (short)6) {
        v = f_0429a0(I(p1,0x12));
        v = ((short)(v & 0xffff) - 5) / 2; // erzwingt 16-Bit-Maske vor Subtraktion wie im Original
        S(ob.p14,2) = v;
        if (v < 10) {
            m = f_0bf7b0(M64, 1, 0x17000065, 0, v, 0);
        } else {
            m = f_0bf7b0(M64, 2, 0x17000065, 0, v, 0);
        }
        d_1c21b4[0] = 0;
        if (m > 0) {
            t = (short)((m * 2 + 5) & 0xffff); // erzwingt 16-Bit-Maske vor Speicherung wie im Original
            if (f_03d3d0(I(p1,0x12), 0x32, C(p1,4)) > 0) {
                S(p1,0) = t;
                S(p1,0) += d_1c042a;
                c = m + 1;
                f_043260(I(p1,0x12), c);
                I(ob.p4,4) = I(p1,0x12);
                S(ob.p14,2) = m;
                f_0e93f0(M38, M21, 0x17000066);
            } else {
                S(p1,0) = (short)0xfffe;
                S(p1,2) = t / (short)2;
            }
        } else {
            S(p1,0) = (short)0xfffc;
        }
    } else {
        I(ob.p4,4) = I(p1,0x12);
        f_0e93f0(M38, M21, 0x17000083);
        S(p1,0) = (short)0xfffc;
    }
    DTOR;
}
//@ f_111300
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Eisenrost und Grüner Span* (0x33), der je nach Zielart (f_030960) entweder
 *   die ausgerüstete Waffe (Slot 3) eines Helden I(p1, 0x16) über f_033c50 zerstört/beschädigt (0x1700006a) oder
 *   die Waffe eines Gegners I(p1, 0x1a) über f_0cfdb0(..., 1) unbrauchbar macht (0x17000069), sofern diese
 *   metallisch und nicht magisch geschützt ist.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: k (Gegenstands-ID in Slot 3 des Ziels), ob (Textkontext).
 === Ende Beschreibung === */
int f_042d00(unsigned p1, int p2);
void f_111300(int p1)
{
    Ob ob;
    short k;
    CTOR;
    signed char t_288 = f_030960(I(p1,0x12));
    if (t_288 == (short)2) {
        k = f_042a60(I(p1,0x16), 3);
        if (!k) {
            S(p1,0) = (short)0xfffe;
        } else if (f_042bb0(I(p1,0x16), 3)) {
            f_0e93f0(M38, M21, 0x17000068);
        } else if (f_042d00((unsigned)I(p1,0x16), 3)) {
            f_033c50(I(p1,0x16), 3, 1);
            I(ob.p4,4) = I(p1,0x16);
            I(ob.pc,4) = (*(int **)&d_1c2c40)[(short)(k & 0xffff)]; // erzwingt 16-Bit-Maske beim Tabellenindex wie im Original
            S(*(int *)ob.pad,2) = 1;
            f_0e93f0(M38, M21, 0x1700006a);
        } else {
            S(p1,0) = (short)0xfffe;
        }
    } else {
        if (!f_0cf990(I(p1,0x1a))) {
            f_0e93f0(M38, M21, 0x17000067);
        } else if (f_0cfda0(I(p1,0x1a))) {
            f_0e93f0(M38, M21, 0x17000068);
        } else {
            f_0cfdb0(I(p1,0x1a), 1);
            I(ob.p8,4) = I(p1,0x1a);
            S(ob.p1c,2) = 1;
            f_0e93f0(M38, M21, 0x17000069);
        }
    }
    DTOR;
}
//@ f_111440
/* === Beschreibung (Katalog) ===
 * - Zweck: Würfelt für einen Kampf-/Schadenszauber 3W6 + Stufe (f_145850(3, 6, 0) + f_0428d0), begrenzt den Wert
 *   auf die vorhandene Astralenergie des Zaubernden (f_0429a0), wendet den Schaden über f_10ccf0 an und trägt
 *   die resultierenden Astralkosten zuzüglich d_1c042a in S(p1, 0) ein.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (Schadenswurf), t (Astralenergie bzw. verrechnete Kosten).
 === Ende Beschreibung === */
void f_111440(int p1)
{
    short s, t;
    signed char c;
    s = f_145850(3, 6, 0);
    c = f_0428d0(I(p1,0x12));
    s = s + c;
    t = f_0429a0(I(p1,0x12));
    if (s > t) {
        s = f_0429a0(I(p1,0x12));
    }
    t = f_10ccf0(p1, (int)s);
    S(p1,0) = t;
    S(p1,0) += (short)d_1c042a;
}

//@ f_1114a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Kampfzauber *Fulminictus* / *Ignifaxius* (0x35), bei dem der Spieler die Anzahl der
 *   Schadenswürfel n (bis Stufe + 1) über f_0bf7b0 (0x1700006b) wählt, nach gelungener Probe (f_03d3d0 mit 0x35)
 *   nW6 Schaden (f_145850(n, 6, 0)) ausgewürfelt und über f_10ccf0 zugefügt wird sowie Rüstungsschutz (cost =
 *   damage / 10) und AT/PA-Werte (-n / 2) des getroffenen Helden oder Gegners gesenkt werden.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: n (gewählte Würfelanzahl), damage (ausgewürfelter und modifizierter Schaden), cost
 *   (Rüstungsminderung damage / 10), half (-n / 2 AT/PA-Abzug).
 === Ende Beschreibung === */
void f_1114a0(int p1)
{
  struct Context:Ob {
    Context(){f_125400((int)this,(int)d_1c349c,(int)d_1c3870,(int)d_1c3498);}
    ~Context(){f_1254a0((int)this,0);}
  } ob;
  short damage,n,cost,id;
  int flag;
  signed char a;
  damage=0;
  a=f_042750(I(p1,0x12));
  flag=0;
  if(a==99) damage=1;
  if(!f_042750(I(p1,0x12)) && !f_042400(I(p1,0x12)) && !f_0425a0(I(p1,0x12))) {
    S(ob.p14,2)=(short)f_0428d0(I(p1,0x12))+1;
    n=f_0bf7b0(M64,2,0x1700006b,0,(int)(short)((short)f_0428d0(I(p1,0x12))+1),1);
    d_1c21b4[0]=0;
    if(n<=0) {  S(p1,0)=-4; return; }
  } else n=(short)f_0428d0(I(p1,0x12))+1;
  if(f_03d3d0(I(p1,0x12),0x35,C(p1,4))>0) {
    if(damage) damage=n+20;
    else {
      damage=f_145850(n,6,0);
      if(damage>f_0429a0(I(p1,0x12))) damage=f_0429a0(I(p1,0x12));
    }
    if(C(p1,5)==1 && f_0d0460(I(p1,0x1a))) { damage*=2; flag=1; }
    if(C(p1,5)==2 && f_043270(I(p1,0x16))) damage/=2;
    damage=f_10ccf0(p1,damage);
    cost=damage/10;
    if(C(p1,5)==2) {
      id=f_042a60(I(p1,0x16),10);
      if(id && cost) {
        int off=id*4;
        if(f_042b50(I(p1,0x16),10)+cost > d_1a47ac[(int)((signed char)(((RivaItemDefinition*)(I(d_1c2c40+off,0)))->f_0a78a0()))*2]) {
          cost=d_1a47ac[(int)((signed char)(((RivaItemDefinition*)(I(d_1c2c40+off,0)))->f_0a78a0()))*2];
          cost-=f_042b50(I(p1,0x16),10);
        }
        f_0348d0(I(p1,0x16),10,(signed char)cost);
      }
      short result=f_0d4c80(I(p1,0x16));
      int half=(signed char)(-(int)n/2);
      f_0d5040(I(p1,0x16),result,0x1518,f_043120(I(p1,0x16)),half,2);
      result=f_0d4c80(I(p1,0x16));
      f_0d5040(I(p1,0x16),result,0x1518,f_043120(I(p1,0x16)),half,3);
      d_1c21b4[0]=0;
    } else {
      f_0cf970(I(p1,0x1a),(signed char)-(signed char)cost);
      int half=(signed char)(-(int)n/2);
      f_0cfae0(I(p1,0x1a),half);
      f_0cfb10(I(p1,0x1a),half);
      d_1c21b4[0]=0;
    }
    if((short)flag) damage/=2;
    int attr=d_1c042a;
    S(p1,0)=damage;
    p1 = (p1 & 0) ? 0 : p1; // haelt ersten Schreibzugriff auf S(p1,0) und Registerfolge wie im Original
    if(attr!=-1) { damage+=(short)d_1c042a; S(p1,0)=damage; }
  } else {
    S(p1,0)=-2;
    S(p1,2)=n/2;
  }
}

//@ f_1117c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Senkt den Angriffswert des Ziels (C(p1, 5) == 2: Held I(p1, 0x16) über f_0d5040 für 0x2d Ticks; sonst
 *   Gegner I(p1, 0x1a) über f_0cfae0) um 3 Punkte und gibt die passende Kampfmeldung (0x1700006c/0x170000ce bzw.
 *   0x1700006d/0x170000cf) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (Timer-Slot des Zielhelden).
 === Ende Beschreibung === */
void f_1117c0(int p1)
{
    struct Ob ob;
    signed char c;
    short s;
    CTOR;
    if (C(p1,5) == 2) {
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, 0x2d, f_043120(I(p1,0x16)), -3, 2);
        I(ob.p4,4) = I(p1,0x16);
        f_0e93f0(M38, M21, f_0773b0(d_1c0004) ? 0x170000ce : 0x1700006c);
    } else {
        f_0cfae0(I(p1,0x1a), -3);
        I(ob.p8,4) = I(p1,0x1a);
        S(ob.p1c,2) = 1;
        f_0e93f0(M38, M21, f_0773b0(d_1c0004) ? 0x170000cf : 0x1700006d);
    }
    DTOR;
}

//@ f_1118a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft vor Ausführung eines Zaubers, ob der Zaubernde I(p1, 0x12) den benötigten Gegenstand 0x8c im
 *   Inventar besitzt (f_0d4aa0), führt bei Erfolg die Zauberroutine f_10f250(p1) aus und gibt 0x170000c0 (bzw.
 *   bei fehlendem Gegenstand 0x170000c1 und Status -2) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (Inventarslot des Gegenstands 0x8c).
 === Ende Beschreibung === */
void f_1118a0(int p1)
{
    struct Ob ob;
    short s;
    CTOR;
    s = f_0d4aa0(I(p1,0x12), 0x8c);
    if (s != -1) {
        f_10f250(p1);
        if (S(p1,0) != -4) {
            I(ob.p4,4) = I(p1,0x12);
            f_0e93f0(M38, M21, 0x170000c0);
        }
    } else {
        f_0e93f0(M38, M21, 0x170000c1);
        S(p1,0) = -2;
    }
    DTOR;
}

//@ f_111930
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Kampfrausch-/Verwandlungszauber *Karnifilo Raserei* (f_043ce0-Prüfung), der für n =
 *   1W20 + 2 (f_1457e0(20) + 2) mal 9 Zeiteinheiten über vier f_0d5040-Timer den Angriffswert um +5 erhöht, die
 *   Parade um -5 senkt, den Schadensbonus um +5 steigert und das Statusflag 0x0e setzt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: n (Wirkungsdauer-Basis und Astralkosten 1W20 + 2), s (Timer-Slots).
 === Ende Beschreibung === */
void f_111930(int p1)
{
    struct Ob ob;
    short n;
    short s;
    int *qd = &d_1c0004; // haelt lokale Temp-Nummerierung fuer Registerwahl wie im Original (Argon 852)
    CTOR;
    I(ob.p4,4) = I(p1,0x16);
    if (f_043ce0(I(p1,0x16)) != 0) {
        f_0e93f0(M38, M21, 0x170000c2);
        S(p1,0) = -4;
    } else {
#if FIX_R041   /* R041: Karnifilo prueft vor Wirkung, ob die ausgewuerfelten AE-Kosten vorhanden sind */
        n = f_1457e0(0x14) + 2;
        S(p1,0) = n + d_1c042a;
        if (d_1c042a != -1 && f_0429a0(I(p1,0x12)) < S(p1,0)) {
            S(p1,2) = S(p1,0) / 2;
            S(p1,0) = -2;
        } else {
            s = f_0d4c80(I(p1,0x16));
            f_0d5040(I(p1,0x16), (int)s, n * 9, f_043120(I(p1,0x16)), 5, 2);
            s = f_0d4c80(I(p1,0x16));
            f_0d5040(I(p1,0x16), (int)s, n * 9, f_043120(I(p1,0x16)), -5, 3);
            s = f_0d4c80(I(p1,0x16));
            f_0d5040(I(p1,0x16), (int)s, n * 9, 0, 5, 8);
            s = f_0d4c80(I(p1,0x16));
            f_0d5040(I(p1,0x16), (int)s, n * 9, 0, 1, 0xe);
            S(ob.p14,2) = n;
            f_0e93f0(M38, M21, (f_0773b0(*qd) != 0) ? 0x170000e9 : 0x1700006e);
        }
#else
        n = f_1457e0(0x14) + 2;
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, n * 9, f_043120(I(p1,0x16)), 5, 2);
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, n * 9, f_043120(I(p1,0x16)), -5, 3);
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, n * 9, 0, 5, 8);
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, n * 9, 0, 1, 0xe);
        S(p1,0) = n;
        S(p1,0) += d_1c042a;
        S(ob.p14,2) = n;
        f_0e93f0(M38, M21, (f_0773b0(*qd) != 0) ? 0x170000e9 : 0x1700006e);
#endif
    }
    DTOR;
}
//@ f_111a80
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Geschwindigkeitszauber *Axxeleratus Blitzgeschwind* (f_043cf0-Prüfung), der für
 *   0x2d Zeiteinheiten über drei f_0d5040-Timer zwei Kampfwert-Attribute (7 und 8) des Zielhelden I(p1, 0x16) um
 *   jeweils +5 erhöht und das Axxeleratus-Flag (0x0f) aktiviert.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: u (Zielheld I(p1, 0x16)), s (Timer-Slots).
 === Ende Beschreibung === */
void f_111a80(int p1)
{
    struct Ob ob;
    short s;
    int u;
    CTOR;
    u = I(p1,0x16);
    I(ob.p4,4) = u;
    if (f_043cf0(u) != 0) {
        f_0e93f0(M38, M21, 0x170000c3);
#if FIX_R044   /* R044: Bereits aktiver Axxeleratus bricht wie andere Statuszauber mit -4 statt 0 ab */
        S(p1,0) = -4;
#else
        S(p1,0) = 0;
#endif
    } else {
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, 0x2d, 8, 5, 1);
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, 0x2d, 7, 5, 1);
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, 0x2d, 0, 1, 0xf);
        f_0e93f0(M38, M21, 0x1700006f);
    }
    DTOR;
}

//@ f_111b60
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt für einen im aktuellen Kontext nicht anwendbaren Zauber die Ablehnungsmeldung 0x170000ac über
 *   f_0e93f0 aus und setzt den Statuscode S(p1, 0) auf -4 (0xfffc).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_111b60(int p1)
{
    f_0e93f0(M38, M21, 0x170000ac);
    S(p1,0) = (short)0xfffc;
}

//@ f_111b90
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Verständigungs-/Gedankenzauber *Respondami* / *Blick in die Gedanken* (0x3b), der
 *   im Dialogkontext (d_1c0428 == 4) direkt die Zauberprobe f_03d3d0(..., 0x3b, ...) würfelt und außerhalb davon
 *   ein Gesprächsziel über f_039070(d_1c0004) ermittelt sowie bei gelungener Probe eine zufällige Antwort
 *   (0x17000036 + 1W10) ausgibt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: iv (Gesprächsziel), s (Probenergebnis), n (Zufallsindex 0..9).
 === Ende Beschreibung === */
void f_111b90(int p1)
{
    struct Ob ob;
    short s;
    short n;
    int iv;
    CTOR;
    switch (d_1c0428) {
    case 4:
    s = f_03d3d0(I(p1,0x12), 0x3b, (int)C(p1,4));
    if (s > 0) goto L_end;
L_fail:
    *(short *)(p1+2) = 5;
    *(short *)p1 = (short)0xfffe;
    goto L_end;
    default:
    iv = f_039070(d_1c0004);
    I(p1,0x16) = iv;
    if (iv) goto L_continue;
    f_0e93f0(M38, M21, 0x17000034);
    *(short *)p1 = (short)0xfffc;
    goto L_end;
L_continue:
    s = f_03d3d0(I(p1,0x12), 0x3b, (int)C(p1,4));
    if (s <= 0) goto L_fail;
    I(ob.p4,4) = I(p1,0x12);
    I(ob.p4,8) = I(p1,0x16);
    n = f_1457e0(10);
    I(ob.p10,4) = n + 0x17000036;
    f_0e93f0(M38, M21, 0x17000035);
    goto L_end;
    }
L_end:
    DTOR;
    return;
}

//@ f_111ca0
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Ekliptifactus* / *Dunkelheit* (0x49), der im Kampf die Sichtweite aller
 *   Beteiligten drastisch senkt oder außerhalb des Kampfes magische Lichtquellen der Gruppe auslöscht.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_111ca0(int p1)
{
    struct Ob ob;
    signed char c;
    short s;
    int u;
    CTOR;
    u = I(p1,0x12);
    I(ob.p4,4) = u;
    if (f_043ca0(u) != 0) {
        f_0e93f0(M38, M21, 0x170000f1);
        S(p1,0) = (short)0xfffc;
    } else {
        s = f_0d4c80(I(p1,0x12));
        f_0d5290(I(p1,0x12), 0xd);
        f_0d5040(I(p1,0x12), (int)s, f_0428d0(I(p1,0x12)) * 0x1c2, 0, 1, 0x11);
        c = f_0428d0(I(p1,0x12));
        S(ob.p14,2) = c * 5;
        f_0e93f0(M38, M21, 0x170000ad);
    }
    DTOR;
}

//@ f_111d70
/* === Beschreibung (Katalog) ===
 * - Zweck: Erhöht einen Rüstungs- oder Schutzwert (Typ 5, Bonus +2) des Zielhelden I(p1, 0x16) für 0x1518 Ticks
 *   (1 Stunde) über f_0d5040 und kopiert den erzeugten Statustext aus d_1c0834 nach d_1c21b4.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: c (gesicherter Zustand aus f_043e30), s (Timer-Slot).
 === Ende Beschreibung === */
void f_111d70(int p1)
{
    signed char c;
    short s;
    c = f_043e30(I(p1,0x16));
    f_043e20(I(p1,0x16), 5);
    d_1c0834[0] = 0;
    s = f_0d4c80(I(p1,0x16));
    f_0d5040(I(p1,0x16), (int)s, 0x1518, 0, 2, 5);
    f_043e20(I(p1,0x16), (int)c);
    strcpy(d_1c21b4, d_1c0834);
}

//@ f_111e00
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Rüstungszauber *Armatrutz* (0x3e), der anhand der verfügbaren Astralenergie des
 *   Zaubernden (iv * iv < AE, maximal 9) im Zahlendialog 0x17000071 den gewünschten Rüstungsschutz-Bonus n
 *   abfragt, nach gelungener Probe (f_03d3d0 mit 0x3e) n * n Astralpunkte berechnet und den RS-Bonus n für 0x1c2
 *   Ticks über f_0d5040 (Typ 9) einträgt.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (maximal wählbarer RS-Bonus), n / iv (gewählter RS-Bonus), S(p1, 0) (Astralkosten n *
 *   n).
 === Ende Beschreibung === */
void f_111e00(int p1)
{
    struct Ob ob;
    signed char c;
    short s, n;
    short iv;
    int bval;
    CTOR;
    c = f_042750(I(p1,0x12));
    if (c == 'c') {
        n = 5;
    } else {
        s = 0;
        while (1) {
#if FIX_R043   /* R043: Armatrutz begrenzt waehlbaren RS-Bonus auf (s+1)*(s+1) <= vorhandene AE */
            iv = s + 1;
            if (iv * iv > f_0429a0(I(p1,0x12))) break;
#else
            iv = s;
            if (iv * iv >= f_0429a0(I(p1,0x12))) break;
#endif
            s = s + 1;
        }
        if (9 < s) s = 9;
        if (s) {
            S(ob.p14,2) = s;
            n = f_0bf7b0(M64, 1, 0x17000071, 0, (short)s, 0);
        } else {
            n = 0;
        }
    }
    iv = n;
    if (iv > 0) {
        if (f_03d3d0(I(p1,0x12), 0x3e, (int)C(p1,4)) > 0) {
            S(p1,0) = n * n;
            if (d_1c042a != -1) {
                S(p1,0) += (short)d_1c042a;
            }
            bval = (signed char)n;
            s = f_0d4c80(I(p1,0x16));
            f_0d5040(I(p1,0x16), (short)s, 0x1c2, 0, bval, 9);
            I(ob.p4,4) = I(p1,0x16);
            S(ob.p14,2) = n;
            f_0e93f0(M38, M21, 0x17000072);
        } else {
            S(p1,0) = -2;
            S(p1,2) = (short)((iv * iv) / 2);
            d_1c21b4[0] = 0;
        }
    } else {
        S(p1,0) = -4;
        d_1c21b4[0] = 0;
    }
    DTOR;
}

//@ f_111f80
/* === Beschreibung (Katalog) ===
 * - Zweck: Gemeinsame Hilfsfunktion der *Attributo*-Zauber: Sie prüft über f_0429c0(I(p1, 0x16), p2), ob die
 *   positive Eigenschaft p2 des Zielhelden bereits über ihrem Normalwert liegt (dann Ablehnung 0x1700007d), und
 *   erhöht sie andernfalls über f_0d5040 für 0x2a30 Ticks (2 Stunden) um +2 Punkte.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt), p2 (Index der zu steigernden Grundeigenschaft 0..6).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cs (gesicherter Anzeigemodus aus f_043e30), s (Timer-Slot).
 === Ende Beschreibung === */
void f_111f80(int p1, short p2)
{
    struct Ob ob;
    signed char cs;
    short s;
    CTOR;
    if (*(signed char *)(f_0429c0(I(p1,0x16), p2) + 1) >
        *(signed char *)f_0429c0(I(p1,0x16), p2)) {
        I(ob.p4,4) = I(p1,0x16);
        I(ob.p10,4) = (unsigned int)p2 + 0x20000143;
        f_0e93f0(M38, M21, 0x1700007d);
    } else {
        cs = f_043e30(I(p1,0x16));
        f_043e20(I(p1,0x16), 5);
        d_1c0834[0] = 0;
        s = f_0d4c80(I(p1,0x16));
        f_0d5040(I(p1,0x16), (int)s, 0x2a30, (signed char)p2, 2, 0);
        f_043e20(I(p1,0x16), (int)cs);
        strcpy(d_1c21b4, d_1c0834);
    }
    DTOR;
}

//@ f_112080
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 2 (Charisma / Fingerfertigkeit)
 *   über f_111f80(p1, 2) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112080(int p1)
{
    f_111f80(p1, 2);
}

//@ f_112090
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert für den Zaubernden I(p1, 0x12) einen stufenabhängigen Schutz- oder Tarneffekt (Dauer Stufe
 *   * 0x1c2, Typ 10 über f_0d5040, Meldung 0x17000074), sofern dieser noch nicht aktiv ist (!f_043270(u), sonst
 *   Abbruch mit 0x170000c4).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: u (Zaubernder I(p1, 0x12)), s (Timer-Slot).
 === Ende Beschreibung === */
void f_112090(int p1)
{
    struct Ob ob;
    signed char c;
    short s;
    int u;
    CTOR;
    u = I(p1,0x12);
    I(ob.p4,4) = u;
    if (!f_043270(u)) {
        s = f_0d4c80(I(p1,0x12));
        f_0d5040(I(p1,0x12), (int)s, f_0428d0(I(p1,0x12)) * 0x1c2, 0, 1, 10);
        f_0e93f0(M38, M21, 0x17000074);
    } else {
        f_0e93f0(M38, M21, 0x170000c4);
        S(p1,0) = (short)0xfffc;
    }
    DTOR;
}

//@ f_112140
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 3 über f_111f80(p1, 3) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112140(int p1)
{
    f_111f80(p1, 3);
}

//@ f_112150
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 4 über f_111f80(p1, 4) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112150(int p1)
{
    f_111f80(p1, 4);
}

//@ f_112160
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 5 über f_111f80(p1, 5) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112160(int p1)
{
    f_111f80(p1, 5);
}

//@ f_112170
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 6 (Körperkraft) über f_111f80(p1,
 *   6) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112170(int p1)
{
    f_111f80(p1, 6);
}

//@ f_112180
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 1 (Klugheit) über f_111f80(p1, 1)
 *   aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112180(int p1)
{
    f_111f80(p1, 1);
}

//@ f_112190
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt den eigenschaftssteigernden Zauber für die Grundeigenschaft 0 (Mut) über f_111f80(p1, 0) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112190(int p1)
{
    f_111f80(p1, 0);
}

//@ f_1121a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt für einen nicht direkt anwendbaren Zauber die Meldung 0x170000ae über f_0e93f0 aus und setzt den
 *   Statuscode S(p1, 0) auf -4 (0xfffc).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_1121a0(int p1)
{
    f_0e93f0(M38, M21, 0x170000ae);
    S(p1,0) = (short)0xfffc;
}

//@ f_1121d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Versetzt je nach Zielart C(p1, 5) entweder ein gegnerisches Kampfwesen (C(p1, 5) == 1 oder 4,
 *   f_0cfe40(I(p1, 0x1a), 1), Meldung 0x17000075) oder ein Gruppenmitglied (f_0424f0(I(p1, 0x16), 1), Meldung
 *   0x17000109) in einen Versteinerungs- oder Lähmungszustand (*Paralü Paralein*).
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: C(p1, 5) (Zielart).
 === Ende Beschreibung === */
void f_1121d0(int p1)
{
    struct Ob ob;
    CTOR;
    if (C(p1,5) == 1 || C(p1,5) == 4) {
        f_0cfe40(I(p1,0x1a), 1);
        I(ob.p8,4) = I(p1,0x1a);
        S(ob.p1c,2) = 1;
        f_0e93f0(M38, M21, 0x17000075);
    } else {
        f_0424f0(I(p1,0x16), 1);
        I(ob.p4,4) = I(p1,0x16);
        f_0e93f0(M38, M21, 0x17000109);
    }
    DTOR;
}

//@ f_112270
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert einen kostenvariablen Kampfzauber gegen das Gegnerziel I(p1, 0x1a): Die Astralkosten
 *   betragen das Dreifache eines Zielkennwerts (f_0cfa70 * 3, mindestens 25 AE); reicht die Astralenergie des
 *   Zaubernden (f_0429a0) aus, wird der Effekt über f_0cff00(I(p1, 0x1a), 1) ausgelöst (0x17000076), andernfalls
 *   mit 0x17000083 und -4 abgebrochen.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s3 (berechnete Mindest-Astralkosten >= 25).
 === Ende Beschreibung === */
void f_112270(int p1)
{
    struct Ob ob;
    short s3;

    CTOR;

    s3 = (short)(f_0cfa70(I(p1, 0x1a)) * 3);
    if (s3 < 0x19) {
        s3 = (short)0x19;
    }
    if (s3 <= f_0429a0(I(p1, 0x12))) {
        f_0cff00(I(p1, 0x1a), 1);
        S(p1, 0) = s3;
        S(p1, 0) += d_1c042a;

        I(ob.p8, 4) = I(p1, 0x1a);
        S(ob.p1c, 2) = 1;
        f_0e93f0(M38, M21, 0x17000076);
    } else {
        int obj = I(p1, 0x12);
        I(ob.p4, 4) = obj;
        f_0e93f0(M38, M21, 0x17000083);
        S(p1, 0) = (short)-4;
    }

    DTOR;
}
