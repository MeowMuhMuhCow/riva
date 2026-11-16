/* ============================================================================
 * r_plog.h - Optionales Live-Probenlog fuer RIVA_FIX_*.EXE
 *
 * Schreibt im Fix-Modus (FIX_BUGS >= 1) jede gewuerfelte Talent-, Zauber-,
 * Eigenschafts- und Kampfprobe als Zeile an die Datei PROBEN.CSV im aktuellen
 * Spielordner (Laufwerk C: in DOSBox = Build\Testspielstaende_Fix_*).
 *
 * Im Original-Modus (FIX_BUGS == 0) ist dieser Header komplett inaktiv,
 * sodass RIVA.EXE zu 100 % byte-identisch zum Original von 1997 bleibt.
 * ============================================================================ */

#ifndef RIVA_PLOG_H
#define RIVA_PLOG_H

#if FIX_BUGS >= 1

#ifndef PLOG_AKTIV
#define PLOG_AKTIV 1
#endif

#if PLOG_AKTIV

extern char plog_d_1c2148[];
#pragma aux plog_d_1c2148 "d_1c2148"
int plog_f_144fbf(const char *name, int mode, ...);
#pragma aux plog_f_144fbf "f_144fbf"
long plog_f_145279(int h, long pos, int whence);
#pragma aux plog_f_145279 "f_145279"
int plog_f_144cb6(int h, const void *buf, unsigned int n);
#pragma aux plog_f_144cb6 "f_144cb6"
int plog_f_145259(int h);
#pragma aux plog_f_145259 "f_145259"

static char *riva_plog_zahl(char *p, int v)
{
    char tmp[12];
    int n = 0;
    unsigned int u;
    if (v < 0) {
        *p++ = '-';
        u = (unsigned int)(-v);
    } else {
        u = (unsigned int)v;
    }
    do {
        tmp[n++] = (char)('0' + (u % 10));
        u /= 10;
    } while (u != 0);
    while (n > 0)
        *p++ = tmp[--n];
    *p++ = ';';
    return p;
}

static char *riva_plog_name(char *p, const char *held)
{
    if (held != 0) {
        int i, dots = 0;
        for (i = 0; i < 24 && held[i] != '\0'; i++) {
            if (held[i] == '.') {
                dots++;
                if (dots >= 2) break;
            } else if (held[i] != ';') {
                *p++ = held[i];
            }
        }
    }
    *p++ = ';';
    return p;
}

static void riva_plog_schreib(const char *zeile, unsigned int len)
{
    char pfad[128];
    int i, fd;
    for (i = 0; i < 100 && plog_d_1c2148[i] != '\0'; i++)
        pfad[i] = plog_d_1c2148[i];
    if (i > 0 && pfad[i - 1] != '\\')
        pfad[i++] = '\\';
    pfad[i++] = 'P'; pfad[i++] = 'R'; pfad[i++] = 'O'; pfad[i++] = 'B'; pfad[i++] = 'E'; pfad[i++] = 'N';
    pfad[i++] = '.'; pfad[i++] = 'C'; pfad[i++] = 'S'; pfad[i++] = 'V'; pfad[i] = '\0';
    fd = plog_f_144fbf(pfad, 0x0221, 0x0180);
    if (fd == -1)
        return;
    plog_f_145279(fd, 0L, 2);
    plog_f_144cb6(fd, zeile, len);
    plog_f_145259(fd);
}

static void riva_plog_3w20(char typ, const char *held, int nr, int tw, int mod,
                           int a1, int v1, int w1,
                           int a2, int v2, int w2,
                           int a3, int v3, int w3, int erg)
{
    char z[160];
    char *p = z;
    *p++ = typ;
    *p++ = ';';
    p = riva_plog_name(p, held);
    p = riva_plog_zahl(p, nr);
    p = riva_plog_zahl(p, tw);
    p = riva_plog_zahl(p, mod);
    p = riva_plog_zahl(p, a1);
    p = riva_plog_zahl(p, v1);
    p = riva_plog_zahl(p, w1);
    p = riva_plog_zahl(p, a2);
    p = riva_plog_zahl(p, v2);
    p = riva_plog_zahl(p, w2);
    p = riva_plog_zahl(p, a3);
    p = riva_plog_zahl(p, v3);
    p = riva_plog_zahl(p, w3);
    p = riva_plog_zahl(p, erg);
    p[-1] = '\r';
    *p++ = '\n';
    riva_plog_schreib(z, (unsigned int)(p - z));
}

static void riva_plog_1w20(const char *held, int attr, int wert, int mod, int w, int erg)
{
    char z[128];
    char *p = z;
    *p++ = 'A';
    *p++ = ';';
    p = riva_plog_name(p, held);
    p = riva_plog_zahl(p, attr);
    p = riva_plog_zahl(p, wert);
    p = riva_plog_zahl(p, mod);
    p = riva_plog_zahl(p, w);
    p = riva_plog_zahl(p, erg);
    p[-1] = '\r';
    *p++ = '\n';
    riva_plog_schreib(z, (unsigned int)(p - z));
}

static void riva_plog_kampf_c(char ktyp, const char *held, int ziel, int mod, int w, int erg)
{
    char z[128];
    char *p = z;
    if (ktyp == 'P') {
        *p++ = 'P'; *p++ = 'A';
    } else if (ktyp == 'F') {
        *p++ = 'F'; *p++ = 'K';
    } else {
        *p++ = 'A'; *p++ = 'T';
    }
    *p++ = ';';
    p = riva_plog_name(p, held);
    p = riva_plog_zahl(p, ziel);
    p = riva_plog_zahl(p, mod);
    p = riva_plog_zahl(p, w);
    p = riva_plog_zahl(p, erg);
    p[-1] = '\r';
    *p++ = '\n';
    riva_plog_schreib(z, (unsigned int)(p - z));
}

#ifdef __cplusplus
static inline void riva_plog_kampf(char ktyp, const char *held, int ziel, int mod, int w, int erg)
{
    riva_plog_kampf_c(ktyp, held, ziel, mod, w, erg);
}
static inline void riva_plog_kampf(const char *typ, const char *held, int ziel, int mod, int w, int erg)
{
    riva_plog_kampf_c((typ != 0 && typ[0] != '\0') ? typ[0] : 'A', held, ziel, mod, w, erg);
}
#else
#define riva_plog_kampf(typ, held, ziel, mod, w, erg) \
    riva_plog_kampf_c((char)(typ), held, ziel, mod, w, erg)
#endif

#define PLOG_3W20(typ, held, nr, tw, mod, a1, v1, w1, a2, v2, w2, a3, v3, w3, erg) \
    riva_plog_3w20(typ, held, nr, tw, mod, a1, v1, w1, a2, v2, w2, a3, v3, w3, erg)
#define PLOG_1W20(held, attr, wert, mod, w, erg) \
    riva_plog_1w20(held, attr, wert, mod, w, erg)
#define PLOG_KAMPF(typ, held, ziel, mod, w, erg) \
    riva_plog_kampf(typ, held, ziel, mod, w, erg)
#else
#define PLOG_3W20(typ, held, nr, tw, mod, a1, v1, w1, a2, v2, w2, a3, v3, w3, erg) ((void)0)
#define PLOG_1W20(held, attr, wert, mod, w, erg) ((void)0)
#define PLOG_KAMPF(typ, held, ziel, mod, w, erg) ((void)0)
#endif

#endif /* FIX_BUGS >= 1 */

#endif /* RIVA_PLOG_H */
