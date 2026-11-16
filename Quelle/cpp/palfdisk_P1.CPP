/* === Beschreibung (Katalog) ===
 * Einheit palfdisk (0da250 - 0da510)
 *
 * Überblick
 * Die Einheit palfdisk umfasst die letzte Funktion aus packfile.cpp (f_0da250) sowie den Beginn der Quelldatei
 * palfdisk.cpp (f_0da370 bis f_0da460), die eine abgeleitete ALF-Archivklasse (vtable d_1bb4b8) für teilweise
 * auf Festplatte ausgelagerte Archivdateien implementiert.
 === Ende Beschreibung === */
// P3 2/4 gleich (suche.py 30.10.2026, Basis palfdisk_P1.CPP)
// palfdisk.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0DA250-0x0DA510
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_013670(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0143c0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a626c[];           // Text 0x1A626C
// --- eigene Funktionen (3), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---

int __cdecl f_144fbf(int path, int flags);
int f_144cb6(int h, const void *b, unsigned n);
int f_144e8b(int h, void *b, int n);
int f_145259(int h);
int f_1492b4(int path, int attr, void *ft);
int f_1492ed(void *ft);
extern int d_1bb4b8[];
struct FT { char r[22]; short t; short d; unsigned size; char name[13]; };
struct HD { char a[8]; short n;  };

#pragma aux f_013670 modify [ecx];
//@ f_0da250
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Dekomprimiert einen mit dem "RIVAPACK"-Lauflängenverfahren gepackten Datenblock aus p2 (der Länge
 *   p4), indem 0x7f-Sequenzen (0x7f, anzahl, wert) wieder zu anzahl gleichen Bytes expandiert und über den
 *   Puffer p3 (Größe p6) in die Zieldatei p5 geschrieben werden.
 * - Eingaben: Übergeben werden das Objekt-Handle (p1), der Eingabepuffer (p2), der Ausgabepuffer (p3), die
 *   Anzahl der gepackten Eingabebytes (p4), das Dateihandle der Zieldatei (p5) sowie die Kapazität des
 *   Ausgabepuffers (p6).
 * - Rückgabewert: Gibt die Gesamtzahl der entpackten und geschriebenen Bytes oder -1 bei einem Schreibfehler
 *   zurück.
 === Ende Beschreibung === */
int f_0da250(short p1, unsigned char *p2, unsigned char *p3, short p4, short p5, short p6)
{
    unsigned char ch;
    unsigned char run;
    unsigned char value;
    short written = 0;
    short pending;
    int total = 0;
    int old_written;
    unsigned char *src;
    unsigned char *dst;

    src = p2;
    dst = p3;
    while (p4 > 0) {
        ch = *src++;
        p4 = p4 - 1;
        if (ch == 0x7f) {
            run = *src++;
            value = *src++;
            p4 -= 2;
            old_written = written;
            if ((int)run + old_written > p6) {
                short flush_count = written;
                if ((short)f_144cb6(p5, dst, flush_count) != written) {
                    total = -1;
                    goto done;
                }
                written = 0;
                total += old_written;
                p3 = dst;
            }
            while (run > 0) {
                *p3 = value;
                ++p3;
                --run;
                ++written;
            }
        } else {
            if (written == p6) {
                if ((short)f_144cb6(p5, dst, p6) != written) {
                    total = -1;
                    goto done;
                }
                total += written;
                written = 0;
                p3 = dst;
            }
            ++p3;
            p3[-1] = ch;
            ++written;
        }
    }
done:
    if ((int)(pending = written) != 0) {
        if ((short)f_144cb6(p5, dst, written) != written)
            total = -1;
        total += written;
    }
    return total;
}

void f_0da370(char *p1, int p2)
{
    struct HD hd;
    int h = f_144fbf(p2, 0x200);
    if (h >= 0) {
        f_144e8b(h, &hd, 10);
        if (hd.n > 0) {
            void *buf = operator new[]((unsigned)(short)hd.n, mark(d_1a626c, 0x5b));
            *(void **)(p1 + 0x82) = buf;
            f_144e8b(h, buf, hd.n);
        }
        f_145259(h);
    }
}
//@ f_0da3f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Ermittelt für den Archiveintrag mit dem Index p2 über f_0143c0 den zugehörigen Dateipfad (p1 +
 *   0x90), fragt mit _dos_findfirst (f_1492b4) Dateigröße, Uhrzeit und Datum der ausgelagerten Einzeldatei im
 *   Dateisystem ab und speichert diese Metadaten im Archivobjekt (+0x9e..+0xa8).
 * - Eingaben: Übergeben werden der Zeiger auf das Festplatten-Archivobjekt (p1) sowie der Eintragsindex (p2).
 * - Rückgabewert: Diese Funktion liefert keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0da3f0(int p1, short p2)
{
    struct FT ft;
    int iVar1;
    f_0143c0(p1, p1 + 0x90, p2);
    iVar1 = f_1492b4(p1 + 0x90, 0x20, &ft);
    if (iVar1 == 0) {
        *(unsigned *)(p1 + 0x9e) = ft.size;
        *(short *)(p1 + 0xa2) = ft.t;
        unsigned d = *(unsigned *)((char *)&ft + 24);
        *(short *)(p1 + 0xa6) = 1;
        *(int *)(p1 + 0xa8) = 0;
        *(short *)(p1 + 0xa4) = (short)d;
    }
    f_1492ed(&ft);
}
//@ f_0da460
/* === Beschreibung (Katalog) ===
 * - Aufgabe: Konstruiert ein Festplatten-Archivobjekt (palfdisk) auf Basis des allgemeinen Archivkonstruktors
 *   f_013670, trägt die virtuelle Methodentabelle d_1bb4b8 ein und lädt bei angegebenem Pfad (p4) die Tabelle
 *   der auf Festplatte ausgelagerten Einträge (*(p1 + 0x82)).
 * - Eingaben: Übergeben werden der Speicherbereich des Archivobjekts (p1), die Archivparameter (p2, p3) sowie
 *   optional der Pfad der Auslagerungs-Indexdatei (p4).
 * - Rückgabewert: Gibt den Zeiger auf das initialisierte Festplatten-Archivobjekt zurück.
 === Ende Beschreibung === */
int f_144fbf_x(int path, int flags);
#pragma aux f_144fbf_x parm caller [] modify exact [eax edx];
int *f_0da460(int p1, int p2, int p3, int p4)
{
    char *uVar3;
    struct HD hdr;
    p1 = f_013670(p1, p2, p3);
    *(int *)p1 = (int)d_1bb4b8;
    *(int *)(p1 + 0x82) = 0;
    *(int *)(p1 + 0x86) = 0;
    *(int *)(p1 + 0x8c) = -1;
    if (p4) {
        int h = f_144fbf_x(p4, 0x200);
        if (h >= 0) {
            f_144e8b(h, &hdr, 10);
            if (0 < hdr.n) {
                uVar3 = (char *)operator new[](hdr.n, mark(d_1a626c, 0x5b));
                *(char **)(p1 + 0x82) = uVar3;
                f_144e8b(h, uVar3, hdr.n);
                
                
            }
            f_145259(h);
        }
    }
    return (int *)p1;
}
