/* === Beschreibung (Katalog) ===
 * Einheit gz_0452a0 (0x0452a0 - 0x045b70)
 *
 * Überblick
 * Die Einheit gz_0452a0 ergänzt charact1 um weitere Berechnungs- und Hilfsfunktionen der Heldenklasse:
 * Kopfrüstungsschutz, Aktionspunkte (BP) im Kampf unter Berücksichtigung von Traglast und Zaubern, permanente
 * und temporäre Eigenschaftsänderungen, effektive Attacke- und Paradewerte, das Speichern und Laden eines
 * CHAR-Blocks im Spielstand, die Suche nach Gegenständen (auch im Magier-Zauberstab), Ausrüstungsbeschränkungen,
 * den Lichtradius des Helden sowie Konstruktoren/Destruktoren einer Text-/Font-Hilfsklasse (AD).
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
// OPT -4r -oneatx -zp1 -s -j
// P3 13/18 gleich (suche.py 26.10.2026, Basis gz_0452a0_P1.CPP)
// gz_0452a0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0452A0-0x045B70
#include <string.h>
typedef RivaTextContextData PL;
struct Q { int x; };
struct AD { char *vp; int a; int b; short s0c; short s0e; short s10; char *p12; char buf[0x400]; char *p416; char *p41a; short s41e; };
int f_030fe0(int p1);
short f_03d860(int p1, int p2, int p3);
signed char f_042350(int p1);
signed char f_042400(int p1);
signed char f_0427e0(int p1);
signed char f_042a40(int p1, int p2);
short f_042a60(int p1, int p2);
int f_042b50(int p1, int p2);
short f_043170(int p1);
signed char f_0432d0(int p1);
int f_043cb0(int p1);
int f_043cc0(int p1);
signed char f_043e30(int p1);
int f_0449d0(int p1, int p2);
int f_044b60(int p1);



int f_0bf730(void *p1, int p2);
int f_0ce7c0(void *p1);
int f_0ce7e0(void *p1, int p2);
short f_0d4aa0(int p1, int p2);
int f_0e93f0(void *p1, void *p2, int p3);
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
short f_149360(int p1, int p2);
int f_144cb6(int h, void *buf, unsigned n);
int f_144e8b(int h, void *buf, unsigned n);
void f_145300(void *p, int c, unsigned n);
void *f_145234(void *p, void *d);
void f_145254();
extern signed char d_1a47ac[];
extern int d_1a4388[];
extern short d_1a933c[];
extern int d_1b6648[];
extern char d_1bacf4[];
extern char d_1bad08[];
extern char d_1bad24[];
extern int d_1c0834;
extern short d_1c2140;
extern volatile short d_1c2198;
extern int d_1c2a80;

extern int d_1c2c64;
extern int d_1c3498;
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c38b0;
void f_045430(int p1, short p2, signed char p3);
short f_0458b0(int p1);
AD *f_045a80(AD *p, int fl);

//@ f_0452a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt den aktuellen Rüstungsschutz des am Kopf (Inventarslot 0) getragenen Helms des
 *   Helden p1 abzüglich bereits erlittener Rüstungsschäden (f_042b50).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den verbleibenden
 *   Helm-Rüstungsschutz als int zurück (0, wenn kein Helm getragen wird).
 * - Wichtige Variablen: Liest Slot 0 über f_042a60, die Gegenstandsdatenbank d_1c2c40 und die RS-Tabelle
 *   d_1a47ac.
 === Ende Beschreibung === */
int f_0452a0(int p1)
{
    int s = f_042a60(p1, 0);
    union { int n; short w; } r;
    r.n = 0;
    if (s > 0) {
        int off = s * 4;
        int t_69 = ((RivaItemDefinition*)(*(int *)(off + ((int)d_1c2c40))))->f_0a79b0();
        if (t_69 != 0) {
            r.w = d_1a47ac[((signed char)(((RivaItemDefinition*)(*(int *)(off + ((int)d_1c2c40))))->f_0a78a0())) * 2];
            r.n = r.n - f_042b50(p1, 0);
        }
    }
    return r.n;
}

//@ f_045300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Bewegungspunkte (BP, Grundwert 8) des Helden p1 für den Taktikkampf in
 *   Abhängigkeit von seiner Körperkraft (KK, Attribut 6) und seiner getragenen Last (f_043170): Ab 50 * KK Unzen
 *   sinkt der Wert auf 7, ab 75 * KK um 2, ab 100 * KK um weitere 2 und ab 110 * KK auf 1. Ein aktiver
 *   *Axxeleratus* (f_0427e0) erhöht die BP um +4, Gegenstand 0x154 senkt sie um -1, und Gegenstand 0x185
 *   (Siebenmeilenstiefel) verdoppelt sie bis zum Höchstwert 12.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt die verfügbaren Bewegungspunkte (1
 *   bis 12) als int zurück.
 * - Wichtige Variablen: Liest KK über f_042a40(p1, 6), die Traglast über f_043170 und prüft Sondergegenstände
 *   über f_0d4aa0.
 === Ende Beschreibung === */
int f_045300(int p1)
{
    signed char c = f_042a40(p1, 6);
    short s4 = c;
    int r = 8;
    if (f_043170(p1) >= c * 0x32) r = 7;
    if (f_043170(p1) >= s4 * 0x4b) r = r - 2;
    if (f_043170(p1) >= s4 * 100) r = r - 2;
    if (f_0427e0(p1)) r = r + 4;
    if (f_043170(p1) < s4 * 0x6e) { } else r = 1;
    if ((short)r > 1) {
        if (f_0d4aa0(p1, 0x154) != -1) r = r - 1;
    }
    if (f_0d4aa0(p1, 0x185) != -1) r = r * 2;
    if ((short)r > 0xc) r = 0xc;
    return r;
}

//@ f_0453e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert sowohl den permanenten Normalwert (p1 + p2 * 3 + 0x46) als auch über f_045430 den
 *   aktuellen Wert einer Eigenschaft p2 des Helden p1 dauerhaft um p3 (begrenzt auf den Bereich 1 bis 20).
 *   *(Hinweis: Enthält im Unterlaufzweig sum < 1 einen Vorzeichenfehler p3 = e[0x46] - 1 statt 1 - e[0x46],
 *   siehe Fehlerliste).*
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), den Attribut-Index (p2) sowie die
 *   permanente Änderung (p3) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert p->attrib[p2].normal (Offset 0x46) und ruft anschließend f_045430 auf.
 === Ende Beschreibung === */
void f_0453e0(int p1, short p2, signed char p3)
{
    signed char *e = (signed char *)(p1 + p2 * 3);
    int sum = p3 + e[0x46];
    if (sum > 0x14) p3 = 0x14 - e[0x46];
    else if (sum < 1) p3 = e[0x46] - 1;
    *(signed char *)(p1 + p2 * 3 + 0x46) += p3;
    f_045430(p1, p2, p3);
}

//@ f_045430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den aktuellen Wert der Eigenschaft p2 (p1 + p2 * 3 + 0x47) des Helden p1 um p3, gibt
 *   bei Helden der aktiven Gruppe (oder in der Herberge) eine entsprechende Statusmeldung (0x20000198 für
 *   Gewinn, 0x20000199 für Verlust) aus und berechnet bei Änderungen von IN/KK/GE den AT/PA-Basiswert (f_044b60)
 *   beziehungsweise bei MU/KL/AG die Magieresistenz (f_0449d0) neu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), den Attribut-Index (p2) sowie die Änderung
 *   (p3) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert p3 auf *(signed char*)(p1 + p2 * 3 + 0x47) und setzt bei geöffnetem
 *   Charakterblatt d_1c2198 = 1.
 === Ende Beschreibung === */
void f_045430(int p1, short p2, signed char p3)
{
    PL pl;
    struct Q lk;
    int code;
    f_125400(&pl, &d_1c349c, &d_1c3870, &d_1c3498);
    f_0ce7c0(&lk);
    pl.tables.p[1] = p1;
    if (f_030fe0(p1) == 1 || f_043e30(p1) == 5) {
        if (p3 > 0) {
            pl.tables.tail.short_numbers[1] = p3;
            pl.tables.tail.numbers[1] = p2 + 0x20000143;
            pl.tables.tail.numbers[2] = p3 > 1 ? 0x20000164 : 0x20000194;
            code = 0x20000198;
        } else {
            pl.tables.tail.short_numbers[1] = p3;
            pl.tables.tail.short_numbers[1] = -p3;
            pl.tables.tail.numbers[1] = p2 + 0x20000143;
            pl.tables.tail.numbers[2] = p3 < -1 ? 0x20000164 : 0x20000194;
            code = 0x20000199;
        }
        if (f_043e30(p1) == 5) f_0e93f0(&d_1c38b0, &d_1c0834, code);
        else f_0bf730(&d_1c2c64, code);
    }
    *(signed char *)(p2 * 3 + 0x47 + p1) += p3;
    if (p2 == 6 || p2 == 5 || p2 == 4) f_044b60(p1);
    int index = p2;
    if (index == 1 || index == 0 || index == 7) f_0449d0(p1, 0);
    if (d_1c2a80 == 0x30000) d_1c2198 = 1;
    f_0ce7e0(&lk, 0);
    f_1254a0(&pl, 0);
}

//@ f_0455b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den aktuellen Wert der Eigenschaft p2 (p1 + p2 * 3 + 0x47) ohne Textmeldung direkt auf
 *   p3 und aktualisiert bei Bedarf den AT/PA-Basiswert (f_044b60) oder die Magieresistenz (f_0449d0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1), den Attribut-Index (p2) sowie den neuen
 *   Eigenschaftswert (p3) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt *(signed char*)(p1 + 0x47 + p2 * 3).
 === Ende Beschreibung === */
void f_0455b0(int p1, short p2, signed char p3)
{
    *(signed char *)(p1 + 0x47 + p2 * 3) = p3;
    if (p2 == 6 || p2 == 5 || p2 == 4) f_044b60(p1);
    if (p2 == 1 || p2 == 0 || p2 == 7) f_0449d0(p1, 0);
    if (d_1c2a80 == 0x30000) d_1c2198 = 1;
}

//@ f_045610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den aktuell im Kampf wirksamen Attackewert (AT) des Helden p1 mit seiner
 *   ausgerüsteten Waffe nach der Formel AT[weapon_type] + at_mod + attack_type - rs_be / 2 (nach unten begrenzt
 *   auf 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den effektiven Attackewert als
 *   short zurück.
 * - Wichtige Variablen: Liest weapon_type (0x8a), at (0x7a), at_mod (0x88), attack_type (0x8b) und die
 *   Rüstungsbehinderung rs_be (0x44).
 === Ende Beschreibung === */
short f_045610(int p1)
{
    struct HeroAt {
        char pad00[0x44]; signed char rs_be;
        char pad45[0x35]; signed char at[7]; signed char pa[7];
        signed char at_mod, pa_mod, weapon_type, attack_type;
    };
    struct HeroAt *h = (struct HeroAt *)p1;
    short val;
    val = h->weapon_type < 7 ? h->at[h->weapon_type] + h->at_mod + h->attack_type - h->rs_be / 2 :
        h->at[0] + h->at_mod + h->attack_type - h->rs_be / 2;
    if (val < 0) val = 0;
    return val;
}

//@ f_045660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den aktuell im Kampf wirksamen Paradewert (PA) des Helden p1 mit seiner
 *   ausgerüsteten Waffe nach der Formel PA[weapon_type] + pa_mod - attack_type - (rs_be + 1) / 2 (bei ungerader
 *   Behinderung geht der größere Teil zu Lasten der Parade; nach unten begrenzt auf 0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den effektiven Paradewert als
 *   short zurück.
 * - Wichtige Variablen: Liest weapon_type (0x8a), pa (0x81), pa_mod (0x89), attack_type (0x8b) und rs_be (0x44).
 === Ende Beschreibung === */
short f_045660(int p1)
{
    short value;
    value=*(signed char *)(p1+0x8a)<7 ? *(signed char *)(*(signed char *)(p1 + 0x8a) + 0x81 + p1) + *(signed char *)(p1 + 0x89) - *(signed char *)(p1 + 0x8b) - *(signed char *)(p1 + 0x44) / 2 : *(signed char *)(p1 + 0x81) + *(signed char *)(p1 + 0x89) - *(signed char *)(p1 + 0x8b) - *(signed char *)(p1 + 0x44) / 2;
    if ((*(unsigned char *)(p1+0x44)&1)!=0) value--;
    if ((short)value<0) value=0;
    return value;
}
//@ f_0456e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den waffenunabhängigen Attackewert einer bestimmten Waffengattung p2 (0 bis 6) unter
 *   Berücksichtigung der Kampfweise (attack_type) und der halben Behinderung (rs_be / 2), jedoch ohne den
 *   individuellen Waffenmodifikator at_mod (für die Anzeige auf dem Charakterblatt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie den Waffengattungsindex (p2) und gibt
 *   den Attackewert als int zurück.
 * - Wichtige Variablen: Liest at[p2] (0x7a + p2), attack_type (0x8b) und rs_be (0x44).
 === Ende Beschreibung === */
int f_0456e0(int p1, short p2)
{
    int r = *(signed char *)(p2 + 0x7a + p1) + *(signed char *)(p1 + 0x8b) - *(signed char *)(p1 + 0x44) / 2;
    if ((short)r < 0) r = 0;
    return r;
}

//@ f_045710
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den waffenunabhängigen Paradewert einer bestimmten Waffengattung p2 (0 bis 6) unter
 *   Berücksichtigung der Kampfweise (attack_type) und der aufgerundeten halben Behinderung ((rs_be + 1) / 2),
 *   jedoch ohne pa_mod (für die Anzeige auf dem Charakterblatt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie den Waffengattungsindex (p2) und gibt
 *   den Paradewert als short zurück.
 * - Wichtige Variablen: Liest pa[p2] (0x81 + p2), attack_type (0x8b) und rs_be (0x44).
 === Ende Beschreibung === */
short f_045710(int p1, short p2)
{
    short r = *(signed char *)(p1 + 0x81 + p2) - *(signed char *)(p1 + 0x8b) - *(signed char *)(p1 + 0x44) / 2;
    if ((*(unsigned char *)(p1 + 0x44) & 1) != 0) r = r - 1;
    if ((short)r < 0) r = 0;
    return r;
}

//@ f_045750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Helden-Datensatz mit der 4-Byte-Kennung "CHAR" (d_1b6648), der
 *   2-Byte-Längenangabe 0x5ef und den 0x5ef Strukturbytes in die geöffnete Spielstands- oder Exportdatei
 *   (d_1c2140).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt 1 zurück, wenn alle 0x5f5 Bytes
 *   erfolgreich geschrieben wurden, sonst 0.
 * - Wichtige Variablen: Nutzt das Datei-Handle d_1c2140 und die Signatur d_1b6648.
 === Ende Beschreibung === */
int f_045750(int p1)
{
    unsigned local = 0x5ef;
    int s = f_144cb6(d_1c2140, d_1b6648, 4);
    s = s + f_144cb6(d_1c2140, &local, 2);
    s = s + f_144cb6(d_1c2140, (void *)p1, (unsigned short)local);
    return s == 0x5f5;
}

//@ f_0457c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen Helden-Datensatz aus der geöffneten Datei d_1c2140 ein, sofern am aktuellen
 *   Dateizeiger die 4-Byte-Signatur 0x52414843 ("CHAR") steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Ziel-Heldenzeiger (p1) und gibt 1 bei gültiger "CHAR"-Kennung
 *   zurück, andernfalls 0.
 * - Wichtige Variablen: Liest aus dem Datei-Handle d_1c2140.
 === Ende Beschreibung === */
int f_0457c0(int p1)
{
    int a;
    unsigned short b;
    f_144e8b(d_1c2140, &a, 4);
    if (a == 0x52414843) {
        f_144e8b(d_1c2140, &b, 2);
        f_144e8b(d_1c2140, (void *)p1, b);
        return 1;
    }
    return 0;
}

//@ f_045820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht im Inventar des Helden p1 nach einem Gegenstand mit der Kennung p2. Wird der Gegenstand
 *   nicht direkt gefunden, prüft die Funktion zusätzlich über f_0458b0 und f_03d860, ob der Held einen
 *   Magierstab trägt, der durch einen Stabzauber (d_1a933c, z. B. *Stabzauber Fackel* oder *Seil*) die Funktion
 *   des gesuchten Gegenstands ersetzt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die gesuchte Gegenstandskennung (p2)
 *   und gibt den gefundenen Inventarslot-Index (oder -1 bei Nichtbesitz) zurück.
 * - Wichtige Variablen: Nutzt die Tabelle der durch Stabzauber ersetzbaren Gegenstände d_1a933c.
 === Ende Beschreibung === */
int f_045820(int p1, short p2)
{
    short p2_ = p2;
    int ret = -1;
    int s = f_0d4aa0(p1, p2);
    short t, i;
    if (s != ret) {
        ret = s;
    } else {
        t = f_0458b0(p1);
        if (t == ret) return ret;
        for (i = 0; i < (short)7; i = i + 1) {
            if (d_1a933c[i] == p2_ && f_03d860(p1, t, i)) {
                ret = t;
                break;
            }
        }
    }
    return ret;
}

//@ f_0458b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht das Inventar des Helden p1 nach einem der acht möglichen Zauberstäbe (0x145,
 *   0x19d-0x1a1, 0x1cf, 0x1d0) und gibt dessen Slot-Index zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den Inventarslot des Zauberstabs
 *   (oder -1, falls keiner vorhanden ist) als short zurück.
 * - Wichtige Variablen: Ruft f_0d4aa0 für alle acht Zauberstab-Item-IDs auf.
 === Ende Beschreibung === */
short f_0458b0(int p1)
{
    short s = f_0d4aa0(p1, 0x145);
    if (s == -1) {
        s = f_0d4aa0(p1, 0x19d);
        if (s == -1) {
            s = f_0d4aa0(p1, 0x19e);
            if (s == -1) {
                s = f_0d4aa0(p1, 0x19f);
                if (s == -1) {
                    s = f_0d4aa0(p1, 0x1a0);
                    if (s == -1) {
                        s = f_0d4aa0(p1, 0x1a1);
                        if (s == -1) {
                            s = f_0d4aa0(p1, 0x1cf);
                            if (s == -1) {
                                s = f_0d4aa0(p1, 0x1d0);
                            }
                        }
                    }
                }
            }
        }
    }
    return s;
}

//@ f_045960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der Held p1 den Gegenstand p2 aufgrund seiner Klasse (d_1a4388[type]) oder seines
 *   NPC-Status (npc_id == 7 oder 8 dürfen außer 0x1d8 keine Waffen führen) benutzen bzw. anlegen darf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) sowie die Gegenstandskennung (p2) und gibt
 *   1 zurück, wenn der Gegenstand erlaubt ist, sonst 0.
 * - Wichtige Variablen: Prüft die Verbotslisten d_1a4388 je Heldentypus sowie d_1c2c40.
 === Ende Beschreibung === */
int f_045960(int p1, short p2)
{
    int r = 1;
    if (f_042400(p1) == 7 || f_042400(p1) == 8) {
        if ((int)p2 != 0x1d8) {
            int off = p2 * 4;
            int base = ((int)d_1c2c40);
            if (((RivaItemDefinition*)(*(int *)(base + off)))->f_0a7990() != 0) r = 0;
        }
    }
    if (r == 1) {
        signed char c = f_042350(p1);
        if (f_149360(p2, d_1a4388[c]) != -1) r = 0;
    }
    return r;
}

//@ f_0459e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt die persönliche Lichtreichweite des Helden p1: Bei aktivem *Dunkelheit*-Zauber
 *   (f_043cc0) beträgt sie -5, bei aktivem *Flim Flam* (f_043cb0) +5; andernfalls addiert die Funktion +3 für
 *   einen leuchtenden Magierstab (0x85 ab Stabzauber 2) oder eine brennende Laterne (0xf9) sowie +2 für eine
 *   brennende Fackel (0x16), begrenzt auf maximal 5.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p1) und gibt den Lichtradius (-5 bis +5) als
 *   short zurück.
 * - Wichtige Variablen: Durchsucht die 31 Inventarslots des Helden nach aktiven Lichtquellen.
 === Ende Beschreibung === */
short f_0459e0(int p1)
{
    short r = 0;
    short i;
    if (f_043cc0(p1) != 0) {
        r = -5;
    } else if (f_043cb0(p1) != 0) {
        r = 5;
    } else {
        for (i = 0; i < 0x1f; i++) {
            if ((f_042a60(p1, i) == 0x85 && f_0432d0(p1) >= 2) || f_042a60(p1, i) == 0xf9) {
                r = r + 3;
            } else if (f_042a60(p1, i) == 0x16) {
                r = r + 2;
            }
        }
    }
    if (r > (short)5) r = 5;
    return r;
}

//@ f_045a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den virtuellen Methodentabellen-Zeiger (vp) der Basisklasse eines
 *   AD-Schrift-/Anzeigeobjekts auf d_1bad24.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p) sowie ein Flag (fl) und gibt p zurück.
 * - Wichtige Variablen: Setzt p->vp = d_1bad24.
 === Ende Beschreibung === */
AD *f_045a80(AD *p, int fl)
{
    p->vp = d_1bad24;
    return p;
}

//@ f_045a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert als Konstruktor ein AD-Schrift-/Textausgabeobjekt (Größe 0x420 Bytes), setzt die
 *   virtuelle Methodentabelle auf d_1bad08, löscht den 0x400 Byte großen Zeichensatzpuffer und speichert die
 *   beiden übergebenen Kontextzeiger a und b.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p) sowie zwei Parameter (a, b) und gibt p
 *   zurück.
 * - Wichtige Variablen: Initialisiert die Felder von AD und setzt p->vp = d_1bad08.
 === Ende Beschreibung === */
AD *f_045a90(AD *p, int a, int b)
{
    p->vp = d_1bad08;
    p->s0c = 0;
    p->s0e = 0;
    p->s10 = 0;
    p->a = a;
    p->b = b;
    p->p12 = 0;
    f_145300(p->buf, 0, 0x400);
    p->p416 = 0;
    p->p41a = 0;
    p->s41e = 0;
    return p;
}

//@ f_045af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt als virtueller Destruktor eines AD-Schrift-/Textausgabeobjekts die dynamisch allokierten
 *   Puffer p->p12 und p->p41a frei, ruft den Basisklassen-Destruktor f_045a80 auf und gibt bei gesetztem Bit 2
 *   in fl auch den Objektspeicher selbst frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger (p) sowie die Destruktor-Flags (fl) und gibt p
 *   zurück.
 * - Wichtige Variablen: Prüft die Watcom-Destruktor-Flags (fl & 4 für Array-Abbau, fl & 2 für operator delete).
 === Ende Beschreibung === */
#pragma aux f_045a80
AD *f_045af0(AD *p, unsigned fl)
{
    if (fl & 4) {
        f_145234(p, d_1bacf4);
        f_145254();
    } else {
        p->vp = d_1bad08;
        if (p->p12) {
            operator delete(p->p12);
            p->p12 = 0;
        }
        if (p->p41a) {
            operator delete(p->p41a);
            p->p41a = 0;
        }
        p->a = 0;
        p->b = 0;
        p = f_045a80(p, 1);
        if (fl & 2) operator delete(p);
    }
    return p;
}
