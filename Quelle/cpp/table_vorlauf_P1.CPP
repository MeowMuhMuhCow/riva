/* === Beschreibung (Katalog) ===
 * Einheit table_vorlauf (0x11EA00 - 0x11EAE0)
 *
 * Überblick
 * Die Einheit table_vorlauf enthält zwei Funktionen (f_11ea00 und f_11ea90) zum Lesen und Schreiben einzelner
 * Datensätze fester Größe aus bzw. in Archivtabellen der Formate "ARR" und "LST" über den RivaFileManager
 * (d_1c2098).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 11ea00-11eae0 aus Quelle/cpp/TABLE.CPP; erster Entwurf, Einbau separat prüfen.
// table.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Welle 1
// Code 0x11EA00-0x11EBB5 (f_11ebc0 noch Assembler, Entwurf unten, Stapelbelegung offen). Tabellen aus Archivdateien lesen/schreiben (Formate "ARR" und "LST").
// Namen f_/d_<Adresse> bis Phase 6. Texte und Globale bis Phase 2 extern im gemeinsamen Datenobjekt.
#include <string.h>

void *mark(const char *file, int line);                 // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0


extern RivaFileManager d_1c2098;
extern const char d_1a7eb8[];                            // "p:\riva\source\cpp\table.cpp"
extern const char d_1b8368[];                            // "ARR"
extern const char d_1b836c[];                            // "LST"

int f_11ebc0(int a, short idx, int size);

//@ f_11ea00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Tabellen-Archivdatei id (für die drei Sonderdateien 0x220009, 0x220011 und
 *   0x22000a unverändert, für alle anderen mit gesetztem Bit 0x40000000) im Lesemodus (0x200), positioniert den
 *   Dateizeiger über f_11ebc0(a, idx, size) auf den Datensatz idx und liest bei Erfolg size Bytes in buf ein;
 *   existiert der Eintrag nicht, wird buf per memset mit Nullen gefüllt.
 * - Eingaben: a (Zeiger auf die Tabellen-Instanz), id (32-Bit-Ressourcen-ID der Tabellendatei), idx
 *   (Datensatzindex), buf (Zielpuffer), size (Größe des Datensatzes in Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c2098: Globale Instanz des RivaFileManager.
 === Ende Beschreibung === */
void f_11ea00(int a, unsigned long id, short idx, void *buf, int size)
{
    if (id == 0x220009 || id == 0x220011 || id == 0x22000a) d_1c2098.f_1448b0(id, 0x200);
    else d_1c2098.f_1448b0(id | 0x40000000, 0x200);
    if (f_11ebc0(a, idx, size) == 1) d_1c2098.f_144920(buf, size);
    else memset(buf, 0, size);
    d_1c2098.f_1449a0();
}

//@ f_11ea90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Tabellen-Archivdatei id | 0x40000000 im Schreibmodus (2), positioniert über
 *   f_11ebc0(a, idx, size) auf den Datensatz idx und schreibt bei Erfolg size Bytes aus buf über f_144960 in die
 *   Datei.
 * - Eingaben: a (Zeiger auf die Tabellen-Instanz), id (32-Bit-Ressourcen-ID), idx (Datensatzindex), buf
 *   (Quellpuffer), size (Größe des Datensatzes in Bytes).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c2098: Globale Instanz des RivaFileManager.
 === Ende Beschreibung === */
void f_11ea90(int a, unsigned long id, short idx, void *buf, int size)
{
    d_1c2098.f_1448b0(id | 0x40000000, 2);
    if (f_11ebc0(a, idx, size) == 1) d_1c2098.f_144960(buf, size);
    d_1c2098.f_1449a0();
}

int f_11eae0(int a, unsigned long id);


