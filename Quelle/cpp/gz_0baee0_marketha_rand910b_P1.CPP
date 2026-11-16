/* === Beschreibung (Katalog) ===
 * Einheit gz_0baee0_marketha_rand910b (Adresse 0x0baee0 - 0x0bb900)
 *
 * Diese Einheit bildet die zweite Rand-Aufteilung an der Modulgrenze zur Markthalle von Riva (marketha). Während
 * die drei LXT-Hilfsfunktionen (f_0baee0, f_0baf60, f_0baf80) hier als Vorwärtsdeklarationen stehen, enthält
 * diese Einheit die vollständige Implementierung der Markthalle von Riva (f_0bafb0 bis f_0bb640), einschließlich
 * des Besuchs der vier Händlerstände, der NPC-Begegnungen in der Halle, des Taschendiebstahls im Marktgetümmel
 * und des Kraftwettkampfs am Stand des Schaustellers.
 *
 *
 * Vorwärtsdeklarationen (Implementierung in gz_0baee0_marketha_rand910a)
 *
 * Die Funktionen f_0baee0, f_0baf60 und f_0baf80 sind in dieser Teileinheit nur als Prototypen deklariert und in
 * gz_0baee0_marketha_rand910a beschrieben.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 2/5 gleich (suche.py 25.10.2026, Basis gz_0baee0_P1.CPP)
// gz_0baee0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0BAEE0-0x0BB080
#include <string.h>
int f_15eaf3(unsigned n);
int f_05ff60(int p1, int p2);
signed char f_126450(int p1);
extern char d_1bf228;
extern int d_1bf229;
extern int d_1bf22c;
extern int d_1bf22d;
extern int d_1c212a;
extern int *d_1c212c;
extern int d_1bb290;
extern int d_1c2c44;
struct LX { int hdr; int tab; int vt; };
#define SLOT(i) (*(int *)((int)d_1c212c + (i) * 4))
//@ f_0baee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsmethode des LXT-Textlesers reserviert anhand der im Dateikopf (hdr + 8) vermerkten
 *   Zeilenanzahl das Zeiger-Array tab und trägt dort der Reihe nach die Startadressen aller nullterminierten
 *   Textzeilen ab hdr + 0x1a ein.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LX-Textleserobjekt mit bereits geladenem Dateikopf hdr
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt stets 1 zurück.
 === Ende Beschreibung === */
int f_0baee0(LX *p)
;
//@ f_0baf60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liefert einen 0-basiert indizierten Textzeiger aus einer geladenen
 *   LXT-Textdatei, sofern der Index idx kleiner als die Zeilenanzahl bei hdr + 8 ist.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LX-Textleserobjekt sowie den 0-basierten Zeilenindex idx
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf die angeforderte Zeichenkette oder 0 bei einem ungültigen
 *   Index zurück.
 === Ende Beschreibung === */
int f_0baf60(LX *p, unsigned idx)
;
//@ f_0baf80
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liefert einen 1-basiert indizierten Textzeiger (idx - 1) aus einer geladenen
 *   LXT-Textdatei, sofern der um 1 verminderte Index innerhalb der Zeilenanzahl bei hdr + 8 liegt.
 * - Eingaben: Die Funktion nimmt den Zeiger p auf das LX-Textleserobjekt sowie den 1-basierten Zeilenindex idx
 *   entgegen.
 * - Rückgabewert: Die Funktion gibt die Adresse der angeforderten Zeichenkette oder 0 bei einem Bereichsüberlauf
 *   zurück.
 === Ende Beschreibung === */
unsigned short f_0baf80(LX *p, unsigned short idx)
;
struct ObjAF { signed char a; short b; };
struct RegAF { short count; ObjAF **list; };
extern ObjAF af228, af22c; extern RegAF afreg;
#pragma aux af228 "d_1bf228"
#pragma aux af22c "d_1bf22c"
#pragma aux afreg "d_1c212a"
inline signed char afzero() { signed char c=0; return c; }
inline void afadd(ObjAF &o,RegAF &r,short id) { o.a=afzero();o.b=id;r.list[r.count]=&o;r.count++; }
//@ f_0bafb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese statische Initialisierungsfunktion (__STI) registriert beim Programmstart die beiden
 *   Spielstand-Variablen der Markthalle (d_1bf228 mit Kennung 0x1e für den gewonnenen Kraftwettkampf und
 *   d_1bf22c mit Kennung 0x1f für die einmalige Begegnung in der Halle) in der globalen Persistenzliste
 *   d_1c212a.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bafb0(void)
{
    afadd(af228,afreg,0x1e);
    afadd(af22c,afreg,0x1f);
}
//@ f_0bb020
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert das Gebäudeobjekt für die Markthalle von Riva (Ortskennung 0x1a =
 *   26), setzt die virtuelle Methodentabelle d_1bb290 und prüft über den Spielzeit-Manager (f_126450), ob an
 *   diesem Wochentag (Tag 8) besonderer Markttag herrscht.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das zu initialisierende Markthallen-Objekt entgegen.
 * - Rückgabewert: Die Funktion gibt den initialisierten Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_0bb020(int p1)
{
    int *q;
    signed char c;
    int riva_05ff60(int, int);
    #pragma aux riva_05ff60 "f_05ff60" parm [eax] [edx] value [eax] modify exact [eax edx]
    signed char riva_126450(int, int);
    #pragma aux riva_126450 "f_126450" parm [eax] [ebx] value [al] modify exact [eax]
    q = (int *)riva_05ff60(p1, 0x1a);
    q[2] = (int)&d_1bb290;
    c = riva_126450((int)&d_1c2c44, p1);
    q[3] = (c == 8);
    return (int)q;
}

// ===== marketha (gleiches Originalmodul: Tabelle von f_0bb080 bei 0BB058 direkt hinter f_0bb020, nop-Ausrichtung ohne Linker-Nullen)
// marketha-Teil: eigene Typsicht fuer gemeinsam genutzte Daten (Fixups maskiert)
#define d_1bf228 d_1bf228mh
#define d_1bf22c d_1bf22cmh




int f_038d70(int p1, int p2);
int f_039320(int p1, int p2);
int f_040780(int p1, int p2);



int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
int f_044890(int p1, int p2);
int f_044c90(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);
int f_0bb5b0(int p1);
int f_0bf730(int p1, int p2);
int f_0db820(int p1, int p2);
int f_0db8b0(int p1, int p2);
int f_0dd7f0(int p1, int p2, int p3);
int f_0de7e0(int p1);
int f_0de810(int p1, int p2);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int p2);
int f_125ed0(int p1, int p2);
int f_145760(int p1, int p2);
unsigned short f_1457e0(int p1);
struct S5 { short v[5]; };
struct I5 { int v[5]; };
typedef RivaTextContextData OB;
extern S5 d_1a5360;
extern I5 d_1a536c;
extern volatile signed char d_1bf228;
extern signed char d_1bf22c;
extern int d_1c0004;
extern int d_1c2c44;
extern int d_1c2c64;
extern int d_1c349c;
extern int d_1c3498;
extern int d_1c3870;
#define P(k) f_0bf730((int)&d_1c2c64, k)
#define EQI(x,v) (((x)==(v))?1:0)
#define BODY2 { int n, m; short s; P(0x2300001d); P(0x2300001e); P(0x2300001f); P(0x23000020); n = f_0de7e0(d_1c0004); if (0 < n) { s = (short)f_1457e0(0x32); m = (int)s; if (s > n) m = n; f_0db8b0(d_1c0004, m); P(0x23000021); } }
#define C5(P1) switch ((unsigned short)f_1457e0(3)) { case 1: f_0bb640(P1); break; case 2: BODY2 break; case 3: f_0bb460(); break; }
void f_0bb280(void);
void f_0bb2a0(void);
void f_0bb2c0(void);
void f_0bb2e0(int p1, unsigned short idx);
void f_0bb310(int p1);
void f_0bb460(void);
void f_0bb640(int p1);
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0bb080
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Haupt-Dispatch-Funktion verarbeitet die Auswahl eines Hotspots p2 innerhalb der Markthalle: Die
 *   Optionen 1 bis 4 öffnen einen der vier Krämer- und Marktstände (d_1a5360), Option 5 löst ein zufälliges
 *   Marktereignis aus (Kraftprobe am Schaustellerstand f_0bb640, Taschendiebstahl im Gedränge oder Begegnung
 *   f_0bb460), und die Optionen 6 bis 8 starten die Händler-/NPC-Interaktionen 0x73, 0x74 bzw. 0x72.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Markthallen-Objekt sowie den gewählten Hotspot-Index p2
 *   (1 bis 8) entgegen.
 * - Rückgabewert: Die Funktion gibt 1 bei einem gültigen Hotspot-Index (1-8) oder 0 im Standardfall zurück.
 === Ende Beschreibung === */
void f_0bb460(int p1);
int f_0bb080(int p1, unsigned short p2)
{
    int r = 1;
    S5 s4, s1, s3, s2;
    switch (p2) {
    case 1: { int h = d_1c0004; s1 = d_1a5360; f_0dd7f0(h, 0, (int)s1.v[1]); break; }
    case 2: { int h = d_1c0004; s2 = d_1a5360; f_0dd7f0(h, 0, (int)s2.v[2]); break; }
    case 3: { int h = d_1c0004; s3 = d_1a5360; f_0dd7f0(h, 0, (int)s3.v[3]); break; }
    case 4: { int h = d_1c0004; s4 = d_1a5360; f_0dd7f0(h, 0, (int)s4.v[4]); break; }
    case 5:
        switch ((unsigned short)f_1457e0(3)) {
        case 1: f_0bb640(p1); break;
        case 2:
            {
                int n, m;
                P(0x2300001d); P(0x2300001e); P(0x2300001f); P(0x23000020);
                n = f_0de7e0(d_1c0004);
                if (0 < n) {
                    m = (short)f_1457e0(0x32);
                    if (m > n) m = n;
                    f_0db8b0(d_1c0004, m);
                    P(0x23000021);
                }
            }
            break;
        case 3: f_0bb460(p1); break;
        }
        break;
    case 6: f_0de810(d_1c0004, 0x73); break;
    case 7: f_0de810(d_1c0004, 0x74); break;
    case 8: f_0de810(d_1c0004, 0x72); break;
    default: r = 0; break;
    }
    return r;
}
//@ f_0bb280
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion startet in der Markthalle die Interaktion bzw. den Händlerdialog mit der Kennung
 *   0x73 (115).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb280(void)
{
    f_0de810(d_1c0004, 0x73);
}
//@ f_0bb2a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion startet in der Markthalle die Interaktion bzw. den Händlerdialog mit der Kennung
 *   0x72 (114).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb2a0(void)
{
    f_0de810(d_1c0004, 0x72);
}
//@ f_0bb2c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion startet in der Markthalle die Interaktion bzw. den Händlerdialog mit der Kennung
 *   0x74 (116).
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb2c0(void)
{
    f_0de810(d_1c0004, 0x74);
}
//@ f_0bb2e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet den durch den Index idx (1 bis 4) bestimmten Marktstand aus der Krämertabelle
 *   d_1a5360 über f_0dd7f0.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Markthallen-Objekt sowie den Stand-Index idx entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb2e0(int p1, unsigned short idx)
{
    S5 t = d_1a5360;
    f_0dd7f0(d_1c0004, 0, t.v[idx]);
}
//@ f_0bb310
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion würfelt beim Schlendern durch die Markthalle mit f_1457e0(3) eines von drei zufälligen
 *   Ereignissen aus: Entweder stößt die Gruppe auf den Kraftmenschen/Schausteller (f_0bb640), wird im Gedränge
 *   Opfer eines Taschendiebs (Verlust von bis zu 50 Hellern aus der Gruppenkasse f_0db8b0), oder erlebt die
 *   einmalige Begegnung f_0bb460.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Markthallen-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb310(int p1)
{
    void f_0bb460(int p1);
    int n, m;
    switch ((unsigned short)f_1457e0(3)) {
    case 1: f_0bb640(p1); break;
    case 2: {
        P(0x2300001d); P(0x2300001e); P(0x2300001f); P(0x23000020);
        n = f_0de7e0(d_1c0004);
        if (0 < n) {
            m = (short)f_1457e0(0x32);
            if (m > n) m = n;
            f_0db8b0(d_1c0004, m);
            P(0x23000021);
        }
        break;
    }
    case 3: f_0bb460(p1); break;
    }
}
//@ f_0bb3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt das Taschendiebstahl-Ereignis in der Markthalle aus: Sie zeigt die Textsequenz
 *   0x2300001d bis 0x23000020 an und zieht der Gruppe, sofern sie Geld besitzt (f_0de7e0 > 0), einen zufälligen
 *   Betrag von 1 bis 50 Hellern (f_1457e0(0x32)) ab.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb3e0(void)
{
    BODY2
}
//@ f_0bb460
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt eine einmalige Begegnung in der Markthalle ab (d_1bf22c == 0), bei der ein
 *   Held mit hohem Talentwert 0x27 (f_039320) ausgewählt wird, eine längere Dialogsequenz (0x23000022 bis
 *   0x2300002e) abläuft und die Gruppe 2 Dukaten (200 Heller, f_0db820) erhält; bei späteren Auslösungen
 *   erscheint nur noch der Kurztext 0x2300002f.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb460(void)
{
    OB ob;
    if (EQI(d_1bf22c, 0)) {
        f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
        *(int *)(ob.addresses.objects + 4) = f_039320(d_1c0004, 0x27);
        P(0x23000022); P(0x23000023); P(0x23000024); P(0x23000025); P(0x23000026);
        P(0x23000027); P(0x23000028); P(0x23000029); P(0x2300002a); P(0x2300002b);
        P(0x2300002c); P(0x2300002d); P(0x2300002e);
        f_0db820(d_1c0004, 200);
        d_1bf22c = 1;
        f_1254a0((int)&ob, 0);
        return;
    }
    P(0x2300002f);
}
//@ f_0bb5b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Auswahlfunktion lässt den Spieler einen Helden für die Kraftprobe in der Markthalle bestimmen
 *   (0x2300000b) und prüft, ob dessen Körperkraft (f_042a40, Attribut 6) mindestens 16 beträgt. Ist der gewählte
 *   Held zu schwach (< 16), wird er mit dem Hinweis 0x2300000c abgelehnt und die Auswahl wiederholt, bis ein
 *   starker Held gewählt oder abgebrochen wird.
 * - Eingaben: Die Funktion erhält keine Parameter (void).
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den ausgewählten Helden mit Körperkraft >= 16 oder 0 bei
 *   Abbruch zurück.
 === Ende Beschreibung === */
int f_0bb5b0(void)
{
    int ok, p;
    signed char c;
    OB ob;
    do {
        p = f_038d70(d_1c0004, 0x2300000b);
        if (p != 0) {
            c = f_042a40((struct hero *)(p), 6);
            if (c < 16) {
                f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(ob.addresses.objects + 4) = p;
                p = 0;
                P(0x2300000c);
                ok = 0;
                f_1254a0((int)&ob, 0);
            } else {
                ok = 1;
            }
        } else {
            ok = 1;
            p = 0;
        }
    } while (!ok);
    return p;
}
//@ f_0bb640
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert den Wettkampf am Stand des Kraftmenschen in der Markthalle: Gegen einen
 *   Einsatz von 1 Dukaten (100 Hellern) tritt ein Held mit mindestens 16 Körperkraft (f_0bb5b0) zu einer Serie
 *   von Talent- und Attributsproben (Selbstbeherrschung 0x32, Gewandtheit 4 und erschwerte Körperkraftprobe 6)
 *   an. Bei einem Sieg gewinnt die Gruppe 10 Dukaten (1000 Heller), der Held erhält 5 Abenteuerpunkte und das
 *   Flag d_1bf228 = 1 beendet künftige Wettkämpfe; bei einer Niederlage erleidet der Held schweren
 *   Lebenspunkteschaden (LE - 4) sowie Wundfieber/Ausdauerverlust.
 * - Eingaben: Die Funktion nimmt den Zeiger p1 auf das Markthallen-Objekt entgegen.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0bb640(int p1)
{
    struct Context : OB {
        Context() { f_125400((int)this,(int)&d_1c349c,(int)&d_1c3870,(int)&d_1c3498); }
        ~Context() { f_1254a0((int)this,0); }
    } ob;
    int n;
    short stat, loss;
    short bonus;
    if (EQ(d_1bf228,0)) {
        P(0x23000008);
        P(0x23000009);
        if (f_0de7e0(d_1c0004)>=100 && f_0bf6f0((int)&d_1c2c64,0x2300000a)==1) {
            n=f_0bb5b0(p1);
            if (n) {
                *(int *)(ob.addresses.objects+4)=n;
                if (f_042380((struct hero *)(n))==1) P(0x2300000d);
                else P(0x2300000e);
                f_0db8b0(d_1c0004,100);
                P(0x2300000f);
                if ((short)f_044c90(n,0x32,0)<=0) {
                    P(0x23000010);
                    short damage=((int)(f_042960((struct hero *)(n))))-4;
                    if (damage>0) f_044300(n,damage);
                    P(0x23000011);
                    f_044890(n,3);
                    goto done;
                }
                {
                    stat=f_042a40((struct hero *)(n),6);
                    if ((short)f_044c90(n,4,0)<=0) {
                        P(0x23000012);
                        f_044850(n,4,5);
                        bonus=0;
                    } else {
                        P(0x23000013);
                        bonus=1;
                    }
                    short mod=(20-stat)*2-bonus*5;
                    if ((short)f_044c90(n,6,(signed char)mod)>0) {
                        P(0x23000014);
                        f_0db820(d_1c0004,1000);
                        f_040780(n,5);
                        P(0x23000015);
                        d_1bf228=1;
                    return;
                    }
                    P(0x23000016);
                    loss=((int)(f_042960((struct hero *)(n))))-4;
                    if (loss>0) f_044300(n,loss);
                    P(0x23000011);
                    f_044890(n,3);
                    return;
                }
            }
        }
    } else {
        I5 a=d_1a536c;
        short pick=f_145760(0,4);
        *(int *)(ob.addresses.numbers+4)=a.v[pick];
        P(0x2300001b);
        P(0x2300001c);
        f_125ed0((int)&d_1c2c44,0x14);
    }
done:;
}
#undef d_1bf228
#undef d_1bf22c
