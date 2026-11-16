/* === Beschreibung (Katalog) ===
 * Einheit gz_11a880 (0x11a930 - 0x11aaa0)
 *
 * Überblick
 * Diese Einheit enthält die Registrierungsfunktion für die persistenten Zustandsvariablen der dritten Ebene des
 * Bienenstocks (star3, Dungeon-ID 9) sowie den Konstruktor des zugehörigen Dungeon-Objekts.
 === Ende Beschreibung === */
// P1 9/10 gleich
// gz_11a880.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x11A880-0x11AAA0
#include <string.h>
#include "RIVAMEM.H"



int f_115630(int p1, int p2);
int f_115640(int p1, int p2);
int f_145234(int p1, int p2);
void f_145254(void);
void f_11a500(void);
void f_11a5c0(int p1);
void f_11a5e0(void);
void f_11a600(void);
void f_11a620(void);
int f_11a650(int p1, int p2, int p3);
struct E3 { signed char b; short id; };
extern struct E3 d_1c0a0c, d_1c0a10, d_1c0a14, d_1c0a18, d_1c0a1c, d_1c0a20, d_1c0a24;
extern int d_1c212c;
extern short d_1c212a;
extern int d_1bb978, d_1bb9d0;
#define STB(v,k) (v).b = 0; (v).id = (k);
#define STI(v,k) (v).id = (k); (v).b = 0;
#define TAB(v) *(int *)(d_1c212c + d_1c212a * 4) = (int)&(v); d_1c212a++;
//@ f_11a930
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die persistenten Zustandsvariablen der dritten Bienenstock-Ebene (d_1c0a0c bis d_1c0a24)
 *   in der globalen Spielstands-Tabelle (d_1c212a).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
extern short d_1c212a;
struct ObjB { signed char a; short b; };
struct RegB { short count; ObjB **list; };
extern ObjB d_o0c, d_o10, d_o14, d_o18, d_o1c, d_o20, d_o24;
extern RegB d_r;
#pragma aux d_o0c "d_1c0a0c"
#pragma aux d_o10 "d_1c0a10"
#pragma aux d_o14 "d_1c0a14"
#pragma aux d_o18 "d_1c0a18"
#pragma aux d_o1c "d_1c0a1c"
#pragma aux d_o20 "d_1c0a20"
#pragma aux d_o24 "d_1c0a24"
#pragma aux d_r "d_1c212a"
inline signed char z_11a930()
{
    signed char c = 0;
    return c;
}
inline void add_11a930(ObjB &o, RegB &r, short id)
{
    o.a = z_11a930();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
void f_11a930(void)
{
    add_11a930(d_o0c, d_r, 0x12e);
    add_11a930(d_o10, d_r, 0x12f);
    d_o14.a = z_11a930();
    d_o14.b = 0x130;
    d_r.list[d_r.count] = &d_o14;
    d_r.count++;
    d_o18.a = z_11a930();
    d_o18.b = 0x131;
    d_r.list[d_r.count] = &d_o18;
    d_r.count++;
    d_o1c.a = z_11a930();
    d_o1c.b = 0x132;
    d_r.list[d_r.count] = &d_o1c;
    d_o20.a = z_11a930();
    d_r.count += 1;
    d_o20.b = 0x133;
    d_r.list[d_r.count] = &d_o20;
    d_r.count++;
    d_o24.a = z_11a930();
    d_o24.b = 0x1af;
    d_r.list[d_r.count] = &d_o24;
    d_r.count++;
}

//@ f_11aa80
/* === Beschreibung (Katalog) ===
 * - Zweck: Konstruktor des Dungeon-Objekts für die dritte Ebene des Bienenstocks (star3, Dungeon-ID 9), der die
 *   Basisklasse (f_115630) initialisiert und die virtuelle Methodentabelle (d_1bb9d0) einträgt.
 * - Eingaben: Die Funktion erhält im Parameter p1 den this-Zeiger des Dungeon-Objekts.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_11aa80(int p1)
{
    int r;
    r = f_115630(p1, 9);
    *(int *)(r + 8) = (int)&d_1bb9d0;
}
