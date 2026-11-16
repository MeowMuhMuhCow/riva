// OPT -5r -oneatx -zp1 -s
// P3 2/11 gleich (suche.py 28.10.2026, Basis fz_14dc28_t5_P1.CPP)
// CC wcc386
// fz_14dc28_t5 (Schatten ueber Riva) - Pass 1, Code 0x1524D0-0x153AC8
#include <string.h>
#include <stdlib.h>
#pragma aux f_16cf6a parm [eax edx ebx] modify exact [eax edx];
#pragma aux f_16cff5 parm [eax edx ebx] modify exact [eax edx];
int f_149470();                       // nicht in clobber.tsv
int f_149524(int p1);                                   // reg eax stapel 0
int f_149a88();                                         // reg - stapel 0
int f_149b9c(int p1, int p2);                           // reg eax edx stapel 0
int f_160320(int p1);                                   // reg eax stapel 0
int f_161328();                                         // reg - stapel 0
int f_161e84(int p1);                                   // reg eax stapel 0
int f_1629a8();                                         // reg - stapel 0
int f_162db8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_163050(int p1);                                   // reg eax stapel 0
int f_1630ac();                                         // reg - stapel 0
int f_163428(int p1, int p2);                           // reg eax edx stapel 0
int f_163484(int p1, int p2, int p3, int p4);           // reg eax edx stapel 0
int f_163bf8(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16b60c(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16b930(int p1);                                   // reg eax stapel 0
int f_16cbdc(int p1, int p2);                           // reg eax edx stapel 0
int f_16cc44(int p1, int p2);                           // reg eax edx stapel 0
int f_16ccac(int p1, int p2);                           // reg eax edx stapel 0
int f_16cd74(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_16cf6a(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16cff5(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0 (SICHERT)
int f_16d295(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_16d33f(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3b7(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16d3d0();                       // nicht in clobber.tsv
int f_16d4d8(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d7e7(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16d8ad(int p1, int p2, int p3, int p4);           // reg edx ebx ecx stapel 0
int f_16e93c(int p1, int p2, int p3, int p4, int p5, int p6);// reg eax edx ebx ecx stapel 8
int __cdecl f_16ebd8(int, ...);                         // Stapelargumente, caller-clean
int f_16ecb4(int p1);                                   // reg eax stapel 0
int f_16ecba(int p1);                                   // reg eax stapel 0
int f_16f693(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_16fb53(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_16fb72(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_1702b8(int p1);                                   // reg eax stapel 0
int f_171000(int p1, int p2);                           // reg eax edx stapel 0
int f_171994(int p1, int p2);                           // reg eax edx stapel 0
int f_172028(int p1, int p2);                           // reg eax edx stapel 0
int f_172148(int p1, int p2);                           // reg eax edx stapel 0
int f_172278();                                         // reg - stapel 0
int f_172628(int p1);                                   // reg eax stapel 0
int f_17464c(int p1);                                   // reg eax stapel 0
int f_1750b6();                       // nicht in clobber.tsv
int f_1750bc(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_176f10(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1782e8(int p1);                                   // reg eax stapel 0
int f_152020(int p1);
int f_152310(int p1);
int f_16fc19(void);
char f_16d2c9(int p1);
unsigned char f_165de2(void);
#pragma aux f_16fc19 modify exact [eax edx ecx];
struct REC { int w[46]; };
struct V3 { int x; int y; int z; };
extern int d_1a9a00, d_1a99fc, d_1a9a04, d_1a9a3c, d_1a9a48, d_1a99e4, d_1a9a38, d_1a9a6c, d_1a9aa0, d_1a9aa4;
extern char d_1cdc2a;
extern char *d_1cd314, *d_1cd224, *d_1cd324, *d_1cd204, *d_1cd220, *d_1cd210;
extern unsigned char *d_1cdc14;
extern struct REC *d_1cd1b0;
extern struct REC d_1c6bc0;
extern int d_1c6bd4;
extern short d_1c6bca;
extern short d_1c6bcc;
extern char d_1a9935, d_1a9936, d_1a9937;
extern int d_1a9b08, d_1a9b54;
extern short d_1a9a0c;
extern short d_1cdc26, d_1cdc28;
extern char d_1c8ff8[], d_1c7168[], d_1c7230[];
extern short d_1a9a1c[];
extern unsigned d_1cdb3c;
extern int d_1a99f4, d_1cd308, d_1cd30c, d_1cd310, d_1a99b0, d_1a9978, d_1a9ab0;
extern unsigned short d_1a9b24;
extern char *d_1cd1e0, *d_1cd1e8;
extern char d_1a9b5c[];
extern char d_1cc788[];
extern char d_1c76f8[];
extern unsigned char d_1c76f9[];
extern char d_1c7734[];
extern int d_1a9b44, d_1a9b48, d_1a99ac, d_1a9adc, d_1a9a98;
extern short d_1a9a90;
extern int d_1c6c3c, d_1c6c40, d_1c6bd0, d_1c6be8, d_1c6bec, d_1c6bf0, d_1c6bf4, d_1c6bf8, d_1c6bfc;
extern short d_1c6bc4, d_1c6c00, d_1c6c02, d_1c6c04, d_1c6c06, d_1c6c08, d_1c6c0a, d_1c6c0e, d_1c6c12, d_1c6c14, d_1c6c16, d_1c6c18, d_1c6c1a, d_1c6c1c, d_1c6c1e, d_1c6c20;
extern int d_1c6c44;
#define I(p,o) (*(int *)((char *)(p) + (o)))
#define U16(p,o) (*(unsigned short *)((char *)(p) + (o)))
#define S16(p,o) (*(short *)((char *)(p) + (o)))
#define U8(p,o) (*(unsigned char *)((char *)(p) + (o)))
int FMUL(int a, int b);
#pragma aux FMUL = "imul edx" "shrd eax,edx,16" parm [eax] [edx] modify [edx] value [eax];
int MULDIV(int a, int b, int c);
#pragma aux MULDIV = "imul edx" "idiv ebx" parm [eax] [edx] [ebx] modify exact [eax edx] value [eax];
#define ABSX(x) ((((x) ^ ((x) >> 31)) - ((x) >> 31)))


//@ f_1539e4
// Verdeckte Folgefunktion im bisherigen Originalbereich.
#pragma aux f_1539e4 "*";
void f_1539e4(char *p)
{
    unsigned n = 0;
    int i = 0;
    struct Pair { int x,y; } v;
    extern int d_1cdb44, d_1cdb48, d_1cdb74, d_1ad4d4, d_1cd320;
    extern const double d_1b8fa9;
    extern const char d_1b8f9c[];
    int __cdecl f_16ebd8(int, ...);
#pragma aux f_16ebd8 parm caller [] modify exact [eax];
    for (i = 0; i < U16(p,4); i++) {
        int x, y;
        volatile int *pos;
        n = U16(p,10 + i*2);
        v = ((struct Pair *)d_1cd224)[n];
        pos = (volatile int *)I(p,0x1c + i*4);
        x = d_1cdb44 + ((FMUL(0xe666,v.x) + 0x8000) >> 16);
        y = ((FMUL(0xb333,v.y) + 0x8000) >> 16) + d_1cdb48;
        f_16ebd8(d_1cd320, (short)x, (short)(y+8), d_1cdb74, d_1ad4d4, d_1b8f9c, pos[0]*d_1b8fa9, pos[1]*d_1b8fa9, n);
    }
}

