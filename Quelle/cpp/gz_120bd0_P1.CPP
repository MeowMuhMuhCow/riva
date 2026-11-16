/* === Beschreibung (Katalog) ===
 * Einheit gz_120bd0 (0x120bd0 - 0x120c60)
 *
 * Überblick
 * Diese kleine Einheit enthält eine Hilfsfunktion der 3D-Engine, die gespeicherte Positions- und
 * Blickwinkelwerte aus dem Zwischenpuffer d_1c0af8 in den aktuellen Gruppenzustand überträgt.
 === Ende Beschreibung === */
// P1 0/1 gleich
// gz_120bd0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x120BD0-0x120C60
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
#pragma inline_depth(0)
extern int d_1c0004;
extern int d_1c0af8;
extern char *d_1c0b40;
int f_0de850(int p1, int p2);
int f_0de870(int p1, int p2);
int f_0de890(int p1, int p2);
int f_0de8d0(int p1, int p2);
int f_0de8f0(int p1, int p2);
int f_0de930(int p1, int p2);
//@ f_120bd0
/* === Beschreibung (Katalog) ===
 * - Zweck: Liest aus dem Zwischenpuffer d_1c0af8 nacheinander die X-, Y- und Z-Koordinaten sowie die beiden
 *   Blickwinkel aus und setzt damit die Position und Ausrichtung der Heldengruppe in der 3D-Szenerie.
 * - Eingaben: Die Funktion erhält keine Parameter.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_120bd0(void)
{
	char *p;
	unsigned short *w;
	d_1c0b40 = (char *)d_1c0af8;
	p = (d_1c0b40 += 4);
	f_0de850(d_1c0004, *(int *)p);
	p += 4;
	f_0de870(d_1c0004, *(int *)p);
	p += 4;
	f_0de890(d_1c0004, *(int *)p);
	p += 4;
	w = (unsigned short *)p; w++; f_0de8d0(d_1c0004, *(w - 1)); w++; f_0de8f0(d_1c0004, *(w - 1)); w++; p = (char *)w;
	d_1c0b40 = p;
	f_0de930(d_1c0004, 1);
}
