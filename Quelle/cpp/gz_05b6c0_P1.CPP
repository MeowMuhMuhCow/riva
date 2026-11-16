/* === Beschreibung (Katalog) ===
 * Einheit gz_05b6c0 (0x05b6c0 - 0x05b820)
 *
 * Überblick
 * Dieses Grenzstück am Ende von diskmen2.cpp enthält eine Hilfsfunktion zum Leeren des ..\TEMP-Verzeichnisses,
 * sieben vom Compiler ausgelagerte Inline-Zugriffsmethoden für die registrierten Spielstandvariablen (BVAR,
 * WVAR, DVAR) sowie den statischen Initialisierer der Byte-Spielvariable 0x15.
 === Ende Beschreibung === */
// P3 7/9 gleich (suche.py 24.10.2026, Basis gz_05b6c0_P1.CPP)
// gz_05b6c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x05B6C0-0x05B860
#include <string.h>
char *f_144850(char *o, unsigned long id);
extern char d_1c2098[];
int f_14572e(char *, const char *, ...);
int f_149336(char *p);
short f_1492b4(char *name, int attr, void *dta);
short f_1492d1(void *dta);
int f_1492ed(void *dta);
extern const char *d_1a9674;
extern const char d_1b6ed1[];
extern char d_1bcacc;
extern int d_1bcacd;
extern short d_1c212a;
extern char **d_1c212c;
struct Dta { char r[30]; char name[14]; };

//@ f_05b6c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht das Verzeichnis ..\TEMP\*.* und löscht sämtliche darin enthaltenen temporären
 *   Dateien bis auf diejenige Datei, deren Name im Textarchiv d_1c2098 unter der Kennung 0x90001 hinterlegt ist.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die lokale Struktur dta (Dta) nimmt die DOS-Dateisucheinträge
 *   (_dos_findfirst/_dos_findnext) auf, während buf1 und buf2 das Suchmuster und den Löschpfad enthalten.
 === Ende Beschreibung === */
#pragma aux f_144850 modify [ebx];
void f_05b6c0()
{
    char buf1[80];
    char buf2[80];
    Dta dta;
    f_14572e(buf1, d_1a9674, d_1b6ed1);
    if (!f_1492b4(buf1, 0, &dta)) {
      do {
        if (strcmp(dta.name, f_144850(d_1c2098, 0x90001))) {
            f_14572e(buf2, d_1a9674, dta.name);
            f_149336(buf2);
        }
      } while (!f_1492d1(&dta));
    }
    f_1492ed(&dta);
}

//@ f_05b770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den 32-Bit-Wert (+0) eines registrierten Doppelwort-Spielvariableneintrags (DVAR).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Variablen-Eintrag und den neuen Wert p2.
 *   Sie gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt direkt in das erste int-Feld *p1 der 6-Byte-Struktur (4 Bytes Wert + 2 Bytes
 *   Kennnummer).
 === Ende Beschreibung === */
void f_05b770(int *p1, int p2)
{
    *p1 = p2;
}

//@ f_05b780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den 32-Bit-Wert (+0) eines registrierten Doppelwort-Spielvariableneintrags (DVAR) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Variablen-Eintrag und gibt dessen int-Wert
 *   zurück.
 * - Wichtige Variablen: Liest das erste int-Feld *p1 des Eintrags.
 === Ende Beschreibung === */
int f_05b780(int *p1)
{
    return *p1;
}

//@ f_05b790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die 16-Bit-Variablennummer (Offset +4) eines Doppelwort-Spielvariableneintrags (DVAR),
 *   anhand derer die Variable beim Speichern und Laden zugeordnet wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Variablen-Eintrag und gibt die Kennnummer
 *   als short zurück.
 * - Wichtige Variablen: Liest das short-Feld an Offset +4 von p1.
 === Ende Beschreibung === */
short f_05b790(char *p1)
{
    return *(short *)(p1 + 4);
}

//@ f_05b7a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den 16-Bit-Wert (+0) eines registrierten Wort-Spielvariableneintrags (WVAR).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Wort-Eintrag und den neuen Wert p2. Sie
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt den auf short gekürzten Wert p2 an Offset +0 der 4-Byte-Struktur.
 === Ende Beschreibung === */
void f_05b7a0(short *p1, int p2)
{
    *p1 = (short)p2;
}

//@ f_05b7b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die 16-Bit-Variablennummer (Offset +2) eines Wort-Spielvariableneintrags (WVAR).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Wort-Eintrag und gibt die Kennnummer als
 *   short zurück.
 * - Wichtige Variablen: Liest das short-Feld an Offset +2 von p1.
 === Ende Beschreibung === */
short f_05b7b0(char *p1)
{
    return *(short *)(p1 + 2);
}

//@ f_05b7c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den 8-Bit-Wert (+0) eines registrierten Byte-Spielvariableneintrags (BVAR).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Byte-Eintrag und den neuen Wert p2. Sie
 *   gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Schreibt das untere Byte von p2 an Offset +0 der 3-Byte-Struktur.
 === Ende Beschreibung === */
void f_05b7c0(char *p1, int p2)
{
    *p1 = (char)p2;
}

//@ f_05b7d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die 16-Bit-Variablennummer (Offset +1) eines Byte-Spielvariableneintrags (BVAR).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Byte-Eintrag und gibt die Kennnummer als
 *   short zurück.
 * - Wichtige Variablen: Liest das ungepackte short-Feld an der ungeraden Adresse p1 + 1.
 === Ende Beschreibung === */
short f_05b7d0(char *p1)
{
    return *(short *)(p1 + 1);
}

//@ f_05b7e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert beim Programmstart die globale Byte-Spielvariable d_1bcacc mit dem Startwert 0
 *   und der Variablennummer 0x15 und trägt sie in das globale BVAR-Register (d_1c212c/d_1c212a) ein, damit sie
 *   in Spielständen mitgespeichert wird.
 * - Eingaben und Rückgabe: Die Funktion nimmt keine Parameter entgegen und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bcacc (+0 Wert, +1 Kennnummer d_1bcacd = 0x15) wird an Position
 *   d_1c212a in das Zeigerarray d_1c212c eingetragen.
 === Ende Beschreibung === */
void f_05b7e0()
{
    d_1bcacc = 0;
    *(short *)&d_1bcacd = 0x15;
    d_1c212c[d_1c212a] = &d_1bcacc;
    ++*(volatile short *)&d_1c212a;
}
