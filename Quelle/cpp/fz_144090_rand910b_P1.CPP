/* === Beschreibung (Katalog) ===
 * Einheit fz_144090_rand910b (0x1445D0 - 0x144BE1)
 *
 * Überblick
 * Diese Einheit implementiert den zentralen Dateimanager (RivaFileManager, file.cpp), der im Spiel über die
 * globale Instanz d_1c2098 angesprochen wird. Er abstrahiert sämtliche Dateizugriffe über eine virtuelle
 * Methodentabelle und entscheidet anhand der oberen Bits einer 32-Bit-Ressourcen-ID automatisch, welches
 * untergeordnete Dateisystem zuständig ist:
 * - Bit 31 gesetzt (0x80000000): Virtuelle RAM-Disk (virt, Offset +0x08).
 * - Bit 30 gesetzt (0x40000000): Temporäres Spielstandsverzeichnis (temp, Offset +0x0c).
 * - Obere 16 Bit gleich 0 ((id & 0xFFFF0000) == 0): Direkte Datei im Arbeitsverzeichnis (real, Offset +0x10).
 * - Alle übrigen IDs: Gepacktes .ALF-Archiv (alf, Offset +0x04).
 *
 * Zusätzlich befinden sich am Anfang der Einheit drei kleine Hilfs- und Initialisierungsfunktionen (f_1445d0,
 * f_1445e0, f_144600).
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
 *   angelegten globalen Puffer, Grafikpaletten und Hilfsobjekte wieder frei (d_1bc8f0, d_1bc8f8, f_0a7d00,
 *   d_1bdbe4, d_1bdbe8, d_1be17c, d_1c2c44).
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1bc8f0, d_1bc8f8, d_1bdbe4, d_1bdbe8, d_1be17c, d_1c2c44.
 === Ende Beschreibung === */
void f_144090()
;
//@ f_144110
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Richtet beim Spielstart das Verzeichnis für temporäre Spieldateien (TEMP, d_1a97a4) ein,
 *   löscht darin alle verwaisten temporären Dateien aus einer früheren Sitzung und kopiert anschließend die
 *   initiale Spielstandsdatei (0x90001) über f_0b06d0 in den temporären Arbeitsbereich.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: s / info (FT), buf (Pfadpuffer).
 === Ende Beschreibung === */
#pragma aux f_144110 modify exact [eax]
int f_0ed8f0(int p1, ...);
int f_1492b4(char *p1, int p2, FT *p3);
int f_1492d1(FT *p1);
int f_1492ed(FT *p1);
char *g_144850(RivaFileManager *p1, unsigned p2);
#pragma aux g_144850 "f_144850"
void f_144110()
;
//@ f_1442c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Führt die zentrale Spielinitialisierung für Grafiktext (0x130000, d_1c38b0), aktive
 *   Heldengruppe (d_1c0004 = &d_1bfdbc), Mauszeiger, Konfigurationsdatei (d_1a5afc), Gesamtlautstärke (d_1c2edc)
 *   und Timer-/Animationssystem (f_120460, f_01bfb0(45)) durch.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void) bzw. 1 bei Erfolg.
 * - Wichtige Variablen: d_1c38b0, d_1c0004, d_1a5afc, d_1c2edc.
 === Ende Beschreibung === */
char f_0ce070(void *p1);
void f_1442c0()
;
//@ f_144570
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fährt vor dem Verlassen des Spiels die aktiven Subsysteme für Maus (f_0d2710, f_0d4070),
 *   Soundeffekte (f_147aad), Hintergrundmusik (f_11fbe0, f_01e0c0, f_01bf80) und Timer (f_149dfe) geordnet
 *   herunter.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c2edc.
 === Ende Beschreibung === */
void f_144570()
;
//@ f_1445c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dient als Konstruktor-Wrapper zur Initialisierung eines virtuellen RAM-Disk-Dateisystems
 *   (virtdisk) ohne feste Größenbegrenzung, indem f_13fa90(p1, 0) aufgerufen wird.
 * - Eingaben: p1 (Zeiger auf die virtdisk-Instanz).
 * - Rückgabewert: Gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445c0(int p1) ;
//@ f_1445d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert ein ALF-Archiv-Treiberobjekt, indem der Konstruktor f_04fe30 mit dem
 *   Standardmodus 1 aufgerufen wird.
 * - Eingaben: p1 (Zeiger auf das ALF-Treiberobjekt).
 * - Rückgabewert: Gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445d0(int p1) { f_04fe30(p1, 1); }
//@ f_1445e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Initialisiert ein Dateisystemobjekt für ein Unterverzeichnis (insbesondere das
 *   TEMP-Verzeichnis), indem f_0d3a30 mit den Standardparametern -1 und 1 aufgerufen wird.
 * - Eingaben: p1 (Zeiger auf das Verzeichnis-Treiberobjekt).
 * - Rückgabewert: Gibt den initialisierten Objektzeiger zurück.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_1445e0(int p1) { f_0d3a30(p1, -1, 1); }
//@ f_144600
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion (Stub), die ohne Aktion sofort 0 zurückgibt.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Immer 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_144600() { return 0; }
//@ f_144610
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor der Basisklasse für Dateisystemtreiber (RivaFileBase), der den Zeiger auf die
 *   virtuelle Methodentabelle (d_1a97c8) im Objekt einträgt.
 * - Eingaben: p1 (Zeiger auf das Dateisystemobjekt).
 * - Rückgabewert: Gibt p1 zurück.
 * - Wichtige Variablen: vptr (Zeiger auf die virtuelle Methodentabelle am Offset +0x00).
 === Ende Beschreibung === */
RivaFileManager *RivaFileManager::f_144610(RivaFileDevice *p2, RivaFileDevice *p3, RivaFileDevice *p4, RivaFileDevice *p5)
{
    vt = &d_1bbf24;
    cur = 0;
    real = p2;
    alf = p3;
    virt = p4;
    temp = p5;
    return this;
}
//@ f_144630
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt im Dateimanager (RivaFileManager) das virtuelle RAM-Disk-Dateisystem (virt) als
 *   aktives Gerät (cur) aus, prüft dessen Vorhandensein und verknüpft es über cur->s22(p2) mit dem
 *   untergeordneten Basis-Gerät p2 (real oder alf).
 * - Eingaben: this (Dateimanager), p2 (Basis-Dateisystemtreiber RivaFileDevice *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: virt, cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144630(RivaFileDevice *p2)
{
    if (!virt) f_1664d0(d_1b87cc, d_1a97ac, 0x1f);
    cur = virt;
    cur->s22(p2);
}
//@ f_144670
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt im Dateimanager (RivaFileManager) das temporäre Spielstands-Dateisystem (temp) als
 *   aktives Gerät (cur) aus, prüft dessen Vorhandensein und verknüpft es über cur->s22(p2) mit dem Basis-Gerät
 *   p2 (real oder alf).
 * - Eingaben: this (Dateimanager), p2 (Basis-Dateisystemtreiber RivaFileDevice *).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: temp, cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144670(RivaFileDevice *p2)
{
    if (!temp) f_1664d0(d_1b87e0, d_1a97ac, 0x28);
    cur = temp;
    cur->s22(p2);
}
//@ f_1446b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wertet die oberen Steuerbits (0x80000000 für virt, 0x40000000 für temp) sowie die oberen
 *   16 Bit (== 0 für real, sonst alf) einer Ressourcen-ID p2 aus, setzt den Zeiger cur im Dateimanager auf das
 *   zuständige Dateisystemgerät und gibt die um die beiden obersten Bits bereinigte Ressourcen-ID (p2 &
 *   0x3fffffff) zurück.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID inklusive Orts-Flags).
 * - Rückgabewert: Bereinigte 30-Bit-Ressourcen-ID (int).
 * - Wichtige Variablen: v (RAM-Disk-Flag), t (Temp-Flag), cur (ausgewähltes Gerät).
 === Ende Beschreibung === */
int RivaFileManager::f_1446b0(unsigned p2)
{
    int v = (p2 & 0x80000000) != 0;
    int t = (p2 & 0x40000000) != 0;
    p2 &= 0x3fffffff;
    if ((p2 & 0xffff0000) == 0) {
        if (!real) f_1664d0(d_1b87f6, d_1a97ac, 0x3c);
        if (v == 1) f_144630(real);
        else if (t == 1) f_144670(real);
        else cur = real;
    } else {
        if (!alf) f_1664d0(d_1b8807, d_1a97ac, 0x4d);
        if (v == 1) f_144630(alf);
        else if (t == 1) f_144670(alf);
        else cur = alf;
    }
    return p2;
}
//@ f_144820
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob im Dateimanager ein aktives Gerät cur ausgewählt ist, und ruft auf diesem die
 *   virtuelle Methode s1() auf.
 * - Eingaben: this (Dateimanager).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144820()
{
    if (!cur) f_1664d0(d_1b8817, d_1a97ac, 98);
    cur->s1();
}
//@ f_144850
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das für die Ressourcen-ID p2 zuständige Dateisystemgerät cur aus
 *   und ruft dessen virtuelle Methode s2(r) (z. B. zur Ermittlung des Dateinamens/Pfads) auf.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Zeiger auf die vom Backend gelieferte Zeichenkette (char *).
 * - Wichtige Variablen: r (bereinigte Ressourcen-ID), cur.
 === Ende Beschreibung === */
char * RivaFileManager::f_144850(unsigned p2)
{
    int r = f_1446b0(p2);
    return cur->s2(r);
}
//@ f_144870
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateisystemgerät cur aus und prüft über dessen
 *   virtuelle Methode s3(r) das Vorhandensein bzw. den Status der Ressource p2.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Statuswert von cur->s3(r).
 * - Wichtige Variablen: r, cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144870(unsigned p2)
{
    int r = f_1446b0(p2);
    return cur->s3(r);
}
//@ f_144890
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateisystemgerät cur aus und führt für die
 *   Ressource p2 die virtuelle Methode s4(r) (z. B. Löschen der Ressource) aus.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: r, cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144890(unsigned p2)
{
    int r = f_1446b0(p2);
    cur->s4(r);
}
//@ f_1448b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateisystemgerät cur aus und öffnet die Ressource
 *   p2 über die virtuelle Methode cur->s5(r, (short)p3) im Zugriffsmodus p3.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID), p3 (Öffnungsmodus).
 * - Rückgabewert: Status- oder Handle-Wert von cur->s5.
 * - Wichtige Variablen: r, cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448b0(unsigned p2, int p3)
{
    int r = f_1446b0(p2);
    return cur->s5(r, (short)p3);
}
//@ f_1448d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das zuständige Dateisystemgerät cur aus und lädt die Ressource p2
 *   über cur->s6(r, buffer) in den Puffer buffer.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID), buffer (Zielpuffer).
 * - Rückgabewert: Rückgabewert von cur->s6.
 * - Wichtige Variablen: r, cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448d0(unsigned p2, void *buffer)
{
    int r = f_1446b0(p2);
    return cur->s6(r, buffer);
}
//@ f_1448f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und leitet den Aufruf s7(p2) an
 *   dieses weiter.
 * - Eingaben: this (Dateimanager), p2 (Parameter für s7).
 * - Rückgabewert: Rückgabewert von cur->s7(p2).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1448f0(int p2)
{
    if (!cur) f_1664d0(d_1b8824, d_1a97ac, 140);
    return cur->s7(p2);
}
//@ f_144920
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur ausgewählt ist, und liest über dessen virtuelle
 *   Methode s8(p2, p3) bis zu p3 Bytes in den Puffer p2 ein.
 * - Eingaben: this (Dateimanager), p2 (Zielpuffer), p3 (Byte-Anzahl).
 * - Rückgabewert: Anzahl der gelesenen Bytes (unsigned).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
unsigned RivaFileManager::f_144920(void *p2, int p3)
{
    if (!cur) f_1664d0(d_1b8831, d_1a97ac, 147);
    return cur->s8(p2, p3);
}
//@ f_144960
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft die Existenz oder den Status einer Ressource p2 (virtuelle Methode s5) über das
 *   zuständige Backend-Dateisystem.
 * - Eingaben: p1 (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Statuswert des Backends (s5).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
unsigned RivaFileManager::f_144960(void *p2, int p3)
{
    if (!cur) f_1664d0(d_1b883e, d_1a97ac, 154);
    return cur->s9(p2, p3);
}
//@ f_1449a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und ruft dessen virtuelle Methode
 *   s10() (Schließen der aktuell geöffneten Ressource) auf.
 * - Eingaben: this (Dateimanager).
 * - Rückgabewert: Rückgabewert von cur->s10().
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_1449a0()
{
    if (!cur) f_1664d0(d_1b884b, d_1a97ac, 161);
    return cur->s10();
}
//@ f_1449d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und ruft dessen virtuelle Methode
 *   s11() auf.
 * - Eingaben: this (Dateimanager).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
void RivaFileManager::f_1449d0()
{
    if (!cur) f_1664d0(d_1b8858, d_1a97ac, 168);
    cur->s11();
}
//@ f_144a00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und gibt über dessen virtuelle
 *   Methode s12() die Größe der aktuell geöffneten Datei zurück.
 * - Eingaben: this (Dateimanager).
 * - Rückgabewert: Dateigröße in Bytes (long).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
long RivaFileManager::f_144a00()
{
    if (!cur) f_1664d0(d_1b8865, d_1a97ac, 175);
    return cur->s12();
}
//@ f_144a30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest einen Teilbereich von p4 Bytes ab Dateioffset p3 aus der aktuell geöffneten
 *   Ressource in den Puffer p5 (virtuelle Methode s7), weitergeleitet an das zuständige Backend.
 * - Eingaben: p1 (Dateimanager), p2 (Ressourcen-ID / Kontext), p3 (Byte-Offset), p4 (Byte-Anzahl), p5
 *   (Zielpuffer).
 * - Rückgabewert: Anzahl der gelesenen Bytes.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
long RivaFileManager::f_144a30(unsigned p2)
{
    int r = f_1446b0(p2);
    return cur->s13(r);
}
//@ f_144a50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest p3 Bytes ab der aktuellen Dateiposition in den Puffer p4 (virtuelle Methode s8) über
 *   das zuständige Backend.
 * - Eingaben: p1 (Dateimanager), p2 (Ressourcen-ID / Kontext), p3 (Byte-Anzahl), p4 (Zielpuffer).
 * - Rückgabewert: Anzahl der gelesenen Bytes.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int RivaFileManager::f_144a50(int p2)
{
    if (!cur) f_1664d0(d_1b8872, d_1a97ac, 189);
    return cur->s14(p2);
}
//@ f_144a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und fragt über dessen virtuelle
 *   Methode s15() die aktuelle Dateiposition (tell) ab.
 * - Eingaben: this (Dateimanager).
 * - Rückgabewert: Aktueller Dateioffset (long).
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
long RivaFileManager::f_144a80()
{
    if (!cur) f_1664d0(d_1b887f, d_1a97ac, 196);
    return cur->s15();
}
//@ f_144ab0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob ein aktives Dateisystemgerät cur gesetzt ist, und positioniert den Dateizeiger
 *   über cur->s16(p2, (short)p3) (seek) auf Offset p2 im Modus p3.
 * - Eingaben: this (Dateimanager), p2 (Byte-Offset), p3 (Seek-Ursprung).
 * - Rückgabewert: Rückgabewert von cur->s16.
 * - Wichtige Variablen: cur.
 === Ende Beschreibung === */
int RivaFileManager::f_144ab0(int p2, int p3)
{
    if (!cur) f_1664d0(d_1b888c, d_1a97ac, 0xcb);
    return cur->s16(p2, (short)p3);
}
//@ f_144af0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt über f_1446b0(p2) das für die Ressourcen-ID p2 zuständige Dateisystemgerät cur aus
 *   und führt darauf die virtuelle Operation cur->s17(r) aus.
 * - Eingaben: this (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: r, cur.
 === Ende Beschreibung === */
void RivaFileManager::f_144af0(unsigned p2)
{
    int r = f_1446b0(p2);
    cur->s17(r);
}
//@ f_144b10
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Positioniert den Dateizeiger oder führt die Schreib-/Steueroperation s13 mit Wert p3 auf
 *   dem Backend aus.
 * - Eingaben: p1 (Dateimanager), p2 (Kontext), p3 (Offset/Wert).
 * - Rückgabewert: Rückgabewert von s13.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void RivaFileManager::f_144b10()
{
    if (!cur) f_1664d0(d_1b8899, d_1a97ac, 217);
    cur->s18();
}
//@ f_144b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Entfernt einen Teilbereich von p4 Bytes ab Offset p3 aus einer Ressourcendatei (virtuelle
 *   Methode s15).
 * - Eingaben: p1 (Dateimanager), p2 (Kontext), p3 (Offset), p4 (Länge).
 * - Rückgabewert: Rückgabewert von s15.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int RivaFileManager::f_144b40(int p2)
{
    if (!cur) f_1664d0(d_1b88a6, d_1a97ac, 224);
    return cur->s19(p2);
}
//@ f_144b70
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leitet die Positionierungsoperation s18 (seek auf Offset p3) an das zuständige Backend
 *   weiter.
 * - Eingaben: p1 (Dateimanager), p2 (Kontext), p3 (Zieloffset).
 * - Rückgabewert: Rückgabewert von s18.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void RivaFileManager::f_144b70(int p2, void *p3, int p4)
{
    void *q3 = 0;
    q3 = p3;
    if (*(RivaFileDevice *volatile *)this == 0) f_1664d0(d_1b88b3, d_1a97ac, 231); // volatile erzwingt erneutes Laden von cur vor dem virtuellen Aufruf s20
    cur->s20(p2, q3, p4);
}
//@ f_144bb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wählt anhand der oberen Bits der Ressourcen-ID p2 (0x80000000 -> virt, 0x40000000 -> temp,
 *   obere 16 Bit leer -> real, sonst alf) den zuständigen Backend-Dateisystemtreiber aus dem Dateimanager p1
 *   aus. Diese Hilfsfunktion wird von den Weiterleitungsmethoden s7 bis s21 genutzt.
 * - Eingaben: p1 (Dateimanager), p2 (Ressourcen-ID).
 * - Rückgabewert: Zeiger auf das zuständige Backend-Dateisystemobjekt (RivaFileBase *).
 * - Wichtige Variablen: virt, temp, real, alf (die vier Backend-Zeiger im Dateimanager).
 === Ende Beschreibung === */
void RivaFileManager::f_144bb0(int p2, int p3)
{
    if (!cur) f_1664d0(d_1b88c0, d_1a97ac, 238);
    cur->s21(p2, p3);
}
