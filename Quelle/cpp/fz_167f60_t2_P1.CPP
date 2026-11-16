/* === Beschreibung (Katalog) ===
 * Einheit fz_167f60_t2 (0x169412 - 0x1699CC)
 *
 * Überblick
 * Diese Einheit enthält den zweiten Teil der digitalen Soundbibliothek (HMI SOS): das Schließen und Freigeben
 * eines digitalen Soundtreibers (f_169412), die Reservierung und Freigabe von DMA-fähigem DOS-/XMS-Speicher
 * (f_1695ef, f_1696b8, f_1697d4), die fünf kanalspezifischen DMA-Interrupt-/Mischer-Einsprungpunkte (f_169845
 * bis f_1698d1) sowie die Initialisierungs- und Abschlussfunktionen des Gesamtsystems (f_16991e, f_16997a).
 === Ende Beschreibung === */
// P3 10/14 gleich (suche.py 25.10.2026, Basis fz_167f60_t2_P1.CPP)
// CC wcc386
// P1 10/14 gleich
// OPT -3r -od -zp1 -s -nt=_TEXT2
// fz_167f60_t2.c (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x169412-0x1699CC
struct S { unsigned char fl; char q1[0x2f]; int f30; char q2[0x14]; int f48; char q3[4]; int f50; char q4[4]; int f58; char q5[8]; int f64; char q6[0x70]; int fd8; unsigned short fdc; short qde; int fe0; unsigned short fe4; short qe6; char qe8[8]; int ff0; int ff4; unsigned short ff8; short qfa; char qfc[4]; int f100; };
struct R { int v; short w; };
extern struct S *d_1af4c8[];
extern char d_1af4dc[];
extern int d_1af4e8;
extern unsigned char d_1af3c4;
extern char d_1af3c8[];
int f_17c0ec(int a);
int f_17c1ad(int a, int b, int c, int d);
int f_17c2c0(int a, int b, int c, int d);
int f_17c3ed(int a);
int f_17c50c(void);
int f_17c529(int a, int *b, int *c);
int f_17c56a(int a, int b);
int f_17c598(int a);
int f_17c604(int a);
int f_17c651(int a);
int f_17c709(void *a);
int f_17cbaf(void);
int f_17cf21(void);
int f_17bc5d(int p1);
int f_17bdb1(int p1, int p2);
void f_17c6e0(void __far *d, void __far *s, int n);
char *f_15f2d6(char *d, const char *s);
void f_1697d4(int p1, int p2, short p3);
int f_1696b8(void __far **p1, int *p2, int *p3);
int f_17befd(int a, int b);
int f_17c0b6(int a, unsigned *b, int *c);
#pragma aux f_17c0ec "*" parm caller [];
#pragma aux f_17befd "*" parm caller [];
#pragma aux f_17c0b6 "*" parm caller [];
#pragma aux f_1695ef "*";
#pragma aux f_17c1ad "*" parm caller [];
#pragma aux f_17c2c0 "*" parm caller [];
#pragma aux f_17c3ed "*" parm caller [];
#pragma aux f_17c50c "*" parm caller [];
#pragma aux f_17c529 "*" parm caller [];
#pragma aux f_17c56a "*" parm caller [];
#pragma aux f_17c598 "*" parm caller [];
#pragma aux f_17c604 "*" parm caller [];
#pragma aux f_17c651 "*" parm caller [];
#pragma aux f_17c709 "*" parm caller [];
#pragma aux f_17cbaf "*";
#pragma aux f_17cf21 "*";
#pragma aux f_17bc5d "*";
#pragma aux f_17bdb1 "*";
#pragma aux f_17c6e0 "*";
#pragma aux f_15f2d6 "*";
#pragma aux f_169412 "*";
#pragma aux f_1696b8 "*";
#pragma aux f_1697d4 "*";
#pragma aux f_169845 "*";
#pragma aux f_169868 "*";
#pragma aux f_16988b "*";
#pragma aux f_1698ae "*";
#pragma aux f_1698d1 "*";
#pragma aux f_1698f4 "*";
#pragma aux f_169909 "*";
#pragma aux f_16991e "*";
#pragma aux f_16997a "*";
#pragma aux f_1699b7 "*";
//@ f_169412
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schließt den digitalen Soundtreiber p1, stoppt über die Treiberfunktionen f_17c1ad,
 *   f_17c2c0 und f_17c3ed die Hardware-DMA-Übertragung, gibt bei p2 != 0 den DMA-Puffer (f_1697d4 bzw. f_17c0ec)
 *   und bei p3 != 0 die Treiber- und Kanalpuffer (f_17bc5d, f_17bdb1) frei und löscht den Eintrag aus
 *   d_1af4c8[p1].
 * - Eingaben: Treiber-Handle p1, Flag p2 zum Freigeben des DMA-Puffers und Flag p3 zum Entladen des
 *   Treibermoduls.
 * - Rückgabewert: int - 0 bei Erfolg, 1 wenn der Treiber nicht geladen war, oder 10 bei ungültigem Handle.
 * - Wichtige Variablen:
 *   - p: Zeiger auf die Treiberstruktur d_1af4c8[p1].
 === Ende Beschreibung === */
#include <i86.h>
int f_169412(int p1, int p2, int p3)
{
    struct F { char pad[0xf4]; void __far *ptr; };
    struct S *p;
    p = d_1af4c8[p1];
    if (p == 0) {
        return 10;
    }
    if ((p->fl & 2) == 0) {
        return 1;
    }
    p->f30 = 0;
    f_17c1ad(p->fe0, p->fe4, p->fd8, p->fdc);
    f_17c2c0(p->fe0, p->fe4, p->fd8, p->fdc);
    f_17c3ed(p->f64);
    if ((p->fl & 4) && p2) {
        p->fl &= 0xfb;
        if ((f_17c50c() & 0xff) == 3) {
            ((void (*)(int, int, int))f_1697d4)(FP_SEG(((struct F *)p)->ptr), p->f100, p->ff0);
        } else {
            f_17c0ec(FP_SEG(((struct F *)p)->ptr));
            p->fl &= 0xfb;
        }
    }
    if ((p->fl & 2) && p3) {
        f_17bc5d(p1);
        p->fdc = 0;
        p->fd8 = 0;
        p->fe4 = 0;
        p->fe0 = 0;
        f_17bdb1(p->f48, p->f50);
        f_17bdb1(p->f58, 0x1e00);
        p->fl &= 0xfd;
    }
    d_1af4c8[p1] = 0;
    p->fl &= 0xfe;
    return 0;
}
//@ f_1695ef
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Reserviert einen p1 Bytes großen, garantiert nicht über eine 64-KB-Physisch-Seitengrenze
 *   ragenden DMA-Speicherblock im unteren DOS-Speicher (entweder über VDS/DPMI-Hilfsfunktionen f_1696b8/f_17befd
 *   oder durch wiederholtes Anfordern über f_17c0b6, bis (*p2 & 0xFFFF) <= 0xFFFF - p1 erfüllt ist).
 * - Eingaben: Benötigte Puffergröße p1, Rückgabezeiger p2 für die lineare/physische Adresse, Selektorzeiger p3
 *   und Far-Pointer-Struktur p4.
 * - Rückgabewert: int - Adresse des reservierten DMA-fähigen Speicherblocks oder 0 bei Fehler.
 * - Wichtige Variablen:
 *   - v: Zugewiesener DOS-Speicherselektor.
 === Ende Beschreibung === */
int f_1695ef(unsigned p1, unsigned *p2, int *p3, struct R *p4)
{
    int v;
    if ((f_17c50c() & 0xff) == 3) {
        if (f_1696b8(p4, p3, p2) != 0) {
            return 0;
        }
        f_17befd(p4->v, p1);
        return p4->v;
    }
    f_17c0b6((p1 >> 4) + 4, p2, &v);
    while ((*p2 & 0xffff) > 0xffff - p1) {
        f_17c0b6((p1 >> 4) + 4, p2, &v);
    }
    *(void __far **)p4 = (void __far *)((__segment)v :> (void __near *)0);
    return *p2;
}
//@ f_1696b8
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fordert über den Virtual-DMA-Service (VDS) beziehungsweise DPMI-Puffer (f_17c529,
 *   f_17c598, f_17c651) einen seitenausgerichteten DMA-Puffer an und trägt dessen Far-Pointer in *p1 sowie die
 *   Adresse in *p3 ein.
 * - Eingaben: Ausgabezeiger p1 (Far-Pointer), p2 und p3 (physische/lineare Adresse).
 * - Rückgabewert: int - 0 bei Erfolg, 5 bei Fehler.
 * - Wichtige Variablen:
 *   - d_1af4dc, d_1af4e8: Globale VDS-Deskriptorstruktur und physische Pufferadresse.
 === Ende Beschreibung === */
int f_1696b8(void __far **p1, int *p2, int *p3)
{
    int b; int pad; int a;
    int __far *fp;
    int t14; int r18; int r1c;
    t14 = 0;
    r18 = 0;
    *p1 = (void __far *)0;
    *p2 = 0;
    *p3 = 0;
    b = 0;
    if (f_17c529(0x20, &a, &b) != 0) {
        return 0;
    }
    fp = (int __far *)((__segment)a :> (int __near *)0);
    *fp = 0x1000;
    r18 = f_17c598(b);
    f_17c6e0((void __far *)d_1af4dc, (void __far *)fp, 0x10);
    f_17c56a(a, b);
    if (r18 == 0) {
        d_1af4e8 &= 0xfffff000;
        r1c = f_17c651(d_1af4e8);
        t14 = d_1af4e8;
        *p1 = (void __far *)((__segment)0 :> (void __near *)r1c);
        *p3 = t14;
        return 0;
    }
    return 5;
}
//@ f_1697d4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt einen zuvor über f_1696b8 angeforderten VDS-DMA-Speicherblock mittels f_17c604 und
 *   f_17c56a wieder frei.
 * - Eingaben: Segment/Selektor p1, Offset p2 und Größe p3.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1697d4(int p1, int p2, short p3)
{
    int __far *fp;
    int a; int b;
    f_17c529(0x20, &a, &b);
    fp = (int __far *)((__segment)a :> (int __near *)0);
    f_17c6e0((void __far *)fp, (void __far *)d_1af4dc, 0x10);
    f_17c604(b);
    f_17c56a(a, b);
}
//@ f_169845
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Mischer-/DMA-Callback für den ersten digitalen Soundtreiber (d_1af4c8[0]), der die
 *   Mischroutine f_17c709 aufruft.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_169845(void)
{
    f_17c709(d_1af4c8[0]);
}
//@ f_169868
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Mischer-/DMA-Callback für den zweiten digitalen Soundtreiber (d_1af4c8[1]).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_169868(void)
{
    f_17c709(d_1af4c8[1]);
}
//@ f_16988b
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Mischer-/DMA-Callback für den dritten digitalen Soundtreiber (d_1af4c8[2]).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_16988b(void)
{
    f_17c709(d_1af4c8[2]);
}
//@ f_1698ae
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Mischer-/DMA-Callback für den vierten digitalen Soundtreiber (d_1af4c8[3]).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1698ae(void)
{
    f_17c709(d_1af4c8[3]);
}
//@ f_1698d1
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Mischer-/DMA-Callback für den fünften digitalen Soundtreiber (d_1af4c8[4]).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1698d1(void)
{
    f_17c709(d_1af4c8[4]);
}
//@ f_1698f4
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1698f4(void)
{
}
//@ f_169909
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_169909(void)
{
}
//@ f_16991e
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert das digitale SOS- Gesamtsystem über f_17cbaf, setzt das Initialisierungs-Bit
 *   in d_1af3c4 und kopiert den optionalen Treiber-Suchpfad p1 nach d_1af3c8.
 * - Eingaben: Optionaler Treiberverzeichnis-Pfad p1 und Systemflags p2.
 * - Rückgabewert: int - 0 bei Erfolg, sonst Fehlercode von f_17cbaf.
 * - Wichtige Variablen:
 *   - d_1af3c4: Status-Flag des SOS-Systems.
 *   - d_1af3c8: Gespeicherter Dateipfad für .DRV-Treiberdateien.
 === Ende Beschreibung === */
int f_16991e(char *p1, int p2)
{
    int t;
    t = f_17cbaf();
    if (t != 0) {
        return t;
    }
    d_1af3c4 |= 1;
    if (p1 != 0) {
        f_15f2d6(d_1af3c8, p1);
    } else {
        d_1af3c8[0] = 0;
    }
    return 0;
}
//@ f_16997a
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Beendet das digitale SOS-Gesamtsystem über f_17cf21 und löscht das Aktiv-Bit in d_1af3c4.
 * - Eingaben: Keine.
 * - Rückgabewert: int - gibt immer 0 zurück.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_16997a(void)
{
    int t;
    t = f_17cf21();
    if (t != 0) {
        return 0;
    }
    d_1af3c4 &= 0xfe;
    return 0;
}
//@ f_1699b7
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalter- und Segment-Endmarkierungsfunktion der Soundbibliothek.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_1699b7(void)
{
}
