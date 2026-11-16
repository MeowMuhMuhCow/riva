/* === Beschreibung (Katalog) ===
 * Einheit ch_level_t1 (0x036ee0 - 0x0384e0)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil des Stufenaufstiegs-Systems (Level-Up, in *Sternenschweif*
 * vergleichbar mit den Funktionen zum Steigern von Eigenschaften, Lebens-/Astralpunkten, Talenten und Zaubern).
 * Sie unterstützt sowohl die manuelle Steigerung durch den Spieler im Charakterbogen als auch die automatische
 * Computer-Steigerung (i122 != 0 oder Einsteigermodus d_1bfaec == 0) anhand klassenspezifischer
 * Prioritätstabellen.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 9/14 gleich (suche.py 30.10.2026, Basis ch_level_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 951 (vorher 953)
// ch_level.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil 1, Code 0x036EE0-0x0384E0
#include <string.h>
#include "RIVAMEM.H"



typedef signed char SB;
typedef signed char RC;



RC f_03ad80(int p1, int p2);
RC f_043ac0(int p1, int p2);


char f_043e30(int p1);


int f_03af20(int p1, int p2, int p3);
int f_0453e0(int p1, int p2, int p3);



int f_043360(int p1, int p2);
int f_040730(int p1, int p2);
int f_040880(int p1, int p2);
int f_043e20(int p1, int p2);
int f_0449d0(int p1, int p2);
int f_0bf6f0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
int f_0bf7b0(void *p1, int p2, int p3, int p4, int p5, int p6);
short f_0bf820();
int f_0d26e0();
int f_0d2710();
int f_0d3860();
int f_0d5550(void *p1);
int f_125400(int p1, void *p2, void *p3);
int f_125400(int p1, void *p2, void *p3, void *p4);
int f_1254a0(int p1, int);
short f_145760(int p1, int p2);
short f_1457e0(int p1);
short f_149360(int p1, char *p2);
extern unsigned char d_1a0514;
extern unsigned char d_1a0515;
extern signed char d_1a0994[];
extern short d_1a09a6[];
extern short d_1a09ac[];
extern char *d_1a0a8c[];
extern short d_1a0ab0[];
extern short d_1a0abe[];
extern short d_1a0acc[];
extern unsigned char d_1a0ae4[];
extern unsigned char d_1a0aeb[];
extern unsigned short d_1a6ad3[];
extern signed char d_1a7270[];
extern char *d_1bc898;
extern SB *d_1bc89c;
extern SB *d_1bc8a0;
extern char *d_1bc8a4;
extern signed char d_1bfaec;
extern short d_1c2198;
extern char d_1c2bcc[];
extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
struct Tmp { char b[20]; short *q; char r[0x3c - 24]; };
short f_036ee0(int i0, int c);
int f_037250(int c);
int f_037280(int c);
struct Lv {
    char p0[5]; short s5; char p7[4]; int ch; char pf[0x122 - 0xf]; int i122;
    void f_037030(short p2); void f_037140(short p2); void f_0372c0(short p2); void f_037420(short p2);
    void f_0376d0(); void f_037730(); void f_0378e0(); void f_037bb0(); void f_037de0(); void f_037e60(); void f_037fd0();
    void f_04e470();
};
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_036ee0  groesse 336 B, 119 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Funktion ermittelt, um wie viele Punkte ein magiebegabter Held einen bestimmten
 *   Zauberspruch i0 während eines einzelnen Stufenaufstiegs maximal steigern darf (1, 2 oder 3 Punkte). Das
 *   Limit hängt von der Charakterklasse (7 = Hexe, 8 = Druide, 9 = Magier mit Spezialgebiet, >= 10 = Elfen)
 *   sowie der Herkunft/Kategorie des Zaubers (d_1a7270[i0 * 14]) und der Hauszauberliste (d_1bc8a4) ab.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zauberindex i0 und den Heldenzeiger c und gibt die maximal
 *   erlaubte Steigerungszahl (1, 2 oder 3) als short zurück.
 * - Wichtige Variablen: d_1a7270 ist die Zauber-Stammdatentabelle (14 Bytes pro Zauber), d_1a0994 begrenzt die
 *   Schulzauberbereiche der Magierakademien, und d_1bc8a4 enthält die geladenen Hauszauber je Magierschule.
 === Ende Beschreibung === */
short f_036ee0(int i0, int c)
{
    short r = 1;
    if (((RC)(f_042350((struct hero *)(c)))) == 7 && d_1a7270[(short)i0 * 14] == 2) r = 2;
    else if (((RC)(f_042350((struct hero *)(c)))) >= 10 && (d_1a7270[(short)i0 * 14] == 3 || d_1a7270[(short)i0 * 14] == 5 || d_1a7270[(short)i0 * 14] == 4)) {
        r = 2;
    } else if (((RC)(f_042350((struct hero *)(c)))) == 8 && d_1a7270[(short)i0 * 14] == 0) {
        r = 2;
    } else if (((RC)(f_042350((struct hero *)(c)))) == 9) {
        if (d_1a7270[(short)i0 * 14] == 1) r = 2;
        if ((short)i0 >= d_1a0994[((RC)(f_043320((struct hero *)(c)))) * 2]) {
            if ((short)i0 <= d_1a0994[((RC)(f_043320((struct hero *)(c)))) * 2 + 1]) r = 2;
        }
        if (f_149360((short)i0, d_1bc8a4 + ((RC)(f_043320((struct hero *)(c)))) * 0x21 + 1) != -1) r = 3;
    }
    return r;
}
//@ f_037030  groesse 272 B, 84 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode führt im interaktiven Stufenaufstieg einen einzelnen Steigerungsversuch für den
 *   Zauberspruch p2 durch. Sie prüft, ob das Stufenlimit (f_036ee0) bereits erreicht ist oder bereits drei
 *   Fehlversuche vorliegen, zieht einen Zauber-Steigerungspunkt ab, würfelt mit 2W6 (bei Zauberwert < 11) bzw.
 *   3W6 (ab Zauberwert 11) gegen den aktuellen Zauberwert und erhöht bei Erfolg den Zauberwert um 1.
 * - Eingaben und Rückgabe: Die Methode wird auf dem Stufenaufstiegs-Dialogobjekt Lv (this) mit dem Zauberindex
 *   p2 (short) aufgerufen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Array d_1bc8a0 protokolliert während des Stufenaufstiegs für jeden der 86 Zauber die
 *   bisherigen Fehlversuche (d_1bc8a0[p2 * 2]) und die bereits erzielten Steigerungen (d_1bc8a0[p2 * 2 + 1]).
 === Ende Beschreibung === */
void Lv::f_037030(short p2)
{
    short r = f_036ee0(p2, ch);
#if FIX_R029
    if (((RC)(f_0430f0((struct hero *)(ch), p2))) >= 18 || d_1bc8a0[p2 * 2 + 1] >= r) { f_0bf730(d_1c2c64, 0x304003e); return; }
#else
    if (d_1bc8a0[p2 * 2 + 1] >= r) { f_0bf730(d_1c2c64, 0x304003e); return; }
#endif
    if (d_1bc8a0[p2 * 2] == 3) { f_0bf730(d_1c2c64, 0x304003f); return; }
    f_043310((struct hero *)(ch), -1);
    short roll;
    if (((RC)(f_0430f0((struct hero *)(ch), p2))) >= 11) roll = f_145760(3, 18);
    else roll = f_145760(2, 12);
    if (roll > ((RC)(f_0430f0((struct hero *)(ch), p2)))) {
        f_0bf730(d_1c2c64, 0x3040040);
        f_043110((struct hero *)(ch), p2, 1);
        d_1bc8a0[p2 * 2] = 0;
        d_1bc8a0[p2 * 2 + 1]++;
        return;
    }
    f_0bf730(d_1c2c64, 0x3040041);
    d_1bc8a0[p2 * 2]++;
}
//@ f_037140  groesse 384 B, 80 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode führt im interaktiven Stufenaufstieg einen einzelnen Steigerungsversuch für das
 *   Talent p2 durch. Analog zu f_037030 prüft sie das maximale Steigerungslimit aus d_1a6ad3 sowie die
 *   Drei-Fehlversuche-Grenze, zieht einen Talent-Steigerungspunkt ab und würfelt mit 2W6 (unter Talentwert 11)
 *   bzw. 3W6 (ab Talentwert 11).
 * - Eingaben und Rückgabe: Die Methode erhält auf Lv (this) den Talentindex p2 (short) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Das Array d_1bc89c speichert für jedes der 52 Talente die Fehlversuche ([p2 * 2]) und
 *   die erfolgreichen Steigerungen ([p2 * 2 + 1]) innerhalb des aktuellen Stufenaufstiegs.
 === Ende Beschreibung === */
void Lv::f_037140(short p2)
{
    short limit = ((signed char *)d_1a6ad3)[p2 * 4];
#if FIX_R029
    if (f_03ad80(ch, p2) >= 18 || d_1bc89c[p2 * 2 + 1] >= limit) {
#else
    if (d_1bc89c[p2 * 2 + 1] >= limit) {
#endif
        f_0bf730(d_1c2c64, 0x304003e);
    } else {
        if (d_1bc89c[p2 * 2] == 3) { f_0bf730(d_1c2c64, 0x304003f); return; }
        f_043360(ch, -1);
        short roll;
        if (f_03ad80(ch, p2) >= 11) roll = f_145760(3, 18);
        else roll = f_145760(2, 12);
        if (roll > f_03ad80(ch, p2)) {
            f_0bf730(d_1c2c64, 0x3040040);
            f_03af20(ch, p2, 1);
            d_1bc89c[p2 * 2] = 0;
            d_1bc89c[p2 * 2 + 1]++;
            return;
        }
        f_0bf730(d_1c2c64, 0x3040041);
        d_1bc89c[p2 * 2]++;
    }
}
//@ f_037250  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft, ob der Held c überhaupt noch mindestens ein Talent besitzt, dessen
 *   Wert unter dem Höchstwert 18 liegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger c und gibt 1 zurück, falls mindestens eines der
 *   52 Talente (0..51) kleiner als 18 ist, andernfalls 0.
 * - Wichtige Variablen: Abgefragt werden die Talentwerte über f_03ad80(c, i).
 === Ende Beschreibung === */
int f_037250(int c)
{
    short i;
    for (i = 0; i < 0x34; i++) {
        if (f_03ad80(c, i) < 18) return 1;
    }
    return 0;
}
//@ f_037280  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsfunktion prüft analog zu f_037250, ob ein magiebegabter Held c noch mindestens
 *   einen Zauberspruch (1..85) besitzt, dessen Wert unter dem Höchstwert 18 liegt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger c und gibt 1 zurück, falls noch ein steigerbarer
 *   Zauber (< 18) existiert, sonst 0.
 * - Wichtige Variablen: Abgefragt werden die Zauberwerte über f_0430f0(c, i).
 === Ende Beschreibung === */
int f_037280(int c)
{
    short i;
    for (i = 1; i < 0x56; i++) {
        if (((RC)(f_0430f0((struct hero *)(c), i))) < 18) return 1;
    }
    return 0;
}
//@ f_0372c0  groesse 352 B, 99 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode versucht im automatischen Computer-Steigerungsmodus so lange das Talent p2 zu
 *   steigern, bis entweder eine Steigerung gelingt, drei Fehlversuche erreicht sind, das Stufenlimit
 *   ausgeschöpft ist oder der Held keine freien Talent-Steigerungspunkte mehr hat.
 * - Eingaben und Rückgabe: Die Methode erhält auf Lv (this) den Talentindex p2 (short) und gibt keinen Wert
 *   zurück.
 * - Wichtige Variablen: Sind bereits alle Talente auf 18 (!f_037250(ch)), werden die verbleibenden
 *   Talent-Steigerungspunkte des Helden über f_043350(ch, 0) auf 0 gesetzt.
 === Ende Beschreibung === */
void Lv::f_0372c0(short p2)
{
    short done = 0;
    short limit = ((signed char *)d_1a6ad3)[p2 * 4];
    if (!f_037250(ch)) {
        f_043350((struct hero *)(ch), 0);
        done = 1;
    }
    while (!done) {
        if (d_1bc89c[p2 * 2] == 3 || f_03ad80(ch, p2) == 18 || d_1bc89c[p2 * 2 + 1] >= limit) {
            done = 1;
        } else {
            f_043360(ch, -1);
            if (!((RC)(f_043340((struct hero *)(ch))))) done = 1;
            short roll;
            if (f_03ad80(ch, p2) >= 11) roll = f_145760(3, 18);
            else roll = f_145760(2, 12);
            if (roll > f_03ad80(ch, p2)) {
                f_03af20(ch, p2, 1);
                d_1bc89c[p2 * 2] = 0;
                d_1bc89c[p2 * 2 + 1]++;
                done = 1;
            } else {
                d_1bc89c[p2 * 2]++;
            }
        }
    }
}
//@ f_037420  groesse 784 B, 179 Bef, reg eax edx, stapel ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode versucht im automatischen Computer-Steigerungsmodus einen einzelnen Zauberspruch
 *   p2 um 1 Punkt zu steigern, bis der Wurf gelingt, drei Fehlversuche aufgetreten sind, das klassenspezifische
 *   Limit erreicht ist oder keine Zauber-Steigerungspunkte mehr übrig sind.
 * - Eingaben und Rückgabe: Die Methode erhält auf Lv (this) den Zauberindex p2 (short) und hat keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Die Berechnung des erlaubten Stufenlimits lvl (1, 2 oder 3) entspricht exakt der Logik
 *   in f_036ee0.
 === Ende Beschreibung === */
void Lv::f_037420(short p2)
{
    short done = 0;
    short lvl = 1;
    if (((RC)(f_042350((struct hero *)(ch)))) == 7 && d_1a7270[p2 * 14] == 2) {
        lvl = 2;
    } else if (((RC)(f_042350((struct hero *)(ch)))) >= 10 && (d_1a7270[p2 * 14] == 3 || d_1a7270[p2 * 14] == 5 || d_1a7270[p2 * 14] == 4)) {
        lvl = 2;
    } else if (((RC)(f_042350((struct hero *)(ch)))) == 8 && d_1a7270[p2 * 14] == 0) {
        lvl = 2;
    } else if (((RC)(f_042350((struct hero *)(ch)))) == 9) {
        if (d_1a7270[p2 * 14] == 1) lvl = 2;
        if (p2 >= d_1a0994[((RC)(f_043320((struct hero *)(ch)))) * 2]) {
            if (p2 <= d_1a0994[((RC)(f_043320((struct hero *)(ch)))) * 2 + 1]) lvl = 2;
        }
        if (f_149360(p2, d_1bc8a4 + ((RC)(f_043320((struct hero *)(ch)))) * 0x21 + 1) != -1) lvl = 3;
    }
    if (!f_037280(ch)) {
        f_043300((struct hero *)(ch), 0);
        done = 1;
    }
    while (!done) {
        if (d_1bc8a0[p2 * 2] == 3 || ((RC)(f_0430f0((struct hero *)(ch), p2))) == 18 || d_1bc8a0[p2 * 2 + 1] >= lvl) {
            done = 1;
        } else {
            f_043310((struct hero *)(ch), -1);
            if (!((RC)(f_0432f0((struct hero *)(ch))))) done = 1;
            short roll;
            if (((RC)(f_0430f0((struct hero *)(ch), p2))) >= 11) roll = f_145760(3, 18);
            else roll = f_145760(2, 12);
            if (roll > ((RC)(f_0430f0((struct hero *)(ch), p2)))) {
                f_043110((struct hero *)(ch), p2, 1);
                d_1bc8a0[p2 * 2] = 0;
                d_1bc8a0[p2 * 2 + 1]++;
                done = 1;
            } else {
                d_1bc8a0[p2 * 2]++;
            }
        }
    }
}
//@ f_0376d0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Hilfsmethode zeichnet das Charakterbogen-Fenster während des Stufenaufstiegs neu und
 *   kopiert den Bildschirmpuffer bei ausgeblendetem Mauszeiger auf die Anzeige.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die globalen Marker d_1a0514 und d_1a0515 werden vor dem Kopieren (f_0d5550(d_1c2bcc))
 *   auf 0xff zurückgesetzt.
 === Ende Beschreibung === */
void Lv::f_0376d0()
{
    struct Guard {
        int on;
        Guard() { if (f_0d3860() == 1) { f_0d2710(); on = 1; } else on = 0; }
        ~Guard() { if (on == 1) f_0d26e0(); }
    } guard;
    f_04e470();
    d_1a0515 = 0xff;
    d_1a0514 = 0xff;
    f_0d5550(d_1c2bcc);
}
//@ f_037730  groesse 432 B, 141 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode führt beim Stufenaufstieg die Erhöhung einer positiven Eigenschaft (MU, KL, CH,
 *   FF, GE, IN, KK, Index 0..6) um 1 Punkt bis zum Höchstwert 20 durch. Im Automatikmodus (i122 != 0) wählt sie
 *   anhand der klassenspezifischen Präferenztabelle d_1a0ae4 eine Eigenschaft aus; im manuellen Modus öffnet sie
 *   ein Auswahlmenü für den Spieler.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und hat keinen Rückgabewert.
 * - Wichtige Variablen: Die Tabelle d_1a0ae4 listet für jede der 12 Heldenklassen die bevorzugten positiven
 *   Eigenschaften in absteigender Priorität auf; f_0453e0(ch, idx, 1) erhöht sowohl den aktuellen als auch den
 *   maximalen Eigenschaftswert.
 === Ende Beschreibung === */
void Lv::f_037730()
{
    int f_0bf820(void *, ...);
    int any = 0;
    short i;
    int k;
    RC c;
    for (i = 0; i <= 6; i++) {
        if (f_043ac0(ch, i) < 20) any = 1;
    }
    if (any) {
        if (i122 != 0) {
            s5 = -1;
            for (;;) {
                for (i = 0; i < 7; i++) {
                    c = ((RC)(f_042350((struct hero *)(ch))));
                    if (f_043ac0(ch, d_1a0ae4[(c - 1) * 14 + i]) < 20 && f_1457e0(100) < 75) {
                        c = ((RC)(f_042350((struct hero *)(ch))));
                        s5 = d_1a0ae4[i + (c - 1) * 14];
                        break;
                    }
                }
                if (s5 != -1) {
                    f_0453e0(ch, s5, 1);
                    return;
                }
            }
        }
        do {
            short r = f_0bf820(d_1c2c64, 0x3040042, 7,
                0x20000143, 0x20000144, 0x20000145, 0x20000146,
                0x20000147, 0x20000148, 0x20000149);
            s5 = r - 1;
            if (f_043ac0(ch, (short)(r - 1)) >= 20) {
                s5 = -2;
                f_0bf730(d_1c2c64, 0x3040043);
            }
            k = s5;
        } while (k == -2);
        f_0453e0(ch, k, 1);
        struct Guard {
            int on;
            Guard() { if (f_0d3860() == 1) { f_0d2710(); on = 1; } else on = 0; }
            ~Guard() { if (on == 1) f_0d26e0(); }
        } guard;
        f_04e470();
        d_1a0515 = 0xff;
        d_1a0514 = 0xff;
        f_0d5550(d_1c2bcc);
    }
}
//@ f_0378e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode wickelt beim Stufenaufstieg den Versuch ab, eine schlechte Eigenschaft (AG, HA,
 *   RA, TA, NG, GG, JZ, Index 7..13) um 1 Punkt bis auf das Minimum 2 zu senken. Es werden drei Würfe mit 1W20
 *   gegen den aktuellen Wert der gewählten schlechten Eigenschaft ausgeführt; gelingt mindestens einer der drei
 *   Würfe, sinkt der Wert um 1.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Die Tabelle d_1a0aeb enthält für den Automatikmodus (i122 != 0) je Heldenklasse die
 *   bevorzugte Reihenfolge, in der schlechte Eigenschaften gesenkt werden sollen.
 === Ende Beschreibung === */
void Lv::f_0378e0()
{
    int f_0bf820(void *, ...);
    RC f_043ac0(int, short);
    int eligible = 0;
    short attempt;
    short succeeded;

    for (attempt = 7; attempt <= 13; attempt++) {
        if (f_043ac0(ch, attempt) > 2) eligible = 1;
    }
    if (eligible) {
        if (i122) {
            s5 = -1;
            do {
                for (attempt = 0; attempt < 7; attempt++) {
                    if (f_043ac0(ch, d_1a0aeb[(((RC)(f_042350((struct hero *)(ch)))) - 1) * 14 + attempt]) > 2 &&
                        f_1457e0(100) < 75) {
                        s5 = d_1a0aeb[attempt + (((RC)(f_042350((struct hero *)(ch)))) - 1) * 14];
                        break;
                    }
                }
            } while (s5 == -1);
            succeeded = 0;
            for (attempt = 0; attempt < 3; attempt++) {
                if (f_1457e0(20) <= f_043ac0(ch, s5)) succeeded = 1;
            }
            if (succeeded) {
                f_0453e0(ch, s5, -1);
                if (!f_043e30(ch)) f_0376d0();
            }
        } else {
            // Unterschiedliche Breiten trennen die Konstanten-Webs (ecx = Meldung, edi = -2)
            short invalid = -2;
            int message = 0x3040045;
            do {
                s5 = f_0bf820(d_1c2c64, 0x3040044, 7,
                             0x2000014a, 0x2000014b, 0x2000014c, 0x2000014d,
                             0x2000014e, 0x2000014f, 0x20000150) - 1;
                if (f_043ac0(ch, (short)(s5 + 7)) <= 2) {
                    s5 = invalid;
                    f_0bf730(d_1c2c64, message);
                }
            } while (s5 == -2);
            succeeded = 0;
            for (attempt = 0; attempt < 3; attempt++) {
                if (f_1457e0(20) <= f_043ac0(ch, (short)(s5 + 7))) succeeded = 1;
            }
            if (succeeded) {
                f_0bf730(d_1c2c64, 0x3040040);
                f_0453e0(ch, (short)(s5 + 7), -1);
                f_0376d0();
            } else {
                f_0bf730(d_1c2c64, 0x3040041);
            }
        }
    }
}
//@ f_037bb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode würfelt beim Stufenaufstieg den Zuwachs an Lebensenergie (LE) und bei
 *   magiebegabten Helden zusätzlich an Astralenergie (AE) aus, verteilt die Punkte und bietet einem Magier
 *   (Klasse 9) im Fortgeschrittenenmodus (d_1bfaec == 1) außerdem die Große Meditation an (10
 *   Zauber-Steigerungspunkte opfern für 1W6+2 permanente Astralpunkte). Nichtmagier erhalten 1W6 Lebenspunkte,
 *   Magiebegabte können 1W6+2 Gesamtpunkte frei (oder im Automatikmodus hälftig) zwischen LE und AE aufteilen.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und hat keinen Rückgabewert.
 * - Wichtige Variablen: f_040880(ch, le) erhöht die permanente und aktuelle Lebensenergie, während f_040730(ch,
 *   ae) die permanente und aktuelle Astralenergie erhöht.
 === Ende Beschreibung === */
void Lv::f_037bb0()
{
    int f_125400(int, void *, void *, void *);
    struct Frame { Tmp t; int first, second; } f;
    int f_043e30(void *);
    short roll, a, b;
    f_125400((int)&f.t, d_1c349c, d_1c3870, d_1c3498);
    roll = f_1457e0(6);
    a = roll;
    a++;
    b = roll;
    b += 3;
    if (i122 != 0) {
        if (f_042a10((struct hero *)(ch)) != 0) {
            short half = b / 2;
            s5 = half;
            f_040880(ch, half);
            b -= s5;
            f_040730(ch, b);
        } else {
            f_040880(ch, a);
        }
        if ((signed char)f_043e30((void *)ch) == (signed char)0) {
            if (f_0d3860() == 1) { f_0d2710(); f.first = 1; }
            else f.first = 0;
            f_04e470();
            d_1a0515 = 0xff;
            d_1a0514 = 0xff;
            f_0d5550(d_1c2bcc);
            if (f.first == 1) f_0d26e0();
        }
    } else {
        if (f_042a10((struct hero *)(ch)) != 0) {
            short total = b;
            f.t.q[1] = b;
            short value;
            do {
                value = f_0bf7b0(d_1c2c64, 1, 0x3040048, 0, total, 0);
                s5 = value;
            } while (value < 0);
            if (total < s5) s5 = total;
            f_040880(ch, s5);
            total -= s5;
            f_040730(ch, total);
            if (((RC)(f_042350((struct hero *)(ch)))) == 9 && EQ(d_1bfaec, 1)) {
                if (f_0bf6f0(d_1c2c64, 0x3040047) == 1) {
                    f_043310((struct hero *)(ch), -10);
                    f_040730(ch, f_145760(3, 8));
                }
            }
        } else {
            f.t.q[1] = a;
            f_0bf730(d_1c2c64, 0x3040046);
            f_040880(ch, a);
        }
        if (f_0d3860() == 1) { f_0d2710(); f.second = 1; }
        else f.second = 0;
        f_04e470();
        d_1a0515 = 0xff;
        d_1a0514 = 0xff;
        f_0d5550(d_1c2bcc);
        if (f.second == 1) f_0d26e0();
    }
    f_1254a0((int)&f.t, 0);
}
//@ f_037de0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese kleine Hilfsmethode berechnet beim Stufenaufstieg die Magieresistenz des Helden über
 *   f_0449d0(ch, 0) neu und aktualisiert bei Bedarf die Bildschirmmaske.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Das Flag d_1c2198 signalisiert, ob eine Neuzeichnung des Charakterbogens erforderlich
 *   ist.
 === Ende Beschreibung === */
void Lv::f_037de0()
{
    struct Guard {
        int on;
        Guard() { if (f_0d3860() == 1) { f_0d2710(); on = 1; } else on = 0; }
        ~Guard() { if (on == 1) f_0d26e0(); }
    };
    f_0449d0(ch, 0);
    if (d_1c2198 != (short)0 && (signed char)f_043e30(ch) == (signed char)0) {
        Guard mg;
        f_04e470();
        d_1a0515 = 0xff;
        d_1a0514 = 0xff;
        f_0d5550(d_1c2bcc);
    }
}
//@ f_037e60  groesse 1664 B, 101 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode führt die automatische Computer-Steigerung aller Talente eines Helden durch. Sie
 *   arbeitet zunächst bis zu sechsmal die 25 Einträge umfassende klassenspezifische Talent-Zielwerttabelle
 *   (d_1bc898) ab und verteilt anschließend eventuell noch übrig gebliebene Talent-Steigerungspunkte auf
 *   zufällige Talente.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und hat keinen Rückgabewert.
 * - Wichtige Variablen: Die aus dem Archiv geladene Tabelle d_1bc898 enthält pro Heldenklasse (100 Bytes je
 *   Klasse) bis zu 25 Paare aus (Talent-ID, Zielwert).
 === Ende Beschreibung === */
void Lv::f_037e60()
{
    short done = 0;
    short saved = (signed char)f_043e30(ch);
    short i;
    short j;
    f_043e20(ch, 1);
    if (!f_037250(ch)) f_043350((struct hero *)(ch), 0);
    j = 0;
    i = 0;
    while (((RC)(f_043340((struct hero *)(ch)))) && done == (short)0) {
        s5 = *(short *)(d_1bc898 + ((RC)(f_042350((struct hero *)(ch)))) * 100 + i * 4);
        short v = f_03ad80(ch, s5);
        if (v != 18 && v < *(short *)(d_1bc898 + ((RC)(f_042350((struct hero *)(ch)))) * 100 + i * 4 + 2)) f_0372c0(s5);
        i++;
        if (24 < i) {
            j++;
            i = 0;
            if (5 < j) done = 1;
        }
    }
    while (((RC)(f_043340((struct hero *)(ch))))) f_0372c0(f_1457e0(0x33));
    f_043e20(ch, (signed char)saved);
}
//@ f_037fd0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Diese Methode führt die automatische Computer-Steigerung aller Zaubersprüche für magiebegabte
 *   Helden (Klassen 7..12) durch. Sie steigert in bis zu drei Durchläufen vorrangig die Haus- und Klassenzauber
 *   sowie die in den Tabellen d_1a09a6, d_1a09ac, d_1a0a8c, d_1a0ab0, d_1a0acc und d_1a0abe hinterlegten
 *   Vorzugszauber bis auf den Wert 11 und verteilt verbleibende Punkte danach zufällig auf alle Zauber.
 * - Eingaben und Rückgabe: Die Methode wird parameterlos auf Lv (this) aufgerufen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Je nach Klasse (7 = Hexe, 8 = Druide, 9 = Magier, 10 = Auelf, 11 = Firnelf, 12 =
 *   Waldelf) werden die zugehörigen Zauberkategorien in d_1a7270 und die klassenspezifischen Empfehlungslisten
 *   abgearbeitet.
 === Ende Beschreibung === */
void Lv::f_037fd0()
{
    int t519_39;
    short i = 0, n;
    int found = 0;
    int saved_ch = ch;
    for (i = 1; i < 0x56; i++) {
        if (((RC)(f_0430f0((struct hero *)(saved_ch), i))) < 18) {
            found = 1;
            goto found_done;
        }
    }
    found = 0;
found_done:
    if (!found) f_043300((struct hero *)(ch), 0);
    if (f_042a10((struct hero *)(ch))) {
        i = 1;
        n = 0;
        while (((RC)(f_0432f0((struct hero *)(ch)))) && n < 3) {
            n++;
            switch (((RC)(f_042350((struct hero *)(ch))))) {
            case 7:
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 2 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && (t519_39 = d_1a09a6[i]) != -1) {
                    f_037420(d_1a09a6[i]);
                    i++;
                }
                break;
            case 8:
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    int flag = d_1a7270[i * 14];
                    if (flag == 0 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && (t519_39 = d_1a09ac[i]) != -1) {
                    f_037420(d_1a09ac[i]);
                    i++;
                }
                break;
            case 9:
            {
                short item;
                i = 0;
                item = *(short *)(((RC)(f_043320((struct hero *)(ch)))) * 0x21 + d_1bc8a4 + 1);
                while (((RC)(f_0432f0((struct hero *)(ch)))) && item > 0) {
                    if (((RC)(f_0430f0((struct hero *)(ch), item))) < 11) f_037420(item);
                    item = *(short *)(((RC)(f_043320((struct hero *)(ch)))) * 0x21 + d_1bc8a4 + 1 + (i++) * 2);
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && *(short *)(i * 2 + d_1a0a8c[((RC)(f_043320((struct hero *)(ch))))]) != -1) {
                    if (((RC)(f_0430f0((struct hero *)(ch), *(short *)(i * 2 + d_1a0a8c[((RC)(f_043320((struct hero *)(ch))))])))) < 11)
                        f_037420(*(short *)(i * 2 + d_1a0a8c[((RC)(f_043320((struct hero *)(ch))))]));
                    i++;
                }
                i = 0;
                item = *(short *)(((RC)(f_043320((struct hero *)(ch)))) * 0x21 + d_1bc8a4 + 1);
                while (((RC)(f_0432f0((struct hero *)(ch)))) && item > 0) {
                    if (((RC)(f_0430f0((struct hero *)(ch), item))) < 11) f_037420(item);
                    item = *(short *)(((RC)(f_043320((struct hero *)(ch)))) * 0x21 + d_1bc8a4 + 1 + (i++) * 2);
                }
                break;
            }
            case 10:
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 3 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && (t519_39 = d_1a0ab0[i]) != -1) {
                    f_037420(d_1a0ab0[i]);
                    i++;
                }
                i = 1;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 3 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                break;
            case 11:
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 4 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && (t519_39 = d_1a0acc[i]) != -1) {
                    f_037420(d_1a0acc[i]);
                    i++;
                }
                i = 1;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 4 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                break;
            case 12:
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 5 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                i = 0;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && (t519_39 = d_1a0abe[i]) != -1) {
                    f_037420(d_1a0abe[i]);
                    i++;
                }
                i = 1;
                while (((RC)(f_0432f0((struct hero *)(ch)))) && i < 0x56) {
                    if (d_1a7270[i * 14] == 5 && ((RC)(f_0430f0((struct hero *)(ch), i))) < 11) f_037420(i);
                    i++;
                }
                break;
            }
        }
        while (((RC)(f_0432f0((struct hero *)(ch))))) f_037420(f_1457e0(0x55));
    }
}
