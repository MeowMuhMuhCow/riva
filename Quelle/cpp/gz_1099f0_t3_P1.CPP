/* === Beschreibung (Katalog) ===
 * Einheit gz_1099f0_t3 (10a250 - 10aad0)
 *
 * Überblick
 *
 * Die Einheit gz_1099f0_t3 bildet den dritten Teil des Handels- und Ladenmoduls gz_1099f0. Sie enthält die
 * Zugriffsmethoden auf Waren- und Preisstrukturen sowie die Benutzeroberflächen-Callbacks zum Blättern,
 * Auswählen und Zeichnen der Warenzeilen im Kauf-/Verkaufsfenster (f_10a250 bis f_10aa60).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// OPT -4r -oneatx -zp1 -s
// P3 26/36 gleich (suche.py 26.10.2026, Basis gz_1099f0_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 12 gleich (vorher 12), Rest 622 (vorher 626)
// gz_1099f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1099F0-0x10AAD0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01c840(int p1);                                   // reg eax stapel 0
void f_01f350(int p1, short p2);
int f_02de80(int p1, int p2);                           // reg edx stapel 0
int f_02de90(int p1, int p2);                           // reg eax edx stapel 0
int f_038ba0(int p1);                                   // reg eax stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_038e10(int p1, int p2);                           // reg eax edx stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_03aa20(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_03c860(int p1);                                   // reg eax stapel 0
int f_040cb0(int p1, short p2, int p3, short p4, short p5);
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bd350(int p1, int p2, int p3);
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ecx stapel 8
short f_0bf820(int, ...);
short f_0dbfe0(int p1);
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d5040(int, int, int, int, int, int);                       // nicht in clobber.tsv
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db970(int p1);                                   // reg eax stapel 0
int f_0dcf00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de5a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de5d0(int p1, int p2);                           // reg eax edx stapel 0
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_1094e0(int p1);                                   // reg eax stapel 0
int f_10ad70(int p1, int p2);                           // reg eax edx stapel 0
int f_11e760(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_11e8f0();                                         // reg - stapel 0
int f_11e900();                                         // reg - stapel 0
int f_11e910(int p1, int p2, int p3, int p4);           // reg - stapel 0
int __stdcall f_11e960(int p1);                         // reg - stapel 4 R59 __stdcall?
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
int f_126410(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_149d20();                                         // reg - stapel 0
int f_14a1d0(int p1, int p2, int p3, int p4, int p5, int p6);// reg - stapel 8
int f_14b3d0(int p1, int p2, int p3, int p4, int p5);   // reg - stapel 4
int f_14bb40(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg - stapel 12
#include <bios.h>
extern int d_1bb87c[];
extern int d_1bb890[];
extern int d_1c2c64, d_1c2c44, d_1c27a8, d_1c21b4, d_1bf230;
extern int d_1c0004;
extern short d_1bc760;
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c3498[];
extern signed char d_1c03ac, d_1c03b0;
extern signed char d_1c03b4;
extern short d_1c03b8;
extern volatile short d_1c219a; // verhindert Register-Caching der Timer-Flagge in den Warteschleifen
extern volatile short d_1c2198; // verhindert Wegoptimierung des Schreibzugriffs in f_10a6d0
extern int d_1c21b0;
extern const char d_1a0710[];
extern const char d_1b8354[];

signed char f_126420(int p1);
signed char f_1265a0(int p1);

int __stdcall f_11e730(int p1);
int __stdcall f_14bb10(int p1);
int f_14d040(const char *fmt, ...);
int f_14d0e4(const char *fmt, ...);
int f_145234(int p1, int p2);
int f_145254();
int f_03aa20(int p1, int p2, int p3, int);
int f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_1094e0();
int f_10ad70(int p1, int p2);
int f_14b3d0(int p1);
int f_14b3d0_stack(int p1);
#pragma aux f_14b3d0_stack "f_14b3d0" parm [] modify [eax ebx ecx edx];
int f_14a1d0_call(int p1, int p2);
#pragma aux f_14a1d0_call "f_14a1d0" parm [] modify [eax ebx ecx edx];
int f_11e910_all8(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
#pragma aux f_11e910_all8 "f_11e910" parm caller [] modify [eax ebx ecx edx];
unsigned char __stdcall f_11e760(short p1, short p2);
void f_10a170(int p1);
#define OBJ RivaTextContext o(d_1c349c, d_1c3870, d_1c3498)
#define C64 ((int)&d_1c2c64)
#define C44 ((int)&d_1c2c44)
#define POLL key = 0; rd = 0; if (d_1c219a != 0) { f_0bbf00((int)&d_1bf230); rd = _bios_keybrd(1); } if (rd) key = _bios_keybrd(0);
#define KEYCOND (f_0d3780() != 0 || f_0d37b0() != 0 || key == 0x11b || key == 0x3920 || key == 0x4900 || key == 0x5100)

static inline int EQBF(const signed char &x,int v){return x==v;}
static inline int EQN(int a, int b) { return a == b; }
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_02dee0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktionen gehören zu den vorangehenden Teileinheiten gz_1099f0_t1 und gz_1099f0_t2 und sind
 *   dort dokumentiert.
 * - Eingaben: Siehe gz_1099f0_t1.md und gz_1099f0_t2.md.
 * - Rückgabewert: Siehe gz_1099f0_t1.md und gz_1099f0_t2.md.
 === Ende Beschreibung === */
void f_02dee0(short *p1)
;
//@ f_1099f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_1099f0_t1)
 *   richtet das Gebäude- bzw. Handelsfenster-Subsystem ein.
 * - Eingaben: Die Funktion nimmt in der Vorwärtsdeklaration keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Siehe gz_1099f0_t1.md.
 === Ende Beschreibung === */
void f_1099f0(void)
;
//@ f_109a50
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Destruktor gibt die vom Handelsfenster angelegten Warenlisten, Icons und Textpuffer wieder
 *   frei.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 (sowie optionale Destruktor-Flags p2).
 * - Rückgabewert: Die Funktion gibt den Objektzeiger p1 zurück.
 === Ende Beschreibung === */
int f_109a50(int p1)
;
//@ f_109b20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode stellt das Warensortiment des Händlers für die Anzeige zusammen und filtert Gegenstände
 *   nach Verfügbarkeit und Ladentyp.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verfügbaren Waren zurück.
 === Ende Beschreibung === */
void f_109b20(int p1)
;
//@ f_109ba0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode sammelt alle verkäuflichen Gegenstände aus den Inventaren der Heldengruppe für den
 *   Verkaufsmodus des Ladens.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verkäuflichen Gegenstände zurück.
 === Ende Beschreibung === */
void f_109ba0(int p1)
;
//@ f_109c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode steuert die Hauptinteraktion im Handelsfenster: Sie verarbeitet die Auswahl und
 *   Stückzahl der Waren, berechnet die Gesamtsumme in Dukaten, Silbertalern, Hellern und Kreuzern und ruft bei
 *   Abschluss die Feilschen-Probe (f_109f30) sowie die Waren- und Geldübergabe auf.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Abschlussstatus des Handels zurück.
 === Ende Beschreibung === */
int f_109c20(int p1)
;

//@ f_109f30
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt beim Kaufen oder Verkaufen die Feilschen-Talentprobe des ausgewählten Helden
 *   gegen den Aufschlag bzw. Rabatt des Händlers durch, prüft die Geduld des Händlers und passt den Endpreis um
 *   den ausgehandelten Prozentsatz an.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1 sowie den gewünschten Rabattprozentsatz p2.
 * - Rückgabewert: Die Funktion gibt das Ergebnis der Preisverhandlung zurück (Erfolg, Ablehnung oder Rauswurf
 *   aus dem Laden).
 === Ende Beschreibung === */
void f_109f30(int p1)
;
//@ f_10a170
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode überträgt nach einem erfolgreichen Einkauf die ausgewählten Waren in die Inventare der
 *   Helden und zieht den Kaufpreis vom Gruppengold ab.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion gibt den Status der Transaktion zurück.
 === Ende Beschreibung === */
void f_10a170(int p1)
;
//@ f_10a200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode entfernt nach einem erfolgreichen Verkauf die verkauften Gegenstände aus dem
 *   Heldeninventar und schreibt den Erlös dem Gruppengold gut.
 * - Eingaben: Die Funktion erhält den this-Zeiger p1.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_10a200(int p1, short *p2, short *p3)
;
//@ f_10a240
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode (in dieser Teileinheit vorwärtsdeklariert, Definition in gz_1099f0_t2) liest
 *   das 16-Bit-Statuswort bei Offset +0x0e des Handels-/Gebäudeobjekts aus.
 * - Eingaben: Die Funktion erhält den Objektzeiger (in der Vorwärtsdeklaration void).
 * - Rückgabewert: Die Funktion gibt den 16-Bit-Statuswert zurück (int).
 * - Wichtige Variablen: Siehe gz_1099f0_t2.md.
 === Ende Beschreibung === */
int f_10a240(void)
;
//@ f_10a250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sechs kurzen Zugriffsmethoden lesen und ändern Statusfelder, Zeiger und Zähler innerhalb des
 *   Handelsfenster- und Wareneintrags-Objekts.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1 (sowie bei Setter-Methoden den neuen Wert p2).
 * - Rückgabewert: Die Getter geben das jeweilige Strukturfeld zurück; die Setter haben keinen Rückgabewert
 *   (void).
 === Ende Beschreibung === */
int f_10a250(void)
{
    return 0;
}
//@ f_10a260
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser Konstruktor initialisiert ein Laden- oder Stadtgebäudeobjekt über den Basiskonstruktor
 *   f_02de80 und setzt dessen virtuelle Methodentabelle bei Offset +0x58 auf d_1bb890.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Gebäudekennung p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: r (initialisierter Objektzeiger), d_1bb890 (Vtable bei Offset +0x58).
 === Ende Beschreibung === */
void f_10a260(int p1, int p2)
{
    int r;
    r = f_02de80(p1, (short)p2);
    *(int *)(r + 0x58) = (int)d_1bb890;
}
//@ f_10a270
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser virtuelle Destruktor baut ein Gebäudeobjekt der Klasse d_1bb890 (d_1bb87c) über f_02de90 ab
 *   und gibt bei gesetztem Bit p2 & 2 den Objektspeicher frei.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2.
 * - Rückgabewert: Die Funktion gibt den Objektzeiger r zurück (int).
 * - Wichtige Variablen: r (Rückgabe von f_02de90), d_1bb890, d_1bb87c.
 === Ende Beschreibung === */
int f_10a270(int p1, unsigned p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bb87c);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0x58) = (int)d_1bb890;
    r = f_02de90(p1, 1);
    if (p2 & 2) delete (char *)r;
    return r;
}
//@ f_10a2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese leere Funktion dient als Platzhaltermethode ohne eigene Wirkung.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_10a2b0(void)
{
}
//@ f_10a2c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Dieser kurze Wrapper leitet den übergebenen Zeiger p1 direkt an die Hilfsfunktion f_02dee0 weiter.
 * - Eingaben: Die Funktion erhält den Zeiger p1 (int).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Delegiert direkt an f_02dee0(p1).
 === Ende Beschreibung === */
void f_02dee0(int);
void f_10a2c0(int p1) { f_02dee0(p1); }
//@ f_10a2d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese kurze virtuelle Statusmethode gibt konstant 1 zurück.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt stets 1 zurück (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_10a2d0(void)
{
    return 1;
}
//@ f_10a2e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese fünf Methoden zeichnen die einzelnen Warenzeilen (Gegenstands-Icon, Name, Einzelpreis und
 *   ausgewählte Stückzahl), aktualisieren die Summenanzeige im Handelsfenster und verarbeiten Mausklicks zum
 *   Erhöhen oder Verringern der Stückzahl.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1 sowie Zeilen- oder Ereignisparameter (p2, p3).
 * - Rückgabewert: Die Funktionen geben den Status der UI-Aktion zurück bzw. enden ohne Rückgabewert (void).
 === Ende Beschreibung === */
short f_10a2e0(int p1, int p2, int p3, int p4, int p5)
{
    short cnt, i, v, key, rd;
    int done;
    short sp5;
    v = ((short)p3 > 99) ? 3 : (((short)p3 > 9) ? 2 : 1);
    cnt = (short)f_0bf7b0(C64, (short)v, 0x220101b7, (short)p2, (short)p3, (short)p3);
    i = cnt;
    if (cnt > 0) {
        int fl = p4;
        sp5 = p5;
        i = 0;
        if (cnt > 0) {
            short n = cnt;
            done = 0;
            d_1c21b0 = 1;
            if (p4 == 1) f_0de5a0(d_1c0004, (signed char)sp5);
            f_149d20();
            while (i < n && !done) {
                i = (i & 0) ? (short)0 : i; // haelt die Registerzuteilung (ebx/edi/esi/ebp/ecx) in der Warteschleife wie im Original
                done = (done & 0) ? 0 : done; // haelt die Registerzuteilung (ebx/edi/esi/ebp/ecx) in der Warteschleife wie im Original
                f_01c840(*(int *)&d_1bc760);
                i++;
                f_125f70(C44, 1);
                key = 0;
                if (d_1c219a) f_0bbf00((int)&d_1bf230);
                rd = _bios_keybrd(1);
                if (rd) key = _bios_keybrd(0);
                if (KEYCOND) {
                    if (f_0bf6f0(C64, 0x220101b8) == 1) done = 1;
                }
            }
            if (fl == 1) f_0de5d0(d_1c0004, (signed char)sp5);
            d_1c21b0 = 0;
        }
    }
    return i;
}
//@ f_10a450
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion rechnet eine Zeitspanne p2 aus Spielzeit-Ticks in volle Stunden (0x1518 Ticks je
 *   Stunde) um und spult die Spieluhr stundenweise (f_125f70) mit Animationsaktualisierung (f_01c840) und
 *   optionaler Unterbrechung (0x220101b8) vor.
 * - Eingaben: Die Funktion erhält den Objektzeiger p1, die Tick-Anzahl p2, das Gruppenstatus-Flag p3 sowie den
 *   Statuswert p4.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verstrichenen Stunden zurück (short).
 * - Wichtige Variablen: cnt / lim (berechnete Stundenzahl), i (abgelaufene Stunden), done (Abbruchflag),
 *   d_1c21b0 (Wartemodus-Flag).
 === Ende Beschreibung === */
short f_10a450(int p1, unsigned p2, int p3, short p4)
{
    int m;
    short cnt = 0;
    unsigned short c;
    short i;
    int done;
    short key, rd;
    while (p2 > 0) {
        unsigned t;
        cnt++;
        if (p2 > 0x1518) t = 0x1518; else t = p2;
        p2 -= t;
    }
    m = p3;
    c = p4;
    i = 0;
    if (cnt > 0) {
        short lim = cnt;
        done = 0;
        d_1c21b0 = 1;
        if (m == 1) f_0de5a0(d_1c0004, (signed char)c);
        f_149d20();
        while (i < lim && !done) {
            f_01c840(*(int *)&d_1bc760);
            i++;
            f_125f70(C44, 1);
            key = 0;
            if (d_1c219a) f_0bbf00((int)&d_1bf230);
            rd = _bios_keybrd(1);
            if (rd) key = _bios_keybrd(0);
            if (KEYCOND) {
                if (f_0bf6f0(C64, 0x220101b8) == 1) done = 1;
            }
        }
        if (m == 1) f_0de5d0(d_1c0004, (signed char)c);
        done = 0;
        d_1c21b0 = done;
    }
    return i;
}
//@ f_10a5a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt die Spielzeit um p2 Tage und p3 Stunden (p2 * 24 + p3 Stunden) voranschreiten,
 *   aktualisiert in jeder Stunde die Raum-Animation (f_01c840) und erlaubt dem Spieler das vorzeitige Abbrechen
 *   über die Rückfrage 0x220101b8.
 * - Eingaben: Die Funktion erhält einen ungenutzten Parameter p1, die Tagesanzahl p2, die Stundenanzahl p3, das
 *   Status-Flag p4 sowie den Statuswert p5.
 * - Rückgabewert: Die Funktion gibt die Anzahl der abgelaufenen Stunden zurück (int).
 * - Wichtige Variablen: r (Stundenzähler), p3 (Gesamtstunden p3 + p2 * 24), done (Abbruchflag).
 === Ende Beschreibung === */
int f_10a5a0(short p1, short p2, short p3, int p4, int p5)
{
    int r, done;
    short key, rd;
    r = 0;
    if (0 < p2 || 0 < p3) {
        p3 += p2 * 0x18;
        done = 0;
        d_1c21b0 = 1;
        if (p4 == 1) f_0de5a0(d_1c0004, (int)(signed char)p5);
        f_149d20();
        while ((short)r < p3 && !done) {
            f_01c840(*(int *)&d_1bc760);
            r += 1;
            f_125f70(C44, 1);
            key = 0;
            if (d_1c219a) f_0bbf00((int)&d_1bf230);
            rd = _bios_keybrd(1);
            if (rd) key = _bios_keybrd(0);
            if (KEYCOND) {
                if (f_0bf6f0(C64, 0x220101b8) == 1) done = 1;
            }
        }
        if (p4 == 1) f_0de5d0(d_1c0004, (int)(signed char)p5);
        d_1c21b0 = 0;
    }
    return r;
}
//@ f_10a6d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion lässt den Spieler einen Helden auswählen (0x200001be), prüft über f_042520, ob dieser
 *   verfügbar ist (sonst Meldung 0x200001c0), führt für ihn die Aktion f_03c860 aus und addiert bei Erfolg 30
 *   Minuten Spielzeit (f_125ed0(C44, 0x1e)).
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: p (ausgewählter Held), s (Ergebnis von f_03c860), d_1c2198 (Statusflag).
 === Ende Beschreibung === */
void f_10a6d0(void)
{
    int p;
    char c;
    short s;
    p = f_038e10(d_1c0004, 0x200001be);
    if (p != 0) {
        c = ((char)(f_042520((struct hero *)(p))));
        if (c) {
            f_0bf730(C64, 0x200001c0);
            return;
        }
        s = f_03c860(p);
        if (0 < s) {
            d_1c2198 = 0;
            f_125ed0(C44, 0x1e);
        }
    }
}
//@ f_10a730
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion prüft während einer Warteschleife auf Tastatur- oder Mausklicks und fragt den
 *   Spieler über das Dialogfenster 0x220101b8, ob das Warten abgebrochen werden soll.
 * - Eingaben: Die Funktion nimmt keine Parameter entgegen (void).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Spieler den Abbruch bestätigt, sonst 0.
 * - Wichtige Variablen: key (Tastencode aus _bios_keybrd), r (Abbruchstatus).
 === Ende Beschreibung === */
int f_10a730(void)
{
    short key;
    int r;
    key = 0;
    r = 0;
    if (d_1c219a) f_0bbf00((int)&d_1bf230);
    if (_bios_keybrd(1)) key = _bios_keybrd(0);
    if (KEYCOND && f_0bf6f0(C64, 0x220101b8) == 1) r = 1;
    return r;
}
//@ f_10a7d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese sechzehn Hilfs- und Callback-Methoden verwalten das Scrollen der Warenliste, das Umschalten des
 *   aktiven Helden beim Einkauf, die Prüfung der Traglast und Inventarplätze sowie den Abbau der UI-Hilfsobjekte
 *   des Handelsfensters.
 * - Eingaben: Jede Funktion erhält den this-Zeiger p1 (sowie optionale Index- oder Destruktor-Parameter p2).
 * - Rückgabewert: Die Funktionen geben den jeweiligen Feldwert, Objektzeiger oder Statuscode zurück.
 === Ende Beschreibung === */
void f_10a7d0(int p1)
{
    if (*(int *)(p1 + 0x10) != 0) {
        f_14d0e4(d_1b8354, (int)*(short *)(p1 + 0x16));
    }
}
//@ f_10a7f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion öffnet eine Smacker-Videodatei über f_14bb40, speichert das Handle in *p1 und trägt
 *   Breite (+4), Höhe (+8) sowie Frame-Anzahl (+0xc) in die Ausgabeparameter *p3, *p4 und *p5 ein.
 * - Eingaben: Die Funktion erhält den Objekt-/Handle-Zeiger p1, die Dateikennung p2 sowie die Ausgabezeiger p3,
 *   p4 und p5.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: r / *p1 (Smacker-Handle).
 === Ende Beschreibung === */
void f_10a7f0(int *p1, int p2, short *p3, short *p4, short *p5)
{
    int r;
    r = f_14bb40((int)p1, p2, (int)p3, (int)p4, 0, 0, p2);
    *p1 = r;
    *p3 = *(short *)(r + 4);
    *p4 = *(short *)(*p1 + 8);
    *p5 = *(short *)(*p1 + 0xc);
}
//@ f_10a830
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsfunktion liest aus dem Smacker-Handle *p1 die Videobreite (+4), die Videohöhe (+8) und
 *   die Gesamtframezahl (+0xc) in die Zeiger p2, p3 und p4 aus.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die drei 16-Bit-Ausgabezeiger p2, p3 und p4.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *p1 (Smacker-Handle).
 === Ende Beschreibung === */
void f_10a830(int *p1, short *p2, short *p3, short *p4)
{
    *p2 = *(short *)(*p1 + 4);
    *p3 = *(short *)(*p1 + 8);
    *p4 = *(short *)(*p1 + 0xc);
}
//@ f_10a850
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion initialisiert bei noch nicht aktivierter Videoausgabe (*(int *)(p1 + 0xc) == 0) das
 *   Anzeigesystem über f_11e730(1) und setzt den Frame-Index (+0x16) sowie das Aktiv-Flag (+0xc) auf 1.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(int *)(p1 + 0xc) (Aktiv-Flag), *(short *)(p1 + 0x16) (Frame-Index).
 === Ende Beschreibung === */
int f_11e730x(int);
#pragma aux f_11e730x "f_11e730" parm [] modify [eax ebx ecx edx];
void f_10a850(int p1)
{
    if (*(int *)(p1 + 0xc) == 0) {
        f_11e730x(1);
        *(short *)(p1 + 0x16) = 1;
        *(int *)(p1 + 0xc) = 1;
    }
}
//@ f_10a880
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion stellt wie f_10a850 die Initialisierung des Video-Subsystems (f_11e730(1)) sicher und
 *   richtet anschließend über f_11e960(p1 + 0x26) den Anzeigekontext ein.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: p1 + 0x26 (Anzeigekontext im Player-Objekt).
 === Ende Beschreibung === */
void f_10a880(int p1)
{
    if (*(int *)(p1 + 0xc) == 0) {
        f_11e730x(1);
        *(short *)(p1 + 0x16) = 1;
        *(int *)(p1 + 0xc) = 1;
    }
    f_11e960(p1 + 0x26);
}
//@ f_10a8b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den aktuellen Frame-Index *(short *)(p1 + 0x16) auf 1 zurück und spult das
 *   Smacker-Video über f_10ad70 auf den ersten Frame zurück.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(short *)(p1 + 0x16) (Frame-Index).
 === Ende Beschreibung === */
void f_10a8b0(int p1)
{
    *(short *)(p1 + 0x16) = 1;
    f_10ad70(p1, (int)*(short *)(p1 + 0x16));
}
//@ f_10a8d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode liefert den aktuellen 16-Bit-Frame-Index *(short *)(p1 + 0x16) des
 *   Video-Players zurück.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion gibt die aktuelle Frame-Nummer (short) zurück.
 * - Wichtige Variablen: *(short *)(p1 + 0x16).
 === Ende Beschreibung === */
short f_10a8d0(int p1)
{
    return *(short *)(p1 + 0x16);
}
//@ f_10a8e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Zugriffsmethode setzt das Anzeige- bzw. Debug-Flag bei Offset +0x10 des Video-Players p1 auf
 *   den Wert p2.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den neuen Flag-Wert p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(int *)(p1 + 0x10).
 === Ende Beschreibung === */
void f_10a8e0(int p1, int p2)
{
    *(int *)(p1 + 0x10) = p2;
}
//@ f_10a8f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Methode ruft, sofern bei Offset +0x1c des Video-Players p1 ein gültiger Callback-Zeiger (!= 0
 *   und != -1) hinterlegt ist, diese Funktion mit dem Parameter (short)p2 auf.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den Callback-Parameter p2.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(int *)(p1 + 0x1c) (Callback-Funktionszeiger).
 === Ende Beschreibung === */
void f_10a8f0(int p1, int p2)
{
    if (*(int *)(p1 + 0x1c) != 0 && *(int *)(p1 + 0x1c) != -1) {
        ((void (*)(int))*(int *)(p1 + 0x1c))((int)(short)p2);
    }
}
//@ f_10a910
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion übernimmt die im Smacker-Handle *p1 ab Offset +0x6c gespeicherte Farbpalette über
 *   f_14d040 in die aktive Bildschirm-Palette.
 * - Eingaben: Die Funktion erhält den Zeiger p1 (int *) auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *p1 + 0x6c (RGB-Palettendaten im Smacker-Handle).
 === Ende Beschreibung === */
int f_14d040a(const char *p);
#pragma aux f_14d040a "f_14d040" parm caller [] modify [eax ecx edx];
void f_10a910(int *p1)
{
    f_14d040a((const char *)(*p1 + 0x6c));
}
//@ f_10a930
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion reicht den 16-Bit-Steuerparameter p2 an die Smacker-Hilfsfunktion f_14bb10 weiter.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie den Parameter p2 (short).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Delegiert direkt an f_14bb10.
 === Ende Beschreibung === */
int f_14bb10x(int);
#pragma aux f_14bb10x "f_14bb10" parm [] modify [eax ebx ecx edx];
void f_10a930(int p1, short p2)
{
    f_14bb10x((int)(short)p2);
}
//@ f_10a940
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Initialisierungsfunktion setzt alle Status-, Positions- und Callback-Felder des
 *   Smacker-Player-Objekts p1 auf ihre Ausgangswerte (Frame = 1 bei +0x16, übrige Felder 0).
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: Felder +0x08 bis +0x22 des Player-Objekts p1.
 === Ende Beschreibung === */
void f_10a940(int p1)
{
    *(short *)(p1 + 0x16) = 1;
    *(short *)(p1 + 0x14) = 0;
    *(int *)(p1 + 0xc) = 0;
    *(int *)(p1 + 8) = 0;
    *(int *)(p1 + 0x10) = 0;
    *(short *)(p1 + 0x18) = 0;
    *(short *)(p1 + 0x1a) = 0;
    *(short *)(p1 + 0x20) = 0;
    *(int *)(p1 + 0x22) = 0;
}
//@ f_10a980
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion aktiviert bei Bedarf die Videoausgabe (f_11e730(1)), schaltet über f_11e760(p3, p2)
 *   und f_11e8f0 in den gewünschten Anzeigemodus und vermerkt den Moduswert p2 bei Offset +0x14.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die Modusparameter p2 und p3 (short).
 * - Rückgabewert: Die Funktion gibt 1 bei erfolgreichem Moduswechsel zurück, sonst 0.
 * - Wichtige Variablen: c (Rückgabe von f_11e760), *(short *)(p1 + 0x14) (gespeicherter Videomodus).
 === Ende Beschreibung === */
unsigned char f_11e760_q(short, short);
#pragma aux f_11e760_q "f_11e760" parm [] modify [eax ebx ecx edx];
int f_10a980(int p1, volatile short p2, volatile short p3) // volatile haelt Parameter-Ablage auf [esp+4] und [esp] wie im Original
{
    int r = 0;
    if (*(int *)(p1 + 0xc) == 0) {
        f_11e730(1);
        *(short *)(p1 + 0x16) = 1;
        *(int *)(p1 + 0xc) = 1;
    }
    int c = (unsigned char)f_11e760_q(p3, p2);
    if (c != 0) {
        f_11e8f0();
        short saved = 0;
        saved = p2;
        *(short *)(p1 + 0x14) = saved;
        r = 1;
    }
    return r;
}
//@ f_10a9e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entspricht in Aufbau und Wirkung f_10a980: Sie initialisiert bei Bedarf das
 *   Video-Subsystem (f_11e730(1)), prüft und aktiviert über f_11e760(p3, p2) sowie f_11e8f0 den Bildschirmmodus
 *   und speichert p2 bei Offset +0x14.
 * - Eingaben: Die Funktion erhält den Player-Zeiger p1 sowie die Modusparameter p2 und p3 (short).
 * - Rückgabewert: Die Funktion gibt 1 bei Erfolg zurück, sonst 0.
 * - Wichtige Variablen: c (Rückgabe von f_11e760), *(short *)(p1 + 0x14).
 === Ende Beschreibung === */
unsigned char f_11e760_r(short, short);
#pragma aux f_11e760_r "f_11e760" parm [] modify [eax ebx ecx edx];
int f_10a9e0(int p1, volatile short p2, volatile short p3) // volatile haelt Parameter-Ablage auf [esp+4] und [esp] wie im Original
{
    int r = 0;
    if (*(int *)(p1 + 0xc) == 0) {
        f_11e730(1);
        *(short *)(p1 + 0x16) = 1;
        *(int *)(p1 + 0xc) = 1;
    }
    int c = (unsigned char)f_11e760_r(p3, p2);
    if (c != 0) {
        f_11e8f0();
        short saved = 0;
        saved = p2;
        *(short *)(p1 + 0x14) = saved;
        r = 1;
    }
    return r;
}
//@ f_10aa40
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Aufräumfunktion setzt den Bildschirmmodus über f_11e900 zurück, sofern im Player-Objekt p1 bei
 *   Offset +0x14 ein aktiver Videomodus (!= 0) vermerkt ist.
 * - Eingaben: Die Funktion erhält den Zeiger p1 auf das Video-Player-Objekt.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: *(short *)(p1 + 0x14).
 === Ende Beschreibung === */
void f_10aa40(int p1);
#pragma aux f_10aa40 modify [eax];
int f_11e900_all();
#pragma aux f_11e900_all "f_11e900" parm [] modify [eax ebx ecx edx];
void f_10aa40(int p1)
{
    if (*(short *)(p1 + 0x14) != 0) {
        f_11e900_all();
    }
}
//@ f_10aa60
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion dekodiert das aktuelle Einzelbild des Smacker-Handles *p1 über f_14b3d0 und überträgt
 *   bei p2 == 1 in einer Schleife sämtliche geänderten Bildrechtecke (f_14a1d0) über f_11e910 unter
 *   Berücksichtigung des Zieloffsets (+0x1a, +0x18) in den Ausgabepuffer p1[1].
 * - Eingaben: Die Funktion erhält den Zeiger p1 (int *) auf das Smacker-Player-Objekt sowie das Kopier-Flag p2
 *   (int, 1 = geänderte Rechtecke kopieren).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 * - Wichtige Variablen: base (*p1, Smacker-Handle mit Rechteckkoordinaten +0x374..+0x380 und Breite +4), p1[1]
 *   (Ziel-Bildpuffer).
 === Ende Beschreibung === */
void f_10aa60(int *p1, int p2)
{
    f_14b3d0_stack(*p1);
    if (p2 == 1) {
        for (;;) {
            if (f_14a1d0_call(1, *p1) == 0) break;
            int *base = (int *)*p1;
            f_11e910_all8(p1[1],
                     *(int *)((char *)base + 0x374),
                     *(int *)((char *)base + 0x378),
                     *(int *)((char *)base + 0x37c),
                     *(int *)((char *)base + 0x380),
                     *(int *)((char *)base + 4),
                     *(short *)((char *)p1 + 0x1a) + *(int *)((char *)base + 0x374),
                     *(short *)((char *)p1 + 0x18) + *(int *)((char *)base + 0x378));
        }
    }
}
