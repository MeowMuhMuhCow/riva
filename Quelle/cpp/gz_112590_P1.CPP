/* === Beschreibung (Katalog) ===
 * Einheit gz_112590 (0x112590 - 0x112df0)
 *
 * Überblick
 * Diese Einheit implementiert den letzten Block der Zauberspruch-Routinen (aus spell5.cpp), darunter den
 * Wasseratmungs-/Schwimmzauber *Wasseratem* (0x52), den Transmutationszauber *Blei zu Gold* / *Arcanovi*
 * (0x4e/0x54) sowie Hilfsfunktionen zum Ausgeben von Zauber-Fehlermeldungen und zum Prüfen auf gültige
 * Kampfziele.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAITEX.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
#include "R_FIX.H"
// P3 10/11 gleich (suche.py 25.10.2026, Basis gz_112590_P1.CPP)
// gz_112590.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x112590-0x112DF0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_036300(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_036a10(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
void f_0a7840(RivaItemDefinition *item,char *dst,short n);                   // reg eax edx ebx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf820();                                         // reg - stapel 0
int f_0dc3c0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_125400(int p1, int p2, int p3, int p4);           // reg eax edx ebx stapel 0
int f_1254a0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1c0004;                    // 0x1C0004
extern volatile int d_1c1238;           // 0x1C1238 - haelt die Befehlsfolge in f_112dc0 wie im Original
extern signed char d_1c123c;                    // 0x1C123C
extern int d_1c27a8;                    // 0x1C27A8
                    // 0x1C2C40
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
// --- eigene Funktionen (11), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---




short f_03d3d0(int p1, int p2, int p3);
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0d4aa0(int p1, int p2);
short f_0d4c80(int p1);
int f_0d5040(int p1, int p2, int p3, int p4, int p5, int p6);
short f_1457e0(int p1);
extern char d_1c21b4;
extern signed char d_1c042a;
extern short d_1c0428;
extern char d_1c0416;
extern const char d_1c349c[];
extern const char d_1c3870[];
extern const char d_1c3498[];
#define CH ((int)&d_1c2c64)
#define DB ((int)&d_1c38b0)
#define DS1 ((int)&d_1c21b4)
//@ f_112590
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber *Wasseratem* (0x52), mit dem ein ausgewähltes Gruppenmitglied vor dem
 *   Ertrinken in Unterwasser-Abschnitten geschützt wird.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 === Ende Beschreibung === */
void f_112590(int p1)
{
    int msg;
    short sv;
    short a;
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(ob.slots[0] + 4) = *(int *)(p1 + 0x12);
    if (((char)(f_043290((struct hero *)(*(int *)(p1 + 0x12)))))) {
        f_0e93f0(DB, DS1, 0x170000c7);
        *(short *)p1 = -4;
        goto done;
        goto L1;
    }
    sv = f_0bf7b0(CH, 2, 0x17000077, 0, 99, 0);
    d_1c21b4 = 0;
    if (sv > 0) {
        if (sv * 5 <= (short)f_0429a0((struct hero *)(*(int *)(p1 + 0x12)))) {
            short t_68 = f_03d3d0(*(int *)(p1 + 0x12), 0x4b, *(signed char *)(p1 + 4));
            if ((short)(t_68 & 0xffff) > 0) { // haelt die Registerfolge nach dem Aufruf wie im Original
                *(short *)p1 = sv * 5;
                *(short *)p1 = *(short *)p1 + d_1c042a;
                a = f_0d4c80(*(int *)(p1 + 0x12));
                f_0d5040(*(int *)(p1 + 0x12), a, sv * 0x1c2, 0, 1, 0xb);
                f_0e93f0(DB, DS1, 0x17000078);
                goto done;
            }
            *(short *)p1 = -2;
            *(short *)(p1 + 2) = sv * 5 / 2;
            goto done;
        }
        msg = 0x17000083;
L1:
        f_0e93f0(DB, DS1, msg);
    }
    *(short *)p1 = -4;
done: ;
}
//@ f_1126e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Durchsucht das Inventar des Zaubernden *(int *)(p1 + 0x12) über f_0d4aa0 nach allen Vorkommen des
 *   Gegenstands 0x136 und verwandelt jedes gefundene Exemplar über f_042a90 in den Gegenstand 0x135 (mit Meldung
 *   0x170000b0); besitzt der Held keinen solchen Gegenstand, werden 2 AE berechnet und die Meldung 0x170000c8
 *   ausgegeben.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s (gefundener Inventarslot mit Gegenstand 0x136).
 === Ende Beschreibung === */
void f_1126e0(int p1)
{
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(ob.slots[0] + 4) = *(int *)(p1 + 0x12);
    short s = f_0d4aa0(*(int *)(p1 + 0x12), 0x136);
    if (s != -1) {
        do {
            f_042a90((struct hero *)(*(int *)(p1 + 0x12)), s, 0x135);
            f_0e93f0(DB, DS1, 0x170000b0);
            s = f_0d4aa0(*(int *)(p1 + 0x12), 0x136);
        } while (s != -1);
    } else {
        *(short *)p1 = 2;
        f_0e93f0(DB, DS1, 0x170000c8);
    }
}
//@ f_112790
/* === Beschreibung (Katalog) ===
 * - Zweck: Gibt für den Zaubernden *(int *)(p1 + 0x12) die Zaubermeldung 0x170000b1 über f_0e93f0 in den
 *   Textpuffer d_1c21b4 aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: ob (lokales RivaTextContext-Objekt).
 === Ende Beschreibung === */
void f_112790(int p1)
{
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
    *(int *)(ob.slots[0] + 4) = *(int *)(p1 + 0x12);
    f_0e93f0(DB, DS1, 0x170000b1);
}
//@ f_1127e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Verwandlungszauber (0x54), der bestimmte Gegenstände im Inventar des Zaubernden
 *   (wie die Gegenstände 0x116/0x117 in 0x11a) dauerhaft in ihre verwandelte Form überführt.
 * - Eingaben: Die Funktion erhält im Parameter p1 einen Zeiger auf das Zauberkontext-Objekt.
 * - Rückgabewert: Die Funktion gibt keinen Wert zurück.
 * - Bekannte Originalfehler: Die lokale Auswahlvariable choice (WORD PTR [esp+0x3c]) wird nicht initialisiert
 *   und nur dann beschrieben, wenn der Zaubernde beide möglichen Ausgangsgegenstände gleichzeitig im Inventar
 *   trägt (first != -1 && second != -1, 0x112844-0x1128a9). Besitzt der Zaubernde keinen der beiden Gegenstände
 *   (first == -1 und second == -1), springt der Code direkt zu 0x112a64 und prüft if (choice != -1). Da
 *   [esp+0x3c] uninitialisiert ist, hängt es vom zufälligen Stapelinhalt ab, ob die Fehlermeldung 0x1e01004b
 *   ausgegeben wird und ob die Funktion mit p->s0 = 0 statt mit dem Abbruchcode -4 (0xfffc) zurückkehrt.
 === Ende Beschreibung === */
void f_1127e0(int p1)
{
    short __cdecl f_0bf820(int, int, ...);
    RivaTextContext ob(d_1c349c, d_1c3870, d_1c3498);
#if FIX_R045   /* R045: Auswahlvariable choice vorinitialisieren und bei fehlendem Zielgegenstand mit -4 abbrechen */
    short choice = 0;
#else
    short choice;
#endif
    short second;
    short first;
    *(short *)p1 = 0;
    int hero = *(int *)(p1 + 0x12);
    *(int *)(ob.slots[0] + 4) = hero;
    first = f_0d4aa0(hero, 0x41);
    second = f_0d4aa0(*(int *)(p1 + 0x12), 0x19);
    if (first != -1 && second != -1) {
        f_0a7840((RivaItemDefinition *)(*(int *)((*(int*)&d_1c2c40) + 0x104)),(char *)( DS1), 1);
        f_0a7840((RivaItemDefinition *)(*(int *)((*(int*)&d_1c2c40) + 0x64)),(char *)( (int)&d_1c27a8), 1);
        choice = f_0bf820(CH, 0x1e010047, 2,
            f_133fe0((int)d_1c3498, DS1),
            f_133fe0((int)d_1c3498, (int)&d_1c27a8));
        if (choice == -1) { second = -1; first = -1; }
        else if (choice == 1) second = -1;
        else first = -1;
    }
    int index = first;
    if (index != -1) {
        if (f_03d3d0(*(int *)(p1 + 0x12), 0x4e, *(signed char *)(p1 + 4)) > 0) {
            f_042a90((struct hero *)(*(int *)(p1 + 0x12)), index, 0x16);
            f_0430c0((struct hero *)(*(int *)(p1 + 0x12)), index, 10);
            *(short *)p1 = f_1457e0(20);
            *(short *)p1 += (short)d_1c042a;
            f_0e93f0(DB, DS1, 0x1e010048);
            goto done;
        }
        {
fail:
            short roll = f_1457e0(20);
            short half = roll / 2;
            *(short *)p1 = -2;
            *(volatile short *)(p1 + 2) = half; // haelt die Schreib- und Registerfolge vor dem Destruktor wie im Original
            return;
        }
    } else {
        index = second;
        if (index != -1) {
            int third = f_0d4aa0(*(int *)(p1 + 0x12), 0x29);
            if (third != -1) {
                if (f_03d3d0(*(int *)(p1 + 0x12), 0x4e, *(signed char *)(p1 + 4)) > 0) {
                    f_042a90((struct hero *)(*(int *)(p1 + 0x12)), index, 0xf9);
                    f_0430c0((struct hero *)(*(int *)(p1 + 0x12)), index, 100);
                    f_036300(*(int *)(p1 + 0x12), third, 1);
                    f_036a10(*(int *)(p1 + 0x12), 0x2a, 1, third, 0);
                    *(short *)p1 = f_1457e0(20);
                    *(short *)p1 += (short)d_1c042a;
                    f_0e93f0(DB, DS1, 0x1e010049);
                    return;
                }
                goto fail;
            }
            f_0e93f0(DB, DS1, 0x1e01004a);
            return;
        }
        if ((int)choice != index) {
            f_0e93f0(DB, DS1, 0x1e01004b);
#if FIX_R045
            *(short *)p1 = -4;
#endif
            return;
        }
        d_1c21b4 = 0;
        *(short *)p1 = -4;
    }
done:;
}
//@ f_112ac0
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber 0x4f (nur im Kontext d_1c0428 == 5 zulässig, sonst Meldung 0x170000f3),
 *   fragt über den Zahlendialog 0x170000b2 den gewünschten Astraleinsatz s ab und speichert ihn bei gelungener
 *   Zauberprobe (f_03d3d0 mit 0x4f) sowohl in *(short *)p1 als auch in der globalen Variable d_1c0416.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: mode (d_1c0428), s (gewählter Astraleinsatz), d_1c0416 (gespeicherte Zauberstärke).
 === Ende Beschreibung === */
void f_112ac0(int p1)
{
    short mode = *(short *)&d_1c0428;
    if (mode == (short)5) {
        short s = f_0bf7b0(CH, 3, 0x170000b2, 0, (short)f_0429a0((struct hero *)(*(int *)(p1 + 0x12))), 0);
        if (s > 0) {
            if (f_03d3d0(*(int *)(p1 + 0x12), 0x4f, *(signed char *)(p1 + 4)) > 0) {
                *(short *)p1 = s;
                d_1c0416 = (char)s;
            } else {
                *(short *)p1 = -2;
                *(short *)(p1 + 2) = s / 2;
            }
        } else {
            *(short *)p1 = -4;
        }
    } else {
        f_0bf730(CH, 0x170000f3);
        *(short *)p1 = -4;
        d_1c21b4 = 0;
    }
}
//@ f_112b80
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert für den Zaubernden *(int *)(p1 + 0x12) einen stufenabhängigen Langzeiteffekt (Dauer (Stufe
 *   + 3) * 0x1518 Ticks, Typ 0x13) über f_0d5040 und gibt die Meldung 0x17000079 aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: a (Timer-Slot aus f_0d4c80).
 === Ende Beschreibung === */
void f_112b80(int p1)
{
    short a = f_0d4c80(*(int *)(p1 + 0x12));
    f_0d5040(*(int *)(p1 + 0x12), a, (f_0428d0((struct hero *)(*(int *)(p1 + 0x12))) + 3) * 0x1518, 0, 1, 0x13);
    f_0e93f0(DB, DS1, 0x17000079);
}
//@ f_112bf0
/* === Beschreibung (Katalog) ===
 * - Zweck: Bricht einen im aktuellen Kontext nicht einsetzbaren Zauber mit der Meldung 0x170000b3 und dem
 *   Statuscode *(short *)p1 = -4 ab.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112bf0(int p1)
{
    f_0e93f0(DB, DS1, 0x170000b3);
    *(short *)p1 = -4;
}
//@ f_112c20
/* === Beschreibung (Katalog) ===
 * - Zweck: Aktiviert für den Zaubernden *(int *)(p1 + 0x12) einen stufenabhängigen Langzeiteffekt (Dauer (Stufe
 *   + 3) * 0x1518 Ticks, Typ 0x12) über f_0d5040 und gibt die Meldung 0x1700007a aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: a (Timer-Slot aus f_0d4c80).
 === Ende Beschreibung === */
void f_112c20(int p1)
{
    short a = f_0d4c80(*(int *)(p1 + 0x12));
    f_0d5040(*(int *)(p1 + 0x12), a, (f_0428d0((struct hero *)(*(int *)(p1 + 0x12))) + 3) * 0x1518, 0, 1, 0x12);
    f_0e93f0(DB, DS1, 0x1700007a);
}
//@ f_112c90
/* === Beschreibung (Katalog) ===
 * - Zweck: Implementiert den Zauber 0x53 in den Kontexten d_1c0428 == 1 und d_1c0428 == 5: Nach gelungener Probe
 *   (f_03d3d0 mit 0x53) werden 1W20 (f_1457e0(20)) Astralpunkte berechnet (und bei Modus 1 zusätzlich Meldung
 *   0x1700000e ausgegeben); bei Misslingen kosten die Versuche 10 AE (*(short *)(p1 + 2) = 10, Status -2), in
 *   anderen Modi wird mit 0x170000b4 (-4) abgebrochen.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 === Ende Beschreibung === */
void f_112c90(int p1)
{
    switch (d_1c0428) {
    case 1:
        if (f_03d3d0(*(int *)(p1 + 0x12), 0x53, *(signed char *)(p1 + 4)) > 0) {
            f_0bf730(CH, 0x1700000e);
            *(short *)p1 = f_1457e0(0x14);
            return;
        }
        *(short *)(p1 + 2) = 10;
        *(short *)p1 = -2;
        return;
    case 5:
        if (f_03d3d0(*(int *)(p1 + 0x12), 0x53, *(signed char *)(p1 + 4)) > 0) {
            *(short *)p1 = f_1457e0(0x14);
            return;
        }
        *(short *)(p1 + 2) = 10;
        *(short *)p1 = -2;
        return;
    default:
        f_0e93f0(DB, DS1, 0x170000b4);
        *(short *)p1 = -4;
        return;
    }
}
//@ f_112d40
/* === Beschreibung (Katalog) ===
 * - Zweck: Löst einen Gruppen-/Umgebungszauber aus, sofern der Zähler d_1c123c noch 0 ist: Die Funktion startet
 *   über f_0dc3c0(d_1c0004, 0x1c2, 0x0d, 10, 1) den Gruppeneffekt, setzt d_1c123c = 0x1c2, trägt 5 + d_1c042a
 *   als Astralkosten ein und gibt 0x1700007b (bzw. bei bereits aktivem Effekt 0x170000ca) aus.
 * - Eingaben: p1 (Zeiger auf das Zauberkontext-Objekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c123c (Wirkungsdauer-Timer des Gruppeneffekts).
 === Ende Beschreibung === */
void f_112d40(int p1)
{
    if (*(int *)&d_1c123c == 0) {
        f_0dc3c0(d_1c0004, 0x1c2, 0xd, 10, 1);
        *(volatile int *)&d_1c123c = 0x1c2; // verhindert Register-Konstanten-Wiederverwendung von 0x1c2
        *(short *)p1 = 5;
        *(short *)p1 = *(short *)p1 + d_1c042a;
        f_0e93f0(DB, DS1, 0x1700007b);
        return;
    }
    f_0e93f0(DB, DS1, 0x170000ca);
    *(short *)p1 = 0;
}
//@ f_112dc0
/* === Beschreibung (Katalog) ===
 * - Zweck: Setzt den globalen Effekt-Timer d_1c1238 auf 0x1c2 und gibt die Zaubermeldung 0x170000b5 über
 *   f_0e93f0 aus.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c1238 (globaler Timerwert).
 === Ende Beschreibung === */
void f_112dc0()
{
    d_1c1238 = 0x1c2;
    f_0e93f0(DB, DS1, 0x170000b5);
}
