/* === Beschreibung (Katalog) ===
 * Einheit gz_0da510_t1 (0da510 - 0da910)
 *
 * Überblick
 * Die Einheit gz_0da510_t1 bildet die Fortsetzung und den Abschluss der Quelldatei palfdisk.cpp. Sie enthält den
 * Destruktor und sämtliche virtuellen Dateizugriffsmethoden (vtable d_1bb4b8) der Klasse für teilweise auf
 * Festplatte ausgelagerte ALF-Archive, die je nach Modusflag *(p + 0x86) entweder direkt auf eine Einzeldatei im
 * Dateisystem (*(p + 0x8c)) oder auf das reguläre ALF-Archiv der Basisklasse zugreifen.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 21/26 gleich (suche.py 26.10.2026, Basis gz_0da510_P1.CPP)
// P2 Koepfe Stufe Misch (0 Ueberladungen) (Fable K): 7 gleich (vorher 6), Rest 394 (vorher 398)
// gz_0da510.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DA510-0x0DA910 (Teil 1, Claude801 29.10.: Linker-Nullbyte nach f_0da8f0 = Modulende)
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene ---
struct VB;
int f_013710(char *p, int fl);
int f_013da0(char *p);
int f_013db0ext(VB *p);
#define SEL(A, B) if (*(int *)(p + 0x86) == 1) return A; return B;
#define PT int
#define SX(x) (short)(x)
#define IT short
#define IX(x) (x)
#define STO(p) short dd = ft.d; *(short *)(p + 0xa6) = 1; *(int *)(p + 0xa8) = 0; *(short *)(p + 0xa4) = dd;
#pragma aux f_0db020 modify [edx];
int f_014020(char *p, int e, int x);
int f_014020(char *p, int e);
int f_0141d0(char *p);
int f_0141e0(char *p);
int f_014210(char *p);
int f_014240(char *p);
int f_014280(char *p);
int f_0142a0(char *p, int a, int b);
int f_014300(char *p);
int f_0143c0(char *p, char *q, int x);
int f_0a20a0(int a, int b, int c);
int f_0a2450(int a);
int f_0d26e0();
int f_0d2710();
int f_0d37b0();
int f_0d3860();
int f_0d5b50(int a, int b);
int f_0db020(int a);
int f_0db2f0(char *p);
int f_0db3d0(char *p);
int f_0db4a0(char *p, int a, int b, int c);
int f_0dade0(char *p);

int f_149cf0(int a);
int f_145234(int *p, int *q);
int f_1492b4(char *n, int a, void *b);
int f_1492ed(void *b);
int f_144e8b(int h);
int f_144e8b(int h, int e, int c);
int f_1455a4(int h);
int f_145279(int h, int a, int b);
int f_145259(int h);
int f_145300(char *p, int a, int b);
int f_144fbf(char *n, int m, ...);
void f_014710x(int p);
#define MS(a) memset(a, 0, 8)
#define LKB(v) int v = 0; if (f_0d3860() == 1) { v = 1; f_0d2710(); }
#define LKE(v) if (v == 1) f_0d26e0();
// --- Daten ---
extern short d_1a34e0;
extern int d_1bb4a4;
extern int d_1bb4b8[];
extern unsigned short d_1bd762;
extern short d_1bd766;
extern int d_1be17c;
extern short d_1c2198;
struct VB {
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(int a, int b); virtual int v6(); virtual int v7(int a); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15();
    virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21();
    virtual int v22(); virtual short v23();
};
struct FT { char r[21]; char at; short t; short d; int size; char name[13]; };
struct S28 { int a[7]; };
struct E { short id; short v; int on; int x; };

#pragma inline_depth(0)
#define EQ(x,v) (((x)==(v))?1:0)
int f_013db0(VB *p, int e);   // 0x013DB0, gehoert zu gz_013da0_t1 (nicht hier definieren)
#pragma inline_depth(3)
//@ f_0da510
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zerstört ein Festplatten-Archivobjekt (palfdisk), gibt die unter *(p + 0x82) gespeicherte
 *   Auslagerungstabelle frei, ruft den Basisdestruktor f_013710 auf und gibt bei gesetztem Bit 2 in fl auch den
 *   Objektspeicher frei.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p) sowie die Destruktor-Steuerflags
 *   (fl).
 * - Rückgabewert: Gibt den Zeiger auf das zerstörte Objekt zurück.
 === Ende Beschreibung === */
int f_0da510(int *p, unsigned fl)
{
    int r;
    if (fl & 4) {
        void f_145254();
        f_145234(p, &d_1bb4a4);
        f_145254();
        return (int)p;
    }
    *p = (int)d_1bb4b8;
    if (*(int *)((char *)p + 0x82) != 0) operator delete((void *)*(int *)((char *)p + 0x82));
    r = f_013710((char *)p, 1);
    if (fl & 2) operator delete((void *)r);
    return r;
}
//@ f_0da570
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liefert den Dateinamen des aktuell geöffneten Archiveintrags zurück (im Einzeldateimodus *(p +
 *   0x86) == 1 aus p + 0x90, sonst über die Basismethode f_013da0).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p).
 * - Rückgabewert: Gibt den Zeiger auf den Dateinamen-String zurück.
 === Ende Beschreibung === */
char *f_0da570(char *p)
{
    SEL(p + 0x90, (char *)f_013da0(p))
}

//@ f_0da590
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Leitet die Abfrage des Archivstatus direkt an die Basisklassenmethode f_013db0 weiter.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p) sowie ein Zusatzparameter (e).
 * - Rückgabewert: Gibt den Rückgabewert der Basismethode f_013db0 zurück.
 === Ende Beschreibung === */
int f_0da590(VB *p, int e)
{
    return f_013db0ext(p);
}

//@ f_0da5a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Gibt den Index des aktuell geöffneten Archiveintrags zurück (im Einzeldateimodus aus *(short *)(p +
 *   0x8a), sonst über die Basismethode f_014300).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p).
 * - Rückgabewert: Gibt den aktuellen Eintragsindex als 16-Bit-Wert zurück.
 === Ende Beschreibung === */
short f_0da5a0(char *p)
{
    SEL(*(short *)(p + 0x8a), f_014300(p))
}
//@ f_0da5c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Sucht einen Archiveintrag anhand seiner Ressourcenkennung (e), indem der Eintrag im Basisarchiv
 *   kurz geöffnet (f_014020), sein Index über f_014300 abgefragt und das Archiv sofort wieder geschlossen wird
 *   (f_014210).
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p) sowie die gesuchte
 *   Ressourcenkennung (e).
 * - Rückgabewert: Gibt den gefundenen Eintragsindex oder -1 zurück, falls der Eintrag nicht existiert.
 === Ende Beschreibung === */
int f_0da5c0(char *p, int e)
{
    int r = -1;
    if (f_014020(p, e, 0x200) == 1) {
        r = (short)f_014300(p);
        f_014210(p);
    }
    return r;
}
//@ f_0da5f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Füllt eine 28-Byte-Eintragsstruktur (dst) für den Archiveintrag idx und aktualisiert zuvor
 *   Dateigröße, Zeit und Datum über _dos_findfirst (f_1492b4), falls dieser Eintrag laut Auslagerungstabelle *(p
 *   + 0x82) als Einzeldatei auf der Festplatte liegt.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p), der Zielpuffer für die
 *   28-Byte-Eintragsstruktur (dst) sowie der Eintragsindex (idx).
 * - Rückgabewert: Gibt 1 zurück, wenn ein gültiger Eintragsname vorliegt (*(p + 0x90) != 0), sonst 0.
 === Ende Beschreibung === */
int f_0da5f0(char *p, int *dst, IT idx)
{
    FT ft;
    if (*(signed char **)(p + 0x82) != 0 && (*(signed char **)(p + 0x82))[IX(idx)] != 0) {
        f_0143c0(p, p + 0x90, IX(idx));
        if (f_1492b4(p + 0x90, 0x20, &ft) == 0) {
            *(int *)(p + 0x9e) = ft.size;
            *(short *)(p + 0xa2) = ft.t;
            STO(p)
        }
        f_1492ed(&ft);
    } else {
        f_0143c0(p, p + 0x90, IX(idx));
    }
    *(S28 *)dst = *(S28 *)(p + 0x90);
    return *(signed char *)(p + 0x90) != 0;
}
//@ f_0da6b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Dient als virtuelle Leerfunktion der palfdisk-Methodentabelle, die stets 0 liefert.
 * - Eingaben: Diese Funktion erhält keine verwendeten Parameter.
 * - Rückgabewert: Gibt konstant 0 zurück.
 === Ende Beschreibung === */
int f_0da6b0()
{
    return 0;
}
//@ f_0da6c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet einen Archiveintrag (e) mit den Zugriffsflags x: prüft anhand der Auslagerungstabelle *(p +
 *   0x82), ob der Eintrag als separate Datei im Dateisystem vorliegt, öffnet ihn in diesem Fall direkt über
 *   f_144fbf (*(p + 0x86) = 1) und greift bei Fehlschlag oder nicht ausgelagertem Eintrag auf das gepackte
 *   Basisarchiv (f_014020) zurück.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p), die Ressourcenkennung (e) sowie
 *   die Dateizugriffsflags (x).
 * - Rückgabewert: Gibt 1 bei erfolgreichem Öffnen oder den Statuscode von f_014020 zurück.
 === Ende Beschreibung === */
int f_0da6c0(VB *p, int e, short x)
{
    short idx;
    int r = 1;
    FT ft;
    short s = p->v23();
    *(short *)((char *)p + 0x8a) = s;
    int t153_20;
    if (*(signed char **)((char *)p + 0x82) && (t153_20 = (*(signed char **)((char *)p + 0x82))[s])) {
        char *name;
        idx = *(short *)((char *)p + 0x8a);
        f_0143c0((char *)p, name = (char *)p + 0x90, idx);
        if (f_1492b4(name, 0x20, &ft) == 0) {
            *(int *)((char *)p + 0x9e) = ft.size;
            *(short *)((char *)p + 0xa2) = ft.t;
            STO((char *)p)
        }
        int y = x;
        f_1492ed(&ft);
        int h = *(int *)((char *)p + 0x8c) = f_144fbf((char *)p + 0x90, y);
        if (h < 0) {
            r = f_014020((char *)p, e, y);
        } else {
            *(int *)((char *)p + 0x86) = 1;
        }
    } else {
        r = f_014020((char *)p, e, (*&x));
    }
    return r;
}
//@ f_0da7b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Öffnet den Archiveintrag e über die virtuelle Öffnen-Methode (v5), liest den gesamten Inhalt über
 *   die virtuelle Lesemethode (v7) in den Zielpuffer x und schließt den Eintrag über v10 wieder.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p), die Ressourcenkennung (e) sowie
 *   die Zielpufferadresse (x).
 * - Rückgabewert: Gibt 1 bei Erfolg oder 0 zurück, wenn der Eintrag nicht geöffnet werden konnte.
 === Ende Beschreibung === */
int f_0da7b0(VB *p, int e, int x)
{
    int r = 0;
    if (p->v5(e, 0x200) == 1) {
        p->v7(x);
        p->v10();
        r = 1;
    }
    return r;
}
//@ f_0da7f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest den kompletten aktuell geöffneten Archiveintrag in den Puffer e (im Einzeldateimodus über
 *   f_144e8b mit der Dateigröße *(p + 0x9e), sonst über die Basismethode f_0141d0).
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p) sowie die Zielpufferadresse (e).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0da7f0(char *p, int e)
{
    if (*(int *)(p + 0x86) == 1) f_144e8b(*(int *)(p + 0x8c), e, *(int *)(p + 0x9e));
    else f_0141d0(p);
}
//@ f_0da820
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Liest einen Datenblock aus dem aktuell geöffneten Archiveintrag (im Einzeldateimodus direkt aus dem
 *   Dateihandle *(p + 0x8c) über f_144e8b, sonst über die Basismethode f_0141e0).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p) samt den in Registern übergebenen
 *   Leseparametern.
 * - Rückgabewert: Gibt die Anzahl der gelesenen Bytes zurück.
 === Ende Beschreibung === */
int f_0da820(char *p)
{
    SEL(f_144e8b(*(int *)(p + 0x8c)), f_0141e0(p))
}
//@ f_0da840
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Schließt den aktuell geöffneten Archiveintrag (im Einzeldateimodus durch Schließen des Dateihandles
 *   *(p + 0x8c) über f_145259 und Zurücksetzen von *(p + 0x86) = 0, sonst über die Basismethode f_014210).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p).
 * - Rückgabewert: Gibt 1 bzw. den Rückgabewert von f_014210 zurück.
 === Ende Beschreibung === */
int f_0da840(char *p)
{
    int m = *(int *)(p + 0x86);
    if (m == 1) {
        f_145259(*(int *)(p + 0x8c));
        *(int *)(p + 0x8c) = -1;
        *(int *)(p + 0x86) = 0;
        return m;
    }
    return f_014210(p);
}
//@ f_0da880
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Gibt die Dateigröße des aktuell geöffneten Archiveintrags in Bytes zurück (im Einzeldateimodus aus
 *   *(p + 0x9e), sonst über die Basismethode f_014240).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p).
 * - Rückgabewert: Gibt die Größe des Eintrags in Bytes zurück.
 === Ende Beschreibung === */
int f_0da880(char *p)
{
    SEL(*(int *)(p + 0x9e), f_014240(p))
}
//@ f_0da8a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt die Dateigröße eines Archiveintrags e, indem der Eintrag über die virtuelle Methode v5
 *   geöffnet, seine Größe über v12 abgefragt und der Eintrag über v10 sofort wieder geschlossen wird.
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p) sowie die Ressourcenkennung (e).
 * - Rückgabewert: Gibt die Dateigröße in Bytes oder 0 zurück, falls der Eintrag nicht geöffnet werden konnte.
 === Ende Beschreibung === */
int f_0da8a0(VB *p, int e)
{
    int r = 0;
    if (p->v5(e, 0x200) == 1) {
        r = p->v12();
        p->v10();
    }
    return r;
}
//@ f_0da8d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Fragt die aktuelle Lese-/Schreibposition (tell) innerhalb des geöffneten Archiveintrags ab (im
 *   Einzeldateimodus über f_1455a4, sonst über die Basismethode f_014280).
 * - Eingaben: Übergeben wird der Zeiger auf das Festplatten-Archivobjekt (p).
 * - Rückgabewert: Gibt den aktuellen Dateiversatz in Bytes zurück.
 === Ende Beschreibung === */
int f_0da8d0(char *p)
{
    SEL(f_1455a4(*(int *)(p + 0x8c)), f_014280(p))
}
//@ f_0da8f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Positioniert den Dateizeiger (seek) innerhalb des geöffneten Archiveintrags auf den Offset a gemäß
 *   Modus x (im Einzeldateimodus über f_145279, sonst über die Basismethode f_0142a0).
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p), der Zieloffset (a) sowie der
 *   Positionierungsmodus (x).
 * - Rückgabewert: Gibt die neue Dateiposition bzw. den Statuswert des Seek-Aufrufs zurück.
 === Ende Beschreibung === */
int f_0da8f0(char *p, int a, short x)
{
    if (*(int *)(p + 0x86) == 1) return f_145279(*(int *)(p + 0x8c), a, x);
    return f_0142a0(p, a, x);
}