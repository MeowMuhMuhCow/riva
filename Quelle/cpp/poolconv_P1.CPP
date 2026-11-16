/* === Beschreibung (Katalog) ===
 * Einheit poolconv (0dfca0 - 0e04f0)
 *
 * Überblick
 * Die Einheit poolconv stammt aus der Quelldatei poolconv.cpp und enthält die Konvertierungs- und
 * Auswertungsfunktionen für die temporäre Waren-Übergabedatei good.$$$ (d_1a63a0). Damit werden im Handels-Pool
 * ausgewählte Gegenstände gezählt, abgerechnet, aus Heldeninventaren entfernt, in Beutestapel umgewandelt oder
 * als zeitverzögerte Reparaturaufträge beim Schmied eingetragen.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVAITBL.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 25.10.2026, Basis poolconv_P1.CPP)
// poolconv.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DFCA0-0x0E04F0
#include <string.h>
void *f_11c0f0(void *p1, void *p2, int p3);
int f_1270c0(void *p1);
void *f_147c84(void *p, int n, void *t);
extern int d_1bb55c;                    // 0x1BB55C
extern const char d_1a63a4[];           // Text 0x1A63A4
struct Q16 { char b[16]; };

#include <string.h>
#include <stdio.h>

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
extern unsigned char d_1a63a0;
extern unsigned char d_1a965c;
extern unsigned char d_1bb8ac;


int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C036300_3(int,int,int);
#pragma aux C036300_3 "f_036300" modify exact [eax ebx edx];
int C0a7820_1(int);
#pragma aux C0a7820_1 "f_0a7820" modify exact [eax];
int C0a7830_1(int);
#pragma aux C0a7830_1 "f_0a7830" modify exact [eax];
int C0e0120_1(int);
#pragma aux C0e0120_1 "f_0e0120" modify exact [eax];
int C11c0f0_3(int,int,int);
#pragma aux C11c0f0_3 "f_11c0f0" modify exact [eax ebx edx];
int C11c320_1(int);
#pragma aux C11c320_1 "f_11c320" modify exact [eax];
int C11c5f0_2(int,int);
#pragma aux C11c5f0_2 "f_11c5f0" modify exact [eax edx];
int C11c620_2(int,int);
#pragma aux C11c620_2 "f_11c620" modify exact [eax edx];
int C126f40_1(int);
#pragma aux C126f40_1 "f_126f40" modify exact [eax];
int C1448b0_3(int,int,int);
#pragma aux C1448b0_3 "f_1448b0" modify exact [eax ebx edx];
int C144920_3(int,int,int);
#pragma aux C144920_3 "f_144920" modify exact [eax ebx edx];
int C144960_3(int,int,int);
#pragma aux C144960_3 "f_144960" modify exact [eax ebx edx];
int C1449a0_1(int);
#pragma aux C1449a0_1 "f_1449a0" modify exact [eax];
int C144af0_3(int,int,int);
#pragma aux C144af0_3 "f_144af0" modify exact [eax ecx edx];
int C147c84_3(int,int,int);
#pragma aux C147c84_3 "f_147c84" modify exact [eax ebx edx];
//@ f_0dfca0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet die temporäre Waren-Übergabedatei good.$$$ (d_1a63a0), liest den 16-Bit-Zähler am
 *   Dateianfang und gibt die Anzahl der darin vermerkten Warenposten zurück.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Gibt die Anzahl der Datensätze in good.$$$ zurück.
 === Ende Beschreibung === */
int f_0dfca0()
{
    short n=0; ND32(d_1a965c)=ND32(d_1a63a0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)), 0, 0x200);
    C144920_3(NA((*(unsigned char*)&d_1c2098)), (int)&n, 2);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    return (short)n;
}

//@ f_0dfcf0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest sämtliche 24-Byte-Warensätze aus good.$$$ (d_1a63a0) ein und berechnet den gesamten Kauf-
 *   bzw. Verkaufspreis als Summe aus Stückzahl * Einzelpreis * Mengenfaktor (NW(rec, 16) * NW(rec, 6) * NW(rec,
 *   8)).
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Gibt die berechnete Gesamtsumme in Hellern zurück.
 === Ende Beschreibung === */
int f_0dfcf0()
{
    short n=0,i;int sum=0;char *records;
    ND32(d_1a965c)=ND32(d_1a63a0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x200);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
    records=(char *)NNEW(n*24,d_1a63a4,0x37);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    for(i=0;i<n;i++)
        sum+=NW(records+i*24,16)*NW(records+i*24,6)*NW(records+i*24,8);
    C014710_1((int)records);
    return sum;
}

//@ f_0dfdd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schreibt den Warenbestand stock zunächst über f_0e0120 nach good.$$$, liest die Datensätze wieder
 *   ein und berechnet den halbierten Gesamtwert des Bestands unter Einrechnung des prozentualen
 *   Händler-Aufschlags percent.
 * - Eingaben: Übergeben werden der Zeiger auf das Bestandsobjekt (stock) sowie der prozentuale Preisaufschlag
 *   (percent).
 * - Rückgabewert: Gibt den berechneten halbierten Gesamtwert in Hellern zurück.
 === Ende Beschreibung === */
struct PoolSumRecord16 { short amount,id,pad4,width,height;char pad10[6];short count,owner;int ref; };
int f_0dfdd0(int stock,short percent)
{
    short n=0,i=0;int sum=0;
    PoolSumRecord16 *records;
    C0e0120_1(stock);
    ND32(d_1a965c)=ND32(d_1a63a0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x200);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
    records=(PoolSumRecord16 *)NNEW(n*24,d_1a63a4,0x65);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    for(i=0;i<n;i++) {
        PoolSumRecord16 *entry=records+i;
        int area=entry->width*entry->height;
        int surcharge=percent*area/100;
        int total=area+surcharge;
        total/=entry->height;
        surcharge=entry->count*entry->height; total*=surcharge;
        sum+=total;
    }
    sum/=2;
    C014710_1((int)records);
    return sum;
}

//@ f_0dfef0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest die vom Spieler in good.$$$ ausgewählten Gegenstände ein und zieht für jeden Posten mit
 *   gewählter Stückzahl (NW(entry, 16) > 0) die entsprechende Anzahl über f_036300 aus dem Inventarslot
 *   (NW(entry, 18)) des jeweiligen Helden (NI(entry, 20)) ab.
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0dfef0()
{
    short n=0,i;char *records,*entry;
    ND32(d_1a965c)=ND32(d_1a63a0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x200);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
    records=(char *)NNEW(n*24,d_1a63a4,0x97);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    for(i=0;i<n;i++) {
        entry=records+i*24;
        if(NW(entry,16)>0)
            C036300_3(NI(entry,20),NW(entry,18),NW(entry,16));
    }
    C014710_1((int)records);
}

//@ f_0dffd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest die in good.$$$ gespeicherten Warensätze ein, überträgt alle Posten mit positiver Stückzahl
 *   (NW(entry, 16) > 0) in ein 31-Byte-Gegenstands-Array (d_1bb55c) und erzeugt daraus über f_11c0f0 ein neues
 *   Bestandsobjekt (Q16).
 * - Eingaben: Diese Funktion erhält keine Parameter.
 * - Rückgabewert: Gibt den Zeiger auf das neu erzeugte Bestandsobjekt zurück.
 === Ende Beschreibung === */
int f_0dffd0()
{
    short n=0,index,used=0;int count;char *records,*table;int raw,result;
    ND32(d_1a965c)=ND32(d_1a63a0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x200);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
    records=(char *)NNEW(n*24,d_1a63a4,0xc8);
    C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    count=n;
    int allocationTag=C014b10_2(NA(d_1a63a4),0xd9);
    count++;
    char *allocated=(char *)C147c84_3(C014ac0_2(count*31,allocationTag),count,NA(d_1bb55c));
    table=allocated?allocated:0;
    for(index=0;index<n;index++) {
        char *entry=records+index*24;
        if(NW(entry,16)>0) {
            char *out=table+used*31;
            NW(out,0)=NW(entry,16);
            NW(out,2)=NW(entry,2);
            used++;
        }
    }
    C014710_1((int)records);
    raw=NOBJ(16,d_1a63a4,0xf3);
    result=raw?C11c0f0_3(raw,(int)table,0):raw;
    C014710_1((int)table);
    return result;
}

//@ f_0e0120
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Exportiert sämtliche belegten Plätze eines Bestandsobjekts (stock) samt Gegenstands-ID, Stückzahl
 *   und Grundpreisdaten (f_0a7820, f_0a7830) als 24-Byte-Datensätze in die Übergabedatei good.$$$ (d_1a63a0).
 * - Eingaben: Übergeben wird der Zeiger auf das zu exportierende Bestandsobjekt (stock).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
// Diese drei Bestandsmethoden liefern laut Original jeweils AX, nicht volles EAX.
struct StockProto12 { short f_11c320();short f_11c5f0(short);short f_11c620(short); };

struct StockRecord12 { short amount,id,pad4,width,height;char pad10[6];short count,owner;int ref; };
int createStockFile12(int,int);
#pragma aux createStockFile12 "f_144af0" modify exact [eax ecx edx];
void f_0e0120(StockProto12 *stock)
{
    short n=stock->f_11c320();
    short i=0;
    StockRecord12 *records=(StockRecord12 *)NNEW(n*24,d_1a63a4,0x10a);
    for(i=0;i<n;i++) {
        if(stock->f_11c5f0(i)>0) {
            short id=stock->f_11c620(i);
            records[i].count=stock->f_11c5f0(i);
            records[i].amount=records[i].count;
            records[i].id=id;
            records[i].width=(short)C0a7820_1(NI((void *)ND32((*(unsigned char*)&d_1c2c40)),id*4));
            records[i].height=(short)C0a7830_1(NI((void *)ND32((*(unsigned char*)&d_1c2c40)),id*4));
        }
    }
    ND32(d_1a965c)=ND32(d_1a63a0);
    createStockFile12(NA((*(unsigned char*)&d_1c2098)),0);
    C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x221);
    C144960_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
    C144960_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
    C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
    C014710_1((int)records);
}

//@ f_0e0250
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest neu in Auftrag gegebene Gegenstände (z. B. beim Schmied) aus good.$$$ ein, hängt sie an das
 *   bestehende 15-Byte-Auftragsarray old (Größe *count) für den Händler owner an, berechnet für jeden Posten die
 *   Fertigstellungsdauer (d_1bb8ac * amount * laufende_Nummer) und startet jeweils einen Zeittimer (f_126f40).
 * - Eingaben: Übergeben werden die Händlerkennung (owner), ein Zeiger auf die aktuelle Auftragsanzahl (count)
 *   sowie das bisherige Auftragsarray (old).
 * - Rückgabewert: Gibt den Zeiger auf das neu reservierte, erweiterte Auftragsarray zurück.
 === Ende Beschreibung === */
struct OldRecord650 {short amount,id;char tail[20];};
struct NewRecord650 {short owner,amount,id,delay;char timer[7];};
char *f_0e0250(int owner,short *count,char *old)
{
 OldRecord650 *records;
 short n=0,i,product;
 NewRecord650 *result;
 ND32(d_1a965c)=ND32(d_1a63a0);
 C1448b0_3(NA((*(unsigned char*)&d_1c2098)),0,0x200);
 C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)&n,2);
 records=(OldRecord650 *)NNEW(n*24,d_1a63a4,0x144);
 C144920_3(NA((*(unsigned char*)&d_1c2098)),(int)records,n*24);
 C1449a0_1(NA((*(unsigned char*)&d_1c2098)));
 result=(NewRecord650 *)NNEW((n+*count)*15,d_1a63a4,0x155);
 for(i=0;i<*count;i++)result[i]=((NewRecord650 *)old)[i];
 C014710_1((int)old);
 for(i=0;i<n;i++) {
  result[*count+i].owner=owner;
  result[*count+i].amount=records[i].amount;
  result[*count+i].id=records[i].id;
  product=ND16(d_1bb8ac)*records[i].amount;
  result[*count+i].delay=(short)((*(short *)&product)*(*count+i+1));
  C126f40_1((int)result[*count+i].timer);
 }
 C014710_1((int)records);
 *count=(short)(*count+n);
 return (char *)result;
}

//@ f_0e0400  groesse 304 B, 76 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Prüft im 15-Byte-Auftragsarray p3 (mit *p2 Einträgen), welche beim Händler p1 hinterlegten
 *   Gegenstände inzwischen fertiggestellt sind (verstrichene Zeit f_1270c0 / 0x1518 >= Wartezeit), markiert
 *   diese Einträge (r[1] |= 1) und fasst sie über f_11c0f0 zu einem abholbereiten Bestandsobjekt zusammen.
 * - Eingaben: Übergeben werden die Händlerkennung (p1), ein Zeiger auf die Auftragsanzahl (p2) sowie das
 *   Auftragsarray (p3).
 * - Rückgabewert: Gibt den Zeiger auf das Bestandsobjekt mit den fertiggestellten Gegenständen oder 0 zurück,
 *   falls noch kein Auftrag fertig ist.
 === Ende Beschreibung === */
void *f_0e0400(short p1, short *p2, char *p3)
{
    struct Entry { short a, b; char tail[27]; };
    void *res = 0;
    char *tab;
    short i, cnt;
    char *r;
    int m = *p2 + 1;
    i = 0; cnt = 0;
    tab = (char *)f_147c84(new (mark(d_1a63a4, 0x184)) char[m * 0x1f], m, &d_1bb55c);
    tab = tab ? tab : 0;
    while (i < *p2) {
        r = p3 + i * 0xf;
        if (*(short *)r == (short)p1) {
#if FIX_R011   /* R011: Noch nicht fertigen Auftrag ueberspringen (continue) statt nachfolgende fertige Auftraege per break abzuschneiden */
            if ((short)(f_1270c0(r + 8) / 0x1518) < *(short *)(r + 6)) { i++; continue; }
#else
            if ((short)(f_1270c0(r + 8) / 0x1518) < *(short *)(r + 6)) break;
#endif
            ((Entry *)tab)[cnt].a = *(short *)(r + 2);
            ((Entry *)tab)[cnt].b = *(short *)(r + 4);
            cnt++; r[1] |= 1;
        }
        i++;
    }
    if (cnt > 0) {
        void *p = new (mark(d_1a63a4, 0x1ab)) Q16;
        if (p) res = f_11c0f0(p, tab, 1);
        else res = p;
    }
#if FIX_R011   /* R011: Temporaeres Uebergabearray tab nach Aufbau des Stock-Objekts freigeben */
    C014710_1((int)tab);
#endif
    return res;
}
