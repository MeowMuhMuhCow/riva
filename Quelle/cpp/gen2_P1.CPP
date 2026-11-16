/* === Beschreibung (Katalog) ===
 * Einheit gen2 (094f08 - 095600)
 *
 * Überblick
 * Die Einheit gen2 (Character Generation 2) enthält die zentrale Initialisierungsfunktion f_094f40, die nach der
 * Wahl des Heldentypus (area) sämtliche Starttalente, Startzauber, Magierakademie-Boni, Lebens- und
 * Astralenergie, Körpergröße, Gewicht, Startvermögen, Gottheit und Göttergeschenke eines neu erschaffenen Helden
 * nach DSA-3-Regeln berechnet.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
// P3 0/1 gleich (suche.py 29.10.2026, Basis gen2_P1.CPP)
// gen2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x094F40-0x095600
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_03af20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_03af30(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0


                           // reg eax edx stapel 0


                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0

                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
int f_043360(int p1, int p2);                           // reg eax edx stapel 0
int f_043b60(int p1, int p2);                           // reg eax edx stapel 0
int f_043b70(int p1, int p2);                           // reg eax edx stapel 0
int f_043b80(int p1, int p2);                           // reg eax edx stapel 0
int f_043b90(int p1, int p2);                           // reg eax edx stapel 0
int f_043ba0(int p1, int p2);                           // reg eax edx stapel 0
int f_043bb0(int p1, int p2);                           // reg eax edx stapel 0
int f_043bc0(int p1, int p2);                           // reg eax edx stapel 0
int f_044a00(int p1, int p2);                           // reg eax edx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_094ac0(int p1);                                   // reg eax stapel 0
int f_094c70(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int,int,int,int,int,int);
char f_0bf820(...);
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
short f_145760(int p1, int p2);
short f_1457e0(int p1);
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short d_1a29a4[];                  // 0x1A29A4
extern short d_1a29be[];                  // 0x1A29BE
extern unsigned char d_1a29d8[];                    // 0x1A29D8
extern unsigned char d_1a29d9[];                    // 0x1A29D9
extern unsigned char d_1a29f4[];                    // 0x1A29F4
extern int d_1a3330[];                    // 0x1A3330
extern int d_1a3380;                    // 0x1A3380
extern int d_1a3384;                    // 0x1A3384
extern int d_1a3388;                    // 0x1A3388
extern int d_1a338c;                    // 0x1A338C
extern short d_1a3390;                    // 0x1A3390
extern short d_1a3398;                    // 0x1A3398
extern int d_1bc88c;                    // 0x1BC88C
extern short d_1bc89c;                    // 0x1BC89C
extern int d_1bc8a0;                    // 0x1BC8A0
struct MagicValue { signed char value, pad; };
struct MagicRecord { signed char count; short words[8]; MagicValue values[8]; };
extern MagicRecord *d_1bc8a4;
extern unsigned short d_1bfaec;                    // 0x1BFAEC
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1c349c[];                    // 0x1C349C
extern const char d_1c3870[];                    // 0x1C3870
extern const char d_1c3498[];
extern int d_1a3394;
struct LS { unsigned char b39; int l38; int l34; int l30; int l2c; short s28; short pad; int l24; short s20; };
#define CH ((int)&d_1c2c64)
#define Q (*(int *)(p1 + 0xdf))
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_094f40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Belegt einen neuen Helden (Q = *(int *)(p1 + 0xdf)) nach seiner Typwahl (area) vollständig mit
 *   seinen Startwerten: Sie kopiert die 52 Talent-Startwerte und bei Magiebegabten die 86 Zauber-Startwerte aus
 *   den Klassentabellen, lässt Magier (area == 9) ihre Akademie wählen und im Expertenmodus (d_1bfaec == 1)
 *   Zauber- gegen Talentversuche bzw. 10 Zauberversuche gegen +1W6+2 permanente Astralpunkte tauschen, würfelt
 *   Körpergröße, Gewicht, Startgeld (d_1a3330) und Zwölfgötter-Schutzgottheit (1..12) samt Bonus (MU +1, CH +1
 *   oder Talentboni) aus und ruft abschließend f_094ac0 sowie im Einsteigermodus f_094c70 auf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Generierungsstruktur und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Das Flag d_1bfaec unterscheidet zwischen Einsteigermodus (0, automatische Steigerung
 *   über f_094c70) und Expertenmodus (1, manuelle Verteilung und Umwandlungsfragen), während p1 + 8 und p1 + 0xc
 *   sich merken, ob Praios (MU +1) oder Rahja (CH +1) bereits eine Eigenschaft erhöht hat.
 === Ende Beschreibung === */
void f_094f40(int p1)
{
  short t169_9;
  struct C12 { int x[3]; };
  struct C6 { int x; short y; };
  struct Rec { signed char count; short words[8]; signed char values[16]; };
  struct Entry { short stop, low, high; };
  C12 first = *(C12 *)&d_1a3380;
  C6 third;
  C6 second;
  second = *(C6 *)&d_1a338c;
  third = *(C6 *)&d_1a3394;
  short area;
  short index;
  short value;
  unsigned char amount;
  Entry *entry;
  short table_index;
  unsigned char choice;
  char *out;
  int high;
  RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);

  d_1bc88c = 1;
  area = (signed char)((char)(f_042350((struct hero *)(Q))));
  for (index = 0; index < 0x34; index++) {
    int row = *(int *)(p1 + 0x2c);
    f_03af30(Q, index, *(signed char *)(area * 0x34 + row + index));
    int base = *(int *)&d_1bc89c;
    out = (char *)(2 * index + base);
    out[1] = 0;
    *out = out[1];
  }
  f_043350((struct hero *)(Q), ((unsigned char *)&first)[area - 1]);
  if (f_042a10((struct hero *)(Q))) {
    for (index = 0; index < 0x56; index++) {
      int row = *(int *)(p1 + 0x30);
      f_043100((struct hero *)(Q), index, *(signed char *)((area - 7) * 0x56 + row + index));
      int base = d_1bc8a0;
      out = (char *)(index * 2 + base);
      out[1] = 0;
      *out = out[1];
    }
    if (area == 9) {
      f_0432e0((struct hero *)(Q), 1);
      do {
        f_043330((struct hero *)(Q), (signed char)(f_0bf820(CH, 0xe140012, 9,
          0x200000ee, 0x200000ef, 0x200000f0, 0x200000f2,
          0x200000f3, 0x200000f4, 0x200000f6, 0x200000f8,
          0x200000f9) - 1));
      } while ((signed char)f_043320((struct hero *)(Q)) == -2);
      for(index=0; index<d_1bc8a4[(signed char)f_043320((struct hero *)(Q))].count; index++) {
        f_043110((struct hero *)(Q), d_1bc8a4[(signed char)f_043320((struct hero *)(Q))].words[index],
          d_1bc8a4[(signed char)f_043320((struct hero *)(Q))].values[index].value);
      }
    }
    f_043300((struct hero *)(Q), ((unsigned char *)&second)[area - 7]);
    value = ((signed char *)&third)[area - 7];
    if (value != (short)0 && EQ((signed char)d_1bfaec, 1) &&
        f_0bf6f0(CH, 0xe14003d) == 1) {
      *(short *)(obj.slots[4] + 2) = value;
      index = f_0bf7b0(CH, 1, 0xe14003e, 0, 5, 0);
      if (index > 0) {
        if (index > value) index = value;
        f_043310((struct hero *)(Q), (signed char)-(signed char)index);
        f_043360(Q, (signed char)index);
      } else {
        *(short *)(obj.slots[4] + 2) = value;
        index = f_0bf7b0(CH, 1, 0xe14003f, 0, 5, 0);
        if (index <= 0) goto L258;
        do { if (index > value) index = value; } while (0);
        f_043310((struct hero *)(Q), (signed char)index);
        f_043360(Q, (signed char)-(signed char)index);
      }
    }
  }

L258:
  f_043b70(Q, d_1a29a4[area]);
  f_043b60(Q, d_1a29a4[area]);
  f_043b90(Q, d_1a29be[area]);
  f_043b80(Q, d_1a29be[area]);
  if (area == 9 && EQ((signed char)d_1bfaec, 1) &&
      f_0bf6f0(CH, 0xe14003c) == 1) {
    f_043310((struct hero *)(Q), -10);
    f_043b90(Q, (short)(f_0429b0((struct hero *)(Q)) + f_145760(3, 8)));
    f_043b80(Q, f_0429b0((struct hero *)(Q)));
  }
  f_043ba0(Q, (unsigned char)f_145760(
    d_1a29d8[area * 2], d_1a29d9[area * 2]));
  f_043bb0(Q, (short)((((unsigned char)((unsigned short)(f_0428b0((struct hero *)(Q))))) -
    d_1a29f4[area]) * 0x28));
  index = f_1457e0(0x14);
  entry = (Entry *)d_1a3330[area];
  table_index = 0;
  while (entry[table_index].stop < index) table_index++;
  { high = entry[table_index].high;
    int low = entry[table_index].low;
    short roll=f_145760(low,high); roll=(roll&0)?(short)0:roll;  // haelt das Registergewicht von roll wie im Original
    int keep945 = d_1bc88c; d_1bc88c = keep945; // haelt die Registerzuteilung in f_094f40 wie im Original
    f_042420((struct hero *)(Q),roll*10); }
  f_044a00(Q, 0);
  f_043bc0(Q, (signed char)f_1457e0(0xc));
  choice = ((unsigned char)(f_042390((struct hero *)(Q))));
  switch (choice) {
  case 1: f_0453e0(Q, 0, 1); *(int *)(p1 + 8) = 1; break;
  case 2: f_03af20(Q, 3, 1); break;
  case 3: f_03af20(Q, 0xe, 1); break;
  case 4: f_03af20(Q, 0x2c, 1); break;
  case 5: f_03af20(Q, 0x18, 1); break;
  case 6: f_03af20(Q, 0x20, 1); break;
  case 7: f_03af20(Q, 0x1a, 1); f_03af20(Q, 7, 1); break;
  case 8: f_0453e0(Q, 2, 1); *(int *)(p1 + 0xc) = 1; break;
  case 9: f_03af20(Q, 0x31, 1); f_03af20(Q, 0xd, 1); break;
  case 10: f_03af20(Q, 0x2d, 1); f_03af20(Q, 0x2e, 1); break;
  case 0xb: f_03af20(Q, 0x25, 1); break;
  case 0xc: f_03af20(Q, 0x14, 1); f_03af20(Q, 0x10, 1); f_03af20(Q, 0x2f, 1); break;
  }
  f_094ac0(p1);
  if (EQ((signed char)d_1bfaec, 0)) f_094c70(p1);
  d_1bc88c = 0;
}
