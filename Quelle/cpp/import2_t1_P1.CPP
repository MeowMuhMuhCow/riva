/* === Beschreibung (Katalog) ===
 * Einheit import2_t1 (0a3a80-0a50e0)
 *
 * Überblick
 * Diese Einheit enthält die beiden großen Konvertierungs- und Importfunktionen (f_0a3c30 und f_0a4690) zum
 * Übernehmen von Heldengruppen aus Spielständen von *DSA 1: Die Schicksalsklinge* (Version 1 sowie Version 2/3,
 * jeweils für PC und Amiga) in das Heldenformat von *Schatten über Riva*.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/3 gleich (suche.py 26.10.2026, Basis import2_t1_P1.CPP)
// import2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A3A80-0x0A50E0
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
int f_014540(int,int,int);
#pragma aux f_014540 modify exact [eax ebx edx];
int f_057760(int);
#pragma aux f_057760 modify exact [];
int f_057750(int);
#pragma aux f_057750 modify exact [];
int f_144e8b(int,int,int);
#pragma aux f_144e8b modify exact [eax ebx edx];
int f_14d075(int,int,int);
#pragma aux f_14d075 modify exact [eax edx];
int f_145300(int,int,int);
#pragma aux f_145300 modify exact [eax];
char f_145400(int);
#pragma aux f_145400 modify exact [eax];
int f_145450(int);
#pragma aux f_145450 modify exact [eax];
short f_149360(int,int);

#pragma aux f_042220 modify exact [];

#pragma aux f_042230 modify exact [];

#pragma aux f_0422c0 modify exact [eax];

void f_0422f0(char *p1, char *p2);

#pragma aux f_042330 modify exact [];

#pragma aux f_042a20 modify exact [eax];

#pragma aux f_042a90 modify exact [eax edx];

#pragma aux f_042af0 modify exact [eax ebx edx];

#pragma aux f_042b80 modify exact [eax edx];

#pragma aux f_042c10 modify exact [eax edx];

#pragma aux f_042d60 modify exact [eax ebx edx];

#pragma aux f_042dd0 modify exact [eax ebx edx];

#pragma aux f_042e40 modify exact [eax ebx edx];

#pragma aux f_042f20 modify exact [eax ebx edx];

#pragma aux f_042f90 modify exact [eax ebx edx];

#pragma aux f_043000 modify exact [eax edx];

#pragma aux f_043060 modify exact [eax edx];

#pragma aux f_0430c0 modify exact [eax edx];
int f_033c50(int,int,int);
#pragma aux f_033c50 modify exact [eax ebx edx];

#pragma aux f_042a60 modify exact [eax edx];

#pragma aux f_042ac0 modify exact [eax edx];

#pragma aux f_042960 modify exact [eax];

#pragma aux f_043120 modify exact [eax];

#pragma aux f_042880 modify exact [eax];

#pragma aux f_0428d0 modify exact [eax];

#pragma aux f_042350 modify exact [eax];

#pragma aux f_0428f0 modify exact [eax];

#pragma aux f_042410 modify exact [eax];

#pragma aux f_042420 modify exact [];

#pragma aux f_042480 modify exact [eax];

#pragma aux f_042870 modify exact [];

#pragma aux f_043130 modify exact [];

#pragma aux f_043180 modify exact [];

#pragma aux f_043190 modify exact [];
int f_043e60(int,int);
#pragma aux f_043e60 modify exact [];
int f_046bc0(int);
#pragma aux f_046bc0 modify exact [eax ecx];
int f_0366e0(int,int,int,int);
#pragma aux f_0366e0 modify exact [eax ebx ecx edx];
int f_03d8b0(int,int,int,int);
#pragma aux f_03d8b0 modify exact [eax ecx edx];
int f_032ab0(int,int,int);
#pragma aux f_032ab0 modify exact [eax ebx edx];
short f_0d4aa0(int,int);
#pragma aux f_0d4aa0 modify exact [eax edx];
short f_0dcc10(int);
#pragma aux f_0dcc10 modify exact [eax];
int f_0dcc40(int,int,int);
#pragma aux f_0dcc40 modify exact [eax ebx edx];
int f_0a2e30(int,int);
#pragma aux f_0a2e30 modify exact [eax edx];
int f_0a3430(int,int,int);
#pragma aux f_0a3430 modify exact [eax ebx edx];
int f_0a34d0(int,int,int);
#pragma aux f_0a34d0 modify exact [eax ebx edx];
short f_0a3570(int,int,int,int,int);
#pragma aux f_0a3570 modify exact [eax ebx ecx edx];
int f_0a3730(int,int);
#pragma aux f_0a3730 modify exact [eax edx];
int f_0a7810(int);
#pragma aux f_0a7810 modify exact [eax];
int f_0a7950(int);
#pragma aux f_0a7950 modify exact [eax];
struct A23 { short s[23]; };
struct B25 { short s[25]; };
struct B26 { short s[26]; };
extern struct A23 d_1a3d04, d_1a3d66;
extern struct B26 d_1a3d32;
extern struct B25 d_1a3d94;
extern short d_1a3cb0[], d_1a3cc0[], d_1a3cca[], d_1a3cda[];
extern short d_1be1a8;
extern short d_1be1a0;
extern short *d_1be1a4, *d_1be1ac;
extern char d_1c2c00[];

extern signed char d_1c2a50, d_1a9693;
extern int d_1c0004;
extern char *d_1bc8f0;
extern char d_1c27a8[];
extern const char d_1a3ce4[];

//@ f_0a3a80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konvertiert einen Helden-Rohdatensatz p1 der Größe p2 aus dem Amiga-Format der Version 2/3 in
 *   das PC-Format, indem die 68000-Ausrichtungsbytes an Offset 0x8b, 0xaa und in den 23 Inventarslots (0x196 + i
 *   * 14 + 6) entfernt und alle 16-Bit-Felder (d_1a3cca), 32-Bit-Felder (d_1a3cda) sowie Bitfelder (0xaa und
 *   Inventarflags) umgedreht werden.
 * - Eingaben und Rückgabe: Die Funktion erhält die Pufferadresse p1 sowie die Puffergröße p2 und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Tabellen d_1a3cca und d_1a3cda enthalten die Strukturoffsets aller umzudrehenden
 *   16-Bit- und 32-Bit-Werte dieses Formats.
 === Ende Beschreibung === */
static inline void h492_0a3830(char *p1, int p2, int p3)
{
    memmove(p1, p1 + 1, p2 - p3 - 1);
}
static inline void h492_0a3840(char *p1)
{
    char t = p1[0];
    p1[0] = p1[1];
    p1[1] = t;
}
static inline void h492_0a3850(char *p1)
{
    char t = p1[0];
    p1[0] = p1[3];
    p1[3] = t;
    t = p1[1];
    p1[1] = p1[2];
    p1[2] = t;
}
static inline void h492_0a3870(unsigned short *p1)
{
    unsigned short v = *p1; unsigned short r = 0; short i;
    for (i = 0; i < 0x10; i++) {
        r = r * 2;
        if (v & 1) r = r + 1;
        v >>= 1;
    }
    *p1 = r;
}
static inline void h492_0a38a0(unsigned int *p1)
{
    unsigned int v = *p1; unsigned int r = 0; short i;
    for (i = 0; i < 0x20; i++) {
        r = r * 2;
        if (v & 1) r = r + 1;
        v = v >> 1;
    }
    *p1 = r;
}
void f_0a3a80(int p1, int p2)
{
    h492_0a3830((char *)(p1 + 0x8b), p2, 0x8b);
    h492_0a3830((char *)(p1 + 0xaa), p2, 0xaa);
    for (d_1be1a8 = 0; d_1be1a8 < 0x17; d_1be1a8++) {
        h492_0a3830((char *)((p1 + 0x196) + d_1be1a8 * 0xe + 6), p2,
                 (p1 + 0x196) + d_1be1a8 * 0xe + 6 - p1);
        h492_0a3830((char *)((p1 + 0x196) + d_1be1a8 * 0xe + 6), p2,
                 (p1 + 0x196) + d_1be1a8 * 0xe + 6 - p1);
    }
    for (d_1be1ac = d_1a3cca; *d_1be1ac != -1; d_1be1ac++)
        h492_0a3840((char *)(p1 + *d_1be1ac));
    for (d_1be1ac = d_1a3cda; *d_1be1ac != -1; d_1be1ac++)
        h492_0a3850((char *)(p1 + *d_1be1ac));
    h492_0a38a0((unsigned int *)(p1 + 0xaa));
    for (d_1be1a8 = 0; d_1be1a8 < 0x17; d_1be1a8++) {
        h492_0a3840((char *)(d_1be1a8 * 0xe + (p1 + 0x196) - p1 + p1));
        h492_0a3840((char *)(d_1be1a8 * 0xe + (p1 + 0x196) - p1 + p1 + 2));
        h492_0a3870((unsigned short *)(d_1be1a8 * 0xe + (p1 + 0x196) + 4));
    }
}
//@ f_0a3c30  groesse 2656 B
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus der geöffneten Spielstandsdatei p2 (Format Version 2/3, Datensatzgröße 0x6da bzw.
 *   0x60a Bytes) nacheinander bis zu sechs aktive Gruppenmitglieder ein, konvertiert ihre Attribute, Talente,
 *   Zauber, 23 Inventarslots (a = d_1a3d04) und das Porträt (f_0a3570) in die Riva-Heldenstruktur (0x5ef Bytes),
 *   filtert unzulässige Gegenstände (b = d_1a3d32) heraus, stattet Magier (Typ 9) garantiert mit einem
 *   Zauberstab (0x85) und Hexen (Typ 7) mit einem Hexenbesen (0x8c) aus, begrenzt das mitgebrachte Vermögen auf
 *   höchstens 1.000 Heller (100 Dukaten) und trägt die Helden über f_0dcc40 und f_0a2e30 in die aktive Gruppe
 *   d_1bc8f0 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1 (int *), das Dateihandle p2 (short) sowie
 *   das Amiga-Formatflag p3 (short) und gibt 1 zurück, wenn mindestens ein Held importiert wurde, sonst -1
 *   (short).
 * - Wichtige Variablen: Die Tabelle d_1a3d04 bildet die 23 alten Inventarplätze auf die 31 Riva-Inventarplätze
 *   ab, und d_1a3d32 listet Gegenstände auf, die beim Wechsel nach Riva entfernt werden müssen.
 === Ende Beschreibung === */
static inline void h3870k(unsigned short *p1)
{
    unsigned short v = *p1; unsigned short r = 0; short i;
    i = 0;
    i = (i & 0) ? (short)0 : i; // haelt die Registerzuteilung wie im Original
    for (; i < 0x10; i++) {
        r = r * 2;
        if (v & 1) r = r + 1;
        v >>= 1;
    }
    *p1 = r;
}
short f_0a3c30(register int *p1, short p2, short p3);
#pragma aux f_0a3c30 parm [eax] [edx] [ebx];
short f_0a3c30(register int *p1, short p2, short p3)
{
    struct Convert { static inline void run(int p1, int p2) {
        h492_0a3830((char *)(p1 + 0x8b), p2, 0x8b);
        h492_0a3830((char *)(p1 + 0xaa), p2, 0xaa);
        for (d_1be1a8 = 0; d_1be1a8 < 0x17; d_1be1a8++) {
            h492_0a3830((char *)((p1 + 0x196) + d_1be1a8 * 0xe + 6), p2,
                     (p1 + 0x196) + d_1be1a8 * 0xe + 6 - p1);
            h492_0a3830((char *)((p1 + 0x196) + d_1be1a8 * 0xe + 6), p2,
                     (p1 + 0x196) + d_1be1a8 * 0xe + 6 - p1);
        }
        for (d_1be1ac = d_1a3cca; *d_1be1ac != -1; d_1be1ac++)
            h492_0a3840((char *)(p1 + *d_1be1ac));
        for (d_1be1ac = d_1a3cda; *d_1be1ac != -1; d_1be1ac++)
            h492_0a3850((char *)(p1 + *d_1be1ac));
        h492_0a38a0((unsigned int *)(p1 + 0xaa));
        for (d_1be1a8 = 0; d_1be1a8 < 0x17; d_1be1a8++) {
            h492_0a3840((char *)(d_1be1a8 * 0xe + (p1 + 0x196) - p1 + p1));
            h492_0a3840((char *)(d_1be1a8 * 0xe + (p1 + 0x196) - p1 + p1 + 2));
            h3870k((unsigned short *)(d_1be1a8 * 0xe + (p1 + 0x196) + 4));
        }
    } };
    short i;
    int row;
    short extra;
    struct KResult { short v; } ret;
    short weight_id;
    short size;
    short j;
    short k2;
    short rd;
    int ptr;
    struct A23 a;
    short id;
    int x;
    short k1;
    short base;
    int buf;
    int n;
    struct B26 b;
    signed char count;
    short cnt;
    ret.v = 1;
    cnt = 0;
    base = p3 ? 0x300 : 0x400;
    extra = p3 ? 0x30 : 0;
    a = d_1a3d04;
    b = d_1a3d32;

    f_057760((int)d_1c2c00);
    size = base + 0x2da + extra;
    buf = f_014540(size, (int)d_1a3ce4, 0x10c);
    do {
        rd = f_144e8b(p2, buf, (unsigned)size);
        if (rd == size) {
            if (p3) Convert::run(buf, size);
            if (*(char *)(buf + 0x8a) && !*(char *)(buf + 0x89) && cnt < 6) {
                f_145300(*p1, 0, 0x5ef);
                f_0a3430((int)p1, buf, p3);
                f_042220((struct hero *)(*p1), d_1c2a50);
                f_042230((struct hero *)(*p1), d_1a9693);
                f_042330((struct hero *)(*p1), f_0a3570((int)p1, buf + 0x2da, *(signed char *)(buf + 0x22), *(signed char *)(buf + 0x21), p3));
                strcpy(d_1c27a8, (char *)(buf + 0x10));
                f_145450((int)d_1c27a8);
                d_1c27a8[0] = f_145400(d_1c27a8[0]);
                f_0422c0((struct hero *)(*p1),(char *)( (int)d_1c27a8));
                f_0422f0((char *)*p1, (char *)buf);
                ret.v = (ret.v & 0) ? (short)0 : ret.v; // haelt die Registerzuteilung wie im Original
                short importOffset = (short)(size - base - 0x20 - 0x142);
                f_042a20((struct hero *)(*p1),(char *)( buf + 0x20), importOffset);
                for (i = 0; i < 23; i++) {
                    id = a.s[i];
                    f_042a90((struct hero *)(*p1), id, *(short *)(buf + i * 14 + 0x196));
                    d_1c0004 = (d_1c0004 & 0) ? 0 : d_1c0004; // haelt die Ladereihenfolge wie im Original
                    f_042af0((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x198));
                    f_042c10((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x19c));
                    f_042b80((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x19d));
                    f_0430c0((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x19e));
                    f_043000((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x19f));
                    f_043060((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x1a0));
                    if (*(char *)(buf + i * 14 + 0x19a) & 1) f_033c50(*p1, id, 1);
                    if (*(char *)(buf + i * 14 + 0x19a) & 2) f_042dd0((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x19a) & 4) f_042d60((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x19a) & 8) f_042e40((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x19a) & 16) f_042f90((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x19a) & 128) f_042f20((struct hero *)(*p1), id, 1);
                }
                for (i = 0; i < 31; i++) {
                    if (f_149360(f_042a60((struct hero *)(*p1), i), (int)&b) != -1 ||
                        f_042a60((struct hero *)(*p1), i) > 0xf9 || f_042a60((struct hero *)(*p1), i) < 0) {
                        f_0a3730(*p1, i);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x85 || f_042a60((struct hero *)(*p1), i) == 0x8c) {
                        f_0a3730(*p1, i);
                        ret.v = (ret.v & 0) ? (short)0 : ret.v; // haelt die Registerzuteilung wie im Original
                    } else if (f_0a7950((*(int **)&d_1c2c40)[f_042a60((struct hero *)(*p1), i)]) && f_042ac0((struct hero *)(*p1), i) <= 0) {
                        f_042af0((struct hero *)(*p1), i, 1);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x24) {
                        f_042af0((struct hero *)(*p1), i, 10);
                    } else if ((f_042a60((struct hero *)(*p1), i) == 0x25 || f_042a60((struct hero *)(*p1), i) == 0x5f || f_042a60((struct hero *)(*p1), i) == 0x2e || f_042a60((struct hero *)(*p1), i) == 0x29) && f_042ac0((struct hero *)(*p1), i) <= 0) {
                        f_042af0((struct hero *)(*p1), i, 1);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x145) {
                        for (j = 0; j <= (short)7; j++) f_03d8b0(*p1, i, j, 0);
                    }
                }
                n = (short)-f_042880((struct hero *)(*p1));
                count = 0;
                f_042870((struct hero *)(*p1), n);
                for (i = 0; i < 31; i++) if (f_042a60((struct hero *)(*p1), i)) count++;
                f_042870((struct hero *)(*p1), count);
                if (f_042350((struct hero *)(*p1)) == (short)9) {
                    f_0366e0(*p1, 0x85, 2, 1);
                    k1 = f_0d4aa0(*p1, 0x85);
                    j = 15;
                    while (k1 == -1) {
                        f_0a3730(*p1, j);
                        f_0366e0(*p1, 0x85, 2, 1);
                        k1 = f_0d4aa0(*p1, 0x85);
                        rd = (rd & 0) ? (short)0 : rd; // haelt die Registerzuteilung wie im Original
                        j++;
                    }
                    f_032ab0(*p1, 3, k1);
                    p3 = (p3 & 0) ? (short)0 : p3; // haelt die Registerzuteilung wie im Original
                }
                if (f_042350((struct hero *)(*p1)) == 7) {
                    f_0366e0(*p1, 0x8c, 2, 1);
                    k2 = f_0d4aa0(*p1, 0x8c);
                    j = 15;
                    j = (j & 0) ? (short)0 : j; // haelt die Registerzuteilung wie im Original
                    while (k2 == -1) {
                        f_0a3730(*p1, j);
                        f_0366e0(*p1, 0x8c, 2, 1);
                        k2 = f_0d4aa0(*p1, 0x8c);
                        j++;
                    }
                    f_032ab0(*p1, 3, k2);
                }
                f_043180((struct hero *)(*p1), 0);
                for (i = 0; i < 31; i++) {
                    weight_id = f_042a60((struct hero *)(*p1), i);
                    if (weight_id) {
                        if (f_0a7950((*(int **)&d_1c2c40)[weight_id])) {
                            int weight = f_0a7810((*(int **)&d_1c2c40)[weight_id]);
                            f_043190((struct hero *)(*p1), (short)(weight * f_042ac0((struct hero *)(*p1), i)));
                        } else {
                            f_043190((struct hero *)(*p1), (short)f_0a7810((*(int **)&d_1c2c40)[weight_id]));
                            cnt = (cnt & 0) ? (short)0 : cnt; // haelt die Registerzuteilung wie im Original
                        }
                    }
                }

                x = ((int)(f_042410((struct hero *)(*p1))));
                if (x < 0 || x > 1000) x = 1000;
                f_042420((struct hero *)(*p1), x);
                if (f_042960((struct hero *)(*p1)) == 0) f_042480((struct hero *)(*p1), 1);
                if (f_043120((struct hero *)(*p1)) != 0 && f_042a60((struct hero *)(*p1), 3) == 0) f_043130((struct hero *)(*p1), 0, 0, 0);
                row = f_046bc0((short)(f_0428d0((struct hero *)(*p1)) + 1));
                ptr = f_046bc0(f_0428d0((struct hero *)(*p1)));
                if (((int)(f_0428f0((struct hero *)(*p1)))) > row || ((int)(f_0428f0((struct hero *)(*p1)))) < ptr) f_043e60(*p1, ptr);
                i = f_0dcc10(d_1c0004);
                {
                    char *dst = d_1bc8f0 + i * 0x5ef;
                    memcpy(dst, (void *)*p1, 0x5ef);
                    f_0dcc40(d_1c0004, (int)dst, i);
                    cnt++;
                    f_0a2e30((int)p1, (int)dst);
                }
            }
        }
    } while ((short)rd != (short)0);
    f_057750((int)d_1c2c00);
    if (!cnt) ret.v = -1;
    delete (char *)buf;
    return ret.v;
}

//@ f_0a4690  groesse 2640 B
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest analog zu f_0a3c30 bis zu sechs aktive Helden aus einem Spielstand des älteren Formats
 *   Version 1 (Datensatzgröße 0x6ca bzw. 0x5fa Bytes, Inventar ab Offset 0x186, Porträt ab 0x2ca) ein, überträgt
 *   alle Werte, Gegenstände (d_1a3d66 / d_1a3d94), Klassen-Pflichtgegenstände (0x85 / 0x8c), Traglasten und
 *   Erfahrungspunkte in das Riva-Format (bei einer Geld-Obergrenze von 1.000 Hellern) und fügt die importierten
 *   Helden in die Gruppe d_1bc8f0 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1 (int *), das Dateihandle p2 (short) sowie
 *   das Amiga-Formatflag p3 (short) und gibt 1 bei Erfolg oder -1 zurück, falls kein gültiger Held gefunden
 *   wurde (short).
 * - Wichtige Variablen: Die Zuordnungstabellen d_1a3d66 und d_1a3d94 steuern die Slot-Übersetzung und
 *   Gegenstandsfilterung für das Version-1-Format.
 === Ende Beschreibung === */
short f_0a4690(register int *p1, short p2, short p3)
{
    struct Bits32 { static inline void run(unsigned int *p1) {
        unsigned int v = *p1; unsigned int r = 0; short i;
        i = 0;
        i = (i & 0) ? (short)0 : i; // haelt die Registerzuteilung wie im Original
        for (; i < 0x20; i++) {
            r = r * 2;
            if (v & 1) r = r + 1;
            v >>= 1;
        }
        *p1 = r;
    } };
    struct Convert { static inline void run(int p1, int p2) {
        h492_0a3830((char *)(p1 + 0x7b), p2, 0x7b);
        h492_0a3830((char *)(p1 + 0x9a), p2, 0x9a);
        for (d_1be1a0 = 0; d_1be1a0 < 0x17; d_1be1a0++) {
            h492_0a3830((char *)((p1 + 0x186) + d_1be1a0 * 0xe + 6), p2,
                     (p1 + 0x186) + d_1be1a0 * 0xe + 6 - p1);
            h492_0a3830((char *)((p1 + 0x186) + d_1be1a0 * 0xe + 6), p2,
                     (p1 + 0x186) + d_1be1a0 * 0xe + 6 - p1);
        }
        for (d_1be1a4 = d_1a3cb0; *d_1be1a4 != -1; d_1be1a4++)
            h492_0a3840((char *)(p1 + *d_1be1a4));
        for (d_1be1a4 = d_1a3cc0; *d_1be1a4 != -1; d_1be1a4++)
            h492_0a3850((char *)(p1 + *d_1be1a4));
        Bits32::run((unsigned int *)(p1 + 0x9a));
        for (d_1be1a0 = 0; d_1be1a0 < 0x17; d_1be1a0++) {
            h492_0a3840((char *)(d_1be1a0 * 0xe + (p1 + 0x186) - p1 + p1));
            h492_0a3840((char *)(d_1be1a0 * 0xe + (p1 + 0x186) - p1 + p1 + 2));
            h492_0a3870((unsigned short *)(d_1be1a0 * 0xe + (p1 + 0x186) + 4));
        }
    } };
    int x;
    short k2;
    int n;
    short i;
    struct NarrowRole { short v; } ret;
    short size;
    int ptr;
    short rd;
    short extra;
    int row;
    short cnt;
    struct A23 a;
    short k1;
    int buf;
    short id;
    short j;
    signed char count;
    short weight_id;
    struct B25 b;
    short base;
    ret.v = 1;
    cnt = 0;
    base = p3 ? 0x300 : 0x400;
    extra = p3 ? 0x30 : 0;
    a = d_1a3d66;
    b = d_1a3d94;

    size = base + 0x2ca + extra;
    buf = f_014540(size, (int)d_1a3ce4, 0x21e);
    f_057760((int)d_1c2c00);
    do {
        rd = f_144e8b(p2, buf, (unsigned)size);
    p2 = (p2 & 0) ? (short)0 : p2; // haelt die Stapelplatz-Reihenfolge wie im Original
        if (rd == size) {
            if (p3) Convert::run(buf, size);
            if (*(char *)(buf + 0x7a) && !*(char *)(buf + 0x79) && cnt < 6) {
                f_145300(*p1, 0, 0x5ef);
                f_0a34d0((int)p1, buf, p3);
                f_042220((struct hero *)(*p1), d_1c2a50);
                f_042230((struct hero *)(*p1), d_1a9693);
                f_042330((struct hero *)(*p1), f_0a3570((int)p1, buf + 0x2ca, *(signed char *)(buf + 0x12), *(signed char *)(buf + 0x11), p3));
                strcpy(d_1c27a8, (char *)buf);
                f_145450((int)d_1c27a8);
                d_1c27a8[0] = f_145400(d_1c27a8[0]);
                f_0422c0((struct hero *)(*p1),(char *)( (int)d_1c27a8));
                f_0422f0((char *)*p1, (char *)buf);

                short offset1720 = (short)(size - base - 0x10 - 0x142);
                f_042a20((struct hero *)(*p1),(char *)( buf + 0x10), offset1720);
                for (i = 0; i < 23; i++) {
                    id = a.s[i];
                    f_042a90((struct hero *)(*p1), id, *(short *)(buf + i * 14 + 0x186));

                    f_042af0((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x188));
                    f_042c10((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x18c));
                    f_042b80((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x18d));
                    f_0430c0((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x18e));
                    f_043000((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x18f));
                    f_043060((struct hero *)(*p1), id, *(signed char *)(buf + i * 14 + 0x190));
                    if (*(char *)(buf + i * 14 + 0x18a) & 1) f_033c50(*p1, id, 1);
                    if (*(char *)(buf + i * 14 + 0x18a) & 2) f_042dd0((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x18a) & 4) f_042d60((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x18a) & 8) f_042e40((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x18a) & 16) f_042f90((struct hero *)(*p1), id, 1);
                    if (*(char *)(buf + i * 14 + 0x18a) & 128) f_042f20((struct hero *)(*p1), id, 1);
                }
                for (i = 0; i < 31; i++) {
                    if (f_149360(f_042a60((struct hero *)(*p1), i), (int)&b) != -1 ||
                        f_042a60((struct hero *)(*p1), i) > 0xf9 || f_042a60((struct hero *)(*p1), i) < 0) {
                        f_0a3730(*p1, i);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x85 || f_042a60((struct hero *)(*p1), i) == 0x8c) {
                        f_0a3730(*p1, i);

                    } else if (f_0a7950((*(int **)&d_1c2c40)[f_042a60((struct hero *)(*p1), i)]) && f_042ac0((struct hero *)(*p1), i) <= 0) {
                        f_042af0((struct hero *)(*p1), i, 1);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x24) {
                        f_042af0((struct hero *)(*p1), i, 10);
                    } else if ((f_042a60((struct hero *)(*p1), i) == 0x25 || f_042a60((struct hero *)(*p1), i) == 0x5f || f_042a60((struct hero *)(*p1), i) == 0x2e || f_042a60((struct hero *)(*p1), i) == 0x29) && f_042ac0((struct hero *)(*p1), i) <= 0) {
                        f_042af0((struct hero *)(*p1), i, 1);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x145) {
                        for (j = 0; j <= (short)7; j++) f_03d8b0(*p1, i, j, 0);
                    }
                }
                n = (short)-f_042880((struct hero *)(*p1));
                count = 0;
                f_042870((struct hero *)(*p1), n);
                for (i = 0; i < 31; i++) if (f_042a60((struct hero *)(*p1), i)) count++;
                f_042870((struct hero *)(*p1), count);
                if (f_042350((struct hero *)(*p1)) == (short)9) {
                    f_0366e0(*p1, 0x85, 2, 1);
                    k1 = f_0d4aa0(*p1, 0x85);
                    j = 15;
                    while (k1 == -1) {
                        f_0a3730(*p1, j);
                        f_0366e0(*p1, 0x85, 2, 1);
                        k1 = f_0d4aa0(*p1, 0x85);

                        j++;
                    }
                    f_032ab0(*p1, 3, k1);

                }
                if (f_042350((struct hero *)(*p1)) == 7) {
                    f_0366e0(*p1, 0x8c, 2, 1);
                    k2 = f_0d4aa0(*p1, 0x8c);
                    j = 15;

                    while (k2 == -1) {
                        f_0a3730(*p1, j);
                        f_0366e0(*p1, 0x8c, 2, 1);
                        k2 = f_0d4aa0(*p1, 0x8c);
                        j++;
                    }
                    f_032ab0(*p1, 3, k2);

                }
                f_043180((struct hero *)(*p1), 0);

                for (i = 0; i < 31; i++) {
                    weight_id = f_042a60((struct hero *)(*p1), i);
                    if (weight_id) {
                        if (f_0a7950((*(int **)&d_1c2c40)[weight_id])) {
                            int weight = f_0a7810((*(int **)&d_1c2c40)[weight_id]);
                            f_043190((struct hero *)(*p1), (short)(weight * f_042ac0((struct hero *)(*p1), i)));
                        } else {
                            f_043190((struct hero *)(*p1), (short)f_0a7810((*(int **)&d_1c2c40)[weight_id]));

                        }
                    }
                }

                x = ((int)(f_042410((struct hero *)(*p1))));

                if (x < 0 || x > 1000) x = 1000;

                f_042420((struct hero *)(*p1), x);
                if (f_042960((struct hero *)(*p1)) == 0) f_042480((struct hero *)(*p1), 1);
                if (f_043120((struct hero *)(*p1)) != 0 && f_042a60((struct hero *)(*p1), 3) == 0) f_043130((struct hero *)(*p1), 0, 0, 0);
                row = f_046bc0((short)(f_0428d0((struct hero *)(*p1)) + 1));
                ptr = f_046bc0(f_0428d0((struct hero *)(*p1)));
                if (((int)(f_0428f0((struct hero *)(*p1)))) > row || ((int)(f_0428f0((struct hero *)(*p1)))) < ptr) f_043e60(*p1, ptr);

                i = f_0dcc10(d_1c0004);
                {
                    char *dst = d_1bc8f0 + i * 0x5ef;
                    memcpy(dst, (void *)*p1, 0x5ef);
                    f_0dcc40(d_1c0004, (int)dst, i);
                    cnt++;
                    f_0a2e30((int)p1, (int)dst);
                }
            }
        }
    } while ((short)rd != (short)0);
    f_057750((int)d_1c2c00);
    if (!cnt) ret.v = -1;
    delete (char *)buf;
    return ret.v;
}

