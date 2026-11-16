/* === Beschreibung (Katalog) ===
 * Einheit gen (0x092F40-0x0945C0)
 *
 * Überblick
 * Die Einheit gen (im Original gen.cpp) implementiert den ersten Teil des Charakter-Generators (struct Gen), mit
 * dem der Spieler neue Helden erschafft, deren Namen und Porträt wählt, durch die bis zu 11 Eigenschafts-,
 * Talent- und Zauberseiten blättert und den Hauptdialog des Generators bedient.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMOUS.H"
#include "RIVAFILE.H"
// E2 Entwurf 7/10 gleich
// gen.cpp (Schatten ueber Riva, Attic 1996) - E2 Entwurf, Code 0x092F40-0x0945C0
#include <string.h>
#define Z98 (d_1c2198)
#define YV yy
static inline char NEC(int a, int b) { return a != b; }
#define NEI(x,v) (((x)!=(v))?1:0)
#define EQI(x,v) (((x)==(v))?1:0)
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
extern const char d_1a2988[];                            // Text "p:\riva\source\cpp\gen.cpp"

#include "RIVAIMG.H"   // 0x0FAC80 / 0x0FAC10 / 0x0FAD20

struct Gen {                                             // Fenster "Charakter-Generator", Basis-Objekt bei +0x3C (0xA3 Byte)
    signed char c0;                                      // +0
    short s1;                                            // +1
    short s3;                                            // +3
    short s5;                                            // +5
    signed char c7;                                      // +7 Seite 0..10
    char p8[8];
    int x10;                                             // +0x10
    char p14[0x0e];
    short s22;                                           // +0x22
    int x24;                                             // +0x24
    int x28, x2c, x30, x34, x38;
    char w3c[0xa3];                                      // +0x3C Unterobjekt (Ctor 0x1459B0, Dtor 0x1459D0)
    int cdf;                                             // +0xDF Charakter
    RivaRasterImage *i_e3, *i_e7, *i_eb, *i_ef, *i_f3, *i_f7, *i_fb, *i_ff, *i_103, *i_107, *i_10b, *i_10f, *i_113, *i_117;
    int x11b;
};

int f_014540(int n, int file, int line);
int f_01e0c0();
short f_036ed0(int p1);
int f_040e90(int p1);









char f_043ac0(int p1, int p2);
int f_043e20(int p1, int p2);
int f_044ea0(int p1);
int f_04feb0(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9);
int f_05dec0(int p1);
int f_05ded0(int p1, int p2);
int f_05e320(int p1, int p2, int p3);
int f_05e360(int p1, int p2, int p3);
int f_068f40();
void f_094330(Gen *p);
void f_094700(Gen *p);
void f_095c40(Gen *p);
void f_096790(Gen *p, int v);
void f_096960(Gen *p);
void f_0969c0(Gen *p);
void f_096d40(Gen *p);
void f_0971f0(Gen *p);
#pragma aux f_0971f0 parm [eax] modify exact [eax]
void f_097600(Gen *p, int a, int b, int c);
void f_097700(Gen *p);
void f_0978a0(Gen *p);
void f_097960(Gen *p, int v);
void f_097ac0(Gen *p);
void f_098240(Gen *p);
void f_098730(Gen *p);
short f_098a90(Gen *p);
void f_098d90(Gen *p, int a, int b);
short f_098fe0(int p1, int p2, int p3);
struct Msg { int f_0bf6f0(int code); int f_0bf730(int code); int f_0c0000(int v); };
short f_0bf820(int p1, ...);
int f_0c0000(int p1, int p2);
short f_0bfea0(int p1, int p2, int p3);


int f_0d37b0();

int f_0d3f25(int p1, int p2);
int f_0d4800(int p1);
int f_0d5a90();
int f_0d5b50(int p1);
int f_0e4d80(int p1);
int f_0e9510(int p1, int p2, int p3, int p4);
short f_0e95d0(int p1, int p2, int p3, int p4);
int f_0e9660(int p1, int p2, int p3, int p4);
short f_0e9690(int p1, int p2);
int f_09a0d0(int p1);










char f_145400(unsigned c);
int f_145450(int p1);
int f_1459b0(int p1);
int f_1459d0(int p1, int p2);
int f_145a40(int p1, int p2, int p3);
int f_145b10(int p1);

extern int d_1bc760, d_1bc898, d_1bc89c, d_1bc8a0, d_1bc8a4;
extern int d_1a34e0, d_1c2a80, d_1c0c4c;
extern volatile int d_1bf514;
extern int d_1a3190[];
extern volatile short d_1c2198;
extern short d_1bd766;
extern Msg d_1c2c64;
extern signed char d_1bfaec;
extern char d_1a2984;
extern char  d_1c2be0[], d_1c2e78[], d_1c38b0[], d_1c3068[];
extern signed char d_1c299c[];
extern char d_1c299d[];
extern signed char d_1a3204[], d_1a3205[], d_1a3210[];
struct T16 { char c[16]; };
extern T16 d_1bdbb4;
extern short d_1a31bc[];



#define BUF(sz, line) f_014540(sz, (int)d_1a2988, line)
#define NEWIMG(line, a, b) new (mark(d_1a2988, line)) RivaRasterImage(a, b)
#define NEWIMG3(line, a, b, c) new (mark(d_1a2988, line)) RivaRasterImage(a, b, (void *)(c))
#define SEL(img, idx) f_04feb0((int)d_1c2be0, 0xe0013, ((int)(((RivaRasterImage*)(img))->f_0fb0b0())), 0, idx, 0, (int)&p->s22, (int)&p->s22, 0x140);
#define IMGB(img, a, b) { f_0d2710(); ((RivaRasterImage*)(img))->f_0fade0((void *)( d_1a34e0), a, b); f_0d26e0(); }
#define IMGCHAR { RivaRasterImage im(0x20, 0x20, 0); ((RivaRasterImage*)(&im))->f_0fb060((void *)( f_044ea0(p->cdf))); ((RivaRasterImage*)(&im))->f_0fade0((void *)( d_1a34e0), 0x110, 4); }

//@ f_092f40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des Charakter-Generators (Gen). Initialisiert das eingebettete
 *   Fenster-Basisobjekt p->w3c (f_1459b0), baut ein eventuell noch aktives Animationsobjekt d_1bc760 ab
 *   (f_01e0c0), reserviert die Arbeitspuffer sowie den 0x5ef Bytes großen Helden-Datensatz p->cdf und den
 *   64000-Byte-Hintergrundpuffer p->x38, lädt die Generator-Tabellen und Grafiken (0xe000b..0xe0010 und
 *   Schaltflächen-Sprites aus 0xe0013) über d_1c2098 und öffnet das Generator-Grundfenster 0xe0000.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Gen * (p).
 * - Wichtige Variablen:
 *   - p->cdf (int): Zeiger auf den 0x5ef Bytes großen Helden-Datensatz im Generator.
 *   - p->x38 (int): 64000-Byte-Hintergrundpuffer (320x200 Pixel).
 *   - p->c7 (signed char): Aktuell angezeigte Generator-Seite (0..10).
 === Ende Beschreibung === */
Gen *f_092f40(Gen *p)
{
    p = (Gen *)(f_1459b0((int)p->w3c) - 0x3c);
    if (d_1bc760 != 0) f_01e0c0();
    p->x10 = BUF(0x60, 0x18d);
    d_1bc89c = BUF(0x68, 0x18e);
    d_1bc8a0 = BUF(0xac, 0x18f);
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448b0( 0xe0010, 0x200);
    int n = ((int)(((RivaFileManager*)((int)((char*)&d_1c2098)))->f_144a00()));
    d_1bc898 = BUF(n, 0x193);
    ((int)(((RivaFileManager*)((int)((char*)&d_1c2098)))->f_144920((void *)( d_1bc898), n)));
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1449a0();
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448d0( 0xe000c,(void *)( p->x28 = BUF(0x9c, 0x197)));
    p->x2c = BUF(0x2a4, 0x19a);
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448d0( 0xe000e,(void *)( p->x2c));
    int x30 = BUF(0x204, 0x19d);
    *(volatile int *)&p->x30 = x30;
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448d0( 0xe000f,(void *)( x30));
    d_1bc8a4 = BUF(0x129, 0x1a0);
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448d0( 0xe000d,(void *)( d_1bc8a4));
    p->x34 = BUF(0x21c, 0x1a3);
    ((RivaFileManager*)((int)((char*)&d_1c2098)))->f_1448d0( 0xe000b,(void *)( p->x34));
    p->cdf = BUF(0x5ef, 0x1a6);
    p->x38 = BUF(64000, 0x1a8);
    p->x11b = 0;
    p->i_e7 = NEWIMG(0x1ac, 0x5e, 9);
    p->i_f7 = NEWIMG(0x1ad, 0xd, 0xd);
    p->i_fb = NEWIMG(0x1ae, 0xd, 0xd);
    p->i_ff = NEWIMG(0x1af, 0x16, 10);
    p->i_103 = NEWIMG(0x1b0, 0x16, 10);
    p->i_107 = NEWIMG(0x1b1, 0x16, 10);
    p->i_10b = NEWIMG(0x1b2, 0x16, 10);
    p->i_10f = NEWIMG(0x1b3, 0x16, 10);
    p->i_113 = NEWIMG(0x1b4, 0x16, 10);
    p->i_117 = NEWIMG(0x1b5, 0x80, 0xb8);
    p->i_e3 = NEWIMG3(0x1b6, 0x140, 200, p->x38);
    p->i_eb = 0;
    p->i_ef = 0;
    p->i_f3 = 0;
    SEL(p->i_f7, 0)
    SEL(p->i_fb, 1)
    SEL(p->i_ff, 2)
    SEL(p->i_107, 3)
    SEL(p->i_10f, 4)
    SEL(p->i_103, 5)
    SEL(p->i_10b, 6)
    SEL(p->i_113, 7)
    p->c7 = 0;
    p->x24 = 0;
    d_1c2c64.f_0c0000(-100);
    f_09a0d0(d_1a34e0);
    f_145a40((int)p->w3c, 0xe0000, p->x38);
    f_145b10((int)p->w3c);
    return p;
}

//@ f_0934f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor des Charakter-Generators (Gen). Gibt alle angelegten RivaRasterImage-Sprites
 *   (i_e3 bis i_117), den Helden-Puffer p->cdf, den Bildschirm-Zwischenpuffer p->x38 sowie sämtliche geladenen
 *   Generator-Tabellen (x28, x2c, x30, x34, d_1bc898, d_1bc89c, d_1bc8a0, d_1bc8a4, x10) wieder frei, stellt die
 *   Farbpalette über f_09a0d0 wieder her und ruft den Basis-Destruktor f_1459d0 auf.
 * - Eingaben: Gen *p (this-Zeiger), int flag (Destruktor-Flag).
 * - Rückgabewert: Gen * (p).
 * - Wichtige Variablen: d_1c2198 (volatile short, Neuzeichnen-Flag, wird auf 1 gesetzt).
 === Ende Beschreibung === */
Gen *f_0934f0(Gen *p, int flag)
{
    if (p->i_eb) delete p->i_eb;
    if (p->i_ef) delete p->i_ef;
    if (p->i_f3) delete p->i_f3;
    delete p->i_e3;
    delete p->i_117;
    delete p->i_ff;
    delete p->i_103;
    delete p->i_107;
    delete p->i_10b;
    delete p->i_10f;
    delete p->i_113;
    delete p->i_fb;
    delete p->i_f7;
    delete p->i_e7;
    operator delete((void *)p->cdf);
    operator delete((void *)p->x38);
    operator delete((void *)p->x28);
    operator delete((void *)p->x2c);
    operator delete((void *)p->x30);
    operator delete((void *)d_1bc8a4);
    operator delete((void *)p->x34);
    operator delete((void *)d_1bc898);
    operator delete((void *)d_1bc89c);
    operator delete((void *)d_1bc8a0);
    operator delete((void *)p->x10);
    f_09a0d0(d_1a34e0);
    d_1c2198 = 1;
    d_1c2c64.f_0c0000(0);
    return (Gen *)(f_1459d0((int)p->w3c, 0) - 0x3c);
}

//@ f_0936d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet den Namen des aktuellen Helden (f_0422b0(p->cdf)) in das Namensfeld oben rechts
 *   (X = 0xb4, Y = 0x0c) des Charakter-Generators, wobei der Name zuvor auf eine maximale Pixelbreite von 0x5a
 *   (90 Pixel) gekürzt und der Feldhintergrund über das Sprite p->i_e7 restauriert wird.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->i_e7 (RivaRasterImage *, Hintergrundstreifen des Namensfeldes).
 === Ende Beschreibung === */
void f_0936d0(Gen *p)
{
    T16 buf = d_1bdbb4;
    char nm[16];
    short done = 0;
    strcpy(nm, (char *)((int)(f_0422b0((struct hero *)(p->cdf)))));
    short i = 0;
    do {
        buf.c[i] = nm[i];
        if (!nm[i]) done = 1;
        if (f_0e9690((int)d_1c38b0, (int)&buf) > 0x5a) {
            done = 1;
            buf.c[i] = 0;
        }
        i++;
    } while (!done);
    RivaMouseGuard mg;
    ((RivaRasterImage*)(p->i_e7))->f_0fade0((void *)( f_05dec0((int)d_1c3068)), 0xb0, 0xc);
    f_05e320((int)d_1c38b0, 0xff, -1);
    f_0e9660((int)d_1c38b0, (int)&buf, 0xb4, 0xc);
}

//@ f_0937e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet das Texteingabefeld (f_0bfea0 mit Text-ID 0xe140002, maximal 15 Zeichen) zur
 *   Eingabe oder Änderung des Heldennamens. Wurde die Eingabe nicht abgebrochen (!= -1), wandelt die Funktion
 *   den eingegebenen String in d_1c299c zunächst komplett in Kleinbuchstaben um (f_145450), schreibt den ersten
 *   Buchstaben sowie jeden Buchstaben nach einem Leerzeichen groß (f_145400), entfernt abschließende Leerzeichen
 *   am Wortende, trägt den Namen über f_0422f0 und f_0422c0 in den Helden-Datensatz p->cdf ein und aktualisiert
 *   die Anzeige über f_0936d0(p).
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c299c (signed char[]): Globaler Texteingabepuffer für den Heldennamen.
 *   - Hinweis (Originalfehler): Die Schleife zum Entfernen nachfolgender Leerzeichen (i--; while (d_1c299c[i] ==
 *     0x20) { d_1c299c[i] = 0; i--; }) besitzt keine Untergrenzenprüfung i >= 0. Besteht die Eingabe
 *     ausschließlich aus Leerzeichen, läuft i unter 0 ins Negative und überschreibt Bytes vor d_1c299c, falls
 *     dort 0x20 steht; außerdem beginnt die vorherige Schleife ungeprüft bei i = 1, selbst wenn d_1c299c[0] == 0
 *     (leere Eingabe) ist.
 === Ende Beschreibung === */
void f_0937e0(Gen *p)
{
    if (f_0bfea0((int)&d_1c2c64, 0xf, 0xe140002) != -1) {
        f_145450((int)d_1c299c);
        d_1c299c[0] = f_145400((unsigned char)d_1c299c[0]);
        short i = 1;
        while (d_1c299c[i] != 0) {
            if (d_1c299c[i] == 0x20 && d_1c299d[i] != (char)0)
                d_1c299d[i] = f_145400(d_1c299d[i]);
            i++;
        }
        i--;
        while (d_1c299c[i] == 0x20) {
            d_1c299c[i] = 0;
            i--;
        }
        f_0422f0((struct hero *)(p->cdf),(char *)( (int)d_1c299c));
        f_0422c0((struct hero *)(p->cdf),(char *)( (int)d_1c299c));
        f_0936d0(p);
    }
}

//@ f_0938a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet das 32x32 Pixel große Porträtbild (f_044ea0(p->cdf)) des aktuell im Generator
 *   bearbeiteten Helden an die Bildschirmposition (0x110, 4).
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->cdf (Helden-Datensatz).
 === Ende Beschreibung === */
void f_0938a0(Gen *p)
{
    IMGCHAR
}

//@ f_093900
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Porträtauswahl (f_098fe0) für den aktuell bearbeiteten Helden, sofern bereits
 *   ein Archetyp/Typus gewählt wurde (f_042350(p->cdf) != 0; sonst Fehlermeldung 0xe14000e). Bestimmt anhand des
 *   Geschlechts (f_042380) und der Charakterklasse p->c0 über die Tabellen d_1a3204, d_1a3210 und d_1a3205 den
 *   zulässigen Bereich von Porträt-Indizes p->s3..p->s5, speichert das gewählte Porträt (f_042330) und zeichnet
 *   es oben rechts neu.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p->c0 (signed char): Gewählter Heldentypus-Index.
 *   - p->s3, p->s5 (short): Erster und letzter Porträt-Index für diesen Typus und dieses Geschlecht.
 *   - p->s1 (short): Ausgewählter Porträt-Index.
 === Ende Beschreibung === */
void f_093900(Gen *p)
{
    char tbl[0x48];
    if (!((char)(f_042350((struct hero *)(p->cdf))))) {
        d_1c2c64.f_0bf730(0xe14000e);
        return;
    }
    memcpy(tbl, d_1a31bc, 0x48);
    if (((char)(f_042380((struct hero *)(p->cdf))))) {
        p->s3 = d_1a3210[p->c0];
        p->s5 = d_1a3205[p->c0] - 1;
    } else {
        p->s3 = d_1a3204[p->c0];
        p->s5 = d_1a3210[p->c0] - 1;
    }
    short l = p->s5 - p->s3 + 1;
    short w = f_098fe0((int)&d_1c2c64, l, p->s3);
    if (w != -1) {
        p->s1 = w;
        f_042330((struct hero *)(p->cdf), p->s1);
    }
    {
        RivaMouseGuard m;
        IMGCHAR
    }
}
//@ f_093a50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Animiert das kurze Aufleuchten bzw. Eindrücken der rechten Blättern-Pfeiltaste an der
 *   Position (0x121, 0xb6) durch Zeichnen von p->i_113, kurzes Warten (f_0d4800(0x14)) und anschließendes
 *   Wiederherstellen von p->i_10b.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->i_113, p->i_10b (RivaRasterImage *, gedrückter und normaler Rechts-Pfeil).
 === Ende Beschreibung === */
void f_093a50(Gen *p)
{
    IMGB(p->i_113, 0x121, 0xb6)
    f_0d4800(0x14);
    IMGB(p->i_10b, 0x121, 0xb6)
}

//@ f_093ab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Animiert das Eindrücken der linken Blättern-Pfeiltaste (p->i_10f / p->i_107), die je nach
 *   aktueller Generator-Seite p->c7 entweder bei (0x90, 0xb6) (Seiten 0..4) oder bei (0x11, 0xb6) (Zauberseiten
 *   5..10) liegt.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: p->c7 (Seitennummer), p->i_10f, p->i_107 (RivaRasterImage *).
 === Ende Beschreibung === */
void f_093ab0(Gen *p)
{
    if (p->c7 < 5) {
        IMGB(p->i_10f, 0x90, 0xb6)
        f_0d4800(0x14);
        IMGB(p->i_107, 0x90, 0xb6)
    } else {
        IMGB(p->i_10f, 0x11, 0xb6)
        f_0d4800(0x14);
        IMGB(p->i_107, 0x11, 0xb6)
    }
}

#define BLKAB { if (p->c7 < 5) { IMGB(p->i_10f, 0x90, YV) f_0d4800(0x14); IMGB(p->i_107, 0x90, YV) } else { IMGB(p->i_10f, 0x11, YV) f_0d4800(0x14); IMGB(p->i_107, 0x11, YV) } }

//@ f_093bb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Haupt-Ereignisschleife des Charakter-Generators. Zeichnet bei Bedarf (d_1c2198 != 0) die
 *   aktuelle Seite über f_094330(p) neu, liest Maus- und Tastatureingaben über die seitenabhängige
 *   Hotspot-Tabelle d_1a3190[p->c7] ein, öffnet bei Rechtsklick (oder wenn noch kein Charakter existiert) das
 *   Hauptmenü der jeweiligen Seite (auf Seite 0 das 11-teilige Generator-Menü zum Generieren, Laden, Speichern,
 *   Löschen, Umbenennen, Porträt- und Geschlechtswechsel sowie Beenden), verarbeitet Klicks auf
 *   Eigenschaften/Talente/Zauber (d_1bd766 im Bereich 4..0x5f) sowie das Blättern zwischen den Seiten 0..4 (bzw.
 *   0..10 für Magiekundige) mit den Pfeiltasten oder Reitern.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: int (p->x24, Statuscode beim Verlassen des Generators).
 * - Wichtige Variablen:
 *   - d_1a3190 (int[]): Tabelle der Hotspot-Listen für die Seiten 0..10.
 *   - d_1bd766 (short): Zuletzt ausgelöster Tasten- oder Hotspot-Code.
 *   - d_1bfaec (signed char): Flag, ob bereits ein vollständiger Charakter zum Durchblättern bereitsteht.
 === Ende Beschreibung === */
int f_093bb0(Gen *p)
{
    short sy, sx;
    short yy = 0xb6;
    short quit = 0;
    short r;
    d_1c2198 = 1;
    d_1c0c4c = d_1c0c4c + 1;
    f_0d3f25((int)d_1c2e78, 4);
    f_05e360((int)d_1c38b0, (int)&sx, (int)&sy);
    f_05e320((int)d_1c38b0, 0xff, -1);
    do {
        if (Z98) f_094330(p);
        d_1bf514 = d_1a3190[p->c7];
        f_068f40();
        f_0d5a90();
        d_1bf514 = 0;
        if (d_1bd766 == 0x11b && d_1c2c64.f_0bf6f0(0xe140034) == 1) quit = 1;
        if (f_0d37b0() != 0 || d_1bd766 == 0x4900 || !((char)(f_042350((struct hero *)(p->cdf))))) {
            f_0d5b50(0);
            switch ((unsigned char)p->c7) {
            case 0: {
                r = f_0bf820((int)&d_1c2c64, 0xe140004, 0xb, 0xe140037, 0xe14000b, 0xe140009, 0xe14000c, 0xe140007, 0xe140008, 0xe140042, 0xe140044, 0xe140006, 0xe140005, 0xe140033);
                if (r != -1 && ((r != 1 && r != 2 && r != 10) || !f_043ac0(p->cdf, 0) || d_1c2c64.f_0bf6f0(0xe14000a) == 1)) {
                    d_1bd766 = 0;
                    switch ((unsigned short)--r) {
                    case 0: f_0969c0(p); break;
                    case 1: f_094700(p); break;
                    case 2: f_098730(p); break;
                    case 3: f_096d40(p); break;
                    case 4: f_0937e0(p); break;
                    case 5: f_097700(p); break;
                    case 6: f_093900(p); break;
                    case 7:
                        if (!((char)(f_042350((struct hero *)(p->cdf))))) {
                            d_1c2c64.f_0bf730(0xe140015);
                        } else {
                            if (d_1c2c64.f_0bf6f0(0xe140045) == 1) f_0e4d80(p->cdf);
                        }
                        break;
                    case 8:
                        if (f_098a90(p)) {
                            memset((void *)p->cdf, 0, 0x5ef);
                            f_043e20(p->cdf, 1);
                            f_0978a0(p);
                            d_1c2198 = 1;
                        }
                        break;
                    case 9:
                        memset((void *)p->cdf, 0, 0x5ef);
                        f_043e20(p->cdf, 1);
                        f_0978a0(p);
                        d_1c2198 = 1;
                        break;
                    case 10:
                        if (d_1c2c64.f_0bf6f0(0xe140034) == 1) quit = 1;
                        break;
                    }
                }
                break;
            }
            case 1: case 2: case 3:
                f_098240(p);
                break;
            case 4:
                f_096960(p);
                break;
            case 5: case 6: case 7: case 8: case 9: case 10:
                f_097ac0(p);
                break;
            }
            f_0d5b50(0);
        }
        if (d_1bd766 >= 4 && d_1bd766 < 0x60) {
            if (p->c7 >= 1 && p->c7 < 4) {
                if (!((char)(f_043340((struct hero *)(p->cdf))))) {
                    d_1c2c64.f_0bf730(0xe140024);
                } else {
                    short sd = d_1bd766 - 4;
                    r = f_036ed0(sd);
                    f_097600(p, sd, r, r == 1 ? 0xe140026 : (r == 2 ? 0xe140027 : 0xe140028));
                }
            } else {
                short sd = d_1bd766 - 4;
                if (p->c7 == 4) {
                    f_096790(p, sd);
                } else if (p->c7 >= 5 && p->c7 <= 10) {
                    if (!((char)(f_0432f0((struct hero *)(p->cdf))))) d_1c2c64.f_0bf730(0xe140024);
                    else f_097960(p, sd);
                }
            }
        }
        if (d_1bd766 == 0x60) f_097700(p);
        else if (d_1bd766 == 0x61) f_0937e0(p);
        else if (d_1bd766 == 0x62) f_093900(p);
        if (d_1bd766 == 0x4d00 && !EQI(d_1bfaec, 0)) {
            if (!((char)(f_042350((struct hero *)(p->cdf))))) {
                d_1c2c64.f_0bf730(0xe140015);
            } else {
                d_1c2198 = 1;
                IMGB(p->i_113, 0x121, YV)
                f_0d4800(0x14);
                IMGB(p->i_10b, 0x121, YV)
                int n = f_042a10((struct hero *)(p->cdf)) ? 10 : 4;
                if (p->c7 < n) ++p->c7; else p->c7 = 0;
            }
        }
        if (d_1bd766 == 0x4b00) {
            if (p->c7 > 0) {
                d_1c2198 = 1;
                BLKAB
                --p->c7;
            } else {
                if (!EQI(d_1bfaec, 0)) {
                    if (!((char)(f_042350((struct hero *)(p->cdf))))) {
                        d_1c2c64.f_0bf730(0xe140015);
                    } else {
                        d_1c2198 = 1;
                        BLKAB
                        p->c7 = f_042a10((struct hero *)(p->cdf)) ? 10 : 4;
                    }
                }
            }
        }
        if (d_1bd766 >= 0x231 && d_1bd766 <= 0x635 && EQI(d_1bfaec, 1) && ((char)(f_042350((struct hero *)(p->cdf))))) {
            if (d_1bd766 == 0x231) r = 0;
            else if (d_1bd766 == 0x332) r = 1;
            else r = d_1bd766 == 0x433 ? 4 : d_1bd766 == 0x534 ? 5 : 10;
            if (r != p->c7 && (r < 5 || f_042a10((struct hero *)(p->cdf)) != 0)) {
                p->c7 = (signed char)r;
                d_1c2198 = 1;
            }
        }
    } while (!quit);
    f_05e320((int)d_1c38b0, sx, sy);
    d_1c0c4c = d_1c0c4c - 1;
    return p->x24;
}

//@ f_094330
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Baut die komplette Bildschirmanzeige der aktuellen Generator-Seite p->c7 im
 *   Hintergrundpuffer p->x38 auf, lädt das zugehörige Seitenlayout 0xe0000 + p->c7 (f_145a40), zeichnet Rahmen,
 *   Geschlechtssymbol, Blättern-Pfeile, Charakterporträt oder Klassenbild (p->i_117), gibt sämtliche
 *   Eigenschafts-, Talent- oder Zauberwerte über f_095c40(p) aus und kopiert das fertige Bild auf den sichtbaren
 *   Bildschirm d_1a34e0.
 * - Eingaben: Gen *p (this-Zeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c2198 (volatile short): Flag für vollständigen Seiten-Neuaufbau (wird am Ende auf 0 zurückgesetzt).
 *   - d_1a2984 (char): Merker, ob das linke Klassen-/Vorschaufenster p->i_117 geleert werden muss.
 === Ende Beschreibung === */
void f_094330(Gen *p)
{
    if (Z98) {
        f_05ded0((int)d_1c3068, p->x38);
        d_1c2a80 = p->c7 + 0xe0000;
        f_145a40((int)p->w3c, d_1c2a80, p->x38);
        f_0971f0(p);
        if (p->c7 == (signed char)0) {
            ((RivaRasterImage*)(p->i_e7))->f_0fafb0((void *)( p->x38), 0xb0, 0xc);
            if (((char)(f_042380((struct hero *)(p->cdf))))) ((RivaRasterImage*)(p->i_fb))->f_0fade0((void *)( p->x38), 0x132, 3);
            if (EQI(d_1bfaec, 0)) {
                ((RivaRasterImage*)(p->i_103))->f_0fade0((void *)( p->x38), 0x121, 0xb6);
                ((RivaRasterImage*)(p->i_ff))->f_0fade0((void *)( p->x38), 0x90, 0xb6);
            }
        }
        if (p->c7 < 5) {
            if (((char)(f_042350((struct hero *)(p->cdf))))) {
                d_1a2984 = 1;
                ((RivaRasterImage*)(p->i_117))->f_0fade0((void *)( p->x38), 8, 8);
                f_05e320((int)d_1c38b0, 0xff, -1);
                short w = f_0e95d0((int)d_1c38b0, f_040e90(p->cdf), 8, 0x78);
                f_0e9510((int)d_1c38b0, f_040e90(p->cdf), w, 0xb8);
            } else {
                if (d_1a2984 != (char)0) {
                    ((RivaRasterImage*)(p->i_117))->f_0fb120();
                    ((RivaRasterImage*)(p->i_117))->f_0fade0((void *)( p->x38), 8, 8);
                    d_1a2984 = 0;
                }
                f_098d90(p, p->x38, 0);
            }
        }
        RivaMouseGuard mg;
        f_095c40(p);
        ((RivaRasterImage*)(p->i_e3))->f_0fade0((void *)( d_1a34e0), 0, 0);
        if (((char)(f_042350((struct hero *)(p->cdf))))) {
            IMGCHAR
        }
        f_05ded0((int)d_1c3068, d_1a34e0);
    } else {
        RivaMouseGuard mg;
        f_095c40(p);
    }
    d_1c2198 = 0;
}
