// OPT -4r -oneatx -zp1 -s
// Astra630: erster vollstaendiger C++-Entwurf aus Original-ASM, kein GLEICH-Nachweis.
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
extern unsigned char d_1a7dac;
extern unsigned char d_1a967c;
extern unsigned char d_1b8360;
extern unsigned char d_1c1190;
extern unsigned char d_1c20b0;
extern unsigned char d_1c2148;
extern unsigned char d_1c214b;
int C0ce0b0_0();
#pragma aux C0ce0b0_0 "f_0ce0b0" modify exact [eax];
int C0ce120_2(int,int);
#pragma aux C0ce120_2 "f_0ce120" modify exact [eax edx];
int __cdecl C0ed8f0_3(int,int,int);
#pragma aux C0ed8f0_3 "f_0ed8f0" modify exact [eax ecx];
int C144e8b_3(int,int,int);
#pragma aux C144e8b_3 "f_144e8b" modify exact [eax ebx edx];
int __cdecl C144fbf_2(int,int);
#pragma aux C144fbf_2 "f_144fbf" modify exact [eax];
int C145259_1(int);
#pragma aux C145259_1 "f_145259";
int C15f2b5_1(int);
#pragma aux C15f2b5_1 "f_15f2b5" modify exact [eax];
//@ f_11bde0
int f_11bde0(int self)
{
 char path[80];int fd,read;
 strcpy((char *)NA(d_1c2148),(char *)NA(d_1b8360));
 ND8(d_1c2148)=(signed char)(C0ce0b0_0()+0x40);C0ce120_2(0,NA(d_1c214b));
 strcpy(path,(char *)NA(d_1c2148));
 if(path[strlen(path)-1]=='\\')path[strlen(path)-1]=0;
 strcat(path,(char *)ND32(d_1a967c));C15f2b5_1((int)path);
 fd=C144fbf_2(NA(d_1a7dac),0);
 if(fd!=-1) {
  read=C144e8b_3(fd,NA(d_1c20b0),0x78);
  if(read==0x78)C145259_1(fd);else C0ed8f0_3(NA(d_1c1190),0x29a0010,NA(d_1a7dac));
 }else C0ed8f0_3(NA(d_1c1190),0x29a000f,NA(d_1a7dac));
 return self;
}
