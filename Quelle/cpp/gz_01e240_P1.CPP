/* === Beschreibung (Katalog) ===
 * Einheit gz_01e240
 *
 * Diese Einheit (Adressbereich 0x01e240-0x01e860) umfasst zwei voneinander unabhängige Subsysteme:
 * 1. Dynamische Zeichenkettenliste (AL, 0x26 Bytes, f_01e240-f_01e570): Eine generische Containerklasse für
 *   variabel lange Einträge mit Versatztabelle (offs) und zusammenhängendem Datenpuffer (base), die in
 *   xdialog_t1 zum Verwalten und Formatieren von Dialogtexten genutzt wird.
 * 2. Lebens- und Astralenergie-Statusbalken (d_1c2bcc, f_01e5e0-f_01e630): Konstruktor und Zeichenfunktion für
 *   die senkrechten LE- und AE-Balken der Helden in der unteren Statusleiste und in Heldenfenstern (Gegenstück
 *   zu seg004.c:draw_bar und g_status_bar_colors in *Schicksalsklinge*).
 === Ende Beschreibung === */
// P3 14/15 gleich (suche.py 29.10.2026, Basis gz_01e240_P1.CPP)
// OPT -4r -oneatx -oe=200 -zp1 -s
// P3 11/15 gleich (suche.py 26.10.2026, Basis gz_01e240_P1.CPP)
// gz_01e240.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x01E240-0x01E860
#include <string.h>
//#include "RIVA_CLOBBER.H"      // nur noetig, wenn unten ein (SICHERT)-Name vorkommt
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
int f_01e110(int p1);                                   // reg eax stapel 0
int f_01e1a0(int p1, int p2);                           // reg eax edx stapel 0
int f_0bba10();                                // reg eax edx
int f_0bd350(int p1, int p2, int p3);                   // reg eax edx ebx stapel 0
int f_1483f0(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
int f_148450(int p1, int p2, int p3, int p4, int p5);   // reg eax edx ebx ecx stapel 4
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern int d_1a34e0;                    // 0x1A34E0
extern signed char d_1a5544[];
extern short d_1bd90c;                  // 0x1BD90C
// --- eigene Funktionen (15), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
//@ f_01e240  groesse 80 B, 14 Bef, reg eax edx ebx ecx, stapel 4
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert ein AL-Listenobjekt (0x26 Bytes): er setzt Fehlercode (err),
 *   Eintragsanzahl (cnt), Tabellen- und Pufferkapazität (s4, i10), Pufferfüllstand (cur), Iterator (idx) sowie
 *   die Zeiger auf Versatztabelle (offs) und Datenpuffer (base) auf 0 und speichert die Elementgröße p2 (bei
 *   Zeichenketten 1) sowie die drei Funktionszeiger für Vergleich (p3, strcmp), Kopie (p4, strcpy) und Länge
 *   (p5, strlen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 (AL *, this), die Elementgröße p2 (unsigned
 *   short) sowie die Funktionszeiger p3 (CMPF), p4 (CPYF) und p5 (LENF) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Initialisiert werden alle Felder der 0x26 Bytes großen Struktur AL.
 === Ende Beschreibung === */
//@ f_01e290  groesse 272 B, 38 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor gibt - falls vorhanden - die Versatztabelle p1->offs und den Datenpuffer
 *   p1->base frei, setzt sämtliche Zähler, den Iterator und den Fehlercode auf 0 zurück und liefert den
 *   Objektzeiger p1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und das ungenutzte
 *   Destruktor-Flag p2 (int) und gibt p1 zurück.
 * - Wichtige Variablen: Freigegeben werden p1->offs (+0x1e) und p1->base (+0x22).
 === Ende Beschreibung === */
//@ f_01e300  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt den im Feld p1->err gespeicherten Fehlercode der letzten Operation zurück (0
 *   = kein Fehler, 0x404 = Eintrag bereits vorhanden bei f_01e4e0, 0x409 = Liste voll bei f_01e430), ohne ihn
 *   zurückzusetzen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert p1->err (unsigned
 *   short).
 * - Wichtige Variablen: Gelesen wird p1->err (+0x00).
 === Ende Beschreibung === */
//@ f_01e310  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht den Fehlercode (p1->err = 0) und gibt den aktuellen Füllstand p1->cur des
 *   Datenpuffers zurück (der zugleich den Byteversatz des nächsten anzuhängenden Eintrags angibt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert p1->cur (unsigned
 *   int).
 * - Wichtige Variablen: Geändert wird p1->err (+0x00), gelesen wird p1->cur (+0x06).
 === Ende Beschreibung === */
//@ f_01e320  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Fehlercode p1->err auf 0 und liefert die aktuelle Anzahl p1->cnt der in
 *   der Liste gespeicherten Einträge.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und gibt p1->cnt (unsigned
 *   short) zurück.
 * - Wichtige Variablen: Geändert wird p1->err (+0x00), gelesen wird p1->cnt (+0x02).
 === Ende Beschreibung === */
//@ f_01e330  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht p1->err, stellt den Leseiterator p1->idx auf 1 und gibt bei einer
 *   nichtleeren Liste (p1->cnt != 0) den Pufferanfang p1->base (also den Zeiger auf Eintrag 0) zurück, bei einer
 *   leeren Liste hingegen 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert die Adresse des
 *   ersten Eintrags (int / char *) oder 0.
 * - Wichtige Variablen: Genutzt werden p1->idx (+0x10), p1->cnt (+0x02) und p1->base (+0x22).
 === Ende Beschreibung === */
//@ f_01e350  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht p1->err, prüft ob der Iterator p1->idx noch kleiner als die Eintragsanzahl
 *   p1->cnt ist, berechnet in diesem Fall die Adresse p1->base + p1->offs[p1->idx] des aktuellen Eintrags,
 *   erhöht p1->idx um 1 und gibt die Adresse zurück; am Listenende liefert sie 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und gibt den Zeiger auf den
 *   nächsten Eintrag zurück (in der Rekonstruktion für die Registerbreite als short deklariert, im
 *   32-Bit-Rückgaberegister eax die volle Adresse).
 * - Wichtige Variablen: Genutzt werden p1->idx (+0x10), p1->cnt (+0x02), p1->offs (+0x1e) und p1->base (+0x22).
 === Ende Beschreibung === */
//@ f_01e3a0  groesse 144 B, 16 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion stellt den Iterator p1->idx auf p2 + 1, löscht p1->err und liefert - sofern der
 *   Index p2 kleiner als p1->cnt ist - die Adresse p1->base + p1->offs[p2] der gewünschten Zeichenkette zurück
 *   (wird in xdialog_t1 genutzt, um formatierte Dialogtexte auszulesen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und den Eintragsindex p2
 *   (unsigned short) und gibt die Adresse der Zeichenkette (int / char *) oder 0 bei ungültigem Index zurück.
 * - Wichtige Variablen: Genutzt werden p1->cnt, p1->offs, p1->base und p1->idx.
 === Ende Beschreibung === */
//@ f_01e3d0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt p1->err = 0, durchläuft alle Einträge i = 0 .. p1->cnt - 1 und ruft für
 *   jeden Eintrag p1->base + p1->offs[i] die gespeicherte Vergleichsfunktion p1->cmp (strcmp) mit dem Suchtext
 *   p2 auf; beim ersten Treffer (cmp == 0) bricht sie ab und gibt dessen Index i zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) sowie die gesuchte Zeichenkette
 *   p2 (int / const char *) und liefert den gefundenen Index (0 .. cnt - 1) oder 0xffff (-1), falls der Text
 *   nicht enthalten ist.
 * - Wichtige Variablen: Genutzt werden p1->cmp (+0x12), p1->offs, p1->base und p1->cnt.
 === Ende Beschreibung === */
//@ f_01e430  groesse 320 B, 56 Bef, reg eax edx, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hat die Liste die Obergrenze von 0xff00 Einträgen noch nicht erreicht, bestimmt die Funktion
 *   über p1->len(p2) + 1 die benötigte Elementanzahl, stellt über f_01e110 Platz in der Versatztabelle und über
 *   f_01e1a0 Platz im Datenpuffer sicher, trägt den aktuellen Byteversatz p1->cur in p1->offs[p1->cnt] ein,
 *   kopiert die Zeichenkette per p1->cp an die Zieladresse p1->base + p1->cur, erhöht p1->cnt um 1 und rückt
 *   p1->cur um n * p1->esz weiter; bei voller Liste (cnt == 0xff00) setzt sie den Fehlercode p1->err = 0x409.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und die anzuhängende
 *   Zeichenkette p2 (int / const char *); sie gibt den neuen Eintragsindex (short) oder bei einem Fehler 0xffff
 *   (-1) zurück.
 * - Wichtige Variablen: Aktualisiert werden p1->offs, p1->base, p1->cnt (+0x02), p1->cur (+0x06) und bei
 *   Überlauf p1->err (+0x00).
 === Ende Beschreibung === */
//@ f_01e4e0  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion durchsucht die Liste zunächst (mit einer inline eingesetzten Kopie von f_01e3d0)
 *   nach der Zeichenkette p2: wird p2 noch nicht gefunden (0xffff), hängt sie den Text über f_01e430 an und gibt
 *   den neuen Index zurück; ist p2 bereits vorhanden, trägt sie den Fehlercode p1->err = 0x404 ein und liefert
 *   0xffff.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und die Zeichenkette p2 (int /
 *   const char *) und gibt den neuen Index oder 0xffff zurück.
 * - Wichtige Variablen: Geprüft wird über p1->cmp, geändert wird bei Duplikaten p1->err = 0x404.
 === Ende Beschreibung === */
//@ f_01e570  groesse 112 B, 40 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt die Versatztabelle p1->offs und den Datenpuffer p1->base frei und setzt
 *   Fehlercode, Eintragsanzahl, Kapazitäten und Iterator auf 0 zurück, lässt aber die Elementgröße esz und die
 *   Funktionszeiger cmp/cp/len unangetastet, sodass die Liste direkt wieder befüllt werden kann (wird in
 *   xdialog_t1 f_140f20 vor dem Neuaufbau genutzt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Freigegeben und genullt werden p1->offs und p1->base sowie die Zähler cnt, s4, cur, i10
 *   und idx.
 === Ende Beschreibung === */
//@ f_01e5e0  groesse 80 B, 21 Bef, reg eax, stapel 0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert das globale Statusbalken-Objekt d_1c2bcc (aufgerufen aus zmain):
 *   er trägt die Füllfarben für Lebensenergie (p1[8] = 0xfc) und Astralenergie (p1[9] = 0xfd) sowie die
 *   zugehörigen oberen Kappenfarben (p1[10] = 0xd6, p1[11] = 0xbb) ein, setzt die ersten 8 Bytes auf 0 und
 *   löscht die 7 Neuzeichnen-Merker p1[12..18] für die 7 Heldenplätze. Gegenstück zu g_status_bar_colors in
 *   *Schicksalsklinge* seg004.c.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned char *, &d_1c2bcc) und gibt p1 zurück.
 * - Wichtige Variablen: p1[8..9] enthalten die Füllfarben, p1[10..11] die Kappenfarben und p1[12..18] die 7
 *   Heldenplatz-Merker.
 === Ende Beschreibung === */
//@ f_01e620  ?
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Funktionsrumpf ohne Wirkung (anhand der Lage unmittelbar zwischen Konstruktor f_01e5e0
 *   und Zeichenmethode f_01e630 vermutlich der leere Destruktor des Statusbalken-Objekts).
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
//@ f_01e630  groesse 560 B, 172 Bef, reg eax edx ebx ecx, stapel 12
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sofern die Statusanzeige freigegeben ist (f_0bba10(d_1bf230) != 0 oder d_1bd90c != 0), löscht
 *   die Funktion den Neuzeichnen-Merker des Heldenplatzes p3 (p1[0x0c + p3] = 0), bestimmt je nach Anzeigemodus
 *   p6 die X-Koordinate, die Unterkante tag und die Gesamthöhe width (32 Pixel, im Listenmodus p6 == 2 36
 *   Pixel), berechnet bei p4 != 0 die Füllhöhe height = clamp(width * p4 / p5, 1, width), zeichnet 3
 *   nebeneinanderliegende senkrechte Linien (f_148450) in der Füllfarbe p1[8 + p2], füllt den leeren Raum
 *   darüber (außer in Modus 2) mit der Farbe -2 und setzt eine 3 Pixel breite waagrechte Kappenlinie (f_1483f0)
 *   in der Farbe p1[10 + p2] oben auf den Füllstand; bei p4 == 0 und p5 > 0 wird der gesamte Balken als leer
 *   gezeichnet. Gegenstück zu seg004.c:draw_bar in *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Balkenobjekt p1 (&d_1c2bcc), den Balkentyp p2 (0 =
 *   Lebensenergie, 1 = Astralenergie), den Heldenplatz p3 (0..6), den aktuellen Punktestand p4 (short), den
 *   Maximalwert p5 (short), den Anzeigemodus p6 (0 = Heldenleiste am unteren Bildschirmrand, 1/3 =
 *   Einzelhelden-Ansicht oben/unten, 2 = Listenansicht) sowie den Zielbildpuffer p7 (0 = direkt in den
 *   Bildschirmpuffer d_1a34e0) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Porträt-X-Positionen d_1a5544[0..6], der Bildschirmpuffer d_1a34e0,
 *   die Freigabeschalter d_1bf230/d_1bd90c sowie die Farb- und Merkerfelder in d_1c2bcc.
 === Ende Beschreibung === */

#define CH signed char
typedef short (*CMPF)(int, int);
typedef void (*CPYF)(int, int);
typedef int (*LENF)(int);
struct AL {
    unsigned short err;
    unsigned short cnt;
    unsigned short s4;
    unsigned int cur;
    unsigned int i10;
    unsigned short esz;
    unsigned short idx;
    CMPF cmp;
    CPYF cp;
    LENF len;
    int *offs;
    int base;
};
//@ f_01e240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert ein AL-Listenobjekt (0x26 Bytes): er setzt Fehlercode (err),
 *   Eintragsanzahl (cnt), Tabellen- und Pufferkapazität (s4, i10), Pufferfüllstand (cur), Iterator (idx) sowie
 *   die Zeiger auf Versatztabelle (offs) und Datenpuffer (base) auf 0 und speichert die Elementgröße p2 (bei
 *   Zeichenketten 1) sowie die drei Funktionszeiger für Vergleich (p3, strcmp), Kopie (p4, strcpy) und Länge
 *   (p5, strlen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Objektzeiger p1 (AL *, this), die Elementgröße p2 (unsigned
 *   short) sowie die Funktionszeiger p3 (CMPF), p4 (CPYF) und p5 (LENF) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Initialisiert werden alle Felder der 0x26 Bytes großen Struktur AL.
 === Ende Beschreibung === */
void f_01e240(AL *p1, unsigned short p2, CMPF p3, CPYF p4, LENF p5)
{
    p1->err = 0;
    p1->cnt = 0;
    p1->s4 = 0;
    p1->cur = 0;
    p1->i10 = 0;
    p1->idx = 0;
    p1->offs = 0;
    p1->base = 0;
    p1->esz = p2;
    p1->cmp = p3;
    p1->cp = p4;
    p1->len = p5;
}
//@ f_01e290
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Destruktor gibt - falls vorhanden - die Versatztabelle p1->offs und den Datenpuffer
 *   p1->base frei, setzt sämtliche Zähler, den Iterator und den Fehlercode auf 0 zurück und liefert den
 *   Objektzeiger p1 zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und das ungenutzte
 *   Destruktor-Flag p2 (int) und gibt p1 zurück.
 * - Wichtige Variablen: Freigegeben werden p1->offs (+0x1e) und p1->base (+0x22).
 === Ende Beschreibung === */
AL *f_01e290(AL *p1, int p2)
{
    AL *q_ = p1;
    q_->err = 0;
    if (q_->offs) { delete q_->offs; q_->offs = 0; }
    if (q_->base) { delete (char *)q_->base; q_->base = 0; }
    q_->cnt = 0;
    q_->s4 = 0;
    q_->cur = 0;
    q_->i10 = 0;
    q_->idx = 0;
    q_->offs = 0;
    q_->base = 0;
    return p1;
}
//@ f_01e300
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt den im Feld p1->err gespeicherten Fehlercode der letzten Operation zurück (0
 *   = kein Fehler, 0x404 = Eintrag bereits vorhanden bei f_01e4e0, 0x409 = Liste voll bei f_01e430), ohne ihn
 *   zurückzusetzen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert p1->err (unsigned
 *   short).
 * - Wichtige Variablen: Gelesen wird p1->err (+0x00).
 === Ende Beschreibung === */
unsigned short f_01e300(AL *p1)
{
    return p1->err;
}
//@ f_01e310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht den Fehlercode (p1->err = 0) und gibt den aktuellen Füllstand p1->cur des
 *   Datenpuffers zurück (der zugleich den Byteversatz des nächsten anzuhängenden Eintrags angibt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert p1->cur (unsigned
 *   int).
 * - Wichtige Variablen: Geändert wird p1->err (+0x00), gelesen wird p1->cur (+0x06).
 === Ende Beschreibung === */
unsigned int f_01e310(AL *p1)
{
    p1->err = 0;
    return p1->cur;
}
//@ f_01e320
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt den Fehlercode p1->err auf 0 und liefert die aktuelle Anzahl p1->cnt der in
 *   der Liste gespeicherten Einträge.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und gibt p1->cnt (unsigned
 *   short) zurück.
 * - Wichtige Variablen: Geändert wird p1->err (+0x00), gelesen wird p1->cnt (+0x02).
 === Ende Beschreibung === */
unsigned short f_01e320(AL *p1)
{
    p1->err = 0;
    return p1->cnt;
}
//@ f_01e330
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht p1->err, stellt den Leseiterator p1->idx auf 1 und gibt bei einer
 *   nichtleeren Liste (p1->cnt != 0) den Pufferanfang p1->base (also den Zeiger auf Eintrag 0) zurück, bei einer
 *   leeren Liste hingegen 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und liefert die Adresse des
 *   ersten Eintrags (int / char *) oder 0.
 * - Wichtige Variablen: Genutzt werden p1->idx (+0x10), p1->cnt (+0x02) und p1->base (+0x22).
 === Ende Beschreibung === */
int f_01e330(AL *p1)
{
    p1->err = 0;
    p1->idx = 1;
    if (p1->cnt == 0) return 0;
    return p1->base;
}
//@ f_01e350
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion löscht p1->err, prüft ob der Iterator p1->idx noch kleiner als die Eintragsanzahl
 *   p1->cnt ist, berechnet in diesem Fall die Adresse p1->base + p1->offs[p1->idx] des aktuellen Eintrags,
 *   erhöht p1->idx um 1 und gibt die Adresse zurück; am Listenende liefert sie 0.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und gibt den Zeiger auf den
 *   nächsten Eintrag zurück (in der Rekonstruktion für die Registerbreite als short deklariert, im
 *   32-Bit-Rückgaberegister eax die volle Adresse).
 * - Wichtige Variablen: Genutzt werden p1->idx (+0x10), p1->cnt (+0x02), p1->offs (+0x1e) und p1->base (+0x22).
 === Ende Beschreibung === */
short f_01e350(AL *p1)
{
    int r;
    int b;
    unsigned short i;
    p1->err = 0;
    if (p1->idx >= p1->cnt) {
        r = 0;
    } else {
        int *q = (int *)((unsigned)p1->idx * 4 + (int)p1->offs);
        i = (unsigned short)p1->idx;
        b = p1->base;
        r = *q;
        r += b;
        p1->idx = i + 1;
    }
    return r;
}
//@ f_01e3a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion stellt den Iterator p1->idx auf p2 + 1, löscht p1->err und liefert - sofern der
 *   Index p2 kleiner als p1->cnt ist - die Adresse p1->base + p1->offs[p2] der gewünschten Zeichenkette zurück
 *   (wird in xdialog_t1 genutzt, um formatierte Dialogtexte auszulesen).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und den Eintragsindex p2
 *   (unsigned short) und gibt die Adresse der Zeichenkette (int / char *) oder 0 bei ungültigem Index zurück.
 * - Wichtige Variablen: Genutzt werden p1->cnt, p1->offs, p1->base und p1->idx.
 === Ende Beschreibung === */
int f_01e3a0(AL *p1, unsigned short p2)
{
    p1->idx = p2 + 1;
    p1->err = 0;
    if (p1->cnt <= p2) return 0;
    return p1->base + p1->offs[p2];
}
//@ f_01e3d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion setzt p1->err = 0, durchläuft alle Einträge i = 0 .. p1->cnt - 1 und ruft für
 *   jeden Eintrag p1->base + p1->offs[i] die gespeicherte Vergleichsfunktion p1->cmp (strcmp) mit dem Suchtext
 *   p2 auf; beim ersten Treffer (cmp == 0) bricht sie ab und gibt dessen Index i zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) sowie die gesuchte Zeichenkette
 *   p2 (int / const char *) und liefert den gefundenen Index (0 .. cnt - 1) oder 0xffff (-1), falls der Text
 *   nicht enthalten ist.
 * - Wichtige Variablen: Genutzt werden p1->cmp (+0x12), p1->offs, p1->base und p1->cnt.
 === Ende Beschreibung === */
unsigned short f_01e3d0(AL *p1,int p2) {
 unsigned short i,r;
 p1->err=0;r=0xffff;i=0;
 for(;i<p1->cnt;i++){
 int *slot=(int*)((unsigned)i*4+(int)p1->offs);
        int base=p1->base; int value=*slot;value+=base;
 if(p1->cmp(value,p2)==0){r=i;break;}
 }
 return r;
}
//@ f_01e430
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Hat die Liste die Obergrenze von 0xff00 Einträgen noch nicht erreicht, bestimmt die Funktion
 *   über p1->len(p2) + 1 die benötigte Elementanzahl, stellt über f_01e110 Platz in der Versatztabelle und über
 *   f_01e1a0 Platz im Datenpuffer sicher, trägt den aktuellen Byteversatz p1->cur in p1->offs[p1->cnt] ein,
 *   kopiert die Zeichenkette per p1->cp an die Zieladresse p1->base + p1->cur, erhöht p1->cnt um 1 und rückt
 *   p1->cur um n * p1->esz weiter; bei voller Liste (cnt == 0xff00) setzt sie den Fehlercode p1->err = 0x409.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und die anzuhängende
 *   Zeichenkette p2 (int / const char *); sie gibt den neuen Eintragsindex (short) oder bei einem Fehler 0xffff
 *   (-1) zurück.
 * - Wichtige Variablen: Aktualisiert werden p1->offs, p1->base, p1->cnt (+0x02), p1->cur (+0x06) und bei
 *   Überlauf p1->err (+0x00).
 === Ende Beschreibung === */
short f_01e430(AL *p1, int p2)
{
    int n;
    unsigned short r;
    p1->err = 0;
    r = 0xffff;
    if (p1->cnt == 0xff00) {
        p1->err = 0x409;
    } else {
        n = p1->len(p2) + 1;
        f_01e110((int)p1);
        if (p1->err == 0) {
            f_01e1a0((int)p1, n);
        }
        if (p1->err == 0) {
            p1->offs[p1->cnt] = p1->cur;
            int *slot=(int*)((unsigned)p1->cnt*4+(int)p1->offs);
            int base_=p1->base;int value=*slot;value+=base_;p1->cp(value,p2);
            r = p1->cnt;
            p1->cnt = r + 1;
            p1->cur += n * (unsigned int)p1->esz;
        }
    }
    return r;
}
//@ f_01e4e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion durchsucht die Liste zunächst (mit einer inline eingesetzten Kopie von f_01e3d0)
 *   nach der Zeichenkette p2: wird p2 noch nicht gefunden (0xffff), hängt sie den Text über f_01e430 an und gibt
 *   den neuen Index zurück; ist p2 bereits vorhanden, trägt sie den Fehlercode p1->err = 0x404 ein und liefert
 *   0xffff.
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und die Zeichenkette p2 (int /
 *   const char *) und gibt den neuen Index oder 0xffff zurück.
 * - Wichtige Variablen: Geprüft wird über p1->cmp, geändert wird bei Duplikaten p1->err = 0x404.
 === Ende Beschreibung === */
int f_01e4e0(AL *p1,int p2){
struct Query700{static inline unsigned short find(AL *p1,int p2) {
 unsigned short i,r;
 p1->err=0;r=0xffff;i=0;
 for(;i<p1->cnt;i++){
 int *slot=p1->offs+i;
        int base=p1->base; int value=*slot;value+=base;
 if(p1->cmp(value,p2)==0){r=i;break;}
 }
 return r;
}};

 int append700(AL*,int);
 #pragma aux append700 "f_01e430";
 volatile int saved=p2; // Haelt p2 ueber den indirekten Vergleichsaufruf auf [esp] statt in ebp
unsigned short found=0;
 int r;
 p1->err=0;
 found=Query700::find(p1,p2);
 if(found==0xffff)r=append700(p1,saved);
 else{r=0xffff;p1->err=0x404;}
 return r;
}
//@ f_01e570
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Die Funktion gibt die Versatztabelle p1->offs und den Datenpuffer p1->base frei und setzt
 *   Fehlercode, Eintragsanzahl, Kapazitäten und Iterator auf 0 zurück, lässt aber die Elementgröße esz und die
 *   Funktionszeiger cmp/cp/len unangetastet, sodass die Liste direkt wieder befüllt werden kann (wird in
 *   xdialog_t1 f_140f20 vor dem Neuaufbau genutzt).
 * - Eingaben und Rückgabe: Die Funktion erhält den Listen-Zeiger p1 (AL *, this) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Freigegeben und genullt werden p1->offs und p1->base sowie die Zähler cnt, s4, cur, i10
 *   und idx.
 === Ende Beschreibung === */
void f_01e570(AL *p1)
{
    p1->err = 0;
    if (p1->offs) { delete p1->offs; p1->offs = 0; }
    if (p1->base) { delete (char *)p1->base; p1->base = 0; }
    p1->cnt = 0;
    p1->s4 = 0;
    p1->cur = 0;
    p1->i10 = 0;
    p1->idx = 0;
    p1->offs = 0;
    p1->base = 0;
}
//@ f_01e5e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Der Konstruktor initialisiert das globale Statusbalken-Objekt d_1c2bcc (aufgerufen aus zmain):
 *   er trägt die Füllfarben für Lebensenergie (p1[8] = 0xfc) und Astralenergie (p1[9] = 0xfd) sowie die
 *   zugehörigen oberen Kappenfarben (p1[10] = 0xd6, p1[11] = 0xbb) ein, setzt die ersten 8 Bytes auf 0 und
 *   löscht die 7 Neuzeichnen-Merker p1[12..18] für die 7 Heldenplätze. Gegenstück zu g_status_bar_colors in
 *   *Schicksalsklinge* seg004.c.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 (unsigned char *, &d_1c2bcc) und gibt p1 zurück.
 * - Wichtige Variablen: p1[8..9] enthalten die Füllfarben, p1[10..11] die Kappenfarben und p1[12..18] die 7
 *   Heldenplatz-Merker.
 === Ende Beschreibung === */
unsigned char *f_01e5e0(unsigned char *p1)
{
    unsigned char c;
    p1[8] = 0xfc;
    p1[9] = 0xfd;
    p1[10] = 0xd6;
    p1[11] = 0xbb;
    p1[3] = 0;
    c = p1[3];
    p1[2] = c;
    p1[1] = c;
    p1[0] = c;
    *(int *)(p1 + 4) = 0;
    memset(p1 + 12, 0, 7);
    return p1;
}
//@ f_01e620
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leerer Funktionsrumpf ohne Wirkung (anhand der Lage unmittelbar zwischen Konstruktor f_01e5e0
 *   und Zeichenmethode f_01e630 vermutlich der leere Destruktor des Statusbalken-Objekts).
 * - Eingaben und Rückgabe: Die Funktion hat weder Parameter noch einen Rückgabewert.
 * - Wichtige Variablen: Keine.
 === Ende Beschreibung === */
void f_01e620(void)
{
}
//@ f_01e630
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Sofern die Statusanzeige freigegeben ist (f_0bba10(d_1bf230) != 0 oder d_1bd90c != 0), löscht
 *   die Funktion den Neuzeichnen-Merker des Heldenplatzes p3 (p1[0x0c + p3] = 0), bestimmt je nach Anzeigemodus
 *   p6 die X-Koordinate, die Unterkante tag und die Gesamthöhe width (32 Pixel, im Listenmodus p6 == 2 36
 *   Pixel), berechnet bei p4 != 0 die Füllhöhe height = clamp(width * p4 / p5, 1, width), zeichnet 3
 *   nebeneinanderliegende senkrechte Linien (f_148450) in der Füllfarbe p1[8 + p2], füllt den leeren Raum
 *   darüber (außer in Modus 2) mit der Farbe -2 und setzt eine 3 Pixel breite waagrechte Kappenlinie (f_1483f0)
 *   in der Farbe p1[10 + p2] oben auf den Füllstand; bei p4 == 0 und p5 > 0 wird der gesamte Balken als leer
 *   gezeichnet. Gegenstück zu seg004.c:draw_bar in *Schicksalsklinge*.
 * - Eingaben und Rückgabe: Die Funktion erhält das Balkenobjekt p1 (&d_1c2bcc), den Balkentyp p2 (0 =
 *   Lebensenergie, 1 = Astralenergie), den Heldenplatz p3 (0..6), den aktuellen Punktestand p4 (short), den
 *   Maximalwert p5 (short), den Anzeigemodus p6 (0 = Heldenleiste am unteren Bildschirmrand, 1/3 =
 *   Einzelhelden-Ansicht oben/unten, 2 = Listenansicht) sowie den Zielbildpuffer p7 (0 = direkt in den
 *   Bildschirmpuffer d_1a34e0) und hat keinen Rückgabewert.
 * - Wichtige Variablen: Genutzt werden die Porträt-X-Positionen d_1a5544[0..6], der Bildschirmpuffer d_1a34e0,
 *   die Freigabeschalter d_1bf230/d_1bd90c sowie die Farb- und Merkerfelder in d_1c2bcc.
 === Ende Beschreibung === */
void f_01e630(char *p1, short p2, short p3, short p4, short p5, short p6, char *p7)
{
    short height;
    short tag;
    short x;
    short i;
    short width = 0x20;
    int target;
    extern char d_1bf230[];
    if (((int (*)(int))f_0bba10)((int)d_1bf230) || d_1bd90c) {

    *(char *)(p1 + p3 + 0x0c) = 0;
    if (!p6) {
        x = ((short *)d_1a5544)[p3] + 0x22 + p2 * 4;
        if (p7 == 0) {
            target = d_1a34e0;
            tag = 0xbd;
        } else {
            target = (int)p7;
            tag = 0x21;
        }
    } else if (p6 == 2) {
        x = p2 * 4 + 0x13;
        tag = 0x25;
        target = (int)p7;
        width = 0x24;
    } else {
        x = p2 * 4 + 0x24;
        if (p6 == 3) tag = 0xbe;
        else tag = 0x2a;
        target = (int)p7;
    }

    if (p4) {
        height = width * p4;
        height /= p5;
        height = f_0bd350(height, 1, width);
        for (i = 0; i < 3; ++i) {
            f_148450(target, (short)(x + i), (short)(tag - height), height, *(CH *)(p1 + p2 + 8));
        }
        if (p6 != 2) {
            for (i = 0; i < 3; ++i) {
                f_148450(target, (short)(x + i), (short)(tag - width), (short)(width - height), -2);
            }
        }
        f_1483f0(target, x, (short)(tag - height), 3, *(CH *)(p1 + p2 + 10));
        return;
    }

    if (p6 != 2 && p5 > 0) {
        for (i = 0; i < 3; ++i) {
            f_148450(target, (short)(x + i), (short)(tag - width), width, -2);
        }
    }
    }
}
