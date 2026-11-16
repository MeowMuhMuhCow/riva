// P1 2/2 gleich
// gz_0abf10.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0ABF10-0x0ABF50
#include <string.h>
void *mark(const char *file, int line);
int f_0b0460(int p1, int p2, int p3);
extern const char d_1b7d5c[];
//@ f_0abf10
void f_0abf10(int p1, int p2, int p3, int p4, int p5, int p6, int p7)
{
  f_0b0460(p2, p4, 1);
  if (p3) f_0b0460(p3, p4, 2);
}
//@ f_0abf40
const char *f_0abf40(void)
{
  return d_1b7d5c;
}
