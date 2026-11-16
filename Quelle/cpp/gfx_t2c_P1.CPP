/* === Beschreibung (Katalog) ===
 * Einheit gfx_t2c (099910-099da0)
 *
 * Überblick
 * Diese Einheit vervollständigt die Verwaltung des 25-teiligen Grafik-Caches (Cache1050) mit der
 * LRU-Verdrängungslogik (Least Recently Used), der Suche nach bereits geladenen Ressourcen, der Alterung der
 * Einträge und der Hauptzugriffsfunktion f_099b10.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 9/10 gleich (suche.py 30.10.2026, Basis gfx_t2c_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// P3 16/29 gleich (suche.py 25.10.2026, Basis gfx_t2_P1.CPP)
// P2 Koepfe Stufe 2 (Fable K): 10 gleich (vorher 10), Rest 750 (vorher 752)
// gfx.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x097700-0x09AF30
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_014a60();                                         // reg - stapel 0
int f_036ed0(int p1);                                   // reg eax stapel 0
int f_036ee0(int p1, int p2);                           // reg eax edx stapel 0
int f_040e90(int p1);                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax edx stapel 0
int f_043ac0(int p1, int p2);                           // reg eax edx stapel 0
int f_043ae0(int p1, int p2);                           // reg eax edx stapel 0
int f_043af0(int p1, int p2);                           // reg eax edx stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_0453e0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);// reg eax ebx ecx stapel 20
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fd00();                                         // reg - stapel 0
int f_05fd70(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05fe40(int p1);                                   // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_0937e0(int p1);                                   // reg eax stapel 0
int f_0938a0(int p1);                                   // reg eax stapel 0
int f_094330(int p1);                                   // reg eax stapel 0
int f_0945c0(int p1);                                   // reg eax stapel 0
int f_094c70(int p1);                                   // reg eax stapel 0
int f_094f40(int p1);                                   // reg eax stapel 0
int f_097600(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0b0a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0b0e20(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d2e70();                                         // reg - stapel 0
int f_0d2f90(int p1, int p2);                           // reg eax edx stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d3790();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
int f_0d3810();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e3430(int p1);                                   // reg eax stapel 0
int f_0e3580(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3970(int p1, int p2);                           // reg eax edx stapel 0
int f_0e39e0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e3ba0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0e4650(int p1);                                   // reg eax stapel 0
int f_0e9510(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0e95d0(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                           // reg eax edx stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
           // reg eax stapel 0
int f_145760(int p1, int p2);                           // reg eax edx stapel 0
int f_1481a0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_149cf0();                       // nicht in clobber.tsv
int f_149d20();                                         // reg - stapel 0
int f_149eb4(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_15689d(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_0e0011;                    // 0x0E0011
extern int d_0e0012;                    // 0x0E0012
extern int d_0e0015;                    // 0x0E0015
extern int d_1a3204;                    // 0x1A3204
extern int d_1a3205;                    // 0x1A3205
extern int d_1a3210;                    // 0x1A3210
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a34e4;                    // 0x1A34E4
extern int d_1a965c;                    // 0x1A965C
extern int d_1a9b9c;                    // 0x1A9B9C
extern int d_1baac0;                    // 0x1BAAC0
extern int d_1baf74;                    // 0x1BAF74
extern int d_1baf88;                    // 0x1BAF88
extern int d_1bc88c;                    // 0x1BC88C
extern int d_1bc8a0;                    // 0x1BC8A0
extern int d_1bc8f0;                    // 0x1BC8F0
extern int d_1bdbc4;                    // 0x1BDBC4
extern int d_1bdbc8;                    // 0x1BDBC8
extern int d_1bdbcc;                    // 0x1BDBCC
extern int d_1bdbd0;                    // 0x1BDBD0
extern int d_1bdbd4;                    // 0x1BDBD4
extern int d_1bdbd6;                    // 0x1BDBD6
extern int d_1bdbd8;                    // 0x1BDBD8
extern int d_1bdbda;                    // 0x1BDBDA
extern int d_1bdbdc;                    // 0x1BDBDC
extern int d_1bdbe4;                    // 0x1BDBE4
extern int d_1bdbe8;                    // 0x1BDBE8
extern int d_1bdbec;                    // 0x1BDBEC
extern int d_1bdcec;                    // 0x1BDCEC
extern int d_1bdcf0;                    // 0x1BDCF0
extern int d_1bf514;                    // 0x1BF514
                    // 0x1C2098
extern int d_1c2198;                    // 0x1C2198
extern int d_1c29c4;                    // 0x1C29C4
extern int d_1c29f0;                    // 0x1C29F0
extern int d_1c2be0;                    // 0x1C2BE0
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a34c4[];           // Text 0x1A34C4
extern const char d_1a9680[];           // Text 0x1A9680


#pragma inline_depth(20)
#define I(a) (*(int*)(a))
#define S(a) (*(short*)(a))
#define W(a) (*(unsigned short*)(a))
#define B(a) (*(unsigned char*)(a))
#define R(i,k) d_1a64fc[(i)*5+(k)]
#define VSL(o,k) (*(int*)(*(int*)((o)+0x14)+(k)))
typedef int (*FN1)(int);
typedef int (*FN3)(int,int,int);
struct RECB { char x[0x5ef]; };
struct KEY { unsigned a:8; unsigned b:8; unsigned c:16; };
int f_0995c0(int p1, struct KEY k);
int f_099a20(int p1, struct KEY k);
#define GT0(e) ((e) > 0)
#define SV(x) ((short)(x))
#define LI int
#define KA k.a
#define KB k.b
#define KINIT
extern short d_1a64fc[];
extern short d_1a6506, d_1a6508, d_1a650a, d_1a650c, d_1a650e;
extern short d_1bd760, d_1bd766;
extern unsigned short d_1bf4f0;
extern unsigned short d_1bd762;
extern signed char d_1c2a50, d_1a9692, d_1a9693, d_1a9694;
extern char d_1c21b4[];





short f_0c0020(int p1, int p2);
short f_0bf820(int, ...);
int f_099ef0(int, int, int);
#pragma aux f_099ef0 parm caller [] modify [eax ecx edx];
int f_144bf0(char *p1, char *p2);
int f_147c84(int p1, int p2, int p3);
int f_156870(int p1, int p2, int p3);
int f_098730(int p1);
int f_0e4370(int p1);
int f_0990b0(int p1, int p2, int p3);
void f_099560(int p1);
short f_099910(int p1);
//@ f_099910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht unter allen 25 Einträgen des Grafik-Caches den belegten Slot mit der niedrigsten
 *   Alterungspriorität (prio < best, oder ersatzweise den ersten Slot mit prio == 0xff), gibt dessen Speicher
 *   über f_099560 frei und liefert den freigewordenen Slot-Index zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Basisadresse p1 des Grafik-Caches und gibt den Index des
 *   verdrängten Slots (0 bis 24, bzw. -1 falls kein Slot belegt war) zurück (short).
 * - Wichtige Variablen: In jedem 39-Byte-Eintrag (Ent) gibt used (Offset 8) an, ob Pixeldaten geladen sind, und
 *   prio (Offset 0x26) speichert das aktuelle Alterungsgewicht (1 bis 255).
 === Ende Beschreibung === */
short f_099910(int p1)
{
    struct Ent { char pad4[4]; char pad8[4]; int used; char rest[0x1a]; unsigned char prio; };
    Ent *e = (Ent *)p1;
    unsigned char best = 0xff;
    short k = -1, i;
    for (i = 0; i < 25; i++) {
        if (e[i].prio < best && e[i].used != 0) {
            k = i;
            best = e[i].prio;
        }
    }
    if (k == -1) {
        for (i = 0; i < 25; i++) {
            if (e[i].prio == 0xff && e[i].used != 0) {
                k = i;
                break;
            }
        }
    }
    { int o = (short)(k & 0xffff) /* haelt die 16-Bit-Erweiterung vor der Multiplikation wie im Original */ * 0x27; f_099560((int)e + 4 + o); *((unsigned char *)e + o + 0x26) = 0; }
    return k;
}

//@ f_0999a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt alle belegten Slots des Grafik-Caches frei, deren Alterungspriorität bereits unter den
 *   Maximalwert 0xff gefallen ist, sodass nur die im aktuellen Schritt frisch benutzten Grafiken im Speicher
 *   verbleiben.
 * - Eingaben und Rückgabe: Die Funktion erhält die Basisadresse p1 des Grafik-Caches und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Byte B(iVar1 + 0x26) enthält die Alterungspriorität des jeweiligen Slots.
 === Ende Beschreibung === */
void f_0999a0(int p1)
{
  int iVar2, iVar1;
  LI s;
  for (s = 0; SV(s) < 0x19; s++) {
    iVar2 = SV(s) * 0x27;
    iVar1 = p1 + iVar2;
    if ((B(iVar1+0x26) != 0xff) && (I(iVar1+8) != 0)) {
      f_099560(p1 + 4 + iVar2);
      B(iVar1+0x26) = 0;
    }
  }
}
//@ f_0999f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt sämtliche belegten Slots des Grafik-Caches p1 ohne Rücksicht auf ihre Alterungspriorität
 *   über f_099560 frei.
 * - Eingaben und Rückgabe: Die Funktion erhält die Basisadresse p1 des Grafik-Caches und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die Schleife prüft für alle 25 Slots (0 bis 0x18), ob I(iVar1 + 8) != 0 ist.
 === Ende Beschreibung === */
void f_0999f0(int p1)
{
  int iVar1, iVar2;
  LI s;
  for (s = 0; SV(s) < 0x19; s++) {
    iVar2 = SV(s) * 0x27;
    iVar1 = p1 + iVar2;
    if (I(iVar1+8) != 0) {
      f_099560(p1 + 4 + iVar2);
      B(iVar1+0x26) = 0;
    }
  }
}
//@ f_099a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht die 25 Slots des Grafik-Caches nach einem belegten Eintrag, dessen gespeicherter
 *   Ressourcenschlüssel an Offset 0x27 mit dem gesuchten Schlüssel k übereinstimmt.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 sowie den Ressourcenschlüssel k (struct KEY)
 *   und gibt den gefundenen Slot-Index (0 bis 24) oder -1 bei Nichtfinden zurück (int).
 * - Wichtige Variablen: Der Schlüsselvergleich prüft die beiden Teilfelder a (Archiv-/Typkennung) und b
 *   (Eintragsnummer) bei gleichzeitig belegtem Datenzeiger I(iVar2 + 8) != 0.
 === Ende Beschreibung === */
int f_099a20(int p1, struct KEY k)
{
  int bVar1, iVar2, iVar3;
  unsigned ka, kb;
  KINIT
  bVar1 = 0;
  for (iVar3 = 0; (short)iVar3 < 0x19; iVar3 = iVar3 + 1) {
    iVar2 = (short)iVar3 * 0x27 + p1;
    if ((((struct KEY *)(iVar2+0x27))->a == KA) &&
        (((struct KEY *)(iVar2+0x27))->b == KB) &&
        (I(iVar2+8) != 0)) {
      bVar1 = 1;
      break;
    }
  }
  return (!bVar1) ? -1 : iVar3;
}
//@ f_099a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob im Grafik-Cache p1 mindestens ein freier Slot (I(s * 0x27 + 8 + p1) == 0) vorhanden
 *   ist, und gibt andernfalls vorsorglich den ältesten Eintrag über f_099910 frei.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag bVar1 vermerkt, ob ein freier Slot gefunden wurde.
 === Ende Beschreibung === */
void f_099a90(int p1)
{
  int bVar1;
  short s;
  bVar1 = 0;
  for (s = 0; s < 0x19; s++) {
    if (I(s * 0x27 + 8 + p1) == 0) {
      bVar1 = 1;
      break;
    }
  }
  if (!bVar1) {
    f_099910(p1);
  }
}
//@ f_099ad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert die Alterungspriorität (B(iVar1 + 0x26)) aller belegten Cache-Slots mit Ausnahme
 *   des aktuell genutzten Slots p2 um 1, sofern die Priorität noch größer als 1 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält die Cache-Adresse p1 sowie den von der Alterung auszunehmenden
 *   Slot-Index p2 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Mindestpriorität eines belegten Eintrags bleibt auf 1 begrenzt, damit 0 für
 *   unbenutzte Einträge reserviert bleibt.
 === Ende Beschreibung === */
void f_099ad0(int p1, int p2)
{
  int iVar1;
  short s;
  for (s = 0; s < 0x19; s++) {
    if (s != (short)p2) {
      iVar1 = s * 0x27 + p1;
      if ((B(iVar1+0x26) != 1) && (I(iVar1+8) != 0)) {
        B(iVar1+0x26) = B(iVar1+0x26) - 1;
      }
    }
  }
}
#pragma inline_depth(20)
struct Key1050 {
  unsigned archive:8, type:8, frame:16;
  void unpack(unsigned raw) {
    archive=(raw&0xff000000)>>24;
    type=(raw&0x00ff0000)>>16;
    frame=((unsigned short)raw-1)&0xffff;
  }
};
struct Cache1050;
int find1050(Cache1050 *,Key1050);
#pragma aux find1050 "f_099a20";
short discard1050(Cache1050 *);
#pragma aux discard1050 "f_099910";
struct Image1050;
int decode1050(Image1050 *,Key1050);
#pragma aux decode1050 "f_0995c0";
struct Image1050 {
  void *owner, *pixels;
  int *frames;
  short height;
  void *a,*b;
  short flags;
  void *c,*d;
  short count;
  void clear(void *source) {
    pixels=0;frames=0;count=0;height=0;a=0;b=0;flags=0;c=0;d=0;owner=source;
  }
  int load(Key1050 k,void *source) { clear(source); return decode1050(this,k); }
  int get(Key1050 k) { return frames[k.frame]; }
};
struct Record1050 { Image1050 image; unsigned char age; Key1050 key; };
struct Cache1050 {
  void *source;
  Record1050 entries[25];
  short reserve() {
    short i; int available=0;
    for(i=0;i<25;++i) if(entries[i].image.pixels==0) { available=1;break; }
    if(!available) i=discard1050(this);
    return i;
  }
  void populate(Key1050 k,short slot) { Record1050 *base=entries; base=((int)base&0)?0:base; /* haelt den Basiszeiger im Register wie im Original */ while(!base[slot].image.load(k,source)) discard1050(this); }
  void age(short except) {
    short i;
    for(i=0;i<25;++i) {
      if(i==except || entries[i].age==1 || entries[i].image.pixels==0) continue;
      --entries[i].age;
    }
  }
  static void tick1050(short except,Cache1050 *cache) {
    short i;
    for(i=0;i<25;++i) {
      if(i==except || cache->entries[i].age==1 || cache->entries[i].image.pixels==0) continue;
      --cache->entries[i].age;
    }
  }
  int f_099b10(unsigned raw);
};
//@ f_099b10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert zu einer gepackten 32-Bit-Grafikkennung raw die Speicheradresse des gewünschten
 *   Einzelbildes aus dem Grafik-Cache this. Ist die Grafiksequenz noch nicht im Cache vorhanden, reserviert die
 *   Methode einen freien (oder verdrängten) Slot, lädt die Sequenz nach, setzt ihre Priorität auf 255 und lässt
 *   alle übrigen Einträge altern.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger des Cache1050-Objekts sowie die gepackte
 *   Ressourcenkennung raw (unsigned) und gibt die Adresse des Einzelbildes zurück (int).
 * - Wichtige Variablen: Der Schlüssel k (Key1050) zerlegt raw in die Archivnummer (Bits 24..31), den Typ (Bits
 *   16..23) und den nullbasierten Einzelbildindex ((raw & 0xffff) - 1).
 === Ende Beschreibung === */
int Cache1050::f_099b10(unsigned raw) {
    Key1050 k;
    k.archive=(raw&0xff000000)>>24;
    k.type=(raw&0x00ff0000)>>16;
    k.frame=((unsigned short)raw-1)&0xffff;
    short selected=find1050(this,k);
    if(selected==-1) {
      selected=reserve();
      populate(k,selected);
      entries[selected].age=255;
      entries[selected].key=k;
      tick1050(selected,this);
    }
    if(entries[selected].age!=255) age(selected);
    entries[selected].age=255;
    return entries[selected].image.get(k);
  }

#pragma inline_depth(20)
//@ f_099d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ruft den Watcom-Array-Destruktor f_156870 für die 25 Einträge eines Grafik-Caches auf.
 * - Eingaben und Rückgabe: Die Funktion erhält die Array-Adresse p1 sowie ein ungenutztes Flag p2 und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Der Deskriptor d_1baf74 beschreibt den Destruktor der einzelnen Record1050-Elemente.
 === Ende Beschreibung === */
void f_099d20(int p1, int p2)
{
  f_156870(p1, 0x19, (int)&d_1baf74);
}
//@ f_099d40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Speicherblöcke eines einzelnen Image1050-Eintrags über f_099560 frei und gibt dessen
 *   Adresse zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Eintragsadresse p1 sowie ein ungenutztes Flag kp2 und gibt p1
 *   zurück (int).
 * - Wichtige Variablen: Die Funktion ist ein Destruktor-Wrapper um f_099560.
 === Ende Beschreibung === */
int f_099d40(int p1, int kp2)
{
  f_099560(p1);
  return p1;
}
//@ f_099d50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt sämtliche Felder eines Image1050-Eintrags bei der Konstruktion auf 0.
 * - Eingaben und Rückgabe: Die Funktion erhält die Eintragsadresse p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion entspricht im Aufbau dem Standardkonstruktor f_0994b0.
 === Ende Beschreibung === */
void f_099d50(int p1)
{
  I(p1) = 0;
  I(p1+4) = 0;
  I(p1+8) = 0;
  S(p1+0x20) = 0;
  S(p1+0xc) = 0;
  I(p1+0xe) = 0;
  I(p1+0x12) = 0;
  S(p1+0x16) = 0;
  I(p1+0x18) = 0;
  I(p1+0x1c) = 0;
}
