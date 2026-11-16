/* === Beschreibung (Katalog) ===
 * Einheit xdialog_t2 (0x141D30 - 0x142F70)
 *
 * Überblick
 *
 * Die Einheit xdialog_t2 bildet den zweiten Hauptteil des erweiterten Multiple-Choice-Dialogsystems
 * (xdialog.cpp). Sie enthält den Interpreter für mehrstufige Gesprächsverzweigungen (f_141d30) und
 * Skriptsequenzen (f_141ef0), die Behandlung unbekannter oder erschöpfter Gesprächsthemen (f_141fc0), die
 * Hauptauswahl eines Themas (f_1422a0), die Tastatur- und Mausnavigation in der rechten Themenliste sowie in den
 * Antwortoptionen (f_142390 bis f_142d20) und die Eröffnungs- und Abschlusssequenz eines Gesprächs (f_142e10 und
 * f_142e90).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
#include "RIVAFILE.H"
// P3 11/17 gleich (suche.py 30.10.2026, Basis xdialog_t2_P1.CPP)
// xdialog.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x140B40-0x143330
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e240(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_01e290(int p1, int p2);                           // reg eax stapel 0
int f_01e3a0(int p1, int p2);                           // reg eax edx stapel 0
int f_01e430(int p1, int p2);                           // reg eax edx stapel 0
int f_01e570(int p1);                                   // reg eax stapel 0
int f_04fe60(int p1, int p2);                           // reg eax stapel 0
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);// reg eax ebx ecx stapel 12
int f_05e1f0(int p1);                                   // reg eax stapel 0
int f_05e200(int p1);                                   // reg eax stapel 0
int f_05e270(int p1, int p2);                           // reg eax stapel 0
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_05e320(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e360(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_05e420(int p1, int p2);                           // reg eax edx stapel 0
int f_05e440(int p1, int p2);                           // reg eax stapel 0
int f_068f40();                                         // reg - stapel 0
int f_069460();                                         // reg - stapel 0
int f_0bf680(int p1);
int f_0bf6c0(int p1, int p2);                           // reg eax edx stapel 0
int f_0ce7c0(int p1);                                   // reg eax stapel 0
int f_0ce7e0(int p1, int p2);                           // reg eax stapel 0
                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3770();                                         // reg - stapel 0
int f_0d3780();                                         // reg - stapel 0
int f_0d37b0();                                         // reg - stapel 0
                                         // reg - stapel 0
int f_0d3870();                                         // reg - stapel 0
int f_0d5b50(int p1);                                   // reg eax stapel 0
int f_0e93f0(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0e9550(int p1, int p2);                           // reg eax edx stapel 0
int f_0e9660(int p1, int p2, int p3, int p4);           // reg ebx ecx stapel 0
                   // reg eax edx ebx stapel 0
                           // reg eax stapel 0
           // reg eax edx ebx ecx stapel 0
   // reg eax edx ebx ecx stapel 4
           // reg eax edx ebx ecx stapel 0
                                   // reg eax stapel 0
                   // reg eax ebx stapel 0
                   // reg eax stapel 0
                   // reg eax edx ebx stapel 0
                   // reg eax edx ebx stapel 0
                                   // reg eax stapel 0
           // reg eax stapel 0
                   // reg eax edx ebx stapel 0
int f_145970(int p1, int p2);                           // reg eax edx stapel 0
int f_1459d0(int p1);                                   // reg eax stapel 0
int f_145a10(int p1, int p2, int p3);                   // reg - stapel 0
int f_145b10(int p1);                                   // reg eax stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern int d_1a94b0;                    // 0x1A94B0
extern int d_1a9564;                    // 0x1A9564
extern int d_1a965c;                    // 0x1A965C
extern int d_1bf510;                    // 0x1BF510
extern int d_1bf514;                    // 0x1BF514
extern int d_1bf520;                    // 0x1BF520
extern int d_1bf524;                    // 0x1BF524
extern int d_1c1160;                    // 0x1C1160
extern int d_1c1168;                    // 0x1C1168
                    // 0x1C2098
extern int d_1c2c64;                    // 0x1C2C64
extern int d_1c38b0;                    // 0x1C38B0
extern const char d_1a948c[];           // Text 0x1A948C
// --- eigene Funktionen (36), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_140b40  groesse 448 B, 114 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut den grafischen Rahmen des Dialogbildschirms auf: Reserviert bei Bedarf vier Hintergrund-
 *   und Schaltflächenpuffer (p1[0] für das linke Textfeld 201x149 bei (10, 50), p1[1] für die rechte Themenliste
 *   93x194 bei (226, 5), p1[2] und p1[3] für die ungedrückte und gedrückte "Ende"-Schaltfläche 92x16), zeichnet
 *   das Dialog-Hintergrundbild 0x150004 auf den Bildschirm, sichert die beiden Textfeld-Hintergründe aus dem
 *   Bildspeicher und lädt die beiden Schaltflächen-Sprites aus der Ressource 0x150005.
 * - Eingaben: Zeiger p1 (int *) auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - a: Lokales Bildlader-Objekt (164 Bytes) für das Hintergrundbild 0x150004.
 *   - b: Lokales Sprite-Lader-Objekt (32 Bytes) für die Schaltflächengrafiken 0x150005.
 *   - p1[0] bis p1[3]: Grafikpuffer für Haupttextfeld, Themenliste und die beiden Zustände der
 *     Beenden-Schaltfläche.
 === Ende Beschreibung === */
//@ f_140d00  groesse 224 B, 69 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt die binäre Dialogressource self->fileId über den Dateimanager d_1c2098 in einen neu
 *   angelegten Puffer self->data und richtet die acht Abschnittszeiger p0 bis p7 (für Porträt-/Kopfdaten,
 *   Themenzuordnung, Themenphasen, Aktionsskripte, Antwortverzweigungen, Textabsätze, Parameterlisten und
 *   Rohtexte) anhand des Dateikopfes (Meta680) ein.
 * - Eingaben: Zeiger self (Dialog680 *) auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - n: Dateigröße der Dialogressource self->fileId in Bytes.
 *   - header: Zeiger auf den 40-Byte-Kopfblock (Meta680) am Anfang von self->data.
 *   - self->height: Aus dem ersten Datenblock (*(short *)(self->p0 + 6) + 3) gelesene Zeilenhöhe.
 === Ende Beschreibung === */
//@ f_140de0  groesse 320 B, 47 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den bisherigen Gesprächsstand für den aktuellen Dialogpartner (PS(p1, 0x1F)) aus der
 *   temporären Spielstandsdatei 0x40000000 (in dem Unterverzeichnis PI(p1, 0x1B)): Positioniert den Dateizeiger
 *   auf den Datensatz (PB(p1, 0x1A) + 4) * PS(p1, 0x1F) + 6 und liest das 4-Byte-Flag "bereits begrüßt" (p1 +
 *   0x9B) sowie das Array der aktuellen Themenphasen (PI(p1, 0xAB), Länge PB(p1, 0x1A)).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sv: Gesicherter vorheriger Archiv-/Pfadkontext d_1a965c.
 === Ende Beschreibung === */
//@ f_140e90  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt den aktuellen Gesprächsstand des Dialogpartners (p1 + 0x9B und das Themenphasen-Array
 *   PI(p1, 0xAB)) an die zugehörige Offsetposition (PB(p1, 0x1A) + 4) * PS(p1, 0x1F) + 6 in der temporären
 *   Spielstandsdatei 0x40000000 zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sv: Gesicherter vorheriger Wert von d_1a965c.
 === Ende Beschreibung === */
//@ f_140f20  groesse 256 B, 138 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut die Liste der aktuell im Gespräch verfügbaren Stichworte (Themen) neu auf: Leert den
 *   Textspeicher PI(p1, 0x59), setzt alle Einträge im Sichtbarkeitsarray PI(p1, 0x61) zunächst auf 0xFF
 *   (unsichtbar), durchläuft die Themen-Zuordnungstabelle PI(p1, 0x3D) und trägt jedes Thema i, das entweder ein
 *   allgemeines Thema (i >= PB(p1, 0x18)) oder im Freischaltarray PI(p1, 0x14) aktiviert ist, mit seinem Namen
 *   (0x15020002 + i) in die Auswahlliste ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - q: Laufzeiger über die 6-Byte-Einträge der Themen-Zuordnungstabelle PI(p1, 0x3D).
 *   - PB(p1, 0x65): Zähler für die Anzahl der aktuell in der rechten Spalte sichtbaren Gesprächsthemen.
 *   - PI(p1, 0x5D): Gültigkeitsflag der Themenliste (wird am Ende auf 1 gesetzt).
 === Ende Beschreibung === */
//@ f_141020  groesse 448 B, 115 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das 32x32 Pixel große Porträt des aktuellen Gesprächspartners (Sprite-Index PS(PI(p1,
 *   0x39), 4) aus der Porträtdatei 0x150000), zeichnet es an die Position (12, 9) links oben ins Dialogfenster
 *   und gibt daneben den Namen des Gesprächspartners (*PI(p1, 0x39) + PI(p1, 0x55)) mit schwarzem Schatten
 *   (0xFE) und weißer Schrift (0xFF) aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - b: Lokales Sprite-Lader-Objekt (32 Bytes) für 0x150000.
 *   - s: Temporäres 32x32-Grafikobjekt für das NSC-Porträt.
 *   - l24, l2c, l20, l1c, l18, l28: Gesicherte Textfenster-Ränder und Textfarben von d_1c38b0.
 === Ende Beschreibung === */
//@ f_1411e0  groesse 304 B, 136 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die p2-te sichtbare Themenzeile in der rechten Auswahlspalte bei x = 226, y = 5 + 9 *
 *   (p2 - 1) mit Schatteneffekt (0xFE) und der angegebenen Vordergrundfarbe p3 (z. B. 0xFF für normal, 0xFC für
 *   hervorgehoben, 0xCD für abgeblendet).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, 1-basierte sichtbare Zeilennummer p2 (signed char) und Farbwert
 *   p3 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ermittelter interner Themenindex zur sichtbaren Zeile p2.
 *   - s2: Zeiger auf die Zeichenkette des Themennamens aus dem Textpuffer PI(p1, 0x59).
 === Ende Beschreibung === */
//@ f_141310  groesse 272 B, 73 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die Beschriftung der "Ende"-Schaltfläche (Textkennung 0x15010002) zentriert im
 *   Bereich (225, 179) (92x16 Pixel) mit schwarzem Schatten (0xFE) und der gewünschten Textfarbe p2.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Textfarbe p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - w, h: Gemessene Pixelbreite und -höhe des Schaltflächentextes.
 *   - x, y: Zentrierte Ausgabekoordinaten auf der Schaltfläche.
 === Ende Beschreibung === */
//@ f_141420  groesse 192 B, 69 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die gesamte rechte Themenauswahlspalte sowie die "Ende"-Schaltfläche in der Farbe p2
 *   neu. Wurde die Themenliste zuvor als veraltet markiert (PI(p1, 0x5D) == 0, etwa weil im Gespräch ein neues
 *   Stichwort freigeschaltet wurde), stellt die Funktion zuerst den Spaltenhintergrund PI(p1, 4) wieder her und
 *   baut die Themenliste über f_140f20 neu auf.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Textfarbe p2 (int, z. B. 0xFF aktiv oder 0xCD inaktiv).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - c: Schleifenzähler (1 bis PC(p1, 0x65)) über alle sichtbaren Themenzeilen.
 === Ende Beschreibung === */
//@ f_1414e0  groesse 832 B, 190 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert und zeichnet einen einzelnen 14-Byte-Textblock p2 im linken Haupttextfenster: Löst
 *   gegebenenfalls dynamische Platzhalter (*(int *)(p2 + 3) != -1) über den Callback PI(p1, 0x2D) und sprintf
 *   auf, setzt bei wörtlicher Rede (*p2 == 1 für NSC oder *p2 == 2 für Held) Anführungszeichen <...>, wählt die
 *   Sprecherfarbe (0xF9, 0xFF, 0xF0 oder bei hervorgehobener Auswahl p3 == 1 die Farbe 0xFC) und gibt den Absatz
 *   samt Zeilenumbruch (d_1b870a) über den Textrenderer d_1c38b0 aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, Zeiger p2 (short *) auf den 14-Byte-Absatzdatensatz und
 *   Hervorhebungsflag p3 (int, 1 = aktiv markierte Antwortoption, 0 = normal).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - a: Array von bis zu 10 aufgelösten Platzhalter-Strings (a.v[0]..a.v[9]) für sprintf.
 *   - t: Sprecher-/Darstellungsart (*p2: 1 = NSC, 2 = Held, 3 = Beschreibung).
 === Ende Beschreibung === */
//@ f_141720  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt eine Folge von 14-Byte-Textabsätzen ab p2 im Haupttextfenster aus, indem f_1414e0 in
 *   einer Schleife für jeden Absatz aufgerufen wird, bis die Ende-Markierung *p2 == 4 erreicht ist.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz, Startzeiger p2 (short *) auf die Absatzliste und
 *   Hervorhebungsflag p3 (int).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine eigenen lokalen Variablen (nutzt RivaMouseGuard).
 === Ende Beschreibung === */
//@ f_141780  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt die Klick-Animation der "Ende"-Schaltfläche beim Verlassen des Dialogs ab: Zeichnet das
 *   gedrückte Schaltflächen-Sprite PI(p1, 8) mit dunkler Beschriftung (0xC9), wartet 500 Zeiteinheiten
 *   (f_149cf0(0x1F4)), stellt das ungedrückte Sprite PI(p1, 0x0C) mit heller Beschriftung (0xFF) wieder her und
 *   wartet weitere 100 Einheiten.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
//@ f_141820  groesse 304 B, 72 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt am unteren Rand des linken Textfensters (y = 191) in Farbe 0xFC den Hinweis "Weiter..."
 *   (0x15010005) an, schaltet den Mauszeiger auf das Warte-/Weiter-Symbol (f_0d5b50(1)) und wartet in einer
 *   Ereignisschleife, bis der Spieler eine Taste drückt (d_1bd762 != 0) oder eine Maustaste betätigt (f_0d3780 /
 *   f_0d37b0).
 * - Eingaben: Keine (bzw. ungenutzter Dialogzeiger).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - l1c, l18, l14, l10, l20, l24: Gesicherte Textbereichs- und Farbeinstellungen von d_1c38b0.
 *   - sv: Gesicherter Zustand des Maus-Rechteck-Flags d_1bf51c.
 === Ende Beschreibung === */
//@ f_141950  groesse 240 B, 69 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Arbeitet eine bedingte Sequenz von 14-Byte-Redeabsätzen ab p2 im Haupttextfenster (x =
 *   10..201, y = 50) ab: Prüft für jeden Eintrag (*p2 != 4) über die Bedingungsfunktion PI(p1, 0x25) mit der
 *   Bedingungsnummer p2[1], ob der Absatz gültig ist, gibt ihn bei r == 1 über f_1414e0 aus und führt
 *   anschließend die zugehörige Folgeaktion p2[2] über den Aktions-Callback PI(p1, 0x29) aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (short *) auf die bedingte Absatzsequenz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ergebnis der Bedingungsprüfung (1 = Bedingung erfüllt, Absatz anzeigen und Aktion ausführen).
 === Ende Beschreibung === */
//@ f_141a40  groesse 448 B, 124 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet bis zu drei Multiple-Choice-Antwortmöglichkeiten aus dem aktuellen Verzweigungsblock
 *   PI(p1, 0x95) untereinander in das linke Textfenster und trägt für jede Antwortoption das umgebende
 *   Bildschirmrechteck (x0, y0, x1, y1) sowie den Rückgabecode 0x90 + Index in die Klickzonentabelle ab p1 +
 *   0x6B ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - PC(p1, 0x93): Anzahl der aufgebauten Antwortoptionen (0 bis 3).
 *   - p1 + 0x6B: Array von 10-Byte-Klickzonen (x0, y0, x1, y1, id), das hinter der letzten Antwort mit 0xFFFF
 *     terminiert wird.
 === Ende Beschreibung === */
//@ f_141c00  groesse 304 B, 68 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wertet eine Gesprächsverzweigung (PI(p1, 0x95)) aus: Besitzt der Knoten keine
 *   Auswahlmöglichkeiten für den Spieler (PI(PI(p1, 0x95), 6) == -1), wird automatisch der erste Folgezweig
 *   (PS(p1, 0x99) = 1) gewählt und bei p2 == 1 über f_141820 auf einen Klick gewartet; andernfalls baut die
 *   Funktion die Antwortoptionen über f_141a40 auf, aktiviert deren Maus-Klickzonen (p1 + 0x6B) und wartet in
 *   einer Eingabeschleife (f_142d20 / f_142920), bis der Spieler eine Antwort gewählt hat. Gibt anschließend den
 *   Folge-Knotenindex aus *(short *)(ix * 2 + base + 0x10) zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Warte-Flag p2 (int, 1 = bei direktem Weiterlaufen ohne
 *   Antwortwahl auf "Weiter..."-Klick warten).
 * - Rückgabewert: Der 16-Bit-Index des nächsten Verzweigungsblocks (-1, wenn der Verzweigungsbaum endet).
 * - Wichtige Variablen:
 *   - u1 bis u5: Gesicherte globale Mauszonen- und Callback-Zeiger (d_1bf510..d_1bf524).
 *   - ix: Index der vom Spieler gewählten Antwort (PS(p1, 0x99)).
 === Ende Beschreibung === */
//@ f_141d30  groesse 448 B, 173 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft einen Baum aus Multiple-Choice-Gesprächsknoten ab der Startadresse p2: Schaltet das
 *   Dialogobjekt in den Antwortauswahl-Modus (I4(p1 + 0x67) = 1), löscht für jeden Knoten das linke Textfeld,
 *   gibt die einleitende NSC-Rede (listd30907) aus, führt über den Callback p1 + 0x29 die Knoten-Aktion aus und
 *   lässt den Spieler über f_141c00 eine Antwort wählen, bis der Folgeindex -1 erreicht wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Startadresse p2 (int) des Verzweigungsbaums.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - base: Basisadresse der Verzweigungstabelle (p2), relativ zu der jeder Folgeknoten base + r * 0x18
 *     adressiert wird.
 *   - l30: Flag (1, wenn nach einer NSC-Aussage ohne Antwortoptionen noch ein Folgeknoten kommt und daher auf
 *     "Weiter..." gewartet werden soll).
 === Ende Beschreibung === */
//@ f_141ef0  groesse 208 B, 58 Bef, reg eax edx, stapel ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine aus 8-Byte-Befehlen aufgebaute Dialog-Skriptsequenz ab p2 bis zur Endmarkierung
 *   I2(p2) == 3 aus. Prüft für jeden Schritt über den Bedingungs-Callback p1 + 0x25 die Bedingung I2(p2 + 2):
 *   Ist sie erfüllt, wird bei Befehlstyp 1 eine bedingte Textsequenz über f_141950 ausgegeben (und falls noch
 *   ein weiterer erfüllter Schritt folgt, über f_141820 auf "Weiter..." gewartet) oder bei Befehlstyp 2 über
 *   f_141d30 in einen Multiple-Choice-Verzweigungsbaum verzweigt.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (int) auf die Skriptsequenz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - addr: Berechnete Zieladresse für die Textsequenz (I4(p1 + 0x4D) + I4(p2 + 4)) bzw. den Verzweigungsbaum
 *     (I4(p1 + 0x49) + I4(p2 + 4)).
 === Ende Beschreibung === */
//@ f_141fc0  groesse 736 B, 227 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt den Fall, dass ein angesprochenes Thema p2 beim aktuellen NSC keine eigene
 *   Skriptantwort (mehr) besitzt: Gibt zunächst die Standardfrage des Helden (p2 * 2 + 0x15030001) in Farbe 0xF9
 *   aus und zeigt darunter entweder den zum Thema gehörenden allgemeinen Standard-Ablehnungstext (p2 * 2 +
 *   0x15030002, falls der NSC keinen eigenen Ablehnungseintrag in choices[selected + 3] besitzt) oder den
 *   NSC-spezifischen Standard-Ablehnungssatz an.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Themenindex p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - mg.index: Doppelter Themenindex (p2 * 2) zur Berechnung der Standardtext-Kennungen 0x15030001 und
 *     0x15030002.
 *   - selected: Index der speziellen Standard-Einträge (UC(p1 + 0x19)).
 === Ende Beschreibung === */
//@ f_1422a0  groesse 240 B, 79 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ein einzelnes gewähltes Gesprächsthema p2 aus: Blendet die rechte Themenliste während
 *   der Textausgabe grau ab (f_141420(p1, 0xCD)), sucht in der Themen-Zuordnungstabelle I4(p1 + 0x3D) und dem
 *   Phasen-Array I4(p1 + 0xAB) das zur aktuellen Gesprächsphase gehörende Skript; ist dort -1 eingetragen
 *   (unbekanntes Thema), ruft die Funktion die Standardablehnung f_141fc0 auf und erhöht den Ungeduldszähler des
 *   NSCs (ps[idx]++), andernfalls startet sie das Skript über f_141ef0, schaltet je nach Steuercode I2(p1 +
 *   0xA9) die Themenphase weiter (0 = nächste Phase, 1 = gleiche Phase beibehalten, 2 = auf Phase 0
 *   zurücksetzen) und blendet die Themenliste anschließend wieder aktiv (0xFF / 0xFC) ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Themenindex p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sel: 0-basierter Index des Themas (I2(q) - 1).
 *   - addr: Adresse des 32-Bit-Skriptoffsets für die aktuelle Phase des Themas.
 === Ende Beschreibung === */
//@ f_142390  groesse 240 B, 47 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert im Themenauswahl-Modus (I4(p1 + 0x67) == 0) die optische Hervorhebung in der rechten
 *   Spalte von der bisherigen Position cur (SC(p1 + 0x66)) auf die neue Position p2 (1..SC(p1 + 0x65) für ein
 *   Thema oder -1 für die "Ende"-Schaltfläche), indem der alte Eintrag wieder weiß (0xFF) und der neue
 *   gelb/hervorgehoben (0xFC) gezeichnet wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und neue Auswahlposition p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - cur: Bisher hervorgehobene Zeilenposition (SC(p1 + 0x66)).
 === Ende Beschreibung === */
//@ f_142410  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst im Themenauswahl-Modus (I4(p1 + 0x67) == 0) das p2-te sichtbare Thema aus der rechten
 *   Spalte aus, indem der zugehörige interne Themenindex r ermittelt und an f_1422a0(p1, r) übergeben wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und 1-basierte sichtbare Zeilennummer p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ermittelter interner Themenindex.
 === Ende Beschreibung === */
//@ f_142480  groesse 288 B, 104 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet Tastatureingaben (0xA4 = Pfeil hoch, 0xA5 = Pfeil runter, 0xA6 = Eingabetaste)
 *   innerhalb der rechten Themenauswahlspalte: Bewegt den Auswahlbalken zyklisch durch die sichtbaren Themen und
 *   die "Ende"-Schaltfläche (-1) oder startet bei 0xA6 das aktuell markierte Thema über f_1422a0.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Tastencode p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Neu berechnete Auswahlposition in der Themenliste.
 === Ende Beschreibung === */
//@ f_1425a0  groesse 432 B, 128 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert im Multiple-Choice-Antwortmodus (I4(p1 + 0x67) == 1) die optisch hervorgehobene Antwort
 *   im linken Textfenster von SC(p1 + 0x94) auf die neue Antwortnummer p2 (1 bis SC(p1 + 0x93)), indem der alte
 *   Antworttext im Normalmodus (mode = 0) und der neue im Hervorhebungsmodus (mode = 1, Farbe 0xFC) neu
 *   gezeichnet wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und 1-basierte Antwortnummer p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - pos: Tabellenoffset (Index - 1) * 5 in der Koordinatentabelle p1 + 0x6B.
 === Ende Beschreibung === */
//@ f_142700  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übernimmt im Multiple-Choice-Antwortmodus (I4(p1 + 0x67) == 1) die per Maus angeklickte
 *   Antwortnummer p2 nach I2(p1 + 0x99) und wartet, bis der Spieler die linke Maustaste wieder loslässt
 *   (f_0d3780).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und gewählte Antwortnummer p2 (short).
 * - Rückgabewert: 1 bei gültiger Antwortwahl, sonst 0.
 * - Wichtige Variablen:
 *   - u: Erfolgsflag (1, wenn p2 im Bereich 1..SC(p1 + 0x93) liegt).
 === Ende Beschreibung === */
//@ f_142750  groesse 464 B, 49 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet Tastatureingaben (0xA4 = Pfeil hoch, 0xA5 = Pfeil runter, 0xA6 = Eingabetaste) im
 *   Multiple-Choice-Antwortmodus: Bewegt die Hervorhebung über f_1425a0 zyklisch zwischen den bis zu drei
 *   Antworten im linken Textfenster oder bestätigt bei 0xA6 die aktuell markierte Antwort SC(p1 + 0x94).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Tastencode p2 (short).
 * - Rückgabewert: 1, wenn eine Antwort mit der Eingabetaste (0xA6) bestätigt wurde, sonst 0.
 * - Wichtige Variablen:
 *   - s: Neue Antwortnummer nach Pfeiltastenbewegung.
 === Ende Beschreibung === */
//@ f_142800  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt einen rohen BIOS-/Tastaturcode aus d_1bd762 (0x4800 = Pfeil hoch, 0x5000 = Pfeil
 *   runter, 0x1C0D = Enter, 0x4900 = Bild hoch, 0x011B = Escape) in den entsprechenden internen
 *   Dialog-Steuercode (0xA4 bis 0xA8).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz (zur Prüfung von I4(p1 + 0x67) bei Escape/Bild hoch).
 * - Rückgabewert: Interner Steuercode (0xA4-0xA8) oder 0, falls keine relevante Taste gedrückt wurde.
 * - Wichtige Variablen:
 *   - a: Aktueller Tastaturcode aus d_1bd762.
 === Ende Beschreibung === */
//@ f_142890  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ergänzt einen aus der Tastatur gelesenen Steuercode *p2 um Mausklick-Ereignisse: Wurde keine
 *   Taste gedrückt (*p2 == 0), wird der aktuelle Mauszonen-Code d_1bd766 übernommen; wurde im Themenmodus (I4(p1
 *   + 0x67) == 0) die rechte Maustaste (f_0d37b0) gedrückt, wird der Code 0xA7 (Rückfrage zum Beenden des
 *   Gesprächs) eingetragen.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (short *) auf den aktuellen Steuercode.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
//@ f_1428c0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet beim Rechtsklick im Dialog ein kleines Bestätigungsfenster (f_0bf820 auf d_1c2c64) mit
 *   der Frage, ob das Gespräch beendet werden soll (0x15010001, Optionen 0x15010002 "Ende" und 0x15010003
 *   "Weiterreden"), und liefert bei Bestätigung den Beenden-Code 0xA8.
 * - Eingaben: Keine.
 * - Rückgabewert: 0xA8, wenn der Spieler das Gespräch beenden möchte, sonst 0.
 * - Wichtige Variablen:
 *   - p2: Gewählte Schaltfläche im Bestätigungsdialog (1 = Beenden).
 === Ende Beschreibung === */
//@ f_142920  groesse 1024 B, 333 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentrale Eingabe- und Ereignisauswertung für einen einzelnen Durchlauf der Dialogschleife:
 *   Liest Tastatur- und Mausaktionen (key800_907, keyfix890_907), behandelt das Beenden über Escape/Schaltfläche
 *   (0xA8 mit dlgclose_907) oder Rechtsklick-Bestätigung (0xA7), startet angeklickte Themen (0x81-0x8F) oder
 *   Multiple-Choice-Antworten (0x90-0x92), verarbeitet Pfeiltasten/Enter (0xA4-0xA6) und prüft schließlich, ob
 *   der Ungeduldszähler des NSCs das Limit I2(p1 + 0xA7) erreicht hat (woraufhin der NSC das Gespräch mit I4(p1
 *   + 0x9F) = 1 abbricht).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: 1, wenn die aktuelle Auswahlschleife beendet werden soll (Antwort gewählt oder Gespräch
 *   beendet), sonst 0.
 * - Wichtige Variablen:
 *   - key: Ermittelter Tastatur- oder Mauszonen-Code.
 *   - tbl: Zeiger auf das Array der NSC-Ungeduldszähler (I4(p1 + 0x21)).
 === Ende Beschreibung === */
//@ f_142d20  groesse 240 B, 57 Bef, reg -, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die optische Hover-Hervorhebung im Dialogfenster, sobald der Maus-Callback
 *   f_140980 eine neue Schaltflächen-Kennung in d_1c1166 eingetragen hat: Bei Kennungen 148 bis 162 wird das
 *   entsprechende Thema in der rechten Spalte (f_142390), bei 163 die "Ende"-Schaltfläche (f_142390(p1, -1)) und
 *   bei 144 bis 146 die entsprechende Multiple-Choice-Antwort im linken Textfeld (f_1425a0) hervorgehoben.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - key: Neue Hervorhebungskennung aus d_1c1166.
 === Ende Beschreibung === */
//@ f_142e10  groesse 128 B, 37 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Eröffnet ein Gespräch: Baut über f_140b40 das Dialogfenster auf, lädt über f_140d00 und
 *   f_140de0 die Dialogskriptdatei sowie den gespeicherten Gesprächsstand, zeichnet Porträt (f_141020) und
 *   Themenliste (f_141420), senkt einen eventuell bereits am Limit stehenden Ungeduldszähler um 1, damit
 *   zumindest ein Satz gesprochen werden kann, und führt anschließend entweder die Erstbegrüßung (UC(p1 + 0x19)
 *   - 1, falls I4(p1 + 0x9B) == 0) oder die Wiederbegrüßung (UC(p1 + 0x19)) über f_1422a0 aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - ps: Zeiger auf den Ungeduldszähler des aktuellen NSCs.
 *   - u: Themenindex der Erst- bzw. Wiederbegrüßung.
 === Ende Beschreibung === */
//@ f_142e90  groesse 224 B, 72 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt ein Gespräch ab: Wurde das Gespräch wegen Ungeduld des NSCs abgebrochen (I4(p1 +
 *   0x9F) == 1), wartet die Funktion zunächst auf "Weiter..." und wählt den Verärgerungs-Abschiedstext (s =
 *   UC(p1 + 0x19) + 2), andernfalls den normalen Abschiedstext (s = UC(p1 + 0x19) + 1). Sofern kein sofortiger
 *   Abbruch (I4(p1 + 0xA3) == 0) erzwungen wurde und der Abschiedseintrag existiert, wird dieser über f_1422a0
 *   ausgegeben und mit f_141820 bestätigt; abschließend speichert die Funktion den neuen Gesprächsstand in der
 *   temporären Datei 0x40000000.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Themenindex der normalen Verabschiedung (UC(p1 + 0x19) + 1) bzw. des Gesprächsabbruchs durch Ungeduld
 *     (UC(p1 + 0x19) + 2).
 === Ende Beschreibung === */
//@ f_142f70  groesse 304 B, 47 Bef, reg eax edx ebx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor einer xdialog-Gesprächsinstanz (p1): Setzt das globale Dialog-Aktiv-Flag d_1c1160
 *   = 1, speichert die Dateikennung der Dialogressource (W32(p1, 0x10) = p2), kopiert den 33 Byte großen
 *   Konfigurations- und Callback-Block *p3 nach p1 + 0x14, initialisiert alle Grafik-, Daten- und Pufferzeiger
 *   mit 0, setzt das Standard-Ungeduldslimit W16(p1, 0xA7) = 3 und markiert die Antwort-Klickzonentabelle (p1 +
 *   0x6B) als leer (-1).
 * - Eingaben: Zeiger p1 auf die zu initialisierende Dialoginstanz (179 Bytes), Ressourcenkennung p2 (int) der
 *   Dialogdatei und Zeiger p3 (int) auf die 33-Byte-Konfigurationsstruktur (B33).
 * - Rückgabewert: Keiner (void, bzw. this in EAX).
 * - Wichtige Variablen:
 *   - d_1c1160: Globales Flag, das anzeigt, dass gerade ein xdialog-Gespräch aktiv ist.
 *   - W16(p1, 0xA7): Maximale Anzahl unbeantwortbarer Fragen (Standardwert 3), bevor der Gesprächspartner die
 *     Geduld verliert.
 === Ende Beschreibung === */
//@ f_1430a0  groesse 208 B, 86 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor einer xdialog-Gesprächsinstanz (p1): Gibt alle während des Gesprächs dynamisch
 *   angelegten Grafikpuffer (p1 + 0x00 bis p1 + 0x0C), den Dialogdatenpuffer (p1 + 0x35), den
 *   Themen-Textspeicher (p1 + 0x59), das Sichtbarkeitsarray (p1 + 0x61), das Themenphasen-Array (p1 + 0xAB)
 *   sowie den Formatierungspuffer (p1 + 0xAF) wieder frei und setzt d_1c1160 = 0 zurück.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Destruktor-Steuerflag p2 (int).
 * - Rückgabewert: Der Objektzeiger p1 (int).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
//@ f_143170  groesse 480 B, 107 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ein komplettes NSC-Gespräch durch: Reserviert bei Bedarf den
 *   1024-Byte-Textformatierungspuffer W32(p1, 0xAF), sichert die aktuellen Einstellungen des Textrenderers
 *   d_1c38b0 sowie die globalen Mauszonen- und Callback-Variablen (d_1bf510..d_1bf524), aktiviert die
 *   Themen-Klickzonentabelle d_1a94b0 und die Hover-Tabelle d_1a9564 mit dem Callback f_140980, ruft die
 *   Gesprächseröffnung f_142e10(p1) auf, betreibt die Haupt-Ereignisschleife (f_068f40, f_142d20, f_142920), bis
 *   das Gespräch beendet wird, führt anschließend die Verabschiedung und Statussicherung f_142e90(p1) aus und
 *   stellt den vorherigen Grafik- und Mauszustand wieder her.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - g: Lokales Wächterobjekt (CG), das beim Betreten und Verlassen des Gesprächs den
 *     Bildschirm-/Palettenzustand über f_0ce7c0 / f_0ce7e0 sichert.
 *   - s1 bis s5: Gesicherte globale Maus-Klickzonen- und Callback-Zeiger.
 *   - l1 bis l6: Gesicherte Textfenster-Koordinaten und Farben von d_1c38b0.
 === Ende Beschreibung === */
extern int d_1bd762;
extern short d_1bd766;
extern short d_1bf51c, d_1c1164, d_1c1166;
extern char d_1c21b4[];
extern const char d_1b8708[], d_1b870b[];
int f_0bf820(int, ...);
int f_149cf0();
#define I4(a) (*(int *)(a))
#define I2(a) (*(short *)(a))
#define SC(a) (*(signed char *)(a))
#define UC(a) (*(unsigned char *)(a))
#define U2(a) (*(unsigned short *)(a))
#define A(x) ((int)&(x))
#define D38 ((int)&d_1c38b0)
#define D20 ((int)&d_1c2098)
#define DC6 ((int)&d_1c2c64)
typedef int (*FP1)(int);
typedef unsigned short (*FPU)(int);
typedef void (*FP2)(int, int);

void f_140b40(int); void f_140d00(int); void f_140de0(int); void f_141020(int);
void f_141310(int, int); void f_1411e0(int, int, int); void f_141420(int, int);
void f_1414e0(int, int, int); void f_141950(int, int); void f_141820(int);
short f_141c00(int, int);
void f_141d30(int p1, int p2); void f_141ef0(int p1, int p2); void f_141fc0(int p1, short p2);
void f_1422a0(int p1, short p2); void f_142390(int p1, short p2); void f_142480(int p1, short p2);
void f_1425a0(int p1, short p2); int f_142750(int p1, short p2);
short f_142800(int p1); void f_142890(int p1, short *p2); int f_1428c0();

//@ f_141d30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchläuft einen Baum aus Multiple-Choice-Gesprächsknoten ab der Startadresse p2: Schaltet das
 *   Dialogobjekt in den Antwortauswahl-Modus (I4(p1 + 0x67) = 1), löscht für jeden Knoten das linke Textfeld,
 *   gibt die einleitende NSC-Rede (listd30907) aus, führt über den Callback p1 + 0x29 die Knoten-Aktion aus und
 *   lässt den Spieler über f_141c00 eine Antwort wählen, bis der Folgeindex -1 erreicht wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Startadresse p2 (int) des Verzweigungsbaums.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - base: Basisadresse der Verzweigungstabelle (p2), relativ zu der jeder Folgeknoten base + r * 0x18
 *     adressiert wird.
 *   - l30: Flag (1, wenn nach einer NSC-Aussage ohne Antwortoptionen noch ein Folgeknoten kommt und daher auf
 *     "Weiter..." gewartet werden soll).
 === Ende Beschreibung === */
#pragma inline_depth(8)
inline void listd30907(int mode, int q, int object, int &flag) {
    if (f_0d3860()==1) { f_0d2710(); flag=1; } else flag=0;
    while (I2(q)!=4) { f_1414e0(object,q,mode); q+=14; }
    if (flag==1) f_0d26e0();
}
void f_141d30(int p1, int p2)
{
    struct Guard {
        int fl;
        Guard() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
        ~Guard() { if (fl == 1) f_0d26e0(); }
    };
    volatile int base = p2; // haelt base ueber die Schleife auf dem Stapel
    Guard mg;
    int flag;
    volatile int l30; // haelt l30 im originalen Stapelslot
    short v2, v3, v4, v5, v0, v1;
    I4(p1 + 0x95) = base;
    I4(p1 + 0x67) = 1;
    f_05e2a0(D38, A(v5), A(v1), A(v0), A(v2));
    f_05e360(D38, A(v3), A(v4));
    while (I4(p1 + 0x95) != 0) {
        ((RivaRasterImage*)(I4(p1)))->f_0fade0((void *)( d_1a34e0), 10, 0x32);
        f_05e2d0(D38, 10, 0xc9, 0x32, 0);
        l30 = 0;
        int n = I4(p1 + 0x95);
        if (I4(n) != -1) {
            if (I4(n + 6) == -1) {
                if (I2(n + 0x12) != (short)-1) l30 = 1;
            }
            int b = I4(p1 + 0x4d);
            
            listd30907(0,b+I4(I4(p1+0x95)),p1,flag);
        }
        (*(FP2 *)(p1 + 0x29))(p1, (int)I2(I4(p1 + 0x95) + 4));
        {
            short r = f_141c00(p1, l30);
            if (r == (short)-1) I4(p1 + 0x95) = 0;
            else I4(p1 + 0x95) = base + r * 0x18;
        }
    }
    f_05e320(D38, v3, v4);
    f_05e2d0(D38, v5, v1, v0, v2);
    I4(p1 + 0x67) = 0;
}

//@ f_141ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt eine aus 8-Byte-Befehlen aufgebaute Dialog-Skriptsequenz ab p2 bis zur Endmarkierung
 *   I2(p2) == 3 aus. Prüft für jeden Schritt über den Bedingungs-Callback p1 + 0x25 die Bedingung I2(p2 + 2):
 *   Ist sie erfüllt, wird bei Befehlstyp 1 eine bedingte Textsequenz über f_141950 ausgegeben (und falls noch
 *   ein weiterer erfüllter Schritt folgt, über f_141820 auf "Weiter..." gewartet) oder bei Befehlstyp 2 über
 *   f_141d30 in einen Multiple-Choice-Verzweigungsbaum verzweigt.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (int) auf die Skriptsequenz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - addr: Berechnete Zieladresse für die Textsequenz (I4(p1 + 0x4D) + I4(p2 + 4)) bzw. den Verzweigungsbaum
 *     (I4(p1 + 0x49) + I4(p2 + 4)).
 === Ende Beschreibung === */
extern void f_140aea(void);
#pragma aux f_140aea aborts;
void f_141ef0(int p1, int p2)
{
    struct Guard {
        int fl;
        Guard() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
        ~Guard() { if (fl == 1) f_0d26e0(); }
    };
    while (I2(p2) != 3) {
        if ((*(FP1 *)(p1 + 0x25))((int)I2(p2 + 2)) == 1) {
            { Guard mg; ((RivaRasterImage*)(I4(p1)))->f_0fade0((void *)( d_1a34e0), 10, 0x32); }
            if (I2(p2) == 1) {
                int addr = I4(p1 + 0x4d);
                addr += I4(p2 + 4);
                f_141950(p1, addr);
                while (I2(p2 + 8) != 3 && (*(FP1 *)(p1 + 0x25))((int)I2(p2 + 10)) == 0) p2 += 8;
                if (I2(p2 + 8) != 3) f_141820(p1);
            } else if (I2(p2) == 2) {
                int addr = I4(p1 + 0x49);
                addr += I4(p2 + 4);
                f_141d30(p1, addr);
            }
        }
        p2 += 8;
    }
    f_140aea();
}

//@ f_141fc0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Behandelt den Fall, dass ein angesprochenes Thema p2 beim aktuellen NSC keine eigene
 *   Skriptantwort (mehr) besitzt: Gibt zunächst die Standardfrage des Helden (p2 * 2 + 0x15030001) in Farbe 0xF9
 *   aus und zeigt darunter entweder den zum Thema gehörenden allgemeinen Standard-Ablehnungstext (p2 * 2 +
 *   0x15030002, falls der NSC keinen eigenen Ablehnungseintrag in choices[selected + 3] besitzt) oder den
 *   NSC-spezifischen Standard-Ablehnungssatz an.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Themenindex p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - mg.index: Doppelter Themenindex (p2 * 2) zur Berechnung der Standardtext-Kennungen 0x15030001 und
 *     0x15030002.
 *   - selected: Index der speziellen Standard-Einträge (UC(p1 + 0x19)).
 === Ende Beschreibung === */
#pragma intrinsic(strcpy, strcat)
struct MG141fc0 {
    int fl;
    int index;
    struct Coords { int l30, l2c, l28, l24, l20, l1c; } coords;
    MG141fc0() { if (f_0d3860() == 1) { f_0d2710(); fl = 1; } else fl = 0; }
    ~MG141fc0() { if (fl == 1) f_0d26e0(); }
};
void f_141fc0(int p1, short p2)
{
    int f_0e9650(int, int);
    int selected;
    MG141fc0 mg;
    ((RivaRasterImage*)(I4(p1)))->f_0fade0((void *)( d_1a34e0), 10, 0x32);
    f_05e2a0(D38, A(mg.coords.l28), A(mg.coords.l24), A(mg.coords.l2c), A(mg.coords.l20));
    f_05e360(D38, A(mg.coords.l1c), A(mg.coords.l30));
    f_05e2d0(D38, 10, 0xc9, 0x32, 0);
    mg.index = p2 * 2;
    f_0e93f0(D38, (int)d_1c21b4, mg.index + 0x15030001);
    char *t = (char *)I4(p1 + 0xaf);
    *t++ = '<';
    strcpy(t, d_1c21b4);
    strcat((char *)I4(p1 + 0xaf), d_1b8708);
    f_05e320(D38, 0xf9, -1);
    f_0e9650(D38, I4(p1 + 0xaf));
    f_0e9650(D38, (int)d_1b870b);
    unsigned char *choices = (unsigned char *)I4(p1 + 0x61);
    selected = UC(p1 + 0x19);
    if (choices[selected + 3] == (unsigned char)0xff) {
        int textId = mg.index + 0x15030002;
        short u = (*(FPU *)(p1 + 0x31))((int)(short)(p2 + 1));
        f_0e93f0(D38, (int)d_1c21b4, textId);
        int object = p1;
        short mode = u;
        char *src = d_1c21b4;
        char *dst = (char *)I4(object + 0xaf);
        if (mode == 1 || mode == 2) *dst++ = '<';
        strcpy(dst, src);
        if (mode == 1 || mode == 2)
            strcat((char *)I4(object + 0xaf), d_1b8708);
        switch ((unsigned short)mode) {
        case 1: f_05e320(D38, 0xf9, -1); break;
        case 2: f_05e320(D38, 0xff, -1); break;
        case 3: f_05e320(D38, 0xf0, -1); break;
        }
        f_0e9650(D38, I4(p1 + 0xaf));
    } else {
        int q = I4(p1 + 0x3d);
        short chosen = (unsigned char)selected;
        chosen += 3;
        short wanted = chosen;
        wanted++;
        while (I2(q) != 0 && wanted != I2(q)) q += 6;
        while (I2(q) != 0 && I4(q + 2) == -1) q += 6;
        int at = I4(p1 + 0x41) + I4(q + 2);
        int entry = I4(p1 + 0x45);
        entry += I4(at);
        int base = I4(p1 + 0x4d);
        base += I4(entry + 4);
        f_1414e0(p1, base, 0);
    }
    f_05e320(D38, (short)mg.coords.l1c, (short)mg.coords.l30);
    f_05e2d0(D38, (short)mg.coords.l28, (short)mg.coords.l24, (short)mg.coords.l2c, (short)mg.coords.l20);
}

//@ f_1422a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt ein einzelnes gewähltes Gesprächsthema p2 aus: Blendet die rechte Themenliste während
 *   der Textausgabe grau ab (f_141420(p1, 0xCD)), sucht in der Themen-Zuordnungstabelle I4(p1 + 0x3D) und dem
 *   Phasen-Array I4(p1 + 0xAB) das zur aktuellen Gesprächsphase gehörende Skript; ist dort -1 eingetragen
 *   (unbekanntes Thema), ruft die Funktion die Standardablehnung f_141fc0 auf und erhöht den Ungeduldszähler des
 *   NSCs (ps[idx]++), andernfalls startet sie das Skript über f_141ef0, schaltet je nach Steuercode I2(p1 +
 *   0xA9) die Themenphase weiter (0 = nächste Phase, 1 = gleiche Phase beibehalten, 2 = auf Phase 0
 *   zurücksetzen) und blendet die Themenliste anschließend wieder aktiv (0xFF / 0xFC) ein.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Themenindex p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - sel: 0-basierter Index des Themas (I2(q) - 1).
 *   - addr: Adresse des 32-Bit-Skriptoffsets für die aktuelle Phase des Themas.
 === Ende Beschreibung === */
void f_1422a0(int p1, short p2)
{
    int q;
    short want;
    short sel;
    short arg;
    int base;
    int addr;
    f_141420(p1, 0xcd);
    arg = p2;
    want = p2 + 1;
    q = I4(p1 + 0x3d);
    while (I2(q) != 0 && want != I2(q)) q += 6;
    while (I2(q) != 0 && I4(q + 2) == -1) q += 6;
    base = I4(p1 + 0x41) + I4(q + 2);
    sel = I2(q) - 1;
    addr = SC(I4(p1 + 0xab) + sel) * 4;
    addr += base;
    if (I4(addr) == -1) {
        f_141fc0(p1, arg);
        { int idx = I2(p1 + 0x1f);
          short *ps = (short *)I4(p1 + 0x21);
          ps[idx]++; }
    } else {
        f_141ef0(p1, I4(p1 + 0x45) + I4(addr));
        if (sel < UC(p1 + 0x19) - 1) {
            switch (I2(p1 + 0xa9)) {
            case 0: {
                signed char *fl = (signed char *)I4(p1 + 0xab);
                fl[sel]++;
                break;
            }
            case 1: {
                I2(p1 + 0xa9) = 0;
                break;
            }
            case 2: {
                signed char *fl = (signed char *)I4(p1 + 0xab);
                fl[sel] = 0;
                I2(p1 + 0xa9) = 0;
                break;
            }
            }
        }
    }
    f_141420(p1, 0xff);
    f_1411e0(p1, SC(p1 + 0x66), 0xfc);
}




//@ f_142390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert im Themenauswahl-Modus (I4(p1 + 0x67) == 0) die optische Hervorhebung in der rechten
 *   Spalte von der bisherigen Position cur (SC(p1 + 0x66)) auf die neue Position p2 (1..SC(p1 + 0x65) für ein
 *   Thema oder -1 für die "Ende"-Schaltfläche), indem der alte Eintrag wieder weiß (0xFF) und der neue
 *   gelb/hervorgehoben (0xFC) gezeichnet wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und neue Auswahlposition p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - cur: Bisher hervorgehobene Zeilenposition (SC(p1 + 0x66)).
 === Ende Beschreibung === */
void f_142390(int p1, short p2)
{
    int cur;
    if (I4(p1 + 0x67) == 0) {
        cur = SC(p1 + 0x66);
        if (p2 != cur && p2 <= SC(p1 + 0x65)) {
            if (cur == -1) f_141310(p1, 0xff);
            else if (0 < cur) f_1411e0(p1, cur, 0xff);
            if (p2 == -1) f_141310(p1, 0xfc);
            else f_1411e0(p1, (signed char)p2, 0xfc);
            SC(p1 + 0x66) = (char)p2;
        }
    }
}

//@ f_142410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst im Themenauswahl-Modus (I4(p1 + 0x67) == 0) das p2-te sichtbare Thema aus der rechten
 *   Spalte aus, indem der zugehörige interne Themenindex r ermittelt und an f_1422a0(p1, r) übergeben wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und 1-basierte sichtbare Zeilennummer p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - r: Ermittelter interner Themenindex.
 === Ende Beschreibung === */
void f_142410(int p1, short p2)
{
    if (I4(p1 + 0x67) == 0 && p2 > 0 && p2 <= SC(p1 + 0x65)) {
        char *x = (char *)p1;
        short wanted = p2;
        short r = -1;
        unsigned char b = 0;
        short c = 0;
        if (wanted > 0) {
            while (r == (short)-1 && (int)b < (int)(*(unsigned char *)(x + 0x1a) - 1)) {
                if ((*(char **)(x + 0x61))[b] != (char)0xff) c++;
                if (c == wanted) r = b;
                b++;
            }
        }
        f_1422a0(p1, (short)r);
    }
}

//@ f_142480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet Tastatureingaben (0xA4 = Pfeil hoch, 0xA5 = Pfeil runter, 0xA6 = Eingabetaste)
 *   innerhalb der rechten Themenauswahlspalte: Bewegt den Auswahlbalken zyklisch durch die sichtbaren Themen und
 *   die "Ende"-Schaltfläche (-1) oder startet bei 0xA6 das aktuell markierte Thema über f_1422a0.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Tastencode p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Neu berechnete Auswahlposition in der Themenliste.
 === Ende Beschreibung === */
void f_142480(int p1, short p2)
{
    short s;
    switch ((unsigned short)p2) {
    case 0xa4:
            if (SC(p1 + 0x65) > 0) {
                s = SC(p1 + 0x66) - 1;
                if (s < -1) s = SC(p1 + 0x65);
                if (s < 1) s = -1;
                f_142390(p1, s);
            }
        break;
    case 0xa5:
        if (SC(p1 + 0x65) > 0) {
            if (SC(p1 + 0x66) == -1) s = 1;
            else {
                s = SC(p1 + 0x66) + 1;
                if (s > SC(p1 + 0x65)) s = -1;
            }
            f_142390(p1, s);
        }
        break;
    case 0xa6:
        if (SC(p1 + 0x65) > 0) {
            int src = p1;
            short wanted = SC(src + 0x66);
            short n = 0;
            unsigned char i = 0;
            short target = -1;
            if (SC(src + 0x66) > 0) {
                while (target == (short)-1 && i < UC(src + 0x1a) - 1) {
                    int items = I4(src + 0x61);
                    if (((unsigned char *)items)[i] != (unsigned char)0xff) n++;
                    if (n == wanted) target = i;
                    i++;
                }
            }
            f_1422a0(p1, target);
        }
        break;
    }
}

//@ f_1425a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ändert im Multiple-Choice-Antwortmodus (I4(p1 + 0x67) == 1) die optisch hervorgehobene Antwort
 *   im linken Textfenster von SC(p1 + 0x94) auf die neue Antwortnummer p2 (1 bis SC(p1 + 0x93)), indem der alte
 *   Antworttext im Normalmodus (mode = 0) und der neue im Hervorhebungsmodus (mode = 1, Farbe 0xFC) neu
 *   gezeichnet wird.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und 1-basierte Antwortnummer p2 (short).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - pos: Tabellenoffset (Index - 1) * 5 in der Koordinatentabelle p1 + 0x6B.
 === Ende Beschreibung === */
void f_1425a0(int p1, short p2)
{
    if (I4(p1 + 0x67) != 1) return;
    if (p2 == SC(p1 + 0x94) || p2 > SC(p1 + 0x93)) return;
    {
        if (SC(p1 + 0x94) > 0) {
            int pos = (SC(p1 + 0x94) - 1) * 5;
            f_05e2d0(D38, I2(p1 + 0x6b + pos * 2), 0xc9,
                     I2(p1 + 0x6d + pos * 2), 0);
            int old = SC(p1 + 0x94);
            int index = old * 4;
            int entries = I4(p1 + 0x95);
            int objectOld = p1;
            index += entries;
            int mode = 0;
            int base = I4(p1 + 0x4d);
            int off = I4(index + 2);
            int q = base + off;
            volatile int flag; // haelt flag im ersten Zweig auf dem Stapel
            if (f_0d3860() == 1) { f_0d2710(); flag = 1; }
            else flag = mode;
            while (I2(q) != 4) { f_1414e0(objectOld, q, mode); q += 14; }
            if (flag == 1) f_0d26e0();
        }
        {
            int mode = 1;
            int pos = (p2 - 1) * 5;
            f_05e2d0(D38, I2(p1 + 0x6b + pos * 2), 0xc9,
                     I2(p1 + 0x6d + pos * 2), 0);
            int entries = I4(p1 + 0x95);
            int base = I4(p1 + 0x4d);
            int off = I4(entries + p2 * 4 + 2);
            int status = f_0d3860();
            status = (status & 0) ? 0 : status; // haelt die Registerfolge fuer status und q wie im Original
            int objectNew = p1;
            int q = off + base;
            int flag;
            if (status == mode) { f_0d2710(); flag = mode; }
            else flag = 0;
            while (I2(q) != 4) { f_1414e0(objectNew, q, mode); q += 14; }
            if (flag == 1) f_0d26e0();
        }
        SC(p1 + 0x94) = (char)p2;
    }
}


//@ f_142700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übernimmt im Multiple-Choice-Antwortmodus (I4(p1 + 0x67) == 1) die per Maus angeklickte
 *   Antwortnummer p2 nach I2(p1 + 0x99) und wartet, bis der Spieler die linke Maustaste wieder loslässt
 *   (f_0d3780).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und gewählte Antwortnummer p2 (short).
 * - Rückgabewert: 1 bei gültiger Antwortwahl, sonst 0.
 * - Wichtige Variablen:
 *   - u: Erfolgsflag (1, wenn p2 im Bereich 1..SC(p1 + 0x93) liegt).
 === Ende Beschreibung === */
int f_142700(int p1, short p2)
{
    int u = 0;
    if (I4(p1 + 0x67) == 1) {
        if (0 < p2 && p2 <= SC(p1 + 0x93)) {
            u = 1;
            I2(p1 + 0x99) = p2;
            while (f_0d3780() != 0) f_069460();
        }
    }
    return u;
}

//@ f_142750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verarbeitet Tastatureingaben (0xA4 = Pfeil hoch, 0xA5 = Pfeil runter, 0xA6 = Eingabetaste) im
 *   Multiple-Choice-Antwortmodus: Bewegt die Hervorhebung über f_1425a0 zyklisch zwischen den bis zu drei
 *   Antworten im linken Textfenster oder bestätigt bei 0xA6 die aktuell markierte Antwort SC(p1 + 0x94).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und interner Tastencode p2 (short).
 * - Rückgabewert: 1, wenn eine Antwort mit der Eingabetaste (0xA6) bestätigt wurde, sonst 0.
 * - Wichtige Variablen:
 *   - s: Neue Antwortnummer nach Pfeiltastenbewegung.
 === Ende Beschreibung === */
int f_142750(int p1, short p2)
{
    int r = 0;
    short s;
    switch (p2) {
    case 0xa4:
        if (SC(p1 + 0x93) > 0) {
            s = SC(p1 + 0x94) - 1;
            if (s < 1) s = SC(p1 + 0x93);
            f_1425a0(p1, s);
        }
        break;
    case 0xa5:
        if (SC(p1 + 0x93) > 0) {
            s = SC(p1 + 0x94) + 1;
            if (s > SC(p1 + 0x93)) s = 1;
            f_1425a0(p1, s);
        }
        break;
    case 0xa6:
        if (SC(p1 + 0x93) > 0) {
            I2(p1 + 0x99) = SC(p1 + 0x94);
            r = 1;
        }
        break;
    }
    return r;
}

//@ f_142800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Übersetzt einen rohen BIOS-/Tastaturcode aus d_1bd762 (0x4800 = Pfeil hoch, 0x5000 = Pfeil
 *   runter, 0x1C0D = Enter, 0x4900 = Bild hoch, 0x011B = Escape) in den entsprechenden internen
 *   Dialog-Steuercode (0xA4 bis 0xA8).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz (zur Prüfung von I4(p1 + 0x67) bei Escape/Bild hoch).
 * - Rückgabewert: Interner Steuercode (0xA4-0xA8) oder 0, falls keine relevante Taste gedrückt wurde.
 * - Wichtige Variablen:
 *   - a: Aktueller Tastaturcode aus d_1bd762.
 === Ende Beschreibung === */
short f_142800(int p1)
{
    int r = 0;
    unsigned short a = (unsigned short)d_1bd762;
    switch (a) {
    case 0x4900:
        if (I4(p1 + 0x67) == 0) r = 0xa7;
        else f_0d3870();
        break;
    case 0x1c0d: r = 0xa6; break;
    case 0x11b:
        if (I4(p1 + 0x67) == 0) r = 0xa8;
        else f_0d3870();
        break;
    case 0x4800: r = 0xa4; break;
    case 0x5000: r = 0xa5; break;
    }
    return r;
}

//@ f_142890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ergänzt einen aus der Tastatur gelesenen Steuercode *p2 um Mausklick-Ereignisse: Wurde keine
 *   Taste gedrückt (*p2 == 0), wird der aktuelle Mauszonen-Code d_1bd766 übernommen; wurde im Themenmodus (I4(p1
 *   + 0x67) == 0) die rechte Maustaste (f_0d37b0) gedrückt, wird der Code 0xA7 (Rückfrage zum Beenden des
 *   Gesprächs) eingetragen.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz und Zeiger p2 (short *) auf den aktuellen Steuercode.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
void f_142890(int p1, short *p2)
{
    if (*p2 == 0) *p2 = d_1bd766;
    if (f_0d37b0() != 0 && I4(p1 + 0x67) == 0) *p2 = 0xa7;
}

//@ f_1428c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet beim Rechtsklick im Dialog ein kleines Bestätigungsfenster (f_0bf820 auf d_1c2c64) mit
 *   der Frage, ob das Gespräch beendet werden soll (0x15010001, Optionen 0x15010002 "Ende" und 0x15010003
 *   "Weiterreden"), und liefert bei Bestätigung den Beenden-Code 0xA8.
 * - Eingaben: Keine.
 * - Rückgabewert: 0xA8, wenn der Spieler das Gespräch beenden möchte, sonst 0.
 * - Wichtige Variablen:
 *   - p2: Gewählte Schaltfläche im Bestätigungsdialog (1 = Beenden).
 === Ende Beschreibung === */
int f_1428c0()
{
    int r = 0;
    unsigned short p2;
    f_0bf6c0(DC6, 3);
    p2 = f_0bf820(DC6, 0x15010001, 2, 0x15010002, 0x15010003);
    f_0bf680(DC6);
    switch (p2) {
    case 1: r = 0xa8; break;
    }
    return r;
}

inline void dlgclose_907(int p1)
{
    int f_149cf0(int);
    RivaMouseGuard mg;
    ((RivaRasterImage*)(I4(p1 + 8)))->f_0fae30((void *)( d_1a34e0), 0xe1, 0xb3, 0);
    f_141310(p1, 0xc9);
    f_149cf0(0x1f4);
    ((RivaRasterImage*)(I4(p1 + 0xc)))->f_0fae30((void *)( d_1a34e0), 0xe1, 0xb3, 0);
    f_141310(p1, 0xff);
    f_149cf0(0x64);
}

//@ f_142920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zentrale Eingabe- und Ereignisauswertung für einen einzelnen Durchlauf der Dialogschleife:
 *   Liest Tastatur- und Mausaktionen (key800_907, keyfix890_907), behandelt das Beenden über Escape/Schaltfläche
 *   (0xA8 mit dlgclose_907) oder Rechtsklick-Bestätigung (0xA7), startet angeklickte Themen (0x81-0x8F) oder
 *   Multiple-Choice-Antworten (0x90-0x92), verarbeitet Pfeiltasten/Enter (0xA4-0xA6) und prüft schließlich, ob
 *   der Ungeduldszähler des NSCs das Limit I2(p1 + 0xA7) erreicht hat (woraufhin der NSC das Gespräch mit I4(p1
 *   + 0x9F) = 1 abbricht).
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: 1, wenn die aktuelle Auswahlschleife beendet werden soll (Antwort gewählt oder Gespräch
 *   beendet), sonst 0.
 * - Wichtige Variablen:
 *   - key: Ermittelter Tastatur- oder Mauszonen-Code.
 *   - tbl: Zeiger auf das Array der NSC-Ungeduldszähler (I4(p1 + 0x21)).
 === Ende Beschreibung === */
#pragma inline_depth(8)
inline short key800_907(int p1)
{
    short r = 0;
    unsigned short a = (unsigned short)d_1bd762;
    switch (a) {
    case 0x4900:
        if (I4(p1 + 0x67) == 0) r = 0xa7;
        else f_0d3870();
        break;
    case 0x1c0d: r = 0xa6; break;
    case 0x11b:
        if (I4(p1 + 0x67) == 0) r = 0xa8;
        else f_0d3870();
        break;
    case 0x4800: r = 0xa4; break;
    case 0x5000: r = 0xa5; break;
    }
    return r;
}
inline void keyfix890_907(int p1, short &p2)
{
    if (p2 == 0) p2 = d_1bd766;
    if (f_0d37b0() != 0 && I4(p1 + 0x67) == 0) p2 = 0xa7;
}
inline int confirm8c0_907()
{
    int r = 0;
    unsigned short p2;
    f_0bf6c0(DC6, 3);
    p2 = f_0bf820(DC6, 0x15010001, 2, 0x15010002, 0x15010003);
    f_0bf680(DC6);
    switch (p2) {
    case 1: r = 0xa8; break;
    }
    return r;
}
inline int move700_907(int p1, short p2)
{
    int u = 0;
    if (I4(p1 + 0x67) == 1) {
        if (0 < p2 && p2 <= SC(p1 + 0x93)) {
            u = 1;
            I2(p1 + 0x99) = p2;
            while (f_0d3780() != 0) f_069460();
        }
    }
    return u;
}
inline void select410_907(int p1, short p2)
{
    if (I4(p1 + 0x67) == 0 && p2 > 0 && p2 <= SC(p1 + 0x65)) {
        char *x = (char *)p1;
        short wanted = p2;
        short r = -1;
        unsigned char b = 0;
        short c = 0;
        if (wanted > 0) {
            while (r == (short)-1 && (int)b < (int)(*(unsigned char *)(x + 0x1a) - 1)) {
                if ((*(char **)(x + 0x61))[b] != (char)0xff) c++;
                if (c == wanted) r = b;
                b++;
            }
        }
        f_1422a0(p1, (short)r);
    }
}

int f_142920(int p1)
{
    int f_149cf0(int);
    short key;
    int r = 0;
    key = key800_907(p1);
    keyfix890_907(p1, key);    if (key == 0xa7) {
        if (I4(p1 + 0x67) == 0) { key = confirm8c0_907(); }
        else { f_0d3870(); f_0d3770(); }
    }
    if (key == 0xa8) {
        r = 1;
        dlgclose_907(p1);
    } else if (key >= 0x81 && key <= 0x8f) {
        select410_907(p1, key - 0x80);
    } else if (key >= 0x90 && key <= 0x92) {
        int u = 0;
        short s = key - 0x8f;
        u = (u & 0) ? 0 : u; // bildet Mehrblock-Web fuer u wie im inlined Aufruf im Original
        if (I4(p1 + 0x67) == 1) {
            if (0 < s && s <= SC(p1 + 0x93)) {
                u = 1;
                I2(p1 + 0x99) = s;
                while (f_0d3780() != 0) f_069460();
            }
        }
        if (u == 1) r = 1;
    } else if (key >= 0xa4 && key <= 0xa6) {
        if (I4(p1 + 0x67) == 1) {
            if (f_142750(p1, key) == 1) r = 1;
        } else if (key == 0xa6 && SC(p1 + 0x66) == -1) {
            r = 1;
        dlgclose_907(p1);
        } else {
            f_142480(p1, key);
        }
    }
    short *tbl = (short *)I4(p1 + 0x21);
    if (tbl[I2(p1 + 0x1f)] >= I2(p1 + 0xa7) && I4(p1 + 0x67) == 0) {
        r = 1;
        I4(p1 + 0x9f) = 1;
    }
    while (f_0d3780() != 0 || f_0d37b0() != 0) f_069460();
    return r;
}


//@ f_142d20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktualisiert die optische Hover-Hervorhebung im Dialogfenster, sobald der Maus-Callback
 *   f_140980 eine neue Schaltflächen-Kennung in d_1c1166 eingetragen hat: Bei Kennungen 148 bis 162 wird das
 *   entsprechende Thema in der rechten Spalte (f_142390), bei 163 die "Ende"-Schaltfläche (f_142390(p1, -1)) und
 *   bei 144 bis 146 die entsprechende Multiple-Choice-Antwort im linken Textfeld (f_1425a0) hervorgehoben.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - key: Neue Hervorhebungskennung aus d_1c1166.
 === Ende Beschreibung === */
void f_142d20(int p1)
{
    struct Rect821 {
        short left, top, right, bottom;
        Rect821(short x, short y, short w, short h) : left(x), top(y), right(w), bottom(h) {}
    };
    short saved;
    Rect821 rect(0, 0, 319, 199);
    saved = d_1bf51c;
    short key = d_1c1166;
    if ((unsigned short)key != (unsigned short)d_1c1164) {
        key ^= key;
        *(short *)&d_1bf51c = key;
        if (d_1c1166 >= 148 && d_1c1166 <= 162) {
            f_142390(p1, (short)(d_1c1166 - 147));
        } else if (d_1c1166 == 163) {
            f_142390(p1, -1);
        } else if (d_1c1166 >= 144 && d_1c1166 <= 146) {
            f_1425a0(p1, (short)(d_1c1166 - 143));
        }
        d_1c1164 = *(volatile short *)&d_1c1166; // erzwingt frisches Lesen und verhindert Umsortierung der Interrupt-Variablen
        *(volatile short *)&d_1bf51c = saved; // haelt die Schreibreihenfolge von d_1bf51c am Ende des Blocks wie im Original
    }
}

//@ f_142e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Eröffnet ein Gespräch: Baut über f_140b40 das Dialogfenster auf, lädt über f_140d00 und
 *   f_140de0 die Dialogskriptdatei sowie den gespeicherten Gesprächsstand, zeichnet Porträt (f_141020) und
 *   Themenliste (f_141420), senkt einen eventuell bereits am Limit stehenden Ungeduldszähler um 1, damit
 *   zumindest ein Satz gesprochen werden kann, und führt anschließend entweder die Erstbegrüßung (UC(p1 + 0x19)
 *   - 1, falls I4(p1 + 0x9B) == 0) oder die Wiederbegrüßung (UC(p1 + 0x19)) über f_1422a0 aus.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - ps: Zeiger auf den Ungeduldszähler des aktuellen NSCs.
 *   - u: Themenindex der Erst- bzw. Wiederbegrüßung.
 === Ende Beschreibung === */
inline short preceding907(short value) { return value-1; }
void f_142e10(int p1)
{
    int q;
    short *ps;
    short u;
    f_140b40(p1);
    f_140d00(p1);
    f_140de0(p1);
    f_141020(p1);
    f_141420(p1, 0xff);
    q = I4(p1 + 0x21);
    ps = (short *)(q + I2(p1 + 0x1f) * 2);
    if (*ps >= I2(p1 + 0xa7)) *ps = preceding907(I2(p1 + 0xa7));
    if (I4(p1 + 0x9b) == 0) { I4(p1 + 0x9b) = 1; u = UC(p1 + 0x19) - 1; }
    else u = UC(p1 + 0x19);
    f_1422a0(p1, (short)u);
}

//@ f_142e90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt ein Gespräch ab: Wurde das Gespräch wegen Ungeduld des NSCs abgebrochen (I4(p1 +
 *   0x9F) == 1), wartet die Funktion zunächst auf "Weiter..." und wählt den Verärgerungs-Abschiedstext (s =
 *   UC(p1 + 0x19) + 2), andernfalls den normalen Abschiedstext (s = UC(p1 + 0x19) + 1). Sofern kein sofortiger
 *   Abbruch (I4(p1 + 0xA3) == 0) erzwungen wurde und der Abschiedseintrag existiert, wird dieser über f_1422a0
 *   ausgegeben und mit f_141820 bestätigt; abschließend speichert die Funktion den neuen Gesprächsstand in der
 *   temporären Datei 0x40000000.
 * - Eingaben: Zeiger p1 auf die Dialoginstanz.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - s: Themenindex der normalen Verabschiedung (UC(p1 + 0x19) + 1) bzw. des Gesprächsabbruchs durch Ungeduld
 *     (UC(p1 + 0x19) + 2).
 === Ende Beschreibung === */
void f_142e90(int p1)
{
    short s;
    int old;
    if (I4(p1 + 0x9f) == 1) {
        s = UC(p1 + 0x19) + 2;
        f_141420(p1, 0xcd);
        f_141820(p1);
    } else s = UC(p1 + 0x19) + 1;
    if (I4(p1 + 0xa3) == 0) {
        if (*(char *)(s + I4(p1 + 0x61)) != (char)0xff) {
            f_1422a0(p1, s);
            f_141420(p1, 0xcd);
            f_141820(p1);
        }
    }
    old = d_1a965c;
    d_1a965c = I4(p1 + 0x1b);
    ((RivaFileManager*)(D20))->f_1448b0( 0x40000000, 0x201);
    ((RivaFileManager*)(D20))->f_144ab0( I2(p1 + 0x1f) * (UC(p1 + 0x1a) + 4) + 6, 0);
    ((int)(((RivaFileManager*)(D20))->f_144960((void *)( p1 + 0x9b), 4)));
    ((int)(((RivaFileManager*)(D20))->f_144960((void *)( I4(p1 + 0xab)), UC(p1 + 0x1a))));
    ((RivaFileManager*)(D20))->f_1449a0();
    d_1a965c = old;
}
