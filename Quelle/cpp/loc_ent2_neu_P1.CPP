/* === Beschreibung (Katalog) ===
 * Einheit loc_ent2_neu (0x0B3240 - 0x0B3300)
 *
 * Überblick
 * Die Einheit loc_ent2_neu enthält eine Suchfunktion für Ortsereignisse, die einen 16-Byte-Figurennamen aus
 * einer Archivdatei (0x40220069) einliest und das zugehörige Gruppenmitglied in der aktiven Heldengruppe
 * ermittelt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0b3240-0b3300 aus Quelle/cpp/LOC_ENT2.CPP; erster Entwurf, Einbau separat prüfen.
// loc_ent2.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle
// Code 0x0B3240-0x0B3300. Namen (16 Bytes) aus Archivdatei lesen und den passenden Eintrag im Spielobjekt suchen.
#include <string.h>
extern const char d_1a5234[];
#define loc_ent2_file d_1a5234
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710

extern RivaFileManager d_1c2098;
struct Ent : hero {  };                     // Name des Eintrags
struct Game {
    Ent *f_038c40();                                     // erster Eintrag
    Ent *f_0391b0(Ent *e);                               // nÃ¤chster
    Ent *f_038be0();                                     // Standardeintrag
};
extern Game *d_1c0004;
//@ f_0b3240
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest den 16 Bytes langen internen Namen einer bestimmten Figur (vermutlich eines
 *   Begleiters oder Quest-NSCs) aus der Archivressource 0x40220069, durchläuft anschließend die Ringliste der
 *   Gruppenmitglieder (f_038c40 / f_0391b0) und vergleicht deren internen Namen (f_042320) per strcmp; wird die
 *   gesuchte Figur nicht in der Gruppe gefunden, gibt die Funktion ersatzweise den Gruppenanführer (f_038be0)
 *   zurück.
 * - Eingaben: Keine (verwendet das globale Spielobjekt d_1c0004 und den Dateimanager d_1c2098).
 * - Rückgabewert: Zeiger auf den gefundenen Helden/Begleiter (Ent *) oder auf den Gruppenanführer, falls die
 *   gesuchte Figur nicht in der Gruppe ist.
 * - Wichtige Variablen:
 *   - name: Auf dem Heap reservierter 16-Byte-Puffer mit dem aus 0x40220069 gelesenen Vergleichsnamen.
 *   - e, found: Laufzeiger über die Gruppenmitglieder und Zeiger auf den gefundenen Eintrag.
 === Ende Beschreibung === */
Ent *f_0b3240()
{
    Ent *found = 0;
    Ent *e = d_1c0004->f_038c40();
    char *name = new (mark(loc_ent2_file, 282)) char[16];
    d_1c2098.f_1448b0(0x40220069, 0x200);
    d_1c2098.f_144920(name, 16);
    
    d_1c2098.f_1449a0();
    do {
        if (strcmp(name, ::f_042320((hero *)(e))) == 0) found = e;
        e = d_1c0004->f_0391b0(e);
    } while (e != d_1c0004->f_038c40() && found == 0);
    if (found == 0) found = d_1c0004->f_038be0();
    delete name;
    return found;
}
