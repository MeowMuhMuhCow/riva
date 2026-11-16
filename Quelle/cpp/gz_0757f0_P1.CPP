/* === Beschreibung (Katalog) ===
 * Einheit gz_0757f0 (0757f0 - 075bc0)
 *
 * Überblick
 * Diese Einheit enthält Funktionen zur Bildpuffer-Initialisierung und Gesamterneuerung der Kampf-Grafikausgabe
 * (f_0757f0, f_0758b0) sowie zum Zeichnen der Helden-Statusboxen (Porträt, Name, LE- und AE-Balken) am linken
 * Bildschirmrand im Kampf (f_075930).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 1/3 gleich (suche.py 25.10.2026, Basis gz_0757f0_P1.CPP)
// gz_0757f0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0757F0-0x075BC0
#include <string.h>

void *f_145300(void *p, int c, unsigned n);               // memset
int f_069460();
int f_0762e0(int a, int b, int c, int d);
int f_0765a0(char **p);
int f_076bd0(void *p);
int f_075f10(char **p);
int f_01e630(void *o, int a, int b, short c, int d, int e, int f);






int f_045080(int p, void *b);
int f_05ded0(void *o, int a);
int f_05e2a0(void *o, short *a, short *b, short *c, short *d);
int f_05e2d0(void *o, int a, int b, int c, int d);
int f_05e320(void *o, int a, int b);
int f_05e360(void *o, short *a, short *b);
int f_05e7e0(void *o, int a, int b);
int f_05e800(void *o, short *a, short *b);
int f_0e9660(void *o, int a, int b, int c);



int f_1481a0(void *o, int a, int b, int c, int d, int e, int f);
extern char d_1bd928;
extern char d_1bda50;
extern int d_1bda54;
extern int d_1bda58;
extern char *d_1bdaec;
extern char d_1bd988[];
extern char d_1c2d1c[];
extern char d_1c38b0[];
extern char d_1c3068[];
extern char d_1bdbd4[];
extern char d_1c2bcc[];
extern int d_1a34e0;
#define NOGO (!d_1bd928)
#define INITBLK(P) \
    if NOGO { \
        d_1bda50 = 0; \
        f_145300(d_1bd988, -1, 200); \
        d_1bda58 = 0; \
        if (d_1bda54 != 0) { \
            f_0762e0(0, 0, 0x13f, 199); \
            d_1bda58 = 1; \
        } \
        memcpy(*P, d_1bdaec, 0xfa00); \
    }

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_0757f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt einen vollständigen Neuaufbau des Kampfbildschirms durch, indem der gespeicherte
 *   Hintergrundpuffer d_1bdaec (64000 Bytes) in den Arbeitsbildschirm kopiert, alle Kampffiguren und Objekte
 *   über f_0765a0 eingezeichnet, eventuelle Schadens-/Aktionsmeldungen über f_076bd0 gerendert und die
 *   geänderten Bildschirmbereiche über f_075f10 auf die VGA-Anzeige übertragen werden.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 (char ) und gibt den Rückgabewert von f_076bd0 (short, 1
 *   bei aktiver Kampfmeldung, sonst 0) zurück.
 * - Wichtige Variablen: Prüft das Schnell-/Hintergrundflag d_1bd928, leert die Dirty-Rectangle-Liste d_1bd988
 *   und kopiert 0xfa00 Bytes aus d_1bdaec.
 === Ende Beschreibung === */
short f_0757f0(char **p1)
{
    int r = 0;
    if (!d_1bd928) {
        char **p = p1;
        do {
            if (!d_1bd928) {
                d_1bda50 = 0;
                f_145300(d_1bd988, -1, 200);
                d_1bda58 = 0;
                if (d_1bda54 != 0) {
                    f_0762e0(0, 0, 0x13f, 199);
                    d_1bda58 = 1;
                }
                memcpy(*p, d_1bdaec, 0xfa00);
            }
        } while (0);
        f_0765a0(p1);
        r = f_076bd0(d_1c2d1c);
        f_075f10(p1);
    } else {
        f_069460();
    }
    return r;
}

//@ f_0758b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt vor einem neuen Zeichenschritt im Kampf die Dirty-Rectangle-Liste d_1bd988 zurück und
 *   kopiert das saubere Kampfhintergrundbild (samt statischen Hindernissen) aus d_1bdaec in den Offscreen-Puffer
 *   *p1.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1 (char ) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Setzt den Rechteckzähler d_1bda50 auf 0, füllt d_1bd988 (200 Bytes) mit -1 und markiert
 *   bei gesetztem d_1bda54 den gesamten 320 x 200-Bildschirm als zu aktualisieren.
 === Ende Beschreibung === */
void f_0758b0(char **p1)
{
    INITBLK(p1)
}

//@ f_075930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet im Kampf das Porträtfenster eines Helden p3 samt Rahmen, Namen sowie Lebensenergie-
 *   und Astralenergie-Balken (f_01e630) entweder in die obere linke Ecke (p2 == 0, aktiver Held) oder in die
 *   untere linke Ecke (p2 != 0, anvisiertes Ziel) des Kampfbildschirms.
 * - Eingaben und Rückgabe: Empfängt den Kampfzeiger p1, das Positionsflag p2 (0 = oben links, 1 = unten links)
 *   sowie den Heldenzeiger p3 (int) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Lädt das 32 x 32-Heldenporträt über f_045080, zeichnet die Statusbalken über d_1c2bcc
 *   und meldet den geänderten Bildschirmbereich über f_0762e0 an die Dirty-Rectangle-Liste.
 === Ende Beschreibung === */
void f_075930(int *p1, short p2, int p3)
{
    char buf[12];
    short s1c;
    short s18;
    short s14;
    short i10;
    short sc;
    short s8;
    if (p3 != 0) {
        f_05e2a0(d_1c38b0, &i10, &i10, &i10, &s14);
        f_05e800(d_1c38b0, &sc, &s8);
        f_05e2d0(d_1c38b0, -1, -1, -1, 0);
        f_05e7e0(d_1c38b0, 0, 0);
        f_05e360(d_1c38b0, &s18, &s1c);
        f_05e320(d_1c38b0, 0xff, -1);
        f_05ded0(d_1c3068, *p1);
        ((int)(((RivaRasterImage*)(buf))->f_0fac80( 0x20, 0x20)));
        f_045080(p3, buf);
        if (!p2) {
            f_1481a0(d_1bdbd4, *p1, 1, 9, 0x22, 0x22, -3);
            f_0e9660(d_1c38b0, ((int)(f_0422b0((struct hero *)(p3)))), 1, 1);
            ((RivaRasterImage*)(buf))->f_0fade0((void *)( *p1), 2, 10);
            f_01e630(d_1c2bcc, 0, 0, f_042960((struct hero *)(p3)), f_042970((struct hero *)(p3)), 1, *p1);
            f_01e630(d_1c2bcc, 1, 0, (((char)(f_042470((struct hero *)(p3)))) ? 0 : f_0429a0((struct hero *)(p3))), f_0429b0((struct hero *)(p3)), 1, *p1);
            f_0762e0(0, 0, 100, 0x37);
        } else {
            f_1481a0(d_1bdbd4, *p1, 1, 0x9d, 0x22, 0x22, -3);
            f_0e9660(d_1c38b0, ((int)(f_0422b0((struct hero *)(p3)))), 1, 0xc0);
            ((RivaRasterImage*)(buf))->f_0fade0((void *)( *p1), 2, 0x9e);
            f_01e630(d_1c2bcc, 0, 0, f_042960((struct hero *)(p3)), f_042970((struct hero *)(p3)), 3, *p1);
            f_01e630(d_1c2bcc, 1, 0, (((char)(f_042470((struct hero *)(p3)))) ? 0 : f_0429a0((struct hero *)(p3))), f_0429b0((struct hero *)(p3)), 3, *p1);
            f_0762e0(0, 0x91, 100, 199);
        }
        f_05e320(d_1c38b0, s18, s1c);
        f_05ded0(d_1c3068, d_1a34e0);
        f_05e2d0(d_1c38b0, -1, -1, -1, s14);
        f_05e7e0(d_1c38b0, sc, s8);
        ((int)(((RivaRasterImage*)(buf))->f_0fad20( 0)));
    }
}
