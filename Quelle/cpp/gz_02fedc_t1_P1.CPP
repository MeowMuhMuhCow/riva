/* === Beschreibung (Katalog) ===
 * Einheit gz_02fedc_t1 (0x0002fedc - 0x0002ff70)
 *
 * Überblick
 *
 * Die kleine Einheit gz_02fedc_t1 enthält eine Initialisierungsfunktion (f_02fedc), die mit unoptimiertem
 * Compilerprofil (-od) übersetzt wurde und ein 4-Byte-Statusfeld am Offset +0x02 einer übergebenen Struktur auf
 * null setzt.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -od -zp1 -s
// Privater Profilteilungsvorschlag Astra493; noch nicht registriert.
// gz_02fedc.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x02FEDC-0x030080
#include <string.h>
#include "RIVAMEM.H"



int f_038c20(int p1);




char f_0433e0(int p1);
int f_069460();
int f_071e90(int p1, int p2, int p3);
char f_0d54c0(int p1);
extern signed char d_1bd928;
//@ f_02fedc
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löscht die vier Einzelbytes an den Offsets +2, +3, +4 und +5 des übergebenen Objekts p1 auf 0
 *   und gibt den ursprünglichen Objektzeiger wieder zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Strukturzeiger p1 und gibt p1 unverändert zurück.
 * - Wichtige Variablen: Beschreibt die vier Bytes ((unsigned char *)(p1 + 2))[0..3] mit 0.
 === Ende Beschreibung === */
int f_02fedc(int p1)
{
  union ByteSlot { int pad; unsigned char v; };
  struct Frame {
    int t2,t,q;
    ByteSlot a, d, e, f, g, h, i, b, c;
  };
  Frame x;
  x.a.v = 0;
  x.b.v = x.a.v;
  x.c.v = 0;
  x.d.v = x.c.v;
  x.e.v = 0;
  x.f.v = x.e.v;
  x.t = p1 + 2;
  x.q = x.t;
  x.g.v = x.f.v;
  x.h.v = x.d.v;
  x.i.v = x.b.v;
  ((unsigned char *)x.q)[3] = 0;
  ((unsigned char *)x.q)[2] = x.g.v;
  ((unsigned char *)x.q)[1] = x.h.v;
  ((unsigned char *)x.q)[0] = x.i.v;
  x.t2 = x.q;
  p1 = x.t2 - 2;
  return p1;
}
