// P1 3/3 gleich
// fz_145760_t3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x147B3F-0x147C84
// OPT -4r -od -zp1 -s
#include <string.h>
struct S { int f0; int f4; int f8; int fc; int f10; int f14; int f18; int f1c; int f20; };
int f_1664d0(const char *msg, const char *file, int line);
int f_16897e(unsigned short p1, int p2, int *p3);
int f_168cd4(int p1);
int f_147aad(S *p);
extern const char d_1a980c[];
extern const char d_1b8a82[];
extern const char d_1b8a92[];
extern const char d_1b8aa4[];
extern const char d_1b8ab0[];
//@ f_147b3f
int f_147b3f(S *p, int v)
{
    int old;
    if (v == 0) f_1664d0(d_1b8a82, d_1a980c, 0x406);
    f_147aad(p);
    old = p->f20;
    p->f20 = v;
    return old;
}
//@ f_147b97
int f_147b97(S *p, unsigned short id, int q)
{
    int r;
    if (p->f4 != 1) f_1664d0(d_1b8a92, d_1a980c, 0x419);
    p->f10 = f_16897e(id, q, &r);
    if (p->f10 != 0) r = -1;
    return r;
}
//@ f_147c02
int f_147c02(S *p, int id)
{
    int r = 0;
    if (id == -1) f_1664d0(d_1b8aa4, d_1a980c, 0x42f);
    if (p->f4 != 1) f_1664d0(d_1b8ab0, d_1a980c, 0x430);
    p->f10 = f_168cd4(id);
    if (p->f10 == 0) r = 1;
    return r;
}
