/* === Beschreibung (Katalog) ===
 * Einheit gz_0257f0 (0x000257f0 - 0x00025ac0)
 *
 * Überblick
 *
 * Die Einheit gz_0257f0 enthält zwei eng zusammengehörende Grafik-Hilfsfunktionen zur Darstellung und Auswertung
 * der Heldenporträt-Leiste (CARRIER) am unteren Bildschirmrand, insbesondere für das Zeichnen der Lebens- und
 * Astralenergieleisten sowie der Porträtköpfe.
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 28.10.2026, Basis gz_0257f0_P1.CPP)
// gz_0257f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0257F0-0x025AC0
#include <string.h>
typedef char SC;
#include "RIVAMEM.H"



struct Info { char a[14]; unsigned size; unsigned short x; unsigned short y; char pad[6]; };
struct E { short id; unsigned key; short age; };
struct FRb {
    virtual ~FRb();
    virtual void v1(); virtual void *v2(unsigned key); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(unsigned id, void *buf);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22();
    virtual short v23(unsigned id);
    virtual void v24();
    virtual void v25(Info *i, int n);
    virtual void v26(); virtual void v27();
    virtual short *v28(int p2, unsigned *n);
};
struct FR : FRb { FR(char *a, char *b, char *c); char pad[0xa8]; };
struct FAb {
    virtual ~FAb();
};
struct FA : FAb { FA(void **p); char pad[0xc9]; };
struct C {
    FR *f0; FA *f4; E *f8; short fc; short fe; int f10; int f14; int f18; unsigned char f1c;
    char *f1d; char *f21; char *f25; void *f29; short *f2d; unsigned f31; unsigned f35; char *f39; char *f3d;
    void f_024a90();
    void f_025350(int p2, unsigned p3);
    void f_025660(short idx);
    short i_0250d0(short id);
    void i_025170(short idx);
    void i_025590(int p2, unsigned p3);
    void f_0257f0(int p2);
    void f_0259e0();
};
inline short C::i_0250d0(short id)
{
    short i;
    short r = -1;
    for (i = 0; i < fc; i++)
        if (f8[i].id == id) { r = i; break; }
    return r;
}
inline void C::i_025170(short idx)
{
    short i;
    for (i = 0; i < fc; i++) {
        if (i == idx) f8[i].age = 0;
        else {
            f8[i].age--;
            if (f8[i].age < -30000) f8[i].age = -30000;
        }
    }
}
inline void C::i_025590(int p2, unsigned p3)
{
    short idx = i_0250d0(f2d[p3]);
    if (idx < 0) f_025350(p2, p3);
    else i_025170(idx);
}
//@ f_0257f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet für einen bestimmten Gruppenplatz das Porträtgesicht des Helden (beziehungsweise das
 *   Totenkopf- oder Sondersymbol bei Kampfunfähigkeit), seinen abgekürzten Namen sowie die farbigen Balken für
 *   Lebensenergie und Astralenergie in die untere Porträtleiste.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger der Porträtleiste sowie den Gruppenplatz-Index
 *   (0 bis 6) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gelesen werden der Heldenzeiger des jeweiligen Slots über f_0415c0, die aktuellen und
 *   maximalen Lebens- und Astralpunkte des Helden sowie die Bildschirmkoordinaten der Porträtplätze aus der
 *   Tabelle d_1a48f4.
 === Ende Beschreibung === */
void C::f_0257f0(int p2)
{
    short i = 0;
    unsigned n = 0;
    f18 = 0;
    f2d = f0->v28(p2, &n);
    i_025170(-1);
    for (i = 0; i < n; i++) {
        if (f2d[i] != -1) i_025590(p2, i);
    }
    for (i = 0; i < n; i++) {
        if (f2d[i] != -1 && i_0250d0(f2d[i]) < 0) {
            f_0259e0();
            f_024a90();
        }
    }
    f2d = 0;
}
//@ f_0257f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet für einen bestimmten Gruppenplatz das Porträtgesicht des Helden (beziehungsweise das
 *   Totenkopf- oder Sondersymbol bei Kampfunfähigkeit), seinen abgekürzten Namen sowie die farbigen Balken für
 *   Lebensenergie und Astralenergie in die untere Porträtleiste.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger der Porträtleiste sowie den Gruppenplatz-Index
 *   (0 bis 6) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gelesen werden der Heldenzeiger des jeweiligen Slots über f_0415c0, die aktuellen und
 *   maximalen Lebens- und Astralpunkte des Helden sowie die Bildschirmkoordinaten der Porträtplätze aus der
 *   Tabelle d_1a48f4.
 === Ende Beschreibung === */
// BLIND: f_0257f0 hier komplett neu aus dem Original-Assembler schreiben (orig.sh gz_0257f0 f_0257f0).
// Die folgende Deklaration stammt aus einer alten Fassung und darf geaendert werden.
// (Methode, Deklaration steht in der Klasse)

//@ f_0259e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft sämtliche sieben Plätze der Heldengruppe und zeichnet die komplette Porträtleiste
 *   am unteren Bildschirmrand neu, sobald sich die Gruppenzusammensetzung, die Reihenfolge oder die Lebenspunkte
 *   geändert haben.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Objektzeiger der Porträtleiste (sowie ein optionales
 *   Modusflag) entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ruft in einer Schleife über die Gruppenplätze 0 bis 6 jeweils f_0257f0 auf und
 *   synchronisiert anschließend den gezeichneten Bildschirmausschnitt mit dem Mauszeiger.
 === Ende Beschreibung === */
void C::f_0259e0()
{
    if (f8) {
        while (fc > 0) f_025660(fc - 1);
        delete f8;
        f8 = 0;
    }
    if (f4) { delete f4; f4 = 0; }
    if (f0) { delete f0; f0 = 0; }
    if (f1d) { delete f1d; f1d = 0; }
    if (f21) { delete f21; f21 = 0; }
    if (f25) { delete f25; f25 = 0; }
    if (f39) { delete f39; f39 = 0; }
    if (f3d) { delete f3d; f3d = 0; }
}
