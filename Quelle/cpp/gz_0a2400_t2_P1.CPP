/* === Beschreibung (Katalog) ===
 * Einheit gz_0a2400_t2 (0a2710-0a2810)
 *
 * Überblick
 * Diese kleine Einheit berechnet die Dateioffset-Prüfsummen zum Auffinden der Heldenblöcke in Spielständen aus
 * den Vorgängerspielen (*Schicksalsklinge* und *Sternenschweif*), bevor der eigentliche Charakterimport in
 * import startet.
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

struct Gfx {
    char b[9];
    Gfx();
    ~Gfx();
};

struct Icon {
    char *data;
    int key;
    short id;
    short w;
    short h;
    Gfx a;
    Gfx b;
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
#pragma inline_depth(0)
#pragma inline_depth(3)
//@ f_0a2710
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus der geöffneten Spielstandsdatei fd ab Datei-Offset 0x155d insgesamt 0x109 (265)
 *   32-Bit-Wörter im Big-/Little-Endian-Format (f_148180), summiert sie auf den Basiswert 0x1981 auf, stellt die
 *   ursprüngliche Dateiposition wieder her und gibt die Summe als Startoffset der Heldendaten zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Dateihandle fd (short) und gibt den berechneten Datei-Offset
 *   zurück (int).
 * - Wichtige Variablen: Das lokale Array buf[0x109] nimmt die 0x424 Bytes der Offsettabelle auf, die über
 *   f_148180 bytegedreht und zu sum addiert werden.
 === Ende Beschreibung === */
int f_0a2710(short fd)
{
    int buf[0x109];
    short i;
    int pos, sum;
    pos = f_1455a4(fd);
    f_145279(fd, 0x155d, 0);
    f_144e8b(fd, buf, 0x424);
    sum = 0x1981;
    for (i = 0; i < 0x109; i++) {
        sum += (buf[i] = f_148180(buf[i]));
    }
    f_145279(fd, pos, 0);
    return sum;
}

//@ f_0a2790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest aus der geöffneten Spielstandsdatei fd ab Datei-Offset 0x162f insgesamt 0x10a (266)
 *   32-Bit-Wörter ein, summiert sie nach Byte-Reihenfolge-Umwandlung (f_148180) auf den Basiswert 0x1a57 auf,
 *   setzt den Dateizeiger auf die Ausgangsposition zurück und gibt den berechneten Datei-Offset zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält das Dateihandle fd (short) und gibt den berechneten Datei-Offset
 *   zurück (int).
 * - Wichtige Variablen: Das lokale Array buf[0x10a] (0x428 Bytes) dient als Lesepuffer für die Offsettabelle
 *   dieser Spielstandsversion.
 === Ende Beschreibung === */
int f_0a2790(short fd)
{
    int buf[0x10a];
    short i;
    int pos, sum;
    pos = f_1455a4(fd);
    f_145279(fd, 0x162f, 0);
    f_144e8b(fd, buf, 0x428);
    sum = 0x1a57;
    for (i = 0; i < 0x10a; i++) {
        sum += (buf[i] = f_148180(buf[i]));
    }
    f_145279(fd, pos, 0);
    return sum;
}

//@ f_0a2800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion ohne Operation.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion verwendet keine Variablen.
 === Ende Beschreibung === */
void f_0a2800(void)
{
}
