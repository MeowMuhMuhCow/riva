/* === Beschreibung (Katalog) ===
 * Einheit gz_133de0_t1_rand910a (0x133DE0-0x133F90)
 *
 * Überblick
 * Die Einheit gz_133de0_t1_rand910a bildet den ersten Teil von gz_133de0 und enthält Methoden einer
 * Dungeon-/Schalter-Steuerklasse (Weiterleitung an die Basis-Initialisierung, Aktualisierung von
 * Raum-/Rätselschaltern 0x3d..0x64 sowie den virtuellen Destruktor).
 === Ende Beschreibung === */
// OPT -4r -oneatx -zp1 -s -ou
// P3 7/11 gleich (suche.py 25.10.2026, Basis gz_133de0_P1.CPP)
// I9: aus gz_133de0_REST.CPP uebernommen (Stufe-2-Stand), Marken 4 neu
// gz_133de0.cpp (Schatten ?ber Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x133DE0-0x134050. Kleine Hilfsfunktionen (Schalter-Update, Ringpuffer-Handles).  STAND: NICHT GLEICH, DF0 ~43 Befehle offen (a/c Registertausch ebp/edi)
void operator delete(void *p);                           // 0x014710
void f_060100(int a, int b, int c);
int f_069770(void *p, int id);
void f_069860(void *p, int id, int v);
void f_060230(void *p);
void *f_060030(void *p, int fl);
void *f_145234(void *p, void *d);
void f_145254();
int f_05f580();
extern char d_1bbc08[];
extern signed char d_1c0da0, d_1c0da4, d_1c0da8, d_1c0dd0;
extern int d_1c0dd4[];

#define Z(x) (((x) == 0) & 1)
#define IS(x, k) (((x) == k) & 1)

void f_133de0(int a, short b, short c) { f_060100(a, b, c); }

//@ f_133df0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Aktualisiert eine Gruppe zusammenhängender Dungeon-Schalter auf dem eingebetteten
 *   Schalter-Subobjekt self + 2. Liest den invertierten Zustand der Schalter 100 (0x64), 61 (0x3d) und 62 (0x3e)
 *   über f_069770, löscht Schalter 93 (0x5d), prüft, ob mindestens zwei der drei globalen Rätsel-Flags d_1c0da0,
 *   d_1c0da4 und d_1c0da8 bei d_1c0dd0 == 0 gesetzt sind, schiebt die gelesenen Zustände um eine Position weiter
 *   in die Schalter 100, 0x3d, 0x3e und 0x3f, setzt die Schalter 0x40..0x43 sowie 0x5c auf 0 und stößt
 *   anschließend über f_060230(self) die Neuberechnung an.
 * - Eingaben: char *self (this-Zeiger des Dungeon-Objekts).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1c0dd0 (signed char): Sperrflag für die Dreifach-Bedingung (0 = aktiv).
 *   - d_1c0da0, d_1c0da4, d_1c0da8 (signed char): Drei Teilbedingungen, von denen mindestens zwei den Wert 1
 *     haben müssen, damit Schalter 100 gesetzt wird.
 === Ende Beschreibung === */
void f_133df0(char *self)
{
    int c = 0;
    int b;
    int a;
    a = f_069770(self + 2, 100) == 0;
    b = f_069770(self + 2, 0x3d) == 0;
    c = f_069770(self + 2, 0x3e) == 0;
    f_069860(self + 2, 0x5d, 0);
    int r = 0;
    if (IS(d_1c0dd0, 0)) {
        short n = 0;
        if (IS(d_1c0da0, 1)) n++;
        if (IS(d_1c0da4, 1)) n++;
        if (IS(d_1c0da8, 1)) n++;
        if ((int)n >= 2) r = 1;
    }
    void *q = self + 2;
    f_069860(q, 100, r);
    f_069860(q, 0x3d, a);
    f_069860(q, 0x3e, b);
    f_069860(q, 0x3f, c);
    f_069860(q, 0x40, 0);
    f_069860(q, 0x41, 0);
    f_069860(q, 0x42, 0);
    f_069860(q, 0x43, 0);
    f_069860(q, 0x5c, 0);
    f_060230(self);
}

//@ f_133f50
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Virtueller Destruktor bzw. Serialisierungs-Helfer des Dungeon-Objekts. Bei gesetztem Bit
 *   fl & 4 wird das Objekt über f_145234(self, d_1bbc08) und f_145254() registriert; andernfalls ruft die
 *   Funktion den Basis-Destruktor f_060030(self, 1) auf und gibt bei fl & 2 den Speicher über operator delete
 *   frei.
 * - Eingaben: void *self (this-Zeiger), unsigned fl (Destruktor-/Modus-Flags).
 * - Rückgabewert: void * (self).
 * - Wichtige Variablen:
 *   - d_1bbc08 (char[]): Typ-/Klassendeskriptor für die Serialisierung.
 === Ende Beschreibung === */
void *f_133f50(void *self, unsigned fl)
{
    if (fl & 4) {
        f_145234(self, d_1bbc08);
        f_145254();
        return self;
    }
    self = f_060030(self, 1);
    if (fl & 2) operator delete(self);
    return self;
}

int f_133f90() ;
//@ f_133fa0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Virtuelle Standardmethode (Stub), die konstant 0 zurückgibt.
 * - Eingaben: Keine.
 * - Rückgabewert: int (immer 0).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_133fa0()
;
//@ f_133fb0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Virtuelle Standardmethode (Stub), die konstant 0 zurückgibt.
 * - Eingaben: Keine.
 * - Rückgabewert: int (immer 0).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_133fb0() ;
int f_133fc0() ;
void f_133fd0(short *p) ;

//@ f_133fe0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Trägt einen neuen Stringzeiger v an der aktuellen Position *p in den Ringpuffer d_1c0dd4
 *   ein, bildet daraus das Pseudo-Text-Handle *p + 0x0eee0000, erhöht den Ringpufferindex *p um 1 (mit
 *   Rücksprung auf 0 bei *p == 0x22 = 34) und gibt das gebildete Handle zurück.
 * - Eingaben: short *p (this-Zeiger auf den aktuellen Ringpufferindex), int v (Zeiger auf die einzutragende
 *   Zeichenkette).
 * - Rückgabewert: int (Pseudo-Text-Handle 0x0eee0000 + index).
 * - Wichtige Variablen:
 *   - d_1c0dd4 (int[34]): Ringpuffer der registrierten Stringzeiger.
 === Ende Beschreibung === */
int f_133fe0(short *p, int v)
;

//@ f_134010
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Prüft anhand der oberen 16 Bits ((b >> 16) == 0x0eee), ob es sich bei einer Text-Kennung b
 *   um ein Ringpuffer-Handle aus f_133fe0 handelt.
 * - Eingaben: int a (this-Zeiger, ungenutzt), unsigned b (zu prüfende Text-ID).
 * - Rückgabewert: int (1, wenn (b >> 16) == 0x0eee, sonst 0).
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
int f_134010(int a, unsigned b)
;

//@ f_134030
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest zu einem Ringpuffer-Index b (untere 16 Bits eines 0x0eee....-Handles) den
 *   zugehörigen Stringzeiger d_1c0dd4[b] aus, sofern b < 0x23 ist.
 * - Eingaben: signed char a (this-Zeiger, ungenutzt), short b (Ringpufferindex im unteren 16-Bit-Wort), int c
 *   (Register ebx beim Eintritt).
 * - Rückgabewert: const char * (in eax: der gespeicherte Stringzeiger d_1c0dd4[b]).
 * - Wichtige Variablen:
 *   - d_1c0dd4 (int[]): Ringpuffer der Stringzeiger.
 *   - Hinweis (Originalfehler): f_133fe0 setzt den Ringpuffer bereits bei *p == 0x22 (34 Einträge, 0..0x21) auf
 *     0 zurück, während f_134030 auf b < 0x23 (0..0x22) prüft, keine Untergrenze b >= 0 testet und im Fall b >=
 *     0x23 das Rückgaberegister (ebx) überhaupt nicht initialisiert.
 === Ende Beschreibung === */
short f_134030(signed char a, short b, int c)
;
#pragma aux f_134030 modify exact [eax];
