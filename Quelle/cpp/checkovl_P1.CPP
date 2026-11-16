/* === Beschreibung (Katalog) ===
 * Einheit checkovl (0x046BF0 - 0x046D10)
 *
 * Überblick
 * Die Einheit checkovl enthält die zentrale Prüfung auf Stufenanstiege der Heldengruppe (f_046bf0): Sie
 * vergleicht für alle lebenden Gruppenmitglieder die aktuellen Abenteuerpunkte mit der Schwelle für die nächste
 * Erfahrungsstufe und startet bei Erreichen den Stufenanstiegs-Ablauf.
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 0/1 gleich (suche.py 29.10.2026, Basis checkovl_P1.CPP)
// OPT -4r -onetx -zp1 -s
// I9: aus checkovl.VT uebernommen (Stufe-2-Stand), Marken 1 neu
// checkovl.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4 Kleinwelle 2
// Code 0x046BF0-0x046D10. Stufenanstieg prüfen: für jeden Helden mit genug Abenteuerpunkten den Aufstieg auslösen, bis keiner mehr kann.
extern const char checkovl_file[] = "p:\\riva\\source\\cpp\\checkovl.cpp";   // 0x1A0E84
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void operator delete(void *p);                           // 0x014710
struct Lock {                                            // lokales Objekt mit Konstruktor/Destruktor
    Lock();                                              // 0x0CE7C0
    ~Lock();                                             // 0x0CE7E0
    int x;
};
struct Hero : hero {                                            // 0x5EF Bytes
    
                                         // lebt
    
                                         // Stufe
                                         // Abenteuerpunkte
};
extern Hero *d_1bc8f0;
extern long d_1c0c4c;
extern unsigned short d_1c20b2;
long f_046bc0(short lv);
struct LevelUp {                                         // 0x128 Bytes, Konstruktor 0x04A890, Destruktor 0x04AD40
    char b[0x128];
    LevelUp();
    ~LevelUp();
    void f_038880(Hero *h, int z);
};
//@ f_046bf0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchläuft, sofern keine Sperre (d_1c0c4c == 0) aktiv ist, wiederholt alle sieben
 *   Gruppenplätze (d_1bc8f0[0..6]) und prüft für jeden vorhandenen (f_042350), lebenden (!f_042470) Helden
 *   unterhalb von Stufe 21 (f_0428d0 < 21), ob seine Abenteuerpunkte (ap = f_0428f0) den Schwellenwert need für
 *   die nächste Stufe n = Stufe + 1 (berechnet nach der Gaußschen Stufenformel aus d_1c20b2 * 100 und f_046bc0(n
 *   - 1)) erreichen. Ist dies der Fall, wird ein LevelUp-Objekt erzeugt und der Stufenanstieg über
 *   LevelUp::f_038880(h, 0) durchgeführt; die Schleife wiederholt sich, bis kein Held mehr weiter aufsteigen
 *   kann.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - h (Laufzeiger über die sieben Heldenplätze ab d_1bc8f0).
 *   - ap (Aktuelle Abenteuerpunkte des geprüften Helden).
 *   - n (Zielstufe aktuelle_Stufe + 1).
 *   - need (Für das Erreichen der Zielstufe n benötigte Abenteuerpunkte).
 *   - again (Schleifenflag, das auf 1 gesetzt wird, sobald mindestens ein Held aufgestiegen ist, damit auch
 *     Mehrfach-Aufstiege sofort abgearbeitet werden).
 *   - u (Dynamisch angelegtes LevelUp-Steuerobjekt für die Durchführung des Stufenanstiegs).
 === Ende Beschreibung === */
void f_046bf0()
{
    Hero *h;
    short i;
    int again;
    if (d_1c0c4c == 0) {
        do {
            again = 0;
            h = d_1bc8f0;
            for (i = 0; i <= 6; i++, h++) {
                if (::f_042350((hero *)(h)) && !::f_042470((hero *)(h)) && ::f_0428d0((hero *)(h)) < 21) {
                    long need = 0;
                    long ap = 0;
                    short n = 0;
                    ap = ::f_0428f0((hero *)(h));
                    n = ::f_0428d0((hero *)(h)) + 1;
                    need = d_1c20b2 * 100;
                    if (n > 2) need = f_046bc0(n - 1) + (n - 1) * need;
                    if (ap >= need) {
                        Lock lock;
                        unsigned long r0; unsigned short r1; // haelt die Registerzuteilung wie im Original
                        LevelUp *u = new (mark((r0=d_1c0c4c, r1=d_1c20b2, d_1c0c4c=r0, d_1c20b2=r1, checkovl_file), 456)) LevelUp;
                        { long *qh3 = &d_1c0c4c; (n=0,u->f_038880(h, (int)(r0=*(unsigned long*)&(*qh3), r0^=(unsigned long)(*qh3), r0))); } // haelt die Registerzuteilung wie im Original
                        delete u;
                        again = 1;
                    }
                }
            }
        } while (again);
    }
}
