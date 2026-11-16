/* === Beschreibung (Katalog) ===
 * Einheit textstub (0x125400-0x125940)
 *
 * Überblick
 * Die Einheit textstub (im Original textstub.cpp) implementiert die Grundmethoden der Klasse RivaTextContext
 * (Größe 0x3C Bytes), die bei der Textformatierung und Platzhalter-Ersetzung (Heldennamen, Gegenstandsnamen mit
 * Grammatik-/Kasusformen, Zahlenwerte und Text-Handles) als verketteter Kontextstapel dient.
 === Ende Beschreibung === */
#include "RIVAITEM.H"
#include "RIVACTX.H"
#include "RIVAMEM.H"
// P3 7/8 gleich (suche.py 30.10.2026, Basis textstub_P1.CPP)
// I9: aus textstub_REST.CPP uebernommen (Stufe-2-Stand), Marken 4 neu
// REST (Helfer A, Regelrunde 1, 5 Laeufe): 15 Befehle offen in f_125550. Fall 2: Original edx=tail.fc; push; ebx=tail.f20; movsx ebx,WORD direkt, Tabellen in edx/ebx; ours Tabellen ecx/esi + movsx ebx,bx (short-Param) bzw. int-Param -> Kaskade. Fall 3: Tabelle in ebx statt edx.
// textstub.cpp (Schatten über Riva, Attic 1996) - rekonstruiert 21.10.2026, Phase 4
// Code 0x125400-0x125940. Klasse Ctx (Kontext, 0x3C Bytes): Tabellen, Textpuffer, Dekoder fuer Textcodes.
#include <string.h>
#include <stdio.h>
extern const char d_1a8b20[];
#define textstub_file d_1a8b20
extern const char d_1b8504[];                            // "%ld"
typedef short F20T;
struct Blk { char b[0x120]; };




void f_0b04d0(int a, RivaTextSelector b);
struct RivaTextContext;
extern RivaTextContext *d_1c0c48;

extern RivaTextContext *d_1c0c48;




//@ f_125400
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Konstruktor von RivaTextContext. Reserviert einen 0x120 Bytes großen Arbeitsblock f0 für
 *   die acht Platzhalter-Tabellen (f4 für Heldenzeiger, f8 und f1c für Monster/NPCs, fc und f20 für Gegenstände
 *   und deren Stückzahlen, f10 für Text-IDs, f14 für short-Zahlen, f18 für int-Zahlen), füllt ihn mit 0xcc,
 *   speichert die übergebenen Textkatalog- und Lookup-Zeiger und hängt das Objekt an die Spitze der globalen
 *   Kontextkette d_1c0c48.
 * - Eingaben: this (RivaTextContext *), void *a (Zeiger auf den Text-Lookup RivaTextLookup *), void *b (Zeiger
 *   auf die Kontextkennung f30), void *c (Zeiger auf den Ringpuffer-Textkatalog RivaTextCatalog *).
 * - Rückgabewert: RivaTextContext * (this).
 * - Wichtige Variablen:
 *   - f0 (char *): Zeiger auf den 0x120-Byte-Tabellenpuffer des Textkontexts.
 *   - d_1c0c48 (RivaTextContext *): Kopfzeiger der verketteten Liste aktiver Textkontexte (vorheriger Kontext
 *     wird in tables.tail.f38 gesichert).
 === Ende Beschreibung === */
RivaTextContext *RivaTextContext::f_125400(void *a, void *b, void *c)
{
    char *t = (char *)new (mark(textstub_file, 0x2f)) Blk;
    f0 = t;
    tables.f4 = (void **)t;
    tables.tail.f8 = (void **)(t + 0x20);
    tables.tail.fc = (void **)(f0 + 0x40);
    tables.tail.f10 = (int *)(f0 + 0x60);
    tables.tail.f14 = (short *)(f0 + 0xa0);
    tables.tail.f18 = (int *)(f0 + 0xc0);
    tables.tail.f1c = (short *)(f0 + 0x100);
    tables.tail.f20 = (F20T *)(f0 + 0x110);
    memset(f0, 0xcccc, 0x120);
    tables.tail.f24 = 0;
    tables.tail.f34 = (RivaTextLookup *)a;
    tables.tail.f38 = d_1c0c48;
    tables.tail.f30 = *(int *)b;
    d_1c0c48 = this;
    tables.tail.f2c = (RivaTextCatalog *)c;
    return this;
}

//@ f_1254a0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Destruktor von RivaTextContext. Stellt den vorherigen Textkontext aus tables.tail.f38 in
 *   der globalen Variable d_1c0c48 wieder her und gibt den 0x120-Byte-Tabellenpuffer f0 frei.
 * - Eingaben: this (RivaTextContext *), int unused (Destruktor-Flag).
 * - Rückgabewert: RivaTextContext * (this).
 * - Wichtige Variablen:
 *   - d_1c0c48 (RivaTextContext *): Wird auf den Vorgängerkontext tables.tail.f38 zurückgesetzt.
 === Ende Beschreibung === */
RivaTextContext *RivaTextContext::f_1254a0(int unused)
{
    RivaTextContext *p = this;
    d_1c0c48 = p->tables.tail.f38;
    delete p->f0;
    return p;
}
void RivaTextContext::f_1254c0() { memset(f0, 0xcccc, 0x120); }
int RivaTextContext::f_1254e0() { int r = 0; if (tables.tail.f24) r = 1; return r; }
//@ f_125500
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Liest das nächste Zeichen aus dem aktuell expandierten Platzhalter-String über den
 *   Lesezeiger tables.tail.f28 aus und rückt f28 um 1 Byte weiter. Ist das nachfolgende Zeichen (oder das
 *   gelesene Zeichen selbst) das Nullbyte \0, wird der temporäre Puffer tables.tail.f24 sofort freigegeben und
 *   auf 0 gesetzt.
 * - Eingaben: this (RivaTextContext *).
 * - Rückgabewert: signed char (das gelesene Zeichen aus der Platzhalter-Ersetzung).
 * - Wichtige Variablen:
 *   - tables.tail.f24 (char *): Allokierter Puffer der aktuellen Platzhalter-Ersetzung.
 *   - tables.tail.f28 (char *): Laufender Lesezeiger innerhalb von f24.
 === Ende Beschreibung === */
signed char RivaTextContext::f_125500()
{
    char *q = tables.tail.f28; q++; signed char c = q[-1]; tables.tail.f28 = q;
    if (*(signed char *)tables.tail.f28 == 0 || c == 0) {
        delete tables.tail.f24;
        tables.tail.f24 = 0;
    }
    return c;
}
//@ f_125550
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Dekodiert eine 3-Byte-Steuersequenz (p2, p3, p4) aus einem Spieltext in Tabellenwahl (k =
 *   (p2 & 0xf) - 1), Tabellenindex (i = (p2 & 0xf0) >> 4) sowie grammatische Formatierungs- und
 *   Kasus-/Artikel-Flags (t1, t3). Abhängig von der Tabellennummer k (0..5) verzweigt die Funktion in die
 *   entsprechende Formatierungsroutine für Helden (f_125940), Gegner/NPCs (f_125c20), Gegenstände (f_125a30),
 *   Text-Handles (f_1258c0), 16-Bit-Zahlen (f_125880 mit f14[i]) oder 32-Bit-Zahlen (f_125880 mit f18[i]).
 * - Eingaben: this (RivaTextContext *), signed char p2 (Tabellennummer und Index), signed char p3 (Formatflags
 *   t1), signed char p4 (Grammatik-/Plural-/Geschlechtsflags t3).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - t1 (RivaTextFormat), t2 (RivaTextSelector), t3 (RivaTextFlags): Entpackte Bitfelder der
 *     3-Byte-Textsteuersequenz.
 *   - tables.f4, f8, fc, f10, f14, f18, f1c, f20: Die acht Platzhalter-Tabellen im Puffer f0.
 === Ende Beschreibung === */
void RivaTextContext::f_125550(signed char p2, signed char p3, signed char p4)
{
    RivaTextFormat t1; RivaTextSelector t2; RivaTextFlags t3;
    t2.lo = (p2 & 0xf) - 1;
    t2.hi = (p2 & 0xf0) >> 4;
    t1.a = p3 & 3;
    t1.b = ((p3 & 0x1c) >> 2) - 1;
    t1.c = ((p3 & 0xe0) >> 5) - 1;
    t3.c = p4 & 0xf;
    t3.b = ((p4 & 0x30) >> 4) - 1;
    t3.a = ((p4 & 0xe0) >> 6) - 1;
    unsigned k = t2.lo; short i = t2.hi;
    if (t1.a == 1 && t3.c != 0xf) {
        short j = (p4 & 0xf0) >> 4;
        t3.b = ((unsigned short)tables.tail.f20[j] == 1) ? 0 : 1;
        t3.a = ((int)(((RivaItemDefinition*)(tables.tail.fc[j]))->f_0a78c0()));
    }
    f_0b04d0(tables.tail.f30, t2);
    switch ((unsigned short)k) {
    case 0: f_125940(tables.f4[(short)(i & 0xffff)], t1, t3); break; // haelt die Registerzuteilung wie im Original
    case 1: f_125c20(tables.tail.f8[i], tables.tail.f1c[i], t1, t3); break;
    case 2: f_125a30(tables.tail.fc[i], tables.tail.f20[i], t1, t3); break;
    case 3: f_1258c0(tables.tail.f10[(short)(i & 0xffff)]); break; // haelt die Registerzuteilung wie im Original
    case 4: f_125880(tables.tail.f14[i]); break;
    case 5: f_125880(tables.tail.f18[i]); break;
    }
}
//@ f_125880
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Wandelt einen ganzzahligen Platzhalterwert x mit sprintf(p, "%ld", x) in eine
 *   Dezimal-Zeichenkette um, legt dafür einen 25 Bytes großen temporären Puffer an und trägt ihn in
 *   tables.tail.f24 und tables.tail.f28 zur Ausgabe ein.
 * - Eingaben: this (RivaTextContext *), int x (auszugebender Zahlenwert).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - d_1b8504 (const char[]): Formatstring "%ld".
 *   - tables.tail.f24, tables.tail.f28 (char *): Empfangspuffer für den formatierten Zahlentext.
 === Ende Beschreibung === */
void RivaTextContext::f_125880(int x) {
    char *p = (char *)new (mark(textstub_file, 0xcf)) char[0x19];
    tables.tail.f28 = tables.tail.f24 = p;
    sprintf(p, d_1b8504, x);
}
//@ f_1258c0
/* === Beschreibung (Katalog) ===
 * - Aufgabe im Spiel: Löst eine Text-Kennung n auf, indem geprüft wird, ob es sich um ein temporäres
 *   Ringpuffer-Handle mit der Kennung 0x0eee.... (f_134010(n) == 1, Auslesen über f_134030) oder um eine
 *   reguläre Text-ID aus der Textdatenbank (f_099b10(n)) handelt, und kopiert den gefundenen String in einen neu
 *   angelegten Puffer tables.tail.f24.
 * - Eingaben: this (RivaTextContext *), int n (Text-ID oder 0x0eee0000-Ringpuffer-Handle).
 * - Rückgabewert: Keiner (void).
 * - Wichtige Variablen:
 *   - tables.tail.f2c (RivaTextCatalog *): Zeiger auf die Ringpuffer-Verwaltung für dynamische Teilstrings.
 *   - tables.tail.f34 (RivaTextLookup *): Zeiger auf die Textdatenbank-Suchinstanz.
 === Ende Beschreibung === */
void RivaTextContext::f_1258c0(int n) {
    const char *s;
    if (tables.tail.f2c->f_134010(n) == 1) s = tables.tail.f2c->f_134030(n);
    else s = tables.tail.f34->f_099b10(n);
    char *p = (char *)new (mark(textstub_file, 0xf1)) char[strlen(s) + 1];
    tables.tail.f28 = tables.tail.f24 = p;
    strcpy(p, s);
}

