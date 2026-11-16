// OPT -4r -od -zp1 -s
// Astra493: privater nativer Treiberteil, noch nicht registriert.
void *f_145300(void*,int,unsigned);
void f_149caa(void*);
int f_145702(int,void*,void*,void*);
int f_149cd2(int,void*,void*);
int f_05fc00(int,void*,void*,void*);
int f_05fee0(int);
int f_05fef0(int);
int f_149cf0(int);
#define I4(p,o) (*(int*)((p)+(o)))
#define H1(p) I4(p,0x1e)
#define U1(p) (*(unsigned char*)(p))
#define U2(p) (*(unsigned short*)(p))
#define S2(p) (*(short*)(p))
struct DriverRegs493{unsigned short ax,axh,bx,bxh,cx,cxh,dx,dxh,si,sih,di,dih,flags,flagsh;};
struct DriverBuffers493{char ext[12];DriverRegs493 regs;};
//@ f_02e080
int f_02e080(int p){
 DriverRegs493 regs;char ext[12];
 f_145300(&regs,0,28);f_145300(ext,0,12);
 regs.ax=0x150b;regs.cx=p-1;
 f_149caa(ext);f_145702(0x2f,&regs,&regs,ext);
 if(regs.bx==0xadad)return (int)regs.ax?1:0;
 return 0;
}
//@ f_02e11a
int f_02e11a(int p){
 DriverRegs493 regs;char ext[12];
 f_145300(&regs,0,28);f_145300(ext,0,12);
 regs.ax=0x1500;regs.bx=0;
 f_149caa(ext);f_145702(0x2f,&regs,&regs,ext);
 if(regs.bx==0)return 0;
 return regs.cx+1;
}
//@ f_02e199
int f_02e199(int p){
 DriverBuffers493 s;
 f_145300(&s.regs,0,28);f_145300(s.ext,0,12);
 s.regs.ax=0x1500;s.regs.bx=0;
 f_149caa(s.ext);f_145702(0x2f,&s.regs,&s.regs,s.ext);
 return s.regs.bx;
}
//@ f_02e204
int f_02e204(int p){
 DriverRegs493 regs;char ext[12];
 f_145300(&regs,0,28);f_145300(ext,0,12);
 if(f_02e199(p)>0){regs.ax=0x150c;f_149cd2(0x2f,&regs,&regs);return regs.bx;}
 return 0;
}
//@ f_02e273
void f_02e273(int p){
 DriverBuffers493 s;
 f_145300(&s.regs,0,28);f_145300(s.ext,0,12);
 S2(H1(p)+3)=0;s.regs.ax=0x1510;s.regs.cx=S2(p)-1;s.regs.bx=f_05fee0(p+0x22);
 f_149caa(s.ext);S2(s.ext)=((unsigned)f_05fee0(p+0x22))>>16;
 f_05fc00(0x2f,&s.regs,&s.regs,s.ext);
}
//@ f_02e304
void f_02e304(int p,int n){
 f_02e273(p);
 while((short)n>0&&(U1(H1(p)+4)&0x80)!=0){
  if((unsigned short)(U2(H1(p)+3)&0x800f)==(unsigned short)0x8002)f_149cf0(1000);else f_149cf0(100);
  --n;f_02e273(p);
 }
}
//@ f_02e375
void f_02e375(int p){
 f_149cf0(500);U1(H1(p)+2)=7;f_02e273(p);f_149cf0(500);
 U1(f_05fef0(p+0x2e))=2;U1(H1(p)+2)=12;
 I4(H1(p),14)=f_05fee0(p+0x2e);S2(H1(p)+18)=1;
 f_02e273(p);f_149cf0(500);I4(H1(p),14)=0;S2(H1(p)+18)=0;
}
//@ f_02e41a
void f_02e41a(int p){
 unsigned char*q=(unsigned char*)f_05fef0(p+0x2e);
 U1(H1(p)+2)=3;I4(H1(p),14)=f_05fee0(p+0x2e);*q=6;S2(H1(p)+18)=5;f_02e273(p);
 if((unsigned short)(U2(H1(p)+3)&0x800f)==(unsigned short)0x8002){I4(p,18)=0;I4(p,10)=0;I4(p,14)=0;}
 else{
  if((q[1]&1)||(q[2]&8))I4(p,18)=0;else I4(p,18)=1;
  if(I4(p,18)==0){I4(p,10)=0;I4(p,14)=0;}
  else{*q=15;S2(H1(p)+18)=11;f_02e273(p);if(q[1]&1)I4(p,14)=1;else I4(p,14)=0;
   if(U1(H1(p)+4)&2)I4(p,10)=1;else I4(p,10)=0;
  }
 }
 I4(H1(p),14)=0;S2(H1(p)+18)=0;
}
