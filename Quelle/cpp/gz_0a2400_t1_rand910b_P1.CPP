/* === Beschreibung (Katalog) ===
 * Einheit gz_0a2400_t1_rand910b (0a2500-0a2710)
 *
 * Überblick
 * Diese Einheit enthält den Standardkonstruktor eines Icon-Cache-Eintrags sowie drei Entpackroutinen (f_0a2520,
 * f_0a2660, f_0a26c0) für Lauflängenkodierung (RLE mit Fluchtsymbol 0x7f bzw. Vorzeichenbit 0x80) und
 * LZW-/Wörterbuch-Dekompression (0x32) von Bilddaten.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// P3 11/13 gleich (suche.py 27.10.2026, Basis gz_0a2400_P1.CPP)
// gz_0a2400.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A2400-0x0A2810
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---

// ---- eigene Deklarationen ----
extern char d_dummy_unused[];

int f_147cd0(void *p1);
int f_147ef0(void *p1, void *p2, void *p3, unsigned p4);
int f_148180(int p1);
int f_1455a4(int fd);
int f_145279(int fd, int off, int whence);
int f_145279(int fd);
int f_144e8b(int fd, void *buf, int n);

struct Part {
    char b[9];
    Part();
    ~Part();
};

struct Icon {
    char *data;
    int key;
    short id;
    short w;
    short h;
    Part a;
    Part b;
    ~Icon();
    short f_0a2430();
    short f_0a2440();
    short f_0a2450();
    void f_0a2460(int x, short y, short z);
    void f_0a2480(int x, short y, short z);
};

struct Entry {
    short id;
    int key;
    Icon *icon;
    short ref;
    void f_0a24a0();
    void Clear();
};

inline void h_2660(int p1, char *dst, char *src, short w, short h);
inline void h_26c0(int p1, unsigned char *dst, unsigned char *src, int n);

inline void h_2660(int p1, char *dst, char *src, short w, short h)
{
    signed char c, cnt, k;
    unsigned char v;
    short sw;
    for (; h > 0; h--) {
        sw = w;
        while (sw > 0) {
            c = *src++;
            if (c == 0x7f) {
                cnt = *src++;
                v = *src++;
                for (k = cnt; k > 0; k--) *dst++ = v;
                sw -= cnt;
            } else {
                *dst++ = c;
                sw--;
            }
        }
    }
}

inline void h_26c0(int p1, unsigned char *dst, unsigned char *src, int n)
{
    int i;
    unsigned char hd, cnt, v;
    i = 0;
    if (n > 0) {
        do {
            hd = *src++;
            if (hd & 0x80) {
                cnt = 1 - hd;
                v = *src++;
                i++;
                do {
                    *dst++ = v;
                    cnt--;
                } while (cnt > 0);
            } else {
                cnt = hd + 1;
                do {
                    v = *src++;
                    *dst++ = v;
                    cnt--;
                    i++;
                } while (cnt > 0);
            }
        } while (++i < n);
    }
}


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

int C014710_1(int);
#pragma aux C014710_1 "f_014710" modify exact [eax];
int C014ab0_2(int,int);
#pragma aux C014ab0_2 "f_014ab0" modify exact [eax edx];
int C014ac0_2(int,int);
#pragma aux C014ac0_2 "f_014ac0" modify exact [eax edx];
int C014b10_2(int,int);
#pragma aux C014b10_2 "f_014b10" modify exact [eax];
int C0fad20_2(int,int);
#pragma aux C0fad20_2 "f_0fad20" modify exact [eax edx];


inline Icon::~Icon()
{
    if (data) delete data;
}
//@ f_0a2400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor eines Icon-Objekts p, gibt dessen gemeinsamen Pixelpuffer NI(p, 0) über
 *   f_014710 frei und baut anschließend die beiden eingebetteten RivaRasterImage-Teilobjekte an p + 23 und p +
 *   14 über f_0fad20 ab.
 * - Eingaben und Rückgabe: Die Funktion erhält die Objektadresse p sowie ein unutztes Flag unused und gibt die
 *   Basisadresse p zurück (int).
 * - Wichtige Variablen: Das Feld NI(p, 0) hält den im Konstruktor f_0a22e0 reservierten Bildspeicher für beide
 *   Schaltflächenzustände.
 === Ende Beschreibung === */
int f_0a2400(int p,int unused)
;


//@ f_0a2430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Breite w des Icon-Objekts in Pixeln zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Icon-Objekts und gibt dessen Breite w zurück
 *   (short).
 * - Wichtige Variablen: Das 16-Bit-Feld w liegt an Offset 10 der Icon-Struktur.
 === Ende Beschreibung === */
short Icon::f_0a2430()
;

//@ f_0a2440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Höhe h des Icon-Objekts in Pixeln zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Icon-Objekts und gibt dessen Höhe h zurück
 *   (short).
 * - Wichtige Variablen: Das 16-Bit-Feld h liegt an Offset 12 der Icon-Struktur.
 === Ende Beschreibung === */
short Icon::f_0a2440()
;

//@ f_0a2450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die numerische Icon-Kennung id des Icon-Objekts zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Icon-Objekts und gibt id zurück (short).
 * - Wichtige Variablen: Das Feld id liegt an Offset 8 der Icon-Struktur.
 === Ende Beschreibung === */
short Icon::f_0a2450()
;

//@ f_0a2460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das gedrückte bzw. hervorgehobene Teilbild (b, Offset +23) des Icons transparent an
 *   die Position (y, z) in das Ziel-Rasterbild x.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Icons, den Zielbildzeiger x (int) sowie die
 *   Koordinaten y und z (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das eingebettete RivaRasterImage b repräsentiert den gedrückten Zustand der
 *   Schaltfläche.
 === Ende Beschreibung === */
void Icon::f_0a2460(int x, short y, short z)
;

//@ f_0a2480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet das normale, ungedrückte Teilbild (a, Offset +14) des Icons transparent an die
 *   Position (y, z) in das Ziel-Rasterbild x.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Icons, den Zielbildzeiger x (int) sowie die
 *   Koordinaten y und z (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das eingebettete RivaRasterImage a repräsentiert den Ruhezustand der Schaltfläche.
 === Ende Beschreibung === */
void Icon::f_0a2480(int x, short y, short z)
;

//@ f_0a24a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das in einem Entry-Cache-Slot gespeicherte Icon-Objekt frei (sofern vorhanden) und setzt
 *   die Felder id = -1, icon = 0, ref = 0 und key = 0 auf den freien Ausgangszustand zurück.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Entry-Objekts und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Diese Methode entspricht dem in icon aufgerufenen Entry::Release().
 === Ende Beschreibung === */
void Entry::f_0a24a0()
;

//@ f_0a2500
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert einen einzelnen Entry-Slot des Icon-Caches mit den Standardwerten id = -1, icon
 *   = 0, ref = 0 und key = 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger entry (Entry *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die vier Felder des Entry-Eintrags werden als unbenutzt markiert.
 === Ende Beschreibung === */
void f_0a2500(Entry *entry)
{
    entry->id = -1;
    entry->icon = 0;
    entry->ref = 0;
    entry->key = 0;
}

#pragma inline_depth(0)
//@ f_0a2520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entpackt komprimierte Bilddaten aus dem Quellpuffer src in den Zielpuffer dst abhängig vom
 *   Kompressionsmodus mode: Bei mode == 1 wird eine zeilenweise 0x7f-Lauflängenkodierung der Dimension w x h
 *   entpackt, bei mode == 2 eine Paket-Lauflängenkodierung über n Quellbytes (Bit 0x80 kennzeichnet
 *   Wiederholungsläufe), bei mode == 0x32 der LZW-/Entpacker f_147ef0 aufgerufen und in allen anderen Fällen
 *   werden n Bytes unkomprimiert per memcpy kopiert.
 * - Eingaben und Rückgabe: Die Funktion erhält einen Objektzeiger p1, den Kompressionsmodus mode (unsigned
 *   short), die Byteanzahl n (int), die Breite w und Höhe h (short) sowie den Zielpuffer dst und Quellpuffer src
 *   (char *) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der lokale 616-Byte-Puffer buf wird zu Beginn über f_147cd0 für den Entpacker f_147ef0
 *   initialisiert.
 === Ende Beschreibung === */
void f_0a2520(int p1, unsigned short mode, int n, short w, short h, char *dst, char *src)
{
    char buf[616];
    f_147cd0(buf);
    switch (mode) {
    default:
        memcpy(dst, src, n);
        return;
    case 1: {
        char *out = dst, *in = src;
        volatile short width = w; short rows = h, left;
        signed char c, count, k;
        unsigned char value;
        while (0 < rows) {
            left = width;
            while (left > 0) {
                c = *in++;
                if (c == 0x7f) {
                    count = *in++;
                    value = *in++;
                    k = count;
                    while (k > 0) {
                        *out++ = value;
                        k--;
                    }
                    left -= count;
                } else {
                    *out++ = c;
                    left--;
                }
            }
            rows--;
        }
        return;
    }
    case 2: {
        unsigned char *out = (unsigned char *)dst, *in = (unsigned char *)src;
        unsigned char cnt, v;
        int i = 0, limit = n;
        if (limit > 0) goto body_2520;
        return;
    next_2520:
        if (++i >= limit) return;
    body_2520:
        {
                v = *in++;
                if (v & 0x80) {
                    cnt = 1 - v;
                    v = *in++;
                    i++;
                    do {
                        *out++ = v;
                        cnt--;
                    } while (cnt > 0);
                } else {
                    cnt = v;
                    cnt++;
                    do {
                        v = *in++;
                        *out++ = v;
                        cnt--;
                        i++;
                    } while (cnt > 0);
                }
        }
        goto next_2520;
    }
    case 0x32:
        f_147ef0(buf, dst, src, n);
        return;
    }
    return;
}
#pragma inline_depth(3)

//@ f_0a2660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entpackt ein mit dem Fluchtbyte 0x7f (0x7f, Anzahl, Farbwert) lauflängenkodiertes Bild der
 *   Breite w und Höhe h zeilenweise aus dem Quellpuffer src in den Zielpuffer dst.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Zeiger p1, den Zielpuffer dst (char *), den
 *   Quellpuffer src (char *) sowie die Breite w und Höhe h (short) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Zähler rows und sw überwachen die verbleibenden Bildzeilen und Pixel pro Zeile.
 === Ende Beschreibung === */
void f_0a2660(int p1, char *dst, char *src, short w, short h)
{
    short sw;
    short rows = h;
    signed char c, cnt, k;
    unsigned char v;
    while (rows > 0) {
        sw = w;
        while (sw > 0) {
            c = *src++;
            if (c == 0x7f) {
                cnt = *src++;
                v = *src++;
                k = cnt;
                while (k > 0) {
                    *dst++ = v;
                    k--;
                }
                sw -= cnt;
            } else {
                *dst++ = c;
                sw--;
            }
        }
        rows--;
    }
}

//@ f_0a26c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entpackt n Quellbytes im PackBits-ähnlichen RLE-Format aus src nach dst: Ist im Steuerbyte
 *   value das höchste Bit (0x80) gesetzt, wird das folgende Byte (1 - (signed char)value)-mal wiederholt;
 *   andernfalls werden die nächsten (value + 1) Bytes unverändert in den Zielpuffer kopiert.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Zeiger p1, den Zielpuffer dst (unsigned char
 *   *), den Quellpuffer src (unsigned char *) sowie die Quelllänge n (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Schleifenzähler i verfolgt die Anzahl der bereits verarbeiteten Bytes aus dem
 *   Quellpuffer src.
 === Ende Beschreibung === */
void f_0a26c0(int p1, unsigned char *dst, unsigned char *src, int n)
{
    unsigned char count, value;
    int i;
    for (i = 0; i < n; i++) {
        value = *src++;
        if (value & 0x80) {
            count = 1 - value;
            value = *src++;
            i++;
            do {
                *dst = value;
                count--;
                dst++;
            } while (count > 0);
        } else {
            count = value + 1;
            do {
                value = *src++;
                *dst = value;
                count--;
                dst++;
                i++;
            } while (count > 0);
        }
    }
}

