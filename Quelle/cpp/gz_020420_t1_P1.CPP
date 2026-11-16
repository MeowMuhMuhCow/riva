/* === Beschreibung (Katalog) ===
 * Einheit gz_020420_t1 (0x00020420 - 0x000216b0)
 *
 * Überblick
 *
 * Die Einheit gz_020420_t1 enthält den ersten Teil der Ereignis- und Ortslogik für den Boronanger (Friedhof von
 * Riva) einschließlich des Totengräber-Häuschens, des geheimen Eingangs in die Katakomben und der
 * Gräberuntersuchung. Sie verwaltet das Laden der Friedhofstexte, das Betreten und Verlassen der Gruft sowie die
 * Dialoge und Interaktionen auf den einzelnen Ereignisfeldern des Friedhofs.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAIMG.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAACE.H"
#include "RIVAMEM.H"
// P3 17/20 gleich (suche.py 28.10.2026, Basis gz_020420_t1_P1.CPP)
// P2 Koepfe Stufe 1 (Fable K): 7 gleich (vorher 7), Rest 1283 (vorher 1286)
// gz_020420.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x020420-0x022030
#include <string.h>
//#include "RIVA_CLOBBER.H"      // nur noetig, wenn unten ein (SICHERT)-Name vorkommt
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_022030(int p1);                                   // reg eax stapel 0
int f_0222d0(int p1);                                   // reg eax stapel 0
int f_0224b0();                                         // reg - stapel 0
int f_0227d0();                                         // reg - stapel 0
int f_038c40(int p1);                                   // reg eax stapel 0
int f_038c80(int p1);                                   // reg eax stapel 0
int f_0391b0(int p1, int p2);                           // reg eax edx stapel 0
int f_039320(int p1, int p2);                           // reg eax edx stapel 0
int f_039660(int p1, int p2);                           // reg eax edx stapel 0
int f_0397d0(int p1, int p2);                           // reg eax edx stapel 0
int f_039830(int p1, int p2);                           // reg eax edx stapel 0
int f_039b00(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
                                   // reg eax stapel 0
int f_043e20(int p1, int p2);                           // reg eax edx stapel 0
int f_044230(int p1, int p2);                           // reg eax edx stapel 0
int f_044c90(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_054ca0(int p1, int p2);                           // reg eax edx stapel 0
int f_05dec0(int p1);                                   // reg eax stapel 0
int f_05ded0(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9690(int p1, int p2);                           // reg eax stapel 0
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e340(int p1);                                   // reg eax stapel 0
int f_05ff60(int p1, int p2);
int f_0600f0(int p1, int p2);                           // reg edx stapel 0
int f_060100(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_060230(int p1);                                   // reg eax stapel 0
int f_069860(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
                                   // reg eax stapel 0
int f_0b8490(int p1, int p2);                           // reg eax edx stapel 0
int f_0b8520(int p1, int p2);                            // reg eax edx stapel 0
int f_0bbf00(int p1);                                   // reg eax stapel 0
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0d26e0();                                         // reg - stapel 0
int f_0d2710();                                         // reg - stapel 0
int f_0d3860();                                         // reg - stapel 0
int f_0d4a60(int p1);                                   // reg eax stapel 0
short f_0d54f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db9a0(int p1);                                   // reg eax stapel 0
int f_0dd3a0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0dd7f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
           // reg eax edx ebx ecx stapel 0
int f_11c320(int p1);                                   // reg eax stapel 0
int f_11c620(int p1, int p2);                           // reg eax edx stapel 0
int f_125400(int p1, int p2, int p3);           // reg eax edx ebx stapel 0
int f_1254a0(int p1, int);                                   // reg eax stapel 0
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
int f_147323(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax edx ebx ecx stapel 12
int f_1483f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_148450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
void f_145234(int p1, int p2);
void f_145254();
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a9820;                    // 0x1A9820
extern int d_1bab08;                    // 0x1BAB08
extern int d_1bf230;                    // 0x1BF230
extern int d_1c0004;                    // 0x1C0004
                    // 0x1C2C40
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c2edc;                    // 0x1C2EDC
extern int d_1c3068;                    // 0x1C3068
extern int d_1c3498;                    // 0x1C3498
extern int d_1c349c;                    // 0x1C349C
extern int d_1c3870;                    // 0x1C3870
extern int d_1c38b0;                    // 0x1C38B0
#include <stdlib.h>
struct O { int a; int b; };
extern RivaAceByteRegister d_1c2128;
extern RivaAceIntRegister d_1c2138;
extern signed char d_1bd70c;
extern int d_1bab1c;
extern int d_1bab50;
extern int d_1c21b4;
#define A(x) ((int)&(x))
extern RivaAceByteEntry d_1bc76c, d_1bc770, d_1bc774, d_1bc778, d_1bc77c, d_1bc780, d_1bc784, d_1bc788, d_1bc78c, d_1bc790, d_1bc794, d_1bc798, d_1bc79c, d_1bc7a0, d_1bc7a4, d_1bc7a8, d_1bc7ac, d_1bc7b0, d_1bc7b4, d_1bc7b8, d_1bc7bc, d_1bc7c0, d_1bc7c4, d_1bc7c8, d_1bc7cc, d_1bc7d0, d_1bc7d4, d_1bc7d8, d_1bc7dc, d_1bc7e0, d_1bc7e4, d_1bc7e8, d_1bc7ec, d_1bc7f0, d_1bc7f4, d_1bc7f8, d_1bc7fc, d_1bc800;
extern RivaAceIntEntry d_1bc804, d_1bc80c;
//@ f_020420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Verlassen des Friedhofs den geladenen Textpuffer der Friedhofs-Dialoge wieder frei
 *   und setzt bei Bedarf den Ortsstatus zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Freigegeben wird der globale Textpufferzeiger d_1bc79c, während der Friedhofsstatus in
 *   den Ortsflags um d_1bc74c gepflegt wird.
 === Ende Beschreibung === */
void f_020420(int p1, int p2, short p3, short p4, short p5)
{
    int dest = p2;
    short s = f_11c620(*(int *)(p1 + 0x12), p3);
    s = d_1c2c40[s]->f_0a7810();
    int t = 0;
    t = f_05dec0(A(d_1c3068));
    p5 = p5 + 0x11;
    itoa(s, (char *)&d_1c21b4, 10);
    short w = f_0e9690(A(d_1c38b0), A(d_1c21b4));
    ++p4;
    p4 += (0x1d - w) / 2;
    f_05ded0(A(d_1c3068), dest);
    f_05e320(A(d_1c38b0), 0xcb, -1);
    f_0e9660(A(d_1c38b0), A(d_1c21b4), p4, p5);
    f_05e340(A(d_1c38b0));
    f_05ded0(A(d_1c3068), t);
}
//@ f_0204f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim Betreten des Boronangers die zugehörige Textdatei mit den Grabinschriften und
 *   Totengräber-Dialogen in den Speicher und richtet die lokalen Ereigniszeiger ein.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Gesetzt wird der Textpufferzeiger d_1bc79c über den Ressourcenlader f_0a27a0.
 === Ende Beschreibung === */
int f_0204f0(int p1, int p2)
{
    short s = f_11c620(*(int *)(p1 + 0x12), (short)p2);
    int r = 2;
    if (d_1c2c40[s]->f_0a7910() != 0) r = 0;
    else if (d_1c2c40[s]->f_0a7990() != 0 || d_1c2c40[s]->f_0a79b0() != 0) r = 1;
    return r;
}
//@ f_020550
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft bei jedem Schritt der Gruppe auf dem Boronanger die aktuelle Ereignisfeldnummer und
 *   verzweigt in die passende Gräber-, Hütten- oder Gruft-Interaktion.
 * - Eingaben und Rückgabe: Die Funktion erwartet die Nummer des ausgelösten Ereignisfeldes als Parameter und
 *   gibt keinen Wert zurück.
 * - Wichtige Variablen: Verglichen wird die übergebene Feldnummer mit den registrierten Ereignispunkten des
 *   Boronangers, um die nachgelagerten Handler f_020640 bis f_021e10 aufzurufen.
 === Ende Beschreibung === */
short f_020550(int p1, short *p2, short *p3)
{
    short a = *p2 + 1;
    *p2 = a;
    short w = *(short *)(p1 + 0xc);
    int r = 0;
    if (a == *(short *)(p1 + 0xc)) {
        *p2 = 0;
        short b = *p3 + 1;
        *p3 = b;
        if (b == *(short *)(p1 + 10)) r = 1;
    }
    return r;
}
//@ f_020590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft auf dem Friedhof, ob es Tag oder Nacht ist und ob die Heldengruppe dem Totengräber
 *   begegnet oder unbemerkt auf dem Gelände agieren kann.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen (oder erhält den Ereigniskontext) und
 *   gibt einen Statuswert darüber zurück, ob die Aktion fortgesetzt werden darf.
 * - Wichtige Variablen: Abgefragt werden die globale Spielzeit und die Besuchsmerker des Boronangers ab
 *   d_1bc74c.
 === Ende Beschreibung === */
void f_020590(short *p1, int p2, short p3, short p4, short p5)
{
    struct Step { static void next(short *p, short &r, short &c) { c++; if (c == p[6]) { r++; c = 0; } } };
    short x = p4 * p1[2] + p1[0];
    short y = p5 * p1[3] + p1[1];
    while (p3 < p1[4]) {
        ((RivaRasterImage*)((*(int **)(p1 + 0xb))[p3]))->f_0fade0((void *)( p2), x, y);
        Step::next(p1,p5,p4);
        p3 = p1[6] * p5 + p4;
        x = p4 * p1[2];
        x += p1[0];
        y = p5 * p1[3] + p1[1];
    }
}

//@ f_020640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt der Gruppe die Inschrift eines bestimmten Grabes auf dem Boronanger an und erlaubt bei
 *   näherer Untersuchung das Entdecken von Hinweisen oder Gegenständen.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden der Friedhofs-Textpuffer d_1bc79c sowie das Textfenster f_056000 zur
 *   Anzeige der Grabbeschreibung.
 === Ende Beschreibung === */
void f_020640(short *p1, int p2, int p3)
{
    short x = p1[0] + ((short)p2 % p1[6]) * p1[2];
    short y = p1[1] + ((short)p2 / p1[6]) * p1[3];
    int fl;
    if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0;
    int c = (signed char)p3;
    f_1483f0(d_1a34e0, (short)(x + 1), y, (short)(p1[2] - 2), c);
    f_148450(d_1a34e0, x, (short)(y + 1), (short)(p1[3] - 2), c);
    f_1483f0(d_1a34e0, (short)(x + 1), (short)(y + p1[3] - 1), (short)(p1[2] - 2), c);
    f_148450(d_1a34e0, (short)(x + p1[2] - 1), (short)(y + 1), (short)(p1[3] - 2), c);
    if (fl == 1) f_0d26e0();
}
//@ f_020760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt die Untersuchung eines zweiten markanten Grabmals auf dem Boronanger, gibt den
 *   zugehörigen Beschreibungstext aus und schaltet bei erfüllten Bedingungen einen Hinweis frei.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Textpuffer d_1bc79c, der Gruppenanführer d_1c0004 und die
 *   Statusmerker des Friedhofs.
 === Ende Beschreibung === */
int f_020760(int p1, int p2)
{
    int first;
    int result = 0;
    int i;
    int done;
    int count;
    union N941 { int full; short word; } n;
    int target = p2;
    union Partial { int full; short word; } part;
    { int hold = ((int)d_1c2c40); (*(int*)&d_1c2c40) = hold; } // Codelose Referenz fuer die Stapelplatzsortierung in f_020760
    part.full = p1;
    part.word = *(short *)(p1 + 0x10);
    target += part.full;
    first = p1;
    int raw = f_11c320(*(int *)(p1 + 0x12));
    n.full = raw;
    count = i = 0;
    if ((short)raw > 0) {
        int limit;
        do {
            if (*(short *)(first + 0xe) != (short)3) {
                short s = f_11c620(*(int *)(first + 0x12), (short)i);
                int off = s;
                off *= 4;
                short kind = 2;
                if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a7910()) kind = 0;
                else if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a7990() ||
                         ((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a79b0()) kind = 1;
                if ((short)kind != *(short *)(first + 0xe)) goto first_next;
            }
            ++count;
first_next:
            limit = n.full;
            i++;
        } while ((short)i < (short)limit);
    }
    int selected = target;
    if ((short)selected >= (short)count) result = -1;
    else {
        if (*(short *)(p1 + 0xe) == (short)3) {
            result = selected;
        } else {
        int seen = -1;
        (int &)done = 0;
        do {
            short s = f_11c620(*(int *)(p1 + 0x12), (short)result);
            int off = s;
            off *= 4;
            short kind = 2;
            if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a7910()) kind = 0;
            else if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a7990() ||
                     ((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + off)))->f_0a79b0()) kind = 1;
            if ((short)kind == *(short *)(p1 + 0xe)) seen++;
            if ((short)seen == (short)target ||
                (short)result == (short)f_11c320(*(int *)(p1 + 0x12))) (int &)done = 1;
            else result++;
        } while (done == 0);
        }
    }
    return result;
}
//@ f_0208d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft an einem versperrten Durchgang des Boronangers, ob die Gruppe den passenden Schlüssel
 *   besitzt oder das Schloss öffnen kann, und gibt eine entsprechende Meldung aus.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft werden das Gruppeninventar sowie der Öffnungsstatus im Flagbereich ab d_1bc74c.
 === Ende Beschreibung === */
int f_0208d0(int p1)
{
    int obj;
    short n2 = (short)f_11c320(*(int *)(p1 + 0x12));
    int i = 0;
    int cnt = 0;
    obj = p1;
    if (0 < n2) {
        do {
            if (*(unsigned short *)(obj + 0xe) != (unsigned short)3) {
                short v = f_11c620(*(int *)(obj + 0x12), (short)i);
                int i3 = v * 4;
                short cls = 2;
                if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + i3)))->f_0a7910() != 0) {
                    cls = 0;
                } else if (((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + i3)))->f_0a7990() != 0 || ((RivaItemDefinition*)(*(int *)(((int)d_1c2c40) + i3)))->f_0a79b0() != 0) {
                    cls = 1;
                }
                if (cls != *(short *)(obj + 0xe)) goto f_0208d0_next;
            }
            cnt++;
f_0208d0_next:
            i++;
        } while ((short)i < n2);
    }
    return cnt;
}
//@ f_020970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Dient als kleiner Zustands- oder Ereigniswächter innerhalb der Friedhofslogik, der einen
 *   Merker setzt oder abfragt.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt einen kurzen Statuswert zurück.
 * - Wichtige Variablen: Gelesen oder gesetzt wird ein Statusbyte im Bereich d_1bc74c-d_1bc798.
 === Ende Beschreibung === */
void f_020970(int p1, int p2)
{
    int r = f_0b8490(p1, (short)p2);
    *(int *)(r + 0x58) = (int)&d_1bab1c;
}
//@ f_020980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst beim Betreten eines Übergangsfeldes auf dem Friedhof den Wechsel in den angrenzenden
 *   Bereich oder das Öffnen eines Zugangs aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Aktualisiert werden die Orts- und Positionsvariablen der Heldengruppe.
 === Ende Beschreibung === */
int f_020980(int p1, unsigned p2)
{
    if (p2 & 4) {
        f_145234(p1, (int)&d_1bab08);
        f_145254();
        return p1;
    }
    *(int *)(p1 + 0x58) = (int)&d_1bab1c;
    int u = f_0b8520(p1, 1);
    if (p2 & 2) delete (char *)u;
    return u;
}
//@ f_0209c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert oder setzt einen Statusmerker für den Fortschritt der Untersuchungen auf dem
 *   Boronanger.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den aktuellen Statuswert zurück.
 * - Wichtige Variablen: Zugegriffen wird auf die Friedhofs-Merker im globalen Datensegment um d_1bc750.
 === Ende Beschreibung === */
void f_0209c0()
{
}
//@ f_0209d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Beschreibt ein verdächtiges Grabmal auf dem Boronanger und ermöglicht den Helden, den geheimen
 *   Abstieg in die Katakomben unter dem Friedhof freizulegen oder zu betreten.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden die Entdeckungsflags des Geheimgangs sowie der Textpuffer d_1bc79c.
 === Ende Beschreibung === */
int f_0209d0(int p1, int p2)
{
    p2 = (short)p2;
    int r = 0;
    if (p2 == 0) {
        if ((d_1bd70c == 0) ? 1 : 0) {
            d_1bd70c = 1;
            *(int *)(p1 + 0x50) = 1;
            return r;
        }
        if ((d_1bd70c == 2) ? 1 : 0) {
            *(int *)(p1 + 0x50) = 2;
            *(volatile signed char *)&d_1bd70c = 1; // Verhindert Tail-Merging der Zuweisung d_1bd70c = 1 mit dem ersten Zweig
            return r;
        }
    } else {
        if (p2 == 0x80) {
            *(int *)(p1 + 0x50) = 4;
        } else if (p2 == 0xb4 && ((d_1bd70c == 1) ? 1 : 0)) {
            *(int *)(p1 + 0x50) = 5;
            d_1bd70c = 2;
        }
    }
    return r;
}
#pragma inline_depth(0)
#pragma inline_depth(0)
//@ f_020a70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die gesamte Szene an und in der Hütte des Totengräbers auf dem Boronanger. Je nach
 *   Tageszeit, bisherigem Spielfortschritt und Gesprächsverlauf können die Helden mit dem Totengräber sprechen,
 *   die Hütte durchsuchen, verdächtige Gegenstände finden oder den Zugang zum Keller entdecken.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verwendet werden der Friedhofs-Textpuffer d_1bc79c, zahlreiche Fortschrittsflags im
 *   Bereich d_1bc74c-d_1bc798, Talentproben über f_03d220 und Beutefunde über f_051360.
 === Ende Beschreibung === */
inline void first492_1(RivaAceByteEntry *p,short *n,int * &t,short k,char v)
{p->v=v;p->id=k;t[*n]=(int)p;}
inline void put492_1(RivaAceByteEntry *p,short *n,int * &t,short k,char v)
{p->v=v;p->id=k;t[++*n]=(int)p;}
inline void first492_4(RivaAceIntEntry *p,short *n,int * &t,short k,int v,short *previous)
{p->v=v;p->id=k;++*previous;t[*n]=(int)p;}
inline void put492_4(RivaAceIntEntry *p,short *n,int * &t,short k,int v)
{p->v=v;p->id=k;t[++*n]=(int)p;}
struct RR700V3_020a708;
struct OR700V3_020a708 { signed char flag; short number; char pad; OR700V3_020a708 *init(RR700V3_020a708 &r,short id,signed char f); };
struct RR700V3_020a708 { short count; OR700V3_020a708 **list; void append(OR700V3_020a708 *o) {list[count]=o;count++;} };
inline OR700V3_020a708 *OR700V3_020a708::init(RR700V3_020a708 &r,short id,signed char f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_020a708 regR700V3_020a708;
#pragma aux regR700V3_020a708 "d_1c212a"
struct RR700V3_020a7032;
struct OR700V3_020a7032 { int flag; short number; short pad; OR700V3_020a7032 *init(RR700V3_020a7032 &r,short id,int f); };
struct RR700V3_020a7032 { short count; OR700V3_020a7032 **list; void append(OR700V3_020a7032 *o) {list[count]=o;count++;} };
inline OR700V3_020a7032 *OR700V3_020a7032::init(RR700V3_020a7032 &r,short id,int f) {flag=f;number=id;r.append(this);return this;}
extern RR700V3_020a7032 regR700V3_020a7032;
#pragma aux regR700V3_020a7032 "d_1c213a"
extern OR700V3_020a708 obR700V3_020a70_1bc76c;
#pragma aux obR700V3_020a70_1bc76c "d_1bc76c"
extern OR700V3_020a708 obR700V3_020a70_1bc770;
#pragma aux obR700V3_020a70_1bc770 "d_1bc770"
extern OR700V3_020a708 obR700V3_020a70_1bc774;
#pragma aux obR700V3_020a70_1bc774 "d_1bc774"
extern OR700V3_020a708 obR700V3_020a70_1bc778;
#pragma aux obR700V3_020a70_1bc778 "d_1bc778"
extern OR700V3_020a708 obR700V3_020a70_1bc77c;
#pragma aux obR700V3_020a70_1bc77c "d_1bc77c"
extern OR700V3_020a708 obR700V3_020a70_1bc780;
#pragma aux obR700V3_020a70_1bc780 "d_1bc780"
extern OR700V3_020a708 obR700V3_020a70_1bc784;
#pragma aux obR700V3_020a70_1bc784 "d_1bc784"
extern OR700V3_020a708 obR700V3_020a70_1bc788;
#pragma aux obR700V3_020a70_1bc788 "d_1bc788"
extern OR700V3_020a708 obR700V3_020a70_1bc78c;
#pragma aux obR700V3_020a70_1bc78c "d_1bc78c"
extern OR700V3_020a708 obR700V3_020a70_1bc790;
#pragma aux obR700V3_020a70_1bc790 "d_1bc790"
extern OR700V3_020a708 obR700V3_020a70_1bc794;
#pragma aux obR700V3_020a70_1bc794 "d_1bc794"
extern OR700V3_020a708 obR700V3_020a70_1bc798;
#pragma aux obR700V3_020a70_1bc798 "d_1bc798"
extern OR700V3_020a708 obR700V3_020a70_1bc79c;
#pragma aux obR700V3_020a70_1bc79c "d_1bc79c"
extern OR700V3_020a708 obR700V3_020a70_1bc7a0;
#pragma aux obR700V3_020a70_1bc7a0 "d_1bc7a0"
extern OR700V3_020a708 obR700V3_020a70_1bc7a4;
#pragma aux obR700V3_020a70_1bc7a4 "d_1bc7a4"
extern OR700V3_020a708 obR700V3_020a70_1bc7a8;
#pragma aux obR700V3_020a70_1bc7a8 "d_1bc7a8"
extern OR700V3_020a708 obR700V3_020a70_1bc7ac;
#pragma aux obR700V3_020a70_1bc7ac "d_1bc7ac"
extern OR700V3_020a708 obR700V3_020a70_1bc7b0;
#pragma aux obR700V3_020a70_1bc7b0 "d_1bc7b0"
extern OR700V3_020a708 obR700V3_020a70_1bc7b4;
#pragma aux obR700V3_020a70_1bc7b4 "d_1bc7b4"
extern OR700V3_020a708 obR700V3_020a70_1bc7b8;
#pragma aux obR700V3_020a70_1bc7b8 "d_1bc7b8"
extern OR700V3_020a708 obR700V3_020a70_1bc7bc;
#pragma aux obR700V3_020a70_1bc7bc "d_1bc7bc"
extern OR700V3_020a708 obR700V3_020a70_1bc7c0;
#pragma aux obR700V3_020a70_1bc7c0 "d_1bc7c0"
extern OR700V3_020a708 obR700V3_020a70_1bc7c4;
#pragma aux obR700V3_020a70_1bc7c4 "d_1bc7c4"
extern OR700V3_020a708 obR700V3_020a70_1bc7c8;
#pragma aux obR700V3_020a70_1bc7c8 "d_1bc7c8"
extern OR700V3_020a708 obR700V3_020a70_1bc7cc;
#pragma aux obR700V3_020a70_1bc7cc "d_1bc7cc"
extern OR700V3_020a708 obR700V3_020a70_1bc7d0;
#pragma aux obR700V3_020a70_1bc7d0 "d_1bc7d0"
extern OR700V3_020a708 obR700V3_020a70_1bc7d4;
#pragma aux obR700V3_020a70_1bc7d4 "d_1bc7d4"
extern OR700V3_020a708 obR700V3_020a70_1bc7d8;
#pragma aux obR700V3_020a70_1bc7d8 "d_1bc7d8"
extern OR700V3_020a708 obR700V3_020a70_1bc7dc;
#pragma aux obR700V3_020a70_1bc7dc "d_1bc7dc"
extern OR700V3_020a708 obR700V3_020a70_1bc7e0;
#pragma aux obR700V3_020a70_1bc7e0 "d_1bc7e0"
extern OR700V3_020a708 obR700V3_020a70_1bc7e4;
#pragma aux obR700V3_020a70_1bc7e4 "d_1bc7e4"
extern OR700V3_020a708 obR700V3_020a70_1bc7e8;
#pragma aux obR700V3_020a70_1bc7e8 "d_1bc7e8"
extern OR700V3_020a708 obR700V3_020a70_1bc7ec;
#pragma aux obR700V3_020a70_1bc7ec "d_1bc7ec"
extern OR700V3_020a708 obR700V3_020a70_1bc7f0;
#pragma aux obR700V3_020a70_1bc7f0 "d_1bc7f0"
extern OR700V3_020a708 obR700V3_020a70_1bc7f4;
#pragma aux obR700V3_020a70_1bc7f4 "d_1bc7f4"
extern OR700V3_020a708 obR700V3_020a70_1bc7f8;
#pragma aux obR700V3_020a70_1bc7f8 "d_1bc7f8"
extern OR700V3_020a708 obR700V3_020a70_1bc7fc;
#pragma aux obR700V3_020a70_1bc7fc "d_1bc7fc"
extern OR700V3_020a708 obR700V3_020a70_1bc800;
#pragma aux obR700V3_020a70_1bc800 "d_1bc800"
extern OR700V3_020a7032 obR700V3_020a70_1bc804;
#pragma aux obR700V3_020a70_1bc804 "d_1bc804"
extern OR700V3_020a7032 obR700V3_020a70_1bc80c;
#pragma aux obR700V3_020a70_1bc80c "d_1bc80c"
void f_020a70(void) {
obR700V3_020a70_1bc76c.init(regR700V3_020a708,0x20,0);
obR700V3_020a70_1bc770.init(regR700V3_020a708,0x21,0);
obR700V3_020a70_1bc774.init(regR700V3_020a708,0x22,0);
obR700V3_020a70_1bc778.init(regR700V3_020a708,0x23,0);
obR700V3_020a70_1bc77c.init(regR700V3_020a708,0x24,0);
obR700V3_020a70_1bc780.init(regR700V3_020a708,0x25,0);
obR700V3_020a70_1bc784.init(regR700V3_020a708,0x27,0);
obR700V3_020a70_1bc788.init(regR700V3_020a708,0x28,0);
obR700V3_020a70_1bc78c.init(regR700V3_020a708,0x2b,0);
obR700V3_020a70_1bc790.init(regR700V3_020a708,0x2c,0);
obR700V3_020a70_1bc794.init(regR700V3_020a708,0x2d,0);
obR700V3_020a70_1bc798.init(regR700V3_020a708,0x2e,0);
obR700V3_020a70_1bc79c.init(regR700V3_020a708,0x2f,0);
obR700V3_020a70_1bc7a0.init(regR700V3_020a708,0x30,0);
obR700V3_020a70_1bc7a4.init(regR700V3_020a708,0x31,0);
obR700V3_020a70_1bc7a8.init(regR700V3_020a708,0x32,0);
obR700V3_020a70_1bc7ac.init(regR700V3_020a708,0x33,0);
obR700V3_020a70_1bc7b0.init(regR700V3_020a708,0x34,0);
obR700V3_020a70_1bc7b4.init(regR700V3_020a708,0x35,0);
obR700V3_020a70_1bc7b8.init(regR700V3_020a708,0x36,0);
obR700V3_020a70_1bc7bc.init(regR700V3_020a708,0x38,0);
obR700V3_020a70_1bc7c0.init(regR700V3_020a708,0x39,0);
obR700V3_020a70_1bc7c4.init(regR700V3_020a708,0x3a,0);
obR700V3_020a70_1bc7c8.init(regR700V3_020a708,0x3b,0);
obR700V3_020a70_1bc7cc.init(regR700V3_020a708,0x3c,0);
obR700V3_020a70_1bc7d0.init(regR700V3_020a708,0x3d,0);
obR700V3_020a70_1bc7d4.init(regR700V3_020a708,0x3e,0);
obR700V3_020a70_1bc7d8.init(regR700V3_020a708,0x3f,0);
obR700V3_020a70_1bc7dc.init(regR700V3_020a708,0x40,0);
obR700V3_020a70_1bc7e0.init(regR700V3_020a708,0x41,0);
obR700V3_020a70_1bc7e4.init(regR700V3_020a708,0x42,0);
obR700V3_020a70_1bc7e8.init(regR700V3_020a708,0x43,0);
obR700V3_020a70_1bc7ec.init(regR700V3_020a708,0x44,0);
obR700V3_020a70_1bc7f0.init(regR700V3_020a708,0x45,0);
obR700V3_020a70_1bc7f4.init(regR700V3_020a708,0x1f5,0);
obR700V3_020a70_1bc7f8.init(regR700V3_020a708,0x1f6,0);
obR700V3_020a70_1bc7fc.init(regR700V3_020a708,0x1f7,0);
obR700V3_020a70_1bc800.init(regR700V3_020a708,0x1fa,0);
obR700V3_020a70_1bc804.init(regR700V3_020a7032,0x1,653);
obR700V3_020a70_1bc80c.init(regR700V3_020a7032,0x2,4380);
}

#pragma inline_depth(3)
#pragma inline_depth(3)
//@ f_021180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Stand eines Teilflags der Friedhofs-Untersuchung zurück.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Flagwert als Ganzzahl zurück.
 * - Wichtige Variablen: Gelesen wird ein einzelnes Statusbyte aus dem Friedhofs-Datenblock.
 === Ende Beschreibung === */
void f_021180(int p1)
{
    f_043e20(p1, 1);
}
//@ f_021190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest einen weiteren Fortschrittsmerker des Boronangers aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt den gespeicherten Merker zurück.
 * - Wichtige Variablen: Gelesen wird ein Statusbyte im Bereich d_1bc750-d_1bc798.
 === Ende Beschreibung === */
void f_021190(int p1)
{
    f_043e20(p1, 0);
}
//@ f_0211a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert einen Fortschrittsmerker des Friedhofs nach einer abgeschlossenen Aktion oder
 *   Dialogentscheidung.
 * - Eingaben und Rückgabe: Die Funktion erhält den neuen Statuswert oder setzt ein festes Flag und gibt keinen
 *   Wert zurück.
 * - Wichtige Variablen: Beschrieben wird ein Statusbyte der Boronanger-Ereignissteuerung.
 === Ende Beschreibung === */
void f_0211a0(int p1)
{
    int r = f_05ff60(p1, 0xd);
    *(int *)(r + 8) = (int)&d_1bab50;
}
//@ f_0211c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lässt die Heldengruppe ein auffälliges, frisch aufgeschüttetes Grab auf dem Boronanger
 *   untersuchen, prüft ob Grabwerkzeug (Schaufel) vorhanden ist, und fördert beim Aufgraben wichtige Hinweise
 *   zutage.
 * - Eingaben und Rückgabe: Die Funktion erwartet keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Geprüft werden der Besitz einer Schaufel im Gruppeninventar, der Grabstatus im Bereich
 *   d_1bc74c-d_1bc798 und die Textausgabe über d_1bc79c.
 === Ende Beschreibung === */
void f_0216b0();
void f_021870();
void f_021a70();
void f_021c30();
void f_021e10();
void f_021490(int p1);
int f_0211c0(int p1, unsigned short p2)
{
    int result = 1;
    switch (p2) {
    case 1:
        if (f_0bf6f0(A(d_1c2c64), 0x24000001) == result) {
            unsigned short a7 = 1;
            unsigned short a4;
            int a5;
            short a6;
            unsigned short a3;
            f_147323(A(d_1c2edc), 0x240006, (a3 = 0x7fff), (a4 = 0x8000),
                     (a5 = d_1a9820), (a6 = 0), a7);
            f_0dd7f0(d_1c0004, 0, 0x170c);
        }
        break;
    case 2: ((void (*)())f_021490)(); break;
    case 3: f_0216b0(); break;
    case 4: f_021870(); break;
    case 5: f_021a70(); break;
    case 6: f_021c30(); break;
    case 7: f_021e10(); break;
    case 8: ((void (*)())f_022030)(); break;
    case 9: ((void (*)())f_0222d0)(); break;
    case 0x1f41: f_0224b0(); break;
    case 0x6f:
        if ((unsigned char)((signed char)d_1bc800.v == 0)) {
            d_1bc800.v = 1;
            f_0bf730(A(d_1c2c64), 0x24000038);
        }
        break;
    case 0x70:
        if ((unsigned char)((signed char)d_1bc800.v == 0)) {
            d_1bc800.v = 1;
            f_0bf730(A(d_1c2c64), 0x24000038);
        }
        break;
    case 0x1f43: break;
    default: result = 0; break;
    }
    return result;
}
//@ f_021390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim Betrachten eines weiteren Grabsteins auf dem Boronanger den zugehörigen
 *   Inschriftentext in einem Dialogfenster aus.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Genutzt werden d_1bc79c als Textquelle und f_056000 zur Darstellung der Textbox.
 === Ende Beschreibung === */
#define EQ21(x,v) (((x)==(v))?1:0)
void f_021390(int p1)
{
    if (EQ21((signed char)d_1bc790.v, 0) && EQ21((signed char)d_1bc78c.v, 1))
        f_069860(p1 + 2, 0x1d, 1);
    else
        f_069860(p1 + 2, 0x1d, 0);
    if (EQ21((signed char)d_1bc76c.v, 1) && EQ21((signed char)d_1bc780.v, 0))
        f_069860(p1 + 2, 0x1e, 1);
    else
        f_069860(p1 + 2, 0x1e, 0);
    f_060230(p1);
}
#undef EQ21
//@ f_021430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest ein einzelnes Statusbyte des Boronangers für nachgelagerte Prüfungen aus.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt das gelesene Flag zurück.
 * - Wichtige Variablen: Gelesen wird ein Byte aus dem Zustandsblock des Boronangers.
 === Ende Beschreibung === */
void f_021430(int p1, int p2, int p3)
{
    f_060100(p1, (short)p2, (short)p3);
}
//@ f_021440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schaltet bei einer Aktion auf dem Friedhof einen Durchgang oder ein Ereignisflag um und
 *   aktualisiert den Kartenzustand.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück.
 * - Wichtige Variablen: Verändert wird der Statusmerker des jeweiligen Friedhofs-Ereignisses.
 === Ende Beschreibung === */
void f_021440()
{
    int r;
    if (f_0bf6f0(A(d_1c2c64), 0x24000001) == 1) {
        f_147323(A(d_1c2edc), 0x240006, 0x7fff, 0x8000, (r=d_1a9820), 0, 1);
        f_0dd7f0(d_1c0004, 0, 0x170c);
    }
}
//@ f_021490
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert die Untersuchung eines verschlossenen Mausoleums auf dem Boronanger, prüft Schlösser-
 *   oder Kraftakt-Optionen und gewährt bei Erfolg den Abstieg in das Gewölbe unter dem Friedhof.
 * - Eingaben und Rückgabe: Die Funktion erhält keine Parameter und gibt keinen Wert zurück.
 * - Wichtige Variablen: Ausgewertet werden der Gruppenanführer d_1c0004, der Öffnungsmerker im Bereich
 *   d_1bc74c-d_1bc798 und die Texte aus d_1bc79c.
 === Ende Beschreibung === */
#define EQI(x,v) (((x)==(v))?1:0)
struct MsgC { int h; char *q[14]; MsgC(void*,void*,void*); ~MsgC(); };
void f_021490(int p1)
{
    if (EQI((signed char)d_1bc76c.v, 1) && EQI((signed char)d_1bc77c.v, 0)) {
        if (f_0bf6f0(A(d_1c2c64), 0x24000002) == 1) {
            if (EQI((signed char)d_1bc770.v, 0) && EQI((signed char)d_1bc790.v, 0)) {
                f_125ed0(A(d_1c2c44), 5);
                if (f_0bf6f0(A(d_1c2c64), 0x24000003) == 1) {
                    MsgC m(&d_1c349c, &d_1c3870, &d_1c3498);
                    *(int *)(m.q[0] + 4) = f_038c40(d_1c0004);
                    if ((short)f_0d54f0(d_1c0004, 0x49) != -1)
                        f_0bf730(A(d_1c2c64), 0x24000004);
                    else
                        f_0bf730(A(d_1c2c64), 0x24000005);
                    d_1bc770.v = 1;
                    d_1bc7f0.v = 1;
                    if (EQI((signed char)d_1bc788.v, 0)) {
                        f_0600f0(p1, 0x150008);
                        d_1bc788.v = 1;
                    } else {
                        f_0600f0(p1, 0x15000b);
                    }
                } else {
                    f_0bf730(A(d_1c2c64), 0x24000006);
                    d_1bc770.v = 1;
                    if (EQI((signed char)d_1bc788.v, 0)) {
                        f_0600f0(p1, 0x150008);
                        d_1bc788.v = 1;
                    } else {
                        f_0600f0(p1, 0x15000b);
                    }
                }
            } else {
                f_0bf730(A(d_1c2c64), 0x24000007);
            }
        }
    } else if (EQI((signed char)d_1bc7f4.v, 0)) {
        MsgC m2(&d_1c349c, &d_1c3870, &d_1c3498);
        *(int *)(m2.q[0] + 4) = f_038c40(d_1c0004);
        f_0bf730(A(d_1c2c64), 0x24000008);
        d_1bc7f4.v = 1;
    }
}
