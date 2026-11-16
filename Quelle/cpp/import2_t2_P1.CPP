/* === Beschreibung (Katalog) ===
 * Einheit import2_t2 (0a50e0-0a5730)
 *
 * Überblick
 * Diese Einheit bildet den Abschluss des Helden-Importmoduls (IMPORT2.CPP) und übernimmt den Import von
 * Heldengruppen aus chunk-basierten Spielständen von *DSA 2: Sternenschweif* (gekennzeichnet durch die
 * Chunk-Signatur 'CHAR' = 0x52414843).
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 2/4 gleich (suche.py 29.10.2026, Basis import2_t2_P1.CPP)
// import2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A3A80-0x0A5730
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_032ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0366e0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_03d8b0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0

                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_043e60(int p1, int p2);                           // reg eax edx stapel 0
int f_046bc0(int p1);
int f_057750(int p1);                                   // reg eax stapel 0
int f_057760(int p1);                                   // reg eax stapel 0
int f_0a2e30(int p1, int p2);                           // reg edx stapel 0
int f_0a3700(int p1, int p2);                           // reg edx stapel 0
int f_0a3730(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
short f_0d4aa0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dcc10(int p1);                                   // reg eax stapel 0
int f_0dcc40(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
short f_149360(int p1, void *p2);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a3cb0;                    // 0x1A3CB0
extern int d_1a3cc0;                    // 0x1A3CC0
extern int d_1a3cca;                    // 0x1A3CCA
extern int d_1a3cda;                    // 0x1A3CDA
extern int d_1a3d32;                    // 0x1A3D32
extern int d_1a3d94;                    // 0x1A3D94
extern int d_1a3dc6;                    // 0x1A3DC6
extern short d_1a9693;
extern short d_1bc8f0;                    // 0x1BC8F0
extern int d_1be1a0;                    // 0x1BE1A0
extern int d_1be1a4;                    // 0x1BE1A4
extern int d_1be1a8;                    // 0x1BE1A8
extern int d_1be1ac;                    // 0x1BE1AC
extern int d_1c0004;                    // 0x1C0004
extern int d_1c2a50;
extern int d_1c2c00;                    // 0x1C2C00
extern int d_1c2c40;                    // 0x1C2C40
extern const char d_1a3ce4[];           // Text 0x1A3CE4
extern const char d_1a9680[];           // Text 0x1A9680

int f_144e8b(int fd, void *buf, int n);
int f_145279(int fd, int off, int wh);
int f_0a5240(int *p1, short p2);
struct T94 { char b[94]; };
struct T5EF { char b[0x5ef]; };
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0a50e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht eine geöffnete *Sternenschweif*-Spielstandsdatei p2 ab Datei-Offset 0x114 Block für
 *   Block nach dem ersten 'CHAR'-Chunk (0x52414843), setzt den Dateizeiger an den Beginn dieser Chunk-Kennung
 *   zurück und meldet, ob Charakterdaten gefunden wurden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1 sowie das Dateihandle p2 (short) und gibt
 *   1 bei gefundenem 'CHAR'-Block oder 0 bei Dateiende zurück (int).
 * - Wichtige Variablen: Jeder nicht passende Chunk wird anhand seiner 16-Bit-Länge l18 (bzw. bei l18 == -1
 *   anhand der nachfolgenden 32-Bit-Länge l1c) übersprungen.
 === Ende Beschreibung === */
int f_0a50e0(int p1, short p2)
{
    int found = 0;
    int cnt = 1;
    short rd = cnt;
    int w;
    int off = 0; // haelt die Stapelplatz-Reihenfolge wie im Original
    short l18;
    f_145279((short)p2, 0x114, 0);
    while (found == 0 && rd) {
        int l1c;
        w = 0;
        rd = f_144e8b((short)p2, &w, 4);
        if (w == 0x52414843 && (short)cnt++ == (short)1) {
            found = 1;
        } else {
            f_144e8b((short)p2, &l18, 2);
            off = l18;
            if (off == -1) {
                f_144e8b((short)p2, &l1c, 4);
                f_145279((short)p2, l1c, 1);
            } else {
                f_145279((short)p2, off, 1);
            }
        }
    }
    if (found != 0) f_145279((short)p2, -4, 1);
    return found;
}
//@ f_0a51c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen einzelnen 'CHAR'-Chunk (0x52414843) aus der Datei p3 in die Heldenstruktur p2
 *   (0x5ef Bytes) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1, den Zielheldenzeiger p2 sowie das
 *   Dateihandle p3 (short) und gibt bei Erfolg die Strukturgröße 0x5ef (1519 Bytes), andernfalls 0 zurück (int).
 * - Wichtige Variablen: Die ersten len - 12 Bytes des Chunks werden ab Offset +12 der Heldenstruktur abgelegt,
 *   während die letzten 12 Bytes in einen lokalen Puffer buf gelesen werden.
 === Ende Beschreibung === */
int f_0a51c0(int p1, int p2, short p3)
{
    char buf[12];
    int mg;
    unsigned short len;
    int fd = p3;
    f_144e8b(fd, &mg, 4);
    if (mg == 0x52414843) {
        unsigned m;
        int q;
        f_144e8b(fd, &len, 2);
        m = len;
        q = ((int)(f_042260((struct hero *)(p2))));
        f_144e8b(fd, (void *)(q + 0xc), m - 0xc);
        f_144e8b(fd, buf, 0xc);
        return 0x5ef;
    }
    return 0;
}
//@ f_0a5230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leitet den Charakterimport für *Sternenschweif*-Spielstände der Versionen 2 und 3 direkt an
 *   f_0a5240 weiter.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1 (int *) sowie das Dateihandle p2 (short)
 *   und gibt den Statuswert von f_0a5240 zurück (int).
 * - Wichtige Variablen: Es werden keine eigenen Variablen benötigt.
 === Ende Beschreibung === */
int f_0a5230(int *p1, short p2)
{
    return f_0a5240(p1, p2);
}
struct Chunk904 { static int read(int obj,short fd,int &mg) {
 unsigned short len; char hdrbuf[12];
 f_144e8b(fd,&mg,4);
 if(mg==0x52414843){
 f_144e8b(fd,&len,2);
 f_144e8b(fd,(void*)(((int)(f_042260((struct hero *)(obj))))+12),len-12);
 f_144e8b(fd,hdrbuf,12);return 0x5ef;
 }
 return 0;
}};
//@ f_0a5240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht über f_0a50e0 die 'CHAR'-Blöcke in einer *Sternenschweif*-Spielstandsdatei p2, liest bis
 *   zu sechs lebende Gruppenmitglieder ein, entfernt nicht übernehmbare Gegenstände anhand der Ausschlussliste
 *   d_1a3dc6, prüft Pflichtgegenstände für Magier (0x85) und Hexen (0x8c), berechnet Traglast und
 *   Stufen-AP-Grenzen neu, begrenzt das mitgebrachte Geld auf 2.000 Heller (200 Dukaten) und trägt die Helden
 *   über f_0dcc40 und f_0a2e30 in die aktive Gruppe d_1bc8f0 ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Importer-Zeiger p1 (int *) sowie das Dateihandle p2 (short)
 *   und gibt 1 bei mindestens einem importierten Helden oder -1 bei Misserfolg zurück (int).
 * - Wichtige Variablen: Diese Funktion enthält beim Charakterimport aus *Sternenschweif* einen eindeutigen
 *   Originalfehler: Während für Hexen (Typ == 7) korrekt f_0d4aa0(*p1, 0x8c) == -1 geprüft wird, steht für
 *   Magier (Typ == 9) der Tippfehler f_0d4aa0(*p1, 0x85) == 1 statt == -1 (cmp eax, 1), sodass ein Magier nur
 *   dann einen neuen Zauberstab (0x85) an Handplatz 3 erhält, wenn sich zufällig bereits in Inventarslot 1
 *   (Hals) ein Zauberstab befand (siehe Fehlerliste).
 === Ende Beschreibung === */
int f_0a5240(int *p1, short p2)
{
    int ret = 1;
    short cnt;
    struct T94 tab = *(struct T94 *)&d_1a3dc6;
    short v;
    unsigned short len;
    short i = 0, k, id, t, j;
    signed char count;
    // haelt die Registerzuteilung wie im Original
    int x = 0, n=0, dst;
    int mg;
    char hdrbuf[12];
    f_057760((int)&d_1c2c00);
    if (f_0a50e0((cnt = 0, (int)p1), p2)) {
        do {
            if ((short)(v=Chunk904::read(*p1,p2,mg)) == (short)0x5ef && ((char)(f_042460((struct hero *)(*p1)))) && !((char)(f_042400((struct hero *)(*p1)))) && cnt < 6) {
                f_0a3700((int)p1, *p1);
                f_0421f0((char *)(*p1),(char *)( (int)d_1a9680));
                f_042220((struct hero *)(*p1), *(signed char *)&d_1c2a50);
                f_042230((struct hero *)(*p1), *(signed char *)&d_1a9693);
                for (i = 0; i < 31; ++i) {
                    if (f_149360(f_042a60((struct hero *)(*p1), i), &tab) != -1 ||
                        f_042a60((struct hero *)(*p1), i) > 0x15f || f_042a60((struct hero *)(*p1), i) < 0) {
                        f_0a3730(*p1, i);
                    } else if (f_042a60((struct hero *)(*p1), i) == 0x145) {
                        for (k = 0; k <= (short)7; ++k)
                            f_03d8b0(*p1, i, k, 0);
                    }
                }
                f_042870((struct hero *)(*p1), (short)-(signed char)((char)(f_042880((struct hero *)(*p1)))));
                *(signed char *)((p2 & 0) ? (void *)0 : (void *)&count) = 0; // haelt die Stapel-Adressierung wie im Original
                for (j = 0; j < 31; ++j) {
                    if (f_042a60((struct hero *)(*p1), j) != (short)0)
                        ++count;
                }
                f_042870((struct hero *)(*p1), count);
                if ((signed char)((char)(f_042350((struct hero *)(*p1)))) == 9 && f_0d4aa0(*p1, 0x85) == 1) {
                    f_0366e0(*p1, 0x85, 2, 1);
                    i = 15;
                    t = f_0d4aa0(*p1, 0x85);
                    while (t == -1) {
                        f_0a3730(*p1, i);
                        f_0366e0(*p1, 0x85, 2, 1);
                        t = f_0d4aa0(*p1, 0x85);
                        ++i;
                    }
                    f_032ab0(*p1, 3, t);
                }
                if ((signed char)((char)(f_042350((struct hero *)(*p1)))) == 7 && f_0d4aa0(*p1, 0x8c) == -1) {
                    f_0366e0(*p1, 0x8c, 2, 1);
                    i = 15;
                    t = f_0d4aa0(*p1, 0x8c);
                    while (t == -1) {
                        f_0a3730(*p1, i);
                        f_0366e0(*p1, 0x8c, 2, 1);
                        t = f_0d4aa0(*p1, 0x8c);
                        ++i;
                    }
                    f_032ab0(*p1, 3, t);
                }
                f_043180((struct hero *)(*p1), 0);
                for (i = 0; i < 31; ++i) {
                    id = f_042a60((struct hero *)(*p1), i);
                    if (id != (short)0) {
                        if (((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7950())
                            f_043190((struct hero *)(*p1), (short)(((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810() * f_042ac0((struct hero *)(*p1), i)));
                        else
                            f_043190((struct hero *)(*p1), ((RivaItemDefinition*)((*(int **)&d_1c2c40)[id]))->f_0a7810());
                    }
                }
                n = ((int)(f_042410((struct hero *)(*p1))));
                if (n < 0 || n > 2000)
                    n = 2000;
                f_042420((struct hero *)(*p1), n);
                int t_212 = f_042960((struct hero *)(*p1));
                if (t_212 == 0)
                    f_042480((struct hero *)(*p1), 1);
                if ((int)f_043120((struct hero *)(*p1)) != 0 && f_042a60((struct hero *)(*p1), 3) == 0)
                    f_043130((struct hero *)(*p1), 0, 0, 0);
                x = f_046bc0((short)((signed char)((char)(f_0428d0((struct hero *)(*p1)))) + 1));
                n = f_046bc0((short)(signed char)((char)(f_0428d0((struct hero *)(*p1)))));
                if (((int)(f_0428f0((struct hero *)(*p1)))) > x || ((int)(f_0428f0((struct hero *)(*p1)))) < n)
                    f_043e60(*p1, n);
                i = f_0dcc10(d_1c0004);
                dst = (int)(*(T5EF **)&d_1bc8f0 + i);
                memcpy((void *)dst, (void *)*p1, 0x5ef);
                f_0dcc40(d_1c0004, dst, i);
                ++cnt;
                f_0a2e30((int)p1, dst);
            }
        } while ((short)v != (short)0);
    }
    f_057750((int)&d_1c2c00);
    if (!cnt)
        ret = -1;
    return ret;
}
