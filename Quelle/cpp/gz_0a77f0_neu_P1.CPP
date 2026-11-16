/* === Beschreibung (Katalog) ===
 * Einheit gz_0a77f0_neu (0x0A77F0 - 0x0A7B60)
 *
 * Überblick
 * Die Einheit gz_0a77f0_neu enthält 31 kleine Zugriffsfunktionen der Gegenstandsdefinition (RivaItemDefinition),
 * mit denen Grundwerte (Gewicht, Preis, Grafik-ID, Gegenstandstyp), einzelne Bitflags des
 * 16-Bit-Eigenschaftsworts u6 (z. B. Rüstung, Waffe, stapelbar, magisch), die Singular- oder Pluralform des
 * Gegenstandsnamens sowie prozentuale Preisänderungen abgefragt und berechnet werden.
 === Ende Beschreibung === */
#include "RIVAITEX.H"
#include "RIVAITEM.H"
// OPT -4r -oneatx -zp1 -s
// Astra630: Zuschnitt 0a77f0-0a7b60 aus Quelle/cpp/G0A77F0.CPP; erster Entwurf, Einbau separat prüfen.
// gz_0a77f0.cpp (Schatten Ã¼ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0xA77F0-0xA7B60. Kleine Zugriffsfunktionen auf Gegenstandsdatensatz, Namens-TeilstÃ¼ck, Zeichenketten-Ende.
#include <string.h>
void f_154af8();

//@ f_0a77f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Ruft die globale Hilfsfunktion f_154af8() auf (vermutlich zur Initialisierung oder
 *   Aktualisierung der Gegenstandsverwaltung).
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0a77f0() { f_154af8(); }
//@ f_0a7800
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld data.s4 (vermutlich die Grafik- oder Icon-ID) der
 *   Gegenstandsdefinition zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 16-Bit-Wert data.s4 (short).
 * - Wichtige Variablen: this->data.s4.
 === Ende Beschreibung === */
short RivaItemDefinition::f_0a7800() { return data.s4; }
//@ f_0a7810
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld data.sa (das Einzelgewicht des Gegenstands in Unzen) zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 16-Bit-Gewicht data.sa (short).
 * - Wichtige Variablen: this->data.sa.
 === Ende Beschreibung === */
short RivaItemDefinition::f_0a7810() { return data.sa; }
//@ f_0a7820
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das 16-Bit-Feld data.sc (den Grundpreis bzw. Wert des Gegenstands) zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 16-Bit-Grundpreis data.sc (short).
 * - Wichtige Variablen: this->data.sc.
 === Ende Beschreibung === */
short RivaItemDefinition::f_0a7820() { return data.sc; }
//@ f_0a7830
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das vorzeichenbehaftete 8-Bit-Feld data.ce (die Preiseinheit bzw. den
 *   Münzmultiplikator des Gegenstands) als short zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.ce (short).
 * - Wichtige Variablen: this->data.ce.
 === Ende Beschreibung === */
short RivaItemDefinition::f_0a7830() { return data.ce; }
//@ f_0a7840
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Extrahiert aus der mit Punkten ('.') getrennten Namenszeichenkette item->name (Format
 *   "Stamm.SingularEndung.PluralEndung") den vollständigen Gegenstandsnamen im Singular (n <= 1) oder Plural (n
 *   > 1) und schreibt ihn nullterminiert nach dst.
 * - Eingaben: item (Zeiger auf RivaItemDefinition), dst (Zielpuffer für den zusammengesetzten Namen), n
 *   (Stückzahl: <= 1 wählt Singular, > 1 überspringt die erste Endung und hängt die Pluralendung an).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - item->name: Punktgetrennte Namensvorlage des Gegenstands.
 === Ende Beschreibung === */
void f_0a7840(RivaItemDefinition *item, char *dst, short n) {
  char *s = item->name; char c; int t;
  do { t = (signed char)(c = *s++); *dst++ = c; if (t == 0) break; } while (c != '.');
  if (n > 1) { do { c = *s++; t = (signed char)c; if (t == 0) break; } while (c != '.'); }
  dst--;
  do { c = *s++; *dst++ = c; t = (signed char)c; if (t == 0) break; } while (c != '.');
  dst--;
  *dst = 0;
}
//@ f_0a7890
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt den direkten Zeiger auf die rohe Namenszeichenkette item->name der
 *   Gegenstandsdefinition zurück.
 * - Eingaben: item (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Zeiger auf item->name (char *).
 * - Wichtige Variablen: item->name.
 === Ende Beschreibung === */
char *f_0a7890(RivaItemDefinition *item) { return item->name; }
//@ f_0a78a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.c9 (die Gegenstandskategorie bzw. den Untertyp, z. B.
 *   Waffen-/Rüstungsart) zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c9 (unsigned char).
 * - Wichtige Variablen: this->data.c9.
 === Ende Beschreibung === */
unsigned char RivaItemDefinition::f_0a78a0() { return data.c9; }
//@ f_0a78b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.c8 (vermutlich den Ausrüstungsplatz oder die Hauptgruppe des
 *   Gegenstands) zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c8 (unsigned char).
 * - Wichtige Variablen: this->data.c8.
 === Ende Beschreibung === */
unsigned char RivaItemDefinition::f_0a78b0() { return data.c8; }
//@ f_0a78c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.c11 (vermutlich den Tabellenindex in der Waffen-, Rüstungs- oder
 *   Spezialtabelle) zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c11 (unsigned char).
 * - Wichtige Variablen: this->data.c11.
 === Ende Beschreibung === */
unsigned char RivaItemDefinition::f_0a78c0() { return data.c11; }
//@ f_0a78d0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.cf der Gegenstandsdefinition zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.cf (unsigned char).
 * - Wichtige Variablen: this->data.cf.
 === Ende Beschreibung === */
unsigned char RivaItemDefinition::f_0a78d0() { return data.cf; }
//@ f_0a78e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das gesamte 16-Bit-Eigenschaftswort data.u6.w mit allen Gegenstandsflags auf einmal
 *   zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 16-Bit-Flagwort data.u6.w (unsigned short).
 * - Wichtige Variablen: this->data.u6.w.
 === Ende Beschreibung === */
unsigned short RivaItemDefinition::f_0a78e0() { return data.u6.w; }
//@ f_0a78f0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_6 (Bit 6 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 6 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_6.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a78f0() { return data.u6.b.bf6_6; }
//@ f_0a7910
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_5 (Bit 5 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 5 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_5.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7910() { return data.u6.b.bf6_5; }
//@ f_0a7930
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_3 (Bit 3 des Eigenschaftsworts u6, vermutlich
 *   Benutzbarkeit/Verbrauchbarkeit) der Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 3 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_3.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7930() { return data.u6.b.bf6_3; }
//@ f_0a7950
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_4 (Bit 4 des Eigenschaftsworts u6, vermutlich
 *   Stapelbarkeit) der Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 4 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_4.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7950() { return data.u6.b.bf6_4; }
//@ f_0a7970
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_2 (Bit 2 des Eigenschaftsworts u6, Waffen-Flag) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 2 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_2.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7970() { return data.u6.b.bf6_2; }
//@ f_0a7990
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_1 (Bit 1 des Eigenschaftsworts u6, Rüstungs-Flag) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 1 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_1.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7990() { return data.u6.b.bf6_1; }
//@ f_0a79b0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_0 (Bit 0 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 0 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_0.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a79b0() { return data.u6.b.bf6_0; }
//@ f_0a79c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_8 (Bit 8 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 8 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_8.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a79c0() { return data.u6.b.bf6_8; }
//@ f_0a79e0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_9 (Bit 9 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 9 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_9.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a79e0() { return data.u6.b.bf6_9; }
//@ f_0a7a00
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_10 (Bit 10 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 10 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_10.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a00() { return data.u6.b.bf6_10; }
//@ f_0a7a20
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_11 (Bit 11 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 11 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_11.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a20() { return data.u6.b.bf6_11; }
//@ f_0a7a40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_12 (Bit 12 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 12 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_12.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a40() { return data.u6.b.bf6_12; }
//@ f_0a7a60
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_13 (Bit 13 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 13 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_13.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a60() { return data.u6.b.bf6_13; }
//@ f_0a7a80
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft das Bitfeld data.u6.b.bf6_14 (Bit 14 des Eigenschaftsworts u6) der
 *   Gegenstandsdefinition.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn Bit 14 gesetzt ist, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_14.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a80() { return data.u6.b.bf6_14; }
//@ f_0a7a90
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das vorzeichenbehaftete Bytefeld data.c10 der Gegenstandsdefinition als int zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c10 (int).
 * - Wichtige Variablen: this->data.c10.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7a90() { return data.c10; }
//@ f_0a7aa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft, ob es sich bei dem Gegenstand um eine Waffe (data.u6.b.bf6_2 != 0) vom Untertyp
 *   data.c9 == 2 (vermutlich Stich- oder Fernkampfwaffe) handelt.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: 1, wenn beide Bedingungen erfüllt sind, sonst 0.
 * - Wichtige Variablen: this->data.u6.b.bf6_2, this->data.c9.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7aa0() { if (data.u6.b.bf6_2 && (signed char)data.c9 == 2) return 1; return 0; }
//@ f_0a7ac0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.c12 (vermutlich einen Sortier- oder Händler-Kategoriewert) als int
 *   zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c12 (int).
 * - Wichtige Variablen: this->data.c12.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7ac0() { return data.c12; }
//@ f_0a7ad0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Gibt das Bytefeld data.c13 der Gegenstandsdefinition als int zurück.
 * - Eingaben: this (Zeiger auf RivaItemDefinition).
 * - Rückgabewert: Wert von data.c13 (int).
 * - Wichtige Variablen: this->data.c13.
 === Ende Beschreibung === */
int RivaItemDefinition::f_0a7ad0() { return data.c13; }
//@ f_0a7ae0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Passt den Grundpreis data.sc des Gegenstands um einen prozentualen Auf- oder Abschlag p
 *   unter Berücksichtigung der Preiseinheit data.ce an (((sc * ce) / 100 * p) / ce) und speichert den neuen
 *   Preis in data.sc.
 * - Eingaben: this (Zeiger auf RivaItemDefinition), p (Prozentsatz der Preisänderung).
 * - Rückgabewert: Neuer Grundpreis data.sc (short).
 * - Wichtige Variablen: this->data.sc (Preis), this->data.ce (Preiseinheit).
 === Ende Beschreibung === */
short RivaItemDefinition::f_0a7ae0(short p) {
int t = data.sc * data.ce; int b = data.ce; t = t / 100; t = t * p; t = t / b; return data.sc += t;
}
//@ f_0a7b30
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Leere Platzhalterfunktion (ret) ohne Operation.
 * - Eingaben: Keine.
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_0a7b30() {}
//@ f_0a7b40
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Überspringt eine nullterminierte Zeichenkette p einschließlich ihres Nullbytes und gibt
 *   den Zeiger auf den Beginn der unmittelbar darauffolgenden Zeichenkette im selben Textblock zurück (p +
 *   strlen(p) + 1).
 * - Eingaben: p (Zeiger auf die aktuelle nullterminierte Zeichenkette).
 * - Rückgabewert: Zeiger auf das erste Byte nach dem abschließenden Nullbyte (char *).
 * - Wichtige Variablen: p.
 === Ende Beschreibung === */
char *f_0a7b40(char *p) { return p + strlen(p) + 1; }
