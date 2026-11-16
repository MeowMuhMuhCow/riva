/* === Beschreibung (Katalog) ===
 * Einheit door (0x05f190 - 0x05fbf0)
 *
 * Überblick
 * Diese Einheit (door.cpp) implementiert die Klasse Door zur Verwaltung von Türen in Dungeons und Gebäuden: das
 * Laden und Zurückschreiben der 20-Byte-Türsätze aus der Türdatei 0x400a0000, das Öffnen des Schloss-Dialogs bei
 * verriegelten Türen, die Türanimation samt Klang und Automap-Eintrag sowie die Prüfung, ob eine Heldengruppe im
 * Türfeld steht (einschließlich Einklemmschaden).
 === Ende Beschreibung === */
#include "RIVAFILE.H"
#include "RIVAMEM.H"
// P3 14/16 gleich (suche.py 25.10.2026, Basis door_P1.CPP)
// door.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x05F190-0x05FBF0
#include <string.h>
#pragma aux f_147323 modify [esp];
struct Ent { short s0, s2, s4, s6, s8, sa; int st; short s10, s12; };
struct E61 { char pad[0x61]; int f_0de7c0(); short f_0de820(); int f_0de840(); int f_0de880(); int f_0ddeb0(); int f_0ddd60(); };

struct Msg { int f_0bf730(int); int f_0bf6f0(int); };
struct Guard { int v; void f_0ce7c0(); void f_0ce7e0(int); };
struct Snd { int f_147323(int, int, int, int, int, int); int f_146dfa(int); };
struct Sx { int f_019c90(int, int); };
struct T12 { short a, b, c, d, e, f; };
struct O38 { char pad[38]; O38 *f_0ba0d0(const char *, T12 *); int f_0ba160(int); int f_0ba180(); };
struct Obj { int x0; int x4; char pad[52]; void f_125400(void *, void *, void *); void f_1254a0(int); };
extern RivaFileManager d_1c2098; extern Msg d_1c2c64; extern Snd d_1c2edc; extern Sx d_1c2a84;
extern E61 d_1bfdbc[]; extern E61 *d_1c21b4[]; extern E61 *d_1c0004;
extern short d_1c21a4; extern int d_1a9820; extern char d_1a18ec[][3];
extern char d_1c349c[], d_1c3870[], d_1c3498[];
extern const char d_1a18d0[];
int f_149640(unsigned short id); void f_149a14(unsigned short id, int p); void f_149524(unsigned short id);
void f_149b44(); void f_149d20(); int f_1223c0(); short f_1511ec(int a, int b);
int f_1457e0(int n); int f_038c40(E61 *e); int f_039a80(E61 *e, void (*cb)(E61 *));
int f_0d4a60(E61 *e); int f_044850(E61 *e, int a, int b);
#define DEL(x) operator delete((void *)(x))
struct Door {
    int sz; Ent *ents; short cnt; unsigned short id;
    Door *f_05f190(short a, short b);
    Door *f_05f220(int p_unused1);
    void f_05f280(int p2);
    int f_05f360();
    int f_05f460();
    int f_05f470();
    int f_05f480();
    int f_05f4f0(int p2);
    int f_05f560();
    int f_05f580();
    void f_05f5a0(int p2);
    void f_05f6e0(int p2);
    short f_05f800(E61 **out);
    int f_05f890();
};
#define EQ(x,v) (((x)==(v))?1:0)
//@ f_05f190
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Konstruktor eines Door-Objekts: speichert die Satznummer a und die Türkennung b (8000 +
 *   Türnummer) und liest, sofern die Tür ein Schloss besitzt (a != 0), den 20-Byte-Türsatz an Dateiposition a *
 *   20 aus der Türdatei 0x400a0000 in einen frisch angelegten Puffer ents ein.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger, die Satznummer a (0 = Tür ohne Schloss) und die
 *   Türkennung b und gibt this zurück.
 * - Wichtige Variablen: Im Door-Objekt speichern cnt die Satznummer, id die Türkennung (8000 + n), sz den
 *   Dateiversatz cnt * 20 und ents den Zeiger auf den 20-Byte-Türsatz (Ent).
 === Ende Beschreibung === */
Door *Door::f_05f190(short a, short b)
{
    ents = 0;
    cnt = a;
    id = b;
    if ((int)(short&)cnt) { // Haelt die Bedingungspruefung als short-Ladezugriff wie im Original
        // Erzwingt erneutes Laden von cnt aus this nach den Feldstores
        sz = (volatile short&)cnt * 20;
        ents = (Ent *)operator new(20, mark(d_1a18d0, 0x5e));
        d_1c2098.f_1448b0(0x400a0000, 0x200);
        d_1c2098.f_144ab0(sz, 0);
        d_1c2098.f_144920(ents, 0x14);
        d_1c2098.f_1449a0();
    }
    return this;
}
//@ f_05f220
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Destruktor eines Door-Objekts: schreibt bei einer Tür mit Türsatz (cnt != 0) den
 *   möglicherweise entriegelten 20-Byte-Türsatz ents an die Position sz der Türdatei 0x400a0000 zurück und gibt
 *   den Pufferspeicher ents frei.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und eine ungenutzte Destruktorkennung p_unused1
 *   und gibt this zurück.
 * - Wichtige Variablen: Nutzt das globale Dateisystem-Objekt d_1c2098 im Schreibmodus 0x202.
 === Ende Beschreibung === */
Door *Door::f_05f220(int p_unused1)
{
    if (cnt != 0) {
        d_1c2098.f_1448b0(0x400a0000, 0x202);
        d_1c2098.f_144ab0(sz, 0);
        d_1c2098.f_144960(ents, 0x14);
        d_1c2098.f_1449a0();
        DEL(ents);
    }
    return this;
}
//@ f_05f280
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Führt die Standardinteraktion des Spielers mit einer Tür aus: ist die Tür derzeit offen
 *   (f_05f580() == 1), wird versucht, sie über f_05f4f0(p2) zu schließen; ist sie geschlossen, wird versucht,
 *   sie (gegebenenfalls nach einem Schlossversuch) über f_05f480() zu öffnen.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und eine optionale Meldungskennung p2 für das
 *   Schließen (0 = keine Meldung) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ein lokales Guard-Objekt g (f_0ce7c0/f_0ce7e0) sichert den Anzeige-/Mauszustand während
 *   der Türaktion.
 === Ende Beschreibung === */
void Door::f_05f280(int p2)
{
    Guard g;
    g.f_0ce7c0();
    if (f_05f580() == 1) f_05f4f0(p2); else f_05f480();
    g.f_0ce7e0(0);
}
//@ f_05f360
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft, ob die Tür verriegelt ist (ents->st == 1), und öffnet in diesem Fall den Schloss-Dialog
 *   (O38, f_0ba0d0) mit den sechs Schlosswerten aus dem Türsatz (s10, s12, s4, s6, s8, sa) und dem
 *   3-Zeichen-Schlosstyp d_1a18ec[ents->s2]. Gelingt das Knacken oder Aufschließen im Dialog (f_0ba180() == 1),
 *   wird die Tür dauerhaft als entriegelt markiert (ents->st = 0).
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn die Tür danach entriegelt
 *   ist (ents->st == 0), sonst 0.
 * - Wichtige Variablen: Das Feld ents->st speichert den Verriegelungszustand (1 = verriegelt, 0 = entriegelt),
 *   analog zum Truhenschloss in chest.
 === Ende Beschreibung === */
int Door::f_05f360()
{
    if (ents->st == 1) {
        T12 *p3 = (T12 *)operator new(12, mark(d_1a18d0, 0xa0));
        p3->a = ents->s10;
        p3->b = ents->s12;
        p3->c = ents->s4;
        p3->d = ents->s6;
        p3->e = ents->s8;
        p3->f = ents->sa;
        O38 *n = (O38 *)operator new(38, mark(d_1a18d0, 0xb5));
        O38 *o = n ? n->f_0ba0d0((char *)(ents->s2 * 3 + (int)(char *)d_1a18ec), p3) : n;
        if (o->f_0ba180() == 1) ents->st = 0;
        if (o) DEL(o->f_0ba160(0));
        DEL(p3);
    }
    return ents->st == 0;
}
//@ f_05f460
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verriegelt die Tür, indem das Statusfeld ents->st im Türsatz auf 1 gesetzt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt konstant 1 zurück.
 * - Wichtige Variablen: Setzt this->ents->st = 1 (setzt voraus, dass ents != 0 ist).
 === Ende Beschreibung === */
int Door::f_05f460()
{
    ents->st = 1;
    return 1;
}
//@ f_05f470
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Entriegelt die Tür (z. B. durch einen passenden Schlüssel oder ein Skriptereignis), indem
 *   ents->st auf 0 gesetzt wird.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt konstant 1 zurück.
 * - Wichtige Variablen: Setzt this->ents->st = 0.
 === Ende Beschreibung === */
int Door::f_05f470()
{
    ents->st = 0;
    return 1;
}
//@ f_05f480
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versucht eine geschlossene Tür zu öffnen: ist sie verriegelt (f_05f560() == 1), wird zuerst
 *   der Schloss-Dialog f_05f360() aufgerufen; ist sie danach (oder von vornherein) unverriegelt, wird sie über
 *   f_05f6e0(0) mit Klang und Animation geöffnet.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn die Tür am Ende offen
 *   steht, sonst 0.
 * - Wichtige Variablen: Fragt den Verriegelungszustand über f_05f560() und den Öffnungszustand über f_05f580()
 *   ab.
 === Ende Beschreibung === */
int Door::f_05f480()
{
    if (!f_05f580()) {
        if (f_05f560() == 1) f_05f360();
        if (f_05f560() == 0) f_05f6e0(0);
    }
    return f_05f580();
}
//@ f_05f4f0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Versucht eine offene Tür zu schließen: prüft über f_05f890(), ob eine Heldengruppe im Türfeld
 *   steht; nur wenn das Türfeld frei ist, wird eine optionale Meldung p2 angezeigt (f_0bf730) und die Tür über
 *   f_05f5a0(0) geschlossen.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und eine optionale Textkennung p2 (0 = keine
 *   Meldung) und gibt 1 zurück, wenn die Tür danach geschlossen ist, sonst 0.
 * - Wichtige Variablen: Nutzt das globale Meldungsfenster d_1c2c64 für die optionale Textausgabe.
 === Ende Beschreibung === */
int Door::f_05f4f0(int p2)
{
    if (EQ(f_05f580(), 0)) goto done;
    if (f_05f890() == 0) {
        if (p2 != 0) d_1c2c64.f_0bf730(p2);
        f_05f5a0(0);
    }
done:
    return !f_05f580();
}
//@ f_05f560
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt an, ob die Tür verriegelt ist; eine Tür ohne geladenen Türsatz (ents == 0) gilt stets als
 *   unverriegelt.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt ents->st (1 = verriegelt, 0 =
 *   unverriegelt) zurück.
 * - Wichtige Variablen: Prüft this->ents auf Nullzeiger und liest this->ents->st.
 === Ende Beschreibung === */
int Door::f_05f560()
{
    int r = 0;
    if (ents != 0) r = ents->st;
    return r;
}
//@ f_05f580
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt über die 3D-/Karten-Engine (f_149640(id)) ab, ob sich die Tür derzeit im offenen Zustand
 *   (1) befindet.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn die Tür offen ist, sonst
 *   0.
 * - Wichtige Variablen: Übergibt die Türkennung this->id (8000 + n) an f_149640 (Zustandswerte: 1 = offen, 2 =
 *   geschlossen, 3 = öffnet gerade, 4 = schließt gerade).
 === Ende Beschreibung === */
int Door::f_05f580()
{
    int r = 0;
    if (f_149640(id) == 1) r = 1;
    return r;
}
//@ f_05f5a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Schließt eine offene Tür (f_149640(id) == 1): spielt im Normalbetrieb (p2 == 0 und d_1c21a4 ==
 *   0) den Türklang 0xa0002 ab, startet die Schließanimation (f_149a14(id, 0), f_149524(id)) und zeichnet
 *   Einzelbilder, solange die Tür im Zustand 4 (schließt) ist. Ist sie danach geschlossen (2), wird der neue
 *   Zustand (0) für die Tür id - 8000 in der Automap (d_1c2a84.f_019c90) vermerkt und für alle besetzten Gruppen
 *   am selben Ort f_0ddd60() aufgerufen.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und den Stummschalter p2 (1 = lautlos und ohne
 *   Bildneuaufbau, 0 = mit Klang und Bildaufbau) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die globale Variable d_1c21a4 erzwingt außerhalb des normalen Spielbetriebs (!= 0) den
 *   lautlosen Modus; d_1bfdbc[0..5] ist die Tabelle aller 6 Heldengruppen.
 === Ende Beschreibung === */
void Door::f_05f5a0(int p2)
{
    int f_147323_frame(int, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp]
    Guard g;
    g.f_0ce7c0();
    if (f_149640(id) == 1) {
        if (d_1c21a4 != 0) p2 = 1;
        int snd;
        if (p2 == 0) f_147323_frame((int)&d_1c2edc, 0xa0002, 0x7fff, 0x8000, (snd = d_1a9820), p2, 1);
        f_149a14(id, 0);
        f_149524(id);
        int s;
        do {
            d_1c2edc.f_146dfa(1);
            if (p2 == 0) f_1223c0(); else f_149b44();
            s = f_149640(id);
            f_149d20();
        } while (s == 4);
        if (f_149640(id) == 2) d_1c2a84.f_019c90((short)(id - 8000), 0);
        short i;
        for (i = 0; i < 6; i++) {
            E61 *e = &d_1bfdbc[i];
            if (e->f_0de7c0() != 0) {
                if (e->f_0de820() == d_1c0004->f_0de820()) {
                    if (e->f_0ddeb0() != 0) e->f_0ddd60();
                }
            }
        }
    }
    g.f_0ce7e0(0);
}
//@ f_05f6e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet als Gegenstück zu f_05f5a0 eine geschlossene Tür (f_149640(id) == 2): spielt bei p2 ==
 *   0 den Türklang 0xa0002 ab, startet die Öffnungsanimation (f_149a14(id, 1), f_149524(id)), wartet in einer
 *   Animationsschleife das Ende der Bewegung (Zustand 3) ab und trägt die offene Tür (1) anschließend für id -
 *   8000 in die Automap (d_1c2a84.f_019c90) ein.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und den Stummschalter p2 (1 = lautlos, 0 = mit
 *   Klang und Bildaufbau) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Nutzt wie f_05f5a0 das Klangsystem d_1c2edc und das Automap-Objekt d_1c2a84.
 === Ende Beschreibung === */
void Door::f_05f6e0(int p2)
{
    int f_147323_frame(int, int, int, int, int, int, int);
#pragma aux f_147323_frame "f_147323" modify [esp]
    Guard g;
    g.f_0ce7c0();
    if (f_149640(id) == 2) {
        if (d_1c21a4 != 0) p2 = 1;
        int snd;
        if (p2 == 0) f_147323_frame((int)&d_1c2edc, 0xa0002, 0x7fff, 0x8000, (snd = d_1a9820), p2, 1);
        f_149a14(id, 1);
        f_149524(id);
        int s;
        do {
            d_1c2edc.f_146dfa(1);
            if (p2 == 0) f_1223c0(); else f_149b44();
            s = f_149640(id);
            f_149d20();
        } while (s == 3);
        if (f_149640(id) == 1) d_1c2a84.f_019c90((short)(id - 8000), 1);
    }
    g.f_0ce7e0(0);
}
//@ f_05f7d0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Rückruffunktion für f_039a80: fügt einem handlungsfähigen Helden e (f_0d4a60(e) != 0), der im
 *   Türfeld steht, während die Tür gewaltsam zugeschlagen wird, 2 Schadenspunkte unter Beachtung einer
 *   Lebensenergiereserve von 5 LE (f_044850) zu.
 * - Eingaben und Rückgabe: Die Funktion erhält den Heldenzeiger e und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Ruft f_044850(e, 2, 5) (charact1) auf.
 === Ende Beschreibung === */
void f_05f7d0(E61 *e)
{
    if (f_0d4a60(e) != 0) f_044850(e, 2, 5);
}
//@ f_05f800
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Durchsucht alle 6 Heldengruppen d_1bfdbc[0..5] und trägt jede besetzte Gruppe, die sich am
 *   selben Ort wie die aktive Gruppe d_1c0004 befindet und auf dem Kartenfeld dieser Tür (f_1511ec(x, y) == id)
 *   steht, in das Ausgabearray out ein.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und das Zeigerarray out und gibt die Anzahl n der
 *   im Türfeld stehenden Gruppen als short zurück.
 * - Wichtige Variablen: Fragt über e->f_0de840() und e->f_0de880() die Kartenkoordinaten jeder Gruppe ab und
 *   vergleicht die Feldkennung f_1511ec mit this->id.
 === Ende Beschreibung === */
short Door::f_05f800(E61 **out)
{
    short n = 0;
    short i;
    for (i = 0; i < 6; i++) {
        E61 *e = &d_1bfdbc[i];
        if (e->f_0de7c0() != 0) {
            if (e->f_0de820() == d_1c0004->f_0de820()) {
                if (f_1511ec(e->f_0de840(), e->f_0de880()) == (short)id) out[n++] = e;
            }
        }
    }
    return n;
}
//@ f_05f890
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Prüft über f_05f800, ob mindestens eine Heldengruppe im Türfeld steht und das Schließen der
 *   Tür blockiert. Ist das der Fall, würfelt die Methode mit 1W4 (f_1457e0(4)) eine von vier Reaktionen aus:
 *   eine von drei Warnmeldungen (0xa010017, 0xa010018 oder 0xa010019 mit dem Namen des ersten handlungsfähigen
 *   Helden) oder die Ja/Nein-Frage 0xa01001a, bei deren Bejahung die Meldung 0xa01001b erscheint und alle Helden
 *   der blockierenden Gruppen Einklemmschaden über f_05f7d0 erleiden.
 * - Eingaben und Rückgabe: Die Methode erhält den this-Zeiger und gibt 1 zurück, wenn mindestens eine Gruppe im
 *   Türfeld steht (Tür bleibt offen), sonst 0.
 * - Wichtige Variablen: Nutzt den globalen Puffer d_1c21b4 als Zeigerliste tab für die gefundenen Gruppen.
 === Ende Beschreibung === */
int Door::f_05f890()
{
    E61 **tab = d_1c21b4;
    short n = f_05f800(tab);
    short m;
    m = n;
    if (n > 0) {
        Obj o;
        o.f_125400(d_1c349c, d_1c3870, d_1c3498);
        switch ((short)f_1457e0(4)) {
        case 1:
            d_1c2c64.f_0bf730(0xa010017);
            break;
        case 2:
            d_1c2c64.f_0bf730(0xa010018);
            break;
        case 3:
            ((Obj *)o.x4)->x4 = f_038c40(d_1c0004);
            d_1c2c64.f_0bf730(0xa010019);
            break;
        case 4:
            if (d_1c2c64.f_0bf6f0(0xa01001a) == 1) {
                short k;
                d_1c2c64.f_0bf730(0xa01001b);
                k = 0;
                while (k < m) {
                    f_039a80(tab[k++], f_05f7d0);
                }
            }
            break;
        }
        o.f_1254a0(0);
    }
    return m != 0;
}
//@ f_05fa00
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Freie Komfortfunktion für Orts-Skripte (z. B. in castle_t1): legt auf dem Heap ein temporäres
 *   Door-Objekt mit Satznummer a und Türkennung b (8000 + n) an, führt einmal die Standard-Türbenutzung
 *   (f_05f280(0)) aus und speichert und zerstört das Objekt anschließend sofort wieder.
 * - Eingaben und Rückgabe: Die Funktion erhält die Satznummer a in der Türdatei und die Türkennung b und gibt
 *   keinen Wert zurück (void).
 * - Wichtige Variablen: Bildet die Methoden f_05f190, f_05f4f0, f_05f280 und f_05f220 in einer lokalen
 *   Hilfsklasse BuiltDoor nach.
 === Ende Beschreibung === */
void f_05fa00(short a,short b)
{
    int state730(Door*);
    #pragma aux state730 "f_05f580" parm [eax] value [eax] modify exact [eax]
    struct BuiltDoor:Door {
        BuiltDoor(short a,short b) {
            ents=0; cnt=a; id=b;
            if ((int)(short&)cnt) { // Haelt die Bedingungspruefung als short-Ladezugriff wie im Original
                // Erzwingt erneutes Laden von cnt aus this nach den Feldstores
                sz=(volatile short&)cnt*20;
                ents=(Ent*)operator new(20,mark(d_1a18d0,0x5e));
                d_1c2098.f_1448b0(0x400a0000,0x200);
                d_1c2098.f_144ab0(sz,0);
                d_1c2098.f_144920(ents,20);
                d_1c2098.f_1449a0();
            }
        }
        ~BuiltDoor(){f_05f220(0);}
        int open730(int message) {
            if(EQ(state730(this),0)) goto done;
            if(f_05f890()==0) {
                if(message) d_1c2c64.f_0bf730(message);
                f_05f5a0(0);
            }
        done: return !state730(this);
        }
        void action730(int message) {
            Guard g;g.f_0ce7c0();
            if(f_05f580()==1) open730(message); else f_05f480();
            g.f_0ce7e0(0);
        }
    };
    BuiltDoor*d=new(mark(d_1a18d0,0x2a9))BuiltDoor(a,b);
    d->action730(0);
    delete d;
}
