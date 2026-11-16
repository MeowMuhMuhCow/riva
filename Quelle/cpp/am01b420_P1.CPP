/* === Beschreibung (Katalog) ===
 * Einheit am01b420
 *
 * Diese Einheit bildet den Hauptteil von amapplst.cpp (Adressbereich 0x01b420-0x01be20). Sie verwaltet die
 * persistente Änderungs- und Statusdatei der Automap (Dateikennung 0x40000000, Dateiname aus d_1a04b4): nach
 * einem 8-Byte-Dateikopf (*d_1a04b0, 0, 1) enthält die Datei für jede Karte einen eigenen Abschnitt, der mit dem
 * 2-Byte-Trennpaar (-1, karten_id) beginnt und dahinter beliebig viele 2-Byte-Paare (a, b) für Kartenänderungen
 * (z. B. geöffnete Türen, a > 0) sowie einen optionalen kartenweiten Statuseintrag (a == 0) speichert.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// OPT -4r -oneatx -zp1 -s
// P3 14/18 gleich (suche.py 25.10.2026, Basis amapplst_P1.CPP)
// amapplst.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01B3B0-0x01BF70
#include <string.h>
struct Dim { char pad[8]; short n; };
struct Ent { unsigned short a, b; char pad[8]; };
struct Lst { long x0; Dim *d; Ent *e; short s; };
struct Rec { signed char c; signed char a; signed char b; long pos; };
struct Hdr { long a; short b; short c; };
int f_01ae60(Lst *p1, int p2);

extern RivaFileManager d_1c2098;
extern long *d_1a04b0;
extern const char *d_1a04b4;
extern const char *d_1a965c;
extern const char d_1a0490[];
void f_01b420();
int f_01b4d0(Rec *p1);
int f_01b5a0(Rec *p1);
void f_01b610(Rec *p1);
void f_01b650(Rec *p1);
void f_01b680(Rec *p1);
void f_01b6a0(Rec *p1);
void f_01b6c0(Rec *p1);
#define WRITEREC(p) f_01b6c0(p)
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_01b420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Dateinamen-Zeiger d_1a965c vorübergehend auf d_1a04b4, prüft ob die
 *   Datei 0x40000000 bereits existiert, legt sie anderenfalls neu an und schreibt den 8-Byte-Kopfsatz (h.a =
 *   *d_1a04b0, h.b = 0, h.c = 1); danach öffnet sie die Datei im Lese-/Schreibmodus (0x202), liest den
 *   8-Byte-Kopf ein und stellt d_1a965c wieder her.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden der globale Dateimanager d_1c2098, die Dateikennung d_1a04b0, der
 *   Dateiname d_1a04b4 und der globale Dateinamen-Zeiger d_1a965c.
 === Ende Beschreibung === */
void f_01b420()
{
    Hdr h;
    const char *save = d_1a965c;
    d_1a965c = d_1a04b4;
    if (d_1c2098.f_144870(0x40000000) == 0) {
        h.a = *d_1a04b0; h.b = 0; h.c = 1;
        d_1c2098.f_144890(0x40000000);
        d_1c2098.f_144960(&h, 8);
        d_1c2098.f_1449a0();
    }
    d_1c2098.f_1448b0(0x40000000, 0x202);
    d_1c2098.f_144920(&h, 8);
    d_1a965c = save;
}
//@ f_01b4c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schließt die geöffnete Änderungsdatei 0x40000000 im Dateimanager d_1c2098.
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Genutzt wird das globale Dateiobjekt d_1c2098.
 === Ende Beschreibung === */
void f_01b4c0()
{
    d_1c2098.f_1449a0();
}
//@ f_01b4d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sofern die geöffnete Datei 0x40000000 mehr als die 8 Kopfbytes enthält, liest die Funktion den
 *   gesamten Dateiinhalt in einen temporären Puffer und sucht ab Byte 8 in 2-Byte-Schritten nach der
 *   Abschnittsmarke (-1, p1->c) für die Karte p1->c; bei einem Treffer positioniert sie den Dateizeiger direkt
 *   hinter diese 2-Byte-Abschnittsmarke.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, mit der gesuchten Kartennummer in
 *   p1->c) und gibt 1 zurück, wenn der Kartenabschnitt gefunden wurde, sonst 0.
 * - Wichtige Variablen: Gelesen wird die Kartennummer p1->c (+0x00, signed char).
 === Ende Beschreibung === */
int f_01b4d0(Rec *p1)
{
    int r = 0;
    unsigned found = 0;
    unsigned n = d_1c2098.f_144a00();
    if (n > 8) {
        signed char *buf = new (mark(d_1a0490, 0x8a)) signed char[n];
        d_1c2098.f_144ab0(0, 0);
        d_1c2098.f_144920(buf, n);
        {
            unsigned i = 8;
            signed char *q = buf + i;
            while (found == 0 && i < n) {
                if (q[0] == -1 && q[1] == p1->c) found = i + 2;
                i += 2; q += 2;
            }
        }
        delete buf;
        if (found > 0) { r = 1; d_1c2098.f_144ab0(found, 0); }
    }
    return r;
}
//@ f_01b5a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liest ab der aktuellen Dateiposition im Kartenabschnitt fortlaufend 2-Byte-Paare
 *   r[0..1], bis entweder der nächste Kartenabschnitt beginnt (r[0] == -1), das Dateiende erreicht ist oder der
 *   gesuchte Schlüssel r[0] == p1->a gefunden wird; war das Dateiende noch nicht erreicht, setzt sie den
 *   Dateizeiger um 2 Bytes zurück auf den Beginn des gefundenen Eintrags bzw. der nächsten Abschnittsmarke.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, mit gesuchtem Schlüssel p1->a) und
 *   liefert 1 bei einem Treffer, sonst 0.
 * - Wichtige Variablen: Verglichen wird die Eintragsnummer p1->a (+0x01, signed char).
 === Ende Beschreibung === */
int f_01b5a0(Rec *p1)
{
    int found = 0;
    int eof = 0;
    signed char r[2];
    unsigned n;
    do {
        n = d_1c2098.f_144920(r, 2);
        if (n == 2) {
            if (r[0] == -1) n = 0;
            else if (r[0] == p1->a) { found = 1; n = 0; }
        } else eof = 1;
    } while (n > 0);
    if (!eof) d_1c2098.f_144ab0(-2, 1);
    return found;
}
//@ f_01b610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion positioniert den Dateizeiger ans Ende der Änderungsdatei 0x40000000 und hängt die
 *   2-Byte-Abschnittsmarke (-1, p1->c) für die Karte p1->c an.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geschrieben wird die Kartennummer p1->c (+0x00).
 === Ende Beschreibung === */
void f_01b610(Rec *p1)
{
    signed char w[2];
    w[0] = -1;
    w[1] = p1->c;
    d_1c2098.f_144ab0(0, 2);
    d_1c2098.f_144960(w, 2);
}
//@ f_01b650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion fügt an der aktuellen Dateiposition in der Änderungsdatei 2 Bytes mit den Werten
 *   (p1->a, p1->b) über f_144b70 ein, wobei alle nachfolgenden Bytes der Datei um 2 Bytes nach hinten verschoben
 *   werden.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geschrieben werden die beiden Bytes p1->a (+0x01) und p1->b (+0x02).
 === Ende Beschreibung === */
void f_01b650(Rec *p1)
{
    d_1c2098.f_144b70(d_1c2098.f_144a80(), &p1->a, 2);
}
//@ f_01b680
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion schreibt die 2 Bytes (p1->a, p1->b) direkt an die aktuelle Dateiposition in der
 *   Änderungsdatei 0x40000000.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geschrieben werden p1->a und p1->b.
 === Ende Beschreibung === */
void f_01b680(Rec *p1)
{
    d_1c2098.f_144960(&p1->a, 2);
}
//@ f_01b6a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion liest 2 Bytes ab der aktuellen Dateiposition aus der Änderungsdatei in die Felder
 *   (p1->a, p1->b) ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Gefüllt werden p1->a (+0x01) und p1->b (+0x02).
 === Ende Beschreibung === */
void f_01b6a0(Rec *p1)
{
    d_1c2098.f_144920(&p1->a, 2);
}
//@ f_01b6c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet (bzw. erzeugt) die Änderungsdatei 0x40000000 und sucht den Abschnitt der
 *   Karte p1->c: existiert der Abschnitt noch nicht, hängt sie ihn samt dem Paar (p1->a, p1->b) ans Dateiende
 *   an; existiert er bereits, sucht sie darin nach dem Schlüssel p1->a, überschreibt bei einem Treffer das
 *   vorhandene Paar oder fügt das neue Paar am Ende des Kartenabschnitts ein, schließt die Datei und setzt
 *   p1->pos = -1.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, mit c, a und b) und liefert keinen
 *   Rückgabewert.
 * - Wichtige Variablen: Genutzt werden p1->c (Kartennummer), p1->a (Änderungsindex), p1->b (Variante/Zustand)
 *   und p1->pos (+0x03, Dateiposition).
 === Ende Beschreibung === */
void f_01b6c0(Rec *p1)
{
    f_01b420();
    if (!f_01b4d0(p1)) {
        f_01b610(p1);
        f_01b680(p1);
    } else {
        if (!f_01b5a0(p1)) {
            f_01b650(p1);
        } else {
            f_01b680(p1);
        }
    }
    f_01b4c0();
    p1->pos = -1;
}
//@ f_01b860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert ein Rec-Objekt (7 Bytes): er setzt Schlüssel a = 0, Wert b = 0,
 *   Lese-Dateiposition pos = -1 und trägt die übergebene Kartennummer p2 in p1->c ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 (Rec *, this) und die Kartennummer p2 (int)
 *   und gibt p1 zurück.
 * - Wichtige Variablen: Initialisiert werden p1->c (+0x00), p1->a (+0x01), p1->b (+0x02) und p1->pos (+0x03).
 === Ende Beschreibung === */
Rec *f_01b860(Rec *p1, int p2)
{
    p1->a = 0;
    p1->b = 0;
    p1->pos = -1;
    p1->c = p2;
    return p1;
}
//@ f_01b880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Destruktor des Rec-Objekts ohne eigene Operationen.
 * - Eingaben und Rückgabe: Die Funktion hat keine genutzten Parameter und keinen Rückgabewert.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_01b880(Rec *p1, int p2)
{
}
//@ f_01b890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Unterscheidet sich die neue Kartennummer p2 von der bisher in p1->c gespeicherten, setzt die
 *   Funktion den Leseiterator p1->pos auf -1 zurück und übernimmt p1->c = p2.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) sowie die neue Kartennummer
 *   p2 (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Geändert werden p1->c (+0x00) und p1->pos (+0x03).
 === Ende Beschreibung === */
void f_01b890(Rec *p1, int p2)
{
    if ((signed char)p2 != p1->c) { p1->pos = -1; p1->c = p2; }
}
//@ f_01b8a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion kopiert das 16-Bit-Wort *p2 in die Felder (p1->a, p1->b) und speichert dieses
 *   Änderungspaar anschließend genau wie f_01b6c0 im Abschnitt der Karte p1->c in der Datei 0x40000000.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) und einen Zeiger p2 (short *)
 *   auf das 2-Byte-Paar (a, b) und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden p1->a, p1->b, p1->pos und die Datei 0x40000000.
 === Ende Beschreibung === */
void f_01b8a0(Rec *p1, short *p2)
{
    Hdr h;
    char w[2];
    signed char r[2];
    const char *old = d_1a965c; // Vor *p2 geladen, haelt die Registerzuteilung (ecx/esi) im else-Zweig wie im Original
    int err, found;
    unsigned n;
    Rec *s;
    s = p1;
    *(short *)&s->a = *p2;
    d_1a965c = d_1a04b4;
    if (!d_1c2098.f_144870(0x40000000)) {
        h.a = *d_1a04b0;
        h.b = 0;
        h.c = 1;
        d_1c2098.f_144890(0x40000000);
        d_1c2098.f_144960(&h, 8);
        d_1c2098.f_1449a0();
    }
    d_1c2098.f_1448b0(0x40000000, 0x202);
    d_1c2098.f_144920(&h, 8);
    d_1a965c = old;
    if (!f_01b4d0(s)) {
        w[0] = 0xff;
        w[1] = s->c;
        d_1c2098.f_144ab0(0, 2);
        d_1c2098.f_144960(w, 2);
        d_1c2098.f_144960(&s->a, 2);
    } else {
        Rec *q = s;
        found = 0;
        err = 0;
        do {
            n = d_1c2098.f_144920(r, 2);
            if (n == 2) {
                if ((signed char)r[0] == -1) {
                    n = 0;
                } else if ((unsigned char)r[0] == (unsigned char)q->a) {
                    found = 1;
                    n = 0;
                }
            } else {
                err = 1;
            }
        } while (n > 0);
        if (!err) d_1c2098.f_144ab0(-2, 1);
        if (!found) {
            d_1c2098.f_144b70(d_1c2098.f_144a80(), &s->a, 2);
        } else {
            d_1c2098.f_144960(&s->a, 2);
        }
    }
    d_1c2098.f_1449a0();
    s->pos = -1;
}
//@ f_01ba50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet die Änderungsdatei 0x40000000, sucht über f_01b4d0 den Abschnitt der Karte
 *   p1->c, liest darin den ersten regulären Änderungseintrag (wobei ein eventueller Kartenstatus-Eintrag mit a
 *   == 0 übersprungen wird), merkt die nachfolgende Dateiposition in p1->pos und schließt die Datei wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) und gibt einen Zeiger auf
 *   &p1->a (das gelesene Paar a, b) zurück, oder 0, falls keine Änderungen für diese Karte vorliegen.
 * - Wichtige Variablen: Gefüllt werden p1->a, p1->b und die Leseposition p1->pos (+0x03).
 === Ende Beschreibung === */
signed char *f_01ba50(Rec *p1)
{
    signed char *r;
    int again;
    unsigned n;
    p1->pos = -1;
    r = 0;
    f_01b420();
    if (f_01b4d0(p1) == 1) {
        do {
            again = 0;
            n = d_1c2098.f_144920(&p1->a, 2);
            if (n == 2 && p1->a != -1) {
                if (p1->a == 0) again = 1;
                else { r = &p1->a; p1->pos = d_1c2098.f_144a80(); }
            }
        } while (again == 1);
    }
    d_1c2098.f_1449a0();
    return r;
}
//@ f_01bb60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion öffnet die Änderungsdatei 0x40000000, springt an die zuvor in p1->pos gemerkte
 *   Dateiposition, liest den nächsten regulären 2-Byte-Eintrag des aktuellen Kartenabschnitts (überspringt a ==
 *   0 und bricht bei der nächsten Abschnittsmarke a == -1 oder am Dateiende ab), aktualisiert p1->pos und
 *   schließt die Datei.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) und liefert einen Zeiger auf
 *   &p1->a oder 0 am Ende des Kartenabschnitts.
 * - Wichtige Variablen: Genutzt und aktualisiert werden p1->pos, p1->a und p1->b.
 === Ende Beschreibung === */
signed char *f_01bb60(Rec *p1)
{
    signed char *r;
    int again;
    unsigned n;
    r = 0;
    f_01b420();
    d_1c2098.f_144ab0(p1->pos, 0);
    p1->pos = -1;
    do {
        again = 0;
        n = d_1c2098.f_144920(&p1->a, 2);
        if (n == 2 && p1->a != -1) {
            if (p1->a == 0) again = 1;
            else { r = &p1->a; p1->pos = d_1c2098.f_144a80(); }
        }
    } while (again == 1);
    d_1c2098.f_1449a0();
    return r;
}
//@ f_01bc70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Eintragsindex p1->a = 0 sowie den Statuswert p1->b = p2 und schreibt
 *   dieses Paar wie f_01b6c0 in den Abschnitt der Karte p1->c der Datei 0x40000000 (wird in gz_01a470_t1
 *   genutzt, um kartenbezogene Automap-Optionen wie die Sichtbarkeit von Notizsymbolen im Spielstand zu
 *   sichern).
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) und den zu speichernden
 *   Statuswert p2 (int) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Gesetzt werden p1->a = 0, p1->b = p2 und p1->pos = -1.
 === Ende Beschreibung === */
void f_01bc70(Rec *p1, int p2)
{
    p1->a = 0;
    p1->b = p2;
    f_01b6c0(p1);
}
//@ f_01be20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt p1->a = 0 und p1->b = 0, öffnet die Datei 0x40000000, sucht im Abschnitt
 *   der Karte p1->c nach dem Sondereintrag mit Schlüssel a == 0 und liest bei einem Treffer dessen gespeicherten
 *   Statuswert in p1->b ein.
 * - Eingaben und Rückgabe: Die Funktion erhält das Zugriffsobjekt p1 (Rec *, this) und gibt den gelesenen
 *   Statuswert p1->b (signed char, 0 falls nicht vorhanden) zurück.
 * - Wichtige Variablen: Gelesen wird der Sondereintrag a == 0 der Karte p1->c.
 === Ende Beschreibung === */
signed char f_01be20(Rec *p1)
{
    signed char r[2];
    int found, eof;
    unsigned n;
    p1->a = 0;
    p1->b = 0;
    f_01b420();
    if (f_01b4d0(p1) == 1) {
        Rec *q = p1;
        found = 0;
        eof = 0;
        do {
            n = d_1c2098.f_144920(r, 2);
            if (n == 2) {
                if ((signed char)r[0] == -1) {
                    n = 0;
                } else if (r[0] == q->a) {
                    found = 1;
                    n = 0;
                }
            } else {
                eof = 1;
            }
        } while (n > 0);
        if (eof == 0) d_1c2098.f_144ab0(-2, 1);
        if (found == 1) f_01b6a0(p1);
    }
    f_01b4c0();
    return p1->b;
}

// Astra700: bisher unregistrierter Randrumpf.
// gz_01bf70.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x01BF70-0x01BF80. Zaehler: liefert alten Wert und erhoeht ihn.
extern int d_1bc75c;   // BSS 0x1BC75C-0x1BC760