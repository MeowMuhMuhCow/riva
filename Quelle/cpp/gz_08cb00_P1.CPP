/* === Beschreibung (Katalog) ===
 * Einheit gz_08cb00 (08cb00 - 08d590)
 *
 * Überblick
 * Die Einheit gz_08cb00 bildet den Auftakt der Ereignis- und Dungeonlogik für das Finale im Magierturm bzw. im
 * letzten Spielabschnitt (FINAL1/FINAL2): Sie registriert die zugehörigen Spielstands-Flags (f_08cb00),
 * initialisiert die virtuelle Methodentabelle der Dungeon-Steuerung (f_08cd00), verteilt die Ereigniskennungen
 * auf die jeweiligen Raum- und Objektaktionen (f_08cd20) und stellt erste Ereignishandler für Schaden, Opferung
 * und Gegenstandsfunde bereit.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 4/7 gleich (suche.py 26.10.2026, Basis gz_08cb00_P1.CPP)
// gz_08cb00.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08CB00-0x08D590
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"
#include "R_FIX.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_040900(int p1, int p2);                           // reg eax edx stapel 0
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_045190(int p1, int p2);                           // reg eax edx stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (7), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
int f_05ff60(int p1, int p2);
short f_145760(int p1, int p2);

int f_060740(int p1, int p2);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_0bf6f0(const char *o, int b);
int f_0bf730(const char *o, int b);
int f_0bbf00(const char *o);
int f_0dcf00(int p1, int p2, int p3);
int f_0dd7f0(int p1, int p2, int p3);
int f_08d590(int p1);
int f_08d690(int p1);
int f_08d7a0(int p1);
int f_08da20(int p1);
int f_091f70(int p1);
extern char d_1bdb00, d_1bdb01, d_1bdb02, d_1bdb03, d_1bdb04, d_1bdb08, d_1bdb0c, d_1bdb10, d_1bdb14, d_1bdb18, d_1bdb24;
extern char d_1bdb1c;
extern signed char d_1bdb20;
extern short d_1bdb05, d_1bdb09, d_1bdb0d, d_1bdb11, d_1bdb15, d_1bdb1d, d_1bdb25;
extern short d_1bdb19;
extern short d_1bdb21;
extern int d_1bdb28;
extern int d_1baef4;
extern char d_1bf230[];
extern int d_1c0004;
extern short d_1c212a;
extern char **d_1c212c;
extern char d_1c2c64[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
struct SO { int a; int *p; char c[52]; SO() { f_125400(this, d_1c349c, d_1c3870, d_1c3498); } ~SO() { f_1254a0(this, 0); } };
#define VC(p,a) ((short (*)(int,int,int))(**(int **)((p)+8)))((p),(a),0)
void f_08d410();
void f_08d430();
void f_08d4f0();
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_08cb00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Registriert neun persistente Zustands- und Zählervariablen (d_1bdb04 bis d_1bdb24 mit den
 *   Kennungen 0xca..0xd0, 0x241 und 0x264) in der globalen Spielstands-Tabelle d_1c212a, wobei der Vorratszähler
 *   d_1bdb20 mit dem Startwert 10 vorbelegt wird.
 * - Eingaben und Rückgabe: Die Initialisierungsfunktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Register d_1c212a sammelt alle Variablen, die beim Speichern und Laden eines
 *   Spielstands automatisch gesichert werden.
 === Ende Beschreibung === */
struct Obj08cb { signed char value; short id; };
struct Reg08cb { short count; Obj08cb **list; };
extern Reg08cb reg08cb;
#pragma aux reg08cb "d_1c212a"
extern Obj08cb obj08cb_04;
#pragma aux obj08cb_04 "d_1bdb04"
extern Obj08cb obj08cb_08;
#pragma aux obj08cb_08 "d_1bdb08"
extern Obj08cb obj08cb_0c;
#pragma aux obj08cb_0c "d_1bdb0c"
extern Obj08cb obj08cb_10;
#pragma aux obj08cb_10 "d_1bdb10"
extern Obj08cb obj08cb_14;
#pragma aux obj08cb_14 "d_1bdb14"
extern Obj08cb obj08cb_18;
#pragma aux obj08cb_18 "d_1bdb18"
extern Obj08cb obj08cb_1c;
#pragma aux obj08cb_1c "d_1bdb1c"
extern Obj08cb obj08cb_20;
#pragma aux obj08cb_20 "d_1bdb20"
extern Obj08cb obj08cb_24;
#pragma aux obj08cb_24 "d_1bdb24"
inline signed char zero08cb() { signed char z=0; return z; }
inline void add08cb(Obj08cb &o, Reg08cb &r, short id) { o.value=zero08cb(); o.id=id; r.list[r.count]=&o; r.count++; }
struct RR700V3_08cb008;
struct OR700V3_08cb008 { signed char flag; short number; char pad; OR700V3_08cb008 *init(RR700V3_08cb008 &r,short id,signed char f); };
struct RR700V3_08cb008 { short count; OR700V3_08cb008 **list; void append(OR700V3_08cb008 *o) {list[count]=o;count++;} };
inline OR700V3_08cb008 *OR700V3_08cb008::init(RR700V3_08cb008 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_08cb008 regR700V3_08cb008;
#pragma aux regR700V3_08cb008 "d_1c212a"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb04;
#pragma aux obR700V3_08cb00_1bdb04 "d_1bdb04"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb08;
#pragma aux obR700V3_08cb00_1bdb08 "d_1bdb08"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb0c;
#pragma aux obR700V3_08cb00_1bdb0c "d_1bdb0c"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb10;
#pragma aux obR700V3_08cb00_1bdb10 "d_1bdb10"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb14;
#pragma aux obR700V3_08cb00_1bdb14 "d_1bdb14"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb18;
#pragma aux obR700V3_08cb00_1bdb18 "d_1bdb18"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb1c;
#pragma aux obR700V3_08cb00_1bdb1c "d_1bdb1c"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb20;
#pragma aux obR700V3_08cb00_1bdb20 "d_1bdb20"
extern OR700V3_08cb008 obR700V3_08cb00_1bdb24;
#pragma aux obR700V3_08cb00_1bdb24 "d_1bdb24"
void f_08cb00(void) {
obR700V3_08cb00_1bdb04.init(regR700V3_08cb008,0xca,0);
obR700V3_08cb00_1bdb08.init(regR700V3_08cb008,0xcb,0);
obR700V3_08cb00_1bdb0c.init(regR700V3_08cb008,0xcc,0);
obR700V3_08cb00_1bdb10.init(regR700V3_08cb008,0xcd,0);
obR700V3_08cb00_1bdb14.init(regR700V3_08cb008,0xce,0);
obR700V3_08cb00_1bdb18.init(regR700V3_08cb008,0xcf,0);
obR700V3_08cb00_1bdb1c.init(regR700V3_08cb008,0xd0,0);
obR700V3_08cb00_1bdb20.init(regR700V3_08cb008,0x241,10);
obR700V3_08cb00_1bdb24.init(regR700V3_08cb008,0x264,0);
}

//@ f_08ccc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fügt einem lebenden Helden (p1) bei einer Raumfalle oder Explosion im Final-Dungeon 2..5
 *   Schadenspunkte (f_145760(2, 5)) zu und aktualisiert die Anzeige der Heldenleiste (f_0bbf00).
 * - Eingaben und Rückgabe: Die Rückruffunktion erhält den Heldenzeiger p1 (aufgerufen über f_039a80 für jedes
 *   Gruppenmitglied) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über f_0d4a60(p1) wird sichergestellt, dass nur lebende, anwesende Helden Schaden
 *   erleiden.
 === Ende Beschreibung === */
void f_08ccc0(int p1)
{
    if (f_0d4a60(p1)) {
        short s = f_145760(2, 5);
        f_044300(p1, s);
        f_0bbf00(d_1bf230);
    }
}
//@ f_08cd00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert das Dungeon-Steuerobjekt (p1) für den ersten Teil des Final-Dungeons (Kennung 10
 *   über f_05ff60) und trägt dessen virtuelle Methodentabelle d_1baef4 ein.
 * - Eingaben und Rückgabe: Der Konstruktor erhält den Objektzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: An Offset r + 8 wird der Zeiger auf die virtuelle Methodentabelle d_1baef4 gespeichert.
 === Ende Beschreibung === */
void f_08cd00(int p1)
{
    int r = f_05ff60(p1, 10);
    *(int *)(r + 8) = (int)&d_1baef4;
}
//@ f_08cd20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verzweigt für den ersten Final-Dungeon anhand der ausgelösten Ereigniskennung (p2, z. B.
 *   0x65..0x324) in die jeweilige Raumaktion: Textmeldungen, Auswahl des geschwächtesten Helden (0x66), Kraft-
 *   und Lebenspunkte-Opferung (0x67), Beutefunde (0xca, 0x2be, 0x322), Kämpfe und Rätselstationen (0xc9, 0x12d,
 *   0x191, 0x321).
 * - Eingaben und Rückgabe: Die Methode nimmt den Dungeon-Objektzeiger p1 sowie die Ereigniskennung p2 (unsigned
 *   short) entgegen und gibt 1 zurück, wenn das Ereignis behandelt wurde, sonst 0.
 * - Wichtige Variablen: Im Zweig case 0x322 (Entnahme von bis zu 10 Gegenständen 0x182 aus dem Vorrat d_1bdb20)
 *   steckt ein Originalfehler (siehe Fehlerliste): Die Prüfung if (n > 0 && d_1bdb20 == 0) für das Umschalten
 *   des Kartenobjekts 0x1f41 erfolgt vor der Subtraktion d_1bdb20 -= n und ist daher unerreichbar.
 === Ende Beschreibung === */
static inline int eq0c(signed char b) { int ia = (signed char)d_1bdb0c; int ib = b; return ia == ib ? 1 : 0; }
static inline void h_08d760(int p1)
{
    if (eq0c(0) && VC(p1, 0x44) == 0)
        d_1bdb0c = 1;
}
static inline void h_08d930(int p1)
{
    if (EQ((signed char)d_1bdb14, 0) && VC(p1, 0x48) == 0)
        d_1bdb14 = 1;
}
static inline void h_08d9e0(int p1)
{
    if (EQ((signed char)d_1bdb18, 0) && VC(p1, 0x47) == 0)
        d_1bdb18 = 1;
}
short f_08cd20(int p1, unsigned short p2)
{
    int rv = 1;
    char objects[240];
    switch (p2) {
    case 0x65:
        f_0bf730(d_1c2c64, 0x29000007);
        break;
    case 0x66: {
        f_125400(objects + 60, d_1c349c, d_1c3870, d_1c3498);
        int best = 0;
        short i;
        int item;
        for (i = 0; i < 7; i++) {
            item = f_0de7d0(d_1c0004, i);
            if (item && f_0d4a60(item)) {
                if (best) {
                    short a = ((int)(f_042960((struct hero *)(item))));
                    short b = ((int)(f_042960((struct hero *)(best))));
                    if (a > b) continue;
                }
                best = item;
            }
        }
        ((SO *)(objects + 60))->p[1] = best;
        if (f_0bf6f0(d_1c2c64, 0x29000008) == 1) {
            f_0bf730(d_1c2c64, 0x29000009);
            f_0dd7f0(d_1c0004, 11, 0x1459);
            d_1bdb28 = best;
        }
        f_1254a0(objects + 60, 0);
        break;
    }
    case 0x67:
        if (f_0bf6f0(d_1c2c64, 0x2900000b) == 1) {
            int item = f_038d70(d_1c0004, 0x2900000c);
            if (item) {
                f_125400(objects + 180, d_1c349c, d_1c3870, d_1c3498);
                ((SO *)(objects + 180))->p[1] = item;
                f_045190(item, 10);
                if (f_0bf6f0(d_1c2c64, 0x2900000d) == 1) {
                    f_0bf730(d_1c2c64, 0x2900000e);
                    f_040900(item, 5);
                }
                f_1254a0(objects + 180, 0);
            }
        }
        break;
    case 0xc9: f_08d590(p1); break;
    case 0xca:
        if (f_0bf6f0(d_1c2c64, 0x29000010) == 1)
            f_0dcf00(d_1c0004, 0x184, 10);
        break;
    case 0x12d: f_08d690(p1); break;
    case 0x12e: h_08d760(p1); break;
    case 0x191: f_08d7a0(p1); break;
    case 0x192:
        if ((signed char)d_1bdb00 == 0) {
            d_1bdb00 = 1;
            f_0bf730(d_1c2c64, 0x29000017);
        }
        break;
    case 0x1f5: {
        int s = p1;
        f_125400(objects, d_1c349c, d_1c3870, d_1c3498);
        if (EQ((signed char)d_1bdb10, 0)) {
            f_0bf730(d_1c2c64, 0x29000016);
            if (VC(s, 0x46) == 0) {
                d_1bdb10 = 1;
                f_091f70(0x1c);
            }
        }
        f_1254a0(objects, 0);
        break;
    }
    case 0x1f6:
        if ((signed char)d_1bdb01 == 0) {
            d_1bdb01 = 1;
            f_0bf730(d_1c2c64, 0x29000017);
        }
        break;
    case 0x259: h_08d930(p1); break;
    case 0x2bd:
        if ((signed char)d_1bdb02 == 0) {
            d_1bdb02 = 1;
            f_0bf730(d_1c2c64, 0x29000017);
        }
        break;
    case 0x2be:
        if (f_0bf6f0(d_1c2c64, 0x29000018) == 1) {
            f_0bf730(d_1c2c64, 0x29000019);
            f_0dcf00(d_1c0004, 0x181, 1);
        }
        break;
    case 0x2bf: h_08d9e0(p1); break;
    case 0x321: f_08da20(p1); break;
    case 0x322: {
        short n;
        if (d_1bdb20 > 0 ? 1 : 0) {
            if (f_0bf6f0(d_1c2c64, 0x2900001c) == 1) {
                signed char value = d_1bdb20;
                n = f_0dcf00(d_1c0004, 0x182, value);
#if FIX_R071   /* R071: Vorrat d_1bdb20 zuerst reduzieren und danach auf 0 pruefen, damit Objekt 0x1f41 umschaltet */
                d_1bdb20 -= (char)n;
                if (n > 0 && EQ(d_1bdb20, 0))
                    f_060740(0x1f41, 1);
#else
                if (n > 0 && EQ(d_1bdb20, 0))
                    f_060740(0x1f41, 1);
                d_1bdb20 -= (char)n;
#endif
            }
        } else {
            f_0bf730(d_1c2c64, 0x2900001d);
        }
        break;
    }
    case 0x323:
        if ((signed char)d_1bdb03 == 0) {
            d_1bdb03 = 1;
            f_0bf730(d_1c2c64, 0x29000017);
        }
        break;
    case 0x324: {
        char bit = (char)(d_1bdb24 & 1);
        if ((bit != (char)0 ? 1 : 0) == 0) {
            d_1bdb24 = (char)(d_1bdb24 | 1);
            f_0bf730(d_1c2c64, 0x2900001e);
            f_125400(objects + 120, d_1c349c, d_1c3870, d_1c3498);
            ((SO *)(objects + 120))->p[1] = f_039320(d_1c0004, 0x25);
            f_0bf730(d_1c2c64, 0x2900001f);
            f_1254a0(objects + 120, 0);
        }
        break;
    }
    default:
        rv = 0;
    }
    return rv;
}
//@ f_08d410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Betreten oder Untersuchen des Ereignisfelds 0x65 die zugehörige Beschreibungsmeldung
 *   (0x29000007) im Dialogfenster aus.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Textausgabe erfolgt über das globale Textfenster-Objekt d_1c2c64.
 === Ende Beschreibung === */
void f_08d410()
{
    f_0bf730(d_1c2c64, 0x29000007);
}
//@ f_08d430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in der Heldengruppe den lebenden Helden mit den aktuell niedrigsten Lebenspunkten
 *   (f_042960), bietet dem Spieler eine Interaktion (0x29000008) an und versetzt die Gruppe bei Zustimmung auf
 *   den Zielpunkt 0x1459 in Karte 11, wobei der ausgewählte Held in d_1bdb28 für das Folgeereignis vorgemerkt
 *   wird.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bdb28 merkt sich den Zeiger auf den am schwersten angeschlagenen
 *   Helden für die spätere Auswertung nach dem Kartenwechsel.
 === Ende Beschreibung === */
void f_08d430()
{
    SO o;
    int best = 0; short s;
    int t;
    s = 0;
    for (;; s++) {
        int i = s;
        if (i >= 7) break;
        t = f_0de7d0(d_1c0004, i);
        if (t != 0 && f_0d4a60(t)) {
            if (best != (short)0) {
                short a = ((int)(f_042960((struct hero *)(t))));
                short b = ((int)(f_042960((struct hero *)(best))));
                if (a > b) continue;
            }
            best = t;
        }
    }
    o.p[1] = best;
    do {
    if (f_0bf6f0(d_1c2c64, 0x29000008) == 1) {
        f_0bf730(d_1c2c64, 0x29000009);
        f_0dd7f0(d_1c0004, 0xb, 0x1459);
        d_1bdb28 = best;
    }
    } while (0);
}
//@ f_08d4f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler am Ereignisfeld 0x67, ob ein Held vortreten soll (0x2900000b), lässt den
 *   Helden auswählen (f_038d70), zieht diesem 10 Punkte ab (f_045190) und gewährt ihm nach einer zweiten
 *   Bestätigung (0x2900000d) im Gegenzug 5 permanente Punkte (f_040900).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der ausgewählte Held wird in den Textplatzhalter o.p[1] eingetragen, damit sein Name in
 *   den Meldungen 0x2900000d und 0x2900000e erscheint.
 === Ende Beschreibung === */
void f_08d4f0()
{
    if (f_0bf6f0(d_1c2c64, 0x2900000b) == 1) {
        int t = f_038d70(d_1c0004, 0x2900000c);
        if (t != 0) {
            SO o;
            o.p[1] = t;
            f_045190(t, 10);
            if (f_0bf6f0(d_1c2c64, 0x2900000d) == 1) {
                f_0bf730(d_1c2c64, 0x2900000e);
                f_040900(t, 5);
            }
        }
    }
}
