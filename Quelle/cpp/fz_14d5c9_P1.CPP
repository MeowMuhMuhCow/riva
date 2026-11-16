/* === Beschreibung (Katalog) ===
 * Einheit fz_14d5c9 (0x14D5C9 - 0x14D63F)
 *
 * Überblick
 * Diese kleine Einheit der Watcom-C-Laufzeitbibliothek enthält die Standardfunktion zur Umwandlung einer
 * Zeichenkette in eine Ganzzahl (atoi) sowie die Abfrage des noch freien Stapelspeichers (stackavail).
 === Ende Beschreibung === */
// P3 1/2 gleich (suche.py 30.10.2026, Basis fz_14d5c9_P1.CPP)
// OPT -4r -oneax -zp1 -s
// P3 0/1 gleich (suche.py 26.10.2026, Basis fz_14d5c9_P1.CPP)
// CC wcc386
extern unsigned char d_1bbfdc[];
extern unsigned d_1a9e64;
#define IX(c) d_1bbfdc[((c) + 1) & 0xff]
#define ISP(c) ((int)(unsigned char)(IX(c) & 2))
#define ISD(c) ((int)(unsigned char)(IX(c) & 0x20))
#pragma aux f_14d5c9 "f_14d5c9"
//@ f_14d5c9
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konvertiert eine nullterminierte ASCII-Zeichenkette p in einen vorzeichenbehafteten
 *   32-Bit-Integer (atoi). Sie überspringt führende Leerzeichen anhand der Zeichenklassentabelle d_1bbfdc (Bit
 *   0x02), wertet ein optionales Vorzeichen ('+' oder '-') aus und akkumuliert alle folgenden Dezimalziffern
 *   (Bit 0x20 in d_1bbfdc).
 * - Eingaben: p (Zeiger auf die umzuwandelnde Zeichenkette als const unsigned char *).
 * - Rückgabewert: Berechneter Ganzzahlwert (int).
 * - Wichtige Variablen:
 *   - d_1bbfdc: Globale ctype-Zeichenklassentabelle der Laufzeitbibliothek.
 *   - sign: Gelesenes Vorzeichenbyte ('+', '-' oder erste Ziffer).
 *   - value: Laufender Dezimalwert.
 === Ende Beschreibung === */
int f_14d5c9(const unsigned char *p)
{
    int value;
    unsigned ix; unsigned char flags; // codeloser Tabellen-Roundtrip und frisches Feldlesen halten den Index im Originalregister
    unsigned char sign=0;
    while ((int)(unsigned char)(d_1bbfdc[(unsigned char)(*p+1)] & 2)) p++;
    sign=*p;
    if ((int)sign=='+' || (int)sign=='-') p++;
    value=0;
    while ((ix=(unsigned char)(*p+1)), (flags=d_1bbfdc[ix]), (d_1bbfdc[ix]=flags), ((int)(unsigned char)(d_1bbfdc[ix]&0x20)))
{
    sign = (sign & 0) ? (unsigned char)0 : sign; // haelt das Live-Range-Web von sign ueber die Ziffernschleife im Originalregister
    value = value * 10 + *p;
    p++;
    value -= '0';
}
    if ((int)sign=='-') value=-value;
    return value;
}


/* Original liest ESP direkt; kein Aufrufer muss ein Argument vorbereiten.
   Die codefreie ABI-Angabe bindet nur diesen vorhandenen Eingangswert. */
#pragma aux f_14d636 "f_14d636" parm [esp] value [eax] modify exact [eax]
//@ f_14d636
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Berechnet die aktuell noch auf dem CPU-Stack verfügbare Byteanzahl (stackavail), indem die
 *   untere Stackgrenze d_1a9e64 vom aktuellen Stackpointer ESP abgezogen wird.
 * - Eingaben: Liest direkt das CPU-Register ESP (stack_pointer).
 * - Rückgabewert: Freier Stapelspeicher in Bytes (unsigned).
 * - Wichtige Variablen: d_1a9e64 (untere Grenze des Stacksegments).
 === Ende Beschreibung === */
unsigned f_14d636(unsigned stack_pointer)
{
    return stack_pointer - d_1a9e64;
}
