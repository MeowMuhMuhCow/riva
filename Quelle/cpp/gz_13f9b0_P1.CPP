/* === Beschreibung (Katalog) ===
 * Einheit gz_13f9b0 (0x13F9B0 - 0x13F9D0)
 *
 * Überblick
 *
 * Die winzige Einheit gz_13f9b0 enthält lediglich den Standardkonstruktor für einen einzelnen Cache-Eintrag (E)
 * der virtuellen RAM-Disk (virtdisk.cpp), die bis zu 200 häufig benötigte Archivdateien im Arbeitsspeicher
 * zwischenspeichert.
 === Ende Beschreibung === */
// P1 1/1 gleich
// gz_13f9b0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x13F9B0-0x13F9D0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
// --- eigene Funktionen (1), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
struct E { unsigned key; unsigned short s; char *ptr; int n; };
//@ f_13f9b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert einen einzelnen 14-Byte-Tabelleneintrag der virtuellen RAM-Disk (virtdisk) als
 *   leer, indem Datenzeiger (ptr = 0), Ressourcenkennung (key = 0) und Dateigröße (n = 0) genullt und der
 *   Indexverweis s auf 0xFFFF (-1) gesetzt werden.
 * - Eingaben: Zeiger p auf den zu initialisierenden Cache-Eintrag (E).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - p->key, p->s, p->ptr, p->n: Felder des 14-Byte-Cache-Eintrags.
 === Ende Beschreibung === */
void f_13f9b0(E *p)
{
  p->ptr = 0;
  p->s = 0xffff;
  p->key = 0;
  p->n = 0;
}
