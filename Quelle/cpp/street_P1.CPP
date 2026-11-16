/* === Beschreibung (Katalog) ===
 * Einheit street (0x11E500-0x11E6D0)
 *
 * Überblick
 * Die Einheit street (im Original street.cpp) umfasst die zentrale Auswahl- und Startfunktion für zufällige
 * Straßenbegegnungen während des Stadtrundgangs in Riva.
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 25.10.2026, Basis street_P1.CPP)
// I9: aus STREET.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// street.cpp (0x11E500-0x11E6D0)
#include <stdarg.h>
#include "R_FIX.H"
extern "C" void *memset(void *p, int c, unsigned n);
short f_1457e0(short n);                                 // Zufallszahl 1..n
extern long d_1c0a3c[21];                                // Straßenflags
extern signed char d_1c0a28, d_1c0a2c, d_1c0a30, d_1c0a34, d_1c0a38;
extern short d_1c0a90[3];                                // die letzten drei Ereignisse
extern void (*d_1a7e38[])();                             // Ereignistabelle (eigene Daten, vorerst extern)
inline int f_a28() { return d_1c0a28 == 0; }
inline int f_a2c() { return d_1c0a2c == 1; }
inline int f_a30() { return d_1c0a30 == 1; }
inline int f_a34() { return d_1c0a34 == 1; }
inline int f_a38() { return d_1c0a38 == 1; }

static inline int EQBF(const signed char &x,int v){return x==v;}
#define EQB(x,v) EQBF((x),(v))
//@ f_11e500
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft beim Betreten eines Straßenabschnitts in Riva mit einer Wahrscheinlichkeit von 1 zu
 *   30 (f_1457e0(30) == 1), ob eine zufällige Straßenbegegnung ausgelöst wird, sofern Straßenbegegnungen nicht
 *   global gesperrt sind (d_1c0a28 == 0). Dazu markiert die Funktion zunächst alle über die variable
 *   Argumentliste übergebenen, an diesem Ort möglichen Ereignis-Kennungen (1..20) in der Freigabetabelle
 *   d_1c0a3c, streicht bereits erledigte oder durch Story-Flags (d_1c0a2c bis d_1c0a38) gesperrte Ereignisse
 *   sowie die letzten drei bereits eingetretenen Begegnungen (d_1c0a90[0..2]) heraus, wählt aus den
 *   verbleibenden Kandidaten zufällig ein Ereignis aus, trägt es in die Historie d_1c0a90 ein und ruft die
 *   zugehörige Ereignisfunktion über die Sprungtabelle d_1a7e38[r]() auf.
 * - Eingaben: short n (Anzahl der nachfolgenden Ereignis-Kennungen), ... (n Werte vom Typ short mit den am
 *   aktuellen Straßenpunkt zulässigen Ereignis-IDs im Bereich 1..20).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0a3c (long[21]): Kandidatenfeld für die Ereignis-Kennungen 1..20 (1 = am aktuellen Ort möglich, 0 =
 *     ausgeschlossen).
 *   - d_1c0a28 (signed char): Globaler Sperrschalter für Straßenbegegnungen (0 = Begegnungen erlaubt).
 *   - d_1c0a2c, d_1c0a30, d_1c0a34, d_1c0a38 (signed char): Story-Fortschrittsflags für die gestaffelten
 *     Straßenereignisse 3, 4, 5 und 6 (wobei Ereignis 4 Vorrang vor 5 und 6 hat und Ereignis 5 Vorrang vor 6).
 *   - d_1c0a90 (short[3]): Ringpuffer der letzten drei ausgelösten Straßenereignisse zur Vermeidung
 *     unmittelbarer Wiederholungen.
 *   - d_1a7e38 (void (*[])()): Funktionszeigertabelle der Straßenbegegnungen in Riva.
 *   - Hinweis (Originalfehler): Die Zählschleife for (i = 0; i < 20; i++) prüft nur die Indizes 0..19 statt
 *     1..20. Dadurch wird das Ereignis 20 (0x14, das u. a. in cityriva_t1 und gz_0478d0 übergeben wird) bei der
 *     Ermittlung von cnt nicht mitgezählt und fällt unter den Tisch, sobald alle anderen übergebenen Kandidaten
 *     bereits in d_1c0a90[0..2] stehen.
 === Ende Beschreibung === */
void f_11e500(short n, ...)
{
    va_list ap;
    short i, r, cnt;
    va_start(ap, n);
    memset(d_1c0a3c, 0, sizeof d_1c0a3c);
    for (i = 0; i < n; i++) {
        short a = va_arg(ap, short);
        d_1c0a3c[a] = 1;
    }
    r = 0;
    if (EQBF(d_1c0a28,0) && f_1457e0(30) == 1) {
        if (f_a2c()) d_1c0a3c[3] = 0;
        if (f_a30()) d_1c0a3c[4] = 0;
        if (f_a34()) d_1c0a3c[5] = 0;
        if (f_a38()) d_1c0a3c[6] = 0;
        if (d_1c0a3c[4] == 1) { d_1c0a3c[5] = 0; d_1c0a3c[6] = 0; }
        else if (d_1c0a3c[5] == 1) d_1c0a3c[6] = 0;
        for (i = 0; i < (short)3; ) {
            short a = ((short *)d_1c0a90)[i++];
            d_1c0a3c[a] = 0;
        }
        cnt = 0;
#if FIX_R055   /* R055: Strassenbegegnungen sind 1..20 (1-basiert); Index 20 in cnt mitzaehlen */
        for (i = 1; i <= (short)20; i++) if (d_1c0a3c[i] == 1) cnt++;
#else
        for (i = 0; i < (short)20; i++) if (d_1c0a3c[i] == 1) cnt++;
#endif
        if (cnt > 0) {
            do r = f_1457e0(20); while (d_1c0a3c[r] == 0);
        }
    }


    short selected = r;
    if ((short)(r & 0xffff) > 0 && r <= (short)20) {
        int k; for(i=0;(k=i)<2;i++) ((short *)d_1c0a90)[k]=((short *)d_1c0a90)[k+1];
        ((short *)d_1c0a90)[2] = r;
        d_1a7e38[selected]();
    }
}
