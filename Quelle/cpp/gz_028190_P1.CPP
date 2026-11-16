/* === Beschreibung (Katalog) ===
 * Einheit gz_028190 (0x00028190 - 0x000286d0)
 *
 * Überblick
 *
 * Die Übergangseinheit gz_028190 enthält am Anfang noch die letzte Hilfsfunktion der Porträtleiste (f_028190)
 * und anschließend die Spielstand-Variablenregistrierung (f_0281d0, f_0286b0) für die große nachfolgende Einheit
 * Burg / Festung von Riva (castle_t1-castle_t3).
 === Ende Beschreibung === */
// P1 1/3 gleich
// gz_028190.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x028190-0x0286D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"
#include "R_FIX.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a48f4[];
extern char d_1bc820;
extern short d_1bc821;
extern char d_1bc824;
extern short d_1bc825;
extern char d_1bc828;
extern short d_1bc829;
extern char d_1bc82c;
extern short d_1bc82d;
extern char d_1bc830;
extern short d_1bc831;
extern char d_1bc834;
extern short d_1bc835;
extern char d_1bc838;
extern short d_1bc839;
extern char d_1bc83c;
extern short d_1bc83d;
extern char d_1bc840;
extern short d_1bc841;
extern char d_1bc844;
extern short d_1bc845;
extern char d_1bc848;
extern short d_1bc849;
extern char d_1bc84c;
extern short d_1bc84d;
extern char d_1bc850;
extern short d_1bc851;
extern char d_1bc854;
extern short d_1bc855;
extern char d_1bc858;
extern short d_1bc859;
extern char d_1bc85c;
extern short d_1bc85d;
extern char d_1bc860;
extern short d_1bc861;
extern char d_1bc864;
extern short d_1bc865;
extern char d_1bc868;
extern short d_1bc869;
extern char d_1bc86c;
extern short d_1bc86d;
extern char d_1bc870;
extern short d_1bc871;
extern char d_1bc874;
extern short d_1bc875;
extern char d_1bc878;
extern short d_1bc879;
extern char d_1bc87c;
extern short d_1bc87d;
extern short d_1bc880;
extern short d_1bc882;
extern char d_1bc884;
extern short d_1bc885;
extern char d_1bc888;
extern short d_1bc889;
extern short d_1c212a;
extern int d_1c212c;                    // 0x1C212C
extern short d_1c2132;
extern int d_1c2134;                    // 0x1C2134
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_05ff60(int p1, int p2);
extern int d_1bac08;

//@ f_028190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet wie f_027750 anhand der horizontalen Koordinate pos, über welchem der sieben
 *   Heldenporträt-Plätze (6 bis 0) sich der gezogene Rahmen befindet. *(Hinweis: Auch hier fehlt in der
 *   do-while-Schleife die Untergrenze i >= 0, sodass bei pos < d_1a48f4[0] - 20 vor den Arrayanfang gelesen
 *   wird.)*
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger this sowie die X-Koordinate pos und gibt den
 *   ermittelten Slot-Index zurück.
 * - Wichtige Variablen: Liest rückwärts ab i = 6 die X-Koordinaten der sieben Porträtkästchen aus d_1a48f4[i *
 *   2].
 === Ende Beschreibung === */
void f_028190(int p1, int p2)
{
    short s;
    int found;
    s = 6;
    found = 0;
    do {
#if FIX_R014   /* R014: Untergrenze s > 0 in der Portraet-Suchschleife sichern */
        if (s > 0 && (int)(short)p2 < d_1a48f4[s * 2] - 0x14) {
#else
        if ((int)(short)p2 < d_1a48f4[s * 2] - 0x14) {
#endif
            s = s - 1;
        } else {
            found = 1;
        }
    } while (!found);
    ;
}

//@ f_0281d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Meldet beim Programmstart über 60 persistente Ereignis-, Tür-, Truhen- und Quest-Flags der
 *   Burg von Riva (CASTLE) in der globalen Spielstand-Tabelle an, damit der Zustand der Festung beim Speichern
 *   und Laden erhalten bleibt. *(Hinweis: Hier liegt ein Originalfehler vor, da die beiden direkt vor d_1bc820
 *   liegenden Einmal-Flags d_1bc81c für Feld 108 und d_1bc81d für Feld 1001 nicht im Spielstand-Array
 *   registriert werden und beim Laden eines Spielstands verloren gehen.)*
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Trägt die Ortsflags ab d_1bc820 (mit den Kennungen ab 0x197) einzeln und in Schleifen in
 *   das globale Speicher-Array d_1c212a ein und erhöht jeweils den Zähler d_1c392a.
 === Ende Beschreibung === */
struct RR700V3_0281d08;
struct OR700V3_0281d08 { signed char flag; short number; char pad; OR700V3_0281d08 *init(RR700V3_0281d08 &r,short id,signed char f); };
struct RR700V3_0281d08 { short count; OR700V3_0281d08 **list; void append(OR700V3_0281d08 *o) {list[count]=o;count++;} };
inline OR700V3_0281d08 *OR700V3_0281d08::init(RR700V3_0281d08 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0281d08 regR700V3_0281d08;
#pragma aux regR700V3_0281d08 "d_1c212a"
struct RR700V3_0281d016;
struct OR700V3_0281d016 { short flag; short number;  OR700V3_0281d016 *init(RR700V3_0281d016 &r,short id,short f); };
struct RR700V3_0281d016 { short count; OR700V3_0281d016 **list; void append(OR700V3_0281d016 *o) {list[count]=o;count++;} };
inline OR700V3_0281d016 *OR700V3_0281d016::init(RR700V3_0281d016 &r,short id,short f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_0281d016 regR700V3_0281d016;
#pragma aux regR700V3_0281d016 "d_1c2132"
extern OR700V3_0281d08 obR700V3_0281d0_1bc820;
#pragma aux obR700V3_0281d0_1bc820 "d_1bc820"
extern OR700V3_0281d08 obR700V3_0281d0_1bc824;
#pragma aux obR700V3_0281d0_1bc824 "d_1bc824"
extern OR700V3_0281d08 obR700V3_0281d0_1bc828;
#pragma aux obR700V3_0281d0_1bc828 "d_1bc828"
extern OR700V3_0281d08 obR700V3_0281d0_1bc82c;
#pragma aux obR700V3_0281d0_1bc82c "d_1bc82c"
extern OR700V3_0281d08 obR700V3_0281d0_1bc830;
#pragma aux obR700V3_0281d0_1bc830 "d_1bc830"
extern OR700V3_0281d08 obR700V3_0281d0_1bc834;
#pragma aux obR700V3_0281d0_1bc834 "d_1bc834"
extern OR700V3_0281d08 obR700V3_0281d0_1bc838;
#pragma aux obR700V3_0281d0_1bc838 "d_1bc838"
extern OR700V3_0281d08 obR700V3_0281d0_1bc83c;
#pragma aux obR700V3_0281d0_1bc83c "d_1bc83c"
extern OR700V3_0281d08 obR700V3_0281d0_1bc840;
#pragma aux obR700V3_0281d0_1bc840 "d_1bc840"
extern OR700V3_0281d08 obR700V3_0281d0_1bc844;
#pragma aux obR700V3_0281d0_1bc844 "d_1bc844"
extern OR700V3_0281d08 obR700V3_0281d0_1bc848;
#pragma aux obR700V3_0281d0_1bc848 "d_1bc848"
extern OR700V3_0281d08 obR700V3_0281d0_1bc84c;
#pragma aux obR700V3_0281d0_1bc84c "d_1bc84c"
extern OR700V3_0281d08 obR700V3_0281d0_1bc850;
#pragma aux obR700V3_0281d0_1bc850 "d_1bc850"
extern OR700V3_0281d08 obR700V3_0281d0_1bc854;
#pragma aux obR700V3_0281d0_1bc854 "d_1bc854"
extern OR700V3_0281d08 obR700V3_0281d0_1bc858;
#pragma aux obR700V3_0281d0_1bc858 "d_1bc858"
extern OR700V3_0281d08 obR700V3_0281d0_1bc85c;
#pragma aux obR700V3_0281d0_1bc85c "d_1bc85c"
extern OR700V3_0281d08 obR700V3_0281d0_1bc860;
#pragma aux obR700V3_0281d0_1bc860 "d_1bc860"
extern OR700V3_0281d08 obR700V3_0281d0_1bc864;
#pragma aux obR700V3_0281d0_1bc864 "d_1bc864"
extern OR700V3_0281d08 obR700V3_0281d0_1bc868;
#pragma aux obR700V3_0281d0_1bc868 "d_1bc868"
extern OR700V3_0281d08 obR700V3_0281d0_1bc86c;
#pragma aux obR700V3_0281d0_1bc86c "d_1bc86c"
extern OR700V3_0281d08 obR700V3_0281d0_1bc870;
#pragma aux obR700V3_0281d0_1bc870 "d_1bc870"
extern OR700V3_0281d08 obR700V3_0281d0_1bc874;
#pragma aux obR700V3_0281d0_1bc874 "d_1bc874"
extern OR700V3_0281d08 obR700V3_0281d0_1bc878;
#pragma aux obR700V3_0281d0_1bc878 "d_1bc878"
extern OR700V3_0281d08 obR700V3_0281d0_1bc87c;
#pragma aux obR700V3_0281d0_1bc87c "d_1bc87c"
extern OR700V3_0281d016 obR700V3_0281d0_1bc880;
#pragma aux obR700V3_0281d0_1bc880 "d_1bc880"
extern OR700V3_0281d08 obR700V3_0281d0_1bc884;
#pragma aux obR700V3_0281d0_1bc884 "d_1bc884"
extern OR700V3_0281d08 obR700V3_0281d0_1bc888;
#pragma aux obR700V3_0281d0_1bc888 "d_1bc888"
#if FIX_R014   /* R014: Burg-Einmalflags d_1bc81c und d_1bc81d bei der Initialisierung zuruecksetzen */
extern signed char d_1bc81c, d_1bc81d;
#endif
void f_0281d0(void) {
#if FIX_R014
d_1bc81c = 0;
d_1bc81d = 0;
#endif
obR700V3_0281d0_1bc820.init(regR700V3_0281d08,0x197,0);
obR700V3_0281d0_1bc824.init(regR700V3_0281d08,0x198,0);
obR700V3_0281d0_1bc828.init(regR700V3_0281d08,0x199,0);
obR700V3_0281d0_1bc82c.init(regR700V3_0281d08,0x19a,0);
obR700V3_0281d0_1bc830.init(regR700V3_0281d08,0x19b,0);
obR700V3_0281d0_1bc834.init(regR700V3_0281d08,0x19c,0);
obR700V3_0281d0_1bc838.init(regR700V3_0281d08,0x19d,0);
obR700V3_0281d0_1bc83c.init(regR700V3_0281d08,0x19e,0);
obR700V3_0281d0_1bc840.init(regR700V3_0281d08,0x19f,0);
obR700V3_0281d0_1bc844.init(regR700V3_0281d08,0x1a0,0);
obR700V3_0281d0_1bc848.init(regR700V3_0281d08,0x1a1,0);
obR700V3_0281d0_1bc84c.init(regR700V3_0281d08,0x1a2,0);
obR700V3_0281d0_1bc850.init(regR700V3_0281d08,0x1a3,0);
obR700V3_0281d0_1bc854.init(regR700V3_0281d08,0x1a4,0);
obR700V3_0281d0_1bc858.init(regR700V3_0281d08,0x1a5,0);
obR700V3_0281d0_1bc85c.init(regR700V3_0281d08,0x1a6,0);
obR700V3_0281d0_1bc860.init(regR700V3_0281d08,0x1a7,0);
obR700V3_0281d0_1bc864.init(regR700V3_0281d08,0x1a8,0);
obR700V3_0281d0_1bc868.init(regR700V3_0281d08,0x1a9,0);
obR700V3_0281d0_1bc86c.init(regR700V3_0281d08,0x1aa,0);
obR700V3_0281d0_1bc870.init(regR700V3_0281d08,0x1ab,0);
obR700V3_0281d0_1bc874.init(regR700V3_0281d08,0x1b4,0);
obR700V3_0281d0_1bc878.init(regR700V3_0281d08,0x23b,0);
obR700V3_0281d0_1bc87c.init(regR700V3_0281d08,0x249,0);
obR700V3_0281d0_1bc880.init(regR700V3_0281d016,0x2,500);
obR700V3_0281d0_1bc884.init(regR700V3_0281d08,0x253,0);
obR700V3_0281d0_1bc888.init(regR700V3_0281d08,0x266,0);
}


//@ f_0286b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wird beim Start der EXE automatisch aufgerufen und führt f_0281d0 aus, um sämtliche
 *   registrierten Burg-Variablen in der Spielstand-Verwaltung anzumelden.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Delegiert unmittelbar an f_0281d0.
 === Ende Beschreibung === */
void f_0286b0(int p1)
{
    int r;
    r = f_05ff60(p1, 6);
    *(int *)(r + 8) = (int)&d_1bac08;
    *(short *)(r + 0xc) = 0;
}
