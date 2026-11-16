/* === Beschreibung (Katalog) ===
 * Einheit fz_18e380 (0x18e380 - 0x18e638)
 *
 * Überblick
 * Diese Einheit stellt das Standard-Diagnose- und Dateisystem-Adaptermodul der BRender-Bibliothek (brstdlib /
 * brstddiag / brstdfile) bereit. Es gibt Warnungen und tödliche Fehlermeldungen auf der Standardfehlerausgabe
 * (stderr) aus und öffnet BRender-Ressourcendateien unter Berücksichtigung der Suchpfad-Umgebungsvariable
 * (BRENDER_PATH).
 === Ende Beschreibung === */
// OPT -5r -oneatx -zp1 -s
// P3 6/7 gleich (suche.py 25.10.2026, Basis fz_18e380_P1.CPP)
// CC wcc386
// fz_18e380.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x18E380-0x18E638
#include <string.h>
int f_18e0d6(char *p1);
int f_197308(const char *s, char *f);
int f_17a891(int c, char *f);
void f_148534(int code);
int f_197390(const char *fmt, ...);
void *f_15e469(const char *name, const char *mode);
unsigned f_15e65b(void *buf, int size, unsigned n, void *f);
int f_15e836(void *f);
char *f_1968cf(const char *name);
#pragma aux f_18e0d6 "*";
#pragma aux f_197308 "*";
#pragma aux f_17a891 "*";
#pragma aux f_148534 "*";
#pragma aux f_197390 "*";
#pragma aux f_15e469 "*";
#pragma aux f_15e65b "*";
#pragma aux f_15e836 "*";
#pragma aux f_1968cf "*";
#pragma aux f_18e380 "*";
#pragma aux f_18e3b8 "*";
#pragma aux f_18e400 "*";
#pragma aux f_18e408 "*";
#pragma aux f_18e60c "*";
#pragma aux f_18e628 "*";
#pragma aux f_18e630 "*";
extern char d_1aa55a[];
extern char d_1aa574[];
extern const char d_1ba748[];
extern const char d_1ba74c[];
extern const char d_1ba75c[];
extern const char d_1ba760[];
extern const char d_1ba788[];
extern const char d_1ba78c[];
//@ f_18e380
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e380
 * - Aufgabe im Spiel: Gibt eine BRender-Warnmeldung (msg) auf der Konsole aus: Zuerst wird die Standardausgabe
 *   (d_1aa55a, stdout) per f_18e0d6 (fflush) geleert, danach die Meldung samt Zeilenumbruch ('\n') auf die
 *   Standardfehlerausgabe (d_1aa574, stderr) geschrieben und diese ebenfalls geleert.
 * - Eingaben: Die auszugebende Warnmeldung als Zeichenkette (msg).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - Globale Standardströme d_1aa55a (stdout) und d_1aa574 (stderr).
 === Ende Beschreibung === */
void f_18e380(char *msg)
{
    f_18e0d6(d_1aa55a);
    f_197308(msg, d_1aa574);
    f_17a891(10, d_1aa574);
    f_18e0d6(d_1aa574);
}
//@ f_18e3b8
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e3b8
 * - Aufgabe im Spiel: Gibt eine tödliche BRender-Fehlermeldung (msg) samt Zeilenumbruch auf stderr (d_1aa574)
 *   aus, leert die Ausgabepuffer und beendet anschließend das gesamte Programm sofort über f_148534(10)
 *   (exit(10)).
 * - Eingaben: Die auszugebende Fehlermeldung als Zeichenkette (msg).
 * - Rückgabewert: Kehrt nicht zurück (void).
 * - Wichtige Variablen:
 *   - Globale Standardströme d_1aa55a (stdout) und d_1aa574 (stderr).
 === Ende Beschreibung === */
void f_18e3b8(char *msg)
{
    f_18e0d6(d_1aa55a);
    f_197308(msg, d_1aa574);
    f_17a891(10, d_1aa574);
    f_18e0d6(d_1aa574);
    f_148534(10);
}
//@ f_18e400
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e400
 * - Aufgabe im Spiel: Liefert die feste Attribut-Bitmaske (31 bzw. 0x1f) des Standard-Dateisystemtreibers
 *   zurück, die angibt, welche Dateioperationen (Lesen, Schreiben, Binär-/Textmodus usw.) unterstützt werden.
 * - Eingaben: Keine (void).
 * - Rückgabewert: Der konstante Fähigkeitswert 31.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_18e400(void)
{
    return 31;
}
//@ f_18e408
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e408
 * - Aufgabe im Spiel: Öffnet eine BRender-Datei (name) zum Lesen: Falls die Datei nicht direkt im aktuellen
 *   Verzeichnis gefunden wird und name keinen Laufwerks- oder Pfadtrenner (':', '/', '\\') enthält, durchsucht
 *   die Funktion nacheinander alle durch Semikolon getrennten Verzeichnisse aus der Umgebungsvariable d_1ba74c
 *   ("BRENDER_PATH"). Nach dem Auffinden liest sie optional die ersten n_magics Header-Bytes ein, lässt über die
 *   Callback-Funktion identify prüfen, ob die Datei im Text- (1) oder Binärmodus (0) geöffnet werden soll, und
 *   öffnet sie anschließend im ermittelten Zielmodus neu.
 * - Eingaben: Dateiname (name), Anzahl der zu prüfenden Header-Bytes (n_magics), Zeiger auf die
 *   Format-Erkennungsfunktion (identify) sowie Zeiger auf die Ein-/Ausgabevariable für den Dateimodus
 *   (mode_result).
 * - Rückgabewert: Das geöffnete Dateihandle (fh) oder 0 (NULL), falls die Datei nicht gefunden werden konnte
 *   oder der Modus 2 zurückgegeben wurde.
 * - Wichtige Variablen:
 *   - Lokaler Pfadpuffer try_name (84 Bytes) und Header-Puffer magics (16 Bytes).
 *   - Lokaler Suchpfad-Zeiger br_path: Durchläuft die per f_1968cf (getenv) abgefragte Umgebungsvariable
 *     d_1ba74c.
 === Ende Beschreibung === */
void *f_18e408(char *name, int n_magics, int (*identify)(unsigned char *, int), int *mode_result)
{
    int open_mode = 0;
    void *fh;
    char *br_path;
    char try_name[84], *cp;
    unsigned char magics[16];
    unsigned char zero;
    int c;

    strncpy(try_name, name, 80);
    if ((fh = f_15e469(try_name, d_1ba748)) == 0) {
        if (strchr(name, ':') || strchr(name, '/') || strchr(name, '\\'))
            return 0;
        if ((br_path = f_1968cf(d_1ba74c)) == 0)
            return 0;
        zero = 0;
        while ((c = 0, *br_path) != zero) {
            cp = try_name;
            while ((int)*br_path != ';' && *br_path != zero) {
                *cp++ = *br_path++;
            }
            if ((c = *br_path) == ';')
                br_path++;
            if (cp != try_name && ((c = *(cp - 1)) != ':' && c != '/' && c != '\\'))
                *cp++ = '/';
            strcpy(cp, name);
            if ((fh = f_15e469(try_name, d_1ba748)) != 0)
                break;
        }
        if (fh == 0)
            return 0;
    }
    if (mode_result)
        open_mode = *mode_result;
    if (n_magics != 0) {
        if (f_15e65b(magics, 1, n_magics, fh) != n_magics) {
            f_15e836(fh);
            return 0;
        }
        if (identify)
            open_mode = identify(magics, n_magics);
        if (mode_result)
            *mode_result = open_mode;
    }
    f_15e836(fh);
    switch (open_mode) {
    case 1:
        fh = f_15e469(try_name, d_1ba75c);
        break;
    case 0:
        fh = f_15e469(try_name, d_1ba748);
        break;
    case 2:
        fh = 0;
        break;
    default:
        f_197390(d_1ba760, open_mode);
    }
    return fh;
}
//@ f_18e60c
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e60c
 * - Aufgabe im Spiel: Öffnet eine Datei (name) zum Schreiben über f_15e469, wobei je nach mode zwischen
 *   Textmodus (mode == 1, Modus-String d_1ba788 "w") und Binärmodus (Modus-String d_1ba78c "wb") gewählt wird.
 * - Eingaben: Dateiname (name) und Schreibmodus-Kennung (mode).
 * - Rückgabewert: Das geöffnete Dateihandle oder 0 bei Fehler.
 * - Wichtige Variablen:
 *   - Globale Modus-Zeichenketten d_1ba788 und d_1ba78c.
 === Ende Beschreibung === */
void *f_18e60c(char *name, int mode)
{
    return f_15e469(name, (mode == 1) ? d_1ba788 : d_1ba78c);
}
//@ f_18e628
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e628
 * - Aufgabe im Spiel: Schließt eine geöffnete BRender-Datei (f), indem das Dateihandle direkt an f_15e836
 *   (fclose) übergeben wird.
 * - Eingaben: Das zu schließende Dateihandle (f).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_18e628(void *f)
{
    f_15e836(f);
}
//@ f_18e630
/* === Beschreibung (Katalog) ===
 * - Adresse: 0x18e630
 * - Aufgabe im Spiel: Prüft anhand des Status-Flags an Offset +12 der Dateistrom-Struktur (*(int *)(f + 12) &
 *   16), ob beim Lesen der Datei f das Dateiende (EOF) erreicht wurde.
 * - Eingaben: Zeiger auf die Dateistrom-Struktur (f).
 * - Rückgabewert: Ungleich 0 (16), wenn das Dateiende erreicht ist, sonst 0.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_18e630(char *f)
{
    return *(int *)(f + 12) & 16;
}
