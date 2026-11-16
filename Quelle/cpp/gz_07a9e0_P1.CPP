// P1 2/2 gleich
// gz_07a9e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07A9E0-0x07AA40
#pragma pack(1)
struct R26 { short a, b; char rest[22]; };
extern R26 *d_1bd944;
extern R26 *d_1bd948;

//@ f_07a9e0
short f_07a9e0(unsigned char c)
{
    int i = c;
    if (i >= 100) return d_1bd944[i - 100].a;
    return d_1bd948[i].a;
}

//@ f_07aa10
short f_07aa10(unsigned char c)
{
    int i = c;
    if (i >= 100) return d_1bd944[i - 100].b;
    return d_1bd948[i].b;
}
