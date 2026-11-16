/* === Beschreibung (Katalog) ===
 * Einheit gz_0ce7c0 (0x0CE7C0 - 0x0CE980)
 *
 * Überblick
 * Die Einheit gz_0ce7c0 enthält den Konstruktor und Destruktor der im gesamten Spiel verwendeten
 * RAII-Sperrklasse Lock (f_0ce7c0, f_0ce7e0), die das globale Unterbrechungs-/Event-Flag d_1c0b2c während
 * kritischer Abschnitte auf 0 setzt und danach wiederherstellt, sowie den statischen Initialisierer (f_0ce7f0)
 * für eine 16 Einträge umfassende Methodentabelle bei d_1bf378.
 === Ende Beschreibung === */
// I9: aus gz_0ce7c0_REST.CPP uebernommen (Stufe-2-Stand), Marken 1 neu
// gz_0ce7c0.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xCE7C0-0xCE980. Klasse Lock (merkt d_1c0b2c, setzt 0, stellt zurück) und Initialisierer einer 16er-Tabelle (Funktionszeiger) bei 0x1BF378. STAND: NICHT GLEICH (56 Befehle, nur Registerzuteilung der Konstanten in f_0ce7f0).
#pragma pack(1)
extern short d_1c0b2c;
struct Lock { Lock(); ~Lock(); short saved; };



void f_0cf900();
void f_0cf8f0();
void f_0cf8e0();
void f_0cf8d0();
void f_0cf8c0();
void f_0cf8b0();
void f_0cf8a0();
void f_0cf890();
void f_0cf880();
void f_0cf870();
void f_0cf860();
void f_0cf850();
void f_0cf840();
void f_0cf830();
void f_0cf820();
extern int d_1bf378[48];
//@ f_0ce7c0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Konstruktor der Lock-Hilfsklasse: Sichert den aktuellen Wert des globalen Flags d_1c0b2c im
 *   Objektfeld p->saved und schaltet d_1c0b2c auf 0.
 * - Eingaben:
 *   - p (Zeiger auf das zu initialisierende Lock-Objekt).
 * - Rückgabewert: Lock * - Der Objektzeiger p.
 * - Wichtige Variablen:
 *   - d_1c0b2c (Globales Interrupt-/Ereignis-Freigabeflag).
 === Ende Beschreibung === */
Lock *f_0ce7c0(Lock *p) { p->saved = d_1c0b2c; d_1c0b2c = 0; return p; }

//@ f_0ce7e0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Destruktor der Lock-Hilfsklasse: Stellt beim Verlassen des geschützten Blocks den im
 *   Konstruktor gesicherten Wert p->saved in d_1c0b2c wieder her.
 * - Eingaben:
 *   - p (Zeiger auf das Lock-Objekt).
 * - Rückgabewert: Lock * - Der Objektzeiger p.
 * - Wichtige Variablen:
 *   - d_1c0b2c (Globales Interrupt-/Ereignis-Freigabeflag).
 === Ende Beschreibung === */
Lock *f_0ce7e0(Lock *p, int) { d_1c0b2c = p->saved; return p; }
//@ f_0ce7f0
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Initialisiert beim Programmstart die 16 Einträge zu je 12 Bytes (48 Integer-Wörter) der
 *   globalen Rückruftabelle d_1bf378 mit den Funktionszeigern f_0cf900 bis f_0cf820.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1bf378 (Globale Tabelle von 16 Funktionszeiger-Deskriptoren für das Monster-/Einheitensystem).
 === Ende Beschreibung === */
void f_0ce7f0()
{
    d_1bf378[0] = 0;
    d_1bf378[1] = 0;
    d_1bf378[2] = 0;
    d_1bf378[3] = (int)f_0cf900;
    d_1bf378[4] = 0;
    d_1bf378[5] = 0;
    d_1bf378[6] = (int)f_0cf8f0;
    d_1bf378[7] = 0;
    d_1bf378[8] = 0;
    d_1bf378[9] = (int)f_0cf8e0;
    d_1bf378[10] = 0;
    d_1bf378[11] = 0;
    d_1bf378[12] = (int)f_0cf8d0;
    d_1bf378[13] = 0;
    d_1bf378[14] = 0;
    d_1bf378[15] = (int)f_0cf8c0;
    d_1bf378[16] = 0;
    d_1bf378[17] = 0;
    d_1bf378[18] = (int)f_0cf8b0;
    d_1bf378[19] = 0;
    d_1bf378[20] = 0;
    d_1bf378[21] = (int)f_0cf8a0;
    d_1bf378[22] = 0;
    d_1bf378[23] = 0;
    d_1bf378[24] = (int)f_0cf890;
    d_1bf378[25] = 0;
    d_1bf378[26] = 0;
    d_1bf378[27] = (int)f_0cf880;
    d_1bf378[28] = 0;
    d_1bf378[29] = 0;
    d_1bf378[30] = (int)f_0cf870;
    d_1bf378[31] = 0;
    d_1bf378[32] = 0;
    d_1bf378[33] = (int)f_0cf860;
    d_1bf378[34] = 0;
    d_1bf378[35] = 0;
    d_1bf378[36] = (int)f_0cf850;
    d_1bf378[37] = 0;
    d_1bf378[38] = 0;
    d_1bf378[39] = (int)f_0cf840;
    d_1bf378[40] = 0;
    d_1bf378[41] = 0;
    d_1bf378[42] = (int)f_0cf830;
    d_1bf378[43] = 0;
    d_1bf378[44] = 0;
    d_1bf378[45] = (int)f_0cf820;
    d_1bf378[46] = 0;
    d_1bf378[47] = 0;
}

