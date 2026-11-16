/* === Beschreibung (Katalog) ===
 * Einheit diskmen2_t1 (0x059d60 - 0x05b080)
 *
 * Überblick
 * Diese Einheit bildet den ersten Teil von diskmen2.cpp und implementiert das physische Speichern und Laden der
 * Spielstände im Ordner ..\GAMES\. Eine .GAM-Datei besteht aus einem 16-Byte-Versionskopf (DSA VERSION), einem
 * 260-Byte-Beschreibungsblock (DESC) und benannten Datenblöcken (CHAR, PART, TIME, RUNV, MONS, BVAR, WVAR, DVAR
 * sowie je Datei im ..\TEMP-Ordner ein TEMP-Block, optional RIVAPACK-komprimiert).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 5/8 gleich (suche.py 26.10.2026, Basis diskmen2_t1_P1.CPP)
// F4 Stand (Basis p3 DISKMEN2_T1_P1.CPP)
// diskmen2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x059D60-0x05B080
#include <string.h>
#pragma pack(1)
struct Obj { char pad0[0x10]; int *p; char rest[0x28]; };
struct Dta { char pad[30]; char nm[14]; };
struct DM { char a0[0x22]; short s22; short a24; short s26; short s28; char b0[0x12a-0x2a]; char names[0x526]; short s650; };
int f_144fbf(const char *n, int m, ...);                 // open
int f_144e8b(int h, void *b, unsigned n);                // read
int f_144cb6(int h, const void *b, unsigned n);          // write
int f_145279(int h, int pos, int w);                     // lseek
int f_145259(int h);                                     // close
int f_1452bc(int h);                                     // filelen
int f_14572e(char *b, const char *f, ...);               // sprintf
short f_1492b4(const char *n, int a, void *d);           // findfirst
short f_1492d1(void *d);                                 // findnext
int f_1492ed(void *d);                                   // findclose
int f_149336(const char *n);                             // unlink
int f_14d717(const char *a, const char *b);              // stricmp
int f_145547(const char *a, const char *b, unsigned n);  // strncmp
int f_144bf0(const char *a, const char *b);              // cmp386
const 
int f_14d0d7(const char *n, int m);
int f_014a60();
void *f_014540(int size, const char *file, int line);
int f_125400(void *o, void *a, void *b, void *c);
int f_1254a0(void *o, int fl);
int f_0d2f90(int a, int b);
int f_0d2e70();
int f_0cdd30(char *s, int c);
int f_133fe0(void *o, const char *s);
int f_0bf730(void *o, int c);
int f_0bf6f0(void *o, int c);
int f_0e93f0(void *o, const char *s, int c);
int f_069460();
int f_05da90(DM *p);
int f_05d2d0(DM *p);
int f_01a490(void *p);
int f_056d70(void *p);
int f_0457c0(int p);
int f_045750(int p);
int f_0dd220(void *p);
int f_0dd2f0(void *p);
int f_126c70(void *p);
int f_126dd0(void *p);
int f_0125b0(void *o, int h);
int f_011fb0(void *o, int h);
int f_011970(void *o, int h);
int f_012450(void *o, int h);
int f_011e50(void *o, int h);
int f_0117e0(void *o, int h);
int f_11f5f0();
int f_0d9d20(void *x, char *a, char *b);
int f_0d9fe0(void *x, char *a, char *b);
int f_0999f0(void *o, int a);
int f_0de930(void *o);
short f_0db940(char *p);
char f_0ce070(char *p);
short f_05b420(DM *p, char *n, char *q);
int f_05a020(DM *p, const char *n);
int f_05a910(DM *p, const char *n);
int f_05a820(void *p, int a, int b);
void f_059e90(DM *p);
void f_059d60(const char *a, const char *b);
extern const char d_1a1794[], d_1a6260[], d_1b6e74[], d_1b6e7d[], d_1b6e82[], d_1b6e87[], d_1b6e8c[], d_1b6e91[], d_1b6e96[];
extern const char d_1b6e9b[], d_1b6ea0[], d_1b6ea4[], d_1b6ead[], d_1b6eb2[], d_1b6eb7[], d_1b6ec4[], d_1b6ecc[], d_1b6ed1[], d_1a9680[];
extern const char d_1a9692[], d_1a9693[], d_1a9694[];
extern char d_1c11cd[], d_1c129d[], d_1c2128[], d_1c2130[], d_1c2138[], d_1c21b4[], d_1c2a50[], d_1c2c00[], d_1c2c44[];
extern char d_1c2c64[], d_1c3498[], d_1c349c[], d_1c3870[], d_1c38b0[], d_1c2a84[], d_1bfdbc[];
extern const char *d_1a9674, *d_1a9678;
extern int d_1bc8f0, d_1c2a80, d_1bdb94;
extern short d_1c2140, d_1c219e, d_1a9696;
extern char *d_1c0004;
extern signed char d_1c002c;

//@ f_059d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine Datei vom Quellpfad a zum Zielpfad b blockweise über einen dynamischen Puffer von
 *   bis zu 32000 Bytes (der bei knappem Heap automatisch halbiert wird). Sie wird unter anderem genutzt, um den
 *   zuletzt gespeicherten Spielstand nach ..\GAMES\LASTGAME zu kopieren oder gepackte TEMP-Dateien nach unp.$$$
 *   auszulagern.
 * - Eingaben und Rückgabe: Die Funktion erhält den Quellpfad a und den Zielpfad b als Strings und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Dateihandles h1 (Quelle) und h2 (Ziel) steuern den Kopierlauf, während size die an
 *   den freien Speicher (f_014a60) angepasste Puffergröße hält.
 === Ende Beschreibung === */
void f_059d60(const char *a, const char *b)
{
    unsigned short r;
    short h2;
    short h1;
    int size;
    h1 = f_144fbf(a, 0x200);
    size = 32000;
    if (h1 != -1) {
        h2 = f_14d0d7(b, 0);
        if (h2 != -1) {
            while (f_014a60() < size) size /= 2;
            char *p = (char *)f_014540(size, d_1a1794, 0x5a);
            int n = f_1452bc(h1);
            while (n > 0) {
                short k; if (n > size) { k = size; } else { k = n; }
                r = f_144e8b(h1, p, (unsigned short)k);
                f_144cb6(h2, p, r);
                n -= r;
            }
            delete p;
            f_145259(h2);
        }
        f_145259(h1);
    }
}

//@ f_059e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert die angegebene Spielstanddatei ..\GAMES\<name> über f_059d60 nach ..\GAMES\LASTGAME,
 *   damit das Spiel beim nächsten Programmstart über "Letztes Spiel fortsetzen" direkt diesen Stand laden kann.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten ersten Parameter unused sowie den Dateinamen
 *   name des Spielstands und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokalen Puffer source[40] und dest[40] nehmen die mit d_1a9678 ("..\GAMES\%s")
 *   zusammengesetzten Dateipfade auf.
 === Ende Beschreibung === */
void f_059e40(const char *unused, const char *name)
{
    char dest[40];
    char source[40];
    f_14572e(dest, d_1a9678, d_1b6e74);
    f_14572e(source, d_1a9678, name);
    f_059d60(source, dest);
}

//@ f_059e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert den aktuellen Spielzustand unter dem im Diskmenü markierten Dateinamen (names[s22 +
 *   s26] + ".GAM") über f_05a020, aktualisiert bei Erfolg auch ..\GAMES\LASTGAME und zeigt dem Spieler das
 *   Bestätigungsfenster 0x903000a mit dem Dateinamen an.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt (DM) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Aus p1->s22 (erste sichtbare Zeile) und p1->s26 (Cursorzeile) wird der Index des
 *   ausgewählten Eintrags in der Namenstabelle p1->names berechnet.
 === Ende Beschreibung === */
void f_059e90(DM *p1)
{
    Obj o; char bA[40], bB[40], nm[16];
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    f_0d2f90(5, 1);
    strcpy(nm, p1->names + (p1->s22 + p1->s26) * 13);
    strcat(nm, d_1b6e7d);
    if (f_05a020(p1, nm) != 0) {
        f_14572e(bB, d_1a9678, d_1b6e74);
        f_14572e(bA, d_1a9678, nm);
        f_059d60(bA, bB);
        f_0cdd30(nm, 0x20);
        f_0cdd30(nm, 0x2e);
        strcat(nm, d_1b6e82);
        o.p[1] = f_133fe0(d_1c3498, nm);
        f_0bf730(d_1c2c64, 0x903000a);
    }
    f_0d2e70();
    f_1254a0(&o, 0);
}

//@ f_05a020
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen vollständigen Spielstand nach ..\GAMES\<p2>: zuerst den 16-Byte-Kopf ("DSA
 *   VERSION\0", Versionsbytes 1, 3, 1 und d_1c2a50) und den 260-Byte-DESC-Block (f_05d2d0), danach die 7
 *   Heldenblöcke (CHAR, f_045750), 6 Gruppenblöcke (PART, f_0dd220), die Spielzeit (TIME, f_126c70), die
 *   Laufzeit- und Monsterdaten (RUNV, MONS), die registrierten Byte-, Wort- und Doppelwortvariablen (BVAR, WVAR,
 *   DVAR) sowie für jede Datei in ..\TEMP (außer der Ausnahmedatei 0x90001) einen nach Möglichkeit über pack.$$$
 *   komprimierten TEMP-Block. Tritt beim Schreiben der TEMP-Blöcke ein Schreibfehler auf (z. B. voller
 *   Datenträger), wird die unvollständige Spielstanddatei gelöscht und die Fehlermeldung 0x200001ae ausgegeben.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und den Dateinamen p2. Sie
 *   gibt 1 bei erfolgreichem Speichern und 0 bei einem Fehler zurück.
 * - Wichtige Variablen: Das globale Dateihandle d_1c2140 (spiegelbildlich in p1->s28) hält die offene
 *   Spielstanddatei für alle Block-Schreibfunktionen, d_1bc8f0 ist die Tabelle der 7 Helden (je 0x5ef Bytes) und
 *   d_1bfdbc die Tabelle der 6 Gruppen (je 0x61 Bytes).
 === Ende Beschreibung === */
int f_05a020(DM *p1, const char *p2)
{
    extern char d_1c1298[],d_1c1345[];
    int __cdecl f_144fbf(char*,int);
    struct FA { char b3[144]; Dta dta; char fn[40], path[40]; volatile int t34; } A; // Rahmenfolge auf dem Stapel wie im Original
#define b3 A.b3
#define dta A.dta
#define fn A.fn
#define path A.path
#define t34 A.t34
    int result, size, ok;
    int w20, h2;
    int x;
    short h;
    short i;
    short fr;
    //E
    (void)&p1; (void)&result; (void)&size; (void)&ok; (void)&h2; // Haelt diese Variablen auf dem Stapel
    result = 0;
    ok = 1;
    size = 32000;
    f_14572e(fn, d_1a9678, p2);
    h = f_14d0d7(fn, 0);
    d_1c2140 = h;
    p1->s28 = h;
    if (h != -1) {
        result = 1;
        for (;;) { int capacity = size; if (f_014a60() >= capacity) break; size = capacity / 2; }
        char *p = (char *)f_014540(size, d_1a1794, 0xe1);
        p += size ^ size; // Haelt p nach dem Aufruf im Zielregister
        f_145279(p1->s28, 0, 0);
        f_144cb6(p1->s28, d_1a9680, 12);
        f_144cb6(p1->s28, d_1a9694, 1);
        f_144cb6(p1->s28, d_1a9693, 1);
        f_144cb6(p1->s28, d_1a9692, 1);
        f_144cb6(p1->s28, d_1c2a50, 1);
        f_05d2d0(p1);
        int q = d_1bc8f0;
        for (i = 0; i < 7; i++) {
            f_045750(q);
            q += 0x5ef;
        }
        char *r = d_1bfdbc;
        for (i = 0; i < 6; i++) {
            f_0dd220(r);
            r += 0x61;
        }
        f_126c70(d_1c2c44);
        w20 = (int)d_1c1298-(int)d_1c11cd;
        f_144cb6(d_1c2140, d_1b6e87, 4);
        f_144cb6(d_1c2140, &w20, 2);
        f_144cb6(d_1c2140, d_1c11cd, (short)w20);
        w20 = (int)d_1c1345-(int)d_1c129d;
        f_144cb6(d_1c2140, d_1b6e8c, 4);
        f_144cb6(d_1c2140, &w20, 2);
        f_144cb6(d_1c2140, d_1c129d, (short)w20);
        f_144cb6(d_1c2140, d_1b6e91, 4);
        f_0125b0(d_1c2128, d_1c2140);
        f_144cb6(d_1c2140, d_1b6e96, 4);
        f_011fb0(d_1c2130, d_1c2140);
        f_144cb6(d_1c2140, d_1b6e9b, 4);
        f_011970(d_1c2138, d_1c2140);
        f_11f5f0();
        f_14572e(d_1c21b4, d_1a9674, d_1b6ea0);
        fr = f_1492b4(d_1c21b4, 0, &dta);
            fr = (fr & 0) ? 0 : fr; // Haelt die Registerwahl fuer fr
        if (fr == (short)0) do {
            if (f_144bf0(dta.nm, ((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( 0x90001)) != 0) {
                f_14572e(path, d_1a9674, dta.nm);
                f_14572e(b3, d_1a9674, d_1b6ea4);
                f_149336(b3);
                if(f_0d9d20(&x,path,b3)!=-1) h2=f_144fbf(b3,0x200);
                else h2=f_144fbf(path,0x200);
                f_144cb6(d_1c2140, d_1b6ead, 4);
                int length = f_1452bc((short)h2) + 14; length += h2 ^ h2; // Haelt den Compare-Pick wie im Original
                t34 = length;
                if (length > 0x8000) {
                    int sentinel = -1;
                    int t_ = d_1c2140;
                    w20 = sentinel;
                    f_144cb6(t_, &w20, 2);
                    f_144cb6(d_1c2140, (const void *)&t34, 4);
                } else {
                    // Volatile t34 erzwingt hier die erneute Laengenladung.
                    w20 = t34;
                    f_144cb6(d_1c2140, &w20, 2);
                }
                strcpy(fn, dta.nm);
                f_144cb6(d_1c2140, fn, 14);
                int left=t34-14; left += 0; left += size ^ size; t34=left; // Zwei LatePicks fuer die Registerfolge
                while (left > 0) {
                    unsigned short u;
                    if (t34 > size) u = size; else u = t34;
                    unsigned short rd = f_144e8b((short)h2, p, u);
                    unsigned short used=rd;
                    unsigned short wr = f_144cb6(d_1c2140, p, rd);
                    if (wr != rd) ok = 0;
                    union WordCount { unsigned full; unsigned short low; } count;
                    count.full = 0;
                    left = (h2 & 0) ? 0 : t34; // Trennt das Load-Web
                    count.low = used;
                    left -= count.full; t34 = left;
                }
                f_145259((short)h2);
                f_149336(b3);
            }
            fr = f_1492d1(&dta);
        } while(fr==(short)0);
        f_1492ed(&dta);
        f_145259(d_1c2140);
        delete p;
    }
    int finalok=ok; if (finalok == 0) {
        finalok = (finalok & 0) ? 0 : finalok; // Haelt die lokale Kopie in finalok
        DM *self=p1;
        self->s28 = -1;
        d_1c2140 = self->s28;
        f_149336(fn);
        result = finalok;
        f_0bf730(d_1c2c64, 0x200001ae);
    }
    return result;
#undef b3
#undef dta
#undef fn
#undef path
#undef t34
#undef result
#undef size
#undef ok
#undef w20
#undef h2
#undef x
#undef p1
}

//@ f_05a5c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt den Menüpunkt "Speichern" im Diskmenü aus: verhindert das Überschreiben des geschützten
 *   Startspielstands START   .GAM (0x903001e) sowie das Speichern an gesperrten Orten (p2 == 1, Meldung
 *   0x9030017) oder bei leerer Spielstandliste (0x9030014). Ist p3 != 0, wird zuvor eine Sicherheitsabfrage
 *   (0x9030019 beim Überschreiben eines vorhandenen Spielstands bzw. 0x9030003 bei einer neuen Datei) gestellt,
 *   bevor f_059e90 den Stand speichert und f_05da90 die Anzeige aktualisiert.
 * - Eingaben und Rückgabe: Die Funktion erhält das Diskmenü-Objekt p1, den Sperrmodus p2 (1 = Speichern
 *   verboten) und den Rückfrageschalter p3 (1 = vor dem Speichern fragen). Sie gibt 1 zurück, wenn gespeichert
 *   wurde, sonst 0.
 * - Wichtige Variablen: Das Feld p1->s650 enthält die Gesamtzahl der vorhandenen Spielstände in der Liste.
 === Ende Beschreibung === */
static inline int NameOffset1327(DM *self) { int first = self->s22; int index = self->s26; index += first; return index * 13; }
static inline void TrimName1327(char*name){char*q=strchr(name,' ');if(q)*q=0;else{q=strchr(name,'.');if(q)*q=0;}}

short f_05a5c0(DM *p1, int p2, int p3)
{
    struct{int confirm,mode;}args;
    //D
    char buf104[100];
    Obj o;
    char path[40];
    struct Names1327 { char stem[16]; char file[16]; } names;
    int local14;
    short h;
    char *c;
    int rr;
    //E
    args.mode=p2;*(volatile int *)&args.confirm=p3;
    local14 = 0;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    strcpy(names.file, p1->names + (p1->s22 + p1->s26) * 13);
    strcat(names.file, d_1b6eb2);
    if (f_14d717(names.file, d_1b6eb7) == 0) {
        f_0bf730(d_1c2c64, 0x903001e);
    } else {
        f_14572e(path, d_1a9678, names.file);
        if (args.mode == 1) {
            f_0bf730(d_1c2c64, 0x9030017);
        } else {
            if (p1->s650 > 0) {
                d_1c219e = 1;
                f_069460();
                h = f_144fbf(path, 0x200);
                if (h > 0) {
                    strcpy(names.stem, p1->names + NameOffset1327(p1));
                    TrimName1327(names.stem);
                    o.p[1] = f_133fe0(d_1c3498, names.stem);
                    f_0e93f0(d_1c38b0, buf104, 0x9030019);
                    f_145259(h);
                } else {
                    f_0e93f0(d_1c38b0, buf104, 0x9030003);
                }
                if (args.confirm != 0) {
                    rr = f_0bf6f0(d_1c2c64, f_133fe0(d_1c3498, buf104));
                    if (rr != 1) goto done;
                }
                f_059e90(p1);
                f_05da90(p1);
                local14 = 1;
                goto done;
            }
            f_0bf730(d_1c2c64, 0x9030014);
        }
    }
    
done:
    f_1254a0(&o, 0);
    return local14;
}

//@ f_05a820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die geöffnete Spielstanddatei d_1c2140 ab Dateiversatz 0x114 (direkt hinter dem
 *   DESC-Block) nach dem p3-ten Datenblock mit der 4-Byte-Blockkennung p2 ('CHAR', 'PART', 'TEMP' usw.), indem
 *   fremde Blöcke anhand ihres 16-Bit-Längenworts (bzw. bei -1 anhand des nachfolgenden 32-Bit-Längenworts)
 *   übersprungen werden. Bei einem Treffer wird der Dateizeiger wieder 4 Bytes zurück vor die Blockkennung
 *   gestellt.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Parameter p1, die gesuchte 4-Byte-Kennung p2
 *   und die laufende Treffernummer p3 (ab 1). Sie gibt 1 zurück, wenn der Block gefunden wurde, oder 0 am
 *   Dateiende.
 * - Wichtige Variablen: Das globale Dateihandle d_1c2140 bezeichnet die geöffnete .GAM-Datei; cnt zählt die
 *   bisherigen Vorkommen der gesuchten Blockkennung.
 === Ende Beschreibung === */
int f_05a820(void *p1, int p2, int p3)
{
    struct Lo { static short s(int rd) { return (short)rd; } };
    int cnt = 1;
    f_145279(d_1c2140, 0x114, 0);
    int found = 0;
    int rd = cnt;
    do {
        int w;
        int l1c;
        short l18[2];
        if (Lo::s(rd) == (short)0) break;
        w = 0;
        rd = f_144e8b(d_1c2140, &w, 4);
        if (p2 == w && (short)cnt++ == (short)p3) {
            found = 1;
        } else {
            f_144e8b(d_1c2140, l18, 2);
            int off = l18[0];
            if (off == -1) {
                f_144e8b(d_1c2140, &l1c, 4);
                f_145279(d_1c2140, l1c, 1);
            } else {
                f_145279(d_1c2140, off, 1);
            }
        }
    } while (found == 0);
    if (found != 0) f_145279(d_1c2140, -4, 1);
    return found;
}

//@ f_05a910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den Spielstand ..\GAMES\<p2> vollständig in den Speicher: setzt das Tagebuch zurück
 *   (f_056d70), sucht über f_05a820 und liest der Reihe nach die Blöcke CHAR (7 Helden), PART (6 Gruppen), TIME,
 *   RUNV, MONS, BVAR, WVAR, DVAR und entpackt sämtliche TEMP-Blöcke zurück in den Ordner ..\TEMP\ (wobei
 *   RIVAPACK-komprimierte Dateien über unp.$$$ und f_0d9fe0 dekomprimiert werden). Anschließend stellt die
 *   Funktion sicher, dass d_1c0004 auf eine nicht-leere Heldengruppe zeigt, und stößt den Neuaufbau von Automap
 *   und Grafik an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Diskmenü-Objekt p1 und den Dateinamen p2. Sie gibt 1 zurück,
 *   wenn die Datei geöffnet und gelesen wurde, sonst 0.
 * - Wichtige Variablen: Die globale Variable d_1c002c speichert den Index (0..5) der aktiven Gruppe und d_1c0004
 *   den Zeiger auf deren 97-Byte-Struktur in d_1bfdbc.
 === Ende Beschreibung === */
int f_05a910(DM *p1, const char *p2)
{
    char buf0[144],tmp[40],nm[40],hdr[8];
    int rd,n,ret; short a; short uh; short idx; char x;
    short i;
    //E
    a = 0;
    idx = 1;
    rd = 0;
    n = 0;
    ret = 0;
    unsigned blk = 0x8000;
    f_14572e(nm, d_1a9678, p2);
    d_1c2140 = f_144fbf(nm, 0x200);
    if (d_1c2140 != -1) {
        f_056d70(d_1c2c00);
        ret = 1;
        if (f_05a820(p1, 0x52414843, 1) != 0) {
            int q = d_1bc8f0;
            for (i = 0; i < 7; i++) {
                f_0457c0(q);
                q += 0x5ef;
            }
        }
        if (f_05a820(p1, 0x54524150, 1) != 0) {
            char *r = d_1bfdbc;
            for (i = 0; i < 6; i++) {
                f_0dd2f0(r);
                r += 0x61;
            }
        }
        if (f_05a820(p1, 0x454d4954, 1) != 0) f_126dd0(d_1c2c44);
        if (f_05a820(p1, 0x564e5552, 1) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x564e5552) {
                f_144e8b(d_1c2140, &a, 2);
                f_144e8b(d_1c2140, d_1c11cd, (short)a);
            }
        }
        if (f_05a820(p1, 0x534e4f4d, 1) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x534e4f4d) {
                f_144e8b(d_1c2140, &a, 2);
                f_144e8b(d_1c2140, d_1c129d, (short)a);
            }
        }
        if (f_05a820(p1, 0x52415642, 1) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x52415642) f_012450(d_1c2128, d_1c2140);
        }
        if (f_05a820(p1, 0x52415657, 1) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x52415657) f_011e50(d_1c2130, d_1c2140);
        }
        if (f_05a820(p1, 0x52415644, 1) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x52415644) f_0117e0(d_1c2138, d_1c2140);
        }
        while (f_014a60() < (int)blk) blk = (int)blk / 2;
        char *p = (char *)f_014540(blk, d_1a1794, 0x26d);
        while (f_05a820(p1, 0x504d4554, (short)idx) != 0) {
            f_144e8b(d_1c2140, &rd, 4);
            if (rd == 0x504d4554) {
                f_144e8b(d_1c2140, &a, 2);
                ++idx;
                int amount=(short)a; if (amount == -1) {
                    f_144e8b(d_1c2140, &n, 4);
                } else n=amount;
                n -= f_144e8b(d_1c2140, nm, 14);
                f_14572e(tmp, d_1a9674, nm);
                uh = f_14d0d7(tmp, 0);
                while (n > 0) {
                    unsigned short v;
                    if ((int)blk < n) v = blk; else v = n;
                    unsigned short w = f_144e8b(d_1c2140, p, v);
                    f_144cb6((short)uh, p, w);
                    n -= w;
                }
                int hh = (short)uh;
                f_145279(hh, 0, 0);
                f_144e8b(hh, hdr, 8);
                f_145259(hh);
                if (f_145547(hdr, d_1a6260, 8) == 0) {
                    f_14572e(buf0, d_1a9674, d_1b6ec4);
                    f_059d60(tmp, buf0);
                    f_149336(tmp);
                    int t_446 = f_0d9fe0(&x, buf0, tmp);
                    if (t_446 != -1) f_149336(buf0);
                }
            }
        }
        delete p;
        f_145259(d_1c2140);
        signed char sel = d_1c002c;
        d_1c0004 = d_1bfdbc + sel * 0x61;
        if (f_0db940(d_1c0004) == 0) {
            signed char k=0;
            do {
                char *e = d_1bfdbc + k * 0x61;
                if (f_0db940(e) > 0) {
                    d_1c0004 = e;
                    d_1c002c = f_0ce070(e);
                    break;
                }
                ++k;
            } while((int)k<6);
        }
    }
    d_1a9696 = -1;
    d_1c2a80 = 0;
    f_01a490(d_1c2a84);
    d_1bdb94 = 1;
    f_0999f0(d_1c349c, 1);
    f_0de930(d_1c0004);
    return ret;
}

//@ f_05aed0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den im Diskmenü unter dem Cursor stehenden Spielstand: löscht zunächst alle temporären
 *   Dateien in ..\TEMP\ (außer der Ausnahmedatei 0x90001), prüft und konvertiert den Spielstand bei Bedarf über
 *   f_05b420, lädt ihn bei Erfolg mit f_05a910 und gibt den von f_05b420 vorbereiteten Meldungstext in einem
 *   Dialogfenster (f_0bf730) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf das Diskmenü-Objekt und gibt bei erfolgreichem
 *   Laden den Rückgabewert von f_05a910 (1) zurück (sowie im Fehlerfall ebenfalls 1).
 * - Wichtige Variablen: Der auf dem Heap angelegte 500-Byte-Puffer q nimmt den von f_05b420 formatierten Status-
 *   oder Fehlermeldungstext auf.
 === Ende Beschreibung === */
int f_05aed0(DM *p1)
{
    char b1[80], b0[80]; Dta dta; char nm[16];
    int res;
    short r;
    char *q;
    strcpy(nm, p1->names + (p1->s22 + p1->s26) * 13);
    strcat(nm, d_1b6ecc);
    f_14572e(b0, d_1a9674, d_1b6ed1);
    r = f_1492b4(b0, 0, &dta);
    while (r == (short)0) {
        if (f_144bf0(dta.nm, ((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( 0x90001)) != 0) {
            f_14572e(b1, d_1a9674, dta.nm);
            f_149336(b1);
        }
        r = f_1492d1(&dta);
    }
    f_1492ed(&dta);
    q = (char *)f_014540(500, d_1a1794, 0x2e8);
    f_0d2f90(5, 1);
    if (f_05b420(p1, nm, q) != 0) {
        res = f_05a910(p1, nm);
        f_0d2e70();
        f_0bf730(d_1c2c64, f_133fe0(d_1c3498, q));
        delete q;
    } else {
        f_0d2e70();
        f_0bf730(d_1c2c64, f_133fe0(d_1c3498, q));
        res = 1;
        delete q;
    }
    return res;
}
