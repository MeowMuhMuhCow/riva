/* === Beschreibung (Katalog) ===
 * Einheit gz_0c9940_t3
 *
 * Diese Einheit bildet den dritten Teil der Dungeon-Logik für die dritte Ebene der Zwergenmine (0x11,
 * Text-Overlay 0x35) und implementiert eine weitere Steinschlagfalle, die Überquerung des unterirdischen
 * Wasserlaufs (f_0cc010) sowie das Buchstaben- und Passworträtsel an den Zwergentoren (f_0cc8c0, f_0cca60,
 * f_0ccb50).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 3/6 gleich (suche.py 30.10.2026, Basis gz_0c9940_t3_P1.CPP)
// gz_0c9940_t3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CBDA0-0x0CCF00
#include <string.h>
#include "RIVAMEM.H"



#pragma aux f_147323 modify [esp];
struct MO { int z0; int *p; int pad[2]; int *p4; short *q; char d[36]; };
struct Q4 { int v[4]; };
inline int EQ(int a, int b) { return a == b; }
inline int GT(int a, int b) { return a > b; }
int f_038c40(int p1);
int f_038d70(int p1, int p2);
int f_038e10(int p1, int p2);
int f_039320(int p1, int p2);
int f_039320(int p1, int p2, int p3);
int f_039b70(int p1, int p2, int p3);
int f_03d4b0(int p1, int p2, int p3);





int f_043ca0(int p1);
int f_044230(int p1, int p2);
int f_044300(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
short f_045210(int p1);
short f_0452a0(int p1);
#pragma aux f_0452a0 modify [eax ebx ecx edx];
int f_060740(int p1, int p2);
int f_0607e0(int p1, int p2);
int f_060800(int p1, int p2, int p3);
int f_0bbf00(void *p1);
int f_0bf680(void *p1);
int f_0bf6c0(void *p1, int p2);
int f_0bf730(void *p1, int p2);
short f_0bf820(void *o, int b, short c, ...);
int f_0bfea0(void *p1, short p2, int p3);
int f_0ccf00(int p1);
int f_0ccb50(int p1, int p2);
int f_0d4a60(int p1);
int f_0db9a0(int p1);
int f_0dd750(int p1, int p2);
int f_0de7d0(int p1, int p2);
int f_0de7f0(int p1);
int f_1223c0();
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_133fe0(const char *p1, char *p2);
int f_144bf0(const signed char *p1, const char *p2);
short f_145850(int p1, int p2, int p3);
short f_1457e0(int p1);
int f_146dfa(void *p1, int p2);
int f_147323(void *p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_149a14(int p1, int p2);
extern int d_1a9820;
extern char d_1bf230[];
extern signed char d_1bf304;
extern signed char d_1bf308;
extern signed char d_1bf30c;
extern signed char d_1bf340;
extern short d_1bf358;
extern unsigned short d_1bf35c;
extern struct Q4 d_1bf364;
extern signed char *d_1bf360;
extern int d_1c0004;
extern unsigned short d_1c040c;
extern int d_1c0412;
extern unsigned char d_1c0416;
extern short d_1c0428;
extern char d_1c21b4[];
extern short d_1c21b5;
extern char d_1c2c64[];
extern char d_1c2edc[];
extern const char d_1c299c[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_0cbda0  groesse 624 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wickelt beim ersten Betreten (d_1bf304 == 0) eine Steinschlagfalle (0x35003a) ab, die
 *   einen einzelnen Helden sofort erschlägt (0x35000144), während bei einer Gruppe eine um 14 erschwerte
 *   Sinnesschärfe-Probe (0x33) und eine um 8 erschwerte Probe auf Talent 9 (Akrobatik/Körperbeherrschung)
 *   entscheiden, ob der Anführer ausweicht oder 1W6 + 4 - Rüstungsschutz Wundschaden erleidet, bevor das Objekt
 *   0x1f42 umgeschaltet wird.
 * - Eingaben: Übergeben werden zwei ungenutzte Parameter unused1 und unused2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
static inline int h_cbda0_probe(int p, signed char k)
{
  int r = 0;
  if (f_044c90(p, 0x33, k) > 1) r = 1;
  return r;
}
static inline void h_cbda0_damage(int p)
{
  if (f_0d4a60(p)) {
    short s = f_145850(1, 6, 4);
    s -= f_045210(p);
    if (s < 1) s = 1;
    f_044850(p, s, 1);
  }
}
void f_0cbda0(int unused1, int unused2)
{
  int f_147323_x(void *, int, int, int, int, int, int);
#pragma aux f_147323_x "f_147323" modify [esp]
  short f_044c90_c(int, int, signed char);
#pragma aux f_044c90_c "f_044c90" parm [eax] [edx] [ebx] modify exact [eax edx ebx]
  MO obj;
  int p1, p2;
  if (EQB(d_1bf304, 0)) {
    p1 = f_038c40(d_1c0004);
    p2 = p1;
    f_125400(&obj, d_1c349c, d_1c3870, d_1c3498);
    obj.p[1] = p1;
    short level = f_0db9a0(d_1c0004);
    if (level == 1) {
      int snd;
      f_147323_x(d_1c2edc, 0x35003a, 0x7fff, 0x8000, (snd = d_1a9820), 0, level);
      f_0bf730(d_1c2c64, 0x35000144);
      short hp = f_042960((struct hero *)(p1));
      f_044300(p1, hp);
    } else {
      int r = 0;
      short roll = f_044c90_c(p1, 0x33, (signed char)(roll = 0xe));
      if (roll > 1) r = 1;
      if (r == 1) {
        f_0bf730(d_1c2c64, 0x35000145);
        f_0bf730(d_1c2c64, 0x35000146);
        int snd = d_1a9820;
        f_147323_x(d_1c2edc, 0x35003a, 0x7fff, 0x8000, snd, 0, r);
        if (f_044c90_c(p2, 9, 8) > 0) {
          f_0bf730(d_1c2c64, 0x35000147);
        } else {
          f_0bf730(d_1c2c64, 0x35000148);
          h_cbda0_damage(p2);
        }
      } else {
        int snd = d_1a9820;
        f_147323_x(d_1c2edc, 0x35003a, 0x7fff, 0x8000, snd, 0, 1);
        f_0bf730(d_1c2c64, 0x35000149);
        h_cbda0_damage(p2);
      }
    }
    f_060740(0x1f42, 1);
    f_0607e0(0x1f42, 1);
    d_1bf304 = 1;
    f_1254a0(&obj, 0);
  }
}
//@ f_0cc010  groesse 1936 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert als Zustandsautomat (state = 0 bis 7) die Überquerung eines unterirdischen
 *   Wasser- oder Schluchthindernisses (d_1bf308) zum Zielfeld p2, wobei der Spieler zwischen demVorausschicken
 *   eines einzelnen Helden (case 1), dem Durchschwimmen mit der gesamten Gruppe (case 2) und dem Einsatz von
 *   Zaubersprüchen (case 3: Zauber 0x4f, 0x53, 0x19 oder 0x1a) wählen kann. Originalfehler: In case 2: wird
 *   found = 0 initialisiert, die anschließende Schleife über die 7 Gruppenplätze prüft jedoch die Bedingung
 *   found != 0 statt found == 0; dadurch wird die Schleife (Prüfung auf Bewusstlosigkeit, Überladung f_043ca0
 *   und Schwimmen-Probe 0xb +5) niemals betreten und die Gruppe überquert das Hindernis immer automatisch ohne
 *   jede Probe (0x35000158).
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger pa, die Zielposition p2 bei erfolgreicher
 *   Überquerung sowie ein ungenutzter dritter Parameter unused.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
static inline int h_cc010eq(const signed char &a,int b){return a==b;}
static inline int h_cc010_probe(int p, int k)
{
  int r = 0;
  short roll = f_044c90(p, 0x33, (signed char)(roll = k));
  if (roll > 1) r = 1;
  return r;
}
static inline void h_setp1(MO &o, int v)
{
  o.p[1] = v;
}
void f_0cc010(int pa, unsigned short p2,int unused)
{
  void f_1254a0_end(void *, int);
#pragma aux f_1254a0_end "f_1254a0" modify [esp];
  struct MOp { int z0; union { int *p; void **pp; }; int pad[2]; int *p4; short *q; char d[36]; };
  // Getrennte Objekt-, Menue- und Wertebloecke bewahren die Speicherabhaengigkeiten.
  struct Objects {MO o2;MOp o;} ob; struct Menu {Q4 opts; int z2c;} m; struct Values {int z28,state,own20;} v; struct Levels {int lvl,lv18;} lv;
  int title, t, found;
  short n, i;
  short sv;
  short s;
  f_125400(&ob.o, d_1c349c, d_1c3870, d_1c3498);
  lv.lvl = f_0db9a0(d_1c0004);
  v.z28 = 0;
  lv.lv18 = f_0de7f0(d_1c0004);
  // haelt die Stapelplatz-Reihenfolge wie im Original
  {int *cross=(int *)((char *)&lv+2);int q=*cross;*cross=q;}
  m.z2c = 0;
  { int hero=f_038c40(d_1c0004); ob.o.p[1]=hero; v.own20=hero; }
  v.state = 8;
  if (h_cc010eq((signed char&)d_1bf308, 0)) {
    signed char k = 4;
    found = h_cc010_probe(v.own20, k);
    if (found == 0) {
      v.z28 = v.own20;
      ob.o.p[1] = v.own20;
      v.state = 4;
      f_0bf730(d_1c2c64, 0x3500014a);
    } else {
      v.state = 0;
    }
  } else if (h_cc010eq((signed char&)d_1bf308, 1)) {
    v.state = 0;
  } else if (h_cc010eq((signed char&)d_1bf308, 2)) {
    v.state = 5;
  } else if (h_cc010eq((signed char&)d_1bf308, 3)) {
    v.state = 7;
  }
  do {
    switch (v.state) {
    case 0:
      n = 0;
      m.opts = d_1bf364;
      if (h_cc010eq((signed char&)d_1bf308, 0)) {
        title = 0x3500014b;
        m.z2c = 1;
        d_1bf308 = 1;
      } else if (m.z2c == 0) {
        m.z2c = 1;
        title = 0x3500014c;
      } else {
        title = 0x3500014d;
      }
      if ((short)lv.lvl > 1) m.opts.v[n++] = 0x3500014e;
      else m.opts.v[n++] = 0x3500014f;
      m.opts.v[n++] = 0x35000150;
      if ((short)lv.lvl != 1 || f_042a10((struct hero *)(v.own20)) != 0) m.opts.v[n++] = 0x35000151;
      m.opts.v[n++] = 0x35000152;
      do {
        sv = f_0bf820(d_1c2c64, title, n, m.opts.v[0], m.opts.v[1], m.opts.v[2], m.opts.v[3]);
      } while (sv == -1);
      switch ((unsigned short)(sv - 1)) {
      case 0: v.state = 1; break;
      case 1: v.state = 2; break;
      case 2: v.state = 3; break;
      case 3: v.state = 6; break;
      }
      break;
    case 1:
      if ((short)lv.lvl > 1) v.z28 = f_038d70(d_1c0004, 0x35000153);
      else v.z28 = v.own20;
      if (v.z28 != 0) {
        ob.o.p[1] = v.z28;
        v.state = 4;
        f_0bf730(d_1c2c64, 0x35000154);
      } else {
        v.state = 0;
      }
      break;
    case 2:
      found = 0;
      for (i = 0; i < 7 && found != 0; i++) {
        t = f_0de7d0(d_1c0004, (int)i);
        if (t == 0) continue;
        ob.o.p[1] = t;
        if (((char)(f_042470((struct hero *)(t))))) continue;
        if (((char)(f_0425f0((struct hero *)(t))))) continue;
        if (((char)(f_0424e0((struct hero *)(t))))) {
          f_0bf730(d_1c2c64, 0x35000155);
          found = t;
          continue;
        }
        if (f_043ca0(t)) {
          f_0bf730(d_1c2c64, 0x35000156);
          continue;
        }
        if (f_044c90(t, 0xb, 5) <= 0) {
          f_0bf730(d_1c2c64, 0x35000157);
          found = t;
        }
      }
      if (found != 0) {
        v.z28 = found;
        v.state = 4;
      } else {
        f_0bf730(d_1c2c64, 0x35000158);
        v.state = 5;
      }
      break;
    case 3:
      v.state = 0;
      if ((short)lv.lvl == 1 && f_042a10((struct hero *)(v.own20)) == 1) t = v.own20;
      else t = f_038e10(d_1c0004, 0x35000159);
      if (t != 0) {
        d_1c0428 = 5;
        f_03d4b0(t, 1, 0);
        if (d_1c0412 == 1) {

          f_125400(&ob.o2, d_1c349c, d_1c3870, d_1c3498);
          ob.o2.p[1] = t;
          switch (d_1c040c) {
          case 0x4f:
            f_0bf730(d_1c2c64, 0x3500015b);
            if ((signed char)d_1c0416 < 10) {
              f_0bf730(d_1c2c64, 0x3500015c);
              v.z28 = t;
              v.state = 4;
            } else {
              f_0bf730(d_1c2c64, 0x3500015d);
              d_1bf308 = 3;
              f_149a14(0x6d, 1);
              f_149a14(0x69, 1);
              v.state = 7;
            }
            break;
          case 0x53:
            f_0bf730(d_1c2c64, 0x3500015e);
            d_1bf308 = 2;
            f_060740(0x1f43, 1);
            f_0607e0(0x1f43, 1);
            f_0607e0(0x1f4c, 1);
            f_0bf730(d_1c2c64, 0x35000164);
            v.state = 5;
            break;
          case 0x19:
            if ((signed char)d_1c0416 < 4) {
              f_0bf730(d_1c2c64, 0x3500015f);
              v.z28 = t;
              d_1bf308 = 2;
              v.state = 4;
            } else {
              f_0bf730(d_1c2c64, 0x35000160);
              v.state = 5;
            }
            break;
          case 0x1a:
            // haelt die Registerzuteilung wie im Original
            ob.o2.q[1] = (i=(signed char)d_1c0416);
            f_0bf730(d_1c2c64, 0x35000161);
            if ((signed char)d_1c0416 < 5) {
              f_0bf730(d_1c2c64, 0x35000162);
              v.state = 0;
            } else {
              f_0bf730(d_1c2c64, 0x35000163);
              v.state = 5;
            }
            break;
          default:
            v.state = 0;
          }
          f_1254a0(&ob.o2, 0);
          f_0bbf00(d_1bf230);
        } else {
          f_0bbf00(d_1bf230);
        }
      } else v.state = t;
      break;
    case 4:
      if (v.z28 != 0) {
        s = f_1457e0(8);
        s += 4;
        s -= f_0452a0(v.z28);
        f_147323(d_1c2edc, 0x350039, 0x7fff, 0x8000, (t = d_1a9820), 0, 1);
        if (s < 1) s = 1;
        if ((short)lv.lvl == 1) f_044850(v.z28, (int)s, 5);
        else f_044300(v.z28, (int)s);
        ob.o.p[1] = (t = v.z28);
        if (f_0d4a60(t) != 0 && (short)lv.lv18 == 1) {
          t = 0x35000165;
          goto msg;
        }
        if (f_0d4a60(v.z28) != 0 && (short)lv.lvl == 1) {
          t = 0x35000166;
          goto msg;
        }
        if (f_0d4a60(v.z28) != 0 && (short)lv.lvl > 1) {
          t = 0x35000167;
          goto msg;
        }
        if (((char)(f_0425f0((struct hero *)(v.z28))))) {
          t = 0x35000168;
          goto msg;
        }
        if (((char)(f_042470((struct hero *)(v.z28))))) {
          ob.o.p[2] = f_038c40(d_1c0004);
          t = 0x35000169;
msg:
          f_0bf730(d_1c2c64, t);
        }
        d_1bf308 = 2;
        f_060740(0x1f43, 1);
        f_0607e0(0x1f43, 1);
        // haelt die Registerzuteilung wie im Original
        {int a=d_1a9820,b=d_1c0004; v.state=5; d_1a9820=a; d_1c0004=b;}
        f_0607e0(0x1f4c, 1);
      } else v.state = v.z28;
      break;
    case 5:
      f_0dd750(d_1c0004, (unsigned short)p2);
      v.state = 7;
      break;
    case 6:
      v.state = 7;
      break;
    case 7:
      break;
    }
  } while (v.state != 7);
  f_1254a0_end(&ob.o, 0);
}

//@ f_0cc7a0  groesse 288 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion spielt beim ersten Auslösen (d_1bf30c == 0) einen kurzen Dialog zwischen dem
 *   Gruppenanführer, dem Helden mit dem höchsten Wert in Talent 0x25 und einem Begleiter (0x3500016a bis
 *   0x3500016c) ab und startet anschließend immer die über p2 angegebene Dungeon-Sequenz (f_060800(p2, 0, 0)).
 * - Eingaben: Übergeben werden der ungenutzte Kontextzeiger p1 sowie die Sequenz-ID p2.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0cc7a0(int p1, int p2)
{
  if (EQ(d_1bf30c, 0)) {
    MO o;
    int a, b;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    if ((short)f_0db9a0(d_1c0004) > 1) {
      a = f_039320(d_1c0004, 0x25);
      b = f_039b70(d_1c0004, a, 1);
      o.p[1] = f_038c40(d_1c0004);
      f_0bf730(d_1c2c64, 0x3500016a);
      o.p[1] = a;
      o.p[2] = b;
      f_0bf6c0(d_1c2c64, 6);
      f_0bf730(d_1c2c64, 0x3500016b);
      f_0bf680(d_1c2c64);
    } else {
      o.p[1] = f_038c40(d_1c0004);
      f_0bf730(d_1c2c64, 0x3500016c);
    }
    d_1bf30c = 1;
    f_1254a0(&o, 0);
  }
  f_060800(p2, 0, 0);
}
//@ f_0cc8c0  groesse 416 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion steuert die Interaktion mit der Passwort-Vorrichtung der Zwergenmine (0x35003d),
 *   startet beim ersten Mal (d_1bf340 == 0) direkt die Passworteingabe f_0ccb50(p1, 0x35000188) und bietet bei
 *   weiteren Versuchen ein Vier-Optionen-Menü (0x35000189) an, über das man das Wort erneut eingeben (f_0ccb50),
 *   die Vorrichtung näher untersuchen (f_0ccf00) oder einen Magiebegabten unter Verlust von 5 Astralpunkten
 *   (f_044230(q, 5)) um Rat fragen kann.
 * - Eingaben: Als Parameter wird der Zeiger p1 auf die Dungeon-Verwaltungsstruktur übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das richtige Lösungswort eingegeben wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0cc8c0(int p1)
{
  int f_147323_frame(void *, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp];
  MO o;
  int r = 0;
  int q;
  unsigned short n;
  if (EQB(d_1bf340, 0)) {
    { int t_ = *(int *)&d_1a9820; f_147323_frame(d_1c2edc, 0x35003d, 0x7fff, 0x8000, t_, r, 1); }
    n = 0x14;
    while (n--) {
      f_1223c0();
      f_146dfa(d_1c2edc, (r = 1));
    }
    r = f_0ccb50(p1, 0x35000188);
    d_1bf340 = 1;
  } else {
    { int t_ = *(int *)&d_1a9820; f_147323_frame(d_1c2edc, 0x35003d, 0x7fff, 0x8000, t_, r, 1); }
    n = 0x14;
    while (n--) {
      f_1223c0();
      f_146dfa(d_1c2edc, 1);
    }
    switch ((unsigned short)(f_0bf820(d_1c2c64, 0x35000189, 4, 0x3500018a, 0x3500018b, 0x3500018c, 0x3500018d) + 1)) {
    case 0: case 1: case 5: break;
    case 2:
      r = f_0ccb50(p1, 0x3500018e);
      goto done;
    case 3:
      f_0ccf00(p1);
      goto done;
    case 4:
      f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
      q = f_038e10(d_1c0004, 0x35000192);
      if (q != 0) {
        o.p[1] = q;
        f_0bf730(d_1c2c64, 0x35000193);
        f_044230(q, 5);
      }
      f_1254a0(&o, 0);
      return r;
    }
  }
done:
  return r;
}
//@ f_0cca60  groesse 240 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Hilfsfunktion soll im Lösungswort d_1bf360 nach einem noch nicht in der Bitmaske d_1bf35c
 *   aufgedeckten Buchstaben suchen, der im Wort genau einmal vorkommt, um ihn als Hinweis auszugeben.
 *   Originalfehler: Die Funktion setzt selected = -1 und prüft in der äußeren for-Schleife die Laufbedingung
 *   selected != -1 statt selected == -1; dadurch wird der Schleifenrumpf niemals ausgeführt und die Funktion
 *   gibt immer -1 (0xff) zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Aufgrund des Schleifenfehlers gibt die Funktion stets -1 (0xff) zurück (vorgesehen war der
 *   gefundene Einzelbuchstabe).
 === Ende Beschreibung === */
char f_0cca60(void)
{
  struct AT { static signed char at(signed char *s, int i) { return s[i]; } };
  struct BitB { static int in(short i, const unsigned short &mask) {
    unsigned short b = 1 << i; b &= mask; return b != (unsigned short)0;
  } };
  signed char *p, *q;
  short length;
  short outer, inner, occurrences;
  signed char selected, current, counted;
  int found;


  length = strlen((char *)d_1bf360);
  outer = 0;
  selected = -1;
  for (; (int)outer < (int)length && selected != -1; outer++) {
    // haelt die Registerzuteilung der Schleifen wie im Original
    // Innen-Schleifen in die Originalform (Schleife 1: edx/add, Schleife 2: ecx/lea).
    current = AT::at(d_1bf360, outer);
    found = 0;
    for (inner = 0; d_1bf360[inner] != 0; inner++) {
      if (current == d_1bf360[inner] && BitB::in(inner, d_1bf35c)) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      // haelt die Registerzuteilung der Innenschleifen wie im Original
      counted = AT::at(((signed char *)((char*)(((unsigned)d_1bf360 & 0)?0:(unsigned)d_1bf360))), outer);
      occurrences = 0;
      for (inner = 0; d_1bf360[inner] != 0; inner++) {
        if (counted == d_1bf360[inner]) occurrences++;
      }
      if (!GT(occurrences, 1)) selected = AT::at(d_1bf360, outer);
    }
  }
  
  return selected;
}

//@ f_0ccb50 groesse 944 B
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion liest über f_0bfea0 die Passworteingabe des Spielers ein, vergleicht sie mit dem
 *   Lösungswort d_1bf360 und baut bei einer Fehleingabe in d_1c21b4 eine Maske aus bereits bekannten Buchstaben
 *   (d_1bf35c) und Fragezeichen '?' auf, wobei nach mehreren Fehlversuchen automatisch ein noch unbekannter
 *   Buchstabe als Hinweis (0x35000190 oder 0x35000191) in d_1bf358 und d_1bf35c freigeschaltet wird.
 *   Originalfehler: Auch in der hier eingebetteten Kopie von f_0cca60 (Suche nach einem einfach vorkommenden
 *   Buchstaben, falls hint == 0 ist) lautet die Schleifenbedingung s.selected.b != -1 nach der Initialisierung
 *   s.selected.b = -1, sodass die Suche nach Einzelbuchstaben niemals durchlaufen wird und hint = -1 (0xff)
 *   liefert.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Dungeon-Verwaltungsstruktur (mit dem Fehlversuchszähler bei
 *   Offset +0x20) sowie die Text-ID p2 der Eingabeaufforderung.
 * - Rückgabewert: Zurückgegeben wird 1 bei Übereinstimmung mit dem Lösungswort d_1bf360, andernfalls 0.
 === Ende Beschreibung === */
static inline int np_bit(short i, const unsigned short &mask) {
  unsigned short b=1<<i; b&=mask; return b!=(unsigned short)0;
}
static inline int np_gt1(short n) { return n>1; }
static inline short np_next(int p) { return ++*(short *)(p+0x20); }
static inline void np_set(signed char c,unsigned short &mask) {
  for(short i=0;d_1bf360[i]!=0;i++) {
    if(c==d_1bf360[i]) {unsigned short b=1<<i;mask|=b;}
  }
}
int f_0ccb50(int p1,int p2) {
  MO o;
  union ByteSlot { signed char b; int w; };
  union WordSlot { short s; int w; };
  struct Saved {
    int arg, result, known358, known35c, found;
    WordSlot length,count;
    ByteSlot dup,counted1,selected,ch,counted2;
  } s;
  s.arg=p1;
  // haelt die Registerzuteilung wie im Original
  s.result=0; s.result=0; s.result=0; s.result=0; s.result=0; 
  signed char *str=d_1bf360;
  f_0bfea0(d_1c2c64,strlen((char *)str),p2);
  if(f_144bf0(str,d_1c299c)==0) s.result=1;
  else {
    // haelt die Registerzuteilung wie im Original
    s.count.w=0; s.count.w=0; s.count.w=0;  s.dup.b=0;
    short pos;
    // haelt die Registerzuteilung wie im Original
    // Die vorhandene Globale bewahrt die Registerfolge aller Schleifen; nativer Code bleibt unveraendert.
    for(pos=d_1c21b5 ^ d_1c21b5;d_1bf360[pos]!=0;pos++) {
      s.ch.b=d_1bf360[pos];
      signed char current=s.ch.b;
      s.known35c=0;
      for(short j=0;d_1bf360[j]!=0;j++) {
        if(current==d_1bf360[j] && np_bit(j,d_1bf35c)) {s.known35c=1;break;}
      }
 // haelt die Registerzuteilung wie im Original
      if(s.known35c==1) {
        ((volatile char *)d_1c21b4)[pos]=s.ch.b;
        s.count.w++;
      } else {
        d_1c21b4[pos]='?';
        s.counted1.b=s.ch.b;
        short occurrences=0;
        for(short j=0;d_1bf360[j]!=0;j++) {
          if(s.counted1.b==d_1bf360[j]) occurrences++;
        }
        if(np_gt1(occurrences)) s.dup.b=s.ch.b;
      }
    }
    d_1c21b4[pos]=0;
    f_125400(&o,d_1c349c,d_1c3870,d_1c3498);
    o.p[1]=f_039320(d_1c0004,0x26);
    o.p4[1]=f_133fe0(d_1c3498,d_1c21b4);
    f_0bf730(d_1c2c64,0x3500018f);
    if((int)s.count.s<3 || ((int)s.count.s<5 && np_next(s.arg)>5)) {
      *(short *)(s.arg+0x20)=0;
      signed char hint=s.dup.b;
      int message=0x35000190;
      if(hint==0) {
        s.length.w=strlen((char *)d_1bf360);
        short pos2=0;
        s.selected.b=-1;
        for(;(int)pos2<(int)s.length.s && s.selected.b!=-1;pos2++) {
          signed char current=d_1bf360[pos2];
          s.found=0;
          for(short j=0;d_1bf360[j]!=0;j++) {
            if(current==d_1bf360[j] && np_bit(j,d_1bf35c)) {s.found=1;break;}
          }
          if(s.found==0) {
            s.counted2.b=d_1bf360[pos2];
            short occurrences=0;
            for(short j=0;d_1bf360[j]!=0;j++) {
              if(s.counted2.b==d_1bf360[j]) occurrences++;
            }
            if(!np_gt1(occurrences)) {int k=pos2;signed char *base=d_1bf360; base=(signed char *)(((int)base&0)?0:(int)base);s.selected.b=base[k];}
          }
        }
        hint=s.selected.b;
        message=0x35000191;
      }
      signed char current=hint;
      s.known358=0;
      for(short j=0;((signed char *)(((int)d_1bf360&0)?0:(int)d_1bf360))[j]!=0;j++) {
        if(current==((signed char *)(((int)d_1bf360&0)?0:(int)d_1bf360))[j] && np_bit(j,(const unsigned short &)d_1bf358)) {s.known358=1;break;}
      }
      {signed char *q=d_1bf360;d_1bf360=q;}
      if(s.known358==0) np_set(((hint&0)?0:hint),(unsigned short &)d_1bf358);
      np_set(hint,d_1bf35c);
      *(char *)&d_1c21b5=0;
      d_1c21b4[0]=hint;
      o.p[2]=f_039320(d_1c0004,0x21);
      o.p4[1]=f_133fe0(d_1c3498,d_1c21b4);
      f_0bf730(d_1c2c64,message);
    }
    f_1254a0(&o,0);
  }
  return s.result;
}
