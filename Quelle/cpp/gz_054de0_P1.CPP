/* === Beschreibung (Katalog) ===
 * Einheit gz_054de0 (054de0 - 055120)
 *
 * Überblick
 * Diese kleine Einheit gehört zum Dialog-Modul (dialog.cpp) und enthält die Registrierung der 16 globalen
 * Dialog-Questflags (d_1bca7c bis d_1bcab8) für das Spielstandsystem sowie die Hilfsfunktion zum zeitabhängigen
 * Abbau der NPC-Gesprächszähler (d_1bca78).
 === Ende Beschreibung === */
// P1 0/2 gleich
// gz_054de0.cpp (Schatten ueber Riva, Attic 1996) - Pass 1, Code 0x054DE0-0x055120
#include <string.h>
// RIVA_CLOBBER.H nur bei (SICHERT)-Namen: Pragmas daraus direkt einfuegen
#include "RIVAMEM.H"



// --- Aufgerufene (Parameterzahl aus clobber.tsv; Typen int = Annahme, nach Entwurf anpassen; "this" = 1. Parameter) ---
struct E { char a; short b; };
// --- Daten (Breite aus Casts im Entwurf geraten; Strings immer extern, Pass 1 baut keine Datenstuecke ein) ---
extern short *d_1bca78;
extern E d_1bca7c;
extern E d_1bca80;
extern E d_1bca84;
extern E d_1bca88;
extern E d_1bca8c;
extern E d_1bca90;
extern E d_1bca94;
extern E d_1bca98;
extern E d_1bca9c;
extern E d_1bcaa0;
extern E d_1bcaa4;
extern E d_1bcaa8;
extern E d_1bcaac;
extern E d_1bcab0;
extern E d_1bcab4;
extern E d_1bcab8;
extern short d_1c212a;
extern E **d_1c212c;

//@ f_054de0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Initialisiert die 16 globalen Dialog- und Quest-Statusvariablen (d_1bca7c bis d_1bcab8) mit 0,
 *   weist ihnen ihre festen Savegame-Kennnummern (0x08, 0x0a, 0x8f, 0xb0, 0x15e bis 0x168, 0x16b) zu und hängt
 *   sie in die globale Savegame-Liste d_1c212c (d_1c212a) ein.
 * - Eingaben und Rückgabe: Die Funktion hat keine Parameter (void) und gibt keinen Wert zurück (void).
 * - Wichtige Variablen: Jedes der 16 O54_670-Objekte (d_1bca7c..d_1bcab8) wird mit flag = 0 und seiner Kennung
 *   number in registry54_670 (d_1c212a / d_1c212c) eingetragen.
 === Ende Beschreibung === */
struct R54_670;
struct O54_670 {signed char flag;short number;char pad;O54_670 *init(R54_670 &r,short id,signed char f);O54_670 *initDirect(R54_670 &r,short id,signed char f);};
struct R54_670 {short count; O54_670 **list;void append(O54_670 *o){list[count]=o;count++;}};
inline O54_670 *O54_670::init(R54_670 &r,short id,signed char f){flag=f;number=id;r.append(this);return this;}
inline O54_670 *O54_670::initDirect(R54_670 &r,short id,signed char f){flag=f;number=id;r.list[r.count]=this;r.count++;return this;}
extern R54_670 registry54_670;
#pragma aux registry54_670 "d_1c212a"
extern O54_670 o54_670_0;
#pragma aux o54_670_0 "d_1bca7c"
extern O54_670 o54_670_1;
#pragma aux o54_670_1 "d_1bca80"
extern O54_670 o54_670_2;
#pragma aux o54_670_2 "d_1bca84"
extern O54_670 o54_670_3;
#pragma aux o54_670_3 "d_1bca88"
extern O54_670 o54_670_4;
#pragma aux o54_670_4 "d_1bca8c"
extern O54_670 o54_670_5;
#pragma aux o54_670_5 "d_1bca90"
extern O54_670 o54_670_6;
#pragma aux o54_670_6 "d_1bca94"
extern O54_670 o54_670_7;
#pragma aux o54_670_7 "d_1bca98"
extern O54_670 o54_670_8;
#pragma aux o54_670_8 "d_1bca9c"
extern O54_670 o54_670_9;
#pragma aux o54_670_9 "d_1bcaa0"
extern O54_670 o54_670_10;
#pragma aux o54_670_10 "d_1bcaa4"
extern O54_670 o54_670_11;
#pragma aux o54_670_11 "d_1bcaa8"
extern O54_670 o54_670_12;
#pragma aux o54_670_12 "d_1bcaac"
extern O54_670 o54_670_13;
#pragma aux o54_670_13 "d_1bcab0"
extern O54_670 o54_670_14;
#pragma aux o54_670_14 "d_1bcab4"
extern O54_670 o54_670_15;
#pragma aux o54_670_15 "d_1bcab8"
void f_054de0(void){
o54_670_0.init(registry54_670,0x8,0x0);
o54_670_1.init(registry54_670,0xa,0x0);
o54_670_2.init(registry54_670,0x8f,0x0);
o54_670_3.initDirect(registry54_670,0xb0,0x0);
o54_670_4.init(registry54_670,0x15e,0x0);
o54_670_5.init(registry54_670,0x15f,0x0);
o54_670_6.initDirect(registry54_670,0x160,0x0);
o54_670_7.init(registry54_670,0x161,0x0);
o54_670_8.init(registry54_670,0x162,0x0);
o54_670_9.initDirect(registry54_670,0x163,0x0);
o54_670_10.init(registry54_670,0x164,0x0);
o54_670_11.init(registry54_670,0x165,0x0);
o54_670_12.initDirect(registry54_670,0x166,0x0);
o54_670_13.init(registry54_670,0x167,0x0);
o54_670_14.init(registry54_670,0x168,0x0);
o54_670_15.initDirect(registry54_670,0x16b,0x0);
}
#pragma inline_depth(3)

//@ f_0550b0
/* === Beschreibung (Katalog) ===
 * - Spielwirkung: Verringert alle 103 (0x67) NPC-Gesprächszähler im Array d_1bca78 um ein Viertel der
 *   vergangenen Spieltage p1 (sofern mehr als 3 Tage vergangen sind) und begrenzt sie nach unten auf 0, damit
 *   NPCs nach einiger Zeit wieder gesprächsbereit werden.
 * - Eingaben und Rückgabe: Die Funktion erhält die Anzahl der vergangenen Tage p1 (short) und gibt als int den
 *   Wert 1 zurück, wenn die Zähler gesenkt wurden (p1 > 3), sonst 0.
 * - Wichtige Variablen: Das globale Array d_1bca78 (0x67 short-Einträge) speichert für jeden Dialogpartner, wie
 *   oft die Gruppe ihn bereits angesprochen hat.
 === Ende Beschreibung === */
int f_0550b0(short p1)
{
    int r = 0;
    short i;
    if (p1 > 3) {
        p1 /= 4;
        for (i = 0; i < 0x67; i++) {
            d_1bca78[i] -= p1;
            if (d_1bca78[i] < 0) d_1bca78[i] = 0;
        }
        r = 1;
    }
    return r;
}
