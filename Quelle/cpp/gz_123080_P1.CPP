// P1 4/4 gleich
// gz_123080.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x123080-0x123330
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
int f_120620(int p1);
int f_164cf0();
int f_15e469(char *p, const char *m);
int f_15e65b(int buf, int size, int cnt, int file);
int f_15e55f(int file, int off, int whence, int file2);
int f_15e55f(int file, int off, int whence);
int f_15e836(int file);
extern const char d_1b84c8[];
extern const char d_1b84d2[];
extern const char d_1b84d7[];
extern const char d_1b84dc[];
extern const char d_1b84e2[];
extern const char d_1b84eb[];
extern short d_1a9696;
//@ f_123080
int f_123080(void)
{
  return 0;
}
//@ f_1230a0
int f_1230a0(char *p1)
{
  int r;
  int hdr, cnt, file;
  char *s;
  *(int *)(p1 + 0x52) = f_164cf0();
  if (*(int *)(p1 + 0x52) != 0) {
    s = (char *)f_120620(*(short *)(p1 + 0x24));
    strcpy(p1, d_1b84c8);
    strcat(p1, s);
    switch (*(int *)(p1 + 0x20)) {
    case 0: strcat(p1, d_1b84d2); break;
    case 1: strcat(p1, d_1b84d7); break;
    case 2: strcat(p1, d_1b84dc); break;
    case 3: strcat(p1, d_1b84e2); break;
    }
    hdr = 0;
    cnt = 0;
    r = 1;
    file = f_15e469(p1, d_1b84eb);
    if (file != 0) {
      f_15e65b((int)&hdr, 4, 1, file);
      if (hdr == 0x78743031) {
      f_15e65b((int)&cnt, 4, 1, file);
      f_15e55f(file, *(short *)(p1 + 0x2c) * cnt + 8, 0);
      f_15e65b(*(int *)(p1 + 0x4e), 0x400, 1, file);
      f_15e65b(*(int *)(p1 + 0x52), 0x4000, 1, file);
      f_15e65b((int)p1 + 0x3a, 2, 1, file);
      f_15e65b((int)p1 + 0x3c, 2, 3, file);
      f_15e65b((int)p1 + 0x5e, 2, 1, file);
      } else {
        r = 0;
        (*(void (**)(char *, int))(*(int *)(p1 + 0x62) + 0x1c))(p1, 0);
      }
      f_15e836(file);
    } else {
      r = 0;
      (*(void (**)(char *, int))(*(int *)(p1 + 0x62) + 0x1c))(p1, 0);
    }
  }
  else r = 0;
  return r;
}
//@ f_1232e0
void f_1232e0(int p1)
{
  if ((*(int (**)(int, int))(*(int *)(p1 + 0x62) + 4))(p1, d_1a9696) == 1) {
    if ((*(int (**)(int))(*(int *)(p1 + 0x62) + 8))(p1) != 0) {
      (*(void (**)(int))(*(int *)(p1 + 0x62) + 0x10))(p1);
      (*(void (**)(int))(*(int *)(p1 + 0x62) + 0x14))(p1);
    }
  }
}
//@ f_123320
int f_123320(int p1)
{
  return *(int *)(p1 + 0x5a);
}
