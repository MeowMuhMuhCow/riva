/* === Beschreibung (Katalog) ===
 * Einheit environ1 (0x063550 - 0x0640f0)
 *
 * Überblick
 * Die Einheit environ1 bildet den ersten Teil der Umgebungs- und Dungeon-Ereignissteuerung (vermutlich
 * Orts-/Raum-Interaktionen in einem Gewölbe oder Tempel/Kanalisation mit Textarchiv 0x360000xx). Sie behandelt
 * Truhen-/Objektuntersuchungen, Krankheits-/Vergiftungsproben, Kraftakte der Gruppe (gemeinsames
 * Aufstemmen/Heben mit Erschöpfungsschaden) sowie mehrstufige Fallen- und Gefahrensituationen mit Ausdauer- und
 * Lebenspunktverlusten.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 11/14 gleich (suche.py 26.10.2026, Basis environ1_P1.CPP)
#define EQI(x,v) (((x)==(v))?1:0)
#define EQI0(x) (((x)==0)?1:0)
// P1 4/14 gleich
// environ1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x063550-0x0640F0
#include <string.h>
#define YES(x) ((x)!=0)
typedef RivaTextContextData Fr;
int f_0104b0(void *p1, int p2, int p3, int p4);
void *f_010590(void *p1, int p2);
int f_038c40(int p1);
int f_038d70(int p1, int p2);
int f_039320(int p1, int p2);
int f_039a80(int p1, int p2);
int f_039b70(int p1, int p2, int p3);
int f_0407e0(int p1, int p2);
int f_0428c0(int p1);
short f_042960(int p1);
int f_043170(int p1);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_0bbf00(int *p1);
int f_0bf680(int *p1);
int f_0bf6c0(int *p1, int p2);
int f_0bf6f0(int *p1, int p2);
int f_0bf730(int *p1, int p2);
short f_0bf820(int *p1, ...);
int f_0bf980(int *p1, ...);
int f_0d4a60(int p1);
short f_0db9a0(int p1);
int f_0dd7f0(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
int f_125400(void *p1, int *p2, int *p3, int *p4);
int f_1254a0(void *p1, int p2);
short f_1457e0(int p1);
int f_145850(int p1, int p2, int p3);
int f_147323(int *p1, int p2, int p3, int p4, int p5, int p6, int p7);
extern signed char d_1a9820;
extern signed char d_1bd6e0;
extern signed char d_1bd6e8;
extern int d_1bf230;
extern int d_1c0004;
extern signed char d_1c0c9c;
extern signed char d_1c0ca4;
extern signed char d_1c0cd4;
extern int d_1c2c64;
extern int d_1c2edc;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern const char d_1a19e4[];
//@ f_063550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt ein Umgebungsgeräusch (0x360009) ab und fragt den Spieler je nach den Statusflags
 *   d_1c0ca4 und d_1bd6e8 mit Text 0x3600002b oder 0x3600002c, ob eine Aktion ausgeführt werden soll. Bei
 *   Zustimmung (1) zeigt die Funktion die Grafik 0x2c0000 mit dem Beschreibungstext 0x3600002d im Dialogfenster
 *   an und löst anschließend die Orts-/Kartenaktion f_0dd7f0(d_1c0004, 5, 0x1533) aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globalen Bytes d_1c0ca4 und d_1bd6e8 wählen den Fragetext, d_1c2edc ist das
 *   Soundsystem, d_1c2c64 ist die Dialogsteuerung und d_1c0004 bezeichnet den globalen Gruppen-/Spielkontext.
 === Ende Beschreibung === */
void f_063550(void)
{
    int m;
    int snd;
    void *p;
    if (YES(d_1c0ca4 != 0) && EQI0(d_1bd6e8)) m = 0x3600002b; else m = 0x3600002c;
    snd = *(int *)&d_1a9820;
    f_147323(&d_1c2edc, 0x360009, 0x7fff, 0x8000, snd, 0, 1);
    if (f_0bf6f0(&d_1c2c64, m) == 1) {
        p = operator new(0x13e, mark(d_1a19e4, 0x1ef));
        p = p ? (void *)f_0104b0(p, 0x2c0000, 0, 0) : p;
        f_0bf6c0(&d_1c2c64, 6);
        f_0bf980(&d_1c2c64, p, 0, 0x3600002d, 0);
        f_0bf680(&d_1c2c64);
        if (p) operator delete(f_010590(p, 0));
        f_0dd7f0(d_1c0004, 5, 0x1533);
    }
}
//@ f_063650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler per Ja/Nein-Dialog (0x3600002e), lässt danach über f_038d70 (0x3600002f)
 *   einen Helden auswählen und legt für diesen eine Talentprobe auf Talent 0x0e (Schwimmen) ab, die um Traglast
 *   / 100 (f_043170(q) / 100) erschwert ist. Bei Misslingen gibt die Funktion die Meldung 0x36000030 aus und
 *   zieht 4 Lebenspunkte (f_044300(q, 4)) ab; bei Gelingen erscheint 0x36000031 und der Held verliert nur 2
 *   Lebenspunkte.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Die lokale Variable q hält den ausgewählten Heldenzeiger, l speichert den aus dem
 *   getragenen Gewicht berechneten Probenaufschlag und o ist der temporäre Textkontextrahmen
 *   (RivaTextContextData).
 === Ende Beschreibung === */
void f_063650(void)
{
    int q;
    Fr o; short l;
    if (f_0bf6f0(&d_1c2c64, 0x3600002e) == 1) {
        q = f_038d70(d_1c0004, 0x3600002f);
        if (q) {
            l = (short)f_043170(q) / 100;
            f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
            o.tables.p[1] = q;
            if (f_044c90(q, 0xe, (signed char)l) <= 0) {
                f_0bf730(&d_1c2c64, 0x36000030);
                f_044300(q, 4);
            } else {
                f_0bf730(&d_1c2c64, 0x36000031);
                f_044300(q, 2);
            }
            f_1254a0(&o, 0);
        }
    }
}
//@ f_063720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den einfachen Hinweis- oder Beschreibungstext 0x36000032 im Dialogfenster d_1c2c64 aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwendet ausschließlich die globale Dialogsteuerung d_1c2c64.
 === Ende Beschreibung === */
void f_063720(void)
{
    f_0bf730(&d_1c2c64, 0x36000032);
}
//@ f_063740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft beim Untersuchen eines Ortsfeldes das Einmal-Flag d_1c0c9c: Beim ersten Mal (d_1c0c9c ==
 *   0) meldet der Gruppenanführer den Fundtext 0x36000033, ruft die virtuelle Objektmethode an Offset +8 mit dem
 *   Code 0x96 auf und setzt d_1c0c9c = 1. Bei späteren Besuchen fragt die Funktion mit 0x36000034 nach und führt
 *   bei Bestätigung den Ortsübergang f_0dd7f0(d_1c0004, 0x12, 0x66) aus.
 * - Eingaben und Rückgabe: Als Parameter p1 (eax) wird der Zeiger auf das auslösende Umgebungs-/Ereignisobjekt
 *   übergeben; die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Das globale Flag d_1c0c9c speichert, ob die Stelle bereits entdeckt wurde, und o bindet
 *   den Anführer (f_038c40) in die Textausgabe ein.
 === Ende Beschreibung === */
void f_063740(int p1)
{
    Fr o;
    if (EQI0(d_1c0c9c)) {
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        o.tables.p[1] = f_038c40(d_1c0004);
        f_0bf730(&d_1c2c64, 0x36000033);
        (**(int (***)(int, int, int))(p1 + 8))(p1, 0x96, 0);
        d_1c0c9c = 1;
        f_1254a0(&o, 0);
    } else {
        if (f_0bf6f0(&d_1c2c64, 0x36000034) == 1)
            f_0dd7f0(d_1c0004, 0x12, 0x66);
    }
}
//@ f_0637f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Ereignisflag d_1c0cd4: Ist es noch 0, wird lediglich der Text 0x36000035 ausgegeben.
 *   Ist d_1c0cd4 gesetzt, fragt die Funktion mit 0x36000036 nach und löst bei Zustimmung den Ortswechsel
 *   f_0dd7f0(d_1c0004, 0x12, 0x14b4) aus.
 * - Eingaben und Rückgabe: Die Funktion besitzt keine Parameter und keinen Rückgabewert (void).
 * - Wichtige Variablen: Das globale Byte d_1c0cd4 steuert, ob der Durchgang oder die Interaktion bereits
 *   freigeschaltet ist.
 === Ende Beschreibung === */
void f_0637f0(void)
{
    if (EQI0(d_1c0cd4)) {
        f_0bf730(&d_1c2c64, 0x36000035);
        return;
    }
    if (f_0bf6f0(&d_1c2c64, 0x36000036) == 1)
        f_0dd7f0(d_1c0004, 0x12, 0x14b4);
}
//@ f_063850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt den Umgebungstext 0x36000037 über die Dialogsteuerung d_1c2c64 an.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt nichts zurück (void).
 * - Wichtige Variablen: Nutzt die globale Dialoginstanz d_1c2c64.
 === Ende Beschreibung === */
void f_063850(void)
{
    f_0bf730(&d_1c2c64, 0x36000037);
}
//@ f_063870
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet für einen Helden p1 die Summe aus den beiden Last-/Gewichtswerten f_0428c0(p1) und
 *   f_043170(p1) (vermutlich Körpergewicht plus getragene Ausrüstungslast).
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); zurückgegeben wird die ganzzahlige Summe (int
 *   in eax).
 * - Wichtige Variablen: Die lokalen Variablen a und b nehmen die beiden Teilgewichte des Helden auf.
 === Ende Beschreibung === */
int f_063870(int p1)
{
    int a = f_0428c0(p1);
    int b = f_043170(p1);
    return b + a;
}
//@ f_063890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle sieben Gruppenplätze (0..6) nach dem handlungsfähigen Helden (f_0d4a60) mit
 *   der höchsten Gesamtlast f_0428c0(p) + f_043170(p).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Zeiger auf den schwersten aktiven
 *   Helden (int in eax, oder 0 falls keiner gefunden wurde) zurück.
 * - Wichtige Variablen: Die lokale Variable best merkt sich den bisher schwersten Helden und mx (unsigned short)
 *   den zugehörigen Höchstwert.
 === Ende Beschreibung === */
int f_063890(void)
{
    int best = 0;
    unsigned short mx = 0;
    short i;
    int p;
    for (i = 0; i < 7; i++) {
        p = f_0de7d0(d_1c0004, i);
        if (p) {
            if (f_0d4a60(p)) {
                if ((unsigned short)(f_0428c0(p) + f_043170(p)) >= mx) {
                    best = p;
                    mx = f_0428c0(p) + f_043170(p);
                }
            }
        }
    }
    return best;
}
//@ f_063900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft eine Gewichts- oder Tragfähigkeitsfalle (z. B. morsche Brücke oder brüchiger Boden)
 *   gegen den schwersten handlungsfähigen Helden best der Gruppe. Gelingt diesem die Eigenschaftsprobe auf
 *   Gewandtheit (f_044900(best, 4, p2) > 0) oder liegt seine Gesamtlast unter dem Grenzwert 4500 - p2 * 100,
 *   erscheint nur die Warnmeldung 0x36000007; andernfalls bricht der Untergrund ein (unterschiedliche Texte
 *   0x36000008..0x3600000d für Einzelheld oder Gruppe) und der Held verliert je nach Schwere des Sturzes 1W6
 *   Ausdauer oder die Hälfte bzw. sämtliche Lebens-/Ausdauerpunkte (f_044850).
 * - Eingaben und Rückgabe: Übergeben werden das Ereignisobjekt p1 (eax, unbenutzt) und der
 *   Schwierigkeits-/Schwellenparameter p2 (edx); die Funktion gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable best (who) bezeichnet den schwersten Helden, lim die Tragfähigkeitsgrenze,
 *   count die Anzahl aktiver Gruppenmitglieder (f_0db9a0) und r das Ergebnis der Eigenschaftsprobe.
 === Ende Beschreibung === */
void f_063900(int p1, int p2)
{
    union Max { unsigned i; unsigned short s; };
    int lim;
    int best;
    int attr;
    int tmp;
    int msg;
    int who;
    Fr o;
    unsigned char b;
    short sv;
    short i;
    short r;
    short count;
    Max mx;
    short amount;
    f_125400(&o,&d_1c349c,&d_1c3870,&d_1c3498);
    // Berechnete Aliasnamen fuer die Stapelsortierung ohne Zusatzcode
    (void)((unsigned char *)&o)[0];
    (void)((unsigned char *)&o)[1];
    (void)((unsigned char *)&o)[2];
    (void)((unsigned char *)&o)[3];
    (void)((unsigned char *)&o)[4];
    (void)((unsigned char *)&o)[5];
    (void)((unsigned char *)&o)[6];
    (void)((unsigned char *)&o)[7];
    (void)((unsigned char *)&o)[8];
    (void)((unsigned char *)&o)[9];
    (void)((unsigned char *)&o)[10];
    (void)((unsigned char *)&o)[11];
    (void)((unsigned char *)&o)[12];
    (void)((unsigned char *)&o)[13];
    (void)((unsigned short *)&o)[0];
    (void)((unsigned short *)&o)[1];
    (void)((unsigned short *)&o)[2];
    (void)((unsigned short *)&o)[3];
    (void)((unsigned short *)&o)[4];
    (void)((unsigned short *)&o)[5];
    (void)((unsigned short *)&o)[6];
    (void)((unsigned short *)&o)[7];
    (void)((unsigned short *)&o)[8];
    (void)((double *)&o)[0];
    (void)((double *)&o)[1];
    (void)((double *)&o)[2];
    (void)((unsigned char *)&mx)[1];
    (void)((unsigned char *)&mx)[0];
    best = mx.i = 0;
    
    for(i=0;i<7;i++) {
        int p=f_0de7d0(d_1c0004,i);
        if(p && f_0d4a60(p)) {
            if((unsigned short)(f_0428c0(p)+f_043170(p)) >= mx.s) {
                tmp=f_0428c0(p);
                mx.i=f_043170(p)+tmp;
                best=p;
            }
        }
    }
    int pp=(short)p2;
    r=f_044900(best,4,pp);
    { int sw; *(short*)&sw=f_0db9a0(d_1c0004); count=(short)sw; b=(unsigned char)sw-1; (void)((unsigned char *)&sw)[3]; (void)((unsigned short *)&sw)[1]; (void)((unsigned char *)&sw)[1]; (void)((unsigned char *)&sw)[2]; /* Berechnete Aliasnamen fuer sw */ }
    who=best;
    o.tables.p[1]=best;
    d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // Haelt die Registerwahl fuer d_1c0004
    if(r>0) goto refuse;
    lim=0x1194-pp*100;
    if((unsigned short)(f_0428c0(best)+f_043170(best)) < lim) {
refuse:
        f_0bf730(&d_1c2c64,0x36000007);
        goto end;
    }
    if(count>1) {
        short score=(unsigned short)b+r;
        o.tables.p[2]=f_039b70(d_1c0004,best,6);
        if(score>-3) {
            f_0bf730(&d_1c2c64,0x36000008);
            f_044850(best,f_1457e0(6),5);
        } else if(score>-6 || f_1457e0(100)>(short)p2) {
            f_0bf730(&d_1c2c64,0x36000009);
            attr=(short)((f_1457e0((short)(p2*3))>=(short)p2)?5:4);
            amount=f_042960(who)/2;
            f_044850(who,amount,attr);
        } else {
            f_0bf730(&d_1c2c64,0x3600000a);
            f_044850(best,f_042960(best),4);
        }
    } else {
        if(r>-3) {
            f_0bf730(&d_1c2c64,0x3600000b);
            f_044850(best,f_1457e0(6),5);
        } else if(r>-6 || f_1457e0(100)>(short)p2) {
            f_0bf730(&d_1c2c64,0x3600000c);
            attr=(short)((f_1457e0((short)(p2*3))>=(short)p2)?5:4);
            amount=f_042960(who)/2;
            { int kk; f_044850(who,(kk=amount,kk=amount),attr); } // Haelt die Registerwahl beim Aufruf
        } else {
            f_0bf730(&d_1c2c64,0x3600000d);
            f_044850(best,f_042960(best),4);
        }
    }
end:
    f_1254a0(&o,0);
}
//@ f_063b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wendet auf den Helden p1 eine Erschöpfungs- und Krankheits-/Vergiftungsfolge an: Der
 *   Lebens-/Ausdauerabzug p2 wird so begrenzt, dass dem Helden mindestens 1 Punkt (f_042960(p1) - 1) verbleibt,
 *   danach wird die Meldung 0x36000026 mit den Zahlenwerten p2 und p3 ausgegeben, über f_0407e0(p1, p3) sowie
 *   f_044850(p1, p2, 1) der Schaden verbucht und die Statusanzeige (f_0bbf00) aktualisiert.
 * - Eingaben und Rückgabe: Eingaben sind der Heldenzeiger p1 (eax) sowie die beiden Abzugswerte p2 (edx, short)
 *   und p3 (ebx, short); es gibt keinen Rückgabewert (void).
 * - Wichtige Variablen: Der Textkontext o stellt den Helden in o.tables.p[1] und die beiden Abzugszahlen in
 *   o.tables.tail.short_numbers[1..2] für die Textformatierung bereit.
 === Ende Beschreibung === */
void f_063b90(int p1, short p2, short p3)
{
    Fr o;
    f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
    if (f_042960(p1) - p2 < 1)
        p2 = f_042960(p1) - 1;
    o.tables.p[1] = p1;
    o.tables.tail.short_numbers[1] = p2;
    o.tables.tail.short_numbers[2] = p3;
    f_0bf730(&d_1c2c64, 0x36000026);
    f_0407e0(p1, p3);
    f_044850(p1, p2, 1);
    f_0bbf00(&d_1bf230);
    f_1254a0(&o, 0);
}
//@ f_063c30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gruppen-Callback für das erstmalige Auslösen der Umgebungsgefahr aus f_063f40: Würfelt für
 *   einen handlungsfähigen Helden p1 die beiden Schadenswerte 1W4+3 (l18) und 1W6+4 (l1c) aus, begrenzt l18 auf
 *   maximal aktuelle LE - 1, zeigt die Schadensmeldung 0x36000026 an und zieht die Werte über f_0407e0 und
 *   f_044850(..., 1) ab.
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Die lokalen Variablen l18/l20 und l1c speichern die ausgewürfelten Lebens- und
 *   Ausdauerverluste des Helden.
 === Ende Beschreibung === */
void f_063c30(int p1)
{
    // Lokale short-Sicht mit vollem EAX-Rueckgaberegister; echte Clobber EAX/EBX/EDX.
    short dice902(int,int,int);
#pragma aux dice902 "f_145850" parm [eax] [edx] [ebx] value [eax] modify exact [eax ebx edx]
    Fr o;
    short l18, l1c, l20;
    int a;
    unsigned short sort902;
    if (f_0d4a60(p1)) {
        a = p1;
        l18 = dice902(1, 4, 3);
        unsigned char rt1,rt2,rt3; // Drei berechnete kleine Sortierknoten
        rt1=*(unsigned char*)&d_1c0c9c; *(unsigned char*)&d_1c0c9c=rt1;
        rt2=*(unsigned char*)&d_1c0ca4; *(unsigned char*)&d_1c0ca4=rt2;
        rt3=*(unsigned char*)&d_1c0cd4; *(unsigned char*)&d_1c0cd4=rt3;

        {
            short v2;
            v2 = f_145850(1, 6, 4);
            l20 = l18;
            l1c = v2;
        }
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        if (f_042960(p1) - (int)l18 < 1)
            l20 = f_042960(p1) - 1;
        o.tables.p[1] = a;
        o.tables.tail.short_numbers[1] = (short)l20;
        o.tables.tail.short_numbers[2] = (short)l1c;
        f_0bf730(&d_1c2c64, 0x36000026);
        f_0407e0(a, (short)l1c);
        f_044850(a, (short)l20, 1);
        f_0bbf00(&d_1bf230);
        f_1254a0(&o, 0);
    }
}
//@ f_063d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gruppen-Callback für die erste Entscheidungsoption in f_063f40: Würfelt für einen
 *   handlungsfähigen Helden p1 1W3 (l18) und 2W20+5 (v2) aus, reduziert v2 um die übrigbehaltenen Punkte einer
 *   Körperkraftprobe (f_044900(p1, 5, 0), mindestens 1 Punkt Rest) und wendet beide Abzüge mit Meldung
 *   0x36000026 über f_0407e0 und f_044850 an.
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); die Funktion gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Variable v3 enthält die Qualitätsstufe der Körperkraftprobe, die den Ausdauerverlust
 *   v2 (l1c) abmildert.
 === Ende Beschreibung === */
void f_063d20(int p1)
{
    Fr o;
    short l18, l1c, l20;
    int a;
    if (f_0d4a60(p1)) {
        l18 = f_145850(1, 3, 0);
        {
            short v2;
            short v3;
            v2 = f_145850(2, 0x14, 5);
            v3 = f_044900(p1, 5, 0);
            if (v3 >= (short)v2) v3 = v2 - 1;
            if (0 < v3) v2 -= v3;
            l1c = v2;
        }
        a = p1;
        l20 = l18;
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        if (f_042960(p1) - (short)l18 < 1)
            l20 = f_042960(p1) - 1;
        o.tables.p[1] = a;
        o.tables.tail.short_numbers[1] = (short)l20;
        o.tables.tail.short_numbers[2] = (short)l1c;
        f_0bf730(&d_1c2c64, 0x36000026);
        f_0407e0(a, (short)l1c);
        f_044850(a, (short)l20, 1);
        f_0bbf00(&d_1bf230);
        f_1254a0(&o, 0);
    }
}
//@ f_063e30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gruppen-Callback für die zweite Entscheidungsoption in f_063f40: Würfelt für einen
 *   handlungsfähigen Helden p1 einen höheren Lebenspunktschaden von 1W20+5 (l18) und einen geringeren
 *   Ausdauerverlust von 1W10 (v2, gemindert um eine Körperkraftprobe f_044900(p1, 5, 0)) aus und zieht beide
 *   Werte mit Meldung 0x36000026 ab.
 * - Eingaben und Rückgabe: Eingabe ist der Heldenzeiger p1 (eax); die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Wie in f_063d20 speichern l20 den auf LE - 1 gekappten Lebenspunktabzug und l1c den
 *   reduzierten Ausdauerabzug.
 === Ende Beschreibung === */
void f_063e30(int p1)
{
    Fr o;
    short l18, l1c, l20;
    int a;
    if (f_0d4a60(p1)) {
        l18 = f_145850(1, 0x14, 5);
        {
            short v2;
            short v3;
            v2 = f_145850(1, 10, 0);
            v3 = f_044900(p1, 5, 0);
            if (v3 >= (short)v2) v3 = v2 - 1;
            if (0 < v3) v2 -= v3;
            l1c = v2;
        }
        a = p1;
        l20 = l18;
        f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
        if (f_042960(p1) - (short)l18 < 1)
            l20 = f_042960(p1) - 1;
        o.tables.p[1] = a;
        o.tables.tail.short_numbers[1] = (short)l20;
        o.tables.tail.short_numbers[2] = (short)l1c;
        f_0bf730(&d_1c2c64, 0x36000026);
        f_0407e0(a, (short)l1c);
        f_044850(a, (short)l20, 1);
        f_0bbf00(&d_1bf230);
        f_1254a0(&o, 0);
    }
}
//no pragma
//@ f_063f40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst mit Wahrscheinlichkeit p2 Prozent (oder garantiert beim allerersten Mal, wenn d_1bd6e0 ==
 *   0) eine Umgebungsgefahr mit Soundeffekt 0x360008 aus. Beim ersten Auftreten setzt die Funktion d_1bd6e0 = 1,
 *   zeigt das Ereignisbild 0x2c0001 mit den Texten 0x36000023..0x36000025 an und wendet f_063c30 auf alle
 *   Gruppenmitglieder an; bei späteren Auslösungen lässt sie den Spieler per Auswahlmenü (0x36000027) zwischen
 *   den beiden Verhaltensweisen f_063d20 und f_063e30 wählen.
 * - Eingaben und Rückgabe: Eingaben sind der Ereigniszeiger p1 (eax, unbenutzt) und die Prozentchance p2 (edx,
 *   short); die Funktion gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Flag d_1bd6e0 merkt sich, ob die Gruppe dieses Ereignis bereits einmal
 *   erlebt hat.
 === Ende Beschreibung === */
void f_063f40(int p1, short p2)
{
    short aux_0bf820(int *p1, ...);
#pragma aux aux_0bf820 "f_0bf820" parm caller [] value [eax] modify exact [eax esp];
    short v = p2;
    int snd, q;
    if (f_1457e0(0x64) <= v || EQI(d_1bd6e0, 0))
    {
        snd = *(int *)&d_1a9820;
        f_147323(&d_1c2edc, 0x360008, 0x7fff, 0x8000, snd, 0, 1);
        if (EQI(d_1bd6e0, 0))
        {
            Fr o;
            f_125400(&o, &d_1c349c, &d_1c3870, &d_1c3498);
            d_1bd6e0 = 1;
            {
                int h = f_039320(d_1c0004, 0x1e);
                o.tables.p[1] = h;
            }
            {
                int t = (int)operator new(0x13e, mark(d_1a19e4, 0x524));
                if (t)
                    q = f_0104b0((void *)t, 0x2c0001, 0, 0);
                else
                    q = t;
            }
            f_0bf6c0(&d_1c2c64, 6);
            f_0bf980(&d_1c2c64, q, 0, 0x36000023, 0);
            f_0bf680(&d_1c2c64);
            if (q)
                operator delete(f_010590((void *)q, 0));
            f_0bf730(&d_1c2c64, 0x36000024);
            f_0bf730(&d_1c2c64, 0x36000025);
            f_039a80(d_1c0004, (int)f_063c30);
            f_1254a0(&o, 0);
        }
        else
        {
            switch (aux_0bf820(&d_1c2c64, 0x36000027, 2, 0x36000028, 0x36000029))
            {
            case 1:
                f_039a80(d_1c0004, (int)f_063d20);
                break;
            case 2:
            case -1:
                f_039a80(d_1c0004, (int)f_063e30);
                break;
            }
        }
    }
}
