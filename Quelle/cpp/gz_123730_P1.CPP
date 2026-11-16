/* === Beschreibung (Katalog) ===
 * Einheit gz_123730 (0x123730 - 0x123850)
 *
 * Überblick
 * Diese kleine Einheit registriert die persistenten Tempel-Flags (d_1c0c30 bis d_1c0c44) in der globalen
 * Spielstands-Tabelle (d_1c212a).
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 26.10.2026, Basis gz_123730_P1.CPP)
// gz_123730.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x123730-0x123850
#include <string.h>
void *mark(const char *file, int line);
extern char d_1c0c30;
extern short d_1c0c31;
extern char d_1c0c34;
extern signed char d_1c0c35;
extern char d_1c0c38;
extern short d_1c0c39;
extern char d_1c0c3c;
extern short d_1c0c3d;
extern char d_1c0c40;
extern short d_1c0c41;
extern char d_1c0c44;
extern short d_1c0c45;
extern short d_1c212a;
//@ f_123730
/* === Beschreibung (Katalog) ===
 * - Zweck: Registriert die sechs persistenten Besuchs- und Ereignisflags der Tempel in Riva (d_1c0c30 bis
 *   d_1c0c44, Kennungen 0x8c und 0x93-0x97) in der globalen Spielstands-Tabelle (d_1c212a).
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
extern char **d_1c212c;
struct ObjB { signed char a; short b; };
struct RegB { short count; ObjB **list; };
extern ObjB d_o30, d_o34, d_o38, d_o3c, d_o40, d_o44;
extern RegB d_r;
#pragma aux d_o30 "d_1c0c30"
#pragma aux d_o34 "d_1c0c34"
#pragma aux d_o38 "d_1c0c38"
#pragma aux d_o3c "d_1c0c3c"
#pragma aux d_o40 "d_1c0c40"
#pragma aux d_o44 "d_1c0c44"
#pragma aux d_r "d_1c212a"
inline signed char z_123730()
{
    signed char c = 0;
    return c;
}
inline void add_123730(ObjB &o, RegB &r, short id)
{
    o.a = z_123730();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
inline void add2_123730(ObjB &o, RegB &r, int id)
{
    o.a = z_123730();
    o.b = id;
    r.list[r.count] = &o;
    r.count++;
}
inline void add3_123730(ObjB &o, RegB &r, short id)
{
    o.a = z_123730();
    o.b = id;
    r.list[r.count++] = &o;
}
void f_123730(void)
{
    add_123730(d_o30, d_r, 0x8c);
    add_123730(d_o34, d_r, 0x93);
    add_123730(d_o38, d_r, 0x94);
    signed char c = 0;
    d_o3c.a = c;
    d_o3c.b = 0x95;
    d_r.list[d_r.count] = &d_o3c;
    d_r.count++;
    d_o40.a = c;
    d_o40.b = 0x96;
    d_r.list[d_r.count] = &d_o40;
    d_r.count++;
    d_o44.a = c;
    d_o44.b = 0x97;
    d_r.list[d_r.count] = &d_o44;
    d_r.count++;
}
