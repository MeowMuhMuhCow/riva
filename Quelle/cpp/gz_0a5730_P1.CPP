/* === Beschreibung (Katalog) ===
 * Einheit gz_0a5730 (0a5730-0a6200)
 *
 * Überblick
 * Diese Einheit implementiert die Herberge (INN.CPP), in der die Heldengruppe eine Zeche in der Schankstube
 * bezahlen (0x97 / f_0a5e70), Zimmer in drei Qualitätsstufen (Schlafsaal, Einzelzimmer, Suite) für ein bis neun
 * Tage mieten (0x9a / f_0a5f30), im gemieteten Zimmer rasten (0x9b / f_0a6030) oder das Tagebuch lesen (0x8c /
 * f_0a60f0) kann.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 12/14 gleich (suche.py 25.10.2026, Basis gz_0a5730_P1.CPP)
// gz_0a5730.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0A5730-0x0A6200
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_02dee0(int p1);                                   // reg eax stapel 0
short f_02df40(int p1);
int f_02dfe0(int p1);                                   // reg eax stapel 0
int f_038d70(int p1, int p2);                           // reg eax edx stapel 0
short f_03aa20(int p1, int p2, int p3, int p4);
int f_040370(int p1, int p2);                           // reg eax edx stapel 0
int f_0b9060(int p1);                                   // reg eax stapel 0
int f_0bba10(int p1);
int f_0bf6f0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bf730(int p1, int p2);                           // reg eax edx stapel 0
short f_0bf7b0(int p1, int p2, int p3, int p4, int p5, int p6);
short f_0bf820(int p1, ...);
                                         // reg - stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0daa90(int p1, int p2);                           // reg eax edx stapel 0
int f_0daaf0(int p1, int p2);                           // reg eax edx stapel 0
int f_0daba0(int p1, int p2);                           // reg eax edx stapel 0
int f_0db820(int p1, int p2);                           // reg eax edx stapel 0
int f_0db8b0(int p1, int p2);                           // reg eax edx stapel 0
short f_0dbff0(int p1);
int f_0de7e0(int p1);                                   // reg eax stapel 0
int f_10a260(int p1, int p2);                           // reg edx stapel 0
int f_10a270(int p1, int p2);                           // reg eax edx stapel 0
int f_10a2e0(int p1, int p2, int p3, int p4, int p5);   // reg edx ebx ecx stapel 4
int f_10a6d0();                                         // reg - stapel 0
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
int f_125ed0(int p1, int p2);                           // reg eax edx stapel 0
int f_126f40(int p1);                                   // reg eax stapel 0
int f_1270c0(int p1);                                   // reg eax stapel 0
int f_133fe0(int p1, int p2);                           // reg eax edx stapel 0
                   // reg eax ebx stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1bb058;                    // 0x1BB058
extern int d_1bfdb8;                    // 0x1BFDB8
extern int d_1c0004;                    // 0x1C0004
                    // 0x1C2098
extern volatile short d_1c2198;
extern volatile short d_1c219a;
extern int d_1c21b4;                    // 0x1C21B4
extern int d_1c2c44;                    // 0x1C2C44
extern int d_1c2c64;                    // 0x1C2C64
extern const char d_1c3498[];
extern const char d_1c349c[];
extern const char d_1c3870[];

int f_145234(int p1, int p2);
void f_145254(void);
int f_145300(int p1, int p2, int p3);
extern char d_1bb06c[];
extern int d_1bf230;
#define W16(p,o) (*(short *)((p) + (o)))
#define W32(p,o) (*(int *)((p) + (o)))
#define RESET3(p) W16(p,0x66) = 0; W16(p,0x64) = W16(p,0x66); W16(p,0x62) = W16(p,0x66);
#define FIX(p) { int v_ = f_1270c0((p) + 0x68); if (v_ >= W16(p,0x64) * 0x1518 - 0x1517) { RESET3(p) } f_0a5d80(p); }

struct OA { char pad[0x14]; short *q; char rest[0x24]; };
struct OB { char pad[0x10]; char *q; char rest[0x2c]; };
void f_0a5d80(int p1);
void f_0a5e70(int p1);
void f_0a5f30(int p1);
void f_0a6030(int p1);
void f_0a60f0(int p1);
#define E70BODY(p1) { struct OB o; short s; f_125400(&o, d_1c349c, d_1c3870, d_1c3498); s = f_02df40(p1); f_040370((int)&d_1c21b4, s); *(int *)(o.q + 4) = f_133fe0((int)d_1c3498, (int)&d_1c21b4); if (f_0bf6f0((int)&d_1c2c64, 0x11000006) == 1) { if (f_0de7e0(d_1c0004) < (int)s) { f_0bf730((int)&d_1c2c64, 0x20000010); } else { f_0bf730((int)&d_1c2c64, 0x11000007); f_0db8b0(d_1c0004, s); f_02dfe0(p1); } } f_1254a0(&o, 0); }
#define B60F0(p1) { int v = f_038d70(d_1c0004, 0x200001bf); if (v != 0) { if (f_03aa20(v, 0, 3, -1) != -3) { d_1c2198 = 0; d_1c219a = 1; f_125ed0((int)&d_1c2c44, 0x1e); } } FIX(p1) }
//@ f_0a5730
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruiert ein Herbergs-Gebäudeobjekt über den Basiskonstruktor f_10a260, trägt die virtuelle
 *   Methodentabelle d_1bb06c an Offset 0x58 ein und initialisiert die Mietdauer-, Zimmerkategorie-, Preis- und
 *   Zeitstempelfelder an Offset 0x60..0x72 mit 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Gebäudekennung p2 und gibt die
 *   initialisierte Objektadresse zurück (int).
 * - Wichtige Variablen: Die Felder ab t + 0x60 speichern den Mietzustand der Herberge (Gebäudenummer 0x60,
 *   Zimmerkategorie 0x62, Mietstunden 0x64, Mietpreis 0x66 und Mietzeitstempel 0x68..0x6e).
 === Ende Beschreibung === */
int f_0a5730(int p1, int p2)
{
    int t = f_10a260(p1, (short)p2);
    int q = t + 0x68;
    W32(q, -0x10) = (int)d_1bb06c;
    W16(q, -6) = 0;
    W16(q, -4) = 0;
    W16(q, -8) = p2;
    W16(q, -2) = 0;
    f_145300(q, 0, 7);
    W16(t, 0x6f) = 0;
    W16(t, 0x71) = W16(t, 0x6f);
    return t;
}
//@ f_0a5780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wirkt als Destruktor des Herbergs-Gebäudeobjekts, ruft den Basisdestruktor f_10a270 auf und
 *   gibt bei gesetztem Bit 2 in p2 den Objektspeicher frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 sowie die Destruktor-Flags p2 (unsigned) und
 *   gibt die Objektadresse zurück (int).
 * - Wichtige Variablen: Bei Array-Freigaben (p2 & 4) wird der Deskriptor d_1bb058 an f_145234 übergeben.
 === Ende Beschreibung === */
int f_0a5780(int p1, unsigned p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)&d_1bb058);
        f_145254();
        return p1;
    }
    W32(p1, 0x58) = (int)d_1bb06c;
    r = f_10a270(p1, 1);
    if (p2 & 2) {
        operator delete((void *)r);
    }
    return r;
}
//@ f_0a57d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Steuert als zentrale Ereignismethode der Herberge das Betreten (0x81), das Essen und Trinken
 *   in der Gaststube (0x97), das Mieten oder Stornieren eines Zimmers (0x9a über f_0a5f30), das Schlafen im
 *   gemieteten Zimmer (0x9b über f_0a6030), das Lesen im Tagebuch (0x8c) sowie das Verlassen (0x8d).
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 sowie den Ereigniscode p2 und gibt bei 0x80
 *   den Wert 1, sonst 0 zurück (int).
 * - Wichtige Variablen: Am Ende jeder Aktion prüft das Makro FIX(p1) (f_0a5d20), ob die gemietete Zimmerzeit
 *   inzwischen abgelaufen ist, und passt über f_0a5d80 die sichtbaren Menüschaltflächen an.
 === Ende Beschreibung === */
int f_0a57d0(int p1, int p2)
{
    int f_10a6d0(int);
    int f_02df40(void *);
    int r = 0;
    unsigned short u = p2;
    switch (u) {
    case 0: break;
    case 0x81: f_0b9060(p1); break;
    case 0x97: {
        struct { char pad[0x10]; char *q; char rest[0x28]; } o;
        f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
        int s = f_02df40((void *)p1);
        f_040370((int)&d_1c21b4, (short)s);
        *(int *)(o.q + 4) = f_133fe0((int)d_1c3498, (int)&d_1c21b4);
        if (f_0bf6f0((int)&d_1c2c64, 0x11000006) == 1) {
            int e = (short)(s & 0xffff);
            if (f_0de7e0(d_1c0004) >= e) {
                f_0bf730((int)&d_1c2c64, 0x11000007);
                f_0db8b0(d_1c0004, e);
                f_02dfe0(p1);
            } else f_0bf730((int)&d_1c2c64, 0x20000010);
        }
        f_1254a0(&o, 0);
        break;
    }
    case 0x9a: f_0a5f30(p1); break;
    case 0x9b: f_0a6030(p1); break;
    case 0x8c: { int p = p1; B60F0(p) } break;
    case 0x8d: f_10a6d0(p1); FIX(p1) break;
    case 0x80: r = 1; break;
    }
    FIX(p1)
    return r;
}
//@ f_0a5a70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt beim Betreten der Herberge p1 deren gespeicherten 15-Byte-Mietzustand (p1 + 0x60) aus der
 *   Spielstandsdatei 0x40110001 (Offset (GebäudeID - 13) * 15), prüft eine eventuell laufende Zimmermiete auf
 *   Ablauf und schaltet die passenden Raum-Aktionen über f_0a5d80 frei.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Jede Herberge ab Gebäude-ID 13 (0xd) besitzt in der Datei 0x40110001 einen eigenen
 *   15-Byte-Datensatz (0xf Bytes).
 === Ende Beschreibung === */
void f_0a5a70(int p1)
{
    f_02dee0(p1);
    if (((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0x40110001, 0x200) == 1) {
        ((RivaFileManager*)((int)&d_1c2098))->f_144ab0( (short)((W16(p1, 0) - 0xd) * 0xf), 0);
        ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144920((void *)( p1 + 0x60), 0xf)));
        ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
    }
    if (W16(p1, 0x62) > 0) {
        FIX(p1)
    } else {
        f_0a5d80(p1);
    }
}
//@ f_0a5b30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert beim Verlassen der Herberge p1 den aktuellen 15-Byte-Mietzustand ab p1 + 0x60 an die
 *   Position (GebäudeID - 13) * 15 in der Datei 0x40110001.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Dateizugriff erfolgt schreibend (0x221) über den globalen Dateimanager d_1c2098.
 === Ende Beschreibung === */
void f_0a5b30(int p1)
{
    if (((RivaFileManager*)((int)&d_1c2098))->f_1448b0( 0x40110001, 0x221) == 1) {
        ((RivaFileManager*)((int)&d_1c2098))->f_144ab0( (short)((W16(p1, 0) - 0xd) * 0xf), 0);
        ((int)(((RivaFileManager*)((int)&d_1c2098))->f_144960((void *)( p1 + 0x60), 0xf)));
        ((RivaFileManager*)((int)&d_1c2098))->f_1449a0();
    }
}
//@ f_0a5b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet aus einem Grundbetrag p2 und dem prozentualen Preismodifikator W16(p1, 0x5c) der
 *   Herberge den angepassten Preis ((Modifikator * p2) / 100 + p2).
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 sowie den Grundpreis p2 und gibt den
 *   modifizierten Preis zurück (int).
 * - Wichtige Variablen: Das 16-Bit-Feld W16(p1, 0x5c) enthält den Preisaufschlag der jeweiligen Herberge in
 *   Prozent.
 === Ende Beschreibung === */
int f_0a5b90(int p1, int p2)
{
    return (W16(p1, 0x5c) * p2) / 100 + p2;
}
//@ f_0a5bb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die Tagespreise für die drei Zimmerkategorien (Schlafsaal: Grundpreis 5 Heller,
 *   Einzelzimmer: 30 Heller, Suite: 100 Heller, jeweils angepasst um W16(p1, 0x5c)), lässt den Spieler die
 *   gewünschte Zimmerkategorie (1..3) und die Anzahl der Tage (1..9) wählen und berechnet den Gesamtpreis
 *   W16(p1, 0x66) für alle zahlungspflichtigen Gruppenmitglieder (f_0dbff0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt 1 zurück, wenn der Spieler eine
 *   gültige Auswahl getroffen hat, oder 0 bei Abbruch (int).
 * - Wichtige Variablen: Das Feld W16(p1, 0x62) speichert die gewählte Zimmerart (1..3), W16(p1, 0x64) die
 *   gebuchten Stunden (Tage * 24) und W16(p1, 0x66) den Gesamtpreis in Hellern.
 === Ende Beschreibung === */
#pragma aux f_0dbff0 modify [eax];
int f_0a5bb0(int p1)
{
    struct OA o;
    int r;
    int b, a, c;
    short s;
    r = 0;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    int v = (W16(p1, 0x5c) * 5) / 100; o.q[1] = (v += 5);
    a = o.q[1];
    o.q[2] = (W16(p1, 0x5c) * 15 * 2) / 100 + 30;
    b = o.q[2];
    o.q[3] = (W16(p1, 0x5c) * 100) / 100 + 100;
    c = o.q[3];
    W16(p1, 0x62) = f_0bf820((int)&d_1c2c64, 0x11000002, 3, 0x11000003, 0x11000004, 0x11000005);
    if (W16(p1, 0x62) != -1) {
        s = f_0bf7b0((int)&d_1c2c64, 1, 0x1100000a, 0, 9, 1);
        if (s > 0) {
            W16(p1, 0x64) = s * 0x18;
            int m = (W16(p1, 0x62) == 1) ? a : ((W16(p1, 0x62) == 2) ? b : c);
            int k = (short)m; k *= W16(p1, 0x64); W16(p1, 0x66) = (k * f_0dbff0(d_1c0004)) / 0x18;
            r = 1;
        }
    }
    if (!r) {
        RESET3(p1)
    }
    f_1254a0(&o, 0);
    return r;
}
//@ f_0a5d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der seit Mietbeginn (p1 + 0x68) verstrichenen Spielsekunden (f_1270c0), ob die
 *   gebuchte Mietdauer W16(p1, 0x64) * 5400 (0x1518 Zeiteinheiten pro Stunde) abgelaufen ist, setzt bei Ablauf
 *   die Mietdaten (0x62, 0x64, 0x66) auf 0 zurück und gibt die verbleibende Mietzeit zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt die verbleibenden Zeiteinheiten
 *   oder 0 nach Ablauf zurück (int).
 * - Wichtige Variablen: Eine Spielstunde entspricht 0x1518 (5.400) internen Zeiteinheiten.
 === Ende Beschreibung === */
int f_0a5d20(int p1)
{
    int v = f_1270c0(p1 + 0x68);
    int w = W16(p1, 0x64) * 0x1518;
    if (v >= w - 0x1517) {
        RESET3(p1)
        return 0;
    }
    return w - v;
}
//@ f_0a5d80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Passt die Aktionsschaltflächen im Raummenü d_1bfdb8 der Herberge an den aktuellen Mietstatus
 *   an: Solange ein Zimmer gemietet ist (W16(p1, 0x62) != 0), werden die Schaltflächen 0xc, 0xd und 0x1b (u. a.
 *   Rasten und Tagebuch im Zimmer) über f_0daaf0 eingeblendet, andernfalls über f_0daa90 ausgeblendet, und bei
 *   einer Statusänderung wird die Menüleiste neu gezeichnet (f_0daba0).
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Felder W16(p1, 0x6f) und W16(p1, 0x71) merken sich den alten und neuen
 *   Sichtbarkeitsstatus der Zimmer-Schaltflächen.
 === Ende Beschreibung === */
void f_0a5d80(int p1)
{
    short s = d_1c2198;
    if (W16(p1, 0x62) == 0) {
        f_0daa90(d_1bfdb8, 0xc);
        f_0daa90(d_1bfdb8, 0xd);
        f_0daa90(d_1bfdb8, 0x1b);
        W16(p1, 0x71) = 0;
    } else {
        f_0daaf0(d_1bfdb8, 0xc);
        f_0daaf0(d_1bfdb8, 0xd);
        f_0daaf0(d_1bfdb8, 0x1b);
        W16(p1, 0x71) = 1;
    }
    if (W16(p1, 0x71) != W16(p1, 0x6f)) {
        W16(p1, 0x6f) = W16(p1, 0x71);
        if (f_0bba10((int)&d_1bf230)) {
            RivaMouseGuard mg;
            f_0daba0(d_1bfdb8, d_1a34e0);
        }
    }
    if (s == 0) {
        d_1c2198 = 0;
    }
}
//@ f_0a5e70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt über f_02df40 den Preis für Speis und Trank in der Schankstube, fragt den Spieler um
 *   Bestätigung (0x11000006), zieht den Betrag bei ausreichendem Gruppenvermögen über f_0db8b0 ab und versorgt
 *   die Gruppe über f_02dfe0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Funktion entspricht dem Zweig case 0x97 in f_0a57d0.
 === Ende Beschreibung === */
void f_0a5e70(int p1)
{
    int f_02df40(void *);
    struct { char pad[0x10]; char *q; char rest[0x28]; } o;
    f_125400(&o, d_1c349c, d_1c3870, d_1c3498);
    int s = f_02df40((void *)p1);
    f_040370((int)&d_1c21b4, (short)s);
    *(int *)(o.q + 4) = f_133fe0((int)d_1c3498, (int)&d_1c21b4);
    if (f_0bf6f0((int)&d_1c2c64, 0x11000006) == 1) {
        int e = (short)(s & 0xffff);
        if (f_0de7e0(d_1c0004) >= e) {
            f_0bf730((int)&d_1c2c64, 0x11000007);
            f_0db8b0(d_1c0004, e);
            f_02dfe0(p1);
        } else f_0bf730((int)&d_1c2c64, 0x20000010);
    }
    f_1254a0(&o, 0);
}
//@ f_0a5f30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verwaltet das Mieten und vorzeitige Kündigen eines Herbergszimmers: Ist bereits ein Zimmer
 *   gemietet (W16(p1, 0x62) != 0), kann der Spieler die Buchung stornieren (0x11000001) und erhält den
 *   anteiligen Preis für die noch nicht angebrochenen Stunden über f_0db820 zurück; ist kein Zimmer gemietet,
 *   ruft die Funktion die Auswahl f_0a5bb0 auf, zieht den Mietpreis ab, lässt 30 Minuten (0x1e) vergehen und
 *   speichert den Startzeitpunkt über f_126f40(p1 + 0x68).
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nach jeder Änderung aktualisiert f_0a5d80 die verfügbaren Menüschaltflächen.
 === Ende Beschreibung === */
void f_0a5f30(int p1)
{
    if (W16(p1, 0x62) != 0) {
        if (f_0bf6f0((int)&d_1c2c64, 0x11000001) == 1) {
            short s = W16(p1, 0x64) - f_1270c0(p1 + 0x68) / 0x1518;
            f_0db820(d_1c0004, (short)((W16(p1, 0x66) * (short)s) / W16(p1, 0x64)));
            W16(p1, 0x62) = 0;
        }
    }
    if (W16(p1, 0x62) == 0) {
        if (f_0a5bb0(p1) == 1) {
            if (f_0de7e0(d_1c0004) < W16(p1, 0x66)) {
                f_0bf730((int)&d_1c2c64, 0x20000010);
                RESET3(p1)
            } else {
                f_0db8b0(d_1c0004, W16(p1, 0x66));
                f_125ed0((int)&d_1c2c44, 0x1e);
                f_0bf730((int)&d_1c2c64, 0x11000008);
                W16(p1, 0x60) = W16(p1, 0);
                f_126f40(p1 + 0x68);
            }
        }
    }
    f_0a5d80(p1);
}
//@ f_0a6030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet eine Rast im gemieteten Herbergszimmer (f_10a2e0), wobei die höchstens rastbare
 *   Stundenzahl n aus der verbleibenden Mietzeit und der Regenerationsbonus s4 aus der gebuchten Zimmerkategorie
 *   (W16(p1, 0x62) * 2 + 1) sowie der Herbergsqualität (W16(p1, 0x5c)) berechnet wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Bessere Zimmer (W16(p1, 0x62) == 3 für Suite) und günstigere/bessere Herbergen erhöhen
 *   den Regenerationsparameter s4 für f_10a2e0.
 === Ende Beschreibung === */
void f_0a6030(int p1)
{
    short s = W16(p1, 0x62);
    int v = f_1270c0(p1 + 0x68);
    short n = W16(p1, 0x64);
    short s4;
    s = s * 2;
    s4 = s + 1;
    for (; 0x1518 < v; v = v - 0x1518) {
        n = n - 1;
    }
    if (n == 0) {
        n = 1;
    }
    if (W16(p1, 0x5c) < 8) {
        s4 = s4 + 1;
    } else if (W16(p1, 0x5c) > 0xf) {
        s4 = s4 - 1;
    }
    if (1 < n) {
        f_10a2e0(p1, 0, n, 1, s4);
    }
    FIX(p1)
}
//@ f_0a60f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet im Herbergszimmer die Tagebuch- bzw. Dokumentenansicht (0x200001bf) über f_03aa20 und
 *   lässt nach dem Lesen 30 Minuten (0x1e) Spielzeit vergehen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Am Ende wird über FIX(p1) geprüft, ob die Zimmermiete während der verstrichenen 30
 *   Minuten abgelaufen ist.
 === Ende Beschreibung === */
void f_0a60f0(int p1)
{
    int v = f_038d70(d_1c0004, 0x200001bf);
    if (v != 0) {
        if (f_03aa20(v, 0, 3, -1) != -3) {
            d_1c2198 = 0;
            d_1c219a = 1;
            f_125ed0((int)&d_1c2c44, 0x1e);
        }
    }
    FIX(p1)
}
//@ f_0a61a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft exakt wie f_0a5d20, ob die gebuchte Zimmermietzeit abgelaufen ist, setzt bei Ablauf die
 *   Mietfelder zurück und gibt die verbleibende Mietdauer in Zeiteinheiten zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Herbergszeiger p1 und gibt die verbleibende Mietzeit oder 0
 *   zurück (int).
 * - Wichtige Variablen: Das Feld p1 + 0x68 enthält den Zeitstempel des Mietbeginns.
 === Ende Beschreibung === */
int f_0a61a0(int p1)
{
    int v = f_1270c0(p1 + 0x68);
    int w = W16(p1, 0x64) * 0x1518;
    if (v >= w - 0x1517) {
        RESET3(p1)
        return 0;
    }
    return w - v;
}
