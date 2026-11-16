/* === Beschreibung (Katalog) ===
 * Einheit chest (0x046d10 - 0x0478d0)
 *
 * Überblick
 * Die Einheit chest implementiert die C++-Klasse Chest zur Verwaltung von Schatztruhen und Beutelbehältern im
 * Spiel. Sie lädt und speichert die 24 Byte großen Truhen-Datensätze (CD) aus der temporären Truhendatei
 * (0x40060000), prüft und entschärft Truhenschlösser und Fallen über das Schlossknacken-Minispiel (f_0ba0d0),
 * öffnet das Beutefenster (f_0a8830), zahlt gefundenes Gold an die Heldengruppe aus und legt Gegenstände in der
 * zugehörigen Gegenstandsliste (0x60001) ab oder entnimmt sie daraus.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 14/18 gleich (suche.py 26.10.2026, Basis chest_P1.CPP)
// chest.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x046D10-0x0478D0
#include <string.h>
struct R27 { char b[27]; };
struct Rec12 { short a[6]; };
struct Rec16 { char b[16]; };
struct Rec24 { char b[24]; };
struct Rec26 { char b[38]; };
struct Rec5a { char b[90]; };
struct Rec1f { short a; short b; R27 r; };
struct S60 { char b[16]; int *p; char rest[40]; };
struct CD { short s0; short s2; short s4; short s6; short s8; short s10; unsigned short s12; int i14; short s18; short s20; short s22; };
int f_040370(void *p1, int p2);



void f_09a400();

int f_0a8830(int p1, int p2, int p3);
int f_0a8b40(int p1, int p2);
int f_0a8be0(int p1);
int f_0ba0d0(int p1, void *p2, void *p3);
int f_0ba160(int p1, int p2);
short f_0ba180(int p1);
int f_0bf730(void *p1, int p2);
int f_0db820(int p1, int p2);
short f_11c320(int p1);
int f_11c350(int p1, void *p2);
int f_11c580(int p1, int p2);
int f_11c5f0(int p1, int p2);
short f_11c620(int p1, int p2);
int f_11c680(int p1, int p2, int p3);
int f_11c760(int p1, int p2);
int f_11c7b0(int p1, int p2);
int f_11c8a0(int p1, int p2);
int f_11c980(int p1, int p2);
int f_11caf0(int p1);
int f_125400(void *p1, void *p2, void *p3, void *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(void *p1, void *p2);





extern char d_1a0ec4[];
extern R27 d_1bc900;
extern int d_1c0004;

extern short d_1c2198;
extern char d_1c27a8[];

extern char d_1c2c64[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern const char d_1a0ea4[];
struct Chest {
    int n; CD *d;
    Chest *f_046d10(short sz);
    Chest *f_046d90(int p_unused1);
    void f_046de0();
    int f_046eb0();
    int f_046ec0();
    void f_046fc0();
    void f_047080();
    int f_047120();
    short f_0471b0(short p2, int p3);
    int f_0472b0(short p2, int p3);
    void f_047570(int p2, int (*p3)(int, int));
    void f_047620(unsigned short p2);
    void f_047650(int p2);
    short f_047660(short p2);
    short f_047720();
    void f_0477a0();
    void f_047830(int p2, short *p3, short *p4);
};
//@ f_046d10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Chest-Objekt für die Truhe mit dem Index sz, berechnet den Dateiversatz n = sz
 *   * 24 und liest den 24 Byte großen Truhen-Datensatz (d) aus der Datei 0x40060000 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den this-Zeiger sowie den Truhenindex (sz) und gibt den
 *   initialisierten Chest*-Zeiger zurück.
 * - Wichtige Variablen: Speichert den Offset in this->n, allokiert this->d (24 Bytes) und liest über das
 *   Datei-Objekt d_1c2098.
 === Ende Beschreibung === */
Chest *Chest::f_046d10(short sz) {
    n = sz * 24;
    d = (CD *)new (mark(d_1a0ea4, 0x4f)) Rec24;
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x40060000, 0x200);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( n, 0);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( d), 0x18)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    return this;
}
//@ f_046d90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt als Destruktor der Chest-Klasse den aktuellen 24-Byte-Datensatz (this->d) an die
 *   Position this->n in die Datei 0x40060000 zurück und gibt den Speicher von this->d frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den this-Zeiger sowie ein ungenutztes Flag (p_unused1) und gibt
 *   this zurück.
 * - Wichtige Variablen: Schreibt this->d über d_1c2098 zurück auf die Festplatte.
 === Ende Beschreibung === */
Chest *Chest::f_046d90(int p_unused1) {
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x40060000, 0x202);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( n, 0);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( d), 0x18)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    operator delete(d);
    return this;
}
//@ f_046de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette Interaktion mit einer Truhe aus: Zuerst wird bei einer verschlossenen
 *   Truhe (d->i14 == 1) über f_046ec0 das Schloss-/Fallenfenster aufgerufen; ist die Truhe anschließend offen
 *   (d->i14 == 0), öffnet sie das Gegenstands-Beutefenster (f_046fc0) und zahlt etwaiges in der Truhe
 *   enthaltenes Gold (d->s12) mit einer Textmeldung (0x6040001) an die aktive Heldengruppe (d_1c0004) aus.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger der Truhe und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Prüft d->i14 (Schlossstatus) und d->s12 (Goldbetrag in Hellern) und setzt d_1c2198 = 1.
 === Ende Beschreibung === */
void Chest::f_046de0() {
    S60 s;
    f_046ec0();
    if (d->i14 == 0) {
        f_046fc0();
        f_09a400();
        if (d->s12 != 0) {
            f_125400(&s, d_1c349c, d_1c3870, d_1c3498);
            f_040370(d_1c27a8, d->s12);
            s.p[1] = f_133fe0(d_1c3498, d_1c27a8);
            f_0bf730(d_1c2c64, 0x6040001);
            f_0db820(d_1c0004, d->s12);
            d->s12 = 0;
            f_1254a0(&s, 0);
        }
        d_1c2198 = 1;
    }
}
//@ f_046eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Truhe bereits unverschlossen (d->i14 == 0) ist.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn die Truhe offen ist, sonst
 *   0.
 * - Wichtige Variablen: Liest d->i14.
 === Ende Beschreibung === */
int Chest::f_046eb0() {
    return d->i14 == 0;
}
//@ f_046ec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet bei einer verschlossenen Truhe (d->i14 == 1) den Schloss- und Fallendialog (f_0ba0d0 /
 *   f_0ba180) mit den sechs aus dem Truhen-Datensatz kopierten Schloss-/Fallenparametern (s18, s20, s4, s6, s8,
 *   s10) und entriegelt die Truhe (d->i14 = 0), sobald das Schloss erfolgreich geöffnet wurde (r == 0).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt den Rückgabewert des Schlossdialogs (0 =
 *   erfolgreich geöffnet) als int zurück.
 * - Wichtige Variablen: Übergibt die Truhenparameter und die Grafikkennung d_1a0ec4 + 3 * d->s2 an das
 *   Schloss-Objekt.
 === Ende Beschreibung === */
int Chest::f_046ec0() {
    short r = 1;
    if (d->i14 == 1) {
        Rec12 *t = new (mark(d_1a0ea4, 0x90)) Rec12;
        t->a[0] = d->s18;
        t->a[1] = d->s20;
        t->a[2] = d->s4;
        t->a[3] = d->s6;
        t->a[4] = d->s8;
        t->a[5] = d->s10;
        int n = (int)new (mark(d_1a0ea4, 0x98)) Rec26;
        int o = n ? f_0ba0d0(n, d_1a0ec4 + 3 * d->s2, t) : n;
        r = ((int (*)(int))f_0ba180)(o);
        if (o != 0) operator delete((void *)f_0ba160(o, 0));
        operator delete(t);
        d->i14 = (r == (short)0);
    }
    return r;
}
//@ f_046fc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die zur Truhe gehörige Gegenstandsliste (d->s22) aus dem Archiv 0x60001, öffnet das
 *   grafische Truhen-Inventarfenster (f_0a8830 / f_0a8be0), in dem der Spieler Gegenstände entnehmen oder
 *   ablegen kann, und speichert die geänderte Liste anschließend über f_11c980 wieder zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Nutzt die Listenkennung d->s22 im Archiv 0x60001.
 === Ende Beschreibung === */
void Chest::f_046fc0() {
    int o = (int)new (mark(d_1a0ea4, 0xb1)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    int p = (int)new (mark(d_1a0ea4, 0xb4)) Rec5a;
    p = p ? f_0a8830(p, f_11caf0(o), 1) : p;
    f_0a8be0(p);
    if (p) operator delete((void *)f_0a8b40(p, 0));
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
//@ f_047080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Nimmt ausschließlich das in der Truhe liegende Gold (d->s12) heraus, gibt die Fundmeldung
 *   0x6040001 aus, schreibt den Betrag über f_0db820 der aktiven Gruppe (d_1c0004) gut und setzt d->s12 auf 0.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest und löscht d->s12 und erhöht das Gruppengeld von d_1c0004.
 === Ende Beschreibung === */
void Chest::f_047080() {
    S60 s;
    if (d->s12 != 0) {
        f_125400(&s, d_1c349c, d_1c3870, d_1c3498);
        f_040370(d_1c27a8, d->s12);
        s.p[1] = f_133fe0(d_1c3498, d_1c27a8);
        f_0bf730(d_1c2c64, 0x6040001);
        f_0db820(d_1c0004, d->s12);
        d->s12 = 0;
        f_1254a0(&s, 0);
    }
}
//@ f_047120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Truhe noch mindestens einen Gegenstand in ihrer Gegenstandsliste (d->s22)
 *   enthält.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn die Truhe nicht leer ist,
 *   sonst 0.
 * - Wichtige Variablen: Fragt die Elementanzahl der Liste d->s22 über f_11c320 ab.
 === Ende Beschreibung === */
int Chest::f_047120() {
    int res = 0;
    int o;
    Rec16 *p = new (mark(d_1a0ea4, 0xd8)) Rec16;
    o = (p) ? f_11c760((int)p, 0x60001) : (int)p;
    f_11c8a0(o, d->s22);
    if (f_11c320(f_11caf0(o)) > 0) res = 1;
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return res;
}
//@ f_0471b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entnimmt bis zu p3 Stück des Gegenstands mit der Kennung p2 aus der Gegenstandsliste (d->s22)
 *   der Truhe (oder entfernt den Listeneintrag komplett, falls nicht mehr als p3 Stück vorhanden sind) und
 *   speichert die Liste wieder ab.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Gegenstandskennung (p2) sowie die gewünschte
 *   Stückzahl (p3) und gibt die tatsächlich entnommene Menge als short zurück.
 * - Wichtige Variablen: Durchsucht die Liste d->s22 mit f_11c620 und reduziert oder löscht den Eintrag über
 *   f_11c680 bzw. f_11c580.
 === Ende Beschreibung === */
short Chest::f_0471b0(short p2, int p3) {
    short ret = 0;
    int o = (int)new (mark(d_1a0ea4, 0xfa)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    short idx = -1;
    f_11c8a0(o, d->s22);
    short k = 0;
    int list = f_11caf0(o);
    goto test;
next:
    ++k;
test:
    if (k >= f_11c320(list)) goto done;
    if (idx != -1) goto done;
    if (f_11c620(list, k) == (short)p2) idx = k;
    goto next;
done:
    {
        int i = idx;
        if (i != -1) {
            int have = f_11c5f0(list, i);
            if ((short)have > (short)p3) {
                ret = p3;
                f_11c680(list, i, (short)(have - p3));
            } else {
                ret = have;
                f_11c580(list, i);
            }
        }
    }
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return ret;
}

//@ f_0472b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt p3 Stück des Gegenstands mit der Kennung p2 in die Gegenstandsliste (d->s22) der Truhe
 *   hinein, indem entweder ein vorhandener Stapel erhöht (f_11c680) oder ein neuer Listeneintrag (f_11c350) mit
 *   Standard-Gegenstandsattributen (d_1bc900) angelegt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Gegenstandskennung (p2) sowie die Stückzahl
 *   (p3) und gibt p3 als int zurück.
 * - Wichtige Variablen: Nutzt die Vorlagestruktur d_1bc900 (27 Bytes) für neu angelegte Gegenstandseinträge.
 === Ende Beschreibung === */
int Chest::f_0472b0(short p2, int p3) {
    struct X {
        short a, b;
        R27 r;
        X(short aa, short bb, R27 rr) {
            a = aa;
            b = bb;
            memcpy(&r, &rr, 0x1b);
        }
    };
    int ret;
    int t = (int)new (mark(d_1a0ea4, 0x137)) Rec16;
    int obj = 0;
    obj = t ? f_11c760(t, 0x60001) : t;
    int l;
    {
        short k;
        short i = 0;
        k = -1;
        f_11c8a0(obj, d->s22);
        l = f_11caf0(obj);
        for (short key = p2; i < f_11c320(l) && k == -1; i++) {
            if (f_11c620(l, i) == key) k = i;
        }
        if (k != -1) {
            ret = p3;
            short v = f_11c5f0(l, k) + ret;
            f_11c680(l, k, v);
        } else {
            R27 L = d_1bc900;
            X *q = new (mark(d_1a0ea4, 0x159)) X(p3, p2, L);
            ret = p3;
            f_11c350(l, q);
        }
    }
    f_11c980(obj, d->s22);
    if (obj) {
        delete (char *)f_11c7b0(obj, 0);
    }
    return ret;
}
//@ f_047420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Überträgt den Gegenstand aus dem Inventarslot p3 des Helden p2 samt seinen individuellen
 *   27-Byte-Eigenschaften (Bruchfaktor, Giftladungen, Brenndauer) in die geöffnete Truhen-Gegenstandsliste p1
 *   (stapelt bis zu einer Summe < 99, andernfalls wird ein neuer Listeneintrag erzeugt).
 * - Eingaben und Rückgabe: Die Funktion erhält die Gegenstandsliste (p1), den Heldenzeiger (p2) sowie den
 *   Inventarslot-Index (p3) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Kopiert den 27-Byte-Slot über f_0431a0(p2, p3) in den neuen Truheneintrag.
 === Ende Beschreibung === */
void f_047420(int p1, int p2, short p3) {
    struct X {
        short b, a;
        R27 r;
        X(short aa, short bb, R27 rr) {
            b = aa;
            a = bb;
            memcpy(&r, &rr, 0x1b);
        }
    };
    int done = 0;
    short t;
    short r40;
    short found = -1;
    short k;
    r40 = f_042a60((struct hero *)(p2), (int)p3);
    t = d_1c2c40[r40]->f_0a7950() ? f_042ac0((struct hero *)(p2), (int)p3) : 1;
    for (k = 0; k < (short)f_11c320(p1) && found == -1; k++) {
        if (r40 == (short)f_11c620(p1, k)) found = k;
    }
#if FIX_R038
    if (d_1c2c40[r40]->f_0a7950() && found != -1) {
#else
    if (found != -1) {
#endif
        short count902(int,int);
#pragma aux count902 "f_11c5f0"
        short s = count902(p1, found) + t;
        if (s < 99) {
            f_11c680(p1, found, s);
            done = 1;
        }
    }
    if ((*(int *)&done) == 0) { // Adressierter Zugriff haelt done im Stapelslot wie im Original
        R27 tmp = *((R27 *)(f_0431a0((struct hero *)(p2), (short)p3)));
        X *q = new (mark(d_1a0ea4, 0x19f)) X(t, r40, tmp);
        { int *rt = (*(int **)&d_1c2c40); (*(int **)&d_1c2c40) = rt; } // Haelt die Register- und Stapelvergabe wie im Original
        f_11c350(p1, q);
    }
}
//@ f_047570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft alle 31 Inventarslots (0 bis 30) des Helden p2 und überträgt jeden Gegenstand, für
 *   den die übergebene Filterfunktion p3(p2, k) den Wert 1 liefert, über f_047420 in die Truhe (z. B. bei
 *   Gefangennahme oder Abgabe bestimmter Ausrüstung).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, den Heldenzeiger (p2) sowie den Funktionszeiger
 *   auf das Filterprädikat (p3) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Lädt und speichert die Truhenliste d->s22 im Archiv 0x60001.
 === Ende Beschreibung === */
void Chest::f_047570(int p2, int (*p3)(int, int)) {
    int o = (int)new (mark(d_1a0ea4, 0x1b4)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    short s = 0;
    int list = f_11caf0(o);
    goto test;
next:
    ++s;
test:
    {
        int k = s;
        if (k >= 0x1f) goto done;
        if ((*p3)(p2, k) == 1) ((void (*)(int,int,int))f_047420)(list, p2, k);
        goto next;
    }
done:
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
//@ f_047620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt der Truhe p2 Heller Gold (d->s12) hinzu und begrenzt den Goldbestand der Truhe nach oben
 *   auf 65000.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie den hinzuzufügenden Goldbetrag (p2) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Erhöht d->s12 mit Obergrenze 65000.
 === Ende Beschreibung === */
void Chest::f_047620(unsigned short p2) {
    unsigned v = p2 + d->s12;
    if (65000 < v) v = 65000;
    d->s12 = v;
}
//@ f_047650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Verriegelungsstatus (d->i14, 0 = offen, 1 = verschlossen) der Truhe auf den Wert p2.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie den neuen Status (p2) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt d->i14.
 === Ende Beschreibung === */
void Chest::f_047650(int p2) {
    d->i14 = p2;
}
//@ f_047660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt zusammen, wie viele Exemplare des Gegenstands p2 sich insgesamt in der Gegenstandsliste
 *   (d->s22) der Truhe befinden.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger sowie die gesuchte Gegenstandskennung (p2) und
 *   gibt die gefundene Gesamtmenge als short zurück.
 * - Wichtige Variablen: Summiert f_11c5f0(list, k) für alle passenden Einträge in d->s22.
 === Ende Beschreibung === */
short Chest::f_047660(short p2) {
    int o = (int)new (mark(d_1a0ea4, 0x1ee)) Rec16;
    short sum = 0;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    short s = 0;
    int list = f_11caf0(o);
    goto test;
next:
    ++s;
test:
    if (s >= f_11c320(list)) goto done;
    {
        int k = s;
        if (f_11c620(list, k) == (short)p2) sum += f_11c5f0(list, k);
        goto next;
    }
done:
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return sum;
}
//@ f_047720
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Anzahl der belegten Gegenstandsslots in der Gegenstandsliste (d->s22) der Truhe
 *   zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt die Anzahl der Listeneinträge als short
 *   zurück.
 * - Wichtige Variablen: Ruft f_11c320 für die Liste d->s22 auf.
 === Ende Beschreibung === */
short Chest::f_047720() {
    int o = (int)new (mark(d_1a0ea4, 0x20a)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    int r = ((int (*)(int))f_11c320)(f_11caf0(o));
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
    return r;
}
//@ f_0477a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leert die Truhe vollständig, indem sämtliche Einträge aus ihrer Gegenstandsliste (d->s22)
 *   gelöscht werden.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Entfernt in einer Schleife jeweils das erste Element (f_11c580(list, 0)), bis die Liste
 *   leer ist.
 === Ende Beschreibung === */
void Chest::f_0477a0() {
    int o = (int)new (mark(d_1a0ea4, 0x220)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    int list = f_11caf0(o);
    while (f_11c320(list) > 0) f_11c580(list, 0);
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
//@ f_047830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Stückzahl (*p3) und die Gegenstandskennung (*p4) des Listeneintrags mit Index p2 aus
 *   der Truhe aus.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, den Listenindex (p2) sowie zwei Ausgabezeiger (p3
 *   für die Anzahl, p4 für die Item-ID) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Liest die Werte über f_11c5f0 und f_11c620 aus der Liste d->s22.
 === Ende Beschreibung === */
void Chest::f_047830(int p2, short *p3, short *p4) {
    int o;
    o = (int)new (mark(d_1a0ea4, 0x238)) Rec16;
    o = o ? f_11c760(o, 0x60001) : o;
    f_11c8a0(o, d->s22);
    p2 = (short)p2;
    int list = f_11caf0(o);
    *p3 = f_11c5f0(list, p2);
    *p4 = f_11c620(list, p2);
    f_11c980(o, d->s22);
    if (o) operator delete((void *)f_11c7b0(o, 0));
}
