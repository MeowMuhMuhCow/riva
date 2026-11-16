// P3 3/4 gleich (suche.py 24.10.2026, Basis gz_0d451f_P1.CPP)
// I9: aus gz_0d451f_REST.CPP uebernommen (Stufe-2-Stand), Marken 3 neu
// gz_0d451f.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xD4730-0xD4894. Warteschleifen (Taste/Mausklick), Zeichen setzen, Zähler löschen.
struct Lock { Lock(); ~Lock(); int x; };
extern int d_1c0c4c; extern short d_1bfa74; extern unsigned short d_1bd766, d_1bd762; extern int d_1bf4e8;
extern short d_1c016c; extern int d_1c0170;
void f_068f40(); void f_099ea0(); int f_0d37b0(); int f_0d3780();
void f_15f307(void);
//@ f_0d4720
void f_0d4720(void)
{
  f_15f307();
}

//@ f_0d4730
int f_0d4730(int n)
{
  Lock l;
  int r = 1;
  short brk = 0;
  short i = 0;
  d_1c0c4c++;
  for (; i < (short)n; i++, f_099ea0()) {
      d_1bfa74 = 1;
      f_068f40();
      d_1bfa74 = 0;
      if (d_1bd766 || f_0d37b0() || f_0d3780()) brk = 1;
      if (brk == 1) {
        if (d_1bd762 == 0x11b || f_0d37b0()) r = 0;
        (*(volatile int *)&d_1bf4e8 = 0, d_1bd766 = 0x1c0d);
        break;
      }
  }
  d_1c0c4c--;
  return r;
}
//@ f_0d4800
void f_0d4800(short n)
{
  Lock l;
  short i = 0;
  if (n > (short)0) {
    do {
      d_1bfa74 = 1;
      f_068f40();
      i++;
      d_1bfa74 = 0;
      f_099ea0();
    } while (i < n);
  }
}
//@ f_0d4850
char *f_0d4850(char *s, short n, char c)
{
  short i;
  for (i = 0; i < n; i++)
    if (!s[i]) { s[i] = c; s[i + 1] = 0; }
  return s;
}
void f_0d4880() { d_1c016c = 0; d_1c0170 = 0; }
