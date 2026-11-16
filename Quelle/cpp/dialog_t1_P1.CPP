/* === Beschreibung (Katalog) ===
 * Einheit dialog_t1 (055120 - 056930)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil des allgemeinen Dialog-Systems (dialog.cpp) von *Schatten über Riva*. Sie
 * verwaltet die temporäre Dialog-Statusdatei im Spielstand (0x40000000), wertet bis zu 70 verschiedene
 * Vorbedingungen für Gesprächsoptionen aus (f_055650), führt bis zu 31 verschiedene Dialog-Folgeaktionen aus
 * (f_056030, wie Tagebucheinträge, Goldabzug, Talentproben oder Kampfstart) und setzt variable Textbausteine wie
 * Heldennamen in Dialogtexte ein (f_056450).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 5/8 gleich (suche.py 28.10.2026, Basis dialog_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 2 gleich (vorher 2), Rest 936 (vorher 954)
#define EQI(x,v) (((x)==(v))?1:0)
// P1 0/8 gleich
// dialog.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Teil t1 0x055120-0x056930
#include <string.h>
#define A(x) ((int)(x))
int f_038c40(int p1);

int f_039040(int p1);
int f_0391b0(int p1, int p2);
int f_039320(int p1, int p2);



short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_057220(int p1, int p2, int p3);
int f_0b8a00(int p1, int p2);
int f_0d4a10(int p1);
int f_0d5ff0(int p1);
int f_0db8b0(int p1, int p2);
short f_0db970(int p1);
short f_0dbfe0(int p1);
signed char f_0dd410(int p1, int p2);
int f_0de7e0(int p1);
int f_0e93f0(int p1, int p2, int p3);
int f_11f550(int p1);
int f_125400(int p1, int p2, int p3, int p4);
int f_1254a0(int p1, int);
int f_125ed0(int p1, int p2);
int f_125f70(int p1, int p2);
int f_126f40(int p1, int p2);
#pragma aux f_126f40 parm [eax edx] modify exact [eax];
int f_1270c0(int p1);
short f_143350(int p1, int p2);
int f_143390(int p1);
int f_1433c0(int p1);
int f_1433d0(int p1, int p2, int p3);
int f_1434f0(int p1);


#pragma aux f_144890 modify exact [eax edx ecx];





short f_145760(int p1, int p2);
short f_1457e0(int p1);
int __cdecl f_14572e(char *p1, const char *p2, int p3);
extern char *d_1a965c;
extern char *d_1a1688;
extern char *d_1a168c;
extern char *d_1a1690;
extern char *d_1a1694;
extern char *d_1a1698;
extern signed char d_1bc76c, d_1bc788, d_1bc790, d_1bc7f0;
extern signed char d_1bca68, d_1bca69;
extern int d_1bca6c, d_1bca70;
extern signed char *d_1bca74;
extern short *d_1bca78;
extern signed char d_1bca7c, d_1bca80, d_1bca84, d_1bca88, d_1bca8c, d_1bca90, d_1bca94, d_1bca98, d_1bca9c;
extern signed char d_1bcaa0, d_1bcaa4, d_1bcaa8, d_1bcaac, d_1bcab0;
extern short d_1bcab4;
extern signed char d_1bdcf4, d_1bdcf8, d_1bed74;
extern int d_1bf1ac, d_1c0004;
extern signed char d_1c00a0, d_1c00a4, d_1c00a8, d_1c00ac, d_1c00bc, d_1c00c0, d_1c00c4;
extern signed char d_1c01b8, d_1c01e0, d_1c01f4;
extern char  d_1c21b4[], d_1c21b8[], d_1c27a8[], d_1c2c00[], d_1c2c44[], d_1c349c[], d_1c3870[], d_1c38b0[];
extern const char d_1a1668[];
extern const char d_1b6e14[];
struct F7 { int a; signed char b, c, d; };
struct Q4 { char c[4]; };

//@ f_055120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt die Dialog-Zustandsdatei (0x40000000) im aktuellen Spielstandverzeichnis neu an, falls
 *   sie noch nicht existiert, und initialisiert darin die Gesprächs-Flags, Zähler und den Zeitstempel.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Über den Dateimanager d_1c2098 werden 0x67 Dialogeinträge zu je 0x24 Bytes, das
 *   12-Byte-Flagarray (d_1a1690), das 0xce-Byte-Zählerarray (d_1a1694) und die 7-Byte-Datumsstruktur (d_1a1698)
 *   geschrieben.
 === Ende Beschreibung === */
void f_055120(void)
{
    int call_144890(int, int);
    #pragma aux call_144890 "f_144890" parm [eax] [edx] value [eax] modify exact [eax edx edi];
    char *call_145300(void *, int, unsigned);
    #pragma aux call_145300 "f_145300" parm [eax] [edx] [ebx] value [edi] modify exact [eax edx ebx ecx];
    void call_144960_first(int, int, int);
    #pragma aux call_144960_first "f_144960" parm [eax] [edx] [ebx] modify exact [eax edx ebx];
    F7 s;
    char *sv = d_1a965c;
    int local_1c = 0;
    d_1a965c = d_1a1688;
    if (!((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144870( 0x40000000)) {
        memcpy(d_1c21b4, &local_1c, 4);
        char *out = call_145300(d_1c21b8, 0, 0x20);
        call_144890(A(((char*)&d_1c2098)), 0x40000000);
        int i = 0;
        call_144960_first(A(((char*)&d_1c2098)), A(d_1a168c), 6);
        for (; i < 0x67; i++)
            ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(out)), 0x24)));
        memset(d_1c21b4, 0, 0xc);
        d_1c21b4[1] = d_1c21b4[0] = 1;
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1a1690)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1c21b4)), 0xc)));
        memset(d_1c21b4, 0, 0xce);
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1a1694)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1c21b4)), 0xce)));
        s.a = 0;
        s.b = 0;
        s.c = 0;
        s.d = 0;
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1a1698)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(&s)), 7)));
        ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1449a0();
    }
    d_1a965c = sv;
}

//@ f_0552a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt vor Gesprächsbeginn die globalen Dialog-Flags (d_1bca74) und Gesprächszähler (d_1bca78)
 *   aus der Datei 0x40000000 und verringert die Gesprächszähler automatisch um ein Viertel der seit dem letzten
 *   Gespräch verstrichenen Spieltage (sofern mindestens 4 Tage vergangen sind).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter (void) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das dynamisch reservierte Array d_1bca74 (12 Bytes) hält globale Dialogflags, d_1bca78
 *   (0x67 short-Werte) speichert Gesprächs-Ermüdungszähler pro NPC, und f_1270c0 berechnet die seit dem
 *   gespeicherten Datum s verstrichene Spielzeit.
 === Ende Beschreibung === */
void f_0552a0(void)
{
    struct Div { static inline short quarter(short x) { x /= 4; return x; } };
    int shift_date(int, void *);
    #pragma aux shift_date "f_126f40" parm [edx] [eax] value [eax] modify exact [eax];
    short t140_24;
    F7 s;
    char *sv = d_1a965c;
    int ok;
    short days, k, i;
    d_1a965c = d_1a1688;
    if (((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1448b0( 0x40000000, 0x202) == 1) {
        ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144ab0( 0xe82, 0);
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1c21b4)), 6)));
        d_1bca74 = new (mark(d_1a1668, 0x139)) signed char[0xc];
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1bca74)), 0xc)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1c21b4)), 6)));
        d_1bca78 = new (mark(d_1a1668, 0x144)) short[0x67];
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1bca78)), 0xce)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1c21b4)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(&s)), 7)));
        if (s.a != 0 || s.b != 0 || s.c != 0 || s.d != 0) {
            days = f_1270c0(A(&s)) / 0x1518;
            ok = 0;
            if (days > 3) {
                k = Div::quarter(days);
                for (i = 0; i < 0x67; i++) {
                    short *p = d_1bca78 + i;
                    *p -= k;
                    if ((t140_24 = *p) < 0) *p = 0;
                }
                ok = 1;
            }
        } else {
            ok = 1;
        }
        if ((int)ok == (short)1) {
            shift_date(-7, &s);
            ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144ab0( -7, ok);
            ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(&s)), 7)));
        }
        ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1449a0();
    }
    d_1a965c = sv;
}

//@ f_055460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die im Speicher gehaltenen Dialog-Flags (d_1bca74) und Gesprächszähler (d_1bca78)
 *   zurück in die Datei 0x40000000 und gibt deren Heap-Puffer wieder frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Zeiger d_1bca74 und d_1bca78 werden ab Offset 0xe82 in die Datei 0x40000000
 *   gesichert und anschließend mit delete freigegeben.
 === Ende Beschreibung === */
void f_055460(void)
{
    char *sv = d_1a965c;
    d_1a965c = d_1a1688;
    if (((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1448b0( 0x40000000, 0x202) == 1) {
        ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144ab0( 0xe82, 0);
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1c21b4)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1bca74)), 0xc)));
        delete d_1bca74;
        d_1bca74 = 0;
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144920((void *)( A(d_1c21b4)), 6)));
        ((int)(((RivaFileManager*)(A(((char*)&d_1c2098))))->f_144960((void *)( A(d_1bca78)), 0xce)));
        delete d_1bca78;
        d_1bca78 = 0;
        ((RivaFileManager*)(A(((char*)&d_1c2098))))->f_1449a0();
    }
    d_1a965c = sv;
}

//@ f_055650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wertet im Dialog-Skriptinterpreter eine von 70 nummerierten Gesprächs-Vorbedingungen (case 0
 *   bis case 70) aus, etwa ob der Anführer männlich oder weiblich ist, ob bestimmte Quest-Flags gesetzt sind, ob
 *   mindestens ein Held lebt oder ob mehr Gruppenmitglieder tot als lebendig sind.
 * - Eingaben und Rückgabe: Die Funktion erhält die Bedingungsnummer p (unsigned short) und gibt als short den
 *   Wahrheitswert 1 (Bedingung erfüllt) oder 0 (nicht erfüllt) zurück.
 * - Wichtige Variablen: Geprüft werden zahlreiche globale Quest- und Dialogflags (d_1bca68 bis d_1bcab4,
 *   d_1bc76c, d_1bc788, d_1bc790, d_1c00a0 bis d_1c01f4) sowie der Zustand der Heldengruppe d_1c0004. Hinweis
 *   auf Originalfehler: Die Fälle case 42 und case 43 sind exakte Copy-Paste-Duplikate von case 40 und case 41
 *   (beide Paare testen d_1bc788 == 1 bzw. d_1bc788 == 0, statt in case 42/43 das Nachbarflag d_1bc78c zu
 *   prüfen).
 === Ende Beschreibung === */
short f_055650(unsigned short p)
{
    struct Flags {
        static inline unsigned char zero(signed char x) { return x == 0; }
        static inline signed char get(const signed char &x) { return x; }
        static inline int eq(const signed char &x, signed char v) { return x == v; }
        static inline int eqi(const signed char &x, int v) { return x == v; }
        static inline int gt(const signed char &x, signed char v) { return x > v; }
    };
    int person, next;
    short alive, dead;
    int result = 1;
    signed char flag;
    switch (p) {
    case 0: break;
    case 1: { result = d_1bca69; return result; }
    case 2: if (f_0dbfe0(d_1c0004) != 1) break; { result = 0; return result; }
    case 3: if (f_042380((struct hero *)(f_038c40(d_1c0004))) != 0) break; { result = 0; return result; }
    case 4: if (f_042380((struct hero *)(f_038c40(d_1c0004))) != 1) break; { result = 0; return result; }
    case 5: if (f_0dbfe0(d_1c0004) == 1) break; { result = 0; return result; }
    case 6:
        flag = 1;
        if (Flags::eq(d_1c01e0, flag) && Flags::gt(d_1bdcf8, 1)) break;
        { result = 0; return result; }
    case 7: { result = Flags::get(d_1c01e0); return result; }
    case 8: flag = 1; if (Flags::gt(d_1bdcf4, flag)) break; { result = 0; return result; }
    case 9: { result = Flags::get(d_1c01f4); return result; }
    case 10: { result = Flags::get(d_1c00a0) == 0; return result; }
    case 11: { result = Flags::get(d_1c00a0); return result; }
    case 12: { result = Flags::get(d_1c00a4); return result; }
    case 13: flag = 1; if (Flags::eq(d_1c00a8, flag) && Flags::eq(d_1bc76c, 0)) break; { result = 0; return result; }
    case 14: { result = Flags::get(d_1c00ac); return result; }
    case 15: { result = Flags::get(d_1c00ac) == 0; return result; }
    case 16: { result = Flags::get(d_1bca8c); return result; }
    case 17: { result = Flags::get(d_1bca8c) == 0; return result; }
    case 18: { result = Flags::get(d_1bca84); return result; }
    case 19: { result = Flags::get(d_1bca84) == 0; return result; }
    case 21: { result = Flags::get(d_1bcaa0); return result; }
    case 20: { result = Flags::get(d_1bcaa0) == 0; return result; }
    case 22:
        person = f_038c40(d_1c0004);
        result = 0;
        do {
            if (f_042380((struct hero *)(person)) == 0 && f_0d4a10(person) == 1) result = 1;
            next = f_0391b0(d_1c0004, person);
            person = next;
        } while (next != f_038c40(d_1c0004));
        return result;
    case 23: { result = d_1bca68 == 0; return result; }
    case 24: { result = d_1bca68; return result; }
    case 25:
        flag = 1;
        if (Flags::eq(d_1bc76c, flag) && Flags::eqi(*(signed char *)&d_1bcab4, 1) && Flags::eq(d_1bc790, 0)) break;
        { result = 0; return result; }
    case 26:
        flag = 1;
        if (Flags::eq(d_1bc76c, flag) && Flags::eqi(*(signed char *)&d_1bcab4, 1) && Flags::eq(d_1bc790, 0)) { result = 0; return result; }
        break;
    case 27: { result = Flags::get(d_1c00c0); return result; }
    case 28: { result = Flags::get(d_1c00c0) == 0; return result; }
    case 29: { result = Flags::get(d_1c01b8); return result; }
    case 30: if (d_1bca6c == 1) break; { result = 0; return result; }
    case 31: if (d_1bca6c == 2) break; { result = 0; return result; }
    case 32: if (d_1bca6c == 3) break; { result = 0; return result; }
    case 33: { result = Flags::get(d_1bcaa4); return result; }
    case 34: { result = Flags::get(d_1c00c4); return result; }
    case 35: { result = Flags::get(d_1c00c4) == 0; return result; }
    case 36: { result = Flags::get(d_1c00bc); return result; }
    case 37: { result = Flags::zero(Flags::get(d_1c00bc)); return result; }
    case 38: flag = 1; if (Flags::eq(d_1bc7f0, flag)) break; { result = 0; return result; }
    case 39: flag = 0; if (Flags::eq(d_1bc7f0, flag)) break; { result = 0; return result; }
    case 40:  if (Flags::eq(d_1bc788, (signed char)1)) break; { result = 0; return result; }
    case 41:  if (Flags::eq(d_1bc788, (signed char)0)) break; { result = 0; return result; }
#if FIX_R074   /* R074: In case 42/43 das Nachbarflag d_1bc78c statt nochmals d_1bc788 pruefen */
    case 42:  { extern signed char d_1bc78c; if (Flags::eq(d_1bc78c, (signed char)1)) break; { result = 0; return result; } }
    case 43:  { extern signed char d_1bc78c; if (Flags::eq(d_1bc78c, (signed char)0)) break; { result = 0; return result; } }
#else
    case 42:  if (Flags::eq(d_1bc788, (signed char)1)) break; { result = 0; return result; }
    case 43:  if (Flags::eq(d_1bc788, (signed char)0)) break; { result = 0; return result; }
#endif
    case 44: { result = Flags::get(d_1bca90); return result; }
    case 45: { result = Flags::get(d_1bca90) == 0; return result; }
    case 46: { result = Flags::get(d_1bca94) == 0; return result; }
    case 47: { result = Flags::get(d_1bca98) == 0; return result; }
    case 48: { result = Flags::get(d_1bca9c) == 0; return result; }
    case 49: if (d_1bca70 == 1) break; { result = 0; return result; }
    case 50: if (d_1bca70 == 2) break; { result = 0; return result; }
    case 51: if (d_1bca70 == 3) break; { result = 0; return result; }
    case 52: if (d_1bca70 == 4) break; { result = 0; return result; }
    case 53:  if (Flags::gt(d_1bca7c, (signed char)0)) break; { result = 0; return result; }
    case 54:
        
        if (Flags::eq(d_1bca7c, (signed char)0)) { result = 1; return result; }
        break;
    case 55: { result = Flags::get(d_1bca88); return result; }
    case 56: { result = Flags::get(d_1bca88) == 0; return result; }
    case 57:
        person = f_038c40(d_1c0004);
        do {
            if (f_042380((struct hero *)(person)) == 0 && f_0d4a10(person) == 1) result = 0;
            next = f_0391b0(d_1c0004, person);
            person = next;
        } while (next != f_038c40(d_1c0004));
        return result;
    case 58:
        person = f_038c40(d_1c0004);
        alive = 0;
        dead = 0;
        do {
            if (f_0d4a10(person) == 1) {
                if (f_042380((struct hero *)(person)) == 0) ++alive;
                else ++dead;
            }
            next = f_0391b0(d_1c0004, person);
            person = next;
        } while (next != f_038c40(d_1c0004));
        if (alive > 0 && dead > alive) break;
        { result = 0; return result; }
    case 59: { result = Flags::get(d_1bcaa8) == 0; return result; }
    case 60: { result = Flags::get(d_1bcaac) == 0; return result; }
    case 61: { result = Flags::get(d_1bcaac); return result; }
    case 62: { result = Flags::get(d_1bcab0) == 0; return result; }
    case 63:
        result = 0;
        if (Flags::eqi(d_1bc790, 1) && Flags::eq(d_1bca80, 0)) result = 1;
        break;
    case 67:
        person = f_038c40(d_1c0004);
        do {
            if (f_042380((struct hero *)(person)) == 1 && f_0d4a10(person) == 1) result = 0;
            next = f_0391b0(d_1c0004, person);
            person = next;
        } while (next != f_038c40(d_1c0004));
        return result;
    case 68:
        person = f_038c40(d_1c0004);
        result = 0;
        do {
            if (f_042380((struct hero *)(person)) == 1 && f_0d4a10(person) == 1) result = 1;
            next = f_0391b0(d_1c0004, person);
            person = next;
        } while (next != f_038c40(d_1c0004));
        return result;
    case 69:
        person = f_039040(d_1c0004);
        result = 0;
        if (person && f_042400((struct hero *)(person)) == 1) result = 1;
        break;
    case 70:
        person = f_039040(d_1c0004);
        if (person && f_042400((struct hero *)(person)) == 1) result = 0;
        break;
    }
    return result;
}

//@ f_055f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt unter allen lebenden und anwesenden Helden der Gruppe denjenigen mit dem höchsten
 *   Charisma-Wert (Attribut 2), damit dieser in bestimmten Dialogszenen als Sprecher auftritt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (void) und gibt den Zeiger auf die
 *   Heldenstruktur mit dem höchsten Charisma als int zurück.
 * - Wichtige Variablen: Die Schleife durchläuft alle Helden in d_1c0004 und vergleicht deren aktuellen
 *   Attributswert f_042a40(hero, 2) (Charisma).
 === Ende Beschreibung === */
int f_055f30(void)
{
    signed char c1;
    signed char c2;
    int p = f_038c40(d_1c0004);
    int best = 0;
    do {
        if (f_042380((struct hero *)(p)) == 0 && f_0d4a10(p) == 1) {
            if (best != 0) {
                c1 = f_042a40((struct hero *)(p), 2);
                c2 = f_042a40((struct hero *)(best), 2);
                if (c1 <= c2) goto next;
            }
            best = p;
        }
    next:
        p = f_0391b0(d_1c0004, p);
    } while (p != f_038c40(d_1c0004));
    return best;
}

//@ f_056030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine von 31 nummerierten Dialog-Aktionen (case 0 bis case 0x1f) aus, wenn ein
 *   entsprechender Gesprächsknoten erreicht wird - darunter das Setzen von Quest-Flags, das Eintragen von
 *   Tagebuchnotizen (f_057220), das Abziehen von 10 Silbertalern (case 16), eine Charisma-Probe (case 0x1c) oder
 *   eine Menschenkenntnis-/Bekehren-Probe (case 0x1f).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf das laufende Dialogfenster p1 sowie die
 *   Aktionsnummer p2 (unsigned short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: In case 0x1c wird eine Eigenschaftsprobe f_044900 auf Charisma für den charismatischsten
 *   Helden abgelegt und das Ergebnis in d_1bca68 gespeichert; in case 0x1f wird für den besten Helden im Talent
 *   0x18 eine Talentprobe f_044c90 gewürfelt und das Ergebnis in d_1bca69 vermerkt.
 === Ende Beschreibung === */
void f_056030(int p1, unsigned short p2)
{
    int call_125f70(int, int);
    #pragma aux call_125f70 "f_125f70" parm [edx] [eax];
    int call_125ed0(int, int);
    #pragma aux call_125ed0 "f_125ed0" parm [edx] [eax];
    struct Store {static inline void set(signed char v, signed char &x) {x=v;}};
    unsigned a, b;
    signed char c1, c2;
    short s;
    short u;
    switch (p2) {
    default: goto C_default1116;
    case 0: goto C_0_1116;
    case 1: goto C_1_1116;
    case 2: goto C_2_1116;
    case 3: goto C_3_1116;
    case 4: goto C_4_1116;
    case 6: goto C_6_1116;
    case 7: goto C_7_1116;
    case 8: goto C_8_1116;
    case 9: goto C_9_1116;
    case 0x1e: goto C_30_1116;
    case 10: goto C_10_1116;
    case 0xb: goto C_11_1116;
    case 0xc: goto C_12_1116;
    case 0xd: goto C_13_1116;
    case 5: goto C_5_1116;
    case 0xe: goto C_14_1116;
    case 0xf: goto C_15_1116;
    case 0x10: goto C_16_1116;
    case 0x1b: goto C_27_1116;
    case 0x11: goto C_17_1116;
    case 0x12: goto C_18_1116;
    case 0x13: goto C_19_1116;
    case 0x14: goto C_20_1116;
    case 0x15: goto C_21_1116;
    case 0x16: goto C_22_1116;
    case 0x17: goto C_23_1116;
    case 0x18: goto C_24_1116;
    case 0x19: goto C_25_1116;
    case 0x1a: goto C_26_1116;
    case 0x1d: goto C_29_1116;
    case 0x1f: goto C_31_1116;

C_default1116:
C_0_1116:
        return;
C_1_1116:
        d_1bca74[6] = 1;
        f_1433c0(p1);
        return;
C_2_1116:
        d_1bca74[5] = 1;
        f_1433c0(p1);
        return;
C_3_1116:
        d_1bca74[7] = 1;
        f_1433c0(p1);
        return;
C_4_1116:
        d_1bca74[4] = 1;
        f_1433c0(p1);
        if (EQI(d_1bed74, 0)) f_057220(A(d_1c2c00), 0x803000e, 0);
        d_1bed74 = 1;
        return;
C_6_1116: {
        // Haelt die Vorlistenposition vor dem Vergleichstripel
        int rt902=d_1c0004; d_1c0004=rt902;
        s = f_143350(p1, 0);
        f_143350(p1, (short)(5 - s));
        return;
    }
C_7_1116: {
        struct H { static int eq(const signed char &x, signed char v) { return x == v; } };
        if (H::eq(d_1bc76c, 0)) {
            if (f_0dd410(d_1c0004, 0) == 1)
                f_057220(A(d_1c2c00), 0x8030001, 0);
            else
                f_057220(A(d_1c2c00), 0x8030002, 0);
        }
        d_1bc76c = 1;
        *(signed char *)&d_1bcab4 = 1;
        return;
    }
C_8_1116:
        Store::set(1,d_1bca8c);
        return;
C_9_1116:
C_30_1116: {
        int rt9_1116=d_1c0004; d_1c0004=rt9_1116; // Haelt die Sortierposition fuer d_1c0004
        f_0b8a00(d_1bf1ac, -1);
        f_143390(p1);
        return;
    }
C_10_1116:
        call_125f70(1, A(d_1c2c44));
        return;
C_11_1116:
        f_0d5ff0(2);
        f_143390(p1);
        return;
C_12_1116:
        f_11f550(d_1bf1ac);
        return;
C_13_1116:
        call_125ed0(0x1e, A(d_1c2c44));
C_5_1116:
        f_143390(p1);
        return;
C_14_1116:
        f_0d5ff0(1);
        return;
C_15_1116:
        d_1bca6c = f_1457e0(3);
        return;
C_16_1116:
        if (f_0de7e0(d_1c0004) >= 10) {
            d_1bcaa4 = 1;
            // Alias-Stores halten die Registerwahl in Fall 7 auf BH
            *(unsigned char *)&d_1bcaa4 = 1;
            *(signed char *)&d_1bcaa4 = 1;
            *(unsigned char *)&d_1bcaa4 = 1;
            *(signed char *)&d_1bcaa4 = 1;
            // Objekt-Roundtrip haelt den Dialogzeiger bis nach den Stores lebendig
            int round1116 = *(int *)p1; *(int *)p1 = round1116;
            f_0db8b0(d_1c0004, 10);
            return;
        }
        d_1bcaa4 = 0;
        // Redundante Byte-Stores halten die Registerwahl vor dem Erfolgszweig auf AL
        *(unsigned char *)&d_1bcaa4 = 0;
        *(signed char *)&d_1bcaa4 = 0;
        *(unsigned char *)&d_1bcaa4 = 0;
        *(signed char *)&d_1bcaa4 = 0;
        *(unsigned char *)&d_1bcaa4 = 0;

        f_1433d0(p1, 3, 0x15010006);
C_27_1116:
        f_1434f0(p1);
        return;
C_17_1116:
        Store::set(1, d_1bca90);
        return;
C_18_1116:
        d_1bca94 = 1;
        *(unsigned char *)&d_1bca94 = 1; // Haelt die Registerwahl fuer Fall 11
        return;
C_19_1116:
        d_1bca98 = 1;
        return;
C_20_1116:
        d_1bca9c = 1;
        return;
C_21_1116:
        d_1bca70 = f_1457e0(4);
        return;
C_22_1116:
        f_0d5ff0(3);
        return;
C_23_1116:
        d_1bcaa8 = 1;
        return;
C_24_1116:
        d_1bca74[6] = 1;
        d_1bca74[5] = 1;
        d_1bca74[4] = 1;
        d_1bca74[3] = 1;
        if (EQI(d_1bed74, 0)) f_057220(A(d_1c2c00), 0x803000e, 0);
        d_1bed74 = 1;
        f_1433c0(p1);
        return;
C_25_1116:
        d_1bcaac = 1;
        return;
C_26_1116:
        d_1bcab0 = 1;
        return;
    case 0x1c:
        a = f_038c40(d_1c0004);
        b = 0;
        do {
            if (f_042380((struct hero *)(a)) == 0 && f_0d4a10(a) == 1) {
                if (b != 0) {
                    c1 = f_042a40((struct hero *)(a), 2);
                    c2 = f_042a40((struct hero *)(b), 2);
                    if (c1 <= c2) goto next;
                }
                b = a;
            }
        next:
            a = f_0391b0(d_1c0004, a);
            if (a == f_038c40(d_1c0004)) {
                s = f_044900(b, 2, 0);
                if (s > 0) {
                    d_1bca68 = 1;
                    return;
                }
                d_1bca68 = 0;
                return;
            }
        } while (1);
C_29_1116:
        d_1bca80 = 1;
        return;
C_31_1116: {
        int target1116 = f_039320(d_1c0004, 0x18);
        s = f_044c90(target1116, 0x18, 0);
        if (s > 0) {
            d_1bca69 = 1;
            return;
        }
        d_1bca69 = 0;
        return;
    }
    
    } // Ende Switch mit direktem Schleifenfall
}

struct Inner { int x; int tgt; };
struct Obj { int a; Inner *p; char pad[0x34]; };
//@ f_056450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert für Platzhalter im Dialogtext (1 bis 14) die passende einzusetzende Zeichenkette
 *   zurück, etwa den Namen des Gruppenanführers, den Namen des charismatischsten Helden, das aktuelle Vermögen
 *   der Gruppe oder geschlechtsspezifische Anreden.
 * - Eingaben und Rückgabe: Die Funktion erhält den 1-basierten Platzhalterindex p (unsigned short) und gibt
 *   einen Zeiger char * auf den formatierten Text zurück.
 * - Wichtige Variablen: Je nach Platzhalter wird f_0422b0 (Heldenname) für den Anführer (f_038c40) oder das
 *   beste Gruppenmitglied aufgerufen oder über f_0e93f0 eine geschlechtsabhängige Textform in den Puffer
 *   d_1c21b4 expandiert.
 === Ende Beschreibung === */
char *f_056450(unsigned short p)
{
    extern char d_1c3498[];
    Obj o;
    char *r;
    int best;
    int it;
    signed char value;
    f_125400(A(&o), A(d_1c349c), A(d_1c3870), A(d_1c3498));
    r = 0;
    switch (--p) {
    case 0:
        r = f_0422b0((struct hero *)(f_039320(d_1c0004, 0x18)));
        break;
    case 1:
        r = f_0422b0((struct hero *)(f_038c40(d_1c0004)));
        break;
    case 2:
        o.p->tgt = f_039320(d_1c0004, 0x18);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x15010007);
        break;
    case 3:
        o.p->tgt = f_038c40(d_1c0004);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x15010008);
        break;
    case 4:
        o.p->tgt = f_038c40(d_1c0004);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x15010007);
        break;
    case 5:
        r = d_1c27a8;
        f_14572e(d_1c2c00 - 0x458, d_1b6e14, f_0db970(d_1c0004));
        break;
    case 6:
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), f_145760(0, 0x13) + 0x15070001);
        break;
    case 7:
        it = f_038c40(d_1c0004);
        best = 0;
        do {
            if (f_042380((struct hero *)(it)) == 0 && f_0d4a10(it) == 1) {
                if (best == 0)
                    best = it;
                else {
                    value = f_042a40((struct hero *)(it), 2);
                    if (f_042a40((struct hero *)(best), 2) < value)
                        best = it;
                }
            }
            it = f_0391b0(d_1c0004, it);
        } while (it != f_038c40(d_1c0004));
        r = f_0422b0((struct hero *)(best));
        break;
    case 8:
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), f_145760(0, 9) + 0x15060001);
        break;
    case 9:
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x15010009);
        break;
    case 10:
        o.p->tgt = f_038c40(d_1c0004);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x1501000a);
        break;
    case 11:
        o.p->tgt = f_038c40(d_1c0004);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x1501000b);
        break;
    case 12:
        it = f_038c40(d_1c0004);
        best = 0;
        do {
            if (f_042380((struct hero *)(it)) == 0 && f_0d4a10(it) == 1) {
                if (best == 0)
                    best = it;
                else {
                    value = f_042a40((struct hero *)(it), 2);
                    if (f_042a40((struct hero *)(best), 2) < value)
                        best = it;
                }
            }
            it = f_0391b0(d_1c0004, it);
        } while (it != f_038c40(d_1c0004));
        o.p->tgt = best;
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x1501000b);
        break;
    case 13:
        o.p->tgt = f_038c40(d_1c0004);
        r = d_1c21b4;
        f_0e93f0(A(d_1c38b0), A(d_1c21b8 - 4), 0x1501000c);
    default:
        break;
    }
    f_1254a0(A(&o), 0);
    return r;
}

//@ f_056860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bestimmt nach dem Ende eines Dialogs anhand der Gesprächskennung, ob Spielzeit verstreicht
 *   (30, 45, 60, 90 oder 300 Zeiteinheiten) und welchen Rückgabecode das Dialogsystem liefert.
 * - Eingaben und Rückgabe: Die Funktion nimmt die Gesprächskennung p (unsigned short) entgegen und gibt als
 *   unsigned short den Statuscode 2 (ohne Zeitverbrauch) oder 3 (mit Zeitfortschritt über f_125ed0) zurück.
 * - Wichtige Variablen: Für bestimmte Gespräche (case 13, 14, 15, 21, 22, 23, 24) wird die Uhr d_1c2c44 über
 *   f_125ed0 um 30 bis 300 Einheiten vorgestellt.
 === Ende Beschreibung === */
unsigned short f_056860(unsigned short p)
{
    int r = 2;
    switch (p) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
    case 16: case 17: case 18: case 19: case 20:
    case 25: case 26: case 27:
        break;
    case 13: case 14: case 22:
        r = 3;
        f_125ed0(A(d_1c2c44), 30);
        break;
    case 15:
        r = 3;
        f_125ed0(A(d_1c2c44), 300);
        break;
    case 21:
        r = 3;
        f_125ed0(A(d_1c2c44), 60);
        break;
    case 23:
        r = 3;
        f_125ed0(A(d_1c2c44), 45);
        break;
    case 24:
        r = 3;
        f_125ed0(A(d_1c2c44), 90);
        break;
    case 28: case 29: case 30: case 31: case 32:
        break;
    default:
        break;
    }
    return r;
}
