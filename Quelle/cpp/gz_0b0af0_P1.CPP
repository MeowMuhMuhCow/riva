/* === Beschreibung (Katalog) ===
 * Einheit gz_0b0af0 (0x0B0AF0 - 0x0B0F90)
 *
 * Fortsetzung der Helden-Dateioperationen (loaders.cpp): Überschreiben, Anhängen, Einladen in die aktive
 * Heldengruppe und Speichern einzelner Heldendatensätze (0x5ef Bytes).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
#include "RIVAMEM.H"
// P3 2/5 gleich (suche.py 23.10.2026, Basis gz_0b0af0_P1.CPP)
// gz_0b0af0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0B0AF0-0x0B0F90
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
int f_034e20(void *p);




int f_0b0a00(int p1, short *p2, int p3);






int f_14d0d7(const char *p1, int p2);
int f_144fbf(const char *p, int fl, ...);
int f_144cb6(int fd, void *buf, int n);
int f_145259(int fd);
int f_145279(int fd, int off, int whence);
int f_14572e(char *buf, const char *fmt, ...);

extern char *d_1a9674, *d_1a9678;
extern char *d_1bc8f0;
struct REC { char c[0x5ef]; };
//@ f_0b0af0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion überschreibt einen bestehenden 0x5ef Bytes großen Heldendatensatz an einem
 *   bestimmten Datensatzindex in der angegebenen Heldendatei im ..\TEMP\-Verzeichnis und aktualisiert - sofern
 *   es sich nicht um die reine Temp-Datei 0x90002 handelt - denselben Datensatz zusätzlich direkt in der Datei
 *   0x90001 im ..\GAMES\-Verzeichnis.
 * - Eingaben: Übergeben werden der nullbasierte Datensatzindex (p1), ein Zeiger auf die zu speichernde
 *   Heldenstruktur (p2, 0x5ef Bytes) sowie die Ressourcenkennung der Zieldatei (p3).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0af0(short p1, char *p2, unsigned p3)
{
    char buf[40];
    short fd;
    if (p3 == 0x90002) {
        if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p3 | 0x40000000, 0x202) == 1) {
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( p1 * 0x5ef, 0);
            ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( p2), 0x5ef)));
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
        }
    } else {
        if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p3 | 0x40000000, 0x202) == 1) {
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( p1 * 0x5ef, 0);
            ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( p2), 0x5ef)));
            ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
        }
        f_14572e(buf, d_1a9678, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( 0x90001))));
        fd = f_144fbf(buf, 2);
        f_145279(fd, p1 * 0x5ef, 0);
        f_144cb6(fd, p2, 0x5ef);
        f_145259(fd);
    }
}
//@ f_0b0c30
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion hängt einen neuen 0x5ef Bytes großen Heldendatensatz an das Ende einer
 *   Heldendatei an, legt die Datei bei Bedarf zuvor im ..\TEMP\- (und außer bei 0x90002 auch im
 *   ..\GAMES\-)Verzeichnis neu an und schreibt den Datensatz in beide Verzeichnisse.
 * - Eingaben: Übergeben werden ein Zeiger auf die anzuhängende Heldenstruktur (p1, 0x5ef Bytes) und die
 *   Ressourcenkennung der Zieldatei (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0c30(char *p1, unsigned p2)
{
    char buf[40];
    short fd;
    if (p2 == 0x90002) {
        if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p2 | 0x40000000, 0x200) == 0) {
            f_14572e(buf, d_1a9674, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p2))));
            f_145259((short)f_14d0d7(buf, 0x180));
        } else ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p2 | 0x40000000, 0x202);
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( 0, 2);
        ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( p1), 0x5ef)));
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
        return;
    }
    if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p2 | 0x40000000, 0x200) == 0) {
        f_14572e(buf, d_1a9674, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p2))));
        f_145259((short)f_14d0d7(buf, 0x180));
        f_14572e(buf, d_1a9678, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p2))));
        f_145259((short)f_14d0d7(buf, 0x180));
    } else ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p2 | 0x40000000, 0x202);
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( 0, 2);
    ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144960((void *)( p1), 0x5ef)));
    ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    f_14572e(buf, d_1a9678, ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144850( p2))));
    fd = f_144fbf(buf, 2);
    f_145279(fd, 0, 2);
    f_144cb6(fd, p1, 0x5ef);
    f_145259(fd);
}
//@ f_0b0e20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion speichert einen Heldendatensatz in der angegebenen Heldendatei (p2), indem
 *   sie zunächst über den internen Dateinamen des Helden (f_042320) prüft, ob bereits ein Eintrag in der Datei
 *   existiert (f_0b0a00), und diesen entweder an Ort und Stelle überschreibt (f_0b0af0) oder den Helden am
 *   Dateiende neu anhängt (f_0b0c30).
 * - Eingaben: Übergeben werden ein Zeiger auf die zu speichernde Heldenstruktur (p1) sowie die Ressourcenkennung
 *   der Zieldatei (p2).
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0e20(char *p1, unsigned p2)
{
    short s[2];
    int h = ((int)(f_042320((struct hero *)(p1))));
    f_0b0a00(h, s, p2);
    if (s[0] != -1) {
        f_0b0af0(s[0], p1, p2);
    } else {
        f_0b0c30(p1, p2);
    }
}
//@ f_0b0e60
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion liest einen Heldendatensatz am Index p2 aus der Heldendatei p1 in einen
 *   temporären Puffer ein, trägt dessen Gruppenplatz (p4) ein, prüft die Gültigkeit des Helden über f_034e20 und
 *   kopiert ihn bei Erfolg in das globale Gruppen-Array (d_1bc8f0) an den Zielslot p3.
 * - Eingaben: Übergeben werden die Ressourcenkennung der Heldendatei (p1), der Datensatzindex in der Datei (p2),
 *   der Ziel-Slot im globalen Helden-Array (p3) sowie die Gruppenpositionsnummer (p4).
 * - Rückgabewert: Die Funktion gibt 1 zurück, wenn der Held gültig war und in das Gruppen-Array übernommen
 *   wurde, andernfalls 0.
 === Ende Beschreibung === */
int f_0b0e60(unsigned p1, short p2, short p3, short p4)
{
    char buf[0x5ef];
    int r;
    int close_record(void *, int);
#pragma aux close_record "f_0421e0" parm [eax] [edx] value [eax] modify exact [eax edx ecx esi edi] // haelt die Register-Sicherung wie im Original
    struct Copier { static int assign(REC *to, const REC *from, int result) { *to = *from; return result; } };
    ((int)(f_0421c0((struct hero *)(buf))));
    if (((RivaFileManager*)(((char*)&d_1c2098)))->f_1448b0( p1 | 0x40000000, 0x200) == 1) {
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_144ab0( p2 * 0x5ef, 0);
        ((int)(((RivaFileManager*)(((char*)&d_1c2098)))->f_144920((void *)( buf), 0x5ef)));
        ((RivaFileManager*)(((char*)&d_1c2098)))->f_1449a0();
    }
    f_042440((struct hero *)(buf), p4);
    if (!f_034e20(buf)) {
        close_record(buf, 0);
        r = 0;
    } else {
        r = Copier::assign((REC *)(d_1bc8f0 + p3 * 0x5ef), (REC *)buf, 1);
        close_record(buf, 0);
    }
    return r;
}
//@ f_0b0f40
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Diese Funktion speichert einen Heldendatensatz gezielt in der temporären Heldendatei
 *   0x90002, indem sie bei bereits vorhandenem Namen (f_0b0a00) den bestehenden Datensatz über f_0b0af0
 *   aktualisiert oder den Helden sonst über f_0b0c30 neu anhängt.
 * - Eingaben: Als Parameter wird ein Zeiger auf die zu speichernde Heldenstruktur (p1) übergeben.
 * - Rückgabewert: Die Funktion hat keinen Rückgabewert (void).
 === Ende Beschreibung === */
void f_0b0f40(char *p1)
{
    short s[2];
    int h = ((int)(f_042320((struct hero *)(p1))));
    f_0b0a00(h, s, 0x90002);
    if (s[0] != -1) f_0b0af0(s[0], p1, 0x90002);
    else f_0b0c30(p1, 0x90002);
}
