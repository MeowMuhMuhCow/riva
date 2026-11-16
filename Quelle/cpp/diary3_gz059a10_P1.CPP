/* === Beschreibung (Katalog) ===
 * Einheit diary3_gz059a10 (0x0595f0 - 0x059d60)
 *
 * Überblick
 * Diese Einheit umfasst diary3.cpp (0x0595f0-0x059a10) sowie das anschließende Grenzstück gz_059a10
 * (0x059a10-0x059d60). Sie verwaltet die Textpuffer des Tagebuchs, baut das Kategorienmenü für die
 * Stichwortsuche auf, trägt die Namen der Gruppenmitglieder automatisch in die Stichworttabelle ein und gibt
 * Tagebuchseiten formatiert auf dem Drucker oder in ..\DIARY.TXT aus.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 8/9 gleich (suche.py 29.10.2026, Basis diary3_gz059a10_P1.CPP)
// OPT -4r -oneatx -zp1 -s
// P3 2/4 gleich (suche.py 25.10.2026, Basis diary3_P1.CPP)
// diary3.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0595F0-0x059A10
#include <string.h>
void *f_014710(void *p);
char *f_014540(int p1, const char *p2, int p3);
int f_038c80(int p1);
int f_039040(int p1);
int f_0391b0(int p1, int p2);






extern int d_1c0004;

extern const char d_1a1774[];
struct D3 { int c0; char *p4; char *p8; char pad[0x1c]; unsigned char b28[8]; int c30; };
//@ f_059d50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Funktion ohne Anweisungen am Ende des Adressbereichs (0x059d50), die vermutlich als
 *   leerer Destruktor oder Platzhalter an der Modulgrenze zu diskmen2.cpp dient.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine lokalen oder globalen Variablen verwendet.
 === Ende Beschreibung === */
void f_059d50(void)
{
}

//@ f_0595f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fordert beim ersten Aufruf (t->c30 == 0) die beiden 2000-Byte-Arbeitspuffer des Tagebuchs
 *   (t->p4 für den Seitentext und t->p8 für den Zeilenpuffer) auf dem Heap an und erhöht den Referenzzähler
 *   t->c30, sodass verschachtelte Tagebuchoperationen dieselben Puffer gemeinsam nutzen können.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger t auf das Tagebuch-Objekt (d_1c2c00) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Feld t->c30 (Offset +0x30) zählt die aktiven Pufferanforderungen, während t->p4 (+4)
 *   und t->p8 (+8) die Zeiger auf die beiden 2000-Byte-Puffer halten.
 === Ende Beschreibung === */
void f_0595f0(D3 *t)
{
    if (t->c30 == 0) {
        t->p4 = f_014540(2000, d_1a1774, 0x35);
        t->p8 = f_014540(2000, d_1a1774, 0x36);
    }
    ++t->c30;
}
//@ f_059630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt als Gegenstück zu f_0595f0 bei der letzten Freigabe (t->c30 == 1) die beiden
 *   2000-Byte-Tagebuchpuffer t->p8 und t->p4 wieder frei und verringert den Referenzzähler t->c30 um 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger t auf das Tagebuch-Objekt (d_1c2c00) und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Wie in f_0595f0 steuert der Zähler t->c30, wann die Pufferzeiger t->p4 und t->p8
 *   tatsächlich über f_014710 gelöscht werden.
 === Ende Beschreibung === */
void f_059630(D3 *t)
{
    if (t->c30 == 1) {
        t->p8 = (char *)f_014710(t->p8);
        t->p4 = (char *)f_014710(t->p4);
    }
    --t->c30;
}
//@ f_059660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Stichworttabelle 0x40080002 ein und prüft für jede der fünf Stichwortkategorien 0..4
 *   (Kennungen 0xa4..0xa8), ob mindestens ein bereits im Tagebuch gefundener Begriff (e[1] != 0) vorhanden ist.
 *   Alle vorhandenen Kategorien, bei mindestens einem Treffer zusätzlich der Sammelpunkt 5 ("alle Kategorien")
 *   sowie stets der Punkt 6 ("eigene Einträge") werden in das Array t->b28 eingetragen, aus dem f_057a00 (diary)
 *   das Suchmenü aufbaut.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger t auf das Tagebuch-Objekt und gibt die Anzahl k der
 *   eingetragenen Menüpunkte als short zurück.
 * - Wichtige Variablen: Das Byte-Array t->b28[8] (Offset +0x28 im Tagebuch-Objekt) speichert die verfügbaren
 *   Kategorienummern für das Suchmenü.
 === Ende Beschreibung === */
short f_059660(D3 *t)
{
    short k, j, m;
    signed char c;
    int found;
    unsigned char *p2;
    int size;
    memset(t->b28, 0, 8);
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x40080002, 0x200);
    size = ((int)(((RivaFileManager*)(&d_1c2098))->f_144a00()));
    p2 = (unsigned char *)f_014540(size, d_1a1774, 0x5a);
    k = 0;
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p2), size)));
    j = 0;
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    for (c = j + 0xa4; j <= 4; c++, j++) {
        unsigned char cb = c;
        m = 0;
        found = 0;
        do {
            unsigned char *e = p2 + m * 0x17;
            if (e[2] == cb && e[1]) {
                t->b28[k++] = (unsigned char)j;
                found = 1;
            }
            m++;
        } while (p2[m * 0x17] != 0xff && !found);
    }
    if (k > 0) t->b28[k++] = 5;
    t->b28[k++] = 6;
    delete p2;
    return k;
}
//@ f_059780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft vor dem Schreiben eines neuen Tagebucheintrags alle Spielerhelden der aktiven
 *   Gruppe d_1c0004, kürzt jeden Heldennamen am ersten Leerzeichen auf das erste Wort und trägt ihn in die
 *   ersten 20 Sätze der Stichworttabelle 0x40080002 ein (mit Gefunden-Merker 1), sofern dort noch kein passender
 *   oder kürzerer gleichlautender Eintrag steht. Dadurch werden Heldennamen im Tagebuchtext automatisch als
 *   suchbare Stichwörter erkannt.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine genutzten Parameter entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die globale Variable d_1c0004 bezeichnet die aktive Heldengruppe; p2 hält die aus der
 *   Datei 0x40080002 geladene Tabelle aus 23-Byte-Sätzen (0x17 Bytes je Satz, Name ab Offset +3).
 === Ende Beschreibung === */
void f_059780(void)
{
    short i;
    int cur, size, found;
    short len = 0, l2, n;
    char *buf, *p2;
    found = 0;
    cur = f_038c80(d_1c0004);
    if (cur == (short)0) return;
    buf = new (mark(d_1a1774, 0x8b)) char[16];
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x40080002, 0x200);
    size = ((int)(((RivaFileManager*)(&d_1c2098))->f_144a00()));
    p2 = f_014540(size, d_1a1774, 0x9b);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144920((void *)( p2), size)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    for (;;) {
        short l2; short idx = 0;
        found = 0;
        idx = -1;
        memcpy(buf, f_0422b0((struct hero *)(cur)), 16);
        i = 0;
        { char *q = buf;
        while (q[i] != ' ' && i < 16) i++;
        while (i < 16) q[i++] = 0; }
        len = strlen(buf);
        n = len;
        for (i = 0; i < (short)20; i++) {
            l2 = strlen(p2 + i * 0x17 + 3);
            if ((short)l2 && (short)l2 < (short)len) n = l2;
            if (strncmp(buf, p2 + i * 0x17 + 3, n) == 0) {
                if ((short)n != (short)len) found = 1; else idx = i;
                break;
            }
            if ((short)n == (short)l2 && strncmp(buf, p2 + i * 0x17 + 3, n) == 0) {
                idx = i;
                break;
            }
        }
        if (idx != -1) {
            strcpy(p2 + idx * 0x17 + 3, buf);
        } else {
            if (!found) {
                i = 0;
                while (p2[i * 0x17 + 3] && i < (short)20) i++;
                if (i != (short)20) {
                    strcpy(p2 + i * 0x17 + 3, buf);
                    p2[i * 0x17 + 1] = 1;
                }
            }
        }
        cur = f_0391b0(d_1c0004, cur);
        if (cur == f_039040(d_1c0004) || cur == f_038c80(d_1c0004)) break;
    }
    ((RivaFileManager*)(&d_1c2098))->f_1448b0( 0x40080002, 0x201);
    ((int)(((RivaFileManager*)(&d_1c2098))->f_144960((void *)( p2), size)));
    ((RivaFileManager*)(&d_1c2098))->f_1449a0();
    delete p2;
    delete buf;
}

// Getrennte Quellsicht gz_059a10; keine neuen Datenobjekte.
// P3 2/5 gleich (suche.py 25.10.2026, Basis gz_059a10_P1.CPP)
// gz_059a10.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x059A10-0x059D60
#include <string.h>




struct ag700_1_Dy { short w0; unsigned short w2; char *p4; char *p8; };
struct ag700_1_Q { short a0; short a2; short a4; };
struct ag700_1_S { char pad[0x14]; ag700_1_Q *q; char pad2[0x24]; };
int ag700_1_f_0591c0(ag700_1_Dy *p1, int p2);
int ag700_1_f_0d2e70();
int ag700_1_f_0d2f90(int p1, int p2);
int ag700_1_f_0e8cd0();
int ag700_1_f_0e8eb0(void *p1, int p2);
int ag700_1_f_0e93f0(void *p1, void *p2, int p3);
int ag700_1_f_0e9240(int p1);
int ag700_1_f_125400(void *p1, void *p2, void *p3, void *p4);
int ag700_1_f_1254a0(void *p1, int p2);
void ag700_1_f_145300(void *p1, int p2, int p3);
void f_059ad0(ag700_1_Dy *t);
extern short ag700_1_d_1c0090;
extern unsigned short ag700_1_d_1c21b4;
extern int ag700_1_d_1c3498;
extern int ag700_1_d_1c349c;
extern int ag700_1_d_1c3870;
extern int ag700_1_d_1c38b0;
extern signed char ag700_1_d_1bfaf8;
extern signed char ag700_1_d_1a16c8, ag700_1_d_1a16c9, ag700_1_d_1a16ca, ag700_1_d_1a16cb, ag700_1_d_1a16cc, ag700_1_d_1a16d0;
extern const char *ag700_1_d_1a965c;
extern const char ag700_1_d_1a16bc[];
extern const char ag700_1_d_1b6e64[];
#pragma aux ag700_1_d_1a16bc "d_1a16bc"
#pragma aux ag700_1_d_1a16c8 "d_1a16c8"
#pragma aux ag700_1_d_1a16c9 "d_1a16c9"
#pragma aux ag700_1_d_1a16ca "d_1a16ca"
#pragma aux ag700_1_d_1a16cb "d_1a16cb"
#pragma aux ag700_1_d_1a16cc "d_1a16cc"
#pragma aux ag700_1_d_1a16d0 "d_1a16d0"
#pragma aux ag700_1_d_1a965c "d_1a965c"
#pragma aux ag700_1_d_1b6e64 "d_1b6e64"
#pragma aux ag700_1_d_1bfaf8 "d_1bfaf8"
#pragma aux ag700_1_d_1c0090 "d_1c0090"
#pragma aux ag700_1_d_1c21b4 "d_1c21b4"
#pragma aux ag700_1_d_1c3498 "d_1c3498"
#pragma aux ag700_1_d_1c349c "d_1c349c"
#pragma aux ag700_1_d_1c3870 "d_1c3870"
#pragma aux ag700_1_d_1c38b0 "d_1c38b0"
#pragma aux ag700_1_f_0591c0 "f_0591c0"
#pragma aux ag700_1_f_0d2e70 "f_0d2e70"
#pragma aux ag700_1_f_0d2f90 "f_0d2f90"
#pragma aux ag700_1_f_0e8cd0 "f_0e8cd0"
#pragma aux ag700_1_f_0e8eb0 "f_0e8eb0"
#pragma aux ag700_1_f_0e9240 "f_0e9240"
#pragma aux ag700_1_f_0e93f0 "f_0e93f0"
#pragma aux ag700_1_f_125400 "f_125400"
#pragma aux ag700_1_f_1254a0 "f_1254a0"
#pragma aux ag700_1_f_145300 "f_145300"
//@ f_059a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schneidet einen bis zu 16 Zeichen langen Namen s am ersten Leerzeichen ab und füllt alle
 *   nachfolgenden Zeichen bis Index 15 mit Nullbytes auf.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten this-Parameter p1 und den Zeiger s auf den
 *   16-Byte-Namenspuffer. Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Schleifenvariable i läuft von 0 bis 15 über das Zeichenarray s.
 === Ende Beschreibung === */
void f_059a10(int p1, char *s)
{
    short i;
    i = 0;
    while (s[i] != ' ' && i < 16) i++;
    while (i < 16) s[i++] = 0;
}
//@ f_059a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Druckt alle Tagebuchseiten im 0-basierten Bereich von p2 bis einschließlich p3, indem jede
 *   Seite nacheinander über f_0591c0 geladen und über f_059ad0 an den Drucker bzw. die Druckdatei gesendet wird.
 *   Während des Druckvorgangs wird der Warte-Mauszeiger (5) angezeigt und am Ende der Druckauftrag über f_0e8cd0
 *   abgeschlossen sowie die zuvor betrachtete Tagebuchseite wiederhergestellt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger t auf das Tagebuch-Objekt, die erste zu druckende
 *   Seitennummer p2 und die letzte Seitennummer p3 (beide 0-basiert). Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokale Variable sv sichert die vor dem Drucken geöffnete Seitennummer t->w2, damit
 *   nach dem Drucklauf wieder dieselbe Seite geladen werden kann.
 === Ende Beschreibung === */
void f_059a40(ag700_1_Dy *t, int p2, unsigned short p3)
{
    int t_47;
    unsigned short sv;
    short p3_ = p3;
    sv = t->w2;
    ag700_1_f_0d2f90(5, 1);
    t->w2 = p2;
    for (; t->w2 <= p3_; t->w2++) {
        ag700_1_d_1a965c = ag700_1_d_1a16bc;
        t_47 = ag700_1_f_0591c0(t, t->w2);
        if (t_47 != 0) {
            ag700_1_d_1a965c = ag700_1_d_1b6e64;
            f_059ad0(t);
        }
        ;
    }
    ag700_1_f_0e8cd0();
    ag700_1_d_1a965c = 0;
    ag700_1_f_0591c0(t, (t->w2 = sv));
    ag700_1_f_0d2e70();
}
//@ f_059ad0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine einzelne, bereits in t->p4 geladene Tagebuchseite auf dem Drucker bzw. in
 *   ..\DIARY.TXT aus: zuerst die formatierte Kopfzeile (0x803006a, "Seite x von n") und die Trennlinie
 *   (0x803006b), danach die Überschriften und Textabsätze ohne interne Farb- und Kategoriemarken und schließlich
 *   Leerzeilen (f_0e9240) bis zum Ende der Druckseite.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger t auf das Tagebuch-Objekt und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die globale Variable d_1c0090 zählt die bereits gedruckten Zeilen der aktuellen Seite,
 *   d_1bfaf8 enthält die konfigurierte Seitenlänge des Druckers (geteilt durch 3 als Zeilenlimit), und wie in
 *   f_058960 (diary2) werden hier nur Kategoriemarken im Bereich d_1a16cc..d_1a16d0 ([4..8]) statt bis d_1a16d1
 *   ([9]) übersprungen.
 === Ende Beschreibung === */
void f_059ad0(ag700_1_Dy *t)
{
    ag700_1_S s;
    short pos;
    short len;
    short i;
    signed char c;

    pos = 0;
    i = 0;
    len = strlen(t->p4);
    ag700_1_f_125400(&s, &ag700_1_d_1c349c, &ag700_1_d_1c3870, &ag700_1_d_1c3498);
    s.q->a2 = t->w2 + 1;
    ag700_1_d_1c0090 = 0;
    s.q->a4 = t->w0;
    ag700_1_f_145300(t->p8, 0, 0x7d0);
    ag700_1_f_0e93f0(&ag700_1_d_1c38b0, t->p8, 0x803006a);
    ag700_1_f_0e8eb0(t->p8, 1);
    ag700_1_f_145300(t->p8, 0, 0x7d0);
    ag700_1_f_0e93f0(&ag700_1_d_1c38b0, &ag700_1_d_1c21b4, 0x803006b);
    ag700_1_f_0e8eb0(&ag700_1_d_1c21b4, 1);
    while (i <= len) {
        c = t->p4[i++];
        if (c == ag700_1_d_1a16c8) {
            if (t->p8[0]) {
                t->p8[pos] = 0;
                pos = 0;
                ag700_1_f_0e8eb0(t->p8, 0);
                ag700_1_f_0e9240(0);
            }
            while (c != ag700_1_d_1a16c9 && c != ag700_1_d_1a16ca) {
                c = t->p4[i++];
                int ox = (pos & 0) ? 0 : pos; // Mehrblock-Index fuer die Registerfolge
                { signed char rr_0=ag700_1_d_1a16ca; ag700_1_d_1a16ca=rr_0; } // Berechneter Zusatzknoten
                { signed char rr_1=ag700_1_d_1a16cb; ag700_1_d_1a16cb=rr_1; } // Berechneter Zusatzknoten
                t->p8[ox] = c;
                int rt_0=ag700_1_d_1c3498;
                rt_0=(rt_0&0)?(int)0:rt_0; ag700_1_d_1c3498=rt_0; // Berechnete Sortierform
                int rt_1=ag700_1_d_1c349c;
                rt_1=(rt_1&0)?(int)0:rt_1; ag700_1_d_1c349c=rt_1; // Berechnete Sortierform
                int rt_2=ag700_1_d_1c3870;
                rt_2=(rt_2&0)?(int)0:rt_2; ag700_1_d_1c3870=rt_2; // Berechnete Sortierform
                { int rt_3=ag700_1_d_1c38b0; ag700_1_d_1c38b0=rt_3; } // Einfacher Roundtrip fuer die Konfliktsortierung
                short rt_4=ag700_1_d_1c0090;
                rt_4=(rt_4&0)?(short)0:rt_4; ag700_1_d_1c0090=rt_4; // Berechnete Sortierform
                signed char rt_5=ag700_1_d_1a16c8;
                rt_5=(rt_5&0)?(signed char)0:rt_5; ag700_1_d_1a16c8=rt_5; // Berechnete Sortierform
                signed char rt_6=ag700_1_d_1a16c9;
                rt_6=(rt_6&0)?(signed char)0:rt_6; ag700_1_d_1a16c9=rt_6; // Berechnete Sortierform
                pos++;
            }
            t->p8[pos - 1] = t->p8[pos] = 0;
            ag700_1_f_0e9240(0);
            ag700_1_f_0e8eb0(t->p8, 0);
            pos = 0;
            ag700_1_f_0e9240(0);
        } else {
            if (c >= ag700_1_d_1a16cc && c <= ag700_1_d_1a16d0) {
                i++;
            } else if (c != ag700_1_d_1a16c9 && c != ag700_1_d_1a16ca && c != ag700_1_d_1a16cb) {
                t->p8[pos++] = c;
            }
        }
    }
    { int idx=(pos&0)?0:pos;  t->p8[idx]=0; } // Mehrblock-Index fuer den Nullterminator
    ag700_1_f_0e8eb0(t->p8, 0);
    while (ag700_1_d_1c0090 > (signed char)(ag700_1_d_1bfaf8 / 3)) {
        ag700_1_d_1c0090 -= (short)(signed char)(ag700_1_d_1bfaf8 / 3);
    }
    for (;;) {
        signed char grenze = ag700_1_d_1bfaf8 / 3;
        int grenze_i = (grenze & 0) ? 0 : grenze; // Mehrblock-Quotient wie im Original
        if (ag700_1_d_1c0090 >= grenze_i) break;
        ag700_1_f_0e9240(0);
    }
    { int rr_end=ag700_1_d_1c3498; ag700_1_d_1c3498=rr_end; } // Berechneter Abschlussknoten
    ag700_1_f_1254a0(&s, 0);
}


//@ f_059d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert die Trennlinie (0x803006b) in den globalen Textpuffer d_1c21b4 und gibt sie über
 *   f_0e8eb0 als einzelne Zeile auf dem Drucker aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Verwendet das globale Textausgabe-Objekt d_1c38b0 und den Textpuffer d_1c21b4.
 === Ende Beschreibung === */
void f_059d20(void)
{
    ag700_1_f_0e93f0(&ag700_1_d_1c38b0, &ag700_1_d_1c21b4, 0x803006b);
    ag700_1_f_0e8eb0(&ag700_1_d_1c21b4, 1);
}
