/* === Beschreibung (Katalog) ===
 * Einheit gz_0421c0_t1 (0x0421c0 - 0x043360)
 *
 * Überblick
 * Die Einheit gz_0421c0_t1 bildet den ersten Teil der zentralen C++-Methoden der Heldenklasse (struct hero,
 * Größe 0x5ef Bytes). Sie kapselt die Konstruktoren, Destruktoren sowie die Lese- und Schreibzugriffe (Getter
 * und Setter) für Grunddaten (Name, Porträt, Typus, Geschlecht, Gottheit, Geld, Stufe, Abenteuerpunkte), Lebens-
 * und Astralpunkte, Status-Flags (tot, schlafend, versteinert, gefesselt, verängstigt, abtrünnig), Zauberwerte
 * und die 31 Inventarslots (inv_slot, je 0x1b Bytes ab Offset 0x1ac).
 === Ende Beschreibung === */
#include "RIVAHERO.H"
#include "RIVAHAPI.H"
// P3 157/166 gleich (suche.py 23.10.2026, Basis gz_0421c0_t1_P1.CPP)
struct BF16 { unsigned short b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1,b8:1,b9:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1; };
// P1 139/166 gleich
// gz_0421c0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x0421C0-0x044300
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
void *mark(const char *file, int line);                  // 0x014B10
void *operator new(unsigned size, void *tag);            // 0x014AB0
void *operator new[](unsigned size, void *tag);          // 0x014AC0
void operator delete(void *p);                           // 0x014710
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_044300(int p1, int p2);                           // reg eax edx stapel 0
int f_045430(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_0bcd30(int p1, int p2, int p3);                   // reg edx ebx stapel 0
int f_0d4c80(int p1, int p2, int p3, int p4);           // reg eax stapel 0
int f_0d4cd0(int p1, int p2);                           // reg eax edx stapel 0
int f_0d5040();                       // nicht in clobber.tsv
int f_0d5290(int p1, int p2);                           // reg eax edx stapel 0
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1bf230;                    // 0x1BF230
extern char d_1bfabc;                    // 0x1BFABC
extern char d_1bfac0;                    // 0x1BFAC0
extern char d_1bfac4;                    // 0x1BFAC4
extern int d_1c219a;                    // 0x1C219A
extern short d_1c219c;                    // 0x1C219C

struct T3 { char a, b, c; };
//@ f_0421c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert eine neue Heldenstruktur (0x5ef Bytes), indem der gesamte Speicherbereich mit
 *   Nullen überschrieben und der Geldanteil-Zähler (money_share) auf 0 gesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf die Heldenstruktur (p) und gibt denselben Zeiger
 *   nach der Initialisierung zurück.
 * - Wichtige Variablen: Löscht alle 0x5ef Bytes der Heldenstruktur p.
 === Ende Beschreibung === */
hero *f_0421c0(hero *p) {
    memset(p, 0, 0x5ef);
    p->money_share = 0;
    return p;
}
//@ f_0421e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt den leeren Destruktor (oder Kopier-Stub) der Heldenstruktur dar, der den übergebenen
 *   Heldenzeiger unverändert zurückgibt.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger auf den Helden (p) sowie ein Lösch-Flag (deleting) und
 *   gibt p zurück.
 * - Wichtige Variablen: Greift auf keine globalen oder lokalen Felder zu.
 === Ende Beschreibung === */
hero *f_0421e0(hero *p, int deleting) { return p; }
//@ f_0421f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert eine nullterminierte Zeichenkette von der Quelladresse s in den Zielpuffer d (z. B.
 *   den internen Heldennamen am Beginn der Struktur).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zielpuffer (d) und die Quellzeichenkette (s) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Schreibt direkt in den übergebenen Zeichenpuffer d.
 === Ende Beschreibung === */
void f_0421f0(char *d, char *s) { strcpy(d, s); }
//@ f_042220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die erste Versionsnummer (ver[0]) in den Kopf der Heldenstruktur (für das Speichern
 *   und Laden von Heldendateien).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das erste Versionsbyte (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->ver[0] der Heldenstruktur.
 === Ende Beschreibung === */
void f_042220(hero *p, int v_input) { char v = (char)v_input; p->ver[0] = v; }
//@ f_042230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die zweite Versionsnummer (ver[1]) in den Kopf der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das zweite Versionsbyte (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->ver[1] der Heldenstruktur.
 === Ende Beschreibung === */
void f_042230(hero *p, int v_input) { char v = (char)v_input; p->ver[1] = v; }
//@ f_042240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die dritte Versionsnummer (ver[2]) in den Kopf der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das dritte Versionsbyte (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->ver[2] der Heldenstruktur.
 === Ende Beschreibung === */
void f_042240(hero *p, int v_input) { char v = (char)v_input; p->ver[2] = v; }
//@ f_042250
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt die vierte Versionsnummer (ver[3]) in den Kopf der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie das vierte Versionsbyte (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->ver[3] der Heldenstruktur.
 === Ende Beschreibung === */
void f_042250(hero *p, int v_input) { char v = (char)v_input; p->ver[3] = v; }
//@ f_042260
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Startadresse des ersten Namensfeldes am Offset 0x00 der Heldenstruktur zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt denselben Zeiger als char* /hero*
 *   zurück.
 * - Wichtige Variablen: Zeigt auf den Beginn der Heldenstruktur p.
 === Ende Beschreibung === */
hero *f_042260(hero *p) { return p; }
//@ f_042270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die erste Versionsnummer (ver[0]) aus dem Kopf der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das erste Versionsbyte als unsigned
 *   char zurück.
 * - Wichtige Variablen: Liest das Feld p->ver[0].
 === Ende Beschreibung === */
unsigned char f_042270(hero *p) { return (unsigned char)p->ver[0]; }
//@ f_042280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die zweite Versionsnummer (ver[1]) aus dem Kopf der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das zweite Versionsbyte als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Feld p->ver[1].
 === Ende Beschreibung === */
unsigned char f_042280(hero *p) { return (unsigned char)p->ver[1]; }
//@ f_042290
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die dritte Versionsnummer (ver[2]) aus dem Kopf der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das dritte Versionsbyte als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Feld p->ver[2].
 === Ende Beschreibung === */
unsigned char f_042290(hero *p) { return (unsigned char)p->ver[2]; }
//@ f_0422a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die vierte Versionsnummer (ver[3]) aus dem Kopf der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das vierte Versionsbyte als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Feld p->ver[3].
 === Ende Beschreibung === */
unsigned char f_0422a0(hero *p) { return (unsigned char)p->ver[3]; }
//@ f_0422b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zeiger auf den Rufnamen (name) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt einen Zeiger (char*) auf das
 *   Namensfeld zurück.
 * - Wichtige Variablen: Greift auf das Feld p->name der Heldenstruktur zu.
 === Ende Beschreibung === */
char *f_0422b0(hero *p) { return p->name; }
//@ f_0422c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Rufnamen (name) des Helden auf die übergebene Zeichenkette.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Namen (s) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Kopiert den Text in das Feld p->name.
 === Ende Beschreibung === */
void f_0422c0(hero *p, char *s) { strcpy(p->name, s); }
//@ f_0422f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert den Dateinamen (file_name) für den Heldenexport oder -import in der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Dateinamen (s) und liefert keinen
 *   Rückgabewert (void).
 * - Wichtige Variablen: Kopiert die Zeichenkette in das Feld p->file_name.
 === Ende Beschreibung === */
void f_0422f0(hero *p, char *s) { strcpy(p->file_name, s); }
//@ f_042320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Zeiger auf den gespeicherten Dateinamen (file_name) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt einen Zeiger (char*) auf
 *   p->file_name zurück.
 * - Wichtige Variablen: Liest die Adresse von p->file_name.
 === Ende Beschreibung === */
char *f_042320(hero *p) { return p->file_name; }
//@ f_042330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Legt die Bildnummer des Heldenporträts (portrait, Offset 0x10) fest.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Porträt-Kennung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das 16-Bit-Feld p->portrait.
 === Ende Beschreibung === */
void f_042330(hero *p, int v_input) { short v = (short)v_input; p->portrait = v; }
//@ f_042340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuelle Bildnummer des Heldenporträts (portrait, Offset 0x10) aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Porträt-Kennung als short
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->portrait.
 === Ende Beschreibung === */
short f_042340(hero *p) { return (unsigned short)p->portrait; }
//@ f_042350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Archetyp beziehungsweise die Heldenklasse (type, z. B. Krieger, Streuner, Magier,
 *   Elf; 0 bedeutet leerer Gruppenplatz) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Typus als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->type (Offset 0x33).
 === Ende Beschreibung === */
signed char f_042350(hero *p) { return (unsigned char)p->type; }
//@ f_042360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den geschlechtsspezifischen Klassenindex (0 bis 19) für Text- und Grafiktabellen aus
 *   dem Heldentypus (type, begrenzt auf maximal 10) und dem Geschlecht (sex, 0 = männlich, 1 = weiblich) nach
 *   der Formel (type - 1) * 2 + sex.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den kombinierten
 *   Typus-Geschlechts-Index als int zurück.
 * - Wichtige Variablen: Liest die Felder p->type und p->sex.
 === Ende Beschreibung === */
// @@A42360=1
int f_042360(hero *p) {
    int i = ((signed char)p->type < 10) ? (signed char)p->type - 1 : 9;
    return (signed char)p->sex + i * 2;
}

//@ f_042380
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Geschlecht des Helden (sex, 0 = männlich, 1 = weiblich) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das Geschlecht als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->sex (Offset 0x34).
 === Ende Beschreibung === */
signed char f_042380(hero *p) { return (unsigned char)p->sex; }
//@ f_042390
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Schutzgottheit des Helden (god, 1 bis 12 für die Zwölfgötter) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Gottheitskennung als signed
 *   char zurück.
 * - Wichtige Variablen: Liest das Feld p->god (Offset 0x32).
 === Ende Beschreibung === */
signed char f_042390(hero *p) { return (unsigned char)p->god; }
//@ f_0423a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet die aktuell wirksame Magieresistenz (MR) des Helden als Summe aus dem Basiswert (mr)
 *   und dem temporären oder ausrüstungsbedingten Modifikator (mr_mod).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die gesamte Magieresistenz als
 *   signed char zurück.
 * - Wichtige Variablen: Addiert die Felder p->mr (Offset 0x78) und p->mr_mod (Offset 0xbb).
 === Ende Beschreibung === */
// @@A423a0=1
signed char f_0423a0(hero *p) { return (unsigned char)((unsigned char)p->mr + (unsigned char)p->mr_mod); }

//@ f_0423b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den aktuellen Magieresistenz-Modifikator (mr_mod) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Modifikator als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->mr_mod (Offset 0xbb).
 === Ende Beschreibung === */
signed char f_0423b0(hero *p) { return (unsigned char)p->mr_mod; }
//@ f_0423c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Rüstungsschutz-Grundwert (rs_bonus, Summe der getragenen Rüstungsteile) des Helden
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Rüstungsschutz als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->rs_bonus (Offset 0x42).
 === Ende Beschreibung === */
signed char f_0423c0(hero *p) { return (unsigned char)p->rs_bonus; }
//@ f_0423d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Rüstungsschutz-Grundwert (rs_bonus) des Helden auf den angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Rüstungsschutz (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->rs_bonus (Offset 0x42).
 === Ende Beschreibung === */
void f_0423d0(hero *p, int v_input) { signed char v = (signed char)v_input; p->rs_bonus = v; }
//@ f_0423e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den zusätzlichen magischen oder temporären Rüstungsschutz-Bonus (rs_bonus2, z. B. durch
 *   *Armatrutz*) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Zusatz-RS als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->rs_bonus2 (Offset 0x43).
 === Ende Beschreibung === */
signed char f_0423e0(hero *p) { return (unsigned char)p->rs_bonus2; }
//@ f_0423f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den gesamten Rüstungsschutz (RS) des Helden als Summe aus Rüstungs-RS (rs_bonus) und
 *   Zusatz-RS (rs_bonus2).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den gesamten Rüstungsschutz als
 *   signed char zurück.
 * - Wichtige Variablen: Addiert die Felder p->rs_bonus und p->rs_bonus2.
 === Ende Beschreibung === */
// @@A423f0=1
signed char f_0423f0(hero *p) { return (unsigned char)((unsigned char)p->rs_bonus + (unsigned char)p->rs_bonus2); }

//@ f_042400
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die NPC-Kennung (npc_id, Offset 0x9b; 0 bei regulären Spielerhelden, > 0 bei
 *   Begleit-NPCs) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die NPC-Kennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->npc_id (Offset 0x9b).
 === Ende Beschreibung === */
signed char f_042400(hero *p) { return (unsigned char)p->npc_id; }
//@ f_042410
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das persönliche Vermögen (money, in Hellern) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Geldbetrag als long zurück.
 * - Wichtige Variablen: Liest das 32-Bit-Feld p->money.
 === Ende Beschreibung === */
long f_042410(hero *p) { return p->money; }
//@ f_042420
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das persönliche Vermögen (money, in Hellern) des Helden auf den übergebenen Betrag.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Geldbetrag (v) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->money.
 === Ende Beschreibung === */
void f_042420(hero *p, long v) { p->money = v; }
//@ f_042430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Nummer der Teilgruppe (group_no, 0 bis 5) zurück, der dieser Held aktuell angehört.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Gruppennummer als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->group_no.
 === Ende Beschreibung === */
signed char f_042430(hero *p) { return (unsigned char)p->group_no; }
//@ f_042440
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Weist den Helden einer bestimmten Teilgruppe (group_no) zu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Gruppennummer (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->group_no.
 === Ende Beschreibung === */
void f_042440(hero *p, int v_input) { signed char v = (signed char)v_input; p->group_no = v; }
//@ f_042450
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die 1-basierte Gruppenposition (group_pos, 1 bis 7) des Helden innerhalb seiner Gruppe.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Position (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->group_pos.
 === Ende Beschreibung === */
void f_042450(hero *p, int v_input) { signed char v = (signed char)v_input; p->group_pos = v; }
//@ f_042460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuelle Gruppenposition (group_pos) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Position als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->group_pos.
 === Ende Beschreibung === */
signed char f_042460(hero *p) { return (unsigned char)p->group_pos; }
//@ f_042470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit dead (Bit 0 am Offset 0xbc), ob der Held tot ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held tot ist,
 *   sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.dead.
 === Ende Beschreibung === */
unsigned char f_042470(hero *p) { return p->status.dead; }
//@ f_042480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht den Todesstatus (status.dead) eines Helden und spiegelt diesen Status bei
 *   den ersten drei Begleit-NPCs (npc_id 1, 2 oder 3) zusätzlich in den globalen Story-Flags d_1bfabc, d_1bfac0
 *   beziehungsweise d_1bfac4.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Todesstatus (v, 0 oder 1)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->status.dead und aktualisiert bei Bedarf die NPC-Todesflags d_1bfabc,
 *   d_1bfac0 und d_1bfac4.
 === Ende Beschreibung === */
// @@A42480=0
void f_042480(hero *p, signed char v) {
    p->status.dead = v;
    int c = (signed char)p->npc_id;
    if (c == 1) { d_1bfabc = v; return; }
    if (c == 2) { d_1bfac0 = v; return; }
    if (c == 3) d_1bfac4 = v;
}

//@ f_0424d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit asleep (Bit 1 am Offset 0xbc), ob der Held schläft.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held schläft,
 *   sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.asleep.
 === Ende Beschreibung === */
unsigned char f_0424d0(hero *p) { return p->status.asleep; }
//@ f_0424e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit petrified (Bit 2 am Offset 0xbc), ob der Held versteinert ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held versteinert
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.petrified.
 === Ende Beschreibung === */
unsigned char f_0424e0(hero *p) { return p->status.petrified; }
//@ f_0424f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit petrified (Versteinerung) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Bitfeld p->status.petrified.
 === Ende Beschreibung === */
void f_0424f0(hero *p, int v_input) { signed char v = (signed char)v_input;
    p->status.petrified = v;
}
//@ f_042520
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit brewing (Bit 3 am Offset 0xbc), ob der Held gerade mit dem Brauen eines
 *   alchemistischen Tranks beschäftigt ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held braut,
 *   sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.brewing.
 === Ende Beschreibung === */
unsigned char f_042520(hero *p) { return p->status.brewing; }
//@ f_042530
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Alchemie-Status-Bit brewing des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Bitfeld p->status.brewing.
 === Ende Beschreibung === */
void f_042530(hero *p, int v_input) { short v = (short)v_input;
    p->status.brewing = v;
}
//@ f_042560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit chamaelioni, ob auf dem Helden der Tarnzauber *Chamaelioni Mimikry* aktiv
 *   ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Zauber aktiv
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.chamaelioni.
 === Ende Beschreibung === */
unsigned char f_042560(hero *p) { return p->status.chamaelioni; }
//@ f_042570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Aktiviert oder deaktiviert das Status-Bit chamaelioni (*Chamaelioni Mimikry*) beim Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Bitfeld p->status.chamaelioni.
 === Ende Beschreibung === */
void f_042570(hero *p, int v_input) { short v = (short)v_input;
    p->status.chamaelioni = v;
}
//@ f_0425a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit renegade, ob der Held feindlich/abtrünnig (z. B. durch *Böser Blick* oder
 *   *Horriphobus*) geworden ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held abtrünnig
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.renegade.
 === Ende Beschreibung === */
unsigned char f_0425a0(hero *p) { return p->status.renegade; }
//@ f_0425b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit renegade (abtrünnig) des Helden und markiert bei Aktivierung
 *   (v != 0) über d_1c219c = 1 die Kampfgruppe zur Neuprüfung.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->status.renegade und setzt gegebenenfalls d_1c219c.
 === Ende Beschreibung === */
void f_0425b0(hero *p, int v_input) { short v = (short)v_input;
    p->status.renegade = v;
    if (v) d_1c219c = 1;
}
//@ f_0425f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit unconscious, ob der Held bewusstlos ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held bewusstlos
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.unconscious.
 === Ende Beschreibung === */
unsigned char f_0425f0(hero *p) { return p->status.unconscious; }
//@ f_042600
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit tied, ob der Held gefesselt oder durch *Band und Fessel* gebunden ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held gefesselt
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.tied.
 === Ende Beschreibung === */
unsigned char f_042600(hero *p) { return p->status.tied; }
//@ f_042610
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit tied (gefesselt) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Bitfeld p->status.tied.
 === Ende Beschreibung === */
void f_042610(hero *p, int v_input) { signed char v = (signed char)v_input;
    p->status.tied = v;
}
//@ f_042640
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit scared, ob der Held in Panik versetzt ist und flieht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held verängstigt
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.scared.
 === Ende Beschreibung === */
unsigned char f_042640(hero *p) { return p->status.scared; }
//@ f_042650
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit scared (Panik/Flucht) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Bitfeld p->status.scared.
 === Ende Beschreibung === */
void f_042650(hero *p, int v_input) { signed char v = (signed char)v_input;
    p->status.scared = v;
}
//@ f_042680
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit tame (Bit 11 am Offset 0xbc), ob der Held besänftigt (*Sanftmut* /
 *   *Bannbaladin*) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn das Bit gesetzt ist,
 *   sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.tame.
 === Ende Beschreibung === */
unsigned char f_042680(hero *p) { return p->status.tame; }
//@ f_042690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit tame (Bit 11 am Offset 0xbc) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 11 im Statuswort bei Offset 0xbc.
 === Ende Beschreibung === */
void f_042690(hero *p, int v_input) { short v = (short)v_input;
    *(unsigned char *)((char *)p + 0xbd) &= 0xf7;
    *(unsigned *)((char *)p + 0xbc) |= ((int)v & 1U) << 0xb;
}
//@ f_0426c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit gods_pissed (Bit 13 am Offset 0xbc), ob der Held den Zorn der Götter auf
 *   sich gezogen hat.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn das Bit gesetzt ist,
 *   sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.gods_pissed.
 === Ende Beschreibung === */
unsigned char f_0426c0(hero *p) { return p->status.gods_pissed; }
//@ f_0426d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit gods_pissed (Bit 13 am Offset 0xbc) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 13 im Statuswort bei Offset 0xbc.
 === Ende Beschreibung === */
void f_0426d0(hero *p, int v_input) { short v = (short)v_input;
    *(unsigned char *)((char *)p + 0xbd) &= 0xdf;
    *(unsigned *)((char *)p + 0xbc) |= ((int)v & 1U) << 0xd;
}
//@ f_042700
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft das Status-Bit transformed (Bit 14 am Offset 0xbc), ob der Held verwandelt ist (z. B.
 *   durch *Visibili*, *Salander* oder *Adlerschwinge*).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held verwandelt
 *   ist, sonst 0.
 * - Wichtige Variablen: Liest das Bitfeld p->status.transformed.
 === Ende Beschreibung === */
unsigned char f_042700(hero *p) { return p->status.transformed; }
//@ f_042710
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht das Status-Bit transformed (Bit 14 am Offset 0xbc) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Statuswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 14 im Statuswort bei Offset 0xbc.
 === Ende Beschreibung === */
void f_042710(hero *p, int v_input) { short v = (short)v_input;
    *(unsigned char *)((char *)p + 0xbd) &= 0xbf;
    *(unsigned *)((char *)p + 0xbc) |= ((int)v & 1U) << 0xe;
}
//@ f_042740
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert einen Statuswert im Bytefeld fb5 (Offset 0xb5) der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->fb5.
 === Ende Beschreibung === */
void f_042740(hero *p, int v_input) { signed char v = (signed char)v_input; p->fb5 = v; }
//@ f_042750
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Statuswert aus dem Bytefeld fb5 (Offset 0xb5) der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->fb5.
 === Ende Beschreibung === */
signed char f_042750(hero *p) { return (unsigned char)p->fb5; }
//@ f_042760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Wert in das Kampf-/Statusfeld bei Offset 0x4fc der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den zu schreibenden Bytewert (v_input)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Byte an Offset 0x4fc.
 === Ende Beschreibung === */
void f_042760(hero *p, int v_input) { char v = (char)v_input; *(unsigned char *)((char *)p + 0x4fc) = v; }
//@ f_042770
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Kampf-/Statusfeld bei Offset 0x4fc der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das Byte an Offset 0x4fc als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Byte an Offset 0x4fc.
 === Ende Beschreibung === */
unsigned char f_042770(hero *p) { return *(unsigned char *)((char *)p + 0x4fc); }
//@ f_042780
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Wert in das Kampf-/Statusfeld bei Offset 0x4fd der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den zu schreibenden Bytewert (v_input)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Byte an Offset 0x4fd.
 === Ende Beschreibung === */
void f_042780(hero *p, int v_input) { char v = (char)v_input; *(unsigned char *)((char *)p + 0x4fd) = v; }
//@ f_042790
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Kampf-/Statusfeld bei Offset 0x4fd der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das Byte an Offset 0x4fd als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Byte an Offset 0x4fd.
 === Ende Beschreibung === */
unsigned char f_042790(hero *p) { return *(unsigned char *)((char *)p + 0x4fd); }
//@ f_0427a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schreibt einen Wert in das Kampf-/Statusfeld bei Offset 0x4fe der Heldenstruktur.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den zu schreibenden Bytewert (v_input)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Byte an Offset 0x4fe.
 === Ende Beschreibung === */
void f_0427a0(hero *p, int v_input) { char v = (char)v_input; *(unsigned char *)((char *)p + 0x4fe) = v; }
//@ f_0427b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Kampf-/Statusfeld bei Offset 0x4fe der Heldenstruktur aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das Byte an Offset 0x4fe als
 *   unsigned char zurück.
 * - Wichtige Variablen: Liest das Byte an Offset 0x4fe.
 === Ende Beschreibung === */
unsigned char f_0427b0(hero *p) { return *(unsigned char *)((char *)p + 0x4fe); }
//@ f_0427c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Fluchtposition (escape_position) des Helden für den Taktikkampf aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Fluchtposition als short
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->escape_position.
 === Ende Beschreibung === */
short f_0427c0(hero *p) { return (unsigned short)p->escape_position; }
//@ f_0427d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Fluchtposition (escape_position) des Helden für den Taktikkampf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Fluchtposition (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->escape_position.
 === Ende Beschreibung === */
void f_0427d0(hero *p, int v_input) { short v = (short)v_input; p->escape_position = v; }
//@ f_0427e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob und wie lange der Beschleunigungszauber *Axxeleratus Blitzgeschwind* (axxeleratus)
 *   auf dem Helden aktiv ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Statuswert von p->axxeleratus
 *   als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->axxeleratus.
 === Ende Beschreibung === */
signed char f_0427e0(hero *p) { return (unsigned char)p->axxeleratus; }
//@ f_0427f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Statuswert des Zaubers *Axxeleratus Blitzgeschwind* (axxeleratus) beim Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->axxeleratus.
 === Ende Beschreibung === */
void f_0427f0(hero *p, int v_input) { signed char v = (signed char)v_input; p->axxeleratus = v; }
//@ f_042800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuelle Kampf- oder Gruppenaktionskennung (action_id) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Aktionskennung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->action_id.
 === Ende Beschreibung === */
void f_042800(hero *p, int v_input) { signed char v = (signed char)v_input; p->action_id = v; }
//@ f_042810
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die aktuelle Kampf- oder Gruppenaktionskennung (action_id) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Aktionskennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->action_id.
 === Ende Beschreibung === */
signed char f_042810(hero *p) { return (unsigned char)p->action_id; }
//@ f_042820
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die verbleibende Braudauer (recipe_timer, in Tagen) für ein laufendes alchemistisches
 *   Rezept zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Timerwert als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->recipe_timer.
 === Ende Beschreibung === */
signed char f_042820(hero *p) { return (unsigned char)p->recipe_timer; }
//@ f_042830
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Rezeptkennung (recipe_id) des aktuell vom Helden gebrauten Tranks zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Rezeptkennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->recipe_id.
 === Ende Beschreibung === */
signed char f_042830(hero *p) { return (unsigned char)p->recipe_id; }
//@ f_042840
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert die Rezeptkennung (recipe_id) eines begonnenen alchemistischen Brauvorgangs beim
 *   Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Rezeptkennung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->recipe_id.
 === Ende Beschreibung === */
void f_042840(hero *p, int v_input) { signed char v = (signed char)v_input; p->recipe_id = v; }
//@ f_042850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Herbergskennung (alchemy_inn_id), in der der Held zum Brauen zurückgelassen wurde,
 *   aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Herbergskennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->alchemy_inn_id.
 === Ende Beschreibung === */
signed char f_042850(hero *p) { return (unsigned char)p->alchemy_inn_id; }
//@ f_042860
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Herbergskennung (alchemy_inn_id), in der der Held einen Trank braut.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Herbergskennung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->alchemy_inn_id.
 === Ende Beschreibung === */
void f_042860(hero *p, int v_input) { signed char v = (signed char)v_input; p->alchemy_inn_id = v; }
//@ f_042870
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert das Bytefeld bei Offset 0x32 (god bzw. Sonderzähler) um den angegebenen Summanden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Änderungswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v_input auf das Byte an Offset 0x32.
 === Ende Beschreibung === */
void f_042870(hero *p, int v_input) { char v = (char)v_input; *(char *)((char *)p + 0x32) += v; }
//@ f_042880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Anzahl der belegten Inventarplätze (nr_items) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Gegenstandsanzahl als signed
 *   char zurück.
 * - Wichtige Variablen: Liest das Feld p->nr_items.
 === Ende Beschreibung === */
signed char f_042880(hero *p) { return (unsigned char)p->nr_items; }
//@ f_042890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Attacke-/Parade-Basiswert (atpa_base) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Basiswert als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->atpa_base (Offset 0x79).
 === Ende Beschreibung === */
signed char f_042890(hero *p) { return (unsigned char)p->atpa_base; }
//@ f_0428a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Attacke-/Parade-Basiswert (atpa_base) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Basiswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->atpa_base (Offset 0x79).
 === Ende Beschreibung === */
void f_0428a0(hero *p, int v_input) { signed char v = (signed char)v_input; p->atpa_base = v; }
//@ f_0428b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Körpergröße (height, in Zentimetern) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Körpergröße als unsigned char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->height (Offset 0x35).
 === Ende Beschreibung === */
unsigned char f_0428b0(hero *p) { return (unsigned char)p->height; }
//@ f_0428c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt das Körpergewicht (weight, in Unzen) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt das Gewicht als short zurück.
 * - Wichtige Variablen: Liest das Feld p->weight (Offset 0x36).
 === Ende Beschreibung === */
short f_0428c0(hero *p) { return (unsigned short)p->weight; }
//@ f_0428d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuelle Erfahrungsstufe (level) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Stufe als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->level (Offset 0x39).
 === Ende Beschreibung === */
signed char f_0428d0(hero *p) { return (unsigned char)p->level; }
//@ f_0428e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht die Erfahrungsstufe (level, Offset 0x39) des Helden beim Stufenanstieg um 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Inkrementiert das Feld p->level (Offset 0x39).
 === Ende Beschreibung === */
void f_0428e0(hero *p) { ((char *)p)[0x39]++; }
//@ f_0428f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die gesamten gesammelten Abenteuerpunkte (ap) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Abenteuerpunkte als long
 *   zurück.
 * - Wichtige Variablen: Liest das 32-Bit-Feld p->ap (Offset 0x3a).
 === Ende Beschreibung === */
long f_0428f0(hero *p) { return p->ap; }
//@ f_042900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Hungerwert (hunger, 0 bis 100 %) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Hungerwert als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->hunger (Offset 0x91).
 === Ende Beschreibung === */
signed char f_042900(hero *p) { return (unsigned char)p->hunger; }
//@ f_042910
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Durstwert (thirst, 0 bis 100 %) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Durstwert als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->thirst (Offset 0x92).
 === Ende Beschreibung === */
signed char f_042910(hero *p) { return (unsigned char)p->thirst; }
//@ f_042920
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Hungerwert (hunger, Offset 0x91) des Helden direkt auf den angegebenen Prozentwert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Hungerwert (v_input) und
 *   gibt den gesetzten Wert als unsigned char zurück.
 * - Wichtige Variablen: Beschreibt das Feld p->hunger (Offset 0x91).
 === Ende Beschreibung === */
unsigned char f_042920(hero *p, int v_input) { unsigned char v = (unsigned char)v_input; return (*((char *)p + 0x91) = v); }
//@ f_042930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Durstwert (thirst, Offset 0x92) des Helden direkt auf den angegebenen Prozentwert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Durstwert (v_input) und gibt
 *   den gesetzten Wert als signed char zurück.
 * - Wichtige Variablen: Beschreibt das Feld p->thirst (Offset 0x92).
 === Ende Beschreibung === */
signed char f_042930(hero *p, int v_input) { signed char v = (signed char)v_input; return p->thirst = v; }
//@ f_042940
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest das Feld money_share (Anteil an der Beuteverteilung bzw. Söldneranteil) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Wert als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->money_share.
 === Ende Beschreibung === */
signed char f_042940(hero *p) { return (unsigned char)p->money_share; }
//@ f_042950
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Trunkenheitsgrad (drunk) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Trunkenheitswert als signed
 *   char zurück.
 * - Wichtige Variablen: Liest das Feld p->drunk (Offset 0xa1).
 === Ende Beschreibung === */
signed char f_042950(hero *p) { return (unsigned char)p->drunk; }
//@ f_042960
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuellen Lebenspunkte (le, Offset 0x72) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die aktuelle Lebensenergie als
 *   short zurück.
 * - Wichtige Variablen: Liest das Feld p->le (Offset 0x72).
 === Ende Beschreibung === */
short f_042960(hero *p) { return (unsigned short)p->le; }
//@ f_042970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die maximalen Lebenspunkte (le_max, Offset 0x70) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die maximale Lebensenergie als
 *   short zurück.
 * - Wichtige Variablen: Liest das Feld p->le_max (Offset 0x70).
 === Ende Beschreibung === */
short f_042970(hero *p) { return (unsigned short)p->le_max; }
//@ f_042980
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den durch schweren Hunger, Durst oder Krankheit verlorenen Anteil der maximalen
 *   Lebensenergie (le_mod, Offset 0x8c) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den LE-Abzug als short zurück.
 * - Wichtige Variablen: Liest das Feld p->le_mod (Offset 0x8c).
 === Ende Beschreibung === */
short f_042980(hero *p) { return (signed char)p->le_mod; }
//@ f_042990
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den temporären Abzug auf die maximale Lebensenergie (le_mod, Offset 0x8c) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Abzugswert (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->le_mod (Offset 0x8c).
 === Ende Beschreibung === */
void f_042990(hero *p, int v_input) { signed char v = (signed char)v_input; p->le_mod = v; }
//@ f_0429a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuellen Astralpunkte (ae, Offset 0x76) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die aktuelle Astralenergie als
 *   short zurück.
 * - Wichtige Variablen: Liest das Feld p->ae (Offset 0x76).
 === Ende Beschreibung === */
short f_0429a0(hero *p) { return (unsigned short)p->ae; }
//@ f_0429b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die maximalen Astralpunkte (ae_max, Offset 0x74) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die maximale Astralenergie als
 *   short zurück.
 * - Wichtige Variablen: Liest das Feld p->ae_max (Offset 0x74).
 === Ende Beschreibung === */
short f_0429b0(hero *p) { return (unsigned short)p->ae_max; }
//@ f_0429c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Adresse des Attribut-Eintrags (hero_attrib, 3 Bytes für Normalwert, aktuellen Wert
 *   und Modifikator ab Offset 0x46) für das angegebene Attribut (0 = MU bis 13 = GG).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Attribut-Index (i_input) und gibt
 *   einen Zeiger (hero_attrib*) auf den entsprechenden Eintrag zurück.
 * - Wichtige Variablen: Adressiert das Array p->attrib[i] ab Offset 0x46.
 === Ende Beschreibung === */
// @@A429c0=0
hero_attrib *f_0429c0(hero *p, int i_input) { short i = (short)i_input; return &p->attrib[i]; }

//@ f_0429e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt das Feld money_share des Helden auf den übergebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->money_share.
 === Ende Beschreibung === */
void f_0429e0(hero *p, int v_input) { signed char v = (signed char)v_input; p->money_share = v; }
//@ f_0429f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der Held grundsätzlich am Leben und nicht versteinert ist (weder Bit 0 dead noch Bit
 *   2 petrified im Statuswort bei Offset 0xbc gesetzt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held weder tot
 *   noch versteinert ist, andernfalls 0.
 * - Wichtige Variablen: Prüft die Bits 0x01 und 0x04 im Statusbyte p + 0xbc.
 === Ende Beschreibung === */
int f_0429f0(hero *p) {
    if ((*(char *)((char *)p + 0xbc) & 1) != 0 || (*(char *)((char *)p + 0xbc) & 4) != 0) return 0;
    return 1;
}
//@ f_042a10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand des Heldentypus (type >= 7), ob der Held magiebegabt ist (Hexe, Druide, Magier
 *   oder Elf).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt 1 zurück, wenn der Held
 *   zauberkundig ist, sonst 0.
 * - Wichtige Variablen: Liest das Feld p->type (Offset 0x33).
 === Ende Beschreibung === */
int f_042a10(hero *p) { return (signed char)p->type >= 7; }
//@ f_042a20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert einen Datenblock der Länge n_input in den Heldenrumpf ab Offset 0x32 (Gottheit, Typus,
 *   Geschlecht, Größe, Gewicht usw., z. B. bei der Charaktergenerierung oder beim Import).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Quellpuffer (s) und die Byteanzahl
 *   (n_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Überschreibt n_input Bytes ab p + 0x32.
 === Ende Beschreibung === */
void f_042a20(hero *p, char *s, int n_input) { short n = (short)n_input; memcpy((char *)p + 0x32, s, n); }
//@ f_042a40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Berechnet den aktuell wirksamen Wert einer Eigenschaft (i_input, 0 bis 13) als Summe aus dem
 *   aktuellen Eigenschaftswert (Offset 0x47 + i * 3) und dem temporären Eigenschaftsmodifikator (Offset 0x48 + i
 *   * 3).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Eigenschaftsindex (i_input) und
 *   gibt den effektiven Eigenschaftswert als signed char zurück.
 * - Wichtige Variablen: Liest die beiden Bytes q[0x47] und q[0x48] des Attribut-Arrays.
 === Ende Beschreibung === */
// @@A42a40=0
signed char f_042a40(hero *p, int i_input) { short i = (short)i_input;
    char *q = (char *)p + i * 3;
    return q[0x47] + q[0x48];
}

//@ f_042a60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Gegenstandskennung (item_id) im angegebenen Inventarslot (i_input, 0 bis 30) des
 *   Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt die
 *   Gegenstandskennung als short zurück (0 bei leerem Slot).
 * - Wichtige Variablen: Liest p->inv[i].item_id (Offset 0x1a6 + i * 0x1b).
 === Ende Beschreibung === */
short f_042a60(hero *p, int i_input) { short i = (short)i_input; return (unsigned short)p->inv[i].item_id; }
//@ f_042a90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt eine neue Gegenstandskennung (item_id) in den angegebenen Inventarslot (i_input) des
 *   Helden ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die
 *   Gegenstandskennung (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].item_id.
 === Ende Beschreibung === */
void f_042a90(hero *p, int i_input, int v_input) { short i = (short)i_input; short v = (short)v_input; p->inv[i].item_id = v; }
//@ f_042ac0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Stückzahl (quantity) von stapelbaren Gegenständen im angegebenen Inventarslot
 *   (i_input) zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt die
 *   Anzahl als short zurück.
 * - Wichtige Variablen: Liest p->inv[i].quantity.
 === Ende Beschreibung === */
short f_042ac0(hero *p, int i_input) { short i = (short)i_input; return (unsigned short)p->inv[i].quantity; }
//@ f_042af0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Stückzahl (quantity) im angegebenen Inventarslot (i_input) auf den übergebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die neue
 *   Stückzahl (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].quantity.
 === Ende Beschreibung === */
void f_042af0(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input; p->inv[i].quantity = v; }
//@ f_042b20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert die Stückzahl (quantity) im angegebenen Inventarslot (i_input) um den
 *   Differenzwert v_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die
 *   Mengenänderung (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v_input auf p->inv[i].quantity.
 === Ende Beschreibung === */
void f_042b20(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input; p->inv[i].quantity += v; }
//@ f_042b50
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den durch Abnutzung verlorenen Rüstungsschutz (rs_lost) eines Rüstungsstücks im
 *   Inventarslot i_input zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt den
 *   verlorenen RS-Wert als short zurück.
 * - Wichtige Variablen: Liest p->inv[i].rs_lost.
 === Ende Beschreibung === */
short f_042b50(hero *p, int i_input) { short i = (short)i_input; return (signed char)p->inv[i].rs_lost; }
//@ f_042b80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den durch Beschädigung verlorenen Rüstungsschutz (rs_lost) eines Rüstungsstücks im
 *   Inventarslot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den neuen
 *   Schadenswert (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].rs_lost.
 === Ende Beschreibung === */
void f_042b80(hero *p, int i_input, int v_input) { short i = (short)i_input; char v = (char)v_input; p->inv[i].rs_lost = v; }
//@ f_042bb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft Bit 0 des Gegenstands-Statusworts im Inventarslot i_input, ob die Waffe oder der
 *   Gegenstand zerbrochen ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn der Gegenstand zerbrochen ist, sonst 0.
 * - Wichtige Variablen: Liest Bit 0 des Statusworts bei p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042bb0(hero *p, int i_input) { short i = (short)i_input; return *(unsigned short *)((char *)p + 0x1ac + i * 0x1b) & 1; }
//@ f_042be0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Bruchfaktor (bf) der Waffe im Inventarslot i_input zurück (-99 steht für
 *   unzerbrechliche Waffen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt den
 *   Bruchfaktor als short zurück.
 * - Wichtige Variablen: Liest p->inv[i].bf (Offset 0x1ae + i * 0x1b).
 === Ende Beschreibung === */
short f_042be0(hero *p, int i_input) { short i = (short)i_input; return (signed char)p->inv[i].bf; }
//@ f_042c10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Bruchfaktor (bf) der Waffe im Inventarslot i_input auf den angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den neuen
 *   Bruchfaktor (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].bf.
 === Ende Beschreibung === */
void f_042c10(hero *p, int i_input, int v_input) { short i = (short)i_input; char v = (char)v_input; p->inv[i].bf = v; }
//@ f_042c40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Senkt den Bruchfaktor (bf) einer nicht unzerbrechlichen Waffe (bf != -99) im Slot i_input um
 *   1, solange er größer als 0 ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Dekrementiert p->inv[i].bf.
 === Ende Beschreibung === */
// @@A42c4x=1
void f_042c40(hero *p, int i_input) { short i = (short)i_input;
    int ok = (signed char)p->inv[i].bf != (signed char)-99;
    if (ok && (signed char)p->inv[i].bf > 0) (*(signed char *)(((char *)p + i * 0x1b) + 0x1ae))--;
}

//@ f_042ca0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht den Bruchfaktor (bf) einer nicht unzerbrechlichen Waffe (bf != -99) im Slot i_input
 *   nach einem misslungenen Bruchfaktortest um 1 (bis maximal 20).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Inkrementiert p->inv[i].bf.
 === Ende Beschreibung === */
// @@A42c4x=1
void f_042ca0(hero *p, int i_input) { short i = (short)i_input;
    int ok = (signed char)p->inv[i].bf != (signed char)-99;
    if (ok && (signed char)p->inv[i].bf < 20) (*(signed char *)(((char *)p + i * 0x1b) + 0x1ae))++;
}

//@ f_042d00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand des Bruchfaktors (bf != -99), ob der Gegenstand im Inventarslot i_input
 *   grundsätzlich zerbrechlich ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn der Gegenstand zerbrechen kann, sonst 0.
 * - Wichtige Variablen: Prüft p->inv[i].bf != -99.
 === Ende Beschreibung === */
int f_042d00(hero *p, int i_input) { short i = (short)i_input; return (signed char)p->inv[i].bf != (signed char)-99; }
//@ f_042d30
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 2 (b2) des Gegenstands-Statusworts im Inventarslot i_input aus (Kennzeichnung für
 *   benutzte/halbvolle oder speziell markierte Gegenstände).
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt den
 *   Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Extrahiert Bit 2 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042d30(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0xd; t >>= 0xf; return t; }
//@ f_042d60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 2 (b2) des Gegenstands-Statusworts im Inventarslot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 2 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42d60=0
void f_042d60(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b2 = v;
}

//@ f_042da0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 1 (b1) des Gegenstands-Statusworts im Inventarslot i_input aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt den
 *   Bitwert (0 oder 1) zurück.
 * - Wichtige Variablen: Extrahiert Bit 1 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042da0(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0xe; t >>= 0xf; return t; }
//@ f_042dd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 1 (b1) des Gegenstands-Statusworts im Inventarslot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 1 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42dd0=0
void f_042dd0(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b1 = v;
}

//@ f_042e10
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 3 (b3, Magisch-Flag) des Gegenstands-Statusworts im Inventarslot i_input aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn das Flag gesetzt ist, sonst 0.
 * - Wichtige Variablen: Extrahiert Bit 3 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042e10(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0xc; t >>= 0xf; return t; }
//@ f_042e40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 3 (b3, Magisch-Flag) des Gegenstands-Statusworts im Inventarslot
 *   i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 3 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42e40=0
void f_042e40(hero *p, int i_input, int v) { short i = (short)i_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b3 = v;
}

//@ f_042e80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 6 (b6, Magie-bekannt/identifiziert durch *Odem Arcanum* oder *Analüs*) des
 *   Gegenstands-Statusworts im Inventarslot i_input aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn das Bit gesetzt ist, sonst 0.
 * - Wichtige Variablen: Extrahiert Bit 6 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042e80(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0x9; t >>= 0xf; return t; }
//@ f_042eb0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 6 (b6, Magie identifiziert) des Gegenstands-Statusworts im Inventarslot
 *   i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 6 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42eb0=1
void f_042eb0(hero *p, int i_input, int v) { short i = (short)i_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b6 = v;
}

//@ f_042ef0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 7 (b7, vollständige Analyse bekannt) des Gegenstands-Statusworts im Inventarslot
 *   i_input aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn das Bit gesetzt ist, sonst 0.
 * - Wichtige Variablen: Extrahiert Bit 7 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042ef0(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0x8; t >>= 0xf; return t; }
//@ f_042f20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 7 (b7, vollständige Analyse bekannt) des Gegenstands-Statusworts im
 *   Inventarslot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 7 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42f20=1
void f_042f20(hero *p, int i_input, int v) { short i = (short)i_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b7 = v;
}

//@ f_042f60
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest Bit 4 (b4, vergiftete Waffe) des Gegenstands-Statusworts im Inventarslot i_input aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt 1
 *   zurück, wenn die Waffe vergiftet ist, sonst 0.
 * - Wichtige Variablen: Extrahiert Bit 4 aus dem Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
int f_042f60(hero *p, int i_input) { short i = (short)i_input; unsigned short t = *(short *)((char *)p + 0x1ac + i * 0x1b); t <<= 0xb; t >>= 0xf; return t; }
//@ f_042f90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt oder löscht Bit 4 (b4, vergiftete Waffe) des Gegenstands-Statusworts im Inventarslot
 *   i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie den Bitwert
 *   (v) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Modifiziert Bit 4 im Wort p + 0x1ac + i * 0x1b.
 === Ende Beschreibung === */
// @@A42f90=1
void f_042f90(hero *p, int i_input, int v) { short i = (short)i_input;
    ((struct BF16 *)((char *)p + 0x1ac + i * 0x1b))->b4 = v;
}

//@ f_042fd0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Giftart (poison_type) zurück, mit der die Waffe im Inventarslot i_input bestrichen
 *   ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt die
 *   Giftkennung als short zurück.
 * - Wichtige Variablen: Liest p->inv[i].poison_type.
 === Ende Beschreibung === */
short f_042fd0(hero *p, int i_input) { short i = (short)i_input; return (signed char)p->inv[i].poison_type; }
//@ f_043000
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert die Giftart (poison_type), mit der die Waffe im Inventarslot i_input bestrichen
 *   wurde.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die
 *   Giftkennung (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].poison_type.
 === Ende Beschreibung === */
void f_043000(hero *p, int i_input, int v_input) { short i = (short)i_input; char v = (char)v_input; p->inv[i].poison_type = v; }
//@ f_043030
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die verbleibende Anzahl an Giftanwendungen (poison_charges) einer vergifteten Waffe im
 *   Slot i_input zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt die
 *   Ladungsanzahl als unsigned char zurück.
 * - Wichtige Variablen: Liest p->inv[i].poison_charges.
 === Ende Beschreibung === */
unsigned char f_043030(hero *p, int i_input) { short i = (short)i_input; return (unsigned char)p->inv[i].poison_charges; }
//@ f_043060
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die verbleibende Anzahl an Giftanwendungen (poison_charges) der Waffe im Slot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die neue
 *   Ladungsanzahl (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].poison_charges.
 === Ende Beschreibung === */
void f_043060(hero *p, int i_input, int v_input) { short i = (short)i_input; char v = (char)v_input; p->inv[i].poison_charges = v; }
//@ f_043090
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die verbleibende Brenndauer (lighting_timer) einer brennenden Fackel oder Laterne im
 *   Inventarslot i_input zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt die
 *   Brenndauer als unsigned char zurück.
 * - Wichtige Variablen: Liest p->inv[i].lighting_timer.
 === Ende Beschreibung === */
unsigned char f_043090(hero *p, int i_input) { short i = (short)i_input; return (unsigned char)p->inv[i].lighting_timer; }
//@ f_0430c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die verbleibende Brenndauer (lighting_timer) einer Lichtquelle im Inventarslot i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Slot-Index (i_input) sowie die neue
 *   Brenndauer (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->inv[i].lighting_timer.
 === Ende Beschreibung === */
void f_0430c0(hero *p, int i_input, int v_input) { short i = (short)i_input; char v = (char)v_input; p->inv[i].lighting_timer = v; }
//@ f_0430f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest den Fertigkeitswert (ZfW) des Zauberspruchs mit Index i_input aus dem Zauber-Array
 *   (spells) des Helden aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Zauberindex (i_input) und gibt den
 *   Zauberwert als signed char zurück.
 * - Wichtige Variablen: Liest p->spells[i].
 === Ende Beschreibung === */
signed char f_0430f0(hero *p, int i_input) { short i = (short)i_input; return p->spells[i]; }
//@ f_043100
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Fertigkeitswert (ZfW) des Zauberspruchs i_input auf den angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Zauberindex (i_input) sowie den neuen
 *   Zauberwert (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->spells[i].
 === Ende Beschreibung === */
void f_043100(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input; p->spells[i] = v; }
//@ f_043110
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verändert den Fertigkeitswert (ZfW) des Zauberspruchs i_input um den Differenzwert v_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Zauberindex (i_input) sowie den
 *   Änderungswert (v_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v_input auf p->spells[i].
 === Ende Beschreibung === */
void f_043110(hero *p, int i_input, int v_input) { short i = (short)i_input; signed char v = (signed char)v_input; p->spells[i] += v; }
//@ f_043120
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den Waffentalent-Typ (weapon_type, 0 = Waffenlos bis 6 = Zweihänder) der aktuell
 *   geführten Waffe des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Waffentyp als short zurück.
 * - Wichtige Variablen: Liest p->weapon_type (Offset 0x8a).
 === Ende Beschreibung === */
short f_043120(hero *p) { return (signed char)p->weapon_type; }
//@ f_043130
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Trägt den Waffentalent-Typ (weapon_type), den Waffen-Attackemodifikator (at_mod) und den
 *   Waffen-Parademodifikator (pa_mod) der ausgerüsteten Waffe gleichzeitig in die Heldenstruktur ein.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Waffentyp (a_input), den AT-Modifikator
 *   (b_input) und den PA-Modifikator (c_input) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->weapon_type (0x8a), p->at_mod (0x88) und p->pa_mod (0x89).
 === Ende Beschreibung === */
void f_043130(hero *p, int a_input, int b_input, int c_input) { signed char a = (signed char)a_input; signed char b = (signed char)b_input; signed char c = (signed char)c_input;
    p->weapon_type = a;
    p->at_mod = b;
    p->pa_mod = c;
}
//@ f_043150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die gewählte Kampfweise (attack_type: +2 aggressiv, 0 normal, -2 vorsichtig) des Helden
 *   aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Kampfweise-Modifikator als
 *   signed char zurück.
 * - Wichtige Variablen: Liest p->attack_type (Offset 0x8b).
 === Ende Beschreibung === */
signed char f_043150(hero *p) { return (unsigned char)p->attack_type; }
//@ f_043160
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Kampfweise (attack_type: aggressiv, normal oder vorsichtig) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Kampfweise-Modifikator (v_input)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->attack_type (Offset 0x8b).
 === Ende Beschreibung === */
void f_043160(hero *p, int v_input) { signed char v = (signed char)v_input; p->attack_type = v; }
//@ f_043170
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die aktuell getragene Gesamtlast (load, in Unzen) des Helden zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Traglast als short zurück.
 * - Wichtige Variablen: Liest p->load (Offset 0x4ed).
 === Ende Beschreibung === */
short f_043170(hero *p) { return (unsigned short)p->load; }
//@ f_043180
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die aktuell getragene Gesamtlast (load, in Unzen) des Helden auf den angegebenen Wert.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Traglast (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt p->load (Offset 0x4ed).
 === Ende Beschreibung === */
void f_043180(hero *p, int v_input) { short v = (short)v_input; p->load = v; }
//@ f_043190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert die getragene Gesamtlast (load, Offset 0x4ed) des Helden um das Gewicht
 *   v_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Gewichtsänderung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v_input auf p->load (Offset 0x4ed).
 === Ende Beschreibung === */
void f_043190(hero *p, int v_input) { short v = (short)v_input; *(short *)((char *)p + 0x4ed) += v; }
//@ f_0431a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liefert die Speicheradresse des gesamten 0x1b Byte großen Inventarslots (inv_slot) mit Index
 *   i_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den Slot-Index (i_input) und gibt
 *   einen Zeiger (inv_slot*) auf den Inventareintrag zurück.
 * - Wichtige Variablen: Adressiert p->inv[i].
 === Ende Beschreibung === */
inv_slot *f_0431a0(hero *p, int i_input) { short i = (short)i_input; return &p->inv[i]; }
//@ f_0431d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Kopiert den gesamten Inhalt eines 0x1b Byte großen Inventarslots (*s) in den Inventarplatz
 *   i_input des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p), den Zielslot-Index (i_input) sowie den
 *   Quellzeiger (s) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Überschreibt die Struktur p->inv[i] mit *s.
 === Ende Beschreibung === */
// @@A431d0=0
void f_0431d0(hero *p, int i_input, inv_slot *s) { short i = (short)i_input; p->inv[i] = *s; }

//@ f_043210
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt die durch schweren Hunger oder Durst abgesenkten maximalen Lebenspunkte (le_mod, Offset
 *   0x8c) wieder her, indem der gespeicherte Abzug wieder auf le_max (Offset 0x70) aufaddiert und le_mod auf 0
 *   zurückgesetzt wird.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert p->le_mod (0x8c) auf p->le_max (0x70) und löscht p->le_mod.
 === Ende Beschreibung === */
void f_043210(hero *p) {
    short c = (signed char)p->le_mod;
    *((char *)p + 0x8c) = 0;
    *(short *)((char *)p + 0x70) += c;
}
//@ f_043230
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der Held durch den Zauber *Blitz dich find* geblendet (blind) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Blendungszähler als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->blind.
 === Ende Beschreibung === */
signed char f_043230(hero *p) { return (unsigned char)p->blind; }
//@ f_043240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Blendungsstatus (blind) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->blind.
 === Ende Beschreibung === */
void f_043240(hero *p, int v_input) { signed char v = (signed char)v_input; p->blind = v; }
//@ f_043250
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob auf dem Helden der Schattenzauber *Ecliptifactus* (ecliptifactus) aktiv ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Statuswert von p->ecliptifactus
 *   als signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->ecliptifactus.
 === Ende Beschreibung === */
signed char f_043250(hero *p) { return (unsigned char)p->ecliptifactus; }
//@ f_043260
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Statuswert des Zaubers *Ecliptifactus* (ecliptifactus) beim Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->ecliptifactus.
 === Ende Beschreibung === */
void f_043260(hero *p, int v_input) { signed char v = (signed char)v_input; p->ecliptifactus = v; }
//@ f_043270
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der Held unter dem Schutzzauber *Feuerbann* (fireban) steht.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Statuswert von p->fireban als
 *   signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->fireban.
 === Ende Beschreibung === */
signed char f_043270(hero *p) { return (unsigned char)p->fireban; }
//@ f_043280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Statuswert des Zaubers *Feuerbann* (fireban) beim Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->fireban.
 === Ende Beschreibung === */
void f_043280(hero *p, int v_input) { signed char v = (signed char)v_input; p->fireban = v; }
//@ f_043290
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob der Held unsichtbar (invisible, *Visibili Vanitar*) ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt den Unsichtbarkeitsstatus als
 *   signed char zurück.
 * - Wichtige Variablen: Liest das Feld p->invisible.
 === Ende Beschreibung === */
signed char f_043290(hero *p) { return (unsigned char)p->invisible; }
//@ f_0432a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt den Unsichtbarkeitsstatus (invisible) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie den neuen Wert (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->invisible.
 === Ende Beschreibung === */
void f_0432a0(hero *p, int v_input) { signed char v = (signed char)v_input; p->invisible = v; }
//@ f_0432b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Liest die Kennung des aktuellen Zielgegners (enemy_id) des Helden im Kampf aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Gegnerkennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->enemy_id.
 === Ende Beschreibung === */
signed char f_0432b0(hero *p) { return (unsigned char)p->enemy_id; }
//@ f_0432c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Speichert die Kennung des aktuellen Zielgegners (enemy_id) des Helden im Kampf.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Gegnerkennung (v_input) und
 *   liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->enemy_id.
 === Ende Beschreibung === */
void f_0432c0(hero *p, int v_input) { signed char v = (signed char)v_input; p->enemy_id = v; }
//@ f_0432d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die erreichte Stabzauber-Stufe (staffspell_lvl, 0 bis 7) eines Magiers zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Stabzauber-Stufe als signed
 *   char zurück.
 * - Wichtige Variablen: Liest das Feld p->staffspell_lvl.
 === Ende Beschreibung === */
signed char f_0432d0(hero *p) { return (unsigned char)p->staffspell_lvl; }
//@ f_0432e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die erreichte Stabzauber-Stufe (staffspell_lvl) eines Magiers.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Stabzauber-Stufe (v_input)
 *   und liefert keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->staffspell_lvl.
 === Ende Beschreibung === */
void f_0432e0(hero *p, int v_input) { signed char v = (signed char)v_input; p->staffspell_lvl = v; }
//@ f_0432f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Anzahl der noch offenen Zaubersteigerungsversuche (spell_incs) beim Stufenanstieg
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Anzahl als unsigned char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->spell_incs (Offset 0x1a5).
 === Ende Beschreibung === */
unsigned char f_0432f0(hero *p) { return (unsigned char)p->spell_incs; }
//@ f_043300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Anzahl der verfügbaren Zaubersteigerungsversuche (spell_incs) beim Stufenanstieg.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Anzahl (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->spell_incs (Offset 0x1a5).
 === Ende Beschreibung === */
void f_043300(hero *p, int v_input) { char v = (char)v_input; p->spell_incs = v; }
//@ f_043310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erhöht oder verringert die Anzahl der Zaubersteigerungsversuche (spell_incs, Offset 0x1a5) um
 *   den Wert v_input.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Änderung (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Addiert v_input auf p->spell_incs (Offset 0x1a5).
 === Ende Beschreibung === */
void f_043310(hero *p, int v_input) { char v = (char)v_input; *(char *)((char *)p + 0x1a5) += v; }
//@ f_043320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die gewählte Magierakademie beziehungsweise das Spezialgebiet (magic_school) eines
 *   Magiers zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Schulkennung als signed char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->magic_school.
 === Ende Beschreibung === */
signed char f_043320(hero *p) { return (unsigned char)p->magic_school; }
//@ f_043330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Magierakademie (magic_school) des Helden.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die Schulkennung (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->magic_school.
 === Ende Beschreibung === */
void f_043330(hero *p, int v_input) { signed char v = (signed char)v_input; p->magic_school = v; }
//@ f_043340
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt die Anzahl der noch offenen Talentsteigerungsversuche (skill_incs) beim Stufenanstieg
 *   zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) und gibt die Anzahl als unsigned char
 *   zurück.
 * - Wichtige Variablen: Liest das Feld p->skill_incs (Offset 0x14e).
 === Ende Beschreibung === */
unsigned char f_043340(hero *p) { return (unsigned char)p->skill_incs; }
//@ f_043350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Setzt die Anzahl der verfügbaren Talentsteigerungsversuche (skill_incs, Offset 0x14e) beim
 *   Stufenanstieg.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger (p) sowie die neue Anzahl (v_input) und liefert
 *   keinen Rückgabewert (void).
 * - Wichtige Variablen: Beschreibt das Feld p->skill_incs (Offset 0x14e).
 === Ende Beschreibung === */
void f_043350(hero *p, int v_input) { char v = (char)v_input; p->skill_incs = v; }
