/* === Beschreibung (Katalog) ===
 * Einheit fz_177260 (0x177260 - 0x178334)
 *
 * Überblick
 * Diese Einheit verwaltet das Laden, Prüfen und Anlegen von 3D-Texturen (.PIX-Pixelmaps) und Materialdateien für
 * die 3D-Dungeon-Engine. Sie zählt den Texturspeicherbedarf nach Größenklassen (<= 64, <= 128, <= 256, > 256
 * Pixel in d_1a99d8 bis d_1a99cc), liest Bildabmessungen und Big-Endian-Datenstrukturen aus Material- und
 * Pixelmap-Dateien (f_177518 bis f_177e30) und erzeugt oder zerstört 0x24 Byte große Pixelmap-Headerstrukturen
 * (f_1781c8, f_1782e8).
 === Ende Beschreibung === */
// P3 2/8 gleich (suche.py 30.10.2026, Basis fz_177260_P1.CPP)
// CC wcc386
// OPT -4r -oneatx -zp1 -s -fp5
// fz_177260.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x177260-0x178334
#include <string.h>
int f_15e469(int p1, const char *p2);
int f_1452bc(int p1);
int f_156370(int p1, const char *p2, const char *p3, int p4);
int f_1563a8(int p1);
int f_15e65b(char *p1, int p2, int p3, int p4);
int f_15e836(int p1);
int f_16cf00(int p1);
int f_16cf05(int p1);
int f_148143(int p1, const char *p2, int p3);
int f_16e060(int p1);
#pragma aux f_15e469 "*";
#pragma aux f_1452bc "*";
#pragma aux f_156370 "*";
#pragma aux f_1563a8 "*";
#pragma aux f_15e65b "*";
#pragma aux f_15e836 "*";
#pragma aux f_16cf00 "*";
#pragma aux f_16cf05 "*";
#pragma aux f_148143 "*";
#pragma aux f_16e060 "*";
#pragma aux f_177e30 "*";
#pragma aux f_1781c8 "*";
#pragma aux f_1782e8 "*";
extern int d_1a996c;
extern int d_1a9a34;
extern const char d_1b9e78[];
extern const char d_1b9eb0[];
extern const char d_1b9f88[];
extern const char d_1b9f98[];
typedef struct { char pad[0x18]; unsigned char t; char nm[0x7d]; } HDR;
int f_144bf0(const char *a, const char *b);
int f_14572e(char *buf, const char *fmt, ...);
int f_177910(char *path, int *w, int *h);
#pragma aux f_144bf0 "*";
#pragma aux f_14572e "*";
#pragma aux f_177910 "*";
#pragma aux f_177260 "*";
#pragma aux f_177518 "*";
#pragma aux f_177ab8 "*";
#pragma aux f_177cc8 "*";
extern const char d_1b9ef4[], d_1b9f2c[], d_1b9f58[];
extern char d_1ccf88[];
extern const char d_1b9e0c[], d_1b9e44[], d_1b9e7c[], d_1b9ebc[];

extern char *d_1cdb90;
extern int d_1a99cc, d_1a99d0, d_1a99d4, d_1a99d8, d_1a9a4c;
extern char d_1a994a;
typedef struct { char nm[0x1a]; unsigned short cnt; unsigned short w; unsigned short h; char pad[4]; } TREC;
extern TREC *d_1cd200;
extern char d_1cd0b0[];
extern char d_1d2b60[];
extern const char d_1b9d58[], d_1b9d88[], d_1b9db8[], d_1b9dc0[];
typedef struct { char pad[0x2c]; char *nm; char pad2[4]; } TENT;
typedef struct { char pad[8]; int n; char pad2[0x24]; TENT *tex; } SSET;
//@ f_177260
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft alle in der Szenen-Texturliste p eingetragenen Texturen (p->tex[0..n-1]): Setzt aus
 *   dem Basisverzeichnis d_1cd0b0, dem Texturnamen und der Endung d_1b9db8 (.PIX) den Dateipfad zusammen, liest
 *   über f_177910 die Bildgröße (w, h) aus, übernimmt bei bekannten Spezialtexturen aus d_1cd200 die
 *   Frame-Anzahl cnt, halbiert bei aktivierter Textur-Halbierung (d_1a994a != 0) große Texturen auf maximal
 *   128x128 und summiert die Texturanzahl in den vier Größenklassen-Zählern d_1a99d8 (<= 64), d_1a99d4 (<= 128),
 *   d_1a99d0 (<= 256) und d_1a99cc (> 256) auf.
 * - Eingaben: Zeiger p auf die Szenen-Texturliste (SSET).
 * - Rückgabewert: int - 0 wenn alle Texturen gültig (<= 256x256) sind, 0xF01B wenn mindestens eine Textur zu
 *   groß ist, oder 0xF005 bei Nullzeiger-Fehler.
 * - Wichtige Variablen:
 *   - d_1a99d8, d_1a99d4, d_1a99d0, d_1a99cc: Globale Zähler für benötigte Textur-Slots nach Kantenlänge.
 *   - d_1cd200, d_1a9a4c: Tabelle und Anzahl vordefinierter Spezial-/Animationstexturen.
 === Ende Beschreibung === */
int f_177260(SSET *p)
{
    char path[0x68];
    int bad;
    TENT *tex;
    int w;
    int h;
    int n;
    char *badname;
    int i;
    char found;
    char *name;
    TREC *record;
    int j;
    int amount;

    d_1a9a34 = 0;
    if (p == 0) {
        d_1cdb90 = (char *)d_1b9d58;
        d_1a996c = 0xf005;
        return 0xf005;
    }
    if (d_1cd200 == 0) {
        d_1cdb90 = (char *)d_1b9d88;
        return d_1a996c = 0xf005;
    }
    d_1a99cc = 0;
    d_1a99d0 = 0;
    d_1a99d4 = 0;
    d_1a99d8 = 0;
    n = p->n;
    tex = p->tex;
    bad = 0;
    badname = 0;
    for (i = 0; i < n; i++, tex++) {
        if (tex->nm == 0) continue;
        name = tex->nm;
        strcpy(path, d_1cd0b0);
        strcat(path, name);
        strcat(path, d_1b9db8);
        found = 0;
        record = d_1cd200;
        for (j = 0; j < d_1a9a4c; j++, record++) {
            if (f_144bf0(record->nm, name) == 0) {
                found = 1;
                break;
            }
        }
        if (f_177910(path, &w, &h) == 0) {
            if (found) {
                w = record->w;
                h = record->h;
                amount = record->cnt;
            } else {
                amount = 1;
            }
            if (w > 0x100 || h > 0x100) {
                badname = name;
                bad = 1;
            }
            if (d_1a994a != 0) {
                while (w > 0x80 || h > 0x80) {
                    w >>= 1;
                    h >>= 1;
                }
            }
            if (w <= 0x40 && h <= 0x40) {
                d_1a99d8 += amount;
            } else if (w <= 0x80 && h <= 0x80) {
                d_1a99d4 += amount;
            } else if (w <= 0x100 && h <= 0x100) {
                d_1a99d0 += amount;
            } else {
                d_1a99cc += amount;
            }
        }
    }
    if (bad) {
        f_14572e(d_1d2b60, d_1b9dc0, badname);
        d_1cdb90 = d_1d2b60;
        return 0xf01b;
    }
    return 0;
}

//@ f_177518
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest eine binäre 3D-Materialdatei fname komplett ein, durchläuft alle enthaltenen
 *   Materialeinträge, zählt deren Gesamtzahl in *count und ermittelt für jedes Material mit zugeordneter
 *   Texturdatei über f_177910 die Texturgröße, um wie in f_177260 die vier Größenklassen-Zähler
 *   d_1a99d8..d_1a99cc zu befüllen.
 * - Eingaben: Dateiname fname der Materialdatei und Rückgabezeiger count für die Anzahl der gelesenen
 *   Materialien.
 * - Rückgabewert: int - 0 bei Erfolg, oder Fehlercode (0xF005 = ungültiger Parameter, 0xF010 = Datei nicht
 *   gefunden, 0xF001 = Speichermangel, 0xF00F = Formatfehler).
 * - Wichtige Variablen:
 *   - pos, len: Aktuelle Leseposition und Gesamtgröße des eingelesenen Materialdatei-Puffers buf.
 === Ende Beschreibung === */
int f_177518(char *fname, int *count)
{
    char path[0x68];
    int buf;
    int w;
    int h;
    int ret;
    int fp;
    int len;
    int pos;
    char found;
    char *p;
    int l;
    int d1;
    int c;
    char *name;
    int k;
    TREC *record;
    int j;
    int amount;

    if (fname == 0 || count == 0) {
        d_1cdb90 = (char *)d_1b9e0c;
        d_1a996c = 0xf005;
        return 0xf005;
    }
    if (d_1cd200 == 0) {
        d_1cdb90 = (char *)d_1b9e44;
        return d_1a996c = 0xf005;
    }
    { int rt = d_1a99cc; d_1a99cc = rt; } // haelt die Registerzuteilung wie im Original
    fp = f_15e469((int)fname, d_1b9e78);
    if (fp == 0) {
        f_14572e(d_1ccf88, d_1b9e7c, fname);
        d_1cdb90 = d_1ccf88;
        d_1a996c = 0xf010;
        return 0xf010;
    }
    len = f_1452bc(*(int *)(fp + 0x10));
    buf = f_156370(len, d_1b9eb0, fname, 0xa);
    if (buf == 0) {
        d_1cdb90 = (char *)d_1b9ebc;
        return d_1a996c = 0xf001;
    }
    f_15e65b((char *)buf, 1, len, fp);
    d_1a99cc = 0;
    d_1a99d0 = 0;
    d_1a99d4 = 0;
    d_1a99d8 = 0;
    ret = 0;
    *(unsigned char *)&ret = (unsigned char)ret; // haelt die Registerzuteilung wie im Original
    *(unsigned char *)&count = (unsigned char)count;
    *count = 0;
    for (pos = 0x10; pos < len; (*count)++) {
        pos += 0x38;
        p = (char *)buf + pos;
        l = strlen(p) + 1;
        pos += l;
        p += l;
        d1 = f_16cf05(*(int *)p);
        c = f_16cf05(*(int *)(p + 4));
        p += 8;
        pos += 8;
        if (d1 != 0 || c != 0) {
            l = strlen(p);
            if (l != c + 1) {
                ret = 0xf00f;
                break;
            }
            pos += l + 5;
            p += l + 5;
            name = p - 5;
            for (k = 0; k < 8 && k < l; k++, name--) {
                if (*name == '\\' || *name == '/' || *name == ':') break;
            }
            strcpy(path, d_1cd0b0);
            strcat(path, name);
            strcat(path, d_1b9db8);
            // haelt die Registerzuteilung wie im Original
            { int saved_word = *(int *)(path + 0); *(int *)(path + 0) = saved_word; }
            { int saved_word = *(int *)(path + 4); *(int *)(path + 4) = saved_word; }
            { int saved_word = *(int *)(path + 8); *(int *)(path + 8) = saved_word; }
            { int saved_word = *(int *)(path + 12); *(int *)(path + 12) = saved_word; }
            { int saved_word = *(int *)(path + 16); *(int *)(path + 16) = saved_word; }
            { int saved_word = *(int *)(path + 20); *(int *)(path + 20) = saved_word; }
            { int saved_word = *(int *)(path + 24); *(int *)(path + 24) = saved_word; }
            { int saved_word = *(int *)(path + 28); *(int *)(path + 28) = saved_word; }
            found = 0;
            record = d_1cd200;
            for (j = 0; j < d_1a9a4c; j++, record++) {
                if (f_144bf0(record->nm, name) == 0) {
                    found = 1;
                    break;
                }
            }
            if (f_177910(path, &w, &h) == 0) {
                if (found) {
                    w = record->w;
                    h = record->h;
                    amount = record->cnt;
                } else {
                    amount = 1;
                }
                if (d_1a994a != 0) {
                    while (w > 0x80 || h > 0x80) {
                        w >>= 1;
                        h >>= 1;
                    }
                }
                if (w <= 0x40 && h <= 0x40) {
                    d_1a99d8 += amount;
                } else if (w <= 0x80 && h <= 0x80) {
                    d_1a99d4 += amount;
                } else if (w <= 0x100 && h <= 0x100) {
                    d_1a99d0 += amount;
                } else {
                    d_1a99cc += amount;
                }
            }
            c = f_16cf05(*(int *)p) + 1;
            pos += 4;
            p += 4;
            l = strlen(p);
            if (l != c) {
                ret = 0xf00f;
                break;
            }
            pos += l + 9;
        }
    }
    f_15e836(fp);
    f_1563a8(buf);
    return ret;
}

//@ f_177910
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet eine einzelne .PIX-Texturdatei fname, aktualisiert bei Bedarf die maximale
 *   Dateigröße d_1a9a34, liest die ersten 0x32 Bytes des Dateiheaders ein, konvertiert die
 *   Big-Endian-16-Bit-Felder für Breite (pw) und Höhe (ph) über f_16cf00 in Little-Endian und schreibt sie nach
 *   *w und *h.
 * - Eingaben: Dateipfad fname sowie Rückgabezeiger w (Breite) und h (Höhe).
 * - Rückgabewert: int - 0 bei Erfolg, sonst Fehlercode (0xF005, 0xF010 oder 0xF001).
 * - Wichtige Variablen:
 *   - pw, ph: Aus dem Dateiheader gelesene und byte-getauschte Texturbreite und Texturhöhe.
 *   - d_1a9a34: Größte bisher beobachtete Texturdateilänge.
 === Ende Beschreibung === */
int f_177910(char *fname, int *w, int *h)
{
    char name[0x65];
    int fp, buf;
    unsigned short pw, ph;   // ohne volatile: Lastfolge *w=pw / *h=ph wie im Original (Opus W44)
    int len;
    char *p;
    int l;
    if (fname == 0 || w == 0 || h == 0) {
        d_1cdb90 = (char *)d_1b9ef4;
        return d_1a996c = 0xf005;
    }
    fp = f_15e469((int)fname, d_1b9e78);
    if (fp == 0) {
        f_14572e(d_1ccf88, d_1b9f2c, fname);
        d_1cdb90 = d_1ccf88;
        d_1a996c = 0xf010;
        return 0xf010;
    }
    len = f_1452bc(*(int *)(fp + 0x10));
    if (len > d_1a9a34) d_1a9a34 = len;
    buf = f_156370(len, d_1b9eb0, fname, 0x14);
    if (buf == 0) {
        d_1cdb90 = (char *)d_1b9f58;
        return d_1a996c = 0xf001;
    }
    if (len > 0x32) len = 0x32;
    f_15e65b((char *)buf, 1, len, fp);
    p = (char *)buf + 0x18;
    f_16cf00(*(short *)(p + 1));
    pw = f_16cf00(*(int *)(p + 1) >> 16);
    ph = f_16cf00(*(int *)(p + 3) >> 16);
    f_16cf00(*(int *)(p + 5) >> 16);
    f_16cf00(*(int *)(p + 7) >> 16);
    p += 0xb;
    l = *(short *)&fp;   // haelt die Registerzuteilung wie im Original
    l = *(short *)&w;   // haelt die Registerzuteilung wie im Original
    l = strlen(p);
    f_148143((int)name, p, 0x64);
    name[0x64] = 0;
     name[28] = name[28]; name[29] = name[29]; name[30] = name[30]; name[31] = name[31]; name[32] = name[32];   // haelt die Registerzuteilung wie im Original
    l++;
    f_16cf05(*(int *)(p + l + 0));
    f_16cf05(*(int *)(p + l + 4));
    f_16cf05(*(int *)(p + l + 8));
    f_16cf05(*(int *)(p + l + 0xc));
    f_15e836(fp);
    f_1563a8(buf);
    *w = pw;
    *h = ph;
    return 0;
}
//@ f_177ab8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest eine binäre 3D-Materialdatei fname ein, prüft und konvertiert bis zu maxn
 *   Materialdatensätze (jeweils mit Materialnamen names[2], Texturnamen names[0] und
 *   Schattierungs-/Tabellennamen names[1]) aus dem Big-Endian-Format und gibt die Anzahl der erfolgreich
 *   gelesenen Materialien zurück.
 * - Eingaben: Dateiname fname, ungenutzter Parameter unused und maximale Anzahl maxn.
 * - Rückgabewert: unsigned - Anzahl n der gelesenen Materialeinträge.
 * - Wichtige Variablen:
 *   - names: Dreielementiges String-Array für Material-, Textur- und Paletten-/Tabellenname jedes Eintrags.
 === Ende Beschreibung === */
unsigned f_177ab8(char *fname, int unused, unsigned maxn)
{
int fp;
    unsigned n;
    int buf;
    char names[3][0x68];
    char *p;
    int len;
    int c;
    int l;
    int pos;
    {
        fp = f_15e469((int)fname, d_1b9e78);
        if (fp == 0) return 0;
        len = f_1452bc(*(int *)(fp + 0x10));
        buf = f_156370(len, d_1b9eb0, fname, 0x1e);
        if (buf == 0) return 0;
        f_15e65b((char *)buf, 1, len, fp);
        pos = 0x10;
        for (n = 0; n < maxn && pos < len; n++) {
            p = (char *)buf + pos;
            f_16cf05(*(int *)(p + 8));
            f_16cf05(*(int *)(p + 0xc));
            f_16cf05(*(int *)(p + 0x10));
            f_16cf05(*(int *)(p + 0x14));
            f_16cf05(*(int *)(p + 0x18));
            f_16cf00(*(int *)(p + 0x1a) >> 16);
            f_16cf05(*(int *)(p + 0x1e));
            f_16cf05(*(int *)(p + 0x22));
            f_16cf05(*(int *)(p + 0x26));
            p += 0x38;
            f_16cf05(*(int *)(p - 0xe));
            f_16cf05(*(int *)(p - 0xa));
            f_16cf05(*(int *)(p - 6));
            l = strlen(p);
            pos += 0x38;
            f_148143((int)names[2], p, 0x64);
            l++;
            p += l;
            names[2][0x64] = 0;
            pos += l;
 // haelt die Registerzuteilung wie im Original
            len = (len & 0) ? 0 : len; // haelt die Registerzuteilung wie im Original
            f_16cf05(*(int *)p);
            pos += 8;
            c = f_16cf05(*(int *)(p + 4));
            p += 8;
            l = strlen(p);
            if (l != c + 1) break;
            f_148143((int)names[0], p, 0x64);
            l++;
            p += l;
            names[0][0x64] = 0;
            pos += l;
            p += 4;
            f_16cf05(*(int *)(p - 4));
            pos += 8;
            c = f_16cf05(*(int *)p) + 1;
            p += 4;
            l = strlen(p);
            if (l != c) break;
            f_148143((int)names[1], p, 0x64);
            pos += l + 9;
            names[1][0x64] = 0;
        }
        f_15e836(fp);
        f_1563a8(buf);
    }
    return n;
}

//@ f_endp_d14
//@ f_177cc8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchläuft eine mehrteilige .PIX-Pixelmap-Datei fname mit bis zu maxn eingebetteten
 *   Texturblöcken, konvertiert deren Headerfelder aus dem Big-Endian-Format, überspringt jeweils die zugehörigen
 *   Pixeldatenblöcke (pos += d) und gibt die Anzahl der enthaltenen Texturen zurück.
 * - Eingaben: Dateiname fname, ungenutzter Parameter unused und maximale Anzahl maxn.
 * - Rückgabewert: unsigned - Anzahl n der in der Datei gefundenen Pixelmap-Blöcke.
 * - Wichtige Variablen:
 *   - d: Bytegröße des jeweiligen Pixeldatenblocks.
 === Ende Beschreibung === */
unsigned f_177cc8(char *fname, int unused, unsigned maxn)
{
    char name[0x65];
    int buf;
    int fp;
    int len;
    unsigned n;
    int pos;
    char *p;
    int l, d;
    fp = f_15e469((int)fname, d_1b9e78);
    if (fp == 0) return 0;
    len = f_1452bc(*(int *)(fp + 0x10));
    buf = f_156370(len, d_1b9eb0, fname, 0x28);
    if (buf == 0) return 0;
    f_15e65b((char *)buf, 1, len, fp);
    pos = 0x10;
    for (n = 0; n < maxn && pos < len; ) {
        pos += 8;
        p = (char *)buf + pos;
        f_16cf00(*(short *)(p + 1));
        f_16cf00(*(int *)(p + 1) >> 16);
        f_16cf00(*(int *)(p + 3) >> 16);
        f_16cf00(*(int *)(p + 5) >> 16);
        f_16cf00(*(int *)(p + 7) >> 16);
        p += 0xb;
        l = strlen(p);
        f_148143((int)name, p, 0x64);
        // haelt die Registerzuteilung wie im Original
        { int saved_word = *(int *)(name + 0); *(int *)(name + 0) = saved_word; }
        { int saved_word = *(int *)(name + 4); *(int *)(name + 4) = saved_word; }
        { int saved_word = *(int *)(name + 8); *(int *)(name + 8) = saved_word; }
        { int saved_word = *(int *)(name + 12); *(int *)(name + 12) = saved_word; }
        { int saved_word = *(int *)(name + 16); *(int *)(name + 16) = saved_word; }
        { int saved_word = *(int *)(name + 20); *(int *)(name + 20) = saved_word; }
        { int saved_word = *(int *)(name + 24); *(int *)(name + 24) = saved_word; }
        { char saved_byte = name[28]; name[28] = saved_byte; }
        name[0x64] = 0;
        l++;
        pos += 0xb;
        p += l;
        pos += l;
        f_16cf05(*(int *)p);
        pos += 0x10;
        n++;
        d = f_16cf05(*(int *)(p + 4));
        f_16cf05(*(int *)(p + 8));
        pos += d;
        f_16cf05(*(int *)(p + 0xc));
    }
    f_15e836(fp);
    f_1563a8(buf);
    return n;
}
//@ f_177e30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt eine einzelne Pixelmap-Datei p1 vollständig in den Speicher: Reserviert eine 0x24
 *   Byte große Pixelmap-Headerstruktur hdr, liest den 0x96-Byte-Dateianfang in h, konvertiert Typ, Zeilenbreite
 *   (+0x10), Breite (+0x18), Höhe (+0x1A) und Ursprung (+0x1C, +0x1E), kopiert den eingebetteten Texturnamen in
 *   einen eigenen Stringpuffer nm, liest die gesamten Pixeldaten (sz Bytes) in den Puffer dat, dreht bei 16-Bit-
 *   oder 32-Bit-Pixelformaten (Typ 4..8) die Byte-Reihenfolge aller Pixel und gibt den Zeiger hdr zurück.
 * - Eingaben: Dateiname p1 (als int/Zeiger).
 * - Rückgabewert: int - Zeiger hdr auf die geladene Pixelmap-Struktur oder 0 bei Fehler (Fehlercode in
 *   d_1a996c).
 * - Wichtige Variablen:
 *   - hdr: Neu angelegte 0x24-Byte-BRender-Pixelmap-Struktur (Flags 0x12 | 0x40 | 0x20 an Offset +0x13).
 *   - nm, dat: Dynamisch reservierte Puffer für den Texturnamen (*(int *)hdr) und die Pixeldaten (*(int *)(hdr +
 *     4)).
 === Ende Beschreibung === */
int f_177e30(int p1)
{
    int *lp;
    short *sp;
    char *q;
    int t5;
    int nm;
    int dat;
    int sz;
    int hdr;
    int fp;
    HDR h;
    if (p1 != 0) {
        fp = f_15e469(p1, d_1b9e78);
        if (fp == 0) {
            d_1a996c = 0xf00a;
            return fp;
        } else {
            int len;
            int n;
            len = f_1452bc(*(int *)(fp + 0x10));
            if (d_1a9a34 < len) d_1a9a34 = len;
            hdr = f_156370(0x24, d_1b9eb0, (const char *)p1, 0x32);
            if (hdr == 0) {
                d_1a996c = 0xf001;
                f_15e836(fp);
                return 0;
            }
            f_15e65b((char *)&h, 1, 0x96, fp);
            *(char *)(hdr + 0x13) = 0x12;
            *(short *)(hdr + 0x1c) = 0;
            *(short *)(hdr + 0x1e) = 0;
            *(char *)(hdr + 0x12) = h.t;
            *(short *)(hdr + 0x10) = f_16cf00((*(int *)((char *)&h + 0x17)) >> 16);
            *(short *)(hdr + 0x18) = f_16cf00((*(int *)((char *)&h + 0x19)) >> 16);
            *(short *)(hdr + 0x1a) = f_16cf00((*(int *)((char *)&h + 0x1b)) >> 16);
            *(short *)(hdr + 0x1c) = f_16cf00((*(int *)((char *)&h + 0x1d)) >> 16);
            { int a0_ = (*(int *)((char *)&h + 0x1f)) >> 16; t5 = f_16cf00(a0_); }
            *(int *)(hdr + 0xc) = 0;
            *(int *)hdr = 0;
            *(int *)(hdr + 0x20) = 0;
            *(int *)(hdr + 4) = 0;
            *(short *)(hdr + 0x1e) = t5;
            q = (char *)&h.t;
            q += 0xb;
            n = p1; /* haelt die Registerzuteilung wie im Original */
            n = strlen(q);
            len = n;
            len += 1;
            nm = f_156370(len, d_1b9eb0, (const char *)p1, 0x3c);
            if (nm == 0) {
                f_1563a8(hdr);
                f_15e836(fp);
                d_1a996c = 0xf001;
                return 0;
            }
            *(char *)(hdr + 0x13) |= 0x40;
            f_148143(nm, q, n);
            *(char *)(nm + n) = 0;
            q += len;
            *(int *)hdr = nm;
            f_16cf05(*(int *)q);
            f_16cf05(*(int *)(q + 4));
            f_16cf05(*(int *)(q + 8));
            f_16cf05(*(int *)(q + 0xc));
            sz = ((*(int *)(hdr + 0xe)) >> 16) * *(unsigned short *)(hdr + 0x1a);
            q += 0x10;
            dat = f_156370(sz, d_1b9eb0, (const char *)p1, 0x46);
            if (dat == 0) {
                f_1563a8(*(int *)hdr);
                f_1563a8(hdr);
                f_15e836(fp);
                d_1a996c = 0xf001;
                return 0;
            }
            *(char *)(hdr + 0x13) |= 0x20;
            n = 0x96 - (q - (char *)&h);
            if (n >= sz) {
                memcpy((void *)dat, q, sz);
            } else {
                memcpy((void *)dat, q, n);
                f_15e65b((char *)(dat + n), 1, sz - n, fp);
            }
            switch (*(unsigned char *)(hdr + 0x12)) {
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            case 4:
            case 5:
                sp = (short *)dat;
                len = (sz >> 1) + 1;
                goto tw; bw: *sp++ = f_16cf00(*sp); tw: if (--len != 0) goto bw;
                break;
            case 6:
            case 7:
            case 8:
                lp = (int *)dat;
                len = (sz >> 2) + 1;
                goto td; bd: *lp++ = f_16cf05(*lp); td: if (--len != 0) goto bd;
                break;
            }
            *(int *)(hdr + 4) = dat;
            f_15e836(fp);
            return hdr;
        }
    }
    return p1;
}
//@ f_1781c8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt im Speicher eine neue 0x24 Byte große Pixelmap-Struktur für das Pixelformat p1 (0
 *   = 1 Bit bis 14 = 16 Bit), die Breite p2 und die Höhe p3: Berechnet aus dem Format p1 die Zeilenbreite n in
 *   Bytes, übernimmt entweder den vom Aufrufer übergebenen Pixelpuffer p4 oder reserviert bei p4 == 0 einen
 *   eigenen Puffer der Größe n * p3 Bytes (mit Eigentümer-Flag 0x20 in r + 0x13).
 * - Eingaben: Pixelformat-Kennung p1, Breite p2, Höhe p3, optionaler bestehender Pixelpuffer p4 und ungenutzter
 *   Parameter p5.
 * - Rückgabewert: int - Zeiger r auf die angelegte Pixelmap-Struktur oder 0 bei Fehler.
 * - Wichtige Variablen:
 *   - n: Berechnete Byte-Schrittweite (Stride) einer Bildzeile je nach Bittiefe p1.
 === Ende Beschreibung === */
int f_1781c8(char p1, unsigned p2, unsigned p3, int p4, int p5)
{
    int r;
    unsigned n;
    r = f_156370(0x24, d_1b9eb0, d_1b9f88, 0x50);
    if (r == 0) return 0;
    switch (p1) {
    case 0: n = (p2 + 7) >> 3; goto common;
common:
    *(volatile int *)r = 0;
    *(int *)(r + 0xc) = 0;
    *(int *)(r + 0x20) = 0;
    *(short *)(r + 0x14) = 0;
    *(short *)(r + 0x16) = 0;
    *(char *)(r + 0x13) = 0x16;
    *(short *)(r + 0x10) = n;
    *(short *)(r + 0x18) = p2;
    *(char *)(r + 0x12) = p1;
    *(short *)(r + 0x1a) = p3;
    *(short *)(r + 0x1c) = p2 >> 1;
    *(short *)(r + 0x1e) = p3 >> 1;
    if (p4 != 0) goto external;
    n = f_156370(n * p3, d_1b9eb0, d_1b9f98, 0x5a);
    *(int *)(r + 4) = n;
    if (n != 0) goto owned;
fail:
    f_1563a8(r);
    return 0;
    case 1: n = (p2 + 3) >> 2; goto common;
    case 2: n = (p2 + 1) >> 1; goto common;
    case 3:
    case 13: n = p2; goto common;
    case 4:
    case 5:
    case 11:
    case 14: n = p2 * 2; goto common;
    case 6:
    case 10: n = p2 * 3; goto common;
    case 7:
    case 8:
    case 9:
    case 12: n = p2 * 4; goto common;
    default: goto fail;
    }
owned:
    *(char *)(r + 0x13) |= 0x20;
    goto finish;
external:
    *(int *)(r + 4) = p4;
finish:
    return r;
}
//@ f_1782e8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt eine Pixelmap-Struktur p1 wieder frei: Wenn das Kennbit 0x10 in *(unsigned char *)(p1
 *   + 0x13) gesetzt ist, werden je nach Eigentümer-Bits 0x20 und 0x40 der Pixelpuffer (+4), der Namenspuffer
 *   (+0) und die Headerstruktur selbst über f_1563a8 freigegeben; andernfalls wird die allgemeine
 *   BRender-Freigabefunktion f_16e060(p1) aufgerufen.
 * - Eingaben: Zeiger p1 auf die freizugebende Pixelmap-Struktur.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1782e8(int p1)
{
    int t1;
    int t2;
    if (p1 != 0) {
        if ((*(unsigned char *)(p1 + 0x13) & 0x10) != 0) {
            if ((*(unsigned char *)(p1 + 0x13) & 0x20) != 0 && *(int *)(p1 + 4) != 0) f_1563a8(*(int *)(p1 + 4));
            if ((*(unsigned char *)(p1 + 0x13) & 0x40) != 0 && *(int *)p1 != 0) f_1563a8(*(int *)p1);
            f_1563a8(p1);
            return;
        }
        f_16e060(p1);
    }
}
