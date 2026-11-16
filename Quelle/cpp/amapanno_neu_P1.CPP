/* === Beschreibung (Katalog) ===
 * Einheit amapanno_neu (0x01A880-0x01A9B0)
 *
 * Überblick
 * Die Einheit amapanno_neu (Ausschnitt aus amapanno.cpp) verwaltet das Laden und erstmalige Anlegen der
 * Kartenanmerkungs-Datei ("ANNO", bis zu 500 Spielernotizen auf der Automap).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 01a880-01a9b0 aus Quelle/cpp/AMAPANNO.CPP; erster Entwurf, Einbau separat prüfen.
// amapanno.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x01A880-0x01A9B0. Kartenanmerkungen: Kopf (0x12 Bytes) und bis zu 500 EintrÃ¤ge laden, Datei bei Bedarf anlegen.
// Die Kennung "ANNO" (Zeiger d_1a048c) liegt noch im Assembler-DatenstÃ¼ck.
#include <string.h>
extern const char d_1a046c[];
#define amapanno_file d_1a046c
extern char *d_1a048c;                                   // -> "ANNO"
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0

extern RivaFileManager d_1c2098;
struct AnnoHdr {                                         // 0x12 Bytes
    char  magic[4];
    short a;                                             // +0x04
    short b;                                             // +0x06
    short n;                                             // +0x08 Anzahl
    long  ofs;                                           // +0x0A
    long  end;                                           // +0x0E
};
struct AnnoEntry { char b[12]; };
struct AMapAnno {
    unsigned long fileid;                                // +0x00
    AnnoHdr *hdr;                                        // +0x04
    AnnoEntry *ent;                                      // +0x08
    void f_01a880();
};
//@ f_01a880
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Lädt die Kartenanmerkungen (AMapAnno) zur Datei-ID this->fileid. Reserviert zunächst den
 *   0x12 Bytes großen Dateikopf this->hdr (AnnoHdr) und das Array this->ent für bis zu 500 Einträge zu je 12
 *   Bytes (AnnoEntry[500]). Existiert die Datei im Dateimanager d_1c2098 noch nicht (f_144870(fileid) == 0),
 *   legt die Funktion sie neu an und schreibt einen leeren "ANNO"-Kopf (n = 0). Anschließend öffnet sie die
 *   Datei, liest den Kopf hdr ein und lädt - falls bereits Anmerkungen vorhanden sind (hdr->n > 0) - ab
 *   Dateioffset hdr->ofs alle hdr->n Einträge in das Array ent.
 * - Eingaben: this (AMapAnno *, mit fileid auf Offset +0x00).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->fileid (unsigned long): Ressourcen-/Datei-ID der Anmerkungsdatei der aktuellen Karte.
 *   - this->hdr (AnnoHdr *): Zeiger auf den 0x12-Byte-Dateikopf (magic = "ANNO", n = Anzahl der Einträge, ofs =
 *     Dateioffset der Eintragsliste, end = Dateiende).
 *   - this->ent (AnnoEntry *): Array für bis zu 500 Anmerkungseinträge zu je 12 Bytes.
 *   - d_1c2098 (RivaFileManager): Globaler Dateimanager.
 === Ende Beschreibung === */
void AMapAnno::f_01a880()
{
    hdr = new (mark(amapanno_file, 68)) AnnoHdr;
    ent = new (mark(amapanno_file, 69)) AnnoEntry[500];
    if (d_1c2098.f_144870(fileid) == 0) {
        *(long *)hdr->magic = *(long *)d_1a048c;
        hdr->a = 0;
        hdr->b = 1;
        hdr->n = 0;
        d_1c2098.f_144890(fileid);
        d_1c2098.f_144960(hdr, sizeof(AnnoHdr));
        d_1c2098.f_1449a0();
    }
    d_1c2098.f_1448b0(fileid, 0x200);
    d_1c2098.f_144920(hdr, sizeof(AnnoHdr));
    AnnoHdr *h = hdr;
    if (h->n > 0) {
        d_1c2098.f_144ab0(h->ofs, 0);
        d_1c2098.f_144920(ent, hdr->n * sizeof(AnnoEntry));
    } else {
        h->end = sizeof(AnnoHdr);
        hdr->ofs = h->end;
    }
    d_1c2098.f_1449a0();
}
