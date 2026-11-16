/* === Beschreibung (Katalog) ===
 * Einheit fi_miovl (07aa40 - 07b370)
 *
 * Überblick
 * Die Einheit fi_miovl (Fight Misc Overlay) bündelt zehn Hilfsfunktionen für den Rundenkampf: die Abfrage
 * begehbarer Spezialkacheln (f_07aa40), die Prüfung von Sieg-, Niederlage- und Fluchtbedingungen (f_07aa90,
 * f_07aab0, f_07b1d0), das Aufräumen getöteter oder geflohener Gegner aus der Monsterliste (f_07ab80), das
 * Suchen freier Nachbarkacheln und das Einrücken wartender Verstärkungsmonster (f_07ad40, f_07aec0), das
 * Auffrischen der Aktionspunkte aller Monster zu Rundenbeginn (f_07b150) sowie das Einblenden einer Kampfmeldung
 * (f_07b220) und des Bildschirm-Blitzeffekts bei Kampfzaubern (f_07b2d0).
 === Ende Beschreibung === */
// P3 9/10 gleich (suche.py 30.10.2026, Basis fi_miovl_P1.CPP)
// fi_miovl.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x07AA40-0x07B370
#include <string.h>
void *mark(const char *file, int line);
void *operator new(unsigned size, void *tag);
void operator delete(void *p);
#pragma pack(1)
struct Dir { short x, y; };
struct Rec15 { char b[15]; };
struct Fig { char b[0x73]; };
void *f_014540(int p1, const char *p2, int p3);
int f_02ffa0(int p1);
int f_0309d0(int p1);
int f_069460();
int f_072910(int p1);
int f_072a00(int p1);
int f_0757f0(int p1);
int f_0773b0(int p1);
int f_07b370(int p1, int p2, int p3, unsigned char p4, int p5);
int f_07b7e0(int p1);
int f_07e850(int p1, int p2);
char *f_07ea60(int p1, int p2);
char *f_07eb00(int p1, int p2);
int f_07eba0(int p1, int p2, int p3);
int f_07ec10(int p1, int p2);
int f_099ea0();
void __cdecl f_099ef0(void *p, int a, int b);
void __cdecl f_149eb4(void *p, int a, int b);
char f_0cf910(int p1);
short f_0cfa10(int p1);
short f_0cfa50(int p1);
signed char f_0cfab0(int p1);
signed char f_0cfbb0(int p1);
int f_0cfbe0(int p1, int p2);
unsigned char f_0cfc50(int p1);
int f_0cfca0(int p1, int p2);
char f_0cfdc0(int p1);
int f_0cfdd0(int p1, int p2);
char f_0cfe30(int p1);
char f_0cfef0(int p1);
char f_0cffb0(int p1);
signed char f_0d00a0(int p1);
int f_0d00b0(int p1, int p2);
int f_0d01b0(int p1, int p2);
int f_0d4730(int p1);
int f_0e93f0(void *p1, char *p2, int p3);
char f_145400(unsigned char p1);
void *f_145300(void *p, int c, unsigned n);
extern Dir d_1a2734[];
extern short d_1bd924;
extern char d_1bd928;
extern char *d_1bd984;
extern char *d_1bda5c;
extern int d_1bda68;
extern int d_1bd914;
extern signed char d_1bfafc;
extern signed char d_1bfb00;
extern int d_1c0004;
extern short d_1c21a4;
extern int d_1c21b4;
extern char *d_1c2ed4;
short f_07b1d0();
extern int d_1c38b0;
extern const char d_1a1ed4[];
// Haelt die boolesche Zwischenberechnung in f_07b220 wie im Original.
#define EQI(x,v) (((x)==(v))?1:0)

//@ f_07aa40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand einer kurzen Nachschlagetabelle, ob der übergebene Kampfraster-Kachelwert c zu
 *   den sieben speziellen Boden- bzw. Hinderniskacheln (0x96..0x99 oder 0xa9..0xab) gehört.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Kachelwert c entgegen und gibt 1 zurück, wenn c in der Tabelle
 *   enthalten ist, andernfalls 0.
 * - Wichtige Variablen: Das lokale Array t[8] enthält die sieben Offsets relativ zur Basis 0x96 sowie die
 *   Endmarkierung 0xff.
 === Ende Beschreibung === */
int f_07aa40(unsigned char c)
{
    unsigned char t[8] = { 0, 1, 2, 3, 0x13, 0x14, 0x15, 0xff };
    short i;
    int r;
    i = 0;
    while (t[i] != 0xff) {
        if (c == t[i] + 0x96) { r = 1; goto END; }
        i++;
    }
    r = 0;
END:
    return r;
}

//@ f_07aa90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft im laufenden Kampf, ob keine kampffähigen Helden mehr auf dem Schlachtfeld stehen
 *   (f_02ffa0 == 0) und ob stattdessen zumindest geflohene Helden überlebt haben (f_0309d0).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt den Rückgabewert von f_0309d0 zurück,
 *   falls kein Held mehr auf dem Feld aktiv ist, sonst 0.
 * - Wichtige Variablen: Die globale Variable d_1c0004 verweist auf die aktive Heldengruppe.
 === Ende Beschreibung === */
int f_07aa90()
{
    if (f_02ffa0(d_1c0004) == 0) return f_0309d0(d_1c0004);
    return 0;
}

inline short h_07b1d0()
{
    short n;
    short i;
    n = 0;
    if (d_1bd928) f_069460();
    for (i = 0; i < (short)0x14; i++) {
        if (f_072a00((int)(d_1c2ed4 + i * 0x73))) n++;
    }
    return n;
}

//@ f_07aab0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entscheidet am Ende einer Kampfaktion, ob der Kampf weiterläuft (1) oder beendet ist (0), und
 *   setzt bei Flucht der gesamten Gruppe den Kampfausgang d_1c21a4 = 5 bzw. bei Kampfunfähigkeit aller Helden
 *   d_1c21a4 = 7. Solange noch Helden stehen, prüft sie über h_07b1d0, ob noch mindestens ein handlungsfähiger
 *   Gegner auf dem Schlachtfeld verblieben ist.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die Hauptkampfstruktur und gibt 1 zurück,
 *   solange der Kampf fortgesetzt wird, oder 0, wenn der Kampf geendet hat.
 * - Wichtige Variablen: Die globale Variable d_1c21a4 speichert den Ergebniscode des Kampfes (5 = Gruppe
 *   geflohen, 7 = Gruppe besiegt), und d_1bd928 kennzeichnet den Schnellkampfmodus.
 === Ende Beschreibung === */
int f_07aab0(int p1)
{
    if (f_07aa90()) {
        if (d_1bd928) f_07b7e0(p1);
        d_1c21a4 = 5;
        return 0;
    }
    if (f_02ffa0(d_1c0004) == 0) {
        if (d_1bd928) f_07b7e0(p1);
        d_1c21a4 = 7;
        return 0;
    }
    {
    int r = h_07b1d0();
    if (r != 0) r = 1;
    return r;
    }
}

//@ f_07ab80
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Bereinigt die Tabelle der bis zu 20 aktiven Monster (d_1c2ed4) sowie die zugehörigen
 *   15-Byte-Verstärkungseinträge (p + 0xee9), indem tote, geflohene oder versteinerte Gegner entfernt und die
 *   nachfolgenden Tabelleneinträge aufgerückt werden.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p auf die Hauptkampfstruktur entgegen und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Das Array d_1c2ed4 hält die 20 Monsterstrukturen zu je 0x73 Bytes, während ab p + 0xee9
 *   die zugehörigen 15-Byte-Start- und Verstärkungsdaten liegen.
 === Ende Beschreibung === */
void f_07ab80(char *p)
{
    short n;
    short i;
    short j;
    char *q;
    if (d_1bd928) f_069460();
    n = h_07b1d0();
    i = 0;
    while (i < (short)0x14) {
        q = d_1c2ed4 + i * 0x73;
        if (f_0cf910((int)q) && (f_0cfdc0((int)q) || f_0cfef0((int)q) || f_0cfe30((int)q) || (p[i * 0xf + 0xeed] && !n))) {
            if (i == 0x13) {
                f_145300(p + 0xee9 + i * 0xf, 0, 0xf);
                break;
            }
            for (j = i; j < 0x13; j++) {
                *(Rec15 *)(p + 0xee9 + j * 0xf) = *(Rec15 *)(p + 0xee9 + (j + 1) * 0xf);
                f_145300(p + 0xee9 + (j + 1) * 0xf, 0, 0xf);
                *(Fig *)(d_1c2ed4 + j * 0x73) = *(Fig *)(d_1c2ed4 + (j + 1) * 0x73);
                f_145300(d_1c2ed4 + (j + 1) * 0x73, 0, 0x73);
                f_0cfdd0((int)(d_1c2ed4 + (j + 1) * 0x73), 1);
            }
        } else {
            i++;
        }
    }
}

#define MAP(x,y) (*(d_1bd984 + (y) * 0x19 + (x)))
//@ f_07ad40
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sucht ausgehend von einer Wunschkoordinate (p2, p3) spiralförmig in den vier Hauptrichtungen
 *   nach dem nächstgelegenen freien Kampffeld (bzw. bei zweifeldrigen Großgegnern mit p7 != 0 nach zwei
 *   zusammenhängenden freien Feldern in Blickrichtung p6) und schreibt die gefundene Position nach *p4 und *p5.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1, die Startkoordinaten p2 und p3, die
 *   Ausgabezeiger p4 und p5, die Blickrichtung p6 sowie das Zweifeld-Flag p7 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das globale Array d_1bd984 repräsentiert das 24 x 25-Kampfraster, und d_1a2734 liefert
 *   die Richtungsvektoren der vier Blickrichtungen.
 === Ende Beschreibung === */
void f_07ad40(int p1, short p2, short p3, short *p4, short *p5, short p6, short p7)
{
    char found;
    short k;
    short i;
    short x, y;
    found = 0;
    if (d_1bd928) f_069460();
    *p4 = p2;
    *p5 = p3;
    if (MAP(p2, p3) != 0 || (p7 && MAP(p2 + d_1a2734[p6].x, p3 + d_1a2734[p6].y) != 0)) {
        k = 1;
        while (!found) {
            for (i = 0; i < 4; i++) {
                x = *p4 + d_1a2734[i].x * k;
                y = *p5 + d_1a2734[i].y * k;
                if (x >= 0 && x < 0x18 && y >= 0 && y < 0x18 && !MAP(x, y)
                    && (!p7 || !MAP(x + d_1a2734[p6].x, y + d_1a2734[p6].y))) {
                    found = 1;
                    *p4 = x;
                    *p5 = y;
                    break;
                }
            }
            k++;
        }
    }
}

//@ f_07aec0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt zu Beginn einer neuen Kampfrunde für alle noch in Reserve wartenden Verstärkungsmonster
 *   (f_0d00a0 > 0) den Runden-Countdown um 1 herunter und setzt jedes Monster, dessen Countdown 0 erreicht, auf
 *   ein freies Kampffeld (f_07ad40), aktiviert seine Darstellung in der Objektliste und addiert seine Lebens-
 *   und Astralpunkte zur gegnerischen Gesamtsumme (p + 0x145 und p + 0x147).
 * - Eingaben und Rückgabe: Die Funktion nimmt den Zeiger p auf die Hauptkampfstruktur entgegen und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1bd924 enthält die Gesamtzahl der im aktuellen Kampf definierten
 *   Monster, und d_1c2ed4 verweist auf deren Statusstrukturen.
 === Ende Beschreibung === */
void f_07aec0(char *p)
{
    int q;
    char *o, *o2;
    unsigned char id;
    signed char c;
    short y;
    short x;
    short i;
    id = (unsigned char)d_1bd924;   // Stapel-Layout: id vor c anfassen (toter Code)
    // Haelt die Temp-Identitaeten und Stapelslots wie im Original.
    char *r929b; short r929a; char r929c; short r929d;
    if (d_1bd928) f_069460();
    i = 0;
    c = id;
    if (i < d_1bd924) {
        c = i + 10;
        i = (i & 0) ? 0 : i;
        do {
            q = (int)(d_1c2ed4 + i * 0x73);
            if (f_0d00a0(q) > 0) {
                if (!f_0cfdc0(q)) {
                    f_0d00b0(q, (signed char)(f_0d00a0(q) - 1));
                    if (!f_0d00a0(q)) {
                        if (!f_0cffb0(q)) {
                            if (f_072910(q)) {
                                f_07ad40((int)p, (signed char)p[i * 0xf + 0xeea], (signed char)p[i * 0xf + 0xeeb], &x, &y, (signed char)p[i * 0xf + 0xeec], 1);
                                o = f_07ea60((int)p + 0x39, f_0cfc50(q));
                                o[0] = (char)x;
                                o[1] = (char)y;
                                o2 = f_07eb00((int)p + 0x39, (unsigned char)(o[0xd] + 0x14));
                                o2[0] = (char)x + (char)d_1a2734[(signed char)p[i * 0xf + 0xeec]].x;
                                o2[1] = (char)y + (char)d_1a2734[(signed char)p[i * 0xf + 0xeec]].y;
                                id = f_0cfc50(q);
                                f_07eba0((int)p + 0x39, id, 1);
                                f_07ec10((int)p + 0x39, (signed char)id);
                                id = o2[9];
                                f_07eba0((int)p + 0x39, id, 1);
                                f_07ec10((int)p + 0x39, (signed char)id);
                            } else {
                                f_07ad40((int)p, (signed char)p[i * 0xf + 0xeea], (signed char)p[i * 0xf + 0xeeb], &x, &y, (signed char)p[i * 0xf + 0xeec], 0);
                                o = f_07ea60((int)p + 0x39, f_0cfc50(q));
                                o[0] = (char)x;
                                o[1] = (char)y;
                                f_07eba0((int)p + 0x39, f_0cfc50(q), 1);
                                f_07ec10((int)p + 0x39, (signed char)f_0cfc50(q));
                            }
                            f_07b370((int)p, x, y, c, (signed char)p[i * 0xf + 0xeec]);
                            f_07e850((int)p + 0x39, f_0cfc50(q));
                            *(short *)(p + 0x145) += f_0cfa10(q);
                            *(short *)(p + 0x147) += f_0cfa50(q);
                        } else {
                            f_0cfdd0(q, 1);
                        }
                    }
                }
            }
            c++;
            i++;
        } while (i < d_1bd924);
    }
    r929b = d_1c2ed4; d_1c2ed4 = r929b;
    r929a = d_1bd924; d_1bd924 = r929a;
    r929c = d_1bd928; d_1bd928 = r929c;
    r929d = d_1a2734[0].x; d_1a2734[0].x = r929d;
}

//@ f_07b150
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Frischt zu Beginn einer neuen Kampfrunde für die ersten n Monster in d_1c2ed4 die aktuellen
 *   Aktionspunkte (f_0cfca0) und die Zahl der freien Paraden (f_0cfbe0) auf deren jeweilige Grundwerte auf,
 *   löscht das Überraschungsflag (f_0d01b0) und summiert alle vergebenen Aktionspunkte.
 * - Eingaben und Rückgabe: Die Funktion erhält den Kampfkontext p1 sowie die Monsteranzahl n und gibt die Summe
 *   der vergebenen Aktionspunkte als short zurück.
 * - Wichtige Variablen: Die Schleife läuft über d_1c2ed4 + i * 0x73 und addiert die Basis-Aktionspunkte
 *   (f_0cfab0) in sum.
 === Ende Beschreibung === */
short f_07b150(int p1, short n)
{
    short sum;
    short i;
    int q;
    signed char a, b, c2;
    sum = 0;
    if (d_1bd928) f_069460();
    for (i = 0; i < n; i++) {
        q = (int)(d_1c2ed4 + i * 0x73);
        a = f_0cfab0(q);
        f_0cfca0(q, a);
        sum += f_0cfab0(q);
        c2 = f_0cfbb0(q);
        f_0cfbe0(q, c2);
        f_0d01b0(q, 0);
    }
    return sum;
}

//@ f_07b1d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zählt, wie viele der bis zu 20 Monsterslots in d_1c2ed4 derzeit einen noch kampffähigen Gegner
 *   (f_072a00 != 0) enthalten.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt die Anzahl der noch aktiven Gegner als
 *   short zurück.
 * - Wichtige Variablen: Das globale Array d_1c2ed4 umfasst die 20 Monster-Slots zu je 0x73 Bytes.
 === Ende Beschreibung === */
short f_07b1d0()
{
    return h_07b1d0();
}

//@ f_07b220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert eine Kampftextmeldung anhand der Textkennung p1 in den Meldungspuffer d_1bda5c,
 *   sorgt für einen Großbuchstaben am Satzanfang, blendet die Meldung im Kampfbildschirm ein (f_0757f0), wartet
 *   die konfigurierte Lesepause ab (f_0d4730) und löscht die Meldung anschließend wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält die Text-Ressourcenkennung p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der Zeiger d_1bda5c verweist auf den Kampfmeldungstext, d_1bda68 markiert die Textzeile
 *   als änderungsbedürftig, und d_1bfb00 bzw. d_1bfafc bestimmen die eingestellte Lesepause.
 === Ende Beschreibung === */
void f_07b220(int p1)
{
    short s;
    f_0e93f0(&d_1c38b0, d_1bda5c, p1);
    *d_1bda5c = f_145400(*d_1bda5c);
    d_1bda68 = 1;
    f_0757f0(d_1bd914);
    if (f_0773b0(d_1c0004)) {
        s = (signed char)(d_1bfb00 + 2) * 0x14;
        if (EQI(d_1bfb00, 0)) s = 10;
    } else {
        s = (signed char)(d_1bfafc + 2) * 0x14;
    }
    f_0d4730(s);
    *d_1bda5c = 0;
    d_1bda68 = 1;
    f_0757f0(d_1bd914);
}

//@ f_07b2d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Erzeugt einen kurzen, grellen Blitzeffekt im Kampfbildschirm (unter anderem beim Zauber
 *   *Fulminictus*), indem die aktuelle VGA-Farbpalette gesichert, kurzzeitig komplett auf Weiß (0x3f) sowie
 *   Schwarz (0x00) geschaltet und nach fünf Bildwechseln wieder restauriert wird.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Der dynamisch reservierte Puffer buf (0x300 Bytes) sichert die ursprünglichen 256
 *   RGB-Farbwerte, während d_1c21b4 als temporärer Palettenpuffer für den Weiß- und Schwarzblitz dient.
 === Ende Beschreibung === */
void f_07b2d0()
{
    char *buf;
    short i;
    buf = (char *)f_014540(0x300, d_1a1ed4, 0x1fd);
    f_149eb4(buf, 0, 0x100);
    f_099ea0();
    f_145300(&d_1c21b4, 0x3f, 0x300);
    f_099ef0(&d_1c21b4, 0, 0x100);
    f_145300(&d_1c21b4, 0, 0x300);
    for (i = 0; i < 5; i++) f_099ea0();
    f_099ef0(buf, 0, 0x100);
    delete buf;
}
