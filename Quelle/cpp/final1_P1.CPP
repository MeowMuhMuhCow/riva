/* === Beschreibung (Katalog) ===
 * Einheit final1 (08d590 - 08dae0)
 *
 * Überblick
 * Die Einheit final1 enthält dreizehn Einzel-Ereignishandler des ersten Final-Abschnitts (f_08d590 bis
 * f_08da20), die von der Ereignisverteilung f_08cd20 aufgerufen werden: das Anzeigen von Raumgrafiken und
 * Zwischensequenzen, das Öffnen von Truhen und Beutelagern (0x41, 0x42), das Auslösen von Story-Kämpfen
 * (0x44..0x48) samt Vergabe von Spielpunkten (f_091f70) sowie einmalige Raumhinweise.
 === Ende Beschreibung === */
#include "RIVAIMG.H"
#include "RIVAMEM.H"
// OPT -4r -onetx -zp1 -s
// P1 10/13 gleich
// final1.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x08D590-0x08DAE0
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern const char d_1a2860[];           // Text 0x1A2860
// --- eigene Funktionen (13), in dieser Reihenfolge definieren, je eine Zeile //@ f_xxxxxx davor ---
void *f_0104b0(void *p, int a, int b, int c);
int f_010590(void *p, int a);
int f_038c40(int p1);
int f_039660(int p1, int p2);
void *f_0606a0(int p1, int p2);
int f_091f70(int p1);
int f_0bf680(const char *o);
int f_0bf6c0(const char *o, int b);
int f_0bf6f0(const char *o, int b);
int f_0bf730(const char *o, int b);
int f_0bf980(const char *o, ...);
int f_0bfa20(const char *o, ...);
int f_0dcf00(int p1, int p2, int p3);

void *f_112df0(void *p, int a, int b, int c);
int f_112e70(void *p, int a);
int f_112ec0(void *p);
int f_1131b0(void *p);
int f_125400(void *p1, const char *p2, const char *p3, const char *p4);
int f_1254a0(void *p1, int p2);
extern signed char d_1bdb00, d_1bdb01, d_1bdb02, d_1bdb08, d_1bdb0c, d_1bdb10, d_1bdb14, d_1bdb18, d_1bdb1c;
extern int d_1c0004;
extern char d_1c2c64[];
extern const char d_1c349c[], d_1c3870[], d_1c3498[];
struct SO { int a; int *p; char c[52]; SO() { f_125400(this, d_1c349c, d_1c3870, d_1c3498); } ~SO() { f_1254a0(this, 0); } };
struct T1 { char b[0x13e]; };
struct T2 { char b[0x14]; };
#define EQI(x,v) (((x)==(v))?1:0)
#define VC(p,a) ((short (*)(int,int,int))(**(int **)((p)+8)))((p),(a),0)
//@ f_08d590
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Spielt beim erstmaligen Auslösen (d_1bdb08 == 0) eine Bild- und Textsequenz (0x2c0006 mit
 *   Meldung 0x2900000f) für den Gruppenanführer ab und setzt anschließend das Einmal-Flag d_1bdb08 = 1.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb08 verhindert, dass die Zwischensequenz bei erneutem Betreten des Feldes
 *   noch einmal abgespielt wird.
 === Ende Beschreibung === */
void f_08d590()
{
    if (EQI(d_1bdb08, 0)) {
        SO o;
        T1 *p = new (mark(d_1a2860, 0x11c)) T1;
        p = p ? (T1 *)f_0104b0(p, 0x2c0006, 0, 0) : p;
        o.p[1] = f_038c40(d_1c0004);
        f_0bf6c0(d_1c2c64, 6);
        f_0bf980(d_1c2c64, p, 0, 0x2900000f, 0);
        f_0bf680(d_1c2c64);
        d_1bdb08 = 1;
        if (p) delete (char *)f_010590(p, 0);
    }
}
//@ f_08d660
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler an einer Fundstelle (0x29000010), ob er die dort liegenden Gegenstände
 *   mitnehmen möchte, und übergibt bei Zustimmung 10 Exemplare des Gegenstands 0x184 an das Gruppeninventar
 *   (f_0dcf00).
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Übergabe erfolgt über die globale Gruppenverwaltung d_1c0004.
 === Ende Beschreibung === */
void f_08d660()
{
    if (f_0bf6f0(d_1c2c64, 0x29000010) == 1) f_0dcf00(d_1c0004, 0x184, 10);
}
//@ f_08d690
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet nach Rückfrage (0x29000011) den Beutecontainer Nr. 0x41 (f_112df0/f_1131b0), zeigt bei
 *   erfolgreicher Entnahme eine Begleitmeldung (0x29000013) mit dem Helden an Position 1 an und speichert den
 *   geleerten Containerzustand (f_112ec0).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das dynamisch angelegte Containerobjekt p verwaltet den aktuellen Inhalt der Truhe bzw.
 *   Fundstelle 0x41.
 === Ende Beschreibung === */
void f_08d690()
{
    T2 *p = new (mark(d_1a2860, 0x14d)) T2;
    p = p ? (T2 *)f_112df0(p, 0x41, 0, 0) : p;
    if (f_0bf6f0(d_1c2c64, 0x29000011) == 1) {
        f_0bf730(d_1c2c64, 0x29000012);
        if (f_1131b0(p)) {
            SO o;
            o.p[1] = f_039660(d_1c0004, 1);
            f_0bf730(d_1c2c64, 0x29000013);
            f_112ec0(p);
        }
    }
    if (p) delete (char *)f_112e70(p, 0);
}
//@ f_08d760
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet beim ersten Betreten (d_1bdb0c == 0) über den virtuellen Methodenaufruf VC(p1, 0x44)
 *   den Kampf Nr. 0x44 und setzt bei siegreichem Ausgang (r == 0) das Erledigt-Flag d_1bdb0c = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb0c speichert dauerhaft im Spielstand, dass die Begegnung 0x44 bereits
 *   gewonnen wurde.
 === Ende Beschreibung === */
void f_08d760(int p1)
{
    
    if (EQI(d_1bdb0c, 0)) {
        short r = VC(p1, 0x44);
        if (r == 0) d_1bdb0c = 1;
    }
}
//@ f_08d7a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Auslösen (d_1bdb1c == 0) das Ereignisbild 0x290001 (Index 0) mit dem Text
 *   0x29000015 an, startet anschließend den Kampf Nr. 0x45 und markiert ihn nach einem Sieg in d_1bdb1c = 1 als
 *   erledigt.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das geladene RivaRasterImage q wird direkt nach dem Schließen des Bilddialogfensters
 *   wieder freigegeben.
 === Ende Beschreibung === */
void f_08d7a0(int p1)
{
    if (EQI(d_1bdb1c, 0)) {
        SO o;
        o.p[1] = f_038c40(d_1c0004);
        void *q = f_0606a0(0x290001, 0);
        f_0bfa20(d_1c2c64, q, 0, 0x29000015, 0);
        if (q) delete (char *)((int)(((RivaRasterImage*)(q))->f_0fad20( 0)));
        short r = VC(p1, 0x45);
        if (r == 0) d_1bdb1c = 1;
    }
}
//@ f_08d850
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten des Feldes (d_1bdb00 == 0) die Hinweismeldung 0x29000017 aus und
 *   setzt das Flag d_1bdb00 = 1.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb00 unterdrückt Wiederholungen der Meldung während desselben Aufenthalts.
 === Ende Beschreibung === */
void f_08d850()
{
    if (d_1bdb00 == 0) {
        d_1bdb00 = 1;
        f_0bf730(d_1c2c64, 0x29000017);
    }
}
//@ f_08d880
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Zeigt beim ersten Auslösen (d_1bdb10 == 0) die Kampfeinleitung 0x29000016 an, startet den
 *   Kampf Nr. 0x46 und vergibt bei einem Sieg (r == 0) die Spielpunkte für den Erfolg 0x1c (f_091f70(0x1c)) samt
 *   Setzen von d_1bdb10 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb10 verhindert ein mehrfaches Auslösen des Kampfes und der Punktevergabe.
 === Ende Beschreibung === */
void f_08d880(int p1)
{
    SO o;
    if (EQI(d_1bdb10, 0)) {
        f_0bf730(d_1c2c64, 0x29000016);
        short r = VC(p1, 0x46);
        if (r == 0) {
            d_1bdb10 = 1;
            f_091f70(0x1c);
        }
    }
}
//@ f_08d900
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt beim ersten Betreten einer weiteren Stelle (d_1bdb01 == 0) die Hinweismeldung 0x29000017
 *   aus und setzt d_1bdb01 = 1.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb01 merkt vor, dass diese Warnmeldung bereits angezeigt wurde.
 === Ende Beschreibung === */
void f_08d900()
{
    if (d_1bdb01 == 0) {
        d_1bdb01 = 1;
        f_0bf730(d_1c2c64, 0x29000017);
    }
}
//@ f_08d930
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Löst beim ersten Betreten (d_1bdb14 == 0) den Kampf Nr. 0x48 aus und setzt nach einem Sieg der
 *   Gruppe (r == 0) das Flag d_1bdb14 = 1.
 * - Eingaben und Rückgabe: Die Funktion erhält den Dungeon-Kontextzeiger p1 und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Über d_1bdb14 wird der Abschluss des Kampfes 0x48 im Spielstand vermerkt.
 === Ende Beschreibung === */
void f_08d930(int p1)
{
    
    if (EQI(d_1bdb14, 0)) {
        short r = VC(p1, 0x48);
        if (r == 0) d_1bdb14 = 1;
    }
}
//@ f_08d970
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Gibt an einer dritten Stelle beim ersten Betreten (d_1bdb02 == 0) die Hinweismeldung
 *   0x29000017 aus und setzt d_1bdb02 = 1.
 * - Eingaben und Rückgabe: Die Funktion benötigt keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Flag d_1bdb02 verhindert das erneute Einblenden der Meldung.
 === Ende Beschreibung === */
void f_08d970()
{
    if (d_1bdb02 == 0) {
        d_1bdb02 = 1;
        f_0bf730(d_1c2c64, 0x29000017);
    }
}
//@ f_08d9a0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Fragt den Spieler (0x29000018), ob er einen besonderen Gegenstand (0x181) an sich nehmen
 *   möchte, gibt bei Zustimmung die Meldung 0x29000019 aus und legt ein Exemplar von 0x181 im Gruppeninventar ab
 *   (f_0dcf00).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Die Gegenstands-ID 0x181 bezeichnet ein einzelnes Quest- oder Schlüsselobjekt dieses
 *   Abschnitts.
 === Ende Beschreibung === */
void f_08d9a0()
{
    if (f_0bf6f0(d_1c2c64, 0x29000018) == 1) {
        f_0bf730(d_1c2c64, 0x29000019);
        f_0dcf00(d_1c0004, 0x181, 1);
    }
}
//@ f_08d9e0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Startet beim ersten Auslösen (d_1bdb18 == 0) den Kampf Nr. 0x47 und markiert ihn nach einem
 *   Sieg (r == 0) über d_1bdb18 = 1 als abgeschlossen.
 * - Eingaben und Rückgabe: Die Funktion nimmt den Dungeon-Kontextzeiger p1 entgegen und gibt keinen Wert zurück
 *   (void).
 * - Wichtige Variablen: Das Flag d_1bdb18 speichert den Kampferfolg im Spielstand.
 === Ende Beschreibung === */
void f_08d9e0(int p1)
{
    
    if (EQI(d_1bdb18, 0)) {
        short r = VC(p1, 0x47);
        if (r == 0) d_1bdb18 = 1;
    }
}
//@ f_08da20
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Öffnet den Beutecontainer Nr. 0x42 (f_112df0/f_1131b0), zeigt je nachdem, ob Gegenstände
 *   entnommen wurden, die Meldung 0x2900001a oder 0x2900001b mit dem Namen des Gruppenanführers an und speichert
 *   den Containerzustand (f_112ec0).
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Das Containerobjekt p verwaltet die Fundstelle 0x42.
 === Ende Beschreibung === */
void f_08da20()
{
    SO o;
    T2 *p = new (mark(d_1a2860, 0x27f)) T2;
    p = p ? (T2 *)f_112df0(p, 0x42, 0, 0) : p;
    o.p[1] = f_038c40(d_1c0004);
    if (f_1131b0(p)) {
        f_0bf730(d_1c2c64, 0x2900001a);
        f_112ec0(p);
    } else {
        f_0bf730(d_1c2c64, 0x2900001b);
    }
    if (p) delete (char *)f_112e70(p, 0);
}
