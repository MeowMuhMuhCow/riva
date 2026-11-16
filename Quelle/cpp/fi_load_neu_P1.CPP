/* === Beschreibung (Katalog) ===
 * Einheit fi_load_neu (0x07A8A0 - 0x07A9E0)
 *
 * Überblick
 * Die Einheit fi_load_neu enthält die Laderoutine Fight::f_07a8a0 des rundenbasierten Kampfsystems, die den
 * jeweiligen Kampfdatensatz (0x26d Bytes) aus der Kampflistendatei (0x80260002) sowie die zugehörige Hindernis-
 * und Aufstellungstabelle (d_1bd948) für den gewählten Kampfschauplatz lädt.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 07a8a0-07a9e0 aus Quelle/cpp/FI_LOAD.CPP; erster Entwurf, Einbau separat prüfen.
// fi_load.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x07A8A0-0x07A9E0. Kampf laden: Kampfdatensatz (0x26D Bytes) und die Tabelle zur Kampfart.
extern const char d_1a1eb4[];
#define fi_load_file d_1a1eb4
void *f_014540(long size, const char *file, int line);   // Speicher mit Herkunft
void operator delete(void *p);                           // 0x014710

extern RivaFileManager d_1c2098;
struct KindEntry { long a; unsigned long file; long c; };   // 12 Bytes, Tabelle in fight.cpp
extern KindEntry d_1a2510[];
struct Res { short f_050710(long id); };
extern Res d_1c2be0;
extern char *d_1bd948;
struct FightRec { char pad[0x14]; signed char kind; };  // 0x26D Bytes in der Datei
struct Fight {
    char pad[0xee7];
    short nr;                                            // +0xEE7
    char pad2[0x1073 - 0xee9];
    FightRec *rec;                                       // +0x1073
    void f_07a8a0();
};
//@ f_07a8a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Kampflistendatei (0x80260002), liest die 16-Bit-Gesamtanzahl cnt der
 *   gespeicherten Kämpfe, begrenzt die angeforderte Kampfnummer this->nr nach oben auf cnt, lädt den 0x26d (621)
 *   Bytes großen Kampfdatensatz ab Dateioffset nr * 0x26d + 2 in this->rec und lädt anschließend anhand der
 *   Kampfart (rec->kind) die passende Schauplatz-Tabelle (d_1a2510[rec->kind].file) in den dynamisch
 *   reservierten Puffer d_1bd948. *(Hinweis: Die Begrenzung if (nr > cnt) nr = cnt; enthält einen mutmaßlichen
 *   Off-by-One-Fehler, da bei cnt Datensätzen mit 0-basiertem Index nr = cnt bereits hinter den letzten gültigen
 *   Datensatz cnt - 1 zeigt; siehe Fehlerliste).*
 * - Eingaben: this (Zeiger auf das Fight-Objekt mit der Kampfnummer this->nr an Offset +0xEE7 und dem Zielpuffer
 *   this->rec an Offset +0x1073).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->nr (+0xEE7): Laufende Nummer des zu ladenden Kampfes.
 *   - this->rec (+0x1073): Zeiger auf den 0x26d Bytes großen Kampfdatensatz (rec->kind an Offset +0x14 bestimmt
 *     den Schauplatz-Typ).
 *   - d_1a2510: Schauplatz-Tabelle mit den Ressourcen-IDs der Grafik- und Aufstellungsdateien je Kampfart.
 *   - d_1bd948: Dynamisch reservierter Puffer für die (Anzahl + 1) * 0x1a Bytes große Schauplatz-Tabelle.
 === Ende Beschreibung === */
void Fight::f_07a8a0()
{
    short cnt;
    d_1c2098.f_1448b0(0x80260002, 0x200);
    d_1c2098.f_144920(&cnt, 2);
    if (nr > cnt) nr = cnt;
    d_1c2098.f_144ab0(nr * 0x26d + 2, 0);
    d_1c2098.f_144920(rec, 0x26d);
    d_1c2098.f_1449a0();
    if (d_1bd948) {
        delete d_1bd948;
        d_1bd948 = 0;
    }
    long n = (d_1c2be0.f_050710(d_1a2510[rec->kind].a) + 1) * 0x1a;
    d_1bd948 = (char *)f_014540(n, fi_load_file, 193);
    d_1c2098.f_1448b0(d_1a2510[rec->kind].file, 0x200);
    d_1c2098.f_144920(d_1bd948, n);
    d_1c2098.f_1449a0();
}
