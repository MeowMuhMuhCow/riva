/* === Beschreibung (Katalog) ===
 * Einheit icon (0a1d00-0a2400)
 *
 * Überblick
 * Diese Einheit implementiert die Verwaltung und den referenzgezählten Cache für Schaltflächen-Icons (ICON.CPP).
 * Jedes Icon-Objekt lädt aus einem Bildarchiv zwei Zustandsgrafiken (normal und gedrückt/aktiviert) in zwei
 * eingebettete RivaRasterImage-Teilobjekte, während der Cache (f_0a1e10) mehrfach angeforderte Icons über einen
 * Referenzzähler teilt und acht Standard-Icons (d_1be180[0..7]) dauerhaft vorhält.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 7/8 gleich (suche.py 29.10.2026, Basis icon_P1.CPP)
// icon.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A1D00-0x0A2400
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a3c2c[];           // Text 0x1A3C2C

// ---- eigene Deklarationen ----
extern char d_1bb040[];
extern char d_1bb054[];
extern int d_1c2be0;
extern short d_1a3c48[8];
#define A(x) ((int)&(x))
int f_050580(int p1, int p2, int p3, short *p4, short *p5);
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
void *f_145234(void *p1, void *p2);
void f_145254(void *p1);

struct Icon {
    char *data;
    int key;
    short id;
    short w;
    short h;
    RivaRasterImage a;
    RivaRasterImage b;
    Icon(int k, short i);
    ~Icon() { if (data) delete data; }
};

struct IcoD {
    char c[0x20];
    ~IcoD();
};

struct Entry {
    short id;
    int key;
    Icon *icon;
    short ref;
    void Release() {
        if (icon) {
            delete icon;
            id = -1;
            icon = 0;
            ref = 0;
            key = 0;
        }
    }
    void Clear();
    Icon *f_0a1d00(int k, short i);
    void f_0a1da0();
};

struct Cache {
    Entry *tab;
    short n;
    int vp;
};

extern Icon *d_1be180[8];
Icon *f_0a20a0(Cache *p, int key, short id);


#include <string.h>

// Astra630: Feldbreiten aus Original-ASM; Aliase enthalten nur ABI-/Symbolangaben.
#define NA(a) ((int)&(a))
#define ND32(a) (*(int *)&(a))
#define ND16(a) (*(short *)&(a))
#define ND8(a) (*(signed char *)&(a))
#define NI(p,o) (*(int *)((char *)(p)+(o)))
#define NW(p,o) (*(short *)((char *)(p)+(o)))
#define NB(p,o) (*(unsigned char *)((char *)(p)+(o)))
#define NNEW(n,a,l) C014ac0_2((n),C014b10_2(NA(a),(l)))
#define NOBJ(n,a,l) C014ab0_2((n),C014b10_2(NA(a),(l)))

int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C04fef0_7(int,int,int,int,int,int,int);
#pragma aux C04fef0_7 "f_04fef0" modify exact [eax ebx ecx edx];
int C050580_5(int,int,int,int,int);
#pragma aux C050580_5 "f_050580";
int C0fabf0_1(int);
#pragma aux C0fabf0_1 "f_0fabf0";
int C0fad50_4(int,int,int,int);
#pragma aux C0fad50_4 "f_0fad50" modify exact [eax ebx ecx edx];
int C0fb0b0_1(int);
#pragma aux C0fb0b0_1 "f_0fb0b0" modify exact [eax];
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0a1d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt ein eventuell im Cache-Eintrag this vorhandenes altes Icon frei, legt ein neues
 *   Icon-Objekt für den Archivschlüssel k und die Icon-Kennung i an, erhöht den Referenzzähler ref auf 1 und
 *   gibt den Zeiger auf das geladene Icon zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Entry-Objekts, den Archivschlüssel k (int)
 *   sowie die Icon-Nummer i (short) und gibt den Icon *-Zeiger zurück.
 * - Wichtige Variablen: Die Felder id, key, icon und ref bilden einen einzelnen Eintrag in der
 *   Icon-Cache-Tabelle.
 === Ende Beschreibung === */
Icon *Entry::f_0a1d00(int k, short i)
{
    Release();
    id = i;
    key = k;
    icon = new (mark(d_1a3c2c, 0x39)) Icon(key, id);
    ref++;
    return icon;
}

//@ f_0a1da0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert den Referenzzähler ref eines Icon-Cache-Eintrags um 1 und gibt das Icon-Objekt über
 *   Release() (f_0a24a0) frei, sobald der Zähler 0 erreicht.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Entry-Objekts und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Feld ref zählt die aktiven Nutzer des jeweiligen Icons.
 === Ende Beschreibung === */
void Entry::f_0a1da0()
{
    if (--ref == 0) Release();
}

//@ f_0a1e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert den Icon-Cache p mit n Tabelleneinträgen, initialisiert alle Einträge als leer (id
 *   = -1, ref = 0) und lädt vorab die acht Standard-Icons aus d_1a3c48[0..7] (Archiv 0x280000) in das globale
 *   Zeigerarray d_1be180[0..7].
 * - Eingaben und Rückgabe: Die Funktion erhält den Cache-Zeiger p (Cache *) sowie die Tabellengröße n (short)
 *   und gibt p zurück (Cache *).
 * - Wichtige Variablen: Das Array p->tab speichert die n Cache-Slots, und d_1be180 hält die acht ständig
 *   verfügbaren System-Icons.
 === Ende Beschreibung === */
Cache *f_0a1e10(Cache *p, short n)
{
    short i;
    p->vp = (int)d_1bb054;
    p->n = n;
    p->tab = new (mark(d_1a3c2c, 0x5d)) Entry[p->n];
    for (i = 0; i < p->n; i++) {
        Entry *t = p->tab;
        t[i].id = -1;
        t[i].icon = 0;
        t[i].ref = 0;
        t[i].key = 0;
    }
    for (i = 0; i < 8; i++) {
        d_1be180[i] = f_0a20a0(p, 0x280000, d_1a3c48[i]);
    }
    return p;
}

//@ f_0a1ec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des Icon-Caches p, gibt zunächst die acht Standard-Icons aus
 *   d_1be180[0..7] frei, räumt anschließend alle verbleibenden Einträge in p->tab über Release() ab und löscht
 *   das Tabellenarray (sowie bei fl & 2 das Cache-Objekt selbst).
 * - Eingaben und Rückgabe: Die Funktion erhält den Cache-Zeiger p (Cache *) sowie die Destruktor-Flags fl
 *   (unsigned) und gibt p zurück (Cache *).
 * - Wichtige Variablen: Falls eines der acht Icons aus d_1be180 nicht in p->tab gefunden wird, bleibt j = -1 und
 *   &c->tab[j] greift vor den Tabellenanfang (siehe Fehlerliste).
 === Ende Beschreibung === */
inline void yank2(Entry *e)
{
    if (e->icon) {
        delete (IcoD *)e->icon;
        e->Clear();
    }
}

Cache *f_0a1ec0(Cache *p, unsigned fl)
{
    short j = -1;
    short i = 0;
    short k, m;
    Entry *e;
    if (fl & 4) {
        f_145254(f_145234(p, d_1bb040));
    } else {
        p->vp = (int)d_1bb054;
        for (i = 0; i < 8; i++) {
            Icon *ic = d_1be180[i];
            Cache *c = p;
            j = -1;
            for (k = 0; k < c->n; k++) {
                if (ic == p->tab[k].icon) { j = k; break; }
            }
            e = &c->tab[j];
            if (--e->ref == 0) yank2(e);
        }
        if (p->tab) {
            Cache *q = p;
            for (m = 0; m < q->n; m++) q->tab[m].Release();
            operator delete(p->tab);
            p->tab = 0;
        }
        if (fl & 2) operator delete(p);
    }
    return p;
}

//@ f_0a2020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt sämtliche aktuell im Icon-Cache p gespeicherten Icons über Release() frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Cache-Zeiger p (Cache *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Schleife läuft über alle p->n Einträge der Tabelle p->tab.
 === Ende Beschreibung === */
void f_0a2020(Cache *p)
{
    short i;
    for (i = 0; i < p->n; i++) p->tab[i].Release();
}

//@ f_0a20a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht im Icon-Cache p nach einem bereits geladenen Icon mit dem Archivschlüssel key und der
 *   Kennung id. Wird es gefunden, erhöht die Funktion dessen Referenzzähler ref und gibt das vorhandene Icon
 *   zurück; andernfalls sucht sie den ersten freien Slot (ref == 0) und lädt das Icon über f_0a1d00 neu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Cache-Zeiger p (Cache *), den Archivschlüssel key (int) sowie
 *   die Icon-Kennung id (short) und gibt den Zeiger auf das Icon zurück (Icon *).
 * - Wichtige Variablen: Wenn alle p->n Slots des Caches belegt sind (ref != 0), bleibt j = -1 und &p->tab[j]
 *   adressiert Speicher vor dem Array (siehe Fehlerliste).
 === Ende Beschreibung === */
Icon *f_0a20a0(Cache *p, int key, short id)
{
    short j, i;
    for (i = 0; i < p->n; i++) {
        Entry *q = &p->tab[i];
        if (q->id == id && q->key == key) {
            q->ref++;
            return q->icon;
        }
    }
    j = -1;
    for (i = 0; i < p->n; i++) {
        if (p->tab[i].ref == 0) { j = i; break; }
    }
    Entry *e = &p->tab[j];
    e->Release();
    Entry *g = &p->tab[j];
    return g->f_0a1d00(key, id);
}
//@ f_0a2230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht das übergebene Icon ic in der Tabelle des Icon-Caches p, dekrementiert dessen
 *   Referenzzähler ref und gibt den Eintrag bei ref == 0 über Release() frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Cache-Zeiger p (Cache *) sowie den freizugebenden Icon-Zeiger
 *   ic (Icon *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Auch hier wird j = -1 vor dem Zugriff &p->tab[j] nicht abgefangen, falls ic nicht in der
 *   Tabelle enthalten ist.
 === Ende Beschreibung === */
void f_0a2230(Cache *p, Icon *ic)
{
    short j, i;
    j = -1;
    for (i = 0; i < p->n; i++) {
        if (ic == p->tab[i].icon) { j = i; break; }
    }
    Entry *e = &p->tab[j];
    if (--e->ref == 0) e->Release();
}


//@ f_0a22e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein einzelnes Icon-Objekt p mit dem Archivschlüssel key und der Kennung id,
 *   ermittelt bei id > 0 die Bildmaße über f_050580 zum Paarindex (id - 128) * 2, reserviert einen gemeinsamen
 *   Pixelpuffer für beide Icon-Zustände (w * h * 2 Bytes) und entpackt das ungedrückte (v) sowie das gedrückte
 *   (v + 1) Teilbild über f_04fef0 in die beiden eingebetteten RivaRasterImage-Objekte an Offset +14 und +23.
 * - Eingaben und Rückgabe: Die Funktion erhält die Objektadresse p, den Archivschlüssel key (int) sowie die
 *   Icon-Kennung id (short) und gibt p zurück (int).
 * - Wichtige Variablen: Das Feld NI(p, 0) zeigt auf den gemeinsamen Pixelpuffer, NW(p, 10) und NW(p, 12)
 *   speichern Breite und Höhe des Icons, und die beiden RivaRasterImage-Teilobjekte liegen an p + 14
 *   (Standardzustand) und p + 23 (gedrückter Zustand).
 === Ende Beschreibung === */
int f_0a22e0(int p,int key,short id)
{
    short v;
    char *image;
    p=C0fabf0_1(C0fabf0_1(p+14)+9)-23;
    NW(p,10)=0;
    NW(p,12)=0;
    NI(p,0)=0;
    NW(p,8)=id;
    int active=*(volatile short *)(p+8);
    ((volatile Icon*)p)->key=key;
    if (active>0) {
        v=(short)((*(volatile short *)(p+8)-128)*2);
        C050580_5(NA(d_1c2be0),((Icon*)p)->key,v,p+10,(int)&((Icon*)p)->h);
        image=(char*)NNEW((NW(p,10)*2)*NW(p,12),d_1a3c2c,0x109);
        NI(p,0)=(int)image;
        ((RivaRasterImage*)(p+23))->f_0fad50(NW(p,10),NW(p,12),image);
        int sum=NW(p,10)*NW(p,12);
        int base=NI(p,0);
        sum+=base;
        ((RivaRasterImage*)(p+14))->f_0fad50(NW(p,10),NW(p,12),(char*)sum);
        f_04fef0(NA(d_1c2be0),NI(p,4),(int)(((RivaRasterImage*)(p+14))->f_0fb0b0()),0,v,0,320);
        f_04fef0(NA(d_1c2be0),NI(p,4),(int)(((RivaRasterImage*)(p+23))->f_0fb0b0()),0,(short)((short)(v)+1),0,320);
    }
    return p;
}


