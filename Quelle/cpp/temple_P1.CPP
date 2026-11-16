/* === Beschreibung (Katalog) ===
 * Einheit temple (0x123850 - 0x124810)
 *
 * Überblick
 * Diese Einheit implementiert den ersten Teil der Tempel-Gebäudelogik in Riva (temple.cpp). Sie verwaltet das
 * Betreten der verschiedenen Zwölfgöttertempel (Boron, Travia, Firun, Tsa, Phex, Efferd usw.), das Laden des
 * zugehörigen Gottheits-Objekts (Deity), Gespräche mit den Geweihten, Wunder/Gebete, das Aufnehmen und Entlassen
 * von Helden im Tempel, das Speichern des Spielstands sowie die besonderen Dialoge, wenn die Gruppe den
 * Gegenstand 0x1a2 mitführt.
 === Ende Beschreibung === */
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAMEM.H"
// P3 6/10 gleich (suche.py 23.10.2026, Basis temple_P1.CPP)
// temple.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x123850-0x124810
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01cef0(int p1);                                   // reg eax stapel 0
int f_03f390(int p1, int p2);                           // reg eax edx stapel 0
int f_03f4d0(int p1);                                   // reg eax stapel 0
int f_053fd0(int p1, int p2);                           // reg eax stapel 0
int f_054060(int p1);                                   // reg eax stapel 0
int f_056a50(int p1);                                   // reg eax stapel 0
int f_059d50(int p1); int f_059d50(int p1, int p2);
int f_05b860(int p1, int p2);
int f_09a400();                                         // reg - stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2); 
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0d54f0(int p1, int p2); 
int f_0daa90(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
short f_0de7f0(int p1); 
short f_0de800(int p1); 
short f_0de820(int p1); 
int f_0ea400();                                         // reg - stapel 0
int f_11ea00(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_124810(int p1);                                   // reg eax stapel 0
int f_124a20(int p1);                                   // reg eax stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int p2); 
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bbac4;                    // 0x1BBAC4
extern int d_1bc760;                    // 0x1BC760
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c0004;                    // 0x1C0004
extern signed char d_1c00a8;                    // 0x1C00A8
extern signed char d_1c0c30;                    // 0x1C0C30
extern int d_1c0c34;                    // 0x1C0C34
extern signed char d_1c0c38;                    // 0x1C0C38
extern signed char d_1c0c3c;                    // 0x1C0C3C
extern signed char d_1c0c40;                    // 0x1C0C40
extern signed char d_1c0c44;                    // 0x1C0C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern const char d_1a8b00[];           // Text 0x1A8B00
int f_053f20(int p1, int p2);
int f_145234(int p1, int p2);
int f_145254(int p1);
int f_0bc060(int p1);
int f_0daba0(int p1, int p2);
int f_0bcae0(int p1, int p2, int p3, int p4);
extern int d_1c3498, d_1bf230, d_1a34e0;
extern char d_1bbad8[];
#define EQI(x,v) (((x)==(v))?1:0)
struct T { unsigned short s0; int i2; int i6; char pad0a[28]; unsigned short s26; char pad28[48]; int vp58; short s5c; int i5e; int i62; };
typedef RivaTextContextData OB;
struct S14 { char b[0x14]; };
struct S0e { char b[0xe]; };
struct S652 { char b[0x652]; };
#define B1D0(q) \
  { \
    char *t = new (mark(d_1a8b00, 0xf4)) char; \
    f_11ea00((int)t, 0x220007, (short)(q)->s0, (int)&(q)->i5e, 4); \
    delete t; \
    S14 *o = new (mark(d_1a8b00, 0x104)) S14; \
    o = o ? (S14 *)f_053f20((int)o, *(short *)&(q)->i5e) : o; \
    (q)->i62 = (int)o; \
  }
#define B240(q) \
    int t240 = (q)->i62; if (t240 != 0) delete (char *)f_053fd0(t240, 0);
#define M3(q, fl, X1, X2, X3) \
    if (EQI(fl, 0)) { \
        short s = f_0d54f0(d_1c0004, 0x1a2); \
        if (s != -1) { \
            OB ob; \
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498); \
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s); \
            f_0bf730((int)&d_1c2c64, X1); \
            f_0bf730((int)&d_1c2c64, X2); \
            f_0bf730((int)&d_1c2c64, X3); \
            f_0daaf0(d_1bfdb8, 6); \
            fl = 1; \
            f_1254a0((int)&ob, 0); \
        } \
    }
#define M2(q, fl, X1, X2) \
    if (EQI(fl, 0)) { \
        short s = f_0d54f0(d_1c0004, 0x1a2); \
        if (s != -1) { \
            OB ob; \
            f_125400((int)&ob, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498); \
            *(int *)(ob.addresses.objects + 4) = f_0de7d0(d_1c0004, s); \
            f_0bf730((int)&d_1c2c64, X1); \
            f_0bf730((int)&d_1c2c64, X2); \
            f_0daaf0(d_1bfdb8, 6); \
            fl = 1; \
            f_1254a0((int)&ob, 0); \
        } \
    }
#define B260(q) \
  { \
    if ((q)->s0 == 0x19 && EQI(d_1c00a8, 0)) { f_0ea400(); f_09a400(); } \
    switch ((q)->s0) { \
    case 6: M3(q, d_1c0c30, 0x22000021, 0x22000022, 0x22000023) break; \
    case 0x16: M3(q, d_1c0c34, 0x2200005d, 0x2200005e, 0x2200005f) break; \
    case 0x17: M3(q, d_1c0c38, 0x22000060, 0x22000061, 0x22000062) break; \
    case 0x18: M3(q, d_1c0c3c, 0x22000063, 0x22000064, 0x22000065) break; \
    case 0x1a: M2(q, d_1c0c44, 0x22000068, 0x22000069) break; \
    case 0x19: M2(q, d_1c0c40, 0x22000066, 0x22000067) break; \
    } \
    f_056a50((q)->s26 + 0x150007); \
  }
#define B720(q) \
  { \
    S0e *o = new (mark(d_1a8b00, 0x14d)) S0e; \
    o = o ? (S0e *)f_03f390((int)o, (q)->s5c) : o; \
    f_03f4d0((int)o); \
    delete (char *)o; \
    f_0bc060((int)&d_1bf230); \
    f_0daba0(d_1bfdb8, d_1a34e0); \
    f_0bcae0((int)&d_1bf230, (q)->i6, 0xff, d_1a34e0); \
  }
#define B7A0 \
  { \
    int sv = d_1bfdb8; \
    S652 *o; \
    d_1bfdb8 = 0; \
    f_01cef0(d_1bc760); \
    o = new (mark(d_1a8b00, 0x170)) S652; \
    o = o ? (S652 *)f_059d50((int)o) : o; \
    f_05b860((int)o, 0); \
    if (o) delete (char *)f_059d50((int)o, 0); \
    d_1bfdb8 = sv; \
  }

//@ f_123850
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor eines Tempel-Gebäudeobjekts, der die Gebäude-Basisklasse (f_0b8490) initialisiert, die
 *   virtuelle Methodentabelle (d_1bbad8) einträgt, die Gottheits-Kennung aus der Tempeltabelle (0x220007)
 *   ausliest und das zugehörige Gottheits-Objekt (f_053f20) anlegt.
 * - Eingaben: Die Funktion erhält im Parameter th den this-Zeiger des Tempel-Objekts und in p2 die Gebäude-ID.
 * - Rückgabewert: Die Funktion gibt den initialisierten this-Zeiger (th) zurück.
 === Ende Beschreibung === */
T *f_123850(T *th, short p2)
{
    T *p = (T *)f_0b8490((int)th, p2);
    p->vp58 = (int)d_1bbad8;
    p->i5e = 0;
    th = p;
    p->i62 = 0;
    p->s5c = p2;
    T *q = p;
    B1D0(q)
    return th;
}
//@ f_123900
/* === Beschreibung (Katalog) ===
 * - Zweck: Destruktor eines Tempel-Gebäudeobjekts, der das zugeordnete Gottheits-Objekt (i62), die Basisklasse
 *   (f_0b8520) und bei gesetztem Flag den Objektspeicher freigibt.
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts und in fl die
 *   Destruktor-Flags.
 * - Rückgabewert: Die Funktion gibt den this-Zeiger (p) zurück.
 === Ende Beschreibung === */
T *f_123900(T *p, int fl)
{
    int r;
    if (fl & 4) {
        f_145254(f_145234((int)p, (int)&d_1bbac4));
        return p;
    }
    p->vp58 = (int)d_1bbad8;
    B240(p)
    r = f_0b8520((int)p, 1);
    if (fl & 2) delete (char *)r;
    return (T *)r;
}
//@ f_123980
/* === Beschreibung (Katalog) ===
 * - Zweck: Zentraler Ereignis-Handler des Tempels, der Gespräche mit dem Geweihten (0x81), die Heldenverwaltung
 *   im Tempel (0x82), den Spielstands-Dialog (0x83), Tempelspenden (0x84, f_124810), das Gebet um ein göttliches
 *   Wunder (0x85, f_054060), den Zugang zu den Katakomben bzw. Tempelkellern (0x86) und das Verlassen des
 *   Tempels (0x80, f_124a20) steuert.
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts und in event den ausgelösten
 *   Ereigniscode.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn sich der Orts- oder Gebäudezustand geändert hat, andernfalls
 *   0.
 === Ende Beschreibung === */
int f_123980(T *p, short event)
{
    int changed = 0;
    f_0de800(d_1c0004);
    if (event > 0) {
        if (event != 0x82 && event != 0x83 && !f_0de7f0(d_1c0004)) {
            f_0bf730((int)&d_1c2c64, 0x1c000001);
            event = 0;
        }
        switch ((unsigned short)(event - 0x80)) {
        case 1: {
            T *q = p;

    struct Frame { OB ob19, ob16, ob6, ob18, ob1a, ob17; } frame;
    if (q->s0 == 0x19 && EQI(d_1c00a8, 0)) { f_0ea400(); f_09a400(); }
    switch (q->s0) {
    case 6: {
        if (EQI(d_1c0c30, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob6, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob6.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000021);
                f_0bf730((int)&d_1c2c64, 0x22000022);
                f_0bf730((int)&d_1c2c64, 0x22000023);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c30 = 1;
                f_1254a0((int)&frame.ob6, 0);
            }
        }
        break;
    }
    case 0x16: {
        if (EQI(*(signed char *)&d_1c0c34, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob16, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob16.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x2200005d);
                f_0bf730((int)&d_1c2c64, 0x2200005e);
                f_0bf730((int)&d_1c2c64, 0x2200005f);
                f_0daaf0(d_1bfdb8, 6);
                *(signed char *)&d_1c0c34 = 1;
                f_1254a0((int)&frame.ob16, 0);
            }
        }
        break;
    }
    case 0x17: {
        if (EQI(d_1c0c38, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob17, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob17.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000060);
                f_0bf730((int)&d_1c2c64, 0x22000061);
                f_0bf730((int)&d_1c2c64, 0x22000062);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c38 = 1;
                f_1254a0((int)&frame.ob17, 0);
            }
        }
        break;
    }
    case 0x18: {
        if (EQI(d_1c0c3c, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob18, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob18.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000063);
                f_0bf730((int)&d_1c2c64, 0x22000064);
                f_0bf730((int)&d_1c2c64, 0x22000065);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c3c = 1;
                f_1254a0((int)&frame.ob18, 0);
            }
        }
        break;
    }
    case 0x1a: {
        if (EQI(d_1c0c44, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob1a, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob1a.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000068);
                f_0bf730((int)&d_1c2c64, 0x22000069);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c44 = 1;
                f_1254a0((int)&frame.ob1a, 0);
            }
        }
        break;
    }
    case 0x19: {
        if (EQI(d_1c0c40, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob19, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob19.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000066);
                f_0bf730((int)&d_1c2c64, 0x22000067);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c40 = 1;
                f_1254a0((int)&frame.ob19, 0);
            }
        }
        break;
    }
    }
    f_056a50(q->s26 + 0x150007);

            break;
        }
        case 2: {
            T *q = p;
            B720(q)
            break;
        }
        case 3:
            B7A0
            break;
        case 4:
            f_124810((int)p);
            break;
        case 5:
            f_054060(p->i62);
            break;
        case 6: {
            short b;
            short a = -1;
            b = a;
            switch (p->s0) {
            case 6: b = 5000; a = 2; break;
            case 0x16: b = 0x13fe; a = 2; break;
            case 0x17: b = 0x152a; a = 2; break;
            case 0x18: b = 0x157c; a = 2; break;
            case 0x19: b = 0x14cf; a = 2; break;
            case 0x1a: b = 0x1462; a = 2; break;
            }
            if (a != -1 && b != -1)
                f_0dd7f0(d_1c0004, a, b);
            changed = 1;
            break;
        }
        case 0:
            changed = f_124a20((int)p);
            break;
        }
    }
    if (f_0de800(d_1c0004) != p->s5c)
        changed = 1;
    return changed;
}
//@ f_124080
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktualisiert beim Betreten des Tempels den Zustand der Schaltfläche 6 (Zugang zum hinteren
 *   Tempelbereich bzw. den Katakomben) in der Gebäude-Schaltflächenleiste (d_1bfdb8) anhand der
 *   tempelspezifischen Fortschrittsflags (d_1c0c30 bis d_1c0c44).
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124080(T *p)
{
    int fl = 0;
    signed char t;
    switch (p->s0) {
    case 6:
        if (f_0de820(d_1c0004) == 2) d_1c0c30 = 1;
        t = d_1c0c30; fl = t;
        break;
    case 0x16:
        if (f_0de820(d_1c0004) == 2) *(signed char *)&d_1c0c34 = 1;
        t = d_1c0c34; fl = t;
        break;
    case 0x17:
        if (f_0de820(d_1c0004) == 2) d_1c0c38 = 1;
        t = d_1c0c38; fl = t;
        break;
    case 0x18:
        if (f_0de820(d_1c0004) == 2) d_1c0c3c = 1;
        t = d_1c0c3c; fl = t;
        break;
    case 0x19:
        if (f_0de820(d_1c0004) == 2) d_1c0c40 = 1;
        t = d_1c0c40; fl = t;
        break;
    case 0x1a:
        if (f_0de820(d_1c0004) == 2) d_1c0c44 = 1;
        t = d_1c0c44; fl = t;
        break;
    }
    if (fl == 0) {
        f_0daa90(d_1bfdb8, 6);
    } else {
        f_0daaf0(d_1bfdb8, 6);
    }
}
//@ f_1241c0
/* === Beschreibung (Katalog) ===
 * - Zweck: Leere Platzhalter-Methode in der virtuellen Methodentabelle des Tempel-Objekts.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1241c0(void)
{
}
//@ f_1241d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest aus der Tempeltabelle (0x220007) die Gottheits-Kennung des Tempels p->s0 aus und erzeugt das
 *   zugehörige Gottheits-Objekt (f_053f20) im Feld p->i62.
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1241d0(T *p)
{
    B1D0(p)
}
//@ f_124240
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt das im Feld p->i62 gespeicherte Gottheits-Objekt wieder frei.
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124240(T *p)
{
    B240(p)
}
//@ f_124260
/* === Beschreibung (Katalog) ===
 * - Zweck: Führt das Gespräch mit dem Geweihten des jeweiligen Tempels (p->s0 == 6, 0x16-0x1a) durch, gibt beim
 *   Vorhandensein des Questgegenstands 0x1a2 einmalig eine besondere Textsequenz aus, schaltet die Schaltfläche
 *   6 frei und startet anschließend den regulären Geweihten-Dialog (p->s26 + 0x150007).
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124260(T *p)
{
    struct Frame { OB ob1a, ob19, ob18, ob17, ob16, ob6; } frame;
    if (p->s0 == 0x19 && EQI(d_1c00a8, 0)) { f_0ea400(); f_09a400(); }
    switch (p->s0) {
    case 6: {
        if (EQI(d_1c0c30, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob6, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob6.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000021);
                f_0bf730((int)&d_1c2c64, 0x22000022);
                f_0bf730((int)&d_1c2c64, 0x22000023);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c30 = 1;
                f_1254a0((int)&frame.ob6, 0);
            }
        }
        break;
    }
    case 0x16: {
        if (EQI(*(signed char *)&d_1c0c34, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob16, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob16.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x2200005d);
                f_0bf730((int)&d_1c2c64, 0x2200005e);
                f_0bf730((int)&d_1c2c64, 0x2200005f);
                f_0daaf0(d_1bfdb8, 6);
                *(signed char *)&d_1c0c34 = 1;
                f_1254a0((int)&frame.ob16, 0);
            }
        }
        break;
    }
    case 0x17: {
        if (EQI(d_1c0c38, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob17, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob17.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000060);
                f_0bf730((int)&d_1c2c64, 0x22000061);
                f_0bf730((int)&d_1c2c64, 0x22000062);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c38 = 1;
                f_1254a0((int)&frame.ob17, 0);
            }
        }
        break;
    }
    case 0x18: {
        if (EQI(d_1c0c3c, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob18, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob18.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000063);
                f_0bf730((int)&d_1c2c64, 0x22000064);
                f_0bf730((int)&d_1c2c64, 0x22000065);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c3c = 1;
                f_1254a0((int)&frame.ob18, 0);
            }
        }
        break;
    }
    case 0x1a: {
        if (EQI(d_1c0c44, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob1a, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob1a.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000068);
                f_0bf730((int)&d_1c2c64, 0x22000069);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c44 = 1;
                f_1254a0((int)&frame.ob1a, 0);
            }
        }
        break;
    }
    case 0x19: {
        if (EQI(d_1c0c40, 0)) {
            short s = f_0d54f0(d_1c0004, 0x1a2);
            if (s != -1) {
                f_125400((int)&frame.ob19, (int)&d_1c349c, (int)&d_1c3870, (int)&d_1c3498);
                *(int *)(frame.ob19.addresses.objects + 4) = f_0de7d0(d_1c0004, s);
                f_0bf730((int)&d_1c2c64, 0x22000066);
                f_0bf730((int)&d_1c2c64, 0x22000067);
                f_0daaf0(d_1bfdb8, 6);
                d_1c0c40 = 1;
                f_1254a0((int)&frame.ob19, 0);
            }
        }
        break;
    }
    }
    f_056a50(p->s26 + 0x150007);
}
//@ f_124720
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet im Tempel den Verwaltungsdialog zum Aufnehmen, Entlassen oder Austauschen von
 *   Gruppenmitgliedern (f_03f390, f_03f4d0) und zeichnet danach das Tempel-Hintergrundbild neu.
 * - Eingaben: Die Funktion erhält im Parameter p den this-Zeiger des Tempel-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_124720(T *p)
B720(p)
//@ f_1247a0
/* === Beschreibung (Katalog) ===
 * - Zweck: Öffnet im Tempel das Hauptmenü zum Speichern und Laden des Spielstands (f_059d50, f_05b860).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_1247a0(void)
B7A0
