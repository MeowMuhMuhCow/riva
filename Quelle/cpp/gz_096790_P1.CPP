/* === Beschreibung (Katalog) ===
 * Einheit gz_096790 (096790 - 097700)
 *
 * Überblick
 * Die Einheit gz_096790 fasst den letzten Teil der Heldenerschaffung (gen3/gen4/gz_0974f0) zusammen: das
 * Umverteilen von Kampftalentpunkten zwischen Attacke und Parade (f_096790, f_096960), die Auswahl des
 * Heldentypus mit Prüfung der Mindestvoraussetzungen (f_0969c0), das nachträgliche Tauschen positiver gegen
 * negative Eigenschaften (f_096d40), das Anlegen und Restaurieren der drei Seiten-Hintergrundpuffer (f_0971f0,
 * f_0974f0) sowie die manuelle Talentsteigerung im Expertenmodus (f_097600).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 1/4 gleich (suche.py 24.10.2026, Basis gz_096790_P1.CPP)
// gz_096790.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x096790-0x0971F0
#include <string.h>
int f_094330(int p1); // zusammengelegt: Typ aus Teil 3
extern char d_1c2c64[]; // zusammengelegt: Typ aus Teil 3
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#define A(x) ((int)&(x))
extern int d_1bc88c;
extern short d_1c2198;
extern int d_1c29c4;
extern int d_1c29c8;
 /* zusammengelegt: extern int (*(int *)&d_1c2c64); */
extern int d_1c349c;
extern int d_1c3870;
extern int d_1c3498;
extern int d_1a34e0;
extern signed char d_1a3204[];
extern signed char d_1a3205[];
extern signed char d_1a3210[];
struct Obj { int pad0[4]; int *p10; int rest[10]; };
signed char f_03ad80(int, int);
signed char f_043b30(int, int);
signed char f_043b20(int, int);



signed char f_043ac0(int, int);



void f_043ae0(int, int);
void f_043af0(int);
#pragma aux f_043af0 modify [eax edx];
void f_043e20(int, int);
void f_043b40(int, int, int);
void f_043b50(int, int, int);
void f_043aa0(int, int, int);
void f_0455b0(int, int, int);
void f_0453e0(int, int, int);

void f_0978a0(int, int);
void f_098d90(int, int, int);
 /* zusammengelegt: void ((void)f_094330(int)); */
void f_094f40(int);
short f_0945c0(int);
void f_145300(int, int, int);
int f_145760(int, int);
int f_0bf730(int, int);
int f_0bf6f0(int, int);
short f_0bf820(int, ...);
int f_125400(void *p1, int p2, int p3, int p4);
int f_1254a0(void *p1, int p2);
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_096790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erlaubt dem Spieler in der Heldenerschaffung, für ein gewähltes Kampftalent (p2) Punkte
 *   zwischen Attacke (f_043b40) und Parade (f_043b50) umzuschichten, solange der abgebende Wert über dem
 *   AT/PA-Basiswert (f_042890) bleibt und die Höchstgrenze zwischen AT und PA eingehalten wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p1 sowie den Kampftalent-Index p2 (0..6)
 *   und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nach jeder zulässigen Verschiebung (+1 AT / -1 PA bzw. -1 AT / +1 PA) wird die Anzeige
 *   über f_094330(p1) sofort aktualisiert.
 === Ende Beschreibung === */
void f_096790(int p1, short p2)
{
  Obj o;
  int s;
  f_125400(&o, A(d_1c349c), A(d_1c3870), A(d_1c3498));
  if (f_03ad80(*(int *)(p1 + 0xdf), p2) <= 0) {
    f_0bf730(A((*(int *)&d_1c2c64)), 0xe140035);
  } else {
    if (f_043b30(*(int *)(p1 + 0xdf), p2) > f_042890((struct hero *)(*(int *)(p1 + 0xdf))))
      d_1c29c4 = 0xe140018;
    else {
      d_1c29c4 = 0x2000000a;
      o.p10[1] = 0xe140018;
    }
    if (f_043b20(*(int *)(p1 + 0xdf), p2) > f_042890((struct hero *)(*(int *)(p1 + 0xdf))))
      d_1c29c8 = 0xe140019;
    else {
      d_1c29c8 = 0x2000000a;
      o.p10[1] = 0xe140019;
    }
    s = f_0bf820(A((*(int *)&d_1c2c64)), 0xe14002f, 2, d_1c29c4, d_1c29c8);
    if (s != -1) {
      if (s == 1) {
        if (f_043b30(*(int *)(p1 + 0xdf), p2) > f_042890((struct hero *)(*(int *)(p1 + 0xdf)))) {
          f_043b40(*(int *)(p1 + 0xdf), p2, 1);
          f_043b50(*(int *)(p1 + 0xdf), p2, -1);
          ((void)f_094330(p1));
        } else {
          f_0bf730(A((*(int *)&d_1c2c64)), 0xe140030);
        }
      } else {
        if (f_043b20(*(int *)(p1 + 0xdf), p2) > f_042890((struct hero *)(*(int *)(p1 + 0xdf)))) {
          f_043b40(*(int *)(p1 + 0xdf), p2, -1);
          f_043b50(*(int *)(p1 + 0xdf), p2, 1);
          ((void)f_094330(p1));
        } else {
          f_0bf730(A((*(int *)&d_1c2c64)), 0xe140031);
        }
      }
    }
  }
  f_1254a0(&o, 0);
}
//@ f_096960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet in einer Schleife das Auswahlmenü der sieben Kampftalente (0x2000005c..0x20000062:
 *   Raufen bis Schußwaffen) und ruft für das gewählte Kampftalent f_096790 auf, bis der Spieler das Menü mit
 *   Rechtsklick/Abbruch (s == -2) verlässt.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Gesteuert wird der Dialog über das globale Text- und Menüsystem d_1c2c64.
 === Ende Beschreibung === */
void f_096960(int p1)
{
  short s;
  do {
    s = f_0bf820(A((*(int *)&d_1c2c64)), 0xe14001b, 7, 0x2000005c, 0x2000005d, 0x2000005e, 0x2000005f, 0x20000060, 0x20000061, 0x20000062);
    s = s - 1;
    if (s != -2) f_096790(p1, s);
  } while (s != -2);
}
//@ f_0969c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt den Spieler in der Heldenerschaffung einen der zwölf Heldentypen (1..12, männlich oder
 *   weiblich) auswählen, würfelt bei Bestätigung sämtliche 14 Eigenschaften passend zum gewählten Typus aus,
 *   hebt oder senkt Werte, die die Mindest- oder Höchstvoraussetzungen des Typus (*(int *)(p1 + 0x28))
 *   verletzen, automatisch auf die Typgrenze, lädt das zugehörige Porträt- und Körperbild (f_098d90) und
 *   berechnet über f_094f40 alle abgeleiteten Startwerte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Tabelle an *(int *)(p1 + 0x28) enthält pro Heldentypus bis zu 6
 *   Eigenschaftsanforderungen (12 Bytes), wobei Bit 0x80 eine Höchstgrenze (für negative Eigenschaften) und
 *   Werte ohne 0x80 eine Mindestgrenze (für positive Eigenschaften) kennzeichnen.
 === Ende Beschreibung === */
void f_0969c0(int p1)
{
    void f_0978a0(int);
    void f_043af0(int,int);
    char buf[20];
    short s, j, i, k;
    signed char g;
    short v;
    d_1bc88c = 1;
    if (f_0bf6f0(A((*(int *)&d_1c2c64)), 0xe140039) == 1) {
        int base = f_042380((struct hero *)(*(int *)(p1 + 0xdf))) ? 0x2000004f : 0x20000042;
        s = f_0bf820(A((*(int *)&d_1c2c64)), 0xe14000f, 12,
            base+1,base+2,base+3,base+4,base+5,base+6,
            base+7,base+8,base+9,base+10,base+11,base+12);
        if (s != -1) {
            strcpy(buf, f_0422b0((struct hero *)(*(int *)(p1 + 0xdf))));
            g = f_042380((struct hero *)(*(int *)(p1 + 0xdf)));
            f_145300(*(int *)(p1 + 0xdf), 0, 0x5ef);
            f_043e20(*(int *)(p1 + 0xdf), 1);
            f_0978a0(p1);
            f_043af0(*(int *)(p1+0xdf),g);
            f_0422c0((struct hero *)(*(int *)(p1 + 0xdf)),(char *)( buf));
            f_0422f0((struct hero *)(*(int *)(p1 + 0xdf)),(char *)( buf));
            f_043ae0(*(int *)(p1 + 0xdf), (signed char)s);
            for (i = 0; i <= 6; i++) {
                v = f_145760(8, 13);
                if (v > 8) v--;
                f_043aa0(*(int *)(p1 + 0xdf), i, (signed char)v);
                f_0455b0(*(int *)(p1 + 0xdf), i, (signed char)v);
            }
            for (j = 7; j <= 13; j++) {
                short v = f_145760(2, 7);
                if (v < 7) v++;
                f_043aa0(*(int *)(p1 + 0xdf), j, (signed char)v);
                f_0455b0(*(int *)(p1 + 0xdf), j, (signed char)v);
            }
            for (k = 0; k < (short)6; k++) {
                int e = *(int *)(p1 + 0x28) + s * 12;
                e += k * 2;
                short b = *(unsigned char *)(e + 1);
                short a = *(unsigned char *)e;
                if (b) {
                    if (b & 0x80) {
                        short limit; signed char value=f_043ac0(*(int *)(p1 + 0xdf), a); limit=b; limit &= 0x7f; if (value > limit) {
                            f_043aa0(*(int *)(p1 + 0xdf), a, (signed char)(b & 0x7f));
                            f_0455b0(*(int *)(p1 + 0xdf), a, (signed char)(b & 0x7f));
                        }
                    } else {
                        if ((signed char)f_043ac0(*(int *)(p1+0xdf),a)<b) {
                            f_043aa0(*(int *)(p1 + 0xdf), a, (signed char)b);
                            f_0455b0(*(int *)(p1 + 0xdf), a, (signed char)b);
                        }
                    }
                }
            }
            f_098d90(p1, d_1a34e0, f_042350((struct hero *)(*(int *)(p1 + 0xdf))));
            *(signed char *)p1 = f_042350((struct hero *)(*(int *)(p1 + 0xdf))) > 10 ? 10 : f_042350((struct hero *)(*(int *)(p1 + 0xdf)));
            short w;
            if (f_042380((struct hero *)(*(int *)(p1 + 0xdf)))) {
                *(short *)(p1 + 3) = *(short *)(p1 + 1) = d_1a3210[*(signed char *)p1];
                w = d_1a3205[*(signed char *)p1];
            } else {
                *(short *)(p1 + 3) = *(short *)(p1 + 1) = d_1a3204[*(signed char *)p1];
                w = d_1a3210[*(signed char *)p1];
            }
            *(short *)(p1 + 5) = w - 1;
            f_042330((struct hero *)(*(int *)(p1 + 0xdf)), *(short *)(p1 + 1));
            f_094f40(p1);
            d_1c2198 = 1;
        }
    }
    d_1bc88c = 0;
}
//@ f_096d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt in der Heldenerschaffung den interaktiven Eigenschaftstausch durch: Der Spieler kann
 *   eine positive Eigenschaft (0..6) um 1 Punkt erhöhen, wenn er dafür zwei negative Eigenschaften (7..13) um je
 *   1 Punkt erhöht, oder eine positive Eigenschaft um 1 Punkt senken, um zwei negative Eigenschaften um je 1
 *   Punkt zu senken (wobei ein bereits gewählter Heldentypus zuvor zurückgesetzt wird).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Array *(signed char *)(p1 + 0x14 + i) verhindert, dass dieselbe Eigenschaft mehrfach
 *   in entgegengesetzte Richtungen getauscht wird, und *(int *)(p1 + 0x11b) schaltet während des Tauschs die
 *   Farbmarkierung in f_095820 ein.
 === Ende Beschreibung === */
void f_096d40(int p1)
{
  short s2, mode; int s3;
  int i4, i5, lc;
  signed char c;
  *(int *)(p1+0x11b) = d_1bc88c = 1;
  if (!(signed char)f_043ac0(*(int *)(p1+0xdf),0)) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14000d); goto END; }
  if (!f_0945c0(p1)) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14003b); goto END; }
  if (f_042350((struct hero *)(*(int *)(p1+0xdf)))) {
    i4=f_0bf6f0(A((*(int *)&d_1c2c64)),0xe140016);
    lc=0;
    if(i4==1) {
      f_043ae0(*(int *)(p1+0xdf),0);
      if(*(int *)(p1+8)) { f_0453e0(*(int *)(p1+0xdf),0,-1); *(int *)(p1+8)=0; }
      if(*(int *)(p1+12)) { f_0453e0(*(int *)(p1+0xdf),2,-1); *(int *)(p1+12)=0; }
      *(volatile short *)&d_1c2198=1; // haelt den Speicherzugriff auf d_1c2198 wie im Original
      ((void)f_094330(p1));
      lc=1;
    }
  }
L33:
  if(!lc) goto END;
  if(!f_0945c0(p1)) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14003b); goto END; }
  s2=f_0bf820(A((*(int *)&d_1c2c64)),0xe14001b,7,0x20000143,0x20000144,0x20000145,0x20000146,0x20000147,0x20000148,0x20000149);
  --s2;
  {
    int j=s2;
    if(j==-2) goto END;
    j+=p1;
    if(!*(signed char *)(j+0x14)) {
      mode=f_0bf820(A((*(int *)&d_1c2c64)),0x20000194,2,0xe140018,0xe140019);
      if(mode==-1) goto END;
    } else mode=*(signed char *)(j+0x14);
  }
  c=(signed char)f_043ac0(*(int *)(p1+0xdf),s2);
  if(mode==1) {
    if(c==13) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14001a); goto L33; }
    i4=0;
    for(s3=7;(i5=(short)s3)<=13;++s3) {
      if(*(signed char *)(p1+i5+0x14)!=-1 && (signed char)f_043ac0(*(int *)(p1+0xdf),i5)<8)
        i4+=8-(signed char)f_043ac0(*(int *)(p1+0xdf),i5);
    }
    if(i4<2) { f_0bf730(A((*(int *)&d_1c2c64)),0xe140022); goto L33; }
    f_0453e0(*(int *)(p1+0xdf),s2,1);
    s3=0;
    *(signed char *)(p1+s2+0x14)=1;
UPDRAW:
    ((void)f_094330(p1));
UPCHECK:
    if((short)s3==2) goto L33;
UPMENU:
    s2=f_0bf820(A((*(int *)&d_1c2c64)),0xe14001d,7,0x2000014a,0x2000014b,0x2000014c,0x2000014d,0x2000014e,0x2000014f,0x20000150);
    --s2;
    if((short)(s2 & 0xffff)==-2) goto UPMENU; // haelt die 16-Bit-Vergleichsform wie im Original
    i4=(short)(s2+7);
    if(*(signed char *)(p1+i4+0x14)==-1) { f_0bf730(A((*(int *)&d_1c2c64)),0xe140020); goto UPCHECK; }
    if((signed char)f_043ac0(*(int *)(p1+0xdf),i4)==8) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14001a); goto UPCHECK; }
    *(signed char *)(p1+i4+0x14)=1;
    f_0453e0(*(int *)(p1+0xdf),i4,1);
    ++s3;
    ((void)f_094330(p1));
    goto UPCHECK;
  } else {
    if(c==8) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14001e); goto L33; }
    i4=0;
    for(s3=7;(i5=(short)s3)<=13;++s3) {
      if(*(signed char *)(p1+i5+0x14)!=1 && (signed char)f_043ac0(*(int *)(p1+0xdf),i5)>2)
        i4+=(signed char)f_043ac0(*(int *)(p1+0xdf),i5)-2;
    }
    if(i4<2) { f_0bf730(A((*(int *)&d_1c2c64)),0xe140022); goto L33; }
    f_0453e0(*(int *)(p1+0xdf),s2,-1);
    s3=0;
    *(signed char *)(p1+s2+0x14)=-1;
DOWNDRAW:
    ((void)f_094330(p1));
DOWNCHECK:
    if((short)s3==2) goto L33;
DOWNMENU:
    s2=f_0bf820(A((*(int *)&d_1c2c64)),0xe14001c,7,0x2000014a,0x2000014b,0x2000014c,0x2000014d,0x2000014e,0x2000014f,0x20000150);
    --s2;
    if(s2==-2) goto DOWNMENU;
    i4=(short)(s2+7);
    if(*(signed char *)(p1+i4+0x14)==1) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14001f); goto DOWNCHECK; }
    if((signed char)f_043ac0(*(int *)(p1+0xdf),i4)==2) { f_0bf730(A((*(int *)&d_1c2c64)),0xe14001e); goto DOWNCHECK; }
    ++s3;
    f_0453e0(*(int *)(p1+0xdf),i4,-1);
    *(signed char *)(p1+i4+0x14)=-1;
    ((void)f_094330(p1));
    goto DOWNCHECK;
  }
END:
  *(int *)(p1+0x11b)=d_1bc88c=0;
}

// ===== Teil 2: gen4 (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// I9: aus gen4_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// gen4.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x0971F0-0x0974F0. Loescht drei Bilder und legt sie je nach Typ neu an.
extern const char gen4_file[44] = "p:\\riva\\source\\cpp\\gen4.cpp";   // 0x1A3408



#include "RIVAIMG.H"     // 0x0FAC80 / 0x0FAD20


struct Gen4 {
    char p0[7];
    unsigned char kind;
    char p8[0x30];
    int w38;
    char p3c[0xaf];
    RivaRasterImage *i_eb, *i_ef, *i_f3;
    void f_0971f0();
};

//@ f_0971c4
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Vom Watcom-Compiler erzeugtes, leeres Hilfssymbol (gen4_tab / W?$Wsi01tab$) am Beginn des
 *   Moduls gen4.
 * - Eingaben und Rückgabe: Es handelt sich um ein Datensymbol ohne Parameter oder Rückgabe.
 * - Wichtige Variablen: Es werden keine Laufzeitvariablen verändert.
 === Ende Beschreibung === */
extern const char gen4_tab[];
#pragma aux gen4_tab "W?$Wsi01tab$";
extern const char gen4_tab[] = "";

//@ f_0971f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht die bis zu drei gespeicherten Hintergrund-Teilbilder (i_eb, i_ef, i_f3) der aktuellen
 *   Generierungsseite und schneidet je nach gewählter Seitennummer (kind = 0..10) die drei Zahlen- und
 *   Textspalten aus dem frisch geladenen Seitenhintergrund (w38) in neue RivaRasterImage-Objekte aus, damit
 *   diese Bereiche vor jedem Neuzeichnen von Zahlen schnell restauriert werden können.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger (Gen4 *) der Generierungsstruktur und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die drei RivaRasterImage-Zeiger an den Offsets +0xeb, +0xef und +0xf3 sichern die
 *   Überschriftszeile sowie die linke und rechte Wertespalte der jeweiligen Karteikarte.
 === Ende Beschreibung === */
void Gen4::f_0971f0()
{
    if (i_eb) { delete i_eb; i_eb = 0; }
    if (i_ef) { delete i_ef; i_ef = 0; }
    if (i_f3) { delete i_f3; i_f3 = 0; }
    short x1 = 0, h3, h2, y1, h1, x3, y2, w2, w3, w1, y3, x2;
    switch (kind) {
    case 0:
        x1 = 176; y1 = 12; w1 = 94; h1 = 8; y2 = 205; x2 = 73; w2 = 20; h2 = 90; y3 = 273; x3 = 73; w3 = 20; h3 = 90;
        break;
    case 1: case 2: case 3:
        x1 = 270; y1 = 184; w1 = 15; h1 = 8; y2 = 206; x2 = 40; w2 = 24; h2 = 138; y3 = 296; x3 = 40; w3 = 24; h3 = 138;
        break;
    case 4:
        y2 = 225; x2 = 48; w2 = 20; h2 = 130; y3 = 260; x3 = 48; w3 = 20; h3 = 130;
        break;
    case 5: case 6: case 7: case 8: case 9: case 10:
        x1 = 215; y1 = 184; w1 = 15; h1 = 8; y2 = 141; x2 = 42; w2 = 20; h2 = 140; y3 = 296; x3 = 42; w3 = 24; h3 = 140;
        break;
    }
    if (x1) {
        i_eb = new (mark(gen4_file, 463)) RivaRasterImage(w1, h1);
        ((RivaRasterImage*)(i_eb))->f_0fafb0((void *)( w38), x1, y1);
    }
    i_ef = new (mark(gen4_file, 480)) RivaRasterImage(w2, h2);
    ((RivaRasterImage*)(i_ef))->f_0fafb0((void *)( w38), y2, x2);
    i_f3 = new (mark(gen4_file, 496)) RivaRasterImage(w3, h3);
    ((RivaRasterImage*)(i_f3))->f_0fafb0((void *)( w38), y3, x3);
}

// ===== Teil 3: gz_0974f0 (08.11. Claude I15: gleiches Original-Modul, zusammengelegt) =====
// P3 0/2 gleich (suche.py 24.10.2026, Basis gz_0974f0_P1.CPP)
// gz_0974f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0974F0-0x097700
// #include <string.h>
signed char f_03ad80(int p1, int p2);
int f_03af20(int p1, int p2, int p3);
int f_043360(int p1, int p2);
/* nach vorn: int f_094330(int p1); */
int f_0bf730(const char *o, int b);

 /* zusammengelegt: short ((short)f_145760(int p1, int p2)); */
extern int d_1bc88c;
extern signed char *d_1bc89c;
/* nach vorn: extern char d_1c2c64[]; */
#define ST(a,b,c,d) l14=a; l18=b; l1c=d; l20=c;
//@ f_0974f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert die in f_0971f0 gesicherten Hintergrund-Teilbilder (+0xeb, +0xef, +0xf3) passend zur
 *   aktiven Karteikarte (*(unsigned char *)(p1 + 7)) zurück in den Zielbildpuffer p2, bevor f_095c40 die
 *   aktuellen Eigenschafts-, Talent- oder Zauberwerte darüberzeichnet.
 * - Eingaben und Rückgabe: Die Funktion erhält den Generierungskontext p1 sowie den Zielbildpuffer p2 und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Auf Seite 4 (Kampftalente) wird kein oberes Kopfbild (a == 0) benötigt, sodass dort nur
 *   die beiden Spaltenpuffer +0xef und +0xf3 ausgegeben werden.
 === Ende Beschreibung === */
void f_0974f0(int p1, int p2)
{
  short a = 0;
  short w;
  short l1c, l18, l14, l20;
  switch (*(unsigned char *)(p1 + 7)) {
  case 0:
    a = 0xb0; w = 0xc;
    ST(0xcd, 0x49, 0x49, 0x111)
    break;
  case 1:
  case 2:
  case 3:
    a = 0x10e; w = 0xb8;
    ST(0xce, 0x28, 0x28, 0x128)
    break;
  case 4:
    ST(0xe1, 0x30, 0x30, 0x104)
    break;
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
    a = 0xd7; w = 0xb8;
    ST(0x8d, 0x2a, 0x2a, 0x128)
  }
  if (a != (short)0) ((RivaRasterImage*)(*(int *)(p1 + 0xeb)))->f_0fade0((void *)( p2), a, w);
  ((RivaRasterImage*)(*(int *)(p1 + 0xef)))->f_0fade0((void *)( p2), l14, l18);
  ((RivaRasterImage*)(*(int *)(p1 + 0xf3)))->f_0fade0((void *)( p2), l1c, l20);
}
//@ f_097600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt im Expertenmodus der Heldenerschaffung einen einzelnen manuellen Steigerungsversuch für
 *   das vom Spieler angeklickte Talent p2 durch: Sie prüft die Höchstzahl erlaubter Steigerungen (p3) und die
 *   Grenze von 3 Fehlversuchen (d_1bc89c[p2 * 2] == 3), zieht einen Talentversuch ab, würfelt mit 2W6
 *   (f_145760(2, 12)) gegen den aktuellen Talentwert und gibt eine Erfolgs- oder Fehlschlagsmeldung (0xe14002a
 *   bzw. 0xe14002b) aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Generierungskontext p1, den Talentindex p2, das
 *   Steigerungslimit p3 sowie die Meldungskennung p4 (bei erreichtem Limit) entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Array d_1bc89c speichert paarweise je Talent die Fehlversuche (p2 * 2) und die
 *   bereits erzielten Steigerungen (p2 * 2 + 1).
 === Ende Beschreibung === */
void f_097600(int p1, short p2, short p3, int p4)
{
  d_1bc88c = 1;
  if (d_1bc89c[p2 * 2 + 1] >= p3) {
    f_0bf730(d_1c2c64, p4);
  } else if (d_1bc89c[p2 * 2] == 3) {
    f_0bf730(d_1c2c64, 0xe140029);
  } else {
    f_043360(*(int *)(p1 + 0xdf), -1);
    if (((short)f_145760(2, 0xc)) > f_03ad80(*(int *)(p1 + 0xdf), p2)) {
      f_0bf730(d_1c2c64, 0xe14002a);
      f_03af20(*(int *)(p1 + 0xdf), p2, 1);
      d_1bc89c[p2 * 2] = 0;
      d_1bc89c[p2 * 2 + 1]++;
      f_094330(p1);
    } else {
      f_0bf730(d_1c2c64, 0xe14002b);
      d_1bc89c[p2 * 2]++;
      f_094330(p1);
    }
  }
  d_1bc88c = 0;
}
