/* === Beschreibung (Katalog) ===
 * Einheit time_neu (0x1261B0 - 0x126410)
 *
 * Überblick
 * Die Einheit time_neu enthält die zentrale Zeitfortschritts-Methode Time::f_1261b0, die den aventurischen
 * Kalender von *Schatten über Riva* (Tageszeitticks, periodische Regenerations-/Zauberintervalle, Tageswechsel,
 * Wochentage, 30-tägige Monate, Namenlose Tage, Jahreswechsel und Feiertage) um einen Zeitschritt
 * weiterschaltet.
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 1261b0-126410 aus Quelle/cpp/TIME.CPP; erster Entwurf, Einbau separat prüfen.
// time.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x1261B0-0x126410. Spielzeit: ein Tick weiter (Minute/Tag/Jahr-Zaehler, Tageszeit-Tabelle).
extern const signed char d_1a8b5c[][3];
extern volatile int d_1c0c4c, d_1c0c58, d_1c0c5c, d_1c0c60, d_1c0c64, d_1c0c68, d_1c0c6c, d_1c0c70,
           d_1c0c74, d_1c0c78, d_1c0c7c, d_1c0c80, d_1c0c84, d_1c0c88, d_1c0c8c;
struct Time {
    volatile char c0; volatile int t; volatile signed char c5, c6, c7, c8, c9; int d; char pad[0x1a - 0xe]; volatile signed char m, n;
    void f_1261b0();
};
//@ f_1261b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Schaltet die Spielzeit - sofern die Uhr nicht über d_1c0c4c != 0 angehalten ist - um einen
 *   Untertick this->m weiter; erreicht m den Teiler this->n, wird der Tageszeitzähler this->t (0 .. 0x1fa40 - 1,
 *   also 129600 Ticks pro Tag) erhöht, periodische Intervallzähler (d_1c0c58 bei jedem Tick, d_1c0c5c alle 90,
 *   d_1c0c60 alle 450, d_1c0c64 alle 1350, d_1c0c68 alle 5400, d_1c0c6c alle 21600 Ticks) sowie feste
 *   Tageszeit-Trigger (d_1c0c84 bei 0x5460, d_1c0c7c bei 54000, d_1c0c88 bei 0x17bb0, d_1c0c8c bei 0x1d010)
 *   gesetzt und bei Mitternacht (t >= 0x1fa40) der Wochentag c5 (0..6), der Monatstag c7 (1..30, bzw. -5..0 für
 *   die fünf Namenlosen Tage nach Monat 12), der Monat c8 (1..12), das Jahr c9 und anhand der Feiertagstabelle
 *   d_1a8b5c das Feiertagskennzeichen this->c0 aktualisiert.
 * - Eingaben: this (Zeiger auf die globale Time-Instanz).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - this->t (+0x01): Aktueller Tageszeitzähler (0 .. 129599, 0x1fa40 Ticks entsprechen 24 Stunden).
 *   - this->c5 (+0x05), this->c6 (+0x06), this->c7 (+0x07), this->c8 (+0x08), this->c9 (+0x09): Wochentag
 *     (0..6), Wochenzähler, Monatstag (1..30 bzw. -5..-1 an den Namenlosen Tagen), Monat (1..12) und Jahr.
 *   - this->c0 (+0x00): Kennung eines besonderen Feiertags aus der Tabelle d_1a8b5c (0 = normaler Tag).
 *   - d_1c0c4c: Uhr-Sperrflag (0 = Spielzeit läuft, != 0 = Spielzeit pausiert).
 *   - d_1c0c58 bis d_1c0c8c: Globale Intervall- und Tageszeit-Ereignisflags für Spielmechanik, Lichtwechsel und
 *     Regeneration.
 === Ende Beschreibung === */
void Time::f_1261b0()
{
    int k = d_1c0c4c;
    int w = 0;
    if (k == 0) {


        if (m >= n) {

            m = 0;
            t++;
            d_1c0c58++;
            if (t >= 0xfd20) { t -= 0xfd20; w = 1; }
            if (t % 0x5a == 0) d_1c0c5c++;
            if (t % 0x1c2 == 0) d_1c0c60++;
            if (t % 0x546 == 0) d_1c0c64++;
            if (t % 0x1518 == 0) d_1c0c68++;
            if (t % 0x5460 == 0) d_1c0c6c++;
            if (w == 1) t += 0xfd20;
            if (t == 54000) d_1c0c7c = 1;
            if (t == 0x5460) d_1c0c84 = 1;
            if (t == 0x17bb0) d_1c0c88 = 1;
            if (t == 0x1d010) d_1c0c8c = 1;
            if (t >= 0x1fa40) {
                t = 0;
                d_1c0c70++;
                d_1c0c80 = 1;
                c5++;
                if (c5 > 6) {
                    c5 = 0;
                    if (d != 0) { d = 0; c6 = 1; }
                    else c6++;
                }
                c7++;
                if (c7 > 30) {
                    c7 = 1;
                    c8++;
                    if (c5 == 0) c6++;
                    else d = 1;
                    d_1c0c74++;
                    if (c8 > 12) c7 = -5;
                } else if (c7 == 0) {
                    c8 = 1;
                    c9++;
                    c7 = 1;
                    d_1c0c78++;
                }
                short i = 0;
                c0 = 0;
                while (d_1a8b5c[i][0] != -1) {
                    if (d_1a8b5c[i][0] == c8 && d_1a8b5c[i][1] == c7) {
                        c0 = d_1a8b5c[i][2]; return;
                    }
                    i++;
                }
            }
        } else m++;
    }
}
