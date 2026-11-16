/* === Beschreibung (Katalog) ===
 * Einheit item (0x0A7B60 - 0x0A7D00)
 *
 * Überblick
 * Die Einheit item lädt beim Spielstart die globale Gegenstandsdatenbank (f_0a7b60) aus dem Spielarchiv
 * (Ressourcen 0x50000 für die Gegenstandsnamen und 0x50003 für die 16-Byte-Gegenstandsdatensätze) und baut
 * daraus die zentrale Gegenstandstabelle d_1c2c40 auf.
 === Ende Beschreibung === */
#include "RIVAITBL.H"
#include "RIVAFILE.H"
#include "RIVAITEM.H"
#include "RIVAMEM.H"
// P3 0/1 gleich (suche.py 26.10.2026, Basis item_P1.CPP)
// I9: aus item_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// item.cpp (Schatten ueber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x0A7B60-0x0A7D00. Laedt Namenstabelle (Kapitel 5/0 und 5/3) und baut Eintragsliste auf.
#include <string.h>
extern const char item_file[];   // 0x1A3EB0, Zeichenkette liegt im Original (nicht in dieser Einheit definieren)
extern RivaFileManager d_1c2098;


extern short d_1be258;
extern int d_1be260;
extern char *d_1be264;
extern RivaItemDefinition *d_1be268;

//@ f_0a7b60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Fragt im Dateimanager d_1c2098 die Dateigrößen der Namenstabelle (0x50000) und der
 *   Gegenstandsdatensätze (0x50003) ab, berechnet aus recordBytes >> 4 die Anzahl d_1be260 der Gegenstände im
 *   Spiel, reserviert das Zeigerarray d_1c2c40, das RivaItemDefinition-Array d_1be268 (je 20 Bytes) sowie den
 *   Namenspuffer d_1be264, lädt Namen und Datensätze ein und verknüpft in einer Schleife jeden Eintrag
 *   d_1c2c40[index] mit seinem nullterminierten Namen und seinem 16-Byte-Datensatz RivaItemRecord.
 * - Eingaben: Keine.
 * - Rückgabewert: int - Immer 0.
 * - Wichtige Variablen:
 *   - d_1be260, d_1be258 (Gesamtanzahl der geladenen Gegenstandsdefinitionen).
 *   - d_1c2c40 (Globales Array von Zeigern auf die einzelnen RivaItemDefinition-Einträge).
 *   - d_1be268 (Zusammenhängendes Array der 20-Byte-RivaItemDefinition-Strukturen).
 *   - d_1be264 (Puffer mit allen hintereinanderliegenden, nullterminierten Gegenstandsnamen).
 *   - records (Temporäres Array der 16-Byte-Rohdatensätze RivaItemRecord aus Ressource 0x50003).
 === Ende Beschreibung === */
extern "C" int f_0a7b60();
#pragma aux f_0a7b60 "f_0a7b60" modify exact [eax gs];
extern "C" int f_0a7b60()
{
    char *name; int recordBytes; RivaItemDefinition *entry; int nameBytes; short index; RivaItemRecord *records; int result = 0;
    nameBytes = d_1c2098.f_144a30(0x50000);
    recordBytes = d_1c2098.f_144a30(0x50003);
    if (nameBytes > 0 && recordBytes > 0) {
        d_1be260 = (unsigned)recordBytes >> 4;
        d_1c2c40 = new (mark(item_file, 936)) RivaItemDefinition *[d_1be260];
        d_1be268 = new (mark(item_file, 937)) RivaItemDefinition[d_1be260];
        d_1be264 = new (mark(item_file, 938)) char[nameBytes];
        records = new (mark(item_file, 940)) RivaItemRecord[d_1be260];
        d_1c2098.f_1448d0(0x50000, d_1be264);
        d_1c2098.f_1448d0(0x50003, records);
        name = d_1be264;
        for (index = 0; index < d_1be260; index++) {
            recordBytes = index * 20;
            nameBytes = index * 4;
            entry = (RivaItemDefinition *)((char *)d_1be268 + recordBytes);
            *(RivaItemDefinition **)((char *)d_1c2c40 + nameBytes) = entry;
            (*(RivaItemDefinition **)((char *)d_1c2c40 + nameBytes))->name = name;
            (*(RivaItemDefinition **)((char *)d_1c2c40 + nameBytes))->rec = records[index];
            name = name + strlen(name) + 1;
        }
        delete records;
        (*(volatile short *)&d_1be258) = d_1be260;
    }
    return result;
}
