/* === Beschreibung (Katalog) ===
 * Einheit tdmalloc_neu (0x11F570 - 0x11F790)
 *
 * Überblick
 * Die Einheit tdmalloc_neu bildet die Speicher- und Zustandsschnittstelle zwischen dem Hauptspiel und der
 * 3D-Dungeon-Engine (tdmalloc.cpp): Sie verwaltet die Speicherreservierungs-Rückrufe mit Blockzähler (d_1c0ae0),
 * setzt Kamera-/Startparameter und speichert bzw. lädt den dynamischen 3D-Szenenzustand beim Dungeonwechsel in
 * temporäre Dateien.
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// I14 31.10.: f_11f570-f_11f5f0 aus gz_11f550 (vor RAND833, dort 7/7 GLEICH) hierher zurueck - laut teile_alle gehoeren sie zu tdmalloc_neu (11f570-11f790),
//            833 hatte sie aus gz_11f550 entfernt, hier fehlten sie (FEHLT). Deklarationen der Koerper wie in gz_11f550.
// tdmalloc.cpp (Schatten ueber Riva, Attic 1996). Code 0x11F570-0x11F78F. Speicher-Rueckrufe und Speicherabbild fuer die 3D-Engine.
#include <stdio.h>
#include <string.h>
#include <io.h>

#include "RIVAMEM.H"



int f_014540(int p1, int p2, int p3);                    // reg eax edx ebx stapel 0
int f_060080(int p1);                                    // reg eax stapel 0
int f_15fffc(int p1, int p2);                            // reg eax edx stapel 0
char *f_120640(char *p1);
int f_144bf0(const char *a, const char *b);
int f_15e469(const char *a, const char *b);
int f_15fdd5(int a, int b, int c, int d);
int f_15e836(int a);
int f_14572e(char *, const char *, ...);
void  f_160320(void *buf);

extern const char d_1a7f38[];                            // "p:\riva\source\cpp\tdmalloc.cpp"
extern const char d_1b8370[];                            // "wb"
extern const char d_1b8373[];                            // "%s%s.%s"
extern const char d_1b837b[];                            // "%s%s.%s"
extern const char d_1b8383[];                            // "rb"
extern char  d_1c0b00[];
extern char  d_1c27a8[];
extern const char *d_1a9674;
extern short d_1a9696, d_1a7fc2;
extern char d_1c0b98;
extern int d_1bd6c0;
extern int d_1c0ae0;                            // Zaehler belegter Bloecke
extern int d_1a9900, d_1a9904, d_1a9908;

//@ f_11f570
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speicherreservierungs-Rückruf der 3D-Engine: Reserviert einen Speicherblock der Größe p1
 *   über den Spiel-Allocator f_014540(p1, p2, p4) (mit Dateiname p2 und Zeilennummer p4), erhöht den Zähler der
 *   von der 3D-Engine belegten Speicherblöcke d_1c0ae0 um 1 und gibt den Zeiger in eax zurück.
 * - Eingaben: p1 (Größe in Bytes), p2 (Quelltext-Dateiname), p3 (ungenutzt), p4 (Quelltext-Zeilennummer).
 * - Rückgabewert: Zeiger auf den reservierten Speicherblock (void * in eax).
 * - Wichtige Variablen:
 *   - d_1c0ae0: Globaler Zähler der aktuell von der 3D-Engine belegten Heap-Blöcke.
 === Ende Beschreibung === */
void f_11f570(int p1, int p2, int p3, int p4)
{
    f_014540(p1, p2, p4);
    ++d_1c0ae0;
}

//@ f_11f580
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speicherfreigabe-Rückruf der 3D-Engine: Gibt den übergebenen Speicherblock p1 per delete
 *   (f_014710) frei und verringert den Blockzähler d_1c0ae0 um 1.
 * - Eingaben: p1 (Zeiger auf den freizugebenden Speicherblock).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1c0ae0.
 === Ende Beschreibung === */
void f_11f580(int p1)
{
    delete (char *)p1;
    d_1c0ae0 -= 1;
}

//@ f_11f590
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Speichert drei 32-Bit-Parameter (p1, p2, p3, vermutlich Koordinaten oder Rückrufzeiger der
 *   3D-Engine) in den globalen Variablen d_1a9900, d_1a9904 und d_1a9908.
 * - Eingaben: p1, p2, p3 (drei 32-Bit-Werte).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: d_1a9900, d_1a9904, d_1a9908.
 === Ende Beschreibung === */
void f_11f590(int p1, int p2, int p3)
{
    d_1a9900 = p1;
    d_1a9904 = p2;
    d_1a9908 = p3;
}

//@ f_11f5b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Datei mit dem Namen p1 im binären Schreibmodus "wb" (d_1b8370, f_15e469),
 *   schreibt p3 Bytes aus dem Puffer p2 hinein (f_15fdd5) und schließt die Datei (f_15e836).
 * - Eingaben: p1 (Dateiname als const char *), p2 (Quellpuffer), p3 (Anzahl der zu schreibenden Bytes).
 * - Rückgabewert: 1 bei erfolgreichem Schreiben, 0 falls der Dateiname NULL ist oder die Datei nicht geöffnet
 *   werden konnte.
 * - Wichtige Variablen: d_1b8370 ("wb").
 === Ende Beschreibung === */
int f_11f5b0(int p1, int p2, int p3)
{
    if (p1 != 0) {
        p1 = f_15e469((const char *)p1, d_1b8370);
        if (p1 != 0) {
            f_15fdd5(p2, 1, p3, p1);
            f_15e836(p1);
            p1 = 1;
        }
    }
    return p1;
}

//@ f_11f5f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Erzeugt beim Verlassen oder Speichern eines 3D-Dungeons über f_15fffc ein serialisiertes
 *   Speicherabbild des aktuellen 3D-Szenenzustands (local_1c, Größe local_18), setzt aus dem Pfad d_1a9674 und
 *   dem Dungeon-Namen d_1c0b00 den Dateinamen in d_1c27a8 zusammen, schreibt das Abbild in diese Datei, gibt den
 *   Puffer local_1c wieder frei (--d_1c0ae0) und ruft bei vorhandenem Ansichtsobjekt d_1bd6c0 die
 *   Aufräumfunktion f_060080 auf.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1a9696, d_1a7fc2, d_1c0b98: Statusflags der 3D-Engine.
 *   - d_1c0b00, d_1c27a8: Aktueller Szenenname und zusammengesetzter Dateipfad für die Zustandssicherung.
 *   - d_1c0ae0: Zähler belegter 3D-Speicherblöcke.
 === Ende Beschreibung === */
void f_11f5f0(void)
{
    extern const char d_1b8373[];
    int local_1c;
    int local_18;
    int iVar2;
    int iVar3;
    int iVar4;
    char *uVar1;
    local_1c = 0;
    if ((d_1a9696 != -1 || d_1a7fc2 == -2) && (signed char)d_1c0b98 == 0) {
        uVar1 = f_120640(d_1c0b00);
        d_1c27a8[0] = 0;
        if (f_144bf0(uVar1, d_1c0b00) == 0) {
            if (f_15fffc((int)&local_1c, (int)&local_18) == 0) {
                f_14572e(d_1c27a8, d_1b8373, (int)d_1a9674, uVar1 + 10, uVar1 + 10);
                iVar2 = local_1c;
                iVar3 = local_18;
                iVar4 = (int)d_1c27a8;
                if (iVar4 != 0) {
                    iVar4 = f_15e469((const char *)iVar4, d_1b8370);
                    if (iVar4 != 0) {
                        f_15fdd5(iVar2, 1, iVar3, iVar4);
                        f_15e836(iVar4);
                    }
                }
            }
            if (local_1c != 0) {
                delete (char *)local_1c;
                --d_1c0ae0;
            }
        }
        if (d_1bd6c0 != 0) f_060080(d_1bd6c0);
    }
}

//@ f_11f6e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Sucht beim Betreten eines 3D-Dungeons nach einer zuvor gespeicherten Zustandsdatei
 *   (d_1c27a8, Modus "rb"), liest deren gesamten Inhalt in einen temporären Puffer buf ein, stellt den
 *   3D-Szenenzustand über f_160320(buf) wieder her und gibt buf wieder frei.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0b00, d_1c27a8: Szenenname und Dateipfad der gespeicherten 3D-Zustandsdatei.
 === Ende Beschreibung === */
void f_11f6e0()
{
    char *p = f_120640(d_1c0b00);
    d_1c27a8[0] = 0;
    if (strcmp(p, d_1c0b00) == 0) {
        sprintf(d_1c27a8, d_1b837b, d_1a9674, p + 10, p + 10);
        FILE *f = fopen(d_1c27a8, d_1b8383);
        if (f) {
            long n = filelength(fileno(f));
            char *buf = new (mark(d_1a7f38, 330)) char[n];
            if (buf) {
                fread(buf, 1, n, f);
                fclose(f);
                f_160320(buf);
                delete [] buf;
            }
        }
    }
}
