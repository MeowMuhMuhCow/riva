/* === Beschreibung (Katalog) ===
 * Einheit gz_0727e0 (0727e0 - 0738a0)
 *
 * Überblick
 * Diese Einheit enthält zentrale Hilfsfunktionen der Kampf-Engine zur Ermittlung von Animationsdatei-IDs
 * (f_0727e0, f_0728f0), zur Prüfung von Großgegnern und Kampffähigkeit (f_072850, f_072910, f_072940, f_072a00,
 * f_072b70), zum Markieren von Fernkampf-/Zauber-Zielkorridoren auf dem Wegfindungsraster (f_072cf0, f_072ec0,
 * f_0730d0) sowie zur Sichtlinien- und Reichweitenprüfung (f_073410, f_0735b0, f_073800).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/15 gleich (suche.py 29.10.2026, Basis gz_0727e0_P1.CPP)
// gz_0727e0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0727E0-0x0738A0
#include <string.h>
char f_043470(int p1);
void f_069460();
short f_071e20(int p1, int p2, int p3, int p4);
int f_071e90(int, short *, short *);
void *f_145300(void *, int, unsigned);
short f_1457e0(int, int);
int f_073410(int, int, int, short *, short);
#pragma aux f_07b580 parm [eax edx] modify exact [eax edx]
int f_07b580(int p1, int p2);
int f_0307d0(int p1);
int f_0cdd50(int p1, int p2, int p3, int p4, int p5);
short f_0dbfb0(int p1, int p2);
char f_0cf910(int p1);
int f_0cf930(int p1);
int f_0cf940(void *p1, int p2);
#pragma aux f_0d0220_ctor parm [eax] modify exact []
void f_0d0220_ctor(void *p1);
void f_0d0220_dtor(void *p1, int p2);




char f_0cfdc0(int p1);
char f_0cfdf0(int p1);
char f_0cfe30(int p1);
char f_0cfe60(int p1);
char f_0cfec0(int p1);
char f_0cfef0(int p1);
char f_0cff50(int p1);
char f_0cff80(int p1);
char f_0cffe0(int p1);
signed char f_0d00a0(int p1);
int f_0d06c0(int p1);
unsigned short f_0d12e0(int p1);
short f_149410(int p1, int *p2);
extern char d_0b0000[];
extern char d_0b0054[];
extern int d_1a27f4;

extern int d_1bc8f0;
extern signed char d_1bd928;
extern short d_1bd920;
extern char *d_1bd984;
extern int d_1c2ed4;
extern signed char d_1c0004;
#define S(x) ((short)(x))
//@ f_0727e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Ressourcen-ID (0xb0000 + ...) der Kampfanimationsdatei für einen Helden oder
 *   Gruppenbegleiter p.
 * - Eingaben und Rückgabe: Empfängt den Heldenzeiger p (int) und gibt die 32-Bit-Ressourcenkennung (int) im
 *   Archivbereich 0xb0000 zurück.
 * - Wichtige Variablen: Prüft über f_042400(p), ob es sich um einen Begleiter/NSC handelt (Offset 0xb0054), oder
 *   addiert den Archetyp-/Grafikindex f_042360(p) zu 0xb0000.
 === Ende Beschreibung === */
int f_0727e0(int p)
{
  if (f_042400((struct hero *)(p)))
    return 0xb0054 + f_042400((struct hero *)(p));
  return 0xb0000 + ((signed char)(f_042360((struct hero *)(p))));
}
//@ f_072810
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht in den 7 Gruppen-Slots p[0..6] nach dem Helden, der im Kampf die
 *   Sprite-/Animationslisten-Kennung c (f_043470) besitzt.
 * - Eingaben und Rückgabe: Empfängt das Heldenzeiger-Array p (int *) und die gesuchte Kennung c (char) und gibt
 *   den gefundenen Heldenzeiger (int) oder 0 zurück.
 * - Wichtige Variablen: Durchläuft die 7 Gruppenplätze und vergleicht f_043470(p[i]) mit c.
 === Ende Beschreibung === */
int f_072810(int *p, char c)
{
  short i;
  int v;
  if (d_1bd928) f_069460();
  for (i = 0; i <= 6; i++) { v = p[i]; if (v && f_043470(v) == c) return v; } return 0;
}
//@ f_072850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt den 58 Byte großen Monsterdatensatz Nr. p aus der Monsterdatei 0x80010003 und prüft
 *   anhand der Tabelle d_1a27f4, ob dieses Monster ein zweifeldriger Großgegner ist.
 * - Eingaben und Rückgabe: Empfängt die Monster-Datensatznummer p (int) und gibt 1 zurück, wenn die
 *   Grafikkennung in der Großgegner-Liste d_1a27f4 steht, sonst 0.
 * - Wichtige Variablen: Nutzt den Dateimanager d_1c2098 auf 0x80010003 (Eintragsgröße 0x3a Bytes) und die
 *   Suchfunktion f_149410 auf d_1a27f4.
 === Ende Beschreibung === */
int f_072850(int p)
{
  char t[0xb0];
  int ok;
  f_0d0220_ctor(t);
  ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( 0x80010003, 0x200);
  ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( (short)p * 0x3a, 0);
  ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( t + 0x74), 0x3a)));
  ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
  f_0cf940(t, (unsigned char)t[0x75]);
  ok = f_149410((unsigned char)f_0cf930((int)t), &d_1a27f4) != -1;
  f_0d0220_dtor(t, 0);
  return ok;
}
//@ f_0728f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Ressourcen-ID (0xb0000 + ...) der Kampfanimationsdatei eines Monsters p anhand
 *   seiner Grafikkennung f_0cf930(p). *(Hinweis: Enthält eine redundante if (d_1bd920 == 2)-Verzweigung, deren
 *   beide Zweige exakt denselben Wert (f_0cf930(p) & 0xff) + 0xb0000 zurückgeben; siehe Fehlerliste.)*
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt die Ressourcen-ID (int) zurück.
 * - Wichtige Variablen: Liest den Kampfmodus d_1bd920 und das Grafikbyte f_0cf930(p).
 === Ende Beschreibung === */
int f_0728f0(int p)
{
  if (d_1bd920 == 2)
    return (f_0cf930(p) & 0xff) + 0xb0000;
  return (f_0cf930(p) & 0xff) + 0xb0000;
}
//@ f_072910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für ein bereits geladenes Monster p im laufenden Kampf, ob dessen Grafikkennung
 *   f_0cf930(p) in der Großgegner-Tabelle d_1a27f4 (zweifeldrige Gegner wie Oger, Drachen oder Hunde) enthalten
 *   ist.
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt 1 bei einem zweifeldrigen Gegner oder 0
 *   bei einem einfeldrigen Gegner zurück.
 * - Wichtige Variablen: Ruft f_149410(f_0cf930(p) & 0xff, &d_1a27f4) auf.
 === Ende Beschreibung === */
int f_072910(int p)
{
  return f_149410(f_0cf930(p) & 0xff, &d_1a27f4) != -1;
}
//@ f_072940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Monster p aktuell handlungsfähig ist (weder tot, geflohen, versteinert,
 *   schlafend, gelähmt noch anderweitig kampfunfähig).
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt 1 zurück, wenn das Monster agieren kann,
 *   sonst 0.
 * - Wichtige Variablen: Fragt nacheinander die Status-Getter f_0cfdf0, f_0cfdc0, f_0cfe30, f_0cffe0, f_0cfec0,
 *   f_0cfef0, f_0cfe60, f_0cff50 und f_0d00a0 ab.
 === Ende Beschreibung === */
int f_072940(int p)
{
  if (f_0cfdf0(p) || f_0cfdc0(p) || f_0cfe30(p) || f_0cffe0(p) || f_0cfec0(p) || f_0cfef0(p) || f_0cfe60(p) || f_0cff50(p) || f_0d00a0(p) > 0) return 0; return 1;
}
//@ f_0729c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt den Array-Index (0..19) eines Monsterzeigers p innerhalb des globalen Monster-Arrays
 *   d_1c2ed4 (Eintragsgröße 0x73 Bytes).
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt dessen Index 0..19 als unsigned char
 *   zurück.
 * - Wichtige Variablen: Vergleicht p in einer Schleife mit d_1c2ed4 + i * 0x73.
 === Ende Beschreibung === */
unsigned char f_0729c0(int p)
{
  int p_ = p;
  unsigned char i = 0;
  int q = d_1c2ed4;
  int index;
  for (; i < 0x14; i = i + 1, index = i * 0x73, q = d_1c2ed4, q += index) {
    if (p_ == q) return i;
  }
  return 0;
}
//@ f_072a00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob das Monster p ein gültiges, lebendes, feindliches Angriffsziel ist, das sich aktuell
 *   auf dem 24 x 24-Kampfraster d_1bd984 befindet.
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt 1 zurück, wenn das Monster aktiv,
 *   feindlich (!f_0cff80(p)) und auf dem Spielfeld platziert ist, sonst 0.
 * - Wichtige Variablen: Sucht die Monsterkennung idx + 10 auf dem Kampfraster d_1bd984.
 === Ende Beschreibung === */
int f_072a00(int p)
{
  struct Counter494 {
    static void zero(short &v){v=0;}
    static short next(short &v){return ++v;}
  };
  struct Lookup494 {
    struct Base494 {
      static int value(){return d_1c2ed4;}
    };

    static unsigned char get(int p) {
      int p_=p;
      unsigned char i=0;
      int q=d_1c2ed4;
      for(;i<20;i=i+1,q=i*0x73,q+=Base494::value())if(p_==q)return i;
      return 0;
    }
  };
  short x,y,bound;
  int found;
  unsigned char i;
  if(f_0cf910(p)&&!f_0cfdc0(p)&&!f_0cfe30(p)&&!f_0cfef0(p)&&!f_0cff50(p)&&!f_0cff80(p)&&!f_0cfec0(p)&&!f_0cfe60(p)&&!f_0cffe0(p)&&f_0d00a0(p)<=0) {
    i=Lookup494::get(p);
    bound=24;
    {char key=(char)(i+10);
    Counter494::zero(x);
    for(;x<24;Counter494::next(x)) {
      if(d_1bd928)f_069460();
      Counter494::zero(y);
      do {
        char *row=d_1bd984+y*25;
        if(key==row[x]){found=1;goto board_done494;}
      }while(bound>Counter494::next(y));
    }
    found=0;
    }
  board_done494:
    if(found)goto yes494;
  }
  return 0;
 yes494:
  return 1;
}
//@ f_072b70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft analog zu f_072a00, ob das Monster p aktiv und auf dem Kampfraster platziert ist, jedoch
 *   zur Seite der Helden gehört (verzaubertes oder verbündetes Wesen mit f_0cff80(p) != 0).
 * - Eingaben und Rückgabe: Empfängt den Monsterzeiger p (int) und gibt 1 zurück, wenn es ein aktives verbündetes
 *   Wesen auf dem Spielfeld ist, sonst 0.
 * - Wichtige Variablen: Prüft nach der Rastersuche zusätzlich f_0cff80(p).
 === Ende Beschreibung === */
int f_072b70(int p)
{
  struct Counter494 {
    static void zero(short &v){v=0;}
    static short next(short &v){return ++v;}
  };
  struct Lookup494 {
    struct Base494 {
      static int value(){return d_1c2ed4;}
    };

    static unsigned char get(int p) {
      int p_=p;
      unsigned char i=0;
      int q=d_1c2ed4;
      for(;i<20;i=i+1,q=i*0x73,q+=Base494::value())if(p_==q)return i;
      return 0;
    }
  };
  struct Scan494 {static int run(short &x,short &y,char key,short bound){
    Counter494::zero(x);
    for(;x<24;Counter494::next(x)) {
      if(d_1bd928)f_069460();
      Counter494::zero(y);
      do {
        char *row=d_1bd984+y*25;
        if(key==row[x]){return 1;}
      }while(bound>Counter494::next(y));
    }
    return 0;
  }};
  short x,y,bound;
  int found;
  unsigned char i;
  if(f_0cf910(p)&&!f_0cfdc0(p)&&!f_0cfe30(p)&&!f_0cfef0(p)&&!f_0cff50(p)&&!f_0cffe0(p)&&!f_0cfec0(p)&&!f_0cfe60(p)&&f_0d00a0(p)<=0) {
    i=Lookup494::get(p);
    bound=24;
    found=Scan494::run(x,y,(char)(i+10),bound);
    if(found&&f_0cff80(p))return 1;
  }
  return 0;
}
//@ f_072cf0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Markiert auf der temporären Wegfindungs-Kopie des Kampfrasters (*(p + 0x3d3)) für alle in
 *   zufälliger Reihenfolge geprüften Helden (nr = 0..6) sämtliche freien Felder, von denen aus eine freie
 *   Sicht-/Schusslinie (Hilf::pruefe mit Reichweite 99) und mindestens der Abstand mindest zum Helden besteht,
 *   mit dem Zielmarker nr + 0xce. Dadurch kann die KI im Breitensuchlauf (f_074b40) ein geeignetes Fernkampf-
 *   oder Zauber-Schussfeld auf einen Helden finden.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p, den Suchmodus art, die Mindestdistanz mindest sowie einen
 *   auszuschließenden Heldenindex ausnahme und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt das Hilfsraster *(unsigned char )(p + 0x3d3) und trägt dort Werte im Bereich
 *   0xce..0xd4 ein.
 === Ende Beschreibung === */
void f_072cf0(int p, short art, short mindest, short ausnahme)
{
  struct Hilf {
    static int pruefe(int p1, short p2, short p3, short p4, short p5, short p6) {
      short r;
      if (p6 == 1) {
        if (p2 != p4 && p3 != S(p5)) r = 0;
        else {
          r = f_071e20(p2, p3, p4, S(p5));
          if (r > 1) r = 0; else r = 1;
        }
      } else {
        f_0cdd50(p2, p3, p4, S(p5), p1 + 0x35b);
        r = f_073410(p1, p2, p3, (short *)(p1 + 0x35b), p6);
      }
      return r;
    }
  };
  struct HH { char b[0x5ef]; };
  extern HH *p_hh;
  #pragma aux p_hh "d_1bc8f0"
  short row;
  short zy;
  int feld;
  short nr;
  int benutzt[7];
  short zx; // Haelt die Register- und Stapelfolge wie im Original F07 Ort: Block-Deklaration verlegt
  int i;
  short col;
  unsigned char *karte;
  f_145300(benutzt, 0, 28);
  for (i = 0; (short)i <= 6; i++) {
    if (d_1bd928) f_069460();
    do nr = ((short (*)(int))f_1457e0)(7) - 1; while (benutzt[nr]); // Haelt die Register- und Stapelfolge wie im Original echte Signatur
    benutzt[nr] = 1;
    if (art == 14) { if (nr == ausnahme) continue; } else if (art == 12) { if (nr == ausnahme) continue; }
    if (!((int (*)(int, int))f_0dbfb0)(*(int *)&d_1c0004, (int)(p_hh + nr))) continue; // Haelt die Register- und Stapelfolge wie im Original Rueckgabe/Global int
    if (!f_071e90((unsigned char)(nr + 1), &zx, &zy)) continue;
    karte = (*(unsigned char **)(p + 0x3d3) + zy * 25) + zx;
    feld = *karte;
    { unsigned char *u_ = karte; karte = u_; }
    { short u_ = ausnahme; ausnahme = u_; }
    { short u_ = art; art = u_; }
    if (!feld || *karte == (unsigned char)0xcc) continue;
    for (row = 0; row < (short)24; row++) {
      for (col = 0; col < 24; col++) {
        if ((*(unsigned char **)(p + 0x3d3) + row * 25)[col]) continue;
        if (f_071e20(col, row, zx, zy) < mindest) continue;
        if (Hilf::pruefe(p, col, row, zx, zy, 99))
          (*(unsigned char **)(p + 0x3d3) + row * 25)[col] = nr + 0xce;
          { short u_ = col; col = u_; } // Haelt die Register- und Stapelfolge wie im Original F07 Ort: 1x Umlauf col
      }
        { short u_ = mindest; mindest = u_; }
        { short u_ = mindest; mindest = u_; }
        { short u_ = ausnahme; ausnahme = u_; }
        { short u_ = art; art = u_; }
        { int u_ = i; i = u_; }
        { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } { int u_ = feld; feld = u_; } // Haelt die Register- und Stapelfolge wie im Original F07 Dosis: 10x Umlauf feld
    }
  }
}


//@ f_072ec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Markiert analog zu f_072cf0 für alle bis zu 20 Monster (nr = 0..19) sämtliche freien
 *   Kampffelder mit freier Sichtlinie und Mindestdistanz mindest zum jeweiligen Monster mit dem Marker nr + 0xd8
 *   (0xd8..0xeb) auf dem Hilfsraster *(p + 0x3d3).
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p, den Suchmodus art, die Mindestdistanz mindest sowie einen
 *   auszuschließenden Monsterindex ausnahme und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Unterscheidet über art (9, 10, 12, 13), ob feindliche (f_072a00) oder verbündete
 *   (f_072b70) Monster als Ziele markiert werden.
 === Ende Beschreibung === */
void f_072ec0(int p, short art, short mindest, short ausnahme)
{
  struct Hilf {
    static int base() { return d_1c2ed4; }
    static int pruefe(int p1, short p2, short p3, short p4, short p5, short p6) {
      short r;
      if (p6 == 1) {
        if (p2 != p4 && p3 != S(p5)) r = 0;
        else {
          r = f_071e20(p2, p3, p4, S(p5));
          if (r > 1) r = 0; else r = 1;
        }
      } else {
        f_0cdd50(p2, p3, p4, S(p5), p1 + 0x35b);
        r = f_073410(p1, p2, p3, (short *)(p1 + 0x35b), p6);
      }
      return r;
    }
  };
  int mon;
  short nr;
  short row;
  short zx;
  short col;
  short i;
  short zy;
  int feld;
  int benutzt[20];
  unsigned char marke;
  unsigned char *karte;
  f_145300(benutzt, 0, 80);
  for (i = 0; i < (short)20; i++) {
    { short c1935_1 = (ausnahme & 0) ? (short)0 : ausnahme; ausnahme = c1935_1; } // Haelt die Register- und Stapelfolge wie im Original
    if (d_1bd928) f_069460();
    do nr = ((short (*)(int))f_1457e0)(20) - 1; while (benutzt[nr]); // Haelt die Register- und Stapelfolge wie im Original echte Signatur
    benutzt[nr] = 1;
    if ((art == 10 || art == 9) && nr == ausnahme) continue;
    mon = nr * 0x73;
    mon += Hilf::base();
    if (!(((art == 10 || art == 13) && f_072a00(mon)) || ((art == 9 || art == 12) && f_072b70(mon)))) continue;
    if (!f_071e90((unsigned char)(nr + 10), &zx, &zy)) continue;
    karte = (*(unsigned char **)(p + 0x3d3) + ((p & 0) ? (int)0 : (zy * 25))) + zx; // Haelt die Register- und Stapelfolge wie im Original A1_1935: codefreies Merge fuer MUL-Registerfolge
    feld = *karte;
    if (!feld || *karte == (unsigned char)0xcc) continue;
    for (row = 0, marke = nr + 0xd8; row < (short)24; row++) {
      for (col = 0; col < 24; col++) {
        if ((*(unsigned char **)(p + 0x3d3) + row * 25)[col]) continue;
        if (f_071e20(col, row, zx, zy) < mindest) continue;
        if (Hilf::pruefe(p, col, row, zx, zy, 99))
          (*(unsigned char **)(p + 0x3d3) + row * 25)[col] = marke;
        { short u_ = col; col = u_; }
          { short u0_ = ((col & 0) ? 0 : col); col = u0_; }  // Haelt die Register- und Stapelfolge wie im Original F12 Umlauf 1x col // Haelt die Register- und Stapelfolge wie im Original F12 tern
      }
      { short u0_ = mindest; mindest = u0_; } // Haelt die Register- und Stapelfolge wie im Original F12 Umlauf 1x mindest
      { int u_ = feld; feld = u_; }
    }
  }
}

//@ f_0730d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereinigt vor einer Wegfindung (f_074b40) die Arbeitskopie des Kampfrasters (*(p + 0x3d3)):
 *   Tote oder geflohene Kämpfer werden auf 0 (begehbar) gesetzt, während kampfunfähige oder für den aktuellen
 *   Suchmodus mode nicht als Ziel in Frage kommende Figuren als unpassierbares Hindernis 0xcc eingetragen
 *   werden.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p und den Wegfindungsmodus mode (short) und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Prüft Helden (c < 10) in d_1bc8f0 und Monster (10 <= c < 50, einschließlich
 *   zweifeldriger Rücksegmente c >= 30) in d_1c2ed4.
 === Ende Beschreibung === */
void f_0730d0(int p, short mode)
{
  struct HeroA6 { char raw[0x5ef]; };
  struct MonsterA6 { char raw[0x73]; };
  extern HeroA6 *heroesA6;
  #pragma aux heroesA6 "d_1bc8f0"
  extern MonsterA6 *monstersA6;
  #pragma aux monstersA6 "d_1c2ed4"
  extern char callA6_042470(HeroA6 *);
  #pragma aux callA6_042470 "f_042470"
  extern char callA6_0425f0(HeroA6 *);
  #pragma aux callA6_0425f0 "f_0425f0"
  extern char callA6_0424e0(HeroA6 *);
  #pragma aux callA6_0424e0 "f_0424e0"
  extern char callA6_0cfdc0(MonsterA6 *);
  #pragma aux callA6_0cfdc0 "f_0cfdc0"
  extern char callA6_0cfe30(MonsterA6 *);
  #pragma aux callA6_0cfe30 "f_0cfe30"
  extern int callA6_0d12e0(MonsterA6 *);
  #pragma aux callA6_0d12e0 "f_0d12e0"
  short y, x;
  if (mode != 8) {
    for (y = 0; y < (short)24; y++) {
      for (x = 0; x < 24; x++) {
        unsigned char c;
        c = (*(unsigned char **)(p + 0x3d3) + y * 25)[x];
        if (d_1bd928) f_069460();
        if (c <= 0) continue;
        if (c < 10 && (callA6_042470(heroesA6 + (c - 1)) || callA6_0425f0(heroesA6 + (c - 1)))) {
          (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0;
          continue;
        }
        if (c < 10 && callA6_0424e0(heroesA6 + (c - 1))) {
          (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
          continue;
        }
        if (c >= 10 && c < 50) {
          if (callA6_0cfdc0(monstersA6 + (c - 10 - (c >= 30 ? 20 : 0)))) {
            if (callA6_0d12e0(monstersA6 + (c - 10 - (c >= 30 ? 20 : 0))))
              (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
            else
              (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0;
          } else if (callA6_0cfe30(monstersA6 + (c - 10 - (c >= 30 ? 20 : 0)))) {
            (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
          }
        }
      }
    }
  } else {
    for (y = 0; y < (short)24; y++) {
      for (x = 0; x < 24; x++) {
        unsigned char c;
        c = (*(unsigned char **)(p + 0x3d3) + y * 25)[x];
        if (d_1bd928) f_069460();
        if (c <= 0) continue;
        if (c < 10 && (callA6_042470(heroesA6 + (c - 1)) || callA6_0425f0(heroesA6 + (c - 1)))) {
          (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0;
          continue;
        }
        if (c < 10 && !callA6_0424e0(heroesA6 + (c - 1))) {
          (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
          continue;
        }
        if (c >= 10 && c < 50) {
          if (callA6_0cfdc0(monstersA6 + (c - 10 - (c >= 30 ? 20 : 0)))) {
            if (callA6_0d12e0(monstersA6 + (c - 10 - (c >= 30 ? 20 : 0))))
              (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
            else
              (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0;
          } else {
            (*(volatile unsigned char **)(p + 0x3d3) + y * 25)[x] = 0xcc;
          }
        }
      }
    }
  }
}
//@ f_073410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft entlang einer zuvor mit f_0cdd50 berechneten Bresenham-Punktliste p4, ob zwischen
 *   Startfeld (p2, p3) und Zielpunkt eine freie Sicht- bzw. Schusslinie innerhalb der maximalen Reichweite p5
 *   besteht oder ob Hindernisse, große Objekte oder stehende Figuren die Linie blockieren.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, die Startkoordinaten p2 und p3, das Punkt-Array p4
 *   (short *, Ende -1) sowie die Reichweite p5 (short) und gibt 1 bei freier Sichtlinie oder 0 bei Blockade
 *   zurück.
 * - Wichtige Variablen: Liest für jeden Zwischenpunkt des Strahls den Rasterwert in d_1bd984 und prüft bei
 *   Objekten (0x32..0xc7) über f_07b580, ob man über sie hinwegschießen kann.
 === Ende Beschreibung === */
int f_073410(int p1, unsigned short p2, unsigned short p3, short *p4, short p5)
{
  struct H5ef { char b[0x5ef]; };
  struct M73 { char b[0x73]; };
  extern H5ef *p_1bc8f0;
  #pragma aux p_1bc8f0 "d_1bc8f0"
  extern M73 *p_1c2ed4;
  #pragma aux p_1c2ed4 "d_1c2ed4"
  extern int c_0d06c0(M73 *);
  #pragma aux c_0d06c0 "f_0d06c0"
  extern int c_0307d0(H5ef *);
  #pragma aux c_0307d0 "f_0307d0"
  extern int c_0d12e0(M73 *);
  #pragma aux c_0d12e0 "f_0d12e0"
  int ok = 1;
  short i;
  short r;
  short v;
  if (p4[2] == -1) return ok;
  i = 1;
  while (p4[2 + i * 2] != -1) {
      if (d_1bd928) f_069460();
      r = f_071e20(S(p2), S(p3), p4[i * 2], p4[i * 2 + 1]);
      v = *(d_1bd984 + p4[i * 2 + 1] * 0x19 + p4[i * 2]);
      if (v == 0xfd || (v == (short)10 && c_0d06c0(p_1c2ed4))) v = 0;
      if (r > 0 && r <= p5) {
        if ((v > (short)200 && v != 0xcd && v != (unsigned short)0xfe)
          || (v >= (short)0x32 && v < (short)200 && f_07b580(p1, (short)(v - 0x32)) == 0)
          || (v > 0 && v < (short)10 && c_0307d0(p_1bc8f0 + (v - 1)) == 0)
          || (v >= (short)10 && v < (short)0x1e && c_0d12e0(p_1c2ed4 + (v - 10)) != 0)
          || (v >= (short)0x1e && v < (short)0x32 && c_0d12e0(p_1c2ed4 + (v - 0x1e)) != 0)) {
          ok = 0;
          break;
        }
      } else if (r != 0) {
        ok = 0;
        break;
      }
      i++;
  }
  return ok;
}
//@ f_0735b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft für Spezialgegner mit mehreren Trefferfeldern (0xfd-Markierungen im Raster, z. B. der
 *   Riesendrache/Wurm), ob vom Feld (p2, p3) aus innerhalb der Reichweite p6 entweder das anvisierte Feld (*p4,
 *   *p5) selbst oder irgendein anderes 0xfd-Feld des Großgegners sichtbar bzw. angreifbar ist, und aktualisiert
 *   *p4, *p5 auf das getroffene Teilfeld.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, die Angreiferposition p2, p3, die Ein-/Ausgabezeiger p4,
 *   p5 der Zielkoordinate sowie die Reichweite p6 und gibt 1 bei Erfolg oder 0 zurück.
 * - Wichtige Variablen: Sucht bei verdecktem Hauptfeld alle Zellen mit Wert 0xfd in d_1bd984 ab.
 === Ende Beschreibung === */
int f_0735b0(int p1, short p2, short p3, short *p4, short *p5, short p6)
{
  struct Hilf {
    static int val(int a) { return a; }
    static int pruefe(int p1, short p2, short p4, short p3, short p5, short p6) {
      short r;
      if (p6 == 1) {
        if (p2 != p4 && p3 != S(p5)) r = 0;
        else {
          r = f_071e20(p2, p3, p4, S(p5));
          if (r > 1) r = 0; else r = 1;
        }
      } else {
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        f_0cdd50(p2, p3, p4, S(p5), p1 + 0x35b);
        r = f_073410(p1, p2, p3, (short *)(p1 + 0x35b), p6);
      }
      return r;
    }
    static int pruefe1(int p1, short p3, short p2, short p5, short p4, short p6) {
      short r;
      if (p6 == 1) {
        if (p2 != p4 && p3 != S(p5)) r = 0;
        else {
          r = f_071e20(p2, p3, p4, S(p5));
          if (r > 1) r = 0; else r = 1;
        }
      } else {
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p3=(p3 & 0)?(short)0:p3; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p2=(p2 & 0)?(short)0:p2; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p5=(p5 & 0)?(short)0:p5; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        p4=(p4 & 0)?(short)0:p4; // Haelt die Register- und Stapelfolge wie im Original: berechnete gemeinsame Sortierung
        f_0cdd50(p2, p3, p4, S(p5), p1 + 0x35b);
        r = f_073410(p1, p2, p3, (short *)(p1 + 0x35b), p6);
      }
      return r;
    }
  };
  short res;
  short x;
  short y;
  if (p6 == 1) {
    x = *p4;
    y = *p5;
    { short u_ = y; y = u_; }
    if (p2 != x && p3 != y) {
      res = 0;
    } else if (f_071e20(p2, p3, x, y) != 1) {
      res = 0;
    } else {
      res = 1;
      *p4 = x;
      *p5 = y;
    }
  } else {
    res = 0;
    x = *p4;
    y = *p5;
    { short u_ = y; y = u_; }
    if (Hilf::pruefe1(p1, p3, p2, y, x, p6))
      res = 1;
    if (Hilf::val(res))
      { short u = res; res = u; return res; }
    for (y = 0; y < (short)24; y++) {
      p2=(p2&0)?(short)0:p2; p6=(p6&0)?(short)0:p6; // Haelt die Register- und Stapelfolge wie im Original: getrennte p2-Nutzung
      if (!Hilf::val(res)) {
      p2=(p2&0)?(short)0:p2; p6=(p6&0)?(short)0:p6; // Haelt die Register- und Stapelfolge wie im Original: getrennte p2-Nutzung
        for (x = 0; x < 24; x++) {
          if ((d_1bd984 + y * 25)[x] == (char)0xfd) {
            { int q=d_1a27f4; d_1a27f4=q; } // Haelt die Register- und Stapelfolge wie im Original: codefreier Global-Roundtrip
            if (Hilf::pruefe(p1, p2, x, p3, y, p6)) {
              res = 1;
              *p4 = x;
              *p5 = y;
              break;
            }
          }
        }
      } else {
        break;
      }
    }
  }
  return res;
}

//@ f_073800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kapselt die allgemeine Angriffs- und Sichtlinienprüfung zwischen (p2, p3) und (p4, p5) für
 *   Reichweite p6: Bei Nahkampfreichweite (p6 == 1) müssen beide Felder orthogonal direkt benachbart sein
 *   (f_071e20 == 1), bei größerer Reichweite wird über f_0cdd50 und f_073410 die Sichtlinie geprüft.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, Startfeld p2, p3, Zielfeld p4, p5 sowie die Reichweite
 *   p6 (short) und gibt 1 (erreichbar) oder 0 (nicht erreichbar) zurück.
 * - Wichtige Variablen: Schreibt die Bresenham-Linie in den Puffer p1 + 0x35b.
 === Ende Beschreibung === */
int f_073800(int p1, short p2, short p3, short p4, short p5, short p6)
{
  short r;
  if (p6 == 1) {
    if (p2 != p4 && p3 != S(p5)) r = 0;
    else {
      r = f_071e20(p2, p3, p4, S(p5));
      if (r > 1) r = 0; else r = 1;
    }
  } else {
    f_0cdd50(p2, p3, p4, S(p5), p1 + 0x35b);
    r = f_073410(p1, p2, p3, (short *)(p1 + 0x35b), p6);
  }
  return r;
}
