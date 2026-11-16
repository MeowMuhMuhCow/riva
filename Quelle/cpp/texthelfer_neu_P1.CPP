// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0e9240-0e9360 aus Quelle/cpp/G0E9240.CPP; erster Entwurf, Einbau separat prüfen.
// gz_0e9240.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xE9240-0xE9360. Textausgabe mit Zeilenende, Hilfsfunktionen.
extern const char d_1b8319[];                            // 0x1B8319 "\r\n" (Datenstueck D20054, fremd)
#include <string.h>
extern char d_1bfaf0;
extern short d_1c0090;
extern int d_1c0098;
struct Obj { int a[0x12]; void *x48; };
struct Glob { int a[13]; void *x34; };
extern Glob *d_1c0c48;
void f_144cb6(int fd, const char *s, unsigned n);
void f_0ce2b0(char *s);
void f_069460();
void f_0ce280(int c);
void *f_05e170(void *a);
void f_05e1c0(void *a, void *b);
int f_134010(void *a, void *b);
int f_134030(void *a, void *b);
int f_099b10(void *a, void *b);
void f_0e9450(void *a, char *b, int c);

//@ f_0e9240
void f_0e9240(char *p)
{
    char fl = d_1bfaf0;
    if ((signed char)fl == 0) {
        const char *nl = d_1b8319;
        if (p != 0) f_144cb6(d_1c0098, p, strlen(p));
        f_144cb6(d_1c0098, nl, strlen(nl));
    } else {
        if (p != 0) { f_0ce2b0(p); f_069460(); }
        f_0ce280(13);
        f_0ce280(10);
    }
    d_1c0090++;
}

//@ f_0e92d0
char f_0e92d0(char *p, char c)
{
    return *p + c;
}

//@ f_0e92e0
void *f_0e92e0(void *a, void *b, void *c)
{
    void *r = f_05e170(a);
    f_05e1c0(r, b);
    ((Obj *)r)->x48 = c;
    return r;
}

//@ f_0e9300
int f_0e9300(Obj *o, char *s, void *c)
{
    int r = 0;
    char *e = s + strlen(s);
    int t = f_134010(o->x48, c);
    if (t == 1) t = f_134030(o->x48, c);
    else t = f_099b10(d_1c0c48->x34, c);
    if (t != 0) { f_0e9450(o, e, t); r = 1; }
    return r;
}
