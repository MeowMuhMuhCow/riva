/* === Beschreibung (Katalog) ===
 * Einheit gz_1206a0 (0x1206A0-0x1206C0)
 *
 * Überblick
 * Die kleine Einheit gz_1206a0 liegt zwischen der 3D-Initialisierung (tdminit2) und dem 3D-Demo-Interpreter
 * (tdmintrp) und enthält den Timer-Callback für die getaktete 3D-Bewegungs- und Demo-Verarbeitung.
 === Ende Beschreibung === */
// P3 0/1 gleich (suche.py 25.10.2026, Basis gz_1206a0_P1.CPP)
// I9: aus G1206A0.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// gz_1206a0 (0x1206A0-0x1206C0), zwischen tdminit2.cpp und tdmintrp.cpp
extern unsigned short d_1c0b2c;
extern volatile short d_1c0b28;
int f_120880();
//@ f_1206a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dient als periodische Rückruffunktion des Zeitgebers im 3D-Bewegungs- und Demo-Modus. Ist
 *   die 3D-Taktverarbeitung aktiv (d_1c0b2c != 0), erhöht die Funktion den Schrittzähler d_1c0b28 um 1 und ruft
 *   f_120880 auf, um einen Bewegungs- bzw. Demo-Schritt auszuführen; andernfalls kehrt sie sofort mit 0 zurück.
 * - Eingaben: Keine.
 * - Rückgabewert: int (0, wenn die Taktverarbeitung deaktiviert ist, sonst der Rückgabewert von f_120880).
 * - Wichtige Variablen:
 *   - d_1c0b2c (unsigned short): Freigabeschalter für den getakteten 3D-Demo-/Bewegungsschritt (0 = pausiert).
 *   - d_1c0b28 (volatile short): Laufender Zähler der ausgeführten Timer-Schritte.
 === Ende Beschreibung === */
int f_1206a0()
{
    if ((short)d_1c0b2c == 0) return 0;
    d_1c0b28++;
    return f_120880();
}
