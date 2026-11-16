/* === Beschreibung (Katalog) ===
 * Einheit misc_b
 *
 * Diese Einheit bildet den zweiten Teil von misc.cpp und enthält DOS-Laufwerks- und Verzeichnisabfragen, einen
 * CD-ROM-Geschwindigkeitstest, BIOS-Druckerroutinen (LPT), eine Namenslisten-Formatierung für Heldengruppen,
 * Inventar-Zähl- und Entfernungsfunktionen sowie Timer-gestützte Warteschleifen für die Soundausgabe.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAITEM.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 10/17 gleich (suche.py 26.10.2026, Basis misc_b_P1.CPP)
// misc_b.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0CE0D0-0x0CE7C0
#include <string.h>
#include <bios.h>
struct DF { unsigned short a, b, c, d; };
void f_15f1b4(unsigned *p);
void f_15f1c8(int drive, unsigned *p);
char *f_15f1e1(char *buf, int n);
void f_15f1dc(unsigned char drive, struct DF *p);
int f_036300(int p1, int p2, int p3);




int f_0d2e70();
int f_0d2f90(int p1, int p2);
int f_0de7d0(int p1, int p2);
int f_0e9300(void *p1, char *p2, int p3);
int f_146dfa(int p1, int p2);
int f_147688(int p1, int p2);
int f_14778f(int p1, int p2);
int f_147808(int p1);
int f_147aad(int p1);
int f_147b97(int p1, int p2, int p3);
int f_147c02(int p1, int p2);
int f_149e2e(int p1, int p2);
#pragma aux f_149e2e parm caller [] modify [eax ecx edx];
extern int d_1a57c4;
extern volatile unsigned d_1bf374;
extern char d_1bfaf0;

extern int d_1c2edc;
extern int d_1c38b0;
extern int d_1c2a74;
extern const char d_1a57a8[];
extern int d_1a34e0;
extern const char d_1b8228[];
extern const char d_1b8236[];
extern int d_1c2e78;
int f_09a0d0(int p1, const char *p2, int p3, int p4);
int f_09a400();
int f_0e9660(int p1);
int f_0d3df6(int p1, int p2, const char *p3);
int f_0d451f(int p1);
#define PORT (signed char)(d_1bfaf0 - 1)
//@ f_0ce0d0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wechselt bei einer Laufwerksnummer p1 != 0 über die DOS-Laufwerksfunktion f_15f1c8
 *   (_dos_setdrive) das aktuelle Laufwerk und gibt die Anzahl der verfügbaren Laufwerke zurück. Originalfehler:
 *   Wenn p1 == 0 übergeben wird, wird f_15f1c8(p1, &t) übersprungen und die lokale Variable t uninitialisiert
 *   vom Stack zurückgegeben.
 * - Eingaben: Als Parameter wird die 1-basierte Laufwerksnummer p1 (1 = A:, 2 = B:, 3 = C: usw.) übergeben.
 * - Rückgabewert: Zurückgegeben wird die Gesamtzahl der logischen Laufwerke t (bzw. bei p1 == 0 ein
 *   uninitialisierter Stackwert).
 === Ende Beschreibung === */
int f_0ce0d0(short p1)
{
    unsigned t;
    int check = (unsigned short)p1;
    if ((short)check != 0) f_15f1c8(p1, &t);
    return t;
}
//@ f_0ce0f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion fragt über f_15f1dc (_dos_getdiskfree) die Cluster- und Sektorinformationen des
 *   Laufwerks p1 ab und berechnet daraus den gesamten freien Speicherplatz in Bytes (freie_Cluster *
 *   Sektoren_pro_Cluster * Bytes_pro_Sektor).
 * - Eingaben: Als Parameter wird die Laufwerksnummer p1 (0 für aktuelles Laufwerk, 1 für A: usw.) übergeben.
 * - Rückgabewert: Zurückgegeben wird der freie Speicherplatz des Laufwerks in Bytes als vorzeichenlose
 *   32-Bit-Zahl.
 === Ende Beschreibung === */
unsigned f_0ce0f0(unsigned char p1)
{
    struct DF s;
    f_15f1dc(p1, &s);
    return (unsigned)s.b * s.c * s.d;
}
//@ f_0ce120
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion ermittelt das aktuelle Arbeitsverzeichnis des Laufwerks p1 (durch temporäres
 *   Umschalten auf p1 mittels _dos_getdrive/_dos_setdrive und Abfrage von getcwd), entfernt das Laufwerkspräfix
 *   ("C:\", 3 Zeichen) und kopiert den Pfad in den Zielpuffer p2.
 * - Eingaben: Übergeben werden die Laufwerksnummer p1 (0 für das aktuelle Laufwerk) sowie der Zeiger p2 auf den
 *   Ausgabepuffer für den Verzeichnispfad.
 * - Rückgabewert: Zurückgegeben wird 0 bei Erfolg oder -1, wenn das Laufwerk nicht ausgewählt oder das
 *   Verzeichnis nicht gelesen werden konnte.
 === Ende Beschreibung === */
short f_0ce120(short p1, char *p2)
{
    void setdrv(unsigned drive, unsigned *p);
    #pragma aux setdrv "W?f_15f1c8$n(ipui)v"
    unsigned cur, t1, c2, t2, saved;
    char *s;
    short r = 0;
    s = 0;
    char *buf = new (mark(d_1a57a8, 0x21a)) char[0x90];
    if (p1 != 0) {
        f_15f1b4(&cur);
        saved = cur;
        if (p1 != 0) setdrv(p1, &t1);
        f_15f1b4(&c2);
        if (p1 != (short)c2) {
            r = -1;
        } else {
            s = f_15f1e1(buf, 0x90);
            if ((short)saved != 0) setdrv((short)saved, &t2);
        }
    } else {
        s = f_15f1e1(buf, 0x90);
    }
    if (r == 0 && s) {
        s += 3;
        strcpy(p2, s);
    } else {
        r = -1;
    }
    delete buf;
    return r;
}
//@ f_0ce200
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion führt den CD-ROM-Geschwindigkeitstest ("CD Speed Test") durch, indem sie den
 *   Bildschirm löscht, die Meldung ausgibt und einen Benchmark-Durchlauf auf der Archivdatei "DATA\\SEQS.ALF"
 *   (f_0d3df6, f_0d451f) startet.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce200()
{
void clear670(void*);
#pragma aux clear670 "f_09a0d0"
void draw670(int,int,int,int);
#pragma aux draw670 "f_0e9660"
    #pragma aux f_0e9660 modify [eax ebx ecx edx];
    #pragma aux f_0d3df6 parm [edx] [ebx] [eax];
clear670((void*)d_1a34e0);f_09a400();draw670((int)&d_1c38b0,(int)d_1b8228,0xf,0xc);
    f_0d3df6(5, (int)d_1b8236, (const char *)&d_1c2e78);
    f_0d451f((int)&d_1c2e78);
}
//@ f_0ce250
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion prüft über den BIOS-Interrupt _bios_printer(_PRINTER_STATUS, PORT, 0), ob der am
 *   konfigurierten Parallelport (d_1bfaf0 - 1) angeschlossene Drucker empfangsbereit ist (Status 0x90:
 *   ausgewählt und bereit, kein Papierfehler).
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird 1, wenn der Druckerstatus exakt 0x90 lautet, andernfalls 0.
 === Ende Beschreibung === */
int f_0ce250()
{
    return _bios_printer(_PRINTER_STATUS, PORT, 0) == 0x90;
}
//@ f_0ce280
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion sendet ein einzelnes Zeichen p1 über _bios_printer(_PRINTER_WRITE, PORT, p1) an den
 *   konfigurierten Parallelport und prüft anhand des Statusbits 0x10 (Selected), ob die Übertragung erfolgreich
 *   war.
 * - Eingaben: Als Parameter wird das auszugebende Zeichen p1 übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Statusbit 0x10 gesetzt ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0ce280(int p1)
{
    return (_bios_printer(_PRINTER_WRITE, PORT, p1) & 0x10) != 0;
}
//@ f_0ce2b0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion gibt eine nullterminierte Zeichenkette p Zeichen für Zeichen über _bios_printer an den
 *   Parallelport (d_1bfaf0 - 1) aus, solange der Drucker das Statusbit 0x10 (Selected) meldet.
 * - Eingaben: Als Parameter wird der Zeiger p auf die zu druckende Zeichenkette übergeben.
 * - Rückgabewert: Zurückgegeben wird 1, wenn das Statusbit 0x10 nach Abschluss der Schleife weiterhin gesetzt
 *   ist, andernfalls 0.
 === Ende Beschreibung === */
int f_0ce2b0(signed char *p)
{
    signed char port = d_1bfaf0;
    unsigned char data = 0;
    --port;
    unsigned char cmd = 2;
    unsigned short st;
    st = _bios_printer(cmd, port, data);
    int c;
    while ((c = *p) && (st & 0x10)) {
        data = *(signed char *)p;
        cmd = 0;
        ++p;
        st = _bios_printer(cmd, port, data);
    }
    return (st & 0x10) != 0;
}
//@ f_0ce2f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion formatiert eine Liste von p1 Helden aus dem Zeigerarray p2 zu einer grammatisch
 *   korrekten Aufzählung in der Ausgabekette p3, indem sie die Heldennamen (f_0422b0) durch Kommas (0x20000193)
 *   und vor dem letzten Namen durch ein "und" (0x20000195, eingerahmt von Leerzeichen 0x200001b5) verbindet.
 * - Eingaben: Übergeben werden die Anzahl der Helden p1, das Array p2 mit Zeigern auf die Heldenstrukturen sowie
 *   der Ausgabepuffer p3.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce2f0(short p1, int *p2, char *p3)
{
    short i;
    *p3 = 0;
    for (i = 0; i < p1; i++) {
        if (p1 > 1 && i == p1 - 1) {
            f_0e9300(&d_1c38b0, p3, 0x200001b5);
            f_0e9300(&d_1c38b0, p3, 0x20000195);
            f_0e9300(&d_1c38b0, p3, 0x200001b5);
        }
        strcat(p3, f_0422b0((struct hero *)(p2[i])));
        if (p1 > 2 && i < p1 - 2) f_0e9300(&d_1c38b0, p3, 0x20000193);
    }
}
//@ f_0ce3e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion durchsucht alle 31 Inventarplätze (0 bis 0x1e) eines einzelnen Helden p1 nach dem
 *   Gegenstandstyp p2 und summiert dessen Gesamtanzahl (unter Berücksichtigung stapelbarer Gegenstände über
 *   f_0a7950 und f_042ac0).
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur sowie die Gegenstands-ID p2.
 * - Rückgabewert: Zurückgegeben wird die gefundene Stückzahl des Gegenstands im Inventar des Helden.
 === Ende Beschreibung === */
short f_0ce3e0(int p1, short p2)
{
    short total=0;
    int k = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[p2]))->f_0a7950();
    short i;
    for (i = 0; i < 0x1f; i++) {
        if (f_042a60((struct hero *)(p1), i) == p2) {
            total += k ? f_042ac0((struct hero *)(p1), i) : 1;
        }
    }
    return total;
}
//@ f_0ce450
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion summiert über alle sieben Gruppenplätze der Gruppe p1 mittels f_0ce3e0, wie viele
 *   Exemplare des Gegenstandstyps p2 die gesamte Heldengruppe zusammen besitzt.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Gruppenstruktur sowie die Gegenstands-ID p2.
 * - Rückgabewert: Zurückgegeben wird die Gesamtstückzahl des Gegenstands p2 in der gesamten Gruppe.
 === Ende Beschreibung === */
short f_0ce450(int p1, short p2)
{
    short total=0;
    short b;
    for (b = 0; b < 7; b++) {
        int inv = f_0de7d0(p1, b);
        if (inv) total += f_0ce3e0(inv, p2);
    }
    return total;
}
//@ f_0ce4f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entfernt bis zu p3 Exemplare des Gegenstandstyps p2 aus den 31 Inventarplätzen des
 *   Helden p1 (f_036300) und gibt die Anzahl der tatsächlich entfernten Gegenstände zurück. Originalfehler: Wenn
 *   ein Inventarplatz genügend Gegenstände enthält, um den verbleibenden Restbedarf p3 - total zu decken (cnt >=
 *   p3 - total), rechnet der else-Zweig total += p3 statt total = p3 (oder total += p3 - total); wird die
 *   angeforderte Menge über mehrere Slots hinweg abgebucht, liefert die Funktion dadurch einen zu hohen
 *   Rückgabewert (total > p3).
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Heldenstruktur, die Gegenstands-ID p2 sowie die zu
 *   entfernende Anzahl p3.
 * - Rückgabewert: Zurückgegeben wird die gezählte Menge der entfernten Gegenstände (bei Verteilung auf mehrere
 *   Slots fehlerhaft überhöht).
 === Ende Beschreibung === */
short f_0ce4f0(int p1, short p2, short p3)
{
    short total = 0;
    short cnt;
    short i;
    int k = ((RivaItemDefinition*)((*(int **)&d_1c2c40)[(*&p2)]))->f_0a7950();
    (*(int **)&d_1c2c40) = ((int)(*(int **)&d_1c2c40) & 0) ? 0 : (*(int **)&d_1c2c40);
    for (i = 0; i < 0x1f && (short)total < p3; i++) {
        if (f_042a60((struct hero *)(p1), i) == p2) {
            cnt = k ? f_042ac0((struct hero *)(p1), i) : 1;
            f_036300(p1, i, (short)(p3 - total));
            if (cnt < p3 - (short)total) total += cnt; else total += p3;
        }
    }
    return total;
}
int f_0ce4f0_w(int p1, short p2, short p3);
#pragma aux f_0ce4f0_w "W?f_0ce4f0$n(iss)s"
#define f_0ce4f0 f_0ce4f0_w
//@ f_0ce590
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion entfernt insgesamt bis zu p3 Exemplare des Gegenstandstyps p2 aus dem Besitz der
 *   gesamten Heldengruppe p1, indem sie nacheinander die sieben Gruppenplätze über f_0ce4f0 abarbeitet.
 * - Eingaben: Übergeben werden der Zeiger p1 auf die Gruppenstruktur, die Gegenstands-ID p2 sowie die insgesamt
 *   zu entfernende Stückzahl p3.
 * - Rückgabewert: Zurückgegeben wird die Summe der bei den Gruppenmitgliedern entfernten Gegenstände.
 === Ende Beschreibung === */
int f_0ce590(int p1, short p2, short p3)
{
    int total = 0;
    short i;
    for (i = 0; i < 7 && (short)total < p3; i++) {
        int inv = f_0de7d0(p1, i);
        if (inv) total += f_0ce4f0(inv, p2, (short)(p3 - total));
    }
    return total;
}
//@ f_0ce5e0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Timer-Callback-Funktion erhöht den globalen Zeitzähler d_1bf374 bei jedem Aufruf um 1 und gibt
 *   den vorherigen Zählerstand zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Zurückgegeben wird der Zählerstand von d_1bf374 vor dem Inkrementieren.
 === Ende Beschreibung === */
int f_0ce5e0()
{
    return d_1bf374++;
}
//@ f_0ce5f0
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion beendet den in d_1a57c4 gespeicherten Sound-/System-Timer über f_147c02 und setzt das
 *   Handle d_1a57c4 auf -1 zurück.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce5f0()
{
    if (d_1a57c4 != -1) {
        f_147c02((int)&d_1c2edc, d_1a57c4);
        d_1a57c4 = -1;
    }
}
//@ f_0ce620
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion setzt den Zeitzähler d_1bf374 auf 0 und registriert f_0ce5e0 über f_147b97 als
 *   periodischen 100-Hz-Timer im Soundsystem d_1c2edc.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce620()
{
    d_1bf374 = 0;
    d_1a57c4 = f_147b97((int)&d_1c2edc, 100, (int)f_0ce5e0);
}
//@ f_0ce650
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wartet mit Sanduhr-Mauszeiger (f_0d2f90(5, 1)) darauf, dass eine laufende Sprach- oder
 *   Soundausgabe (f_147808) beendet wird, bricht diese nach einem Timeout von d_1bf374 > 500 Ticks über f_147aad
 *   ab und gibt den Timer anschließend wieder frei.
 * - Eingaben: Diese Funktion nimmt keine Parameter entgegen.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce650()
{
    d_1bf374 = 0;
    d_1a57c4 = f_147b97((int)&d_1c2edc, 100, (int)f_0ce5e0);
    if (f_147808((int)&d_1c2edc) == 1) {
        f_149e2e((int)&d_1c2a74, 0xff);
        f_0d2f90(5, 1);
        while (f_147808((int)&d_1c2edc) == 1) {
            f_146dfa((int)&d_1c2edc, 1);
            if (d_1bf374 > 500) f_147aad((int)&d_1c2edc);
        }
        f_0d2e70();
    }
    if (d_1a57c4 != -1) {
        f_147c02((int)&d_1c2edc, d_1a57c4);
        d_1a57c4 = -1;
    }
}
//@ f_0ce710
/* === Beschreibung (Katalog) ===
 * - Zweck: Diese Funktion wartet mit Sanduhr-Mauszeiger (f_0d2f90(5, 1)) darauf, dass der spezifische
 *   Soundeffekt mit dem Handle p1 (f_14778f) fertig abgespielt wurde, stoppt ihn spätestens bei d_1bf374 > 500
 *   über f_147688 und entfernt danach den Hilfstimer.
 * - Eingaben: Als Parameter wird das Handle bzw. die Kanalkennung p1 des laufenden Soundeffekts übergeben.
 * - Rückgabewert: Es wird kein Rückgabewert geliefert (void).
 === Ende Beschreibung === */
void f_0ce710(int p1)
{
    d_1bf374 = 0;
    d_1a57c4 = f_147b97((int)&d_1c2edc, 100, (int)f_0ce5e0);
    f_149e2e((int)&d_1c2a74, 0xff);
    f_0d2f90(5, 1);
    while (f_14778f((int)&d_1c2edc, p1) == 1) {
        f_146dfa((int)&d_1c2edc, 1);
        if (d_1bf374 > 500) f_147688((int)&d_1c2edc, p1);
    }
    f_0d2e70();
    if (d_1a57c4 != -1) {
        f_147c02((int)&d_1c2edc, d_1a57c4);
        d_1a57c4 = -1;
    }
}
