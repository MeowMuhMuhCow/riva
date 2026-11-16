/* === Beschreibung (Katalog) ===
 * Einheit alloc_t1 (0x014540 - 0x014be0)
 *
 * Überblick
 * Diese Einheit implementiert die zentrale Debug- und Laufzeit-Speicherverwaltung (alloc.cpp) von *Schatten über
 * Riva*. Sie verwaltet eine Überwachungstabelle (d_1bc614) mit bis zu 2.500 aktiven Speicherblöcken, versieht
 * jeden Block mit Kopf- und Fuß-Wächtermarken ("GUYS" = 0x53595547 und "GUYE" = 0x45595547), prüft den gesamten
 * Heap auf Speicherkorruption (f_0149a0) und stellt die C++-Operatoren new / delete sowie die
 * 16-Byte-ausgerichteten Allokatoren (radmalloc / radfree für Miles/Smacker) bereit.
 === Ende Beschreibung === */
// P3 13/17 gleich (suche.py 29.10.2026, Basis alloc_P1.CPP)
// I9: aus alloc_REST.CPP uebernommen (Stufe-2-Stand), Marken 12 neu
// ALLOC_REST (Helfer A, 22.10.2026): NICHT gleich. Offen: f_014540 16, f_014710 87, f_0149a0 21, f_014b30 35 Befehle (Rest GLEICH, f_014ba0 nur Fuellbytes). Beste Einzelvarianten: 014540=V001, 014710=V000, 014b30=V003 (je Funktion verschieden), diese Datei = V010 (Gesamtbestwert 189).
// alloc.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 22.10.2026, Phase 4
// Code 0x014540-0x014DF0. Speicherverwaltung mit Herkunft (Tabelle 2500 Eintraege, Magic-Pruefung), new/delete, radmalloc, Kartenraster.
#include "R_FIX.H"
#include <i86.h>
#include <string.h>
#include <stdio.h>
extern const char d_1b6315[];
extern const char d_1b634b[];
extern const char d_1b63c6[];
extern const char d_1b63a1[];

extern const char d_1b62f8[];
#define alloc_file d_1b62f8   // 0x1B62F8
struct Ent { unsigned *p; unsigned *e; const char *file; int line; int ser; };
struct Pool {
    void *f_0bda70(long size, const char *file, int line);
    void  f_0bdb00(void *p, int a, int b);
    long  f_0bdbc0();
};
struct Part {
    char b[12];
    Part(); ~Part();
    void f_0fad50(int n, int w, int z);
    void f_0fade0(void *img, short x, short y);
};
struct Mark { const char *file; int line; };
struct Sl { short w; char pad[0x12]; };
struct AMap {
    char a0[9]; short s9; short sb; char a1[0x17 - 0xd]; short s17; short s19; char a2[0x23 - 0x1b]; int i23; int i27;
    char a3[0x89 - 0x2b]; Sl sl[5]; char a4[3]; signed char c0f0; char a5[0x10f - 0xf1]; int f10f;
    void f_016fd0(int idx);
    void f_014c20(short *a, short *b, long px, long py);
    void f_014c80(long *a, long *b, short px, short py);
    void f_014cc0();
};
extern Pool d_1c11a0;
extern Pool *d_1bf240;
extern int d_1a01b4;
extern const char d_1a01b8[];
extern const char d_1a01c8[];
extern const char d_1a01d4[];
extern const char d_1a01e0[];
extern Ent *d_1bc614;
extern short d_1bc61c, d_1bc61e;
extern int d_1bc618, d_1bc610, d_1bc60c, d_1bc608;
extern char d_1bc620[];
extern Mark d_1bc5fc;
extern unsigned d_1bc710, d_1bc714;
extern unsigned d_1c3914;
extern short d_1a0102;
extern short d_1bc74c, d_1bc74e, d_1bc750, d_1bc752;
extern void *d_1a34e0;
void f_1455b5();
int f_051870(const char *s, int z);
void f_0149a0();
void f_0d26e0();
void f_0d2710();
void f_068f40();
void f_145702(int intno, union REGS *in, union REGS *out, struct SREGS *s);
#define NN ((short)0x9c4)
void *f_014710(void *p1);

inline short slot()
{
    short i = d_1bc61c;
    Ent *e = d_1bc614 + i;
    for (; i < NN; i++, e++) { if (e->p == 0) return i; }
    return -1;
}

#define EQ(x,v) (((x)==(v))?1:0)
//@ f_014540
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014540
 * - Aufgabe im Spiel: Reserviert über den globalen Speicherpool d_1c11a0 einen Speicherblock der Größe size + 8
 *   Bytes, umschließt den Nutzbereich mit der Startkennung 0x53595547 ("GUYS") und der Endkennung 0x45595547
 *   ("GUYE") und trägt den Block samt Quelldateiname (file), Zeilennummer (line) und laufender Seriennummer
 *   (d_1bc610) in einen freien Slot der 2.500-Einträge-Tabelle d_1bc614 ein. Zudem wird vor der Allokation der
 *   gesamte Heap über f_0149a0 auf Überschreiber geprüft und über DPMI 0x0500 der Tiefststand des freien
 *   Speichers in d_1bc608 nachgeführt; schlägt die Allokation im Debug-Modus (d_1a01b4 == 1) fehl, wird über
 *   f_051870 ein Guru-Meditation-Absturz ausgelöst.
 * - Eingaben: Angeforderte Größe (size), Quelldateiname (file) und Zeilennummer (line).
 * - Rückgabewert: Zeiger auf den Nutzdatenbereich ((char *)blk + 4) oder 0 (NULL) bei Speichermangel.
 * - Wichtige Variablen:
 *   - Globale Überwachungstabelle d_1bc614 (2.500 Einträge zu je 20 Bytes), nächster freier Suchindex d_1bc61c,
 *     höchster belegter Index d_1bc61e, aktiver Blockzähler d_1bc60c, Seriennummer d_1bc610 und Minimalwert des
 *     freien DPMI-Speichers d_1bc608.
 === Ende Beschreibung === */
void *f_014540(long size, const char *file, int line)
{
    union REGS r; struct SREGS s; int info[12];
    unsigned *blk;
    short i;
    if (d_1bc614 == 0) {
        d_1bc614 = (Ent *)d_1c11a0.f_0bda70(50000, alloc_file, 0x5d);
        d_1bc61e = 0;
        d_1bc61c = 0;
    }
    f_0149a0();
    blk = (unsigned *)d_1c11a0.f_0bda70(size + 8, file, line);
    f_1455b5();
    r.x.eax = 0x500;
    memset(&s, 0, sizeof(s));
    s.es = FP_SEG(info);
    r.x.edi = FP_OFF(info);
    f_145702(0x31, &r, &r, &s);
    { int m; m = info[0]; if (d_1bc608 > m) { d_1bc608 = m; } }
    if (blk != 0) {
#if FIX_R004   /* R004: Nutzdaten ab blk + 4 nullsetzen und Tabellenueberlauf (i < 0) abfangen */
        memset((char *)blk + 4, 0, size);
        *blk = 0x53595547;
        unsigned *endp = (unsigned *)((char *)blk + size + 4);
        *endp = 0x45595547;
        i = slot();
        if (i >= 0) {
            Ent *q = d_1bc614 + i;
            q->p = blk;
            q->e = endp;
            q->line = line;
            q->file = file;
            q->ser = d_1bc610;
            d_1bc610++;
            d_1bc61c = i + 1;
            if (i > d_1bc61e) d_1bc61e = i;
        }
        d_1bc60c++;
        { int hold = d_1bc608; d_1bc608 = hold; } // haelt die Registerzuteilung wie im Original
        return (char *)blk + 4;
#else
        memset(blk, 0, size);
        *blk = 0x53595547;
        unsigned *endp = (unsigned *)((char *)blk + size + 4);
        *endp = 0x45595547;
        i = slot();
        Ent *q = d_1bc614 + i;
        q->p = blk;
        q->e = endp;
        q->line = line;
        q->file = file;
        q->ser = d_1bc610;
        d_1bc610++;
        d_1bc61c = i + 1;
        if (i > d_1bc61e) d_1bc61e = i;
        d_1bc60c++;
        { int hold = d_1bc608; d_1bc608 = hold; } // haelt die Registerzuteilung wie im Original
        return (char *)blk + 4;
#endif
    }
    if (d_1a01b4 == 1) {
        sprintf(d_1bc620, d_1b6315, size, d_1c11a0.f_0bdbc0());
        f_051870(d_1bc620, 0);
    }
    return 0;
}
//@ f_014710
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014710
 * - Aufgabe im Spiel: Gibt einen zuvor mit f_014540 reservierten Speicherblock (p1) wieder frei (operator
 *   delete). Im erweiterten Prüfmodus (d_1a01b4 != 0) sucht die Funktion den Eintrag rückwärts ab d_1bc61e in
 *   d_1bc614, kontrolliert die beiden Wächterworte "GUYS" und "GUYE", überschreibt den gesamten freigegebenen
 *   Block zur Erkennung von Use-after-Free-Fehlern mit dem Bytewert 0xcc und löscht bei unbekanntem Zeiger oder
 *   zerstörter Wächtermarke über f_051870 einen Guru-Meditation-Fehler aus. Anschließend wird der Block an den
 *   Pool d_1c11a0.f_0bdb00 zurückgegeben und der freie DPMI-Speicherstand (d_1bc608) aktualisiert.
 * - Eingaben: Zeiger auf den freizugebenden Nutzdatenbereich (p1).
 * - Rückgabewert: 0 (NULL) nach erfolgreicher Freigabe (oder p1 bei vorzeitigem Abbruch).
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1bc614, Indexgrenzen d_1bc61c und d_1bc61e, Prüfmodus-Flag d_1a01b4 und Blockzähler
 *     d_1bc60c.
 === Ende Beschreibung === */
void *f_014710(void *p1)
{
    f_0149a0();
    char *p2 = (char *)p1 - 4;
    if (d_1a01b4 != 0) {
        short idx; short found;
        unsigned *blk, *endp;
        unsigned n;
        char *q;
        if (p1 == 0) goto done;
        found = 0;
        p1 = p2;
        short j = 0;
        j = d_1bc61e;
        Ent *e = d_1bc614 + j;
        for (; j >= 0; j--, e--) {
            if (p1 == (char *)e->p) {
                int one = 1;
                found = one;
                idx = j;
                if (j == d_1bc61e) d_1bc61e = j - one;
                break;
            }
        }
        if (found) {
            blk = e->p;
            endp = e->e;
            if (*blk != 0x53595547 || *endp != 0x45595547) {
                sprintf(d_1bc620, d_1b634b, e->file, e->line, p1);
                f_051870(d_1bc620, 0);
                goto done;
            }
 // haelt die Registerzuteilung wie im Original
            e->p = 0;
            d_1bc60c--;
            n = (unsigned)endp - (unsigned)blk;
            q = (char *)blk;
            n += 4;
            if (n & 1) { *q = 0xcc; q++; }
            if (n & 2) { *(short *)q = (short)0xcccc; q += 2; }
            n >>= 2;
            if (n != 0) {
                unsigned k;
                for (k = 0; k < n; k++) { *(unsigned *)q = 0xcccccccc; q += 4; }
            }
            if (idx < d_1bc61c) d_1bc61c = idx;
        } else {
            f_051870(d_1b63a1, (int)p1);
            goto done;
        }
    } else {
        if (p1 == 0) goto done;
        short found = 0, idx;
        short j = d_1bc61e;
        Ent *e = d_1bc614 + j;
        for (; j >= 0; j--, e--) {
            if (p2 == (char *)e->p) {
                found = 1;
                idx = j;
                if (j == d_1bc61e) d_1bc61e = j - found;
                break;
            }
        }
        if (found) {
            e->p = 0;
            p1 = p2;
            if (idx < d_1bc61c) d_1bc61c = idx;
            else { short keep = (found & 0) ? (short)0 : found; p1 = p2 + (keep - found); } // haelt die Registerzuteilung wie im Original
        }
    }
    d_1c11a0.f_0bdb00(p1, 0, 0);
    f_1455b5();
    p1 = 0;
done:
    f_1455b5();
    {
        int m; union REGS r; struct SREGS s; int info[12];
        r.x.eax = 0x500;
        memset(&s, 0, sizeof(s));
        s.es = FP_SEG(info);
        r.x.edi = FP_OFF(info);
        f_145702(0x31, &r, &r, &s);
        m = info[0]; if (d_1bc608 > m) d_1bc608 = m;
    }
    return p1;
}

//@ f_014950
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014950
 * - Aufgabe im Spiel: Durchsucht die globale Allokationstabelle d_1bc614 ab dem Index d_1bc61c bis 2499 (0x9c4)
 *   nach dem ersten freien Eintrag (e->p == 0) und gibt dessen Index zurück.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Der Index des ersten freien Tabellenplatzes oder -1, falls kein Platz frei ist.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1bc614 und Startindex d_1bc61c.
 === Ende Beschreibung === */
short f_014950()
{
    short i = d_1bc61c;
    Ent *e = d_1bc614 + i;
    for (; i < NN; i++, e++) { if (e->p == 0) return i; }
    return -1;
}

//@ f_0149a0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x0149a0
 * - Aufgabe im Spiel: Prüft bei aktiviertem Debug-Modus (d_1a01b4 != 0) sämtliche belegten Einträge unter den
 *   2.500 Plätzen der Tabelle d_1bc614 darauf, ob die Kopfmarke 0x53595547 ("GUYS") und die Fußmarke 0x45595547
 *   ("GUYE") noch unversehrt sind. Wird ein Pufferüberlauf oder -unterlauf entdeckt, formatiert die Funktion
 *   eine Fehlermeldung mit Quelldatei, Zeilennummer und Adresse in d_1bc620 und bricht das Spiel über f_051870
 *   ab.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globales Reentranz-Schutzflag d_1bc618 (verhindert rekursive Selbstprüfungen), Prüfmodus-Flag d_1a01b4 und
 *     Tabelle d_1bc614.
 === Ende Beschreibung === */
void f_0149a0()
{
    if (d_1bc618 == 0 && d_1bc614 != 0) {
        d_1bc618 = 1;
        if (d_1a01b4 != 0 && d_1bc614 != 0) {
            short i;
            Ent *e = d_1bc614;
            for (i = 0; i < NN; i++, e++) {
                if (e->p != 0) {
                    unsigned *w = e->e;
                    if (*e->p != 0x53595547 || *w != 0x45595547) {
                        sprintf(d_1bc620, d_1b63c6, e->file, e->line, (char *)e->p + 4);
                        f_051870(d_1bc620, 0);
                    }
                }
            }
        }
        d_1bc618 = 0;
    }
}

//@ f_014a60
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014a60
 * - Aufgabe im Spiel: Fragt über d_1c11a0.f_0bdbc0() ab, wie viele Bytes im internen Speicherpool d_1c11a0
 *   aktuell noch frei sind.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Die Anzahl der freien Bytes im Speicherpool d_1c11a0.
 * - Wichtige Variablen:
 *   - Globales Pool-Objekt d_1c11a0.
 === Ende Beschreibung === */
long f_014a60()
{
    return d_1c11a0.f_0bdbc0();
}

//@ f_014a70
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014a70
 * - Aufgabe im Spiel: Zählt, wie viele der 2.500 Einträge in der Allokationstabelle d_1bc614 aktuell unbelegt
 *   sind (e->p == 0).
 * - Eingaben: Keine (void).
 * - Rückgabewert: Die Anzahl der freien Slots (n) in d_1bc614.
 * - Wichtige Variablen:
 *   - Globale Tabelle d_1bc614.
 === Ende Beschreibung === */
int f_014a70()
{
    int n = 0;
    short i;
    Ent *e = d_1bc614;
    for (i = 0; i < NN; i++, e++) { if (e->p == 0) n++; }
    return n;
}

//@ f_014ab0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014ab0
 * - Aufgabe im Spiel: Überladener C++-Operator new(size, tag) für Einzelobjekte, der Dateiname und Zeilennummer
 *   aus der übergebenen Mark-Struktur (tag) liest und an f_014540 weiterleitet.
 * - Eingaben: Objektgröße (size) und Zeiger auf die Herkunftsmarkierung (tag).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void *f_014ab0(unsigned size, void *tag)
{
    return f_014540(size, ((Mark *)tag)->file, ((Mark *)tag)->line);
}

//@ f_014ac0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014ac0
 * - Aufgabe im Spiel: Überladener C++-Operator new[](size, tag) für Objekt-Arrays, der Dateiname und
 *   Zeilennummer aus tag entnimmt und f_014540 aufruft.
 * - Eingaben: Arraygröße (size) und Zeiger auf die Herkunftsmarkierung (tag).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void *f_014ac0(unsigned size, void *tag)
{
    return f_014540(size, ((Mark *)tag)->file, ((Mark *)tag)->line);
}

//@ f_014ad0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014ad0
 * - Aufgabe im Spiel: Standard-Operator new(size) ohne explizite Herkunftsangabe, der f_014540 mit der
 *   Standard-Kennzeichnung d_1a01b8 und Zeilennummer 0 aufruft.
 * - Eingaben: Angeforderte Größe (size).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock.
 * - Wichtige Variablen:
 *   - Globale Standard-Herkunftszeichenkette d_1a01b8.
 === Ende Beschreibung === */
void *f_014ad0(unsigned size)
{
    return f_014540(size, d_1a01b8, 0);
}

//@ f_014af0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014af0
 * - Aufgabe im Spiel: Standard-Array-Operator new[](size) ohne explizite Herkunftsangabe, der f_014540 mit
 *   d_1a01b8 und Zeile 0 aufruft.
 * - Eingaben: Angeforderte Größe (size).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock.
 * - Wichtige Variablen:
 *   - Globale Standard-Herkunftszeichenkette d_1a01b8.
 === Ende Beschreibung === */
void *f_014af0(unsigned size)
{
    return f_014540(size, d_1a01b8, 0);
}

//@ f_014b10
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014b10
 * - Aufgabe im Spiel: Hilfsfunktion (mark), die vor einem new-Aufruf den Quelldateinamen (file) und die
 *   Zeilennummer (line) in der globalen Struktur d_1bc5fc ablegt und deren Adresse zur Übergabe an f_014ab0 bzw.
 *   f_014ac0 zurückgibt.
 * - Eingaben: Quelldateiname (file) und Zeilennummer (line).
 * - Rückgabewert: Zeiger auf die globale Struktur d_1bc5fc.
 * - Wichtige Variablen:
 *   - Globale Herkunftsstruktur d_1bc5fc.
 === Ende Beschreibung === */
void *f_014b10(const char *file, int line)
{
    d_1bc5fc.file = file;
    d_1bc5fc.line = line;
    return &d_1bc5fc;
}

#pragma inline_depth(0)
//@ f_014b30
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014b30
 * - Aufgabe im Spiel: 16-Byte-ausgerichteter Speicherallokator (radmalloc, Pascal-Aufrufkonvention für den
 *   Smacker-Videoplayer): Er fordert size + 16 Bytes entweder aus dem Sonderpool d_1bf240 oder über f_014540 an,
 *   richtet den Rückgabezeiger p auf die nächste 16-Byte-Grenze aus und speichert den Verschiebungswert (1..16)
 *   unmittelbar im Byte p[-1] vor dem Nutzbereich.
 * - Eingaben: Angeforderte Bytegröße (size).
 * - Rückgabewert: Der auf 16 Bytes ausgerichtete Zeiger p oder 0 bei Fehler bzw. size == 0.
 * - Wichtige Variablen:
 *   - Optionaler globaler Sonderpool-Zeiger d_1bf240 und Kennzeichnungs-String d_1a01c8.
 === Ende Beschreibung === */
void * __pascal f_014b30(unsigned size)
{
    if (size == 0) return 0;
    unsigned char *p;
    unsigned nsize = size + 0x10;
    if (d_1bf240) p = size != (unsigned)-1 ? (unsigned char *)d_1bf240->f_0bda70(nsize, d_1a01c8, 0) : 0;
    else p = size != (unsigned)-1 ? (unsigned char *)f_014540(nsize, d_1a01c8, 0) : 0;
    if (p) {
        {
            {
                unsigned char lo = (unsigned char)(unsigned)p;
                lo &= 0xf;
                unsigned char n = 0x10;
                n -= lo;
                p += n;
                p[-1] = n;
            }
        }
    }
    return p;
}
#pragma inline_depth(3)

//@ f_014ba0
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x014ba0
 * - Aufgabe im Spiel: Gibt einen mit f_014b30 (radmalloc) angeforderten, auf 16 Bytes ausgerichteten
 *   Speicherblock wieder frei (radfree), indem aus p[-1] der Ausrichtungsversatz ausgelesen und die
 *   ursprüngliche Blockadresse p - p[-1] an d_1bf240->f_0bdb00 bzw. f_014710 übergeben wird.
 * - Eingaben: Der ausgerichtete Nutzdaten-Zeiger (p).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globaler Pool-Zeiger d_1bf240.
 === Ende Beschreibung === */
void __pascal f_014ba0(unsigned char *p)
{
    if (d_1bf240 != 0) {
        d_1bf240->f_0bdb00(p - p[-1], 0, 0);
        return;
    }
    f_014710(p - p[-1]);
}
