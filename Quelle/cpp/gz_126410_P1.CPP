/* === Beschreibung (Katalog) ===
 * Einheit gz_126410 (0x126410-0x1265C0)
 *
 * Überblick
 * Die Einheit gz_126410 enthält die Zugriffsmethoden, den Konstruktor, den Tageszeit-Intervalltest sowie die
 * Tag- und Wochentag-Vorschau der Spielzeit- und Kalenderstruktur Time (Aventurischer Kalender mit
 * Tagessekunden, Wochentag, Stunde, Tag, Monat und Jahr).
 === Ende Beschreibung === */
// I9: aus gz_126410_REST.CPP uebernommen (Stufe-2-Stand), Marken 3 neu
// gz_126410.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x126410-0x1265C0. Datums-Struktur (Zeit): Feldzugriffe, Konstruktor, Tag-/Wochentag-Weiterschaltung.
struct Time {
    char f0;
    int  f1;
    char f5, f6, f7, f8, f9;
    int  fa;
    char pad[0xc];
    char f1a, f1b;
};
#define V(t) (*(volatile int *)&(t)->f1)
extern int d_1c0c90;   // Fable 30.10.: Daten liegen in der Basis
extern int d_1c0c94;

int  f_126410(Time *t) { return t->f1; }
char f_126420(Time *t) { return t->f5; }
char f_126430(Time *t) { return t->f7; }
char f_126440(Time *t) { return t->f6; }
char f_126450(Time *t) { return t->f8; }
char f_126460(Time *t) { return t->f9; }
void f_126470(Time *t, int v) { t->f1 = v; }
void f_126480(Time *t, int v) { t->f5 = v; }
void f_126490(Time *t, int v) { t->f7 = v; }
//@ f_1264a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Feld t->f6 (Tagesstunde/Tagesphase) auf v.
 * - Eingaben: Time *t, int v.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: t->f6 (char).
 === Ende Beschreibung === */
void f_1264a0(Time *t, int v) { t->f6 = v; }
//@ f_1264b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt den Kalendermonat t->f8 auf v.
 * - Eingaben: Time *t, int v (Monat).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: t->f8 (char).
 === Ende Beschreibung === */
void f_1264b0(Time *t, int v) { t->f8 = v; }
//@ f_1264c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Kalenderjahr t->f9 auf v.
 * - Eingaben: Time *t, int v (Jahr).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: t->f9 (char).
 === Ende Beschreibung === */
void f_1264c0(Time *t, int v) { t->f9 = v; }
//@ f_1264d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Setzt das Status-/Modusbyte t->f1b (Offset +0x1B) der Zeitstruktur auf v.
 * - Eingaben: Time *t, int v.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: t->f1b (char, Offset +0x1B).
 === Ende Beschreibung === */
void f_1264d0(Time *t, int v) { t->f1b = v; }
//@ f_1264e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest das Status-/Modusbyte t->f1b (Offset +0x1B) der Zeitstruktur aus.
 * - Eingaben: Time *t.
 * - Rückgabewert: char (Wert von t->f1b).
 * - Wichtige Variablen: t->f1b (char).
 === Ende Beschreibung === */
char f_1264e0(Time *t) { return t->f1b; }

//@ f_1264f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob die aktuelle Tageszeit t->f1 innerhalb des Zeitfensters [a, b] liegt (z. B. für
 *   Ladenöffnungszeiten oder Nacht-Ereignisse), und berücksichtigt dabei auch Intervalle über Mitternacht hinweg
 *   (a > b, d. h. t->f1 >= a || t->f1 <= b).
 * - Eingaben: Time *t, int a (Startzeitpunkt), int b (Endzeitpunkt).
 * - Rückgabewert: int (1, wenn t->f1 im Intervall [a, b] liegt, sonst 0).
 * - Wichtige Variablen: t->f1 (int, aktuelle Tageszeit).
 === Ende Beschreibung === */
int f_1264f0(Time *t, int a, int b)
{
    int r = 0;
    if (a < b && a <= V(t) && b >= V(t))
        r = 1;
    else if (a > b && (a <= V(t) || b >= V(t)))
        r = 1;
    return r;
}

//@ f_126520
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor der Zeitstruktur Time. Setzt das Startdatum des Spiels auf den 15. Tag (f7 =
 *   15) des 12. Monats Rahja (f8 = 12) im Jahr 17 Hal (f9 = 17), Wochentag 0 (f5 = 0), Tagesphase 3 (f6 = 3) und
 *   Tageszeit 0xa8c0 (43200 = 12:00 Uhr mittags) und initialisiert die globalen Zeitsteuervariablen d_1c0c94 = 1
 *   und d_1c0c90 = 0.
 * - Eingaben: Time *t (this).
 * - Rückgabewert: Time * (t).
 * - Wichtige Variablen:
 *   - d_1c0c94 (int): Zeittakt-Freigabe (1).
 *   - d_1c0c90 (int): Zeitakkumulator (0).
 === Ende Beschreibung === */
Time *f_126520(Time *t)
{
    *(volatile int *)&d_1c0c94 = 1;
    *(volatile int *)&d_1c0c90 = 0;
    t->f0 = 0; t->f1 = 0xa8c0; t->f5 = 0; t->f7 = 15; t->f6 = 3; t->f8 = 12; t->f9 = 17; *(volatile int *)&t->fa = 0; t->f1a = 0; t->f1b = 0;
    return t;
}

//@ f_126560
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leerer Destruktor bzw. Platzhalter der Zeitstruktur Time.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_126560() {}

//@ f_126570
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet die Nummer des nächsten Kalendertages (t->f7 + 1). Überschreitet der Tag die
 *   Monatslänge 30 (c > 30), gibt die Funktion im 13. Monat (Namenlose Tage, t->f8 > 12) den Sonderwert -5
 *   zurück und springt in regulären Monaten (1..12) auf den 1. des Folgemonats um.
 * - Eingaben: Time *t.
 * - Rückgabewert: signed char (Tag des Folgetages 1..30 oder -5 in den Namenlosen Tagen).
 * - Wichtige Variablen: t->f7 (Tag), t->f8 (Monat).
 === Ende Beschreibung === */
signed char f_126570(Time *t)
{
    signed char c;
    c = (signed char)t->f7;
    c = c + 1;
    if (c > 30) {
        if ((signed char)t->f8 > 12) return -5;
        c = 1;
    }
    return c;
}

//@ f_1265a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet den nächsten Wochentag ((t->f5 + 1) % 7), indem bei Wochentag 6 wieder 0 und
 *   sonst t->f5 + 1 zurückgegeben wird.
 * - Eingaben: Time *t.
 * - Rückgabewert: signed char (Wochentag des Folgetages 0..6).
 * - Wichtige Variablen: t->f5 (aktueller Wochentag über f_126420(t)).
 === Ende Beschreibung === */
signed char f_1265a0(Time *t)
{
    if ((signed char)f_126420(t) == 6) return 0;
    return f_126420(t) + 1;
}

