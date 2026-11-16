/* === Beschreibung (Katalog) ===
 * Einheit gz_131a70_t1 (0x131A70 - 0x131BB0)
 *
 * Überblick
 * Diese Einheit enthält den ersten Teil des Übergangsmoduls zwischen der dritten und der vierten Ebene des
 * Magierturms (tower3.cpp / tower4.cpp). Sie umfasst die Gruppenprüfung zur Umwandlung bestimmter
 * Turmgegenstände in Edelsteine, den Konstruktor/Destruktor-Wrapper der vierten Turmebene sowie eine
 * Hilfsabfrage auf Zauberkundige in der aktiven Gruppe.
 === Ende Beschreibung === */
// P1 6/7 gleich
// gz_131a70.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x131A70-0x131F30
#include <string.h>
#include "RIVAMEM.H"



void f_014710(void *p);
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
extern void f_131a10(void);
int f_039660(int p1, int p2);
short f_0398c0(int p1, int p2, int p3);
int f_039b00(int p1, int p2, int p3);
int f_0390a0(int p1);
int f_05ff60(int p1, int p2);
int f_060030(int p1, int p2);
int f_0bf730(int p1, int p2);
int f_0de7c0(int p1);
int f_145234(int p1, int p2);
int f_145254();
extern char d_1bbbc4[];
extern char d_1bbc1c[];
extern char d_1bfdbc[];
extern int d_1c0004;
extern signed char d_1c0d98;
extern short d_1c0d99;
extern signed char d_1c0d9c;
extern short d_1c0d9d;
extern signed char d_1c0da0;
extern short d_1c0da1;
extern signed char d_1c0da4;
extern short d_1c0da5;
extern signed char d_1c0da8;
extern short d_1c0da9;
extern signed char d_1c0dac;
extern short d_1c0dad;
extern signed char d_1c0db0;
extern short d_1c0db1;
extern signed char d_1c0db4;
extern short d_1c0db5;
extern signed char d_1c0db8;
extern short d_1c0db9;
extern signed char d_1c0dbc;
extern short d_1c0dbd;
extern signed char d_1c0dc0;
extern short d_1c0dc1;
extern signed char d_1c0dc4;
extern short d_1c0dc5;
extern signed char d_1c0dc8;
extern short d_1c0dc9;
extern signed char d_1c0dcc;
extern short d_1c0dcd;
extern signed char d_1c0dd0;
extern short d_1c0dd1;
extern short d_1c212a;
extern char **d_1c212c;
extern char d_1c2538[];
extern char d_1c2c64[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c3498[];
#define I(p, o) (*(int *)((int)(p) + (o)))
#define EQI(x,v) (((x)==(v))?1:0)
#define EQ2(x) EQI(x,1)

//@ f_131a70
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft für alle Mitglieder einer Heldengruppe (p1) über die Filterfunktion f_131a10, ob sie
 *   bestimmte magische Beutestücke aus dem Turm bei sich tragen, die sich nun in Edelsteine verwandeln; handelt
 *   es sich dabei um die gerade aktive Gruppe (d_1c0004), wird außerdem eine Meldung (0x27000001 und bei
 *   Anwesenheit eines zweiten scharfsinnigen Helden auch 0x27000002) ausgegeben.
 * - Eingaben: Ein Zeiger auf die zu untersuchende Heldengruppe (p1).
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: p2 ist der Held mit dem höchsten Wert in Attribut 10, v ein weiterer Held mit hoher
 *   Sinnenschärfe (0x27), deren Namen in den Textkontext (obj) eingesetzt werden.
 === Ende Beschreibung === */
void f_131a70(int p1)
{
    if (f_0398c0(p1, (int)f_131a10, (int)d_1c2538) > 0 && p1 == d_1c0004) {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        int p2 = f_039660(d_1c0004, 10);
        int v = f_039b00(d_1c0004, p2, 0x27);
        *(int *)(obj.slots[0] + 4) = p2; *(int *)(obj.slots[0] + 8) = v;
        f_0bf730((int)d_1c2c64, 0x27000001);
        if (v != 0) f_0bf730((int)d_1c2c64, 0x27000002);
    }
}
//@ f_131b20
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Durchläuft alle sechs möglichen Teilgruppen der Heldengruppe (d_1bfdbc) und ruft für jede
 *   existierende Gruppe (f_0de7c0) die Umwandlungsfunktion f_131a70 auf.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Kein Rückgabewert (void).
 * - Wichtige Variablen: Die Schleifenvariable i (0 bis 5) berechnet den jeweiligen Gruppenzeiger p im Abstand
 *   von 0x61 Bytes.
 === Ende Beschreibung === */
void f_131b20(void)
{
    short i;
    for (i = 0; i < 6; i++) {
        int p = (int)d_1bfdbc + i * 0x61;
        if (f_0de7c0(p)) f_131a70(p);
    }
}
//@ f_131b50
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Agiert als generischer Destruktor- bzw. Serialisierungs-Wrapper für das Ebenen-Objekt der
 *   vierten Magierturmebene: Ist Bit 4 in p2 gesetzt, wird der Zustand des Objekts über die
 *   Laufzeit-Serialisierung (f_145234/f_145254) gesichert, andernfalls wird der Basisklassen-Destruktor
 *   (f_060030) aufgerufen und bei gesetztem Bit 2 der Objektspeicher (f_014710) freigegeben.
 * - Eingaben: Ein Zeiger auf das Ebenen-Objekt (p1) sowie die Steuerflags (p2).
 * - Rückgabewert: Gibt den Zeiger auf das Ebenen-Objekt (p1 bzw. r) zurück.
 * - Wichtige Variablen: r speichert den vom Basisklassen-Destruktor zurückgegebenen Objektzeiger vor der
 *   optionalen Speicherfreigabe.
 === Ende Beschreibung === */
int f_131b50(int p1, unsigned p2)
{
    int r;
    if (p2 & 4) {
        f_145234(p1, (int)d_1bbbc4);
        f_145254();
        return p1;
    }
    r = f_060030(p1, 1);
    if (p2 & 2) f_014710((void *)r);
    return r;
}
//@ f_131b90
/* === Beschreibung (Katalog) ===
 * - Zweck im Spiel: Prüft, ob sich in der aktiven Heldengruppe (d_1c0004) mindestens ein Zauberkundiger
 *   befindet.
 * - Eingaben: Keine Parameter.
 * - Rückgabewert: Gibt 1 zurück, wenn die Gruppe über einen Zauberkundigen verfügt (f_0390a0 != 0), sonst 0.
 * - Wichtige Variablen: Keine lokalen Variablen.
 === Ende Beschreibung === */
int f_131b90(void)
{
    return f_0390a0(d_1c0004) != 0;
}