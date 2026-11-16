/* === Beschreibung (Katalog) ===
 * Einheit gamepoin (091f70 - 092ee0)
 *
 * Überblick
 * Die Einheit gamepoin (Game Points) implementiert das Spielpunkte- und Fortschrittssystem von *Schatten über
 * Riva* (bis zu 1000 Punkte für gelöste Quests und Meilensteine): Sie vergibt einmalig Punkte für erreichte
 * Ereignisse (f_091f70), fragt den aktuellen Punktestand und Spielfortschrittsabschnitt ab (f_092050, f_0921d0)
 * und zeichnet den grafischen Fortschrittsbildschirm mit der sich füllenden Säule und der Textanzeige <Punkte>
 * von 1000 (f_092310 bis f_092b90).
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMOUS.H"
#include "RIVAMEM.H"
// P3 9/13 gleich (suche.py 27.10.2026, Basis gamepoin_P1.CPP)
// gamepoin.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x091F70-0x092EE0
#include <string.h>
#include <bios.h>
#pragma inline_depth(3)
// OPT -4r -oneatx -oe=0 -zp1 -s
#include "RIVACTX.H"   // 0x3a Bytes; Ctor f_125400, Dtor f_1254a0
int __cdecl f_149eb4(int p1, int p2, int p3);
int f_149d20();
int f_147c84(int p1, int p2, int p3);
short f_02ddf0(int p1);
int f_02de00(int p1, int p2);
int f_04fef0(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
int f_05e1d0(int p1, int p2, int p3);
int f_05e1f0(int p1);
int f_05e200(int p1);
int f_05e2a0(int p1, int p2, int p3, int p4, int p5);
int f_05e2d0(int p1, int p2, int p3, int p4, int p5);
int f_05e320(int p1, int p2, int p3);
int f_05e340(int p1);
int f_069460();
int f_092f00(int p1, int p2);
int f_092f20(int p1, int p2);
int f_09a0d0(int p1);
int f_09a120(int p1, int p2);
int f_09a140(int p1, int p2);
int f_09ac80(int p1, int p2, int p3);
int f_09ade0(int p1, int p2, int p3);
int f_09aed0(int p1);
int f_0ce7c0(int p1);
int f_0ce7e0(int p1, int p2);


int f_0d3780();
int f_0d37b0();

int f_0e9550(int p1, int p2);






int f_1459b0(int p1);
int f_1459d0(int p1, int p2);
int f_145a20(int p1, int p2, int p3, int p4);
extern int d_1bdb98;
extern int d_1bdba0;
extern int d_1bdba8;
extern short d_1bdbb0;
extern signed char d_1bdcfc;
extern signed char d_1bdd04;
extern signed char d_1bee18;
extern signed char d_1c00a0;
extern signed char d_1a2938[];
extern int d_1a2934;
extern int d_1a34e0;
extern int d_1c0c4c;
extern volatile int d_1c0c94; // haelt das Lesen und Schreiben von d_1c0c94 wie im Original
extern char d_1baac0[];
extern char d_1c2be0[];
extern char d_1c3498[];
extern char d_1c349c[];
extern char d_1c3870[];
extern char d_1c38b0[];
extern const char d_1a2914[];
#define EQI(x,v) (((x)==(v))?1:0)
#define GTI(x,v) (((x)>(v))?1:0)
#define NEI(x,v) (((x)!=(v))?1:0)
struct T { char b[0xa3]; };
struct T600 { char b[0x600]; };
#define CTOR(o) o = o ? (T *)f_1459b0((int)o) : o;
#define DTOR(o) if (o) operator delete((void *)f_1459d0((int)o, 0));
#define CLAMP(v) if (GTI(d_1bdbb0, 1000)) v = 1000; else v = d_1bdbb0;
#define SEL(s) if (GTI(d_1bdcfc, 0) || EQI(d_1bdd04, 1)) s = 3; else if (EQI(d_1c00a0, 1)) s = 2; else if (EQI(d_1bee18, 1)) s = 1; else s = 0;
#define WAITKEY while (!f_0d3780() && !f_0d37b0() && !_bios_keybrd(_KEYBRD_READY)) f_069460(); while (f_0d3780() || f_0d37b0()) f_069460(); while (_bios_keybrd(_KEYBRD_READY)) _bios_keybrd(_KEYBRD_READ);

#define TAIL5(s1, s2) f_05e2a0((int)d_1c38b0, (int)&a, (int)&b, (int)&c, (int)&d); f_05e2d0((int)d_1c38b0, 0, 0x140, -1, 1); f_05e1d0((int)d_1c38b0, s1, 0x9a); f_05e320((int)d_1c38b0, 0xff, -1); f_0e9550((int)d_1c38b0, 0x2a000005); f_05e340((int)d_1c38b0); f_05e1d0((int)d_1c38b0, s1, (short)s2); f_05e2d0((int)d_1c38b0, a, b, c, d);

//@ f_091f70
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft anhand der drei 32-Bit-Masken d_1bdb98, d_1bdba0 und d_1bdba8 (für bis zu 96
 *   Meilensteine 0..95), ob das Spielziel p1 bereits erreicht wurde; falls nicht, addiert sie den zugehörigen
 *   Punktwert aus d_1a2938[p1] auf den Gesamtpunktestand d_1bdbb0, setzt das entsprechende Bit und gibt den (auf
 *   maximal 1000 begrenzten) Punktestand zurück.
 * - Eingaben und Rückgabe: Die Funktion erhält die Meilenstein-Kennung p1 (0..95) und gibt den aktuellen
 *   Gesamtpunktestand (0..1000) als short zurück.
 * - Wichtige Variablen: Das Array d_1a2938 enthält die Punktwerte der einzelnen Story-Erfolge, und d_1bdbb0
 *   speichert die Summe der bisher erzielten Spielpunkte.
 === Ende Beschreibung === */
#pragma inline_depth(3)
static inline int mask903(short i){return 1<<(i%32);}
short f_091f70(int p1)
{
    struct Bits { static unsigned char nz0(int a){return a != 0 ? 1 : 0;}static unsigned char nz1(int a){return a != 0 ? 1 : 0;}static int nz2(int a){return a != 0 ? 1 : 0;} };
    { short hold = d_1bdbb0; d_1bdbb0 = hold; } // haelt die Registerzuteilung in f_091f70 wie im Original
    short i = (unsigned short)p1;
    int r = 0;
    int m = 1 << (i % 32);
    if (i < 0x20) {
        r = Bits::nz0(m & d_1bdb98);
    } else if (i < 0x40) {
        r = Bits::nz1(m & d_1bdba0);
    } else if (i < 0x60) {
        r = Bits::nz2(m & d_1bdba8);
    }
    if (!r) d_1bdbb0 += (short)d_1a2938[(short)p1];
    i = (short)p1;
    m = mask903(i);
    if ((short)i < 0x20) d_1bdb98 |= m;
    else if ((short)i < 0x40) d_1bdba0 |= m;
    else if ((short)i < 0x60) d_1bdba8 |= m;
    if (GTI(d_1bdbb0, 1000)) return 1000;
    return d_1bdbb0;
}


#pragma inline_depth(3)
//@ f_092050
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt den aktuellen Spielpunktestand aus d_1bdbb0 zurück, gedeckelt auf den Höchstwert 1000.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt den Punktestand (0..1000) als short zurück.
 * - Wichtige Variablen: Gelesen wird ausschließlich der globale Spielpunktezähler d_1bdbb0.
 === Ende Beschreibung === */
short f_092050(void)
{
    if (GTI(d_1bdbb0, 1000)) return 1000;
    return d_1bdbb0;
}

//@ f_092080
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert zwei hintereinanderliegende 256-Farben-Palettenpuffer à 0x300 Bytes ab der
 *   Adresse p1 über f_147c84 und gibt den Basiszeiger p1 zurück.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Pufferzeiger p1 entgegen und gibt denselben Basiszeiger
 *   zurück.
 * - Wichtige Variablen: Die beiden Palettenbereiche (p1 und p1 + 0x300) dienen beim Auf- und Abblenden des
 *   Spielpunktebildschirms als Sicherungspalette und Zielpalette.
 === Ende Beschreibung === */
int f_092080(int p1)
{
    int result = f_147c84(p1, 0x100, (int)d_1baac0);
    result = f_147c84(result + 0x300, 0x100, (int)d_1baac0);
    return result - 0x300;
}

//@ f_0920b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Leere Platzhalterfunktion (ret), die keinen Code ausführt.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Es werden keine Variablen gelesen oder verändert.
 === Ende Beschreibung === */
void f_0920b0(void)
{
}

//@ f_0920c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Wartet im Spielpunktebildschirm, bis der Spieler eine Taste drückt, eine Maustaste klickt oder
 *   ein Joystick-Signal auslöst, damit das Fenster erst nach Bestätigung wieder geschlossen wird.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Abgefragt werden der Tastaturpuffer sowie die Maus- und Eingabestatusfunktionen.
 === Ende Beschreibung === */
void f_0920c0(void)
{
    WAITKEY
}

//@ f_092140
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Blendet das aktuelle Bild ab (f_09a140), sichert den Bildschirminhalt in das temporäre
 *   Sicherungsobjekt d_1a2934 (f_09ac80) und löscht den sichtbaren Grafikpuffer d_1a34e0, um Platz für die
 *   Spielpunkteanzeige zu schaffen.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den Palettenpuffer und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Objekt d_1a2934 hält den gesicherten Bildschirminhalt vor dem Öffnen der
 *   Spielpunkteübersicht.
 === Ende Beschreibung === */
void f_092140(int p1)
{
    f_149eb4(p1, 0, 0x100);
    f_09ac80(d_1a34e0, d_1a2934, 0);
    f_09a140(p1, 0x19);
    f_09a0d0(d_1a34e0);
}

//@ f_092190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Stellt nach dem Schließen der Spielpunkteanzeige den zuvor in d_1a2934 gesicherten
 *   Bildschirminhalt wieder her (f_09ade0, f_09aed0) und blendet die ursprüngliche Farbpalette p1 weich ein
 *   (f_09a120).
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf die gesicherte Farbpalette und gibt keinen Wert
 *   zurück (void).
 * - Wichtige Variablen: Der gespeicherte Bildschirm in d_1a2934 wird nach dem Zurückkopieren sofort wieder
 *   freigegeben.
 === Ende Beschreibung === */
void f_092190(int p1)
{
    f_09ade0(d_1a34e0, d_1a2934, 0);
    f_09aed0(d_1a2934);
    f_09a120(p1, 0x19);
}

//@ f_0921d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Ermittelt anhand der globalen Kapitel- und Storyflags (d_1bdcfc, d_1bdd04, d_1c00a0,
 *   d_1bee18), in welchem der vier großen Handlungsabschnitte (0..3) sich die Heldengruppe befindet, um das
 *   passende Hintergrundbild für den Spielpunktebildschirm auszuwählen.
 * - Eingaben und Rückgabe: Die Funktion nimmt einen ungenutzten Parameter p1 entgegen und gibt die
 *   Abschnittsnummer (0..3) als short zurück.
 * - Wichtige Variablen: Geprüft werden in absteigender Reihenfolge der späteste Spielabschnitt (d_1bdcfc > 0 ||
 *   d_1bdd04 == 1 -> 3), Abschnitt 2 (d_1c00a0 == 1), Abschnitt 1 (d_1bee18 == 1) und der Spielbeginn (0).
 === Ende Beschreibung === */
short f_0921d0(int p1)
{
    if (GTI(d_1bdcfc, 0) || EQI(d_1bdd04, 1)) return 3;
    if (EQI(d_1c00a0, 1)) return 2;
    if (EQI(d_1bee18, 1)) return 1;
    return 0;
}

//@ f_092240
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Lädt das zum aktuellen Handlungsabschnitt (0..3) gehörende Vollbild (0x2a0001 + s) für die
 *   Spielpunkteanzeige in den Grafikpuffer d_1a34e0 und kopiert dessen Farbpalette nach p1 + 0x300.
 * - Eingaben und Rückgabe: Die Funktion erhält den Palettenpufferzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das temporäre Bildladeobjekt o entpackt die Bildressource 0x2a0001..0x2a0004 direkt in
 *   den Bildschirmpuffer.
 === Ende Beschreibung === */
void f_092240(int p1)
{
    short s;
    int q;
    T *o = new (mark(d_1a2914, 499)) T;
    CTOR(o)
    SEL(s)
    q = p1;
    { int t_ = (int)(d_1a34e0); f_145a20((int)o, s + 0x2a0001, t_, q + 0x300); }
    DTOR(o)
}

//@ f_092310
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeichnet die grafische Fortschrittsanzeige (Füllsäule bzw. Sanduhr/Balken aus 0x2a0005)
 *   entsprechend dem aktuellen Spielpunktestand (d_1bdbb0 im Verhältnis zu 1000) anteilig auf das geladene
 *   Hintergrundbild in d_1a34e0.
 * - Eingaben und Rückgabe: Die Funktion erhält einen ungenutzten Kontextparameter p1 und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Die sichtbare Höhe height der Fortschrittssäule wird proportional aus (amount * 100 /
 *   1000) * 0xc3 / 100 + 0x18 berechnet.
 === Ende Beschreibung === */
void f_092310(int p1)
{
    char left[12];
    char right[12];
    short selection;
    short amount;
    short top;
    short height;
    int bitmap;

    if (((d_1bdcfc > 0) ? 1 : 0) || ((d_1bdd04 == 1) ? 1 : 0))
        selection = 3;
    else if ((d_1c00a0 == 1) ? 1 : 0)
        selection = 2;
    else if ((d_1bee18 == 1) ? 1 : 0)
        selection = 1;
    else
        selection = 0;

    ((int)(((RivaRasterImage*)((int)left))->f_0fac80( 0x30, 0x24)));
    ((int)(((RivaRasterImage*)((int)right))->f_0fac80( 0xdb, 0x24)));
    ((RivaRasterImage*)((int)left))->f_0fb120();
    ((RivaRasterImage*)((int)right))->f_0fb120();
    f_04fef0((int)d_1c2be0, 0x2a0005, ((int)(((RivaRasterImage*)((int)left))->f_0fb0b0())), 0, selection, 0, 0x140);
    selection += 4;
    f_04fef0((int)d_1c2be0, 0x2a0005, ((int)(((RivaRasterImage*)((int)right))->f_0fb0b0())), 0, selection, 0, 0x140);

    if (((d_1bdbb0 > 1000) ? 1 : 0)) amount = 1000;
    else amount = d_1bdbb0;
    bitmap = d_1a34e0;
    bitmap += 0xcc0e;
    height = (int)(((short)((amount * 100) / 1000) * 0xc3) / 100);
    height += 0x18;
    top = 0xdb - height;
    ((RivaRasterImage*)((int)right))->f_0fb3e0((char *)( bitmap), 0x140, (short)top, 0, (short)height, 0x24, 0);
    ((RivaRasterImage*)((int)left))->f_0fae30((void *)( d_1a34e0), 0x23, 0xa3, 1);
    ((int)(((RivaRasterImage*)((int)right))->f_0fad20( 0)));
    ((int)(((RivaRasterImage*)((int)left))->f_0fad20( 0)));
    return;
}
//@ f_0924c0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Formatiert und zeichnet die zentrierte Textzeile <aktuelle Punkte> von 1000 (0x2a000005) bei Y
 *   = 0x9a auf den Spielpunktebildschirm.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Im RivaTextContext obj werden slots[4] + 2 mit dem aktuellen Punktestand v und slots[4]
 *   + 4 mit dem Maximalwert 1000 belegt.
 === Ende Beschreibung === */
void f_0924c0(void)
{
    RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
    short v, s1, s2;
    short c, b, d, a;
    CLAMP(v)
    *(short *)(obj.slots[4] + 2) = v;
    *(short *)(obj.slots[4] + 4) = 1000;
    s1 = f_05e1f0((int)d_1c38b0);
    s2 = f_05e200((int)d_1c38b0);
    TAIL5(s1, s2)
}

//@ f_0925e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Baut den Spielpunktebildschirm im bereits abgedunkelten Zustand auf (lädt das
 *   Kapitelhintergrundbild, zeichnet die Fortschrittssäule über f_092310 und gibt den Punktestandstext aus),
 *   blendet das Bild ein, wartet auf einen Tastendruck oder Mausklick und blendet es wieder aus.
 * - Eingaben und Rückgabe: Die Funktion erhält den Zeiger p1 auf den doppelten Palettenpuffer und gibt keinen
 *   Wert zurück (void).
 * - Wichtige Variablen: Die Zielpalette des Hintergrundbildes liegt in p1 + 0x300.
 === Ende Beschreibung === */
void f_0925e0(int p1)
{
    int codex_arg_0_231;
    short s, v, s1;
    struct {
        short c, pc;
        short b, pb;
        int s2;
        short d, pd;
        short a, pa;
    } L;
    int q = p1;
    T *o = new (mark(d_1a2914, 499)) T;
    CTOR(o)
    SEL(s)
    f_145a20((int)o, s + 0x2a0001, d_1a34e0, q + 0x300);
    DTOR(o)
    f_092310(p1);
    {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        CLAMP(v)
        *(short *)(obj.slots[4] + 2) = v;
        *(short *)(obj.slots[4] + 4) = 1000;
        s1 = f_05e1f0((int)d_1c38b0);
        L.s2 = f_05e200((int)d_1c38b0);
        f_05e2a0((int)d_1c38b0, (int)&L.a, (int)&L.b, (int)&L.c, (int)&L.d);
        f_05e2d0((int)d_1c38b0, 0, 0x140, -1, 1);
        f_05e1d0((int)d_1c38b0, s1, 0x9a);
        f_05e320((int)d_1c38b0, 0xff, -1);
        f_0e9550((int)d_1c38b0, 0x2a000005);
        {
            int t;
            f_05e340((t = (short)L.s2, (int)d_1c38b0));
            f_05e1d0((int)d_1c38b0, s1, t);
        }
        f_05e2d0((int)d_1c38b0, L.a, L.b, L.c, L.d);
    }
    f_09a120(p1 + 0x300, 0x19);
    WAITKEY
    f_09a140(p1 + 0x300, 0x19);
    f_09a0d0((codex_arg_0_231 = d_1a34e0));
}

//@ f_092870
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die komplette Anzeige des Spielpunktebildschirms mit einem bereits bereitgestellten
 *   Palettenpuffer p1 durch: Sie blendet den laufenden Spielbildschirm aus, sichert ihn in d_1a2934, zeigt
 *   Hintergrundbild, Fortschrittssäule und Punktetext bis zum Tastendruck an und stellt danach den
 *   ursprünglichen Spielbildschirm samt Mauszeiger wieder her.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Palettenpufferzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Flag L.fl merkt sich, ob der Mauszeiger vor dem Bildwechsel sichtbar war (f_0d3860()
 *   == 1), damit er am Ende über f_0d26e0() wieder eingeschaltet wird.
 === Ende Beschreibung === */
void f_092310(int p1);
void f_092870(int p1)
{
    struct {
        int fl;
        short d, pd;
        short a, pa;
        short b, pb;
        short c, pc;
    } L;
    int s2;
    int codex_arg_0_276;
    int codex_arg_1_276;
    if (f_0d3860() == 1) { int flag = 1; f_0d2710(); L.fl = flag; } else L.fl = 0;
    f_149eb4(p1, 0, 0x100);
    f_09ac80(d_1a34e0, d_1a2934, 0);
    f_09a140(p1, 0x19);
    f_09a0d0(d_1a34e0);
    int q = p1;
    {
        short s;
        int r = p1;
        T *o = new (mark(d_1a2914, 499)) T;
        CTOR(o)
        if (f_092f20((int)&d_1bdcfc, 0) || f_02de00((int)&d_1bdd04, 1)) s = 3;
        else if (f_02de00((int)&d_1c00a0, 1)) s = 2;
        else if (f_02de00((int)&d_1bee18, 1)) s = 1;
        else s = 0;
        { int t_ = d_1a34e0; int sel = (short)s; sel += 0x2a0001; f_145a20((int)o, sel, t_, r + 0x300); }
        DTOR(o)
    }
    f_092310(q);
    {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        short v, s1;
        if (f_092f00((int)&d_1bdbb0, 1000)) v = 1000; else v = f_02ddf0((int)&d_1bdbb0);
        *(short *)(obj.slots[4] + 2) = v;
        *(short *)(obj.slots[4] + 4) = 1000;
        s1 = f_05e1f0((int)d_1c38b0);
        s2 = f_05e200((int)d_1c38b0);
        f_05e2a0((int)d_1c38b0, (int)&L.a, (int)&L.b, (int)&L.c, (int)&L.d);
        f_05e2d0((int)d_1c38b0, 0, 0x140, -1, 1);
        f_05e1d0((int)d_1c38b0, s1, 0x9a);
        f_05e320((int)d_1c38b0, 0xff, -1);
        f_0e9550((int)d_1c38b0, 0x2a000005);
        f_05e340((int)d_1c38b0);
        f_05e1d0((int)d_1c38b0, s1, (short)s2);
        f_05e2d0((int)d_1c38b0, L.a, L.b, L.c, L.d);
    }
    f_09a120(q + 0x300, 0x19);
    WAITKEY
    f_09a140(q + 0x300, 0x19);
    f_09a0d0(d_1a34e0);
    f_09ade0((codex_arg_0_276 = d_1a34e0), (codex_arg_1_276 = d_1a2934), 0);
    f_09aed0(d_1a2934);
    f_09a120(p1, 0x19);
    if (L.fl == 1) f_0d26e0();
}
//@ f_092b90
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet als eigenständige Hauptfunktion das Spielpunktefenster aus dem Options- oder Hauptmenü
 *   heraus, indem sie den benötigten 0x600-Byte-Palettenpuffer selbst reserviert, Bildschirm und Mausstatus
 *   sichert, Hintergrundbild, Fortschrittssäule und Punktestand bis zum Tastendruck anzeigt und anschließend
 *   alle Puffer wieder freigibt.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Während der Anzeige wird d_1c0c94 vorübergehend auf 0 gesetzt und d_1c0c4c
 *   inkrementiert, um Hintergrund-Timeraktionen zu pausieren.
 === Ende Beschreibung === */
void f_092b90(void)
{
    struct {
        int fl;
        volatile int old_global; // haelt den Stapelplatz fuer den gesicherten Globalwert wie im Original
        int bitmap_for_clear;
        short d, pd;
        int cleanup_object;
    } S1;
    struct {
        short b, pb;
        short c, pc;
        int s2;
        short a, pa;
    } L;

    f_0ce7c0((int)&S1.cleanup_object);
    S1.old_global = d_1c0c94;
    d_1c0c94 = 0;
    ++d_1c0c4c;

    int b = (int)new (mark(d_1a2914, 0x2a9)) T600;
    int res = (b ? f_147c84(f_147c84(b, 0x100, (int)d_1baac0) + 0x300, 0x100, (int)d_1baac0) - 0x300 : b);
    S1.bitmap_for_clear = res;
    int p1 = res;

    if (f_0d3860() == 1) {
        int flag = 1;
        f_0d2710();
        S1.fl = flag;
    } else {
        S1.fl = 0;
    }

    f_149eb4(p1, 0, 0x100);
    f_09ac80(d_1a34e0, d_1a2934, 0);
    f_09a140(p1, 0x19);
    f_09a0d0(d_1a34e0);
    int q = p1;
    {
        short s;
        int r = p1;
        T *o = new (mark(d_1a2914, 499)) T;
        CTOR(o)
        s = f_0921d0(r);
        int sel = s;
        sel += 0x2a0001;
        f_145a20((int)o, sel, d_1a34e0, r + 0x300);
        DTOR(o)
    }

    f_092310(q);
    {
        RivaTextContext obj(d_1c349c, d_1c3870, d_1c3498);
        short level, s1;
        level = f_092050();
        *(short *)(obj.slots[4] + 2) = level;
        *(short *)(obj.slots[4] + 4) = 1000;
        s1 = f_05e1f0((int)d_1c38b0);
        L.s2 = f_05e200((int)d_1c38b0);
        f_05e2a0((int)d_1c38b0, (int)&L.a, (int)&L.b, (int)&L.c, (int)&S1.d);
        f_05e2d0((int)d_1c38b0, 0, 0x140, -1, 1);
        f_05e1d0((int)d_1c38b0, s1, 0x9a);
        f_05e320((int)d_1c38b0, 0xff, -1);
        f_0e9550((int)d_1c38b0, 0x2a000005);
        {
            int t;
            f_05e340((t = (short)L.s2, (int)d_1c38b0));
            f_05e1d0((int)d_1c38b0, s1, t);
        }
        f_05e2d0((int)d_1c38b0, L.a, L.b, L.c, S1.d);
    }

    f_09a120(q + 0x300, 0x19);
    WAITKEY
    f_09a140(q + 0x300, 0x19);
    f_09a0d0(d_1a34e0);
    f_09ade0(d_1a34e0, d_1a2934, 0);
    f_09aed0(d_1a2934);
    f_09a120(p1, 0x19);
    if (S1.fl == 1) f_0d26e0();

    int delete_bitmap = S1.bitmap_for_clear;
    if (delete_bitmap != 0) operator delete((void *)delete_bitmap);
    int dec_val = d_1c0c4c - 1;
    int old_val = S1.old_global;
    d_1c0c4c = dec_val;
    d_1c0c94 = old_val;
    f_149d20();
    f_0ce7e0((int)&S1.cleanup_object, 0);
}
