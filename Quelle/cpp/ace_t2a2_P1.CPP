/* === Beschreibung (Katalog) ===
 * Einheit: ace_t2a2
 *
 * Adressbereich: 0x011750-0x011e00
 * Spielsystem: Spielstand & Zustandsvariablen - Template-Instanzen zur Verwaltung, Suche und Serialisierung
 * (Spielstand 'DVAR' sowie Strom-Objekte) von registrierten Spielvariablen (vorwiegend
 * 32-Bit-Doppelwort-Register d_1c2138 sowie Initialisierer für 16-Bit- und 8-Bit-Variablen).
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
//@ f_011750
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert eine 16-Bit-Wort-Spielvariable mit Startwert und Kennnummer und trägt sie in
 *   das übergebene Wort-Variablenregister (im Spiel d_1c2130, Block 'WVAR') ein.
 * - Eingaben / Rückgabe: Zeiger auf das 4-Byte-Variablenobjekt, Zeiger auf das Wort-Register, Kennnummer (p3)
 *   und 16-Bit-Startwert (p4); keine Rückgabe.
 * - Wichtige Variablen & Daten: Wort-Variablenobjekt (short v bei +0, short id bei +2) und Register (cap, n,
 *   arr). Keine Kapazitätsprüfung gegen cap.
 === Ende Beschreibung === */
void f_011750(RivaAceShortEntry *p1, RivaAceShortRegister *p2, int p3, short p4)
{
    p1->v = p4;
    p1->id = (short)p3;
    p2->arr[p2->n] = p1;
    p2->n++;
}
//@ f_011770
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert eine 8-Bit-Byte-Spielvariable (oder Spieloption) mit Startwert und
 *   Kennnummer und hängt sie an das übergebene Byte-Variablenregister (z. B. d_1c2128 für 'BVAR' oder d_1bfad4
 *   für Optionen) an.
 * - Eingaben / Rückgabe: Zeiger auf das 3-Byte-Variablenobjekt, Zeiger auf das Byte-Register, Kennnummer (p3)
 *   und 8-Bit-Startwert (p4); keine Rückgabe.
 * - Wichtige Variablen & Daten: Byte-Variablenobjekt (char v bei +0, short id bei +1) und Register (cap, n,
 *   arr). Keine Kapazitätsprüfung gegen cap.
 === Ende Beschreibung === */
void f_011770(RivaAceByteEntry *p1, RivaAceByteRegister *p2, int p3, char p4)
{
    p1->v = p4;
    p1->id = (short)p3;
    p2->arr[p2->n] = p1;
    p2->n++;
}
//@ f_011790
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Durchsucht ein 32-Bit-Doppelwort-Variablenregister nach dem ersten Eintrag mit der
 *   angegebenen Kennnummer.
 * - Eingaben / Rückgabe: Zeiger auf das Doppelwort-Register (p1) und gesuchte Kennnummer (p2); gibt den Zeiger
 *   auf den gefundenen Variableneintrag oder 0 (falls nicht gefunden) zurück.
 * - Wichtige Variablen & Daten: Durchläuft p1->arr[0 .. p1->n - 1] und vergleicht die Kennnummer id.
 * - Besonderheiten / Originalfehler: Der Suchschlüssel wird vorzeichenbehaftet als (short)p2 nach int erweitert,
 *   die Eintragsnummer t->id jedoch als unsigned short gelesen (if (id == key)). Dadurch sind Kennnummern >=
 *   0x8000 (negativ als short) niemals auffindbar. Zudem prüft die Schleife erst zu Beginn des *nächsten*
 *   Durchlaufs if (r != 0) return r;, macht also nach einem Treffer noch einen unnötigen Schleifenschritt.
 === Ende Beschreibung === */
RivaAceIntEntry *f_011790(RivaAceIntRegister *p1, int p2)
{
    RivaAceIntEntry *r = 0;
    short i;
    for (i = 0; i < p1->n; i++) {
        int key = (short)p2;
        if (r != 0) return r;
        RivaAceIntEntry *t = p1->arr[i];
        unsigned short id = t->id;
        if (id == key) r = t;
    }
    return r;
}
//@ f_0117e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt beim Laden eines Spielstands (aufgerufen aus diskmen2_t1 nach der Blockkennung
 *   'DVAR') alle gespeicherten 32-Bit-Doppelwort-Spielvariablen aus der Spielstanddatei und weist die gelesenen
 *   Werte anhand ihrer Kennnummer den im Register (d_1c2138) angemeldeten Variablen zu.
 * - Eingaben / Rückgabe: Zeiger auf das Doppelwort-Register (p1, im Spiel d_1c2138) und Dateihandle der
 *   Spielstanddatei (p2, d_1c2140); gibt 1 bei Erfolg (auch bei n <= 0), 0 bei Lesefehler zurück.
 * - Wichtige Variablen & Daten: Liest 2 Bytes Blocklänge (wird ignoriert), 2 Bytes Anzahl n, danach n * 4 Bytes
 *   Werte in einen temporären Puffer b1 und n * 2 Bytes Kennnummern in b2. Unbekannte Kennnummern werden
 *   stillschweigend übergangen (Abwärts-/Aufwärtskompatibilität von Spielständen).
 === Ende Beschreibung === */
int f_0117e0(RivaAceIntRegister *p1, short p2)
{
    int fd = p2;
    short total, n;
    short *b2 = 0;
    int *b1 = 0;
    int r;
    read(fd, &total, 2);
    r = 0;
    if (read(fd, &n, 2) == 2)
    {
        if (n > 0)
        {
            short j, i;
            b1 = new (mark(d_1a0134, 0x1e7)) int[n];
            b2 = new (mark(d_1a0134, 0x1e8)) short[n];
            if (read(fd, b1, n * 4) == n * 4u)
            {
                if (read(fd, b2, n * 2) == n * 2)
                {
                    for (i = 0; i < n; i++)
                    {
                        for (j = 0; j < p1->n; j++)
                        {
                            short *id = &b2[i];
                            RivaAceIntEntry *t = p1->arr[j];
                            if (t->id == *id)
                            {
                                t->v = b1[i];
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

//@ f_011970
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt beim Speichern eines Spielstands (aufgerufen aus diskmen2_t1 nach dem Schreiben
 *   der 4-Byte-Kennung 'DVAR') sämtliche im Doppelwort-Register (d_1c2138) geführten Variablen als Datenblock
 *   (Blocklänge 2 + 6*n, Anzahl n, alle 32-Bit-Werte, alle 16-Bit-Nummern) in die Spielstanddatei.
 * - Eingaben / Rückgabe: Zeiger auf das Doppelwort-Register (p1) und Dateihandle (p2); gibt 1 bei Erfolg, 0 bei
 *   Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Legt temporäre Sammelarrays b1 (n Dwords) und b2 (n Words) an, schreibt sie mit
 *   write und gibt sie wieder frei.
 === Ende Beschreibung === */
int f_011970(RivaAceIntRegister *p1, int p2)
{
    int *b1;
    short *b2;
    int r = 0;
    short total = 2;
    total += p1->n * 4;
    total += p1->n * 2;
    write((short)p2, &total, 2);
    if (write((short)p2, &p1->n, 2) == 2)
    {
        if (p1->n > 0)
        {
            short i;
            b1 = new (mark(d_1a0134, 0x1a3)) int[p1->n];
            b2 = new (mark(d_1a0134, 0x1a4)) short[p1->n];
            for (i = 0; i < p1->n; i++)
            {
                b1[i] = p1->arr[i]->v;
                RivaAceIntEntry *t = p1->arr[i];
                b2[i] = t->id;
            }
            if (write((short)p2, b1, p1->n * 4) == p1->n * 4)
            {
                if (write((short)p2, b2, p1->n * 2) == p1->n * 2)
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
//@ f_011ad0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt 32-Bit-Doppelwort-Variablen aus einem abstrakten Strom-Objekt über dessen virtuelle
 *   Lesemethode vt[8] (Format ohne vorangestelltes Längenfeld: Anzahl c, c * 4 Bytes Werte, c * 2 Bytes
 *   Kennnummern) und überträgt die Werte nach Kennnummer in das Register.
 * - Eingaben / Rückgabe: Zeiger auf das Doppelwort-Register (p1) und Zeiger auf das Strom-Objekt (p2); gibt 1
 *   bei Erfolg, 0 bei Lesefehler der Anzahl oder c <= 0 zurück.
 * - Wichtige Variablen & Daten: Nutzt virtuelle Methode vt[8] der Tabelle bei Offset +0x14 des Strom-Objekts
 *   sowie temporäre Puffer a (Werte) und b (Nummern).
 * - Besonderheiten / Originalfehler: Schlägt das Lesen des Werteblocks (VR(p2, a, c * 4)) fehl, verzweigt die
 *   Funktion in else { r = 1; }: Sie meldet fälschlich Erfolg (1) und überspringt delete a; delete b;, wodurch
 *   beide Puffer als Speicherleck zurückbleiben (identischer Fehler in f_012100 und f_012700).
 === Ende Beschreibung === */
int f_011ad0(RivaAceIntRegister *p1, RivaFileStream *p2)
{
    short *b = 0; // Haelt die Registerzuteilung wie im Original
    int *a = 0;
    int r = 0;
    short c;
    int n = VR(p2, &c, 2);
    if (n == 2 && c > 0) {
        a = new (mark(d_1a0134, 342)) int[c];
        b = new (mark(d_1a0134, 343)) short[c];
        if (VR(p2, a, c * 4) == c * 4u) {
            if (VR(p2, b, c * 2) == c * 2) {
                for (short i = 0; i < c; i++) {
                    for (short j = 0; j < p1->n; j++) {
                        short *bi = &b[i];
                        RivaAceIntEntry *t = p1->arr[j];
                        if (t->id == *bi) {
                            t->v = a[i];
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

//@ f_011c60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt alle Einträge eines 32-Bit-Doppelwort-Registers ohne Längenfeld über die
 *   virtuelle Schreibmethode vt[9] in ein Strom-Objekt (Anzahl, Werteblock, Nummernblock).
 * - Eingaben / Rückgabe: Zeiger auf das Doppelwort-Register (p1) und Zeiger auf das Strom-Objekt (p2); gibt 1
 *   bei Erfolg (auch bei leerem Register), 0 bei Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Nutzt vt[9] (Offset +0x14) und temporäre Sammelarrays b1 und b2.
 === Ende Beschreibung === */
int f_011c60(RivaAceIntRegister *p1, RivaFileStream *p2)
{
    int *b1;
    short *b2;
    int r = 0;
    if (VW(p2, &p1->n, 2) == 2)
    {
        if (p1->n != 0)
        {
            short i;
            b1 = new (mark(d_1a0134, 0x115)) int[p1->n];
            b2 = new (mark(d_1a0134, 0x116)) short[p1->n];
            for (i = 0; i < p1->n; i++)
            {
                b1[i] = p1->arr[i]->v;
                RivaAceIntEntry *t = p1->arr[i];
                short v = t->id;
                b2[i] = v;
            }
            if (VW(p2, b1, p1->n * 4) == p1->n * 4u)
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

//@ f_011da0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Hängt einen einzelnen Variableneintrags-Zeiger hinten an das Zeigerfeld eines
 *   Variablenregisters an und erhöht die Eintragsanzahl n um 1 (vom Compiler mit der 16-Bit-Fassung f_0123a0
 *   zusammengelegt).
 * - Eingaben / Rückgabe: Zeiger auf das Register (p1) und Zeiger auf den neuen Eintrag (p2); keine Rückgabe.
 * - Wichtige Variablen & Daten: Schreibt p1->arr[p1->n] = p2 und erhöht p1->n ohne Kapazitätsprüfung gegen
 *   p1->cap.
 === Ende Beschreibung === */
void f_011da0(RivaAceIntRegister *p1, void *p2)
{
    p1->arr[p1->n] = (RivaAceIntEntry *)p2;
    p1->n = p1->n + 1;
}
//@ f_011dc0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor eines Variablenregisters (mit f_0123c0 zusammengelegt): gibt das dynamische
 *   Zeigerfeld arr frei, lässt die einzelnen Variablenobjekte selbst jedoch bestehen.
 * - Eingaben / Rückgabe: Zeiger auf das Register (this) und ungenutzter Destruktorschalter; gibt this zurück.
 * - Wichtige Variablen & Daten: Feld arr (+4) des Registers.
 === Ende Beschreibung === */
RivaAceIntRegister *f_011dc0(RivaAceIntRegister *p1, int p_unused1)
{
    delete p1->arr;
    return p1;
}
//@ f_011dd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor eines Variablenregisters: setzt die Eintragsanzahl n auf 0, speichert die
 *   Kapazität cap und reserviert über f_014540 ein Zeigerfeld für cap * 4 Bytes.
 * - Eingaben / Rückgabe: Zeiger auf das Register (this) und gewünschte Kapazität (p2); gibt this zurück.
 * - Wichtige Variablen & Daten: Setzt n = 0, cap = p2 und arr = f_014540(p2 * 4, ...).
 === Ende Beschreibung === */
RivaAceIntRegister *f_011dd0(RivaAceIntRegister *p1, int p2)
{
    p1->n = 0;
    p1->cap = (short)p2;
    p1->arr = (RivaAceIntEntry **)f_014540((short)p2 * 4, (int)d_1a0134, 0xd3);
    return p1;
}
