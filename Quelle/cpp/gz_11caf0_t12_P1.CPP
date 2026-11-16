/* === Beschreibung (Katalog) ===
 * Einheit gz_11caf0_t12 (0x11caf0 - 0x11e500)
 *
 * Überblick
 * Diese Einheit implementiert das System der zufälligen Straßenbegegnungen, Alltagsereignisse und
 * Gruppenkommentare beim Spaziergang durch die Stadt Riva (street.cpp, Textgruppe 0x16000001 bis 0x1600005d).
 * Sie umfasst die Registrierung der zugehörigen Spielstands-Flags, Hilfsfunktionen zur Auswahl passender
 * Gruppenmitglieder (z. B. Elfen, Zwerge, Magier oder weibliche/männliche Helden), die 20 konkreten
 * Straßenereignisse (Bettler, Taschendiebe, Marktschreier, Regenschauer, Gaukler usw.) sowie die Auswahl- und
 * Sperrlogik, die verhindert, dass dasselbe Straßenereignis unmittelbar hintereinander wiederholt wird.
 === Ende Beschreibung === */
#include "R_FIX.H"
#include "RIVACTX.H"
#include "RIVACDAT.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// gz_11caf0_t1.cpp (Schatten ueber Riva) - Pass 1, Code 0x11CAF0-0x11E240
#include <string.h>
int f_038be0(int p1);
int f_038c40(int p1);
int f_038c80(int p1);
int f_038cb0(int p1);
int f_0391b0(int p1, int p2);
int f_039320(int p1, int p2);
int f_039a80(int p1, int p2);
int f_039ac0(int p1, int p2);
int f_040a00(int p1, int p2, int p3);
int f_040a40(int p1);





int f_043e20(int p1, int p2);
int f_044850(int p1, int p2, int p3);
short f_044900(int p1, int p2, int p3);
short f_044c90(int p1, int p2, int p3);
int f_0bf6f0(const char *p1, int p2);
int f_0bf730(const char *p1, int p2);
short f_0bf820(const char *p1, ...);
int f_0d49b0(int p1);
int f_0d4a60(int p1);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
int f_0db8b0(int p1, int p2);
short f_0dbfe0(int p1);
int f_0dbe20(int p1, int p2, int p3);
short f_0dc050(int p1, int p2, int p3);
int f_0dd3a0(int p1, int p2, int p3);
int f_0de7d0(int p1, int p2);
int f_0de7e0(int p1);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(const char *p1, int p2);
int f_125f70(const char *p1, int p2);
int f_126410(const char *p1);
short f_1457e0(int p1);
extern signed char d_1bcaa0;
extern int d_1c0004;
extern signed char d_1c0a28;
extern signed char d_1c0a2c;
extern signed char d_1c0a30;
extern signed char d_1c0a34;
extern signed char d_1c0a38;
extern signed char d_1c0d64;
extern short d_1c212a;
extern int *d_1c212c;
extern char d_1c2c44[];
extern char d_1c2c64[];
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
#define EQ(x,v) (((x)==(v))?1:0)
#define HI(x) ((x) <= 0x190c8)
#define HI2(x) ((x) <= 0x1d010)
#define LO2(x) ((x) <= 0x93a8)
#define SC(s) ((s) <= 0x32)
#define Z42380(p) (f_042380((struct hero *)(p)) == 0)
#define SETC(c,u) c = f_042380((struct hero *)(u))
#define KC(c) (c != 0)
#define W16(a) (*(unsigned short *)(a))
typedef RivaTextContextData OB;
#define CTOR(o) f_125400(&(o), d_1c349c, d_1c3870, d_1c3498)
#define DTOR(o) f_1254a0(&(o), 0)
#define RANGE (f_126410(d_1c2c44) > 0x93a8 && HI(f_126410(d_1c2c44)))
#define PL(k,v) f_0d5040(p1, f_0d4c80(p1), 0x1518, k, v, 0)

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_11caf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Einfache Lese-Hilfsfunktion, die den 32-Bit-Wert an der übergebenen Adresse zurückgibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf einen 32-Bit-Ganzzahlwert.
 * - Rückgabewert: Die Funktion gibt den gelesenen Wert *p1 zurück.
 === Ende Beschreibung === */
int f_11caf0(int *p1)
{
  return *p1;
}
//@ f_11cb00
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die persistenten Flags der städtischen Straßenbegegnungen (d_1c0a28 bis d_1c0a38) in der
 *   globalen Spielstands-Tabelle (d_1c212a).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
struct Obj11 { signed char a; short b; };
struct Reg11 { short count; Obj11 **list; };
extern Obj11 d_o28, d_o2c, d_o30, d_o34, d_o38;
extern Reg11 d_r11;
#pragma aux d_o28 "d_1c0a28"
#pragma aux d_o2c "d_1c0a2c"
#pragma aux d_o30 "d_1c0a30"
#pragma aux d_o34 "d_1c0a34"
#pragma aux d_o38 "d_1c0a38"
#pragma aux d_r11 "d_1c212a"
inline signed char z_11cb00()
{
    signed char c = 0;
    return c;
}
inline void add_11cb00(Obj11 &o, Reg11 &r, short id)
{
    o.a = z_11cb00();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
void f_11cb00(void)
{
    add_11cb00(d_o28, d_r11, 0x1c);
    add_11cb00(d_o2c, d_r11, 0x1e9);
    add_11cb00(d_o30, d_r11, 0x1ea);
    short n = d_r11.count;
    signed char c = 0;
    d_o34.b = 0x1eb;
    d_o34.a = c;
    d_r11.list[n] = &d_o34;
    d_r11.count++;
    d_o38.a = c;
    d_o38.b = 0x1ec;
    d_r11.list[d_r11.count] = &d_o38;
    d_r11.count++;
}
//@ f_11cc00
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion für die Heldensuche, die prüft, ob ein Held handlungsfähig ist und keine speziellen
 *   Einschränkungen (f_042900 == 0) aufweist.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held die Bedingung erfüllt, sonst 0.
 === Ende Beschreibung === */
int f_11cc00(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (f_042900((struct hero *)(p1)) == 0) r = 1;
  }
  return r;
}
//@ f_11cc30
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion für die Heldensuche, die prüft, ob ein handlungsfähiger Held weiblich ist (f_042380 ==
 *   1).
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 bei einem weiblichen handlungsfähigen Helden zurück, sonst 0.
 === Ende Beschreibung === */
int f_11cc30(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (f_042380((struct hero *)(p1)) == 1) r = 1;
  }
  return r;
}
//@ f_11cc60
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der Heldengruppe nach einer geeigneten Zielperson für ein Straßenereignis (bevorzugt einen
 *   weiblichen Helden des Archetyps 6, ersatzweise einen beliebigen weiblichen Helden, einen Elfen oder einen
 *   zufälligen Helden).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den ausgewählten Helden zurück.
 === Ende Beschreibung === */
int f_11cc60(void)
{
  int p1 = f_038c80(d_1c0004);
  int r = 0;
  do {
    if (f_0d4a60(p1) != 0) {
      if (f_042350((struct hero *)(p1)) == 6) {
        if (f_042380((struct hero *)(p1)) == 1) r = p1;
      }
    }
    p1 = f_0391b0(d_1c0004, p1);
  } while (p1 != f_038c80(d_1c0004) && r == 0);
  if (r == 0) {
    r = f_039ac0(d_1c0004, (int)f_11cc30);
    if (r == 0) {
      r = f_0dd3a0(d_1c0004, 9, 0);
      if (r == 0) {
        r = f_0dd3a0(d_1c0004, 8, 0);
        if (r == 0) r = f_038be0(d_1c0004);
      }
    }
  }
  return r;
}
//@ f_11cd20
/* === Beschreibung (Katalog) ===
 * - Zweck: Prüft bei schlechtem Wetter oder Durchnässung mit einer Wahrscheinlichkeit von 10 Prozent, ob ein
 *   ungeschützter Held nach einer misslungenen Selbstbeherrschungs-/Konstitutionsprobe (0x12) erkrankt
 *   (f_040a40), und gibt gegebenenfalls eine Krankheitsmeldung (0x1b000001) aus.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf den geprüften Helden.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11cd20(int p1)
{
  short s = f_1457e0(100);
  if (s <= 10) {
    if (f_0d4a60(p1) != 0) {
      if (f_042950((struct hero *)(p1)) == 0) {
        short t = f_044c90(p1, 0x12, 0);
        if (t <= 0) {
          OB ob;
          CTOR(ob);
          *(int *)(ob.addresses.objects + 4) = p1;
          f_0bf730(d_1c2c64, 0x1b000001);
          f_040a40(p1);
          DTOR(ob);
        }
      }
    }
  }
}
//@ f_11cdb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion, die prüft, ob ein handlungsfähiger Held nicht der Gruppenanführer und weiblichen
 *   Geschlechts ist.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Bedingungen zutreffen, sonst 0.
 === Ende Beschreibung === */
int f_11cdb0(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (p1 != f_038c40(d_1c0004)) {
      if (f_042380((struct hero *)(p1)) == 1) {
        if (f_0d4a60(p1) != 0) r = 1;
      }
    }
  }
  return r;
}
//@ f_11ce00
/* === Beschreibung (Katalog) ===
 * - Zweck: Filterfunktion, die prüft, ob ein handlungsfähiger Held nicht der Gruppenanführer und männlichen
 *   Geschlechts ist.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die Bedingungen zutreffen, sonst 0.
 === Ende Beschreibung === */
int f_11ce00(int p1)
{
  int r = 0;
  if (f_0d4a60(p1) == 1) {
    if (p1 != f_038c40(d_1c0004)) {
      if (Z42380(p1)) {
        if (f_0d4a60(p1) != 0) r = 1;
      }
    }
  }
  return r;
}
//@ f_11ce50
/* === Beschreibung (Katalog) ===
 * - Zweck: Sucht in der Gruppe nach einem Zwerg (Archetyp 7) und gibt ersatzweise den Gruppenanführer zurück.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt den Zeiger auf den gefundenen Zwerg oder den Gruppenanführer zurück.
 === Ende Beschreibung === */
int f_11ce50(void)
{
  int r = f_0dd3a0(d_1c0004, 7, 0);
  if (r != 0 && f_0d4a60(r) != 0) return r;
  return f_038c40(d_1c0004);
}
//@ f_11ce90
/* === Beschreibung (Katalog) ===
 * - Zweck: Zählt die männlichen und weiblichen handlungsfähigen Gruppenmitglieder und stellt fest, ob mehr
 *   Frauen als Männer in der Gruppe sind.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn die weiblichen Helden in der Überzahl sind, andernfalls 0.
 === Ende Beschreibung === */
int f_11ce90(void)
{
  int p1 = f_038c80(d_1c0004);
  int r = 0;
  short a = 0;
  short b = 0;
  do {
    if (f_0d4a60(p1) != 0) {
      if (Z42380(p1)) b = b + 1;
      else a = a + 1;
    }
    p1 = f_0391b0(d_1c0004, p1);
  } while (p1 != f_038c80(d_1c0004));
  if (a > b) r = 1;
  return r;
}
//@ f_11cf00
/* === Beschreibung (Katalog) ===
 * - Zweck: Heilt oder regeneriert bei einem lebenden Gruppenmitglied eine kleine Menge Lebens-/Ausdauerpunkte
 *   (f_040a00(p1, 2, 5)), etwa nach dem Kauf einer warmen Mahlzeit am Straßenstand.
 * - Eingaben: Die Funktion erhält im Parameter p1 den Zeiger auf einen Helden.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11cf00(int p1)
{
  if (f_0d49b0(p1) != 0) f_040a00(p1, 2, 5);
}
//@ f_11cf30
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 1: Bietet der Gruppe tagsüber an einem Straßenstand den Kauf von Erfrischungen oder
 *   Speisen an, zieht den Preis ab, modifiziert kurzzeitig Eigenschaftswerte eines Helden und gibt Proviant aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11cf30(void)
{
  OB ob;
  int iVar2, iVar3, p2;
  short n, n2, n3;
  if (f_126410(d_1c2c44) > 0x93a8) {
    if (HI(f_126410(d_1c2c44))) {
      n3 = n2 = n = f_0dbfe0(d_1c0004);
      iVar2 = f_039ac0(d_1c0004, (int)f_11cc00);
      iVar3 = f_038be0(d_1c0004);
      CTOR(ob);
      if (1 < n2) {
        while (iVar3 == iVar2) iVar3 = f_038be0(d_1c0004);
      }
      *(int *)(ob.addresses.objects + 4) = iVar2;
      *(int *)(ob.addresses.objects + 8) = iVar3;
      p2 = n3;
      iVar3 = f_0de7e0(d_1c0004);
      if (iVar3 >= p2) {
        if (f_0bf6f0(d_1c2c64, 0x16000001) == 1) {
          int p1 = iVar2;
          f_0db8b0(d_1c0004, p2);
          f_0bf730(d_1c2c64, 0x16000002);
          if (iVar2 != 0) {
            f_0bf730(d_1c2c64, 0x16000003);
            f_043e20(iVar2, 1);
            PL(2, -1);
            PL(3, -1);
            PL(4, -1);
            PL(6, -1);
            PL(9, 1);
            PL(8, 1);
            PL(0xd, 1);
            f_043e20(iVar2, 0);
            if (1 < n) f_0bf730(d_1c2c64, 0x16000004);
          }
          f_0dbe20(d_1c0004, 0x14, 0);
        }
      }
      DTOR(ob);
    }
  }
}
//@ f_11d160
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 2: Gibt tagsüber eine kurze atmosphärische Beobachtungsmeldung (0x16000005) für den
 *   Gruppenanführer aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d160(void)
{
  OB ob;
  int u;
  if (f_126410(d_1c2c44) > 0x93a8) {
    if (HI(f_126410(d_1c2c44))) {
      u = f_038c40(d_1c0004);
      CTOR(ob);
      *(int *)(ob.addresses.objects + 4) = u;
      f_0bf730(d_1c2c64, 0x16000005);
      DTOR(ob);
    }
  }
}
//@ f_11d1e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 3: Spielt tagsüber einmalig (d_1c0a2c) einen kurzen Wortwechsel zwischen dem
 *   Gruppenanführer und einem Begleiter (0x16000006 bis 0x1600000a) ab.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d1e0(void)
{
  OB ob;
  int u, p1;
  short n;
  if (f_126410(d_1c2c44) > 0x93a8) {
    if (HI(f_126410(d_1c2c44)) && EQ(d_1c0a2c, 0)) {
      n = f_0dbfe0(d_1c0004);
      u = f_038c40(d_1c0004);
      p1 = f_038cb0(d_1c0004);
      CTOR(ob);
      if (f_042400((struct hero *)(p1)) != 0) p1 = u;
      *(int *)(ob.addresses.objects + 4) = u;
      *(int *)(ob.addresses.objects + 8) = p1;
      f_0bf730(d_1c2c64, 0x16000006);
      f_0bf730(d_1c2c64, 0x16000007);
      f_0bf730(d_1c2c64, (n <= 1) + 0x16000008);
      f_0bf730(d_1c2c64, 0x1600000a);
      d_1c0a2c = 1;
      DTOR(ob);
    }
  }
}
//@ f_11d300
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 4: Lässt nachts einmalig (d_1c0a30) eine zweistufige nächtliche Begegnung (0x1600000b
 *   bis 0x16000012) ablaufen, sofern das Ereignis d_1c0d64 noch nicht eingetreten ist.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d300(void)
{
  OB ob;
  int u;
  if (EQ(d_1c0d64, 0) && EQ(d_1c0a30, 0)) {
    if (RANGE) return;
    u = f_038c40(d_1c0004);
    CTOR(ob);
    *(int *)(ob.addresses.objects + 4) = u;
    if (f_0bf820(d_1c2c64, 0x1600000b, 2, 0x1600000c, 0x1600000d) == 1
        && f_0bf820(d_1c2c64, 0x1600000e, 2, 0x1600000f, 0x16000010) == 1) {
      f_0bf730(d_1c2c64, 0x16000011);
      f_0bf730(d_1c2c64, 0x16000012);
      d_1c0a30 = 1;
    }
    DTOR(ob);
  }
}
//@ f_11d410
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 5: Spielt nachts die Fortsetzung der nächtlichen Begegnung (d_1c0a34, Texte
 *   0x16000013 bis 0x16000016) ab, nachdem Teil 1 (d_1c0a30) erlebt wurde.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d410(void)
{
  OB ob;
  int u, v;
  short n;
  if (EQ(d_1c0d64, 0) && EQ(d_1c0a30, 1) && EQ(d_1c0a34, 0)) {
    if (RANGE) return;
    n = f_0dbfe0(d_1c0004);
    u = f_038c40(d_1c0004);
    v = f_038be0(d_1c0004);
    CTOR(ob);
    if (1 < n) {
      while (v == u) v = f_038be0(d_1c0004);
    }
    *(int *)(ob.addresses.objects + 4) = u;
    *(int *)(ob.addresses.objects + 8) = v;
    f_0bf730(d_1c2c64, 0x16000013);
    f_0bf730(d_1c2c64, 0x16000014);
    f_0bf730(d_1c2c64, 0x16000015);
    if (1 < n) f_0bf730(d_1c2c64, 0x16000016);
    d_1c0a34 = 1;
    DTOR(ob);
  }
}
//@ f_11d550
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 6: Spielt nachts den dritten Teil der nächtlichen Begegnungsreihe (d_1c0a38, Texte
 *   0x16000017 bis 0x16000019) ab, nachdem Teil 2 (d_1c0a34) stattgefunden hat.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d550(void)
{
  OB ob;
  int u, v;
  short n;
  if (EQ(d_1c0d64, 0) && EQ(d_1c0a34, 1) && EQ(d_1c0a38, 0)) {
    if (RANGE) return;
    n = f_0dbfe0(d_1c0004);
    u = f_038c40(d_1c0004);
    v = f_038be0(d_1c0004);
    CTOR(ob);
    if (1 < n) {
      while (v == u) v = f_038be0(d_1c0004);
    }
    *(int *)(ob.addresses.objects + 4) = u;
    *(int *)(ob.addresses.objects + 8) = v;
    f_0bf730(d_1c2c64, 0x16000017);
    f_0bf730(d_1c2c64, 0x16000018);
    if (1 < n) f_0bf730(d_1c2c64, 0x16000019);
    d_1c0a38 = 1;
    DTOR(ob);
  }
}
//@ f_11d680
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 7: Wählt nach der Prioritätslogik aus f_11cc60 ein Gruppenmitglied aus und gibt eine
 *   zweigeteilte Straßenszene (0x1600001a, 0x1600001b) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d680(void)
{
  OB ob;
  int p1, r;
  if (!EQ(d_1bcaa0, 0)) return;
  if (RANGE) {
    if (LO2(f_126410(d_1c2c44))) return;
    if (f_126410(d_1c2c44) > 0x190c8) return;
    if (f_1457e0(100) > 0x32) return;
  }
  p1 = f_038c80(d_1c0004);
  r = 0;
  do {
    if (f_0d4a60(p1) != 0 && f_042350((struct hero *)(p1)) == 6 && f_042380((struct hero *)(p1)) == 1) r = p1;
    p1 = f_0391b0(d_1c0004, p1);
  } while (p1 != f_038c80(d_1c0004) && r == 0);
  if (r == 0 && (r = f_039ac0(d_1c0004, (int)f_11cc30)) == 0
      && (r = f_0dd3a0(d_1c0004, 9, 0)) == 0
      && (r = f_0dd3a0(d_1c0004, 8, 0)) == 0) r = f_038be0(d_1c0004);
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = r;
  f_0bf730(d_1c2c64, 0x1600001a);
  f_0bf730(d_1c2c64, 0x1600001b);
  DTOR(ob);
}
//@ f_11d800
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 8: Lässt den Gruppenanführer in ein Missgeschick auf der Straße geraten (0x1600001c,
 *   0x1600001d), das für einige Zeit einen Abzug von 3 Punkten auf den Charisma-/Auftretenswert (2) bewirkt.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d800(void)
{
  OB ob;
  int p1;
  if (!EQ(d_1bcaa0, 0)) return;
  if (RANGE || f_1457e0(100) > 0x3c) {
    if (LO2(f_126410(d_1c2c44))) return;
    if (f_126410(d_1c2c44) > 0x190c8) return;
    if (f_1457e0(100) > 0x14) return;
  }
  p1 = f_038c40(d_1c0004);
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = p1;
  f_0bf730(d_1c2c64, 0x1600001c);
  f_0d5040(p1, f_0d4c80(p1), 0x2a30, 2, -3, 0);
  f_0bf730(d_1c2c64, 0x1600001d);
  DTOR(ob);
}
//@ f_11d910
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 9: Prüft den Gruppenanführer auf Gefahreninstinkt und Sinnesschärfe (Talente 6 und 4)
 *   und lässt ihn bei Misslingen beider Proben Schaden oder einen Abzug erleiden (0x1600001f), während er die
 *   Gefahr sonst rechtzeitig bemerkt (0x16000020).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11d910(void)
{
  OB ob;
  int p1;
  short s, t;
  if (!EQ(d_1bcaa0, 0)) return;
  if (RANGE) {
    if (LO2(f_126410(d_1c2c44))) return;
    if (f_126410(d_1c2c44) > 0x190c8) return;
    if (f_1457e0(100) > 0x32) return;
  }
  p1 = f_038c40(d_1c0004);
  s = f_044900(p1, 6, 0);
  t = f_044900(p1, 4, 0);
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = p1;
  f_0bf730(d_1c2c64, 0x1600001e);
  if (s <= 0 && t <= 0) {
    f_0bf730(d_1c2c64, 0x1600001f);
    f_044850(p1, 5, 1);
  } else {
    f_0bf730(d_1c2c64, 0x16000020);
  }
  DTOR(ob);
}
//@ f_11da40
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 10: Bietet der Gruppe in den Abendstunden (zwischen 16:00 und 22:00 Uhr) an, vier
 *   Stunden im Freien zu verweilen oder einem Schauspiel zuzusehen, wobei die Zeit um 4 Stunden vorgespult und
 *   für jedes Gruppenmitglied stündlich das Erkältungsrisiko (f_11cd20) geprüft wird.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
extern char d_11cd20[];
void f_11da40(void)
{
  OB ob;
  int p1;
  short s;
  if (!EQB(d_1bcaa0, 0)) return;
  if (RANGE) {
    if (LO2(f_126410(d_1c2c44))) return;
    if (f_126410(d_1c2c44) > 0x190c8) return;
    if (f_1457e0(100) > 0x32) return;
  }
  if (f_126410(d_1c2c44) < 0x15180 || !HI2(f_126410(d_1c2c44))) return;
  p1 = f_038c40(d_1c0004);
  s = 4;
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = p1;
  f_0bf730(d_1c2c64, 0x16000021);
  if (f_0bf820(d_1c2c64, 0x16000022, 2, 0x16000023, 0x16000024) == 1) {
    int fn = (int)d_11cd20;
    f_0bf730(d_1c2c64, 0x16000025);
    while ((int)s > 0) {
      f_125f70(d_1c2c44, 1);
      f_039a80(d_1c0004, fn);
      s--;
    }
    f_0bf730(d_1c2c64, 0x16000026);
  } else {
    f_0bf730(d_1c2c64, 0x16000027);
  }
  DTOR(ob);
}
//@ f_11dbb0
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 11: Gibt mit 50 Prozent Wahrscheinlichkeit eine geschlechtsabhängige Neckerei oder
 *   Beobachtung zwischen dem Gruppenanführer und einem Gruppenmitglied des jeweils anderen Geschlechts
 *   (0x16000028 bis 0x1600002d) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11dbb0(void)
{
  OB ob;
  int u, r, m;
  short c, s;
  u = f_038c40(d_1c0004);
  SETC(c, u);
  CTOR(ob);
  s = f_1457e0(100);
  if (SC(s)) {
    if (!c) r = f_039ac0(d_1c0004, (int)f_11cdb0);
    else r = f_039ac0(d_1c0004, (int)f_11ce00);
    *(int *)(ob.addresses.objects + 4) = u;
    *(int *)(ob.addresses.objects + 8) = r;
    *(int *)(ob.addresses.numbers + 4) = 0x16000028;
    if (!c) m = 0x16000029;
    else m = 0x1600002c;
    f_0bf730(d_1c2c64, m);
    if (r != 0) f_0bf730(d_1c2c64, 0x1600002a);
    if (!c) m = 0x1600002b;
    else m = 0x1600002d;
    f_0bf730(d_1c2c64, m);
  }
  DTOR(ob);
}
//@ f_11dc90
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 12: Stellt dem Gruppenanführer auf der Straße eine zweistufige Entscheidungsfrage
 *   (0x1600002e bis 0x16000037) mit geschlechtsabhängigen Textvarianten.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11dc90(void)
{
  OB ob;
  short c;
  int u;
  u = f_038c40(d_1c0004);
  SETC(c, u);
  CTOR(ob);
  *(int *)(ob.addresses.objects + 4) = u;
  *(int *)(ob.addresses.numbers + 4) = 0x16000032;
  *(int *)(ob.addresses.numbers + 8) = 0x16000033;
  *(int *)(ob.addresses.numbers + 0xc) = c ? 0x16000036 : 0x16000035;
  if (f_0bf820(d_1c2c64, 0x1600002e, 2, 0x1600002f, 0x16000030) == 1) {
    if (f_0bf820(d_1c2c64, 0x16000031, 2, 0x16000032, 0x16000033) == 1) f_0bf730(d_1c2c64, 0x16000034);
    else f_0bf730(d_1c2c64, 0x16000037);
  }
  DTOR(ob);
}

//@ f_11dd70
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 13: Spielt eine fünfteilige Straßenszene (0x16000038 bis 0x1600003c) ab, an der ein
 *   talentierter Held (0x26) sowie ein Zwerg der Gruppe (oder der Anführer) beteiligt sind.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11dd70(void)
{
  OB ob;
  int u, p1;
  CTOR(ob);
  u = f_039320(d_1c0004, 0x26);
  *(int *)(ob.addresses.objects + 4) = u;
  p1 = f_0dd3a0(d_1c0004, 7, 0);
  if (p1 == 0 || f_0d4a60(p1) == 0) p1 = f_038c40(d_1c0004);
  *(int *)(ob.addresses.objects + 8) = p1;
  f_0bf730(d_1c2c64, 0x16000038);
  f_0bf730(d_1c2c64, 0x16000039);
  f_0bf730(d_1c2c64, 0x1600003a);
  f_0bf730(d_1c2c64, 0x1600003b);
  f_0bf730(d_1c2c64, 0x1600003c);
  DTOR(ob);
}
//@ f_11de30
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 14: Gibt eine dreiteilige Beobachtungsszene (0x1600003d bis 0x1600003f) für den
 *   Gruppenanführer aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11de30(void)
{
  OB ob;
  int u;
  CTOR(ob);
  u = f_038c40(d_1c0004);
  *(int *)(ob.addresses.objects + 4) = u;
  f_0bf730(d_1c2c64, 0x1600003d);
  f_0bf730(d_1c2c64, 0x1600003e);
  f_0bf730(d_1c2c64, 0x1600003f);
  DTOR(ob);
}
//@ f_11dea0
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 15: Gibt eine kurze Straßenmeldung (0x16000040) für den Gruppenanführer aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11dea0(void)
{
  OB ob;
  int u;
  CTOR(ob);
  u = f_038c40(d_1c0004);
  *(int *)(ob.addresses.objects + 4) = u;
  f_0bf730(d_1c2c64, 0x16000040);
  DTOR(ob);
}
//@ f_11def0
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 16: Wählt ein zufälliges Gruppenmitglied aus und gibt eine zweiteilige Straßenszene
 *   (0x16000041, 0x16000042) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11def0(void)
{
  OB ob;
  int u;
  CTOR(ob);
  u = f_038be0(d_1c0004);
  *(int *)(ob.addresses.objects + 4) = u;
  f_0bf730(d_1c2c64, 0x16000041);
  f_0bf730(d_1c2c64, 0x16000042);
  DTOR(ob);
}
//@ f_11df50
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 17: Gibt eine dreiteilige Straßenszene (0x16000043, 0x16000044, 0x16000049) mit
 *   zufällig variierten Textbausteinen (0x16000045-0x16000048) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11df50(void)
{
  OB ob;
  int u;
  short s;
  CTOR(ob);
  u = f_038c40(d_1c0004);
  s = f_1457e0(100);
  *(int *)(ob.addresses.objects + 4) = u;
  *(int *)(ob.addresses.numbers + 4) = SC(s) ? 0x16000045 : 0x16000047;
  *(int *)(ob.addresses.numbers + 8) = SC(s) ? 0x16000046 : 0x16000048;
  f_0bf730(d_1c2c64, 0x16000043);
  f_0bf730(d_1c2c64, 0x16000044);
  f_0bf730(d_1c2c64, 0x16000049);
  DTOR(ob);
}
//@ f_11e000
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 18: Bietet der Gruppe an einem Imbiss- oder Marktstand für 20 Heller (0x14) eine
 *   Stärkung an, spult bei Annahme die Spielzeit um 30 Minuten pro Gruppenmitglied vor und regeneriert über
 *   f_11cf00 Lebenspunkte aller Helden.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
short f_0dbfe0(int p1);
void f_11e000(void)
{
  OB ob;
  short n;
  int u, v, e, t, r;
  short s, a, b;
  u = f_038c40(d_1c0004);
  s = f_0dc050(d_1c0004, 0x1a2, -2);
  n = 0x14;
  CTOR(ob);
  v = 0;
  if (s != -1)
    v = f_0de7d0(d_1c0004, s);
  *(int *)(ob.addresses.objects + 4) = v;
  *(int *)(ob.addresses.objects + 8) = u;
  a = 0;
  b = 0;
  e = f_038c80(d_1c0004);
  r = 0;
  do {
    if (f_0d4a60(e)) {
      if (Z42380(e))
        b++;
      else
        a++;
    }
    t = f_0391b0(d_1c0004, e);
    e = t;
  } while (t != f_038c80(d_1c0004));
  if (a > b)
    r = 1;
  if (r == 1) {
    *(int *)(ob.addresses.numbers + 4) = 0x1600004a;
    *(int *)(ob.addresses.numbers + 8) = 0x1600004b;
    *(int *)(ob.addresses.numbers + 12) = 0x1600004c;
    *(int *)(ob.addresses.numbers + 16) = 0x1600004d;
    *(int *)(ob.addresses.numbers + 20) = 0x1600004e;
  } else {
    *(int *)(ob.addresses.numbers + 4) = 0x1600004f;
    *(int *)(ob.addresses.numbers + 8) = 0x16000050;
    *(int *)(ob.addresses.numbers + 12) = 0x16000051;
    *(int *)(ob.addresses.numbers + 16) = 0x16000052;
    *(int *)(ob.addresses.numbers + 20) = 0x16000050;
  }
  f_0bf730(d_1c2c64, 0x16000053);
  if (v) {
    f_0bf730(d_1c2c64, 0x16000054);
  } else {
    if (f_0de7e0(d_1c0004) >= n) {
      if (f_0bf6f0(d_1c2c64, 0x16000055) == 1) {
        short k;
        f_0db8b0(d_1c0004, n);
        k = f_0dbfe0(d_1c0004);
        f_125ed0(d_1c2c44, k * 30);
        f_039a80(d_1c0004, (int)f_11cf00);
        f_0bf730(d_1c2c64, 0x16000056);
      } else {
        f_0bf730(d_1c2c64, 0x16000057);
      }
    }
  }
  DTOR(ob);
}
//@ f_11e1e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 19: Gibt eine zweiteilige atmosphärische Straßenmeldung (0x16000058, 0x16000059) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11e1e0(void)
{
  f_0bf730(d_1c2c64, 0x16000058);
  f_0bf730(d_1c2c64, 0x16000059);
}
//@ f_11e210
/* === Beschreibung (Katalog) ===
 * - Zweck: Straßenereignis 20: Gibt eine dreiteilige atmosphärische Straßenmeldung (0x1600005a bis 0x1600005c)
 *   aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11e210(void)
{
  f_0bf730(d_1c2c64, 0x1600005a);
  f_0bf730(d_1c2c64, 0x1600005b);
  f_0bf730(d_1c2c64, 0x1600005c);
}

extern signed char gz11_493_d_1c0a28, gz11_493_d_1c0a2c, gz11_493_d_1c0a30, gz11_493_d_1c0a34, gz11_493_d_1c0a38;
#pragma aux gz11_493_d_1c0a28 "d_1c0a28"
#pragma aux gz11_493_d_1c0a2c "d_1c0a2c"
#pragma aux gz11_493_d_1c0a30 "d_1c0a30"
#pragma aux gz11_493_d_1c0a34 "d_1c0a34"
#pragma aux gz11_493_d_1c0a38 "d_1c0a38"
extern int gz11_493_d_1c0a48, gz11_493_d_1c0a4c, gz11_493_d_1c0a50, gz11_493_d_1c0a54;
#pragma aux gz11_493_d_1c0a48 "d_1c0a48"
#pragma aux gz11_493_d_1c0a4c "d_1c0a4c"
#pragma aux gz11_493_d_1c0a50 "d_1c0a50"
#pragma aux gz11_493_d_1c0a54 "d_1c0a54"
extern int gz11_493_d_1c0a3c[];
#pragma aux gz11_493_d_1c0a3c "d_1c0a3c"
extern short gz11_493_d_1c0a90[];
#pragma aux gz11_493_d_1c0a90 "d_1c0a90"
extern short gz11_493_d_1c0a92[];
#pragma aux gz11_493_d_1c0a92 "d_1c0a92"
extern short gz11_493_d_1c0a94;
#pragma aux gz11_493_d_1c0a94 "d_1c0a94"
extern int gz11_493_d_1c2c64, gz11_493_d_1c2c00;
#pragma aux gz11_493_d_1c2c64 "d_1c2c64"
#pragma aux gz11_493_d_1c2c00 "d_1c2c00"
struct Context11CA493 { public:
// gz_11caf0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11CAF0-0x11E500
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
static int f_038be0(int p1);                                   // reg eax stapel 0
static int f_038c40(int p1);                                   // reg eax stapel 0
static int f_038c80(int p1);                                   // reg eax stapel 0
static int f_038cb0(int p1);                                   // reg eax stapel 0
static int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
static int f_039320(int p1, int p2);                           // reg eax edx stapel 0
static int f_039a80(int p1, int p2);                           // reg eax edx stapel 0
static int f_039ac0(int p1, int p2);                           // reg eax edx stapel 0
static int f_040a00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_040a40(int p1);                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
static int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
static int f_044850(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_044900(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_057220(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
static int f_0bf820();                                         // reg - stapel 0
static int f_0d49b0(int p1);                                   // reg eax stapel 0
static int f_0d4a60(int p1);                                   // reg eax stapel 0
static int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
static int f_0d5040();                       // nicht in clobber.tsv
static int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0db970(int p1);                                   // reg eax stapel 0
static int f_0dbe20(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0dc050(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
static int f_0de7d0(int p1, int p2);                           // reg eax edx stapel 0
static int f_0de7e0(int p1);                                   // reg eax stapel 0
static int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
static int f_1254a0(int p1);                                   // reg eax stapel 0
static int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
static int f_125f70(int p1, int p2);                           // reg eax edx stapel 0
static int f_126410(int p1);                                   // reg eax stapel 0
static short f_1457e0(int p1);
#define EQM(x,v) (((x)==(v))?1:0)
static inline int EQF(int a, int b) { return a == b; }
static inline char EQC(int a, int b) { return a == b; }
static inline int EQR(const signed char &x, int v) { return x == v; }

#define EQ(x,v) (((x)==(v))?1:0)
static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
static void f_11e240(void);
static void f_11e270(void);
static void f_11e320(void);
static short f_11e350(void);
static short f_11e380(void);
static void f_11e4d0(int p1);
};
//@ f_11e240
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt die besondere Straßenmeldung 0x1600005d aus und schreibt der Gruppe einmalig Abenteuerpunkte
 *   (0x803001a) gut.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void Context11CA493::f_11e240(void)
{
    f_0bf730((int)&gz11_493_d_1c2c64, 0x1600005d);
    f_057220((int)&gz11_493_d_1c2c00, 0x803001a, 0);
}

//@ f_11e270
/* === Beschreibung (Katalog) ===
 * - Zweck: Sperrt in der Kandidatenliste d_1c0a3c bereits erlebte einmalige Straßenereignisse (d_1c0a48 bis
 *   d_1c0a54, d. h. die Ereignisse 3 bis 6) sowie noch nicht freigeschaltete Folgestufen der nächtlichen
 *   Begegnungsreihe.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void Context11CA493::f_11e270(void)
{
    if (EQM(gz11_493_d_1c0a2c, 1)) gz11_493_d_1c0a48 = 0;
    if (EQM(gz11_493_d_1c0a30, 1)) gz11_493_d_1c0a4c = 0;
    if (EQM(gz11_493_d_1c0a34, 1)) gz11_493_d_1c0a50 = 0;
    if (EQM(gz11_493_d_1c0a38, 1)) gz11_493_d_1c0a54 = 0;
    if (gz11_493_d_1c0a4c == 1) {
        gz11_493_d_1c0a50 = 0;
        gz11_493_d_1c0a54 = 0;
    } else if (gz11_493_d_1c0a50 == 1) {
        gz11_493_d_1c0a54 = 0;
    }
}

//@ f_11e320
/* === Beschreibung (Katalog) ===
 * - Zweck: Streicht die letzten drei ausgelösten Straßenereignisse (d_1c0a90[0..2]) aus der aktuellen
 *   Kandidatenliste d_1c0a3c, damit sich dieselben Ereignisse nicht unmittelbar wiederholen.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void Context11CA493::f_11e320(void)
{
    short k;
    short t;
    int i;
    k = 0;
    do {
        i = k;
        k++;
        t = gz11_493_d_1c0a90[i];
        gz11_493_d_1c0a3c[t] = 0;
    } while (k < (short)3);
}

//@ f_11e350
/* === Beschreibung (Katalog) ===
 * - Zweck: Zählt, wie viele Straßenereignisse in der Kandidatenliste d_1c0a3c aktuell als verfügbar (1) markiert
 *   sind.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die Anzahl der verfügbaren Straßenereignisse zurück.
 * - Bekannte Originalfehler: Das Array d_1c0a3c umfasst 21 Einträge (d_1c0a3c[0..20], 84 Bytes = 0x54, siehe
 *   memset in f_11e500), wobei die 20 Straßenereignisse 1-basiert unter den Indizes 1 bis 20 abgelegt sind und
 *   f_1457e0(20) Zufallszahlen von 1 bis 20 zieht. Die Zählschleife in f_11e350 (und identisch inlined in
 *   f_11e380 sowie f_11e500) läuft jedoch über for (k = 0; k < 20; k++) (0..19) statt 1..20. Dadurch wird
 *   d_1c0a3c[20] (Ereignis 20) bei der Verfügbarkeitsprüfung niemals mitgezählt: Ist nur noch Ereignis 20
 *   verfügbar, liefert die Zählung 0 und Ereignis 20 wird übersprungen.
 === Ende Beschreibung === */
short Context11CA493::f_11e350(void)
{
    short n;
    short k;
    n = 0;
#if FIX_R055   /* R055: Strassenbegegnungen sind 1-basiert (1..20) in d_1c0a3c abgelegt */
    for (k = 1; k <= (short)20; k++) {
#else
    for (k = 0; k < (short)20; k++) {
#endif
        if (gz11_493_d_1c0a3c[k] == 1) n++;
    }
    return n;
}

//@ f_11e380
/* === Beschreibung (Katalog) ===
 * - Zweck: Würfelt mit einer Wahrscheinlichkeit von 1 zu 30 (f_1457e0(30) == 1) aus den nach Filterung
 *   (f_11e270, f_11e320) verbleibenden Kandidaten in d_1c0a3c ein zufälliges Straßenereignis (1..20) aus.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt die 1-basierte Nummer des ausgewählten Straßenereignisses (1..20) zurück
 *   oder 0, falls kein Ereignis ausgelöst wird.
 * - Bekannte Originalfehler: Enthält denselben Schleifengrenzenfehler for (k = 0; k < 20; k++) wie f_11e350
 *   (0x11e473-0x11e49f), sodass d_1c0a3c[20] nicht mitgezählt wird.
 === Ende Beschreibung === */
short Context11CA493::f_11e380(void)
{
    short r = 0;
    short n;
    short k;
    short t;
    int i;
    short v;
    if (EQM(gz11_493_d_1c0a28, 0)) {
        if (f_1457e0(0x1e) == 1) {
            if (EQM(gz11_493_d_1c0a2c, 1)) gz11_493_d_1c0a48 = 0;
            if (EQM(gz11_493_d_1c0a30, 1)) gz11_493_d_1c0a4c = 0;
            if (EQM(gz11_493_d_1c0a34, 1)) gz11_493_d_1c0a50 = 0;
            if (EQM(gz11_493_d_1c0a38, 1)) gz11_493_d_1c0a54 = 0;
            if (gz11_493_d_1c0a4c == 1) {
                gz11_493_d_1c0a50 = 0;
                gz11_493_d_1c0a54 = 0;
            } else if (gz11_493_d_1c0a50 == 1) {
                gz11_493_d_1c0a54 = 0;
            }
            k = 0;
            do {
                i = k;
                k++;
                t = gz11_493_d_1c0a90[i];
                gz11_493_d_1c0a3c[t] = 0;
            } while (k < (short)3);
            n = 0;
#if FIX_R055   /* R055: Strassenbegegnungen sind 1-basiert (1..20) in d_1c0a3c abgelegt */
            for (k = 1; k <= (short)20; k++) {
#else
            for (k = 0; k < (short)20; k++) {
#endif
                if (gz11_493_d_1c0a3c[k] == 1) n++;
            }
            if (n > 0) {
                int w = 0x14;
                do {
                    v = f_1457e0(w);
                    r = v;
                } while (gz11_493_d_1c0a3c[(short)(v & 0xffff)] == 0); // haelt v als 32-Bit-Zwischenwert in der Registerfolge wie im Original
            }
        }
    }
    return (short)(r & 0xffff); // haelt r ueber die Funktion hinweg im selben Register wie im Original
}
//@ f_11e4d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Schiebt das zuletzt ausgelöste Straßenereignis p1 in den 3-Elemente-Ringpuffer d_1c0a90[0..2] nach,
 *   damit es bei den nächsten drei Prüfungen gesperrt bleibt.
 * - Eingaben: Die Funktion erhält im Parameter p1 die Nummer des gerade ausgelösten Straßenereignisses.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void Context11CA493::f_11e4d0(int p1)
{
    short k;
    int i;
    for (k = 0; k < 2; k++) gz11_493_d_1c0a90[k] = gz11_493_d_1c0a92[k];
    gz11_493_d_1c0a94 = (short)p1;
}
