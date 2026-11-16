/* D23: Dateimanager 0x18 Byte, 144610 setzt die fuenf Geraetezeiger.
 * Die Slots folgen dem Original-vtable; Namen sind neutral rekonstruiert. */
#ifndef RIVAFILE_H
#define RIVAFILE_H
#include "RIVASTRM.H"
#pragma pack(push,1)
struct RivaFileDevice {
 virtual void s0(); virtual void s1(); virtual char * s2(int); virtual int s3(int); virtual void s4(int);
 virtual int s5(int, int); virtual int s6(int, void *); virtual int s7(int); virtual unsigned s8(void *, int); virtual unsigned s9(void *, int);
 virtual int s10(); virtual void s11(); virtual long s12(); virtual long s13(int); virtual int s14(int);
 virtual long s15(); virtual int s16(int, int); virtual void s17(int); virtual void s18(); virtual int s19(int);
 virtual void s20(int, void *, int); virtual void s21(int, int); virtual void s22(RivaFileDevice *);
};
struct RivaFileManager {
 RivaFileDevice *cur, *real, *alf, *virt, *temp; union { int vp; RivaFileStreamVtable *vt; };
 RivaFileManager *f_144610(RivaFileDevice *p2, RivaFileDevice *p3, RivaFileDevice *p4, RivaFileDevice *p5);
 void f_144630(RivaFileDevice *p2);
 void f_144670(RivaFileDevice *p2);
 int f_1446b0(unsigned p2);
 void f_144820(); char * f_144850(unsigned p2); int f_144870(unsigned p2); void f_144890(unsigned p2);
 int f_1448b0(unsigned p2, int p3);  int f_1448d0(unsigned p2, void *buffer); int f_1448f0(int p2);
 unsigned f_144920(void *p2, int p3); unsigned f_144960(void *p2, int p3); int f_1449a0(); void f_1449d0(); long f_144a00();
 long f_144a30(unsigned p2); int f_144a50(int p2); long f_144a80(); int f_144ab0(int p2, int p3); 
 void f_144af0(unsigned p2); void f_144b10(); int f_144b40(int p2); void f_144b70(int p2, void *p3, int p4); void f_144bb0(int p2, int p3);
};
#pragma pack(pop)
typedef char riva_file_manager_layout[(sizeof(RivaFileManager)==24)?1:-1];
extern RivaFileManager d_1c2098;
#endif
