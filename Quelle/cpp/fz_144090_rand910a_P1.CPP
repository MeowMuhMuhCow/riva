/* === Beschreibung (Katalog) ===
 * Einheit fz_144090_rand910a (0x144090 - 0x1445D0)
 *
 * Überblick
 * Diese Einheit enthält fünf zentrale Systemfunktionen am Übergang zwischen dem Hauptprogramm (zmain.cpp) und
 * der Dateiverwaltung (file.cpp). Sie umfasst die globale Freigabe der Systempuffer und Grafikpaletten, das
 * Anlegen und Bereinigen des temporären Spielstandverzeichnisses (TEMP), die Grundinitialisierung von
 * Schriftart, Textrenderer, Heldengruppe, Mauszeiger und Konfigurationseinstellungen sowie das geordnete
 * Herunterfahren von Maus-, Sound- und Musiktreibern.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 29/33 gleich (suche.py 25.10.2026, Basis fz_144090_P1.CPP)
// P2 Koepfe Stufe 3 (Fable K): 25 gleich (vorher 24), Rest 222 (vorher 228)
// fz_144090.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x144090-0x144BF0
#include <string.h>
#include <stdio.h>
void f_01bf80();
void f_01e0c0();
int f_04fe30(int p1, int p2);
void f_0d2710();
int f_0d3a30(int p1, int p2, int p3);
int f_0d4070(int *p1);
void f_11fbe0();
int f_13fa90(int p1, int p2);
int f_147aad(int *p1);
void __cdecl f_149dfe(void *p);
int f_1664d0(const char *p1, const char *p2, int p3);
char f_0ce0b0();
int f_0ce120(int p1, char *p2);
char *f_15dc3f(char *p1, int p2);
int f_15f2b5(char *p1);
int f_149292(char *p1);
int f_165c50(char *p1, char *p2);
short f_1492b4(char *p1, int p2);
int f_149336(char *p1);
short f_1492d1(void *p1);
int f_1492ed(void *p1, int p2);
int f_0b06d0(char *p1, char *p2);
int f_0ed8f0(void *p1, int p2, ...);
int f_045b70(void *p1, int p2);
int f_05e1c0(void *p1, void *p2);
int f_05e320(void *p1, int p2, int p3);
int f_05e2d0(void *p1, int p2, int p3, int p4, int p5);
int f_05e420(void *p1, int p2);
int f_05ded0(void *p1, int p2);
int f_05e380(void *p1, int p2, int p3, int p4, int p5, int p6);
int f_0c0020(void *p1, int p2);
int f_1568bf(int p1, int p2);
int f_0d3870();
char f_0ce070(void *p1, int p2);
int f_0de810(void *p1, int p2);
int f_0d3df6(void *p1);
int f_0d78a0(void *p1);
int f_0d7a20(void *p1);
char f_0ce200();
int f_0d7be0(void *p1, int p2);
int f_0d78b0(void *p1);
int f_147746(void *p1, unsigned short p2);
int f_120460();
int f_01bfb0(int p1);
extern const char d_1b879b[];
extern const char d_1b879f[];
extern const char d_1a97a4[];
extern const char *d_1a9674;
extern const char *d_1a9678;
extern char d_1c21b4[];
extern char d_1c27a8[];
extern char d_1c1fe0[];
extern int d_1c1190;
extern int d_1c3078, d_1c38b0, d_1c3068, d_1c2c64;
extern int d_1a01b4, d_1a34e0, d_1bc948, d_1bfdbc, d_1c3908;
extern int *d_1c0004;
extern char d_1c002c;
extern unsigned short d_1c2eb2;
extern signed char d_1bfb10, d_1bfb14, d_1bfb24, d_1bfae4, d_1bfb2c;
extern char d_1bfb20;
struct E5 { void *p; char v; };
extern E5 d_1a5afc[];
struct FT { char r[30]; char name[13]; };
void f_0a7d00();
void f_126c40(int *p1);
extern int d_1bc760;
extern int d_1c2e78;
extern int d_1c2edc;
extern int d_1c2a78[];
extern int d_1c2c44;
extern char *d_1bc8f0;
extern char *d_1bc8f8;
extern char *d_1bdbe4;
extern char *d_1bdbe8;
extern const char d_1a97ac[];
extern const char d_1b87cc[];
extern const char d_1b87e0[];
extern const char d_1b87f6[];
extern const char d_1b8807[];
extern const char d_1b8817[];
extern const char d_1b8824[];
extern const char d_1b8831[];
extern const char d_1b883e[];
extern const char d_1b884b[];
extern const char d_1b8858[];
extern const char d_1b8865[];
extern const char d_1b8872[];
extern const char d_1b887f[];
extern const char d_1b888c[];
extern const char d_1b8899[];
extern const char d_1b88a6[];
extern const char d_1b88b3[];
extern const char d_1b88c0[];
struct V6 { short a, b, c; virtual ~V6(); };
extern V6 *d_1be17c;


extern RivaFileManager d_1c2098;
#define EQ(x,v) (((x)==(v))?1:0)
extern RivaFileStreamVtable d_1bbf24;
//@ f_144090
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt beim Programmende oder bei einem Abbruch die in der Hauptinitialisierung (f_143ef0)
 *   angelegten globalen Puffer, Grafikpaletten und Hilfsobjekte wieder frei. Dazu gehören die beiden großen
 *   Arbeitspuffer (d_1bc8f0, d_1bc8f8), das Grafik-/Animationssystem (f_0a7d00), die globalen Farbpaletten
 *   (d_1bdbe4, d_1bdbe8), das zentrale Würfelobjekt (d_1be17c) sowie der globale Aufräum-Manager (d_1c2c44).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bc8f0, d_1bc8f8: Zeiger auf die globalen Hauptspeicherpuffer, die freigegeben und auf 0 gesetzt werden.
 *   - d_1bdbe4, d_1bdbe8: Zeiger auf die globalen 768-Byte-Farbpaletten.
 *   - d_1be17c: Zeiger auf das globale Zufalls-/Würfelobjekt.
 *   - d_1c2c44: Globale Verwaltungsstruktur, die über f_126c40 abgeräumt wird.
 === Ende Beschreibung === */
void f_144090()
{
    delete d_1bc8f0;
    d_1bc8f0 = 0;
    delete d_1bc8f8;
    d_1bc8f8 = 0;
    f_0a7d00();
    delete d_1bdbe4;
    d_1bdbe4 = 0;
    delete d_1bdbe8;
    d_1bdbe8 = 0;
    delete d_1be17c;
    d_1be17c = 0;
    f_126c40(&d_1c2c44);
}
//@ f_144110
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Richtet beim Spielstart das Verzeichnis für temporäre Spieldateien (TEMP, d_1a97a4) ein,
 *   löscht darin alle verwaisten temporären Dateien aus einer früheren Sitzung und kopiert anschließend die
 *   initiale Spielstandsdatei (0x90001) über f_0b06d0 in den temporären Arbeitsbereich. Schlägt das Anlegen des
 *   Verzeichnisses oder das Öffnen der Basisdatei fehl, bricht die Funktion das Programm mit einer Fehlermeldung
 *   (f_1435c0) ab.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s / info: Verzeichnissuchstruktur (find_t) für die Iteration über vorhandene Dateien im TEMP-Ordner
 *     mittels f_1492b4, f_1492d1 und f_149336.
 *   - buf: Pfadpuffer auf dem Stack zum Zusammensetzen der Dateinamen beim Löschen (f_147c84).
 *   - f1, f2: Zwei Dateiobjekte (f_12e1d0), mit denen das Vorhandensein und Kopieren der Ressource 0x90001
 *     (0x80090001 im virtuellen Dateisystem) geprüft wird.
 === Ende Beschreibung === */
#pragma aux f_144110 modify exact [eax]
int f_0ed8f0(int p1, ...);
int f_1492b4(char *p1, int p2, FT *p3);
int f_1492d1(FT *p1);
int f_1492ed(FT *p1);
char *g_144850(RivaFileManager *p1, unsigned p2);
#pragma aux g_144850 "f_144850"
void f_144110()
{
    FT ft;
    char buf[40];
    strcpy(buf, d_1b879b);
    buf[0] = f_0ce0b0() + 0x40;
    f_0ce120(0, buf + 3);
    strcpy(d_1c21b4, buf);
    *f_15dc3f(d_1c21b4, 0x5c) = 0;
    strcat(d_1c21b4, d_1a97a4);
    if (f_15f2b5(d_1c21b4) == 0)
        f_15f2b5(buf);
    else
        f_149292(d_1c21b4);
    f_165c50(d_1c1fe0, d_1c21b4);
    sprintf(d_1c21b4, d_1a9674, d_1b879f);
    if ((short)f_1492b4(d_1c21b4, 0, &ft) == (short)0) {
        do {
            sprintf(d_1c21b4, d_1a9674, ft.name);
            f_149336(d_1c21b4);
        } while ((short)f_1492d1(&ft) == (short)0);
    }
    f_1492ed(&ft);
    sprintf(d_1c21b4, d_1a9678, g_144850(&d_1c2098, 0x90001));
    sprintf(d_1c27a8, d_1a9674, g_144850(&d_1c2098, 0x90001));
    if (f_0b06d0(d_1c21b4, d_1c27a8) == 0)
        f_0ed8f0((int)&d_1c1190, 0x29a000a, d_1c21b4, d_1c27a8);
}
//@ f_1442c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt die zentrale Spielinitialisierung für Grafiktext, Gruppe, Eingabe und
 *   Benutzereinstellungen durch. Sie lädt den Hauptzeichensatz (0x130000), konfiguriert die Standardtextfarben
 *   (255, 253, 249, 252, 231) im Textrenderer (d_1c38b0), setzt den Zeiger der aktiven Heldengruppe (d_1c0004)
 *   auf die Hauptgruppe (d_1bfdbc), initialisiert den Mauszeiger, lädt die Konfigurationsdatei (f_0d78a0 /
 *   f_0d7a20), synchronisiert alle 25 Konfigurationsvariablen der Tabelle d_1a5afc, stellt die Gesamtlautstärke
 *   im Soundmanager (d_1c2edc) ein und startet abschließend das Timer-/Animationssystem (f_120460,
 *   f_01bfb0(45)).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt 1 bei erfolgreicher Initialisierung zurück.
 * - Wichtige Variablen:
 *   - d_1c38b0: Globaler Text- und Font-Renderer, dem der geladene Font aus Ressource 0x130000 zugewiesen wird.
 *   - d_1c0004: Globaler Zeiger auf die aktive Heldengruppe (wird auf &d_1bfdbc gesetzt).
 *   - d_1a5afc: Tabelle mit 25 Konfigurationsdatensätzen (je 12 Byte mit Zielzeiger und Standardwert), die aus
 *     den geladenen Optionen übernommen werden.
 *   - d_1bdbfa: Lautstärkefaktor aus der Konfiguration, der mit 0x147 multipliziert an f_147746 übergeben wird.
 === Ende Beschreibung === */
char f_0ce070(void *p1);
void f_1442c0()
{
    char obj[0x120];
    unsigned short i;
    unsigned short code;
    short factor;
    signed char c;

    d_1a01b4 = 0;
    f_045b70(&d_1c3078, 0x130000);
    f_05e1c0(&d_1c38b0, &d_1c3078);
    f_05e320(&d_1c38b0, 15, 0);
    f_05e2d0(&d_1c38b0, 0, 320, 0, 0);
    f_05e420(&d_1c38b0, 8);
    f_05ded0(&d_1c3068, d_1a34e0);
    f_05e380(&d_1c38b0, 255, 253, 249, 252, 231);
    f_0c0020(&d_1c2c64, 4);
    f_1568bf(-96, -1);
    f_0d3870();
    d_1bc948 = 0;
    d_1c0004 = &d_1bfdbc;
    d_1c002c = f_0ce070(d_1c0004);
    f_0de810(d_1c0004, 25);

    code = d_1c2eb2;
    if (code < (unsigned short)0x3ba) goto common;
    if (code <= (unsigned short)0x3ba) goto case_ba;
    if (code <= (unsigned short)0x3bb) goto case_bb;
    if (code == (unsigned short)0x3bc) goto case_bc;
    common:
    f_0d3df6(&d_1c2e78);
    f_0d78a0(obj);
    if (!f_0d7a20(obj)) {
        d_1bfb24 = f_0ce200();
        d_1bfb10 = d_1bfb14 = 1;
    }
    c = d_1bfb10;
    if (c == 1) {
        if (d_1c3908 != 0) {
            c = d_1bfb24;
            if (c > 35) goto no10;
        }
        d_1bfb10 = 0;
    }
no10:
    c = d_1bfb14;
    if (c == 1 && d_1c3908 == 0)
        d_1bfb14 = 0;
    goto loop_start;
    case_ba: f_0ed8f0(&d_1c1190, 0x29a000b); goto common;
    case_bb: f_0ed8f0(&d_1c1190, 0x29a000c); goto common;
    case_bc: f_0ed8f0(&d_1c1190, 0x29a000d); goto common;
loop_start:
    for (i = 0; (short)i < (short)25; ++i) {
        if (d_1a5afc[(short)i].p == &d_1bfb10)
            d_1a5afc[(short)i].v = d_1bfb10;
        else if (d_1a5afc[(short)i].p == &d_1bfb14)
            d_1a5afc[(short)i].v = d_1bfb14;
        else if (d_1a5afc[(short)i].p == &d_1bfb24)
            d_1a5afc[(short)i].v = d_1bfb24;
        else if (d_1a5afc[(short)i].p == &d_1bfb20)
            d_1a5afc[(short)i].v = d_1c3908;
    }
    d_1bfb2c = 0;
    f_0d7be0(obj, 0);
    f_0d78b0(obj);
    { signed char c = d_1bfae4; factor = c; }
    f_147746(&d_1c2edc, (unsigned short)(factor * 0x147));
    f_120460();
    f_01bfb0(45);
}
//@ f_144570
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fährt vor dem Verlassen des Spiels die aktiven Subsysteme für Maus, Grafik, Soundeffekte,
 *   CD-/Hintergrundmusik und Timer geordnet herunter. Sie blendet den Mauszeiger aus (f_0d2710), beendet das
 *   Grafik-/Maussystem (f_0d4070), stoppt alle laufenden digitalen Soundkanäle (f_147aad), schließt das
 *   Musik-/Audiosystem (f_11fbe0, f_01e0c0, f_01bf80) und stellt den Systemzustand über f_149dfe wieder her.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c2edc: Globale Instanz des HMI-SOS-Soundmanagers, auf der f_147aad zum Stoppen aller Samples aufgerufen
 *     wird.
 === Ende Beschreibung === */
void f_144570()
{
    f_0d2710();
    f_0d4070(&d_1c2e78);
    f_147aad(&d_1c2edc);
    f_11fbe0();
    if (d_1bc760 != 0) f_01e0c0();
    f_01bf80();
    f_149dfe(d_1c2a78);
}
//@ f_1445c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dient als Konstruktor-Wrapper zur Initialisierung eines virtuellen RAM-Disk-Dateisystems
 *   (virtdisk) ohne feste Größenbegrenzung, indem f_13fa90 mit dem Grenzwert 0 aufgerufen wird.
 * - Eingaben:
 *   - p1: Zeiger auf die zu initialisierende virtdisk-Instanz.
 * - Rückgabewert: Gibt den initialisierten Objektzeiger aus f_13fa90 zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445c0(int p1) { f_13fa90(p1, 0); }
//@ f_1445d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert das globale ALF-Archiv-Treiberobjekt, indem der Konstruktor f_04fe30 mit dem
 *   Standardmodus 1 aufgerufen wird.
 * - Eingaben: p1 (Zeiger auf das ALF-Treiberobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445d0(int p1) ;
//@ f_1445e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert ein Verzeichnis-Dateisystemobjekt (für das TEMP- bzw. VIRT-Verzeichnis),
 *   indem der Konstruktor f_0d3a30 mit den Standardparametern -1 und 1 aufgerufen wird.
 * - Eingaben: p1 (Zeiger auf das Verzeichnis-Treiberobjekt).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445e0(int p1) ;
//@ f_144600
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion (Stub), die ohne eigene Aktion sofort 0 zurückgibt.
 * - Eingaben: Keine Parameter (void).
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_144600() ;
//@ f_144610
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor des zentralen Dateimanagers (RivaFileManager), der die virtuelle
 *   Methodentabelle d_1bbf24 einträgt, den Zeiger auf das aktuell aktive Gerät cur mit 0 initialisiert und die
 *   vier übergebenen Backend-Treiber (real, alf, virt, temp) speichert.
 * - Eingaben: this (RivaFileManager *), p2 (real-Treiber), p3 (alf-Treiber), p4 (virt-Treiber), p5
 *   (temp-Treiber).
 * - Rückgabewert: Gibt den initialisierten this-Zeiger zurück.
 * - Wichtige Variablen: vt, cur, real, alf, virt, temp.
 === Ende Beschreibung === */
RivaFileManager *RivaFileManager::f_144610(RivaFileDevice *p2, RivaFileDevice *p3, RivaFileDevice *p4, RivaFileDevice *p5)
;
//@ f_144630
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet das aktive Dateigerät cur des Dateimanagers auf den virtuellen
 *   Speicher-/Verzeichnistreiber virt um und verknüpft ihn über die virtuelle Methode s22(p2) mit dem
 *   unterliegenden Basisgerät p2.
 * - Eingaben: this (RivaFileManager *), p2 (RivaFileDevice *, Basisgerät real oder alf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: virt (virtueller Dateitreiber), cur (aktives Gerät).
 === Ende Beschreibung === */
void RivaFileManager::f_144630(RivaFileDevice *p2)
;
//@ f_144670
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet das aktive Dateigerät cur des Dateimanagers auf den temporären Verzeichnistreiber
 *   temp um und verknüpft ihn über s22(p2) mit dem unterliegenden Basisgerät p2.
 * - Eingaben: this (RivaFileManager *), p2 (RivaFileDevice *, Basisgerät real oder alf).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: temp (TEMP-Dateitreiber), cur (aktives Gerät).
 === Ende Beschreibung === */
void RivaFileManager::f_144670(RivaFileDevice *p2)
;
//@ f_1446b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wertet die oberen Steuerbits einer Ressourcen-ID p2 aus (Bit 31 = virt, Bit 30 = temp),
 *   maskiert sie mit 0x3fffffff aus und wählt anhand der oberen 16 Bits ((p2 & 0xffff0000) == 0 -> lose Datei
 *   über real, sonst Archivressource über alf) sowie der Flags v/t den zuständigen Backend-Treiber in cur aus.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID mit Steuerbits).
 * - Rückgabewert: Die um die Steuerbits 30 und 31 bereinigte Ressourcen-ID (p2 & 0x3fffffff).
 * - Wichtige Variablen: v (Bit 31), t (Bit 30), cur, real, alf.
 === Ende Beschreibung === */
int RivaFileManager::f_1446b0(unsigned p2)
;
//@ f_144820
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateigerät cur gesetzt ist, und ruft darauf die virtuelle Methode
 *   s1() auf.
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur (aktives Dateigerät).
 === Ende Beschreibung === */
void RivaFileManager::f_144820()
;
//@ f_144850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das für die Ressourcen-ID p2 zuständige Dateigerät cur aus und
 *   gibt über dessen virtuelle Methode s2(r) den zugehörigen Dateinamen zurück.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID).
 * - Rückgabewert: Zeiger auf den Dateinamen-String (char *).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
char * RivaFileManager::f_144850(unsigned p2)
;
//@ f_144870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das für p2 zuständige Dateigerät cur aus und prüft über
 *   cur->s3(r), ob die Ressource existiert.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID).
 * - Rückgabewert: Rückgabewert von cur->s3(r) (1 = vorhanden, 0 = nicht vorhanden).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144870(unsigned p2)
;
//@ f_144890
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateigerät cur aus und legt die Ressource r über
 *   cur->s4(r) neu an.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144890(unsigned p2)
;
//@ f_1448b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateigerät cur aus und öffnet die Ressource r im
 *   Modus (short)p3 über cur->s5(r, (short)p3).
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID), p3 (Öffnungsmodus).
 * - Rückgabewert: Status des Öffnens (int).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448b0(unsigned p2, int p3)
;
//@ f_1448d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateigerät cur aus und liest die gesamte Ressource
 *   r über cur->s6(r, buffer) in den Zielpuffer buffer ein.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID), buffer (Zielpuffer void *).
 * - Rückgabewert: Status bzw. gelesene Byteanzahl von cur->s6(r, buffer).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448d0(unsigned p2, void *buffer)
;
//@ f_1448f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den gesamten Inhalt der bereits auf dem aktiven Gerät cur geöffneten Datei über
 *   cur->s7(p2) in den Puffer p2 ein.
 * - Eingaben: this (RivaFileManager *), p2 (Zielpufferadresse).
 * - Rückgabewert: Rückgabewert von cur->s7(p2).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448f0(int p2)
;
//@ f_144920
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest p3 Bytes aus der aktuell auf cur geöffneten Datei über cur->s8(p2, p3) in den
 *   Zielpuffer p2.
 * - Eingaben: this (RivaFileManager *), p2 (Zielpuffer void *), p3 (Byteanzahl).
 * - Rückgabewert: Anzahl der gelesenen Bytes (unsigned).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
unsigned RivaFileManager::f_144920(void *p2, int p3)
;
//@ f_144960
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schreibt p3 Bytes aus dem Puffer p2 über cur->s9(p2, p3) in die aktuell auf cur geöffnete
 *   Datei.
 * - Eingaben: this (RivaFileManager *), p2 (Quellpuffer void *), p3 (Byteanzahl).
 * - Rückgabewert: Anzahl der geschriebenen Bytes (unsigned).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
unsigned RivaFileManager::f_144960(void *p2, int p3)
;
//@ f_1449a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schließt die aktuell auf dem Gerät cur geöffnete Datei über cur->s10().
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Statuscode von cur->s10() (int).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1449a0()
;
//@ f_1449d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Status des aktiven Dateigeräts cur über die virtuelle Methode cur->s11() zurück.
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
void RivaFileManager::f_1449d0()
;
//@ f_144a00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt über cur->s12() die Dateigröße der aktuell auf cur geöffneten Ressource ab.
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Dateigröße in Bytes (long).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
long RivaFileManager::f_144a00()
;
//@ f_144a30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das für p2 zuständige Dateigerät cur aus und ermittelt über
 *   cur->s13(r) die Größe der Ressource r.
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID).
 * - Rückgabewert: Größe der Ressource in Bytes (long).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
long RivaFileManager::f_144a30(unsigned p2)
;
//@ f_144a50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ändert die Dateigröße der aktuell auf cur geöffneten Datei über cur->s14(p2) auf p2 Bytes.
 * - Eingaben: this (RivaFileManager *), p2 (neue Dateigröße).
 * - Rückgabewert: Statuswert von cur->s14(p2) (int).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144a50(int p2)
;
//@ f_144a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt über cur->s15() die aktuelle Lese-/Schreibposition innerhalb der geöffneten Datei
 *   zurück.
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Aktueller Dateioffset (long).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
long RivaFileManager::f_144a80()
;
//@ f_144ab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Positioniert den Dateizeiger der aktuell auf cur geöffneten Datei über cur->s16(p2,
 *   (short)p3) auf den Offset p2 im Modus p3.
 * - Eingaben: this (RivaFileManager *), p2 (Offset), p3 (Seek-Modus).
 * - Rückgabewert: Neue Dateizeigerposition (int).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144ab0(int p2, int p3)
;
//@ f_144af0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateigerät cur aus und löscht die Ressource r über
 *   cur->s17(r).
 * - Eingaben: this (RivaFileManager *), p2 (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144af0(unsigned p2)
;
//@ f_144b10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft auf dem aktiven Dateigerät cur die virtuelle Pfad-/Statusmethode cur->s18() auf.
 * - Eingaben: this (RivaFileManager *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144b10()
;
//@ f_144b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt auf dem aktiven Dateigerät cur über cur->s19(p2) den Arbeitsverzeichnispfad oder
 *   Steuerparameter p2.
 * - Eingaben: this (RivaFileManager *), p2 (Pfad-Zeiger / Parameter).
 * - Rückgabewert: Rückgabewert von cur->s19(p2) (int).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144b40(int p2)
;
//@ f_144b70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fügt in der aktuell auf cur geöffneten Datei am Offset p2 einen Datenblock p3 der Länge p4
 *   über die virtuelle Methode cur->s20(p2, p3, p4) ein.
 * - Eingaben: this (RivaFileManager *), p2 (Einfügeoffset), p3 (Quellpuffer void *), p4 (Byteanzahl).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: q3 (Kopie von p3), cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144b70(int p2, void *p3, int p4)
;
//@ f_144bb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schneidet aus der aktuell auf cur geöffneten Datei ab Offset p2 einen Bereich der Länge p3
 *   über cur->s21(p2, p3) heraus.
 * - Eingaben: this (RivaFileManager *), p2 (Startoffset), p3 (Anzahl der zu entfernenden Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144bb0(int p2, int p3)
;
