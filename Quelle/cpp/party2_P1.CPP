/* === Beschreibung (Katalog) ===
 * Einheit party2 (0dc650 - 0dc9a0)
 *
 * Überblick
 * Die Einheit party2 stammt aus der Quelldatei party2.cpp und enthält die Zeichenroutine, mit der sämtliche
 * Heldenporträts, Namenszüge und Statusbalken einer Teilgruppe in die obere Heldenleiste des Bildschirms
 * gerendert werden.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 29.10.2026, Basis party2_P1.CPP)
// party2.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DC650-0x0DC9A0
#include <string.h>
int f_044ea0(int p1);
int f_0451f0(int p1, int p2);
int f_043de0(int p1, int p2);
int f_0d4b90(int p1, int p2, int p3);
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_050580(int p1, int p2, int p3, short *p4, short *p5);
int f_05dec0(int p1);
int f_05ded0(int p1, int p2);
int f_05e320(int p1, int p2, int p3);
int f_05e340(int p1);
int f_0bbe10(int p1, int p2, int p3);
int f_0dc4d0(int p1);
short f_0de7f0(int p1);
int f_0e9660(int p1, int p2, int p3, int p4);
short f_0e9670(int p1, int p2, int p3, int p4);







extern unsigned short d_1a5544[];
extern short d_1bb2c0;
extern int d_1c0004;
extern char d_1bf230[], d_1c2be0[], d_1c3068[], d_1c38b0[];
extern const char d_1a62e4[];
//@ f_0dc650
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Zeichnet die Mitglieder einer Teilgruppe (party) ab dem Gruppenleisten-Slot start in den
 *   Zielbildpuffer target: lädt den Namensschild-Hintergrund aus 0x40004, kopiert jedes 32x32-Heldenporträt (bei
 *   inaktiven Teilgruppen party != d_1c0004 abgedunkelt über f_0dc4d0; NPC-Begleiter immer auf Slot 6), gibt den
 *   gekürzten Heldennamen darunter aus und zeichnet abschließend die Lebens-/Astralpunktbalken über f_0d4b90.
 * - Eingaben: Übergeben werden der Zeiger auf das Gruppen-Objekt (party), der erste zu belegende Anzeigeslot
 *   (start) sowie das Zielbild-Objekt (target).
 * - Rückgabewert: Gibt den nächsten freien Anzeigeslot (start erhöht um die Zahl der regulären Helden dieser
 *   Teilgruppe) zurück.
 === Ende Beschreibung === */
short f_0dc650(int party, short start, int target)
{
    short textx = 0;
    int resource = 0x40004;
    short mode = (party == d_1c0004) ? 1 : 2;
    short color = (party == d_1c0004) ? d_1bb2c0 : 205;
    short count = f_0de7f0(party);
    short slot2 = 0;
    short slot = 0;
    short i;
    short width = 0, height = 0;
    int hero = 0;
    int background = 0;
    int portrait = (int)operator new(9, mark(d_1a62e4, 0x258));
    portrait = portrait ? ((int)(((RivaRasterImage*)(portrait))->f_0fac10(32,32,(void *)(0)))) : portrait;
    int saved = f_05dec0((int)d_1c3068);
    char *name = new (mark(d_1a62e4, 0x25a)) char[16];
    f_05ded0((int)d_1c3068, ((int)(((RivaRasterImage*)(target))->f_0fb0b0())));
    f_050580((int)d_1c2be0, resource, (short)mode, &width, &height);
    background = (int)operator new(9, mark(d_1a62e4, 0x260));
    background = background ? ((int)(((RivaRasterImage*)(background))->f_0fac80(width,height))) : background;
    f_04fef0((int)d_1c2be0, resource, ((int)(((RivaRasterImage*)(background))->f_0fb0b0())), 0, (short)mode, 0, 320);
    for (i=0; i<count; i++) {
        hero = ((int *)party)[i];
        if (hero) {
            slot = f_042400((struct hero *)(hero)) == 0 ? start+i : 6;
            ((RivaRasterImage*)(portrait))->f_0fb060((void *)( f_044ea0(hero)));
            if (party != d_1c0004) f_0dc4d0(((int)(((RivaRasterImage*)(portrait))->f_0fb0b0())));
            f_0bbe10((int)d_1bf230, (int)name, ((int)(f_0422b0((struct hero *)(hero)))));
            f_05e320((int)d_1c38b0, color, -1);
            textx = f_0e9670((int)d_1c38b0, (int)name, (short)d_1a5544[slot], 43);
            ((RivaRasterImage*)(background))->f_0fae30((void *)( ((int)(((RivaRasterImage*)(target))->f_0fb0b0()))), (short)(d_1a5544[slot]-1), 33, 1);
            ((RivaRasterImage*)(portrait))->f_0fade0((void *)( ((int)(((RivaRasterImage*)(target))->f_0fb0b0()))), (short)d_1a5544[slot], 1);
            f_0e9660((int)d_1c38b0, (int)name, textx, 34);
            f_05e340((int)d_1c38b0);
        }
    }
    f_05ded0((int)d_1c3068, saved);
    operator delete(name);
    if (background) operator delete((void *)((int)(((RivaRasterImage*)(background))->f_0fad20(0))));
    if (portrait) operator delete((void *)((int)(((RivaRasterImage*)(portrait))->f_0fad20(0))));
    for (i=0; i<count; i++) {
        hero = ((int *)party)[i];
        if (hero) {
            slot2 = f_042400((struct hero *)(hero)) == 0 ? start++ : 6;
            f_0451f0(hero,-1);
            f_0d4b90(hero,slot2,((int)(((RivaRasterImage*)(target))->f_0fb0b0())));
            f_043de0(hero,(signed char)slot2);
        }
    }
    return start;
}
