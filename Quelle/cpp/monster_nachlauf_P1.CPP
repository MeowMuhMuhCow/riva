/* === Beschreibung (Katalog) ===
 * Einheit monster_nachlauf (0x0D0260 - 0x0D0350)
 *
 * Überblick
 * Die Einheit monster_nachlauf enthält die Funktion f_0d0260, die den Anzeigenamen eines Monsters anhand seines
 * Typindexes idx aus der Monsternamensdatei (0x80010000) lädt und in die Monsterstruktur kopiert.
 === Ende Beschreibung === */
#include "RIVAFILE.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0d0260-0d0350 aus Quelle/cpp/MONSTER.CPP; erster Entwurf, Einbau separat prüfen.
// monster.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x0D0260-0x0D0350. Monstername Nr. idx aus der Namensdatei holen (164 nullterminierte Texte).
#include <string.h>
extern const char d_1a5914[];
#define monster_file d_1a5914
void *mark(const char *file, int line);                  // 0x014B10
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710

extern RivaFileManager d_1c2098;
struct Monster { char pad[0x49]; char name[1]; };
//@ f_0d0260
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Öffnet die Archivressource 0x80010000 mit den 165 nullterminierten Monsternamen, liest die
 *   gesamte Datei in einen temporären Textpuffer txt, baut eine Zeigertabelle tab[0..164] auf die einzelnen
 *   Namen auf, kopiert den Namen tab[idx] per strcpy in das Namensfeld m->name (+0x49) des übergebenen Monsters
 *   und gibt die Hilfspuffer wieder frei.
 * - Eingaben: m (Zeiger auf die Monster-Struktur), idx (0-basierter Index des Monsternamens in der Namensliste).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - m->name (+0x49): Zielpuffer für den Namen innerhalb der Monsterstruktur.
 *   - txt, tab: Temporärer Dateipuffer und Zeigertabelle für 165 nullterminierte Zeichenketten.
 === Ende Beschreibung === */
void f_0d0260(Monster *m, short idx)
{
    char **q;
    unsigned short n;
    long len;
    char *txt;
    char **tab;
    char *p;
    d_1c2098.f_1448b0(0x80010000, 0x200);
    len = d_1c2098.f_144a00();
    txt = new (mark(monster_file, 81)) char[len];
    tab = new (mark(monster_file, 82)) char *[165];
    d_1c2098.f_144920(txt, len);
    d_1c2098.f_1449a0();
    tab[0] = txt;
    q = tab + 1;
    n = 0;
    p = txt;
    while (n < 164) {
        if (!*p) { *q++ = p + 1; n++; }
        p++;
    }
    strcpy(m->name, tab[idx]);
    delete tab;
    delete txt;
}
