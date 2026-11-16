/* === Beschreibung (Katalog) ===
 * Einheit bars (0x01e860 - 0x01eb40)
 *
 * Überblick
 * Diese Einheit zeichnet und aktualisiert in der Hauptansicht die beiden horizontalen Statusbalken für Hunger
 * (f_042900) und Durst (f_042910) des aktuell ausgewählten Helden (d_1bc8f4). Jeder Balken ist 50 Pixel breit
 * und 6 Zeilen hoch; erreicht ein Wert das Maximum 100, blinkt der betreffende Balken alle 25 Aufrufe zwischen
 * Vorder- und Hintergrundfarbe.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 1/1 gleich (Astra S18_1307 11.11.2026: kruecken-freie Neufassung, Lokale nach Demo-Stapellayout)
// I9: aus bars_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// bars.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x01E860-0x01EB40. Zwei Balken (Werte 0..100) zeichnen, bei 100 blinkend.
// Stand: GLEICH 736/736. Deklarationsfolge der Lokalen bestimmt die Stapelplaetze (Demo -od-Layout + Kettenmodell S11).
extern signed char d_1a0514;                               // 0x1A0514
extern signed char d_1a0515;                               // 0x1A0515
extern void *d_1bc8f4;
extern char *d_1a34e0;
int f_0d3860();
void f_0d2710();
void f_0d26e0();


void f_1483f0(char *dst, int x, int y, int w, int color);
struct Bars {
    signed char b0, b1, b2, b3;
    void f_01e860();
};
//@ f_01e860
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x01e860
 * - Aufgabe im Spiel: Prüft für den aktuell angezeigten Helden (d_1bc8f4) den Hungerwert (f_042900, oberer
 *   Balken bei y = 65..70, Farben -3 und -69) sowie den Durstwert (f_042910, unterer Balken bei y = 72..77,
 *   Farben -5 und -12) an der X-Position 130. Hat sich ein Wert gegenüber dem zuletzt gezeichneten Stand
 *   (d_1a0514 bzw. d_1a0515) geändert, wird der Balken anteilig (width = wert >> 1 von 50 Pixeln) über f_1483f0
 *   neu gezeichnet; steht ein Wert auf 100, schaltet die Funktion alle 25 Ticks die Blinkphase (b1 bzw. b3) um
 *   und synchronisiert bei gleichzeitigem Maximum beider Balken deren Blinktakt (b0 = b2; b1 = b3).
 * - Eingaben: Impliziter this-Zeiger auf das 4-Byte-Bars-Zustandsobjekt.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Instanzfelder b0 (Blinkzähler Hunger), b1 (Blinkphase Hunger), b2 (Blinkzähler Durst), b3 (Blinkphase
 *     Durst).
 *   - Globale Cache-Bytes d_1a0514 (zuletzt gezeichneter Hungerwert) und d_1a0515 (zuletzt gezeichneter
 *     Durstwert).
 *   - Globaler Zeiger d_1bc8f4 auf den aktuell ausgewählten Helden und Ziel-Bildschirmpuffer d_1a34e0.
 === Ende Beschreibung === */
void Bars::f_01e860() {
    typedef void (*DrawF)(char *, short, short, short, signed char); // haelt die Registerzuteilung wie im Original
    struct MG {
        int fl;
        MG() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
        ~MG() { if (fl == 1) f_0d26e0(); }
    };
    short x, i, upper, lower, width;
    x=130; lower=72; upper=65;
    void *hero;
    MG mg;
    hero=d_1bc8f4;
    if(f_042900((struct hero *)(hero))>=100) d_1a0514=100;
    if(f_042910((struct hero *)(hero))>=100) d_1a0515=100;
    if(d_1a0514==100 && d_1a0515==100) { b0=b2; b1=b3; }
    if(d_1a0514==100) {
        if(b0++==25) {
            signed char color;
            b1^=1;
            for(i=0;i<6;i++) {
                if(b1==1) color=-3; else color=-69;
                ((DrawF)f_1483f0)(d_1a34e0,x,upper+i,50,color);
            }
            b0=0;
        }
    } else if(f_042900((struct hero *)(hero))!=d_1a0514) {
        d_1a0514=f_042900((struct hero *)(hero));
        width=(unsigned char)d_1a0514>>1;
        for(i=0;i<6;i++) {
            ((DrawF)f_1483f0)(d_1a34e0,x,upper+i,width,-3);
            ((DrawF)f_1483f0)(d_1a34e0,x+width,upper+i,50-width,-69);
        }
    }
    if(d_1a0515==100) {
        if(b2++==25) {
            signed char color;
            b3^=1;
            for(i=0;i<6;i++) {
                if(b3==1) color=-5; else color=-12;
                ((DrawF)f_1483f0)(d_1a34e0,x,lower+i,50,color);
            }
            b2=0;
        }
    } else if(f_042910((struct hero *)(hero))!=d_1a0515) {
        d_1a0515=f_042910((struct hero *)(hero));
        width=(unsigned char)d_1a0515>>1;
        for(i=0;i<6;i++) {
            ((DrawF)f_1483f0)(d_1a34e0,x,lower+i,width,-5);
            ((DrawF)f_1483f0)(d_1a34e0,x+width,lower+i,50-width,-12);
        }
    }
}
