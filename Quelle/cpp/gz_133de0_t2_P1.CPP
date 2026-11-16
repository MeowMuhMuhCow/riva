// OPT -4r -oneatx -zp1 -s -ou
// P3 7/11 gleich (suche.py 25.10.2026, Basis gz_133de0_P1.CPP)
// I9: aus gz_133de0_REST.CPP uebernommen (Stufe-2-Stand), Marken 4 neu
// gz_133de0.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x133DE0-0x134050. Kleine Hilfsfunktionen (Schalter-Update, Ringpuffer-Handles).  STAND: NICHT GLEICH, DF0 ~43 Befehle offen (a/c Registertausch ebp/edi)
void operator delete(void *p);                           // 0x014710
void f_060100(int a, int b, int c);
int f_069770(void *p, int id);
void f_069860(void *p, int id, int v);
void f_060230(void *p);
void *f_060030(void *p, int fl);
void *f_145234(void *p, void *d);
void f_145254();
int f_05f580();
extern char d_1bbc08[];
extern signed char d_1c0da0, d_1c0da4, d_1c0da8, d_1c0dd0;
extern int d_1c0dd4[];

#define Z(x) (((x) == 0) & 1)
#define IS(x, k) (((x) == k) & 1)

void f_133de0(int a, short b, short c) ;

//@ f_133df0
void f_133df0(char *self)
;

//@ f_133f50
void *f_133f50(void *self, unsigned fl)
;

int f_133f90() ;
//@ f_133fa0
int f_133fa0()
;
//@ f_133fb0
int f_133fb0() { return 0; }
int f_133fc0() ;
void f_133fd0(short *p) ;

//@ f_133fe0
int f_133fe0(short *p, int v)
;

//@ f_134010
int f_134010(int a, unsigned b)
;

//@ f_134030
short f_134030(signed char a, short b, int c)
;
#pragma aux f_134030 modify exact [eax];
