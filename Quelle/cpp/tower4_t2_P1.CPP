/* === Beschreibung (Katalog) ===
 * Einheit tower4_t2 (0x1332C0 - 0x133DE0)
 *
 * Überblick
 * Diese Einheit bildet den zweiten Teil von tower4.cpp für die vierte Ebene des Magierturms. Sie implementiert
 * die Mechanik der vier speziellen Türen, die sich nur mit dem "Achtkantinbus" (0x199) entriegeln lassen (und
 * diesen nach viermaligem Gebrauch zerstören), die drei passwortgeschützten Türen, die Gruppen- und
 * Gefangenenlogik der drei magischen Zellen sowie das große Endkampf-Finale der Ebene mit seinen zufälligen
 * Gegnerwellen.
 === Ende Beschreibung === */
// P3 7/11 gleich (suche.py 26.10.2026, Basis tower4_t2_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 5 gleich (vorher 5), Rest 405 (vorher 406)
// tower4_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x1332C0-0x133DE0
#include <string.h>
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
void f_014710(void *p);
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
struct Q12 { char b[12]; };
struct Q224 { char b[0xe0]; };
struct TE { short s58; unsigned short s5a; short s5c; short s5e; short s60; short s62; char *p64; char *p68; char *p6c; int i70; int i74; int i78; };
typedef short (*VF)(int, int);
typedef short (*VF3)(int, int, int);
extern void f_1332a0(void);
int f_05f190(int p1, int p2, int p3);
int f_05f580(int p1);
int f_05f560(int p1);
int f_05f470(int p1, int p2);
int f_05f4f0(int p1, int p2);
int f_05f280(int p1, int p2);
int f_05f220(int p1, int p2);
int f_039ac0(int p1, int p2);
int f_039320(int p1, int p2);
int f_0d4a60(int p1);
int f_0bf730(int p1, int p2);
short f_0de820(int p1);
int f_0dd4a0(int p1, int p2);
unsigned short f_0de8c0(int p1);
int f_0dd6d0(int p1, int p2, int p3);
int f_0dd100(int p1, int p2);
int f_0dd640(int p1, int p2);
int f_0e93f0(int p1, int p2, int p3);
int f_0e9300(int p1, int p2, int p3);
int f_133fe0(int p1, int p2);
unsigned short f_0de070(int p1, int p2, int p3);
int f_060740(int p1, int p2);
int f_155934();
int f_1454d0(int p1);
short f_0bfea0(int p1, int p2, int p3);
int f_144bf0(int p1, int p2);
short f_1457e0(int p1);
short f_145760(int p1, int p2);
int f_046d10(int p1, int p2);
int f_046de0(int p1);
int f_046d90(int p1, int);
int f_0697c0(int p1, int p2, int p3);
int f_0d13b0(int p1, int p2);
int f_0d1b20(int p1);
int f_038ba0(int p1);
int f_0d1440(int p1);
int f_0d1430(int p1, int p2);
#pragma aux f_0d1430 modify exact []; // Leerer Destruktor, Original RET

int f_0dcbb0(int p1, int p2);
int f_057220(int p1, int p2, int p3);
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_060a70();
int f_0bf6f0(int p1, int p2);
unsigned short f_133cd0(int p1);
int f_133760(int p1, int p2);
int f_1333c0(int p1, int p2);
extern const char d_1a8d38[];
extern TE d_1a8d58[];
extern short d_1a8d34;
extern short d_1a8d36;
extern short d_1a8dc4[];
extern char d_1a8dc6[];
extern int d_1a9820;
extern int d_1bd91c;
extern short d_1bd922;
extern int d_1bfaec;
extern int d_1c0004[];
extern volatile signed char d_1c0d98; // erzwingt direktes inc BYTE PTR in f_1332c0
extern volatile signed char d_1c0d9c; // erzwingt direktes Laden/Inkrementieren in f_133650/f_133890/f_1339d0
extern signed char d_1c0da0;
extern unsigned short d_1c0da4;
extern signed char d_1c0da8;
extern signed char d_1c0dac;
extern signed char d_1c0db0;
extern signed char d_1c0dd0;
extern char d_1c21b4[];
extern char d_1c23a8[];
extern char d_1c240c[];
extern char d_1c299c[];
extern char d_1c2c00[];
extern char d_1c2c64[];
extern char d_1c2edc[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
#define I(p, o) (*(int *)((int)(p) + (o)))
#define EQI(x,v) (((x)==(v))?1:0)
#define LTI(x,v) (((x)<(v))?1:0)
#define Z0(c) EQI(c,0)
#define LT5(x) LTI(x,5)
#define PT short
#define NEWQ(line) (int)new (mark(d_1a8d38, line)) Q12
#define E(i) d_1a8d58[(short)(i)]

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_1332c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die verschlossene Tür 0x1f41 (Schlosskennung 0x4e): Ist sie noch verschlossen und
 *   verriegelt, prüft die Funktion über f_1332a0, ob ein Held den "Achtkantinbus" (0x199) bei sich trägt; falls
 *   ja, schließt dieser Held (oder bei dessen Handlungsunfähigkeit der Held mit dem höchsten Wert in
 *   Schlösserknacken 0x30) die Tür unter Anzeige von 0x27000139 auf (f_05f470), erhöht den Benutzungszähler
 *   d_1c0d98 und öffnet die Tür (f_05f280).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q ist das temporäre Türobjekt für 0x1f41, a (b) der Held mit dem Achtkantinbus, und
 *   d_1c0d98 zählt mit, wie viele Schlösser bereits mit dem Achtkantinbus geöffnet wurden.
 === Ende Beschreibung === */
void f_1332c0(void)
{
    int t = NEWQ(0x3e6);
    int q = t ? f_05f190(t, 0x4e, 0x1f41) : t;
    if (Z0(f_05f580(q))) {
        if (f_05f560(q)) {
            int a = f_039ac0(d_1c0004[0], (int)f_1332a0);
            int b = a;
            if (a) {
                extern void f_125400(void *, void *, void *, void *);
                extern void f_1254a0(void *);
                char obj[0x3a];
                f_125400(obj, d_1c349c, d_1c3870, d_1c3498);
                if (f_0d4a60(a) == 0) b = f_039320(d_1c0004[0], 0x30);
                *(int *)(*(int *)(obj + 4) + 4) = b;
                f_0bf730((int)d_1c2c64, 0x27000139);
                ++d_1c0d98;
                f_05f470(q, 0);
                f_1254a0(obj);
            }
        }
    }
    f_05f280(q, 0);
    if (q) f_014710((void *)f_05f220(q, 0));
}
//@ f_1333c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft als Gruppen-Filterfunktion für eine nicht-aktive Teilgruppe (p1 != d_1c0004) auf der
 *   vierten Turmebene (0x16), ob diese auf einem der beiden zu einer Zelle gehörenden Felder (*(unsigned short
 *   *)(p2 + 0x20) oder *(unsigned short *)(p2 + 0x22)) steht.
 * - Eingaben: Ein Zeiger auf die zu prüfende Teilgruppe (p1) sowie ein Zeiger auf den Tabelleneintrag der
 *   jeweiligen Zelle (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn sich die Teilgruppe auf einem der beiden Zellenfelder befindet, sonst 0.
 * - Wichtige Variablen: r speichert das Ergebnis der Positionsabfragen (f_0dd4a0).
 === Ende Beschreibung === */
int f_1333c0(int p1, int p2)
{
    int r = 0;
    if (p1 != d_1c0004[0]) {
        if (f_0de820(p1) == 0x16) {
            r = f_0dd4a0(p1, *(unsigned short *)(p2 + 0x20));
            if (r == 0) r = f_0dd4a0(p1, *(unsigned short *)(p2 + 0x22));
        }
    }
    return r;
}
//@ f_133410
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet die drei äußeren Zellentüren (p2 = 0, 1, 2, Objekte 0x1f42-0x1f44 über die Tabelle
 *   d_1a8d58): Ist die Tür noch verriegelt und besitzt die Gruppe den "Achtkantinbus" (0x199), wird sie damit
 *   aufgeschlossen und der Zähler d_1c0d98 erhöht; beim vierten aufgeschlossenen Schloss (d_1c0d98 >= 4)
 *   zerbricht bzw. verschwindet der Achtkantinbus (f_0dd100(..., 0x199)) mit dem Zusatztext 0x2700013b.
 *   Anschließend lässt sich die Tür nur dann öffnen, wenn keine andere Teilgruppe die Zelle von innen blockiert
 *   (f_1333c0), und beim Öffnen wird das zugehörige 3D-Objekt (s5a) umgeschaltet.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1) sowie der Index der Zellentür (p2: 0, 1 oder 2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: E(p2) adressiert den jeweiligen Tabelleneintrag in d_1a8d58; c_1c0d98 (d_1c0d98) zählt
 *   die Nutzungen des Achtkantinbus bis zur Zerstörung bei >= 4, und fl verhindert das Öffnen, falls eine andere
 *   Teilgruppe auf den Zellenfeldern steht.
 === Ende Beschreibung === */
void f_133410(int p1, PT p2)
{
    int t = NEWQ(0x431);
    int q = t ? f_05f190(t, E(p2).s5e, E(p2).s58) : t;
    if (Z0(f_05f580(q))) {
        if (f_05f560(q)) {
            int a = f_039ac0(d_1c0004[0], (int)f_1332a0);
            int b = a;
            if (a) {
                extern void f_125400(void *, void *, void *, void *);
                extern void f_1254a0(void *);
                char obj[0x3a];
                f_125400(obj, d_1c349c, d_1c3870, d_1c3498);
                if (f_0d4a60(a) == 0) b = f_039320(d_1c0004[0], 0x30);
                *(int *)(*(int *)(obj + 4) + 4) = b;
                extern signed char c_1c0d98;
                #pragma aux c_1c0d98 "d_1c0d98";
                if (EQ(++c_1c0d98, 1)) {
                    f_0e93f0((int)d_1c38b0, (int)d_1c21b4, 0x27000139);
                } else {
                    f_0e93f0((int)d_1c38b0, (int)d_1c21b4, 0x2700013a);
                    int more = c_1c0d98 >= 4;
                    if (more) {
                        f_0e9300((int)d_1c38b0, (int)d_1c21b4, 0x2700013b);
                        f_0dd100(d_1c0004[0], 0x199);
                    }
                }
                f_0bf730((int)d_1c2c64, f_133fe0((int)d_1c3498, (int)d_1c21b4));
                ((int (*)(int))f_05f470)(q);
                ((void (*)(void *, int))f_1254a0)(obj, 0);
            }
        }
    }
    int r4 = Z0(f_05f580(q));
    int fl = 1;
    if (r4 == 1) {
        if ((short)f_0de070((int)f_1333c0, (int)d_1c240c, (int)&E(p2)) > 0) fl = 0;
    }
    if (fl == 1) {
        f_05f280(q, 0);
        signed char val = *E(p2).p6c;
        if (val == 1 && r4 == 1) {
            if (f_05f580(q) == r4) {
                f_060740(E(p2).s5a, 1);
                *E(p2).p6c = 0;
                f_155934();
            }
        }
    }
    if (q) f_014710((void *)f_05f220(q, 0));
}
//@ f_133650
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die drei passwortgeschützten Innentüren (p2 = 0, 1, 2, Objekte 0x1f45-0x1f47): Ist
 *   die Tür noch geschlossen, wird das erwartete Lösungswort (E(p2).i70) geladen und der Spieler über ein
 *   Texteingabefeld (E(p2).i74) nach dem Passwort gefragt; bei korrekter Eingabe öffnet sich die Tür (f_05f280),
 *   während sich bei falscher Eingabe mit 50 % Chance der Zähler d_1c0d9c (bis maximal 5) erhöht.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1) sowie der Index der Passworttür (p2: 0, 1 oder 2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: buf enthält das in Großbuchstaben umgewandelte Lösungswort der jeweiligen Tür aus
 *   d_1a8d58[p2], das mit der Spielereingabe d_1c299c verglichen wird.
 === Ende Beschreibung === */
void f_133650(int p1, PT p2)
{
    char buf[20];
    int t = NEWQ(0x4aa);
    int q = t ? f_05f190(t, 0, E(p2).s5c) : t;
    if (Z0(f_05f580(q))) {
        f_0e93f0((int)d_1c38b0, (int)buf, E(p2).i70);
        f_1454d0((int)buf);
        if (f_0bfea0((int)d_1c2c64, (short)strlen(buf), E(p2).i74) == -1) goto done;
        if (f_144bf0((int)buf, (int)d_1c299c) != 0) {
            if (LT5(d_1c0d9c)) {
                if (f_1457e0(100) < 0x32) ++d_1c0d9c;
            }
            goto done;
        }
    }
    f_05f280(q, 0);
done:
    if (q) f_014710((void *)f_05f220(q, 0));
}
//@ f_133760
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft für eine nicht-aktive Teilgruppe (p1 != d_1c0004) auf der vierten Turmebene (0x16), ob
 *   sie auf dem Auslöserfeld einer Zelle (*(unsigned short *)(p2 + 0x20)) steht, und versetzt diese Teilgruppe
 *   in diesem Fall unter Beibehaltung ihrer Blickrichtung zum Sammelpunkt 0xcd (f_0dd6d0).
 * - Eingaben: Ein Zeiger auf die zu prüfende Teilgruppe (p1) sowie ein Zeiger auf den Tabelleneintrag der Zelle
 *   (p2).
 * - Rückgabewert: Gibt 1 zurück, wenn die Teilgruppe auf dem Feld stand und wegteleportiert wurde, sonst 0.
 * - Wichtige Variablen: v speichert die aktuelle Blickrichtung (f_0de8c0) der versetzten Teilgruppe.
 === Ende Beschreibung === */
int f_133760(int p1, int p2)
{
    int r = 0;
    if (p1 != d_1c0004[0]) {
        if (f_0de820(p1) == 0x16) {
            if (f_0dd4a0(p1, *(unsigned short *)(p2 + 0x20))) {
                unsigned short v = f_0de8c0(p1);
                f_0dd6d0(p1, 0xcd, v);
                r = 1;
            }
        }
    }
    return r;
}
//@ f_1337c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wird beim Betreten des inneren Auslösers einer der drei Zellen (p2 = 0, 1, 2) aufgerufen:
 *   Falls die zugehörige Zellentür (E(p2).s58) offen steht, schlägt sie hinter der Gruppe zu (f_05f4f0), das
 *   3D-Objekt (s5a) und das Statusflag (*E(p2).p6c = 1) werden umgeschaltet, die Meldung 0x27000141 ausgegeben
 *   und jede auf dem äußeren Zellenfeld wartende Teilgruppe über f_133760 nach 0xcd teleportiert.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1) sowie der Zellenindex (p2: 0, 1 oder 2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q ist das Türobjekt der Zelle p2; *E(p2).p6c speichert den Verriegelungszustand der
 *   Zelle.
 === Ende Beschreibung === */
void f_1337c0(int p1, PT p2)
{
    int t = NEWQ(0x50a);
    int q = t ? f_05f190(t, 0, E(p2).s58) : t;
    if (f_05f580(q)) {
        f_060740(E(p2).s5a, 1);
        *E(p2).p6c = 1;
        f_05f4f0(q, 0);
        f_0bf730((int)d_1c2c64, 0x27000141);
        f_0de070((int)f_133760, (int)d_1c23a8, (int)&E(p2));
    }
    if (q) f_014710((void *)f_05f220(q, 0));
}
//@ f_133890
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Verwaltet die Untersuchung und den Kampf im Inneren einer der drei Zellen (p2 = 0, 1, 2):
 *   Ist der dortige Gegner (E(p2).s62) noch nicht besiegt (*E(p2).p68 == 0), wird eine Meldung (0x2700013f) mit
 *   der aktuellen Stufe d_1c0d9c + 1 ausgegeben und der Kampf s62 gestartet; nach dem Sieg wird das Flag
 *   *E(p2).p68 = 1 gesetzt und die zugehörige Wand- oder Truheninteraktion (f_046de0) freigegeben.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1) sowie der Zellenindex (p2: 0, 1 oder 2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q verweist auf das interaktive Raumobjekt (E(p2).s60), *d_1a8d58[i].p68 merkt sich den
 *   Kampfsieg in dieser Zelle, und d_1bd922 übergibt den Zahlenwert d_1c0d9c + 1 an den Textplatzhalter.
 === Ende Beschreibung === */
void f_133890(int p1, PT p2)
{
    struct Byte { static int get(char *p) { signed char c = *p; return c; } };
    int t = (int)new (mark(d_1a8d38, 0x533)) Q12;
    int q = t ? f_046d10(t, E(p2).s60) : t;
    int i = (short)p2;
    if (Byte::get(d_1a8d58[i].p68) == 0) {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        signed char v = d_1c0d9c + 1;
        d_1bd91c = 1;
        d_1bd922 = v;
        *(volatile short *)(obj.slots[4] + 2) = d_1bd922; // erzwingt Speichern in d_1bd922 und Nachladen statt Registerweiterreichung
        int text_call(int, int, int);
        #pragma aux text_call "f_0bf730" parm [eax] [edx] [ebx] value [eax] modify exact [eax ecx edx];
        int zero = 0;
        text_call((int)d_1c2c64, 0x2700013f, zero);
        if ((*(VF3 **)(p1 + 8))[0](p1, d_1a8d58[i].s62, zero) == 0) {
            f_0697c0(p1 + 2, d_1a8d58[i].s62, 0);
            *d_1a8d58[i].p68 = 1;
        }
    }
    if (Byte::get(E(p2).p68) == 1) f_046de0(q);
    if (q) f_014710((void *)f_046d90(q, 0));
}
//@ f_1339d0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Kapselt als parametrisierte Hilfsfunktion exakt die Teleporterlogik der drei Zellen
 *   (f_132a90, f_132c00, f_132d70): Sie gibt 0x27000140 aus, setzt das Zellenflag *E(p2).p64 = 1, teleportiert
 *   die Gruppe zu 0x259 (wenn alle drei Flags d_1c0da0, d_1c0da4, d_1c0da8 aktiv sind) oder zu 0xcd (mit Kampf
 *   100 ab zwei aktiven Flags) und erhöht mit 50 % Chance d_1c0d9c.
 * - Eingaben: Ein Zeiger auf die Dungeon-Ebene (p1) sowie der Zellenindex (p2: 0, 1 oder 2).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: *E(p2).p64 zeigt auf das jeweilige Zellenflag (d_1c0da0, d_1c0da4 oder d_1c0da8).
 === Ende Beschreibung === */
void f_1339d0(int p1, PT p2)
{
    short c;
    int ok;
    short s;
    f_0bf730((int)d_1c2c64, 0x27000140);
    *E(p2).p64 = 1;
    if (((signed char)d_1c0da0 == 1 ? 1 : 0) &&
        ((signed char)d_1c0da4 == 1 ? 1 : 0) &&
        ((signed char)d_1c0da8 == 1 ? 1 : 0)) {
        f_0dd640(d_1c0004[0], 0x259);
    } else {
        f_0dd640(d_1c0004[0], 0xcd);
        int q = p1;
        ok = 0;
        if (((int)d_1c0dd0 == 0 ? 1 : 0)) {
            c = 0;
            if (((int)d_1c0da0 == 1 ? 1 : 0)) c++;
            if (((int)(signed char)d_1c0da4 == 1 ? 1 : 0)) c++;
            if (((int)d_1c0da8 == 1 ? 1 : 0)) c++;
            if ((int)c >= 2) ok = 1;
        }
        if (ok && (s = (**(VF3 **)(q + 8))(q, 100, 0)) != 2) {
            f_0697c0(q + 2, 100, 0);
            d_1c0dd0 = 1;
        }
    }
    if ((d_1c0d9c < 5 ? 1 : 0) && (s = f_1457e0(100)) < 0x32)
        d_1c0d9c = d_1c0d9c + 1;
}
//@ f_133b30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Steuert die dramatische Endsequenz auf der vierten Turmebene: Es wird ein zeitgesteuertes
 *   Aktions- bzw. Rätselobjekt (q, Schwierigkeitsgrad 0x28 bzw. 0x1b je nach d_1bfaec) angelegt und in einer
 *   Schleife abwechselnd die Hauptaktion (f_0d1440) und zufällige Gegnerwellen (f_133cd0) ausgeführt, bis dem
 *   Spieler die endgültige Ausschaltung der Anlage gelingt (r == 0), woraufhin alle sechs Wellenkämpfe als
 *   erledigt markiert werden, der Siegestext 0x2700014c erscheint, die Gruppe 40 Abenteuerpunkte (0x28) erhält
 *   und das Abschlussvideo 0x803002d abgespielt wird.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: q (u) ist das 0xe0 Bytes große Steuerungsobjekt für das Finale; fa und fb steuern den
 *   Wechsel zwischen dem Voranschreiten am Mechanismus (f_0d1440) und den Zwischenkämpfen (f_133cd0), und
 *   d_1c0dac = 1 markiert den Gesamtsieg.
 === Ende Beschreibung === */
void f_133b30(int p1)
{
    int q;
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    short n;
    if (EQI((signed char)d_1bfaec, 0)) n = 0x28; else n = 0x1b;
    int t = (int)new (mark(d_1a8d38, 0x5b6)) Q224;
    int u = t ? f_0d13b0(t, n) : t;
    q = u;
    int fa, fb;
    f_0d1b20(u);
    fa = 1;
    *(int *)(obj.slots[0] + 4) = f_038ba0(d_1c0004[0]);
    f_0bf730((int)d_1c2c64, 0x2700014b);
    fb = 0;
    d_1c0db0 = 1;
    do {
        p1=(p1&0)?0:p1; // erhoeht Schleifengewicht von p1 gegenueber q (edi statt [esp+0x3c])
        if (fa == 1) {
            int r = f_0d1440(q);
            fa = 0;
            if (r == 0) {
                int i = 0;
                d_1c0dac = 1;
                do {
                    f_0697c0(p1 + 2, d_1a8dc4[(short)i * 3], 0);
                    i++;
                } while ((short)i < (short)6);
                f_0bf730((int)d_1c2c64, 0x2700014c);
                f_0dcbb0(d_1c0004[0], 0x28);
                f_057220((int)d_1c2c00, 0x803002d, 0);
                fb = 1;
            }
        }
        if (fb == (short)0) {
            d_1bd91c = 1;
            switch (f_133cd0(p1)) {
            case 2: fb = 1; break;
            case 3: fa = 1; break;
            }
        }
    } while (!fb);
    { int ptr=q; if(ptr) { f_0d1430(ptr,0); f_014710((void*)ptr); } }
}
//@ f_133ca0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Markiert alle sechs in der Tabelle d_1a8dc4 hinterlegten Wellenkämpfe der Endsequenz im
 *   Ebenenstatus (f_0697c0) als abgeschlossen.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Die Schleifenvariable i (0 bis 5) liest die sechs Kampfkennungen im Schrittabstand 3 aus
 *   d_1a8dc4.
 === Ende Beschreibung === */
void f_133ca0(int p1)
{
    short i = 0;
    do {
        f_0697c0(p1 + 2, d_1a8dc4[i * 3], 0);
        i++;
    } while (i < (short)6);
}
//@ f_133cd0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Wählt während der Endsequenz (f_133b30) per Zufall (0 bis 5) eine der sechs Gegnerwellen aus
 *   d_1a8dc4 aus (wobei keine der beiden zuletzt gespielten Wellen d_1a8d34 und d_1a8d36 direkt wiederholt
 *   wird), spielt den Soundeffekt 0x270019 ab, gibt die Angriffsmeldung 0x27000153 mit dem jeweiligen
 *   Gegnernamen (msg) aus und startet den Kampf (a); nach dem Sieg wird der Spieler gefragt (0x27000154), ob er
 *   weiter am Mechanismus arbeiten möchte.
 * - Eingaben: Ein Zeiger auf die aktuelle Dungeon-Ebene (p1).
 * - Rückgabewert: Gibt 3 zurück, wenn der Kampf gewonnen wurde und der Spieler am Mechanismus weitermachen will,
 *   1 bei Ablehnung oder 2 bei Niederlage/Abbruch.
 * - Wichtige Variablen: a ist die ausgewählte Kampfkennung, msg die zugehörige Textkennung aus d_1a8dc6, und
 *   d_1a8d34/d_1a8d36 speichern die letzten beiden Wellen zur Vermeidung unmittelbarer Wiederholungen.
 === Ende Beschreibung === */
unsigned short f_133cd0(int p1)
{
#pragma aux f_147323 modify [esp];
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    unsigned short r = 0;
    short a;
    int msg;
    do {
        short k = f_145760(0, 5);
        a = d_1a8dc4[k * 3];
        msg = *(int *)(d_1a8dc6 + k * 6);
    } while (a == d_1a8d34 || a == d_1a8d36);
    d_1a8d36 = d_1a8d34;
    *(int *)(obj.slots[3] + 4) = msg;
    d_1a8d34 = a;
    int snd = d_1a9820;
    f_147323((int)d_1c2edc, 0x270019, 0x7fff, 0x8000, snd, 0, 1);
    f_0bf730((int)d_1c2c64, 0x27000153);
    d_1bd91c = 1;
    switch ((unsigned short)((VF3 *)*(int *)(p1 + 8))[0](p1, a, 0)) {
    case 0:
        f_060a70();
        if (f_0bf6f0((int)d_1c2c64, 0x27000154) == 1) r = 3; else r = 1;
        break;
    case 2:
        r = 2;
        break;
    }
    return r;
}
