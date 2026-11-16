/* === Beschreibung (Katalog) ===
 * Einheit startup_neu (0x11BF00 - 0x11C070)
 *
 * Überblick
 * Die Einheit startup_neu enthält die drei Hilfsfunktionen des Startmoduls (startup.cpp): das Setzen des
 * Arbeitsverzeichnisses (f_11bf00), das Übersetzen eines 16-Bit-Sprach-/Tastaturcodes anhand einer
 * 16-Einträge-Tabelle (f_11bfd0) sowie das Einlesen der Konfigurationsdatei LANG.CFG (f_11c010).
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 11bf00-11c070 aus Quelle/cpp/STARTUP.CPP; erster Entwurf, Einbau separat prüfen.
// startup.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x11BDE0-0x11C070. Start: Arbeitsverzeichnis setzen, LANG.CFG lesen.
#include <string.h>
int f_0ce0b0();                                          // getdrive
void f_0ce120(int drive, char *buf);
int f_15f2b5(const char *dir);                           // chdir
int f_144fbf(const char *name, int mode, ...);           // open
int f_144e8b(int h, void *buf, unsigned n);              // read
int f_145259(int h);                                     // close
void f_0ed8f0(void *obj, long code, const char *s, ...);
extern char d_1c1190[], d_1c20b0[], d_1c2148[];
extern unsigned short d_1c2108[16];
extern char *d_1a967c;
extern const char d_1b8360[];                            // "X:\\" (Literal, liegt noch im ASM-DatenstÃ¼ck D20060)
extern char d_1a7dac[];
extern const unsigned short d_1a7db6[17];
#define lang_cfg d_1a7dac
#define tab d_1a7db6
struct Startup { char c; Startup(); };
void f_11bf00();
void f_11c010();
//@ f_11bf00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Fragt das aktuelle Laufwerk (f_0ce0b0) und Verzeichnis (f_0ce120) ab, baut daraus in
 *   d_1c2148 und im lokalen Puffer buf den Pfad zum Unterverzeichnis d_1a967c zusammen und wechselt per f_15f2b5
 *   (chdir) in dieses Verzeichnis.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c2148: Globaler Pfadpuffer für das Startverzeichnis.
 *   - d_1a967c: Zeiger auf den anzuhängenden Unterverzeichnisnamen.
 === Ende Beschreibung === */
void f_11bf00()
{
    char buf[80];
    strcpy(d_1c2148, d_1b8360);
    d_1c2148[0] = f_0ce0b0() + '@';
    f_0ce120(0, d_1c2148 + 3);
    strcpy(buf, d_1c2148);
    if (buf[strlen(buf) - 1] == '\\') buf[strlen(buf) - 1] = 0;
    strcat(buf, d_1a967c);
    f_15f2b5(buf);
}
//@ f_11bfd0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht den übergebenen 16-Bit-Wert v in der 16 Einträge umfassenden Tabelle d_1c2108[0..15]
 *   (innerhalb des LANG.CFG-Blocks) und ersetzt ihn bei einem Treffer durch den korrespondierenden 16-Bit-Wert
 *   aus der Konstantentabelle d_1a7db6[0..15].
 * - Eingaben: v (zu übersetzender 16-Bit-Code).
 * - Rückgabewert: Übersetzter 16-Bit-Wert aus d_1a7db6[i] oder unverändert v, falls kein Eintrag passt.
 * - Wichtige Variablen:
 *   - d_1c2108: 16-Einträge-Quelltabelle im LANG.CFG-Puffer.
 *   - d_1a7db6: 16-Einträge-Zieltabelle.
 === Ende Beschreibung === */
short f_11bfd0(short v)
{
    for (short i = 0; i < 16; i++)
        if (v == d_1c2108[i]) { v = tab[i]; break; }
    return v;
}
//@ f_11c010
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Sprachkonfigurationsdatei LANG.CFG (d_1a7dac) zum Lesen (f_144fbf), liest 0x78
 *   (120) Bytes in den globalen Puffer d_1c20b0 (f_144e8b) und schließt die Datei (f_145259); schlägt das Öffnen
 *   oder Lesen fehl, wird der kritische Fehler 0x29a000f bzw. 0x29a0010 über f_0ed8f0 ausgelöst.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a7dac (lang_cfg): Dateiname "LANG.CFG".
 *   - d_1c20b0: Zielpuffer für die 120 Konfigurationsbytes.
 === Ende Beschreibung === */
void f_11c010()
{
    int h = f_144fbf(lang_cfg, 0);
    if (h != -1) {
        if (f_144e8b(h, d_1c20b0, 0x78) == 0x78) f_145259(h);
        else f_0ed8f0(d_1c1190, 0x29a0010, lang_cfg);
    } else f_0ed8f0(d_1c1190, 0x29a000f, lang_cfg);
}
