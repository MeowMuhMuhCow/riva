/* === Beschreibung (Katalog) ===
 * Einheit tdmintrp (0x1206C0-0x120C60)
 *
 * Überblick
 * Die Einheit tdmintrp (im Original tdmintrp.cpp) realisiert das Aufzeichnen und Abspielen von 3D-Bewegungsdemos
 * (Kamera- und Schrittfolgen in 3D-Dungeons und Unterwassergebieten) sowie die Umsetzung von Richtungs- und
 * Drehkommandos in 3D-Kamerabewegungen.
 === Ende Beschreibung === */
// P3 5/9 gleich (suche.py 26.10.2026, Basis tdmintrp_P1.CPP)
// I9: aus TDMINTRP.CPP uebernommen (Stufe-2-Stand), Marken 9 neu
// tdmintrp.cpp (0x1206C0-0x120C60): Demo aufzeichnen und abspielen
struct Game;
extern Game *d_1c0004;
extern char *d_1c0af8;                                   // Demo-Puffer
extern char *d_1c0b40;   // liegt in der Basis (Fable 30.10.)                    // Schreib-/Lesezeiger
extern long d_1a8950;                                    // Zeitgeber-Kennung (-1 = keiner)
extern unsigned short d_1a8954;                          // Takt
extern short d_1a8956;                                   // L?nge
extern volatile signed char d_1a8958;                    // Tempo
extern volatile short d_1a0102;                                   // aktuelle Eingabe
extern short d_1bd760, d_1bd758;
extern long d_1a89ac, d_1a80c8;
extern long d_1c0b30;
extern long d_1c0b18;
extern volatile long d_1c0b1c;
extern short d_1c0b14, d_1c0b88;
struct Timer { long f_147b97(unsigned short rate, int (*cb)()); void f_147c02(long h); };
extern Timer d_1c2edc;
int f_1206a0();
int f_0d3800();
int f_0d3780();
void f_155b20(long v); void f_155b80(long v); void f_155bc8(long v); void f_155bfc(long v);
void f_0de850(Game *g, long v); void f_0de870(Game *g, long v); void f_0de890(Game *g, long v);
void f_0de8d0(Game *g, unsigned short v); void f_0de8f0(Game *g, unsigned short v); void f_0de930(Game *g, int v);
long f_0de840(Game *g); long f_0de860(Game *g); long f_0de880(Game *g); short f_0de8c0(Game *g); short f_0de8e0(Game *g);
void f_0ddd60(Game *g);
void f_120980(short k);
void f_120a20();
void f_120b40();

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_1206c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Startet den Zeitgeber für die getaktete 3D-Bewegungs- und Demo-Steuerung, sofern noch kein
 *   Timer aktiv ist (d_1a8950 == -1), indem die Rückruffunktion f_1206a0 mit der Taktrate d_1a8954 beim globalen
 *   Timer-Objekt d_1c2edc registriert wird.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a8950 (long): Handle des registrierten Zeitgebers (-1 = kein Timer aktiv).
 *   - d_1a8954 (unsigned short): Taktrate für den 3D-Schritt-Timer.
 *   - d_1c2edc (Timer): Globale Timer-Verwaltung.
 === Ende Beschreibung === */
void f_1206c0()
{
    if (d_1a8950 == -1) d_1a8950 = d_1c2edc.f_147b97(*(volatile unsigned short *)&d_1a8954, f_1206a0);
}
//@ f_1206f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Stoppt den Zeitgeber der 3D-Bewegungs- und Demo-Steuerung, falls ein gültiges Timer-Handle
 *   in d_1a8950 vorliegt, und setzt d_1a8950 wieder auf -1 zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a8950 (long): Timer-Handle (-1 nach dem Entfernen).
 === Ende Beschreibung === */
void f_1206f0()
{
    if (d_1a8950 != -1) {
        d_1c2edc.f_147c02(d_1a8950);
        d_1a8950 = -1;
    }
}
//@ f_120720
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wertet den aktuellen Maus-Bewegungsbefehl d_1c0b88 für die 3D-Steuerung aus: Ist d_1c0b88
 *   == -1 oder wurde die Maustaste losgelassen (f_0d3800()), wird der aktive Befehl d_1c0b14 auf 0 gelöscht;
 *   liegt ein neuer positiver Befehl in d_1c0b88 vor und ist die Maustaste gehalten (f_0d3780()), wird er nach
 *   d_1c0b14 übernommen und d_1c0b88 auf 0 zurückgesetzt.
 * - Eingaben: Keine.
 * - Rückgabewert: short (der aktuell wirksame 3D-Maus-Bewegungsbefehl d_1c0b14).
 * - Wichtige Variablen:
 *   - d_1c0b88 (short): Neu eingegangener 3D-Steuerbefehl der Maus (-1 = Sperre/Abbruch).
 *   - d_1c0b14 (short): Aktuell gehaltener 3D-Maus-Steuerbefehl.
 === Ende Beschreibung === */
short f_120720()
{
    if (d_1c0b88 == -1) d_1c0b14 = 0;
    else {
        if (f_0d3800() && d_1c0b88 >= 0) d_1c0b14 = 0;
        if (d_1c0b88 > 0) {
            if (f_0d3780()) d_1c0b14 = d_1c0b88; else d_1c0b14 = 0;
            d_1c0b88 = 0;
        }
    }
    return d_1c0b14;
}
//@ f_1207a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt die Richtungsbits eines 3D-Steuerworts f in konkrete Kamerabewegungen und -drehungen
 *   der 3D-Engine um. Bit 0x01/0x02 bewegt die Kamera vorwärts bzw. rückwärts (f_155b20), Bit 0x04/0x08 dreht
 *   die Kamera nach links/rechts (f_155bc8) oder verschiebt sie im Seitwärtsschritt-Modus (d_1bd758 != 0,
 *   f_155b80), und Bit 0x10/0x20 neigt die Blickrichtung nach oben bzw. unten (f_155bfc), wobei der
 *   Schnelllauf-Schalter d_1bd760 die Schrittweite verdoppelt.
 * - Eingaben: short f (Bitmaske der aktiven 3D-Steuerkommandos).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0b30 (long): Flag, dass im aktuellen Schritt eine 3D-Bewegung stattgefunden hat (1).
 *   - d_1bd760 (short): Schnelllauf-Flag (0 = einfacher Schrittfaktor 1, sonst 2).
 *   - d_1bd758 (short): Seitwärtsschritt-Flag (Strafe statt Drehung bei Bit 0x04/0x08).
 *   - d_1a89ac (long): Lineare Schrittweite für Vorwärts-/Rückwärts- und Seitwärtsbewegung.
 *   - d_1a80c8 (long): Winkel-Schrittweite für Drehung und Blickneigung.
 === Ende Beschreibung === */
void f_1207a0(short f)
{
    d_1c0b30 = 1;
    short s;
    if (d_1bd760) s = 2;
    else s = 1;
    if (f & 1) {
        f_155b20(s * d_1a89ac);
    } else {
        if (f & 2) {
            long x = s;
            x *= -d_1a89ac;
            f_155b20(x);
        }
    }
    if (f & 4) {
        if (d_1bd758) f_155b80(s * d_1a89ac);
        else f_155bc8(s * d_1a80c8);
    } else {
        if (f & 8) {
            if (d_1bd758) f_155b80(-d_1a89ac * s);
            else {
                long x = -d_1a80c8;
                x *= s;
                f_155bc8(x);
            }
        }
    }
    if (f & 0x10) {
        f_155bfc(d_1a80c8);
    } else {
        if (f & 0x20) f_155bfc(-d_1a80c8);
    }
}
//@ f_120880
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt einen einzelnen 3D-Steuer- und Demo-Taktzyklus aus. Läuft gerade die Demo-Wiedergabe
 *   (d_1c0b1c == 1), liest f_120a20 den nächsten Befehl aus dem Demo-Puffer nach d_1a0102; anschließend wird
 *   entweder der Tastatur-/Demo-Befehl d_1a0102 oder (falls keine Demo läuft) der Mausbefehl d_1c0b14 über
 *   f_1207a0 ausgeführt und bei aktiver Demo-Aufzeichnung (d_1c0b18 == 1) samt Tempowert d_1a8958 über f_120980
 *   in den Aufzeichnungspuffer geschrieben.
 * - Eingaben: short n (ungenutzter Parameter).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0b1c (volatile long): Flag für aktive Demo-Wiedergabe (1 = Wiedergabe läuft).
 *   - d_1c0b18 (long): Flag für aktive Demo-Aufzeichnung (1 = Aufzeichnung läuft).
 *   - d_1a0102 (volatile short): Aktuelles Steuerwort aus Tastatur oder Demo-Stream.
 *   - d_1a8958 (volatile signed char): Aktuelles Bewegungstempo (wird bei Bit 0x40/0x80 angepasst).
 === Ende Beschreibung === */
void f_120880(short n)
{
    if (d_1c0b1c == 1) f_120a20();
    unsigned short m;
    unsigned short k;
    unsigned short v;
    k = d_1a0102;
    if (d_1c0b88 == -1) d_1c0b14 = 0;
    else {
        if (f_0d3800() && d_1c0b88 >= 0) d_1c0b14 = 0;
        if (d_1c0b88 > 0) {
            if (f_0d3780()) d_1c0b14 = d_1c0b88;
            else d_1c0b14 = 0;
            d_1c0b88 = 0;
        }
    }
    m = d_1c0b14;
    v = k;
    unsigned int x;
    x = k;
    if (x) ((void (*)(unsigned int))&f_1207a0)(x);
    else if ((x = m) && d_1c0b1c == 0) {
        ((void (*)(unsigned int))&f_1207a0)(x); v = m;
    }
    if (d_1c0b18 == 1) {
        if (v & 0x40) d_1a8958++;
        else if ((v & 0x80) && d_1a8958 > 8) d_1a8958--;
        ((void (*)(unsigned short))&f_120980)(v);
    }
}
//@ f_120980
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Zeichnet einen einzelnen 3D-Steuerschritt im Demo-Puffer auf. Ist der Schreibzeiger
 *   d_1c0b40 noch 0, schreibt f_120b40 zunächst den 23-Byte-Dateikopf ("AMLO" + Startkoordinaten + "ST"); danach
 *   speichert f_120980 das Steuerbyte k (ergänzt um Bit 0x40 für Schnelllauf d_1bd760 und Bit 0x80 für
 *   Seitwärtsschritt d_1bd758), das Tempo-Byte d_1a8958 sowie eine Endmarkierung -1 (0xff) und beendet die
 *   Aufzeichnung automatisch, sobald die Pufferlänge d_1a8956 9994 Bytes überschreitet.
 * - Eingaben: short k (Steuerwort des aktuellen Taktschritts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0b40 (char *): Aktueller Schreib-/Lesezeiger im Demo-Puffer d_1c0af8.
 *   - d_1a8956 (short): Gesamtlänge der aufgezeichneten Demo-Daten in Bytes.
 === Ende Beschreibung === */
void f_120980(short k)
{
    char *p = d_1c0b40;
    volatile unsigned short v = k;
    if (!p) f_120b40();
    p = d_1c0b40;
    if (d_1bd760) v |= 0x40; else v &= 0xbf;
    if (d_1bd758) v |= 0x80; else v &= 0x7f;
    *p = (char)v; p++;
    *p = d_1a8958; p++;
    *(volatile short *)&d_1a8956 += 2;
    *p = -1;
    if (d_1a8956 > 9994) { d_1c0b18 = 0; p = 0; }
    d_1c0b40 = p;
}
//@ f_120a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest bei laufender Demo-Wiedergabe den nächsten Schritt aus dem Demo-Puffer d_1c0af8.
 *   Beim ersten Aufruf (d_1c0b40 == 0) überspringt die Funktion die Kennung "AMLO", setzt die im Kopf
 *   gespeicherte 3D-Startposition und Blickrichtung der Gruppe über f_0de850..f_0de930 und rückt d_1c0b40 hinter
 *   "ST" vor; danach liest sie pro Aufruf jeweils ein Steuerbyte nach d_1a0102 (inklusive der Flags d_1bd760 und
 *   d_1bd758) sowie das Tempo-Byte nach d_1a8958 oder beendet bei der Endmarke -1 (0xffff) die Wiedergabe
 *   (d_1c0b1c = 0, f_0ddd60).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0af8 (char *): Basiszeiger auf den geladenen Demo-Puffer.
 *   - d_1c0b40 (char *): Aktueller Lesezeiger innerhalb des Demo-Puffers.
 *   - d_1c0004 (Game *): Globales Spielkontext-Objekt, auf dem die 3D-Startkoordinaten gesetzt werden.
 === Ende Beschreibung === */
void f_120a20()
{
    if (d_1c0b40 == 0) {
        d_1c0b40 = d_1c0af8;
        char *p; p = (d_1c0b40 += 4);
        d_1c0b40 = p;
        f_0de850(d_1c0004, *(long *)p); p += 4;
        f_0de870(d_1c0004, *(long *)p); p += 4;
        f_0de890(d_1c0004, *(long *)p);
        f_0de8d0(d_1c0004, *(unsigned short *)(p += 4));
        p += 2;
        f_0de8f0(d_1c0004, *(unsigned short *)p); p += 2;
        p -= -2;
        d_1c0b40 = p;
        f_0de930(d_1c0004, 1);
    }
    d_1a0102 = (signed char)*d_1c0b40;
    if ((unsigned short)d_1a0102 != 0xffff) {
        if (d_1a0102 & 0x40) d_1bd760 = 1;
        else d_1bd760 = 0;
        if (d_1a0102 & 0x80) d_1bd758 = 1;
        else d_1bd758 = 0;
        d_1c0b40++;
        d_1a8958 = *(volatile char *)d_1c0b40;
        d_1c0b40++;
    } else {
        d_1a0102 = 0;
        d_1c0b40 = 0;
        d_1c0b1c = 0;
        f_0ddd60(d_1c0004);
    }
}
//@ f_120b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert den Kopf des Demo-Aufzeichnungspuffers d_1c0af8 zu Beginn einer neuen
 *   Aufnahme. Schreibt die 4-Byte-Kennung "AMLO", liest die drei 32-Bit-Startkoordinaten (f_0de840, f_0de860,
 *   f_0de880) sowie die zwei 16-Bit-Drehwinkel (f_0de8c0, f_0de8e0) aus d_1c0004 in den Kopfbereich, hängt die
 *   2-Byte-Marke "ST" an, setzt den Schreibzeiger d_1c0b40 hinter den Kopf und initialisiert die aufgezeichnete
 *   Gesamtlänge d_1a8956 auf 23 Bytes.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0af8 (char *): Anfangsadresse des Demo-Puffers.
 *   - d_1c0b40 (char *): Schreibzeiger (zeigt nach der Initialisierung auf Offset 22).
 *   - d_1a8956 (short): Aufgezeichnete Länge in Bytes (Startwert 23 inklusive Endmarke).
 === Ende Beschreibung === */
void f_120b40()
{
    long first790(Game *);
    #pragma aux first790 "f_0de840" parm [eax] value [eax] modify exact [eax edx];
    char *q = 0;
    char *p = 0;
    p = d_1c0af8;
    *p++ = 'A'; *p++ = 'M'; *p++ = 'L'; *p++ = 'O';
    d_1c0b40 = p;
    long value = first790(d_1c0004);
    q = p + 4;
    *(long *)p = value;
    *(long *)q = f_0de860(d_1c0004); q += 4;
    *(long *)q = f_0de880(d_1c0004); q += 4;
    *(short *)q = f_0de8c0(d_1c0004); q += 2;
    *(short *)q = f_0de8e0(d_1c0004); q += 2;
    *(volatile char *)q = 'S';
    p = q + 1;
    *(volatile char *)p = 'T';
    ++p;
    d_1c0b40 = p;
    d_1a8956 = 23;
}
void f_120bd0();
