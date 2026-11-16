/* === Beschreibung (Katalog) ===
 * Einheit: ace_t2b
 *
 * Adressbereich: 0x011e00-0x012400
 * Spielsystem: Spielstand & Zustandsvariablen - 16-Bit-Wort-Fassung des Template-Codes für
 * Spielvariablen-Register (insbesondere das globale Wort-Register d_1c2130 mit Spielstand-Kennung 'WVAR').
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAACE.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// P3 17/27 gleich (suche.py 26.10.2026, Basis ace_t2_P1.CPP)
// P1 2/26 GLEICH, Rest: Wait-Schleifen (sete-Muster) 0116a0 0116d0 011700; Stapel/Register in read/write-Funktionen; 011da0/0123a0 und 011dc0/0123c0 vom Compiler gefaltet; 011680 011dd0 0123d0 nur Fuellbytes
// ace.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0104B0-0x012A00
#include <string.h>
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_014540(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_068f40();                                         // reg - stapel 0
int f_099ef0(int p1, int p2, int p3, int p4);           // reg - stapel 0
int f_0a2520(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg edx ebx ecx stapel 12
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3420(int p1, int p2, int p3, int p4);           // reg eax edx ebx ecx stapel 0
int f_0fabf0(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1b62ec;                    // 0x1B62EC
extern int d_1bc5f0;                    // 0x1BC5F0
extern short d_1bc5f4;                    // 0x1BC5F4
extern int d_1bc5f6;                    // 0x1BC5F6
extern int d_1bc5f8;                    // 0x1BC5F8
extern const char d_1a0134[];           // Text 0x1A0134
#include <io.h>
#define VR(s,b,n) (s)->vt->read(s,b,n)
#define VW(s,b,n) (s)->vt->write(s,b,n)
#define EQ(x,v) (((x)==(v))?1:0)
struct RivaAceShortEntry2 {
    short v;
    short id;
    short gv() { return v; }
    short gid() { return id; }
    void sv(short x) { v = x; }
};
struct RivaAceShortRegister2 {
    short cap;
    short n;
    RivaAceShortEntry2 **arr;
};
#define RivaAceShortEntry RivaAceShortEntry2
#define RivaAceShortRegister RivaAceShortRegister2
//@ f_011e00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht ein 16-Bit-Wort-Variablenregister (z. B. d_1c2130) nach dem ersten Eintrag mit
 *   der angegebenen Kennnummer.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1) und gesuchte Kennnummer (p2); gibt den Zeiger auf den
 *   gefundenen 4-Byte-Variableneintrag oder 0 zurück.
 * - Wichtige Variablen & Daten: Durchläuft p1->arr[0 .. p1->n - 1].
 * - Besonderheiten / Originalfehler: Wie in den Schwesterfunktionen f_011790 und f_012400 wird der Suchwert als
 *   vorzeichenbehaftetes (short)p2 mit einer vorzeichenlosen unsigned short id = t->id verglichen, sodass
 *   Kennnummern >= 0x8000 nie gefunden werden können.
 === Ende Beschreibung === */
RivaAceShortEntry *f_011e00(RivaAceShortRegister *p1, int p2)
{
    RivaAceShortEntry *r = 0;
    short i = 0;
    for (; i < p1->n; i++) {
        int key = (short)p2;
        if (r != 0) return r;
        RivaAceShortEntry *t = p1->arr[i];
        unsigned short id = t->id;
        if (id == key) r = t;
    }
    return r;
}
//@ f_011e50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt beim Laden eines Spielstands (aufgerufen aus diskmen2_t1 nach der Blockkennung
 *   'WVAR') alle gespeicherten 16-Bit-Wort-Spielvariablen aus der Spielstanddatei und überträgt ihre Werte
 *   anhand der Kennnummer in das Wort-Register d_1c2130.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1, d_1c2130) und Dateihandle (p2, d_1c2140); gibt 1 bei
 *   Erfolg (auch bei n <= 0), 0 bei Lesefehler zurück.
 * - Wichtige Variablen & Daten: Überliest das 2-Byte-Längenfeld, liest die Anzahl n sowie n * 2 Bytes Werte (b1)
 *   und n * 2 Bytes Kennnummern (b2) und ordnet die Werte passenden Einträgen t->id == b2[i] zu.
 === Ende Beschreibung === */
int f_011e50(RivaAceShortRegister *p1, int p2)
{
    unsigned short fd = (unsigned short)p2;
    short n;
    short *b1;
    short total;
    int r;
    short *b2;
    read((short)fd, &total, 2);
    r = 0;
    if (read((short)fd, &n, 2) == 2)
    {
        if (n > 0)
        {
            short i, j;
            b1 = new (mark(d_1a0134, 0x1e7)) short[n];
            b2 = new (mark(d_1a0134, 0x1e8)) short[n];
            if (read((short)fd, b1, n * 2) == n * 2u)
            {
                if (read((short)fd, b2, n * 2) == n * 2)
                {
                    for (i = 0; i < n; i++)
                    {
                        for (j = 0; j < p1->n; j++)
                        {
                            if (p1->arr[j]->gid() == b2[i])
                            {
                                p1->arr[j]->sv(b1[i]);
                                break;
                            }
                        }
                    }
                    r = 1;
                }
            }
            delete b1;
            delete b2;
        }
        else
            r = 1;
    }
    return r;
}
//@ f_011fb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt beim Speichern eines Spielstands (aufgerufen aus diskmen2_t1 nach der Kennung
 *   'WVAR') sämtliche Einträge des Wort-Registers d_1c2130 als Block (Länge 2 + 4*n, Anzahl n, Wertefeld,
 *   Nummernfeld) in die Spielstanddatei.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1) und Dateihandle (p2); gibt 1 bei Erfolg (auch bei
 *   leerem Register), 0 bei Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Sammelt die 16-Bit-Werte in Puffer a und die 16-Bit-Kennnummern in Puffer b und
 *   schreibt beide mit write.
 === Ende Beschreibung === */
int f_011fb0(RivaAceShortRegister *p1, int p2)
{
    struct Frame { short *a; int r; int fd; } frame;
    frame.fd = p2;
    frame.r = 0;
    short tot = 2;
#define a frame.a
#define r frame.r
#define p2 frame.fd

    tot = tot + p1->n * 2;
    tot = tot + p1->n * 2;
    write((short)p2, &tot, 2);
    if (write((short)p2, &p1->n, 2) == 2) {
        if (p1->n > 0) {
            short *b;
            short i;
            a = (short *)operator new[](p1->n * 2, mark(d_1a0134, 0x1a3));
            b = (short *)operator new[](p1->n * 2, mark(d_1a0134, 0x1a4));
            i = 0;
            if (i < p1->n) {
                do {
                    a[i] = p1->arr[i]->v;
                    b[i] = p1->arr[i]->id;
                    i++;
                } while (i < p1->n);
            }
            if (write((short)p2, a, p1->n * 2) == p1->n * 2) {
                if (write((short)p2, b, p1->n * 2) == p1->n * 2)
                    r = 1;
            }
            delete a;
            delete b;
        } else {
            r = 1;
        }
    }
    return r;
#undef p2
#undef r
#undef a
}
//@ f_012100
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt 16-Bit-Wort-Variablen ohne Längenfeld über die virtuelle Lesemethode vt[8] aus einem
 *   Strom-Objekt (Anzahl c, c * 2 Bytes Werte, c * 2 Bytes Kennnummern) in das angegebene Wort-Register.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1) und Zeiger auf das Strom-Objekt (p2); gibt 1 bei
 *   Erfolg, 0 bei unlesbarer Anzahl oder c <= 0 zurück.
 * - Wichtige Variablen & Daten: Temporäre short-Arrays a (Werte) und b (Nummern), Strom-Lesemethode vt[8].
 * - Besonderheiten / Originalfehler: Schlägt das Lesen des Wertefelds (VR(p2, a, c * 2)) fehl, gibt die Funktion
 *   wie f_011ad0 und f_012700 im else-Zweig fälschlich 1 (Erfolg) zurück und gibt die mit new angeforderten
 *   Puffer a und b nicht frei (Speicherleck).
 === Ende Beschreibung === */
int f_012100(RivaAceShortRegister *p1, RivaFileStream *p2)
{
    short *a;
    int r = 0;
    short c;
    short *b;
    if (VR(p2, &c, 2) == 2 && c > 0) {
        short j, i;
        a = new (mark(d_1a0134, 342)) short[c];
        b = new (mark(d_1a0134, 343)) short[c];
        if (VR(p2, a, c * 2) == c * 2u) {
            if (VR(p2, b, c * 2) == c * 2) {
                for (i = 0; i < c; i++) {
                    for (j = 0; j < p1->n; j++) {
                        if (p1->arr[j]->gid() == b[i]) {
                            p1->arr[j]->sv(a[i]);
                            break;
                        }
                    }
                }
                r = 1;
            }
            delete a;
            delete b;
        } else {
            r = 1;
        }
    }
    return r;
}

//@ f_012270
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt alle Einträge eines 16-Bit-Wort-Registers ohne Längenfeld über die virtuelle
 *   Schreibmethode vt[9] in ein Strom-Objekt.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1) und Zeiger auf das Strom-Objekt (p2); gibt 1 bei
 *   Erfolg, 0 bei Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Temporäre short-Arrays b1 (Werte) und b2 (Nummern), Strom-Schreibmethode vt[9].
 === Ende Beschreibung === */
int f_012270(RivaAceShortRegister *p1, RivaFileStream *p2)
{
    short *b1 = 0;
    short *b2;
    int r = 0;
    if (VW(p2, &p1->n, 2) == 2)
    {
        if (p1->n != 0)
        {
            short i;
            b1 = new (mark(d_1a0134, 0x115)) short[p1->n];
            b2 = new (mark(d_1a0134, 0x116)) short[p1->n];
            for (i = 0; i < p1->n; i++)
            {
                b1[i] = p1->arr[i]->v;
                short v = p1->arr[i]->id;
                b2[i] = v;
            }
            if (VW(p2, b1, p1->n * 2) == p1->n * 2u)
            {
                if (VW(p2, b2, p1->n * 2) == p1->n * 2)
                    r = 1;
            }
            delete b1;
            delete b2;
        }
        else
            r = 1;
    }
    return r;
}

//@ f_0123a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hängt einen Variableneintrag hinten an das Wort-Register an und erhöht n um 1 (vom
 *   Compiler mit f_011da0 gefaltet).
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (p1) und Eintragszeiger (p2); keine Rückgabe.
 * - Wichtige Variablen & Daten: Schreibt p1->arr[p1->n] = p2 und erhöht p1->n ohne Kapazitätsprüfung.
 === Ende Beschreibung === */
void f_0123a0(RivaAceShortRegister *p1, void *p2)
{
    p1->arr[p1->n] = (RivaAceShortEntry *)p2;
    p1->n = p1->n + 1;
}
//@ f_0123c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor des Wort-Registers (mit f_011dc0 gefaltet): gibt das Zeigerfeld arr frei.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (this) und ungenutzter Destruktorschalter; gibt this
 *   zurück.
 * - Wichtige Variablen & Daten: Gibt p1->arr frei.
 === Ende Beschreibung === */
RivaAceShortRegister *f_0123c0(RivaAceShortRegister *p1, int p_unused1)
{
    delete p1->arr;
    return p1;
}
//@ f_0123d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des Wort-Registers: initialisiert Anzahl n = 0, Kapazität cap = p2 und fordert
 *   über f_014540 das Zeigerfeld (p2 * 4 Bytes) an.
 * - Eingaben / Rückgabe: Zeiger auf das Wort-Register (this) und Kapazität (p2); gibt this zurück.
 * - Wichtige Variablen & Daten: Felder n, cap und arr des Registers.
 === Ende Beschreibung === */
RivaAceShortRegister *f_0123d0(RivaAceShortRegister *p1, int p2)
{
    p1->n = 0;
    p1->cap = (short)p2;
    p1->arr = (RivaAceShortEntry **)f_014540((short)p2 * 4, (int)d_1a0134, 0xd3);
    return p1;
}
