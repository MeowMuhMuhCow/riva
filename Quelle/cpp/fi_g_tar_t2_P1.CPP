/* === Beschreibung (Katalog) ===
 * Einheit fi_g_tar_t2 (074a90 - 0757f0)
 *
 * Überblick
 * Der zweite Teil von fi_g_tar enthält die zentrale Wegfindungs- und Zielsuchmaschine (f_074b40 samt
 * Treffer-Hilfsfunktion f_074a90) für die Kampf-KI und die automatische Bewegung auf dem 24 x 24-Kampfraster.
 === Ende Beschreibung === */
// P3 0/2 gleich (suche.py 25.10.2026, Basis fi_g_tar_t2_P1.CPP)
// fi_g_tar_t2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x074A90-0x0757F0
#include "R_FIX.H"
#include <string.h>
#include "RIVAMEM.H"



void *f_014540(int p1, const char *p2, int p3);
void *f_145300(void *p, int c, unsigned n);               // memset
int f_069460();
unsigned char f_0729c0(int p1);
int f_072910(int p1);
unsigned char f_0d54c0(int p1);
signed char f_043410(int p1);
signed char f_0cfbd0(int p1);
int f_072a00(void *p1);
int f_072b70(void *p1);
struct V4 { short v[4][2]; };
struct S115 { char b[0x73]; };
extern const char d_1a1cc0[];
extern V4 d_1a1cf0;
extern short d_1bd928;
extern char *d_1bd984;
extern signed char d_1bd950[];
extern short d_1bda6c;
extern short d_1bda6e;
extern S115 *d_1c2ed4;
struct X {
    char pad[0x3d3];
    char *grid;
    void f_0730d0(int s5);
    void f_072cf0(int s5, int s6, int base);
    void f_072ec0(int s5, int s6, int base);
    void f_074680(char *buf, short x, short y, short n, signed char r, short s5, signed char flag, short base);
    int f_074a90(short *n, short *a0, short *a1, short *a2, char *d, short nx, short ny, unsigned char c);
    unsigned char f_074b40(int p2, short p3, short p4, short s5, short s6);
};

//@ f_074a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt ein während der Breitensuche (f_074b40) gefundenes potenzielles Zielfeld (nx, ny) samt
 *   seiner normierten Zielkennung c (Helden-ID, Monster-ID, Fluchtfeld 0xfe oder Ankerpunkt 0xcb) in die
 *   Kandidatenlisten a0, a1, a2 und d (maximal 10 Kandidaten gleicher Schrittdistanz) ein.
 * - Eingaben und Rückgabe: Empfängt den impliziten Kampfzeiger this, den Zählerzeiger n, die Koordinaten- und
 *   Status-Arrays a0, a1, a2, das Kennungsarray d, die Koordinaten nx, ny sowie den Rasterwert c und gibt 1
 *   zurück, sobald 10 Kandidaten erreicht sind (++*n == 10), sonst 0.
 * - Wichtige Variablen: Rechnet Fernkampf-Zielmarker 0xce..0xd7 (Helden-Schussfelder) und 0xd8..0xeb
 *   (Monster-Schussfelder) wieder auf die eigentlichen Figuren-IDs zurück.
 === Ende Beschreibung === */
int X::f_074a90(short *n, short *a0, short *a1, short *a2, char *d, short nx, short ny, unsigned char c)
{
    if (*(char *)&d_1bd928) f_069460();
    a0[*n] = 1;
    a1[*n] = nx;
    a2[*n] = ny;
    if (c == (unsigned char)0xfe || c == (unsigned char)0xcb) d[*n] = c;
    else if (c >= (unsigned char)0xce && c < (unsigned char)0xd8) d[*n] = c - 0xcd;
    else if (c >= (unsigned char)0xd8 && c < 0xec) d[*n] = c - 0xce;
    else if (c < 10) d[*n] = c;
    else if (c < 0x32) d[*n] = c;
    return ++*n == 10;
}

// KRUECKE: redundante Objekttests entsprechen den doppelten Originalspruengen.
#define BACK921(PY,PX) (*(unsigned char *)(grid + (PY)*25 + (PX)))
#define CHK(PY,PX) \
    if (!(obj == 0 || (obj != 0 && (!flag || (flag && \
        (!BACK921(PY,PX) || BACK921(PY,PX)==base+10 || BACK921(PY,PX)==base+30) && \
        (PY)<(short)24 && (PY)>=0 && (PX)<24 && (PX)>=0))))) continue;
#define ENT(k) (&d_1c2ed4[k])
#define ADD(G) f_074a90(&cnt, a0, a1, a2, D, nx, ny, G)

//@ f_074b40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine Breitensuche (Flood-Fill bis maximal 49 Schritte) auf einem 24 x 25-Distanzpuffer
 *   buf ausgehend von (p3, p4) durch, um je nach Suchmodus s5 das nächstgelegene Ziel (Nahkampfgegner,
 *   Fernkampfschussfeld, Fluchtrand 0xfe oder bestimmtes Zielfeld) zu finden. Unter bis zu 10 gleich weit
 *   entfernten Zielkandidaten wird über f_074680 derjenige mit den wenigsten Richtungswechseln ausgewählt und
 *   dessen Pfad in d_1bd950 abgelegt. *(Hinweis: Enthält in den Makros FREI/FREIQ/FREIA/FREIG für zweifeldrige
 *   Figuren denselben Reihenfolgefehler wie f_074680, bei dem grid[py][px] vor der Bereichsprüfung 0 <= py, px <
 *   24 gelesen wird; siehe Fehlerliste.)*
 * - Eingaben und Rückgabe: Empfängt den impliziten Kampfzeiger this, den Zeiger p2 auf die suchende Figur
 *   (Monster oder Held), die Startkoordinaten p3 (X) und p4 (Y), den Suchmodus s5 (0..14) sowie die
 *   Mindestdistanz s6 und gibt die gefundene Zielkennung (unsigned char, oder 0 bei Misserfolg) zurück.
 * - Wichtige Variablen: Schreibt die Zielkoordinaten des besten Treffers in die globalen Variablen d_1bda6c (X)
 *   und d_1bda6e (Y) und legt den zugehörigen Bewegungspfad in d_1bd950 ab.
 === Ende Beschreibung === */
#define FELD(b,yy,xx) (((unsigned char (*)[25])(b))[yy][xx])
#if FIX_R039   /* R039: Feldgrenzen py/px (0..23) vor dem Zugriff auf grid[py][px] pruefen */
#define FREI (!obj || (obj && (!flag || (flag && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0 && \
    (!FELD(grid, py, px) || FELD(grid, py, px) == gateconv_A6S(base) + 10 || FELD(grid, py, px) == base + 30)))))
static inline unsigned char *tail(char *b, short y) { int off=y*25; return (unsigned char *)(b+off); }
#define FREIQ (!obj || (obj && (!flag || (flag && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0 && \
    (!tail(grid,py)[px] || tail(grid,py)[px] == base + 10 || tail(grid,py)[px] == base + 30)))))
static inline unsigned char *row_K32(char *b,short y) { int off=y*25; unsigned char *row=(unsigned char *)b+off; return row; }
#define FREIA (!obj || (obj && (!flag || (flag && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0 && \
    (!row_K32(grid,py)[px] || row_K32(grid,py)[px] == base + 10 || row_K32(grid,py)[px] == base + 30)))))
// KRUECKE (S57): int-Identitaet um px in fe- und g50-Zellzugriff (FREIG) -> add-Paare richtig
static inline int idi(int v) { return v; }
#define FREIG (!obj || (obj && (!flag || (flag && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0 && \
    (!FELD(grid, py, idi(px)) || FELD(grid, py, idi(px)) == base + 10 || FELD(grid, py, idi(px)) == base + 30)))))
#else
#define FREI (!obj || (obj && (!flag || (flag && \
    (!FELD(grid, py, px) || FELD(grid, py, px) == gateconv_A6S(base) + 10 || FELD(grid, py, px) == base + 30) && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0))))
static inline unsigned char *tail(char *b, short y) { int off=y*25; return (unsigned char *)(b+off); }
#define FREIQ (!obj || (obj && (!flag || (flag && \
    (!tail(grid,py)[px] || tail(grid,py)[px] == base + 10 || tail(grid,py)[px] == base + 30) && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0))))
static inline unsigned char *row_K32(char *b,short y) { int off=y*25; unsigned char *row=(unsigned char *)b+off; return row; }
#define FREIA (!obj || (obj && (!flag || (flag && \
    (!row_K32(grid,py)[px] || row_K32(grid,py)[px] == base + 10 || row_K32(grid,py)[px] == base + 30) && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0))))
// KRUECKE (S57): int-Identitaet um px in fe- und g50-Zellzugriff (FREIG) -> add-Paare richtig
static inline int idi(int v) { return v; }
#define FREIG (!obj || (obj && (!flag || (flag && \
    (!FELD(grid, py, idi(px)) || FELD(grid, py, idi(px)) == base + 10 || FELD(grid, py, idi(px)) == base + 30) && \
    py < (short)24 && py >= 0 && px < 24 && px >= 0))))
#endif
#define NEU(G) f_074a90(&cnt, ok, xs, ys, erg, nx, ny, G)

// A6S: Schmale Parametergrenze an der ersten g<10-Basiskonversion.
// Zusammen mit Modus-Kopie und Deklarationsfolge nativ GLEICH.
static inline int gateconv_A6S(short x) { return x; }
unsigned char X::f_074b40(int p2, short p3, short p4, short s5, short s6)
{
    short step;
    short n;
    short i;
    short best;
    short xs[10];
    short ys[10];
    short ok[10];
    char erg[10];
    short d;
    unsigned short changed;
    short cnt;
    short base;
    unsigned int found;
    unsigned char g;
    short ny;
    short nx;
    unsigned char *buf;
    V4 dirs;
    signed char flag;
    short bestidx;
    short py;
    unsigned char v;
    short j;
    short px;
    short y;
    int obj;
    short x;

    found = 0;
    step = 0;
    dirs = d_1a1cf0;
    obj = 0;
    flag = 0;
    if (*(char *)&d_1bd928) f_069460();
    if ((s5 >= 0 && s5 <= 3) || (s5 >= 9 && s5 <= 11)) {
        obj = p2;
        base = f_0729c0(p2);
        if (f_072910(p2)) flag = 1;
    } else {
        base = f_0d54c0(p2);
    }
    buf = (unsigned char *)f_014540(600, d_1a1cc0, 334);
    grid = (char *)f_014540(600, d_1a1cc0, 335);
    changed = 1;
    f_145300(buf, 0xff, 600);
    FELD(buf, p4, p3) = 0;
    memcpy(grid, d_1bd984, 600);
    for (i = 0; i < 10; i++) {
        xs[i] = ys[i] = ok[i] = 0;
    }
    f_0730d0(s5);
    if (s5 == 11 || s5 == 9 || s5 == 14 || s5 == 12) f_072cf0(s5, s6, base);
    if (s5 == 10 || s5 == 9 || s5 == 13 || s5 == 12) f_072ec0(s5, s6, base);
    while (!found && changed && step < 49) {
        step++;
        changed = cnt = 0;
        for (y = 0; y < (short)24; y++) {
            if (cnt == 10) break;
            for (x = 0; x < 24; x++) {
                if (*(char *)&d_1bd928) f_069460();
                if (cnt == 10) break;
                if (FELD(buf, y, x) == (unsigned char)(step - 1)) {
                    for (d = 0; d < 4; d++) {
                        ny = y + dirs.v[d][1];
                        nx = x + dirs.v[d][0];
                        py = y - dirs.v[d][1];
                        px = x - dirs.v[d][0];
                        if (ny < (short)24 && ny >= 0 && nx < 24 && nx >= 0) {
                            v = FELD(buf, ny, nx);
                            g = FELD(grid, ny, nx);
                            if (v == (unsigned char)0xff) {
                                if (g == 0) {
                                    if (FREIA) {
                                        FELD(buf, ny, nx) = step;
                                        changed = 1;
                                    }
                                } else if (g == (unsigned char)0xfe) {
                                    if (s5 == 3 || s5 == 7) {
                                        if (FREIG) {
                                            if (NEU(g)) break;
                                        }
                                    } else {
                                        FELD(buf, ny, nx) = 0xcc;
                                    }
                                } else if (g == (unsigned char)0xcb) {
                                    if (NEU(g)) break;
                                } else if (g >= (unsigned char)0xce && g < (unsigned char)0xd8) {
                                    if (NEU(g)) break;
                                } else if (g >= (unsigned char)0xd8 && g < 0xec) {
                                    if (NEU(g)) break;
                                } else if (g >= 50) {
                                    FELD(buf, ny, nx) = 0xcc;
                                } else if (g < 10) {
                                    if (s5 == 0 || s5 == 6 || s5 == 2 || s5 == 4) {
                                        if (FREI) {
                                            if (NEU(g)) break;
                                        }
                                    }
                                } else if (g < 50) {
                                    if ((s5 == 0 && g < 30) || s5 == 5 || (s5 == 1 && g < 30) || s5 == 4) {
                                        if (FREIG) {
                                            int z = s5; /* KRUECKE: Nutzwert der konkreten Konversion */ { int u = z; z = u; }
                                            if (z == 1 || z == 5) {
                                                if ((g >= 10 && g < 30 && f_072a00(&d_1c2ed4[g - 10])) ||
                                                    (g >= 30 && g < 50 && f_072a00(&d_1c2ed4[g - 30]))) {
                                                    if (NEU(g)) break;
                                                }
                                            } else {
                                                if ((g >= 10 && g < 30 && f_072b70(&d_1c2ed4[g - 10])) ||
                                                    (g >= 30 && g < 50 && f_072b70(&d_1c2ed4[g - 30]))) {
                                                    if (NEU(g)) break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (s5 == 3 || s5 == 7) {
                                if (FREIQ) {
                                    if (NEU(0xfe)) break;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (cnt) {
            found = 1;
            bestidx = 0;
            best = 99;
            if (*(char *)&d_1bd928) f_069460();
            for (i = 0; i < cnt; i++) {
                if (obj != 0)
                    f_074680((char *)buf, xs[i], ys[i], step, f_0cfbd0(p2), s5, flag, base);
                else {
                    int ix = i;
                    f_074680((char *)buf, xs[ix], ys[ix], step, f_043410(p2), s5, flag, base);
                }
                n = 0;
                if (d_1bd950[0] == -1) {
                    n = 99;
                } else {
                    signed char *weg = d_1bd950;
                    j = 1;
                    while (weg[j] != -1) {
                        if (weg[j - 1] != weg[j]) n++;
                        j++;
                    }
                }
                if (!n) {
                    bestidx = i;
                    break;
                }
                if (n < best) {
                    best = n;
                    // KRUECKE (S56): codelose Kopien heben den Nutzwert von best -> Gleichstand t498 vor t489, ix nach EBX
                    { short u = best; best = u; } { short u = best; best = u; } { short u = best; best = u; }
                    { short u = best; best = u; } { short u = best; best = u; }
                    bestidx = i;
                }
            }
            if (obj != 0)
                f_074680((char *)buf, xs[bestidx], ys[bestidx], step, f_0cfbd0(p2), s5, flag, base);
            else
                f_074680((char *)buf, xs[bestidx], ys[bestidx], step, ((unsigned char (*)(int))f_043410)(p2), s5, flag, base);
        }
    }
    delete buf;
    delete grid;
    if (found) {
        d_1bda6c = xs[bestidx];
        d_1bda6e = ys[bestidx];
        return erg[bestidx];
    }
    return 0;
}
