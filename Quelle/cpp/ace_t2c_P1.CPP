/* === Beschreibung (Katalog) ===
 * Einheit: ace_t2c
 *
 * Adressbereich: 0x012400-0x012870
 * Spielsystem: Spielstand & Optionen - 8-Bit-Byte-Fassung des Template-Codes für Variablenregister: speichert
 * und lädt die Byte-Spielvariablen (d_1c2128, Block 'BVAR') im Spielstand und lädt die
 * Benutzereinstellungen/Optionen (d_1bfad4) aus der Konfigurationsdatei über das Strom-Objekt d_1c2098.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAACE.H"
#include "RIVAMEM.H"
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
int f_1448b0(int p1, int p2, int p3);                   // reg eax ebx stapel 0
int f_144920(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1449a0(int p1);                                   // reg eax stapel 0
int f_144ab0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1b62ec;                    // 0x1B62EC
extern int d_1bc5f0;                    // 0x1BC5F0
extern short d_1bc5f4;                    // 0x1BC5F4
extern int d_1bc5f6;                    // 0x1BC5F6
extern int d_1bc5f8;                    // 0x1BC5F8
extern int d_1c2098;                    // 0x1C2098
extern const char d_1a0134[];           // Text 0x1A0134
#include <io.h>
#define VR(s,b,n) (s)->vt->read(s,b,n)
#define VW(s,b,n) (s)->vt->write(s,b,n)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_012400
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht in einem 8-Bit-Byte-Variablenregister (z. B. d_1c2128 oder d_1bfad4) den ersten
 *   Eintrag mit der angegebenen Kennnummer.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1) und gesuchte Kennnummer (p2); gibt den Zeiger auf den
 *   3-Byte-Eintrag oder 0 zurück.
 * - Wichtige Variablen & Daten: Durchläuft p1->arr[0 .. p1->n - 1].
 * - Besonderheiten / Originalfehler: Wie in f_011790 und f_011e00 wird (short)p2 (vorzeichenbehaftet) mit
 *   unsigned short id = t->id (vorzeichenlos) verglichen, wodurch Kennnummern >= 0x8000 unauffindbar sind.
 === Ende Beschreibung === */
RivaAceByteEntry *f_012400(RivaAceByteRegister *p1, int p2)
{
    RivaAceByteEntry *r = 0;
    short i;
    for (i = 0; i < p1->n; i++) {
        int key = (short)p2;
        if (r != 0) return r;
        RivaAceByteEntry *t = p1->arr[i];
        unsigned short id = t->id;
        if (id == key) r = t;
    }
    return r;
}
//@ f_012450
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt beim Spielstand-Laden (aufgerufen aus diskmen2_t1 nach der Blockkennung 'BVAR') alle
 *   gespeicherten 8-Bit-Byte-Spielvariablen aus der Spielstanddatei und überträgt ihre Werte anhand der
 *   Kennnummer in das globale Byte-Register d_1c2128.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1, d_1c2128) und Dateihandle (p2, d_1c2140); gibt 1 bei
 *   Erfolg (auch bei leerem Block), 0 bei Lesefehler zurück.
 * - Wichtige Variablen & Daten: Überliest das 2-Byte-Längenfeld total, liest die Eintragsanzahl (2 Bytes),
 *   danach n Bytes Werte und n * 2 Bytes Kennnummern und aktualisiert passende Registereinträge.
 === Ende Beschreibung === */
int f_012450(RivaAceByteRegister *p1, short p2)
{
    int fd = p2;
    union Anzahl942 { short wert; char bytes[3]; } anzahl942; short total;
    struct LeseRahmen942 {
        union { char *erstes; int umfang; } zwischen;
        char *zeichen;
        short *kennungen;
    };
    LeseRahmen942 rahmen;
    LeseRahmen942 *ort942 = &rahmen; // Haelt die Stapelplatzfolge im abgetrennten Teilmodul ace_t2c wie im Original
    int r;
    read(fd, &total, 2);
    r = 0;
    if (read(fd, &anzahl942.wert, 2) == 2) {
        if (anzahl942.wert > 0) {
            short i, j;
            union Argument942 { void *markierung; int groesse; short wort; } argument942;
            argument942.markierung = mark(d_1a0134, 0x1e7);
            void *tag1 = argument942.markierung;
            argument942.wort = anzahl942.wert;
            argument942.groesse = argument942.wort;
            char *b1 = (char *)operator new[](argument942.groesse, tag1);
            rahmen.zwischen.erstes = b1;
            rahmen.zeichen = b1;
            argument942.markierung = mark(d_1a0134, 0x1e8);
            void *tag2 = argument942.markierung;
            argument942.wort = anzahl942.wert;
            argument942.groesse = argument942.wort * 2;
            short *b2 = (short *)operator new[](argument942.groesse, tag2);
            rahmen.kennungen = b2;
            if (read(fd, rahmen.zwischen.erstes, anzahl942.wert) == (unsigned)anzahl942.wert) {
                rahmen.zwischen.umfang = anzahl942.wert * 2;
                if (read(fd, b2, rahmen.zwischen.umfang) == rahmen.zwischen.umfang) {
                    for (i = 0; i < anzahl942.wert; i++) {
                        for (j = 0; j < p1->n; j++) {
                            short *id = &rahmen.kennungen[i];
                            RivaAceByteEntry *t = p1->arr[j];
                            if (t->id == *id) {
                                t->v = rahmen.zeichen[i];
                                break;
                            }
                        }
                    }
                    r = 1;
                }
            }
            delete rahmen.zeichen;
            delete rahmen.kennungen;
        } else r = 1;
    }
    { int k0 = d_1a34e0; d_1a34e0 = k0; int k1 = d_1b62ec; d_1b62ec = k1; } // Haelt die Register- und Stapelzuteilung wie im Original
    return r;
}

//@ f_0125b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt beim Spielstand-Speichern (aufgerufen aus diskmen2_t1 nach der 4-Byte-Kennung
 *   'BVAR') alle Einträge des Byte-Registers d_1c2128 als Datenblock (Länge 2 + 3*n, Anzahl n, n Bytes Werte, n
 *   * 2 Bytes Kennnummern) in die Spielstanddatei.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1) und Dateihandle (p2); gibt 1 bei Erfolg, 0 bei
 *   Schreibfehler zurück.
 * - Wichtige Variablen & Daten: Temporäre Puffer b1 (n Bytes) und b2 (n Words).
 === Ende Beschreibung === */
int f_0125b0(RivaAceByteRegister *p1, int p2)
{
    char *b1;
    short *b2;
    int r = 0;
    short total = 2;
    total += p1->n;
    total += p1->n * 2;
    { extern int d_1bc5fc; int kp0 = d_1a34e0; d_1a34e0 = kp0; int kp1 = d_1b62ec; d_1b62ec = kp1; int kp2 = d_1bc5f0; d_1bc5f0 = kp2; int kp3 = d_1bc5f6; d_1bc5f6 = kp3; int kp4 = d_1bc5f8; d_1bc5f8 = kp4; int kp5 = d_1c2098; d_1c2098 = kp5; int kp6 = d_1bc5fc; d_1bc5fc = kp6; } // Haelt die Stapelplatzfolge (r auf [esp], p2 auf [esp+8]) wie im Original
    write((short)p2, &total, 2);
    if (write((short)p2, &p1->n, 2) == 2)
    {
        if (p1->n > 0)
        {
            short i;
            b1 = new (mark(d_1a0134, 0x1a3)) char[p1->n];
            b2 = new (mark(d_1a0134, 0x1a4)) short[p1->n];
            for (i = 0; i < p1->n; i++)
            {
                b1[i] = p1->arr[i]->gv();
                b2[i] = p1->arr[i]->gid();
            }
            if (write((short)p2, b1, p1->n * sizeof(char)) == p1->n * sizeof(char))
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
    { int kq0 = d_1a34e0; d_1a34e0 = kq0; } // Haelt die Stapelplatzfolge wie im Original
    return r;
}

#pragma inline_depth(0)
//@ f_012700
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt ein 8-Bit-Byte-Register ohne Längenfeld über die virtuelle Lesemethode vt[8] aus
 *   einem Strom-Objekt; wird im Spiel von der Optionsverwaltung (options_t1 f_0d7a20 und options_t2) genutzt, um
 *   die 21 gespeicherten Spieloptionen (d_1bfad4) über d_1c2098 aus der Konfigurationsdatei einzulesen.
 * - Eingaben / Rückgabe: Zeiger auf das Byte-Register (p1, im Spiel d_1bfad4) und Zeiger auf das Strom-Objekt
 *   (p2, d_1c2098); gibt 1 bei Erfolg, 0 bei unlesbarer Anzahl oder Anzahl <= 0 zurück.
 * - Wichtige Variablen & Daten: Liest 2 Bytes Anzahl, fordert Wertepuffer a (n Bytes) und Nummernpuffer b (n * 2
 *   Bytes) an und ordnet die Optionswerte über ihre Kennnummer (1-21) zu.
 * - Besonderheiten / Originalfehler: Schlägt das Lesen des Werteblocks (VR(p2, a, n)) fehl, setzt der else-Zweig
 *   r = 1 (meldet also fälschlich Erfolg) und gibt die Puffer a und b nicht frei (Speicherleck; identisch zu
 *   f_011ad0 und f_012100).
 === Ende Beschreibung === */
short f_012700(RivaAceByteRegister *p1, RivaFileStream *p2)
{
    int r = 0;
    short *b;
    char *a;
    union Anzahl942 { short wert; char bytes[3]; } anzahl942;
    int n = VR(p2, &anzahl942.wert, 2);
    if (n == 2 && anzahl942.wert > 0) {
        a = new (mark(d_1a0134, 342)) char[anzahl942.wert];
        b = new (mark(d_1a0134, 343)) short[anzahl942.wert];
        if (VR(p2, a, anzahl942.wert) == anzahl942.wert) {
            unsigned char cv = (unsigned char)anzahl942.wert; *(unsigned char *)&anzahl942.wert = cv; // Haelt die Stapelplatzfolge (r auf [esp+8], b auf [esp+4]) wie im Original
            if (VR(p2, b, anzahl942.wert * 2) == anzahl942.wert * 2) {
                for (short i = 0; anzahl942.wert > i; i++) {
                    for (short j = 0; j < p1->n; j++) {
                        short *bi = &b[i];
                        RivaAceByteEntry *t = p1->arr[j];
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
#pragma inline_depth(3)
